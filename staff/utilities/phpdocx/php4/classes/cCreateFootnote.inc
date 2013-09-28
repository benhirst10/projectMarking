<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreateFootnote extends cCreateElement {
    var $rscInstance = NULL;
    var $intId;
    var $boolInit = 0;
    
    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateFootnote();
       }
       return $this->rscInstance;
    }

    function fGenerateFOOTNOTE($strType) {
      $this->boolInit = 1;
      if(empty($this->intId)) {
        $this->intId = 1;
      }
      else {
        $this->intId++;
      }
      $xmlAux = '<'.NAMESPACE.':footnote';
      if($strType != '')
      	$xmlAux .= ' '.NAMESPACE.':type="'.$strType.'"'; 
      $this->xml = $xmlAux . ' '.NAMESPACE.':id="'.($this->intId - 2).'">__GENERATEFOOTNOTE__</'.NAMESPACE.':footnote>';
      
    }

    function fGenerateP($rsidR = '005F02E5', $rsidRDefault = '005F02E5', $rsidP = '005F02E5') {
      $this->xml = str_replace('__GENERATEFOOTNOTE__', '<'.NAMESPACE.':p>__GENERATEP__</'.NAMESPACE.':p>', $this->xml);
    }

    function fGenerateSEPARATOR($strType = 'separator') {
      $this->xml = str_replace('__GENERATER__', '<w:'.$strType.'></w:'.$strType.'>', $this->xml);
    }

    function fGeneratePPR() {
      $this->xml = str_replace('__GENERATEP__', '<'.NAMESPACE.':pPr>__GENERATEPPR__</'.NAMESPACE.':pPr>__GENERATEP__', $this->xml);
    }
    
 
    function fGenerateSPACING($intAfter = '0', $intLine = '240', $strLineRule = 'auto') {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':spacing w:after="'.$intAfter.'" '.NAMESPACE.':line="'.$intLine.'" '.NAMESPACE.':lineRule="'.$strLineRule.'"></'.NAMESPACE.':spacing>', $this->xml);
    }
        
    function fGenerateR() {
      $this->xml = str_replace('__GENERATEP__', '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>__GENERATEP__', $this->xml);
    }
    
    function fGenerateFOOTNOTEREF() {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':footnoteRef></'.NAMESPACE.':footnoteRef>', $this->xml);
    }
  
    function fGenerateFOOTNOTEREFERENCE($id = '') {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':footnoteReference '.NAMESPACE.':id="' . $id . '"></'.NAMESPACE.':footnoteReference>', $this->xml);
    }
    
    function fCreateInitFootnote() {
      $this->xml = '';
      $arrArgs = func_get_args();
      $this->fGenerateFOOTNOTE($arrArgs[0]['type']);
      $this->fGenerateP();
      $this->fGeneratePPR();
      $this->fGenerateSPACING();
      $this->fGenerateR();
      $this->fGenerateSEPARATOR($arrArgs[0]['type']);
      $this->fCleanTemplate();
    }
  }
?>