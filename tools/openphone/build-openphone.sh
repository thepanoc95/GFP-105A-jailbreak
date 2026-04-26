#!/bin/bash
# build-openphone.sh
# OpenPhone — Automated build and GFH packing script
#
# Copyright (C) 2026 OpenPhone Project
# SPDX-License-Identifier: GPL-2.0-only
#
# Usage: ./build-openphone.sh [--clean] [--disasm] [--gfh <path>]
#
# This script:
#   1. Builds the Stage 1 bootloader
#   2. Finds or uses the specified GFH dump
#   3. Packs the binary with GFH header
#   4. Optionally generates disassembly
#   5. Reports results

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/arch/arm/mt6261"
BINARIES_DIR="$SCRIPT_DIR/../../binaries"
ANALYSIS_DIR="$SCRIPT_DIR/../../analysis"

# Defaults
GFH_PATH=""
CLEAN=0
DISASM=0
VERBOSE=0

# Functions
print_header() {
    echo -e "${BLUE}╔═══════════════════════════════════════╗${NC}"
    echo -e "${BLUE}║${NC}  OpenPhone Build & Pack Script v0.1   ${BLUE}║${NC}"
    echo -e "${BLUE}╚═══════════════════════════════════════╝${NC}"
    echo ""
}

print_step() {
    echo -e "${BLUE}→${NC} $1"
}

print_success() {
    echo -e "${GREEN}✓${NC} $1"
}

print_error() {
    echo -e "${RED}✗${NC} $1" >&2
}

print_warning() {
    echo -e "${YELLOW}⚠${NC} $1"
}

find_gfh() {
    # Search for GFH dump in common locations
    local candidates=(
        "$1"  # User specified
        "$BINARIES_DIR/dump_preloader.bin"
        "$BINARIES_DIR/dump.bin"
        "$ANALYSIS_DIR/dump_preloader.bin"
        "$ANALYSIS_DIR/dump.bin"
        "$BUILD_DIR/dump_preloader.bin"
        "./dump_preloader.bin"
        "./dump.bin"
        "../dump_preloader.bin"
    )
    
    for path in "${candidates[@]}"; do
        if [ -f "$path" ] && [ -s "$path" ]; then
            echo "$path"
            return 0
        fi
    done
    return 1
}

show_usage() {
    cat << 'EOF'
Usage: ./build-openphone.sh [OPTIONS]

OPTIONS:
  --clean       Remove old build artifacts before building
  --disasm      Generate disassembly (.dis file) after build
  --gfh PATH    Specify GFH dump file path (default: auto-search)
  --verbose     Show detailed build output
  -h, --help    Show this help message

EXAMPLES:
  # Build with auto-detected GFH
  ./build-openphone.sh

  # Clean build with disassembly
  ./build-openphone.sh --clean --disasm

  # Use specific GFH dump
  ./build-openphone.sh --gfh /path/to/dump_preloader.bin

EOF
}

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --clean)
            CLEAN=1
            shift
            ;;
        --disasm)
            DISASM=1
            shift
            ;;
        --gfh)
            GFH_PATH="$2"
            shift 2
            ;;
        --verbose)
            VERBOSE=1
            shift
            ;;
        -h|--help)
            show_usage
            exit 0
            ;;
        *)
            print_error "Unknown option: $1"
            show_usage
            exit 1
            ;;
    esac
done

# Main script
print_header

# Check toolchain
print_step "Checking ARM toolchain..."
if ! command -v arm-linux-gnueabihf-gcc &> /dev/null; then
    print_error "arm-linux-gnueabihf-gcc not found"
    print_warning "Install with: sudo apt install binutils-arm-linux-gnueabihf gcc-arm-linux-gnueabihf"
    exit 1
fi
print_success "Toolchain found: $(arm-linux-gnueabihf-gcc --version | head -1)"

# Check build directory
if [ ! -d "$BUILD_DIR" ]; then
    print_error "Build directory not found: $BUILD_DIR"
    exit 1
