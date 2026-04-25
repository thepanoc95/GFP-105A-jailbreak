#!/usr/bin/env bash
set -e

echo "[*] Updating system..."
sudo apt update

echo "[*] Installing core tools..."
sudo apt install -y \
    build-essential \
    gcc \
    make \
    pkg-config \
    git \
    curl \
    wget \
    xz-utils

echo "[*] Installing libusb..."
sudo apt install -y libusb-1.0-0-dev

echo "[*] Installing ARM toolchain..."
sudo apt install -y gcc-arm-none-eabi binutils-arm-none-eabi

echo "[*] Installing Forth..."
sudo apt install -y gforth

echo "[*] Installing Python..."
sudo apt install -y python3 python3-pip python3-venv

echo "[*] Verifying tools..."
gcc --version
arm-none-eabi-gcc --version
gforth --version
python3 --version

echo "[✓] Dev environment ready."
