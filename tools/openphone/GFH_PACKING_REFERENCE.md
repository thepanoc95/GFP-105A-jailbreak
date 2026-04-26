# GFH Packing Tools - Quick Reference

## Tools Available

You now have **three ways** to pack GFH binaries:

### 1. 🔧 Direct Python Tool (Low-level)

```bash
cd arch/arm/mt6261
python3 pack_gfh.py input.bin gfh_dump.bin output.bin
```

**For**: Fine-grained control, scripting  
**Pros**: Direct, transparent  
**Cons**: Requires manual build steps  
**See**: `pack_gfh.py` comments for advanced usage

### 2. 🚀 Bash Wrapper (Recommended for Linux)

```bash
cd tools/openphone
./build-openphone.sh [--clean] [--disasm] [--gfh PATH]
```

**For**: Quick one-command builds  
**Pros**: Automates everything, colored output  
**Cons**: Bash/Linux only  
**See**: `BUILD_SCRIPTS.md` for full docs

### 3. 🐍 Python Wrapper (Cross-Platform)

```bash
cd tools/openphone
python3 build-openphone.py [--clean] [--disasm] [--gfh PATH]
```

**For**: Windows, macOS, any platform  
**Pros**: Works everywhere Python runs  
**Cons**: Slightly slower than Bash  
**See**: `BUILD_SCRIPTS.md` for full docs

---

## Common Workflows

### Quick Build (Recommended)

```bash
cd tools/openphone
./build-openphone.sh
# Output: arch/arm/mt6261/bin/openphone-stage1-final.bin
```

### With Disassembly for Debugging

```bash
./build-openphone.sh --disasm
# Also generates: bin/openphone-stage1.dis
```

### Manual GFH Packing Only

```bash
cd arch/arm/mt6261
make                                    # Build binary
python3 pack_gfh.py \
  bin/openphone-stage1.bin \
  dump_preloader.bin \
  bin/openphone-stage1-final.bin
```

### Full Clean Rebuild

```bash
./build-openphone.sh --clean --disasm --verbose
```

---

## Workflow: From Firmware Dump to Flashable Image

```
1. Locate firmware dump
   └─ Usually: ../../binaries/dump_preloader.bin

2. Build bootloader
   └─ Command: ./build-openphone.sh

3. Script finds GFH in dump
   └─ Extracts: First 96 bytes (0x60)

4. Binary packed with GFH
   └─ Creates: bin/openphone-stage1-final.bin

5. Output ready to flash
   └─ Size: ~12 KB
```

---

## GFH Header Format

MediaTek GFH (General File Header):

```
Offset  Size  Field           Example
0x00    4     Magic           0x4D4D4D00 ("MMM")
0x04    4     Firmware Size   0x00003000
0x08    4     Load Address    0x70006000
0x0C    4     Entry Point     0x70006140
0x10    4     Attributes      0x00000000
0x14    4     Reserved        0x00000000
0x18    4     Checksum        0x12345678
0x1C    60    Padding         (zeros)
```

**Total**: 96 bytes (0x60)

---

## Troubleshooting GFH Packing

| Issue | Solution |
|-------|----------|
| **File not found** | Check paths, use absolute paths |
| **Invalid GFH** | Get from correct firmware dump, not random file |
| **Wrong checksum** | Script auto-computes, shouldn't be problem |
| **Device won't boot** | Wrong GFH header, try extraction guide |

---

## File Sizes (Typical)

```
Binary sizes (varies with config):

openphone-stage1.elf      ~20 KB  (with symbols)
openphone-stage1.bin      ~12 KB  (code only)
openphone-stage1-final.bin~12 KB  (+ 96B GFH header)

Max allowed: 90 KB (before LCD framebuffer at 0x70016800)
```

---

## One-Liner Examples

```bash
# Build everything
cd tools/openphone && ./build-openphone.sh

# Build + disassemble
cd tools/openphone && ./build-openphone.sh --disasm

# Use specific GFH dump
cd tools/openphone && ./build-openphone.sh --gfh /path/to/dump.bin

# Python version (Windows compatible)
cd tools/openphone && python3 build-openphone.py

# Direct tool (manual)
cd tools/openphone/arch/arm/mt6261 && python3 pack_gfh.py bin/openphone-stage1.bin dump.bin bin/openphone-stage1-final.bin

# Verify output
hexdump -C tools/openphone/arch/arm/mt6261/bin/openphone-stage1-final.bin | head -20
```

---

## Checking Your Image

```bash
# File size
ls -lh bin/openphone-stage1-final.bin

# First 96 bytes (should be GFH, not zeros)
hexdump -C bin/openphone-stage1-final.bin | head -6

# Extract GFH header
dd if=bin/openphone-stage1-final.bin of=gfh_extracted.bin bs=1 count=96

# Compare with original
cmp gfh_extracted.bin dump_preloader.bin
```

---

## Next Steps

1. **Run build script**: `./build-openphone.sh`
2. **Check output**: `ls -lh arch/arm/mt6261/bin/openphone-stage1-final.bin`
3. **Flash to device**: (varies by device/tool)
4. **Test on hardware**: Connect serial @ 115200 8N1

---

## Tool Chain

```
Source Code
    ↓
  [Build]    ← Makefile
    ↓
openphone-stage1.bin  (raw binary, no header)
    ↓
  [Pack]    ← pack_gfh.py / build-openphone.sh
    ↓
openphone-stage1-final.bin  (+ GFH header, flashable)
    ↓
 [Flash]   ← MTK Client or UART tool
    ↓
Device NOR at 0x00000000
```

---

## Scripts Overview

| Script | Type | Lines | Purpose |
|--------|------|-------|---------|
| `pack_gfh.py` | Tool | 150 | Low-level GFH packer |
| `build-openphone.sh` | Wrapper | 150 | Bash automation |
| `build-openphone.py` | Wrapper | 350 | Python automation |

**All three are in**: `tools/openphone/`

---

## Make Targets (Used by Scripts)

```bash
cd arch/arm/mt6261

make                      # Build all
make openphone-stage1.elf
make openphone-stage1.bin
make openphone-stage1-final.bin  # With GFH
make disasm               # Disassembly
make size                 # Show sizes
make clean
```

---

**TL;DR**: Use `./build-openphone.sh` in `tools/openphone/` and you're done! 🚀
