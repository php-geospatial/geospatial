--TEST--
Test polar to cartesian
--FILE--
<?php
$lat = 53.38361111111;
$long = 1.4669444444;

var_dump(polar_to_cartesian($lat, $long, GEO_AIRY_1830));
?>
--EXPECTF--
array(3) {
  ["x"]=>
  float(3810891.673439%d)
  ["y"]=>
  float(97591.624686%d)
  ["z"]=>
  float(5095766.393903%d)
}
