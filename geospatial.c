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

ZEND_BEGIN_ARG_INFO_EX(helmert_args, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(polar_to_cartesian_args, 0, 0, 3)
	ZEND_ARG_INFO(0, latitude)
	ZEND_ARG_INFO(0, longitude)
	ZEND_ARG_INFO(0, reference_ellipsoid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(cartesian_to_polar_args, 0, 0, 4)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
	ZEND_ARG_INFO(0, reference_ellipsoid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(transform_datum_args, 0, 0, 4)
	ZEND_ARG_INFO(0, latitude)
	ZEND_ARG_INFO(0, longitude)
	ZEND_ARG_INFO(0, from_reference_ellipsoid)
	ZEND_ARG_INFO(0, to_reference_ellipsoid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(dms_to_decimal_args, 0, 0, 4)
	ZEND_ARG_INFO(0, degrees)
	ZEND_ARG_INFO(0, minutes)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(decimal_to_dms_args, 0, 0, 2)
	ZEND_ARG_INFO(0, decimal)
	ZEND_ARG_INFO(0, coordinate)
ZEND_END_ARG_INFO()

/* {{{ geospatial_functions[]
 *
 * Every user visible function must have an entry in geospatial_functions[].
 */
const zend_function_entry geospatial_functions[] = {
	PHP_FE(haversine, haversine_args)
	PHP_FE(fraction_along_gc_line, fraction_along_gc_line_args)
	PHP_FE(helmert, helmert_args)
	PHP_FE(polar_to_cartesian, polar_to_cartesian_args)
	PHP_FE(cartesian_to_polar, cartesian_to_polar_args)
	PHP_FE(transform_datum, transform_datum_args)
	PHP_FE(dms_to_decimal, dms_to_decimal_args)
	PHP_FE(decimal_to_dms, decimal_to_dms_args)
	/* End of functions */
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
	REGISTER_LONG_CONSTANT("GEO_AIRY_1830", GEO_AIRY_1830, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("GEO_WGS84", GEO_WGS84, CONST_CS | CONST_PERSISTENT);
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

geo_ellipsoid get_ellipsoid(long ellipsoid_const)
{
	switch (ellipsoid_const) {
		case GEO_AIRY_1830:
			return airy_1830;
		case GEO_WGS84:
		default:
			return wgs84;
	}
}

geo_helmert_constants get_helmert_constants(long from, long to)
{
	switch (from - to) {
		case 1:
			return osgb36_wgs84;
		default:
		case -1:
			return wgs84_osgb36;
	}
}

geo_cartesian helmert(double x, double y, double z, geo_helmert_constants helmet_consts)
{
	double rX, rY, rZ;
	double xOut, yOut, zOut;
	double scale_change;
	geo_cartesian point;
	scale_change = 1 + (helmet_consts.scale_change);
	rX = helmet_consts.rotation_x / GEO_SEC_IN_DEG * GEO_DEG_TO_RAD;
	rY = helmet_consts.rotation_y / GEO_SEC_IN_DEG * GEO_DEG_TO_RAD;
	rZ = helmet_consts.rotation_z / GEO_SEC_IN_DEG * GEO_DEG_TO_RAD;

	xOut = helmet_consts.translation_x + ((x - (rZ * y) + (rY * z)) * scale_change);

	yOut =  helmet_consts.translation_y + (((rZ * x) + y - (rX * z)) * scale_change);

	zOut = helmet_consts.translation_z + (((-1 * rY * x) + (rX * y) + z) * scale_change);

	point.x = xOut;
	point.y = yOut;
	point.z = zOut;
	return point;
}

geo_cartesian polar_to_cartesian(double latitude, double longitude, geo_ellipsoid eli)
{
	double x, y, z;

	geo_cartesian point;
	double phi = latitude * GEO_DEG_TO_RAD;
	double lambda = longitude * GEO_DEG_TO_RAD;
	double eSq = ((eli.a * eli.a)  - (eli.b * eli.b))  /  (eli.a * eli.a);
	double nu = eli.a / sqrt(1 - (eSq * sin(phi) * sin(phi)));
	x = nu + HEIGHT;
	x *= cos(phi) * cos(lambda);
	y = nu + HEIGHT;
	y *= cos(phi) * sin(lambda);
	z = ((1 - eSq) * nu) + HEIGHT;
	z*= sin(phi);
	point.x = x;
	point.y = y;
	point.z = z;
	return point;
}


geo_lat_long cartesian_to_polar(double x, double y, double z, geo_ellipsoid eli)
{

	double nu, lambda, h;
	geo_lat_long polar;

	/* aiming for 1m accuracy */
	double precision = 0.1 / eli.a;
	double eSq = ((eli.a * eli.a)  - (eli.b * eli.b))  /  (eli.a * eli.a);
	double p = sqrt(x * x + y * y);
	double phi = atan2(z, p * (1 - eSq));
	double phiP = 2 * M_PI;

	while (abs(phi - phiP) > precision) {
		nu = eli.a / sqrt(1 - eSq * sin(phi) * sin(phi));
		phiP = phi;
		phi = atan2(z + eSq * nu * sin(phi), p);
	}

	lambda = atan2(y ,x);
	h = p / cos(phi) - nu;
	polar.latitude = phi / GEO_DEG_TO_RAD;
	polar.longitude = lambda / GEO_DEG_TO_RAD;
	polar.height = h;

	return polar;
}

/* {{{ proto dms_to_decimal(double degrees, double minutes, double seconds [,string direction])
 * Convert degrees, minutes & seconds values to decimal degrees */
PHP_FUNCTION(dms_to_decimal)
{
	double degrees, minutes, sign;
	double seconds, decimal;
	char *direction = "";
	int direction_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd|s", &degrees, &minutes, &seconds, &direction, &direction_len) == FAILURE) {
		return;
	}

	if (strcmp("", direction) == 0) {
		sign = degrees > 1 ? 1 : -1;
	} else {
		sign = strcmp(direction, "S") == 0 || strcmp(direction, "W") == 0 ? -1 : 1;
	}

	decimal = abs(degrees) + minutes / 60 + seconds / 3600;
	decimal *= sign;
	RETURN_DOUBLE(decimal);
}
/* }}} */

/* {{{ proto decimal_to_dms(double decimal, string coordinate)
 * Convert decimal degrees value to whole degrees and minutes and decimal seconds */
PHP_FUNCTION(decimal_to_dms)
{
	double decimal, seconds;
	int degrees, minutes;
	char *direction;
	char *coordinate;
	int coordinate_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ds", &decimal, &coordinate, &coordinate_len) == FAILURE) {
		return;
	}

	if (strcmp(coordinate, "longitude") == 0) {
		direction = decimal < 1 ? "W" : "E";
	} else {
		direction = decimal < 1 ? "S" : "N";
	}

	array_init(return_value);
	decimal = fabs(decimal);
	degrees = (int) decimal;
	minutes = decimal * 60 - degrees * 60;
	seconds = decimal * 3600 - degrees * 3600 - minutes * 60;
	add_assoc_long(return_value, "degrees", degrees);
	add_assoc_long(return_value, "minutes", minutes);
	add_assoc_double(return_value, "seconds", seconds);
	add_assoc_string(return_value, "direction", direction, 1);
}
/* }}} */

/* {{{ proto helmert(double x, double y, double z [, long from_reference_ellipsoid, long to_reference_ellipsoid])
 * Convert polar ones (latitude, longitude) tp cartesian co-ordiantes (x, y, z)  */
PHP_FUNCTION(helmert)
{
	double x, y, z;
	geo_cartesian point;
	long from_reference_ellipsoid, to_reference_ellipsoid;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd|ll", &x, &y, &z, &from_reference_ellipsoid, &to_reference_ellipsoid) == FAILURE) {
		return;
	}

	array_init(return_value);
	geo_helmert_constants helmert_constants = get_helmert_constants(from_reference_ellipsoid, to_reference_ellipsoid);
	point = helmert(x, y, z, helmert_constants);
	add_assoc_double(return_value, "x", point.x);
	add_assoc_double(return_value, "y", point.y);
	add_assoc_double(return_value, "z", point.z);
}
/* }}} */

/* {{{ proto polar_to_cartesian(double latitude, double longitude[, long reference_ellipsoid])
 * Convert polar ones (latitude, longitude) tp cartesian co-ordiantes (x, y, z)  */
PHP_FUNCTION(polar_to_cartesian)
{
	double latitude, longitude;
	long reference_ellipsoid;
	geo_cartesian point;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dd|l", &latitude, &longitude, &reference_ellipsoid) == FAILURE) {
		return;
	}

	geo_ellipsoid eli = get_ellipsoid(reference_ellipsoid);
	array_init(return_value);
	point = polar_to_cartesian(latitude, longitude, eli);
	add_assoc_double(return_value, "x", point.x);
	add_assoc_double(return_value, "y", point.y);
	add_assoc_double(return_value, "z", point.z);
}
/* }}} */

/* {{{ proto cartesian_to_polar(double x, double y, double z [, long reference_ellipsoid])
 * Convert cartesian co-ordiantes (x, y, z) to polar ones (latitude, longitude) */
PHP_FUNCTION(cartesian_to_polar)
{
	double x, y, z;
	long reference_ellipsoid;
	geo_lat_long polar;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd|l", &x, &y, &z, &reference_ellipsoid) == FAILURE) {
		return;
	}

	geo_ellipsoid eli = get_ellipsoid(reference_ellipsoid);
	array_init(return_value);
	polar = cartesian_to_polar(x, y, z, eli);
	add_assoc_double(return_value, "lat", polar.latitude);
	add_assoc_double(return_value, "long", polar.longitude);
	add_assoc_double(return_value, "height", polar.height);
}
/* }}} */


/* {{{ proto transform_datum(double latitude, double longitude, long from_reference_ellipsoid, long to_reference_ellipsoid)
 * Unified function to transform projection of geo-cordinates between datums */
PHP_FUNCTION(transform_datum)
{
	double latitude, longitude;
	long from_reference_ellipsoid, to_reference_ellipsoid;
	geo_cartesian point, converted_point;
	geo_lat_long polar;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddll", &latitude, &longitude, &from_reference_ellipsoid, &to_reference_ellipsoid) == FAILURE) {
		return;
	}

	geo_ellipsoid eli_from = get_ellipsoid(from_reference_ellipsoid);
	geo_ellipsoid eli_to = get_ellipsoid(to_reference_ellipsoid);
	point = polar_to_cartesian(latitude, longitude, eli_from);
	geo_helmert_constants helmert_constants = get_helmert_constants(from_reference_ellipsoid, to_reference_ellipsoid);
	converted_point = helmert(point.x, point.y, point.z, helmert_constants);
	polar = cartesian_to_polar(converted_point.x, converted_point.y, converted_point.z, eli_to);

	array_init(return_value);
	add_assoc_double(return_value, "lat", polar.latitude);
	add_assoc_double(return_value, "long", polar.longitude);
	add_assoc_double(return_value, "height", polar.height);
}
/* }}} */

/* {{{ proto haversine(double fromLat, double fromLong, double toLat, double toLong [, double radius ])
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
