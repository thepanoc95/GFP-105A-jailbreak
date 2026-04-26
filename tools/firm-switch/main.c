/*
 * openphone_flash.c
 * OpenPhone NOR flasher for MT6261 (GFP-105A / WD031)
 *
 * Flashes openphone-stage1-final.bin to NOR flash offset 0x000000
 * via the MT6261 Boot ROM USB interface (0e8d:0003).
 *
 * Based on mediatek_flash by ilyakurdyukov
 * https://github.com/ilyakurdyukov/mediatek_flash
 *
 * Build:
 *   gcc -O2 -Wall -o openphone_flash openphone_flash.c \
 *       $(pkg-config --cflags --libs libusb-1.0)
 *
 * Usage:
 *   sudo ./openphone_flash [options] <image.bin>
 *
 *   Options:
 *     --verify        Read back after write and verify (default: on)
 *     --no-verify     Skip readback verification
 *     --dry-run       Handshake and validate image but do not write
 *     --offset <hex>  NOR offset to flash to (default: 0x000000)
 *     --verbose       Show protocol traffic
 *     --wait <secs>   Seconds to wait for device (default: 30)
 *
 * Procedure:
 *   1. Power OFF the phone
 *   2. Run this tool
 *   3. Plug in the USB cable (phone powers on via USB)
 *   The BROM (0e8d:0003) will be detected and flashing begins.
 *
 * NOR flash layout (MX25L3291, 4MB):
 *   0x000000 - 0x007FFF   Preloader (Stage 1) ← we write here
 *   0x008000 - 0x03FFFF   DSP / secondary loader
 *   0x040000 - 0x3DFFFF   Main ROM
 *   0x3E0000 - 0x3FFFFF   Factory/calibration ← NEVER touch this
 *
 * WARNING: Do NOT flash past 0x008000 with this tool unless you know
 * exactly what you're doing. Overwriting the factory region will
 * brick the board permanently.
 */

#define _GNU_SOURCE 1

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <libusb-1.0/libusb.h>

/* ── Constants ──────────────────────────────────────────────────────────── */

#define MTK_VID             0x0e8d
#define MTK_BROM_PID        0x0003

#define NOR_BASE            0x00000000
#define NOR_SIZE            0x00400000  /* 4MB total                        */
#define PRELOADER_MAX       0x00008000  /* 32KB — safe write limit          */
#define FACTORY_START       0x003E0000  /* NEVER write here                 */

/* MT6261 BROM commands */
#define CMD_LEGACY_READ     0xa2
#define CMD_READ16          0xd0
#define CMD_READ32          0xd1
#define CMD_WRITE16         0xd2
#define CMD_WRITE32         0xd4
#define CMD_JUMP_DA         0xd5
#define CMD_SEND_DA         0xd7
#define CMD_GET_HW_CODE     0xfd

/* MT6261 chip ID */
#define MT6261_HW_CODE      0x6261

/* GFH magic */
#define GFH_MAGIC           0x014d4d4d  /* 'MMM\x01' little-endian */

/* USB transfer parameters */
#define USB_TIMEOUT         5000        /* ms                               */
#define RECV_BUF_LEN        4096
#define TEMP_BUF_LEN        4096
#define SEND_CHUNK          1024        /* bytes per bulk write             */

/* ── Error/logging macros ───────────────────────────────────────────────── */

#define ERR_EXIT(...) \
    do { fprintf(stderr, "[ERROR] " __VA_ARGS__); exit(1); } while (0)

#define LOG(...)     fprintf(stderr, __VA_ARGS__)
#define INFO(...)    fprintf(stderr, "[INFO]  " __VA_ARGS__)
#define WARN(...)    fprintf(stderr, "[WARN]  " __VA_ARGS__)
#define OK(...)      fprintf(stderr, "[OK]    " __VA_ARGS__)

/* ── USB I/O context ────────────────────────────────────────────────────── */

