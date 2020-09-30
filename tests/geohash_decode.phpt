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
    float(171.029663085%s)
    [1]=>
    float(49.6719360351%s)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.028976440%s)
    [1]=>
    float(49.6739959716%s)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.028461456%s)
    [1]=>
    float(49.6740818023%s)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.0286116%s)
    [1]=>
    float(49.67414617%s)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.0285955667%s)
    [1]=>
    float(49.67415422201%s)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.028596237%s)
    [1]=>
    float(49.67415355145%s)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(171.0285967402%s)
    [1]=>
    float(49.67415413819%s)
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
    float(16.4000000618%s)
    [1]=>
    float(48.19999999366%s)
  }
}
array(2) {
  ["type"]=>
  string(5) "Point"
  ["coordinates"]=>
  array(2) {
    [0]=>
    float(179.9999998323%s)
    [1]=>
    float(89.99999991618%s)
  }
}
