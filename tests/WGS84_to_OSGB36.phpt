--TEST--
WGS84 to OSGB36
--FILE--
<?php

$lat = dms_to_decimal(53, 23, 1);
$long = dms_to_decimal(-1, 28, 1);

$polar = transform_datum($lat, $long, GEO_WGS84, GEO_AIRY_1830);

var_dump($polar);
--EXPECT--
array(3) {
  ["lat"]=>
  float(53.38334018402)
  ["long"]=>
  float(-1.4654162848544)
  ["height"]=>
  float(-24.780265408568)
}