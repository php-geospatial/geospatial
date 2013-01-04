--TEST--
WGS84 to OSGB36 for Grennwich Observertory
--FILE--
<?php

$lat = dms_to_decimal(51, 28.675, 0, 'N');
$long = dms_to_decimal(0, 0.089, 0, 'W');

$polar = transform_datum($lat, $long, GEO_WGS84, GEO_AIRY_1830);

$airyLong = $polar['long'];
$wgs84Long = $long;

$diferenceWGS84 = haversine($lat, $long, $lat, 0);
$diferenceAiry = haversine($polar['lat'], $polar['long'], $polar['lat'], 0);
//lat long of merdian in Airy 1830 ideally long of 0
var_dump($polar);
//distance in m of difference from lat long and meridian
echo round($diferenceWGS84 * 1000, 8),PHP_EOL;
echo round($diferenceAiry * 1000, 8),PHP_EOL;
--EXPECT--
array(3) {
  ["lat"]=>
  float(51.477400823311)
  ["long"]=>
  float(0.00013627354767069)
  ["height"]=>
  float(-21.205192557536)
}
102.84185171
9.44816796