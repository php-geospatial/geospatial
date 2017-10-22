=====================================
geospatial - PHP Geospatial Extension
=====================================
.. image:: https://travis-ci.org/php-geospatial/geospatial.svg?branch=master
    :target: https://travis-ci.org/php-geospatial/geospatial
.. image:: https://codecov.io/gh/php-geospatial/geospatial/branch/master/graphs/badge.svg?branch=master
    :target: https://codecov.io/github/php-geospatial/geospatial?branch=master

PHP Extension to handle common geospatial functions. The extension currently
has implementations of the Haversine and Vincenty's formulas for calculating
distances, an initial bearing calculation function, a Helmert transformation
function to transfer between different supported datums, conversions between
polar and Cartesian coordinates, conversions between Degree/Minute/Seconds and
decimal degrees, a method to simplify linear geometries, as well as a method
to calculate intermediate points on a LineString.

Instalation
===========

::

    git clone git@github.com:php-geospatial/geospatial.git
    cd geospatial
    phpize
    ./configure --enable-geospatial
    make
    sudo make install

Then add the extension to an ini file e.g. /etc/php.ini::

    extension = geospatial.so

Usage
=====

The extension makes use of the GeoJSON standard format for specifying points as
co-ordinates. One important thing to note about this format is that points are
specified longitude **first** i.e. longitude, latitude.

e.g.::

    $greenwichObservatory = array(
        'type' => 'Point',
        'coordinates' => array( -0.001483 , 51.477917);
    );


Haversine
---------

::

    $from = array(
        'type' => 'Point',
        'coordinates' => array( -104.88544, 39.06546 )
    );
    $to = array(
        'type' => 'Point',
        'coordinates' => array( -104.80, 39.06546 )
    );
    var_dump(haversine($to, $from));
    

Vincenty's Formula
------------------

Vincenty's formula attempts to provide a more accurate distance between two
points than the Haversine formula. Whereas the Haversine formula assumes a
spherical earth the Vincenty method models the earth as an ellipsoid::

    $flinders = array(
        'type' => 'Point',
        'coordinates' => array(144.42486788889, -37.951033416667 )
    );
    $buninyong = array(
        'type' => 'Point',
        'coordinates' => array(143.92649552778, -37.652821138889 )
    );
    var_dump(vincenty($flinders, $buninyong));


Helmert Transformation
----------------------

The Helmert transformation allows for the transformation of points between
different datums. It can for instance be used to convert between the WGS84
ellipsoid (GEO_WGS84) used by GPS systems and OSGB36 (GEO_AIRY_1830) used by
Ordnance Survey in the UK::

    $greenwichObservatory = array(
        'type' => 'Point',
        'coordinates' => array(-0.0014833333333333 , 51.477916666667)
    );

    $greenwichObservatoryWGS84 = transform_datum($greenwichObservatory, GEO_WGS84, GEO_AIRY_1830);

    var_dump($greenwichObservatoryWGS84);

Converting between polar and Cartesian Coordinates
--------------------------------------------------

These two functions calculate between Polar and Cartesian Coordinates,
with results depending on which ellipsoid you use.

From Polar to Cartesian::

	$lat = 53.38361111111;
	$long = 1.4669444444;

	var_dump(polar_to_cartesian($lat, $long, GEO_AIRY_1830));

And back::

	$x = 3810891.6734396;
	$y = 97591.624686311;
	$z = 5095766.3939034;

	$polar = cartesian_to_polar($x, $y, $z, GEO_AIRY_1830);
	echo round($polar['lat'], 6), PHP_EOL;
	echo round($polar['long'], 6), PHP_EOL;
	echo round($polar['height'], 3), PHP_EOL;

Converting between Degree/Min/Sec and Decimal coordinates
---------------------------------------------------------

From decimal to dms. The second argument is either "longitude" or "latitude"::

	$dms = decimal_to_dms(-1.034291666667, 'longitude');
	var_dump($dms);

Which outputs::

	array(4) {
	  ["degrees"]=> int(1)
	  ["minutes"]=> int(2)
	  ["seconds"]=> float(3.4500000011994)
	  ["direction"]=> string(1) "W"
	}

And back from DMS to decimal, where the fourth argument is either "N", "S",
"E", or "W"::

	$decimal = dms_to_decimal(0, 6, 9, 'S');

Which outputs::

	float(-0.1025)

Simplifying LineStrings
-----------------------

The ``rdp_simplify``  method implements RDP_ to simplify a LineString
according to a certain accuracy (epsilon). As first argument it takes a
GeoJSON LineString (in PHP variable format), and it outputs a similar
structure but then simplified

.. _RDP: https://en.wikipedia.org/wiki/Ramer%E2%80%93Douglas%E2%80%93Peucker_algorithm

Interpolation along a Greater Circle Line
-----------------------------------------

The ``fraction_along_gc_line`` function can be used to calculate intermediate
points along a Greater Circle Line. For example if you need to draw lines with
more accuracy with for example Leaflet. The function takes the start and end
coordinates (as GeoJson Point), and calculates the intermediate point along
those line. To calculate the point 25% from the start point to the end point,
you would use::

	$point1 = [ 'type' => 'Point', 'coordinates' => [  5, 10 ] ];
	$point2 = [ 'type' => 'Point', 'coordinates' => [ 15, 10 ] ];

	var_dump(fraction_along_gc_line($point1, $point2, 0.25));

Geohashing
----------

The `geohash_encode` function can be used to convert GeoJSON Point to a geohash::

    $geohash = geohash_encode(array('type' => 'Point', 'coordinates' => [16.4, 48.2]), 12);

Which outputs::
    
    u2edjnw17enr

Similarly, a hashed geopoint can be decoded using `geohash_decode` function::

    var_dump(geohash_decode('abcdefghijkl'));
    array(2) {
      ["type"]=>
      string(5) "Point"
      ["coordinates"]=>
      array(2) {
        [0]=>
        float(16.4)
        [1]=>
        float(48.2)
      }
    }