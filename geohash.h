/*
  +----------------------------------------------------------------------+
  | PHP Version 5/7                                                      |
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
#ifndef PHP_GEOHASH_H
#define PHP_GEOHASH_H

char *php_geo_geohash_encode(double lat, double lng, int precision);
geo_lat_long php_geo_geohash_decode(char *hash, size_t hash_len);

#endif /* PHP_GEOHASH_H */
