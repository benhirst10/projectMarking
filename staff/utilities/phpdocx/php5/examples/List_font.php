<?php

/**
 * @author 2mdc.com
 * @version 
 */
/**
 * $arrParamsList
 *   'val' (list type): 0 (clear), 1 (inordinate), 2 (numerical)
 */
require_once '../classes/cCreateDocx.inc';

$objDocx = new cCreateDocx();

$arrDatsList = array(
    'Line 1',
    'Line 2',
    'Line 3',
    'Line 4',
    'Line 5'
);

$arrParamsList = array(
    'val' => 1,
    'font' => 'Times New Roman'
);

$objDocx->fAddList($arrDatsList, $arrParamsList);

$objDocx->fCreateDocx('example_list_font');
?>