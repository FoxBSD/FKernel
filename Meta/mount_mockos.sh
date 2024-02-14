#!/usr/bin/env bash

MOCKOS_DIR="build/mockos/boot/grub"
KERNEL_FILE="build/FKernel.bin"
MOCKOS_KERNEL="build/mockos/boot"
GRUB_FILE="Config/grub.cfg"

if [ ! -d "$MOCKOS_DIR" ]; then
    mkdir -p "$MOCKOS_DIR"
fi

cp "$KERNEL_FILE" "$MOCKOS_KERNEL"
cp "$GRUB_FILE" "$MOCKOS_DIR"

grub-mkrescue /usr/lib/grub/i386-pc -o build/MockOS.iso build/mockos