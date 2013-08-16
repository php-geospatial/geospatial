--TEST--
Test for "fraction_along_gc_line" #3
--FILE--
<?php
$point1 = [ 'type' => 'Point', 'coordinates' => [   0, 90 ] ];
$point2 = [ 'type' => 'Point', 'coordinates' => [ 180,  0 ] ];
var_dump(fraction_along_gc_line($point1, $point2, 0.5));

$point1 = [ 'type' => 'Point', 'coordinates' => [   0,  90 ] ];
$point2 = [ 'type' => 'Point', 'coordinates' => [   3, -90 ] ];
var_dump(fraction_along_gc_line($point1, $point2, 0.5));
?>
--EXPECT--
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(180)
    [1]=>
    float(45)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(1.5)
    [1]=>
    float(0)
  }
}
