<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreatePage extends cCreateElement {
    var $rscInstance = NULL;
    var $xml;

    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreatePage();
       }
       return $this->rscInstance;
    }
    
    function fGenerateSECTPR($rId = '12240') {    
       $this->xml = '<'.NAMESPACE.':sectPr ' . NAMESPACE.':rsidR="' . $rId . '" '.NAMESPACE.':rsidRPr="' . $rId . '" '.NAMESPACE.':rsidSect="' . $rId . '">__GENERATEHEADERREFERENCE____GENERATEFOOTERREFERENCE____GENERATESECTPR__</'.NAMESPACE.':sectPr>';
    }
    function fGeneratePGSZ($w = '11906', $h = '16838', $orient='') {
    	$xmlAux = '<'.NAMESPACE.':pgSz '.NAMESPACE.':w="'.$w.'" '.NAMESPACE.':h="'.$h.'"';
    	if($orient != '')
    		$xmlAux .= ' '.NAMESPACE.':orient="'.$orient.'"';
    	$xmlAux .= '></'.NAMESPACE.':pgSz>__GENERATEPGSZ__';
       	$this->xml = str_replace('__GENERATESECTPR__', $xmlAux, $this->xml);
    }

    function fGeneratePGMAR(){
       $top = '1440';
       $right = '1800';
       $bottom = '1440';
       $left = '1800';
       $header = '720';
       $footer = '720';
       $gutter = '0';
       $arrArgs = func_get_args();
       if(isset($arrArgs[0][0]['top']))
       	 $top = $arrArgs[0][0]['top'];
       if(isset($arrArgs[0][0]['bottom']))
       	 $bottom = $arrArgs[0][0]['bottom'];
       if(isset($arrArgs[0][0]['right']))
       	 $right = $arrArgs[0][0]['right'];
       if(isset($arrArgs[0][0]['left']))
       	 $left = $arrArgs[0][0]['left'];
       
       $this->xml = str_replace('__GENERATEPGSZ__', '<'.NAMESPACE.':pgMar '.NAMESPACE.':top="'.$top.'" '.NAMESPACE.':right="'.$right.'" '.NAMESPACE.':bottom="'.$bottom.'" '.NAMESPACE.':left="'.$left.'" '.NAMESPACE.':header="'.$header.'" '.NAMESPACE.':footer="'.$footer.'" '.NAMESPACE.':gutter="'.$gutter.'"></'.NAMESPACE.':pgMar>__GENERATEPGMAR__', $this->xml);
    }

    function fGenerateCOLS($num = '', $sep = '', $space = '708', $equalWidth = '') {
       $this->xml = str_replace('__GENERATEPGMAR__', '<'.NAMESPACE.':cols '.NAMESPACE.':space="'.$space.'"></'.NAMESPACE.':cols>__GENERATECOLS__', $this->xml);
    }

    function fGenerateCOL($w = '', $space = '708') {
    }

    function fGenerateDOCGRID($linepitch = '360') {
       $this->xml = str_replace('__GENERATECOLS__', '<'.NAMESPACE.':docGrid '.NAMESPACE.':linePitch="'.$linepitch.'"></'.NAMESPACE.':docGrid>', $this->xml);
    }
    
    function fGenerateBR($type = '') {
    	$this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':br '.NAMESPACE.':type="'.$type.'"></'.NAMESPACE.':br>', $this->xml);
    }
  
    function fGenerateSECTIONSECTPR($rId = '12240') {
    	$this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':sectPr '.NAMESPACE.':rsidR="' . $rId . '" '.NAMESPACE.':rsidRPr="' . $rId . '" '.NAMESPACE.':rsidSect="' . $rId . '">__GENERATEHEADERREFERENCE____GENERATEFOOTERREFERENCE____GENERATESECTPR__</'.NAMESPACE.':sectPr>__GENERATEPPR__', $this->xml);      
    }
    
    function fGenerateTITLEPG() {
    	$this->xml = str_replace('__GENERATECOLS__', '<'.NAMESPACE.':titlePg></'.NAMESPACE.':titlePg>__GENERATECOLS__', $this->xml);      
    }

    function fCreatePage($arrDat, $strStyle = '') {
      $this->xml = '';
    }
    
    function fCreateSECTPR(){
    	$this->xml='';
    	$arrArgs = func_get_args();
    	$this->fGenerateSECTPR();
    	if(!empty($arrArgs[0]['orient']) && $arrArgs[0]['orient'] == 'landscape')
	     	$this->fGeneratePGSZ(16838, 11906, 'landscape');
	    else
	     	$this->fGeneratePGSZ(11906, 16838);
    	$this->fGeneratePGMAR($arrArgs);
    	$this->fGenerateCOLS();
    	if(!empty($arrArgs[0]['titlePage']))
	    	$this->fGenerateTITLEPG();
    	$this->fGenerateDOCGRID();
   }
   
   function fGeneratePageBreak($strType){
   		$this->xml='';
   		$this->fGenerateP();
   		if($strType != 'line' && $strType != ''){
	   		$this->fGenerateR();   		
	   		$this->fGenerateBR($strType);   		
   		}
   		$this->fCleanTemplate();
   }
  }
?>