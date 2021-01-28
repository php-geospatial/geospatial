--TEST--
initial_bearing() function - basic test for initial_bearing forumla
--FILE--
<?php
$from = array(
	'type' => 'Point',
    'coordinates' => array( 2.351, 48.857 )
);
$to = array(
	'type' => 'Point',
    'coordinates' => array( 0.119, 52.205 )
);
var_dump(initial_bearing($from, $to));
?>
--EXPECTF--
float(337.8904401904%d)
