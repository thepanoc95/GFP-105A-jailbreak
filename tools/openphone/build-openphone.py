#!/usr/bin/env python3
"""
build-openphone.py
OpenPhone — Automated build and GFH packing script (Python version)

Copyright (C) 2026 OpenPhone Project
SPDX-License-Identifier: GPL-2.0-only

Usage: python3 build-openphone.py [--clean] [--disasm] [--gfh PATH]

This script:
  1. Checks ARM toolchain
  2. Builds Stage 1 bootloader
  3. Finds or uses GFH dump
  4. Packs binary with GFH header
  5. Generates optional disassembly
"""

import os
import sys
import subprocess
import argparse
import shutil
from pathlib import Path

# Color codes
class Color:
    HEADER = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'

def print_header():
    print(f"{Color.HEADER}╔═══════════════════════════════════════╗{Color.ENDC}")
    print(f"{Color.HEADER}║{Color.ENDC}  OpenPhone Build & Pack Script v0.1   {Color.HEADER}║{Color.ENDC}")
    print(f"{Color.HEADER}╚═══════════════════════════════════════╝{Color.ENDC}")
    print()

def print_step(msg):
    print(f"{Color.HEADER}→{Color.ENDC} {msg}")

def print_success(msg):
    print(f"{Color.OKGREEN}✓{Color.ENDC} {msg}")

def print_error(msg):
    print(f"{Color.FAIL}✗{Color.ENDC} {msg}", file=sys.stderr)

def print_warning(msg):
    print(f"{Color.WARNING}⚠{Color.ENDC} {msg}")

def check_toolchain():
    """Verify ARM cross-compiler is available"""
    print_step("Checking ARM toolchain...")
    
    result = shutil.which('arm-linux-gnueabihf-gcc')
    if not result:
        print_error("arm-linux-gnueabihf-gcc not found")
        print_warning("Install with: sudo apt install binutils-arm-linux-gnueabihf gcc-arm-linux-gnueabihf")
        return False
    
    try:
        output = subprocess.check_output(['arm-linux-gnueabihf-gcc', '--version'], 
                                        text=True, stderr=subprocess.DEVNULL)
        version = output.split('\n')[0]
        print_success(f"Toolchain found: {version}")
        return True
    except Exception as e:
        print_error(f"Toolchain check failed: {e}")
        return False

def find_gfh(user_path=None, verbose=False):
    """Search for GFH dump in common locations"""
    candidates = [
        user_path,
        Path(__file__).parent / "../../binaries/dump_preloader.bin",
        Path(__file__).parent / "../../binaries/dump.bin",
        Path(__file__).parent / "../../analysis/dump_preloader.bin",
        Path(__file__).parent / "../../analysis/dump.bin",
        Path(__file__).parent / "arch/arm/mt6261/dump_preloader.bin",
        Path.cwd() / "dump_preloader.bin",
        Path.cwd() / "dump.bin",
    ]
    
    if verbose:
        print_step("Searching for GFH dump in:")
        for candidate in candidates:
            if candidate:
                print(f"    {candidate}")
    
    for candidate in candidates:
        if candidate and isinstance(candidate, (str, Path)):
            path = Path(candidate)
            if path.exists() and path.stat().st_size > 0:
                if verbose:
                    print_success(f"Found: {path}")
                return str(path)
    
    return None

def run_command(cmd, cwd=None, verbose=False, check=True):
    """Run a shell command and capture output"""
    try:
        result = subprocess.run(
            cmd,
            cwd=cwd,
            shell=True if isinstance(cmd, str) else False,
            capture_output=not verbose,
            text=True,
            check=False
        )
        
        if check and result.returncode != 0:
            if not verbose:
                print("STDERR:", result.stderr)
                print("STDOUT:", result.stdout)
            return False
        
        return result
    except Exception as e:
        print_error(f"Command failed: {e}")
        return False

def build(build_dir, clean=False, verbose=False):
    """Build the bootloader"""
    print_step("Building OpenPhone Stage 1...")
    
    build_path = Path(build_dir)
    if not build_path.exists():
        print_error(f"Build directory not found: {build_dir}")
        return False
    
    if clean:
        print_step("Cleaning old artifacts...")
        run_command("make clean", cwd=build_dir, verbose=False, check=False)
        print_success("Clean complete")
    
    result = run_command("make", cwd=build_dir, verbose=verbose, check=True)
    if not result:
        print_error("Build failed!")
        return False
    
    print_success("Build complete")
    return True

