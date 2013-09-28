<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreateFooter extends cCreateElement {
    var $rscInstance = NULL;

    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateFooter();
       }
       return $this->rscInstance;
    }

    function fGenerateFTR() {
      $this->xml = '__GENERATEFTR__';
    }

    function fGenerateP() {
      $this->xml = str_replace('__GENERATEFTR__', '<'.NAMESPACE.':p>__GENERATEP__</'.NAMESPACE.':p>', $this->xml);
    }

    function fGenerateR() {
      if(!empty($this->xml)) {
        if(preg_match("/__GENERATEP__/", $this->xml)) {
          $this->xml = str_replace('__GENERATEP__', '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>__GENERATERSUB__', $this->xml);
        }
        elseif(preg_match("/__GENERATER__/", $this->xml)) {
          $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>__GENERATERSUB__', $this->xml);
        }
        elseif(preg_match("/__GENERATERSUB__/", $this->xml)) {
          $this->xml = str_replace('__GENERATERSUB__', '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>__GENERATERSUB__', $this->xml);
        }
      }
      else {
        $this->xml = '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>__GENERATERSUB__';
      }
    }

    function fGeneratePTAB($strRelativeTo = 'margin', $strAlignment = 'right', $strLeader = 'none') {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':ptab '.NAMESPACE.':relativeTo="'.$strRelativeTo.'" '.NAMESPACE.':alignment="'.$strAlignment.'" '.NAMESPACE.':leader="'.$strLeader.'"></'.NAMESPACE.':ptab>', $this->xml);
    }

    function fGenerateFLDSIMPLE() {
      $this->xml = str_replace('__GENERATERSUB__', '<'.NAMESPACE.':fldSimple '.NAMESPACE.':instr=" PAGE   \* MERGEFORMAT "></'.NAMESPACE.':fldSimple>', $this->xml);
    }

    function fCreateFooter() {
      $this->xml = '';
      $arrArgs = func_get_args();

      $this->fGenerateFTR();
      $this->fGenerateP();
      $this->fGenerateR();
      $this->fGenerateT($arrArgs[0]);
      if($arrArgs[1]['pager'] == 'true') {
        $this->fGenerateR();
        $this->fGeneratePTAB('margin', $arrArgs[1]['pagerAlignment']);
        $this->fGenerateFLDSIMPLE();
      }
    }
  }
?>