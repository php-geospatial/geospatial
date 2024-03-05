<?php
/** @generate-function-entries */

/**
 * @var float
 * @cvalue GEO_EARTH_RADIUS
 */
const GEO_EARTH_RADIUS = UNKNOWN;

/**
 * @var float
 * @cvalue GEO_WGS84
 */
const GEO_WGS84 = UNKNOWN;

/**
 * @var int
 * @cvalue GEO_AIRY_1830
 */
const GEO_AIRY_1830 = UNKNOWN;

/**
 * @var int
 * @cvalue GEO_WGS84
 */
const GEO_WGS84 = UNKNOWN;


function dms_to_decimal(float $degrees, float $minutes, float $seconds, string $direction = ""): float {}
function decimal_to_dms(float $decimal, string $coordinate): array {}

function helmert(float $x, float $y, float $z, int $from_reference_ellipsoid = 0, int $to_reference_ellipsoid = 0): array {}
function polar_to_cartesian(float $latitude, float $longitude, int $reference_ellipsoid = 0): array {}
function cartesian_to_polar(float $x, float $y, float $z, int $reference_ellipsoid = 0): array {}
function transform_datum(array $coordinates, int $from_reference_ellipsoid, int $to_reference_ellipsoid): array {}

function haversine(array $from, array $to, float $radius = GEO_EARTH_RADIUS): float {}
function vincenty(array $from, array $to, float $reference_ellipsoid = GEO_WGS84): float {}

function fraction_along_gc_line(array $from, array $to, float $fraction): array {}
function initial_bearing(array $from, array $to): float {}

function rdp_simplify(array $points, float $epsilon): array {}

function interpolate_linestring(array $line, float $epsilon): array {}

function geohash_encode(array $point, int $precision = 12): string {}
function geohash_decode(string $geohash): array {}
