# LCD Initialization Extraction Guide

## Overview

The MT6261 LCD controller needs a proper initialization sequence to communicate with the panel controller (likely ILI9341, ST7789, or similar). This sequence is embedded in the OEM firmware but has been stubbed in the port.

## Why Extract?

The OEM firmware already contains the correct init sequence for your specific board. Rather than guessing, we can extract and reuse it.

## Step 1: Locate LCD References in Firmware

The LC D controller base address is `0x800B0000`. Search the firmware dump for references:

```bash
# Find all references to LCD base in binary dump
python3 << 'EOF'
import struct

with open('dump_preloader.bin', 'rb') as f:
    data = f.read()

# Search for 0x800B0000 in little-endian
target = struct.pack('<I', 0x800B0000)
i = 0
while True:
    idx = data.find(target, i)
    if idx < 0:
        break
    print(f"0x800B0000 reference at offset 0x{idx:08x}")
    i = idx + 1
EOF
```

## Step 2: Disassemble the Relevant Code

Once you find a reference, disassemble the surrounding code to understand the init sequence.

### For Thumb-2 (most likely):

```bash
# Extract a chunk around the LCD reference
dd if=dump_preloader.bin of=lcd_code.bin bs=1 skip=0x12340 count=0x1000

# Disassemble as Thumb code (ARM7EJ-S uses Thumb)
arm-none-eabi-objdump -D -b binary -m arm -M force-thumb \
    --adjust-vma=0x70006000 lcd_code.bin | tee lcd_code.dis

# Look for STR (store register) instructions to LCD registers
grep -n "800b0000\|800B0000" lcd_code.dis
```

### Register Write Pattern

Look for patterns like:

```
70006xxx:    movw    r1, #0x0000     ; Load low 16 bits of address
70006xxx:    movt    r1, #0x800b     ; Load high 16 bits
70006xxx:    mov     r0, #0x01       ; Data to write
70006xxx:    str     r0, [r1, #4]    ; Write to register offset +4
```

Or more directly:

```
70006xxx:    ldr     r1, [pc, ...]   ; Load address from literal pool
70006xxx:    ldr     r0, [...]       ; Load data
70006xxx:    str     r0, [r1, #offset]
```

## Step 3: Extract Initialization Commands

The init sequence typically looks like:

1. Reset the panel (assert GPIO, delay, deassert)
2. Configure parallel interface (16-bit, timing)
3. Send initialization commands specific to the panel

Common command sequence for ILI9341:

```c
// Soft reset
lcd_write_cmd(0x01);   // SWRESET
delay(150);            // Wait 150ms

// Sleep out
lcd_write_cmd(0x11);   // SLPOUT
delay(120);            // Wait 120ms

// Pixel format
lcd_write_cmd(0x3A);   // COLMOD
lcd_write_dat(0x55);   // 16-bit RGB565

// Memory access control (orientation)
lcd_write_cmd(0x36);   // MADCTL
lcd_write_dat(0x48);   // Portrait, BGR

// Column address set
lcd_write_cmd(0x2A);   // CASET
lcd_write_dat(0x00); lcd_write_dat(0x00);
lcd_write_dat(0x00); lcd_write_dat(0xEF);  // 0-239

// Row address set
lcd_write_cmd(0x2B);   // RASET
lcd_write_dat(0x00); lcd_write_dat(0x00);
lcd_write_dat(0x01); lcd_write_dat(0x3F);  // 0-319

// Display on
lcd_write_cmd(0x29);   // DISPON
delay(10);
```

## Step 4: Identify Your Panel

### Check panel ID (at runtime):

```forth
ok hex
ok 800b0004 l@ .  ( write RDID command 0x04 )
ok 800b0008 l@ .  ( read response )
```

### Common MT6261 Panels:

- **ILI9341** (240x320, most common)
  - ID: 0x9341
  - Command set: ILI9341 standard

