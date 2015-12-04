#!/bin/bash

export CFLAGS="-Wall -ggdb3 -m32"
phpize && ./configure && make clean && make -j 5 all && make install
