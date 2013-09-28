<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreateHeader extends cCreateElement {
    var $rscInstance = NULL;

    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateHeader();
       }
       return $this->rscInstance;
    }

    function fGenerateP() {
      $this->xml = str_replace('__GENERATEHDR__', '<'.NAMESPACE.':p>__GENERATEP__</'.NAMESPACE.':p>', $this->xml);
    }

    function fGenerateHDR() {
      $this->xml = '__GENERATEHDR____GENERATEHDRIMG__';
    }

    function fCreateHeader() {
      $this->xml = '';
      $arrArgs = func_get_args();

      $this->fGenerateHDR();
      $this->fGenerateP();
      $this->fGenerateR();
      $this->fGenerateT($arrArgs[0]);
    }
  }
?>