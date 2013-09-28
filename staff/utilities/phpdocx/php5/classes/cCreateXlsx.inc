<?php

/**
 * @author 2mdc.com
 * @version 
 */
class cCreateXlsx {

    private $objZipXlsx;
    static private $rscInstance = NULL;
    private $xml_Xl_Tables__Content;
    private $xml_Xl_SharedStrings__Content;
    private $xml_Xl_Sheet__Content;

    public function __construct() {

    }

    public function __destruct() {

    }

    public function __toString() {
        return $this->objZipXlsx;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateXlsx();
        }
        return self::$rscInstance;
    }

    private function fCleanTemplate() {
        $this->xml_Word_Document__Template = preg_replace('/__[A-Z]+__/', '', $this->xml_Word_Document__Template);
    }

    protected function fAddTable() {
        $arrArgs = func_get_args();
        $objExcelTable = cCreateExcelTable::getInstance();
        $objExcelTable->fCreateExcelTable($arrArgs[0], $arrArgs[1]);
        $this->xml_Xl_Tables__Content .= (string) $objExcelTable;
    }

    protected function fAddSharedStrings() {
        $arrArgs = func_get_args();
        $objExcelSS = cCreateExcelSharedStrings::getInstance();
        $objExcelSS->fCreateExcelSharedStrings($arrArgs[0], $arrArgs[1]);
        $this->xml_Xl_SharedStrings__Content .= (string) $objExcelSS;
    }

    protected function fAddSheet() {
        $arrArgs = func_get_args();
        $objExcelSheet = cCreateExcelSheet::getInstance();
        $objExcelSheet->fCreateExcelSheet($arrArgs[0], $arrArgs[1]);
        $this->xml_Xl_Sheet__Content .= (string) $objExcelSheet;
    }

    public function fCreateXlsx() {
        $this->objZipXlsx = new ZipArchive();
        $this->objZipXlsx->open('document.xlsx', ZIPARCHIVE::CREATE);
        $this->xml_Xl_Tables__Content = '';
        $this->xml_Xl_SharedStrings__Content = '';
        $this->xml_Xl_Sheet__Content = '';
        $arrArgs = func_get_args();
        if (!empty($arrArgs[0]))
            $strFileName = $arrArgs[0];
        else
            $strFileName = 'document';
        try {
            $dirname = substr(__FILE__, 0, strpos(__FILE__, '/classes')) . '/excel/';
            $this->objZipXlsx->addFile($dirname . '[Content_Types].xml', '[Content_Types].xml');
            $this->objZipXlsx->addFile($dirname . 'docProps/core.xml', 'docProps/core.xml');
            $this->objZipXlsx->addFile($dirname . 'docProps/app.xml', 'docProps/app.xml');
            $this->objZipXlsx->addFile($dirname . '_rels/.rels', '_rels/.rels');
            $this->objZipXlsx->addFile($dirname . 'xl/_rels/workbook.xml.rels', 'xl/_rels/workbook.xml.rels');
            $this->objZipXlsx->addFile($dirname . 'xl/theme/theme1.xml', 'xl/theme/theme1.xml');
            $this->objZipXlsx->addFile($dirname . 'xl/worksheets/_rels/sheet1.xml.rels', 'xl/worksheets/_rels/sheet1.xml.rels');
            $this->objZipXlsx->addFile($dirname . 'xl/styles.xml', 'xl/styles.xml');
            $this->objZipXlsx->addFile($dirname . 'xl/workbook.xml', 'xl/workbook.xml');

            $this->fAddTable($arrArgs[1], $arrArgs[2]);
            $this->objZipXlsx->addFromString('xl/tables/table1.xml', $this->xml_Xl_Tables__Content);

            $this->fAddSharedStrings($arrArgs[1], $arrArgs[2]);
            $this->objZipXlsx->addFromString('xl/sharedStrings.xml', $this->xml_Xl_SharedStrings__Content);

            $this->fAddSheet($arrArgs[1], $arrArgs[2]);
            $this->objZipXlsx->addFromString('xl/worksheets/sheet1.xml', $this->xml_Xl_Sheet__Content);
            $this->objZipXlsx->close();
            rename('document.xlsx', $strFileName . '.xlsx');
            return true;
        }
        catch (Exception $e) {
            echo 'There was an error related to XLSX file: ', $e->getMessage(), "\n";
            return false;
        }
    }

}
?>