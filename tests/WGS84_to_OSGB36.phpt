--TEST--
WGS84 to OSGB36
--FILE--
<?php

$lat = dms_to_decimal(53, 23, 1);
$long = dms_to_decimal(-1, 28, 1);

$coordinate = array(
	'type' => 'Point',
	'coordinates' => array( $long, $lat )
);

$polar = transform_datum($coordinate, GEO_WGS84, GEO_AIRY_1830);

echo round($polar['coordinates'][1], 8),PHP_EOL;
echo round($polar['coordinates'][0], 8),PHP_EOL;
--EXPECT--
53.38334018
-1.46541628
