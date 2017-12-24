/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 2017 The PHP Group                                     |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Emir Beganovic <emir@php.net>                               |
  +----------------------------------------------------------------------+
*/

#include <stdlib.h>

#include "php.h"
#include "geo_lat_long.h"
#include "geohash.h"

#define MAX_LAT  90.0
#define MIN_LAT  -90.0

#define MAX_LONG 180.0
#define MIN_LONG -180.0

typedef struct interval_string {
    double high;
    double low;
} interval_struct;

static char char_map[32] = "0123456789bcdefghjkmnpqrstuvwxyz";

char* php_geo_geohash_encode(double latitude, double longitude, int precision)
{
    char* hash;
    int steps;
    double coord, mid;
    int is_even = 1;
    unsigned int hash_char = 0;
    int i;
    interval_struct lat_interval = { MAX_LAT, MIN_LAT };
    interval_struct lng_interval = { MAX_LONG, MIN_LONG };
    interval_struct* interval;

    hash = (char*)safe_emalloc(precision, sizeof(char), 1);

    hash[precision] = '\0';
    steps = precision * 5.0;

    for (i = 1; i <= steps; i++) {
        if (is_even) {
            interval = &lng_interval;
            coord = longitude;
        } else {
            interval = &lat_interval;
            coord = latitude;
        }

        mid = (interval->low + interval->high) / 2.0;
        hash_char = hash_char << 1;

        if (coord > mid) {
            interval->low = mid;
            hash_char |= 0x01;
        } else {
            interval->high = mid;
        }

        if (!(i % 5)) {
            hash[(i - 1) / 5] = char_map[hash_char];
            hash_char = 0;
        }

        is_even = !is_even;
    }

    return hash;
}

static unsigned int index_for_char(char c, char* string)
{
    unsigned int index = -1;
    int string_amount = strlen(string);
    int i;

    for (i = 0; i < string_amount; i++) {
        if (c == string[i]) {
            index = i;
            break;
        }
    }

    return index;
}

geo_lat_long php_geo_geohash_decode(char* hash)
{
    geo_lat_long coordinate;
    int char_amount = strlen(hash);

    if (char_amount) {

        int charmap_index;
        double delta;
        int i, j;

        interval_struct lat_interval = { MAX_LAT, MIN_LAT };
        interval_struct lng_interval = { MAX_LONG, MIN_LONG };
        interval_struct* interval;

        int is_even = 1;

        for (i = 0; i < char_amount; i++) {

            charmap_index = index_for_char(hash[i], (char*)char_map);

            /* Interpret the last 5 bits of the integer */
            for (j = 0; j < 5; j++) {
                interval = is_even ? &lng_interval : &lat_interval;

                delta = (interval->high - interval->low) / 2.0;

                if ((charmap_index << j) & 0x0010) {
                    interval->low += delta;
                } else {
                    interval->high -= delta;
                }

                is_even = !is_even;
            }
        }

        coordinate.latitude = lat_interval.high - ((lat_interval.high - lat_interval.low) / 2.0);
        coordinate.longitude = lng_interval.high - ((lng_interval.high - lng_interval.low) / 2.0);
        coordinate.height = 0;
    }

    return coordinate;
}

/* }}} */
