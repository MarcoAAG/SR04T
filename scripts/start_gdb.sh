#!/bin/bash

# Función para mostrar la ayuda
show_help() {
    echo "Use: ./start_gdb.sh <file>"
    echo "Example: ./path/appl.out/elf"
}

# Si no se proporciona ningún argumento o se proporciona "--help", mostrar la ayuda
if [ $# -eq 0 ] || [ "$1" = "--help" ] || [ "$1" = "--h" ]; then
    show_help
    exit 0
fi

path="$1"
~/Tools/gcc-arm/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gdb "$path"