typedef struct {
    libusb_device_handle *dev;
    int ep_in;
    int ep_out;
    int verbose;
    int timeout;
    uint8_t recv_buf[RECV_BUF_LEN];
    uint8_t buf[TEMP_BUF_LEN];
    int recv_len;
    int recv_pos;
} usbio_t;

/* ── Big-endian helpers (BROM protocol is big-endian) ───────────────────── */

#define W16BE(p, v) do { \
    ((uint8_t*)(p))[0] = (v) >> 8; \
    ((uint8_t*)(p))[1] = (uint8_t)(v); \
} while (0)

#define W32BE(p, v) do { \
    ((uint8_t*)(p))[0] = (v) >> 24; \
    ((uint8_t*)(p))[1] = (v) >> 16; \
    ((uint8_t*)(p))[2] = (v) >> 8; \
    ((uint8_t*)(p))[3] = (uint8_t)(v); \
} while (0)

#define R16BE(p) ((uint16_t)( \
    ((uint8_t*)(p))[0] << 8 | ((uint8_t*)(p))[1]))

#define R32BE(p) ((uint32_t)( \
    (uint32_t)((uint8_t*)(p))[0] << 24 | \
    (uint32_t)((uint8_t*)(p))[1] << 16 | \
    (uint32_t)((uint8_t*)(p))[2] << 8  | \
    (uint32_t)((uint8_t*)(p))[3]))

#define R32LE(p) ((uint32_t)( \
    (uint32_t)((uint8_t*)(p))[3] << 24 | \
    (uint32_t)((uint8_t*)(p))[2] << 16 | \
    (uint32_t)((uint8_t*)(p))[1] << 8  | \
    (uint32_t)((uint8_t*)(p))[0]))

/* ── USB device setup ───────────────────────────────────────────────────── */

static void find_endpoints(libusb_device_handle *dev, int *ep_in, int *ep_out)
{
    struct libusb_config_descriptor *cfg;
    libusb_device *device = libusb_get_device(dev);
    int i, k, err;

    *ep_in = *ep_out = -1;

    err = libusb_get_config_descriptor(device, 0, &cfg);
    if (err < 0)
        ERR_EXIT("libusb_get_config_descriptor: %s\n", libusb_error_name(err));

    for (k = 0; k < cfg->bNumInterfaces; k++) {
        const struct libusb_interface *iface = cfg->interface + k;
        if (iface->num_altsetting < 1) continue;
        const struct libusb_interface_descriptor *idesc = iface->altsetting;

        for (i = 0; i < idesc->bNumEndpoints; i++) {
            const struct libusb_endpoint_descriptor *ep = idesc->endpoint + i;
            if ((ep->bmAttributes & 3) != LIBUSB_TRANSFER_TYPE_BULK) continue;
            int addr = ep->bEndpointAddress;
            if (addr & LIBUSB_ENDPOINT_IN)
                *ep_in  = addr;
            else
                *ep_out = addr;
        }

        if (*ep_in >= 0 && *ep_out >= 0) {
            int inum = idesc->bInterfaceNumber;
            err = libusb_kernel_driver_active(dev, inum);
            if (err > 0) {
                INFO("Detaching kernel driver from interface %d\n", inum);
                err = libusb_detach_kernel_driver(dev, inum);
                if (err < 0)
                    ERR_EXIT("detach_kernel_driver: %s\n", libusb_error_name(err));
            }
            err = libusb_claim_interface(dev, inum);
            if (err < 0)
                ERR_EXIT("claim_interface: %s\n", libusb_error_name(err));
            break;
        }
    }
    libusb_free_config_descriptor(cfg);

    if (*ep_in  < 0) ERR_EXIT("Bulk IN endpoint not found\n");
    if (*ep_out < 0) ERR_EXIT("Bulk OUT endpoint not found\n");
}

static usbio_t *usbio_open(libusb_device_handle *dev, int verbose)
{
    usbio_t *io = calloc(1, sizeof(usbio_t));
    if (!io) ERR_EXIT("calloc failed\n");

    io->dev     = dev;
    io->verbose = verbose;
    io->timeout = USB_TIMEOUT;

    find_endpoints(dev, &io->ep_in, &io->ep_out);
    INFO("Endpoints — IN: 0x%02x  OUT: 0x%02x\n", io->ep_in, io->ep_out);
    return io;
}

