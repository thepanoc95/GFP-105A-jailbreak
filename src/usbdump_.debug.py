#!/usr/bin/env python3
"""
mt6261_debug.py - Raw byte debugger for MT6261 BROM
Shows exactly what the BROM sends back at each stage.
"""
import sys, time, struct
try:
    import usb.core, usb.util
except ImportError:
    print("pip install pyusb"); sys.exit(1)

MTK_VID      = 0x0e8d
MTK_BROM_PID = 0x0003
USB_TIMEOUT  = 3000
USB_EP_OUT   = 0x01
USB_EP_IN    = 0x81

def find_dev():
    print("Plug in board...")
    deadline = time.time() + 30
    while time.time() < deadline:
        d = usb.core.find(idVendor=MTK_VID, idProduct=MTK_BROM_PID)
        if d: return d
        time.sleep(0.05)
    return None

def setup(dev):
    try:
        if dev.is_kernel_driver_active(0):
            dev.detach_kernel_driver(0)
    except Exception: pass
    dev.set_configuration()

def raw_read(dev, n=512, timeout=1000):
    """Read up to n bytes, return whatever arrives."""
    try:
        data = dev.read(USB_EP_IN, n, timeout)
        return bytes(data)
    except usb.core.USBTimeoutError:
        return b''
    except Exception as e:
        return f'ERR:{e}'.encode()

def raw_write(dev, data):
    if isinstance(data, int): data = bytes([data])
    dev.write(USB_EP_OUT, data, USB_TIMEOUT)

def hexshow(label, data):
    if not data:
        print(f"  {label}: <empty>")
        return
    hex_str = ' '.join(f'{b:02X}' for b in data[:64])
    print(f"  {label} ({len(data)}B): {hex_str}")

def drain(dev):
    """Drain all pending bytes."""
    total = b''
    while True:
        chunk = raw_read(dev, 512, 300)
        if not chunk: break
        total += chunk
    return total

def main():
    dev = find_dev()
    if not dev:
        print("Not found"); sys.exit(1)
    print(f"Found: bus {dev.bus} addr {dev.address}")
    setup(dev)

    # ── Step 1: Drain anything pending ──
    print("\n[0] Initial drain")
    leftover = drain(dev)
    hexshow("leftover", leftover)

    # ── Step 2: Handshake ──
    print("\n[1] Handshake (A0 0A 50 05, expect 5F F5 AF FA)")
    SEQ = [0xA0, 0x0A, 0x50, 0x05]
    EXP = [0x5F, 0xF5, 0xAF, 0xFA]
    for i, (s, e) in enumerate(zip(SEQ, EXP)):
        raw_write(dev, s)
        r = raw_read(dev, 512, 2000)
        hexshow(f"  sent {s:02X} got", r)
        if r and r[0] == e:
            print(f"    ✓ got {e:02X}")
        else:
            print(f"    ✗ expected {e:02X}")

    # ── Step 3: Drain after handshake ──
    print("\n[2] Drain after handshake")
    leftover = drain(dev)
    hexshow("leftover", leftover)

    # ── Step 4: CMD_GET_HW_CODE = 0xFD ──
    print("\n[3] CMD_GET_HW_CODE (0xFD)")
    raw_write(dev, 0xFD)
    time.sleep(0.1)
    r = drain(dev)
    hexshow("response", r)
    if len(r) >= 4:
        hw   = struct.unpack('>H', r[0:2])[0]
        stat = struct.unpack('>H', r[2:4])[0]
        print(f"    hw_code={hw:#06x}  status={stat:#06x}")

    # ── Step 5: Try CMD_READ32 manually ──
    print("\n[4] CMD_READ32 (0xD1) addr=0x00000000 count=4")
    # Build the full command in one write
    cmd = bytes([0xD1]) + struct.pack('>I', 0x00000000) + struct.pack('>I', 4)
    hexshow("sending", cmd)
    raw_write(dev, cmd)
    time.sleep(0.2)
    r = drain(dev)
    hexshow("response", r)
    if len(r) >= 2:
        status = struct.unpack('>H', r[0:2])[0]
        print(f"    status={status:#06x}")
        if status == 0 and len(r) >= 18:
            print(f"    data: {r[2:18].hex()}")

    # ── Step 6: Try sending command byte-by-byte with reads ──
    print("\n[5] CMD_READ32 byte-by-byte (watching each response)")
    drain(dev)
    parts = [
        ("CMD",   bytes([0xD1])),
        ("addr",  struct.pack('>I', 0x00000000)),
        ("count", struct.pack('>I', 4)),
    ]
    for name, data in parts:
        raw_write(dev, data)
        time.sleep(0.05)
        r = raw_read(dev, 512, 500)
        hexshow(f"  after {name}", r)

    print("\n[6] Final drain")
    r = drain(dev)
    hexshow("all remaining", r)

    usb.util.dispose_resources(dev)
    print("\nDone.")

if __name__ == '__main__':
    main()
