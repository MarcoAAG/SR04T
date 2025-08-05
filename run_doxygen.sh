#!/bin/bash
set -e  # Exit immediately if any command fails

mkdir -p documentation

~/Tools/doxygen/1.12.0/doxygen config-doxygen.conf 2> documentation/doxygen.log