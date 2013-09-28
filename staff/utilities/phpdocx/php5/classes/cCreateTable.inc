<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateTable extends cCreateElement {

    static private $rscInstance = NULL;

    public function __construct() {

    }

    public function __destruct() {

    }

    public function __toString() {
        $this->fCleanTemplate();
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateTable();
        }
        return self::$rscInstance;
    }

    private function fCleanTemplateR() {
        $this->xml = preg_replace('/__GENERATETR__/', '', $this->xml);
    }

    protected function fAddList($strList) {
        $this->xml = str_replace('__GENERATEP__', $strList, $this->xml);
    }

    protected function fGenerateGRIDCOLS($w) {
        $this->xml = str_replace('__GENERATEGRIDCOLS__', '<' . cCreateElement::NAMESPACEWORD . ':tblGrid ' . cCreateElement::NAMESPACEWORD . ':w="' . $w . '"></' . cCreateElement::NAMESPACEWORD . ':tblGrid>__GENERATEGRIDCOLS__', $this->xml);
    }

    protected function fGenerateHMERGE($val = '') {

    }

    protected function fGenerateJC($strVal = '') {
        $this->xml = str_replace('__GENERATEJC__', '<' . cCreateElement::NAMESPACEWORD . ':jc ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':jc>', $this->xml);
    }

    protected function fGenerateP() {
        $this->xml = str_replace('__GENERATETC__', '<' . cCreateElement::NAMESPACEWORD . ':p >__GENERATEP__</' . cCreateElement::NAMESPACEWORD . ':p>', $this->xml);
    }

    protected function fGenerateSHD($val="horz-cross", $color="ffff00", $fill="", $bgcolor="") {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':shd val="' . $val . '"';
        if ($color != '')
            $xmlAux .= ' color="' . $color . '"';
        if ($fill != '')
            $xmlAux .= ' fill="' . $fill . '"';
        if ($bgcolor != '')
            $xmlAux .= ' wx:bgcolor="' . $bgcolor . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':shd>';
        $this->xml = str_replace('__GENERATESHD__', $xmlAux, $this->xml);
    }

    protected function fGenerateTBLBORDERS() {
        $this->xml = str_replace('__GENERATETBLBORDERS__', '<' . cCreateElement::NAMESPACEWORD . ':tblBorders>__GENERATETBLBORDER__</' . cCreateElement::NAMESPACEWORD . ':tblBorders>', $this->xml);
    }

    protected function fGenerateTBLBOTTOM($val="single", $sz="4", $space='0', $color='auto') {
        $this->xml = str_replace('__GENERATETBLBORDER__', '<' . cCreateElement::NAMESPACEWORD . ':bottom ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '" ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '" ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '" ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"></' . cCreateElement::NAMESPACEWORD . ':bottom>__GENERATETBLBORDER__', $this->xml);
    }

    protected function fGenerateTBL() {
        $this->xml = '<' . cCreateElement::NAMESPACEWORD . ':tbl>__GENERATETBL__</' . cCreateElement::NAMESPACEWORD . ':tbl>';
    }

    protected function fGenerateTBLSTYLE($strVal = 'TableGrid') {
        $this->xml = str_replace('__GENERATETBLSTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':tblStyle ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':tblStyle>', $this->xml);
    }

    protected function fGenerateTBLCELLSPACING($w = '', $type = '') {
        $this->xml = str_replace('__GENERATETBLCELLSPACING__', '<' . cCreateElement::NAMESPACEWORD . ':tblCellSpacing ' . cCreateElement::NAMESPACEWORD . ':w="' . $w . '" ' . cCreateElement::NAMESPACEWORD . ':type="' . $type . '"></' . cCreateElement::NAMESPACEWORD . ':tblCellSpacing>', $this->xml);
    }

    protected function fGenerateTBLGRID() {
        $this->xml = str_replace('__GENERATETBL__', '<' . cCreateElement::NAMESPACEWORD . ':tblGrid>__GENERATEGRIDCOLS__</' . cCreateElement::NAMESPACEWORD . ':tblGrid>__GENERATETBL__', $this->xml);
    }

    protected function fGenerateTBLINSIDEH($val="single", $sz="4", $space='0', $color='auto') {
        $this->xml = str_replace('__GENERATETBLBORDER__', '<' . cCreateElement::NAMESPACEWORD . ':insideH ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '" ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '" ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '" ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"></' . cCreateElement::NAMESPACEWORD . ':insideH>__GENERATETBLBORDER__', $this->xml);
    }

    protected function fGenerateTBLINSIDEV($val="single", $sz="4", $space='0', $color='auto') {
        $this->xml = str_replace('__GENERATETBLBORDER__', '<' . cCreateElement::NAMESPACEWORD . ':insideV ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '" ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '" ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '" ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"></' . cCreateElement::NAMESPACEWORD . ':insideV>__GENERATETBLBORDER__', $this->xml);
    }

    protected function fGenerateTBLLEFT($val="single", $sz="4", $space='0', $color='auto') {
        $this->xml = str_replace('__GENERATETBLBORDER__', '<' . cCreateElement::NAMESPACEWORD . ':left ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '" ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '" ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '" ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"></' . cCreateElement::NAMESPACEWORD . ':left>__GENERATETBLBORDER__', $this->xml);
    }

    protected function fGenerateTBLLOOK($strVal = '000001E0') {
        $this->xml = str_replace('__GENERATETBLLOOK__', '<' . cCreateElement::NAMESPACEWORD . ':tblLook ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':tblLook>', $this->xml);
    }

    protected function fGenerateTBLOVERLAP($strVal = 'never') {
        $this->xml = str_replace('__GENERATETBLOVERLAP__', '<' . cCreateElement::NAMESPACEWORD . ':tblOverlap ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':tblOverlap>', $this->xml);
    }

    protected function fGenerateTBLPR() {
        $this->xml = str_replace('__GENERATETBL__', '<' . cCreateElement::NAMESPACEWORD . ':tblPr>__GENERATETBLSTYLE____GENERATEJC____GENERATETBLW____GENERATETBLLOOK____GENERATETBLOVERLAP____GENERATETBLCELLSPACING____GENERATETBLBORDERS____GENERATESHD__</' . cCreateElement::NAMESPACEWORD . ':tblPr>__GENERATETBL__', $this->xml);
    }

    protected function fGenerateTBLRIGHT($val="single", $sz="4", $space='0', $color='auto') {
        $this->xml = str_replace('__GENERATETBLBORDER__', '<' . cCreateElement::NAMESPACEWORD . ':right ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '" ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '" ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '" ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"></' . cCreateElement::NAMESPACEWORD . ':right>__GENERATETBLBORDER__', $this->xml);
    }

    protected function fGenerateTBLTOP($val="single", $sz="4", $space='0', $color='auto') {
        $this->xml = str_replace('__GENERATETBLBORDER__', '<' . cCreateElement::NAMESPACEWORD . ':top ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '" ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '" ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '" ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"></' . cCreateElement::NAMESPACEWORD . ':top>__GENERATETBLBORDER__', $this->xml);
    }

    protected function fGenerateTBLW($strType = 'auto', $strW = '0') {
        $this->xml = str_replace('__GENERATETBLW__', '<' . cCreateElement::NAMESPACEWORD . ':tblW ' . cCreateElement::NAMESPACEWORD . ':w="' . $strW . '" ' . cCreateElement::NAMESPACEWORD . ':type="' . $strType . '"></' . cCreateElement::NAMESPACEWORD . ':tblW>', $this->xml);
    }

    protected function fGenerateTC() {
        $this->xml = str_replace('__GENERATETR__', '<' . cCreateElement::NAMESPACEWORD . ':tc >__GENERATETC__</' . cCreateElement::NAMESPACEWORD . ':tc>__GENERATETR__', $this->xml);
    }

    protected function fGenerateTCPR() {
        $this->xml = str_replace('__GENERATETC__', '<' . cCreateElement::NAMESPACEWORD . ':tcPr>__GENERATETCPR__</' . cCreateElement::NAMESPACEWORD . ':tcPr>__GENERATETC__', $this->xml);
    }

    protected function fGenerateTCW($w = '', $type = 'dxa') {
        $this->xml = str_replace('__GENERATETCPR__', '<' . cCreateElement::NAMESPACEWORD . ':tcW ' . cCreateElement::NAMESPACEWORD . ':w="' . $w . '" ' . cCreateElement::NAMESPACEWORD . ':type="' . $type . '"></' . cCreateElement::NAMESPACEWORD . ':tcW>', $this->xml);
    }

    protected function fGenerateTR() {
        $this->xml = str_replace('__GENERATETBL__', '<' . cCreateElement::NAMESPACEWORD . ':tr >__GENERATETR__</' . cCreateElement::NAMESPACEWORD . ':tr>__GENERATETBL__', $this->xml);
    }

    protected function fGenerateTRPR() {

    }

    protected function fGenerateVMERGE($val = '') {

    }

    public function fCreateTable() {
        $this->xml = '';
        $arrArgs = func_get_args();

        if (is_array($arrArgs[0])) {
            $this->fGenerateTBL();
            $this->fGenerateTBLPR();
            $this->fGenerateTBLSTYLE();
            $this->fGenerateTBLW();
            if (!empty($arrArgs[1]['border'])) {
                $this->fGenerateTBLBORDERS();
                $this->fGenerateTBLBOTTOM();
                $this->fGenerateTBLLEFT();
                $this->fGenerateTBLTOP();
                $this->fGenerateTBLRIGHT();
                $this->fGenerateTBLINSIDEH();
                $this->fGenerateTBLINSIDEV();
            }
            $this->fGenerateTBLLOOK();
            $this->fGenerateTBLOVERLAP();
            $intLine = 0;
            foreach ($arrArgs[0] as $arrDatDepth) {
                $this->fGenerateTR();
                $intLine++;
                foreach ($arrDatDepth as $unkDat) {
                    $this->fGenerateTC();
                    $this->fGenerateP();
                    $this->fGenerateR();
                    if ($arrArgs[1]['font'] != '') {
                        $this->fGenerateRPR();
                        $this->fGenerateRFONTS($arrArgs[1]['font']);
                    }
                    $this->fGenerateT($unkDat);
                }
                $this->fCleanTemplateR();
            }
        }
    }

}
?>