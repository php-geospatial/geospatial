--TEST--
haversine() function  - bastic test for haversine forumla
--FILE--
<?php
$lat1 = 39.06546;
$lon1 = -104.88544;
   
$lat2 = $lat1;
$lon2 = -104.80;
var_dump(haversine($lat1, $lon1, $lat2, $lon2));
?>
--EXPECT--
float(7.3785163137969)
