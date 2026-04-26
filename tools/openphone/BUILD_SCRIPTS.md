# Build Scripts - Automated Compilation & GFH Packing

## Overview

Two convenient build scripts are provided:

- **`build-openphone.sh`** (Bash) - For Linux/macOS terminal
- **`build-openphone.py`** (Python) - Cross-platform alternative

Both scripts automate the entire build process:
1. Check ARM toolchain
2. Build Stage 1 bootloader
3. Find GFH dump from OEM firmware
4. Pack binary with GFH header
5. Generate optional disassembly

## Quick Start

### Option 1: Bash Script (Recommended for Linux)

```bash
cd tools/openphone

# Make executable (first time only)
chmod +x build-openphone.sh

# Build with auto-detected GFH
./build-openphone.sh

# Or with options
./build-openphone.sh --clean --disasm --verbose
```

### Option 2: Python Script (Cross-Platform)

```bash
cd tools/openphone

# Build with auto-detected GFH
python3 build-openphone.py

# Or with options
python3 build-openphone.py --clean --disasm --verbose
```

## Usage & Options

### Bash Script

```bash
./build-openphone.sh [OPTIONS]

OPTIONS:
  --clean       Remove old build artifacts before building
  --disasm      Generate disassembly (.dis file) after build
  --gfh PATH    Specify GFH dump file path (default: auto-search)
  --verbose     Show detailed build output
  -h, --help    Show help message
```

**Examples:**

```bash
# Simple build
./build-openphone.sh

# Clean build with all debug outputs
./build-openphone.sh --clean --disasm --verbose

# Use specific GFH dump
./build-openphone.sh --gfh ../../../binaries/dump_preloader.bin

# Combine options
./build-openphone.sh --clean --gfh dump.bin --disasm
```

### Python Script

```bash
python3 build-openphone.py [OPTIONS]

OPTIONS:
  --clean       Remove old build artifacts before building
  --disasm      Generate disassembly (.dis file) after build
  --gfh PATH    Specify GFH dump file path (default: auto-search)
  --verbose     Show detailed build output
  -h, --help    Show help message
```

**Examples:**

```bash
python3 build-openphone.py
python3 build-openphone.py --clean --disasm
python3 build-openphone.py --gfh /path/to/dump_preloader.bin --verbose
```

## What Happens During Build

### 1. Toolchain Check

Verifies `arm-linux-gnueabihf-gcc` is installed:

```
→ Checking ARM toolchain...
✓ Toolchain found: arm-linux-gnueabihf (GCC) 10.2.1...
```

If missing, install with:

```bash
sudo apt install binutils-arm-linux-gnueabihf gcc-arm-linux-gnueabihf
```

### 2. GFH Search

Automatically searches for GFH dump in common locations:

- `../../binaries/dump_preloader.bin` (project structure)
- `../../analysis/dump_preloader.bin`
- `./dump_preloader.bin` (current directory)
- And more...

Example:

```
→ Searching for GFH dump...
✓ Found GFH dump: ../../binaries/dump_preloader.bin
```

If not found, uses a default header (may not work on your device):

```
⚠ GFH dump not found - will create default header
```

### 3. Compilation

Runs `make` in `arch/arm/mt6261/`:

```
→ Building OpenPhone Stage 1...
  CC    uart.c
  CC    msdc.c
  CC    lcd.c
  AS    entry.S
  LINK  openphone-stage1.elf
  BIN   openphone-stage1.bin
✓ Build complete
```

### 4. Size Report

Shows binary sizes:

```
→ Image sizes:
  Total: 12345 bytes
  Binary: 12100 bytes (0x2f24)
```

### 5. GFH Packing

Creates flashable image:

```
→ Packing with GFH header...
✓ Final image: 12160 bytes (0x2f80)
```

### 6. Optional Disassembly

With `--disasm`:

```
→ Generating disassembly...
✓ Disassembly: bin/openphone-stage1.dis
```

## Output Files

After build, you'll have:

```
arch/arm/mt6261/bin/
├── openphone-stage1.elf              # Linked ELF (with symbols)
├── openphone-stage1.bin              # Raw binary
├── openphone-stage1-final.bin        # FLASHABLE IMAGE ← This one!
├── openphone-stage1.map              # Linker map file
├── openphone-stage1.syms             # Symbol table (if --disasm)
└── openphone-stage1.dis              # Disassembly (if --disasm)
```

**Important**: The **final.bin** file is what you flash to the device!

## Troubleshooting

### "arm-linux-gnueabihf-gcc not found"

Install the toolchain:

```bash
sudo apt install binutils-arm-linux-gnueabihf gcc-arm-linux-gnueabihf
```

Or use alternative:

```bash
export PATH=$PATH:~/arm-toolchain/bin  # If installed elsewhere
./build-openphone.sh
```

### "GFH dump not found"

Either:

1. Provide it manually:
   ```bash
   ./build-openphone.sh --gfh /path/to/dump_preloader.bin
   ```

