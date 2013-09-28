<?php

/**
 * @author 2mdc.com
 * @version 
 */
/**
 * $arrParamsTitle
 *   'val' (title type): 1, 2, 3,...
 *   'type' (type): subtitle o title
 *   'b' (bold): 'single'
 *   'color' (color RGB): FF0000, 000000, FFFFFF,...
 *   'i' (italic): 'single'
 *   'jc' (text alignment): 'left', 'center', 'right', 'both', 'distribute'
 *   'sz' (size): 1, 2, 3, 4,...
 *   'u' (underline): 'single', 'words', ''double', 'dotted', 'dash', 'wave'
 *   'pageBreakBefore' (forces a page break before a paragraph) : on, off
 *   'widowControl' (prevents Word from printing the last line of a paragraph by itself at the top of the page (widow) or the first line of a paragraph at the bottom of a page (orphan)) : on, off
 *   'wordWrap' (breaks a line in the middle of a word) : on, off
 */
require_once('../classes/cCreateDocx.inc');

$objDocx = new cCreateDocx();

$arrParamsTitle = array(
    'val' => 1,
    'u' => 'double',
    'jc' => 'right'
);

$objDocx->fAddTitle('Lorem ipsum dolor sit amet.', $arrParamsTitle);

$arrParamsTitle = array(
    'val' => 2,
    'u' => 'double',
    'jc' => 'right'
);
$objDocx->fAddTitle('Lorem ipsum dolor sit amet.', $arrParamsTitle);

$arrParamsTitle = array(
    'val' => 3,
    'u' => 'double',
    'jc' => 'right'
);
$objDocx->fAddTitle('Lorem ipsum dolor sit amet.', $arrParamsTitle);

$arrParamsTitle = array(
    'val' => 2,
    'u' => 'double',
    'jc' => 'right'
);
$objDocx->fAddTitle('Lorem ipsum dolor sit amet.', $arrParamsTitle);

$arrParamsTitle = array(
    'val' => 1,
    'u' => 'double',
    'jc' => 'right'
);
$objDocx->fAddTitle('Lorem ipsum dolor sit amet.', $arrParamsTitle);

$objDocx->fCreateDocx('example_title');
?>