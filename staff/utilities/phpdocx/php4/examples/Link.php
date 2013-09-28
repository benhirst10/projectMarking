<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  require_once('../classes/cCreateDocx.inc');
  
  $objDocx = new cCreateDocx();

  $objDocx->fAddLink('Enlace a Google', 'http://www.google.es');

  $objDocx->fCreateDocx('ejemplo_enlace');
?>