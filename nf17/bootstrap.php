<?php

function clean($string){
	return htmlentities(trim($string),ENT_QUOTES,'UTF-8');
}

if (!defined("HOME")) {
	define("HOME", $_SERVER['REQUEST_URI']);
}

?>