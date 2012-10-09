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

ZEND_BEGIN_ARG_INFO_EX(helmert_args, 0, 0, 3)
    ZEND_ARG_INFO(0, x)
    ZEND_ARG_INFO(0, y)
    ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

/* {{{ geospatial_functions[]
 *
 * Every user visible function must have an entry in geospatial_functions[].
 */
const zend_function_entry geospatial_functions[] = {
    PHP_FE(haversine, haversine_args)
	PHP_FE(helmert, helmert_args)
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

PHP_FUNCTION(helmert)
{
    double x, y, z;
    double xOut, yOut, zOut;
    double rX, rY, rZ;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ddd", &x, &y, &z) == FAILURE) {
        return;
    }

    array_init(return_value);
    rX = ROTATION_X;
    rX /= 3600;
    rX *= GEO_DEG_TO_RAD;

    rY = ROTATION_Y;
    rY /= 3600;
    rY *= GEO_DEG_TO_RAD;

    rZ = ROTATION_Z;
    rZ /= 3600;
    rZ *= GEO_DEG_TO_RAD;

    xOut = x - (rZ * y) + (rY * z);
    xOut *= SCALE_CHANGE;
    xOut += WGS84_OSGB36_X;

    yOut = (rZ * x) + y - (rX * z);
    yOut *= SCALE_CHANGE;
    yOut += WGS84_OSGB36_Y;

    zOut = (-rY * x) + (rX * y) + z;
    zOut *= SCALE_CHANGE;
    zOut += WGS84_OSGB36_Z;

    add_next_index_double(return_value, xOut);
    add_next_index_double(return_value, yOut);
    add_next_index_double(return_value, zOut);
}

/* {{{ proto haversine(double fromLat, double fromLong, double toLat, double toLong [, double radius ])
 * Calculates the greater circle distance between the two lattitude/longitude pairs */
PHP_FUNCTION(haversine)
{
	double fromLat, fromLong, toLat, toLong, deltaLat, deltaLong;
	double radius = GEO_EARTH_RADIUS, latH, longH, result;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "dddd|d", &fromLat, &fromLong, &toLat, &toLong, &radius) == FAILURE) {
		return;
	}

	deltaLat = (fromLat - toLat) * GEO_DEG_TO_RAD;
	deltaLong = (fromLong - toLong) * GEO_DEG_TO_RAD;

	latH = sin(deltaLat * 0.5);
	latH *= latH;
	longH = sin(deltaLong * 0.5);
	longH *= longH;

	result = cos(fromLat * GEO_DEG_TO_RAD) * cos(toLat * GEO_DEG_TO_RAD);
	result = radius * 2.0 * asin(sqrt(latH + result * longH));
	RETURN_DOUBLE(result);
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
