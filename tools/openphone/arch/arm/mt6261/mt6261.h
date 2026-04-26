/*
 * arch/arm/mt6261/mt6261.h
 * OpenPhone — MT6261 hardware definitions
 * Target: Gradiente Neo Flip 105A (GFP-105A)
 *
 * Copyright (C) 2026 OpenPhone Project
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * MediaTek MT6261:
 *   - ARM7EJ-S core (ARMv5, no MMU)
 *   - 104 MHz clock
 *   - 256 KB SRAM (0x70000000 - 0x7003FFFF)
 *   - 4 MB NOR flash (0x00000000 - 0x003FFFFF)
 *   - Integrated peripherals:
 *     - UART 0-2
 *     - SPI
 *     - I2C
 *     - MSDC (SD card controller)
 *     - Parallel LCD interface
 *     - USB (device mode)
 *     - GPIO
 *     - Interrupt controller
 */

#ifndef _MT6261_H_
#define _MT6261_H_

#include <stdint.h>

/* ────────────────────────────────────────────────────────────────────────── */
/* Memory Layout                                                              */
/* ────────────────────────────────────────────────────────────────────────── */

#define MT6261_NOR_BASE             0x00000000  /* 4 MB NOR flash              */
#define MT6261_SRAM_BASE            0x70000000  /* 256 KB SRAM                 */
#define MT6261_SRAM_SIZE            0x00040000  /* 256 KB = 0x40000 bytes      */

/* OpenPhone Stage 1 layout in SRAM */
#define OPENPHONE_LOAD_ADDR         0x70006000  /* BROM loads us here          */
#define OPENPHONE_ENTRY_OFFSET      0x00000140  /* _start offset from load     */
#define OPENPHONE_ENTRY_POINT       (OPENPHONE_LOAD_ADDR + OPENPHONE_ENTRY_OFFSET)
#define OPENPHONE_STACK_TOP         0x7003FFFC  /* Growing down                */
#define OPENPHONE_VERSION           "0.1"

/* LCD framebuffer (in SRAM) */
#define LCD_FB_BASE                 0x70016800  /* 150 KB after code           */
#define LCD_WIDTH                   240
#define LCD_HEIGHT                  320
#define LCD_FB_SIZE                 (240 * 320 * 2)  /* RGB565 = 153600 B    */

/* OpenBIOS load from SD card */
#define OPENBIOS_SD_SECTOR          256          /* Sector 256 on SD card       */
#define OPENBIOS_SD_SECTORS         256          /* 128 KB image = 256 sectors  */
#define OPENBIOS_LOAD_ADDR          0x70008000   /* After Stage 1 in SRAM       */

/* ────────────────────────────────────────────────────────────────────────── */
/* Clock Controller (CONFG)                                                    */
/* ────────────────────────────────────────────────────────────────────────── */

#define MT6261_CONFG_BASE           0x80000000

#define CONFG_PERI_EBUSCFG          (MT6261_CONFG_BASE + 0x0000)
#define CONFG_PERI_GLOBALCON        (MT6261_CONFG_BASE + 0x0010)
#define CONFG_PERI_GLOBALCON_PDWN   (1 << 0)

#define CONFG_CLK_CFG0              (MT6261_CONFG_BASE + 0x0130)
#define CONFG_CLK_CFG1              (MT6261_CONFG_BASE + 0x0134)
#define CONFG_CLK_CFG2              (MT6261_CONFG_BASE + 0x0138)
#define CONFG_CLK_CFG3              (MT6261_CONFG_BASE + 0x013C)

/* ────────────────────────────────────────────────────────────────────────── */
/* GPIO                                                                        */
/* ────────────────────────────────────────────────────────────────────────── */

#define MT6261_GPIO_BASE            0x80020000

/* GPIO banks: 0-4, each 0x10 bytes apart */
#define GPIO_DIR(bank)              (MT6261_GPIO_BASE + 0x0000 + (bank) * 0x10)
#define GPIO_DOUT(bank)             (MT6261_GPIO_BASE + 0x0004 + (bank) * 0x10)
#define GPIO_DIN(bank)              (MT6261_GPIO_BASE + 0x0008 + (bank) * 0x10)
#define GPIO_MODE(bank)             (MT6261_GPIO_BASE + 0x000C + (bank) * 0x10)

/* ────────────────────────────────────────────────────────────────────────── */
/* UART                                                                        */
/* ────────────────────────────────────────────────────────────────────────── */

#define MT6261_UART0_BASE           0x80030000
#define MT6261_UART1_BASE           0x80040000
#define MT6261_UART2_BASE           0x80050000

/* UART register offsets */
#define UART_RBR                    0x00    /* Receive Buffer Register (r)      */
#define UART_THR                    0x00    /* Transmit Holding Register (w)    */
#define UART_DLL                    0x00    /* Divisor Latch Low (DLAB=1)       */
#define UART_DLH                    0x04    /* Divisor Latch High (DLAB=1)      */
#define UART_IER                    0x04    /* Interrupt Enable Register        */
#define UART_FCR                    0x08    /* FIFO Control Register            */
#define UART_LCR                    0x0C    /* Line Control Register            */
#define UART_MCR                    0x10    /* Modem Control Register           */
#define UART_LSR                    0x14    /* Line Status Register             */
#define UART_MSR                    0x18    /* Modem Status Register            */
#define UART_SCR                    0x1C    /* Scratch Register                 */

