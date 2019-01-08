--TEST--
initial_bearing() function - basic test for initial_bearing forumla
--INI--
precision=15
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
--EXPECT--
float(337.890440190492)
