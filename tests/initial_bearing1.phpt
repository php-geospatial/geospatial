--TEST--
initial_bearing() function - basic test for initial_bearing forumla
--INI--
precision=15
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
--EXPECT--
float(148.270892801715)
