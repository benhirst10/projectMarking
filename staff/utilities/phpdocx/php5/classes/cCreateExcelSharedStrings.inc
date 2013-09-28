<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateExcelSharedStrings extends cCreateElement {

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
            self::$rscInstance = new cCreateExcelSharedStrings();
        }
        return self::$rscInstance;
    }

    protected function fGenerateSST($num) {
        $this->xml = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><sst xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main" count="' . $num . '" uniqueCount="' . $num . '">__GENERATESST__</sst>';
    }

    protected function fGenerateSI() {
        $this->xml = str_replace('__GENERATESST__', '<si>__GENERATESI__</si>__GENERATESST__', $this->xml);
    }

    protected function fGenerateT($name, $space='') {
        $xmlAux = '<t';
        if ($space != '')
            $xmlAux .= ' xml:space="' . $space . '"';
        $xmlAux .= '>' . $name . '</t>';
        $this->xml = str_replace('__GENERATESI__', $xmlAux, $this->xml);
    }

    public function fCreateExcelSharedStrings() {
        $this->xml = '';
        $arrArgs = func_get_args();
        $type = $arrArgs[1];
        $datos = $arrArgs[0];
        $intTamDatos = count($datos);
        foreach ($datos as $ind => $data) {
            $intTamCols = count($data);
            break;
        }
        $intTamDatos = count($datos);
        if (strpos($type, 'pie') !== false) {
            $intTamCols = 1;
        }
        else {
            $intTamDatos--;
        }
        $this->fGenerateSST($intTamDatos + $intTamCols + 2);


        for ($i = 0; $i < $intTamCols; $i++) {
            if (strpos($type, 'pie') !== false) {
                $this->fGenerateSI();
                $this->fGenerateT('0');
                break;
            }else
                $this->fGenerateSI();
            $this->fGenerateT($datos[0][$i]);
        }

        foreach ($datos as $ind => $val) {
            if ($ind == '0')
                continue;
            $this->fGenerateSI();
            $this->fGenerateT($ind);
        }
        $this->fGenerateSI();
        $this->fGenerateT(' ', 'preserve');

        $this->fGenerateSI();
        $this->fGenerateT('To change the range size of values, drag the bottom right corner');

        $this->fCleanTemplate();
    }

}
?>