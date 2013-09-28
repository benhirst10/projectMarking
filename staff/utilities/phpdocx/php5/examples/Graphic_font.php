<?php

/**
 * @author 2mdc.com
 * @version 
 */
/**
 * $arrParamsGraphic
 *   'data' (array)
 *   'type' (chart type): pieChart, barChart, colChart
 *   'title' (chart title) : 'title',
 *   'sizeX' (size width chart, in centimeters)=> 10
 *   'sizeY' (size height chart, in centimeters)=> 10 
 */
require_once('../classes/cCreateDocx.inc');

$objDocx = new cCreateDocx();

$arrDatos = array(
    'legend1' => array(10, 11, 12),
    'legend2' => array(0, 1, 2),
    'legend3' => array(40, 41, 42)
);
$arrArgs = array('data' => $arrDatos,
    'type' => 'pieChart',
    'title' => 'titulo',
    'sizeX' => 10, 'sizeY' => 10, //en cm
    'font' => 'Times New Roman'
);
$objDocx->fAddGraphic($arrArgs);

$objDocx->fCreateDocx('example_graphic_font');
?>