static void usbio_free(usbio_t *io)
{
    if (!io) return;
    libusb_close(io->dev);
    free(io);
}

/* ── Low-level USB send/recv ────────────────────────────────────────────── */

static void usb_send(usbio_t *io, const void *data, int len)
{
    const uint8_t *buf = data ? (const uint8_t *)data : io->buf;
    int ret, err;

    if (io->verbose >= 2) {
        LOG("  TX (%d):", len);
        int i; for (i = 0; i < len && i < 16; i++) LOG(" %02x", buf[i]);
        if (len > 16) LOG(" ...");
        LOG("\n");
    }

    err = libusb_bulk_transfer(io->dev, io->ep_out,
                               (uint8_t *)buf, len, &ret, io->timeout);
    if (err < 0)
        ERR_EXIT("usb_send failed: %s\n", libusb_error_name(err));
    if (ret != len)
        ERR_EXIT("usb_send short write: %d / %d\n", ret, len);
}

static int usb_recv(usbio_t *io, int want)
{
    int got = 0;

    if (want > TEMP_BUF_LEN)
        ERR_EXIT("usb_recv: want %d > TEMP_BUF_LEN\n", want);

    while (got < want) {
        /* Drain recv buffer first */
        while (io->recv_pos < io->recv_len && got < want)
            io->buf[got++] = io->recv_buf[io->recv_pos++];

        if (got >= want) break;

        /* Need more data */
        int nread = 0;
        int err = libusb_bulk_transfer(io->dev, io->ep_in,
                                       io->recv_buf, RECV_BUF_LEN,
                                       &nread, io->timeout);
        if (err == LIBUSB_ERROR_NO_DEVICE)
            ERR_EXIT("Device disconnected\n");
        if (err == LIBUSB_ERROR_TIMEOUT) break;
        if (err < 0)
            ERR_EXIT("usb_recv failed: %s\n", libusb_error_name(err));

        io->recv_len = nread;
        io->recv_pos = 0;
    }

    if (io->verbose >= 2 && got > 0) {
        LOG("  RX (%d):", got);
        int i; for (i = 0; i < got && i < 16; i++) LOG(" %02x", io->buf[i]);
        if (got > 16) LOG(" ...");
        LOG("\n");
    }

    return got;
}

static void mtk_echo(usbio_t *io, const void *data, int len)
{
    const uint8_t *ptr = (const uint8_t *)data;
    usb_send(io, ptr, len);
    int ret = usb_recv(io, len);
    if (ret != len || memcmp(io->buf, ptr, len))
        ERR_EXIT("BROM echo mismatch (sent %d, got %d)\n", len, ret);
}

static void mtk_echo8(usbio_t *io, uint32_t v)
{
    uint8_t b = v;
    mtk_echo(io, &b, 1);
}

static void mtk_echo16(usbio_t *io, uint32_t v)
{
    uint8_t b[2]; W16BE(b, v);
    mtk_echo(io, b, 2);
}

static void mtk_echo32(usbio_t *io, uint32_t v)
{
    uint8_t b[4]; W32BE(b, v);
    mtk_echo(io, b, 4);
}

static uint8_t mtk_recv8(usbio_t *io)
{
    if (usb_recv(io, 1) != 1)
        ERR_EXIT("mtk_recv8: no data\n");
    return io->buf[0];
}

static uint16_t mtk_recv16(usbio_t *io)
{
    if (usb_recv(io, 2) != 2)
        ERR_EXIT("mtk_recv16: no data\n");
    return R16BE(io->buf);
}

static uint32_t mtk_recv32(usbio_t *io)
{
    if (usb_recv(io, 4) != 4)
        ERR_EXIT("mtk_recv32: no data\n");
    return R32BE(io->buf);
}

static void mtk_check_status(usbio_t *io)
{
    uint16_t st = mtk_recv16(io);
    if (st != 0x0000)
        ERR_EXIT("BROM error status: 0x%04x\n", st);
}

