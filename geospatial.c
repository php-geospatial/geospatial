/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_geospatial.h"

ZEND_BEGIN_ARG_INFO_EX(haversine_args, 0, 0, 4)
	ZEND_ARG_INFO(0, fromLatitude)
	ZEND_ARG_INFO(0, fromLongitude)
	ZEND_ARG_INFO(0, toLatitude)
	ZEND_ARG_INFO(0, toLongitude)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(fraction_along_gc_line_args, 0, 0, 3)
	ZEND_ARG_INFO(0, geoJsonPoint1)
	ZEND_ARG_INFO(0, geoJsonPoint2)
	ZEND_ARG_INFO(0, fraction)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

/* {{{ geospatial_functions[]
 *
 * Every user visible function must have an entry in geospatial_functions[].
 */
const zend_function_entry geospatial_functions[] = {
	PHP_FE(haversine, haversine_args)
	PHP_FE(fraction_along_gc_line, fraction_along_gc_line_args)
	{ NULL, NULL, NULL }
};
/* }}} */

/* {{{ geospatial_module_entry
 */
zend_module_entry geospatial_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"geospatial",
	geospatial_functions,
	PHP_MINIT(geospatial),
	NULL,
	NULL,
	NULL,
	PHP_MINFO(geospatial),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GEOSPATIAL
ZEND_GET_MODULE(geospatial)
#endif

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(geospatial)
{
	REGISTER_DOUBLE_CONSTANT("GEO_DEG_TO_RAD", GEO_DEG_TO_RAD, CONST_CS | CONST_PERSISTENT);
	REGISTER_DOUBLE_CONSTANT("GEO_EARTH_RADIUS", GEO_EARTH_RADIUS, CONST_CS | CONST_PERSISTENT);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(geospatial)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(geospatial)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Geospatial functions", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ Helpers */
void retval_point_from_coordinates(zval *return_value, double lon, double lat)
{
	zval *coordinates;

	array_init(return_value);
	MAKE_STD_ZVAL(coordinates);
	array_init(coordinates);
	add_assoc_string_ex(return_value, "type", sizeof("type"), "Point", 1);
	add_next_index_double(coordinates, lon);
	add_next_index_double(coordinates, lat);
	add_assoc_zval_ex(return_value, "coordinates", sizeof("coordinates"), coordinates);
}

int geojson_point_to_lon_lat(zval *point, double *lon, double *lat)
{
	zval      **type, **coordinates, **z_lon, **z_lat;
	HashTable *coords;

	if (zend_hash_find(HASH_OF(point), "type", sizeof("type"), (void**) &type) != SUCCESS) {
		return 0;
	}
	if (Z_TYPE_PP(type) != IS_STRING || strcmp(Z_STRVAL_PP(type), "Point") != 0) {
		return 0;
	}
	if (zend_hash_find(HASH_OF(point), "coordinates", sizeof("coordinates"), (void**) &coordinates) != SUCCESS) {
		return 0;
	}
	if (Z_TYPE_PP(coordinates) != IS_ARRAY) {
		return 0;
	}
	coords = HASH_OF(*coordinates);
	if (coords->nNumOfElements != 2) {
		return 0;
	}
	if (zend_hash_index_find(coords, 0, (void**) &z_lon) != SUCCESS) {
		return 0;
	}
	if (zend_hash_index_find(coords, 1, (void**) &z_lat) != SUCCESS) {
		return 0;
	}
	convert_to_double_ex(z_lon);
	convert_to_double_ex(z_lat);
	*lon = Z_DVAL_PP(z_lon);
	*lat = Z_DVAL_PP(z_lat);
	return 1;
}

/* }}} */

double php_geo_haversine(double from_lat, double from_long, double to_lat, double to_long)
{
	double delta_lat, delta_long;
	double latH, longH, result;

	delta_lat = (from_lat - to_lat);
	delta_long = (from_long - to_long);

	latH = sin(delta_lat * 0.5);
	latH *= latH;
	longH = sin(delta_long * 0.5);
	longH *= longH;

	result = cos(from_lat) * cos(to_lat);
	result = 2.0 * asin(sqrt(latH + result * longH));

	return result;
}

/* {{{ proto double haversine(double from_lat, double from_long, double to_lat, double to_long [, double radius ])
 * Calculates the greater circle distance between the two lattitude/longitude pairs */
PHP_FUNCTION(haversine)
{
	double from_lat, from_long, to_lat, to_long;
	double radius = GEO_EARTH_RADIUS;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd|d", &from_lat, &from_long, &to_lat, &to_long, &radius) == FAILURE) {
		return;
	}

	RETURN_DOUBLE(php_geo_haversine(from_lat * GEO_DEG_TO_RAD, from_long * GEO_DEG_TO_RAD, to_lat * GEO_DEG_TO_RAD, to_long * GEO_DEG_TO_RAD) * radius);
}
/* }}} */

void php_geo_fraction_along_gc_line(double from_lat, double from_long, double to_lat, double to_long, double fraction, double radius, double *res_lat, double *res_long)
{
	double distance;
	double a, b, x, y, z;

	/* First we calculate the distance */
	distance = php_geo_haversine(from_lat, from_long, to_lat, to_long);

	a = sin((1 - fraction) * distance) / sin(distance);
	b = sin(fraction * distance) / sin(distance);
	x = a * cos(from_lat) * cos(from_long) + b * cos(to_lat) * cos(to_long);
	y = a * cos(from_lat) * sin(from_long) + b * cos(to_lat) * sin(to_long);
	z = a * sin(from_lat) + b * sin(to_lat);

	*res_lat = atan2(z, sqrt(x * x + y * y));
	*res_long = atan2(y, x);
}

/* {{{ proto GeoJSON fraction_along_gc_line(GeoJSONPoint from, GeoJSONPoint to, double fraction [, double radius ])
 * Calculates a lat/long pair at a fraction (0-1) of the distance along a GC line */
PHP_FUNCTION(fraction_along_gc_line)
{
	zval   *from_geojson, *to_geojson;
	double from_lat, from_long, to_lat, to_long, fraction;
	double radius = GEO_EARTH_RADIUS;
	double res_lat, res_long;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aad|d", &from_geojson, &to_geojson, &fraction, &radius) == FAILURE) {
		return;
	}

	geojson_point_to_lon_lat(from_geojson, &from_long, &from_lat);
	geojson_point_to_lon_lat(to_geojson, &to_long, &to_lat);

	php_geo_fraction_along_gc_line(
		from_lat * GEO_DEG_TO_RAD,
		from_long * GEO_DEG_TO_RAD,
		to_lat * GEO_DEG_TO_RAD,
		to_long * GEO_DEG_TO_RAD,
		fraction, radius,
		&res_lat, &res_long
	);

	retval_point_from_coordinates(return_value, res_long / GEO_DEG_TO_RAD, res_lat / GEO_DEG_TO_RAD);
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
