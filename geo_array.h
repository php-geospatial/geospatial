/*
  +----------------------------------------------------------------------+
  | PHP Version 5/7                                                      |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Derick Rethans <github@derickrethans.nl>                    |
  |          Michael Maclean <michael@no-surprises.co.uk>                |
  |          Nathaniel McHugh <nmchugh@inviqa.com>                       |
  |          Marcus Deglos <marcus@deglos.com>                           |
  +----------------------------------------------------------------------+
*/
#ifndef PHP_GEO_ARRAY_H
#define PHP_GEO_ARRAY_H

typedef struct geo_array {
	double  *x;
	double  *y;
	char    *status;
	int      count;
	int      allocated;
} geo_array;

geo_array *geo_array_ctor(int element_count);
void geo_array_add(geo_array *points, double lat, double lon);
void geo_array_dtor(geo_array *points);
#endif /* PHP_GEO_ARRAY_H */
