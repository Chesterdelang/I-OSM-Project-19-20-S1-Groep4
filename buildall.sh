#!/usr/bin/env bash

mkdir -p linux
./autogen.sh
cd linux
../configure -C --with-cxx=17 $1
make all
