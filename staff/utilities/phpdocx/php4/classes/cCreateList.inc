<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreateList extends cCreateElement {
    var $rscInstance = NULL;
    var $intNumericList = -1;
    var $arrList;

    function toString() {
      $this->fCleanTemplate();
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateList();
       }
       return $this->rscInstance;
    }

    function fAddList($strList) {
      $this->xml = str_replace('__GENERATER__', $strList, $this->xml);
    }

    function fGenerateILFO($intVal = '') {
      $this->xml = str_replace('__GENERATEILFO__', '<'.NAMESPACE.':ilfo '.NAMESPACE.':val="'.$intVal.'"></'.NAMESPACE.':ilfo>', $this->xml);
    }

    function fGenerateILVL($intVal = '') {
      $this->xml = str_replace('__GENERATEPSTYLE__', '<'.NAMESPACE.':ilvl '.NAMESPACE.':val="'.$intVal.'"></'.NAMESPACE.':ilvl>__GENERATEPSTYLE__', $this->xml);
    }

    function fGenerateLISTPR() {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':listPr>__GENERATEILVL____GENERATEILFO__</'.NAMESPACE.':listPr>', $this->xml);
    }

    function fGenerateNUMID($intVal) {
      $this->xml = str_replace('__GENERATEPSTYLE__', '<'.NAMESPACE.':numId '.NAMESPACE.':val="'.$intVal.'"></'.NAMESPACE.':numId>', $this->xml);
    }

    function fGenerateNUMPR() {
      $this->xml = str_replace('__GENERATEPSTYLE__', '<'.NAMESPACE.':numPr>__GENERATEPSTYLE__</'.NAMESPACE.':numPr>', $this->xml);
    }

    function fGeneratePSTYLE($strVal) {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':pStyle '.NAMESPACE.':val="'.$strVal.'">__GENERATEPSTYLE__</'.NAMESPACE.':pStyle>', $this->xml);
    }

    function fRunArray($arrDat, $intVal, $intDepth) {
      foreach($arrDat as $unkDat) {
          $this->fGenerateP();
          $this->fGeneratePPR();
          $this->fGeneratePSTYLE('Prrafodelista');
          $this->fGenerateNUMPR();
          $this->fGenerateILVL($intDepth);
          $this->fGenerateNUMID($intVal);
          $this->fGenerateR();
          $this->fGenerateT($unkDat);
          $this->arrList .= $this->xml;
      }
    }

    function fCreateList() {
      $this->xml = '';
      $arrArgs = func_get_args();
      $this->arrList = '';
      if($arrArgs[1]['val'] == 2) {
      	$this->intNumericList++;
      	$this->fRunArray($arrArgs[0], $arrArgs[1]['val'] + $this->intNumericList, 1);
      }
      else {
      	$this->fRunArray($arrArgs[0], $arrArgs[1]['val'], 1);
      }

      $this->xml = $this->arrList;
    }
  }
?>