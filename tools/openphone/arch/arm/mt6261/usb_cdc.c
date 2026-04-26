/*
 * arch/arm/mt6261/usb_cdc.c
 * OpenPhone — MT6261 USB Device Controller - CDC ACM support
 *
 * Copyright (C) 2026 OpenPhone Project
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * Minimal USB CDC-ACM (virtual serial port) driver.
 * Allows communication with host via USB when plugged in.
 * Falls back to UART if no USB host is connected.
 */

#include "config.h"
#include "mt6261.h"

#define USB_BASE        MT6261_USB_BASE

static int usb_configured = 0;
static int usb_enabled = 0;

/* ────────────────────────────────────────────────────────────────────────── */
/* USB Device Strings (USB 2.0 spec)                                           */
/* ────────────────────────────────────────────────────────────────────────── */

static const uint8_t usb_device_descriptor[] = {
    0x12,           /* bLength                          */
    0x01,           /* bDescriptorType (Device)         */
    0x00, 0x02,     /* bcdUSB 2.00                      */
    0x02,           /* bDeviceClass (CDC)               */
    0x00,           /* bDeviceSubClass                  */
    0x00,           /* bDeviceProtocol                  */
    0x40,           /* bMaxPacketSize0                  */
    0x17, 0x0f,     /* idVendor (MediaTek test VID)    */
    0x61, 0x50,     /* idProduct                        */
    0x00, 0x01,     /* bcdDevice 1.00                   */
    0x01,           /* iManufacturer                    */
    0x02,           /* iProduct                         */
    0x03,           /* iSerialNumber                    */
    0x01,           /* bNumConfigurations               */
};

static const uint8_t usb_config_descriptor[] = {
    0x09,           /* bLength (Configuration)          */
    0x02,           /* bDescriptorType                  */
    0x4b, 0x00,     /* wTotalLength (includes all)      */
    0x02,           /* bNumInterfaces                   */
    0x01,           /* bConfigurationValue              */
    0x00,           /* iConfiguration                   */
    0x80,           /* bmAttributes (bus powered)       */
    0xFA,           /* bMaxPower (500 mA)               */
    
    /* ──── CDC Interface Descriptor (Data Class) ──────── */
    0x09,           /* bLength (Interface)              */
    0x04,           /* bDescriptorType                  */
    0x00,           /* bInterfaceNumber (0)             */
    0x00,           /* bAlternateSetting                */
    0x01,           /* bNumEndpoints (1: interrupt EP)  */
    0x02,           /* bInterfaceClass (CDC)            */
    0x02,           /* bInterfaceSubClass (ACM)         */
    0x01,           /* bInterfaceProtocol (AT commands) */
    0x00,           /* iInterface                       */
    
    /* Header Functional Descriptor */
    0x05,           /* bLength                          */
    0x24,           /* bDescriptorType (CS_INTERFACE)   */
    0x00,           /* bDescriptorSubtype (Header)      */
    0x10, 0x01,     /* bcdCDC 1.10                      */
    
    /* Call Management Functional Descriptor */
    0x05,           /* bLength                          */
    0x24,           /* bDescriptorType                  */
    0x01,           /* bDescriptorSubtype (Call Mgmt)   */
    0x00,           /* bmCapabilities                   */
    0x01,           /* bDataInterface (interface 1)     */
    
    /* Abstract Control Management Functional Descriptor */
    0x04,           /* bLength                          */
    0x24,           /* bDescriptorType                  */
    0x02,           /* bDescriptorSubtype (ACM)         */
    0x02,           /* bmCapabilities (DTR/DSR, RTS/CTS)*/
    
    /* Union Functional Descriptor */
    0x05,           /* bLength                          */
    0x24,           /* bDescriptorType                  */
    0x06,           /* bDescriptorSubtype (Union)       */
    0x00,           /* bControlInterface                */
    0x01,           /* bSubordinateInterface0           */
    
    /* Interrupt endpoint (EP1) */
    0x07,           /* bLength (Endpoint)               */
    0x05,           /* bDescriptorType                  */
    0x81,           /* bEndpointAddress (EP1 IN)        */
    0x03,           /* bmAttributes (Interrupt)         */
    0x40, 0x00,     /* wMaxPacketSize (64 bytes)        */
    0x0a,           /* bInterval (10 ms)                */
    
    /* ──── CDC Data Interface ──────────────────────────── */
    0x09,           /* bLength (Interface)              */
    0x04,           /* bDescriptorType                  */
    0x01,           /* bInterfaceNumber (1)             */
    0x00,           /* bAlternateSetting                */
    0x02,           /* bNumEndpoints (2: IN/OUT)        */
    0x0a,           /* bInterfaceClass (CDC Data)       */
    0x00,           /* bInterfaceSubClass               */
    0x00,           /* bInterfaceProtocol               */
    0x00,           /* iInterface                       */
    
    /* Bulk OUT endpoint (EP2) */
    0x07,           /* bLength (Endpoint)               */
    0x05,           /* bDescriptorType                  */
    0x02,           /* bEndpointAddress (EP2 OUT)       */
    0x02,           /* bmAttributes (Bulk)              */
    0x40, 0x00,     /* wMaxPacketSize (64 bytes)        */
    0x00,           /* bInterval                        */
    
    /* Bulk IN endpoint (EP3) */
    0x07,           /* bLength (Endpoint)               */
    0x05,           /* bDescriptorType                  */
    0x83,           /* bEndpointAddress (EP3 IN)        */
    0x02,           /* bmAttributes (Bulk)              */
    0x40, 0x00,     /* wMaxPacketSize (64 bytes)        */
    0x00,           /* bInterval                        */
};

