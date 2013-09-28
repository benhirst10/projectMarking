<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateStyleTable extends cCreateStyle {

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
            self::$rscInstance = new cCreateStyleTable();
        }
        return self::$rscInstance;
    }

    protected function fGenerateTBLSTYLEPR($type) {
        $this->xml .= '<' . cCreateElement::NAMESPACEWORD . ':tblStylePr ' . cCreateElement::NAMESPACEWORD . ':type="' . $type . '">__GENERATESTYLE__</' . cCreateElement::NAMESPACEWORD . ':tblStylePr>';
    }

    protected function fGenerateTBLPR() {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':tblPr></' . cCreateElement::NAMESPACEWORD . ':tblPr>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateTCPR() {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':tcPr>__GENERATETBLPR__</' . cCreateElement::NAMESPACEWORD . ':tcPr>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateTCBORDERS() {
        $this->xml = str_replace('__GENERATETBLPR__', '<' . cCreateElement::NAMESPACEWORD . ':tcBorders>__GENERATETBLBORDERS__</' . cCreateElement::NAMESPACEWORD . ':tcBorders>__GENERATETBLPR__', $this->xml);
    }

    protected function fGenerateSHD($val, $color='', $fill='', $themeFill='', $themeFillTint='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':shd ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        if ($color != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"';
        if ($fill != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':fill="' . $fill . '"';
        if ($themeFill != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeFill="' . $themeFill . '"';
        if ($themeFillTint != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeFillTint="' . $themeFillTint . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':shd>__GENERATETBLPR__';
        $this->xml = str_replace('__GENERATETBLPR__', $xmlAux, $this->xml);
    }

    public function fAddStyleTable() {
        $this->xml = '';
        $arrArgs = func_get_args();
        if (!empty($arrArgs[0]['type'])) {
            $this->fGenerateTBLSTYLEPR($arrArgs[0]['type']);
        }
        if (!empty($arrArgs[0]['name']))
            $this->fGenerateNAME($arrArgs[0]['name']);
        if (!empty($arrArgs[0]['basedOn']))
            $this->fGenerateBASEDON($arrArgs[0]['basedOn']);
        if (!empty($arrArgs[0]['next']))
            $this->fGenerateNEXT($arrArgs[0]['next']);
        if (!empty($arrArgs[0]['link']))
            $this->fGenerateLINK($arrArgs[0]['link']);
        if ($arrArgs[0]['autoRedefine'] == 1)
            $this->fGenerateAUTOREDEFINE();
        if (!empty($arrArgs[0]['uiPriority']))
            $this->fGenerateUIPRIORITY($arrArgs[0]['uiPriority']);
        if ($arrArgs[0]['semiHidden'] == 1)
            $this->fGenerateSEMIHIDDEN();
        if ($arrArgs[0]['unhideWhenUsed'] == 1)
            $this->fGenerateUNHIDEWHENUSED();
        if ($arrArgs[0]['qFormat'] == 1)
            $this->fGenerateQFORMAT();
        if (!empty($arrArgs[0]['rsid']))
            $this->fGenerateRSID($arrArgs[0]['rsid']);
        if ($arrArgs[0]['keepNext'] == 1 || !empty($arrArgs[0]['keepLines']) || (isset($arrArgs[0]['spacing_before']) || isset($arrArgs[0]['spacing_after']) || isset($arrArgs[0]['spacing_line']) ||
                isset($arrArgs[0]['spacing_lineRule'])) || !empty($arrArgs[0]['outlineLvl']) || $arrArgs[0]['contextualSpacing'] == 1 || isset($arrArgs[0]['ilvl']) || isset($arrArgs[0]['ind_left'])) {
            $this->fGeneratePPR();
            if ($arrArgs[0]['keepNext'] == 1)
                $this->fGenerateKEEPNEXT();
            if (!empty($arrArgs[0]['keepLines']))
                $this->fGenerateKEEPLINES($arrArgs[0]['keepLines']);
            if (isset($arrArgs[0]['pBdr_bottom_val']) && isset($arrArgs[0]['pBdr_bottom_sz']) && isset($arrArgs[0]['pBdr_bottom_space']) && isset($arrArgs[0]['pBdr_bottom_color']) && isset($arrArgs[0]['pBdr_bottom_themeColor'])) {
                $this->fGeneratePBDR();
                $this->fGeneratePBDR_BOTTOM($arrArgs[0]['pBdr_bottom_val'], $arrArgs[0]['pBdr_bottom_sz'], $arrArgs[0]['pBdr_bottom_space'], $arrArgs[0]['pBdr_bottom_color'], $arrArgs[0]['pBdr_bottom_themeColor']);
            }
            if (!empty($arrArgs[0]['tab_center']) || $arrArgs[0]['tab_right']) {
                $this->fGenerateTABS();
                if (!empty($arrArgs[0]['tab_center']))
                    $this->fGenerateTABCENTER($arrArgs[0]['tab_center']);
                if (!empty($arrArgs[0]['tab_right']))
                    $this->fGenerateTABRIGHT($arrArgs[0]['tab_right']);
            }
            if (isset($arrArgs[0]['spacing_before']) || isset($arrArgs[0]['spacing_after']) || isset($arrArgs[0]['spacing_line']) || isset($arrArgs[0]['spacing_lineRule']))
                $this->fGenerateSPACING($arrArgs[0]['spacing_before'], $arrArgs[0]['spacing_after'], $arrArgs[0]['spacing_line'], $arrArgs[0]['spacing_lineRule']);
            if (isset($arrArgs[0]['ind_left']))
                $this->fGenerateIND($arrArgs[0]['ind_left']);
            if ($arrArgs[0]['contextualSpacing'] == 1)
                $this->fGenerateCONTEXTUALSPACING();
            if (isset($arrArgs[0]['outlineLvl']))
                $this->fGenerateOUTLINELVL($arrArgs[0]['outlineLvl']);
            if (isset($arrArgs[0]['ilvl'])) {
                $this->fGenerateNUMPR();
                $this->fGenerateILVL($arrArgs[0]['ilvl']);
            }
        }
        if ((!empty($arrArgs[0]['rFonts_asciiTheme']) && !empty($arrArgs[0]['rFonts_eastAsiaTheme']) && !empty($arrArgs[0]['rFonts_hAnsiTheme']) && !empty($arrArgs[0]['rFonts_cstheme'])) || $arrArgs[0]['b'] == 1 ||
                $arrArgs[0]['bCs'] == 1 || $arrArgs[0]['i'] == 1 || $arrArgs[0]['iCs'] == 1 || $arrArgs[0]['u'] == 1 || !empty($arrArgs[0]['color_val']) || !empty($arrArgs[0]['sz']) || !empty($arrArgs[0]['szCs'])
                || !empty($arrArgs[0]['kern']) || !empty($arrArgs[0]['rPr_spacing']) || !empty($arrArgs[0]['u'])) {
            $this->fGenerateRPR();
            if (!empty($arrArgs[0]['rFonts_asciiTheme']) && !empty($arrArgs[0]['rFonts_eastAsiaTheme']) && !empty($arrArgs[0]['rFonts_hAnsiTheme']) && !empty($arrArgs[0]['rFonts_cstheme']))
                $this->fGenerateRFONTS($arrArgs[0]['rFonts_asciiTheme'], $arrArgs[0]['rFonts_eastAsiaTheme'], $arrArgs[0]['rFonts_hAnsiTheme'], $arrArgs[0]['rFonts_cstheme']);
            if (!empty($arrArgs[0]['rFonts_ascii']) && !empty($arrArgs[0]['rFonts_hAnsi']) && !empty($arrArgs[0]['rFonts_cs']))
                $this->fGenerateRFONTS2($arrArgs[0]['rFonts_ascii'], $arrArgs[0]['rFonts_hAnsi'], $arrArgs[0]['rFonts_cs']);
            if ($arrArgs[0]['b'] == 1)
                $this->fGenerateB();
            if ($arrArgs[0]['bCs'] == 1)
                $this->fGenerateBCS();
            if (isset($arrArgs[0]['i']))
                $this->fGenerateI($arrArgs[0]['i']);
            if (isset($arrArgs[0]['iCs']))
                $this->fGenerateICS($arrArgs[0]['iCs']);
            if ($arrArgs[0]['u'] == 1)
                $this->fGenerateU();
            if (!empty($arrArgs[0]['color_val']))
                $this->fGenerateCOLOR($arrArgs[0]['color_val'], $arrArgs[0]['color_themeColor'], $arrArgs[0]['color_themeShade']);
            if (!empty($arrArgs[0]['u']))
                $this->fGenerateU($arrArgs[0]['u']);
            if (!empty($arrArgs[0]['rPr_spacing']))
                $this->fGenerateRPR_SPACING($arrArgs[0]['rPr_spacing']);
            if (!empty($arrArgs[0]['kern']))
                $this->fGenerateKERN($arrArgs[0]['kern']);
            if (!empty($arrArgs[0]['sz']))
                $this->fGenerateSZ($arrArgs[0]['sz']);
            if (!empty($arrArgs[0]['szCs']))
                $this->fGenerateSZCS($arrArgs[0]['szCs']);
        }
        if (isset($arrArgs[0]['tblPr']))
            $this->fGenerateTBLPR();
        if ((isset($arrArgs[0]['top_w']) && isset($arrArgs[0]['top_type'])) || (isset($arrArgs[0]['left_w']) && isset($arrArgs[0]['left_type'])) || (isset($arrArgs[0]['bottom_w']) &&
                isset($arrArgs[0]['bottom_type'])) || (isset($arrArgs[0]['right_w']) && isset($arrArgs[0]['right_type'])) || (isset($arrArgs[0]['tblInd_w']) && isset($arrArgs[0]['tblInd_type'])) &&
                isset($arrArgs[0]['tblborder_top_val']) || isset($arrArgs[0]['tblborder_left_val']) || isset($arrArgs[0]['tblborder_bottom_val']) || isset($arrArgs[0]['tblborder_right_val']) ||
                isset($arrArgs[0]['tblborder_insideH_val']) || isset($arrArgs[0]['tblborder_insideV_val']) || (isset($arrArgs[0]['shd_val']) && isset($arrArgs[0]['shd_color']) &&
                isset($arrArgs[0]['shd_fill']) && isset($arrArgs[0]['shd_themeFill']))) {
            $this->fGenerateTCPR();
            if (isset($arrArgs[0]['tbl_style_row']))
                $this->fGenerateTBLSTYLEROWBANDSIZE($arrArgs[0]['tbl_style_row']);
            if (isset($arrArgs[0]['tbl_style_col']))
                $this->fGenerateTBLSTYLECOLBANDSIZE($arrArgs[0]['tbl_style_col']);

            if (isset($arrArgs[0]['tblInd_w']) && isset($arrArgs[0]['tblInd_type']))
                $this->fGenerateTBLIND($arrArgs[0]['tblInd_w'], $arrArgs[0]['tblInd_type']);
            if (isset($arrArgs[0]['tblborder_top_val']) || isset($arrArgs[0]['tblborder_left_val']) || isset($arrArgs[0]['tblborder_bottom_val']) || isset($arrArgs[0]['tblborder_right_val']) ||
                    isset($arrArgs[0]['tblborder_insideH_val']) || isset($arrArgs[0]['tblborder_insideV_val'])) {
                $this->fGenerateTCBORDERS();
                if (isset($arrArgs[0]['tblborder_top_val']))
                    $this->fGenerateTBLBORDERS_TOP($arrArgs[0]['tblborder_top_val'], $arrArgs[0]['tblborder_top_sz'], $arrArgs[0]['tblborder_top_space'], $arrArgs[0]['tblborder_top_color'], $arrArgs[0]['tblborder_top_themeColor'], $arrArgs[0]['tblborder_insideV_themeTint']);
                if (isset($arrArgs[0]['tblborder_left_val']))
                    $this->fGenerateTBLBORDERS_LEFT($arrArgs[0]['tblborder_left_val'], $arrArgs[0]['tblborder_left_sz'], $arrArgs[0]['tblborder_left_space'], $arrArgs[0]['tblborder_left_color'], $arrArgs[0]['tblborder_left_themeColor'], $arrArgs[0]['tblborder_insideV_themeTint']);
                if (isset($arrArgs[0]['tblborder_bottom_val']))
                    $this->fGenerateTBLBORDERS_BOTTOM($arrArgs[0]['tblborder_bottom_val'], $arrArgs[0]['tblborder_bottom_sz'], $arrArgs[0]['tblborder_bottom_space'], $arrArgs[0]['tblborder_bottom_color'], $arrArgs[0]['tblborder_bottom_themeColor'], $arrArgs[0]['tblborder_insideV_themeTint']);
                if (isset($arrArgs[0]['tblborder_right_val']))
                    $this->fGenerateTBLBORDERS_RIGHT($arrArgs[0]['tblborder_right_val'], $arrArgs[0]['tblborder_right_sz'], $arrArgs[0]['tblborder_right_space'], $arrArgs[0]['tblborder_right_color'], $arrArgs[0]['tblborder_right_themeColor'], $arrArgs[0]['tblborder_insideV_themeTint']);
                if (isset($arrArgs[0]['tblborder_insideH_val']))
                    $this->fGenerateTBLBORDERS_INSIDEH($arrArgs[0]['tblborder_insideH_val'], $arrArgs[0]['tblborder_insideH_sz'], $arrArgs[0]['tblborder_insideH_space'], $arrArgs[0]['tblborder_insideH_color'], $arrArgs[0]['tblborder_insideH_themeColor'], $arrArgs[0]['tblborder_insideV_themeTint']);
                if (isset($arrArgs[0]['tblborder_insideV_val']))
                    $this->fGenerateTBLBORDERS_INSIDEV($arrArgs[0]['tblborder_insideV_val'], $arrArgs[0]['tblborder_insideV_sz'], $arrArgs[0]['tblborder_insideV_space'], $arrArgs[0]['tblborder_insideV_color'], $arrArgs[0]['tblborder_insideV_themeColor'], $arrArgs[0]['tblborder_insideV_themeTint']);
            }
            if (isset($arrArgs[0]['shd_val']) && isset($arrArgs[0]['shd_color']) && isset($arrArgs[0]['shd_fill']) && isset($arrArgs[0]['shd_themeFill'])) {
                $this->fGenerateSHD($arrArgs[0]['shd_val'], $arrArgs[0]['shd_color'], $arrArgs[0]['shd_fill'], $arrArgs[0]['shd_themeFill'], $arrArgs[0]['shd_themeFillTint']);
            }
            if ((isset($arrArgs[0]['top_w']) && isset($arrArgs[0]['top_type'])) || (isset($arrArgs[0]['left_w']) && isset($arrArgs[0]['left_type']))
                    || (isset($arrArgs[0]['bottom_w']) && isset($arrArgs[0]['bottom_type'])) || (isset($arrArgs[0]['right_w']) && isset($arrArgs[0]['right_type']))) {
                $this->fGenerateTBLCELLMAR();
                if (isset($arrArgs[0]['top_w']) && isset($arrArgs[0]['top_type']))
                    $this->fGenerateTOP($arrArgs[0]['top_w'], $arrArgs[0]['top_type']);
                if (isset($arrArgs[0]['left_w']) && isset($arrArgs[0]['left_type']))
                    $this->fGenerateLEFT($arrArgs[0]['left_w'], $arrArgs[0]['left_type']);
                if (isset($arrArgs[0]['bottom_w']) && isset($arrArgs[0]['bottom_type']))
                    $this->fGenerateBOTTOM($arrArgs[0]['bottom_w'], $arrArgs[0]['bottom_type']);
                if (isset($arrArgs[0]['right_w']) && isset($arrArgs[0]['right_type']))
                    $this->fGenerateRIGHT($arrArgs[0]['right_w'], $arrArgs[0]['right_type']);
            }
        }
        $this->fCleanTemplate();
        $this->xml .= '__GENERATESTYLE__';
    }

}
?>