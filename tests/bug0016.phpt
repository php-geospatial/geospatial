--TEST--
Test for issue #16: Segfault on rdp_simplify for GeoJSON
--FILE--
<?php
$geojson = json_decode('{"type":"LineString","coordinates":[[0,0],[1,0],[2,0],[2,1],[2,2],[1,2],[0,2],[0,1],[0,0]]}', true);

try {
	var_dump(rdp_simplify($geojson, 1));
} catch ( InvalidArgumentException $e ) {
	echo $e->getMessage(), "\n";
}
?>
--EXPECT--
Expected a coordinate pair as an array, but string given
