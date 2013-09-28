<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateGraphic extends cCreateElement {
    const NAMESPACEWORD = 'c';
    static private $rscInstance = NULL;
    private $rId;
    private $type;
    private $name;
    protected $xmlChart;

    public function __construct() {
        $this->rId = '';
        $this->type = '';
        $this->xml = '';
        $this->name = '';
        $this->xmlChart = '';
    }

    public function __destruct() {

    }

    public function __toString() {
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateGraphic();
        }
        return self::$rscInstance;
    }

    public function setRId($rId) {
        $this->rId = $rId;
    }

    public function getRId() {
        return $this->rId;
    }

    public function setName($name) {
        $this->name = $name;
    }

    public function getName() {
        return $this->name;
    }

    public function setXmlChart($xmlChart) {
        $this->xmlChart = $xmlChart;
    }

    public function getXmlChart() {
        return $this->xmlChart;
    }

    protected function fGenerateCHARTSPACE() {
        $this->xmlChart = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><' . cCreateGraphic::NAMESPACEWORD . ':chartSpace xmlns:c="http://schemas.openxmlformats.org/drawingml/2006/chart" xmlns:a="http://schemas.openxmlformats.org/drawingml/2006/main" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships">__GENERATECHARTSPACE__</' . cCreateGraphic::NAMESPACEWORD . ':chartSpace>';
    }

    protected function fGenerateDATE1904($val = '1') {
        $this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<' . cCreateGraphic::NAMESPACEWORD . ':date1904 val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':date1904>__GENERATECHARTSPACE__', $this->xmlChart);
    }

    protected function fGenerateLANG($val = 'es-ES') {
        $this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<' . cCreateGraphic::NAMESPACEWORD . ':lang val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':lang>__GENERATECHARTSPACE__', $this->xmlChart);
    }

    protected function fGenerateSTYLE($val = '2') {
        $this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<' . cCreateGraphic::NAMESPACEWORD . ':style val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':style>__GENERATECHARTSPACE__', $this->xmlChart);
    }

    protected function fGenerateTITLE() {
        $this->xmlChart = str_replace('__GENERATECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':title>__GENERATETITLE__</' . cCreateGraphic::NAMESPACEWORD . ':title>__GENERATECHART__', $this->xmlChart);
    }

    protected function fGenerateTITLETX() {
        $this->xmlChart = str_replace('__GENERATETITLE__', '<' . cCreateGraphic::NAMESPACEWORD . ':tx>__GENERATETITLETX__</' . cCreateGraphic::NAMESPACEWORD . ':tx>__GENERATETITLE__', $this->xmlChart);
    }

    protected function fGenerateRICH() {
        $this->xmlChart = str_replace('__GENERATETITLETX__', '<' . cCreateGraphic::NAMESPACEWORD . ':rich>__GENERATERICH__</' . cCreateGraphic::NAMESPACEWORD . ':rich>__GENERATETITLETX__', $this->xmlChart);
    }

    protected function fGenerateBODYPR() {
        $this->xmlChart = str_replace('__GENERATERICH__', '<' . cCreateImage::NAMESPACEWORD1 . ':bodyPr></' . cCreateImage::NAMESPACEWORD1 . ':bodyPr>__GENERATERICH__', $this->xmlChart);
    }

    protected function fGenerateLSTSTYLE() {
        $this->xmlChart = str_replace('__GENERATERICH__', '<' . cCreateImage::NAMESPACEWORD1 . ':lstStyle></' . cCreateImage::NAMESPACEWORD1 . ':lstStyle>__GENERATERICH__', $this->xmlChart);
    }

    protected function fGenerateTITLEP() {
        $this->xmlChart = str_replace('__GENERATERICH__', '<' . cCreateImage::NAMESPACEWORD1 . ':p>__GENERATETITLEP__</' . cCreateImage::NAMESPACEWORD1 . ':p>__GENERATERICH__', $this->xmlChart);
    }

    protected function fGenerateTITLEPPR() {
        $this->xmlChart = str_replace('__GENERATETITLEP__', '<' . cCreateImage::NAMESPACEWORD1 . ':pPr>__GENERATETITLEPPR__</' . cCreateImage::NAMESPACEWORD1 . ':pPr>__GENERATETITLEP__', $this->xmlChart);
    }

    protected function fGenerateDEFRPR() {
        $this->xmlChart = str_replace('__GENERATETITLEPPR__', '<' . cCreateImage::NAMESPACEWORD1 . ':defRPr>__GENERATEDEFRPR__</' . cCreateImage::NAMESPACEWORD1 . ':defRPr>__GENERATETITLEPPR__', $this->xmlChart);
    }

    protected function fGenerateTITLER() {
        $this->xmlChart = str_replace('__GENERATETITLEP__', '<' . cCreateImage::NAMESPACEWORD1 . ':r>__GENERATETITLER__</' . cCreateImage::NAMESPACEWORD1 . ':r>__GENERATETITLEP__', $this->xmlChart);
    }

    protected function fGenerateTITLERPR($lang = 'es-ES') {
        $this->xmlChart = str_replace('__GENERATETITLER__', '<' . cCreateImage::NAMESPACEWORD1 . ':rPr lang="' . $lang . '">__GENERATETITLERPR__</' . cCreateImage::NAMESPACEWORD1 . ':rPr>__GENERATETITLER__', $this->xmlChart);
    }

    protected function fGenerateTITLET($nombre='') {
        $this->xmlChart = str_replace('__GENERATETITLER__', '<' . cCreateImage::NAMESPACEWORD1 . ':t>' . $nombre . '</' . cCreateImage::NAMESPACEWORD1 . ':t>__GENERATETITLER__', $this->xmlChart);
    }

    protected function fGenerateTITLELAYOUT($nombre='') {
        $this->xmlChart = str_replace('__GENERATETITLE__', '<' . cCreateImage::NAMESPACEWORD1 . ':layout></' . cCreateImage::NAMESPACEWORD1 . ':layout>', $this->xmlChart);
    }

    protected function fGenerateAUTOTITLEDELETED($val = '1') {
        $this->xmlChart = str_replace('__GENERATECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':autoTitleDeleted val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':autoTitleDeleted>__GENERATECHART__', $this->xmlChart);
    }

    protected function fGenerateCHART() {
        $this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<' . cCreateGraphic::NAMESPACEWORD . ':chart>__GENERATECHART__</' . cCreateGraphic::NAMESPACEWORD . ':chart>__GENERATECHARTSPACE__', $this->xmlChart);
    }

    protected function fGeneratePLOTAREA() {
        $this->xmlChart = str_replace('__GENERATECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':plotArea>__GENERATEPLOTAREA__</' . cCreateGraphic::NAMESPACEWORD . ':plotArea>__GENERATECHART__', $this->xmlChart);
    }

    protected function fGenerateLAYOUT() {
        $this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<' . cCreateGraphic::NAMESPACEWORD . ':layout></' . cCreateGraphic::NAMESPACEWORD . ':layout>__GENERATEPLOTAREA__', $this->xmlChart);
    }

    protected function fGeneratePIECHART() {
        $this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<' . cCreateGraphic::NAMESPACEWORD . ':pieChart>__GENERATETYPECHART__</' . cCreateGraphic::NAMESPACEWORD . ':pieChart>__GENERATEPLOTAREA__', $this->xmlChart);
    }

    protected function fGenerateBARCHART() {
        $this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<' . cCreateGraphic::NAMESPACEWORD . ':barChart>__GENERATETYPECHART__</' . cCreateGraphic::NAMESPACEWORD . ':barChart>__GENERATEPLOTAREA__', $this->xmlChart);
    }

    protected function fGenerateLINECHART() {
        $this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<' . cCreateGraphic::NAMESPACEWORD . ':lineChart>__GENERATETYPECHART__</' . cCreateGraphic::NAMESPACEWORD . ':lineChart>__GENERATEPLOTAREA__', $this->xmlChart);
    }

    protected function fGenerateVARYCOLORS($val='1') {
        $this->xmlChart = str_replace('__GENERATETYPECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':varyColors val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':varyColors>__GENERATETYPECHART__', $this->xmlChart);
    }

    protected function fGenerateBARDIR($val='bar') {
        $this->xmlChart = str_replace('__GENERATETYPECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':barDir val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':barDir>__GENERATETYPECHART__', $this->xmlChart);
    }

    protected function fGenerateGROUPING($val='stacked') {
        $this->xmlChart = str_replace('__GENERATETYPECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':grouping val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':grouping>__GENERATETYPECHART__', $this->xmlChart);
    }

    protected function fGenerateSER() {
        $this->xmlChart = str_replace('__GENERATETYPECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':ser>__GENERATESER__</' . cCreateGraphic::NAMESPACEWORD . ':ser>__GENERATETYPECHART__', $this->xmlChart);
    }

    protected function fGenerateIDX($val='0') {
        $this->xmlChart = str_replace('__GENERATESER__', '<' . cCreateGraphic::NAMESPACEWORD . ':idx val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':idx>__GENERATESER__', $this->xmlChart);
    }

    protected function fGenerateORDER($val='0') {
        $this->xmlChart = str_replace('__GENERATESER__', '<' . cCreateGraphic::NAMESPACEWORD . ':order val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':order>__GENERATESER__', $this->xmlChart);
    }

    protected function fGenerateTX() {
        $this->xmlChart = str_replace('__GENERATESER__', '<' . cCreateGraphic::NAMESPACEWORD . ':tx>__GENERATETX__</' . cCreateGraphic::NAMESPACEWORD . ':tx>__GENERATESER__', $this->xmlChart);
    }

    protected function fGenerateSTRREF() {
        $this->xmlChart = str_replace('__GENERATETX__', '<' . cCreateGraphic::NAMESPACEWORD . ':strRef>__GENERATESTRREF__</' . cCreateGraphic::NAMESPACEWORD . ':strRef>__GENERATETX__', $this->xmlChart);
    }

    protected function fGenerateF($val='Hoja1!$B$1') {
        $this->xmlChart = str_replace('__GENERATESTRREF__', '<' . cCreateGraphic::NAMESPACEWORD . ':f>' . $val . '</' . cCreateGraphic::NAMESPACEWORD . ':f>__GENERATESTRREF__', $this->xmlChart);
    }

    protected function fGenerateSTRCACHE() {
        $this->xmlChart = str_replace('__GENERATESTRREF__', '<' . cCreateGraphic::NAMESPACEWORD . ':strCache>__GENERATESTRCACHE__</' . cCreateGraphic::NAMESPACEWORD . ':strCache>__GENERATESTRREF__', $this->xmlChart);
    }

    protected function fGeneratePTCOUNT($val='1') {
        $this->xmlChart = str_replace('__GENERATESTRCACHE__', '<' . cCreateGraphic::NAMESPACEWORD . ':ptCount val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':ptCount>__GENERATESTRCACHE__', $this->xmlChart);
    }

    protected function fGeneratePT($idx='0') {
        $this->xmlChart = str_replace('__GENERATESTRCACHE__', '<' . cCreateGraphic::NAMESPACEWORD . ':pt idx="' . $idx . '">__GENERATEPT__</' . cCreateGraphic::NAMESPACEWORD . ':pt>__GENERATESTRCACHE__', $this->xmlChart);
    }

    protected function fGenerateV($idx='Ventas') {
        $this->xmlChart = str_replace('__GENERATEPT__', '<' . cCreateGraphic::NAMESPACEWORD . ':v>' . $idx . '</' . cCreateGraphic::NAMESPACEWORD . ':v>', $this->xmlChart);
    }

    protected function fGenerateCAT() {
        $this->xmlChart = str_replace('__GENERATESER__', '<' . cCreateGraphic::NAMESPACEWORD . ':cat>__GENERATETX__</' . cCreateGraphic::NAMESPACEWORD . ':cat>__GENERATESER__', $this->xmlChart);
    }

    protected function fGenerateVAL() {
        $this->xmlChart = str_replace('__GENERATESER__', '<' . cCreateGraphic::NAMESPACEWORD . ':val>__GENERATETX__</' . cCreateGraphic::NAMESPACEWORD . ':val>__GENERATESER__', $this->xmlChart);
    }

    protected function fGenerateNUMCACHE() {
        $this->xmlChart = str_replace('__GENERATESTRREF__', '<' . cCreateGraphic::NAMESPACEWORD . ':numCache>__GENERATESTRCACHE__</' . cCreateGraphic::NAMESPACEWORD . ':numCache>__GENERATESTRREF__', $this->xmlChart);
    }

    protected function fGenerateNUMREF() {
        $this->xmlChart = str_replace('__GENERATETX__', '<' . cCreateGraphic::NAMESPACEWORD . ':numRef>__GENERATESTRREF__</' . cCreateGraphic::NAMESPACEWORD . ':numRef>__GENERATETX__', $this->xmlChart);
    }

    protected function fGenerateFORMATCODE($val = 'General') {
        $this->xmlChart = str_replace('__GENERATESTRCACHE__', '<' . cCreateGraphic::NAMESPACEWORD . ':formatCode>' . $val . '</' . cCreateGraphic::NAMESPACEWORD . ':formatCode>__GENERATESTRCACHE__', $this->xmlChart);
    }

    protected function fGenerateLEGEND() {
        $this->xmlChart = str_replace('__GENERATECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':legend>__GENERATELEGEND__</' . cCreateGraphic::NAMESPACEWORD . ':legend>__GENERATECHART__', $this->xmlChart);
    }

    protected function fGenerateLEGENDPOS($val='r') {
        $this->xmlChart = str_replace('__GENERATELEGEND__', '<' . cCreateGraphic::NAMESPACEWORD . ':legendPos val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':legendPos>__GENERATELEGEND__', $this->xmlChart);
    }

    protected function fGeneratePLOTVISONLY($val='1') {
        $this->xmlChart = str_replace('__GENERATECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':plotVisOnly val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':plotVisOnly>__GENERATECHART__', $this->xmlChart);
    }

    protected function fGenerateEXTERNALDATA($val='rId1') {
        $this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<' . cCreateGraphic::NAMESPACEWORD . ':externalData r:id="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':externalData>', $this->xmlChart);
    }

    protected function fGenerateSPPR() {
        $this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<' . cCreateGraphic::NAMESPACEWORD . ':spPr>__GENERATESPPR__</' . cCreateGraphic::NAMESPACEWORD . ':spPr>__GENERATECHARTSPACE__', $this->xmlChart);
    }

    protected function fGenerateLN() {
        $this->xmlChart = str_replace('__GENERATESPPR__', '<' . cCreateImage::NAMESPACEWORD1 . ':ln>__GENERATELN__</' . cCreateImage::NAMESPACEWORD1 . ':ln>', $this->xmlChart);
    }

    protected function fGenerateNOFILL() {
        $this->xmlChart = str_replace('__GENERATELN__', '<' . cCreateImage::NAMESPACEWORD1 . ':noFill></' . cCreateImage::NAMESPACEWORD1 . ':noFill>', $this->xmlChart);
    }

    protected function fGenerateOVERLAP($val='100') {
        $this->xmlChart = str_replace('__GENERATETYPECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':overlap val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':overlap>__GENERATETYPECHART__', $this->xmlChart);
    }

    protected function fGenerateSHAPE($val='box') {
        $this->xmlChart = str_replace('__GENERATETYPECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':shape val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':shape>__GENERATETYPECHART__', $this->xmlChart);
    }

    protected function fGenerateAXID($val='59034624') {
        $this->xmlChart = str_replace('__GENERATETYPECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':axId val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':axId>__GENERATETYPECHART__', $this->xmlChart);
    }

    protected function fGenerateFIRSTSLICEANG($val='0') {
        $this->xmlChart = str_replace('__GENERATETYPECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':firstSliceAng val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':firstSliceAng>', $this->xmlChart);
    }

    protected function fGenerateDLBLS() {
        $this->xmlChart = str_replace('__GENERATETYPECHART__', '<' . cCreateGraphic::NAMESPACEWORD . ':dLbls>__GENERATEDLBLS__</' . cCreateGraphic::NAMESPACEWORD . ':dLbls>__GENERATETYPECHART__', $this->xmlChart);
    }

    protected function fGenerateSHOWPERCENT($val='0') {
        $this->xmlChart = str_replace('__GENERATEDLBLS__', '<' . cCreateGraphic::NAMESPACEWORD . ':showPercent val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':showPercent>', $this->xmlChart);
    }

    protected function fGenerateDOCUMENTCHART() {
        $this->xml = str_replace('__GENERATEGRAPHICDATA__', '<' . cCreateGraphic::NAMESPACEWORD . ':chart xmlns:c="http://schemas.openxmlformats.org/drawingml/2006/chart" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" r:id="rId' . $this->getRId() . '"></' . cCreateGraphic::NAMESPACEWORD . ':chart>', $this->xml);
    }

    protected function fGenerateCATAX() {
        $this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<' . cCreateGraphic::NAMESPACEWORD . ':catAx>__GENERATEAX__</' . cCreateGraphic::NAMESPACEWORD . ':catAx>__GENERATEPLOTAREA__', $this->xmlChart);
    }

    protected function fGenerateVALAX() {
        $this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<' . cCreateGraphic::NAMESPACEWORD . ':valAx>__GENERATEAX__</' . cCreateGraphic::NAMESPACEWORD . ':valAx>', $this->xmlChart);
    }

    protected function fGenerateAXAXID($val='59034624') {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':axId val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':axId>__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateSCALING() {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':scaling>__GENERATESCALING__</' . cCreateGraphic::NAMESPACEWORD . ':scaling>__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateORIENTATION($val = 'minMax') {
        $this->xmlChart = str_replace('__GENERATESCALING__', '<' . cCreateGraphic::NAMESPACEWORD . ':orientation val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':orientation>', $this->xmlChart);
    }

    protected function fGenerateAXPOS($val = 'b') {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':axPos val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':axPos>__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateTICKLBLPOS($val = 'nextTo') {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':tickLblPos val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':tickLblPos>__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateCROSSAX($val = '59040512') {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':crossAx  val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':crossAx >__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateCROSSES($val = 'autoZero') {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':crosses val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':crosses>__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateAUTO($val = '1') {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':auto val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':auto>__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateLBLALGN($val = 'ctr') {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':lblAlgn val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':lblAlgn>__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateLBLOFFSET($val = '100') {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':lblOffset val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':lblOffset>', $this->xmlChart);
    }

    protected function fGenerateMAJORGRIDLINES() {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':majorGridlines></' . cCreateGraphic::NAMESPACEWORD . ':majorGridlines>__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateNUMFMT($formatCode='General', $sourceLinked = '1') {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':numFmt formatCode="' . $formatCode . '" sourceLinked="' . $sourceLinked . '"></' . cCreateGraphic::NAMESPACEWORD . ':numFmt>__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateCROSSBETWEEN($val = 'between') {
        $this->xmlChart = str_replace('__GENERATEAX__', '<' . cCreateGraphic::NAMESPACEWORD . ':crossBetween val="' . $val . '"></' . cCreateGraphic::NAMESPACEWORD . ':crossBetween>', $this->xmlChart);
    }

    protected function fGenerateLEGENDFONT($strFont = '') {
        $this->xmlChart = str_replace('__GENERATELEGEND__', '<c:layout /><c:txPr><a:bodyPr /><a:lstStyle /><a:p><a:pPr><a:defRPr><a:latin typeface="' . $strFont . '" pitchFamily="34" charset="0" /><a:cs typeface="' . $strFont . '" pitchFamily="34" charset="0" /></a:defRPr></a:pPr><a:endParaRPr lang="es-ES" /></a:p></c:txPr>', $this->xmlChart);
    }

    private function fGenerateRFONTS2($strFont) {
        $this->xmlChart = str_replace('__GENERATEAX__', '<c:txPr><a:bodyPr /><a:lstStyle /><a:p><a:pPr><a:defRPr><a:latin typeface="' . $strFont . '" pitchFamily="34" charset="0" /><a:cs typeface="' . $strFont . '" pitchFamily="34" charset="0" /></a:defRPr></a:pPr><a:endParaRPr lang="es-ES" /></a:p></c:txPr>__GENERATEAX__', $this->xmlChart);
    }

    protected function fGenerateTITLERFONTS($strFont = '') {
        $this->xmlChart = str_replace('__GENERATETITLERPR__', '<' . cCreateImage::NAMESPACEWORD1 . ':latin typeface="' . $strFont . '" pitchFamily="34" charset="0"></' . cCreateImage::NAMESPACEWORD1 . ':latin ><' . cCreateImage::NAMESPACEWORD1 . ':cs typeface="' . $strFont . '" pitchFamily="34" charset="0"></' . cCreateImage::NAMESPACEWORD1 . ':cs>', $this->xmlChart);
    }

    private function fCleanTemplateDocument() {
        $this->xmlChart = preg_replace('/__[A-Z]+__/', '', $this->xmlChart);
    }

    private function fCleanTemplate2() {
        $this->xmlChart = preg_replace(array('/__GENERATE[A-B,D-O,Q-R,U-Z][A-Z]+__/', '/__GENERATES[A-D,F-Z][A-Z]+__/', '/__GENERATETX__/'), '', $this->xmlChart);
    }

    private function fCleanTemplate3() {
        $this->xmlChart = preg_replace(array('/__GENERATE[A-B,D-O,Q-S,U-Z][A-Z]+__/', '/__GENERATES[A-D,F-Z][A-Z]+__/', '/__GENERATETX__/'), '', $this->xmlChart);
    }

    protected function fGenerateRFONTS($strFont) {
        $this->xmlChart = str_replace('__GENERATEDEFRPR__', '<' . cCreateImage::NAMESPACEWORD1 . ':latin typeface="' . $strFont . '" pitchFamily="34" charset="0"></' . cCreateImage::NAMESPACEWORD1 . ':latin ><' . cCreateImage::NAMESPACEWORD1 . ':cs typeface="' . $strFont . '" pitchFamily="34" charset="0"></' . cCreateImage::NAMESPACEWORD1 . ':cs>', $this->xmlChart);
    }

    protected function fCreateCHARTXML() {
        $this->xmlChart = '';
        $arrArgs = func_get_args();
        $type = $arrArgs[0][1]['type'];
        $this->setRId($arrArgs[0][0]);
        $this->fGenerateCHARTSPACE();
        $this->fGenerateDATE1904(1);
        $this->fGenerateLANG();
        $this->fGenerateSTYLE();
        $this->fGenerateCHART();
        if (isset($arrArgs[0][1]['title'])) {
            $this->fGenerateTITLE();
            $title = $arrArgs[0][1]['title'];
            $this->fGenerateTITLETX();
            $this->fGenerateRICH();
            $this->fGenerateBODYPR();
            $this->fGenerateLSTSTYLE();
            $this->fGenerateTITLEP();
            $this->fGenerateTITLEPPR();
            $this->fGenerateDEFRPR();
            if (!empty($arrArgs[0][1]['font']))
                $this->fGenerateRFONTS($arrArgs[0][1]['font']);
            $this->fGenerateTITLER();
            $this->fGenerateTITLERPR();
            if (!empty($arrArgs[0][1]['font']))
                $this->fGenerateTITLERFONTS($arrArgs[0][1]['font']);
            $this->fGenerateTITLET($title);
            $this->fGenerateTITLELAYOUT();
        }else {
            $this->fGenerateAUTOTITLEDELETED();
            $title = '';
        }
        if (empty($arrArgs[0][1]['data']))
            exit('You haven`t added dats');
        $datos = $arrArgs[0][1]['data'];
        $this->fGeneratePLOTAREA();
        $this->fGenerateLAYOUT();
        if (strpos($type, 'pie') !== false) {
            $this->fGeneratePIECHART();
            $this->fGenerateVARYCOLORS();
            if (isset($datos[0]))
                $leyends = $datos[0];
            else
                $leyends = array($title);
            $numDatos = count($datos);
        }elseif ((strpos($type, 'bar') !== false) || (strpos($type, 'col') !== false)) {
            $this->fGenerateBARCHART();
            $strTypeBar = 'bar';
            if (strpos($type, 'col') !== false)
                $strTypeBar = 'col';
            $this->fGenerateBARDIR($strTypeBar);
            $this->fGenerateGROUPING('clustered');
            if (isset($datos[0]))
                $leyends = $datos[0];
            else {
                echo('You must write a legend');
                return false;
            }
            $numDatos = count($datos) - 1;
        }
        elseif (strpos($type, 'line') !== false) {
            $this->fGenerateLINECHART();
            $this->fGenerateGROUPING('standard');
            if (isset($datos[0]))
                $leyends = $datos[0];
            else {
                echo('You must write a legend');
                return false;
            }
            $numDatos = count($datos) - 1;
        }
        else {
            echo('The graphic is not available');
            return false;
        }


        $letra = 'A';
        for ($i = 0; $i < count($leyends); $i++) {
            $this->fGenerateSER();
            $this->fGenerateIDX($i);
            $this->fGenerateORDER($i);
            $letra++;

            $this->fGenerateTX();
            $this->fGenerateSTRREF();
            $this->fGenerateF(' Hoja1!$' . $letra . '$1');
            $this->fGenerateSTRCACHE();
            $this->fGeneratePTCOUNT();
            $this->fGeneratePT();
            if (strpos($arrArgs[0][1]['type'], 'pie') !== false) {
                $this->fGenerateV($title);
            }
            else {
                $this->fGenerateV($leyends[$i]);
            }

            $this->fCleanTemplate2();
            $this->fGenerateCAT();
            $this->fGenerateSTRREF();
            $this->fGenerateF('Hoja1!$A$2:$A$' . ($numDatos + 1));
            $this->fGenerateSTRCACHE();
            $this->fGeneratePTCOUNT($numDatos);

            $num = 0;
            foreach ($datos as $legend => $dato) {
                if ($legend == '0')
                    continue;
                $this->fGeneratePT($num);
                $this->fGenerateV($legend);
                $num++;
            }
            $this->fCleanTemplate2();
            $this->fGenerateVAL();
            $this->fGenerateNUMREF();
            $this->fGenerateF('Hoja1!$' . $letra . '$2:$B$' . ($numDatos + 1));
            $this->fGenerateNUMCACHE();
            $this->fGenerateFORMATCODE();
            $this->fGeneratePTCOUNT($numDatos);
            $num = 0;
            foreach ($datos as $legend => $dato) {
                if ($legend == '0')
                    continue;
                $this->fGeneratePT($num);
                $this->fGenerateV($dato[$i]);
                $num++;
            }
            $this->fCleanTemplate3();
        }
        if (strpos($arrArgs[0][1]['type'], 'pie') !== false) {
            $this->fGenerateDLBLS();
            $this->fGenerateSHOWPERCENT();
            $this->fGenerateFIRSTSLICEANG();
        }
        else {
            $this->fGenerateSHAPE();
            $this->fGenerateAXID();
            $this->fGenerateAXID(59040512);
            $this->fGenerateCATAX();
            $this->fGenerateAXAXID(59034624);
            $this->fGenerateSCALING();
            $this->fGenerateORIENTATION();
            $this->fGenerateAXPOS();
            $this->fGenerateTICKLBLPOS();
            $this->fGenerateCROSSAX();
            $this->fGenerateCROSSES();
            $this->fGenerateAUTO();
            $this->fGenerateLBLALGN();
            $this->fGenerateLBLOFFSET();
            $this->fGenerateVALAX();
            $this->fGenerateAXAXID(59040512);
            $this->fGenerateSCALING();
            $this->fGenerateORIENTATION();
            $this->fGenerateAXPOS('l');
            $this->fGenerateMAJORGRIDLINES();
            $this->fGenerateNUMFMT();
            $this->fGenerateTICKLBLPOS();
            if (!empty($arrArgs[0][1]['font']))
                $this->fGenerateRFONTS2($arrArgs[0][1]['font']);
            $this->fGenerateCROSSAX(59034624);
            $this->fGenerateCROSSES();
            $this->fGenerateCROSSBETWEEN();
        }

        $this->fGenerateLEGEND();
        $this->fGenerateLEGENDPOS();
        if (!empty($arrArgs[0][1]['font']))
            $this->fGenerateLEGENDFONT($arrArgs[0][1]['font']);
        $this->fGeneratePLOTVISONLY();
        if (strpos($arrArgs[0][1]['type'], 'pieChart') === false) {
            $this->fGenerateSPPR();
            $this->fGenerateLN();
            $this->fGenerateNOFILL();
        }

        $this->fGenerateEXTERNALDATA();
        $this->fCleanTemplateDocument();
        return true;
    }

    protected function fCreateDOCUEMNTXML() {
        $arrArgs = func_get_args();
        $intAjusteTexto = 0;
        if (isset($arrArgs[0][1]['sizeX']))
            $sizeX = $arrArgs[0][1]['sizeX'] * cCreateImage::CONSTWORD;
        else {
            $sizeX = 2993296;
        }
        if (isset($arrArgs[0][1]['sizeY']))
            $sizeY = $arrArgs[0][1]['sizeY'] * cCreateImage::CONSTWORD;
        else {
            $sizeY = 2238233;
        }
        $this->xml = '';
        $this->fGenerateP();
        $this->fGenerateR();
        $this->fGenerateRPR();
        $this->fGenerateNOPROOF();
        $this->fGenerateDRAWING();
        $this->fGenerateINLINE();
        $this->fGenerateEXTENT($sizeX, $sizeY);
        $this->fGenerateEFFECTEXTENT();
        $this->fGenerateDOCPR();
        $this->fGenerateCNVGRAPHICFRAMEPR();
        $this->fGenerateGRAPHIC();
        $this->fGenerateGRAPHICDATA('http://schemas.openxmlformats.org/drawingml/2006/chart');
        $this->fGenerateDOCUMENTCHART();
        $this->fCleanTemplate();
        return true;
    }

    public function fCreateGraphic() {
        $this->xmlChart = '';
        $arrArgs = func_get_args();
        if (!empty($arrArgs[1]['type']) && !empty($arrArgs[0])) {
            if ($this->fCreateCHARTXML($arrArgs) == false) {
                echo 'You haven`t added legends';
                return false;
            }
            $this->fCreateDOCUEMNTXML($arrArgs);
            return true;
        }
        else {
            echo 'You haven`t added a chart type';
            return false;
        }
    }

}
?>