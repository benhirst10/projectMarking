<?php

/**
 * @author 2mdc.com
 * @version 
 */
error_reporting(E_PARSE);

function __autoload($strClassName) {
    require_once dirname(__FILE__) . '/' . $strClassName . '.inc';
}

class cCreateDocx {
    const NAMESPACEWORD = 'w';
    const SCHEMA_IMAGEDOCUMENT = 'http://schemas.openxmlformats.org/officeDocument/2006/relationships/image';
    const SCHEMA_OFFICEDOCUMENT = 'http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument';

    private $arrIdRels;
    private $arrIdWords;
    private $intIdRels;
    private $intIdWords;
    private $objZipDocx;
    private $xml_ContentTypes__Content;
    private $xml_ContentTypes__Template;
    private $xml_Rels_Rels__Content;
    private $xml_Rels_Rels__Template;
    private $xml_DocProps_App__Content;
    private $xml_DocProps_App__Template;
    private $xml_DocProps_Core__Content;
    private $xml_DocProps_Core__Template;
    private $xml_Word_Document__Template;
    private $xml_Word_Document__Content;
    private $xml_Word_Endnotes__Content;
    private $xml_Word_Endnotes__Template;
    private $xml_Word_FontTable__Template;
    private $xml_Word_FontTable__Content;
    private $xml_Word_Footer__Content;
    private $xml_Word_Footer__Template;
    private $xml_Word_Footnotes__Content;
    private $xml_Word_Footnotes__Template;
    private $xml_Word_Header__Content;
    private $xml_Word_Header__Template;
    private $xml_Word_Numbering__Content;
    private $xml_Word_Numbering__Template;
    private $xml_Word_Rels_DocumentRels__Content;
    private $xml_Word_Rels_DocumentRels__Template;
    private $xml_Word_Rels_HeaderRels__Content;
    private $xml_Word_Rels_HeaderRels__Template;
    private $xml_Word_Settings__Content;
    private $xml_Word_Settings__Template;
    private $xml_Word_Styles__Content;
    private $xml_Word_Styles__Template;
    private $xml_Word_Theme_Theme1__Template;
    private $xml_Word_Theme_Theme1__Content;
    private $xml_Word_WebSettings__Template;
    private $xml_Word_WebSettings__Content;
    private $defaultFont;

    public function __construct() {
        $this->arrIdRels = array();
        $this->arrIdWords = array();
        $this->intIdRels = 1;
        $this->intIdWord = 0;
        $this->objZipDocx = new ZipArchive();
        $this->objZipDocx->open('document.docx', ZIPARCHIVE::CREATE);
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
        $this->xml_Word_Settings__Content = '';
        $this->xml_Word_Settings__Template = '';
        $this->xml_Word_Styles = '';
        $this->xml_Word_Styles__Content = '';
        $this->xml_Word_Styles__Template = '';
        $this->xml_Word_Theme = '';
        $this->xml_Word_Theme_Theme1__Template = '';
        $this->xml_Word_Theme_Theme1__Content = '';
        $this->xml_Word_WebSettings = '';
        $this->xml_Word_WebSettings__Template = '';
        $this->xml_Word_WebSettings__Content = '';
        $this->defaultFont = '';
        $this->fGenerateContentType();
    }

    public function __destruct() {

    }

    public function __toString() {
        $this->fGenerateTemplate_Word_Document();
        return $this->xml_Word_Document__Template;
    }

    public function setXml_ContentTypes($xml_ContentTypes) {
        $this->xml_ContentTypes = $xml_ContentTypes;
    }

    public function getXml_ContentTypes() {
        return $this->xml_ContentTypes;
    }

    public function setXml_Rels_Rels($xml_Rels_Rels) {
        $this->xml_Rels_Rels = $xml_Rels_Rels;
    }

    public function getXml_Rels_Rels() {
        return $this->xml_Rels_Rels;
    }

    public function setXml_DocProps_App($xml_DocProps_App) {
        $this->xml_DocProps_App = $xml_DocProps_App;
    }

    public function getXml_DocProps_App() {
        return $this->xml_DocProps_App;
    }

    public function setXml_DocProps_Core($xml_DocProps_Core) {
        $this->xml_DocProps_Core = $xml_DocProps_Core;
    }

    public function getXml_DocProps_Core() {
        return $this->xml_DocProps_Core;
    }

