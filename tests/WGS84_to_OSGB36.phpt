--TEST--
WGS84 to OSGB36
--FILE--
<?php

function getDecimal($d, $m, $s) {
    $mul =  $d < 0 ? -1 : 1;
    return $mul * (abs($d)+ $m / 60 + $s /3600);
}

$lat = getDecimal(53, 23, 1);
$long = getDecimal(-1, 28, 1);

extract(polar_to_cartesian($lat, $long, GEO_WGS84));
extract(helmert($x, $y, $z));

$polar = cartesian_to_polar($x, $y, $z, GEO_AIRY_1830);
var_dump($polar);
--EXPECT--
array(3) {
  ["lat"]=>
  float(53.38334018402)
  ["long"]=>
  float(-1.4654162848544)
  ["height"]=>
  float(24.780265408568)
}