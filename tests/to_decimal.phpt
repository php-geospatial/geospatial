--TEST--
decimal
--FILE--
<?php

$decimal = to_decimal(1, 2, 3.45, 'W');
var_dump($decimal);

--EXPECT--
float(-1.0342916666667)