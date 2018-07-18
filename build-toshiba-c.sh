#!/bin/bash
# This script builds native optimized c code for toshiba.
DEBIAN_BUILDARCH=pentium
DEBIAN_GCCVER=7
name=$1
builder-cc -march=i386 -mtune=native -O3 -o $name $name.c
mv $name executables/linux/86
exit
