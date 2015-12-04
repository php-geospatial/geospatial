/*
  +----------------------------------------------------------------------+
  | PHP Version 5/7                                                      |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
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

#ifndef PHP_GEOSPATIAL_H
#define PHP_GEOSPATIAL_H

#define PHP_GEOSPATIAL_VERSION "0.1.0"

extern zend_module_entry geospatial_module_entry;
#define phpext_geospatial_ptr &geospatial_module_entry

#ifdef PHP_WIN32
# define PHP_GEOSPATIAL_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
# define PHP_GEOSPATIAL_API __attribute__ ((visibility("default")))
#else
# define PHP_GEOSPATIAL_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

typedef struct {
   double   latitude;
   double   longitude;
   double   height;
} geo_lat_long;

typedef struct {
   double    a;
   double    b;
   double    f;
} geo_ellipsoid;

typedef struct {
  double x;
  double y;
  double z;
} geo_cartesian;

/**
 *  Structure of the seven variables used in the helmert transformation
 *
 */
typedef struct {
  double translation_x;
  double translation_y;
  double translation_z;
  double scale_change;
  double rotation_x;
  double rotation_y;
  double rotation_z;
} geo_helmert_constants;

/**
 *  The WGS84 elipsoid semi major axes
 */
const geo_ellipsoid wgs84 = {6378137.000, 6356752.3142, 1.0/298.257223563};

/**
 *  The Airy 1830 elipsoid semi major axes
 */
const geo_ellipsoid airy_1830 = {6377563.396, 6356256.910, 1.0/299.3249646};
/**
 *  The GRS 80 elipsoid semi major axes
 */
const geo_ellipsoid grs80 = {6378137.000, 6356752.314140, 1.0/298.257222101};

/**
 *  The values of the 7 variables for performing helmert transformation between
 *  wgs84 and osgb36
 */
const geo_helmert_constants wgs84_osgb36 = {
  -446.448,
  125.157,
  -542.060,
  0.0000204894,
  -0.1502,
  -0.2470,
  -0.8421
};

/**
 *  The values of the 7 variables for performing helmert transformation between
 *  osgb36 and wgs84 -1 * the values for the reverse transformation
 */
const geo_helmert_constants osgb36_wgs84 = {
  446.448,
  -125.157,
  542.060,
  -0.0000204894,
  0.1502,
  0.2470,
  0.8421
};

#define GEO_DEG_TO_RAD 0.017453292519943295769236907684886
/**
 * Calculate the radius using WGS-84's equatorial radius of
 * 6,378,137.0m
 */
#define GEO_EARTH_RADIUS 6378137.0
#define GEO_SEC_IN_DEG 3600

#define GEO_WGS84 0x0001
#define GEO_AIRY_1830 0x0002

#define HEIGHT 24.7


PHP_MINIT_FUNCTION(geospatial);
PHP_MINFO_FUNCTION(geospatial);

PHP_FUNCTION(haversine);
PHP_FUNCTION(initial_bearing);
PHP_FUNCTION(fraction_along_gc_line);
PHP_FUNCTION(helmert);
PHP_FUNCTION(polar_to_cartesian);
PHP_FUNCTION(cartesian_to_polar);
PHP_FUNCTION(transform_datum);
PHP_FUNCTION(dms_to_decimal);
PHP_FUNCTION(decimal_to_dms);
PHP_FUNCTION(vincenty);
PHP_FUNCTION(rdp_simplify);
PHP_FUNCTION(interpolate_linestring);
PHP_FUNCTION(interpolate_polygon);

#endif /* PHP_GEOSPATIAL_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
