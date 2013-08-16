--TEST--
WGS84 to OSGB36
--FILE--
<?php

$lat = dms_to_decimal(53, 23, 1);
$long = dms_to_decimal(-1, 28, 1);

$polar = transform_datum($lat, $long, GEO_WGS84, GEO_AIRY_1830);

echo round($polar['lat'], 8),PHP_EOL;
echo round($polar['long'], 8),PHP_EOL;
echo round($polar['height'], 8),PHP_EOL;
--EXPECT--
53.38334018
-1.46541628
-24.78026541
