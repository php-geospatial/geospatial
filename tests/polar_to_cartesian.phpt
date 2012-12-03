--TEST--
Test polar to cartesian
--FILE--
<?php
$lat = 53.38361111111;
$long = 1.4669444444;

var_dump(polar_to_cartesian($lat, $long, GEO_AIRY_1830));
?>
--EXPECT--
array(3) {
  ["x"]=>
  float(3810891.6734396)
  ["y"]=>
  float(97591.624686311)
  ["z"]=>
  float(5095766.3939034)
}