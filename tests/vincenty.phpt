--TEST--
Test for "Vincenty" distance between FlindersPeak and Buninyong
--INI--
precision=15
--FILE--
<?php
$flindersPeakLat = dms_to_decimal(-37, 57, 3.72030);
$flindersPeakLong = dms_to_decimal(144, 25, 29.52440);
$buninyongLat = dms_to_decimal(-37, 39, 10.15610);
$buninyongLong = dms_to_decimal(143, 55, 35.38390);

$flinders = array(
	'type' => 'Point',
	'coordinates' => array( $flindersPeakLong, $flindersPeakLat )
);
$buninyong = array(
	'type' => 'Point',
	'coordinates' => array( $buninyongLong, $buninyongLat )
);
var_dump(vincenty($flinders, $buninyong));
?>
--EXPECTF--
float(54972.2%d)