/* ────────────────────────────────────────────────────────────────────────── */
/* Initialization                                                              */
/* ────────────────────────────────────────────────────────────────────────── */

void mt6261_usb_init(void)
{
    /* Enable USB device function (stub for now) */
    usb_enabled = 1;
    uart_puts("USB: Device controller initialized\r\n");
}

/* ────────────────────────────────────────────────────────────────────────── */
/* Status check                                                                */
/* ────────────────────────────────────────────────────────────────────────── */

int usb_cdc_configured(void)
{
    /* Return 1 if USB host has configured the device (enumerated) */
    /* This is a stub — real implementation would check USB controller status */
    return usb_configured;
}

void usb_cdc_set_configured(int cfg)
{
    usb_configured = cfg;
    if (cfg)
        uart_puts("USB: Device configured by host\r\n");
}

/* ────────────────────────────────────────────────────────────────────────── */
/* CDC ACM Control Functions (stub)                                            */
/* ────────────────────────────────────────────────────────────────────────── */

/*
 * Called by OpenBIOS when USB device is properly enumerated.
 * Switches console I/O to USB if available, falls back to UART.
 */
void usb_cdc_check_host(void)
{
    uint16_t status;
    
    if (!usb_enabled)
        return;
    
    /* Check USB controller status register for enumeration */
    status = read16(USB_BASE + USB_INTRUSB);
    
    if (status & 0x40) {  /* Reset detected = host enumeration */
        uart_puts("USB: Host enumeration detected\r\n");
        usb_cdc_set_configured(1);
    }
}

int usb_cdc_putc(int c)
{
    /* Send character via USB CDC ACM to host */
    /* Stub — real implementation would write to bulk IN endpoint */
    return 0;
}

int usb_cdc_getc(void)
{
    /* Receive character via USB CDC ACM from host */
    /* Stub — real implementation would read from bulk OUT endpoint */
    return -1;
}

int usb_cdc_tstc(void)
{
    /* Check if data available on USB CDC ACM */
    return 0;
}

/* ────────────────────────────────────────────────────────────────────────── */
/* Multiplex console I/O                                                       */
/* ────────────────────────────────────────────────────────────────────────── */

/*
 * Autodetect console: USB if configured, else UART
 */
int console_putc(int c)
{
    if (usb_cdc_configured())
        return usb_cdc_putc(c);
    else
        return uart_putc(c);
}

int console_getc(void)
{
    if (usb_cdc_configured())
        return usb_cdc_getc();
    else
        return uart_getc();
}

int console_tstc(void)
{
    if (usb_cdc_configured())
        return usb_cdc_tstc();
    else
        return uart_tstc();
}
