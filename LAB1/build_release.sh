#!/bin/bash
gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-conversion -Wfloat-equal -c *.c
gcc -o test.exe *.o
