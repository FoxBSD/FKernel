#!/usr/bin/env bash

MOCKOS_DIR="build/mockos/boot/grub"
KERNEL_FILE="build/FKernel.bin"
MOCKOS_KERNEL="build/mockos/boot"
GRUB_FILE="Config/grub.cfg"

if [ ! -d "$MOCKOS_DIR" ]; then
    mkdir -p "$MOCKOS_DIR"
fi

if grub-file --is-x86-multiboot "$KERNEL_FILE"; then
  printf "\033[41;37m ERROR: The $KERNEL_FILE isn't a multiboot file \033[0m \n"  
  exit 1 
fi

cp "$KERNEL_FILE" "$MOCKOS_KERNEL"
cp "$GRUB_FILE" "$MOCKOS_DIR"

grub-mkrescue /usr/lib/grub/i386-pc -o build/MockOS.iso build/mockos
