#!/bin/bash
set -e  # Exit immediately if any command fails

# Create output directory
mkdir -p build

# Compile the source file into an object file
gcc src/sr04m.c \
    -I include/ \
    -std=c11 \
    -Wall -Wextra -pedantic \
    -O2 \
    -c -o build/sr04m.o

