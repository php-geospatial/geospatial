--TEST--
Test polar to cartesian
--FILE--
<?php
$x = 3810891.6734396;
$y = 97591.624686311;
$z = 5095766.3939034;

$polar = cartesian_to_polar($x, $y, $z);
echo round($polar['lat'] ,6),PHP_EOL;
echo round($polar['long'] ,6),PHP_EOL;
echo round($polar['height'] ,3),PHP_EOL;
?>
--EXPECT--
53.383611
1.466944
24.7
