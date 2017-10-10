--TEST--
Test geohash_encode
--SKIPIF--
<?php if (!extension_loaded("geospatial")) print "skip"; ?>
--FILE--
<?php
echo geohash_encode(48.2, 16.4, 12).PHP_EOL;
echo geohash_encode(90, 90, 6).PHP_EOL;
echo geohash_encode(48.21, 16.363, 32).PHP_EOL;
echo geohash_encode(95, 95, 6).PHP_EOL;
echo geohash_encode(185, 185, 12).PHP_EOL;
echo geohash_encode(-185, -90, 12).PHP_EOL;
echo var_dump(geohash_encode(30, 30, 0));
?>
--EXPECT--
u2edjnw17enr
vzzzzz
u2edk275te35u5s6504t7yfpbpbpbpbp
ypgxcz
zzzzzzzzzzzz
1bpbpbpbpbpb
string(0) ""
