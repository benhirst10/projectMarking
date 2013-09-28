<?php

/**
 * @author 2mdc.com
 * @version 
 */
require_once('../classes/cCreateDocx.inc');

$objDocx = new cCreateDocx();

$objDocx->fAddLink('Link to Google', 'http://www.google.es', 'Times New Roman');

$objDocx->fCreateDocx('example_link_font');
?>