<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

define("IMGNAMESPACE", 'wp');
define("IMGNAMESPACE1", 'a');
define("IMGNAMESPACE2", 'pic');
define("CONSTWORD", 360000);
define("TAMBORDER", 12700);    


  class cCreateImage extends cCreateElement {
    var $rscInstance = NULL;
    var $name;
    var $rId;

    function cCreateImage() {
    	$this->name = '';
    	$this->rId = '';
    }

    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateImage();
       }
       return $this->rscInstance;
    }
  
  	function setName($name) {
      $this->name = $name;
    }
  
  	function getName() {
      return $this->name;
    }
  
  	function setRId($rId) {
      $this->rId = $rId;
    }
  
  	function getRId() {
      return $this->rId;
    }

    function fCreateImage() {
      $this->xml = '';
      $this->name = '';
      $this->rId = '';
      $arrArgs = func_get_args();
      if(!empty($arrArgs[0]['rId']) && (!empty($arrArgs[0]['name']))){
      	$arr = array();
      	  $arrAtributos = getimagesize($arrArgs[0]['name']);
      	  $intAjusteTexto = 0;
      	  if(!empty($arrArgs[0]['sizeX']))
      	  	$tamPxX = $arrArgs[0]['sizeX'];
      	  elseif(!empty($arrArgs[0]['scaling']))
      	  	$tamPxX = $arrAtributos[0] * $arrArgs[0]['scaling'] / 100;
      	  else
      	   	$tamPxX = $arrAtributos[0];
      	  if(!empty($arrArgs[0]['scaling']))
      	  	$tamPxY = $arrAtributos[1] * $arrArgs[0]['scaling'] / 100;
      	  elseif(!empty($arrArgs[0]['sizeY']))
      	  	$tamPxY = $arrArgs[0]['sizeY'];
      	  else
      	   	$tamPxY = $arrAtributos[1];
      	  $this->setName($arrArgs[0]['name']);
      	  $this->setRId($arrArgs[0]['rId']);
    	  $top='0';
	      $bottom='0';
	      $left ='0';
	      $right ='0';

	      switch($arrAtributos['mime']){
	      	case 'image/png':
	      		list($dpi_x, $dpi_y) = $this->get_dpi_png($arrArgs[0]['name']);
	      		// la formula es :  pixeles por la inversa de la resolucion(viene dado en pixeles/metros) por la 100 (para reducir metros a centimetros) por la constante de word (360000) 
	      		$tamWordX = round($tamPxX * 100 / $dpi_x * CONSTWORD);
	      		$tamWordY = round($tamPxY * 100 / $dpi_y * CONSTWORD);
	      		break;
	      	case 'image/jpg':
	      	case 'image/jpeg':
	      		list($dpi_x, $dpi_y) = $this->get_dpi_jpg($arrArgs[0]['name']);
	      		// la formula es :  pixeles por la inversa de la resolucion(viene dado en pixeles/inch) por la 2.54 (1 inch son 2.54 cm) por la constante de word (CONSTWORD)
	      		$tamWordX = round($tamPxX * 2.54 / $dpi_x * CONSTWORD);
	      		$tamWordY = round($tamPxY * 2.54 / $dpi_y * CONSTWORD); 
	      		break;
	      	case 'image/gif':
	      		// la formula es :  pixeles por la inversa de la resolucion de la pantalla(96 pixeles por inch) por la 2.54 (1 inch son 2.54 cm) por la constante de word (CONSTWORD)
	      		$tamWordX = round($tamPxX * 2.54 / 96 * CONSTWORD);
	      		$tamWordY = round($tamPxY * 2.54 / 96 * CONSTWORD); 
	      		break;
	      }
	      $align='';
	      $this->fGenerateP();
	      $this->fGenerateR();
	      $this->fGenerateRPR(); 
	      $this->fGenerateNOPROOF();
          $this->fGenerateDRAWING();
          $this->fGenerateINLINE();
	      $this->fGenerateEXTENT($tamWordX, $tamWordY);
	      $this->fGenerateEFFECTEXTENT($left, $top, $right, $bottom);
	      $this->fGenerateDOCPR();
	      $this->fGenerateCNVGRAPHICFRAMEPR();
	      $this->fGenerateGRAPHICPRAMELOCKS(1);
	      $this->fGenerateGRAPHIC();
	      $this->fGenerateGRAPHICDATA();
	      $this->fGeneratePIC();
	      $this->fGenerateNVPICPR();
	      $this->fGenerateCNVPR();
	      $this->fGenerateCNVPICPR();
	      $this->fGenerateBLIPFILL();
	      $this->fGenerateBLIP();
	      $this->fGenerateSTRETCH();
	      $this->fGenerateFILLRECT();
	      $this->fGenerateSPPR();
	      $this->fGenerateXFRM();
	      $this->fGenerateOFF();
	      $this->fGenerateEXT($tamWordX, $tamWordY);
	      $this->fGeneratePRSTGEOM();
	      $this->fGenerateAVLST();
	      $this->fCleanTemplate();
      }else{
      	echo 'Se ha producido un error introduciendo la imagen';
      }
    }
  
  function get_dpi_jpg($filename){    
    $a = fopen($filename,'r');   
    $string = fread($a,20);     
    fclose($a);    
    $data = bin2hex(substr($string,14,4));      
    $x = substr($data,0,4);      
    $y = substr($data,4,4);      
    return array(hexdec($x),hexdec($y));    
  }
      
  function get_dpi_png($filename){    
    $a = fopen($filename,'r');   
    $string = fread($a,1000);
    $aux = strpos($string, 'pHYs');
    $data = bin2hex(substr($string,$aux +  strlen('pHYs'),16));
    fclose($a);
    $x = substr($data, 0,8);
    $y = substr($data, 8,8);
    return array(hexdec($x),hexdec($y)); 
  }
}
?>