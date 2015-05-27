<?php
/**
 * Created by PhpStorm.
 * User: ggrenuy
 * Date: 22.04.15
 * Time: 10:11
 */
ob_start();
echo "1:blah\n";
ob_start();
echo "2:blah";
// ob_get_clean() returns the contents of the last buffer opened.  The first "blah" and the output of var_dump are flushed from the top buffer on exit
var_dump(ob_get_clean());