    public function setXml_Word_Document($xml_Word_Document) {
        $this->xml_Word_Document = $xml_Word_Document;
    }

    public function getXml_Word_Document() {
        return $this->xml_Word_Document;
    }

    public function setXml_Word_Endnotes($xml_Word_Endnotes) {
        $this->xml_Word_Endnotes = $xml_Word_Endnotes;
    }

    public function getXml_Word_Endnotes() {
        return $this->xml_Word_Endnotes;
    }

    public function setXml_Word_FontTable($xml_Word_FontTable) {
        $this->xml_Word_FontTable = $xml_Word_FontTable;
    }

    public function getXml_Word_FontTable() {
        return $this->xml_Word_FontTable;
    }

    public function setXml_Word_Footer1($xml_Word_Footer1) {
        $this->xml_Word_Footer1 = $xml_Word_Footer1;
    }

    public function getXml_Word_Footer1() {
        return $this->xml_Word_Footer1;
    }

    public function setXml_Word_Header1($xml_Word_Header1) {
        $this->xml_Word_Header1 = $xml_Word_Header1;
    }

    public function getXml_Word_Header1() {
        return $this->xml_Word_Header1;
    }

    public function setXml_Word_Rels_DocumentRels($xml_Word_Rels_DocumentRels) {
        $this->xml_Word_Rels_DocumentRels = $xml_Word_Rels_DocumentRels;
    }

    public function getXml_Word_Rels_DocumentRels() {
        return $this->xml_Word_Rels_DocumentRels;
    }

    public function setXml_Word_Settings($xml_Word_Settings) {
        $this->xml_Word_Settings = $xml_Word_Settings;
    }

    public function getXml_Word_Settings() {
        return $this->xml_Word_Settings;
    }

    public function setXml_Word_Styles($xml_Word_Styles) {
        $this->xml_Word_Styles = $xml_Word_Styles;
    }

    public function getXml_Word_Styles() {
        return $this->xml_Word_Styles;
    }

    public function setXml_Word_Theme_Theme1($xml_Word_Theme_Theme1) {
        $this->xml_Word_Theme_Theme1 = $xml_Word_Theme_Theme1;
    }

    public function getXml_Word_Theme_Theme1() {
        return $this->xml_Word_Theme_Theme1;
    }

    public function setXml_Word_WebSettings($xml_Word_WebSettings) {
        $this->xml_Word_WebSettings = $xml_Word_WebSettings;
    }

    public function getXml_Word_WebSettings() {
        return $this->xml_Word_WebSettings;
    }

    private function fCleanTemplate() {
        $this->xml_Word_Document__Template = preg_replace('/__[A-Z]+__/', '', $this->xml_Word_Document__Template);
    }

    public function fAbsoluteZipPath($strPath) {
        $strPath = str_replace(array('/', '\\'), DIRECTORY_SEPARATOR, $strPath);
        $arrParts = array_filter(explode(DIRECTORY_SEPARATOR, $strPath), 'strlen');
        $arrAbsolutes = array();
        foreach ($arrParts as $arrDatParts) {
            if ('.' == $arrDatParts) {
                continue;
            }
            if ('..' == $arrDatParts) {
                array_pop($arrAbsolutes);
            }
            else {
                $arrAbsolutes[] = $arrDatParts;
            }
        }
        return implode('/', $arrAbsolutes);
    }

    private function fGenerateRELATIONSHIP() {
        $arrArgs = func_get_args();
        if ($arrArgs[1] == 'vbaProject')
            $strType = 'http://schemas.microsoft.com/office/2006/relationships/vbaProject';
        else
            $strType = 'http://schemas.openxmlformats.org/officeDocument/2006/relationships/' . $arrArgs[1];

        return '<Relationship Id="' . $arrArgs[0] . '" Type="' . $strType . '" Target="' . $arrArgs[2] . '"></Relationship>';
    }

    protected function fGenerateSECTPR($arrArgs='') {
        $objPage = cCreatePage::getInstance();
        $objPage->fCreateSECTPR($arrArgs);
        $this->xml_Word_Document__Content .= (string) $objPage;
    }

