--TEST--
decimal
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

?>
--EXPECT--
float(-1.0342916666667)
float(-2.3071388888889)
float(-2.3071388888889)
float(-2.3071388888889)
