=====================================
geospatial - PHP Geospatial Extension
=====================================

PHP Extension to handle common geospatial functions. The extension currently
has implementations of the Haversine and Vincenty's formulas as well as a
Helmert transformation function.

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
ellipsoid used by GPS systems and OSGB36 used by ordnance survey in the UK::

    $greenwichObservatory = array(
        'type' => 'Point',
        'coordinates' => array(-0.0014833333333333 , 51.477916666667)
    );
    
    $greenwichObservatoryWGS84 = transform_datum($greenwichObservatory, GEO_WGS84, GEO_AIRY_1830);
    
    var_dump($greenwichObservatoryWGS84);
