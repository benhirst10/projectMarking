<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  /**
    * $arrParamsText
    *   'b' (bold): 'single'
    *   'color' (RGB color): FF0000, 000000, FFFFFF,...
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

  $objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.');

  $objDocx->fCreateDocx('ejemplo_texto_simple');
?>