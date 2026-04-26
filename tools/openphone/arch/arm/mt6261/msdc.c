/*
 * arch/arm/mt6261/msdc.c
 * OpenPhone — MT6261 MSDC (SD Card) controller driver
 *
 * Copyright (C) 2026 OpenPhone Project
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * Minimal polling-based MSDC driver for reading sectors from SD card.
 * Supports SD/MMC cards in SPI mode (most common in feature phones).
 */

#include "config.h"
#include "mt6261.h"

#define MSDC_BASE           MT6261_MSDC_BASE
#define MSDC_TIMEOUT        1000000

static int sd_initialized = 0;

/* ────────────────────────────────────────────────────────────────────────── */
/* Helper functions                                                            */
/* ────────────────────────────────────────────────────────────────────────── */

static void msleep(int ms)
{
    volatile int i = ms * 10000;
    while (i--)
        ;
}

static uint32_t msdc_read_reg(uint32_t offset)
{
    return read32(MSDC_BASE + offset);
}

static void msdc_write_reg(uint32_t offset, uint32_t val)
{
    write32(MSDC_BASE + offset, val);
}

static int msdc_wait_cmd_rdy(void)
{
    int timeout = MSDC_TIMEOUT;
    
    while (timeout--) {
        if (msdc_read_reg(MSDC_INT) & MSDC_INT_CMDRDY)
            return 0;
    }
    return -1;
}

static int msdc_wait_xfer_done(void)
{
    int timeout = MSDC_TIMEOUT * 10;  /* Longer timeout for data transfer */
    
    while (timeout--) {
        uint32_t status = msdc_read_reg(MSDC_INT);
        if (status & MSDC_INT_XFER_COMPL)
            return 0;
        if (status & (MSDC_INT_DATACRC | MSDC_INT_DATTMO))
            return -1;
    }
    return -1;
}

/* ────────────────────────────────────────────────────────────────────────── */
/* SD Card Initialization                                                     */
/* ────────────────────────────────────────────────────────────────────────── */

int mt6261_msdc_init(void)
{
    uint32_t cfg;
    
    if (sd_initialized)
        return 0;
    
    uart_puts("MSDC: Initializing SD card controller...\r\n");
    
    /* Reset FIFO */
    msdc_write_reg(MSDC_FIFOCS, 0x00008000);  /* Reset TX and RX FIFO */
    msleep(1);
    
    /* Configure MSDC: 
     * - Clock divider for ~1 MHz (slow init speed)
     * - Enable high-speed mode if supported
     */
    cfg = msdc_read_reg(MSDC_CFG);
    cfg &= ~MSDC_CFG_DIV_MASK;
    cfg |= (26 << 8);  /* Divisor = 26 for 1 MHz (26MHz / 26 = 1MHz) */
    msdc_write_reg(MSDC_CFG, cfg);
    
    /* Clear all interrupt status */
    msdc_write_reg(MSDC_INT, 0xFFFFFFFF);
    
    /* Enable data/command ready interrupts for polling */
    msdc_write_reg(MSDC_INTEN, MSDC_INT_CMDRDY | MSDC_INT_XFER_COMPL);
    
    /* Set block size to 512 bytes */
    msdc_write_reg(MSDC_BLKNUM, 512);
    
    /* Short delay for stabilization */
    msleep(100);
    
    uart_puts("MSDC: Sending CMD0 (reset)...\r\n");
    
    /* Send CMD0 (GO_IDLE_STATE) */
    msdc_write_reg(MSDC_ARG, 0);
    msdc_write_reg(MSDC_CMD, (SD_CMD_RESET << 8) | 0x09);  /* CMD0, no response */
    
    if (msdc_wait_cmd_rdy() < 0) {
        uart_puts("MSDC: CMD0 timeout\r\n");
        return -1;
    }
    
    msleep(10);
    
    uart_puts("MSDC: Sending CMD1 (SEND_OP_COND)...\r\n");
    
    /* Send CMD1 (SEND_OP_COND) — for MMC cards */
    msdc_write_reg(MSDC_ARG, 0x00300000);
    msdc_write_reg(MSDC_CMD, (1 << 8) | 0x49);  /* CMD1, expects response */
    
    if (msdc_wait_cmd_rdy() < 0) {
        uart_puts("MSDC: CMD1 timeout\r\n");
        return -1;
    }
    
    /* Increase clock speed for data transfer (10 MHz) */
    cfg = msdc_read_reg(MSDC_CFG);
    cfg &= ~MSDC_CFG_DIV_MASK;
    cfg |= (2 << 8);  /* Divisor = 2 for ~13 MHz */
    msdc_write_reg(MSDC_CFG, cfg);
    
    msleep(10);
    
    uart_puts("MSDC: SD card initialized\r\n");
    sd_initialized = 1;
    return 0;
}

/* ────────────────────────────────────────────────────────────────────────── */
/* Sector Read                                                                 */
/* ────────────────────────────────────────────────────────────────────────── */

int mt6261_msdc_read(void *dst, unsigned int lba, unsigned int count)
{
    uint32_t *dest_ptr = (uint32_t *)dst;
    unsigned int i, j;
    uint32_t data;
    
    if (!sd_initialized) {
        uart_puts("MSDC: Card not initialized\r\n");
        return -1;
    }
    
    uart_puts("MSDC: Reading ");
    uart_putdec(count);
    uart_puts(" sectors from LBA ");
    uart_puthex(lba);
    uart_puts("\r\n");
    
    /* For each sector */
    for (i = 0; i < count; i++) {
        uint32_t sector_addr = lba + i;
        
        /* Send CMD17 (READ_SINGLE_BLOCK) */
        msdc_write_reg(MSDC_ARG, sector_addr * 512);  /* SD card in byte-addressed mode */
        msdc_write_reg(MSDC_CMD, (SD_CMD_READ_SINGLE << 8) | 0x49);
        
        if (msdc_wait_cmd_rdy() < 0) {
            uart_puts("MSDC: CMD17 timeout\r\n");
            return -1;
        }
        
        /* Wait for data transfer */
        if (msdc_wait_xfer_done() < 0) {
            uart_puts("MSDC: Data transfer error\r\n");
            return -1;
        }
        
        /* Read 512 bytes (128 words) from FIFO */
        for (j = 0; j < 128; j++) {
            data = msdc_read_reg(MSDC_RXDATA);
            *dest_ptr++ = data;
        }
        
        /* Clear interrupt status */
        msdc_write_reg(MSDC_INT, 0xFFFFFFFF);
    }
    
    uart_puts("MSDC: Read complete\r\n");
    return 0;
}

/* ────────────────────────────────────────────────────────────────────────── */
/* Debug/status functions                                                      */
/* ────────────────────────────────────────────────────────────────────────── */

void mt6261_msdc_status(void)
{
    uart_puts("MSDC_CFG:     ");
    uart_puthex(msdc_read_reg(MSDC_CFG));
    uart_puts("\r\nMSDC_INT:     ");
    uart_puthex(msdc_read_reg(MSDC_INT));
    uart_puts("\r\nMSDC_FIFOCS:  ");
    uart_puthex(msdc_read_reg(MSDC_FIFOCS));
    uart_puts("\r\n");
}
