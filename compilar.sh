#!/bin/bash
gcc -I . -c fileM.c
gcc -c amazingFiles.c
gcc -o fileM amazingFiles.o fileM.o
./fileM
