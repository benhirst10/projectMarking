<?php

/**
 * @author 2mdc.com
 * @version 
 */
/**
 * $arrParamsTable
 *   'border' (border type) : none, single, double
 */
require_once('../classes/cCreateDocx.inc');

$objDocx = new cCreateDocx();

$arrTable = array(
    array(
        'Title A',
        'Title B',
        'Title C',
        'Title D',
        'Title E'
    ),
    array(
        'Line A',
        'Value 01',
        'Value 02',
        'Value 03',
        'Value 04',
        'Value 05'
    ),
    array(
        'Line B',
        'Value 11',
        'Value 12',
        'Value 13',
        'Value 14',
        'Value 15'
    ),
    array(
        'Line C',
        'Value 21',
        'Value 22',
        'Value 23',
        'Value 24',
        'Value 25'
    )
);

$arrParamsTable = array(
    'border' => 'single',
    'font' => 'Times New Roman'
);

$objDocx->fAddTable($arrTable, $arrParamsTable);
$objDocx->fCreateDocx('example_table_font');
?>