static void mtk_handshake(usbio_t *io)
{
    static const uint8_t hs[4] = { 0xa0, 0x0a, 0x50, 0x05 };
    int i;

    INFO("Performing BROM handshake...\n");
    for (i = 0; i < 4; i++) {
        usb_send(io, &hs[i], 1);
        uint8_t r = mtk_recv8(io);
        if ((r ^ hs[i]) != 0xff) {
            /* Already done? */
            if (r == 0 && i == 0) {
                INFO("Handshake already completed\n");
                return;
            }
            ERR_EXIT("Handshake failed at byte %d: sent 0x%02x got 0x%02x\n",
                     i, hs[i], r);
        }
    }
    OK("Handshake OK\n");
}

static uint16_t mtk_get_hw_code(usbio_t *io)
{
    mtk_echo8(io, CMD_GET_HW_CODE);
    uint16_t hw  = mtk_recv16(io);
    uint16_t _st = mtk_recv16(io); (void)_st;
    return hw;
}

static void mtk_disable_watchdog(usbio_t *io)
{
    mtk_echo8(io,  CMD_WRITE16);
    mtk_echo32(io, 0xa0030000);
    mtk_echo32(io, 1);
    mtk_check_status(io);
    mtk_echo16(io, 0x2200);
    mtk_check_status(io);
}

static uint32_t mtk_read32(usbio_t *io, uint32_t addr)
{
    mtk_echo8(io,  CMD_READ32);
    mtk_echo32(io, addr);
    mtk_echo32(io, 1);
    mtk_check_status(io);
    uint32_t val = mtk_recv32(io);
    mtk_check_status(io);
    return val;
}

static void mtk_write16(usbio_t *io, uint32_t addr, uint16_t val)
{
    mtk_echo8(io,  CMD_WRITE16);
    mtk_echo32(io, addr);
    mtk_echo32(io, 1);
    mtk_check_status(io);
    mtk_echo16(io, val);
    mtk_check_status(io);
}

typedef struct {
    uint32_t magic;         /* 0x014d4d4d                                   */
    uint8_t  version;
    uint16_t hdr_size;
    uint16_t file_type;
    uint8_t  flash_dev;
    uint8_t  sig_type;      /* 0 = unsigned                                 */
    uint32_t load_addr;     /* SRAM target: 0x70006000                      */
    uint32_t file_len;
    uint32_t max_size;
    uint32_t content_off;   /* 0x00000140                                   */
    uint32_t sig_len;
    uint32_t jump_off;      /* 0x00000140                                   */
} gfh_t;

static int validate_gfh(const uint8_t *buf, size_t size, gfh_t *out)
{
    gfh_t g;

    if (size < 0x60) return 0;

    g.magic       = R32LE(buf + 0x00);
    g.version     = buf[0x04];
    g.hdr_size    = buf[0x05] | buf[0x06] << 8;
    g.file_type   = buf[0x07] | buf[0x08] << 8;
    g.flash_dev   = buf[0x09];
    g.sig_type    = buf[0x0a];
    g.load_addr   = R32LE(buf + 0x0c);
    g.file_len    = R32LE(buf + 0x10);
    g.max_size    = R32LE(buf + 0x14);
    g.content_off = R32LE(buf + 0x18);
    g.sig_len     = R32LE(buf + 0x1c);
    g.jump_off    = R32LE(buf + 0x20);

    if (g.magic != GFH_MAGIC)
        return 0;

    if (out) *out = g;
    return 1;
}

static uint16_t calc_checksum(const uint8_t *buf, size_t size)
{
    uint32_t chk = 0;
    size_t i;
    for (i = 0; i + 1 < size; i += 2)
        chk ^= (uint32_t)buf[i] | ((uint32_t)buf[i+1] << 8);
    if (size & 1) chk ^= buf[i];
    return (uint16_t)chk;
}

