--TEST--
OSGB36 to WGS84
--FILE--
<?php

$lat = dms_to_decimal(53, 14, 10.5, 'N');
$long = dms_to_decimal(2, 18, 25.7, 'W');

$polar = transform_datum($lat, $long, GEO_AIRY_1830, GEO_WGS84);

var_dump(decimal_to_dms($polar['lat'], 'latitude'));
var_dump(decimal_to_dms($polar['long'] ,'longitude'));
echo round($polar['height'] ,3),PHP_EOL;
--EXPECT--
array(4) {
  ["degrees"]=>
  int(53)
  ["minutes"]=>
  int(14)
  ["seconds"]=>
  float(11.493372672732)
  ["direction"]=>
  string(1) "N"
}
array(4) {
  ["degrees"]=>
  int(2)
  ["minutes"]=>
  int(18)
  ["seconds"]=>
  float(30.817794659248)
  ["direction"]=>
  string(1) "W"
}
75.061