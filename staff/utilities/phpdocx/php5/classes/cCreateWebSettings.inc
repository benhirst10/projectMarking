<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateWebSettings extends cCreateElement {

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
            self::$rscInstance = new cCreateWebSettings();
        }
        return self::$rscInstance;
    }

    public function fGenerateWebSettings() {
        $this->xml = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><' . cCreateElement::NAMESPACEWORD . ':webSettings xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main"><' . cCreateElement::NAMESPACEWORD . ':optimizeForBrowser /></' . cCreateElement::NAMESPACEWORD . ':webSettings>';
    }

}
?>