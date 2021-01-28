--TEST--
initial_bearing() function - basic test for initial_bearing forumla
--FILE--
<?php
$from = array(
	'type' => 'Point',
	'coordinates' => array( -1, 53 )
);
$to = array(
	'type' => 'Point',
	'coordinates' => array( 0, 52 )
);
var_dump(initial_bearing($from, $to));
?>
--EXPECTF--
float(148.2708928017%d)
