<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreateEndnote extends cCreateElement {
    var $intId;

    function cCreateEndnote($intId){
	$this->intId = $intId+1;
    }
	
    function toString() {
      return $this->xml;
    }

    function fGenerateENDNOTE($strType) {
      $xmlAux = '<'.NAMESPACE.':endnote';
      if($strType != '')
      	$xmlAux .= ' '.NAMESPACE.':type="'.$strType.'"'; 
      $this->xml = $xmlAux . ' '.NAMESPACE.':id="'.($this->intId - 2).'">__GENERATEENDNOTE__</'.NAMESPACE.':endnote>';
    }

    function fGeneratePPR() {
      $this->xml = str_replace('__GENERATEP__', '<'.NAMESPACE.':pPr>__GENERATEPPR__</'.NAMESPACE.':pPr>__GENERATEP__', $this->xml);
    }
    

    function fGenerateP($rsidR = '005F02E5', $rsidRDefault = '005F02E5', $rsidP = '005F02E5') {
      $this->xml = str_replace('__GENERATEENDNOTE__', '<'.NAMESPACE.':p>__GENERATEP__</'.NAMESPACE.':p>', $this->xml);
    }

    function fGenerateSEPARATOR($strType = 'separator') {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':'.$strType.'></'.NAMESPACE.':'.$strType.'>', $this->xml);
    }

    function fGenerateSPACING($intAfter = '0', $intLine = '240', $strLineRule = 'auto') {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':spacing w:after="'.$intAfter.'" '.NAMESPACE.':line="'.$intLine.'" '.NAMESPACE.':lineRule="'.$strLineRule.'"></'.NAMESPACE.':spacing>', $this->xml);
    }
    
    function fGenerateR() {
      $this->xml = str_replace('__GENERATEP__', '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>__GENERATEP__', $this->xml);
    }
    
    function fGenerateENDNOTEREF() {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':endnoteRef></'.NAMESPACE.':endnoteRef>', $this->xml);
    }
  
    function fGenerateENDNOTEREFERENCE($id = '') {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':endnoteReference '.NAMESPACE.':id="' . $id . '"></'.NAMESPACE.':endnoteReference>', $this->xml);
    }
    
  	function fCreateEndnote() {
      $this->xml = '';
      $arrArgs = func_get_args();
      $this->fGenerateENDNOTE('');
      $this->fGenerateP();
      $this->fGeneratePPR();
      $this->fGeneratePSTYLE();
      $this->fGenerateR();
      $this->fGenerateRPR();
      $this->fGenerateRSTYLE();
      $this->fGenerateENDNOTEREF();
      $this->fGenerateR();
      $this->fGenerateT($arrArgs[0]['textEndNote']);
      $this->fCleanTemplate();
    }
    
  	function fCreateDocumentEndnote() {
      $this->xml = '';
      $arrArgs = func_get_args();
      parent::fGenerateP();
      $this->fGenerateR();
      $this->fGenerateT($arrArgs[0]['textDocument']);
      $this->fGenerateR();
      $this->fGenerateRPR();
      $this->fGenerateRSTYLE();
      $this->fGenerateENDNOTEREFERENCE($this->intId-2);
      $this->fCleanTemplate();
    }
    
    function fCreateInitEndnote() {
      $this->xml = '';
      $arrArgs = func_get_args();
      $this->fGenerateENDNOTE($arrArgs[0]['type']);
      $this->fGenerateP();
      $this->fGeneratePPR();
      $this->fGenerateSPACING();
      $this->fGenerateR();
      $this->fGenerateSEPARATOR($arrArgs[0]['type']);
      $this->fCleanTemplate();
    }
  }
?>