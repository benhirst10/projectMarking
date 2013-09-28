<?php
  /**
   * @author 2mdc.com
   * @version 
   */

include_once dirname(__FILE__) . '/cCreateElement.inc';

define("THEME1NAMESPACE", 'a');

  class cCreateTheme1 extends cCreateElement {
    var $rscInstance = NULL;    
    var $xml;

    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateTheme1();
       }
       return $this->rscInstance;
    }
    
    function fGenerateTHEMEELEMENTS(){
      $this->xml = '<'.THEME1NAMESPACE.':themeElements>__GENERATETHEMEELEMENTS1____GENERATETHEMEELEMENTS2____GENERATETHEMEELEMENTS3__</'.THEME1NAMESPACE.':themeElements>__GENERATETHEMEELEMENTS4__';
    }
    
    
    function fGenerateCLRSCHEME($name= 'Office'){
      $this->xml = str_replace('__GENERATETHEMEELEMENTS1__', '<'.THEME1NAMESPACE.':clrScheme name="' . $name . '">__GENERATECLRSCHEME__</'.THEME1NAMESPACE.':clrScheme>', $this->xml);
    }
    
    function fGenerateDK1() {
       	$this->xml = str_replace('__GENERATECLRSCHEME__', '<'.THEME1NAMESPACE.':dk1>__GENERATESYSCLR__</'.THEME1NAMESPACE.':dk1>__GENERATEDK1__', $this->xml);
    }
    
    function fGenerateSYSCLR($val = 'windowText', $lastClr = '000000') {
       	$this->xml = str_replace('__GENERATESYSCLR__', '<'.THEME1NAMESPACE.':sysClr val="' . $val . '" lastClr="' . $lastClr . '"></'.THEME1NAMESPACE.':sysClr>', $this->xml);
    }
 
    function fGenerateLT1() {
       	$this->xml = str_replace('__GENERATEDK1__', '<'.THEME1NAMESPACE.':lt1>__GENERATESYSCLR__</'.THEME1NAMESPACE.':lt1>__GENERATELT1__', $this->xml);
    }
    
    function fGenerateDK2() {
       	$this->xml = str_replace('__GENERATELT1__', '<'.THEME1NAMESPACE.':dk2>__GENERATESRGBCLR__</'.THEME1NAMESPACE.':dk2>__GENERATEDK2__', $this->xml);
    }
    
    function fGenerateSRGBCLR($val = 'windowText') {
       	$this->xml = str_replace('__GENERATESRGBCLR__', '<'.THEME1NAMESPACE.':srgbClr val="' . $val . '"></'.THEME1NAMESPACE.':srgbClr>', $this->xml);
    }
    
    function fGenerateLT2() {
       	$this->xml = str_replace('__GENERATEDK2__', '<'.THEME1NAMESPACE.':lt2>__GENERATESRGBCLR__</'.THEME1NAMESPACE.':lt2>__GENERATELT2__', $this->xml);
    }
    
    function fGenerateACCENT1() {
       	$this->xml = str_replace('__GENERATELT2__', '<'.THEME1NAMESPACE.':accent1>__GENERATESRGBCLR__</'.THEME1NAMESPACE.':accent1>__GENERATEACCENT1__', $this->xml);
    }
    
    function fGenerateACCENT2() {
       	$this->xml = str_replace('__GENERATEACCENT1__', '<'.THEME1NAMESPACE.':accent2>__GENERATESRGBCLR__</'.THEME1NAMESPACE.':accent2>__GENERATEACCENT2__', $this->xml);
    }
    
    function fGenerateACCENT3() {
       	$this->xml = str_replace('__GENERATEACCENT2__', '<'.THEME1NAMESPACE.':accent3>__GENERATESRGBCLR__</'.THEME1NAMESPACE.':accent3>__GENERATEACCENT3__', $this->xml);
    }
    
    function fGenerateACCENT4() {
       	$this->xml = str_replace('__GENERATEACCENT3__', '<'.THEME1NAMESPACE.':accent4>__GENERATESRGBCLR__</'.THEME1NAMESPACE.':accent4>__GENERATEACCENT4__', $this->xml);
    }
    
    function fGenerateACCENT5() {
       	$this->xml = str_replace('__GENERATEACCENT4__', '<'.THEME1NAMESPACE.':accent5>__GENERATESRGBCLR__</'.THEME1NAMESPACE.':accent5>__GENERATEACCENT5__', $this->xml);
    }
    
    function fGenerateACCENT6() {
       	$this->xml = str_replace('__GENERATEACCENT5__', '<'.THEME1NAMESPACE.':accent6>__GENERATESRGBCLR__</'.THEME1NAMESPACE.':accent6>__GENERATEACCENT6__', $this->xml);
    }
    
    function fGenerateHLINK() {
       	$this->xml = str_replace('__GENERATEACCENT6__', '<'.THEME1NAMESPACE.':hlink>__GENERATESRGBCLR__</'.THEME1NAMESPACE.':hlink>__GENERATEHLINK__', $this->xml);
    }
  
    function fGenerateFOLHLINK() {
       	$this->xml = str_replace('__GENERATEHLINK__', '<'.THEME1NAMESPACE.':folHlink>__GENERATESRGBCLR__</'.THEME1NAMESPACE.':folHlink>', $this->xml);
    }
  
    function fGenerateFONTSCHEMA($name = 'Office') {
       	$this->xml = str_replace('__GENERATETHEMEELEMENTS2__', '<'.THEME1NAMESPACE.':fontScheme name="' . $name . '">__GENERATEFONTSCHEMA1____GENERATEFONTSCHEMA2__</'.THEME1NAMESPACE.':fontScheme>', $this->xml);
    }
  
    function fGenerateMAYORFONT() {
       	$this->xml = str_replace('__GENERATEFONTSCHEMA1__', '<'.THEME1NAMESPACE.':majorFont>__GENERATEMAYORFONT__</'.THEME1NAMESPACE.':majorFont>', $this->xml);
    }
  
    function fGenerateLATIN($typeface = 'cambia') {
       	$this->xml = str_replace('__GENERATEMAYORFONT__', '<'.THEME1NAMESPACE.':latin typeface="' . $typeface . '"></'.THEME1NAMESPACE.':latin>__GENERATELATIN__', $this->xml);
    }
  
    function fGenerateEA($typeface = '') {
       	$this->xml = str_replace('__GENERATELATIN__', '<'.THEME1NAMESPACE.':ea typeface="' . $typeface . '"></'.THEME1NAMESPACE.':ea>__GENERATEEA__', $this->xml);
    }
  
    function fGenerateCS($typeface = '') {
       	$this->xml = str_replace('__GENERATEEA__', '<'.THEME1NAMESPACE.':cs typeface="' . $typeface . '"></'.THEME1NAMESPACE.':cs>__GENERATECS__', $this->xml);
    }
  
    function fGenerateFONT($script = '', $typeface = '') {
       	$this->xml = str_replace('__GENERATECS__', '<'.THEME1NAMESPACE.':font script="' . $script . '" typeface="' . $typeface . '"></'.THEME1NAMESPACE.':font>__GENERATEFONT__', $this->xml);
    }
  
  	function fGenerateFONT2($script = '', $typeface = '') {
       	$this->xml = str_replace('__GENERATEFONT__', '<'.THEME1NAMESPACE.':font script="' . $script . '" typeface="' . $typeface . '"></'.THEME1NAMESPACE.':font>__GENERATEFONT__', $this->xml);
    }
  
  	function fGenerateFONT3($script = '', $typeface = '') {
       	$this->xml = str_replace('__GENERATEFONT__', '<'.THEME1NAMESPACE.':font script="' . $script . '" typeface="' . $typeface . '"></'.THEME1NAMESPACE.':font>', $this->xml);
    }
  
    function fGenerateMINORFONT() {
       	$this->xml = str_replace('__GENERATEFONTSCHEMA2__', '<'.THEME1NAMESPACE.':minorFont>__GENERATEMAYORFONT__</'.THEME1NAMESPACE.':minorFont>', $this->xml);
    }
    
    
    
    
    
    
    function fGenerateFMTSCHEME($name)  {
       	$this->xml = str_replace('__GENERATETHEMEELEMENTS3__', '<'.THEME1NAMESPACE.':fmtScheme name="' . $name . '">__GENERATEFMTSCHEME__</'.THEME1NAMESPACE.':fmtScheme>', $this->xml);
    }
  
    function fGenerateFILLSTYLELST() {
       	$this->xml = str_replace('__GENERATEFMTSCHEME__', '<'.THEME1NAMESPACE.':fillStyleLst>__GENERATEFILLSTYLELST__</'.THEME1NAMESPACE.':fillStyleLst>__GENERATEFILLSTYLELST2__', $this->xml);
    }
  
    function fGenerateSOLIDFILL() {
       	$this->xml = str_replace('__GENERATEFILLSTYLELST__', '<'.THEME1NAMESPACE.':solidFill>__GENERATESOLIDFILL__</'.THEME1NAMESPACE.':solidFill>__GENERATESOLIDFILL2__', $this->xml);
    }
    
    function fGenerateSCHEMECLR($val) {
       	$this->xml = str_replace('__GENERATESOLIDFILL__', '<'.THEME1NAMESPACE.':schemeClr val="' . $val . '"></'.THEME1NAMESPACE.':schemeClr>', $this->xml);
    }
  
    function fGenerateGRADFILL($rotWithShape) {
       	$this->xml = str_replace('__GENERATESOLIDFILL2__', '<'.THEME1NAMESPACE.':gradFill rotWithShape="' . $rotWithShape . '">__GENERATEGRADFILL__</'.THEME1NAMESPACE.':gradFill>__GENERATESOLIDFILL2__', $this->xml);
    }
  
    function fGenerateGRADFILL2($rotWithShape) {
       	$this->xml = str_replace('__GENERATESOLIDFILL2__', '<'.THEME1NAMESPACE.':gradFill rotWithShape="' . $rotWithShape . '">__GENERATEGRADFILL__</'.THEME1NAMESPACE.':gradFill>', $this->xml);
    }
  
    function fGenerateGSLST() {
       	$this->xml = str_replace('__GENERATEGRADFILL__', '<'.THEME1NAMESPACE.':gsLst>__GENERATEGSLST__</'.THEME1NAMESPACE.':gsLst>__GENERATEGSLST2__', $this->xml);
    }
  
    function fGenerateGS($pos) {
       	$this->xml = str_replace('__GENERATEGSLST__', '<'.THEME1NAMESPACE.':gs pos="' . $pos . '">__GENERATEPOS__</'.THEME1NAMESPACE.':gs>__GENERATEGSLST__', $this->xml);
    }
  
    function fGenerateGS2($pos) {
       	$this->xml = str_replace('__GENERATEGSLST__', '<'.THEME1NAMESPACE.':gs pos="' . $pos . '">__GENERATEPOS__</'.THEME1NAMESPACE.':gs>', $this->xml);
    }
  
    function fGenerateSCHEMECLR2($val) {
       	$this->xml = str_replace('__GENERATEPOS__', '<'.THEME1NAMESPACE.':schemeClr val="' . $val . '">__GENERATESCHEMECLR2__</'.THEME1NAMESPACE.':schemeClr>', $this->xml);
    }
  
    function fGenerateTINT($val) {
       	$this->xml = str_replace('__GENERATESCHEMECLR2__', '<'.THEME1NAMESPACE.':tint val="' . $val . '"></'.THEME1NAMESPACE.':tint>__GENERATETINT__', $this->xml);
    }
  
    function fGenerateSHADE($val) {
       	$this->xml = str_replace('__GENERATESCHEMECLR2__', '<'.THEME1NAMESPACE.':shade val="' . $val . '"></'.THEME1NAMESPACE.':shade>__GENERATETINT__', $this->xml);
    }
  
    function fGenerateSATMOD($val) {
       	$this->xml = str_replace('__GENERATETINT__', '<'.THEME1NAMESPACE.':satMod val="' . $val . '"></'.THEME1NAMESPACE.':satMod>', $this->xml);
    }
  
    function fGenerateLIN($ang, $scaled) {
       	$this->xml = str_replace('__GENERATEGSLST2__', '<'.THEME1NAMESPACE.':lin ang="' . $ang . '" scaled="' . $scaled . '"></'.THEME1NAMESPACE.':lin>', $this->xml);
    }
  
    function fGenerateLNSTYLELST() {
       	$this->xml = str_replace('__GENERATEFILLSTYLELST2__', '<'.THEME1NAMESPACE.':lnStyleLst>__GENERATELNSTYLELST__</'.THEME1NAMESPACE.':lnStyleLst>__GENERATELNSTYLELST2__', $this->xml);
    }
  
    function fGenerateLN($w, $cap, $cmpd, $algn) {
       	$this->xml = str_replace('__GENERATELNSTYLELST__', '<'.THEME1NAMESPACE.':ln w="' . $w . '" cap="' . $cap . '" cmpd="' . $cmpd . '" algn="' . $algn . '">__GENERATEFILLSTYLELST__</'.THEME1NAMESPACE.':ln>__GENERATELNSTYLELST__', $this->xml);
    }
  
    function fGenerateLN2($w, $cap, $cmpd, $algn) {
       	$this->xml = str_replace('__GENERATELNSTYLELST__', '<'.THEME1NAMESPACE.':ln w="' . $w . '" cap="' . $cap . '" cmpd="' . $cmpd . '" algn="' . $algn . '">__GENERATEFILLSTYLELST__</'.THEME1NAMESPACE.':ln>', $this->xml);
    }
    //fGenerateSOLIDFILL
  
    function fGenerateSCHEMECLR3($val) {
       	$this->xml = str_replace('__GENERATESOLIDFILL__', '<'.THEME1NAMESPACE.':schemeClr val="' . $val . '">__GENERATESCHEMECLR2__</'.THEME1NAMESPACE.':schemeClr>', $this->xml);
    }
    
    function fGeneratePRSTDASH($val) {
       	$this->xml = str_replace('__GENERATESOLIDFILL2__', '<'.THEME1NAMESPACE.':prstDash val="' . $val . '"></'.THEME1NAMESPACE.':prstDash>', $this->xml);
    }
  
    function fGenerateEFFECTSTYLELST(){
    	$this->xml = str_replace('__GENERATELNSTYLELST2__', '<'.THEME1NAMESPACE.':effectStyleLst>__GENERATEEFFECTSTYLELST__</'.THEME1NAMESPACE.':effectStyleLst>__GENERATEEFFECTSTYLELST2__', $this->xml);
    }
  
    function fGenerateEFFECTSTYLE(){
    	$this->xml = str_replace('__GENERATEEFFECTSTYLELST__', '<'.THEME1NAMESPACE.':effectStyle>__GENERATEEFFECTSTYLE__</'.THEME1NAMESPACE.':effectStyle>__GENERATEEFFECTSTYLELST__', $this->xml);
    }
  
    function fGenerateEFFECTSTYLE2(){
    	$this->xml = str_replace('__GENERATEEFFECTSTYLELST__', '<'.THEME1NAMESPACE.':effectStyle>__GENERATEEFFECTSTYLE__</'.THEME1NAMESPACE.':effectStyle>', $this->xml);
    }
  
    function fGenerateEFFECTLST(){
    	$this->xml = str_replace('__GENERATEEFFECTSTYLE__', '<'.THEME1NAMESPACE.':effectLst>__GENERATEEFFECTLST__</'.THEME1NAMESPACE.':effectLst>', $this->xml);
    }
    
    function fGenerateOUTERSHDW($blurRad, $dist, $dir, $rotWithShape) {
       	$this->xml = str_replace('__GENERATEEFFECTLST__', '<'.THEME1NAMESPACE.':outerShdw blurRad="' . $blurRad . '" dist="' . $dist . '" dir="' . $dir . '" rotWithShape="' . $rotWithShape . '">__GENERATEOUTERSHDW__</'.THEME1NAMESPACE.':outerShdw>', $this->xml);
    }
  
    function fGenerateSRGBCLR2($val) {
       	$this->xml = str_replace('__GENERATEOUTERSHDW__', '<'.THEME1NAMESPACE.':srgbClr val="' . $val . '">__GENERATESRGBCLR__</'.THEME1NAMESPACE.':srgbClr>', $this->xml);
    }
  
    function fGenerateALPHA($val) {
       	$this->xml = str_replace('__GENERATESRGBCLR__', '<'.THEME1NAMESPACE.':alpha val="' . $val . '"></'.THEME1NAMESPACE.':alpha>', $this->xml);
    }
  
      function fGenerateEFFECTLST2(){
    	$this->xml = str_replace('__GENERATEEFFECTSTYLE__', '<'.THEME1NAMESPACE.':effectLst>__GENERATEEFFECTLST__</'.THEME1NAMESPACE.':effectLst>__GENERATEEFFECTLST2__', $this->xml);
    }

    function fGenerateSCENE3D() {
       	$this->xml = str_replace('__GENERATEEFFECTLST2__', '<'.THEME1NAMESPACE.':scene3d>__GENERATESCENE3D__</'.THEME1NAMESPACE.':scene3d>__GENERATESCENE3D2__', $this->xml);
    }
    
     function fGenerateCAMERA($prst) {
       	$this->xml = str_replace('__GENERATESCENE3D__', '<'.THEME1NAMESPACE.':camera prst="' . $prst . '">__GENERATECAMERA__</'.THEME1NAMESPACE.':camera>__GENERATECAMERA2__', $this->xml);
    }
   
    function fGenerateROT($lat, $lon, $rev) {
       	$this->xml = str_replace('__GENERATECAMERA__', '<'.THEME1NAMESPACE.':rot lat="' . $lat . '" lon="' . $lon . '" rev="' . $rev . '"></'.THEME1NAMESPACE.':rot>', $this->xml);
    }
    
    function fGenerateLIGHTRIG($rig, $dir) {
       	$this->xml = str_replace('__GENERATECAMERA2__', '<'.THEME1NAMESPACE.':lightRig rig="' . $rig . '" dir="' . $dir . '">__GENERATECAMERA__</'.THEME1NAMESPACE.':lightRig>', $this->xml);
    }
  
    function fGenerateSP3D() {
       	$this->xml = str_replace('__GENERATESCENE3D2__', '<'.THEME1NAMESPACE.':sp3d>__GENERATESP3D__</'.THEME1NAMESPACE.':sp3d>', $this->xml);
    }
    
    function fGenerateBEVELT($w, $h) {
       	$this->xml = str_replace('__GENERATESP3D__', '<'.THEME1NAMESPACE.':bevelT w="' . $w . '" h="' . $h . '"></'.THEME1NAMESPACE.':bevelT>', $this->xml);
    }
    
    function fGenerateBGFILLSTYLELST() {
       	$this->xml = str_replace('__GENERATEEFFECTSTYLELST2__', '<'.THEME1NAMESPACE.':bgFillStyleLst>__GENERATEFILLSTYLELST__</'.THEME1NAMESPACE.':bgFillStyleLst>', $this->xml);
    }
  
    function fGenerateTINT2($val) {
       	$this->xml = str_replace('__GENERATESCHEMECLR2__', '<'.THEME1NAMESPACE.':tint val="' . $val . '"></'.THEME1NAMESPACE.':tint>__GENERATESCHEMECLR2__', $this->xml);
    }
  
    function fGeneratePATH($path) {
       	$this->xml = str_replace('__GENERATEGSLST2__', '<'.THEME1NAMESPACE.':path path="' . $path . '">__GENERATEPATH__</'.THEME1NAMESPACE.':path>', $this->xml);
    }
  
    function fGenerateFILLTORECT($l, $t, $r, $b) {
       	$this->xml = str_replace('__GENERATEPATH__', '<'.THEME1NAMESPACE.':fillToRect l="' . $l . '" t="' . $t . '" r="' . $r . '" b="' . $b . '"></'.THEME1NAMESPACE.':fillToRect>', $this->xml);
    }
  
    function fGenerateOBJECTDEFAULTS() {
       	$this->xml = str_replace('__GENERATETHEMEELEMENTS4__', '<'.THEME1NAMESPACE.':objectDefaults></'.THEME1NAMESPACE.':objectDefaults>__GENERATETHEMEELEMENTS4__', $this->xml);
    }
  
    function fGenerateEXTRACLRSCHEMELST() {
       	$this->xml = str_replace('__GENERATETHEMEELEMENTS4__', '<'.THEME1NAMESPACE.':extraClrSchemeLst></'.THEME1NAMESPACE.':extraClrSchemeLst>', $this->xml);
    }
    
    function fCreateTheme($strFont){
    
      $this->xml='';
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
      if($strFont != ''){
	$this->fGenerateFONTSCHEMA('Office');
	$this->fGenerateMAYORFONT();
	$this->fGenerateLATIN($strFont);
        $this->fGenerateEA('');
        $this->fGenerateCS('');
	$this->fGenerateMINORFONT();
	$this->fGenerateLATIN($strFont);
	$this->fGenerateEA('');
	$this->fGenerateCS('');
      }else{      
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
      $this->fGenerateFILLTORECT(50000,'-80000', 50000, 180000);
      
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
      $this->fGenerateFILLTORECT(50000,50000, 50000, 50000);
      $this->fGenerateOBJECTDEFAULTS();
      $this->fGenerateEXTRACLRSCHEMELST();
      $this->fCleanTemplate();
      
      //var_dump($this->xml);
   }
  }
?>