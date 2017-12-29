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

#include <stdlib.h>

#include "geo_array.h"

geo_array *geo_array_ctor(int element_count)
{
	geo_array *tmp;

	tmp = malloc(sizeof(geo_array));
	tmp->count = element_count;
	tmp->allocated = element_count;
	tmp->status = calloc(1, element_count);
	tmp->x = (double*) calloc(1, element_count * sizeof(double));
	tmp->y = (double*) calloc(1, element_count * sizeof(double));

	return tmp;
}

void geo_array_add(geo_array *points, double lat, double lon)
{
	if (points->count >= points->allocated) {
		points->allocated = 1 + (points->allocated * 2);
		points->status = realloc(points->status, points->allocated);
		points->x = (double*) realloc(points->x, points->allocated * sizeof(double));
		points->y = (double*) realloc(points->y, points->allocated * sizeof(double));
	}
	points->x[points->count] = lat;
	points->y[points->count] = lon;
	points->status[points->count] = 1;

	points->count++;
}
	
void geo_array_dtor(geo_array *points)
{
	free(points->status);
	free(points->x);
	free(points->y);
	free(points);
}
