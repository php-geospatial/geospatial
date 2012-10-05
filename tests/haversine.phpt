--TEST--
haversine() function  - bastic test for haversine forumla
--FILE--
<?php
$lon1 = -104.88544  
$lat1 = 39.06546  
   
$lon2 = -104.80  
$lat2 = lat1  
haversine($lat1, $lon2, $lat2, $lon2);
?>
--EXPECT--
float(7.376)
