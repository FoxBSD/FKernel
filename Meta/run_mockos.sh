#!/usr/bin/env bash

MOCKOS_DIR="build/MockOS.iso"

if [ ! "$(command -v qemu-system-x86_64)" ]; then
    echo "qemu-system-x86_64 not found. Install it"
    exit 1
fi

if [ ! -f "$MOCKOS_DIR" ]; then
    xmake -v
fi

if [ ! -d "logs" ]; then
    mkdir logs
fi

qemu-system-x86_64 -cdrom "$MOCKOS_DIR" -m 512M -serial file:logs/log.txt