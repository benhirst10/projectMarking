<?php

/**
 * @author 2mdc.com
 * @version 
 */
require_once('../classes/cCreateDocx.inc');

$objDocx = new cCreateDocx();
$objDocx->fSetDefaultFont('Arial');
$objDocx->fAddHeader('Document header');
$arrParamsText = array(
    'b' => 'single',
    'color' => 'FF0000',
    'jc' => 'center',
    'sz' => '20'
);
$objDocx->fAddText('Introduction', $arrParamsText);
$arrParamsText = array(
    'jc' => 'both',
);
$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehen
derit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cpidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);
$objDocx->fAddBreak('page');
$arrParamsText = array(
    'jc' => 'left',
    'i' => 'single'
);
$objDocx->fAddText('Formula:', $arrParamsText);
$objDocx->fAddMathDocx('../docx/math.docx');
$objDocx->fAddLink('View more', 'http://es.wikipedia.org');
$objDocx->fAddBreak();
$objDocx->fAddText('List: ');
$arrDatsList = array(
    'Lorem',
    'Ipsum',
    'Dolor',
    'Sit',
    'Met'
);
$arrParamsList = array(
    'val' => 1
);
$objDocx->fAddList($arrDatsList, $arrParamsList);
$objDocx->fAddFooter('Document footer');
$arrParamsPage = array(
    'top' => 4000,
    'bottom' => 4000,
    'right' => 4000,
    'left' => 4000
);
$arrDatos = array(
    array('sublegend11', 'sublegend12', 'sublegend13'),
    'legend1' => array(10, 11, 12),
    'legend2' => array(0, 1, 2),
    'legend3' => array(40, 41, 42)
);
$arrArgs = array('data' => $arrDatos,
    'type' => 'lineChart',
    'title' => 'titulo',
    'sizeX' => 10, 'sizeY' => 10//en cm
);
$objDocx->fAddGraphic($arrArgs);

$arrDatos = array(
    array('sublegend21', 'sublegend22', 'sublegend23'),
    'legend1' => array(10, 11, 12),
    'legend2' => array(0, 1, 2),
    'legend3' => array(40, 41, 42)
);
$arrArgs = array('data' => $arrDatos,
    'type' => 'barChart',
);
$objDocx->fAddGraphic($arrArgs);

$arrDatos = array(
    'legend1' => array(10, 11, 12),
    'legend2' => array(0, 1, 2),
    'legend3' => array(40, 41, 42)
);
$arrArgs = array('data' => $arrDatos,
    'type' => 'pieChart',
    'title' => 'titulo',
    'sizeX' => 10, 'sizeY' => 10//en cm
);
$objDocx->fAddGraphic($arrArgs);

$arrParamsImg = array('name' => '../img/image.png',
    'tamX' => 1000, 'tamY' => 1000
);

$objDocx->fAddImage($arrParamsImg);
$strParamsBreak = 'line';
$objDocx->fAddBreak($strParamsBreak);
$arrParamsText = array(
    'b' => 'single'
);

$strParamsBreak = 'line';
$objDocx->fAddBreak($strParamsBreak);
$strParamsBreak = 'line';
$objDocx->fAddBreak($strParamsBreak);
$strParamsBreak = 'line';
$objDocx->fAddBreak($strParamsBreak);
$arrDatsList = array(
    'Line 1',
    'Line 2',
    'Line 3',
    'Line 4',
    'Line 5'
);

$arrParamsList = array(
    'val' => 2
);

$objDocx->fAddList($arrDatsList, $arrParamsList);

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
);

$objDocx->fAddTable($arrTable, $arrParamsTable);

$arrDatsList = array(
    'Line 1',
    'Line 2',
    'Line 3',
    'Line 4',
    'Line 5'
);

$arrParamsList = array(
    'val' => 1
);

$objDocx->fAddList($arrDatsList, $arrParamsList);
$arrParamsText = array(
    'val' => 1,
    'u' => 'double',
    'jc' => 'right'
);

$objDocx->fAddTitle('Lorem ipsum dolor sit amet.', $arrParamsText);
$arrParamsText = array(
    'val' => 2,
    'u' => 'double',
    'jc' => 'right'
);
$objDocx->fAddTitle('Lorem ipsum dolor sit amet.', $arrParamsText);
$arrParamsText = array(
    'val' => 3,
    'u' => 'double',
    'jc' => 'right'
);
$objDocx->fAddTitle('Lorem ipsum dolor sit amet.', $arrParamsText);
$arrParamsText = array(
    'val' => 2,
    'u' => 'double',
    'jc' => 'right'
);
$objDocx->fAddTitle('Lorem ipsum dolor sit amet.', $arrParamsText);
$arrParamsText = array(
    'val' => 1,
    'u' => 'double',
    'jc' => 'right'
);
$objDocx->fAddTitle('Lorem ipsum dolor sit amet.', $arrParamsText);
$arrParamsText = array(
    'b' => 'single'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.');

$arrParamsText = array(
    'b' => 'single'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);

$arrParamsText = array(
    'u' => 'single'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);

$arrParamsText = array(
    'i' => 'single'
);

$strParamsBreak = 'line';
$objDocx->fAddBreak($strParamsBreak);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);

$arrParamsText = array(
    'jc' => 'both'
);
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
    'border' => 'single'
);

$objDocx->fAddTable($arrTable, $arrParamsTable);


$strParamsBreak = 'page';
$objDocx->fAddBreak($strParamsBreak);
$objDocx->fAddMathEq('<m:oMathPara><m:oMath><m:r><m:t>∪±∞=~×</m:t></m:r></m:oMath></m:oMathPara>');

$objDocx->fAddMathDocx('../docx/math.docx');

$arrDatsList = array(
    'Line 1',
    'Line 2',
    'Line 3',
    'Line 4',
    'Line 5'
);

$arrParamsList = array(
    'val' => 2
);

$objDocx->fAddList($arrDatsList, $arrParamsList);
$objDocx->fAddLink('Link to Google', 'http://www.google.es');
$arrDatos = array(
    array('sublegend21', 'sublegend22', 'sublegend23'),
    'legend1' => array(10, 11, 12),
    'legend2' => array(0, 1, 2),
    'legend3' => array(40, 41, 42)
);
$arrArgs = array('data' => $arrDatos,
    'type' => 'colChart',
    'title' => 'titulo'
);
$objDocx->fAddGraphic($arrArgs);
$arrParamsImg = array('name' => '../img/image.png',
    'tamX' => 1000, 'tamY' => 1000
);
$objDocx->fAddImage($arrParamsImg);

$arrParamsPage = array('orient' => 'normal', 'titlePage' => 1);
$objDocx->fCreateDocx('document_full_font', $arrParamsPage);
?>