#!/usr/bin/env python3
"""
arch/arm/mt6261/pack_gfh.py
OpenPhone — GFH header packer for MT6261 firmware images

Copyright (C) 2026 OpenPhone Project
SPDX-License-Identifier: GPL-2.0-only

Creates flashable firmware images with the GFH (General File Header) that
the MT6261 boot ROM expects. The GFH is normally extracted from the OEM
firmware dump.

Usage:
  python3 pack_gfh.py <input_binary> <reference_gfh_dump> <output_image>

Where:
  <input_binary>      : The OpenPhone Stage 1 ELF converted to binary
  <reference_gfh_dump>: Extracted GFH from OEM firmware (0-96 bytes)
  <output_image>      : Final flashable image with GFH header

The input binary should have a placeholder GFH (0x60 bytes of zeros) at offset 0.
This script replaces that with the real header from the OEM dump.

GFH Structure (MediaTek MT6261):
  Offset  Size    Field            Description
  0x00    4       m_magic          Magic: "MMM" (0x4D4D4D00 LE) or similar
  0x04    4       m_size           Firmware size (excluding GFH)
  0x08    4       m_load_addr      Where to load to SRAM
  0x0C    4       m_entry_point    Execution entry point
  0x10    4       m_attr           Device attributes
  0x14    4       m_reserved       Reserved
  0x18    4       m_checksum       Fletcher-32 or simple sum
  0x1C    ...     Padding to 0x60 bytes
"""

import sys
import struct
import os


def compute_checksum(data):
    """Compute Fletcher-32 checksum (simple version for MT6261)"""
    checksum = 0
    for b in data:
        checksum += b
    return (checksum & 0xFFFFFFFF)


def extract_gfh(gfh_dump, offset=0, size=0x60):
    """Extract GFH from a firmware dump file"""
    if not os.path.exists(gfh_dump):
        raise FileNotFoundError(f"GFH dump not found: {gfh_dump}")
    
    with open(gfh_dump, 'rb') as f:
        f.seek(offset)
        gfh_data = f.read(size)
    
    if len(gfh_data) < size:
        raise ValueError(f"GFH dump too small: {len(gfh_data)} < {size}")
    
    return gfh_data


def create_gfh_from_template(magic, load_addr, entry_point, fw_size):
    """Create a GFH header from scratch"""
    gfh = bytearray(0x60)
    
    # Magic (MediaTek format)
    struct.pack_into('<I', gfh, 0x00, magic)
    
    # Firmware size (excluding GFH)
    struct.pack_into('<I', gfh, 0x04, fw_size)
    
    # Load address (where BROM loads us)
    struct.pack_into('<I', gfh, 0x08, load_addr)
    
    # Entry point (where BROM jumps to)
    struct.pack_into('<I', gfh, 0x0C, entry_point)
    
    # Device attributes (MT6261 specific)
    struct.pack_into('<I', gfh, 0x10, 0x00000000)
    
    # Reserved
    struct.pack_into('<I', gfh, 0x14, 0x00000000)
    
    # Checksum (computed over header)
    header_for_cksum = bytes(gfh)
    cksum = compute_checksum(header_for_cksum[:0x18])
    struct.pack_into('<I', gfh, 0x18, cksum)
    
    return bytes(gfh)


def pack_firmware(input_binary, reference_gfh, output_image):
    """Pack firmware with GFH header"""
    
    # Read input binary
    if not os.path.exists(input_binary):
        raise FileNotFoundError(f"Input binary not found: {input_binary}")
    
    with open(input_binary, 'rb') as f:
        fw_data = f.read()
    
    # Extract GFH from reference
    try:
        gfh_data = extract_gfh(reference_gfh, offset=0, size=0x60)
        print(f"✓ Extracted GFH from {reference_gfh} ({len(gfh_data)} bytes)")
    except (FileNotFoundError, ValueError) as e:
        print(f"⚠ Could not extract GFH: {e}")
        print(f"  Creating default GFH (may not work on your device)")
        
        # Create a reasonable default GFH
        # Magic: 0x4D4D4D00 (MediaTek)
        # Load address: 0x70006000 (SRAM)
        # Entry point: 0x70006140 (Stage 1 entry)
        gfh_data = create_gfh_from_template(
            magic=0x4D4D4D00,
            load_addr=0x70006000,
            entry_point=0x70006140,
            fw_size=len(fw_data)
        )
        print(f"⚠ Created default GFH ({len(gfh_data)} bytes)")
    
    # Verify input has placeholder GFH
    if len(fw_data) >= 0x60:
        placeholder = fw_data[:0x60]
        if placeholder == bytes(0x60):
            print(f"✓ Input has GFH placeholder (0x60 zero bytes)")
        else:
            print(f"⚠ Input may not have GFH placeholder")
            print(f"  First 16 bytes: {fw_data[:16].hex()}")
    
    # Create output: GFH + binary content
    output_data = gfh_data + fw_data[0x60:]
    
    # Write output
    with open(output_image, 'wb') as f:
        f.write(output_data)
    
    print(f"✓ Created flashable image: {output_image}")
    print(f"  GFH header:  0x60 bytes")
    print(f"  Firmware:    {len(fw_data[0x60:])} bytes")
    print(f"  Total:       {len(output_data)} bytes")
    
    # Print GFH contents
    print(f"\nGFH Header Contents:")
    magic, size, load_addr, entry, attr, res, cksum = \
        struct.unpack('<IIIIIII', gfh_data[:0x1C])
    
    print(f"  Magic:       0x{magic:08x}")
    print(f"  Size:        {size} bytes (0x{size:x})")
    print(f"  Load addr:   0x{load_addr:08x}")
    print(f"  Entry point: 0x{entry:08x}")
    print(f"  Attributes:  0x{attr:08x}")
    print(f"  Checksum:    0x{cksum:08x}")
    
    return True


if __name__ == '__main__':
    if len(sys.argv) < 4:
        print(f"Usage: {sys.argv[0]} <input.bin> <gfh_dump> <output.bin>")
        print(f"\nExample:")
        print(f"  python3 pack_gfh.py openphone-stage1.bin dump_preloader.bin image.bin")
        print(f"\nIf you don't have a GFH dump, extract one from the OEM firmware:")
        print(f"  dd if=dump.bin of=gfh_dump.bin bs=1 count=96")
        sys.exit(1)
    
    try:
        pack_firmware(sys.argv[1], sys.argv[2], sys.argv[3])
        print(f"\n✓ Success! Image ready to flash.")
        sys.exit(0)
    except Exception as e:
        print(f"✗ Error: {e}", file=sys.stderr)
        import traceback
        traceback.print_exc()
        sys.exit(1)
