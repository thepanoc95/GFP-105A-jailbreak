#!/usr/bin/env python3
"""
mt6261_dump.py - MT6261 BROM NOR flash dumper
Talks directly to the MediaTek MT6261 Boot ROM over USB VCOM or UART.

Usage:
    python3 mt6261_dump.py [port] [output.bin]

    port       : serial port, e.g. /dev/ttyUSB0 or /dev/ttyACM0
                 (default: auto-detect)
    output.bin : output file for flash dump
                 (default: dump.bin)

Requirements:
    pip install pyserial

How to use:
    1. Power OFF the board
    2. Run this script
    3. Plug in the USB cable (board will power on via USB)
    The BROM will be detected and the dump will start automatically.

    If the board has no USB power delivery (bare PCB):
    - Power via DC+/DC- pads externally
    - Short KCOLO to GND BEFORE powering on
    - Then run script and plug USB data cable

MT6261 NOR flash map (MX25L3291, 4MB):
    0x00000000 - 0x00007FFF : Preloader (32KB)
    0x00008000 - 0x0003FFFF : DSP / secondary loader
    0x00040000 - 0x003DFFFF : Main ROM / firmware
    0x003E0000 - 0x003FFFFF : Factory / calibration data
"""

import termios, fcntl, tty
import sys
import os
import time
import struct
import serial
import serial.tools.list_ports

# ── MT6261 BROM constants ────────────────────────────────────────────────────

BROM_HANDSHAKE_BYTE  = 0xC0      # BROM sends this repeatedly on power-on
BROM_HANDSHAKE_ACK   = 0x0F      # We reply with this
BROM_START_CMD       = 0xA0      # Start command sequence
BROM_BAUDRATE        = 115200    # Initial BROM baud rate

# MT6261 BROM command set (feature phone BROM, not Android BROM)
CMD_READ16           = 0xA2      # Read 16-bit word
CMD_READ32           = 0xD1      # Read 32-bit word  
CMD_WRITE16          = 0xA3      # Write 16-bit word
CMD_WRITE32          = 0xD4      # Write 32-bit word
CMD_JUMP_DA          = 0xD5      # Jump to download agent
CMD_GET_HW_CODE      = 0xFD      # Get hardware code (chip ID)
CMD_GET_HW_DICT      = 0xFC      # Get hardware dictionary
CMD_SEND_DA          = 0xD7      # Send download agent
CMD_NOR_READ         = 0xD6      # NOR flash read (via DA)

# MT6261 chip ID
MT6261_HW_CODE       = 0x6261

# NOR flash parameters for MX25L3291 (standard on WD031 boards)
NOR_BASE_ADDR        = 0x00000000
NOR_SIZE_DEFAULT     = 0x00400000  # 4MB

# MT6261 memory map
SRAM_BASE            = 0x70000000
SRAM_SIZE            = 0x00040000  # 256KB

# ── Utility ──────────────────────────────────────────────────────────────────

def log(msg, end='\n'):
    print(msg, end=end, flush=True)