static void print_progress(const char *label, uint32_t done, uint32_t total)
{
    int pct = (int)(done * 100 / total);
    int bar = pct / 2;
    int i;
    fprintf(stderr, "\r  %s [", label);
    for (i = 0; i < 50; i++) fputc(i < bar ? '#' : ' ', stderr);
    fprintf(stderr, "] %3d%%  %uKB/%uKB",
            pct, done / 1024, total / 1024);
    if (done >= total) fputc('\n', stderr);
}

static void nor_read(usbio_t *io, uint32_t addr, uint8_t *dst, uint32_t size)
{
    uint32_t off = 0;
    uint32_t step = 256;  /* 256 dwords = 1KB per request */

    while (off < size) {
        uint32_t n     = size - off;
        uint32_t words = (n + 3) / 4;
        if (words > step) words = step;
        uint32_t bytes = words * 4;

        mtk_echo8(io,  CMD_READ32);
        mtk_echo32(io, addr + off);
        mtk_echo32(io, words);
        mtk_check_status(io);

        uint32_t got = usb_recv(io, bytes);
        if (got != bytes)
            ERR_EXIT("nor_read: short read %u/%u at 0x%08x\n",
                     got, bytes, addr + off);

        /* Swap BE→LE */
        uint32_t i;
        for (i = 0; i + 3 < got; i += 4) {
            uint32_t v = R32BE(io->buf + i);
            dst[off + i + 0] = v & 0xff;
            dst[off + i + 1] = (v >> 8) & 0xff;
            dst[off + i + 2] = (v >> 16) & 0xff;
            dst[off + i + 3] = (v >> 24) & 0xff;
        }

        mtk_check_status(io);
        off += bytes;
    }
}

/* ── Download Agent (DA) send and jump ──────────────────────────────────── */

/*
 * For NOR flash write, the BROM can't write flash directly — we need to
 * upload a small Download Agent (DA) into SRAM and jump to it.
 * The DA then handles flash erase and write on our behalf.
 *
 * For the GFP-105A, we use the same approach as ilyakurdyukov's tool:
 * BROM SEND_DA → load DA binary into SRAM → JUMP_DA → DA handles flash.
 *
 * If no DA binary is provided, we fall back to using BROM WRITE16
 * directly (works for NOR but is slow and has limitations).
 *
 * When a DA is provided:
 *   Protocol after jump: DA speaks a higher-level protocol over USB.
 *   This is the standard MediaTek SP Flash Tool DA protocol.
 */

static void send_da(usbio_t *io, const uint8_t *da, size_t da_size,
                    uint32_t load_addr, uint32_t sig_len)
{
    uint16_t chk_sent, chk_calc;

    INFO("Sending Download Agent (%zu bytes) to 0x%08x...\n",
         da_size, load_addr);

    mtk_echo8(io,  CMD_SEND_DA);
    mtk_echo32(io, load_addr);
    mtk_echo32(io, (uint32_t)da_size);
    mtk_echo32(io, sig_len);
    mtk_check_status(io);

    chk_calc = calc_checksum(da, da_size);

    /* Send in chunks */
    size_t off = 0;
    while (off < da_size) {
        size_t n = da_size - off;
        if (n > SEND_CHUNK) n = SEND_CHUNK;
        usb_send(io, da + off, (int)n);
        off += n;
        print_progress("Sending DA", (uint32_t)off, (uint32_t)da_size);
    }

    chk_sent = mtk_recv16(io);
    if (chk_sent != chk_calc)
        ERR_EXIT("DA checksum mismatch: got 0x%04x expected 0x%04x\n",
                 chk_sent, chk_calc);
    mtk_check_status(io);
    OK("DA uploaded OK (checksum 0x%04x)\n", chk_calc);
}

static void jump_da(usbio_t *io, uint32_t addr)
{
    INFO("Jumping to DA at 0x%08x...\n", addr);
    mtk_echo8(io,  CMD_JUMP_DA);
    mtk_echo32(io, addr);
    mtk_check_status(io);
}

