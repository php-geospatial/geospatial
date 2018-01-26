--TEST--
Test geohash_encode
--SKIPIF--
<?php if (!extension_loaded("geospatial")) print "skip"; ?>
--FILE--
<?php
echo geohash_encode(array('type' => 'Point', 'coordinates' => [16.4, 48.2]), 12).PHP_EOL;
echo geohash_encode(array('type' => 'Point', 'coordinates' => [90, 90]), 6).PHP_EOL;
echo geohash_encode(array('type' => 'Point', 'coordinates' => [16.363, 48.21]), 32).PHP_EOL;
echo geohash_encode(array('type' => 'Point', 'coordinates' => [95, 95]), 6).PHP_EOL;
echo geohash_encode(array('type' => 'Point', 'coordinates' => [185, 185]), 12).PHP_EOL;
echo geohash_encode(array('type' => 'Point', 'coordinates' => [-90, -185]), 12).PHP_EOL;
echo var_dump(geohash_encode(array('type' => 'Point', 'coordinates' => [30, 30]), 0));
echo var_dump(geohash_encode(array('type' => 'Point', 'coordinates' => [30, 30]), -1));
?>
--EXPECT--
u2edjnw17enr
vzzzzz
u2edk275te35u5s6504t7yfpbpbpbpbp
ypgxcz
zzzzzzzzzzzz
1bpbpbpbpbpb
string(0) ""
string(0) ""
