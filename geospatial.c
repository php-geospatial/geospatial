/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_geospatial.h"
#include "geo_array.h"

ZEND_BEGIN_ARG_INFO_EX(haversine_args, 0, 0, 2)
	ZEND_ARG_INFO(0, geoJsonPointFrom)
	ZEND_ARG_INFO(0, geoJsonPointTo)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(vincenty_args, 0, 0, 2)
	ZEND_ARG_INFO(0, geoJsonPointFrom)
	ZEND_ARG_INFO(0, geoJsonPointTo)
	ZEND_ARG_INFO(0, reference_ellipsoid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(fraction_along_gc_line_args, 0, 0, 3)
	ZEND_ARG_INFO(0, geoJsonPointFrom)
	ZEND_ARG_INFO(0, geoJsonPointTo)
	ZEND_ARG_INFO(0, fraction)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(initial_bearing_args, 0, 0, 2)
	ZEND_ARG_INFO(0, geoJsonPointFrom)
	ZEND_ARG_INFO(0, geoJsonPointTo)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(helmert_args, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
	ZEND_ARG_INFO(0, from_reference_ellipsoid)
	ZEND_ARG_INFO(0, to_reference_ellipsoid)
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

ZEND_BEGIN_ARG_INFO_EX(dms_to_decimal_args, 0, 0, 3)
	ZEND_ARG_INFO(0, degrees)
	ZEND_ARG_INFO(0, minutes)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(decimal_to_dms_args, 0, 0, 2)
	ZEND_ARG_INFO(0, decimal)
	ZEND_ARG_INFO(0, coordinate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(rdp_simplify_args, 0, 0, 2)
	ZEND_ARG_INFO(0, pointsArray)
	ZEND_ARG_INFO(0, epsilon)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(interpolate_linestring_args, 0, 0, 2)
	ZEND_ARG_INFO(0, GeoJSONLineString)
	ZEND_ARG_INFO(0, epsilon)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(interpolate_polygon_args, 0, 0, 2)
	ZEND_ARG_INFO(0, GeoJSONPolygon)
	ZEND_ARG_INFO(0, epsilon)
ZEND_END_ARG_INFO()

/* {{{ geospatial_functions[]
 *
 * Every user visible function must have an entry in geospatial_functions[].
 */
const zend_function_entry geospatial_functions[] = {
	PHP_FE(haversine, haversine_args)
	PHP_FE(initial_bearing, initial_bearing_args)
	PHP_FE(fraction_along_gc_line, fraction_along_gc_line_args)
	PHP_FE(helmert, helmert_args)
	PHP_FE(polar_to_cartesian, polar_to_cartesian_args)
	PHP_FE(cartesian_to_polar, cartesian_to_polar_args)
	PHP_FE(transform_datum, transform_datum_args)
	PHP_FE(dms_to_decimal, dms_to_decimal_args)
	PHP_FE(decimal_to_dms, decimal_to_dms_args)
	PHP_FE(vincenty, vincenty_args)
	PHP_FE(rdp_simplify, rdp_simplify_args)
	PHP_FE(interpolate_linestring, interpolate_linestring_args)
	PHP_FE(interpolate_polygon, interpolate_polygon_args)
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

/* {{{ Version compat helpers */
#if PHP_VERSION_ID >= 70000
# define ADD_STRING(zv, name, val) add_assoc_string_ex(zv, name, sizeof(name)-1, val);
# define GEOSPAT_MAKE_STD_ZVAL(zv)  zv = ecalloc(sizeof(zval), 1);
#else
# define ADD_STRING(zv, name, val) add_assoc_string_ex(zv, name, sizeof(name), val, 1);
# define GEOSPAT_MAKE_STD_ZVAL(zv)  MAKE_STD_ZVAL(zv)
#endif
/* }}} */

/* {{{ Helpers */
void retval_point_from_coordinates(zval *return_value, double lon, double lat)
{
	zval *coordinates;

	array_init(return_value);
	GEOSPAT_MAKE_STD_ZVAL(coordinates);
	array_init(coordinates);
	ADD_STRING(return_value, "type", "Point");
	add_next_index_double(coordinates, lon);
	add_next_index_double(coordinates, lat);
#if PHP_VERSION_ID >= 70000
	add_assoc_zval_ex(return_value, "coordinates", sizeof("coordinates") - 1, coordinates);
	efree(coordinates);
#else
	add_assoc_zval_ex(return_value, "coordinates", sizeof("coordinates"), coordinates);
#endif
}

static int parse_point_pair(zval *coordinates, double *lon, double *lat)
{
	HashTable *coords;
#if PHP_VERSION_ID >= 70000
	zval *z_lon, *z_lat;
#else
	zval **z_lon, **z_lat;
#endif

	coords = HASH_OF(coordinates);
	if (coords->nNumOfElements != 2) {
		return 0;
	}
#if PHP_VERSION_ID >= 70000
	if ((z_lon = zend_hash_index_find(coords, 0)) == NULL) {
		return 0;
	}
	if ((z_lat = zend_hash_index_find(coords, 1)) == NULL) {
		return 0;
	}
	convert_to_double_ex(z_lon);
	convert_to_double_ex(z_lat);
	*lon = Z_DVAL_P(z_lon);
	*lat = Z_DVAL_P(z_lat);
#else
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
#endif
	return 1;
}

int geojson_point_to_lon_lat(zval *point, double *lon, double *lat)
{
#if PHP_VERSION_ID >= 70000
	zval *type, *coordinates;

	if ((type = zend_hash_str_find(HASH_OF(point), "type", sizeof("type") - 1)) == NULL) {
		return 0;
	}
	if (Z_TYPE_P(type) != IS_STRING || strcmp(Z_STRVAL_P(type), "Point") != 0) {
		return 0;
	}
	if ((coordinates = zend_hash_str_find(HASH_OF(point), "coordinates", sizeof("coordinates") - 1)) == NULL) {
		return 0;
	}
	if (Z_TYPE_P(coordinates) != IS_ARRAY) {
		return 0;
	}
	return parse_point_pair(coordinates, lon, lat);
#else
	zval **type, **coordinates;

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
	return parse_point_pair(*coordinates, lon, lat);
#endif
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

double php_geo_vincenty(double from_lat, double from_long, double to_lat, double to_long, geo_ellipsoid eli)
{
	double U1, U2, L, lambda, lambdaP;
	double sinSigma, cosSigma, sigma, sinLambda, cosLambda;
	double sinU1, sinU2, cosU1, cosU2;
	double sinAlpha, cos2Alpha;
	double cosof2sigma, A, B, C, uSq, deltaSigma, s;
	int loopLimit = 100;
	double precision = 0.000000000001;
	
	U1 = atan((1.0 - eli.f) * tan(from_lat));
	U2 = atan((1.0 - eli.f) * tan(to_lat));
	L = to_long - from_long;
	sinU1 = sin(U1);
	cosU1 = cos(U1);
	sinU2 = sin(U2);
	cosU2 = cos(U2);
	lambda = L;
	do {
		sinLambda = sin(lambda);
		cosLambda = cos(lambda);
		sinSigma = sqrt((cosU2*sinLambda) * (cosU2*sinLambda) + 
      (cosU1 * sinU2 - sinU1 * cosU2 * cosLambda) * (cosU1 * sinU2 - sinU1 * cosU2 * cosLambda));
		cosSigma = sinU1 * sinU2 + cosU1 * cosU2 * cosLambda;
		sigma = atan2(sinSigma, cosSigma);
		sinAlpha = cosU1 * cosU2 * sinLambda / sinSigma;
		cos2Alpha = 1.0 - sinAlpha * sinAlpha;
		cosof2sigma = cosSigma - 2.0 * sinU1 * sinU2 / cos2Alpha;
		C = eli.f / 16.0 * cos2Alpha * (4.0 + eli.f * (4.0 - 3.0 * cos2Alpha));
		lambdaP = lambda;
		lambda = L + (1.0 - C) * eli.f * sinAlpha *
      (sigma + C*sinSigma*(cosof2sigma+C*cosSigma*(-1.0 + 2.0 *cosof2sigma*cosof2sigma)));
		--loopLimit;
	} while (fabs(lambda -  lambdaP) > precision && loopLimit > 0);
	uSq = cos2Alpha * (eli.a * eli.a - eli.b * eli.b) / (eli.b * eli.b);
	A = 1.0 + uSq / 16384.0 * (4096.0 + uSq * (-768.0 + uSq * (320.0 - 175.0 * uSq)));
	B = uSq / 1024.0 * ( 256.0 + uSq * (-128.0 + uSq * (74.0 - 47.0 * uSq)));
	deltaSigma = B * sinSigma * (cosof2sigma+B/4.0 * (cosSigma * (-1.0 + 2.0 *cosof2sigma*cosof2sigma)-
    B / 6.0 * cosof2sigma * (-3.0 + 4.0 *sinSigma*sinSigma) * (-3.0 + 4.0 *cosof2sigma*cosof2sigma)));
	s = eli.b * A * (sigma - deltaSigma);
	s = floor(s * 1000) / 1000;
	return s;
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

/* {{{ proto double dms_to_decimal(double degrees, double minutes, double seconds [,string direction])
 * Convert degrees, minutes & seconds values to decimal degrees */
PHP_FUNCTION(dms_to_decimal)
{
	double degrees, minutes, sign;
	double seconds, decimal;
	char *direction = "";
#if PHP_VERSION_ID >= 70000
	size_t direction_len;
#else
	int direction_len;
#endif

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

/* {{{ proto array decimal_to_dms(double decimal, string coordinate)
 * Convert decimal degrees value to whole degrees and minutes and decimal seconds */
PHP_FUNCTION(decimal_to_dms)
{
	double decimal, seconds;
	int degrees, minutes;
	char *direction;
	char *coordinate;
#if PHP_VERSION_ID >= 70000
	size_t coordinate_len;
#else
	int coordinate_len;
#endif

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
	ADD_STRING(return_value, "direction", direction);
}
/* }}} */

/* {{{ proto array helmert(double x, double y, double z [, long from_reference_ellipsoid, long to_reference_ellipsoid])
 * Convert cartesian co-ordinates between reference elipsoids  */
PHP_FUNCTION(helmert)
{
	double x, y, z;
	geo_cartesian point;
	long from_reference_ellipsoid = 0, to_reference_ellipsoid = 0;

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

/* {{{ proto array polar_to_cartesian(double latitude, double longitude[, long reference_ellipsoid])
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

/* {{{ proto array cartesian_to_polar(double x, double y, double z [, long reference_ellipsoid])
 * Convert cartesian co-ordinates (x, y, z) to polar ones (latitude, longitude) */
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


/* {{{ proto GeoJSONPoint transform_datum(GeoJSONPoint coordinates, long from_reference_ellipsoid, long to_reference_ellipsoid)
 * Unified function to transform projection of geo-coordinates between datums */
PHP_FUNCTION(transform_datum)
{
	double latitude, longitude;
	zval *geojson;
	long from_reference_ellipsoid, to_reference_ellipsoid;
	geo_cartesian point, converted_point;
	geo_lat_long polar;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "all", &geojson, &from_reference_ellipsoid, &to_reference_ellipsoid) == FAILURE) {
		return;
	}

	if (!geojson_point_to_lon_lat(geojson, &longitude, &latitude)) {
		RETURN_FALSE;
	}

	geo_ellipsoid eli_from = get_ellipsoid(from_reference_ellipsoid);
	geo_ellipsoid eli_to = get_ellipsoid(to_reference_ellipsoid);
	point = polar_to_cartesian(latitude, longitude, eli_from);
	geo_helmert_constants helmert_constants = get_helmert_constants(from_reference_ellipsoid, to_reference_ellipsoid);
	converted_point = helmert(point.x, point.y, point.z, helmert_constants);
	polar = cartesian_to_polar(converted_point.x, converted_point.y, converted_point.z, eli_to);
/*
	array_init(return_value);
	add_assoc_double(return_value, "lat", polar.latitude);
	add_assoc_double(return_value, "long", polar.longitude);
	add_assoc_double(return_value, "height", polar.height);
*/
	retval_point_from_coordinates(return_value, polar.longitude, polar.latitude);
}
/* }}} */

/* {{{ proto double haversine(GeoJSONPoint from, GeoJSONPoint to [, double radius ])
 * Calculates the greater circle distance between two points in m */
PHP_FUNCTION(haversine)
{
	double radius = GEO_EARTH_RADIUS;
	zval   *from_geojson, *to_geojson;
	double from_lat, from_long, to_lat, to_long;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aa|d", &from_geojson, &to_geojson, &radius) == FAILURE) {
		return;
	}

	geojson_point_to_lon_lat(from_geojson, &from_long, &from_lat);
	geojson_point_to_lon_lat(to_geojson, &to_long, &to_lat);

	RETURN_DOUBLE(php_geo_haversine(from_lat * GEO_DEG_TO_RAD, from_long * GEO_DEG_TO_RAD, to_lat * GEO_DEG_TO_RAD, to_long * GEO_DEG_TO_RAD) * radius);
}
/* }}} */

/* {{{ proto double vincenty(GeoJSONPoint from, GeoJSONPoint to [, long reference_ellipsoid ])
 * Calculates the distance between two points in m */
PHP_FUNCTION(vincenty)
{
	zval   *from_geojson, *to_geojson;
	double from_lat, from_long, to_lat, to_long;
	long reference_ellipsoid = GEO_WGS84;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aa|l", &from_geojson, &to_geojson, &reference_ellipsoid) == FAILURE) {
		return;
	}

	geojson_point_to_lon_lat(from_geojson, &from_long, &from_lat);
	geojson_point_to_lon_lat(to_geojson, &to_long, &to_lat);

	geo_ellipsoid eli = get_ellipsoid(reference_ellipsoid);
	RETURN_DOUBLE(php_geo_vincenty(from_lat * GEO_DEG_TO_RAD, from_long * GEO_DEG_TO_RAD, to_lat * GEO_DEG_TO_RAD, to_long * GEO_DEG_TO_RAD, eli));
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

/* {{{ proto GeoJSONPoint fraction_along_gc_line(GeoJSONPoint from, GeoJSONPoint to, double fraction [, double radius ])
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

double php_initial_bearing(double from_lat, double from_long, double to_lat, double to_long)
{
/*
var y = Math.sin(dLon) * Math.cos(lat2);
var x = Math.cos(lat1)*Math.sin(lat2) -
        Math.sin(lat1)*Math.cos(lat2)*Math.cos(dLon);
var brng = Math.atan2(y, x).toDeg();
*/
	double x, y;

	y = sin(fabs(to_long - from_long)) * cos(to_lat);
	x = (cos(from_lat) * sin(to_lat)) - (sin(from_lat) * cos(to_lat) * cos(fabs(to_long - from_long)));

	return atan2(y, x);
}

/* {{{ proto float initial_bearing(GeoJSONPoint from, GeoJSONPoint to)
   Calculates the initial bearing to from from to to. */
PHP_FUNCTION(initial_bearing)
{
	zval   *from_geojson, *to_geojson;
	double from_lat, from_long, to_lat, to_long, bearing;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aa", &from_geojson, &to_geojson) == FAILURE) {
		return;
	}

	geojson_point_to_lon_lat(from_geojson, &from_long, &from_lat);
	geojson_point_to_lon_lat(to_geojson, &to_long, &to_lat);

	bearing = php_initial_bearing(
		from_lat * GEO_DEG_TO_RAD,
		from_long * GEO_DEG_TO_RAD,
		to_lat * GEO_DEG_TO_RAD,
		to_long * GEO_DEG_TO_RAD
	);

	RETURN_DOUBLE(bearing / GEO_DEG_TO_RAD);
}
/* }}} */

geo_array *geo_hashtable_to_array(zval *array)
{
	geo_array *tmp;
	int element_count;
	HashPosition pos;
#if PHP_VERSION_ID >= 70000
	zval *entry;
#else
	zval **entry;
#endif
	double lon, lat;
	int   i = 0;

	element_count = zend_hash_num_elements(Z_ARRVAL_P(array));
	tmp = geo_array_ctor(element_count);

#if PHP_VERSION_ID >= 70000
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(array), entry) {

		if (!parse_point_pair(entry, &lon, &lat)) {
#else
	zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(array), &pos);
	while (zend_hash_get_current_data_ex(Z_ARRVAL_P(array), (void **)&entry, &pos) == SUCCESS) {

		if (!parse_point_pair(*entry, &lon, &lat)) {
#endif

			goto failure;
		}

		tmp->x[i] = lon;
		tmp->y[i] = lat;
		tmp->status[i] = 1;

		zend_hash_move_forward_ex(Z_ARRVAL_P(array), &pos);
		i++;
#if PHP_VERSION_ID >= 70000
	} ZEND_HASH_FOREACH_END();
#else
	}
#endif

	return tmp;

failure:
	geo_array_dtor(tmp);
	return NULL;
}

int geojson_linestring_to_array(zval *line, geo_array **array)
{
	geo_array *tmp;
#if PHP_VERSION_ID >= 70000
	zval *type, *coordinates;

	if (Z_TYPE_P(line) != IS_ARRAY) {
		return 0;
	}

	if ((type = zend_hash_str_find(HASH_OF(line), "type", sizeof("type") - 1)) == NULL) {
		return 0;
	}
	if (Z_TYPE_P(type) != IS_STRING || strcmp(Z_STRVAL_P(type), "Linestring") != 0) {
		return 0;
	}
	if ((coordinates = zend_hash_str_find(HASH_OF(line), "coordinates", sizeof("coordinates") - 1)) == NULL) {
		return 0;
	}
	if (Z_TYPE_P(coordinates) != IS_ARRAY) {
		return 0;
	}

	tmp = geo_hashtable_to_array(coordinates);
#else
	zval **type, **coordinates;

	if (Z_TYPE_P(line) != IS_ARRAY) {
		return 0;
	}

	if (zend_hash_find(HASH_OF(line), "type", sizeof("type"), (void**) &type) != SUCCESS) {
		return 0;
	}
	if (Z_TYPE_PP(type) != IS_STRING || strcmp(Z_STRVAL_PP(type), "Linestring") != 0) {
		return 0;
	}
	if (zend_hash_find(HASH_OF(line), "coordinates", sizeof("coordinates"), (void**) &coordinates) != SUCCESS) {
		return 0;
	}
	if (Z_TYPE_PP(coordinates) != IS_ARRAY) {
		return 0;
	}

	tmp = geo_hashtable_to_array(*coordinates);
#endif
	if (tmp && array) {
		*array = tmp;
		return 1;
	}

	return 0;
}

double rdp_find_perpendicular_distable(double pX, double pY, double p1X, double p1Y, double p2X, double p2Y)
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

/* {{{ proto array rdp_simplify(array points, float epsilon)
   Simplifies a 2D dimensional line according to the Ramer-Douglas-Peucker algorithm */
PHP_FUNCTION(rdp_simplify)
{
	zval      *points_array;
	double     epsilon;
	geo_array *points;
	int        i;
	zval      *pair;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zd", &points_array, &epsilon) == FAILURE) {
		return;
	}

	if (!Z_TYPE_P(points_array) == IS_ARRAY) {
		return;
	}

	array_init(return_value);

	points = geo_hashtable_to_array(points_array);
	rdp_simplify(points, epsilon, 0, points->count - 1);
	for (i = 0; i < points->count; i++) {
		if (points->status[i]) {
			GEOSPAT_MAKE_STD_ZVAL(pair);
			array_init(pair);
			add_next_index_double(pair, points->x[i]);
			add_next_index_double(pair, points->y[i]);
			add_next_index_zval(return_value, pair);
#if PHP_VERSION_ID >= 70000
			efree(pair);
#endif
		}
	}

	geo_array_dtor(points);
}
/* }}} */

static geo_array *interpolate_line(geo_array *points, double epsilon)
{
	int i;
	geo_array *new_array;
	double     dx, dy, distance, step_size, res_lat, res_long, fraction;

	new_array = geo_array_ctor(0);

	for (i = 0; i < points->count - 1; i++) {
		dx = fabs(points->x[i] - points->x[i + 1]);
		dy = fabs(points->y[i] - points->y[i + 1]);
		distance = sqrt((dx * dx) + (dy * dy));
		if (distance > epsilon) {
			step_size = epsilon/distance;
			for (fraction = 0; fraction < 1; fraction += step_size) {
				php_geo_fraction_along_gc_line(
					points->y[i] * GEO_DEG_TO_RAD,
					points->x[i] * GEO_DEG_TO_RAD,
					points->y[i + 1] * GEO_DEG_TO_RAD,
					points->x[i + 1] * GEO_DEG_TO_RAD,
					fraction, GEO_EARTH_RADIUS,
					&res_lat, &res_long
				);
				geo_array_add(new_array, res_long / GEO_DEG_TO_RAD, res_lat / GEO_DEG_TO_RAD);
			}
		} else {
			geo_array_add(new_array, points->x[i], points->y[i]);
		}
	}
	geo_array_add(new_array, points->x[points->count - 1], points->y[points->count - 1]);

	return new_array;
}

/* {{{ proto array interpolate_linestring(GeoJSONLineString line, float epsilon)
   Interpolates lines with intermediate points to show line segments as GC lines */
PHP_FUNCTION(interpolate_linestring)
{
	zval      *line;
	double     epsilon;
	geo_array *points;
	int        i;
	zval      *pair;
	geo_array *new_array;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zd", &line, &epsilon) == FAILURE) {
		return;
	}

	if (!geojson_linestring_to_array(line, &points)) {
		RETURN_FALSE;
	}

	array_init(return_value);

	new_array = interpolate_line(points, epsilon);

	for (i = 0; i < new_array->count; i++) {
		if (new_array->status[i]) {
			GEOSPAT_MAKE_STD_ZVAL(pair);
			array_init(pair);
			add_next_index_double(pair, new_array->x[i]);
			add_next_index_double(pair, new_array->y[i]);
			add_next_index_zval(return_value, pair);
#if PHP_VERSION_ID >= 70000
			efree(pair);
#endif
		}
	}

	geo_array_dtor(points);
	geo_array_dtor(new_array);
}
/* }}} */

/* {{{ proto array interpolate_polygon(GeoJSONPolygon polygon, float epsilon)
   Interpolates polygons with intermediate points to show line segments as GC lines */
PHP_FUNCTION(interpolate_polygon)
{
	zval      *polygon;
	double     epsilon;
	geo_array *points;
	int        i;
	zval      *pair;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zd", &polygon, &epsilon) == FAILURE) {
		return;
	}

	if (!Z_TYPE_P(polygon) == IS_ARRAY) {
		return;
	}

	if (!geojson_linestring_to_array(polygon, &points)) {
		RETURN_FALSE;
	}

	array_init(return_value);

	rdp_simplify(points, epsilon, 0, points->count - 1);

	for (i = 0; i < points->count; i++) {
		if (points->status[i]) {
			GEOSPAT_MAKE_STD_ZVAL(pair);
			array_init(pair);
			add_next_index_double(pair, points->x[i]);
			add_next_index_double(pair, points->y[i]);
			add_next_index_zval(return_value, pair);
#if PHP_VERSION_ID >= 70000
			efree(pair);
#endif
		}
	}

	geo_array_dtor(points);
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
