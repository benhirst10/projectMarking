<?php
  /**
   * @author 2mdc.com
   * @version 
   */
error_reporting(E_PARSE); 

include_once dirname(__FILE__) . '/cCreateChartRels.inc';
include_once dirname(__FILE__) . '/cCreateEndnote.inc';
include_once dirname(__FILE__) . '/cCreateExcelSharedStrings.inc';
include_once dirname(__FILE__) . '/cCreateExcelSheet.inc';
include_once dirname(__FILE__) . '/cCreateExcelTable.inc';
include_once dirname(__FILE__) . '/cCreateFontTable.inc';
include_once dirname(__FILE__) . '/cCreateFooter.inc';
include_once dirname(__FILE__) . '/cCreateFootnote.inc';
include_once dirname(__FILE__) . '/cCreateGraphic.inc';
include_once dirname(__FILE__) . '/cCreateHeader.inc';
include_once dirname(__FILE__) . '/cCreateImage.inc';
include_once dirname(__FILE__) . '/cCreateLink.inc';
include_once dirname(__FILE__) . '/cCreateList.inc';
include_once dirname(__FILE__) . '/cCreatePage.inc';
include_once dirname(__FILE__) . '/cCreateSettings.inc';
include_once dirname(__FILE__) . '/cCreateStyle.inc';
include_once dirname(__FILE__) . '/cCreateStyleTable.inc';
include_once dirname(__FILE__) . '/cCreateTable.inc';
include_once dirname(__FILE__) . '/cCreateText.inc';
include_once dirname(__FILE__) . '/cCreateTheme1.inc';
include_once dirname(__FILE__) . '/cCreateWebSettings.inc';
include_once dirname(__FILE__) . '/cCreateXlsx.inc';
include_once dirname(__FILE__) . '/pclzip.lib.php';

