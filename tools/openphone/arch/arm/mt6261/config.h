/*
 * arch/arm/mt6261/config.h
 * OpenPhone — MT6261 configuration header
 *
 * Copyright (C) 2026 OpenPhone Project
 * SPDX-License-Identifier: GPL-2.0-only
 */

#ifndef _CONFIG_H_
#define _CONFIG_H_

/* Platform configuration */
#define PLATFORM_NAME           "GFP-105A"
#define PLATFORM_BOARD          "Gradiente Neo Flip 105A"
#define PLATFORM_SOC            "MediaTek MT6261"

/* Features */
#define CONFIG_UART             1
#define CONFIG_MSDC             1
#define CONFIG_LCD              1
#define CONFIG_USB_CDC          1

/* Debug output */
#define CONFIG_DEBUG_SERIAL     1
#define CONFIG_VERBOSE_BOOT     1

#endif