/* UART_LCR bits */
#define LCR_DLAB                    (1 << 7)    /* Divisor Latch Access Bit     */
#define LCR_SBC                     (1 << 6)    /* Set Break Control            */
#define LCR_EPS                     (1 << 4)    /* Even Parity Select           */
#define LCR_PEN                     (1 << 3)    /* Parity Enable                */
#define LCR_STB                     (1 << 2)    /* Stop Bits                    */
#define LCR_WLS_8                   (3 << 0)    /* Word Length = 8 bits         */

/* UART_LSR bits */
#define LSR_THRE                    (1 << 5)    /* Transmit Holding Reg Empty   */
#define LSR_DR                      (1 << 0)    /* Data Ready                   */

/* UART_FCR bits */
#define FCR_FE                      (1 << 0)    /* FIFO Enable                  */
#define FCR_RFIFO_RST               (1 << 1)    /* RX FIFO Reset                */
#define FCR_TFIFO_RST               (1 << 2)    /* TX FIFO Reset                */

/* ────────────────────────────────────────────────────────────────────────── */
/* MSDC (SD Card Controller)                                                  */
/* ────────────────────────────────────────────────────────────────────────── */

#define MT6261_MSDC_BASE            0x80050000

/* MSDC register offsets */
#define MSDC_CFG                    0x00    /* Configuration                    */
#define MSDC_IOCON                  0x04    /* I/O Configuration                */
#define MSDC_PS                     0x08    /* Pad Select                       */
#define MSDC_INT                    0x0C    /* Interrupt Status                 */
#define MSDC_INTEN                  0x10    /* Interrupt Enable                 */
#define MSDC_FIFOCS                 0x14    /* FIFO Control & Status            */
#define MSDC_TXDATA                 0x18    /* TX Data Register                 */
#define MSDC_RXDATA                 0x1C    /* RX Data Register                 */
#define MSDC_CMD                    0x20    /* Command                          */
#define MSDC_ARG                    0x24    /* Argument                         */
#define MSDC_RESP0                  0x28    /* Response 0                       */
#define MSDC_RESP1                  0x2C    /* Response 1                       */
#define MSDC_RESP2                  0x30    /* Response 2                       */
#define MSDC_RESP3                  0x34    /* Response 3                       */
#define MSDC_TIMER0                 0x38    /* Timer 0 (Response Timeout)       */
#define MSDC_TIMER1                 0x3C    /* Timer 1 (Data Timeout)           */
#define MSDC_BLKNUM                 0x40    /* Block Number                     */
#define MSDC_FIFOWL                 0x44    /* FIFO Waterline                   */

/* MSDC_CFG bits */
#define MSDC_CFG_HS                 (1 << 0)    /* High-speed mode              */
#define MSDC_CFG_DIV_MASK           (0xFF << 8) /* Clock divider                */

/* MSDC_INT bits */
#define MSDC_INT_CMDRDY             (1 << 25)   /* Command ready                */
#define MSDC_INT_CMDTMO             (1 << 24)   /* Command timeout              */
#define MSDC_INT_RSPCRC             (1 << 23)   /* Response CRC error           */
#define MSDC_INT_CSTA               (1 << 21)   /* Command done                 */
#define MSDC_INT_XFER_COMPL         (1 << 12)   /* Data transfer complete       */
#define MSDC_INT_DATTMO             (1 << 8)    /* Data timeout                 */
#define MSDC_INT_DATACRC            (1 << 7)    /* Data CRC error               */
#define MSDC_INT_ACMDRDY            (1 << 3)    /* Auto CMD ready               */
#define MSDC_INT_ACMDCRCFAIL        (1 << 2)    /* Auto CMD CRC fail            */
#define MSDC_INT_ACMDTMO            (1 << 1)    /* Auto CMD timeout             */
#define MSDC_INT_ACMDRSP            (1 << 0)    /* Auto CMD response            */

/* SD card command codes */
#define SD_CMD_RESET                0           /* GO_IDLE_STATE                */
#define SD_CMD_SEND_OP_COND         41          /* SEND_OP_COND (ACMD)          */
#define SD_CMD_SEND_CSD             9           /* SEND_CSD                     */
#define SD_CMD_SEND_CID             10          /* SEND_CID                     */
#define SD_CMD_STOP_TRANSMISSION    12          /* STOP_TRANSMISSION            */
#define SD_CMD_SEND_STATUS          13          /* SEND_STATUS                  */
#define SD_CMD_SET_BLOCKLEN         16          /* SET_BLOCKLEN                 */
#define SD_CMD_READ_SINGLE          17          /* READ_SINGLE_BLOCK            */
#define SD_CMD_READ_MULTI           18          /* READ_MULTIPLE_BLOCK          */
#define SD_CMD_APP_CMD              55          /* APP_CMD                      */

