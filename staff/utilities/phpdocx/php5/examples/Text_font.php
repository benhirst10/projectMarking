<?php

/**
 * @author 2mdc.com
 * @version 
 */
/**
 * $arrParamsText
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

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', array('font' => 'Times New Roman'));

$arrParamsText = array(
    'b' => 'single',
    'font' => 'Times New Roman'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);

$arrParamsText = array(
    'u' => 'single',
    'font' => 'Times New Roman'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);

$arrParamsText = array(
    'i' => 'single',
    'font' => 'Times New Roman'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);

$arrParamsText = array(
    'jc' => 'both',
    'font' => 'Times New Roman'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);

$arrParamsText = array(
    'b' => 'single',
    'i' => 'single',
    'font' => 'Times New Roman'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);

$arrParamsText = array(
    'u' => 'double',
    'jc' => 'right',
    'font' => 'Times New Roman'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);

$arrParamsText = array(
    'u' => 'double',
    'pageBreakBefore' => 'on',
    'wordWrap' => 'on',
    'widowControl' => 'on',
    'font' => 'Times New Roman'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);

$arrParamsText = array(
    'u' => 'double',
    'pageBreakBefore' => 'on',
    'wordWrap' => 'off',
    'widowControl' => 'on',
    'font' => 'Times New Roman'
);

$objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', $arrParamsText);
$objDocx->fCreateDocx('example_text_font');
?>