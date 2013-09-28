<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateImage extends cCreateElement {
    const NAMESPACEWORD = 'wp';
    const NAMESPACEWORD1 = 'a';
    const NAMESPACEWORD2 = 'pic';
    const CONSTWORD = 360000;
    const TAMBORDER = 12700;
    static private $rscInstance = NULL;
    private $name;
    private $rId;

    public function __construct() {
        $this->name = '';
        $this->rId = '';
    }

    public function __destruct() {

    }

    public function __toString() {
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateImage();
        }
        return self::$rscInstance;
    }

    public function setName($name) {
        $this->name = $name;
    }

    public function getName() {
        return $this->name;
    }

    public function setRId($rId) {
        $this->rId = $rId;
    }

    public function getRId() {
        return $this->rId;
    }

    public function fCreateImage() {
        $this->xml = '';
        $this->name = '';
        $this->rId = '';
        $arrArgs = func_get_args();
        if (!empty($arrArgs[0]['rId']) && (!empty($arrArgs[0]['name']))) {
            $arr = array();
            $arrAtributos = getimagesize($arrArgs[0]['name']);
            $intAjusteTexto = 0;
            if (!empty($arrArgs[0]['sizeX']))
                $tamPxX = $arrArgs[0]['sizeX'];
            elseif (!empty($arrArgs[0]['scaling']))
                $tamPxX = $arrAtributos[0] * $arrArgs[0]['scaling'] / 100;
            else
                $tamPxX = $arrAtributos[0];
            if (!empty($arrArgs[0]['scaling']))
                $tamPxY = $arrAtributos[1] * $arrArgs[0]['scaling'] / 100;
            elseif (!empty($arrArgs[0]['sizeY']))
                $tamPxY = $arrArgs[0]['sizeY'];
            else
                $tamPxY = $arrAtributos[1];
            $this->setName($arrArgs[0]['name']);
            $this->setRId($arrArgs[0]['rId']);
            $top = '0';
            $bottom = '0';
            $left = '0';
            $right = '0';

            switch ($arrAtributos['mime']) {
                case 'image/png':
                    list($dpi_x, $dpi_y) = $this->get_dpi_png($arrArgs[0]['name']);
                    $tamWordX = round($tamPxX * 100 / $dpi_x * cCreateImage::CONSTWORD);
                    $tamWordY = round($tamPxY * 100 / $dpi_y * cCreateImage::CONSTWORD);
                    break;
                case 'image/jpg':
                case 'image/jpeg':
                    list($dpi_x, $dpi_y) = $this->get_dpi_jpg($arrArgs[0]['name']);
                    $tamWordX = round($tamPxX * 2.54 / $dpi_x * cCreateImage::CONSTWORD);
                    $tamWordY = round($tamPxY * 2.54 / $dpi_y * cCreateImage::CONSTWORD);
                    break;
                case 'image/gif':
                    $tamWordX = round($tamPxX * 2.54 / 96 * cCreateImage::CONSTWORD);
                    $tamWordY = round($tamPxY * 2.54 / 96 * cCreateImage::CONSTWORD);
                    break;
            }
            $align = '';
            $this->fGenerateP();
            $this->fGenerateR();
            $this->fGenerateRPR();
            $this->fGenerateNOPROOF();
            $this->fGenerateDRAWING();
            $this->fGenerateINLINE();
            $this->fGenerateEXTENT($tamWordX, $tamWordY);
            $this->fGenerateEFFECTEXTENT($left, $top, $right, $bottom);
            $this->fGenerateDOCPR();
            $this->fGenerateCNVGRAPHICFRAMEPR();
            $this->fGenerateGRAPHICPRAMELOCKS(1);
            $this->fGenerateGRAPHIC();
            $this->fGenerateGRAPHICDATA();
            $this->fGeneratePIC();
            $this->fGenerateNVPICPR();
            $this->fGenerateCNVPR();
            $this->fGenerateCNVPICPR();
            $this->fGenerateBLIPFILL();
            $this->fGenerateBLIP();
            $this->fGenerateSTRETCH();
            $this->fGenerateFILLRECT();
            $this->fGenerateSPPR();
            $this->fGenerateXFRM();
            $this->fGenerateOFF();
            $this->fGenerateEXT($tamWordX, $tamWordY);
            $this->fGeneratePRSTGEOM();
            $this->fGenerateAVLST();
            $this->fCleanTemplate();
        }
        else {
            echo 'There was an error adding the image';
        }
    }

    private function get_dpi_jpg($filename) {
        $a = fopen($filename, 'r');
        $string = fread($a, 20);
        fclose($a);
        $data = bin2hex(substr($string, 14, 4));
        $x = substr($data, 0, 4);
        $y = substr($data, 4, 4);
        return array(hexdec($x), hexdec($y));
    }

    private function get_dpi_png($filename) {
        $a = fopen($filename, 'r');
        $string = fread($a, 1000);
        $aux = strpos($string, 'pHYs');
        $data = bin2hex(substr($string, $aux + strlen('pHYs'), 16));
        fclose($a);
        $x = substr($data, 0, 8);
        $y = substr($data, 8, 8);
        return array(hexdec($x), hexdec($y));
    }

}
?>