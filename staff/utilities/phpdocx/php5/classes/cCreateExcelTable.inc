<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateExcelTable extends cCreateElement {

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
            self::$rscInstance = new cCreateExcelTable();
        }
        return self::$rscInstance;
    }

    protected function fGenerateTABLE($intRows, $intCols) {
        $letra = 'A';
        for ($i = 0; $i < $intCols; $i++)
            $letra++;
        $intRows++;
        $this->xml = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?><table xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main" id="1" name="Tabla1" displayName="Tabla1" ref="A1:' . $letra . $intRows . '" totalsRowShown="0" tableBorderDxfId="0">__GENERATETABLE__</table>';
    }

    protected function fGenerateTABLECOLUMNS($count = '2') {
        $this->xml = str_replace('__GENERATETABLE__', '<tableColumns count="' . $count . '">__GENERATETABLECOLUMNS__</tableColumns>__GENERATETABLE__', $this->xml);
    }

    protected function fGenerateTABLECOLUMN($id = '2', $name='') {
        $this->xml = str_replace('__GENERATETABLECOLUMNS__', '<tableColumn id="' . $id . '" name="' . $name . '"></tableColumn >__GENERATETABLECOLUMNS__', $this->xml);
    }

    protected function fGenerateTABLESTYLEINFO($showFirstColumn='0', $showLastColumn="0", $showRowStripes="1", $showColumnStripes="0") {
        $this->xml = str_replace('__GENERATETABLE__', '<tableStyleInfo   showFirstColumn="' . $showFirstColumn . '" showLastColumn="' . $showLastColumn . '" showRowStripes="' . $showRowStripes . '" showColumnStripes="' . $showColumnStripes . '"></tableStyleInfo >', $this->xml);
    }

    public function fCreateExcelTable() {
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
        $this->fGenerateTABLE($intTamDatos, $intTamCols);
        $this->fGenerateTABLECOLUMNS($intTamCols + 1);
        $this->fGenerateTABLECOLUMN(1, ' ');
        for ($i = 0; $i < $intTamCols; $i++) {
            if (strpos($type, 'pie') !== false) {
                $this->fGenerateTABLECOLUMN($i + 2, '0');
                break;
            }else
                $this->fGenerateTABLECOLUMN($i + 2, $datos[0][$i]);
        }
        $this->fGenerateTABLESTYLEINFO();
        $this->fCleanTemplate();
    }

}
?>