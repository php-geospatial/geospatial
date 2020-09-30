--TEST--
helmert() function - basic test for helmert formula
--FILE--
<?php
$x = 3909833.018;
$y = -147097.1376;
$z = 5020322.478;

var_dump(helmert($x, $y, $z));
?>
--EXPECTF--
array(3) {
  ["x"]=>
  float(3909460.067671%s)
  ["y"]=>
  float(-146987.301381%s)
  ["z"]=>
  float(5019888.070593%s)
}
