<?php

/**
 * @author 2mdc.com
 * @version 
 */
require_once('../classes/cCreateDocx.inc');

$objDocx = new cCreateDocx();

$objDocx->fAddLink('Link to google', 'http://www.google.es');

$objDocx->fCreateDocx('example_link');
?>