<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateTheme1 extends cCreateElement {

    static private $rscInstance = NULL;
    const NAMESPACEWORD = 'a';
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
            self::$rscInstance = new cCreateTheme1();
        }
        return self::$rscInstance;
    }

    protected function fGenerateTHEMEELEMENTS() {
        $this->xml = '<' . cCreateTheme1::NAMESPACEWORD . ':themeElements>__GENERATETHEMEELEMENTS1____GENERATETHEMEELEMENTS2____GENERATETHEMEELEMENTS3__</' . cCreateTheme1::NAMESPACEWORD . ':themeElements>__GENERATETHEMEELEMENTS4__';
    }

    protected function fGenerateCLRSCHEME($name= 'Office') {
        $this->xml = str_replace('__GENERATETHEMEELEMENTS1__', '<' . cCreateTheme1::NAMESPACEWORD . ':clrScheme name="' . $name . '">__GENERATECLRSCHEME__</' . cCreateTheme1::NAMESPACEWORD . ':clrScheme>', $this->xml);
    }

    protected function fGenerateDK1() {
        $this->xml = str_replace('__GENERATECLRSCHEME__', '<' . cCreateTheme1::NAMESPACEWORD . ':dk1>__GENERATESYSCLR__</' . cCreateTheme1::NAMESPACEWORD . ':dk1>__GENERATEDK1__', $this->xml);
    }

    protected function fGenerateSYSCLR($val = 'windowText', $lastClr = '000000') {
        $this->xml = str_replace('__GENERATESYSCLR__', '<' . cCreateTheme1::NAMESPACEWORD . ':sysClr val="' . $val . '" lastClr="' . $lastClr . '"></' . cCreateTheme1::NAMESPACEWORD . ':sysClr>', $this->xml);
    }

    protected function fGenerateLT1() {
        $this->xml = str_replace('__GENERATEDK1__', '<' . cCreateTheme1::NAMESPACEWORD . ':lt1>__GENERATESYSCLR__</' . cCreateTheme1::NAMESPACEWORD . ':lt1>__GENERATELT1__', $this->xml);
    }

    protected function fGenerateDK2() {
        $this->xml = str_replace('__GENERATELT1__', '<' . cCreateTheme1::NAMESPACEWORD . ':dk2>__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':dk2>__GENERATEDK2__', $this->xml);
    }

    protected function fGenerateSRGBCLR($val = 'windowText') {
        $this->xml = str_replace('__GENERATESRGBCLR__', '<' . cCreateTheme1::NAMESPACEWORD . ':srgbClr val="' . $val . '"></' . cCreateTheme1::NAMESPACEWORD . ':srgbClr>', $this->xml);
    }

    protected function fGenerateLT2() {
        $this->xml = str_replace('__GENERATEDK2__', '<' . cCreateTheme1::NAMESPACEWORD . ':lt2>__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':lt2>__GENERATELT2__', $this->xml);
    }

    protected function fGenerateACCENT1() {
        $this->xml = str_replace('__GENERATELT2__', '<' . cCreateTheme1::NAMESPACEWORD . ':accent1>__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':accent1>__GENERATEACCENT1__', $this->xml);
    }

    protected function fGenerateACCENT2() {
        $this->xml = str_replace('__GENERATEACCENT1__', '<' . cCreateTheme1::NAMESPACEWORD . ':accent2>__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':accent2>__GENERATEACCENT2__', $this->xml);
    }

    protected function fGenerateACCENT3() {
        $this->xml = str_replace('__GENERATEACCENT2__', '<' . cCreateTheme1::NAMESPACEWORD . ':accent3>__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':accent3>__GENERATEACCENT3__', $this->xml);
    }

    protected function fGenerateACCENT4() {
        $this->xml = str_replace('__GENERATEACCENT3__', '<' . cCreateTheme1::NAMESPACEWORD . ':accent4>__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':accent4>__GENERATEACCENT4__', $this->xml);
    }

    protected function fGenerateACCENT5() {
        $this->xml = str_replace('__GENERATEACCENT4__', '<' . cCreateTheme1::NAMESPACEWORD . ':accent5>__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':accent5>__GENERATEACCENT5__', $this->xml);
    }

    protected function fGenerateACCENT6() {
        $this->xml = str_replace('__GENERATEACCENT5__', '<' . cCreateTheme1::NAMESPACEWORD . ':accent6>__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':accent6>__GENERATEACCENT6__', $this->xml);
    }

    protected function fGenerateHLINK() {
        $this->xml = str_replace('__GENERATEACCENT6__', '<' . cCreateTheme1::NAMESPACEWORD . ':hlink>__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':hlink>__GENERATEHLINK__', $this->xml);
    }

    protected function fGenerateFOLHLINK() {
        $this->xml = str_replace('__GENERATEHLINK__', '<' . cCreateTheme1::NAMESPACEWORD . ':folHlink>__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':folHlink>', $this->xml);
    }

    protected function fGenerateFONTSCHEMA($name = 'Office') {
        $this->xml = str_replace('__GENERATETHEMEELEMENTS2__', '<' . cCreateTheme1::NAMESPACEWORD . ':fontScheme name="' . $name . '">__GENERATEFONTSCHEMA1____GENERATEFONTSCHEMA2__</' . cCreateTheme1::NAMESPACEWORD . ':fontScheme>', $this->xml);
    }

    protected function fGenerateMAYORFONT() {
        $this->xml = str_replace('__GENERATEFONTSCHEMA1__', '<' . cCreateTheme1::NAMESPACEWORD . ':majorFont>__GENERATEMAYORFONT__</' . cCreateTheme1::NAMESPACEWORD . ':majorFont>', $this->xml);
    }

    protected function fGenerateLATIN($typeface = 'cambia') {
        $this->xml = str_replace('__GENERATEMAYORFONT__', '<' . cCreateTheme1::NAMESPACEWORD . ':latin typeface="' . $typeface . '"></' . cCreateTheme1::NAMESPACEWORD . ':latin>__GENERATELATIN__', $this->xml);
    }

    protected function fGenerateEA($typeface = '') {
        $this->xml = str_replace('__GENERATELATIN__', '<' . cCreateTheme1::NAMESPACEWORD . ':ea typeface="' . $typeface . '"></' . cCreateTheme1::NAMESPACEWORD . ':ea>__GENERATEEA__', $this->xml);
    }

    protected function fGenerateCS($typeface = '') {
        $this->xml = str_replace('__GENERATEEA__', '<' . cCreateTheme1::NAMESPACEWORD . ':cs typeface="' . $typeface . '"></' . cCreateTheme1::NAMESPACEWORD . ':cs>__GENERATECS__', $this->xml);
    }

    protected function fGenerateFONT($script = '', $typeface = '') {
        $this->xml = str_replace('__GENERATECS__', '<' . cCreateTheme1::NAMESPACEWORD . ':font script="' . $script . '" typeface="' . $typeface . '"></' . cCreateTheme1::NAMESPACEWORD . ':font>__GENERATEFONT__', $this->xml);
    }

    protected function fGenerateFONT2($script = '', $typeface = '') {
        $this->xml = str_replace('__GENERATEFONT__', '<' . cCreateTheme1::NAMESPACEWORD . ':font script="' . $script . '" typeface="' . $typeface . '"></' . cCreateTheme1::NAMESPACEWORD . ':font>__GENERATEFONT__', $this->xml);
    }

    protected function fGenerateFONT3($script = '', $typeface = '') {
        $this->xml = str_replace('__GENERATEFONT__', '<' . cCreateTheme1::NAMESPACEWORD . ':font script="' . $script . '" typeface="' . $typeface . '"></' . cCreateTheme1::NAMESPACEWORD . ':font>', $this->xml);
    }

    protected function fGenerateMINORFONT() {
        $this->xml = str_replace('__GENERATEFONTSCHEMA2__', '<' . cCreateTheme1::NAMESPACEWORD . ':minorFont>__GENERATEMAYORFONT__</' . cCreateTheme1::NAMESPACEWORD . ':minorFont>', $this->xml);
    }

    protected function fGenerateFMTSCHEME($name) {
        $this->xml = str_replace('__GENERATETHEMEELEMENTS3__', '<' . cCreateTheme1::NAMESPACEWORD . ':fmtScheme name="' . $name . '">__GENERATEFMTSCHEME__</' . cCreateTheme1::NAMESPACEWORD . ':fmtScheme>', $this->xml);
    }

    protected function fGenerateFILLSTYLELST() {
        $this->xml = str_replace('__GENERATEFMTSCHEME__', '<' . cCreateTheme1::NAMESPACEWORD . ':fillStyleLst>__GENERATEFILLSTYLELST__</' . cCreateTheme1::NAMESPACEWORD . ':fillStyleLst>__GENERATEFILLSTYLELST2__', $this->xml);
    }

    protected function fGenerateSOLIDFILL() {
        $this->xml = str_replace('__GENERATEFILLSTYLELST__', '<' . cCreateTheme1::NAMESPACEWORD . ':solidFill>__GENERATESOLIDFILL__</' . cCreateTheme1::NAMESPACEWORD . ':solidFill>__GENERATESOLIDFILL2__', $this->xml);
    }

    protected function fGenerateSCHEMECLR($val) {
        $this->xml = str_replace('__GENERATESOLIDFILL__', '<' . cCreateTheme1::NAMESPACEWORD . ':schemeClr val="' . $val . '"></' . cCreateTheme1::NAMESPACEWORD . ':schemeClr>', $this->xml);
    }

    protected function fGenerateGRADFILL($rotWithShape) {
        $this->xml = str_replace('__GENERATESOLIDFILL2__', '<' . cCreateTheme1::NAMESPACEWORD . ':gradFill rotWithShape="' . $rotWithShape . '">__GENERATEGRADFILL__</' . cCreateTheme1::NAMESPACEWORD . ':gradFill>__GENERATESOLIDFILL2__', $this->xml);
    }

    protected function fGenerateGRADFILL2($rotWithShape) {
        $this->xml = str_replace('__GENERATESOLIDFILL2__', '<' . cCreateTheme1::NAMESPACEWORD . ':gradFill rotWithShape="' . $rotWithShape . '">__GENERATEGRADFILL__</' . cCreateTheme1::NAMESPACEWORD . ':gradFill>', $this->xml);
    }

    protected function fGenerateGSLST() {
        $this->xml = str_replace('__GENERATEGRADFILL__', '<' . cCreateTheme1::NAMESPACEWORD . ':gsLst>__GENERATEGSLST__</' . cCreateTheme1::NAMESPACEWORD . ':gsLst>__GENERATEGSLST2__', $this->xml);
    }

    protected function fGenerateGS($pos) {
        $this->xml = str_replace('__GENERATEGSLST__', '<' . cCreateTheme1::NAMESPACEWORD . ':gs pos="' . $pos . '">__GENERATEPOS__</' . cCreateTheme1::NAMESPACEWORD . ':gs>__GENERATEGSLST__', $this->xml);
    }

    protected function fGenerateGS2($pos) {
        $this->xml = str_replace('__GENERATEGSLST__', '<' . cCreateTheme1::NAMESPACEWORD . ':gs pos="' . $pos . '">__GENERATEPOS__</' . cCreateTheme1::NAMESPACEWORD . ':gs>', $this->xml);
    }

    protected function fGenerateSCHEMECLR2($val) {
        $this->xml = str_replace('__GENERATEPOS__', '<' . cCreateTheme1::NAMESPACEWORD . ':schemeClr val="' . $val . '">__GENERATESCHEMECLR2__</' . cCreateTheme1::NAMESPACEWORD . ':schemeClr>', $this->xml);
    }

    protected function fGenerateTINT($val) {
        $this->xml = str_replace('__GENERATESCHEMECLR2__', '<' . cCreateTheme1::NAMESPACEWORD . ':tint val="' . $val . '"></' . cCreateTheme1::NAMESPACEWORD . ':tint>__GENERATETINT__', $this->xml);
    }

    protected function fGenerateSHADE($val) {
        $this->xml = str_replace('__GENERATESCHEMECLR2__', '<' . cCreateTheme1::NAMESPACEWORD . ':shade val="' . $val . '"></' . cCreateTheme1::NAMESPACEWORD . ':shade>__GENERATETINT__', $this->xml);
    }

    protected function fGenerateSATMOD($val) {
        $this->xml = str_replace('__GENERATETINT__', '<' . cCreateTheme1::NAMESPACEWORD . ':satMod val="' . $val . '"></' . cCreateTheme1::NAMESPACEWORD . ':satMod>', $this->xml);
    }

    protected function fGenerateLIN($ang, $scaled) {
        $this->xml = str_replace('__GENERATEGSLST2__', '<' . cCreateTheme1::NAMESPACEWORD . ':lin ang="' . $ang . '" scaled="' . $scaled . '"></' . cCreateTheme1::NAMESPACEWORD . ':lin>', $this->xml);
    }

    protected function fGenerateLNSTYLELST() {
        $this->xml = str_replace('__GENERATEFILLSTYLELST2__', '<' . cCreateTheme1::NAMESPACEWORD . ':lnStyleLst>__GENERATELNSTYLELST__</' . cCreateTheme1::NAMESPACEWORD . ':lnStyleLst>__GENERATELNSTYLELST2__', $this->xml);
    }

    protected function fGenerateLN($w, $cap, $cmpd, $algn) {
        $this->xml = str_replace('__GENERATELNSTYLELST__', '<' . cCreateTheme1::NAMESPACEWORD . ':ln w="' . $w . '" cap="' . $cap . '" cmpd="' . $cmpd . '" algn="' . $algn . '">__GENERATEFILLSTYLELST__</' . cCreateTheme1::NAMESPACEWORD . ':ln>__GENERATELNSTYLELST__', $this->xml);
    }

    protected function fGenerateLN2($w, $cap, $cmpd, $algn) {
        $this->xml = str_replace('__GENERATELNSTYLELST__', '<' . cCreateTheme1::NAMESPACEWORD . ':ln w="' . $w . '" cap="' . $cap . '" cmpd="' . $cmpd . '" algn="' . $algn . '">__GENERATEFILLSTYLELST__</' . cCreateTheme1::NAMESPACEWORD . ':ln>', $this->xml);
    }

    //fGenerateSOLIDFILL

    protected function fGenerateSCHEMECLR3($val) {
        $this->xml = str_replace('__GENERATESOLIDFILL__', '<' . cCreateTheme1::NAMESPACEWORD . ':schemeClr val="' . $val . '">__GENERATESCHEMECLR2__</' . cCreateTheme1::NAMESPACEWORD . ':schemeClr>', $this->xml);
    }

    protected function fGeneratePRSTDASH($val) {
        $this->xml = str_replace('__GENERATESOLIDFILL2__', '<' . cCreateTheme1::NAMESPACEWORD . ':prstDash val="' . $val . '"></' . cCreateTheme1::NAMESPACEWORD . ':prstDash>', $this->xml);
    }

    protected function fGenerateEFFECTSTYLELST() {
        $this->xml = str_replace('__GENERATELNSTYLELST2__', '<' . cCreateTheme1::NAMESPACEWORD . ':effectStyleLst>__GENERATEEFFECTSTYLELST__</' . cCreateTheme1::NAMESPACEWORD . ':effectStyleLst>__GENERATEEFFECTSTYLELST2__', $this->xml);
    }

    protected function fGenerateEFFECTSTYLE() {
        $this->xml = str_replace('__GENERATEEFFECTSTYLELST__', '<' . cCreateTheme1::NAMESPACEWORD . ':effectStyle>__GENERATEEFFECTSTYLE__</' . cCreateTheme1::NAMESPACEWORD . ':effectStyle>__GENERATEEFFECTSTYLELST__', $this->xml);
    }

    protected function fGenerateEFFECTSTYLE2() {
        $this->xml = str_replace('__GENERATEEFFECTSTYLELST__', '<' . cCreateTheme1::NAMESPACEWORD . ':effectStyle>__GENERATEEFFECTSTYLE__</' . cCreateTheme1::NAMESPACEWORD . ':effectStyle>', $this->xml);
    }

    protected function fGenerateEFFECTLST() {
        $this->xml = str_replace('__GENERATEEFFECTSTYLE__', '<' . cCreateTheme1::NAMESPACEWORD . ':effectLst>__GENERATEEFFECTLST__</' . cCreateTheme1::NAMESPACEWORD . ':effectLst>', $this->xml);
    }

    protected function fGenerateOUTERSHDW($blurRad, $dist, $dir, $rotWithShape) {
        $this->xml = str_replace('__GENERATEEFFECTLST__', '<' . cCreateTheme1::NAMESPACEWORD . ':outerShdw blurRad="' . $blurRad . '" dist="' . $dist . '" dir="' . $dir . '" rotWithShape="' . $rotWithShape . '">__GENERATEOUTERSHDW__</' . cCreateTheme1::NAMESPACEWORD . ':outerShdw>', $this->xml);
    }

    protected function fGenerateSRGBCLR2($val) {
        $this->xml = str_replace('__GENERATEOUTERSHDW__', '<' . cCreateTheme1::NAMESPACEWORD . ':srgbClr val="' . $val . '">__GENERATESRGBCLR__</' . cCreateTheme1::NAMESPACEWORD . ':srgbClr>', $this->xml);
    }

    protected function fGenerateALPHA($val) {
        $this->xml = str_replace('__GENERATESRGBCLR__', '<' . cCreateTheme1::NAMESPACEWORD . ':alpha val="' . $val . '"></' . cCreateTheme1::NAMESPACEWORD . ':alpha>', $this->xml);
    }

    protected function fGenerateEFFECTLST2() {
        $this->xml = str_replace('__GENERATEEFFECTSTYLE__', '<' . cCreateTheme1::NAMESPACEWORD . ':effectLst>__GENERATEEFFECTLST__</' . cCreateTheme1::NAMESPACEWORD . ':effectLst>__GENERATEEFFECTLST2__', $this->xml);
    }

    protected function fGenerateSCENE3D() {
        $this->xml = str_replace('__GENERATEEFFECTLST2__', '<' . cCreateTheme1::NAMESPACEWORD . ':scene3d>__GENERATESCENE3D__</' . cCreateTheme1::NAMESPACEWORD . ':scene3d>__GENERATESCENE3D2__', $this->xml);
    }

    protected function fGenerateCAMERA($prst) {
        $this->xml = str_replace('__GENERATESCENE3D__', '<' . cCreateTheme1::NAMESPACEWORD . ':camera prst="' . $prst . '">__GENERATECAMERA__</' . cCreateTheme1::NAMESPACEWORD . ':camera>__GENERATECAMERA2__', $this->xml);
    }

    protected function fGenerateROT($lat, $lon, $rev) {
        $this->xml = str_replace('__GENERATECAMERA__', '<' . cCreateTheme1::NAMESPACEWORD . ':rot lat="' . $lat . '" lon="' . $lon . '" rev="' . $rev . '"></' . cCreateTheme1::NAMESPACEWORD . ':rot>', $this->xml);
    }

    protected function fGenerateLIGHTRIG($rig, $dir) {
        $this->xml = str_replace('__GENERATECAMERA2__', '<' . cCreateTheme1::NAMESPACEWORD . ':lightRig rig="' . $rig . '" dir="' . $dir . '">__GENERATECAMERA__</' . cCreateTheme1::NAMESPACEWORD . ':lightRig>', $this->xml);
    }

    protected function fGenerateSP3D() {
        $this->xml = str_replace('__GENERATESCENE3D2__', '<' . cCreateTheme1::NAMESPACEWORD . ':sp3d>__GENERATESP3D__</' . cCreateTheme1::NAMESPACEWORD . ':sp3d>', $this->xml);
    }

    protected function fGenerateBEVELT($w, $h) {
        $this->xml = str_replace('__GENERATESP3D__', '<' . cCreateTheme1::NAMESPACEWORD . ':bevelT w="' . $w . '" h="' . $h . '"></' . cCreateTheme1::NAMESPACEWORD . ':bevelT>', $this->xml);
    }

    protected function fGenerateBGFILLSTYLELST() {
        $this->xml = str_replace('__GENERATEEFFECTSTYLELST2__', '<' . cCreateTheme1::NAMESPACEWORD . ':bgFillStyleLst>__GENERATEFILLSTYLELST__</' . cCreateTheme1::NAMESPACEWORD . ':bgFillStyleLst>', $this->xml);
    }

    protected function fGenerateTINT2($val) {
        $this->xml = str_replace('__GENERATESCHEMECLR2__', '<' . cCreateTheme1::NAMESPACEWORD . ':tint val="' . $val . '"></' . cCreateTheme1::NAMESPACEWORD . ':tint>__GENERATESCHEMECLR2__', $this->xml);
    }

    protected function fGeneratePATH($path) {
        $this->xml = str_replace('__GENERATEGSLST2__', '<' . cCreateTheme1::NAMESPACEWORD . ':path path="' . $path . '">__GENERATEPATH__</' . cCreateTheme1::NAMESPACEWORD . ':path>', $this->xml);
    }

    protected function fGenerateFILLTORECT($l, $t, $r, $b) {
        $this->xml = str_replace('__GENERATEPATH__', '<' . cCreateTheme1::NAMESPACEWORD . ':fillToRect l="' . $l . '" t="' . $t . '" r="' . $r . '" b="' . $b . '"></' . cCreateTheme1::NAMESPACEWORD . ':fillToRect>', $this->xml);
    }

    protected function fGenerateOBJECTDEFAULTS() {
        $this->xml = str_replace('__GENERATETHEMEELEMENTS4__', '<' . cCreateTheme1::NAMESPACEWORD . ':objectDefaults></' . cCreateTheme1::NAMESPACEWORD . ':objectDefaults>__GENERATETHEMEELEMENTS4__', $this->xml);
    }

    protected function fGenerateEXTRACLRSCHEMELST() {
        $this->xml = str_replace('__GENERATETHEMEELEMENTS4__', '<' . cCreateTheme1::NAMESPACEWORD . ':extraClrSchemeLst></' . cCreateTheme1::NAMESPACEWORD . ':extraClrSchemeLst>', $this->xml);
    }

    public function fCreateTheme($strFont) {

        $this->xml = '';
        $this->fGenerateTHEMEELEMENTS();
        $this->fGenerateCLRSCHEME('Office');
        $this->fGenerateDK1();
        $this->fGenerateSYSCLR("windowText", "000000");
        $this->fGenerateLT1();
        $this->fGenerateSYSCLR("window", "FFFFFF");
        $this->fGenerateDK2();
        $this->fGenerateSRGBCLR('1F497D');
        $this->fGenerateLT2();
        $this->fGenerateSRGBCLR('EEECE1');
        $this->fGenerateACCENT1();
        $this->fGenerateSRGBCLR('4F81BD');
        $this->fGenerateACCENT2();
        $this->fGenerateSRGBCLR('C0504D');
        $this->fGenerateACCENT3();
        $this->fGenerateSRGBCLR('9BBB59');
        $this->fGenerateACCENT4();
        $this->fGenerateSRGBCLR('8064A2');
        $this->fGenerateACCENT5();
        $this->fGenerateSRGBCLR('4BACC6');
        $this->fGenerateACCENT6();
        $this->fGenerateSRGBCLR('F79646');
        $this->fGenerateHLINK();
        $this->fGenerateSRGBCLR('0000FF');
        $this->fGenerateFOLHLINK();
        $this->fGenerateSRGBCLR('800080');
        if ($strFont != '') {
            $this->fGenerateFONTSCHEMA('Office');
            $this->fGenerateMAYORFONT();
            $this->fGenerateLATIN($strFont);
            $this->fGenerateEA('');
            $this->fGenerateCS('');
            $this->fGenerateMINORFONT();
            $this->fGenerateLATIN($strFont);
            $this->fGenerateEA('');
            $this->fGenerateCS('');
        }
        else {
            $this->fGenerateFONTSCHEMA('Office');
            $this->fGenerateMAYORFONT();
            $this->fGenerateLATIN('Cambria');
            $this->fGenerateEA('');
            $this->fGenerateCS('');
            $this->fGenerateFONT('Jpan', 'ＭＳ 明朝');
            $this->fGenerateFONT2('Hang', '맑은 고딕');
            $this->fGenerateFONT2('Hans', '宋体');
            $this->fGenerateFONT2('Hant', '新細明體');
            $this->fGenerateFONT2('Arab', 'Times New Roman');
            $this->fGenerateFONT2('Hebr', 'Times New Roman');
            $this->fGenerateFONT2('Thai', 'Angsana New');
            $this->fGenerateFONT2('Ethi', 'Nyala');
            $this->fGenerateFONT2('Beng', 'Vrinda');
            $this->fGenerateFONT2('Gujr', 'Shruti');
            $this->fGenerateFONT2('Khmr', 'MoolBoran');
            $this->fGenerateFONT2('Knda', 'Tunga');
            $this->fGenerateFONT2('Guru', 'Raavi');
            $this->fGenerateFONT2('Cans', 'Euphemia');
            $this->fGenerateFONT2('Cher', 'Plantagenet Cherokee');
            $this->fGenerateFONT2('Yiii', 'Microsoft Yi Baiti');
            $this->fGenerateFONT2('Tibt', 'Microsoft Himalaya');
            $this->fGenerateFONT2('Thaa', 'MV Boli');
            $this->fGenerateFONT2('Deva', 'Mangal');
            $this->fGenerateFONT2('Telu', 'Gautami');
            $this->fGenerateFONT2('Taml', 'Latha');
            $this->fGenerateFONT2('Syrc', 'Estrangelo Edessa');
            $this->fGenerateFONT2('Orya', 'Kalinga');
            $this->fGenerateFONT2('Mlym', 'Kartika');
            $this->fGenerateFONT2('Laoo', 'DokChampa');
            $this->fGenerateFONT2('Sinh', 'Iskoola Pota');
            $this->fGenerateFONT2('Mong', 'Mongolian Baiti');
            $this->fGenerateFONT2('Viet', 'Times New Roman');
            $this->fGenerateFONT3('Uigh', 'Microsoft Uighur');
            $this->fGenerateMINORFONT();
            $this->fGenerateLATIN('Calibri');
            $this->fGenerateEA('');
            $this->fGenerateCS('');
            $this->fGenerateFONT('Jpan', 'ＭＳ 明朝');
            $this->fGenerateFONT2('Hang', '맑은 고딕');
            $this->fGenerateFONT2('Hans', '宋体');
            $this->fGenerateFONT2('Hant', '新細明體');
            $this->fGenerateFONT2('Arab', 'Arial');
            $this->fGenerateFONT2('Hebr', 'Arial');
            $this->fGenerateFONT2('Thai', 'Cordia New');
            $this->fGenerateFONT2('Ethi', 'Nyala');
            $this->fGenerateFONT2('Beng', 'Vrinda');
            $this->fGenerateFONT2('Gujr', 'Shruti');
            $this->fGenerateFONT2('Khmr', 'DaunPenh');
            $this->fGenerateFONT2('Knda', 'Tunga');
            $this->fGenerateFONT2('Guru', 'Raavi');
            $this->fGenerateFONT2('Cans', 'Euphemia');
            $this->fGenerateFONT2('Cher', 'Plantagenet Cherokee');
            $this->fGenerateFONT2('Yiii', 'Microsoft Yi Baiti');
            $this->fGenerateFONT2('Tibt', 'Microsoft Himalaya');
            $this->fGenerateFONT2('Thaa', 'MV Boli');
            $this->fGenerateFONT2('Deva', 'Mangal');
            $this->fGenerateFONT2('Telu', 'Gautami');
            $this->fGenerateFONT2('Taml', 'Latha');
            $this->fGenerateFONT2('Syrc', 'Estrangelo Edessa');
            $this->fGenerateFONT2('Orya', 'Kalinga');
            $this->fGenerateFONT2('Mlym', 'Kartika');
            $this->fGenerateFONT2('Laoo', 'DokChampa');
            $this->fGenerateFONT2('Sinh', 'Iskoola Pota');
            $this->fGenerateFONT2('Mong', 'Mongolian Baiti');
            $this->fGenerateFONT2('Viet', 'Arial');
            $this->fGenerateFONT3('Uigh', 'Microsoft Uighur');
        }
        $this->fGenerateFMTSCHEME('Office');
        $this->fGenerateFILLSTYLELST();
        $this->fGenerateSOLIDFILL();
        $this->fGenerateSCHEMECLR('phClr');
        $this->fGenerateGRADFILL(1);
        $this->fGenerateGSLST();
        $this->fGenerateGS(0);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateTINT('50000');
        $this->fGenerateSATMOD('300000');
        $this->fGenerateGS(35000);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateTINT(37000);
        $this->fGenerateSATMOD(300000);
        $this->fGenerateGS2(100000);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateTINT(15000);
        $this->fGenerateSATMOD(350000);
        $this->fGenerateLIN(16200000, 1);

        $this->fGenerateGRADFILL2(1);
        $this->fGenerateGSLST();
        $this->fGenerateGS(0);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateSHADE('51000');
        $this->fGenerateSATMOD('130000');
        $this->fGenerateGS(80000);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateSHADE(93000);
        $this->fGenerateSATMOD(130000);
        $this->fGenerateGS2(100000);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateSHADE(94000);
        $this->fGenerateSATMOD(135000);
        $this->fGenerateLIN(16200000, 0);

        $this->fGenerateLNSTYLELST();
        $this->fGenerateLN(9525, "flat", "sng", "ctr");
        $this->fGenerateSOLIDFILL();
        $this->fGenerateSCHEMECLR3('phClr');
        $this->fGenerateSHADE('95000');
        $this->fGenerateSATMOD('105000');
        $this->fGeneratePRSTDASH('solid');
        $this->fGenerateLN(25400, "flat", "sng", "ctr");
        $this->fGenerateSOLIDFILL();
        $this->fGenerateSCHEMECLR('phClr');
        $this->fGeneratePRSTDASH('solid');
        $this->fGenerateLN2(38100, 'flat', 'sng', 'ctr');
        $this->fGenerateSOLIDFILL();
        $this->fGenerateSCHEMECLR('phClr');
        $this->fGeneratePRSTDASH('solid');

        $this->fGenerateEFFECTSTYLELST();
        $this->fGenerateEFFECTSTYLE();
        $this->fGenerateEFFECTLST();
        $this->fGenerateOUTERSHDW(40000, 20000, 5400000, 0);
        $this->fGenerateSRGBCLR2('000000');
        $this->fGenerateALPHA(38000);
        $this->fGenerateEFFECTSTYLE();
        $this->fGenerateEFFECTLST();
        $this->fGenerateOUTERSHDW(40000, 23000, 5400000, 0);
        $this->fGenerateSRGBCLR2('000000');
        $this->fGenerateALPHA(35000);
        $this->fGenerateEFFECTSTYLE2();
        $this->fGenerateEFFECTLST2();
        $this->fGenerateOUTERSHDW(40000, 23000, 5400000, 0);
        $this->fGenerateSRGBCLR2('000000');
        $this->fGenerateALPHA(35000);

        $this->fGenerateSCENE3D();
        $this->fGenerateCAMERA('orthographicFront');
        $this->fGenerateROT(0, 0, 0);
        $this->fGenerateLIGHTRIG('threePt', 't');
        $this->fGenerateROT(0, 0, 1200000);
        $this->fGenerateSP3D();
        $this->fGenerateBEVELT(63500, 25400);
        //revisar los datos apartir de aki!!!
        $this->fGenerateBGFILLSTYLELST();
        $this->fGenerateSOLIDFILL();
        $this->fGenerateSCHEMECLR('phClr');
        $this->fGenerateGRADFILL(1);
        $this->fGenerateGSLST();
        $this->fGenerateGS(0);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateTINT('40000');
        $this->fGenerateSATMOD('350000');
        $this->fGenerateGS(40000);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateTINT2(45000);
        $this->fGenerateSHADE(99000);
        $this->fGenerateSATMOD(350000);
        $this->fGenerateGS2(100000);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateSHADE(20000);
        $this->fGenerateSATMOD(255000);
        $this->fGeneratePATH('circle');
        $this->fGenerateFILLTORECT(50000, '-80000', 50000, 180000);

        $this->fGenerateGRADFILL2(1);
        $this->fGenerateGSLST();
        $this->fGenerateGS(0);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateTINT('80000');
        $this->fGenerateSATMOD('300000');
        $this->fGenerateGS2(100000);
        $this->fGenerateSCHEMECLR2('phClr');
        $this->fGenerateSHADE(30000);
        $this->fGenerateSATMOD(200000);
        $this->fGeneratePATH('circle');
        $this->fGenerateFILLTORECT(50000, 50000, 50000, 50000);
        $this->fGenerateOBJECTDEFAULTS();
        $this->fGenerateEXTRACLRSCHEMELST();
        $this->fCleanTemplate();
    }

}
?>