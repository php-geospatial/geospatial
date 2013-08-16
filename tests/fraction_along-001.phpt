--TEST--
Test for "fraction_along_gc_line" #1
--FILE--
<?php
$point1 = [ 'type' => 'Point', 'coordinates' => [  5, 10 ] ];
$point2 = [ 'type' => 'Point', 'coordinates' => [ 15, 10 ] ];
   
var_dump(fraction_along_gc_line($point1, $point2, 0));
var_dump(fraction_along_gc_line($point1, $point2, 0.2));
var_dump(fraction_along_gc_line($point1, $point2, 0.4));
var_dump(fraction_along_gc_line($point1, $point2, 0.6));
var_dump(fraction_along_gc_line($point1, $point2, 0.8));
var_dump(fraction_along_gc_line($point1, $point2, 1));
?>
--EXPECT--
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(5)
    [1]=>
    float(10)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(6.9998522347268)
    [1]=>
    float(10.023944943799)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(8.9999260791276)
    [1]=>
    float(10.035925156339)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(11.000073920872)
    [1]=>
    float(10.035925156339)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(13.000147765273)
    [1]=>
    float(10.023944943799)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(15)
    [1]=>
    float(10)
  }
}
