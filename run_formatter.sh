#!/bin/bash
set -e  # Exit immediately if any command fails

clang-format-19 -i src/*.c
clang-format-19 -i include/*.h