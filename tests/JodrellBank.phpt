--TEST--
WGS84 to OSGB36
--FILE--
<?php

$lat = dms_to_decimal(53, 14, 10.5);
$long = dms_to_decimal(-2, 18, 25.7);

$from = array('type' => 'Point', 'coordinates' => array( $long, $lat ) );

$polar = transform_datum($from, GEO_WGS84, GEO_AIRY_1830);

var_dump($polar);
?>
--EXPECT--
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(-2.3057171628534)
    [1]=>
    float(53.235974015543)
  }
}
