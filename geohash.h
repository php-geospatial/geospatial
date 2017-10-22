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

typedef struct IntervalStruct {
    double high;
    double low;
} Interval;

typedef struct GeoCoordStruct {
    double latitude;
    double longitude;
} GeoCoord;

static char char_map[32] =  "0123456789bcdefghjkmnpqrstuvwxyz";

#endif /* PHP_GEOHASH_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
