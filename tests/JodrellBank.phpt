--TEST--
WGS84 to OSGB36
--FILE--
<?php

function getDecimal($d, $m, $s) {
    $mul =  $d < 0 ? -1 : 1;
    return $mul * (abs($d)+ $m / 60 + $s /3600);
}

$lat = getDecimal(53, 14, 10.5);
$long = getDecimal(-2, 18, 25.7);

$polar = change_datum($lat, $long, GEO_WGS84, GEO_AIRY_1830);

echo round($polar['lat'] ,6),PHP_EOL;
echo round($polar['long'] ,6),PHP_EOL;
echo round($polar['height'] ,3),PHP_EOL;
--EXPECT--
53.235974
-2.305717
-25.649