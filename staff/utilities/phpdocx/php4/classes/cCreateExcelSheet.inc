<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreateExcelSheet extends cCreateElement {
    var $rscInstance = NULL;

    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if ($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateExcelSheet();
       }
       return $this->rscInstance;
    }

    function fCleanTemplateROW() {
      $this->xml = str_replace('__GENERATEROW__', '', $this->xml);
    }

    function fGenerateWORKSHEET() {
      $this->xml = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><worksheet xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships">__GENERATEWORKSHEET__</worksheet>';
    }

    function fGenerateDIMENSION($intSizeX, $intSizeY) {
      $letra= 'A';
      for($i=0; $i < $intSizeY; $i++)
      	$letra ++;
      $intSizeX+= $intSizeY;
      $this->xml = str_replace('__GENERATEWORKSHEET__', '<dimension ref="A1:'. $letra . $intSizeX .'"></dimension>__GENERATEWORKSHEET__', $this->xml);
    }
    
    function fGenerateSHEETVIEWS() {
      $this->xml = str_replace('__GENERATEWORKSHEET__', '<sheetViews>__GENERATESHEETVIEWS__</sheetViews>__GENERATEWORKSHEET__', $this->xml);
    }
    
    function fGenerateSHEETVIEW($tabSelected='1', $workbookViewId='0') {
      $this->xml = str_replace('__GENERATESHEETVIEWS__', '<sheetView tabSelected="' . $tabSelected . '" workbookViewId="' . $workbookViewId . '">__GENERATESHEETVIEW__</sheetView>', $this->xml);
    }
    
    function fGenerateSELECTION($num) {
      $this->xml = str_replace('__GENERATESHEETVIEW__', '<selection activeCell="B' . $num . '" sqref="B' . $num . '"></selection>', $this->xml);
    }
  
    function fGenerateSHEETFORMATPR($baseColWidth='10', $defaultRowHeight='15') {
      $this->xml = str_replace('__GENERATEWORKSHEET__', '<sheetFormatPr baseColWidth="' . $baseColWidth . '" defaultRowHeight="' . $defaultRowHeight . '"></sheetFormatPr>__GENERATEWORKSHEET__', $this->xml);
    }
  
    function fGenerateCOLS(){
      $this->xml = str_replace('__GENERATEWORKSHEET__', '<cols>__GENERATECOLS__</cols>__GENERATEWORKSHEET__', $this->xml);
    }
  
    function fGenerateCOL($min='1', $max='1', $width='11.85546875', $customWidth='1'){
      $this->xml = str_replace('__GENERATECOLS__', '<col min="'.$min.'" max="'.$max.'" width="'.$width.'" customWidth="'.$customWidth.'"></col>', $this->xml);
    }
  
    function fGenerateSHEETDATA(){
      $this->xml = str_replace('__GENERATEWORKSHEET__', '<sheetData>__GENERATESHEETDATA__</sheetData>__GENERATEWORKSHEET__', $this->xml);
    }
    
    function fGenerateROW($r, $spans){
      $spans = '1:' . ($spans+1); 
      $this->xml = str_replace('__GENERATESHEETDATA__', '<row r="'.$r.'" spans="'.$spans.'">__GENERATEROW__</row>__GENERATESHEETDATA__', $this->xml);
    }
    
    function fGenerateC($r, $s, $t=''){
      $xmlAux = '<c r="'.$r.'"';
      if($s != '')
      	$xmlAux .= ' s="'.$s.'"';
      if($t != '')
      	$xmlAux .= ' t="'.$t.'"';
      $xmlAux .= '>__GENERATEC__</c>__GENERATEROW__';
      $this->xml = str_replace('__GENERATEROW__', $xmlAux, $this->xml);
    }
    
    function fGenerateV($num){
      $this->xml = str_replace('__GENERATEC__', '<v>' . $num . '</v>', $this->xml);
    }
  
    function fGeneratePAGEMARGINS($left='0.7', $rigth='0.7', $bottom='0.75', $top='0.75', $header='0.3', $footer='0.3'){
      $this->xml = str_replace('__GENERATEWORKSHEET__', '<pageMargins left="' .$left . '" right="' .$rigth . '" top="' .$top . '" bottom="' . $bottom. '" header="' .$header . '" footer="' .$footer . '"></pageMargins>__GENERATEWORKSHEET__', $this->xml);
    }
  
    function fGeneratePAGESETUP($paperSize='9', $orientation='portrait', $id='1'){
      $this->xml = str_replace('__GENERATEWORKSHEET__', '<pageSetup paperSize="' .$paperSize . '" orientation="' .$orientation . '" r:id="rId' .$id . '"></pageSetup>__GENERATEWORKSHEET__', $this->xml);
    }

    function fGenerateTABLEPARTS($count='1'){
      $this->xml = str_replace('__GENERATEWORKSHEET__', '<tableParts count="' .$count . '">__GENERATETABLEPARTS__</tableParts>', $this->xml);
    }
    
    function fGenerateTABLEPART($id='1'){
      $this->xml = str_replace('__GENERATETABLEPARTS__', '<tablePart r:id="rId' .$id . '"></tablePart>', $this->xml);
    }
    
    
    function fCreateExcelSheet() {
      $this->xml = '';
      $arrArgs = func_get_args();
      $type = $arrArgs[1];
      $datos = $arrArgs[0];
      $intTamDatos= count($datos);
      foreach($datos as $ind => $data){
	    $intTamCols = count($data);
		break;
      }
      $intTamDatos= count($datos);
      if(strpos($type, 'pie') !== false){
      	$intTamCols = 1;
      }else{
      	$intTamDatos--;      
      }
      $this->fGenerateWORKSHEET();
      $this->fGenerateDIMENSION($intTamDatos, $intTamCols);
      $this->fGenerateSHEETVIEWS();
      $this->fGenerateSHEETVIEW();
      $this->fGenerateSELECTION($intTamDatos + $intTamCols);
      $this->fGenerateSHEETFORMATPR();
      $this->fGenerateCOLS();
      $this->fGenerateCOL();
      $this->fGenerateSHEETDATA();
      $intRow=1;
      foreach($datos as $ind => $val){
      	$intCol=1;
      	$letra = 'A';
      	$this->fGenerateROW($intRow, $intTamCols);
        $this->fGenerateC($letra.$intRow, '', 's');
      	$this->fGenerateV($intTamDatos+$intTamCols);
      	$letra++;
      	foreach($val as $valores){
      			$this->fGenerateC($letra.$intRow, '', 's');
      			$this->fGenerateV($intCol-1);
      			$intCol++;
      			$letra++;
      	}
      	$this->fCleanTemplateROW();
      	$intRow++;
      	break;
      }      
      foreach($datos as $ind => $val){
      	if($ind == '0') continue;
      	$this->fGenerateROW($intRow, $intTamCols);
      	$intCol = 1;
      	$letra = 'A';
      	$this->fGenerateC($letra.$intRow, 1, 's');
      	$this->fGenerateV($intTamCols + $intRow - 2);
      	$letra++;
      	foreach($val as $valores){
      		$s ='';
      		if($intCol != $intTamCols)
      			$s = 1;
      		$this->fGenerateC($letra.$intRow, $s);
      		$this->fGenerateV($valores);
      		$intCol++;
      		$letra++;
      	}
    	$intRow++;
      	$this->fCleanTemplateROW();
      }
      $this->fGenerateROW($intRow+1, $intTamCols);
      $intRow++;
      $this->fGenerateC('B'.$intRow, 2, 's');
      $this->fGenerateV($intTamDatos+$intTamCols+1);
      $this->fGeneratePAGEMARGINS();
      //$this->fGeneratePAGESETUP();
      $this->fGenerateTABLEPARTS();
      $this->fGenerateTABLEPART(1);
      $this->fCleanTemplate();
    }
  }
?>