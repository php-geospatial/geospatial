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
  [0]=>
  float(3909460.0676711)
  [1]=>
  float(-146987.30138174)
  [2]=>
  float(5019888.0705933)
}