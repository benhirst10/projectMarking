<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateFooter extends cCreateElement {

    static private $rscInstance = NULL;
    static private $numberPage = 0;

    private function __construct() {

    }

    public function __destruct() {

    }

    public function __toString() {
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateFooter();
        }
        return self::$rscInstance;
    }

    protected function fGenerateFTR() {
        $this->xml = '__GENERATEFTR__';
    }

    protected function fGenerateP() {
        $this->xml = str_replace('__GENERATEFTR__', '<' . cCreateElement::NAMESPACEWORD . ':p>__GENERATEP__</' . cCreateElement::NAMESPACEWORD . ':p>__GENERATEFTR__', $this->xml);
    }

    protected function fGenerateR() {
        if (!empty($this->xml)) {
            if (preg_match("/__GENERATEP__/", $this->xml)) {
                $this->xml = str_replace('__GENERATEP__', '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>__GENERATERSUB__', $this->xml);
            }
            elseif (preg_match("/__GENERATER__/", $this->xml)) {
                $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>__GENERATERSUB__', $this->xml);
            }
            elseif (preg_match("/__GENERATERSUB__/", $this->xml)) {
                $this->xml = str_replace('__GENERATERSUB__', '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>__GENERATERSUB__', $this->xml);
            }
        }
        else {
            $this->xml = '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>__GENERATERSUB__';
        }
    }

    protected function fGeneratePTAB($strRelativeTo = 'margin', $strAlignment = 'right', $strLeader = 'none') {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':ptab ' . cCreateElement::NAMESPACEWORD . ':relativeTo="' . $strRelativeTo . '" ' . cCreateElement::NAMESPACEWORD . ':alignment="' . $strAlignment . '" ' . cCreateElement::NAMESPACEWORD . ':leader="' . $strLeader . '"></' . cCreateElement::NAMESPACEWORD . ':ptab>', $this->xml);
    }

    protected function fGenerateFLDSIMPLE() {
        $this->xml = str_replace('__GENERATERSUB__', '<' . cCreateElement::NAMESPACEWORD . ':fldSimple ' . cCreateElement::NAMESPACEWORD . ':instr=" PAGE   \* MERGEFORMAT "></' . cCreateElement::NAMESPACEWORD . ':fldSimple>', $this->xml);
    }

    public function fCreateFooter() {
        $this->xml = '';
        $arrArgs = func_get_args();
        $this->fGenerateFTR();
        if ($arrArgs[1]['pager'] == 'true') {
            $this->fGenerateP();
            $this->fGenerateR();
            $this->fGeneratePTAB('margin', $arrArgs[1]['pagerAlignment']);
            $this->fGenerateFLDSIMPLE();
        }
        $objText = cCreateText::getInstance();
        $objText->fCreateText($arrArgs[0], $arrArgs[1]);
        $obj = preg_replace('/__[A-Z]+__/', '', (string) $objText);
        $this->xml = str_replace('__GENERATEFTR__', $obj . '__GENERATEFTR__', $this->xml);
    }

}
?>