/* ── Direct NOR write via BROM WRITE16 (no DA needed for preloader slot) ──
 *
 * MT6261 NOR flash (MX25L3291) is memory-mapped at 0x00000000.
 * The BROM exposes WRITE16 which lets us program it directly.
 * This works for the preloader region (first 32KB) since it uses
 * the standard NOR flash CFI write algorithm.
 *
 * Sequence per 16-bit word:
 *   1. Write unlock cycle 1: addr 0x5555 → data 0xAAAA
 *   2. Write unlock cycle 2: addr 0x2AAA → data 0x5555
 *   3. Write program cmd:    addr 0x5555 → data 0xA0A0
 *   4. Write data word to target address
 *   5. Poll until DQ7 = data[7] (data polling for completion)
 *
 * For erase (sector erase, 64KB sectors):
 *   1-3: Same unlock sequence
 *   4. Write erase setup:    addr 0x5555 → data 0x8080
 *   5-7: Repeat unlock
 *   8. Write sector erase:   target_addr → data 0x3030
 *   9. Poll DQ3 (sector erase timer) then DQ7
 */

static void nor_write_word(usbio_t *io, uint32_t addr, uint16_t data)
{
    /* CFI AMD/Fujitsu unlock sequence */
    mtk_write16(io, 0x00005555, 0xAAAA);
    mtk_write16(io, 0x00002AAA, 0x5555);
    mtk_write16(io, 0x00005555, 0xA0A0);
    mtk_write16(io, addr, data);
    /* Poll — read back until data matches */
    int timeout = 10000;
    while (timeout--) {
        uint32_t v = mtk_read32(io, addr & ~3);
        uint16_t got;
        if (addr & 2)
            got = (uint16_t)(v >> 16);
        else
            got = (uint16_t)v;
        if (got == data) return;
        usleep(10);
    }
    ERR_EXIT("NOR write timeout at 0x%08x\n", addr);
}

static void nor_erase_sector(usbio_t *io, uint32_t addr)
{
    /* 64KB sector erase */
    addr &= ~0xFFFF;  /* align to 64KB */
    mtk_write16(io, 0x00005555, 0xAAAA);
    mtk_write16(io, 0x00002AAA, 0x5555);
    mtk_write16(io, 0x00005555, 0x8080);
    mtk_write16(io, 0x00005555, 0xAAAA);
    mtk_write16(io, 0x00002AAA, 0x5555);
    mtk_write16(io, addr,       0x3030);

    /* Poll DQ7 for completion (may take up to 2 seconds per sector) */
    INFO("Erasing sector at 0x%08x...", addr);
    int timeout = 200000;
    while (timeout--) {
        uint32_t v = mtk_read32(io, addr);
        if ((v & 0x0080) == 0x0080 && ((v >> 16) & 0x0080) == 0x0080) {
            fprintf(stderr, " done\n");
            return;
        }
        usleep(100);
    }
    ERR_EXIT("Sector erase timeout at 0x%08x\n", addr);
}

static void nor_write(usbio_t *io, uint32_t addr, const uint8_t *data,
                      uint32_t size)
{
    uint32_t off;

    /* Erase all sectors we're going to write */
    uint32_t sector_start = addr & ~0xFFFF;
    uint32_t sector_end   = (addr + size + 0xFFFF) & ~0xFFFF;
    uint32_t s;
    for (s = sector_start; s < sector_end; s += 0x10000)
        nor_erase_sector(io, s);

    /* Write 16 bits at a time */
    for (off = 0; off < size; off += 2) {
        uint16_t word;
        if (off + 1 < size)
            word = (uint16_t)data[off] | ((uint16_t)data[off + 1] << 8);
        else
            word = (uint16_t)data[off] | 0xFF00; /* pad last byte with 0xFF */
        nor_write_word(io, addr + off, word);
        if ((off & 0x1FF) == 0)
            print_progress("Writing", off, size);
    }
    print_progress("Writing", size, size);
}

static uint8_t *load_file(const char *path, size_t *out_size)
{
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    size_t sz = (size_t)ftell(f);
    rewind(f);
    uint8_t *buf = malloc(sz);
    if (!buf) { fclose(f); return NULL; }
    if (fread(buf, 1, sz, f) != sz) {
        fclose(f); free(buf); return NULL;
    }
    fclose(f);
    if (out_size) *out_size = sz;
    return buf;
}

