#!/usr/bin/env python3
"""
mt6261_dump.py - MT6261 BROM NOR flash dumper (USB bulk transport)
Talks directly to the MediaTek MT6261 Boot ROM via raw USB bulk transfers.
No pyserial, no DTR/RTS issues.

Usage:
    sudo python3 mt6261_dump.py [output.bin]

Requirements:
    pip install pyusb
    sudo apt install libusb-1.0-0

Procedure:
    1. Power OFF the board
    2. Run this script as root
    3. Plug in the USB cable
    Script detects 0e8d:0003 and begins automatically.

Output files:
    dump.bin              - full 4MB NOR flash image
    dump_preloader.bin    - preloader region (0x000000 - 0x007FFF)
    dump_factory.bin      - factory/calibration (0x3E0000 - 0x3FFFFF)
"""

import sys
import os
import time
import struct

try:
    import usb.core
    import usb.util
except ImportError:
    print("[ERROR] pyusb not installed.")
    print("  Run: pip install pyusb")
    print("  And: sudo apt install libusb-1.0-0")
    sys.exit(1)

# ── MTK BROM USB constants ───────────────────────────────────────────────────

MTK_VID           = 0x0e8d
MTK_BROM_PID      = 0x0003
MTK_PRE_PID       = 0x2000

USB_TIMEOUT       = 5000   # ms
USB_EP_OUT        = 0x01
USB_EP_IN         = 0x81
USB_PACKET_SIZE   = 512

# ── MT6261 BROM commands ─────────────────────────────────────────────────────

CMD_GET_HW_CODE   = 0xFD
CMD_READ32        = 0xD1

MT6261_HW_CODE    = 0x6261

NOR_BASE          = 0x00000000
NOR_SIZE          = 0x00400000  # 4MB

PRELOADER_END     = 0x00008000  # 32KB
FACTORY_START     = 0x003E0000

GFH_MAGIC         = b'MMM\x01'

# ── Logging ──────────────────────────────────────────────────────────────────

def log(msg='', end='\n'):
    print(msg, end=end, flush=True)