/* ────────────────────────────────────────────────────────────────────────── */
/* LCD Controller                                                              */
/* ────────────────────────────────────────────────────────────────────────── */

#define MT6261_LCD_BASE             0x800B0000

/* LCD register offsets */
#define LCD_WROI_CTRL               0x0000
#define LCD_WROI_CMD                0x0004
#define LCD_WROI_DATA               0x0008
#define LCD_WROI_SIZE               0x000C
#define LCD_WROI_BGCLR              0x0010
#define LCD_LAYER_EN                0x0020
#define LCD_LAYER0_CTRL             0x0024
#define LCD_LAYER0_SRC              0x0028
#define LCD_LAYER0_PITCHSZ          0x002C
#define LCD_LAYER0_WINDOW           0x0030
#define LCD_STATUS                  0x0100
#define LCD_INTEN                   0x0104
#define LCD_INTSTA                  0x0108
#define LCD_PARALLEL_CFG            0x0204

/* LCD colors (RGB565) */
#define LCD_COLOR_BLACK             0x0000
#define LCD_COLOR_WHITE             0xFFFF
#define LCD_COLOR_RED               0xF800
#define LCD_COLOR_GREEN             0x07E0
#define LCD_COLOR_BLUE              0x001F
#define LCD_COLOR_CYAN              0x07FF
#define LCD_COLOR_MAGENTA           0xF81F
#define LCD_COLOR_YELLOW            0xFFE0
#define LCD_COLOR_GRAY              0x8410

/* Console colors */
#define LCD_CON_FG                  LCD_COLOR_WHITE
#define LCD_CON_BG                  LCD_COLOR_BLACK
#define LCD_CON_BANNER_FG           LCD_COLOR_CYAN
#define LCD_CON_ERROR_FG            LCD_COLOR_RED
#define LCD_CON_PROMPT_FG           LCD_COLOR_CYAN

/* ────────────────────────────────────────────────────────────────────────── */
/* USB Device Controller                                                       */
/* ────────────────────────────────────────────────────────────────────────── */

#define MT6261_USB_BASE             0x80060000

/* USB register offsets */
#define USB_FADDR                   0x00    /* Function Address                 */
#define USB_POWER                   0x01    /* Power Control                    */
#define USB_INTRTX                  0x02    /* Interrupt TX Status              */
#define USB_INTRRX                  0x04    /* Interrupt RX Status              */
#define USB_INTRTXE                 0x06    /* Interrupt TX Enable              */
#define USB_INTRRXE                 0x08    /* Interrupt RX Enable              */
#define USB_INTRUSB                 0x0A    /* USB Interrupt Status             */
#define USB_INTRUSBE                0x0B    /* USB Interrupt Enable             */
#define USB_FRAME                   0x0C    /* Frame Number                     */
#define USB_INDEX                   0x0E    /* Endpoint Index                   */
#define USB_TESTMODE                0x0F    /* Test Mode                        */
#define USB_EP0_CSR                 0x11    /* Endpoint 0 Control & Status      */
#define USB_TXMAXP                  0x10    /* TX Max Packet                    */
#define USB_CSR0                    0x11    /* Control/Status Register 0        */
#define USB_RXMAXP                  0x14    /* RX Max Packet                    */
#define USB_RXCSR                   0x15    /* RX Control & Status              */
#define USB_FIFO0                   0x20    /* FIFO Port 0 (Endpoint 0)         */
#define USB_FIFO1                   0x24    /* FIFO Port 1 (Endpoints 1-4)      */

/* ────────────────────────────────────────────────────────────────────────── */
/* Interrupt Controller                                                        */
/* ────────────────────────────────────────────────────────────────────────── */

#define MT6261_IRQ_BASE             0x80010000

#define IRQ_STATUS                  (MT6261_IRQ_BASE + 0x00)
#define IRQ_MASK                    (MT6261_IRQ_BASE + 0x04)
#define IRQ_ACK                     (MT6261_IRQ_BASE + 0x08)

/* IRQ bits */
#define IRQ_UART0                   1
#define IRQ_UART1                   2
#define IRQ_MSDC                    7
#define IRQ_USB                     24
#define IRQ_LCD                     26

/* ────────────────────────────────────────────────────────────────────────── */
/* Inline helpers                                                              */
/* ────────────────────────────────────────────────────────────────────────── */

static inline void write32(uint32_t addr, uint32_t val)
{
    *(volatile uint32_t *)addr = val;
}

static inline uint32_t read32(uint32_t addr)
{
    return *(volatile uint32_t *)addr;
}

static inline void write16(uint32_t addr, uint16_t val)
{
    *(volatile uint16_t *)addr = val;
}

static inline uint16_t read16(uint32_t addr)
{
    return *(volatile uint16_t *)addr;
}

static inline void write8(uint32_t addr, uint8_t val)
{
    *(volatile uint8_t *)addr = val;
}

static inline uint8_t read8(uint32_t addr)
{
    return *(volatile uint8_t *)addr;
}

#endif /* _MT6261_H_ */
