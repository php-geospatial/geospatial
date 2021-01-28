--TEST--
dms_to_decimal()
--FILE--
<?php

$decimal = dms_to_decimal(1, 2, 3.45, 'W');
var_dump($decimal);
$decimal = dms_to_decimal(2, 18, 25.7, 'W');
var_dump($decimal);
$decimal = dms_to_decimal(-2, 18, 25.7, 'W');
var_dump($decimal);
$decimal = dms_to_decimal(-2, 18.42833333333333333333, 0, 'W');
var_dump($decimal);
$decimal = dms_to_decimal(0, 6, 9, 'S');
var_dump($decimal);
$decimal = dms_to_decimal(74, 34, 31, 'W');
var_dump($decimal);
?>
--EXPECTF--
float(-1.034291666666%d)
float(-2.307138888888%d)
float(-2.307138888888%d)
float(-2.307138888888%d)
float(-0.102%d)
float(-74.57527777777%d)
