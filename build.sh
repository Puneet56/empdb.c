#! /usr/bin/env bash

# flags for curl
# $(curl-config --libs --cflags)

# flags for raylib
# $(pkg-config --libs --cflags raylib)

set -xe

# $(pkg-config --libs --cflags raylib)  $(curl-config --libs --cflags)
gcc -o ./bin/main ./main.c 

## Run file
./bin/main -f ./dev/emp.txt