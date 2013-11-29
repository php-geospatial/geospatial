--TEST--
Test for "Vincenty" distance between FlindersPeak and Buninyong
--FILE--
<?php
$flindersPeakLat = dms_to_decimal(-37, 57, 3.72030);
$flindersPeakLong = dms_to_decimal(144, 25, 29.52440);
$buninyongLat = dms_to_decimal(-37, 39, 10.15610);
$buninyongLong = dms_to_decimal(143, 55, 35.38390);
echo vincenty($flindersPeakLat, $flindersPeakLong, $buninyongLat, $buninyongLong), 'm';
?>
--EXPECT--
54972.271m
