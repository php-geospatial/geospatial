--TEST--
WGS84 to OSGB36
--FILE--
<?php

$lat = dms_to_decimal(53, 14, 10.5);
$long = dms_to_decimal(-2, 18, 25.7);

$polar = transform_datum($lat, $long, GEO_WGS84, GEO_AIRY_1830);

echo round($polar['lat'] ,6),PHP_EOL;
echo round($polar['long'] ,6),PHP_EOL;
echo round($polar['height'] ,3),PHP_EOL;
--EXPECT--
53.235974
-2.305717
-25.649