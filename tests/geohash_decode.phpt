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

var_dump(geohash_decode('zzzzzzzzzzzz'));
?>
--EXPECTF--
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
    float(171.0296630859%d)
    [1]=>
    float(49.67193603515%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.0289764404%d)
    [1]=>
    float(49.6739959716%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.028461456%d)
    [1]=>
    float(49.67408180236%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.0286116%d)
    [1]=>
    float(49.67414617538%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.0285955667%d)
    [1]=>
    float(49.67415422201%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.028596237%d)
    [1]=>
    float(49.67415355145%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.0285967402%d)
    [1]=>
    float(49.67415413819%d)
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
    float(16.4000000618%d)
    [1]=>
    float(48.1999999936%d)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(179.9999998323%d)
    [1]=>
    float(89.9999999161%d)
  }
}
