<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreateWebSettings extends cCreateElement {
    var $rscInstance = NULL;
    var $xml;

    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateWebSettings();
       }
       return $this->rscInstance;
    }

    function fGenerateWebSettings(){
       $this->xml .= '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><'.NAMESPACE.':webSettings xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main"><'.NAMESPACE.':optimizeForBrowser /></'.NAMESPACE.':webSettings>';
    }
    
  }
?>