    private function fGenerateContentType() {
        $this->fGenerateDEFAULT('rels', 'application/vnd.openxmlformats-package.relationships+xml');
        $this->fGenerateDEFAULT('xml', 'application/xml');
        $this->fGenerateOVERRIDE('/word/numbering.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.numbering+xml');
        $this->fGenerateOVERRIDE('/word/styles.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.styles+xml');
        $this->fGenerateOVERRIDE('/docProps/app.xml', 'application/vnd.openxmlformats-officedocument.extended-properties+xml');
        $this->fGenerateOVERRIDE('/word/settings.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.settings+xml');
        $this->fGenerateOVERRIDE('/word/theme/theme1.xml', 'application/vnd.openxmlformats-officedocument.theme+xml');
        $this->fGenerateOVERRIDE('/word/fontTable.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.fontTable+xml');
        $this->fGenerateOVERRIDE('/word/webSettings.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.webSettings+xml');
        if ($this->xml_Word_Footer__Content != '' || $this->xml_Word_Header__Content != '') {
            $this->fGenerateOVERRIDE('/word/header.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.header+xml');
            $this->fGenerateOVERRIDE('/word/footer.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.footer+xml');
            $this->fGenerateOVERRIDE('/word/footnotes.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.footnotes+xml');
            $this->fGenerateOVERRIDE('/word/endnotes.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.endnotes+xml');
        }
        $this->fGenerateOVERRIDE('/docProps/core.xml', 'application/vnd.openxmlformats-package.core-properties+xml');
    }

    private function fGenerateTemplate_DocProps_App() {
        $this->xml_DocProps_App__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <Properties xmlns="http://schemas.openxmlformats.org/officeDocument/2006/extended-properties" xmlns:vt="http://schemas.openxmlformats.org/officeDocument/2006/docPropsVTypes"><Template>Normal.dotm</Template><TotalTime>0</TotalTime><Pages>1</Pages><Words>1</Words><Characters>1</Characters><Application>Microsoft Office Word</Application><DocSecurity>4</DocSecurity><Lines>1</Lines><Paragraphs>1</Paragraphs><ScaleCrop>false</ScaleCrop><Company>Company</Company><LinksUpToDate>false</LinksUpToDate><CharactersWithSpaces>1</CharactersWithSpaces><SharedDoc>false</SharedDoc><HyperlinksChanged>false</HyperlinksChanged><AppVersion>12.0000</AppVersion></Properties>';
    }

    private function fGenerateTemplate_DocProps_Core() {
        $this->xml_DocProps_Core__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <cp:coreProperties xmlns:cp="http://schemas.openxmlformats.org/package/2006/metadata/core-properties" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:dcterms="http://purl.org/dc/terms/" xmlns:dcmitype="http://purl.org/dc/dcmitype/" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"><dc:title>Title</dc:title><dc:subject>Subject</dc:subject><dc:creator>2mdc</dc:creator><dc:description>Description</dc:description><cp:lastModifiedBy>user</cp:lastModifiedBy><cp:revision>1</cp:revision><dcterms:created xsi:type="dcterms:W3CDTF">' . date('c') . '</dcterms:created><dcterms:modified xsi:type="dcterms:W3CDTF">' . date('c') . '</dcterms:modified></cp:coreProperties>';
    }

    private function fGenerateTemplate_Rels_Rels() {
        $this->xml_Rels_Rels__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">' .
                $this->fGenerateRELATIONSHIP('rId3', 'extended-properties', 'docProps/app.xml') .
                '<Relationship Id="rId2" Type="http://schemas.openxmlformats.org/package/2006/relationships/metadata/core-properties" Target="docProps/core.xml"/>' .
                $this->fGenerateRELATIONSHIP('rId1', 'officeDocument', 'word/document.xml') .
                '</Relationships>';
    }

