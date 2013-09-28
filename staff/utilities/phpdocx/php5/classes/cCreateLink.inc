<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateLink extends cCreateElement {

    static private $rscInstance = NULL;
    private $strLink;
    private $strTitle;

    public function __construct() {

    }

    public function __destruct() {

    }

    public function __toString() {
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateLink();
        }
        return self::$rscInstance;
    }

    public function fGetStrLink() {
        return $this->strLink;
    }

    public function fGetStrTitle() {
        return $this->strTitle;
    }

    protected function fGenerateFLDCHAR($strFldCharType) {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':fldChar ' . cCreateElement::NAMESPACEWORD . ':fldCharType="' . $strFldCharType . '"></' . cCreateElement::NAMESPACEWORD . ':fldChar>', $this->xml);
    }

    protected function fGenerateHYPERLINK($strType) {
        $this->xml = '<' . cCreateElement::NAMESPACEWORD . ':hyperlink r:id="rId5" w:history="1">__GENERATEP__</' . cCreateElement::NAMESPACEWORD . ':hyperlink>';
    }

    protected function fGenerateINSTRTEXT($strLink = 'http://localhost') {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':instrText xml:space="preserve"> HYPERLINK "' . $strLink . '"</' . cCreateElement::NAMESPACEWORD . ':instrText>', $this->xml);
    }

    protected function fGeneratePROOFERR($strType) {
        $this->xml = str_replace('__GENERATERSUB__', '<' . cCreateElement::NAMESPACEWORD . ':proofErr ' . cCreateElement::NAMESPACEWORD . ':type="' . $strType . '"></' . cCreateElement::NAMESPACEWORD . ':proofErr>__GENERATERSUB__', $this->xml);
    }

    protected function fGenerateR() {
        if (preg_match("/__GENERATEP__/", $this->xml)) {
            $this->xml = str_replace('__GENERATEP__', '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>__GENERATERSUB__', $this->xml);
        }
        elseif (preg_match("/__GENERATERSUB__/", $this->xml)) {
            $this->xml = str_replace('__GENERATERSUB__', '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>__GENERATERSUB__', $this->xml);
        }
        else {
            $this->xml = '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>__GENERATERSUB__';
        }
    }

    protected function fGenerateRSTYLE($strVal) {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':rStyle ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':rStyle>', $this->xml);
    }

    public function fCreateLink() {
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
        if (!empty($arrArgs[2]))
            $this->fGenerateRFONTS($arrArgs[2]);
        $this->fGenerateRSTYLE('Hipervnculo');
        $this->fGenerateT($arrArgs[0]);
        $this->fGeneratePROOFERR('gramEnd');
        $this->fGenerateR();
        $this->fGenerateFLDCHAR('end');
    }

}
?>