define("NAMESPACE", "w");
define("SCHEMA_IMAGEDOCUMENT", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/image");
define("SCHEMA_OFFICEDOCUMENT", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument");
define("DIRECTORIO", "../build");

  class cCreateDocx {

    var $arrIdRels;
    var $arrIdWords;
    var $intIdRels;
    var $intIdWords;
    var $objZipDocx;
    var $xml_ContentTypes__Content;
    var $xml_ContentTypes__Template;
    var $xml_Rels_Rels__Content;
    var $xml_Rels_Rels__Template;
    var $xml_DocProps_App__Content;
    var $xml_DocProps_App__Template;
    var $xml_DocProps_Core__Content;
    var $xml_DocProps_Core__Template;
    var $xml_Word_Document__Template;
    var $xml_Word_Document__Content;
    var $xml_Word_Endnotes__Content;
    var $xml_Word_Endnotes__Template;
    var $xml_Word_FontTable__Template;
    var $xml_Word_FontTable__Content;    
    var $xml_Word_Footer__Content;
    var $xml_Word_Footer__Template;
    var $xml_Word_Footnotes__Content;
    var $xml_Word_Footnotes__Template;
    var $xml_Word_Header__Content;
    var $xml_Word_Header__Template;
    var $xml_Word_Numbering__Content;
    var $xml_Word_Numbering__Template;
    var $xml_Word_Rels_DocumentRels__Content;
    var $xml_Word_Rels_DocumentRels__Template;
    var $xml_Word_Rels_HeaderRels__Content;
    var $xml_Word_Rels_HeaderRels__Template;
    var $xml_Word_Settings__Content;
    var $xml_Word_Settings__Template;
    var $xml_Word_Styles__Content;
    var $xml_Word_Styles__Template;
    var $xml_Word_Theme_Theme1__Template;
    var $xml_Word_Theme_Theme1__Content;
    var $xml_Word_WebSettings__Template;
    var $xml_Word_WebSettings__Content;
    var $boolInitEndNote;
    var $boolInitFootNote;
    var $defaultFont;

    function cCreateDocx() {
      $this->arrIdRels = array();
      $this->arrIdWords = array();
      $this->intIdRels = 1;
      $this->intIdWord = 0;
      $this->xml_ContentTypes = '';
      $this->xml_Rels_Rels__Content = '';
      $this->xml_Rels_Rels__Template = '';
      $this->xml_DocProps_App__Content = '';
      $this->xml_DocProps_App__Template = '';
      $this->xml_DocProps_Core__Content = '';
      $this->xml_DocProps_Core__Template = '';
      $this->xml_Word_Document__Template = '';
      $this->xml_Word_Document__Content = '';
      $this->xml_Word_Endnotes__Content = '';
      $this->xml_Word_Endnotes__Template = '';
      $this->xml_Word_FontTable__Template = '';
      $this->xml_Word_FontTable__Content = '';
      $this->xml_Word_Footer__Content = '';
      $this->xml_Word_Footer__Template = '';
      $this->xml_Word_Footnotes__Content = '';
      $this->xml_Word_Footnotes__Template = '';
      $this->xml_Word_Header__Content = '';
      $this->xml_Word_Header__Template = '';
      $this->xml_Word_Numbering__Content;
      $this->xml_Word_Numbering__Template;
      $this->xml_Word_Rels_DocumentRels__Content = '';
      $this->xml_Word_Rels_DocumentRels__Template = '';
      $this->xml_Word_Rels_HeaderRels__Content;
      $this->xml_Word_Rels_HeaderRels__Template;
      $this->xml_Word_Settings = '';
      $this->xml_Word_Styles = '';
      $this->xml_Word_Theme_Theme1__Template = '';
      $this->xml_Word_Theme_Theme1__Content = '';
      $this->defaultFont = '';
      $this->xml_Word_WebSettings = '';
      $this->fGenerateContentType();
      $this->boolInitEndNote = 0;
      $this->boolInitFootNote = 0;
      $this->eliminaFichero(DIRECTORIO);
      $this->objZipDocx = new PclZip('documento.docx');
      @mkdir(DIRECTORIO, 0777);
    }

    function toString() {
      $this->fGenerateTemplate_Word_Document();
      return $this->xml_Word_Document__Template;
    }

    function setXml_ContentTypes($xml_ContentTypes) {
      $this->xml_ContentTypes = $xml_ContentTypes;
    }
    function getXml_ContentTypes() {
      return $this->xml_ContentTypes;
    }

    function setXml_Rels_Rels($xml_Rels_Rels) {
      $this->xml_Rels_Rels = $xml_Rels_Rels;
    }
    function getXml_Rels_Rels() {
      return $this->xml_Rels_Rels;
    }

    function setXml_DocProps_App($xml_DocProps_App) {
      $this->xml_DocProps_App = $xml_DocProps_App;
    }
    function getXml_DocProps_App() {
      return $this->xml_DocProps_App;
    }

    function setXml_DocProps_Core($xml_DocProps_Core) {
      $this->xml_DocProps_Core = $xml_DocProps_Core;
    }
    function getXml_DocProps_Core() {
      return $this->xml_DocProps_Core;
    }

    function setXml_Word_Document($xml_Word_Document) {
      $this->xml_Word_Document = $xml_Word_Document;
    }
    function getXml_Word_Document() {
      return $this->xml_Word_Document;
    }

    function setXml_Word_Endnotes($xml_Word_Endnotes) {
      $this->xml_Word_Endnotes = $xml_Word_Endnotes;
    }
    function getXml_Word_Endnotes() {
      return $this->xml_Word_Endnotes;
    }

    function setXml_Word_FontTable($xml_Word_FontTable) {
      $this->xml_Word_FontTable = $xml_Word_FontTable;
    }
    function getXml_Word_FontTable() {
      return $this->xml_Word_FontTable;
    }

    function setXml_Word_Footer1($xml_Word_Footer1) {
      $this->xml_Word_Footer1 = $xml_Word_Footer1;
    }
    function getXml_Word_Footer1() {
      return $this->xml_Word_Footer1;
    }

    function setXml_Word_Header1($xml_Word_Header1) {
      $this->xml_Word_Header1 = $xml_Word_Header1;
    }
    function getXml_Word_Header1() {
      return $this->xml_Word_Header1;
    }

    function setXml_Word_Rels_DocumentRels($xml_Word_Rels_DocumentRels) {
      $this->xml_Word_Rels_DocumentRels = $xml_Word_Rels_DocumentRels;
    }
    function getXml_Word_Rels_DocumentRels() {
      return $this->xml_Word_Rels_DocumentRels;
    }

    function setXml_Word_Settings($xml_Word_Settings) {
      $this->xml_Word_Settings = $xml_Word_Settings;
    }
    function getXml_Word_Settings() {
      return $this->xml_Word_Settings;
    }

    function setXml_Word_Styles($xml_Word_Styles) {
      $this->xml_Word_Styles = $xml_Word_Styles;
    }
    function getXml_Word_Styles() {
      return $this->xml_Word_Styles;
    }

    function setXml_Word_Theme_Theme1($xml_Word_Theme_Theme1) {
      $this->xml_Word_Theme_Theme1 = $xml_Word_Theme_Theme1;
    }
    function getXml_Word_Theme_Theme1() {
      return $this->xml_Word_Theme_Theme1;
    }

    function setXml_Word_WebSettings($xml_Word_WebSettings) {
      $this->xml_Word_WebSettings = $xml_Word_WebSettings;
    }
    function getXml_Word_WebSettings() {
      return $this->xml_Word_WebSettings;
    }

    
    function fCleanTemplate() {
      $this->xml_Word_Document__Template = preg_replace('/__[A-Z]+__/', '', $this->xml_Word_Document__Template);
    }

    function fAbsoluteZipPath($strPath) {
      $strPath = str_replace(array('/', '\\'), DIRECTORY_SEPARATOR, $strPath);
      $arrParts = array_filter(explode(DIRECTORY_SEPARATOR, $strPath), 'strlen');
      $arrAbsolutes = array();
      foreach ($arrParts as $arrDatParts) {
        if('.' == $arrDatParts) {
          continue;
        }
        if('..' == $arrDatParts) {
          array_pop($arrAbsolutes);
        }
        else {
          $arrAbsolutes[] = $arrDatParts;
        }
      }
      return implode('/', $arrAbsolutes);
    }

    function fGenerateRELATIONSHIP() {
      $arrArgs = func_get_args();
      if($arrArgs[1] == 'vbaProject')
      	$strType = 'http://schemas.microsoft.com/office/2006/relationships/vbaProject';
      else
      	$strType = 'http://schemas.openxmlformats.org/officeDocument/2006/relationships/'.$arrArgs[1];

      return '<Relationship Id="'.$arrArgs[0].'" Type="'.$strType.'" Target="'.$arrArgs[2].'"></Relationship>';
    }

    function fGenerateSECTPR($arrArgs='') {
      $objPage = new cCreatePage();
      $objPage->fCreateSECTPR($arrArgs);
      $this->xml_Word_Document__Content .= $objPage->toString();
    }

    function fGenerateContentType() {
      $this->fGenerateDEFAULT('rels', 'application/vnd.openxmlformats-package.relationships+xml');
      $this->fGenerateDEFAULT('xml', 'application/xml');
      $this->fGenerateOVERRIDE('/word/numbering.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.numbering+xml');
      $this->fGenerateOVERRIDE('/word/styles.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.styles+xml');
      $this->fGenerateOVERRIDE('/docProps/app.xml', 'application/vnd.openxmlformats-officedocument.extended-properties+xml');
      $this->fGenerateOVERRIDE('/word/settings.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.settings+xml');
      $this->fGenerateOVERRIDE('/word/theme/theme1.xml', 'application/vnd.openxmlformats-officedocument.theme+xml');
      $this->fGenerateOVERRIDE('/word/fontTable.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.fontTable+xml');
      $this->fGenerateOVERRIDE('/word/webSettings.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.webSettings+xml');
      if($this->xml_Word_Footer__Content != '' || $this->xml_Word_Header__Content != ''){
        $this->fGenerateOVERRIDE('/word/header.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.header+xml');
        $this->fGenerateOVERRIDE('/word/footer.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.footer+xml');
        $this->fGenerateOVERRIDE('/word/footnotes.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.footnotes+xml');
        $this->fGenerateOVERRIDE('/word/endnotes.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.endnotes+xml');
      }
      $this->fGenerateOVERRIDE('/docProps/core.xml', 'application/vnd.openxmlformats-package.core-properties+xml');
    }

    function fGenerateTemplate_DocProps_App() {
      $this->xml_DocProps_App__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <Properties xmlns="http://schemas.openxmlformats.org/officeDocument/2006/extended-properties" xmlns:vt="http://schemas.openxmlformats.org/officeDocument/2006/docPropsVTypes"><Template>Normal.dotm</Template><TotalTime>0</TotalTime><Pages>1</Pages><Words>1</Words><Characters>1</Characters><Application>Microsoft Office Word</Application><DocSecurity>4</DocSecurity><Lines>1</Lines><Paragraphs>1</Paragraphs><ScaleCrop>false</ScaleCrop><Company>Company</Company><LinksUpToDate>false</LinksUpToDate><CharactersWithSpaces>1</CharactersWithSpaces><SharedDoc>false</SharedDoc><HyperlinksChanged>false</HyperlinksChanged><AppVersion>12.0000</AppVersion></Properties>';
    }

    function fGenerateDate(){
	return date('Y'). '-' . date('m'). '-' . date('d'). 'T'. date('G'). ':'. date('i'). ':'. date('s'). substr(date('O'), 0, 3) . ':' . substr(date('O'), 3, 2);
    }

    function eliminaFichero($dir){
		if (is_dir($dir)) {
			if ($gd = opendir($dir)) {
			        while (($archivo = readdir($gd)) !== false) {
				            if(($archivo == '.') || ($archivo == '..'))
				            	continue;
				            if (is_dir($dir.'/'.$archivo)) {
				            	$this->eliminaFichero($dir.'/'.$archivo);
				           }else
				           		@unlink($dir.'/'.$archivo);
			        }
			        closedir($gd);
		  	}else{
		  		echo 'no se abre el directorio';
		  	}
		}
		@rmdir($dir);
    }

    function fGenerateTemplate_DocProps_Core() {
      $this->xml_DocProps_Core__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <cp:coreProperties xmlns:cp="http://schemas.openxmlformats.org/package/2006/metadata/core-properties" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:dcterms="http://purl.org/dc/terms/" xmlns:dcmitype="http://purl.org/dc/dcmitype/" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"><dc:title>Title</dc:title><dc:subject>Subject</dc:subject><dc:creator>2mdc</dc:creator><dc:description>Description</dc:description><cp:lastModifiedBy>user</cp:lastModifiedBy><cp:revision>1</cp:revision><dcterms:created xsi:type="dcterms:W3CDTF">'.$this->fGenerateDate().'</dcterms:created><dcterms:modified xsi:type="dcterms:W3CDTF">'.$this->fGenerateDate().'</dcterms:modified></cp:coreProperties>';
    }

    function fGenerateTemplate_Rels_Rels() {
      $this->xml_Rels_Rels__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">' .
        $this->fGenerateRELATIONSHIP('rId3', 'extended-properties', 'docProps/app.xml') .
        '<Relationship Id="rId2" Type="http://schemas.openxmlformats.org/package/2006/relationships/metadata/core-properties" Target="docProps/core.xml"/>' .
        $this->fGenerateRELATIONSHIP('rId1', 'officeDocument', 'word/document.xml') .
        '</Relationships>';
    }

    function fGenerateTemplate_Word_Document() {
      $arrArgs = func_get_args();
      $this->fGenerateSECTPR($arrArgs[0]);
      if(!empty($this->xml_Word_Header__Content)) {
        $this->xml_Word_Document__Content = str_replace('__GENERATEHEADERREFERENCE__', '<'.NAMESPACE.':headerReference '.NAMESPACE.':type="default" r:id="rId'.$this->arrIdWords['header'].'"></'.NAMESPACE.':headerReference>', $this->xml_Word_Document__Content);
      }
      if(!empty($this->xml_Word_Footer__Content)) {
        $this->xml_Word_Document__Content = str_replace('__GENERATEFOOTERREFERENCE__', '<'.NAMESPACE.':footerReference '.NAMESPACE.':type="default" r:id="rId'.$this->arrIdWords['footer'].'"></'.NAMESPACE.':footerReference>', $this->xml_Word_Document__Content);
      }
      $this->xml_Word_Document__Template ='<?xml version="1.0" encoding="UTF-8" standalone="yes"?>'.
        '<'.NAMESPACE.':wordDocument xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office"' .
        ' xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml"' .
        ' xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word"' . 
        ' xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml">' . 
        '<'.NAMESPACE.':body>' .
        $this->xml_Word_Document__Content .      
        '</'.NAMESPACE.':body>' .
        '</'.NAMESPACE.':wordDocument>';
      $this->fCleanTemplate();
    }

    function fGenerateTemplate_Word_Endnotes() {
      $this->xml_Word_Endnotes__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <'.NAMESPACE.':endnotes xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml">' .
        $this->xml_Word_Endnotes__Content .
        '</'.NAMESPACE.':endnotes>';
      $this->intIdWord++;
      $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'endnotes', 'endnotes.xml');
      $this->fGenerateOVERRIDE('/word/endnotes.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.endnotes+xml');
    }

    function fGenerateTemplate_Word_FontTable() {
    	$this->xml_Word_FontTable__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>' . 
        '<'.NAMESPACE.':fonts xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main">' .
    	  $this->xml_Word_FontTable__Content . 
        '</'.NAMESPACE.':fonts>';
    }

    function fGenerateTemplate_Word_Footer() {
      $this->intIdWord++;
      $this->arrIdWords['footer'] = $this->intIdWord;
      $this->xml_Word_Footer__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <'.NAMESPACE.':ftr xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml">' .
        $this->xml_Word_Footer__Content .
        '</'.NAMESPACE.':ftr>';
      $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'footer', 'footer.xml');
    }

    function fGenerateTemplate_Word_Footnotes() {
      $this->xml_Word_Footnotes__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <'.NAMESPACE.':footnotes xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml">' .
    	  $this->xml_Word_Footnotes__Content . 
        '</'.NAMESPACE.':footnotes>';
   	  $this->intIdWord++;
      $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'footnotes', 'footnotes.xml');
      $this->fGenerateOVERRIDE('/word/footnotes.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.footnotes+xml');
    }

    function fGenerateTemplate_Word_Header() {
      $this->intIdWord++;
      $this->arrIdWords['header'] = $this->intIdWord;
      $this->xml_Word_Header__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <'.NAMESPACE.':hdr xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml"> ' . 
        $this->xml_Word_Header__Content .
        '</'.NAMESPACE.':hdr>';
      $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'header', 'header.xml');
    }

    function fGenerateTemplate_Word_Numbering() {
      $this->xml_Word_Numbering__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <w:numbering xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml"><w:abstractNum w:abstractNumId="0"><w:nsid w:val="713727AE"/><w:multiLevelType w:val="hybridMultilevel"/><w:tmpl w:val="F0B4B6B8"/><w:lvl w:ilvl="0" w:tplc="0C0A0001"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="720" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Symbol" w:hAnsi="Symbol" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="1" w:tplc="0C0A0003" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val="o"/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="1440" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Courier New" w:hAnsi="Courier New" w:cs="Courier New" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="2" w:tplc="0C0A0005" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="2160" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Wingdings" w:hAnsi="Wingdings" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="3" w:tplc="0C0A0001" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="2880" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Symbol" w:hAnsi="Symbol" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="4" w:tplc="0C0A0003" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val="o"/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="3600" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Courier New" w:hAnsi="Courier New" w:cs="Courier New" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="5" w:tplc="0C0A0005" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="4320" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Wingdings" w:hAnsi="Wingdings" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="6" w:tplc="0C0A0001" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="5040" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Symbol" w:hAnsi="Symbol" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="7" w:tplc="0C0A0003" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val="o"/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="5760" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Courier New" w:hAnsi="Courier New" w:cs="Courier New" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="8" w:tplc="0C0A0005" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="6480" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Wingdings" w:hAnsi="Wingdings" w:hint="default"/></w:rPr></w:lvl></w:abstractNum><w:num w:numId="1"><w:abstractNumId w:val="0"/></w:num></w:numbering>';
    }

    function fGenerateTemplate_Word_Rels_DocumentRels() {
      $this->xml_Word_Rels_DocumentRels__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?><Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">' .
      $this->xml_Word_Rels_DocumentRels__Content .
      '</Relationships>';
    }

    function fGenerateTemplate_Word_Settings() {
    	$this->xml_Word_Settings__Template = $this->xml_Word_Settings__Content;
    }

    function fGenerateTemplate_Word_Styles() {
      $this->xml_Word_Styles__Template = 
      '<?xml version="1.0" encoding="UTF-8" standalone="yes"?><'.NAMESPACE.':styles xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main">'. 
      $this->xml_Word_Styles__Content .
      '</'.NAMESPACE.':styles>'; 
    }
  
    function fGenerateTemplate_Word_Theme_Theme1() {
      $this->fAddTheme($this->defaultFont);
      $this->xml_Word_Theme_Theme1__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><' . THEME1NAMESPACE . ':theme xmlns:a="http://schemas.openxmlformats.org/drawingml/2006/main" name="Tema de Office">' .
         $this->xml_Word_Theme_Theme1__Content . 
         '</' . THEME1NAMESPACE . ':theme>';
    }
  
    function fGenerateTemplate_ContentType() {
      $this->xml_Word_ContentType__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">' .
         $this->xml_ContentType__Content . 
         '</Types>';
    }    

    function fGenerateTemplate_Word_Rels_HeaderRels() {
      $this->xml_Word_Rels_HeaderRels__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?><Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">' . $this->xml_Word_Rels_HeaderRels__Content . '</Relationships>';
    }

    function fGenerateTemplate_Word_WebSettings() {
      $this->xml_Word_WebSettings__Template = $this->xml_Word_WebSettings__Content;
    }
    
    function fGenerateDefaultFonts(){
      $arrFont = array('name' => 'Calibri', 'pitch' => 'variable', 'usb0' => 'A00002EF', 'usb1' => '4000207B', 'usb2' => '00000000', 'usb3' => '00000000', 'csb0' => '0000009F', 'csb1' => '00000000','family' => 'swiss', 'charset' => '00', 'panose1' => '020F0502020204030204');
      $this->fAddFont($arrFont);
      $arrFont = array('name' => 'Times New Roman', 'pitch' => 'variable', 'usb0' => 'E0002AEF', 'usb1' => 'C0007841', 'usb2' => '00000009', 'usb3' => '00000000', 'csb0' => '000001FF', 'csb1' => '00000000','family' => 'roman', 'charset' => '00', 'panose1' => '02020603050405020304');
      $this->fAddFont($arrFont);
      $arrFont = array('name' => 'Cambria', 'pitch' => 'variable', 'usb0' => 'A00002EF', 'usb1' => '4000004B', 'usb2' => '00000000', 'usb3' => '00000000', 'csb0' => '0000009F', 'csb1' => '00000000','family' => 'roman', 'charset' => '00', 'panose1' => '02040503050406030204');
      $this->fAddFont($arrFont);
    }
    
      
    function fGenerateOVERRIDE($PartName, $ContentType){
      if(strpos($this->xml_ContentType__Content, 'PartName="' .$PartName. '"') === false){
        $this->xml_ContentType__Content .= '<Override PartName="' . $PartName . '" ContentType="' . $ContentType . '"> </Override>';
      }
    }
    
    function fGenerateDEFAULT($Extension, $ContentType){
      if(strpos($this->xml_ContentType__Content, 'Extension="'.$Extension) === false){
      	$this->xml_ContentType__Content .= '<Default Extension="' . $Extension . '" ContentType="' . $ContentType . '"> </Default>';
      }
    }
	
    function fGenerateDefault_Word_Rels() {
    	$this->intIdWord++;
	    $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'numbering', 'numbering.xml');
	    $this->intIdWord++;
	    $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'theme', 'theme/theme1.xml');
	    $this->intIdWord++;
	    $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'webSettings', 'webSettings.xml');
	    $this->intIdWord++;
	    $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'fontTable', 'fontTable.xml');
	    $this->intIdWord++;
	    $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'settings', 'settings.xml');
	    $this->intIdWord++;
	    $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'styles', 'styles.xml');
      
    }
    
    function fAddDefaultEndnote(){
    	$objEndnote = new cCreateEndnote();
        $objEndnote->fCreateInitEndnote(array('type' => 'separator'));
        $this->xml_Word_Endnotes__Content .= $objEndnote->toString();
        $objEndnote = new cCreateEndnote();
        $objEndnote->fCreateInitEndnote(array('type' => 'continuationSeparator'));
        $this->xml_Word_Endnotes__Content .= $objEndnote->toString();
    }
      
    function fAddDefaultFootnote(){
    	$objFootnote = new cCreateFootnote();
        $objFootnote->fCreateInitFootnote(array('type' => 'separator'));
        $this->xml_Word_Footnotes__Content .= $objFootnote->toString();
        $objFootnote = new cCreateFootnote();
        $objFootnote->fCreateInitFootnote(array('type' => 'continuationSeparator'));
        $this->xml_Word_Footnotes__Content .= $objFootnote->toString();
    }
    
    function parsePath($strDir) {
  		$barra = 0;
	  	$path = '';
		  if(($barra = strrpos($strDir, '/')) !== false)  {
			  $barra += 1;
  			$path = substr($strDir, 0,$barra);
		  }
		  if(($punto = strpos(substr($strDir, $barra), '.')) === false){
			  exit( "error en $strDir... ya que no tiene extensi�n\n");
		  }
		
  		$nombre = substr($strDir, $barra, $punto);
		  $extension = substr($strDir,$punto+$barra+1);
		  return array('path' => $path, 'nombre' => $nombre, 'extension' => $extension);
	  }

    /**
     * Crear archivo Docx con los archivos XML
     */
    function fCreateDocx() {
      $arrArgs = func_get_args();
      if(!empty($arrArgs[0]))
      	$strFileName = $arrArgs[0]; 
      else
      	$strFileName = 'document';
        $this->fGenerateTemplate_Rels_Rels();


	$actual = getcwd();
	if(($pos = strpos(getcwd(), 'build')) !== false)
		chdir(substr(getcwd(), 0, $pos+strlen('build')));
	else
		chdir(DIRECTORIO);
	@mkdir('_rels', 0777);
        $file = fopen('_rels/.rels', 'w+');
	fwrite($file, $this->xml_Rels_Rels__Template);
	fclose($file);

        $this->fGenerateTemplate_DocProps_App();
	@mkdir('docProps', 0777);
        $file = fopen('docProps/app.xml', 'w+');
	fwrite($file, $this->xml_DocProps_App__Template);
	fclose($file);

        $this->fGenerateTemplate_DocProps_Core();
	$file = fopen('docProps/core.xml', 'w+');
	fwrite($file, $this->xml_DocProps_Core__Template);
	fclose($file);
        
        $this->fAddStyle();
        $this->fGenerateTemplate_Word_Styles();
	@mkdir('word', 0777);
        $file = fopen('word/styles.xml', 'w+');
	fwrite($file, $this->xml_Word_Styles__Template);
	fclose($file);
        
        $this->fAddSettings();
        $this->fGenerateTemplate_Word_Settings();
        $file = fopen('word/settings.xml', 'w+');
	fwrite($file, $this->xml_Word_Settings__Template);
	fclose($file);
        
        $this->fAddWebSettings();
        $this->fGenerateTemplate_Word_WebSettings();
        $file = fopen('word/webSettings.xml', 'w+');
	fwrite($file, $this->xml_Word_WebSettings__Template);
	fclose($file);
        
        if(!empty($this->xml_Word_Footer__Content)) {
          $this->fGenerateTemplate_Word_Footer();
          $file = fopen('word/footer.xml', 'w+');
   	  fwrite($file, $this->xml_Word_Footer__Template);
	  fclose($file);
          if($this->boolInitEndNote == 0){
          	$this->fAddDefaultEndnote();
		$this->boolInitEndNote++;
	  }
          $this->fGenerateTemplate_Word_Endnotes();
          $file = fopen('word/endnotes.xml', 'w+');
   	  fwrite($file, $this->xml_Word_Endnotes__Template);
	  fclose($file);

          if($this->boolInitFootNote == 0){
          	$this->fAddDefaultFootnote();
		$this->boolInitFootNote++;
	  }
          $this->fGenerateTemplate_Word_Footnotes();
	  $file = fopen('word/footnotes.xml', 'w+');
   	  fwrite($file, $this->xml_Word_Footnotes__Template);
	  fclose($file);
        }

        if(!empty($this->xml_Word_Header__Content)) {
          $this->fGenerateTemplate_Word_Header();
          $file = fopen('word/header.xml', 'w+');
   	  fwrite($file, $this->xml_Word_Header__Template);
	  fclose($file);
        }

        if(!empty($this->xml_Word_Rels_HeaderRels__Content)) {
          $this->fGenerateTemplate_Word_Rels_HeaderRels();
	  @mkdir('word/_rels', 0777);
          $file = fopen('word/_rels/header.xml.rels', 'w+');
	  fwrite($file, $this->xml_Word_Rels_HeaderRels__Template);
	  fclose($file);
        }
        $this->fGenerateOVERRIDE('/word/document.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml');
        $this->fGenerateTemplate_ContentType();
        
	$file = fopen('[Content_Types].xml', 'w+');
   	fwrite($file, $this->xml_Word_ContentType__Template);
	fclose($file);

        $this->fGenerateTemplate_Word_Numbering();
	$file = fopen('word/numbering.xml', 'w+');
   	fwrite($file, $this->xml_Word_Numbering__Template);
	fclose($file);

        $this->fGenerateDefault_Word_Rels();
        if(!empty($this->xml_Word_Rels_DocumentRels__Content)) {
          $this->fGenerateTemplate_Word_Rels_DocumentRels();
	  @mkdir('word/_rels', 0777);
	  $file = fopen('word/_rels/document.xml.rels', 'w+');
   	  fwrite($file, $this->xml_Word_Rels_DocumentRels__Template);
	  fclose($file);
        }
        $arrArgsPage = array();
        if(isset($arrArgs[1])) {
        	$arrArgsPage = $arrArgs[1];
        }
        $this->fGenerateTemplate_Word_Document($arrArgsPage);
	$file = fopen('word/document.xml', 'w+');
   	fwrite($file, $this->xml_Word_Document__Template);
	fclose($file);
        
        $this->fGenerateDefaultFonts();
        $this->fGenerateTemplate_Word_FontTable();
	$file = fopen('word/fontTable.xml', 'w+');
   	fwrite($file, $this->xml_Word_FontTable__Template);
	fclose($file);
        
        $this->fGenerateTemplate_Word_Theme_Theme1();
	@mkdir('word/theme', 0777);
	$file = fopen('word/theme/theme1.xml', 'w+');
   	fwrite($file, $this->xml_Word_Theme_Theme1__Template);
	fclose($file);

	
	$v_list = $this->objZipDocx->add('[Content_Types].xml,_rels/,docProps/,word/');
	  if ($v_list == 0) {
	    die("Error : ". $this->objZipDocx->errorInfo(true));
	  }
        $arrpathFile = pathinfo($strFileName);
        rename('documento.docx', '../' . $strFileName . '.docx');

    }

    /**
     * Funciones para generar las etiquetas XML del Docx
     */

    function fAddFont($arrFont){
      $objFont = new cCreateFontTable();
      $objFont->fCreateFont($arrFont);
      $this->xml_Word_FontTable__Content .= $objFont->toString();
    }

    function fAddFooter($strDat = '', $arrParamsFooter = '') {
      $objFooter = new cCreateFooter();
      $objFooter->fCreateFooter($strDat, $arrParamsFooter);
      $this->xml_Word_Footer__Content .= $objFooter->toString();
      $this->fGenerateOVERRIDE('/word/footer.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.footer+xml');
    }
    function fAddHeader($strDat = 'Cabecera', $arrParamsHeader = '') {
      $objHeader = new cCreateHeader();
      $objHeader->fCreateHeader($strDat, $arrParamsHeader);
      $this->xml_Word_Header__Content .= $objHeader->toString();

      if(!empty($arrParamsHeader['name'])) {
        $xmlHeaderImg = $this->fAddImageHeader($arrParamsHeader);
        $this->xml_Word_Header__Content = str_replace('__GENERATEHDRIMG__', $xmlHeaderImg, $this->xml_Word_Header__Content);
      }
      $this->fGenerateOVERRIDE('/word/header.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.header+xml');
    }

    function fAddImage($arrDat='') {
      if(isset($arrDat['name']) && file_exists($arrDat['name']) == 'true') {
      	  $arrAtributos = getimagesize($arrDat['name']);
      	  if($arrAtributos['mime'] == 'image/jpg' || $arrAtributos['mime'] == 'image/jpeg' || $arrAtributos['mime'] == 'image/png' || $arrAtributos['mime'] == 'image/gif'){
		      $this->intIdWord++;
		      $objImg = new cCreateImage();
		      $arrDat['rId'] = $this->intIdWord; 	      
		      $objImg->fCreateImage($arrDat);
		      $this->xml_Word_Document__Content .= $objImg->toString();
		      $arrDir = $this->parsePath($arrDat['name']);
		      chdir(DIRECTORIO);
		      @mkdir('word', 0777);
		      @mkdir('word/media', 0777);
		      copy($arrDat['name'],'word/media/image'.$this->intIdWord. '.' . $arrDir['extension']);
		      $this->fGenerateDEFAULT($arrDir['extension'], $arrAtributos['mime']);
		      if($objImg->toString() != '')
		      	$this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'image', 'media/image'.$this->intIdWord . '.' .$arrDir['extension']);
      	  }else {
	      	echo ("La imagen que deseas insertar es de un tipo de imagen no soportado\n");
	      	return false;
	      }
      }
      else {
      	echo ("La imagen que deseas insertar no existe\n");
      	return false;
      }
    }

    function fAddGraphic($arrDatos) {
      if(isset($arrDatos['data']) && isset($arrDatos['type'])){
	      $this->intIdWord++;
	      $objGraphic = new cCreateGraphic();
	      if($objGraphic->fCreateGraphic($this->intIdWord, $arrDatos) != false){
		      $actual = getcwd();
			chdir(DIRECTORIO);
			@mkdir('word', 0777);
			@mkdir('word/charts', 0777);
			$file = fopen('word/charts/chart'.$this->intIdWord . '.xml', 'w+');
			fwrite($file, $objGraphic->getXmlChart());
			fclose($file);
		      $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'chart', 'charts/chart'.$this->intIdWord . '.xml');
		      $this->xml_Word_Document__Content .= $objGraphic->toString();
		      $this->fGenerateDEFAULT('xlsx', 'application/octet-stream');
		      $this->fGenerateOVERRIDE('/word/charts/chart'.$this->intIdWord . '.xml', 'application/vnd.openxmlformats-officedocument.drawingml.chart+xml');
	      }else{
	      	echo ("El grafico que deseas insertar ha generado errores 3\n");
	      	return false;
	      }
	      $objExcel = new cCreateXlsx();
	      if($objExcel->fCreateXlsx('datos'. $this->intIdWord , $arrDatos['data'], $arrDatos['type']) != false){
			chdir('../');

		      @mkdir('word/embeddings');//embeddings
		      copy('excel/datos'. $this->intIdWord . '.xlsx', 'word/embeddings/datos'. $this->intIdWord . '.xlsx');
  		      $objChartRels = new cCreateChartRels();
		      $objChartRels->fCreateRelationship($this->intIdWord);
		      @mkdir('word/charts/_rels', 0777);
		      $file = fopen('word/charts/_rels/chart'.$this->intIdWord . '.xml.rels', 'w+');
		      fwrite($file, $objChartRels->toString());
		      fclose($file);
		      chdir($actual);
	      }else{
	      	echo ("El grafico que deseas insertar ha generado errores 1\n");
	      	return false;
	      }
      }else{
      	echo ("El grafico que deseas insertar ha generado errores 2\n");
      	return false;
      }
    }
  
    function fAddLink($strText = '', $strLink = '') {
      $objLink = new cCreateLink();
      $objLink->fCreateLink($strText, $strLink);
      $this->xml_Word_Document__Content .= $objLink->toString();
    }

    function fAddList($arrDat, $arrParamsList = '') {
      $objList = new cCreateList();
      $objList->fCreateList($arrDat, $arrParamsList);
      $this->xml_Word_Document__Content .= $objList->toString();
    }

    function fAddMathDocx($strPath) {
   
	    $archive = new PclZip($strPath);
	    $list = $archive->extract(PCLZIP_OPT_BY_NAME, "word/document.xml",
				      PCLZIP_OPT_EXTRACT_AS_STRING);
	    if ($list == 0) {
	      echo "ERROR : ".$archive->errorInfo(true);
	      exit;
	    }
	    $strDocument = $list[0]['content'];
	      $arrEqs = preg_split('/<[\/]*m:oMathPara>/', $strDocument);
	      $this->fAddMathEq('<m:oMathPara>'.$arrEqs[1].'</m:oMathPara>');
    }
   
    function fAddMathEq($strDat) {
      $this->xml_Word_Document__Content .= '<'.NAMESPACE.':p>'.$strDat.'</'.NAMESPACE.':p>';
    }

    function fAddParagraph($strDat, $strStyle = '', $strAlign = '') {
      $objParagraph = new cCreateText();
      $objParagraph->fCreateParagraph($strDat, $strStyle, $strAlign);
      $this->xml_Word_Document__Content .= $objParagraph->toString();
    }

    function fAddTable($arrDat, $arrParamsTable = '') {
      $objTable = new cCreateTable();
      $objTable->fCreateTable($arrDat, $arrParamsTable);
      $this->xml_Word_Document__Content .= $objTable->toString();
    }
  
    function fAddText($strDat, $strStyle = '') {
      $objText = new cCreateText();
      $objText->fCreateText($strDat, $strStyle);
      $this->xml_Word_Document__Content .= $objText->toString();
    }
    
    function fAddTitle($strDat, $strStyle = '') {
      $objText = new cCreateText();
      $objText->fCreateTitle($strDat, $strStyle);
      $this->xml_Word_Document__Content .= $objText->toString();
    }
  
    function fAddTheme($strFont){
      $objTheme = new cCreateTheme1();
      $objTheme->fCreateTheme($strFont);
      $this->xml_Word_Theme_Theme1__Content .= $objTheme->toString();
    }
     
    function fAddSettings(){
      $objSettings = new cCreateSettings();
      $objSettings->fGenerateSettings();
      $this->xml_Word_Settings__Content .= $objSettings->toString();
    }

    function fAddStyle(){
      $objStyle = new cCreateStyle();
      $objStyle->fCreateStyle();
      $this->xml_Word_Styles__Content .= $objStyle->toString();
    }
  
    function fAddWebSettings(){
      $objWebSettings = new cCreateWebSettings();
      $objWebSettings->fGenerateWebSettings();
      $this->xml_Word_WebSettings__Content .= $objWebSettings->toString();
    }
  
    function fAddBreak($strType=''){
      $objPage = new cCreatePage();
      $objPage->fGeneratePageBreak($strType);
      $this->xml_Word_Document__Content .= $objPage->toString();
    }
    
    function fSetDefaultFont($strFont){
	$this->defaultFont = $strFont;
    }
  }
?>