def show_sizes(build_dir):
    """Display binary sizes"""
    print_step("Image sizes:")
    
    elf_path = Path(build_dir) / "bin/openphone-stage1.elf"
    bin_path = Path(build_dir) / "bin/openphone-stage1.bin"
    
    if elf_path.exists():
        try:
            result = subprocess.check_output(
                ['arm-linux-gnueabihf-size', '-A', str(elf_path)],
                text=True, stderr=subprocess.DEVNULL
            )
            total_line = result.strip().split('\n')[-1]
            print(f"  {total_line}")
        except:
            pass
    
    if bin_path.exists():
        size = bin_path.stat().st_size
        print(f"  Binary: {size} bytes (0x{size:x})")

def pack_gfh(build_dir, gfh_path=None, verbose=False):
    """Pack binary with GFH header"""
    print_step("Packing with GFH header...")
    
    bin_path = Path(build_dir) / "bin/openphone-stage1.bin"
    out_path = Path(build_dir) / "bin/openphone-stage1-final.bin"
    
    if not bin_path.exists():
        print_error(f"Binary not found: {bin_path}")
        return False
    
    script_path = Path(build_dir) / "pack_gfh.py"
    if not script_path.exists():
        print_error(f"GFH packer not found: {script_path}")
        return False
    
    if gfh_path:
        cmd = f"python3 {script_path} {bin_path} {gfh_path} {out_path}"
    else:
        # Create default GFH
        cmd = f"python3 {script_path} {bin_path} . {out_path}"
    
    result = run_command(cmd, verbose=verbose, check=True)
    if not result:
        print_error("GFH packing failed!")
        return False
    
    if out_path.exists():
        size = out_path.stat().st_size
        print_success(f"Final image: {size} bytes (0x{size:x})")
        return True
    
    return False

def generate_disasm(build_dir):
    """Generate disassembly"""
    print_step("Generating disassembly...")
    
    result = run_command("make disasm", cwd=build_dir, verbose=False, check=False)
    
    dis_path = Path(build_dir) / "bin/openphone-stage1.dis"
    if dis_path.exists():
        print_success(f"Disassembly: {dis_path}")
        return True
    
    return False

def main():
    parser = argparse.ArgumentParser(
        description='OpenPhone automated build and GFH packing script',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog='''
Examples:
  python3 build-openphone.py
  python3 build-openphone.py --clean --disasm
  python3 build-openphone.py --gfh /path/to/dump_preloader.bin --verbose
        ''')
    
    parser.add_argument('--clean', action='store_true',
                       help='Remove old build artifacts')
    parser.add_argument('--disasm', action='store_true',
                       help='Generate disassembly after build')
    parser.add_argument('--gfh', metavar='PATH',
                       help='Specify GFH dump file path')
    parser.add_argument('--verbose', action='store_true',
                       help='Show detailed build output')
    
    args = parser.parse_args()
    
    print_header()
    
    # Setup paths
    script_dir = Path(__file__).parent
    build_dir = script_dir / "arch/arm/mt6261"
    
    # Check toolchain
    if not check_toolchain():
        return 1
    
    # Find GFH if not specified
    gfh_path = args.gfh
    if not gfh_path:
        print_step("Searching for GFH dump...")
        gfh_path = find_gfh(verbose=args.verbose)
        if gfh_path:
            print_success(f"Found GFH dump: {gfh_path}")
        else:
            print_warning("GFH dump not found - will create default header")
    else:
        if not Path(gfh_path).exists():
            print_error(f"GFH file not found: {gfh_path}")
            return 1
    
    # Build
    if not build(str(build_dir), clean=args.clean, verbose=args.verbose):
        return 1
    
    show_sizes(str(build_dir))
    
    # Pack with GFH
    if not pack_gfh(str(build_dir), gfh_path, verbose=args.verbose):
        return 1
    
    # Generate disassembly if requested
    if args.disasm:
        generate_disasm(str(build_dir))
    
    # Success message
    print()
    print(f"{Color.OKGREEN}╔═══════════════════════════════════════╗{Color.ENDC}")
    print(f"{Color.OKGREEN}║{Color.ENDC}         BUILD SUCCESSFUL! ✓          {Color.OKGREEN}║{Color.ENDC}")
    print(f"{Color.OKGREEN}╚═══════════════════════════════════════╝{Color.ENDC}")
    print()
    
    final_image = build_dir / "bin/openphone-stage1-final.bin"
    print(f"Output image: {Color.BOLD}{final_image}{Color.ENDC}")
    print("Ready to flash to NOR at address 0x00000000")
    print()
    print(f"{Color.WARNING}Next steps:{Color.ENDC}")
    print("  1. Connect serial console (115200 8N1)")
    print("  2. Flash the image")
    print("  3. Power on device and watch for boot messages")
    print("  4. Type 'ok' prompt when OpenBIOS loads")
    print()
    
    return 0

if __name__ == '__main__':
    sys.exit(main())
