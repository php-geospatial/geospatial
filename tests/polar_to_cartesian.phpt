--TEST--
Test polar to cartesian
--FILE--
<?php
$lat = 53.38361111111;
$long = 1.4669444444;

var_dump(polar_to_cartesian($lat, $long));
?>
--EXPECT--
array(3) {
  [0]=>
  float(3810891.6734396)
  [1]=>
  float(97591.624686311)
  [2]=>
  float(5095766.3939034)
}