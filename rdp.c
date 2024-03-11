/*
  +----------------------------------------------------------------------+
  | PHP                                                                  |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2024 The PHP Group                                |
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
  +----------------------------------------------------------------------+
*/
#include <math.h>

#include "geo_array.h"

static double rdp_find_perpendicular_distable(double pX, double pY, double p1X, double p1Y, double p2X, double p2Y)
{
	double slope, intercept, result;

	if (p1X == p2X) {
		return fabs(pX - p1X);
	} else {
		slope = (p2Y - p1Y) / (p2X - p1X);
		intercept = p1Y - (slope * p1X);
		result = fabs(slope * pX - pY + intercept) / sqrt(pow(slope, 2) + 1);
		return result;
	}
}

void rdp_simplify(geo_array *points, double epsilon, int start, int end)
{
	double firstX = points->x[start];
	double firstY = points->y[start];
	double lastX = points->x[end];
	double lastY = points->y[end];
	int    index = -1;
	double dist  = 0.0, current_dist;
	int    i;

	if (end - start < 2) {
		return;
	}

	for (i = start + 1; i < end; i++) {
		if (!points->status[i]) {
			continue;
		}

		current_dist = rdp_find_perpendicular_distable(points->x[i], points->y[i], firstX, firstY, lastX, lastY);

		if (current_dist > dist) {
			dist = current_dist;
			index = i;
		}
	}

	if (dist > epsilon) {
		rdp_simplify(points, epsilon, start, index);
		rdp_simplify(points, epsilon, index, end);

		return;
	} else {
		for (i = start + 1; i < end; i++) {
			points->status[i] = 0;
		}
		return;
	}
}

