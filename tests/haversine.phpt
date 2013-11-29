--TEST--
haversine() function - basic test for haversine forumla
--INI--
precision=15
--FILE--
<?php
$from = array(
	'type' => 'Point',
	'coordinates' => array( -104.88544, 39.06546 )
);
$to = array(
	'type' => 'Point',
	'coordinates' => array( -104.80, 39.06546 )
);
var_dump(haversine($to, $from));
?>
--EXPECTF--
float(7.384698392931%d)
