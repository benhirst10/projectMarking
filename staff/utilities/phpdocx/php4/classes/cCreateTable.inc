<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreateTable extends cCreateElement {
    var $rscInstance = NULL;

    function toString() {
      $this->fCleanTemplate();
      return $this->xml;
    }

    function getInstance() {
       if ($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateTable();
       }
       return $this->rscInstance;
    }

    function fCleanTemplateR() {
      $this->xml = preg_replace('/__GENERATETR__/', '', $this->xml);
    }

    function fAddList($strList) {
      $this->xml = str_replace('__GENERATEP__', $strList, $this->xml);
    }

    function fGenerateGRIDCOLS($w) {
      $this->xml = str_replace('__GENERATEGRIDCOLS__', '<'.NAMESPACE.':tblGrid '.NAMESPACE.':w="'.$w.'"></'.NAMESPACE.':tblGrid>__GENERATEGRIDCOLS__', $this->xml);
    }

    function fGenerateHMERGE($val = '') {
    }

    function fGenerateJC($strVal = '') {
      $this->xml = str_replace('__GENERATEJC__', '<'.NAMESPACE.':jc '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':jc>', $this->xml);
    }

    function fGenerateP() {
      $this->xml = str_replace('__GENERATETC__', '<'.NAMESPACE.':p >__GENERATEP__</'.NAMESPACE.':p>', $this->xml);
    }

    function fGenerateSHD($val="horz-cross", $color="ffff00", $fill="", $bgcolor="") {
      $xmlAux = '<'.NAMESPACE.':shd val="'.$val.'"';
      if($color != '')
      	$xmlAux .= ' color="'.$color.'"';
      if($fill != '')
      	$xmlAux .= ' fill="'.$fill.'"';
      if($bgcolor != '')
      	$xmlAux .= ' wx:bgcolor="'.$bgcolor.'"';
      $xmlAux .= '></'.NAMESPACE.':shd>';      
      $this->xml = str_replace('__GENERATESHD__', $xmlAux, $this->xml);
    }

    function fGenerateTBLBORDERS() {
      $this->xml = str_replace('__GENERATETBLBORDERS__', '<'.NAMESPACE.':tblBorders>__GENERATETBLBORDER__</'.NAMESPACE.':tblBorders>', $this->xml);
    }
  
    function fGenerateTBLBOTTOM($val="single", $sz="4", $space='0', $color='auto') {
      $this->xml = str_replace('__GENERATETBLBORDER__', '<'.NAMESPACE.':bottom '.NAMESPACE.':val="'.$val.'" '.NAMESPACE.':sz="'.$sz.'" '.NAMESPACE.':space="'.$space.'" '.NAMESPACE.':color="'.$color.'"></'.NAMESPACE.':bottom>__GENERATETBLBORDER__', $this->xml);
    }
  
    function fGenerateTBL() {
      $this->xml = '<'.NAMESPACE.':tbl>__GENERATETBL__</'.NAMESPACE.':tbl>';
    }

    function fGenerateTBLSTYLE($strVal = 'TableGrid') {
      $this->xml = str_replace('__GENERATETBLSTYLE__', '<'.NAMESPACE.':tblStyle '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':tblStyle>', $this->xml);
    }
    
    function fGenerateTBLCELLSPACING($w = '', $type = '') {
      $this->xml = str_replace('__GENERATETBLCELLSPACING__', '<'.NAMESPACE.':tblCellSpacing '.NAMESPACE.':w="'.$w.'" '.NAMESPACE.':type="'.$type.'"></'.NAMESPACE.':tblCellSpacing>', $this->xml);
    }

    function fGenerateTBLGRID() {
      $this->xml = str_replace('__GENERATETBL__', '<'.NAMESPACE.':tblGrid>__GENERATEGRIDCOLS__</'.NAMESPACE.':tblGrid>__GENERATETBL__', $this->xml);
    }

    function fGenerateTBLINSIDEH($val="single", $sz="4", $space='0', $color='auto') {
      $this->xml = str_replace('__GENERATETBLBORDER__', '<'.NAMESPACE.':insideH '.NAMESPACE.':val="'.$val.'" '.NAMESPACE.':sz="'.$sz.'" '.NAMESPACE.':space="'.$space.'" '.NAMESPACE.':color="'.$color.'"></'.NAMESPACE.':insideH>__GENERATETBLBORDER__', $this->xml); 
    }
  
    function fGenerateTBLINSIDEV($val="single", $sz="4", $space='0', $color='auto') {
      $this->xml = str_replace('__GENERATETBLBORDER__', '<'.NAMESPACE.':insideV '.NAMESPACE.':val="'.$val.'" '.NAMESPACE.':sz="'.$sz.'" '.NAMESPACE.':space="'.$space.'" '.NAMESPACE.':color="'.$color.'"></'.NAMESPACE.':insideV>__GENERATETBLBORDER__', $this->xml);
    }

    function fGenerateTBLLEFT($val="single", $sz="4", $space='0', $color='auto') {
      $this->xml = str_replace('__GENERATETBLBORDER__', '<'.NAMESPACE.':left '.NAMESPACE.':val="'.$val.'" '.NAMESPACE.':sz="'.$sz.'" '.NAMESPACE.':space="'.$space.'" '.NAMESPACE.':color="'.$color.'"></'.NAMESPACE.':left>__GENERATETBLBORDER__', $this->xml);
    }
  
    function fGenerateTBLLOOK($strVal = '000001E0') {
      $this->xml = str_replace('__GENERATETBLLOOK__', '<'.NAMESPACE.':tblLook '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':tblLook>', $this->xml);
    }

    function fGenerateTBLOVERLAP($strVal = 'never') {
      $this->xml = str_replace('__GENERATETBLOVERLAP__', '<'.NAMESPACE.':tblOverlap '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':tblOverlap>', $this->xml);
    }

    function fGenerateTBLPR() {
      $this->xml = str_replace('__GENERATETBL__', '<'.NAMESPACE.':tblPr>__GENERATETBLSTYLE____GENERATEJC____GENERATETBLW____GENERATETBLLOOK____GENERATETBLOVERLAP____GENERATETBLCELLSPACING____GENERATETBLBORDERS____GENERATESHD__</'.NAMESPACE.':tblPr>__GENERATETBL__', $this->xml);
    }

    function fGenerateTBLRIGHT($val="single", $sz="4", $space='0', $color='auto') {
      $this->xml = str_replace('__GENERATETBLBORDER__', '<'.NAMESPACE.':right '.NAMESPACE.':val="'.$val.'" '.NAMESPACE.':sz="'.$sz.'" '.NAMESPACE.':space="'.$space.'" '.NAMESPACE.':color="'.$color.'"></'.NAMESPACE.':right>__GENERATETBLBORDER__', $this->xml);
    }

    function fGenerateTBLTOP($val="single", $sz="4", $space='0', $color='auto') {
      $this->xml = str_replace('__GENERATETBLBORDER__', '<'.NAMESPACE.':top '.NAMESPACE.':val="'.$val.'" '.NAMESPACE.':sz="'.$sz.'" '.NAMESPACE.':space="'.$space.'" '.NAMESPACE.':color="'.$color.'"></'.NAMESPACE.':top>__GENERATETBLBORDER__', $this->xml);
    }

    function fGenerateTBLW($strType = 'auto', $strW = '0') {
      $this->xml = str_replace('__GENERATETBLW__', '<'.NAMESPACE.':tblW '.NAMESPACE.':w="'.$strW.'" '.NAMESPACE.':type="'.$strType.'"></'.NAMESPACE.':tblW>', $this->xml);
    }

    function fGenerateTC() {
      $this->xml = str_replace('__GENERATETR__', '<'.NAMESPACE.':tc >__GENERATETC__</'.NAMESPACE.':tc>__GENERATETR__', $this->xml);
    }

    function fGenerateTCPR() {
    	$this->xml = str_replace('__GENERATETC__', '<'.NAMESPACE.':tcPr>__GENERATETCPR__</'.NAMESPACE.':tcPr>__GENERATETC__', $this->xml);
    }

    function fGenerateTCW($w = '', $type = 'dxa') {
      $this->xml = str_replace('__GENERATETCPR__', '<'.NAMESPACE.':tcW '.NAMESPACE.':w="'.$w.'" '.NAMESPACE.':type="'.$type.'"></'.NAMESPACE.':tcW>', $this->xml);
    }

    function fGenerateTR() {
      $this->xml = str_replace('__GENERATETBL__', '<'.NAMESPACE.':tr >__GENERATETR__</'.NAMESPACE.':tr>__GENERATETBL__', $this->xml);
    }
    
    function fGenerateTRPR() {
    }

    function fGenerateVMERGE($val = '') {
    }

    function fCreateTable() {
      $this->xml = '';
      $arrArgs = func_get_args();

      if(is_array($arrArgs[0])) {
        $this->fGenerateTBL();
        $this->fGenerateTBLPR();
        $this->fGenerateTBLSTYLE();
        $this->fGenerateTBLW();
        if(!empty($arrArgs[1]['border'])){
        	$this->fGenerateTBLBORDERS();
        	$this->fGenerateTBLBOTTOM();
	        $this->fGenerateTBLLEFT();
	        $this->fGenerateTBLTOP();
	        $this->fGenerateTBLRIGHT();
	        $this->fGenerateTBLINSIDEH();
	        $this->fGenerateTBLINSIDEV();
        }
        $this->fGenerateTBLLOOK();
        $this->fGenerateTBLOVERLAP();
        $intLine = 0;
        foreach($arrArgs[0] as $arrDatDepth) {
          $this->fGenerateTR();
          if($intLine == 0) {
              $this->fGenerateTC();
              $this->fGenerateP();
              $this->fGenerateR();
              $this->fGenerateT('');
          }
          $intLine++;
          foreach($arrDatDepth as $unkDat) {
            $this->fGenerateTC();
            $this->fGenerateP();
            $this->fGenerateR();            
            $this->fGenerateT($unkDat);
          }
          $this->fCleanTemplateR();
        }
      }
    }
  }
?>