<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateStyle extends cCreateElement {

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
            self::$rscInstance = new cCreateStyle();
        }
        return self::$rscInstance;
    }

    protected function fGenerateSTYLE($type, $styleId, $default = '', $customStyle = '') {
        $this->xml .= '<' . cCreateElement::NAMESPACEWORD . ':style ' . cCreateElement::NAMESPACEWORD . ':type="' . $type . '"';
        if ($default != '')
            $this->xml .= ' ' . cCreateElement::NAMESPACEWORD . ':default="' . $default . '"';
        $this->xml .= ' ' . cCreateElement::NAMESPACEWORD . ':styleId="' . $styleId . '"';
        if ($customStyle != '')
            $this->xml .= ' ' . cCreateElement::NAMESPACEWORD . ':customStyle="' . $customStyle . '"';
        $this->xml .= '>__GENERATESTYLE__</' . cCreateElement::NAMESPACEWORD . ':style>';
    }

    protected function fGenerateNAME($val) {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':name ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':name>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateBASEDON($val) {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':basedOn ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':basedOn>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateNEXT($val) {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':next ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':next>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateLINK($val) {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':link ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':link>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateUIPRIORITY($val) {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':uiPriority ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':uiPriority>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateUNHIDEWHENUSED() {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':unhideWhenUsed></' . cCreateElement::NAMESPACEWORD . ':unhideWhenUsed>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateAUTOREDEFINE() {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':autoRedefine></' . cCreateElement::NAMESPACEWORD . ':autoRedefine>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateQFORMAT() {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':qFormat></' . cCreateElement::NAMESPACEWORD . ':qFormat>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateRSID($val) {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':rsid ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':rsid>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateSEMIHIDDEN() {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':semiHidden></' . cCreateElement::NAMESPACEWORD . ':semiHidden>__GENERATESTYLE__', $this->xml);
    }

    protected function fGeneratePPR() {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':pPr>__GENERATEPPR__</' . cCreateElement::NAMESPACEWORD . ':pPr>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateKEEPNEXT() {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':keepNext></' . cCreateElement::NAMESPACEWORD . ':keepNext>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateTABS() {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':tabs>__GENERATETABS__</' . cCreateElement::NAMESPACEWORD . ':tabs>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateTABCENTER($pos) {
        $this->xml = str_replace('__GENERATETABS__', '<' . cCreateElement::NAMESPACEWORD . ':tab ' . cCreateElement::NAMESPACEWORD . ':val="center" ' . cCreateElement::NAMESPACEWORD . ':pos="' . $pos . '"></' . cCreateElement::NAMESPACEWORD . ':tab>__GENERATETABS__', $this->xml);
    }

    protected function fGenerateTABRIGHT($pos) {
        $this->xml = str_replace('__GENERATETABS__', '<' . cCreateElement::NAMESPACEWORD . ':tab ' . cCreateElement::NAMESPACEWORD . ':val="right" ' . cCreateElement::NAMESPACEWORD . ':pos="' . $pos . '"></' . cCreateElement::NAMESPACEWORD . ':tab>__GENERATETABS__', $this->xml);
    }

    protected function fGenerateNUMPR() {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':numPr>__GENERATENUMPR__</' . cCreateElement::NAMESPACEWORD . ':numPr>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateILVL($val) {
        $this->xml = str_replace('__GENERATENUMPR__', '<' . cCreateElement::NAMESPACEWORD . ':ilvl ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':ilvl>__GENERATENUMPR__', $this->xml);
    }

    protected function fGenerateKEEPLINES() {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':keepLines></' . cCreateElement::NAMESPACEWORD . ':keepLines>__GENERATEPPR__', $this->xml);
    }

    protected function fGeneratePBDR() {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':pBdr>__GENERATEPBDR__</' . cCreateElement::NAMESPACEWORD . ':pBdr>__GENERATEPPR__', $this->xml);
    }

    protected function fGeneratePBDR_BOTTOM($val, $sz, $space, $color, $themeColor) {
        $this->xml = str_replace('__GENERATEPBDR__', '<' . cCreateElement::NAMESPACEWORD . ':pBdr ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '" ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '" ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '" ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '" ' . cCreateElement::NAMESPACEWORD . ':themeColor="' . $themeColor . '"></' . cCreateElement::NAMESPACEWORD . ':pBdr>__GENERATEPBDR__', $this->xml);
    }

    protected function fGenerateSPACING($before, $after, $line, $lineRule) {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':spacing';
        if ($before != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':before="' . $before . '"';
        if ($after != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':after="' . $after . '"';
        if ($line != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':line="' . $line . '"';
        if ($lineRule != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':lineRule="' . $lineRule . '"';

        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':spacing>__GENERATEPPR__';
        $this->xml = str_replace('__GENERATEPPR__', $xmlAux, $this->xml);
    }

    protected function fGenerateRPR_SPACING($val) {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':spacing ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':spacing>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateKERN($val) {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':kern ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':kern>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateCONTEXTUALSPACING() {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':contextualSpacing></' . cCreateElement::NAMESPACEWORD . ':contextualSpacing>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateOUTLINELVL($val) {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':outlineLvl ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':outlineLvl>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateIND($left) {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':ind ' . cCreateElement::NAMESPACEWORD . ':left="' . $left . '"></' . cCreateElement::NAMESPACEWORD . ':ind>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateTCPR() {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':tcPr>__GENERATETCPR__</' . cCreateElement::NAMESPACEWORD . ':tcPr>__GENERATESTYLE__', $this->xml);
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
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':shd>__GENERATETCPR__';
        $this->xml = str_replace('__GENERATETCPR__', $xmlAux, $this->xml);
    }

    protected function fGenerateTBLPR() {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':tblPr>__GENERATETBLPR__</' . cCreateElement::NAMESPACEWORD . ':tblPr>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateTBLIND($w, $type) {
        $this->xml = str_replace('__GENERATETBLPR__', '<' . cCreateElement::NAMESPACEWORD . ':tblInd ' . cCreateElement::NAMESPACEWORD . ':w="' . $w . '" ' . cCreateElement::NAMESPACEWORD . ':type="' . $type . '"></' . cCreateElement::NAMESPACEWORD . ':tblInd>__GENERATETBLPR__', $this->xml);
    }

    protected function fGenerateTBLSTYLEROWBANDSIZE($val) {
        $this->xml = str_replace('__GENERATETBLPR__', '<' . cCreateElement::NAMESPACEWORD . ':tblStyleRowBandSize ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':tblStyleRowBandSize>__GENERATETBLPR__', $this->xml);
    }

    protected function fGenerateTBLSTYLECOLBANDSIZE($val) {
        $this->xml = str_replace('__GENERATETBLPR__', '<' . cCreateElement::NAMESPACEWORD . ':tblStyleColBandSize ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':tblStyleColBandSize>__GENERATETBLPR__', $this->xml);
    }

    protected function fGenerateTBLBORDERS() {
        $this->xml = str_replace('__GENERATETBLPR__', '<' . cCreateElement::NAMESPACEWORD . ':tblBorders>__GENERATETBLBORDERS__</' . cCreateElement::NAMESPACEWORD . ':tblBorders>__GENERATETBLPR__', $this->xml);
    }

    protected function fGenerateTBLBORDERS_TOP($val, $sz='', $space='', $color='', $themeColor='', $themeTint='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':top ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        if ($sz != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '"';
        if ($space != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '"';
        if ($color != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"';
        if ($themeColor != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeColor="' . $themeColor . '"';
        if ($themeTint != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeTint="' . $themeTint . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':top>__GENERATETBLBORDERS__';
        $this->xml = str_replace('__GENERATETBLBORDERS__', $xmlAux, $this->xml);
    }

    protected function fGenerateTBLBORDERS_LEFT($val, $sz='', $space='', $color='', $themeColor='', $themeTint='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':left ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        if ($sz != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '"';
        if ($space != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '"';
        if ($color != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"';
        if ($themeColor != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeColor="' . $themeColor . '"';
        if ($themeTint != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeTint="' . $themeTint . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':left>__GENERATETBLBORDERS__';
        $this->xml = str_replace('__GENERATETBLBORDERS__', $xmlAux, $this->xml);
    }

    protected function fGenerateTBLBORDERS_BOTTOM($val, $sz='', $space='', $color='', $themeColor='', $themeTint='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':bottom ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        if ($sz != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '"';
        if ($space != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '"';
        if ($color != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"';
        if ($themeColor != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeColor="' . $themeColor . '"';
        if ($themeTint != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeTint="' . $themeTint . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':bottom>__GENERATETBLBORDERS__';
        $this->xml = str_replace('__GENERATETBLBORDERS__', $xmlAux, $this->xml);
    }

    protected function fGenerateTBLBORDERS_RIGHT($val, $sz='', $space='', $color='', $themeColor='', $themeTint='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':right ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        if ($sz != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '"';
        if ($space != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '"';
        if ($color != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"';
        if ($themeColor != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeColor="' . $themeColor . '"';
        if ($themeTint != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeTint="' . $themeTint . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':right>__GENERATETBLBORDERS__';
        $this->xml = str_replace('__GENERATETBLBORDERS__', $xmlAux, $this->xml);
    }

    protected function fGenerateTBLBORDERS_INSIDEH($val, $sz='', $space='', $color='', $themeColor='', $themeTint='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':insideH ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        if ($sz != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '"';
        if ($space != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '"';
        if ($color != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"';
        if ($themeColor != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeColor="' . $themeColor . '"';
        if ($themeTint != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeTint="' . $themeTint . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':insideH>__GENERATETBLBORDERS__';
        $this->xml = str_replace('__GENERATETBLBORDERS__', $xmlAux, $this->xml);
    }

    protected function fGenerateTBLBORDERS_INSIDEV($val, $sz='', $space='', $color='', $themeColor='', $themeTint='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':insideV ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        if ($sz != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':sz="' . $sz . '"';
        if ($space != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':space="' . $space . '"';
        if ($color != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':color="' . $color . '"';
        if ($themeColor != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeColor="' . $themeColor . '"';
        if ($themeTint != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeTint="' . $themeTint . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':insideV>__GENERATETBLBORDERS__';
        $this->xml = str_replace('__GENERATETBLBORDERS__', $xmlAux, $this->xml);
    }

    protected function fGenerateTBLCELLMAR() {
        $this->xml = str_replace('__GENERATETBLPR__', '<' . cCreateElement::NAMESPACEWORD . ':tblCellMar>__GENERATETBLCELLMAR__</' . cCreateElement::NAMESPACEWORD . ':tblCellMar>__GENERATETBLPR__', $this->xml);
    }

    protected function fGenerateTOP($w, $type) {
        $this->xml = str_replace('__GENERATETBLCELLMAR__', '<' . cCreateElement::NAMESPACEWORD . ':top ' . cCreateElement::NAMESPACEWORD . ':w="' . $w . '" ' . cCreateElement::NAMESPACEWORD . ':type="' . $type . '"></' . cCreateElement::NAMESPACEWORD . ':top>__GENERATETBLCELLMAR__', $this->xml);
    }

    protected function fGenerateLEFT($w, $type) {
        $this->xml = str_replace('__GENERATETBLCELLMAR__', '<' . cCreateElement::NAMESPACEWORD . ':left ' . cCreateElement::NAMESPACEWORD . ':w="' . $w . '" ' . cCreateElement::NAMESPACEWORD . ':type="' . $type . '"></' . cCreateElement::NAMESPACEWORD . ':left>__GENERATETBLCELLMAR__', $this->xml);
    }

    protected function fGenerateBOTTOM($w, $type) {
        $this->xml = str_replace('__GENERATETBLCELLMAR__', '<' . cCreateElement::NAMESPACEWORD . ':bottom ' . cCreateElement::NAMESPACEWORD . ':w="' . $w . '" ' . cCreateElement::NAMESPACEWORD . ':type="' . $type . '"></' . cCreateElement::NAMESPACEWORD . ':bottom>__GENERATETBLCELLMAR__', $this->xml);
    }

    protected function fGenerateRIGHT($w, $type) {
        $this->xml = str_replace('__GENERATETBLCELLMAR__', '<' . cCreateElement::NAMESPACEWORD . ':right ' . cCreateElement::NAMESPACEWORD . ':w="' . $w . '" ' . cCreateElement::NAMESPACEWORD . ':type="' . $type . '"></' . cCreateElement::NAMESPACEWORD . ':right>__GENERATETBLCELLMAR__', $this->xml);
    }

    protected function fGenerateRPR() {
        $this->xml = str_replace('__GENERATESTYLE__', '<' . cCreateElement::NAMESPACEWORD . ':rPr>__GENERATERPR__</' . cCreateElement::NAMESPACEWORD . ':rPr>__GENERATESTYLE__', $this->xml);
    }

    protected function fGenerateRFONTS($asciiTheme, $eastAsiaTheme, $hAnsiTheme, $cstheme) {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':rFonts ' . cCreateElement::NAMESPACEWORD . ':asciiTheme="' . $asciiTheme . '" ' . cCreateElement::NAMESPACEWORD . ':eastAsiaTheme="' . $eastAsiaTheme . '" ' . cCreateElement::NAMESPACEWORD . ':hAnsiTheme="' . $hAnsiTheme . '" ' . cCreateElement::NAMESPACEWORD . ':cstheme="' . $cstheme . '"></' . cCreateElement::NAMESPACEWORD . ':rFonts>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateRFONTS2($ascii, $hAnsi, $cs) {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':rFonts ' . cCreateElement::NAMESPACEWORD . ':ascii="' . $ascii . '" ' . cCreateElement::NAMESPACEWORD . ':hAnsi="' . $hAnsi . '" ' . cCreateElement::NAMESPACEWORD . ':cs="' . $cs . '"></' . cCreateElement::NAMESPACEWORD . ':rFonts>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateB() {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':b></' . cCreateElement::NAMESPACEWORD . ':b>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateBCS() {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':bCs></' . cCreateElement::NAMESPACEWORD . ':bCs>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateI($val='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':i';
        if ($val != 1 || $val != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':i>__GENERATERPR__';
        $this->xml = str_replace('__GENERATERPR__', $xmlAux, $this->xml);
    }

    protected function fGenerateICS($val='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':iCs';
        if ($val != 1 || $val != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':iCs>__GENERATERPR__';
        $this->xml = str_replace('__GENERATERPR__', $xmlAux, $this->xml);
    }

    protected function fGenerateU($val='') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':u';
        if ($val != '' && $val != 1)
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':u>__GENERATERPR__';

        $this->xml = str_replace('__GENERATERPR__', $xmlAux, $this->xml);
    }

    protected function fGenerateCOLOR($val, $themeColor='', $themeShade = '') {
        $xmlAux = '<' . cCreateElement::NAMESPACEWORD . ':color ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"';
        if ($themeColor != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeColor="' . $themeColor . '"';
        if ($themeShade != '')
            $xmlAux .= ' ' . cCreateElement::NAMESPACEWORD . ':themeShade="' . $themeShade . '"';
        $xmlAux .= '></' . cCreateElement::NAMESPACEWORD . ':color>__GENERATERPR__';
        $this->xml = str_replace('__GENERATERPR__', $xmlAux, $this->xml);
    }

    protected function fGenerateSZ($val) {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':sz ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':sz>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateSZCS($val) {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':szCs ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':szCs>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateVERTALIGN($val='superscript') {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':vertAlign ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':vertAlign>__GENERATERPR__', $this->xml);
    }

    public function fAddStyle() {
        $arrArgs = func_get_args();
        if (!empty($arrArgs[0][0]['type']) && !empty($arrArgs[0][0]['styleId'])) {
            $this->fGenerateSTYLE($arrArgs[0][0]['type'], $arrArgs[0][0]['styleId'], $arrArgs[0][0]['default'], $arrArgs[0][0]['customStyle']);
        }
        if (!empty($arrArgs[0][0]['name']))
            $this->fGenerateNAME($arrArgs[0][0]['name']);
        if (!empty($arrArgs[0][0]['basedOn']))
            $this->fGenerateBASEDON($arrArgs[0][0]['basedOn']);
        if (!empty($arrArgs[0][0]['next']))
            $this->fGenerateNEXT($arrArgs[0][0]['next']);
        if (!empty($arrArgs[0][0]['link']))
            $this->fGenerateLINK($arrArgs[0][0]['link']);
        if ($arrArgs[0][0]['autoRedefine'] == 1)
            $this->fGenerateAUTOREDEFINE();
        if (!empty($arrArgs[0][0]['uiPriority']))
            $this->fGenerateUIPRIORITY($arrArgs[0][0]['uiPriority']);
        if ($arrArgs[0][0]['semiHidden'] == 1)
            $this->fGenerateSEMIHIDDEN();
        if ($arrArgs[0][0]['unhideWhenUsed'] == 1)
            $this->fGenerateUNHIDEWHENUSED();
        if ($arrArgs[0][0]['qFormat'] == 1)
            $this->fGenerateQFORMAT();
        if (!empty($arrArgs[0][0]['rsid']))
            $this->fGenerateRSID($arrArgs[0][0]['rsid']);
        if ($arrArgs[0][0]['keepNext'] == 1 || !empty($arrArgs[0][0]['keepLines']) || (isset($arrArgs[0][0]['spacing_before']) || isset($arrArgs[0][0]['spacing_after']) || isset($arrArgs[0][0]['spacing_line']) ||
                isset($arrArgs[0][0]['spacing_lineRule'])) || !empty($arrArgs[0][0]['outlineLvl']) || $arrArgs[0][0]['contextualSpacing'] == 1 || isset($arrArgs[0][0]['ilvl']) || isset($arrArgs[0][0]['ind_left'])) {
            $this->fGeneratePPR();
            if ($arrArgs[0][0]['keepNext'] == 1)
                $this->fGenerateKEEPNEXT();
            if (!empty($arrArgs[0][0]['keepLines']))
                $this->fGenerateKEEPLINES($arrArgs[0][0]['keepLines']);
            if (isset($arrArgs[0][0]['pBdr_bottom_val']) && isset($arrArgs[0][0]['pBdr_bottom_sz']) && isset($arrArgs[0][0]['pBdr_bottom_space']) && isset($arrArgs[0][0]['pBdr_bottom_color']) && isset($arrArgs[0][0]['pBdr_bottom_themeColor'])) {
                $this->fGeneratePBDR();
                $this->fGeneratePBDR_BOTTOM($arrArgs[0][0]['pBdr_bottom_val'], $arrArgs[0][0]['pBdr_bottom_sz'], $arrArgs[0][0]['pBdr_bottom_space'], $arrArgs[0][0]['pBdr_bottom_color'], $arrArgs[0][0]['pBdr_bottom_themeColor']);
            }
            if (!empty($arrArgs[0][0]['tab_center']) || $arrArgs[0][0]['tab_right']) {
                $this->fGenerateTABS();
                if (!empty($arrArgs[0][0]['tab_center']))
                    $this->fGenerateTABCENTER($arrArgs[0][0]['tab_center']);
                if (!empty($arrArgs[0][0]['tab_right']))
                    $this->fGenerateTABRIGHT($arrArgs[0][0]['tab_right']);
            }
            if (isset($arrArgs[0][0]['spacing_before']) || isset($arrArgs[0][0]['spacing_after']) || isset($arrArgs[0][0]['spacing_line']) || isset($arrArgs[0][0]['spacing_lineRule']))
                $this->fGenerateSPACING($arrArgs[0][0]['spacing_before'], $arrArgs[0][0]['spacing_after'], $arrArgs[0][0]['spacing_line'], $arrArgs[0][0]['spacing_lineRule']);
            if (isset($arrArgs[0][0]['ind_left']))
                $this->fGenerateIND($arrArgs[0][0]['ind_left']);
            if ($arrArgs[0][0]['contextualSpacing'] == 1)
                $this->fGenerateCONTEXTUALSPACING();
            if (isset($arrArgs[0][0]['outlineLvl']))
                $this->fGenerateOUTLINELVL($arrArgs[0][0]['outlineLvl']);
            if (isset($arrArgs[0][0]['ilvl'])) {
                $this->fGenerateNUMPR();
                $this->fGenerateILVL($arrArgs[0][0]['ilvl']);
            }
        }
        if ((!empty($arrArgs[0][0]['rFonts_asciiTheme']) && !empty($arrArgs[0][0]['rFonts_eastAsiaTheme']) && !empty($arrArgs[0][0]['rFonts_hAnsiTheme']) && !empty($arrArgs[0][0]['rFonts_cstheme'])) || $arrArgs[0][0]['b'] == 1 ||
                $arrArgs[0][0]['bCs'] == 1 || $arrArgs[0][0]['i'] == 1 || $arrArgs[0][0]['iCs'] == 1 || $arrArgs[0][0]['u'] == 1 || !empty($arrArgs[0][0]['color_val']) || !empty($arrArgs[0][0]['sz']) || !empty($arrArgs[0][0]['szCs'])
                || !empty($arrArgs[0][0]['kern']) || !empty($arrArgs[0][0]['rPr_spacing']) || !empty($arrArgs[0][0]['u']) || !empty($arrArgs[0][0]['vertAlign'])) {
            $this->fGenerateRPR();
            if (!empty($arrArgs[0][0]['rFonts_asciiTheme']) && !empty($arrArgs[0][0]['rFonts_eastAsiaTheme']) && !empty($arrArgs[0][0]['rFonts_hAnsiTheme']) && !empty($arrArgs[0][0]['rFonts_cstheme']))
                $this->fGenerateRFONTS($arrArgs[0][0]['rFonts_asciiTheme'], $arrArgs[0][0]['rFonts_eastAsiaTheme'], $arrArgs[0][0]['rFonts_hAnsiTheme'], $arrArgs[0][0]['rFonts_cstheme']);
            if (!empty($arrArgs[0][0]['rFonts_ascii']) && !empty($arrArgs[0][0]['rFonts_hAnsi']) && !empty($arrArgs[0][0]['rFonts_cs']))
                $this->fGenerateRFONTS2($arrArgs[0][0]['rFonts_ascii'], $arrArgs[0][0]['rFonts_hAnsi'], $arrArgs[0][0]['rFonts_cs']);
            if ($arrArgs[0][0]['b'] == 1)
                $this->fGenerateB();
            if ($arrArgs[0][0]['bCs'] == 1)
                $this->fGenerateBCS();
            if (isset($arrArgs[0][0]['i']))
                $this->fGenerateI($arrArgs[0][0]['i']);
            if (isset($arrArgs[0][0]['iCs']))
                $this->fGenerateICS($arrArgs[0][0]['iCs']);
            if ($arrArgs[0][0]['u'] == 1)
                $this->fGenerateU();
            if (!empty($arrArgs[0][0]['color_val']))
                $this->fGenerateCOLOR($arrArgs[0][0]['color_val'], $arrArgs[0][0]['color_themeColor'], $arrArgs[0][0]['color_themeShade']);
            if (!empty($arrArgs[0][0]['u']))
                $this->fGenerateU($arrArgs[0][0]['u']);
            if (!empty($arrArgs[0][0]['rPr_spacing']))
                $this->fGenerateRPR_SPACING($arrArgs[0][0]['rPr_spacing']);
            if (!empty($arrArgs[0][0]['kern']))
                $this->fGenerateKERN($arrArgs[0][0]['kern']);
            if (!empty($arrArgs[0][0]['sz']))
                $this->fGenerateSZ($arrArgs[0][0]['sz']);
            if (!empty($arrArgs[0][0]['szCs']))
                $this->fGenerateSZCS($arrArgs[0][0]['szCs']);
            if (!empty($arrArgs[0][0]['vertAlign']))
                $this->fGenerateVERTALIGN($arrArgs[0][0]['vertAlign']);
        }
        if ((isset($arrArgs[0][0]['top_w']) && isset($arrArgs[0][0]['top_type'])) || (isset($arrArgs[0][0]['left_w']) && isset($arrArgs[0][0]['left_type'])) || (isset($arrArgs[0][0]['bottom_w']) &&
                isset($arrArgs[0][0]['bottom_type'])) || (isset($arrArgs[0][0]['right_w']) && isset($arrArgs[0][0]['right_type'])) || (isset($arrArgs[0][0]['tblInd_w']) && isset($arrArgs[0][0]['tblInd_type'])) &&
                (isset($arrArgs[0][0]['tblborder_top_val'])) || (isset($arrArgs[0][0]['tblborder_left_val'])) || (isset($arrArgs[0][0]['tblborder_bottom_val'])) || (isset($arrArgs[0][0]['tblborder_right_val'])) ||
                (isset($arrArgs[0][0]['tblborder_insideH_val'])) || (isset($arrArgs[0][0]['tblborder_insideV_val']))) {
            $this->fGenerateTBLPR();
            if (isset($arrArgs[0][0]['tbl_style_row']))
                $this->fGenerateTBLSTYLEROWBANDSIZE($arrArgs[0][0]['tbl_style_row']);
            if (isset($arrArgs[0][0]['tbl_style_col']))
                $this->fGenerateTBLSTYLECOLBANDSIZE($arrArgs[0][0]['tbl_style_col']);
            if (isset($arrArgs[0][0]['tblInd_w']) && isset($arrArgs[0][0]['tblInd_type']))
                $this->fGenerateTBLIND($arrArgs[0][0]['tblInd_w'], $arrArgs[0][0]['tblInd_type']);
            if ((isset($arrArgs[0][0]['tblborder_top_val'])) || (isset($arrArgs[0][0]['tblborder_left_val'])) || (isset($arrArgs[0][0]['tblborder_bottom_val'])) || (isset($arrArgs[0][0]['tblborder_right_val'])) ||
                    (isset($arrArgs[0][0]['tblborder_insideH_val'])) || (isset($arrArgs[0][0]['tblborder_insideV_val']))) {
                $this->fGenerateTBLBORDERS();
                if (isset($arrArgs[0][0]['tblborder_top_val']))
                    $this->fGenerateTBLBORDERS_TOP($arrArgs[0][0]['tblborder_top_val'], $arrArgs[0][0]['tblborder_top_sz'], $arrArgs[0][0]['tblborder_top_space'], $arrArgs[0][0]['tblborder_top_color'], $arrArgs[0][0]['tblborder_top_themeColor'], $arrArgs[0][0]['tblborder_insideV_themeTint']);
                if (isset($arrArgs[0][0]['tblborder_left_val']))
                    $this->fGenerateTBLBORDERS_LEFT($arrArgs[0][0]['tblborder_left_val'], $arrArgs[0][0]['tblborder_left_sz'], $arrArgs[0][0]['tblborder_left_space'], $arrArgs[0][0]['tblborder_left_color'], $arrArgs[0][0]['tblborder_left_themeColor'], $arrArgs[0][0]['tblborder_insideV_themeTint']);
                if (isset($arrArgs[0][0]['tblborder_bottom_val']))
                    $this->fGenerateTBLBORDERS_BOTTOM($arrArgs[0][0]['tblborder_bottom_val'], $arrArgs[0][0]['tblborder_bottom_sz'], $arrArgs[0][0]['tblborder_bottom_space'], $arrArgs[0][0]['tblborder_bottom_color'], $arrArgs[0][0]['tblborder_bottom_themeColor'], $arrArgs[0][0]['tblborder_insideV_themeTint']);
                if (isset($arrArgs[0][0]['tblborder_right_val']))
                    $this->fGenerateTBLBORDERS_RIGHT($arrArgs[0][0]['tblborder_right_val'], $arrArgs[0][0]['tblborder_right_sz'], $arrArgs[0][0]['tblborder_right_space'], $arrArgs[0][0]['tblborder_right_color'], $arrArgs[0][0]['tblborder_right_themeColor'], $arrArgs[0][0]['tblborder_insideV_themeTint']);
                if (isset($arrArgs[0][0]['tblborder_insideH_val']))
                    $this->fGenerateTBLBORDERS_INSIDEH($arrArgs[0][0]['tblborder_insideH_val'], $arrArgs[0][0]['tblborder_insideH_sz'], $arrArgs[0][0]['tblborder_insideH_space'], $arrArgs[0][0]['tblborder_insideH_color'], $arrArgs[0][0]['tblborder_insideH_themeColor'], $arrArgs[0][0]['tblborder_insideV_themeTint']);
                if (isset($arrArgs[0][0]['tblborder_insideV_val']))
                    $this->fGenerateTBLBORDERS_INSIDEV($arrArgs[0][0]['tblborder_insideV_val'], $arrArgs[0][0]['tblborder_insideV_sz'], $arrArgs[0][0]['tblborder_insideV_space'], $arrArgs[0][0]['tblborder_insideV_color'], $arrArgs[0][0]['tblborder_insideV_themeColor'], $arrArgs[0][0]['tblborder_insideV_themeTint']);
                //}
            }

            if ((isset($arrArgs[0][0]['top_w']) && isset($arrArgs[0][0]['top_type'])) || (isset($arrArgs[0][0]['left_w']) && isset($arrArgs[0][0]['left_type']))
                    || (isset($arrArgs[0][0]['bottom_w']) && isset($arrArgs[0][0]['bottom_type'])) || (isset($arrArgs[0][0]['right_w']) && isset($arrArgs[0][0]['right_type']))) {
                $this->fGenerateTBLCELLMAR();
                if (isset($arrArgs[0][0]['top_w']) && isset($arrArgs[0][0]['top_type']))
                    $this->fGenerateTOP($arrArgs[0][0]['top_w'], $arrArgs[0][0]['top_type']);
                if (isset($arrArgs[0][0]['left_w']) && isset($arrArgs[0][0]['left_type']))
                    $this->fGenerateLEFT($arrArgs[0][0]['left_w'], $arrArgs[0][0]['left_type']);
                if (isset($arrArgs[0][0]['bottom_w']) && isset($arrArgs[0][0]['bottom_type']))
                    $this->fGenerateBOTTOM($arrArgs[0][0]['bottom_w'], $arrArgs[0][0]['bottom_type']);
                if (isset($arrArgs[0][0]['right_w']) && isset($arrArgs[0][0]['right_type']))
                    $this->fGenerateRIGHT($arrArgs[0][0]['right_w'], $arrArgs[0][0]['right_type']);
            }
        }
        if (isset($arrArgs[0][0]['shd_val']) && isset($arrArgs[0][0]['shd_color']) && isset($arrArgs[0][0]['shd_fill']) && isset($arrArgs[0][0]['shd_themeFill'])) {
            $this->fGenerateTCPR();
            $this->fGenerateSHD($arrArgs[0][0]['shd_val'], $arrArgs[0][0]['shd_color'], $arrArgs[0][0]['shd_fill'], $arrArgs[0][0]['shd_themeFill'], $arrArgs[0][0]['shd_themeFillTint']);
        }
        if (count($arrArgs[0]) > 1) {
            for ($i = 1; $i < count($arrArgs[0]); $i++) {
                $this->fAddStyleTabla($arrArgs[0][$i]);
            }
        }
        $this->fCleanTemplate();
    }

    public function fCreateStyle($lang='es-ES') {
        $this->xml = '<w:docDefaults><w:rPrDefault><w:rPr><w:rFonts w:asciiTheme="minorHAnsi" w:eastAsiaTheme="minorHAnsi" w:hAnsiTheme="minorHAnsi" w:cstheme="minorBidi"/><w:sz w:val="22"/><w:szCs w:val="22"/>' .
                '<w:lang w:val="' . $lang . '" w:eastAsia="' . $lang . '" w:bidi="ar-SA"/></w:rPr></w:rPrDefault><w:pPrDefault><w:pPr><w:spacing w:after="200" w:line="276" w:lineRule="auto"/></w:pPr></w:pPrDefault></w:docDefaults>' .
                '<w:latentStyles w:defLockedState="0" w:defUIPriority="99" w:defSemiHidden="1" w:defUnhideWhenUsed="1" w:defQFormat="0" w:count="267">' .
                '<w:lsdException w:name="Normal" w:semiHidden="0" w:uiPriority="0" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="heading 1" w:semiHidden="0" w:uiPriority="9" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="heading 2" w:uiPriority="9" w:qFormat="1"/><w:lsdException w:name="heading 3" w:uiPriority="9" w:qFormat="1"/><w:lsdException w:name="heading 4" w:uiPriority="9" w:qFormat="1"/><w:lsdException w:name="heading 5" w:uiPriority="9" w:qFormat="1"/><w:lsdException w:name="heading 6" w:uiPriority="9" w:qFormat="1"/><w:lsdException w:name="heading 7" w:uiPriority="9" w:qFormat="1"/><w:lsdException w:name="heading 8" w:uiPriority="9" w:qFormat="1"/><w:lsdException w:name="heading 9" w:uiPriority="9" w:qFormat="1"/><w:lsdException w:name="toc 1" w:uiPriority="39"/><w:lsdException w:name="toc 2" w:uiPriority="39"/><w:lsdException w:name="toc 3" w:uiPriority="39"/><w:lsdException w:name="toc 4" w:uiPriority="39"/><w:lsdException w:name="toc 5" w:uiPriority="39"/><w:lsdException w:name="toc 6" w:uiPriority="39"/><w:lsdException w:name="toc 7" w:uiPriority="39"/><w:lsdException w:name="toc 8" w:uiPriority="39"/><w:lsdException w:name="toc 9" w:uiPriority="39"/><w:lsdException w:name="caption" w:uiPriority="35" w:qFormat="1"/><w:lsdException w:name="Title" w:semiHidden="0" w:uiPriority="10" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Default Paragraph Font" w:uiPriority="1"/><w:lsdException w:name="Subtitle" w:semiHidden="0" w:uiPriority="11" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Strong" w:semiHidden="0" w:uiPriority="22" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Emphasis" w:semiHidden="0" w:uiPriority="20" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Table Grid" w:semiHidden="0" w:uiPriority="59" w:unhideWhenUsed="0"/><w:lsdException w:name="Placeholder Text" w:unhideWhenUsed="0"/><w:lsdException w:name="No Spacing" w:semiHidden="0" w:uiPriority="1" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Light Shading" w:semiHidden="0" w:uiPriority="60" w:unhideWhenUsed="0"/><w:lsdException w:name="Light List" w:semiHidden="0" w:uiPriority="61" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Grid" w:semiHidden="0" w:uiPriority="62" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 1" w:semiHidden="0" w:uiPriority="63" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 2" w:semiHidden="0" w:uiPriority="64" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 1" w:semiHidden="0" w:uiPriority="65" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 2" w:semiHidden="0" w:uiPriority="66" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 1" w:semiHidden="0" w:uiPriority="67" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 2" w:semiHidden="0" w:uiPriority="68" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 3" w:semiHidden="0" w:uiPriority="69" w:unhideWhenUsed="0"/><w:lsdException w:name="Dark List" w:semiHidden="0" w:uiPriority="70" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Shading" w:semiHidden="0" w:uiPriority="71" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful List" w:semiHidden="0" w:uiPriority="72" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Grid" w:semiHidden="0" w:uiPriority="73" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Shading Accent 1" w:semiHidden="0" w:uiPriority="60" w:unhideWhenUsed="0"/><w:lsdException w:name="Light List Accent 1" w:semiHidden="0" w:uiPriority="61" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Grid Accent 1" w:semiHidden="0" w:uiPriority="62" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 1 Accent 1" w:semiHidden="0" w:uiPriority="63" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 2 Accent 1" w:semiHidden="0" w:uiPriority="64" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 1 Accent 1" w:semiHidden="0" w:uiPriority="65" w:unhideWhenUsed="0"/><w:lsdException w:name="Revision" w:unhideWhenUsed="0"/><w:lsdException w:name="List Paragraph" w:semiHidden="0" w:uiPriority="34" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Quote" w:semiHidden="0" w:uiPriority="29" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Intense Quote" w:semiHidden="0" w:uiPriority="30" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Medium List 2 Accent 1" w:semiHidden="0" w:uiPriority="66" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 1 Accent 1" w:semiHidden="0" w:uiPriority="67" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 2 Accent 1" w:semiHidden="0" w:uiPriority="68" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 3 Accent 1" w:semiHidden="0" w:uiPriority="69" w:unhideWhenUsed="0"/><w:lsdException w:name="Dark List Accent 1" w:semiHidden="0" w:uiPriority="70" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Shading Accent 1" w:semiHidden="0" w:uiPriority="71" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful List Accent 1" w:semiHidden="0" w:uiPriority="72" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Grid Accent 1" w:semiHidden="0" w:uiPriority="73" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Shading Accent 2" w:semiHidden="0" w:uiPriority="60" w:unhideWhenUsed="0"/><w:lsdException w:name="Light List Accent 2" w:semiHidden="0" w:uiPriority="61" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Grid Accent 2" w:semiHidden="0" w:uiPriority="62" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 1 Accent 2" w:semiHidden="0" w:uiPriority="63" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 2 Accent 2" w:semiHidden="0" w:uiPriority="64" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 1 Accent 2" w:semiHidden="0" w:uiPriority="65" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 2 Accent 2" w:semiHidden="0" w:uiPriority="66" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 1 Accent 2" w:semiHidden="0" w:uiPriority="67" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 2 Accent 2" w:semiHidden="0" w:uiPriority="68" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 3 Accent 2" w:semiHidden="0" w:uiPriority="69" w:unhideWhenUsed="0"/><w:lsdException w:name="Dark List Accent 2" w:semiHidden="0" w:uiPriority="70" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Shading Accent 2" w:semiHidden="0" w:uiPriority="71" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful List Accent 2" w:semiHidden="0" w:uiPriority="72" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Grid Accent 2" w:semiHidden="0" w:uiPriority="73" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Shading Accent 3" w:semiHidden="0" w:uiPriority="60" w:unhideWhenUsed="0"/><w:lsdException w:name="Light List Accent 3" w:semiHidden="0" w:uiPriority="61" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Grid Accent 3" w:semiHidden="0" w:uiPriority="62" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 1 Accent 3" w:semiHidden="0" w:uiPriority="63" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 2 Accent 3" w:semiHidden="0" w:uiPriority="64" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 1 Accent 3" w:semiHidden="0" w:uiPriority="65" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 2 Accent 3" w:semiHidden="0" w:uiPriority="66" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 1 Accent 3" w:semiHidden="0" w:uiPriority="67" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 2 Accent 3" w:semiHidden="0" w:uiPriority="68" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 3 Accent 3" w:semiHidden="0" w:uiPriority="69" w:unhideWhenUsed="0"/><w:lsdException w:name="Dark List Accent 3" w:semiHidden="0" w:uiPriority="70" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Shading Accent 3" w:semiHidden="0" w:uiPriority="71" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful List Accent 3" w:semiHidden="0" w:uiPriority="72" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Grid Accent 3" w:semiHidden="0" w:uiPriority="73" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Shading Accent 4" w:semiHidden="0" w:uiPriority="60" w:unhideWhenUsed="0"/><w:lsdException w:name="Light List Accent 4" w:semiHidden="0" w:uiPriority="61" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Grid Accent 4" w:semiHidden="0" w:uiPriority="62" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 1 Accent 4" w:semiHidden="0" w:uiPriority="63" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 2 Accent 4" w:semiHidden="0" w:uiPriority="64" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 1 Accent 4" w:semiHidden="0" w:uiPriority="65" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 2 Accent 4" w:semiHidden="0" w:uiPriority="66" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 1 Accent 4" w:semiHidden="0" w:uiPriority="67" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 2 Accent 4" w:semiHidden="0" w:uiPriority="68" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 3 Accent 4" w:semiHidden="0" w:uiPriority="69" w:unhideWhenUsed="0"/><w:lsdException w:name="Dark List Accent 4" w:semiHidden="0" w:uiPriority="70" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Shading Accent 4" w:semiHidden="0" w:uiPriority="71" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful List Accent 4" w:semiHidden="0" w:uiPriority="72" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Grid Accent 4" w:semiHidden="0" w:uiPriority="73" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Shading Accent 5" w:semiHidden="0" w:uiPriority="60" w:unhideWhenUsed="0"/><w:lsdException w:name="Light List Accent 5" w:semiHidden="0" w:uiPriority="61" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Grid Accent 5" w:semiHidden="0" w:uiPriority="62" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 1 Accent 5" w:semiHidden="0" w:uiPriority="63" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 2 Accent 5" w:semiHidden="0" w:uiPriority="64" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 1 Accent 5" w:semiHidden="0" w:uiPriority="65" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 2 Accent 5" w:semiHidden="0" w:uiPriority="66" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 1 Accent 5" w:semiHidden="0" w:uiPriority="67" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 2 Accent 5" w:semiHidden="0" w:uiPriority="68" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 3 Accent 5" w:semiHidden="0" w:uiPriority="69" w:unhideWhenUsed="0"/><w:lsdException w:name="Dark List Accent 5" w:semiHidden="0" w:uiPriority="70" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Shading Accent 5" w:semiHidden="0" w:uiPriority="71" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful List Accent 5" w:semiHidden="0" w:uiPriority="72" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Grid Accent 5" w:semiHidden="0" w:uiPriority="73" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Shading Accent 6" w:semiHidden="0" w:uiPriority="60" w:unhideWhenUsed="0"/><w:lsdException w:name="Light List Accent 6" w:semiHidden="0" w:uiPriority="61" w:unhideWhenUsed="0"/><w:lsdException w:name="Light Grid Accent 6" w:semiHidden="0" w:uiPriority="62" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 1 Accent 6" w:semiHidden="0" w:uiPriority="63" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Shading 2 Accent 6" w:semiHidden="0" w:uiPriority="64" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 1 Accent 6" w:semiHidden="0" w:uiPriority="65" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium List 2 Accent 6" w:semiHidden="0" w:uiPriority="66" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 1 Accent 6" w:semiHidden="0" w:uiPriority="67" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 2 Accent 6" w:semiHidden="0" w:uiPriority="68" w:unhideWhenUsed="0"/><w:lsdException w:name="Medium Grid 3 Accent 6" w:semiHidden="0" w:uiPriority="69" w:unhideWhenUsed="0"/><w:lsdException w:name="Dark List Accent 6" w:semiHidden="0" w:uiPriority="70" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Shading Accent 6" w:semiHidden="0" w:uiPriority="71" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful List Accent 6" w:semiHidden="0" w:uiPriority="72" w:unhideWhenUsed="0"/><w:lsdException w:name="Colorful Grid Accent 6" w:semiHidden="0" w:uiPriority="73" w:unhideWhenUsed="0"/><w:lsdException w:name="Subtle Emphasis" w:semiHidden="0" w:uiPriority="19" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Intense Emphasis" w:semiHidden="0" w:uiPriority="21" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Subtle Reference" w:semiHidden="0" w:uiPriority="31" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Intense Reference" w:semiHidden="0" w:uiPriority="32" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Book Title" w:semiHidden="0" w:uiPriority="33" w:unhideWhenUsed="0" w:qFormat="1"/><w:lsdException w:name="Bibliography" w:uiPriority="37"/><w:lsdException w:name="TOC Heading" w:uiPriority="39" w:qFormat="1"/></w:latentStyles>';
        $arrParametros = array('type' => 'paragraph', 'default' => '1', 'styleId' => 'Normal', 'name' => 'Normal', 'qFormat' => 1, 'rsid' => '000415ED');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Ttulo1', 'name' => 'heading 1', 'basedOn' => 'Normal', 'next' => 'Normal', 'link' => 'Ttulo1Car', 'uiPriority' => '9', 'qFormat' => 1,
            'rsid' => '00CF3BFC', 'keepNext' => 1, 'keepLines' => 1, 'spacing_before' => '480', 'spacing_after' => '0', 'outlineLvl' => '0', 'rFonts_asciiTheme' => 'majorHAnsi',
            'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'b' => 1, 'bCs' => 1, 'color_val' => '365F91', 'color_themeColor' => 'accent1',
            'color_themeShade' => 'BF', 'sz' => 28, 'szCs' => 28);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Ttulo2', 'name' => 'heading 2', 'basedOn' => 'Normal', 'next' => 'Normal', 'link' => 'Ttulo2Car', 'uiPriority' => '9', 'unhideWhenUsed' => 1, 'qFormat' => 1,
            'rsid' => '005235DC', 'keepNext' => 1, 'keepLines' => 1, 'spacing_before' => '200', 'spacing_after' => '0', 'outlineLvl' => '1', 'rFonts_asciiTheme' => 'majorHAnsi',
            'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'b' => 1, 'bCs' => 1, 'color_val' => '200290',
            'sz' => 32, 'szCs' => 26);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Ttulo3', 'name' => 'heading 3', 'basedOn' => 'Normal', 'next' => 'Normal', 'link' => 'Ttulo3Car', 'uiPriority' => '9', 'unhideWhenUsed' => 1, 'qFormat' => 1,
            'rsid' => '005235DC', 'keepNext' => 1, 'keepLines' => 1, 'spacing_before' => '200', 'spacing_after' => '0', 'outlineLvl' => '2', 'rFonts_asciiTheme' => 'majorHAnsi',
            'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'b' => 1, 'bCs' => 1, 'color_val' => '000000', 'color_themeColor' => 'text1',
            'sz' => 28);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Ttulo4', 'name' => 'heading 4', 'basedOn' => 'Normal', 'next' => 'Normal', 'link' => 'Ttulo4Car', 'uiPriority' => '9', 'unhideWhenUsed' => 1, 'qFormat' => 1,
            'rsid' => '007D6ADC', 'keepNext' => 1, 'keepLines' => 1, 'spacing_before' => '200', 'spacing_after' => '0', 'outlineLvl' => '3', 'rFonts_asciiTheme' => 'majorHAnsi',
            'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'b' => 1, 'bCs' => 1, 'i' => 1, 'iCs' => 1, 'color_val' => '4F81BD',
            'color_themeColor' => 'accent1');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'character', 'default' => '1', 'styleId' => 'Fuentedeprrafopredeter', 'name' => 'Default Paragraph Font', 'uiPriority' => '1', 'unhideWhenUsed' => 1,
            'semiHidden' => 1);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'table', 'default' => '1', 'styleId' => 'Tablanormal', 'name' => 'Normal Table', 'uiPriority' => '99', 'semiHidden' => 1, 'unhideWhenUsed' => 1, 'qFormat' => 1,
            'tblInd_w' => '0', 'tblInd_type' => 'dxa', 'top_w' => '0', 'top_type' => 'dxa', 'left_w' => '108', 'left_type' => 'dxa', 'bottom_w' => '0', 'bottom_type' => 'dxa',
            'right_w' => '108', 'right_type' => 'dxa');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'numbering', 'default' => '1', 'styleId' => 'Sinlista', 'name' => 'No List', 'uiPriority' => '99', 'semiHidden' => 1, 'unhideWhenUsed' => 1);
        $this->fAddStyle(array($arrParametros));
        // falla x el acento!!!
        $arrParametros = array('type' => 'character', 'customStyle' => '1', 'styleId' => 'Ttulo1Car', 'name' => 'Titulo 1 Car', 'basedOn' => 'Fuentedeprrafopredeter', 'link' => 'Ttulo1', 'uiPriority' => '9',
            'rsid' => '005235DC', 'rFonts_asciiTheme' => 'majorHAnsi', 'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'b' => 1, 'bCs' => 1,
            'color_val' => '365F91', 'color_themeColor' => 'accent1', 'color_themeShade' => 'BF', 'sz' => '28', 'szCs' => '28');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'character', 'customStyle' => '1', 'styleId' => 'Ttulo2Car', 'name' => 'Titulo 2 Car', 'basedOn' => 'Fuentedeprrafopredeter', 'link' => 'Ttulo2', 'uiPriority' => '9',
            'rsid' => '00CF3BFC', 'rFonts_asciiTheme' => 'majorHAnsi', 'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'b' => 1, 'bCs' => 1,
            'color_val' => '200290', 'sz' => 32, 'szCs' => 26);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'character', 'customStyle' => '1', 'styleId' => 'Ttulo3Car', 'name' => 'Titulo 3 Car', 'basedOn' => 'Fuentedeprrafopredeter', 'link' => 'Ttulo3', 'uiPriority' => '9',
            'rsid' => '005235DC', 'rFonts_asciiTheme' => 'majorHAnsi', 'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'b' => 1, 'bCs' => 1,
            'color_val' => '000000', 'color_themeColor' => 'text1', 'sz' => 28);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Ttulo', 'name' => 'Title', 'basedOn' => 'Normal', 'next' => 'Normal', 'link' => 'TtuloCar', 'uiPriority' => '10', 'qFormat' => 1,
            'rsid' => '00CF3BFC', 'pBdr_bottom_val' => 'single', 'pBdr_bottom_sz' => 8, 'pBdr_bottom_space' => 4, 'pBdr_bottom_color' => '4F81BD', 'pBdr_bottom_themeColor' => 'accent1',
            'spacing_after' => '300', 'spacing_line' => '240', 'spacing_lineRule' => 'auto', 'contextualSpacing' => 1, 'rFonts_asciiTheme' => 'majorHAnsi', 'rFonts_eastAsiaTheme' => 'majorEastAsia',
            'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'color_val' => '17365D', 'color_themeColor' => 'text2', 'color_themeShade' => 'BF', 'rPr_spacing' => '5', 'kern' => '28', 'sz' => 52, 'szCs' => 52);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'character', 'customStyle' => '1', 'styleId' => 'TtuloCar', 'name' => 'Titulo Car', 'basedOn' => 'Fuentedeprrafopredeter', 'link' => 'Ttulo', 'uiPriority' => '10',
            'rsid' => '00CF3BFC', 'rFonts_asciiTheme' => 'majorHAnsi', 'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'color_val' => '17365D',
            'color_themeColor' => 'text2', 'color_themeShade' => 'BF', 'rPr_spacing' => '5', 'kern' => '28', 'sz' => 52, 'szCs' => 52);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Subttulo', 'name' => 'Subtitle', 'basedOn' => 'Normal', 'next' => 'Normal', 'link' => 'SubttuloCar', 'uiPriority' => '11', 'qFormat' => 1,
            'rsid' => '00CF3BFC', 'rFonts_asciiTheme' => 'majorHAnsi', 'ilvl' => '1', 'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'i' => 1, 'iCs' => 1, 'color_val' => '4F81BD',
            'color_themeColor' => 'accent1', 'rPr_spacing' => '15', 'sz' => 24, 'szCs' => 24);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Sinespaciado', 'name' => 'No Spacing', 'uiPriority' => '1', 'qFormat' => 1, 'rsid' => '007D6ADC', 'spacing_after' => '0',
            'spacing_line' => '240', 'spacing_lineRule' => 'auto');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'character', 'customStyle' => '1', 'styleId' => 'Ttulo4Car', 'name' => 'Titulo 4 Car', 'basedOn' => 'Fuentedeprrafopredeter', 'link' => 'Ttulo4', 'uiPriority' => '9',
            'rsid' => '007D6ADC', 'rFonts_asciiTheme' => 'majorHAnsi', 'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'b' => 1, 'bCs' => 1,
            'i' => 1, 'iCs' => 1, 'color_val' => '4F81BD', 'color_themeColor' => 'accent1');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'character', 'styleId' => 'Hipervnculo', 'name' => 'Hyperlink', 'basedOn' => 'Fuentedeprrafopredeter', 'uiPriority' => '99', 'unhideWhenUsed' => 1,
            'rsid' => '00EF1859', 'color_val' => '0000FF', 'color_themeColor' => 'hyperlink', 'u' => 'single');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Prrafodelista', 'name' => 'List Paragraph', 'basedOn' => 'Normal', 'uiPriority' => '34', 'qFormat' => 1, 'rsid' => '007D6ADC',
            'ind_left' => 720, 'contextualSpacing' => 1);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'table', 'styleId' => 'Tablaconcuadrcula', 'name' => 'Table Grid', 'basedOn' => 'Tablanormal', 'uiPriority' => '59', 'rsid' => '007D6ADC', 'spacing_after' => '0',
            'spacing_line' => '240', 'spacing_lineRule' => 'auto', 'tblInd_w' => '0', 'tblInd_type' => 'dxa', 'top_w' => '0', 'top_type' => 'dxa', 'left_w' => '108', 'left_type' => 'dxa', 'bottom_w' => '0', 'bottom_type' => 'dxa',
            'right_w' => '108', 'tblborder_top_val' => 'single', 'tblborder_top_sz' => 4, 'tblborder_top_space' => '0', 'tblborder_top_color' => '000000', 'tblborder_top_themeColor' => 'text1',
            'tblborder_left_val' => 'single', 'tblborder_left_sz' => 4, 'tblborder_left_space' => '0', 'tblborder_left_color' => '000000', 'tblborder_left_themeColor' => 'text1',
            'tblborder_bottom_val' => 'single', 'tblborder_bottom_sz' => 4, 'tblborder_bottom_space' => '0', 'tblborder_bottom_color' => '000000', 'tblborder_bottom_themeColor' => 'text1',
            'tblborder_right_val' => 'single', 'tblborder_right_sz' => 4, 'tblborder_right_space' => '0', 'tblborder_right_color' => '000000', 'tblborder_right_themeColor' => 'text1',
            'tblborder_insideH_val' => 'single', 'tblborder_insideH_sz' => 4, 'tblborder_insideH_space' => '0', 'tblborder_insideH_color' => '000000', 'tblborder_insideH_themeColor' => 'text1',
            'tblborder_insideV_val' => 'single', 'tblborder_insideV_sz' => 4, 'tblborder_insideV_space' => '0', 'tblborder_insideV_color' => '000000', 'tblborder_insideV_themeColor' => 'text1');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Textodeglobo', 'name' => 'Balloon Text', 'basedOn' => 'Normal', 'link' => 'TextodegloboCar', 'uiPriority' => '99', 'semiHidden' => 1,
            'unhideWhenUsed' => 1, 'rsid' => '007D6ADC', 'spacing_after' => '0', 'spacing_line' => '240', 'spacing_lineRule' => 'auto', 'sz' => 16, 'szCs' => 16, 'rFonts_ascii' => 'Tahoma',
            'rFonts_hAnsi' => 'Tahoma', 'rFonts_cs' => 'Tahoma');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'character', 'customStyle' => '1', 'styleId' => 'TextodegloboCar', 'name' => 'Texto de globo Car', 'basedOn' => 'Fuentedeprrafopredeter', 'link' => 'Textodeglobo',
            'uiPriority' => '99', 'semiHidden' => 1, 'rsid' => '007D6ADC', 'sz' => 16, 'szCs' => 16, 'rFonts_ascii' => 'Tahoma', 'rFonts_hAnsi' => 'Tahoma', 'rFonts_cs' => 'Tahoma');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Encabezado', 'name' => 'header', 'basedOn' => 'Normal', 'link' => 'EncabezadoCar', 'uiPriority' => '99', 'unhideWhenUsed' => 1,
            'rsid' => '007D6ADC', 'spacing_after' => '0', 'spacing_line' => '240', 'spacing_lineRule' => 'auto', 'tab_center' => 4252, 'tab_right' => 8504);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'character', 'customStyle' => '1', 'styleId' => 'EncabezadoCar', 'name' => 'Encabezado Car', 'basedOn' => 'Fuentedeprrafopredeter', 'link' => 'Encabezado', 'uiPriority' => '99',
            'rsid' => '007D6ADC');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Piedepgina', 'name' => 'footer', 'basedOn' => 'Normal', 'link' => 'PiedepginaCar', 'uiPriority' => '99', 'unhideWhenUsed' => 1,
            'rsid' => '007D6ADC', 'spacing_after' => '0', 'spacing_line' => '240', 'spacing_lineRule' => 'auto', 'tab_center' => 4252, 'tab_right' => 8504);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'character', 'customStyle' => '1', 'styleId' => 'PiedepginaCar', 'name' => 'Pie de pagina Car', 'basedOn' => 'Fuentedeprrafopredeter', 'link' => 'Piedepgina',
            'uiPriority' => '99', 'rsid' => '007D6ADC');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'TDC1', 'name' => 'toc 1', 'basedOn' => 'Normal', 'next' => 'Normal', 'autoRedefine' => 1, 'uiPriority' => '39', 'unhideWhenUsed' => 1,
            'rsid' => '00EF1859', 'spacing_after' => '100');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'numbering', 'customStyle' => '1', 'styleId' => 'Sinlista', 'name' => 'No List', 'uiPriority' => '99', 'semiHidden' => 1, 'unhideWhenUsed' => 1);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'TDC2', 'name' => 'toc 2', 'basedOn' => 'Normal', 'next' => 'Normal', 'autoRedefine' => 1, 'uiPriority' => '39', 'semiHidden' => 1,
            'unhideWhenUsed' => 1, 'rsid' => '005F706C', 'spacing_after' => '100', 'ind_left' => 220, 'b' => 1, 'sz' => 24);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'TDC3', 'name' => 'toc 3', 'basedOn' => 'Normal', 'next' => 'Normal', 'autoRedefine' => 1, 'uiPriority' => '39',
            'unhideWhenUsed' => 1, 'rsid' => '00EF1859', 'spacing_after' => '100', 'ind_left' => 440);
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'table', 'styleId' => 'Cuadrculamedia3-nfasis1', 'name' => 'Medium Grid 3 Accent 1', 'basedOn' => 'Tablanormal', 'uiPriority' => '69', 'rsid' => '00387AE9',
            'spacing_after' => '0', 'spacing_line' => '240', 'spacing_lineRule' => 'auto',
            'tblInd_w' => '0', 'tblInd_type' => 'dxa', 'top_w' => '0', 'top_type' => 'dxa', 'left_w' => '108', 'left_type' => 'dxa', 'bottom_w' => '0', 'bottom_type' => 'dxa',
            'right_w' => '108', 'right_type' => 'dxa', 'tbl_style_row' => 1, 'tbl_style_col' => 1,
            'tblborder_top_val' => 'single', 'tblborder_top_sz' => 8, 'tblborder_top_space' => '0', 'tblborder_top_color' => 'FFFFFF', 'tblborder_top_themeColor' => 'background1',
            'tblborder_left_val' => 'single', 'tblborder_left_sz' => 8, 'tblborder_left_space' => '0', 'tblborder_left_color' => 'FFFFFF', 'tblborder_left_themeColor' => 'background1',
            'tblborder_bottom_val' => 'single', 'tblborder_bottom_sz' => 8, 'tblborder_bottom_space' => '0', 'tblborder_bottom_color' => 'FFFFFF', 'tblborder_bottom_themeColor' => 'background1',
            'tblborder_right_val' => 'single', 'tblborder_right_sz' => 8, 'tblborder_right_space' => '0', 'tblborder_right_color' => 'FFFFFF', 'tblborder_right_themeColor' => 'background1',
            'tblborder_insideH_val' => 'single', 'tblborder_insideH_sz' => 6, 'tblborder_insideH_space' => '0', 'tblborder_insideH_color' => 'FFFFFF', 'tblborder_insideH_themeColor' => 'background1',
            'tblborder_insideV_val' => 'single', 'tblborder_insideV_sz' => 6, 'tblborder_insideV_space' => '0', 'tblborder_insideV_color' => 'FFFFFF', 'tblborder_insideV_themeColor' => 'background1',
            'shd_val' => 'clear', 'shd_color' => 'auto', 'shd_fill' => 'D3DFEE', 'shd_themeFill' => 'accent1', 'shd_themeFillTint' => '3F');

        $arrStyleTable1 = array('type' => 'firstRow', 'b' => 1, 'b' => 1, 'bCs' => 1, 'i' => '0', 'iCs' => '0', 'color_val' => 'FFFFFF', 'color_themeColor' => 'background1', 'tblPr' => 1,
            'tblborder_top_val' => 'single', 'tblborder_top_sz' => 8, 'tblborder_top_space' => '0', 'tblborder_top_color' => 'FFFFFF', 'tblborder_top_themeColor' => 'background1',
            'tblborder_left_val' => 'single', 'tblborder_left_sz' => 8, 'tblborder_left_space' => '0', 'tblborder_left_color' => 'FFFFFF', 'tblborder_left_themeColor' => 'background1',
            'tblborder_bottom_val' => 'single', 'tblborder_bottom_sz' => 24, 'tblborder_bottom_space' => '0', 'tblborder_bottom_color' => 'FFFFFF', 'tblborder_bottom_themeColor' => 'background1',
            'tblborder_right_val' => 'single', 'tblborder_right_sz' => 8, 'tblborder_right_space' => '0', 'tblborder_right_color' => 'FFFFFF', 'tblborder_right_themeColor' => 'background1',
            'tblborder_insideH_val' => 'nil',
            'tblborder_insideV_val' => 'single', 'tblborder_insideV_sz' => 8, 'tblborder_insideV_space' => '0', 'tblborder_insideV_color' => 'FFFFFF', 'tblborder_insideV_themeColor' => 'background1',
            'shd_val' => 'clear', 'shd_color' => 'auto', 'shd_fill' => '4F81BD', 'shd_themeFill' => 'accent1');
        $arrStyleTable2 = array('type' => 'lastRow', 'b' => 1, 'bCs' => 1, 'i' => '0', 'iCs' => '0', 'color_val' => 'FFFFFF', 'color_themeColor' => 'background1', 'tblPr' => 1,
            'tblborder_top_val' => 'single', 'tblborder_top_sz' => 24, 'tblborder_top_space' => '0', 'tblborder_top_color' => 'FFFFFF', 'tblborder_top_themeColor' => 'background1',
            'tblborder_left_val' => 'single', 'tblborder_left_sz' => 8, 'tblborder_left_space' => '0', 'tblborder_left_color' => 'FFFFFF', 'tblborder_left_themeColor' => 'background1',
            'tblborder_bottom_val' => 'single', 'tblborder_bottom_sz' => 8, 'tblborder_bottom_space' => '0', 'tblborder_bottom_color' => 'FFFFFF', 'tblborder_bottom_themeColor' => 'background1',
            'tblborder_right_val' => 'single', 'tblborder_right_sz' => 8, 'tblborder_right_space' => '0', 'tblborder_right_color' => 'FFFFFF', 'tblborder_right_themeColor' => 'background1',
            'tblborder_insideH_val' => 'nil',
            'tblborder_insideV_val' => 'single', 'tblborder_insideV_sz' => 8, 'tblborder_insideV_space' => '0', 'tblborder_insideV_color' => 'FFFFFF', 'tblborder_insideV_themeColor' => 'background1',
            'shd_val' => 'clear', 'shd_color' => 'auto', 'shd_fill' => '4F81BD', 'shd_themeFill' => 'accent1');
        $arrStyleTable3 = array('type' => 'firstCol', 'b' => 1, 'bCs' => 1, 'i' => '0', 'iCs' => '0', 'color_val' => 'FFFFFF', 'color_themeColor' => 'background1', 'tblPr' => 1,
            'tblborder_left_val' => 'single', 'tblborder_left_sz' => 8, 'tblborder_left_space' => '0', 'tblborder_left_color' => 'FFFFFF', 'tblborder_left_themeColor' => 'background1',
            'tblborder_right_val' => 'single', 'tblborder_right_sz' => 24, 'tblborder_right_space' => '0', 'tblborder_right_color' => 'FFFFFF', 'tblborder_right_themeColor' => 'background1',
            'tblborder_insideH_val' => 'nil', 'tblborder_insideV_val' => 'nil', 'shd_val' => 'clear', 'shd_color' => 'auto', 'shd_fill' => '4F81BD', 'shd_themeFill' => 'accent1');

        $arrStyleTable4 = array('type' => 'lastCol', 'b' => 1, 'bCs' => 1, 'i' => '0', 'iCs' => '0', 'color_val' => 'FFFFFF', 'color_themeColor' => 'background1', 'tblPr' => 1,
            'tblborder_top_val' => 'nil', 'tblborder_left_val' => 'single', 'tblborder_left_sz' => 24, 'tblborder_left_space' => '0', 'tblborder_left_color' => 'FFFFFF', 'tblborder_left_themeColor' => 'background1',
            'tblborder_bottom_val' => 'nil', 'tblborder_right_val' => 'nil',
            'tblborder_insideH_val' => 'nil', 'tblborder_insideV_val' => 'nil', 'shd_val' => 'clear', 'shd_color' => 'auto', 'shd_fill' => '4F81BD', 'shd_themeFill' => 'accent1');

        $arrStyleTable5 = array('type' => 'band1Vert', 'tblPr' => 1,
            'tblborder_top_val' => 'single', 'tblborder_top_sz' => 8, 'tblborder_top_space' => '0', 'tblborder_top_color' => 'FFFFFF', 'tblborder_top_themeColor' => 'background1',
            'tblborder_left_val' => 'single', 'tblborder_left_sz' => 8, 'tblborder_left_space' => '0', 'tblborder_left_color' => 'FFFFFF', 'tblborder_left_themeColor' => 'background1',
            'tblborder_bottom_val' => 'single', 'tblborder_bottom_sz' => 8, 'tblborder_bottom_space' => '0', 'tblborder_bottom_color' => 'FFFFFF', 'tblborder_bottom_themeColor' => 'background1',
            'tblborder_right_val' => 'single', 'tblborder_right_sz' => 8, 'tblborder_right_space' => '0', 'tblborder_right_color' => 'FFFFFF', 'tblborder_right_themeColor' => 'background1',
            'tblborder_insideH_val' => 'nil', 'tblborder_insideV_val' => 'nil', 'shd_val' => 'clear', 'shd_color' => 'auto', 'shd_fill' => 'A7BFDE', 'shd_themeFill' => 'accent1', 'shd_themeFillTint' => '7F');

        $arrStyleTable6 = array('type' => 'band1Horz', 'tblPr' => 1,
            'tblborder_top_val' => 'single', 'tblborder_top_sz' => 8, 'tblborder_top_space' => '0', 'tblborder_top_color' => 'FFFFFF', 'tblborder_top_themeColor' => 'background1',
            'tblborder_left_val' => 'single', 'tblborder_left_sz' => 8, 'tblborder_left_space' => '0', 'tblborder_left_color' => 'FFFFFF', 'tblborder_left_themeColor' => 'background1',
            'tblborder_bottom_val' => 'single', 'tblborder_bottom_sz' => 8, 'tblborder_bottom_space' => '0', 'tblborder_bottom_color' => 'FFFFFF', 'tblborder_bottom_themeColor' => 'background1',
            'tblborder_right_val' => 'single', 'tblborder_right_sz' => 8, 'tblborder_right_space' => '0', 'tblborder_right_color' => 'FFFFFF', 'tblborder_right_themeColor' => 'background1',
            'tblborder_insideH_val' => 'single', 'tblborder_insideH_sz' => 8, 'tblborder_insideH_space' => '0', 'tblborder_insideH_color' => 'FFFFFF', 'tblborder_insideH_themeColor' => 'background1',
            'tblborder_insideV_val' => 'single', 'tblborder_insideV_sz' => 8, 'tblborder_insideV_space' => '0', 'tblborder_insideV_color' => 'FFFFFF', 'tblborder_insideV_themeColor' => 'background1',
            'shd_val' => 'clear', 'shd_color' => 'auto', 'shd_fill' => 'A7BFDE', 'shd_themeFill' => 'accent1', 'shd_themeFillTint' => '7F');

        $this->fAddStyle(array($arrParametros, $arrStyleTable1, $arrStyleTable2, $arrStyleTable3, $arrStyleTable4, $arrStyleTable5, $arrStyleTable6));
        $arrParametros = array('type' => 'character', 'styleId' => 'nfasis', 'name' => 'Emphasis', 'basedOn' => 'Fuentedeprrafopredeter', 'uiPriority' => '20', 'qFormat' => 1, 'rsid' => '005235DC',
            'i' => 1, 'iCs' => 1);
        $this->fAddStyle(array($arrParametros));

        $arrParametros = array('type' => 'table', 'styleId' => 'Sombreadomedio1', 'name' => 'Medium Shading 1', 'basedOn' => 'Tablanormal', 'uiPriority' => '63', 'rsid' => '00E559CE',
            'spacing_after' => '0', 'spacing_line' => '240', 'spacing_lineRule' => 'auto',
            'tblInd_w' => '0', 'tblInd_type' => 'dxa', 'top_w' => '0', 'top_type' => 'dxa', 'left_w' => '108', 'left_type' => 'dxa', 'bottom_w' => '0', 'bottom_type' => 'dxa',
            'right_w' => '108', 'right_type' => 'dxa', 'tbl_style_row' => 1, 'tbl_style_col' => 1,
            'tblborder_top_val' => 'single', 'tblborder_top_sz' => 8, 'tblborder_top_space' => '0', 'tblborder_top_color' => '404040', 'tblborder_top_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_left_val' => 'single', 'tblborder_left_sz' => 8, 'tblborder_left_space' => '0', 'tblborder_left_color' => '404040', 'tblborder_left_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_bottom_val' => 'single', 'tblborder_bottom_sz' => 8, 'tblborder_bottom_space' => '0', 'tblborder_bottom_color' => '404040', 'tblborder_bottom_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_right_val' => 'single', 'tblborder_right_sz' => 8, 'tblborder_right_space' => '0', 'tblborder_right_color' => '404040', 'tblborder_right_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_insideH_val' => 'single', 'tblborder_insideH_sz' => 8, 'tblborder_insideH_space' => '0', 'tblborder_insideH_color' => '404040', 'tblborder_insideH_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF');

        $arrStyleTable1 = array('type' => 'firstRow', 'spacing_before' => '0', 'spacing_after' => '0', 'spacing_line' => '240', 'spacing_lineRule' => 'auto', 'b' => 1, 'b' => 1, 'bCs' => 1, 'color_val' => 'FFFFFF', 'color_themeColor' => 'background1', 'tblPr' => 1,
            'tblborder_top_val' => 'single', 'tblborder_top_sz' => 8, 'tblborder_top_space' => '0', 'tblborder_top_color' => '404040', 'tblborder_top_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_left_val' => 'single', 'tblborder_left_sz' => 8, 'tblborder_left_space' => '0', 'tblborder_left_color' => '404040', 'tblborder_left_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_bottom_val' => 'single', 'tblborder_bottom_sz' => 8, 'tblborder_bottom_space' => '0', 'tblborder_bottom_color' => '404040', 'tblborder_bottom_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_right_val' => 'single', 'tblborder_right_sz' => 8, 'tblborder_right_space' => '0', 'tblborder_right_color' => '404040', 'tblborder_right_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_insideH_val' => 'nil', 'tblborder_insideV_val' => 'nil',
            'shd_val' => 'clear', 'shd_color' => 'auto', 'shd_fill' => '000000', 'shd_themeFill' => 'text1');

        $arrStyleTable2 = array('type' => 'firstRow', 'spacing_before' => '0', 'spacing_after' => '0', 'spacing_line' => '240', 'spacing_lineRule' => 'auto', 'b' => 1, 'b' => 1, 'bCs' => 1, 'tblPr' => 1,
            'tblborder_top_val' => 'double', 'tblborder_top_sz' => 6, 'tblborder_top_space' => '0', 'tblborder_top_color' => '404040', 'tblborder_top_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_left_val' => 'single', 'tblborder_left_sz' => 8, 'tblborder_left_space' => '0', 'tblborder_left_color' => '404040', 'tblborder_left_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_bottom_val' => 'single', 'tblborder_bottom_sz' => 8, 'tblborder_bottom_space' => '0', 'tblborder_bottom_color' => '404040', 'tblborder_bottom_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_right_val' => 'single', 'tblborder_right_sz' => 8, 'tblborder_right_space' => '0', 'tblborder_right_color' => '404040', 'tblborder_right_themeColor' => 'text1', 'tblborder_insideV_themeTint' => 'BF',
            'tblborder_insideH_val' => 'nil', 'tblborder_insideV_val' => 'nil');

        $arrStyleTable3 = array('type' => 'firstCol', 'b' => 1, 'bCs' => 1);
        $arrStyleTable4 = array('type' => 'lastCol', 'b' => 1, 'bCs' => 1);
        $arrStyleTable5 = array('type' => 'band1Vert', 'tblPr' => 1, 'shd_val' => 'clear', 'shd_color' => 'auto', 'shd_fill' => 'C0C0C0', 'shd_themeFill' => 'text1', 'shd_themeFillTint' => '3F');
        $arrStyleTable6 = array('type' => 'band1Horz', 'tblPr' => 1, 'tblborder_insideH_val' => 'nil', 'tblborder_insideV_val' => 'nil', 'shd_val' => 'clear', 'shd_color' => 'auto', 'shd_fill' => 'C0C0C0', 'shd_themeFill' => 'text1', 'shd_themeFillTint' => '3F');
        $arrStyleTable7 = array('type' => 'band1Horz', 'tblPr' => 1, 'tblborder_insideH_val' => 'nil', 'tblborder_insideV_val' => 'nil');

        $this->fAddStyle(array($arrParametros, $arrStyleTable1, $arrStyleTable2, $arrStyleTable3, $arrStyleTable4, $arrStyleTable5, $arrStyleTable6, $arrStyleTable7));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Ttulo4', 'name' => 'heading 4', 'basedOn' => 'Normal', 'next' => 'Normal', 'link' => 'Ttulo4Car', 'uiPriority' => '9',
            'unhideWhenUsed' => 1, 'qFormat' => 1, 'rsid' => '00C967D7', 'keepNext' => 1, 'keepLines' => 1, 'spacing_after' => '0', 'spacing_before' => '200', 'outlineLvl' => 3, 'rFonts_asciiTheme' => 'majorHAnsi',
            'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi', 'b' => 1, 'bCs' => 1, 'i' => 1, 'iCs' => 1, 'color_val' => '244061', 'color_themeColor' => 'accent1', 'color_themeShade' => '80');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'character', 'customStyle' => '1', 'styleId' => 'Ttulo4Car', 'name' => 'Titulo 4 Car', 'basedOn' => 'Fuentedeprrafopredeter', 'link' => 'Ttulo4',
            'uiPriority' => '9', 'rsid' => '00C967D7', 'rFonts_asciiTheme' => 'majorHAnsi', 'rFonts_eastAsiaTheme' => 'majorEastAsia', 'rFonts_hAnsiTheme' => 'majorHAnsi', 'rFonts_cstheme' => 'majorBidi',
            'b' => 1, 'bCs' => 1, 'i' => 1, 'iCs' => 1, 'color_val' => '244061', 'color_themeColor' => 'accent1', 'color_themeShade' => '80', 'sz' => '24');
        $this->fAddStyle(array($arrParametros));
        $arrParametros = array('type' => 'paragraph', 'styleId' => 'Textonotaalfinal', 'name' => 'endnote text', 'basedOn' => 'Normal', 'link' => 'TextonotaalfinalCar', 'semiHidden' => 1,
            'uiPriority' => '99', 'unhideWhenUsed' => 1, 'rsid' => '00684540', 'spacing_after' => '0', 'spacing_line' => '240', 'spacing_lineRule' => 'auto', 'sz' => '20', 'szCs' => '20');
        $this->fAddStyle(array($arrParametros));

        $arrParametros = array('type' => 'character', 'customStyle' => '1', 'styleId' => 'TextonotaalfinalCar', 'name' => 'Texto nota al final Car', 'basedOn' => 'Fuentedeprrafopredeter', 'link' => 'Textonotaalfinal',
            'semiHidden' => 1, 'uiPriority' => '99', 'rsid' => '00684540', 'sz' => '20', 'szCs' => '20');
        $this->fAddStyle(array($arrParametros));

        $arrParametros = array('type' => 'character', 'styleId' => 'Refdenotaalfinal', 'name' => 'endnote reference', 'basedOn' => 'Fuentedeprrafopredeter', 'semiHidden' => 1,
            'uiPriority' => '99', 'unhideWhenUsed' => 1, 'rsid' => '00684540', 'vertAlign' => 'superscript');
        $this->fAddStyle(array($arrParametros));
    }

    public function fAddStyleTabla($arrParam) {
        $objStyle = cCreateStyleTable::getInstance();
        $objStyle->fAddStyleTable($arrParam);
        $this->xml = str_replace('__GENERATESTYLE__', (string) $objStyle, $this->xml);
    }

}
?>