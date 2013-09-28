<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  class cCreateXlsx {
    var $objZipXlsx;
    var $rscInstance = NULL;
    
    var $xml_Xl_Tables__Content;
    var $xml_Xl_SharedStrings__Content;
    var $xml_Xl_Sheet__Content;

    function toString() {
      return $this->objZipXlsx;
    }
	
    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateXlsx();
       }
       return $this->rscInstance;
    }

    function fCleanTemplate() {
      $this->xml_Word_Document__Template = preg_replace('/__[A-Z]+__/', '', $this->xml_Word_Document__Template);
    }
    
    function fAddTable(){
    	$arrArgs = func_get_args();
    	$objExcelTable = new cCreateExcelTable();
        $objExcelTable->fCreateExcelTable($arrArgs[0], $arrArgs[1]);
        $this->xml_Xl_Tables__Content .= $objExcelTable->toString();
    }
  
    function fAddSharedStrings(){
    	$arrArgs = func_get_args();
    	$objExcelSS = new cCreateExcelSharedStrings();
        $objExcelSS->fCreateExcelSharedStrings($arrArgs[0], $arrArgs[1]);
        $this->xml_Xl_SharedStrings__Content .= $objExcelSS->toString();
    }
  
    function fAddSheet(){
    	$arrArgs = func_get_args();
    	$objExcelSheet = new cCreateExcelSheet();
        $objExcelSheet->fCreateExcelSheet($arrArgs[0], $arrArgs[1]);
        $this->xml_Xl_Sheet__Content .= $objExcelSheet->toString();
    }
    
    function fCreateXlsx() {
      $this->objZipDocx = new PclZip('document.xlsx');
      $this->xml_Xl_Tables__Content = '';
      $this->xml_Xl_SharedStrings__Content = '';
      $this->xml_Xl_Sheet__Content = '';
      $arrArgs = func_get_args();
      if(!empty($arrArgs[0]))
      	$strFileName = $arrArgs[0]; 
      else
      	$strFileName = 'document';
      	$dirname = substr(__FILE__,0, strpos(__FILE__, '/classes')). '/excel/';
	

	@mkdir('excel', 0777);
	chdir(DIRECTORIO . '/excel');

	@mkdir('docProps', 0777);
	@mkdir('_rels', 0777);
	@mkdir('xl', 0777);
	@mkdir('xl/_rels', 0777);
	@mkdir('xl/theme', 0777);
	@mkdir('xl/worksheets', 0777);
	@mkdir('xl/worksheets/_rels', 0777);
	@mkdir('xl/tables', 0777);
	copy('../..' . $dirname . '[Content_Types].xml', '[Content_Types].xml');
	copy('../..' . $dirname . 'docProps/core.xml', 'docProps/core.xml');
	copy('../..' . $dirname . 'docProps/app.xml', 'docProps/app.xml');
	copy('../..' . $dirname . '_rels/.rels', '_rels/.rels');
	copy('../..' . $dirname . 'xl/_rels/workbook.xml.rels', 'xl/_rels/workbook.xml.rels');
	copy('../..' . $dirname . 'xl/theme/theme1.xml', 'xl/theme/theme1.xml');
	copy('../..' . $dirname . 'xl/worksheets/_rels/sheet1.xml.rels', 'xl/worksheets/_rels/sheet1.xml.rels');
	copy('../..' . $dirname . 'xl/styles.xml', 'xl/styles.xml');
	copy('../..' . $dirname . 'xl/workbook.xml', 'xl/workbook.xml');

      	$this->fAddTable($arrArgs[1], $arrArgs[2]);
	$file = fopen('xl/tables/table1.xml', 'w+');
	fwrite($file, $this->xml_Xl_Tables__Content);
	fclose($file);

      	$this->fAddSharedStrings($arrArgs[1], $arrArgs[2]);
	$file = fopen('xl/sharedStrings.xml', 'w+');
	fwrite($file, $this->xml_Xl_SharedStrings__Content);
	fclose($file);
      	
      	$this->fAddSheet($arrArgs[1], $arrArgs[2]);
	$file = fopen('xl/worksheets/sheet1.xml', 'w+');
	fwrite($file, $this->xml_Xl_Sheet__Content);
	fclose($file);


	$v_list = $this->objZipDocx->add('[Content_Types].xml,xl/,docProps/,_rels/');
	if ($v_list == 0) {
	    die("Error : ".$this->objZipDocx->errorInfo(true));
	}
	//$this->objZipDocx->create_archive();
	rename('document.xlsx', $strFileName . '.xlsx');
      	return true;
      
    }
  }
?>