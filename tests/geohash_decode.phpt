--TEST--
Test geohash_decode
--SKIPIF--
<?php if (!extension_loaded("geospatial")) print "skip"; ?>
--FILE--
<?php
var_dump(geohash_decode('a'));
var_dump(geohash_decode('ab'));
var_dump(geohash_decode('abc'));
var_dump(geohash_decode('abcd'));
var_dump(geohash_decode('abcde'));
var_dump(geohash_decode('abcdef'));
var_dump(geohash_decode('abcdefg'));
var_dump(geohash_decode('abcdefgh'));
var_dump(geohash_decode('abcdefghi'));
var_dump(geohash_decode('abcdefghij'));
var_dump(geohash_decode('abcdefghijk'));
var_dump(geohash_decode('abcdefghijkl'));

var_dump(geohash_decode('ezs42'));

var_dump(geohash_decode('.'));

var_dump(geohash_decode('😀'));

?>
--EXPECT--
array(2) {
  ["latitude"]=>
  float(67.5)
  ["longitude"]=>
  float(157.5)
}
array(2) {
  ["latitude"]=>
  float(47.8125)
  ["longitude"]=>
  float(174.375)
}
array(2) {
  ["latitude"]=>
  float(49.921875)
  ["longitude"]=>
  float(170.859375)
}
array(2) {
  ["latitude"]=>
  float(49.658203125)
  ["longitude"]=>
  float(171.03515625)
}
array(2) {
  ["latitude"]=>
  float(49.68017578125)
  ["longitude"]=>
  float(171.01318359375)
}
array(2) {
  ["latitude"]=>
  float(49.671936035156)
  ["longitude"]=>
  float(171.02966308594)
}
array(2) {
  ["latitude"]=>
  float(49.67399597168)
  ["longitude"]=>
  float(171.02897644043)
}
array(2) {
  ["latitude"]=>
  float(49.674081802368)
  ["longitude"]=>
  float(171.0284614563)
}
array(2) {
  ["latitude"]=>
  float(49.674146175385)
  ["longitude"]=>
  float(171.02861166)
}
array(2) {
  ["latitude"]=>
  float(49.674154222012)
  ["longitude"]=>
  float(171.02859556675)
}
array(2) {
  ["latitude"]=>
  float(49.674153551459)
  ["longitude"]=>
  float(171.0285962373)
}
array(2) {
  ["latitude"]=>
  float(49.674154138193)
  ["longitude"]=>
  float(171.02859674022)
}
array(2) {
  ["latitude"]=>
  float(42.60498046875)
  ["longitude"]=>
  float(-5.60302734375)
}
array(2) {
  ["latitude"]=>
  float(67.5)
  ["longitude"]=>
  float(157.5)
}
array(2) {
  ["latitude"]=>
  float(89.912109375)
  ["longitude"]=>
  float(179.82421875)
}
