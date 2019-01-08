--TEST--
Test for rdp_simplify
--FILE--
<?php
$json = json_decode( file_get_contents( dirname( __FILE__ ) . '/rdp-belgium.json' ) );
$points = $json[0]->geometry->coordinates[0];

$result = RDP_Simplify( $points, 0.001 );
var_dump( count( $result ) );

$result = RDP_Simplify( $points, 0.01 );
var_dump( count( $result ) );
?>
--EXPECT--
int(1029)
int(261)
