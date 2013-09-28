<?php

/**
 * @author 2mdc.com
 */
require_once dirname(__FILE__) . '/../pdf/dompdf_config.inc.php';

class cTransformDoc {
    const SCHEMA_IMAGEDOCUMENT = 'http://schemas.openxmlformats.org/officeDocument/2006/relationships/image';
    const SCHEMA_OFFICEDOCUMENT = 'http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument';

    private $strXHTML;

    public function __construct() {
        
    }

    public function __destruct() {
        
    }

    public function __toString() {
        
    }

    public function getStrFile() {
        return $this->StrFile;
    }

    public function getStrXHTML() {
        return $this->strXHTML;
    }

    public function getStrOutputFile() {
        return $this->strOutputFile;
    }

    public function setStrFile($strFile) {
        $this->StrFile = $strFile;
    }

    public function setStrXHTML($strXHTML) {
        $this->strXHTML = $strXHTML;
    }

    public function setStrOutputFile($strOutputFile) {
        $this->StrOutputFile = $strOutputFile;
    }

    public function fValidatorXHTML() {
        ob_start();
        echo $this->strXHTML;
        $html = ob_get_clean();
        $config = array(
            'indent' => true,
            'output-xhtml' => true,
            'wrap' => 200);
        $tidy = new tidy;
        $tidy->parseString($html, $config, 'utf8');
        $tidy->cleanRepair();
        $this->strXHTML = $tidy;
    }

    public function fCleanXHTML() {
        $strSeccion1 = explode('<head>', $this->strXHTML);
        $strSeccion2 = explode('</head>', $this->strXHTML);
        $this->strXHTML = $strSeccion1[0] . '<head><meta http-equiv="Content-Type" content="text/html; charset=utf-8" /></head>' . $strSeccion2[1];
    }

    public function fAbsoluteZipPath($strPath) {
        $strPath = str_replace(array('/', '\\'), DIRECTORY_SEPARATOR, $strPath);
        $arrParts = array_filter(explode(DIRECTORY_SEPARATOR, $strPath), 'strlen');
        $arrAbsolutes = array();
        foreach ($arrParts as $arrDatParts) {
            if ('.' == $arrDatParts)
                continue;
            if ('..' == $arrDatParts) {
                array_pop($arrAbsolutes);
            }
            else {
                $arrAbsolutes[] = $arrDatParts;
            }
        }
        return implode('/', $arrAbsolutes);
    }

    public function fGetFileName() {
        try {
            $arrPartsFile = explode('/', $this->StrFile);
            $arrDivideFile = explode('.', array_pop($arrPartsFile));
            $strFileName = array_shift($arrDivideFile);
        }
        catch (Exception $e) {
            $strFileName = 'file';
        }
        return $strFileName;
    }

    public function fGenerateXHTML() {
        $rscPackage = new ZipArchive();
        $rscPackage->open($this->StrFile);
        $rscRelations = simplexml_load_string($rscPackage->getFromName('_rels/.rels'));

        foreach ($rscRelations->Relationship as $rel) {
            if ($rel["Type"] == cTransformDoc::SCHEMA_OFFICEDOCUMENT) {
                $strXML = $rscPackage->getFromName(
                                $this->fAbsoluteZipPath(dirname($rel['Target'])
                                        . '/'
                                        . basename($rel['Target']))
                );

                $rscXML = new DOMDocument();
                $rscXML->loadXML($strXML);

                $objXSLTProc = new XSLTProcessor();
                $objXSL = new DOMDocument();
                $objXSL->load(dirname(__FILE__) . '/../xsl/docx2html.xsl');
                $objXSLTProc->importStylesheet($objXSL);

                $this->strXHTML = $objXSLTProc->transformToXML($rscXML);
            }
        }

        $strPattern = "'src\s*=\s*([\"\'])?(?(1) (.*?)\\1 | ([^\s\>]+))'isx";
        preg_match_all($strPattern, $this->strXHTML, $arrDomImgs);

        $arrIdImgs = array();
        foreach ($arrDomImgs[0] as $arrDats) {
            $arrDatsFiltered = explode('"', $arrDats);
            if (preg_match('/^\?image=rId/', $arrDatsFiltered[1])) {
                $arrDatFiltered = explode('?image=', $arrDats);
                $arrIdImgs[] = substr($arrDatFiltered[1], 0, -1);
            }
        }
        $rscRelationsImgs = simplexml_load_string($rscPackage->getFromName('word/_rels/document.xml.rels'));
        $arrPathImgs = array();
        foreach ($rscRelationsImgs->Relationship as $relImg) {
            if ($relImg["Type"] == cTransformDoc::SCHEMA_IMAGEDOCUMENT) {
                $arrPathImgs[(string) $relImg["Id"]] = (string) $relImg["Target"];
                $arrPathZip[] = 'word/' . (string) $relImg["Target"];
            }
        }

        foreach ($arrIdImgs as $arrDatsIdImgs) {
            $this->strXHTML = str_replace("src=\"?image=$arrDatsIdImgs\"", "src=\"files/files_$this->StrFile/media/word/$arrPathImgs[$arrDatsIdImgs]\"", $this->strXHTML);
        }

        if (!empty($arrPathZip)) {
            $rscPackage->extractTo("files/files_$this->StrFile/media", $arrPathZip);
            $rscPackage->close();
        }
    }

    public function fGeneratePDF() {
        $this->fGenerateXHTML();
        $this->fValidatorXHTML();
        $this->fCleanXHTML();
        try {
            $domPDF = new DOMPDF();
            $domPDF->load_html($this->strXHTML);
            $domPDF->render();
            $strFileName = $this->fGetFileName() . '.pdf';
            $domPDF->stream($strFileName);
        }
        catch (Exception $err) {
            echo 'Unable to generate the file';
        }
    }

}
?>