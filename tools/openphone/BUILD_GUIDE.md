# OpenPhone MT6261 Build Guide

## Overview

OpenPhone is a two-stage boot process:

1. **Stage 1** (ARM assembly shim): Minimal code to set up UART, init MSDC, load OpenBIOS from SD
2. **OpenBIOS**: Forth-based firmware/bootloader with interactive shell, SD card access, LCD output

This guide covers building Stage 1. The full system requires OpenBIOS source integration.

## Prerequisites

### Toolchain

You need an ARM cross-compiler targeting ARMv5 (MT6261 is ARM7EJ-S):

```bash
# Option 1: Linux (Debian/Ubuntu)
sudo apt install binutils-arm-linux-gnueabihf gcc-arm-linux-gnueabihf

# Option 2: macOS (Homebrew)
brew install binutils arm-linux-gnueabihf-gcc

# Option 3: Build from source
# Download: https://github.com/crosstool-ng/crosstool-ng
```

### Python 3

For the GFH packing tool:

```bash
python3 --version  # Should be 3.6+
```

### Required Files

- Your firmware dump: `dumps/dump_preloader.bin` (to extract GFH header)
- Optionally: Disassembly for LCD extraction: `analysis/preloader.dis`

## Project Structure

```
tools/openphone/
├── arch/arm/mt6261/
│   ├── build.xml              # OpenBIOS build config (if integrating)
│   ├── ldscript               # Linker script (you have this now)
│   ├── mt6261.h              # Hardware definitions
│   ├── config.h              # Build configuration
│   │
│   ├── entry.S               # Boot entry point (from patch)
│   ├── openbios.c            # OpenBIOS stub
│   ├── uart.c                # Serial driver
│   ├── msdc.c                # SD card driver
│   ├── lcd.c                 # LCD display driver (from patch)
│   ├── console_lcd.c         # LCD text console (from patch)
│   ├── usb_cdc.c             # USB serial port
│   ├── devices.c             # Forth device packages (from patch)
│   │
│   ├── cpu.fs                # Forth CPU words (from patch)
│   ├── init.fs               # Forth initialization (from patch)
│   │
│   ├── pack_gfh.py           # GFH header packer
│   ├── Makefile              # Build rules
│   │
│   └── LCD_EXTRACTION_GUIDE.md  # How to extract LCD init
│
├── device/
│   └── gfp105a.dts           # Device tree (for kernel boot)
│
└── docs/
    ├── BUILD_GUIDE.md        # This file
    └── README.md             # Project overview
```

## Step 1: Prepare Source Files

The patch file contains most source code. Extract or manually integrate:

```bash
cd tools/openphone

# If you haven't already applied the patch:
patch -p1 < patch-all.patch

# Verify structure
ls -la arch/arm/mt6261/
```

## Step 2: Check Toolchain

```bash
# Verify cross-compiler is available
arm-linux-gnueabihf-gcc --version

# If not found, specify with CROSS_COMPILE:
export CROSS_COMPILE=arm-linux-gnueabihf-

# Test compilation
arm-linux-gnueabihf-gcc -mcpu=arm7tdmi -march=armv5 -c -x c - <<< "int main() { return 0; }"
```

## Step 3: Extract LCD Initialization (Optional but Recommended)

The LCD driver has a stub init sequence. For best results, extract from OEM firmware:

```bash
# See LCD_EXTRACTION_GUIDE.md for detailed instructions
python3 << 'EOF'
import struct

# Find LCD controller references
with open('../../binaries/dump_preloader.bin', 'rb') as f:
    data = f.read()

target = struct.pack('<I', 0x800B0000)
refs = []
i = 0
while True:
    idx = data.find(target, i)
    if idx < 0: break
    refs.append(idx)
    i = idx + 1

print(f"Found {len(refs)} LCD references")
for ref in refs[:3]:
    print(f"  0x{ref:08x}")
EOF

# Follow LCD_EXTRACTION_GUIDE.md to identify panel type and init commands
# Update arch/arm/mt6261/lcd.c mt6261_lcd_hw_init() with real sequence
```

## Step 4: Build Stage 1

```bash
cd arch/arm/mt6261

# Build everything (ELF, binary, and GFH-packed image)
make

# Or step-by-step:
make openphone-stage1.elf    # Link ELF
make openphone-stage1.bin    # Convert to binary
make openphone-stage1-final.bin  # Pack with GFH

# Generate disassembly for debugging:
make disasm

# Check code size:
make size
```

### Build Troubleshooting

**Missing CROSS_COMPILE tools:**
```bash
export CROSS_COMPILE=arm-none-eabi-   # Try this alternative
make clean
make
```

**"can't find mt6261.h":**
```bash
# Make sure you're in the right directory
cd tools/openphone/arch/arm/mt6261/
ls -la mt6261.h
```

**Linker errors (undefined references):**
```bash
# Check if you're missing functions
arm-linux-gnueabihf-nm openphone-stage1.elf | grep " U "

# Add stubs or check includes in .h files
```

**GFH packing fails:**
```bash
# The script needs your firmware dump for the GFH header
# Find it:
find ../../.. -name "dump_preloader.bin" -o -name "dump.bin"

# Or manually specify:
GFH=/path/to/dump_preloader.bin make openphone-stage1-final.bin
```

## Step 5: Verify the Image