    private function fGenerateTemplate_Word_Document() {
        $arrArgs = func_get_args();
        $this->fGenerateSECTPR($arrArgs[0]);
        if (!empty($this->xml_Word_Header__Content)) {
            $this->xml_Word_Document__Content = str_replace('__GENERATEHEADERREFERENCE__', '<' . cCreateDocx::NAMESPACEWORD . ':headerReference ' . cCreateDocx::NAMESPACEWORD . ':type="default" r:id="rId' . $this->arrIdWords['header'] . '"></' . cCreateDocx::NAMESPACEWORD . ':headerReference>', $this->xml_Word_Document__Content);
        }
        if (!empty($this->xml_Word_Footer__Content)) {
            $this->xml_Word_Document__Content = str_replace('__GENERATEFOOTERREFERENCE__', '<' . cCreateDocx::NAMESPACEWORD . ':footerReference ' . cCreateDocx::NAMESPACEWORD . ':type="default" r:id="rId' . $this->arrIdWords['footer'] . '"></' . cCreateDocx::NAMESPACEWORD . ':footerReference>', $this->xml_Word_Document__Content);
        }
        $this->xml_Word_Document__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' .
                '<' . cCreateDocx::NAMESPACEWORD . ':wordDocument xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office"' .
                ' xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml"' .
                ' xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word"' .
                ' xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml">' .
                '<' . cCreateDocx::NAMESPACEWORD . ':body>' .
                $this->xml_Word_Document__Content .
                '</' . cCreateDocx::NAMESPACEWORD . ':body>' .
                '</' . cCreateDocx::NAMESPACEWORD . ':wordDocument>';
        $this->fCleanTemplate();
    }

