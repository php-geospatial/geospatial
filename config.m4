dnl $Id$
dnl config.m4 for extension geospatial

PHP_ARG_ENABLE(geospatial, whether to enable geospatial support,
[  --enable-geospatial           Enable geospatial support])

if test "$PHP_GEOSPATIAL" != "no"; then
  PHP_NEW_EXTENSION(geospatial, geospatial.c geo_array.c geohash.c rdp.c, $ext_shared)
fi
