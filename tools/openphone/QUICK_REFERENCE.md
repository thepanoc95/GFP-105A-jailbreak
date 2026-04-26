# OpenPhone Quick Reference

## 📋 Quick Build

```bash
cd tools/openphone/arch/arm/mt6261
make                    # Build everything
make disasm             # Generate .dis for debugging
make size               # Show section sizes
make clean              # Clean artifacts
```

**Output**: `bin/openphone-stage1-final.bin` (ready to flash)

## 🔧 Toolchain Setup

```bash
# Linux
sudo apt install binutils-arm-linux-gnueabihf gcc-arm-linux-gnueabihf

# Test
arm-linux-gnueabihf-gcc --version
```

## 🐛 Build Fails?

| Error | Fix |
|-------|-----|
| `arm-linux-gnueabihf-gcc: not found` | Install toolchain (see above) |
| `mt6261.h: No such file` | `cd` to `arch/arm/mt6261/` |
| `undefined reference to ...` | Missing driver file, check Makefile |
| `GFH pack fails` | `GFH=../../binaries/dump_preloader.bin make` |

## 📺 Serial Console

```bash
# Connect at 115200 8N1
minicom -D /dev/ttyUSB0 -b 115200

# Or screen
screen /dev/ttyUSB0 115200

# Capture to file
screen -L /dev/ttyUSB0 115200
# View: cat screenlog.0
```

**Expected output after boot:**
```
OpenPhone/0.1
GFP-105A / MT6261

UART: OK
MSDC: OK
LCD: OK
Loading OpenBIOS...

ok _
```

## 🖥️ Interactive Forth Commands

```forth
ok .sysinfo              ( Show system info )
ok .console              ( Show active console )
ok hex                   ( Switch to hex mode )
ok d 70006000 20         ( Disassemble boot code )
ok sd-boot               ( Boot from SD card )
ok words                 ( List all words )
ok help lcd-pixel!       ( Help on a word )
```

## 🎨 LCD Not Working?

1. Check: Is text visible at all?
2. Run: `LCD_EXTRACTION_GUIDE.md` (extract real init)
3. Update: `arch/arm/mt6261/lcd.c` `mt6261_lcd_hw_init()`
4. Rebuild: `make clean && make`

## 📦 Files You'll Touch

| File | Purpose | Edit When |
|------|---------|-----------|
| `mt6261.h` | Hardware definitions | Adding new peripherals |
| `uart.c` | Serial driver | Baud rate or hardware issues |
| `msdc.c` | SD card driver | Card errors |
| `lcd.c` | Display driver | **LCD not working** |
| `Makefile` | Build rules | Changing compiler options |
| `ldscript` | Memory layout | Linker errors |
| `entry.S` | Boot code | Early crashes/hangs |

## 🔍 Debug Workflow

```bash
# 1. Build with symbols
cd arch/arm/mt6261
make

# 2. Check size
arm-linux-gnueabihf-size -A bin/openphone-stage1.elf

# 3. Disassemble problem area
make disasm
grep -A10 "70006000" bin/openphone-stage1.dis

# 4. Flash and monitor
minicom -D /dev/ttyUSB0 -b 115200
# Press keys to test
```

## 📊 Memory Layout

```
0x70000000  ┌─────────────────────────┐
            │   OPENPHONE STAGE 1     │
            │   ~65 KB available      │
0x70016800  ├─────────────────────────┤
            │   LCD FRAMEBUFFER       │
            │   150 KB (240x320 RGB)  │
0x7003FFFC  ├─────────────────────────┤
            │   STACK (growing down)  │
            └─────────────────────────┘
```

## ⚡ Performance Notes

- **No interrupts** - Uses polling (simple, but slow)
- **No interrupts** - Suitable for boot loader
- **UART**: 115200 baud = ~14 KB/sec max throughput
- **SD card**: ~1 MB/sec (depends on card and protocol)
- **LCD**: Framebuffer DMA (fast, no CPU overhead)

## 🔗 Important Addresses

```
0x70006000  Boot load address (BROM jumps here)
0x70006140  _start entry point (jump_off = 0x140)
0x70016800  LCD framebuffer (240x320 RGB565)
0x7003FFFC  Stack top
0x800B0000  LCD controller
0x80030000  UART0
0x80050000  MSDC (SD card)
0x80060000  USB device
```

## 🛠️ Makefile Targets

```bash
make                     # Build all: ELF → BIN → GFH-packed
make openphone-stage1.elf     # Just link ELF
make openphone-stage1.bin     # Just convert to binary
make openphone-stage1-final.bin  # Just pack with GFH
make disasm              # Generate disassembly
make size                # Show section sizes
make objlist             # List all symbols
make clean               # Remove build artifacts
make distclean           # Remove everything
```

## 🆘 Emergency Debug

If device hangs at boot:

```bash
# Add debug output to entry.S
# Between stack setup and SD init:
uart_puts("Stack OK\r\n");
uart_puts("About to init MSDC...\r\n");

# Recompile and see which message stops
# That's where the hang is
```

## 📝 Config Options

Edit `config.h` to enable/disable:

```c
#define CONFIG_UART         1    // Serial console
#define CONFIG_MSDC         1    // SD card
#define CONFIG_LCD          1    // Display
#define CONFIG_USB_CDC      1    // USB serial
#define CONFIG_DEBUG_SERIAL 1    // Verbose output
```

## 🚀 One-Line Build

```bash
cd tools/openphone/arch/arm/mt6261 && make clean && make && \
  echo "✓ Build complete: $(ls -lh bin/openphone-stage1-final.bin | awk '{print $9, $5}')"
```

## 📚 Key Documentation

- **BUILD_GUIDE.md** - Full build instructions
- **LCD_EXTRACTION_GUIDE.md** - Fix blank LCD
- **OPENPHONE_COMPLETION_SUMMARY.md** - Project overview
- **INDEX.md** - File reference

## 💡 Pro Tips

1. **Always save binary output**: `make > build.log 2>&1`
2. **Disassemble first failure**: `make disasm && grep ADDR bin/*.dis`
3. **Test incrementally**: Build → Disasm → Flash → Test
4. **Keep serial monitor open**: Catches boot messages you'd otherwise miss
5. **Serial is your debugger**: `uart_puts()` is your friend

## 🎯 Success Checklist

- [ ] Toolchain installed (`arm-linux-gnueabihf-gcc --version` works)
- [ ] Source extracted (`mt6261.h`, `uart.c`, etc. exist)
- [ ] Build succeeds (`make` completes with no errors)
- [ ] Binary generated (`bin/openphone-stage1-final.bin` exists)
- [ ] Image size OK (< 90 KB typically)
- [ ] Serial output works ("OpenPhone" banner on device)
- [ ] LCD initialized (display shows text/logo)
- [ ] SD card boots (OpenBIOS loads and ready prompt appears)

---

**OpenPhone v0.1 Quick Reference**  
Print this, laminate it, keep it by your workbench 📌
