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

var_dump(geohash_decode('u2edjnw17enr'));
?>
--EXPECT--
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(157.5)
    [1]=>
    float(67.5)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(174.375)
    [1]=>
    float(47.8125)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(170.859375)
    [1]=>
    float(49.921875)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.03515625)
    [1]=>
    float(49.658203125)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.01318359375)
    [1]=>
    float(49.68017578125)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.02966308594)
    [1]=>
    float(49.671936035156)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.02897644043)
    [1]=>
    float(49.67399597168)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.0284614563)
    [1]=>
    float(49.674081802368)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.02861166)
    [1]=>
    float(49.674146175385)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.02859556675)
    [1]=>
    float(49.674154222012)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.0285962373)
    [1]=>
    float(49.674153551459)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.02859674022)
    [1]=>
    float(49.674154138193)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(-5.60302734375)
    [1]=>
    float(42.60498046875)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(157.5)
    [1]=>
    float(67.5)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(16.40000006184)
    [1]=>
    float(48.199999993667)
  }
}