- **ST7789** (240x320)
  - ID: 0x7789
  - Similar to ILI9341

- **ILI9163C** (128x160, less common)
  - ID: 0x9163
  - Different dimensions

## Step 5: Update the Code

Replace the stub in `arch/arm/mt6261/lcd.c`:

```c
static void mt6261_lcd_hw_init(void)
{
    /* Step 1: Hardware reset */
    gpio_out(LCD_RESET_GPIO, 0);
    msleep(10);
    gpio_out(LCD_RESET_GPIO, 1);
    msleep(120);

    /* Step 2: Configure LCD controller */
    REG32(MT6261_LCD_BASE + LCD_PARALLEL_CFG) = LCD_PAR_16BIT;

    /* Step 3: Panel-specific init (from extracted sequence) */
    
    /* Your extracted commands here */
    lcd_write_cmd(0x01);            /* Software reset */
    msleep(150);
    lcd_write_cmd(0x11);            /* Sleep out */
    msleep(120);
    
    /* ... etc ... */
    
    lcd_write_cmd(0x29);            /* Display on */
    msleep(10);
}
```

## Automated Extraction Helper

Use this script to help find and document LCD init code:

```bash
#!/bin/bash
# find_lcd_init.sh

DUMP="${1:-dump_preloader.bin}"
DISASM="${2:-preloader.dis}"

if [ ! -f "$DUMP" ]; then
    echo "Usage: $0 <firmware_dump> [disassembly]"
    exit 1
fi

echo "Searching for LCD references in $DUMP..."
python3 << 'SCRIPT'
import struct, sys

with open("$DUMP", 'rb') as f:
    data = f.read()

# Find 0x800B0000 references
target = struct.pack('<I', 0x800B0000)
refs = []
i = 0
while True:
    idx = data.find(target, i)
    if idx < 0: break
    refs.append(idx)
    i = idx + 1

print(f"Found {len(refs)} references to 0x800B0000")
for idx in refs[:5]:  # Show first 5
    print(f"  Offset 0x{idx:08x}")
SCRIPT

if [ -f "$DISASM" ]; then
    echo ""
    echo "Searching disassembly for nearby LCD writes..."
    grep -B5 -A5 "800b0000\|800B0000" "$DISASM" | head -50
fi
```

## Tools Needed

```bash
# Install ARM cross-compiler
sudo apt install binutils-arm-linux-gnueabihf

# Or for bare metal:
sudo apt install binutils-arm-none-eabi
```

## Reference: LCD Register Offsets

From `arch/arm/mt6261/lcd.c`:

```c
#define LCD_WROI_CMD        0x0004  /* Send LCD command */
#define LCD_WROI_DATA       0x0008  /* Send LCD data */
#define LCD_WROI_CTRL       0x0000  /* Control register */
#define LCD_STATUS          0x0100  /* Status register */
```

## Validation

Once updated, test with:

```bash
# Build the image
make openphone-stage1.bin

# Create flashable image
python3 arch/arm/mt6261/pack_gfh.py \
    openphone-stage1.bin dump_preloader.bin openphone-stage1-final.bin

# Flash and test on device
# Watch serial output for LCD initialization
```

## Troubleshooting

| Symptom | Cause | Fix |
|---------|-------|-----|
| No LCD display | Init sequence incomplete | Extract more commands from dump |
| Garbled display | Wrong pixel format | Check COLMOD (0x3A) command |
| Inverted display | MADCTL wrong | Adjust memory access control (0x36) |
| No output at all | LCD power not enabled | Check reset GPIO, add power commands |

## Additional Resources

- ILI9341 Datasheet: https://cdn-shop.adafruit.com/datasheets/ILI9341.pdf
- ST7789 Datasheet: https://github.com/prusa3d/Prusa-Firmware-Buddy/blob/master/lib/Marlin/Marlin/src/lcd/ST7789V_DRIVER.h
- MediaTek MT6261 (partial): Search OpenWrt/uClinux source code