def log_progress(done, total):
    pct = done * 100 // total
    bar = ('█' * (pct // 2)).ljust(50)
    log(f'\r  [{bar}] {pct:3d}%  {done//1024}KB / {total//1024}KB', end='')

def hexdump(data, base=0, limit=64):
    for i in range(0, min(limit, len(data)), 16):
        chunk    = data[i:i+16]
        hex_part = ' '.join(f'{b:02X}' for b in chunk)
        asc_part = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
        log(f'  {base+i:08X}  {hex_part:<48}  {asc_part}')

# ── USB transport ─────────────────────────────────────────────────────────────

class BromUSB:
    """
    Buffered USB bulk transport for MT6261 BROM.
    Always reads full 512-byte USB packets to avoid LIBUSB_ERROR_OVERFLOW,
    then serves bytes from an internal buffer.
    """
    def __init__(self, dev, ep_out, ep_in):
        self.dev    = dev
        self.ep_out = ep_out
        self.ep_in  = ep_in
        self._buf   = bytearray()  # read-ahead buffer

    def write(self, data):
        if isinstance(data, int):
            data = bytes([data])
        self.dev.write(self.ep_out, data, USB_TIMEOUT)

    def _fill(self):
        """Read one full USB packet into the buffer."""
        try:
            chunk = self.dev.read(self.ep_in, USB_PACKET_SIZE, USB_TIMEOUT)
            self._buf.extend(chunk)
        except usb.core.USBTimeoutError:
            raise TimeoutError(
                f'USB read timeout (buffer has {len(self._buf)} bytes)'
            )

    def read(self, length):
        """Read exactly `length` bytes, buffering full USB packets."""
        while len(self._buf) < length:
            self._fill()
        data       = bytes(self._buf[:length])
        self._buf  = self._buf[length:]
        return data

    def read_byte(self):  return self.read(1)[0]
    def read_word(self):  return struct.unpack('>H', self.read(2))[0]
    def read_dword(self): return struct.unpack('>I', self.read(4))[0]

    def write_byte(self, b):  self.write(bytes([b]))
    def write_word(self, w):  self.write(struct.pack('>H', w))
    def write_dword(self, d): self.write(struct.pack('>I', d))

# ── Device setup ─────────────────────────────────────────────────────────────

def find_device(timeout=30):
    log('  Plug in the USB cable now...')
    deadline = time.time() + timeout
    while time.time() < deadline:
        dev = usb.core.find(idVendor=MTK_VID, idProduct=MTK_BROM_PID)
        if dev:
            return dev, 'BROM'
        dev = usb.core.find(idVendor=MTK_VID, idProduct=MTK_PRE_PID)
        if dev:
            return dev, 'preloader'
        time.sleep(0.05)
    return None, None

def setup_device(dev):
    # Detach cdc_acm or any kernel driver that grabbed it
    for cfg in dev:
        for intf in cfg:
            n = intf.bInterfaceNumber
            try:
                if dev.is_kernel_driver_active(n):
                    log(f'  Detaching kernel driver from interface {n}...')
                    dev.detach_kernel_driver(n)
            except Exception:
                pass

    dev.set_configuration()
    cfg  = dev.get_active_configuration()
    intf = cfg[(0, 0)]

    def is_bulk_out(e):
        return (usb.util.endpoint_direction(e.bEndpointAddress)
                == usb.util.ENDPOINT_OUT and
                usb.util.endpoint_type(e.bmAttributes)
                == usb.util.ENDPOINT_TYPE_BULK)

    def is_bulk_in(e):
        return (usb.util.endpoint_direction(e.bEndpointAddress)
                == usb.util.ENDPOINT_IN and
                usb.util.endpoint_type(e.bmAttributes)
                == usb.util.ENDPOINT_TYPE_BULK)

    ep_out = usb.util.find_descriptor(intf, custom_match=is_bulk_out)
    ep_in  = usb.util.find_descriptor(intf, custom_match=is_bulk_in)

    out_addr = ep_out.bEndpointAddress if ep_out else USB_EP_OUT
    in_addr  = ep_in.bEndpointAddress  if ep_in  else USB_EP_IN

    log(f'  Endpoints — OUT: {out_addr:#04x}  IN: {in_addr:#04x}')
    return BromUSB(dev, out_addr, in_addr)

# ── BROM handshake ────────────────────────────────────────────────────────────

def brom_handshake(brom: BromUSB):
    """
    MT6261 BROM start sequence.
    Send: A0 0A 50 05
    BROM echoes back the bitwise complement of each byte:
    Expect: 5F F5 AF FA
    """
    log('  Sending start sequence...')

    # Flush stale data
    try:
        brom.dev.read(brom.ep_in, 512, 200)
    except Exception:
        pass

    SEQ = [0xA0, 0x0A, 0x50, 0x05]
    EXP = [0x5F, 0xF5, 0xAF, 0xFA]

    for attempt in range(5):
        try:
            ok = True
            for send, expect in zip(SEQ, EXP):
                brom.write_byte(send)
                got = brom.read_byte()
                if got != expect:
                    log(f'  [WARN] seq byte: sent {send:#04x} '
                        f'expected {expect:#04x} got {got:#04x}')
                    ok = False
                    break
            if ok:
                log('  Start sequence OK')
                return
        except TimeoutError:
            log(f'  Attempt {attempt+1} timed out, retrying...')
            time.sleep(0.2)

    raise RuntimeError(
        'BROM handshake failed after 5 attempts.\n'
        '  - Unplug, power off, replug\n'
        '  - Short KCOLO to GND (near VOL pad) before plugging in\n'
        '  - Check USB cable supports data (not charge-only)'
    )

# ── BROM commands ─────────────────────────────────────────────────────────────

def get_hw_code(brom: BromUSB):
    brom.write_byte(CMD_GET_HW_CODE)
    # BROM echoes the command byte (0xFD) back first, then hw_code + status
    echo = brom.read_byte()   # discard echo (should be 0xFD)
    hw   = brom.read_word()
    stat = brom.read_word()
    return hw, stat

def flush_brom(brom: BromUSB):
    """Drain all pending BROM output — call after any failed/partial command."""
    brom._buf.clear()
    # Keep reading until we get two consecutive timeouts (line is truly idle)
    consecutive_timeouts = 0
    while consecutive_timeouts < 2:
        try:
            brom.dev.read(brom.ep_in, USB_PACKET_SIZE, 300)
            consecutive_timeouts = 0   # got data, keep draining
        except Exception:
            consecutive_timeouts += 1
    brom._buf.clear()

def read32_block(brom: BromUSB, addr, count):
    """Read `count` 32-bit words from `addr`. Returns bytes.
    
    MT6261 BROM response format:
      [echo: 1 + 4 + 4 = 9 bytes]  command echoed back
      [status: 2 bytes]             0x0000 = OK
      [data: count * 4 bytes]       little-endian 32-bit words
      [trailing status: 2 bytes]
    """
    brom.write_byte(CMD_READ32)
    brom.write_dword(addr)
    brom.write_dword(count)
    # Skip echo: BROM echoes cmd(1) + addr(4) + count(4) = 9 bytes
    brom.read(9)
    status = brom.read_word()
    if status != 0x0000:
        raise IOError(f'READ32 at {addr:#010x} status={status:#06x}')
    raw  = brom.read(count * 4)
    brom.read_word()  # trailing status
    # BROM sends 32-bit words in big-endian wire order; swap to LE for file
    out = bytearray(len(raw))
    for i in range(0, len(raw), 4):
        out[i:i+4] = raw[i:i+4][::-1]
    return bytes(out)

# ── GFH parser ────────────────────────────────────────────────────────────────

def parse_gfh(data):
    if len(data) < 36 or data[:4] != GFH_MAGIC:
        return None
    try:
        gfh = {
            'magic':       data[0:4].hex(),
            'version':     data[4],
            'hdr_size':    struct.unpack_from('<H', data,  5)[0],
            'file_type':   struct.unpack_from('<H', data,  7)[0],
            'flash_dev':   data[9],
            'sig_type':    data[10],
            'load_addr':   struct.unpack_from('<I', data, 12)[0],
            'file_len':    struct.unpack_from('<I', data, 16)[0],
            'max_size':    struct.unpack_from('<I', data, 20)[0],
            'content_off': struct.unpack_from('<I', data, 24)[0],
            'sig_len':     struct.unpack_from('<I', data, 28)[0],
            'jump_offset': struct.unpack_from('<I', data, 32)[0],
        }
        gfh['entry_point'] = gfh['load_addr'] + gfh['jump_offset']
        return gfh
    except struct.error:
        return None

def print_gfh(gfh):
    if not gfh:
        log('  [!] No valid GFH header at offset 0x0 — dump may still be usable')
        return
    log('  ┌─ GFH Header ──────────────────────────────────')
    log(f"  │  Magic:        {gfh['magic']}")
    log(f"  │  Load address: {gfh['load_addr']:#010x}  ← SRAM target")
    log(f"  │  Entry point:  {gfh['entry_point']:#010x}  ← ARM entry")
    log(f"  │  File length:  {gfh['file_len']:#010x}  ({gfh['file_len']} bytes)")
    log(f"  │  Jump offset:  {gfh['jump_offset']:#010x}")
    log(f"  │  Content off:  {gfh['content_off']:#010x}")
    log(f"  │  Sig type:     {gfh['sig_type']:#04x}  (0x00 = unsigned ✓)")
    log('  └───────────────────────────────────────────────')
    log(f"\n  → Preserve bytes 0x0000–{gfh['content_off']:#06x} verbatim in your bootloader")
    log(f"  → Your custom code starts at NOR offset {gfh['content_off']:#010x}")

# ── Dump ──────────────────────────────────────────────────────────────────────

BLOCK_WORDS = 64  # 1KB per request — conservative for BROM stability

def dump_nor(brom: BromUSB, out_path):
    log(f'\n  Dumping {NOR_SIZE // 1024}KB NOR flash → {out_path}')
    buf  = bytearray()
    addr = NOR_BASE

    with open(out_path, 'wb') as f:
        while addr < NOR_BASE + NOR_SIZE:
            remaining = (NOR_BASE + NOR_SIZE) - addr
            words     = min(BLOCK_WORDS, remaining // 4)
            if words == 0:
                break
            chunk = read32_block(brom, addr, words)
            f.write(chunk)
            buf.extend(chunk)
            addr += words * 4
            log_progress(addr - NOR_BASE, NOR_SIZE)

    log(f'\n  {len(buf)} bytes written.')
    return bytes(buf)

# ── Main ──────────────────────────────────────────────────────────────────────

def main():
    out_path = sys.argv[1] if len(sys.argv) > 1 else 'dump.bin'
    pre_path = out_path.replace('.bin', '_preloader.bin')
    fac_path = out_path.replace('.bin', '_factory.bin')

    log('═' * 56)
    log('  MT6261 BROM NOR Flash Dumper  [USB bulk]')
    log('  WD031 — 0e8d:0003')
    log('═' * 56)

    log('\n[1] Waiting for device')
    dev, mode = find_device(timeout=30)
    if dev is None:
        log('\n  [ERROR] Timed out. Is the board powered off when you plug in?')
        sys.exit(1)
    log(f'  Found 0e8d:{dev.idProduct:04x} ({mode}) — '
        f'bus {dev.bus} addr {dev.address}')
    if mode != 'BROM':
        log('  [WARN] Not in BROM mode — board may have already booted.')
        log('  [WARN] Power off and replug to catch BROM window.')

    log('\n[2] USB setup')
    try:
        brom = setup_device(dev)
    except Exception as e:
        log(f'  [ERROR] {e}')
        sys.exit(1)

    log('\n[3] Handshake')
    try:
        brom_handshake(brom)
    except RuntimeError as e:
        log(f'\n  [ERROR] {e}')
        sys.exit(1)

    log('\n[4] Chip ID')
    # Read HW code but treat errors as non-fatal and always flush after.
    # MT6261 BROM sometimes sends partial responses here; we never let
    # a bad CMD_GET_HW_CODE desync the buffer before the dump.
    try:
        hw, st = get_hw_code(brom)
        log(f'  HW code: {hw:#06x}  status: {st:#06x}')
        log(f'  {"✓ MT6261 confirmed" if hw == MT6261_HW_CODE else f"[WARN] unexpected code {hw:#06x}"}')
    except Exception as e:
        log(f'  [WARN] {e}')
    finally:
        # Always flush after CMD_GET_HW_CODE — it's unreliable on MT6261
        # and any leftover bytes will desync CMD_READ32.
        log('  Flushing after chip ID...')
        flush_brom(brom)
        log(f'  Buffer clear, {len(brom._buf)} bytes remaining')

    log('\n[5] Dump')
    try:
        data = dump_nor(brom, out_path)
    except Exception as e:
        log(f'\n  [ERROR] {e}')
        import traceback; traceback.print_exc()
        sys.exit(1)

    log('\n[6] GFH analysis')
    gfh = parse_gfh(data)
    print_gfh(gfh)

    log('\n[7] Preloader head:')
    hexdump(data, 0, 64)

    with open(pre_path, 'wb') as f:
        f.write(data[0:PRELOADER_END])
    with open(fac_path, 'wb') as f:
        f.write(data[FACTORY_START:NOR_SIZE])

    log(f'\n  Preloader → {pre_path}')
    log(f'  Factory   → {fac_path}')
    log('\n' + '═' * 56)
    log('  Done. Load dump_preloader.bin in Ghidra:')
    log('  ARM7EJ-S · little-endian · load at GFH load_addr')
    log('═' * 56)

    usb.util.dispose_resources(dev)

if __name__ == '__main__':
    main()
