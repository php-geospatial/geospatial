#!/bin/bash

phpize
EXTRA_LDFLAGS="-precious-files-regex .libs/geospatial.gcno" LDFLAGS="-lgcov" CFLAGS="-Wall -ggdb3 -fno-strict-aliasing -coverage -O0" ./configure --enable-geospatial
make
