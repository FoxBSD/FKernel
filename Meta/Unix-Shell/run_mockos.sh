#!/usr/bin/env bash

MOCKOS_ISO="build/MockOS.iso"

if [ ! "$(command -v qemu-system-x86_64)" ]; then
    printf "\033[41;37mError: qemu-system-x86_64 not found. Install it \033[m \n"
    exit 1
fi

if [ ! -f "$MOCKOS_ISO" ]; then
    xmake -v
fi

if [ ! -d "logs" ]; then
    mkdir logs
fi

current_date=$(date +%d-%m-%Y-%H-%M)
qemu-system-x86_64 -cdrom "$MOCKOS_ISO" -m 512M -serial file:"logs/log_$current_date.txt"
