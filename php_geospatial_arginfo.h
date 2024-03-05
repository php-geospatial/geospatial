/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 0fadd3390095e7624d9586206523e5352d345729 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_dms_to_decimal, 0, 3, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, degrees, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, minutes, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, seconds, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, direction, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_decimal_to_dms, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, decimal, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, coordinate, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_helmert, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, from_reference_ellipsoid, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, to_reference_ellipsoid, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_polar_to_cartesian, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, latitude, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, longitude, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, reference_ellipsoid, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_cartesian_to_polar, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, reference_ellipsoid, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_transform_datum, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, coordinates, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, from_reference_ellipsoid, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, to_reference_ellipsoid, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_haversine, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, from, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, to, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, radius, IS_DOUBLE, 0, "GEO_EARTH_RADIUS")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vincenty, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, from, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, to, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, reference_ellipsoid, IS_DOUBLE, 0, "GEO_WGS84")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_fraction_along_gc_line, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, from, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, to, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, fraction, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_interpolate_linestring, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, line, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, epsilon, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_initial_bearing, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, from, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, to, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_rdp_simplify, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, points, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, epsilon, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_geohash_encode, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, point, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, precision, IS_LONG, 0, "12")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_geohash_decode, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, geohash, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(dms_to_decimal);
ZEND_FUNCTION(decimal_to_dms);
ZEND_FUNCTION(helmert);
ZEND_FUNCTION(polar_to_cartesian);
ZEND_FUNCTION(cartesian_to_polar);
ZEND_FUNCTION(transform_datum);
ZEND_FUNCTION(haversine);
ZEND_FUNCTION(vincenty);
ZEND_FUNCTION(fraction_along_gc_line);
ZEND_FUNCTION(interpolate_linestring);
ZEND_FUNCTION(initial_bearing);
ZEND_FUNCTION(rdp_simplify);
ZEND_FUNCTION(geohash_encode);
ZEND_FUNCTION(geohash_decode);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(dms_to_decimal, arginfo_dms_to_decimal)
	ZEND_FE(decimal_to_dms, arginfo_decimal_to_dms)
	ZEND_FE(helmert, arginfo_helmert)
	ZEND_FE(polar_to_cartesian, arginfo_polar_to_cartesian)
	ZEND_FE(cartesian_to_polar, arginfo_cartesian_to_polar)
	ZEND_FE(transform_datum, arginfo_transform_datum)
	ZEND_FE(haversine, arginfo_haversine)
	ZEND_FE(vincenty, arginfo_vincenty)
	ZEND_FE(fraction_along_gc_line, arginfo_fraction_along_gc_line)
	ZEND_FE(interpolate_linestring, arginfo_interpolate_linestring)
	ZEND_FE(initial_bearing, arginfo_initial_bearing)
	ZEND_FE(rdp_simplify, arginfo_rdp_simplify)
	ZEND_FE(geohash_encode, arginfo_geohash_encode)
	ZEND_FE(geohash_decode, arginfo_geohash_decode)
	ZEND_FE_END
};
