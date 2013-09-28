<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  /**
    * $arrParamsImg
	  * 'name' (image path) : 'img/image.png', ...
	  * 'sizeX' (image width) : 1000, ...
	  * 'sizeY' (image height) : 1000, ...
	  * 'scaling' (% of size) 50, 100...
    */

  require_once('../classes/cCreateDocx.inc');

  $objDocx = new cCreateDocx();

  $arrParamsImg = array('name' => '../img/image.png', 
   	'scaling' => 50,
  );
      
  $objDocx->fAddImage($arrParamsImg);
  $objDocx->fAddHeader('Cabecilla');
  $objDocx->fAddFooter('Piececillo');
  
  $objDocx->fCreateDocx('ejemplo_imagen');
  
?>