static void usage(const char *prog)
{
    fprintf(stderr,
        "OpenPhone NOR Flasher for MT6261 (GFP-105A)\n"
        "\n"
        "Usage:\n"
        "  sudo %s [options] <image.bin>\n"
        "\n"
        "Options:\n"
        "  --offset <hex>   NOR offset to flash (default: 0x000000)\n"
        "  --verify         Read back and verify after write (default: on)\n"
        "  --no-verify      Skip readback verification\n"
        "  --dry-run        Validate image without writing\n"
        "  --verbose        Show USB protocol traffic\n"
        "  --wait <secs>    Seconds to wait for device (default: 30)\n"
        "\n"
        "Procedure:\n"
        "  1. Power OFF the phone\n"
        "  2. Run this tool\n"
        "  3. Plug in USB cable\n"
        "\n"
        "Example:\n"
        "  sudo %s openphone-stage1-final.bin\n"
        "  sudo %s --offset 0x0 --verify openphone-stage1-final.bin\n"
        "\n"
        "WARNING: Do not flash past 0x008000 (factory region starts at\n"
        "         0x3E0000 and must never be overwritten).\n",
        prog, prog, prog);
    exit(1);
}


int main(int argc, char **argv)
{
    const char *image_path = NULL;
    uint32_t    nor_offset = 0x000000;
    int         do_verify  = 1;
    int         dry_run    = 0;
    int         verbose    = 0;
    int         wait_secs  = 30;
    int         i;

    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--offset")) {
            if (++i >= argc) usage(argv[0]);
            nor_offset = (uint32_t)strtoul(argv[i], NULL, 0);
        } else if (!strcmp(argv[i], "--verify")) {
            do_verify = 1;
        } else if (!strcmp(argv[i], "--no-verify")) {
            do_verify = 0;
        } else if (!strcmp(argv[i], "--dry-run")) {
            dry_run = 1;
        } else if (!strcmp(argv[i], "--verbose")) {
            verbose = 1;
        } else if (!strcmp(argv[i], "--wait")) {
            if (++i >= argc) usage(argv[0]);
            wait_secs = atoi(argv[i]);
        } else if (argv[i][0] == '-') {
            fprintf(stderr, "Unknown option: %s\n\n", argv[i]);
            usage(argv[0]);
        } else {
            image_path = argv[i];
        }
    }

    if (!image_path) {
        fprintf(stderr, "No image file specified.\n\n");
        usage(argv[0]);
    }

    fprintf(stderr, "═══════════════════════════════════════════════\n");
    fprintf(stderr, "  OpenPhone Flasher  —  MT6261 / GFP-105A\n");
    fprintf(stderr, "═══════════════════════════════════════════════\n\n");

    size_t img_size = 0;
    uint8_t *img = load_file(image_path, &img_size);
    if (!img)
        ERR_EXIT("Cannot open image file: %s\n", image_path);

    INFO("Image: %s (%zu bytes)\n", image_path, img_size);

    gfh_t gfh;
    if (!validate_gfh(img, img_size, &gfh)) {
        if (img_size > 0x800 && validate_gfh(img + 0x800, img_size - 0x800, &gfh)) {
            WARN("SF_BOOT header detected — GFH is at offset 0x800\n");
            WARN("Flash target is the preloader region inside the dump.\n");
            WARN("Use pack_gfh.py to prepare a proper flash image first.\n");
            ERR_EXIT("Please use pack_gfh.py to prepare the flash image.\n");
        } else {
            ERR_EXIT("No valid GFH header found in image.\n"
                     "Run: python3 pack_gfh.py stage1.bin dump_preloader.bin %s\n",
                     image_path);
        }
    }

    INFO("GFH: load_addr=0x%08x  entry=0x%08x  file_len=0x%08x\n",
         gfh.load_addr, gfh.load_addr + gfh.jump_off, gfh.file_len);

    if (gfh.sig_type != 0)
        WARN("sig_type=0x%02x — image may be signed, BROM might reject it\n",
             gfh.sig_type);

    /* Safety check */
    if (nor_offset + img_size > PRELOADER_MAX) {
        WARN("Image extends past preloader region (0x%08x > 0x%08x)\n",
             nor_offset + (uint32_t)img_size, PRELOADER_MAX);
        WARN("Continuing, but be very careful not to overwrite DSP/ROM.\n");
    }
    if (nor_offset + img_size > FACTORY_START)
        ERR_EXIT("Image would overwrite factory region! Aborting.\n");

    if (dry_run) {
        OK("Dry run — image validated OK, not writing.\n");
        free(img);
        return 0;
    }

    /* ── Find BROM device ── */
    int err = libusb_init(NULL);
    if (err < 0)
        ERR_EXIT("libusb_init: %s\n", libusb_error_name(err));

    INFO("Waiting for MT6261 BROM (0e8d:0003)...\n");
    INFO("Plug in USB cable now.\n\n");

    libusb_device_handle *dev = NULL;
    for (i = 0; i < wait_secs * 2; i++) {
        dev = libusb_open_device_with_vid_pid(NULL, MTK_VID, MTK_BROM_PID);
        if (dev) break;
        if (i == 0) fprintf(stderr, "  ");
        fputc('.', stderr);
        fflush(stderr);
        usleep(500000);
    }
    if (!dev) {
        fprintf(stderr, "\n");
        ERR_EXIT("Device not found after %d seconds.\n", wait_secs);
    }
    fprintf(stderr, "\n");
    INFO("Device found!\n");

    usbio_t *io = usbio_open(dev, verbose);

    /* ── BROM protocol ── */
    mtk_handshake(io);

    uint16_t hw_code = mtk_get_hw_code(io);
    INFO("HW code: 0x%04x", hw_code);
    if (hw_code == MT6261_HW_CODE)
        fprintf(stderr, " (MT6261 ✓)\n");
    else
        fprintf(stderr, " (unexpected — expected 0x%04x)\n", MT6261_HW_CODE);

    /* Disable watchdog so it doesn't reset us mid-flash */
    INFO("Disabling watchdog...\n");
    mtk_disable_watchdog(io);

    /* ── Write NOR flash ── */
    fprintf(stderr, "\n");
    INFO("Flashing %zu bytes to NOR offset 0x%08x\n", img_size, nor_offset);
    nor_write(io, nor_offset, img, (uint32_t)img_size);
    OK("Write complete\n");

    /* ── Verify ── */
    if (do_verify) {
        fprintf(stderr, "\n");
        INFO("Verifying...\n");
        uint8_t *readback = malloc(img_size);
        if (!readback)
            ERR_EXIT("malloc for verify buffer failed\n");

        nor_read(io, nor_offset, readback, (uint32_t)img_size);

        if (memcmp(img, readback, img_size) == 0) {
            OK("Verify PASSED — image matches NOR flash ✓\n");
        } else {
            /* Find first mismatch */
            uint32_t mismatch = 0;
            for (mismatch = 0; mismatch < (uint32_t)img_size; mismatch++)
                if (img[mismatch] != readback[mismatch]) break;
            ERR_EXIT("Verify FAILED at offset 0x%08x "
                     "(wrote 0x%02x, read 0x%02x)\n",
                     nor_offset + mismatch,
                     img[mismatch], readback[mismatch]);
        }
        free(readback);
    }

    fprintf(stderr, "\n═══════════════════════════════════════════════\n");
    fprintf(stderr, "  Flash complete!\n");
    fprintf(stderr, "  Offset: 0x%08x  Size: %zu bytes\n",
            nor_offset, img_size);
    fprintf(stderr, "  Unplug and replug the phone to boot OpenPhone.\n");
    fprintf(stderr, "═══════════════════════════════════════════════\n");

    free(img);
    usbio_free(io);
    libusb_exit(NULL);
    return 0;
}