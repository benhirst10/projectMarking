<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateHeader extends cCreateElement {

    static private $rscInstance = NULL;

    private function __construct() {

    }

    public function __destruct() {

    }

    public function __toString() {
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateHeader();
        }
        return self::$rscInstance;
    }

    protected function fGenerateP() {
        $this->xml = str_replace('__GENERATEHDR__', '<' . cCreateElement::NAMESPACEWORD . ':p>__GENERATEP__</' . cCreateElement::NAMESPACEWORD . ':p>', $this->xml);
    }

    protected function fGenerateHDR() {
        $this->xml = '__GENERATEHDR____GENERATEHDRIMG__';
    }

    public function fCreateHeader() {
        $this->xml = '';
        $arrArgs = func_get_args();

        $objText = cCreateText::getInstance();
        $objText->fCreateText($arrArgs[0], $arrArgs[1]);
        $this->fGenerateHDR();
        $this->xml = str_replace('__GENERATEHDR__', (string) $objText . '__GENERATEHDR__', $this->xml);
    }

}
?>