    private function fGenerateTemplate_Word_Endnotes() {
        $this->xml_Word_Endnotes__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <' . cCreateDocx::NAMESPACEWORD . ':endnotes xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml">' .
                $this->xml_Word_Endnotes__Content .
                '</' . cCreateDocx::NAMESPACEWORD . ':endnotes>';
        $this->intIdWord++;
        $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'endnotes', 'endnotes.xml');
        $this->fGenerateOVERRIDE('/word/endnotes.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.endnotes+xml');
    }

    private function fGenerateTemplate_Word_FontTable() {
        $this->xml_Word_FontTable__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>' .
                '<' . cCreateDocx::NAMESPACEWORD . ':fonts xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main">' .
                $this->xml_Word_FontTable__Content .
                '</' . cCreateDocx::NAMESPACEWORD . ':fonts>';
    }

    private function fGenerateTemplate_Word_Footer() {
        $this->intIdWord++;
        $this->arrIdWords['footer'] = $this->intIdWord;
        $this->xml_Word_Footer__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <' . cCreateDocx::NAMESPACEWORD . ':ftr xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml">' .
                $this->xml_Word_Footer__Content .
                '</' . cCreateDocx::NAMESPACEWORD . ':ftr>';
        $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'footer', 'footer.xml');
    }

    private function fGenerateTemplate_Word_Footnotes() {
        $this->xml_Word_Footnotes__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <' . cCreateDocx::NAMESPACEWORD . ':footnotes xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml">' .
                $this->xml_Word_Footnotes__Content .
                '</' . cCreateDocx::NAMESPACEWORD . ':footnotes>';
        $this->intIdWord++;
        $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'footnotes', 'footnotes.xml');
        $this->fGenerateOVERRIDE('/word/footnotes.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.footnotes+xml');
    }

    private function fGenerateTemplate_Word_Header() {
        $this->intIdWord++;
        $this->arrIdWords['header'] = $this->intIdWord;
        $this->xml_Word_Header__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <' . cCreateDocx::NAMESPACEWORD . ':hdr xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml"> ' .
                $this->xml_Word_Header__Content .
                '</' . cCreateDocx::NAMESPACEWORD . ':hdr>';
        $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'header', 'header.xml');
    }

    private function fGenerateTemplate_Word_Numbering() {
        $this->xml_Word_Numbering__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
        <w:numbering xmlns:ve="http://schemas.openxmlformats.org/markup-compatibility/2006" xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:m="http://schemas.openxmlformats.org/officeDocument/2006/math" xmlns:v="urn:schemas-microsoft-com:vml" xmlns:wp="http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing" xmlns:w10="urn:schemas-microsoft-com:office:word" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main" xmlns:wne="http://schemas.microsoft.com/office/word/2006/wordml"><w:abstractNum w:abstractNumId="0"><w:nsid w:val="713727AE"/><w:multiLevelType w:val="hybridMultilevel"/><w:tmpl w:val="F0B4B6B8"/><w:lvl w:ilvl="0" w:tplc="0C0A0001"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="720" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Symbol" w:hAnsi="Symbol" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="1" w:tplc="0C0A0003" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val="o"/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="1440" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Courier New" w:hAnsi="Courier New" w:cs="Courier New" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="2" w:tplc="0C0A0005" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="2160" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Wingdings" w:hAnsi="Wingdings" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="3" w:tplc="0C0A0001" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="2880" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Symbol" w:hAnsi="Symbol" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="4" w:tplc="0C0A0003" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val="o"/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="3600" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Courier New" w:hAnsi="Courier New" w:cs="Courier New" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="5" w:tplc="0C0A0005" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="4320" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Wingdings" w:hAnsi="Wingdings" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="6" w:tplc="0C0A0001" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="5040" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Symbol" w:hAnsi="Symbol" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="7" w:tplc="0C0A0003" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val="o"/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="5760" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Courier New" w:hAnsi="Courier New" w:cs="Courier New" w:hint="default"/></w:rPr></w:lvl><w:lvl w:ilvl="8" w:tplc="0C0A0005" w:tentative="1"><w:start w:val="1"/><w:numFmt w:val="bullet"/><w:lvlText w:val=""/><w:lvlJc w:val="left"/><w:pPr><w:ind w:left="6480" w:hanging="360"/></w:pPr><w:rPr><w:rFonts w:ascii="Wingdings" w:hAnsi="Wingdings" w:hint="default"/></w:rPr></w:lvl></w:abstractNum><w:num w:numId="1"><w:abstractNumId w:val="0"/></w:num></w:numbering>';
    }

    private function fGenerateTemplate_Word_Rels_DocumentRels() {
        $this->xml_Word_Rels_DocumentRels__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?><Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">' .
                $this->xml_Word_Rels_DocumentRels__Content .
                '</Relationships>';
    }

    private function fGenerateTemplate_Word_Settings() {
        $this->xml_Word_Settings__Template = $this->xml_Word_Settings__Content;
    }

    private function fGenerateTemplate_Word_Styles() {
        $this->xml_Word_Styles__Template =
                '<?xml version="1.0" encoding="UTF-8" standalone="yes"?><' . cCreateDocx::NAMESPACEWORD . ':styles xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main">' .
                $this->xml_Word_Styles__Content .
                '</' . cCreateDocx::NAMESPACEWORD . ':styles>';
    }

    private function fGenerateTemplate_Word_Theme_Theme1() {
        $this->fAddTheme($this->defaultFont);
        $this->xml_Word_Theme_Theme1__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><' . cCreateTheme1::NAMESPACEWORD . ':theme xmlns:a="http://schemas.openxmlformats.org/drawingml/2006/main" name="Tema de Office">' .
                $this->xml_Word_Theme_Theme1__Content .
                '</' . cCreateTheme1::NAMESPACEWORD . ':theme>';
    }

    private function fGenerateTemplate_ContentType() {
        $this->xml_Word_ContentType__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">' .
                $this->xml_ContentType__Content .
                '</Types>';
    }

    private function fGenerateTemplate_Word_Rels_HeaderRels() {
        $this->xml_Word_Rels_HeaderRels__Template = '<?xml version="1.0" encoding="UTF-8" standalone="yes"?><Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">' . $this->xml_Word_Rels_HeaderRels__Content . '</Relationships>';
    }

    private function fGenerateTemplate_Word_WebSettings() {
        $this->xml_Word_WebSettings__Template = $this->xml_Word_WebSettings__Content;
    }

    private function fGenerateDefaultFonts() {
        $arrFont = array('name' => 'Calibri', 'pitch' => 'variable', 'usb0' => 'A00002EF', 'usb1' => '4000207B', 'usb2' => '00000000', 'usb3' => '00000000', 'csb0' => '0000009F', 'csb1' => '00000000', 'family' => 'swiss', 'charset' => '00', 'panose1' => '020F0502020204030204');
        $this->fAddFont($arrFont);
        $arrFont = array('name' => 'Times New Roman', 'pitch' => 'variable', 'usb0' => 'E0002AEF', 'usb1' => 'C0007841', 'usb2' => '00000009', 'usb3' => '00000000', 'csb0' => '000001FF', 'csb1' => '00000000', 'family' => 'roman', 'charset' => '00', 'panose1' => '02020603050405020304');
        $this->fAddFont($arrFont);
        $arrFont = array('name' => 'Cambria', 'pitch' => 'variable', 'usb0' => 'A00002EF', 'usb1' => '4000004B', 'usb2' => '00000000', 'usb3' => '00000000', 'csb0' => '0000009F', 'csb1' => '00000000', 'family' => 'roman', 'charset' => '00', 'panose1' => '02040503050406030204');
        $this->fAddFont($arrFont);
    }

    private function fGenerateOVERRIDE($PartName, $ContentType) {
        if (strpos($this->xml_ContentType__Content, 'PartName="' . $PartName . '"') === false) {
            $this->xml_ContentType__Content .= '<Override PartName="' . $PartName . '" ContentType="' . $ContentType . '"> </Override>';
        }
    }

    private function fGenerateDEFAULT($Extension, $ContentType) {
        if (strpos($this->xml_ContentType__Content, 'Extension="' . $Extension) === false) {
            $this->xml_ContentType__Content .= '<Default Extension="' . $Extension . '" ContentType="' . $ContentType . '"> </Default>';
        }
    }

    private function fGenerateDefault_Word_Rels() {
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

    private function parsePath($strDir) {
        $barra = 0;
        $path = '';
        if (($barra = strrpos($strDir, '/')) !== false) {
            $barra += 1;
            $path = substr($strDir, 0, $barra);
        }
        if (($punto = strpos(substr($strDir, $barra), '.')) === false) {
            exit("Error $strDir");
        }

        $nombre = substr($strDir, $barra, $punto);
        $extension = substr($strDir, $punto + $barra + 1);
        return array('path' => $path, 'nombre' => $nombre, 'extension' => $extension);
    }

    public function fCreateDocx() {
        $arrArgs = func_get_args();
        if (!empty($arrArgs[0]))
            $strFileName = $arrArgs[0];
        else
            $strFileName = 'document';
        try {
            $this->fGenerateTemplate_Rels_Rels();
            $this->objZipDocx->addFromString('_rels/.rels', $this->xml_Rels_Rels__Template);
            $this->fGenerateTemplate_DocProps_App();
            $this->objZipDocx->addFromString('docProps/app.xml', $this->xml_DocProps_App__Template);
            $this->fGenerateTemplate_DocProps_Core();
            $this->objZipDocx->addFromString('docProps/core.xml', $this->xml_DocProps_Core__Template);

            $this->fAddStyle();
            $this->fGenerateTemplate_Word_Styles();
            $this->objZipDocx->addFromString('word/styles.xml', $this->xml_Word_Styles__Template);

            $this->fAddSettings();
            $this->fGenerateTemplate_Word_Settings();
            $this->objZipDocx->addFromString('word/settings.xml', $this->xml_Word_Settings__Template);

            $this->fAddWebSettings();
            $this->fGenerateTemplate_Word_WebSettings();
            $this->objZipDocx->addFromString('word/webSettings.xml', $this->xml_Word_WebSettings__Template);

            if (empty($this->xml_Word_Footer__Content)) {
                $arrParamsFooter = array(
                    'pagerAlignment' => 'right',
                    'font' => 'Times New Roman'
                );
                $this->fAddFooter('', $arrParamsFooter);
            }
            $this->fGenerateTemplate_Word_Footer();
            $this->objZipDocx->addFromString('word/footer.xml', $this->xml_Word_Footer__Template);

            if (!empty($this->xml_Word_Header__Content)) {
                $this->fGenerateTemplate_Word_Header();
                $this->objZipDocx->addFromString('word/header.xml', $this->xml_Word_Header__Template);
            }

            if (!empty($this->xml_Word_Rels_HeaderRels__Content)) {
                $this->fGenerateTemplate_Word_Rels_HeaderRels();
                $this->objZipDocx->addFromString('word/_rels/header.xml.rels', $this->xml_Word_Rels_HeaderRels__Template);
            }
            $this->fGenerateOVERRIDE('/word/document.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml');
            $this->fGenerateTemplate_ContentType();


            $this->objZipDocx->addFromString('[Content_Types].xml', $this->xml_Word_ContentType__Template);

            $this->fGenerateTemplate_Word_Numbering();
            $this->objZipDocx->addFromString('word/numbering.xml', $this->xml_Word_Numbering__Template);

            $this->fGenerateDefault_Word_Rels();
            if (!empty($this->xml_Word_Rels_DocumentRels__Content)) {
                $this->fGenerateTemplate_Word_Rels_DocumentRels();
                $this->objZipDocx->addFromString('word/_rels/document.xml.rels', $this->xml_Word_Rels_DocumentRels__Template);
            }
            $arrArgsPage = array();
            if (isset($arrArgs[1])) {
                $arrArgsPage = $arrArgs[1];
            }
            $this->fGenerateTemplate_Word_Document($arrArgsPage);
            $this->objZipDocx->addFromString('word/document.xml', $this->xml_Word_Document__Template);

            $this->fGenerateDefaultFonts();
            $this->fGenerateTemplate_Word_FontTable();
            $this->objZipDocx->addFromString('word/fontTable.xml', $this->xml_Word_FontTable__Template);

            $this->fGenerateTemplate_Word_Theme_Theme1();
            $this->objZipDocx->addFromString('word/theme/theme1.xml', $this->xml_Word_Theme_Theme1__Template);

            $this->objZipDocx->close();

            $arrpathFile = pathinfo($strFileName);
            rename('document.docx', $strFileName . '.docx');
        }
        catch (Exception $e) {
            echo 'There was an error related to DOCX file: ', $e->getMessage(), "\n";
        }
    }

    public function fAddFont($arrFont) {
        $objFont = cCreateFontTable::getInstance();
        $objFont->fCreateFont($arrFont);
        $this->xml_Word_FontTable__Content .= (string) $objFont;
    }

    public function fAddFooter($strDat = '', $arrParamsFooter = '') {
        $objFooter = cCreateFooter::getInstance();
        $strDat .= ' This document was created with free version of PHPdocx. Upgrade to Pro version.';
        $objFooter->fCreateFooter($strDat, $arrParamsFooter);
        $this->xml_Word_Footer__Content .= (string) $objFooter;
        $this->fGenerateOVERRIDE('/word/footer.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.footer+xml');
    }

    public function fAddHeader($strDat = 'Cabecera', $arrParamsHeader = '') {
        $objHeader = cCreateHeader::getInstance();
        $objHeader->fCreateHeader($strDat, $arrParamsHeader);
        $this->xml_Word_Header__Content .= (string) $objHeader;
        $this->fGenerateOVERRIDE('/word/header.xml', 'application/vnd.openxmlformats-officedocument.wordprocessingml.header+xml');
    }

    public function fAddImage($arrDat='') {
        if (isset($arrDat['name']) && file_exists($arrDat['name']) == 'true') {
            $arrAtributos = getimagesize($arrDat['name']);
            if ($arrAtributos['mime'] == 'image/jpg' || $arrAtributos['mime'] == 'image/jpeg' || $arrAtributos['mime'] == 'image/png' || $arrAtributos['mime'] == 'image/gif') {
                $this->intIdWord++;
                $objImg = cCreateImage::getInstance();
                $arrDat['rId'] = $this->intIdWord;
                $objImg->fCreateImage($arrDat);
                $this->xml_Word_Document__Content .= (string) $objImg;
                $arrDir = $this->parsePath($arrDat['name']);
                $this->objZipDocx->addFile($arrDat['name'], 'word/media/image' . $this->intIdWord . '.' . $arrDir['extension']);
                $this->fGenerateDEFAULT($arrDir['extension'], $arrAtributos['mime']);
                if ((string) $objImg != '')
                    $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'image', 'media/image' . $this->intIdWord . '.' . $arrDir['extension']);
            }else {
                echo ('The image format is not supported');
                return false;
            }
        }
        else {
            echo ("The image doesn`t exist");
            return false;
        }
    }

    public function fAddGraphic($arrDatos) {
        if (isset($arrDatos['data']) && isset($arrDatos['type'])) {
            $this->intIdWord++;
            $objGraphic = cCreateGraphic::getInstance();
            if ($objGraphic->fCreateGraphic($this->intIdWord, $arrDatos) != false) {
                $this->objZipDocx->addFromString('word/charts/chart' . $this->intIdWord . '.xml', $objGraphic->getXmlChart());
                $this->xml_Word_Rels_DocumentRels__Content .= $this->fGenerateRELATIONSHIP("rId$this->intIdWord", 'chart', 'charts/chart' . $this->intIdWord . '.xml');
                $this->xml_Word_Document__Content .= (string) $objGraphic;
                $this->fGenerateDEFAULT('xlsx', 'application/octet-stream');
                $this->fGenerateOVERRIDE('/word/charts/chart' . $this->intIdWord . '.xml', 'application/vnd.openxmlformats-officedocument.drawingml.chart+xml');
            }
            else {
                echo ("There was an error related to the chart");
                return false;
            }
            $objExcel = cCreateXlsx::getInstance();
            if ($objExcel->fCreateXlsx('datos' . $this->intIdWord, $arrDatos['data'], $arrDatos['type']) != false) {
                $this->objZipDocx->addFile('datos' . $this->intIdWord . '.xlsx', 'word/embeddings/datos' . $this->intIdWord . '.xlsx');
                @unlink('datos' . $this->intIdWord . '.xlsx');

                $objChartRels = cCreateChartRels::getInstance();
                $objChartRels->fCreateRelationship($this->intIdWord);
                $this->objZipDocx->addFromString('word/charts/_rels/chart' . $this->intIdWord . '.xml.rels', (string) $objChartRels);
            }
            else {
                echo ("There was an error related to the chart");
                return false;
            }
        }
        else {
            echo ("There was an error related to the chart");
            return false;
        }
    }

    public function fAddLink($strText = '', $strLink = '', $strFont = '') {
        $objLink = cCreateLink::getInstance();
        $objLink->fCreateLink($strText, $strLink, $strFont);
        $this->xml_Word_Document__Content .= (string) $objLink;
    }

    public function fAddList($arrDat, $arrParamsList = '') {
        $objList = cCreateList::getInstance();
        $objList->fCreateList($arrDat, $arrParamsList);
        $this->xml_Word_Document__Content .= (string) $objList;
    }

    public function fAddMathDocx($strPath) {
        $rscPackage = new ZipArchive();
        $rscPackage->open($strPath);
        $strDocument = $rscPackage->getFromName('word/document.xml');
        $arrEqs = preg_split('/<[\/]*m:oMathPara>/', $strDocument);
        $this->fAddMathEq('<m:oMathPara>' . $arrEqs[1] . '</m:oMathPara>');
    }

    public function fAddMathEq($strDat) {
        $this->xml_Word_Document__Content .= '<' . cCreateDocx::NAMESPACEWORD . ':p>' . (string) $strDat . '</' . cCreateDocx::NAMESPACEWORD . ':p>';
    }

    public function fAddParagraph($strDat, $strStyle = '', $strAlign = '') {
        $objParagraph = cCreateText::getInstance();
        $objParagraph->fCreateParagraph($strDat, $strStyle, $strAlign);
        $this->xml_Word_Document__Content .= (string) $objParagraph;
    }

    public function fAddTable($arrDat, $arrParamsTable = '') {
        $objTable = cCreateTable::getInstance();
        $objTable->fCreateTable($arrDat, $arrParamsTable);
        $this->xml_Word_Document__Content .= (string) $objTable;
    }

    public function fAddText($strDat, $strStyle = '') {
        $objText = cCreateText::getInstance();
        $objText->fCreateText($strDat, $strStyle);
        $this->xml_Word_Document__Content .= (string) $objText;
    }

    public function fAddTitle($strDat, $strStyle = '') {
        $objText = cCreateText::getInstance();
        $objText->fCreateTitle($strDat, $strStyle);
        $this->xml_Word_Document__Content .= (string) $objText;
    }

    public function fAddTheme($strFont) {
        $objTheme = cCreateTheme1::getInstance();
        $objTheme->fCreateTheme($strFont);
        $this->xml_Word_Theme_Theme1__Content .= (string) $objTheme;
    }

    public function fAddSettings() {
        $objSettings = cCreateSettings::getInstance();
        $objSettings->fGenerateSettings();
        $this->xml_Word_Settings__Content .= (string) $objSettings;
    }

    public function fAddStyle() {
        $objStyle = cCreateStyle::getInstance();
        $objStyle->fCreateStyle();
        $this->xml_Word_Styles__Content .= (string) $objStyle;
    }

    public function fAddWebSettings() {
        $objWebSettings = cCreateWebSettings::getInstance();
        $objWebSettings->fGenerateWebSettings();
        $this->xml_Word_WebSettings__Content .= (string) $objWebSettings;
    }

    public function fAddBreak($strType='') {
        $objPage = cCreatePage::getInstance();
        $objPage->fGeneratePageBreak($strType);
        $this->xml_Word_Document__Content .= (string) $objPage;
    }

    public function fSetDefaultFont($strFont) {
        $this->defaultFont = $strFont;
    }

}
?>