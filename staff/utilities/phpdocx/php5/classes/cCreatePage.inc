<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreatePage extends cCreateElement {

    static private $rscInstance = NULL;
    protected $xml;

    private function __construct() {

    }

    public function __destruct() {

    }

    public function __toString() {
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreatePage();
        }
        return self::$rscInstance;
    }

    protected function fGenerateSECTPR($rId = '12240') {
        $this->xml = '<' . cCreateElement::NAMESPACEWORD . ':sectPr ' . cCreateDocx::NAMESPACEWORD . ':rsidR="' . $rId . '" ' . cCreateDocx::NAMESPACEWORD . ':rsidRPr="' . $rId . '" ' . cCreateDocx::NAMESPACEWORD . ':rsidSect="' . $rId . '">__GENERATEHEADERREFERENCE____GENERATEFOOTERREFERENCE____GENERATESECTPR__</' . cCreateElement::NAMESPACEWORD . ':sectPr>';
    }

    protected function fGeneratePGSZ($w = '11906', $h = '16838', $orient='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':pgSz ' . cCreateElement::NAMESPACEWORD . ':w="' . $w . '" ' . cCreateElement::NAMESPACEWORD . ':h="' . $h . '"';
        if ($orient != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':orient="' . $orient . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':pgSz>__GENERATEPGSZ__';
        $this->xml = str_replace('__GENERATESECTPR__', $xmlAux, $this->xml);
    }

    protected function fGeneratePGMAR() {
        $top = '1440';
        $right = '1800';
        $bottom = '1440';
        $left = '1800';
        $header = '720';
        $footer = '720';
        $gutter = '0';
        $arrArgs = func_get_args();
        if (isset($arrArgs[0][0]['top']))
            $top = $arrArgs[0][0]['top'];
        if (isset($arrArgs[0][0]['bottom']))
            $bottom = $arrArgs[0][0]['bottom'];
        if (isset($arrArgs[0][0]['right']))
            $right = $arrArgs[0][0]['right'];
        if (isset($arrArgs[0][0]['left']))
            $left = $arrArgs[0][0]['left'];

        $this->xml = str_replace('__GENERATEPGSZ__', '<' . cCreateElement::NAMESPACEWORD . ':pgMar ' . cCreateElement::NAMESPACEWORD . ':top="' . $top . '" ' . cCreateElement::NAMESPACEWORD . ':right="' . $right . '" ' . cCreateElement::NAMESPACEWORD . ':bottom="' . $bottom . '" ' . cCreateElement::NAMESPACEWORD . ':left="' . $left . '" ' . cCreateElement::NAMESPACEWORD . ':header="' . $header . '" ' . cCreateElement::NAMESPACEWORD . ':footer="' . $footer . '" ' . cCreateElement::NAMESPACEWORD . ':gutter="' . $gutter . '"></' . cCreateElement::NAMESPACEWORD . ':pgMar>__GENERATEPGMAR__', $this->xml);
    }

    protected function fGenerateCOLS($num = '', $sep = '', $space = '708', $equalWidth = '') {
        $this->xml = str_replace('__GENERATEPGMAR__', '<' . cCreateElement::NAMESPACEWORD . ':cols ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '"></' . cCreateElement::NAMESPACEWORD . ':cols>__GENERATECOLS__', $this->xml);
    }

    protected function fGenerateCOL($w = '', $space = '708') {

    }

    protected function fGenerateDOCGRID($linepitch = '360') {
        $this->xml = str_replace('__GENERATECOLS__', '<' . cCreateElement::NAMESPACEWORD . ':docGrid ' . cCreateElement::NAMESPACEWORD . ':linePitch="' . $linepitch . '"></' . cCreateElement::NAMESPACEWORD . ':docGrid>', $this->xml);
    }

    protected function fGenerateBR($type = '') {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':br ' . cCreateElement::NAMESPACEWORD . ':type="' . $type . '"></' . cCreateElement::NAMESPACEWORD . ':br>', $this->xml);
    }

    protected function fGenerateSECTIONSECTPR($rId = '12240') {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':sectPr ' . cCreateDocx::NAMESPACEWORD . ':rsidR="' . $rId . '" ' . cCreateDocx::NAMESPACEWORD . ':rsidRPr="' . $rId . '" ' . cCreateDocx::NAMESPACEWORD . ':rsidSect="' . $rId . '">__GENERATEHEADERREFERENCE____GENERATEFOOTERREFERENCE____GENERATESECTPR__</' . cCreateElement::NAMESPACEWORD . ':sectPr>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateTITLEPG() {
        $this->xml = str_replace('__GENERATECOLS__', '<' . cCreateElement::NAMESPACEWORD . ':titlePg></' . cCreateElement::NAMESPACEWORD . ':titlePg>__GENERATECOLS__', $this->xml);
    }

    public function fCreatePage($arrDat, $strStyle = '') {
        $this->xml = '';
    }

    public function fCreateSECTPR() {
        $this->xml = '';
        $arrArgs = func_get_args();
        $this->fGenerateSECTPR();
        if (!empty($arrArgs[0]['orient']) && $arrArgs[0]['orient'] == 'landscape')
            $this->fGeneratePGSZ(16838, 11906, 'landscape');
        else
            $this->fGeneratePGSZ(11906, 16838);
        $this->fGeneratePGMAR($arrArgs);
        $this->fGenerateCOLS();
        if (!empty($arrArgs[0]['titlePage']))
            $this->fGenerateTITLEPG();
        $this->fGenerateDOCGRID();
    }

    public function fGeneratePageBreak($strType) {
        $this->xml = '';
        $this->fGenerateP();
        if ($strType != 'line' && $strType != '') {
            $this->fGenerateR();
            $this->fGenerateBR($strType);
        }
        $this->fCleanTemplate();
    }

}
?>