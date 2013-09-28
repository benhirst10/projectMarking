<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateChartRels extends cCreateElement {

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
            self::$rscInstance = new cCreateChartRels();
        }
        return self::$rscInstance;
    }

    protected function fGenerateRELATIONSHIPS() {
        $this->xml = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">__GENERATERELATIONSHIPS__</Relationships>';
    }

    protected function fGenerateRELATIONSHIP($idChart, $id = '1') {
        $this->xml = str_replace('__GENERATERELATIONSHIPS__', '<Relationship Id="rId' . $id . '" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/package" Target="../embeddings/datos' . $idChart . '.xlsx"></Relationship>__GENERATECHARTSPACE__', $this->xml);
    }

    public function fCreateRelationship($idChart) {
        $this->fGenerateRELATIONSHIPS();
        $this->fGenerateRELATIONSHIP($idChart);
        $this->fCleanTemplate();
    }

}
?>