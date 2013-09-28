<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  /**
    * $strParamsBreak (break) : line, page	
    */

  require_once('../classes/cCreateDocx.inc');

    $objDocx = new cCreateDocx();
  $objDocx->fAddHeader('Cabecilla');
  $objDocx->fAddFooter('Piececillo');
      
  $strParamsBreak = 'line';
  $objDocx->fAddBreak($strParamsBreak);
  $objDocx->fAddBreak($strParamsBreak);
  $objDocx->fAddBreak($strParamsBreak);
  $strParamsBreak = 'page';
  $objDocx->fAddBreak($strParamsBreak);
  
  $objDocx->fCreateDocx('ejemplo_break');
  
?>
