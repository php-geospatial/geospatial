--TEST--
Check the haversine function usage.
--SKIPIF--
<?php if (!extension_loaded("geospatial")) print "skip"; ?>
--FILE--
<?php 
echo haversine(51.5171, 0.1062, 55.9500, 3.2200);
/*
	Test the haversine distance between London and Edinburgh.
	
	London:    51.5171° N, 0.1062° W (0.899143016 / 0.00185353967)
	Edinburgh: 55.9500° N, 3.2200° W (0.976511716 / 0.0561996019)

	Delta-lat:  4.4329° (0.0773687004)
	Delta-long: 3.1138° (0.0543460622)

  double a =  pow(sin(0.0773687004 * 0.5),2) + cos(0.899143016) * cos(0.976511716) * pow(sin(0.0543460622 * 0.5),2);
  double a =  pow(sin(0.03868435),2)         +    cos(0.899143016) * cos(0.976511716) * pow(sin(0.027173031),2);
  double a =  pow(0.03867470233,2)           +    0.62228103855    * 0.55991616262    * pow(0.02716968714,2);
  double a =  0.0014957326                   +    0.62228103855    * 0.55991616262    * 0.00073819189
  double a =  0.0014957326                   +    0.00025720466
  double a =  0.00175293726
  double c = 2.0 * atan2(sqrt(a), sqrt(1-a));
  double c = 2.0 * atan2(sqrt(0.00175293726), sqrt(0.99824706274));
  double c = 2.0 * 0.04188033525
  double c = 0.08376067
  return R * c;
  return 

	Accept defined (equatorial) Earth Radius in km (which is based on WGS-84):
	- 6378137m (at the equator).

	Sanity check - expected distance: approx 534km.
*/
?>
--EXPECT--
534.237028


