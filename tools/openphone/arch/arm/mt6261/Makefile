# arch/arm/mt6261/Makefile
# OpenPhone MT6261 Stage 1 bootloader build

# Toolchain
CROSS_COMPILE ?= arm-linux-gnueabihf-
CC            = $(CROSS_COMPILE)gcc
AS            = $(CROSS_COMPILE)as
LD            = $(CROSS_COMPILE)ld
OBJCOPY       = $(CROSS_COMPILE)objcopy
OBJDUMP       = $(CROSS_COMPILE)objdump
STRIP         = $(CROSS_COMPILE)strip
NM            = $(CROSS_COMPILE)nm

# Architecture flags for ARMv5 (MT6261 is ARM7EJ-S)
ARCH_FLAGS    = -mcpu=arm7tdmi -march=armv5 -mthumb-interwork -mno-unaligned-access

# Compiler options
CFLAGS        = $(ARCH_FLAGS) \
                -ffreestanding \
                -nostdlib \
                -fno-common \
                -O2 \
                -g \
                -Wall -Werror \
                -Iinclude \
                -I.

ASFLAGS       = $(ARCH_FLAGS) \
                -g \
                --warn \
                --fatal-warnings

# Linker options
LDFLAGS       = -static \
                --warn-common \
                -nostdlib \
                -Tldscript

# Directories
SRCDIR        = $(CURDIR)
ODIR          = $(SRCDIR)/obj
BINDIR        = $(SRCDIR)/bin

# Source files
CSRCS         = uart.c msdc.c lcd.c console_lcd.c usb_cdc.c openbios.c
ASRCS         = entry.S

# Add devices.c from patch if building with Forth support
# CSRCS += devices.c

COBJS         = $(addprefix $(ODIR)/, $(CSRCS:.c=.o))
AOBJS         = $(addprefix $(ODIR)/, $(ASRCS:.S=.o))
OBJS          = $(COBJS) $(AOBJS)

# Final outputs
ELF           = $(BINDIR)/openphone-stage1.elf
BIN           = $(BINDIR)/openphone-stage1.bin
FINAL_BIN     = $(BINDIR)/openphone-stage1-final.bin
MAP           = $(BINDIR)/openphone-stage1.map
SYMS          = $(BINDIR)/openphone-stage1.syms

# Default target
all: $(FINAL_BIN)

# Create directories
$(ODIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

# Compile C files
$(ODIR)/%.o: %.c | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "  CC    $<"

# Assemble S files
$(ODIR)/%.o: %.S | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "  AS    $<"

# Link ELF
$(ELF): $(OBJS) ldscript | $(BINDIR)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) -Map=$(MAP)
	$(NM) $@ | sort > $(SYMS)
	@echo "  LINK  $@"
	@echo "  Symbols: $(SYMS)"
	@echo "  Map:     $(MAP)"

# Generate binary from ELF
$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@
	@echo "  BIN   $@"
	@echo "  Size: $$(wc -c < $@) bytes"

# Pack with GFH header
$(FINAL_BIN): $(BIN)
	@if [ -f "../../dumps/dump_preloader.bin" ]; then \
		GFH="../../dumps/dump_preloader.bin"; \
	elif [ -f "../../../analysis/dump_preloader.bin" ]; then \
		GFH="../../../analysis/dump_preloader.bin"; \
	elif [ -f "dump_preloader.bin" ]; then \
		GFH="dump_preloader.bin"; \
	else \
		GFH="$(GFH)"; \
	fi; \
	python3 pack_gfh.py $(BIN) $$GFH $@ || echo "⚠ Warning: Could not create final image"; \
	@echo "  PACK  $@"

# Disassembly
disasm: $(ELF)
	$(OBJDUMP) -D $< > $(BINDIR)/openphone-stage1.dis
	@echo "  DIS   $(BINDIR)/openphone-stage1.dis"

# Object listing
objlist: $(ELF)
	$(OBJDUMP) -t $< | sort > $(BINDIR)/openphone-stage1.objs
	@echo "  OBJS  $(BINDIR)/openphone-stage1.objs"

# Size analysis
size: $(ELF)
	$(CROSS_COMPILE)size -A $<

# Clean
clean:
	rm -rf $(ODIR) $(BINDIR)
	@echo "  CLEAN"

# Very clean (also remove .depends)
distclean: clean
	find . -name "*.o" -delete
	find . -name ".depends" -delete

# Help
help:
	@echo "OpenPhone MT6261 Stage 1 Build"
	@echo ""
	@echo "Targets:"
	@echo "  all         Build everything (default)"
	@echo "  $(ELF)   Link ELF executable"
	@echo "  $(BIN)      Convert to raw binary"
	@echo "  $(FINAL_BIN) Pack with GFH header"
	@echo "  disasm      Generate disassembly"
	@echo "  size        Show section sizes"
	@echo "  clean       Remove build artifacts"
	@echo ""
	@echo "Toolchain:"
	@echo "  CC:          $(CC)"
	@echo "  ARCH FLAGS:  $(ARCH_FLAGS)"
	@echo ""
	@echo "Environment:"
	@echo "  CROSS_COMPILE=arm-linux-gnueabihf- (or arm-none-eabi-)"
	@echo "  GFH=path/to/dump_preloader.bin     (for final packing)"

# Phony targets
.PHONY: all clean distclean help disasm objlist size