2. Place it in expected location:
   ```bash
   cp /path/to/dump_preloader.bin ../../binaries/
   ```

3. Or extract from your firmware dump (see LCD_EXTRACTION_GUIDE.md)

### "Build failed"

Check the build log:

```bash
# With Python script:
python3 build-openphone.py --verbose

# With Bash script:
./build-openphone.sh --verbose
```

This shows detailed compiler errors.

### Final image size > 90 KB

Image is too large for SRAM between code and LCD framebuffer.

Try:

```bash
# Disable debug output in config.h
vim arch/arm/mt6261/config.h
# Set: #define CONFIG_VERBOSE_BOOT 0

./build-openphone.sh --clean
```

## Advanced Usage

### Build and Verify

```bash
# Build, disassemble, and check sizes
./build-openphone.sh --clean --disasm

# Check specific section
hexdump -C arch/arm/mt6261/bin/openphone-stage1-final.bin | head -20

# View disassembly around entry
grep -n "70006140" arch/arm/mt6261/bin/openphone-stage1.dis | head -5
```

### Continuous Integration

```bash
#!/bin/bash
# build-all.sh - For CI/CD pipeline

cd tools/openphone

# Build multiple times to ensure reproducibility
for i in {1..3}; do
    echo "Build attempt $i"
    ./build-openphone.sh --clean || exit 1
    cp arch/arm/mt6261/bin/openphone-stage1-final.bin \
       output/openphone-$i.bin
done

echo "All builds successful!"
```

### Custom GFH

Extract GFH from multiple firmware dumps:

```bash
# Create GFH library
mkdir gfh-library
dd if=dump1.bin of=gfh-library/dump1.gfh bs=1 count=96
dd if=dump2.bin of=gfh-library/dump2.gfh bs=1 count=96

# Test each
./build-openphone.sh --gfh gfh-library/dump1.gfh
./build-openphone.sh --gfh gfh-library/dump2.gfh

# Compare results
diff arch/arm/mt6261/bin/openphone-stage1-final.bin \
     arch/arm/mt6261/bin/openphone-stage1-final-v2.bin
```

## Performance Tips

### Faster Builds

Skip disassembly for faster iteration:

```bash
./build-openphone.sh          # Faster
./build-openphone.sh --disasm # Slower, but more debug info
```

### Parallel Make

Edit Makefile to use parallel jobs:

```bash
# In arch/arm/mt6261/Makefile, add:
# MAKEFLAGS = -j4

./build-openphone.sh  # Uses all 4 cores
```

### Cached Dependencies

Keep build artifacts between runs (no --clean):

```bash
./build-openphone.sh            # First build (full)
./build-openphone.sh            # Second build (incremental, faster)
./build-openphone.sh --clean    # Force full rebuild
```

## Integration with CI/CD

### GitHub Actions Example

```yaml
name: Build OpenPhone

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - name: Install toolchain
        run: sudo apt install -y binutils-arm-linux-gnueabihf gcc-arm-linux-gnueabihf
      - name: Build
        run: cd tools/openphone && python3 build-openphone.py --clean --disasm
      - name: Upload artifacts
        uses: actions/upload-artifact@v2
        with:
          name: openphone-build
          path: tools/openphone/arch/arm/mt6261/bin/
```

## Script Source Code

Both scripts are well-documented in the source:

- **build-openphone.sh** - ~150 lines, plain Bash
- **build-openphone.py** - ~350 lines, pure Python (no dependencies)

You can read and modify them to suit your needs.

## FAQ

**Q: Which script should I use?**  
A: `build-openphone.sh` for Linux/macOS, `build-openphone.py` for Windows or if Python is preferred.

**Q: Do the scripts require internet?**  
A: No, they're completely offline.

**Q: Can I use different GFH dumps?**  
A: Yes, with `--gfh` option. Different firmware versions may have different headers.

**Q: What if build fails halfway?**  
A: The scripts exit on error. Fix the issue and re-run (or use `--clean` to start fresh).

**Q: How do I see what commands are running?**  
A: Use `--verbose` flag to see full output including compiler commands.

**Q: Can I cross-compile on Windows?**  
A: Yes, using Windows Subsystem for Linux (WSL) or Cygwin. Use `build-openphone.py` for better compatibility.

---

## Summary

Both build scripts provide the same functionality:

- ✅ Automatic toolchain verification
- ✅ GFH dump auto-discovery
- ✅ Full build pipeline
- ✅ Optional disassembly generation
- ✅ Clear progress reporting
- ✅ Error handling with helpful messages

**Choose your preference**:
- **Bash**: Lighter weight, direct shell integration
- **Python**: Cross-platform, no shell needed

Both produce identical results. Use whichever is most convenient for your workflow!

---

**OpenPhone Build Scripts v0.1**  
(C) 2026 OpenPhone Project - GPL-2.0-only
