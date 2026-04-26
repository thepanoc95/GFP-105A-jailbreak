/*
 * arch/arm/mt6261/uart.c
 * OpenPhone — MT6261 UART driver
 * 
 * Copyright (C) 2026 OpenPhone Project
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * Simple polling-based UART driver for console I/O.
 * Uses UART0 at 115200 baud, 8N1.
 */

#include "config.h"
#include "mt6261.h"

#define UART_BASE           MT6261_UART0_BASE
#define UART_BAUD           115200
#define UART_CLOCK          26000000    /* 26 MHz crystal */

/* ────────────────────────────────────────────────────────────────────────── */
/* Initialization                                                              */
/* ────────────────────────────────────────────────────────────────────────── */

void mt6261_uart_init(void)
{
    uint32_t baudrate_divisor;
    
    /* Calculate divisor for 115200 baud:
     * divisor = uart_clock / (16 * baudrate)
     * 26000000 / (16 * 115200) = 26000000 / 1843200 ≈ 14.1
     * Use 14 (standard for MT6261 @ 26MHz)
     */
    baudrate_divisor = UART_CLOCK / (16 * UART_BAUD);
    if (baudrate_divisor > 255)
        baudrate_divisor = 255;
    if (baudrate_divisor < 1)
        baudrate_divisor = 1;
    
    /* Set DLAB to access baud rate registers */
    write8(UART_BASE + UART_LCR, LCR_DLAB);
    
    /* Set divisor */
    write8(UART_BASE + UART_DLL, baudrate_divisor & 0xFF);
    write8(UART_BASE + UART_DLH, (baudrate_divisor >> 8) & 0xFF);
    
    /* Clear DLAB, set 8N1 format */
    write8(UART_BASE + UART_LCR, LCR_WLS_8);
    
    /* Enable FIFO */
    write8(UART_BASE + UART_FCR, FCR_FE | FCR_TFIFO_RST | FCR_RFIFO_RST);
    
    /* Enable interrupts (optional for polling-based mode, keep disabled for now) */
    write8(UART_BASE + UART_IER, 0);
}

/* ────────────────────────────────────────────────────────────────────────── */
/* Polling output                                                              */
/* ────────────────────────────────────────────────────────────────────────── */

int uart_putc(int c)
{
    volatile int timeout = 100000;
    
    /* Wait for TX holding register to be empty */
    while (!(read8(UART_BASE + UART_LSR) & LSR_THRE) && timeout--)
        ;
    
    if (timeout <= 0)
        return -1;
    
    write8(UART_BASE + UART_THR, (uint8_t)c);
    return 0;
}

void uart_puts(const char *s)
{
    while (*s) {
        if (*s == '\n')
            uart_putc('\r');
        uart_putc(*s++);
    }
}

void uart_puthex(unsigned int v)
{
    static const char hex[] = "0123456789ABCDEF";
    int i;
    
    uart_puts("0x");
    for (i = 28; i >= 0; i -= 4)
        uart_putc(hex[(v >> i) & 0xF]);
}

void uart_putdec(unsigned int v)
{
    if (v >= 10)
        uart_putdec(v / 10);
    uart_putc('0' + v % 10);
}

/* ────────────────────────────────────────────────────────────────────────── */
/* Polling input                                                               */
/* ────────────────────────────────────────────────────────────────────────── */

int uart_getc(void)
{
    /* Block until data available */
    while (!(read8(UART_BASE + UART_LSR) & LSR_DR))
        ;
    
    return read8(UART_BASE + UART_RBR);
}

int uart_tstc(void)
{
    /* Test if character available (non-blocking) */
    return (read8(UART_BASE + UART_LSR) & LSR_DR) ? 1 : 0;
}

/* ────────────────────────────────────────────────────────────────────────── */
/* Printf-style output                                                         */
/* ────────────────────────────────────────────────────────────────────────── */

#include <stdarg.h>
#include <stdio.h>

int uart_printf(const char *fmt, ...)
{
    va_list ap;
    char buf[256];
    int len;
    
    va_start(ap, fmt);
    len = vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    
    uart_puts(buf);
    return len;
}
