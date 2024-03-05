--TEST--
Test for "interpolate_linestring" #3
--FILE--
<?php
$lineString = [
	'type' => 'Linestring',
	'coordinates' => [
		[  0,  50 ],
		[ 90,  50 ],
	]
];

var_dump(interpolate_linestring($lineString, 20));
var_dump(interpolate_linestring($lineString, 40));
?>
--EXPECTF--
array(6) {
  [0]=>
  array(2) {
    [0]=>
    float(0)
    [1]=>
    float(50)
  }
  [1]=>
  array(2) {
    [0]=>
    float(17.264525298083225)
    [1]=>
    float(56.16396630005119)
  }
  [2]=>
  array(2) {
    [0]=>
    float(39.12863273409221)
    [1]=>
    float(59.18552765040588)
  }
  [3]=>
  array(2) {
    [0]=>
    float(62.26466104551454)
    [1]=>
    float(58.14617677212717)
  }
  [4]=>
  array(2) {
    [0]=>
    float(81.99106566784195)
    [1]=>
    float(53.39333006084351)
  }
  [5]=>
  array(2) {
    [0]=>
    float(90)
    [1]=>
    float(50)
  }
}
array(4) {
  [0]=>
  array(2) {
    [0]=>
    float(0)
    [1]=>
    float(50)
  }
  [1]=>
  array(2) {
    [0]=>
    float(39.12863273409221)
    [1]=>
    float(59.18552765040588)
  }
  [2]=>
  array(2) {
    [0]=>
    float(81.99106566784195)
    [1]=>
    float(53.39333006084351)
  }
  [3]=>
  array(2) {
    [0]=>
    float(90)
    [1]=>
    float(50)
  }
}
