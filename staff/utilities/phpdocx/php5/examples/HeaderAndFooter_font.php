<?php

/**
 * @author 2mdc.com
 * @version 
 */
/**
 * $arrParamsHeader
 *   'name' (image path): '../files/image.jpg'
 */
/**
 * $arrParamsFooter
 *   'pager' (pager): 'true'
 *   'pagerAlignment' (pager alignment): 'left', 'center', 'right'
 */
require_once('../classes/cCreateDocx.inc');

$objDocx = new cCreateDocx();

$objDocx->fAddHeader('Header', array('font' => 'Times New Roman'));

$arrParamsFooter = array(
    'pager' => 'true',
    'pagerAlignment' => 'center',
    'font' => 'Times New Roman'
);

$objDocx->fAddFooter('Times new roman', $arrParamsFooter);
$objDocx->fCreateDocx('example_header_and_footer_font.docx');
?>