```bash
# Check final image size
ls -lh bin/openphone-stage1-final.bin

# Hexdump first 256 bytes (should start with GFH header, not 0x60 zeros)
hexdump -C bin/openphone-stage1-final.bin | head -20

# Check it's not too large (must fit before LCD framebuffer)
python3 << 'EOF'
import os
size = os.path.getsize('bin/openphone-stage1-final.bin')
limit = 0x16800 - 0x6000  # Load addr to framebuffer
print(f"Image size: {size} bytes (0x{size:x})")
print(f"Max size:   {limit} bytes (0x{limit:x})")
print(f"Remaining:  {limit - size} bytes")
if size > limit:
    print("ERROR: Image too large!")
else:
    print("OK")
EOF
```

## Step 6: Flash to Device

### Requirements

- OpenPhone hardware flashing tool or MediaTek MTK Client
- USB connection to device
- Knowledge of NOR flash layout

### Using mtkflasher

If you have MediaTek MTK Client or similar tool:

```bash
# Configure for your device
mtk_client --device mt6261 --rom bin/openphone-stage1-final.bin

# Or with dmesg to verify connection:
dmesg | tail -5
```

### Manual via UART boot

If device supports UART boot mode:

```bash
# Use xmodem or similar protocol
serial_tool --port /dev/ttyUSB0 --baud 115200 \
    --send bin/openphone-stage1-final.bin
```

## Step 7: Test on Device

Once flashed:

```bash
# Connect serial console (115200 8N1)
minicom -D /dev/ttyUSB0 -b 115200

# Or screen:
screen /dev/ttyUSB0 115200

# Expected output:
# - Banner: "OpenPhone/0.1"
# - "GFP-105A / MT6261..."
# - "UART initialized"
# - "MSDC initialized"
# - "Loading OpenBIOS from SD..."
# - Forth 'ok' prompt appears
```

### Interactive Commands

Once OpenBIOS loads, try:

```forth
ok .sysinfo              \ Show system information
ok .console              \ Show active console
ok d 70006000 20         \ Disassemble Stage 1 code
ok sd-boot               \ Boot from SD card (if kernel is ready)
ok words                 \ List all Forth words
ok help lcd-pixel!       \ Get help on Forth words
```

## Build Variants

### Minimal Build (no USB)

```bash
# In config.h:
#define CONFIG_USB_CDC          0

make clean
make
```

### Debug Build

```bash
# Verbose output during boot
# In config.h:
#define CONFIG_VERBOSE_BOOT     1

make clean
make
```

### With Full OpenBIOS Integration

If you have OpenBIOS source:

```bash
# Set OpenBIOS paths
export OPENBIOS_TOP=/path/to/openbios
export OPENPHONE_TOP=$PWD

# Build with OpenBIOS build system
cd $OPENBIOS_TOP
./configure --target-cpu=arm --with-mt6261
make
```

## Troubleshooting

| Issue | Cause | Solution |
|-------|-------|----------|
| **Compilation errors** | Missing dependencies | Install `arm-linux-gnueabihf-gcc` |
| **Linker errors** | Undefined functions | Check all .c files are compiled |
| **GFH pack fails** | Can't find dump | Provide GFH= environment variable |
| **Image too large** | Code bloat | Check object sizes, enable -Os |
| **Blank LCD** | LCD init stub incomplete | Extract real init sequence from dump |
| **No serial output** | UART not init'd | Check entry.S, uart_init() call |
| **Device won't boot** | Bad GFH | Verify with `hexdump`, re-extract GFH |

## Performance Optimization

If image is too large:

```bash
# Check which modules consume most space
arm-linux-gnueabihf-size -A bin/openphone-stage1.elf

# Try compilation size optimization
CFLAGS+=-Os make clean && make

# Disable unused features in config.h
```

## Debugging

### Using GDB

```bash
# Build with debug symbols (-g is already in CFLAGS)
arm-linux-gnueabihf-gdb bin/openphone-stage1.elf

# Connect to target (if running in QEMU or debugger)
(gdb) target remote :3333
(gdb) load
(gdb) break _start
(gdb) continue
```

### Serial Logging

```bash
# Capture full boot log
screen -L /dev/ttyUSB0 115200

# View log:
cat screenlog.0
```

### UART Verbosity

Add debug output at key points:

```c
// In entry.S _start:
uart_puts("BSS cleared\r\n");
uart_puts("Jumping to OpenBIOS...\r\n");
```

## Next Steps

1. **Extract LCD init sequence** - See LCD_EXTRACTION_GUIDE.md
2. **Build full OpenBIOS** - Integrate with OpenBIOS source tree
3. **Create uCLinux kernel image** - For actual OS booting
4. **Write device tree** - Already started in `device/gfp105a.dts`
5. **Root filesystem** - ramfs or initramfs on SD card

## References

- [OpenBIOS Project](https://openbios.org/)
- [MediaTek MT6261](https://en.wikipedia.org/wiki/MediaTek_MT6261) - ARM7EJ-S @ 104 MHz
- [ARM7TDMI Architecture](https://en.wikipedia.org/wiki/ARM7) - ARMv5 instruction set
- [GCC ARM Embedded](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm)
- [u-boot MT6261 port](https://github.com/search?q=mt6261+u-boot) - Reference implementation

## Support

For issues or questions:

1. Check the troubleshooting section above
2. See LCD_EXTRACTION_GUIDE.md for LCD-specific problems
3. Check OpenBIOS documentation for Forth-related issues
4. Examine `bin/*.dis` and `bin/*.map` for linking problems

---

**OpenPhone v0.1** - GFP-105A Firmware and OS Development
(C) 2026 OpenPhone Project - GPL-2.0-only
