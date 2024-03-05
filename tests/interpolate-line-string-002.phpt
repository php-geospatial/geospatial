--TEST--
Test for "interpolate_linestring" #2
--FILE--
<?php
$lineString = [
	'type' => 'Linestring',
	'coordinates' => [
		[  0,   0 ],
		[ 90,   0 ],
	]
];

var_dump(interpolate_linestring($lineString, 20));
?>
--EXPECTF--
array(6) {
  [0]=>
  array(2) {
    [0]=>
    float(0)
    [1]=>
    float(0)
  }
  [1]=>
  array(2) {
    [0]=>
    float(19.999999999999996)
    [1]=>
    float(0)
  }
  [2]=>
  array(2) {
    [0]=>
    float(40.00000000000001)
    [1]=>
    float(0)
  }
  [3]=>
  array(2) {
    [0]=>
    float(59.99999999999999)
    [1]=>
    float(0)
  }
  [4]=>
  array(2) {
    [0]=>
    float(80)
    [1]=>
    float(0)
  }
  [5]=>
  array(2) {
    [0]=>
    float(90)
    [1]=>
    float(0)
  }
}
