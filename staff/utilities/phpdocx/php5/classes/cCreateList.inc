<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateList extends cCreateElement {

    static private $rscInstance = NULL;
    static private $intNumericList = -1;
    private $arrList;

    private function __construct() {

    }

    public function __destruct() {

    }

    public function __toString() {
        $this->fCleanTemplate();
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateList();
        }
        return self::$rscInstance;
    }

    protected function fAddList($strList) {
        $this->xml = str_replace('__GENERATER__', $strList, $this->xml);
    }

    protected function fGenerateILFO($intVal = '') {
        $this->xml = str_replace('__GENERATEILFO__', '<' . cCreateElement::NAMESPACEWORD . ':ilfo ' . cCreateElement::NAMESPACEWORD . ':val="' . $intVal . '"></' . cCreateElement::NAMESPACEWORD . ':ilfo>', $this->xml);
    }

    protected function fGenerateILVL($intVal = '') {
        $this->xml = str_replace('__GENERATEPSTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':ilvl ' . cCreateElement::NAMESPACEWORD . ':val="' . $intVal . '"></' . cCreateElement::NAMESPACEWORD . ':ilvl>__GENERATEPSTYLE__', $this->xml);
    }

    protected function fGenerateLISTPR() {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':listPr>__GENERATEILVL____GENERATEILFO__</' . cCreateElement::NAMESPACEWORD . ':listPr>', $this->xml);
    }

    protected function fGenerateNUMID($intVal) {
        $this->xml = str_replace('__GENERATEPSTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':numId ' . cCreateElement::NAMESPACEWORD . ':val="' . $intVal . '"></' . cCreateElement::NAMESPACEWORD . ':numId>', $this->xml);
    }

    protected function fGenerateNUMPR() {
        $this->xml = str_replace('__GENERATEPSTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':numPr>__GENERATEPSTYLE__</' . cCreateElement::NAMESPACEWORD . ':numPr>', $this->xml);
    }

    protected function fGeneratePSTYLE($strVal) {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':pStyle ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '">__GENERATEPSTYLE__</' . cCreateElement::NAMESPACEWORD . ':pStyle>', $this->xml);
    }

    protected function fRunArray($arrDat, $intVal, $intDepth, $strFont = '') {
        foreach ($arrDat as $unkDat) {
            $this->fGenerateP();
            $this->fGeneratePPR();
            $this->fGeneratePSTYLE('Prrafodelista');
            $this->fGenerateNUMPR();
            $this->fGenerateILVL($intDepth);
            $this->fGenerateNUMID($intVal);
            $this->fGenerateR();
            if ($strFont != '') {
                $this->fGenerateRPR();
                $this->fGenerateRFONTS($strFont);
            }
            $this->fGenerateT($unkDat);
            $this->arrList .= $this->xml;
        }
    }

    public function fCreateList() {
        $this->xml = '';
        $arrArgs = func_get_args();
        $this->arrList = '';
        if ($arrArgs[1]['val'] == 2) {
            self::$intNumericList++;
            $this->fRunArray($arrArgs[0], $arrArgs[1]['val'] + self::$intNumericList, 1, $arrArgs[1]['font']);
        }
        else {
            $this->fRunArray($arrArgs[0], $arrArgs[1]['val'], 1, $arrArgs[1]['font']);
        }

        $this->xml = $this->arrList;
    }

}
?>