def log_progress(done, total):
    pct  = done * 100 // total
    bar  = ('█' * (pct // 2)).ljust(50)
    kb   = done // 1024
    tkb  = total // 1024
    print(f'\r  [{bar}] {pct:3d}%  {kb}KB / {tkb}KB', end='', flush=True)

def hexdump(data, offset=0, length=64):
    """Print a short hex dump for debugging."""
    for i in range(0, min(length, len(data)), 16):
        chunk = data[i:i+16]
        hex_part  = ' '.join(f'{b:02X}' for b in chunk)
        ascii_part = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
        print(f'  {offset+i:08X}  {hex_part:<48}  {ascii_part}')

# ── Serial port helpers ───────────────────────────────────────────────────────

def find_mtk_port():
    """Auto-detect MTK USB VCOM port."""
    candidates = []
    for port in serial.tools.list_ports.comports():
        desc = (port.description or '').lower()
        manu = (port.manufacturer or '').lower()
        vid  = port.vid
        pid  = port.pid
        # MTK VCOM: VID=0x0e8d, PID=0x0003 (BROM) or 0x2000 (preloader)
        if vid == 0x0e8d and pid in (0x0003, 0x2000, 0x0023):
            candidates.insert(0, port.device)  # prefer exact match
        elif 'mediatek' in desc or 'mediatek' in manu:
            candidates.append(port.device)
        elif 'mt65' in desc or 'mt62' in desc:
            candidates.append(port.device)
        elif vid == 0x0e8d:
            candidates.append(port.device)
    return candidates[0] if candidates else None

def open_port(port, baud=BROM_BAUDRATE):
    ser = serial.Serial()
    ser.port         = port
    ser.baudrate     = baud
    ser.bytesize     = serial.EIGHTBITS
    ser.parity       = serial.PARITY_NONE
    ser.stopbits     = serial.STOPBITS_ONE
    ser.timeout      = 2.0
    ser.write_timeout = 2.0
    ser.dsrdtr       = False
    ser.rtscts       = False
    ser.xonxoff      = False
    # Open without triggering DTR/RTS
    ser.open()
    ser.dtr = False
    ser.rts = False
    return ser

# ── BROM protocol ─────────────────────────────────────────────────────────────

def send_byte(ser, b):
    ser.write(bytes([b]))

def recv_byte(ser, timeout=3.0):
    ser.timeout = timeout
    data = ser.read(1)
    if not data:
        raise TimeoutError("No response from BROM")
    return data[0]

def send_word(ser, w):
    """Send a 16-bit big-endian word."""
    ser.write(struct.pack('>H', w))

def send_dword(ser, d):
    """Send a 32-bit big-endian dword."""
    ser.write(struct.pack('>I', d))

def recv_word(ser):
    data = ser.read(2)
    if len(data) < 2:
        raise TimeoutError("Timeout reading word")
    return struct.unpack('>H', data)[0]

def recv_dword(ser):
    data = ser.read(4)
    if len(data) < 4:
        raise TimeoutError("Timeout reading dword")
    return struct.unpack('>I', data)[0]

def brom_handshake(ser):
    """
    Wait for BROM handshake byte (0xC0) and complete the handshake.
    The MT6261 BROM sends 0xC0 repeatedly after power-on.
    We reply 0x0F, BROM replies 0x0F back.
    """
    log("  Waiting for BROM handshake (power on the board now)...")
    ser.reset_input_buffer()

    deadline = time.time() + 30.0
    while time.time() < deadline:
        b = ser.read(1)
        if not b:
            continue
        if b[0] == BROM_HANDSHAKE_BYTE:
            # Echo back the handshake
            send_byte(ser, BROM_HANDSHAKE_ACK)
            # BROM should echo our ACK back
            ack = ser.read(1)
            if ack and ack[0] == BROM_HANDSHAKE_ACK:
                log("  Handshake OK")
                return True
            else:
                # Some MT6261 variants just send 0xC0 without echoing ACK
                log("  Handshake OK (no echo variant)")
                return True

    raise TimeoutError("BROM handshake timed out — is the board powering on?")

def brom_get_hw_code(ser):
    """Read the hardware code (chip ID) from BROM."""
    send_byte(ser, CMD_GET_HW_CODE)
    hw_code = recv_word(ser)
    status  = recv_word(ser)
    return hw_code, status

def brom_read32(ser, addr):
    """Read a single 32-bit value from the given address."""
    send_byte(ser, CMD_READ32)
    send_dword(ser, addr)
    send_dword(ser, 1)       # count = 1
    status = recv_word(ser)
    if status != 0:
        raise IOError(f"READ32 failed at {addr:#010x}, status={status:#06x}")
    value  = recv_dword(ser)
    status = recv_word(ser)
    return value

def brom_nor_read_block(ser, addr, length):
    """
    Read a block from NOR flash via BROM memory-mapped access.
    MT6261 NOR flash is memory-mapped starting at 0x00000000 in the
    BROM address space, so we can use READ32 directly.
    length must be a multiple of 4.
    """
    send_byte(ser, CMD_READ32)
    send_dword(ser, addr)
    count = length // 4
    send_dword(ser, count)
    status = recv_word(ser)
    if status != 0:
        raise IOError(f"NOR read failed at {addr:#010x}, status={status:#06x}")
    data = ser.read(length)
    if len(data) < length:
        raise IOError(f"Short read: expected {length}, got {len(data)}")
    status = recv_word(ser)
    return data

# ── GFH header parser ─────────────────────────────────────────────────────────

GFH_MAGIC = b'MMM\x01'

def parse_gfh(data):
    """Parse the GFH (General Flash Header) from preloader data."""
    if data[:4] != GFH_MAGIC:
        return None
    try:
        # GFH_FILE_INFO structure (simplified)
        magic       = data[0:4]
        version     = data[4]
        size        = struct.unpack_from('<H', data, 5)[0]
        file_type   = struct.unpack_from('<H', data, 7)[0]
        flash_dev   = data[9]
        sig_type    = data[10]
        load_addr   = struct.unpack_from('<I', data, 12)[0]
        file_len    = struct.unpack_from('<I', data, 16)[0]
        max_size    = struct.unpack_from('<I', data, 20)[0]
        content_off = struct.unpack_from('<I', data, 24)[0]
        sig_len     = struct.unpack_from('<I', data, 28)[0]
        jump_offset = struct.unpack_from('<I', data, 32)[0]
        return {
            'magic':       magic.hex(),
            'version':     version,
            'hdr_size':    size,
            'file_type':   file_type,
            'flash_dev':   flash_dev,
            'sig_type':    sig_type,
            'load_addr':   load_addr,
            'file_len':    file_len,
            'max_size':    max_size,
            'content_off': content_off,
            'sig_len':     sig_len,
            'jump_offset': jump_offset,
            'entry_point': load_addr + jump_offset,
        }
    except struct.error:
        return None

def print_gfh(gfh):
    if not gfh:
        log("  [!] No valid GFH header found at offset 0")
        return
    log("  ┌─ GFH Header ──────────────────────────────")
    log(f"  │  Magic:        {gfh['magic']}")
    log(f"  │  Load address: {gfh['load_addr']:#010x}")
    log(f"  │  Entry point:  {gfh['entry_point']:#010x}")
    log(f"  │  File length:  {gfh['file_len']:#010x} ({gfh['file_len']} bytes)")
    log(f"  │  Max size:     {gfh['max_size']:#010x}")
    log(f"  │  Content off:  {gfh['content_off']:#010x}")
    log(f"  │  Jump offset:  {gfh['jump_offset']:#010x}")
    log(f"  │  Flash device: {gfh['flash_dev']:#04x}")
    log(f"  │  Sig type:     {gfh['sig_type']:#04x}")
    log("  └───────────────────────────────────────────")

# ── Main dump routine ─────────────────────────────────────────────────────────

BLOCK_SIZE = 0x1000   # 4KB per read request

def dump_nor(ser, out_path, size=NOR_SIZE_DEFAULT):
    log(f"\n  Dumping {size // 1024}KB NOR flash → {out_path}")
    data = bytearray()
    addr = NOR_BASE_ADDR

    with open(out_path, 'wb') as f:
        while addr < NOR_BASE_ADDR + size:
            remaining = (NOR_BASE_ADDR + size) - addr
            block     = min(BLOCK_SIZE, remaining)
            chunk     = brom_nor_read_block(ser, addr, block)
            f.write(chunk)
            data.extend(chunk)
            addr += block
            log_progress(addr - NOR_BASE_ADDR, size)

    log(f"\n  Done. {len(data)} bytes written.")
    return bytes(data)

# ── Entry point ───────────────────────────────────────────────────────────────

def main():
    port_arg   = sys.argv[1] if len(sys.argv) > 1 else None
    output     = sys.argv[2] if len(sys.argv) > 2 else 'dump.bin'

    log("═" * 56)
    log("  MT6261 BROM NOR Flash Dumper")
    log("  WD031 / MTK6261 feature phone board")
    log("═" * 56)

    # Resolve port
    if port_arg:
        port = port_arg
    else:
        log("\n  Auto-detecting MTK USB VCOM port...")
        port = find_mtk_port()
        if port:
            log(f"  Found: {port}")
        else:
            log("  No MTK port found yet — will retry after board powers on")
            log("  Plug in USB cable now...")
            deadline = time.time() + 30
            while time.time() < deadline:
                port = find_mtk_port()
                if port:
                    log(f"  Found: {port}")
                    break
                time.sleep(0.1)
            if not port:
                log("\n  [ERROR] Could not find MTK port.")
                log("  Try: python3 mt6261_dump.py /dev/ttyUSB0 dump.bin")
                sys.exit(1)

    log(f"\n  Opening {port} at {BROM_BAUDRATE} baud...")
    try:
        ser = open_port(port)
        try:
            ser.dtr = False
            ser.rts = False
        except Exception:
            pass
    except serial.SerialException as e:
        log(f"  [ERROR] Could not open port: {e}")
        log(f"  Try: sudo python3 {sys.argv[0]} {port}")
        sys.exit(1)

    try:
        # Step 1: Handshake
        log("\n[1] BROM Handshake")
        brom_handshake(ser)

        # Step 2: Identify chip
        log("\n[2] Chip identification")
        try:
            hw_code, status = brom_get_hw_code(ser)
            log(f"  HW code: {hw_code:#06x}  status: {status:#06x}")
            if hw_code == MT6261_HW_CODE:
                log("  ✓ MT6261 confirmed")
            else:
                log(f"  [WARN] Unexpected HW code {hw_code:#06x} — continuing anyway")
        except Exception as e:
            log(f"  [WARN] Could not read HW code: {e} — continuing anyway")

        # Step 3: Dump
        log("\n[3] NOR Flash dump")
        flash_data = dump_nor(ser, output)

        # Step 4: Parse GFH
        log("\n[4] GFH Header analysis")
        gfh = parse_gfh(flash_data)
        print_gfh(gfh)

        # Step 5: Hexdump preloader head
        log("\n[5] Preloader head (first 64 bytes):")
        hexdump(flash_data, 0, 64)

        # Step 6: Save preloader region separately
        preloader_path = output.replace('.bin', '_preloader.bin')
        with open(preloader_path, 'wb') as f:
            f.write(flash_data[0x0000:0x8000])
        log(f"\n  Preloader region (0x0000-0x7FFF) saved → {preloader_path}")

        # Step 7: Save factory/calibration region separately
        factory_path = output.replace('.bin', '_factory.bin')
        with open(factory_path, 'wb') as f:
            f.write(flash_data[0x3E0000:0x400000])
        log(f"  Factory region  (0x3E0000-0x3FFFFF) saved → {factory_path}")

        log("\n═" * 56)
        log("  Dump complete!")
        log(f"  Full image:   {output}")
        log(f"  Preloader:    {preloader_path}")
        log(f"  Factory data: {factory_path}")
        log("\n  Next steps:")
        log("  1. Open dump.bin in Ghidra (ARM7EJ-S, little-endian)")
        log("  2. Load at address from GFH load_addr field above")
        log("  3. Find MSDC init sequence for SD card bootloader")
        log("═" * 56)

    except KeyboardInterrupt:
        log("\n\n  Interrupted.")
    except Exception as e:
        log(f"\n  [ERROR] {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)
    finally:
        ser.close()

if __name__ == '__main__':
    main()
