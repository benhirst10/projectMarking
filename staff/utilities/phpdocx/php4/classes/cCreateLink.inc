<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreateLink extends cCreateElement {
    var $rscInstance = NULL;
    var $strLink;
    var $strTitle;

    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateLink();
       }
       return $this->rscInstance;
    }

    function fGetStrLink() {
      return $this->strLink;
    }
    function fGetStrTitle() {
      return $this->strTitle;
    }

    function fGenerateFLDCHAR($strFldCharType) {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':fldChar '.NAMESPACE.':fldCharType="'.$strFldCharType.'"></'.NAMESPACE.':fldChar>', $this->xml);
    }

    function fGenerateHYPERLINK($strType) {
      $this->xml = '<'.NAMESPACE.':hyperlink r:id="rId5" w:history="1">__GENERATEP__</'.NAMESPACE.':hyperlink>';
    }

    function fGenerateINSTRTEXT($strLink = 'http://localhost') {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':instrText xml:space="preserve"> HYPERLINK "'.$strLink.'"</'.NAMESPACE.':instrText>', $this->xml);
    }

    function fGeneratePROOFERR($strType) {
      $this->xml = str_replace('__GENERATERSUB__', '<'.NAMESPACE.':proofErr '.NAMESPACE.':type="'.$strType.'"></'.NAMESPACE.':proofErr>__GENERATERSUB__', $this->xml);
    }

    function fGenerateR() {
      if(preg_match("/__GENERATEP__/", $this->xml)) {
        $this->xml = str_replace('__GENERATEP__', '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>__GENERATERSUB__', $this->xml);
      }
      elseif(preg_match("/__GENERATERSUB__/", $this->xml)) {
        $this->xml = str_replace('__GENERATERSUB__', '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>__GENERATERSUB__', $this->xml);
      }
      else {
        $this->xml = '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>__GENERATERSUB__';
      }
    }

    function fGenerateRSTYLE($strVal) {
      $this->xml = str_replace('__GENERATERPR__', '<'.NAMESPACE.':rStyle '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':rStyle>', $this->xml);
    }

    function fCreateLink() {
      $this->xml = '';
      $arrArgs = func_get_args();

      $this->fGenerateP();
      $this->fGenerateR();
      $this->fGenerateFLDCHAR('begin');
      $this->fGenerateR();
      $this->fGenerateINSTRTEXT($arrArgs[1]);
      $this->fGenerateR();
      $this->fGenerateFLDCHAR('separate');
      $this->fGeneratePROOFERR('gramStart');
      $this->fGenerateR();
      $this->fGenerateRPR();
      $this->fGenerateRSTYLE('Hipervnculo');
      $this->fGenerateT($arrArgs[0]);
      $this->fGeneratePROOFERR('gramEnd');
      $this->fGenerateR();
      $this->fGenerateFLDCHAR('end');
    }

  }
?>