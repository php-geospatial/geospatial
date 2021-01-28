--TEST--
OSGB36 to WGS84
--FILE--
<?php

$lat = dms_to_decimal(53, 14, 10.5, 'N');
$long = dms_to_decimal(2, 18, 25.7, 'W');

$from = array('type' => 'Point', 'coordinates' => array( $long, $lat ) );

$polar = transform_datum($from, GEO_AIRY_1830, GEO_WGS84);

var_dump(decimal_to_dms($polar['coordinates'][1], 'latitude'));
var_dump(decimal_to_dms($polar['coordinates'][0] ,'longitude'));
?>
--EXPECTF--
array(4) {
  ["degrees"]=>
  int(53)
  ["minutes"]=>
  int(14)
  ["seconds"]=>
  float(11.49337267273%d)
  ["direction"]=>
  string(1) "N"
}
array(4) {
  ["degrees"]=>
  int(2)
  ["minutes"]=>
  int(18)
  ["seconds"]=>
  float(30.81779465924%d)
  ["direction"]=>
  string(1) "W"
}
