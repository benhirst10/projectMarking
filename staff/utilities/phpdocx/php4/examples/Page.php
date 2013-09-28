<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  /**
    * $arrParamsPage
    *   'orient' (page orientation) : normal,landscape
    *   'top' (top margin) : 4000,...
    *   'bottom' (bottom margin) : 4000,...
    *   'right' (right margin) : 4000,...
    *   'left' (left margin) : 4000,...
    */

  require_once('../classes/cCreateDocx.inc');

  $objDocx = new cCreateDocx();

  $objDocx->fAddHeader('Cabecilla');
  $objDocx->fAddFooter('Piececillo');
  
  $objDocx->fAddText('Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.');

  $arrParamsPage = array('titlePage' => 1, 'orient' => 'normal', 'top' => 4000, 'bottom' => 4000, 'right' => 4000, 'left' => 4000);
  $objDocx->fCreateDocx('ejemplo_page', $arrParamsPage);
  
?>
