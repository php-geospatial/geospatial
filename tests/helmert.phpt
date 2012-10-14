--TEST--
helmert() function - basic test for helmert forumla
--FILE--
<?php
$x = 3909833.018;
$y = -147097.1376;
$z = 5020322.478;

var_dump(helmert($x, $y, $z));
?>
--EXPECT--
array(3) {
  ["x"]=>
  float(3909460.0676711)
  ["y"]=>
  float(-146987.30138174)
  ["z"]=>
  float(5019888.0705933)
}