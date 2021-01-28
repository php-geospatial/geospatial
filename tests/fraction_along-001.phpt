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
--EXPECTF--
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
    float(6.999852234726%d)
    [1]=>
    float(10.02394494379%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(8.999926079127%d)
    [1]=>
    float(10.03592515633%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(11.00007392087%d)
    [1]=>
    float(10.03592515633%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(13.00014776527%d)
    [1]=>
    float(10.02394494379%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(%r(15|14.9999)%r%S)
    [1]=>
    float(10)
  }
}