fi

# Find GFH if not specified
if [ -z "$GFH_PATH" ]; then
    print_step "Searching for GFH dump..."
    if GFH_PATH=$(find_gfh "$GFH_PATH"); then
        print_success "Found GFH dump: $GFH_PATH"
    else
        print_warning "GFH dump not found - will create default header"
        GFH_PATH=""
    fi
fi

# Verify GFH exists if specified
if [ -n "$GFH_PATH" ] && [ ! -f "$GFH_PATH" ]; then
    print_error "GFH file not found: $GFH_PATH"
    exit 1
fi

# Clean if requested
if [ $CLEAN -eq 1 ]; then
    print_step "Cleaning old build artifacts..."
    cd "$BUILD_DIR"
    make clean > /dev/null 2>&1 || true
    print_success "Clean complete"
fi

# Build
print_step "Building OpenPhone Stage 1..."
cd "$BUILD_DIR"

if [ $VERBOSE -eq 1 ]; then
    make
else
    make > /tmp/openphone_build.log 2>&1
fi

if [ $? -ne 0 ]; then
    print_error "Build failed!"
    if [ $VERBOSE -eq 0 ]; then
        echo "Build log:"
        cat /tmp/openphone_build.log
    fi
    exit 1
fi

print_success "Build complete"

# Show sizes
print_step "Image sizes:"
if [ -f "bin/openphone-stage1.elf" ]; then
    echo "  $(arm-linux-gnueabihf-size -A bin/openphone-stage1.elf | tail -1 | awk '{print "Total: " $2 " bytes"}')"
fi
if [ -f "bin/openphone-stage1.bin" ]; then
    SIZE=$(wc -c < "bin/openphone-stage1.bin")
    echo "  Binary: $SIZE bytes (0x$(printf '%x' $SIZE))"
fi

# Pack with GFH
print_step "Packing with GFH header..."
if [ -n "$GFH_PATH" ]; then
    export GFH="$GFH_PATH"
fi

if [ $VERBOSE -eq 1 ]; then
    python3 arch/arm/mt6261/pack_gfh.py \
        bin/openphone-stage1.bin \
        "${GFH_PATH:-.}" \
        bin/openphone-stage1-final.bin
else
    python3 arch/arm/mt6261/pack_gfh.py \
        bin/openphone-stage1.bin \
        "${GFH_PATH:-.}" \
        bin/openphone-stage1-final.bin 2>&1 | tail -5
fi

if [ $? -ne 0 ]; then
    print_error "GFH packing failed!"
    exit 1
fi

FINAL_SIZE=$(wc -c < "bin/openphone-stage1-final.bin")
print_success "Final image: $FINAL_SIZE bytes (0x$(printf '%x' $FINAL_SIZE))"

# Generate disassembly if requested
if [ $DISASM -eq 1 ]; then
    print_step "Generating disassembly..."
    make disasm > /dev/null 2>&1
    if [ -f "bin/openphone-stage1.dis" ]; then
        print_success "Disassembly: bin/openphone-stage1.dis"
    fi
fi

# Final summary
echo ""
echo -e "${GREEN}╔═══════════════════════════════════════╗${NC}"
echo -e "${GREEN}║${NC}         BUILD SUCCESSFUL! ✓          ${GREEN}║${NC}"
echo -e "${GREEN}╚═══════════════════════════════════════╝${NC}"
echo ""
echo "Output image: ${BLUE}$BUILD_DIR/bin/openphone-stage1-final.bin${NC}"
echo "Ready to flash to NOR at address 0x00000000"
echo ""

# Next steps hint
echo -e "${YELLOW}Next steps:${NC}"
echo "  1. Connect serial console (115200 8N1)"
echo "  2. Flash the image: $BUILD_DIR/bin/openphone-stage1-final.bin"
echo "  3. Power on device and watch for boot messages"
echo "  4. Type 'ok' prompt when OpenBIOS loads"
echo ""

exit 0
