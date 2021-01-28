--TEST--
Test for "fraction_along_gc_line" #2
--FILE--
<?php
$point1 = [ 'type' => 'Point', 'coordinates' => [ 0.1062, 51.5171 ] ];
$point2 = [ 'type' => 'Point', 'coordinates' => [ 3.2200, 55.9500 ] ];
   
var_dump(fraction_along_gc_line($point1, $point2, 0.5));
?>
--EXPECTF--
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(1.580948127199%d)
    [1]=>
    float(53.74361133415%d)
  }
}
