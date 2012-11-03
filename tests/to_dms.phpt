--TEST--
degrees minutes seconds
--FILE--
<?php

$dms = to_dms(-1.034291666667, 'longitude');
var_dump($dms);

$dms = to_dms(-1.034291666667, 'latitude');
var_dump($dms);

--EXPECT--
array(4) {
  ["degrees"]=>
  int(1)
  ["minutes"]=>
  int(2)
  ["seconds"]=>
  float(3.45)
  ["direction"]=>
  string(1) "W"
}
array(4) {
  ["degrees"]=>
  int(1)
  ["minutes"]=>
  int(2)
  ["seconds"]=>
  float(3.45)
  ["direction"]=>
  string(1) "S"
}