<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateEndnote extends cCreateElement {

    static private $rscInstance = NULL;
    static private $intId;
    static public $boolInit = 0;

    private function __construct() {

    }

    public function __destruct() {

    }

    public function __toString() {
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateEndnote();
        }
        return self::$rscInstance;
    }

    protected function fGenerateENDNOTE($strType) {
        self::$boolInit = 1;
        if (empty(self::$intId)) {
            self::$intId = 1;
        }
        else {
            self::$intId++;
        }
        $xmlAux = '<' . cCreateElement::NAMESPACEWORDWORD . ':endnote';
        if ($strType != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORDWORD . ':type="' . $strType . '"';
        $this->xml = $xmlAux . ' ' . cCreateElement::NAMESPACEWORDWORD . ':id="' . (self::$intId - 2) . '">__GENERATEENDNOTE__</' . cCreateElement::NAMESPACEWORD . ':endnote>';
    }

    protected function fGeneratePPR() {
        $this->xml = str_replace('__GENERATEP__', '<' . cCreateElement::NAMESPACEWORD . ':pPr>__GENERATEPPR__</' . cCreateElement::NAMESPACEWORD . ':pPr>__GENERATEP__', $this->xml);
    }

    protected function fGenerateP($rsidR = '005F02E5', $rsidRDefault = '005F02E5', $rsidP = '005F02E5') {
        $this->xml = str_replace('__GENERATEENDNOTE__', '<' . cCreateElement::NAMESPACEWORD . ':p>__GENERATEP__</' . cCreateElement::NAMESPACEWORD . ':p>', $this->xml);
    }

    protected function fGenerateSEPARATOR($strType = 'separator') {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':' . $strType . '></' . cCreateElement::NAMESPACEWORD . ':' . $strType . '>', $this->xml);
    }

    protected function fGenerateSPACING($intAfter = '0', $intLine = '240', $strLineRule = 'auto') {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':spacing w:after="' . $intAfter . '" ' . cCreateElement::NAMESPACEWORD . ':line="' . $intLine . '" ' . cCreateElement::NAMESPACEWORD . ':lineRule="' . $strLineRule . '"></' . cCreateElement::NAMESPACEWORD . ':spacing>', $this->xml);
    }

    protected function fGenerateR() {
        $this->xml = str_replace('__GENERATEP__', '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>__GENERATEP__', $this->xml);
    }

    protected function fGenerateENDNOTEREF() {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':endnoteRef></' . cCreateElement::NAMESPACEWORD . ':endnoteRef>', $this->xml);
    }

    protected function fGenerateENDNOTEREFERENCE($id = '') {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':endnoteReference ' . cCreateElement::NAMESPACEWORD . ':id="' . $id . '"></' . cCreateElement::NAMESPACEWORD . ':endnoteReference>', $this->xml);
    }

    public function fCreateEndnote() {
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

    public function fCreateDocumentEndnote() {
        $this->xml = '';
        $arrArgs = func_get_args();
        parent::fGenerateP();
        $this->fGenerateR();
        $this->fGenerateT($arrArgs[0]['textDocument']);
        $this->fGenerateR();
        $this->fGenerateRPR();
        $this->fGenerateRSTYLE();
        $this->fGenerateENDNOTEREFERENCE(self::$intId - 2);
        $this->fCleanTemplate();
    }

    public function fCreateInitEndnote() {
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