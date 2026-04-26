/*
 * arch/arm/mt6261/openbios.c
 * OpenPhone — OpenBIOS integration entry point
 *
 * Copyright (C) 2026 OpenPhone Project
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * Stub for OpenBIOS core functions. When building with the full
 * OpenBIOS source, these are provided by libopenbios.a.
 * This file exists for standalone testing of Stage 1 bootloader.
 */

#include "config.h"
#include "mt6261.h"

/* Forth kernel is provided by OpenBIOS libopenbios.a
 * This is a minimal stub if building without full OpenBIOS
 */

void arch_of_init(void)
{
    /* Called by OpenBIOS after Forth kernel is running */
    extern void mt6261_devices_init(void);
    mt6261_devices_init();
}

void forth_repl(void)
{
    /* Interactive Forth REPL loop */
    /* Provided by OpenBIOS; this is just a marker */
}
