<?php

/**
 * @author 2mdc.com
 * @version 
 */
class cCreateElement {
    const MATHNAMESPACEWORD = 'm';
    const NAMESPACEWORD = 'w';
    protected $xml;

    private function __construct() {

    }

    protected function __destruct() {

    }

    protected function __toString() {

    }

    protected function fGenerateP() {
        $this->xml = '<' . cCreateElement::NAMESPACEWORD . ':p>__GENERATEP__</' . cCreateElement::NAMESPACEWORD . ':p>';
    }

    protected function fGeneratePPR() {
        $this->xml = str_replace('__GENERATEP__', '<' . cCreateElement::NAMESPACEWORD . ':pPr>__GENERATEPPR__</' . cCreateElement::NAMESPACEWORD . ':pPr>__GENERATER__', $this->xml);
    }

    protected function fGenerateT($strDat) {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':t>' . $strDat . '</' . cCreateElement::NAMESPACEWORD . ':t>', $this->xml);
    }

    protected function fGenerateRPR() {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':rPr>__GENERATERPR__</' . cCreateElement::NAMESPACEWORD . ':rPr>__GENERATER__', $this->xml);
    }

    protected function fGenerateJC($strVal = '') {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':jc ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':jc>', $this->xml);
    }

    protected function fGenerateNOPROOF() {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':noProof></' . cCreateElement::NAMESPACEWORD . ':noProof>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateR() {
        if (!empty($this->xml)) {
            if (preg_match("/__GENERATEP__/", $this->xml)) {
                $this->xml = str_replace('__GENERATEP__', '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>', $this->xml);
            }
            elseif (preg_match("/__GENERATER__/", $this->xml)) {
                $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>', $this->xml);
            }
        }
        else {
            $this->xml = '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>';
        }
    }

    protected function fGenerateDRAWING() {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':drawing>__GENERATEDRAWING__</' . cCreateElement::NAMESPACEWORD . ':drawing>', $this->xml);
    }

    protected function fGenerateINLINE($distT= '0', $distB='0', $distL='0', $distR='0') {
        $this->xml = str_replace('__GENERATEDRAWING__', '<' . cCreateImage::NAMESPACEWORD . ':inline distT="' . $distT . '" distB="' . $distB . '" distL="' . $distL . '" distR="' . $distR . '">__GENERATEINLINE__</' . cCreateImage::NAMESPACEWORD . ':inline>', $this->xml);
    }

    protected function fGenerateANCHOR($behindDoc=0, $distT= '0', $distB='0', $distL='114300', $distR='114300', $simplePos=0, $relativeHeight='251658240', $locked=0, $layoutInCell=1, $allowOverlap=1) {
        $this->xml = str_replace('__GENERATEDRAWING__', '<' . cCreateImage::NAMESPACEWORD . ':anchor distT="' . $distT . '" distB="' . $distB . '" distL="' . $distL . '" distR="' . $distR . '" simplePos="' . $simplePos . '" relativeHeight="' . $relativeHeight . '" behindDoc="' . $behindDoc . '" locked="' . $locked . '" layoutInCell="' . $layoutInCell . '" allowOverlap="' . $allowOverlap . '">__GENERATEINLINE__</' . cCreateImage::NAMESPACEWORD . ':anchor>', $this->xml);
    }

    protected function fGenerateSIMPLEPOS($x='0', $y='0') {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':simplePos x="' . $x . '" y="' . $y . '"></' . cCreateImage::NAMESPACEWORD . ':simplePos>__GENERATEINLINE__', $this->xml);
    }

    protected function fGeneratePOSITIONH($relativeFrom = 'column') {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':positionH relativeFrom="' . $relativeFrom . '">__GENERATEPOSITION__</' . cCreateImage::NAMESPACEWORD . ':positionH>__GENERATEINLINE__', $this->xml);
    }

    protected function fGeneratePOSITIONV($relativeFrom = 'paragraph') {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':positionV relativeFrom="' . $relativeFrom . '">__GENERATEPOSITION__</' . cCreateImage::NAMESPACEWORD . ':positionV>__GENERATEINLINE__', $this->xml);
    }

    protected function fGeneratePOSOFFSET($num) {
        $this->xml = str_replace('__GENERATEPOSITION__', '<' . cCreateImage::NAMESPACEWORD . ':posOffset>' . $num . '</' . cCreateImage::NAMESPACEWORD . ':posOffset>', $this->xml);
    }

    protected function fGenerateEXTENT($cx='2986543', $cy='2239906') {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':extent cx="' . $cx . '" cy="' . $cy . '"></' . cCreateImage::NAMESPACEWORD . ':extent>__GENERATEINLINE__', $this->xml);
    }

    protected function fGenerateEFFECTEXTENT($l="19050", $t="0", $r="4307", $b="0") {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':effectExtent l="' . $l . '" t="' . $t . '" r="' . $r . '" b="' . $b . '"></' . cCreateImage::NAMESPACEWORD . ':effectExtent>__GENERATEINLINE__', $this->xml);
    }

    protected function fGenerateWRAPSQUARE($wrapText="bothSides") {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':wrapSquare wrapText="' . $wrapText . '"></' . cCreateImage::NAMESPACEWORD . ':wrapSquare>__GENERATEINLINE__', $this->xml);
    }

    protected function fGenerateWRAPNONE() {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':wrapNone></' . cCreateImage::NAMESPACEWORD . ':wrapNone>__GENERATEINLINE__', $this->xml);
    }

    protected function fGenerateWRAPTOPANDBOTTOM() {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':wrapTopAndBottom></' . cCreateImage::NAMESPACEWORD . ':wrapTopAndBottom>__GENERATEINLINE__', $this->xml);
    }

    protected function fGenerateWRAPTHROUGH($wrapText = 'bothSides') {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':wrapThrough wrapText="' . $wrapText . '">__GENERATEWRAPTHROUGH__</' . cCreateImage::NAMESPACEWORD . ':wrapThrough>__GENERATEINLINE__', $this->xml);
    }

    protected function fGenerateWRAPPOLYGON($edited = '0') {
        $this->xml = str_replace('__GENERATEWRAPTHROUGH__', '<' . cCreateImage::NAMESPACEWORD . ':wrapPolygon edited="' . $edited . '">__GENERATEWRAPPOLYGON__</' . cCreateImage::NAMESPACEWORD . ':wrapPolygon>', $this->xml);
    }

    protected function fGenerateSTART($x = '-198', $y = '0') {
        $this->xml = str_replace('__GENERATEWRAPPOLYGON__', '<' . cCreateImage::NAMESPACEWORD . ':start x="' . $x . '" y="' . $y . '"></' . cCreateImage::NAMESPACEWORD . ':start>__GENERATEWRAPPOLYGON__', $this->xml);
    }

    protected function fGenerateLINETO($x = '-198', $y = '21342') {
        $this->xml = str_replace('__GENERATEWRAPPOLYGON__', '<' . cCreateImage::NAMESPACEWORD . ':lineTo x="' . $x . '" y="' . $y . '"></' . cCreateImage::NAMESPACEWORD . ':lineTo>__GENERATEWRAPPOLYGON__', $this->xml);
    }

    protected function fGenerateDOCPR($id="1", $name="0 Imagen") {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':docPr id="' . $id . '" name="' . $name . '" descr="' . $this->getName() . '"></' . cCreateImage::NAMESPACEWORD . ':docPr>__GENERATEINLINE__', $this->xml);
    }

    protected function fGenerateCNVGRAPHICFRAMEPR() {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD . ':cNvGraphicFramePr>__GENERATECNVGRAPHICFRAMEPR__</' . cCreateImage::NAMESPACEWORD . ':cNvGraphicFramePr>__GENERATEINLINE__', $this->xml);
    }

    protected function fGenerateGRAPHICPRAMELOCKS($noChangeAspect = '') {
        $xmlAux = '<' . cCreateImage::NAMESPACEWORD1 . ':graphicFrameLocks xmlns:a="http://schemas.openxmlformats.org/drawingml/2006/main"';
        if ($noChangeAspect != '')
            $xmlAux .= ' noChangeAspect="' . $noChangeAspect . '"';
        $xmlAux .= '></' . cCreateImage::NAMESPACEWORD1 . ':graphicFrameLocks>';

        $this->xml = str_replace('__GENERATECNVGRAPHICFRAMEPR__', $xmlAux, $this->xml);
    }

    protected function fGenerateGRAPHIC($xmlns="http://schemas.openxmlformats.org/drawingml/2006/main") {
        $this->xml = str_replace('__GENERATEINLINE__', '<' . cCreateImage::NAMESPACEWORD1 . ':graphic xmlns:a="' . $xmlns . '">__GENERATEGRAPHIC__</' . cCreateImage::NAMESPACEWORD1 . ':graphic>', $this->xml);
    }

    protected function fGenerateGRAPHICDATA($uri="http://schemas.openxmlformats.org/drawingml/2006/picture") {
        $this->xml = str_replace('__GENERATEGRAPHIC__', '<' . cCreateImage::NAMESPACEWORD1 . ':graphicData uri="' . $uri . '">__GENERATEGRAPHICDATA__</' . cCreateImage::NAMESPACEWORD1 . ':graphicData>', $this->xml);
    }

    protected function fGeneratePIC($pic="http://schemas.openxmlformats.org/drawingml/2006/picture") {
        $this->xml = str_replace('__GENERATEGRAPHICDATA__', '<' . cCreateImage::NAMESPACEWORD2 . ':pic xmlns:pic="' . $pic . '">__GENERATEPIC__</' . cCreateImage::NAMESPACEWORD2 . ':pic>', $this->xml);
    }

    protected function fGenerateNVPICPR() {
        $this->xml = str_replace('__GENERATEPIC__', '<' . cCreateImage::NAMESPACEWORD2 . ':nvPicPr>__GENERATENVPICPR__</' . cCreateImage::NAMESPACEWORD2 . ':nvPicPr>__GENERATEPIC__', $this->xml);
    }

    protected function fGenerateCNVPR($id='0') {
        $this->xml = str_replace('__GENERATENVPICPR__', '<' . cCreateImage::NAMESPACEWORD2 . ':cNvPr id="' . $id . '" name="' . $this->getName() . '"></' . cCreateImage::NAMESPACEWORD2 . ':cNvPr>__GENERATENVPICPR__', $this->xml);
    }

    protected function fGenerateCNVPICPR() {
        $this->xml = str_replace('__GENERATENVPICPR__', '<' . cCreateImage::NAMESPACEWORD2 . ':cNvPicPr></' . cCreateImage::NAMESPACEWORD2 . ':cNvPicPr>__GENERATENVPICPR__', $this->xml);
    }

    protected function fGenerateBLIPFILL() {
        $this->xml = str_replace('__GENERATEPIC__', '<' . cCreateImage::NAMESPACEWORD2 . ':blipFill>__GENERATEBLIPFILL__</' . cCreateImage::NAMESPACEWORD2 . ':blipFill>__GENERATEPIC__', $this->xml);
    }

    protected function fGenerateBLIP($cstate='print') {
        $this->xml = str_replace('__GENERATEBLIPFILL__', '<' . cCreateImage::NAMESPACEWORD1 . ':blip r:embed="rId' . $this->getRId() . '" cstate="' . $cstate . '"></' . cCreateImage::NAMESPACEWORD1 . ':blip>__GENERATEBLIPFILL__', $this->xml);
    }

    protected function fGenerateSTRETCH() {
        $this->xml = str_replace('__GENERATEBLIPFILL__', '<' . cCreateImage::NAMESPACEWORD1 . ':stretch>__GENERATESTRETCH__</' . cCreateImage::NAMESPACEWORD1 . ':stretch>__GENERATEBLIPFILL__', $this->xml);
    }

    protected function fGenerateFILLRECT() {
        $this->xml = str_replace('__GENERATESTRETCH__', '<' . cCreateImage::NAMESPACEWORD1 . ':fillRect></' . cCreateImage::NAMESPACEWORD1 . ':fillRect>', $this->xml);
    }

    protected function fGenerateSPPR() {
        $this->xml = str_replace('__GENERATEPIC__', '<' . cCreateImage::NAMESPACEWORD2 . ':spPr>__GENERATESPPR__</' . cCreateImage::NAMESPACEWORD2 . ':spPr>', $this->xml);
    }

    protected function fGenerateXFRM() {
        $this->xml = str_replace('__GENERATESPPR__', '<' . cCreateImage::NAMESPACEWORD1 . ':xfrm>__GENERATEXFRM__</' . cCreateImage::NAMESPACEWORD1 . ':xfrm>__GENERATESPPR__', $this->xml);
    }

    protected function fGenerateOFF($x='0', $y='0') {
        $this->xml = str_replace('__GENERATEXFRM__', '<' . cCreateImage::NAMESPACEWORD1 . ':off x="' . $x . '" y="' . $y . '"></' . cCreateImage::NAMESPACEWORD1 . ':off>__GENERATEXFRM__', $this->xml);
    }

    protected function fGenerateEXT($cx='2997226', $cy='2247918') {
        $this->xml = str_replace('__GENERATEXFRM__', '<' . cCreateImage::NAMESPACEWORD1 . ':ext cx="' . $cx . '" cy="' . $cy . '"></' . cCreateImage::NAMESPACEWORD1 . ':ext>__GENERATEXFRM__', $this->xml);
    }

    protected function fGeneratePRSTGEOM($prst='rect') {
        $this->xml = str_replace('__GENERATESPPR__', '<' . cCreateImage::NAMESPACEWORD1 . ':prstGeom prst="' . $prst . '">__GENERATEPRSTGEOM__</' . cCreateImage::NAMESPACEWORD1 . ':prstGeom>__GENERATESPPR__', $this->xml);
    }

    protected function fGenerateAVLST() {
        $this->xml = str_replace('__GENERATEPRSTGEOM__', '<' . cCreateImage::NAMESPACEWORD1 . ':avLst></' . cCreateImage::NAMESPACEWORD1 . ':avLst>__GENERATEPRSTGEOM__', $this->xml);
    }

    protected function fGenerateLN($w ='12700') {
        $this->xml = str_replace('__GENERATESPPR__', '<' . cCreateImage::NAMESPACEWORD1 . ':ln w="' . $w . '">__GENERATELN__</' . cCreateImage::NAMESPACEWORD1 . ':ln>__GENERATESPPR__', $this->xml);
    }

    protected function fGenerateSOLIDFILL() {
        $this->xml = str_replace('__GENERATELN__', '<' . cCreateImage::NAMESPACEWORD1 . ':solidFill>__GENERATESOLIDFILL__</' . cCreateImage::NAMESPACEWORD1 . ':solidFill>__GENERATELN__', $this->xml);
    }

    protected function fGenerateSCHEMECLR($val ='tx1') {
        $this->xml = str_replace('__GENERATESOLIDFILL__', '<' . cCreateImage::NAMESPACEWORD1 . ':schemeClr val="' . $val . '"></' . cCreateImage::NAMESPACEWORD1 . ':schemeClr>', $this->xml);
    }

    protected function fGeneratePRSTDASH($val= 'sysDash') {
        $this->xml = str_replace('__GENERATELN__', '<' . cCreateImage::NAMESPACEWORD1 . ':prstDash val="' . $val . '"></' . cCreateImage::NAMESPACEWORD1 . ':prstDash>__GENERATELN__', $this->xml);
    }

    protected function fCleanTemplate() {
        $this->xml = preg_replace('/__[A-Z]+__/', '', $this->xml);
    }

    protected function fGenerateQUITAR() {
        $this->xml = '<' . cCreateElement::NAMESPACEWORD . ':r>__GENERATER__</' . cCreateElement::NAMESPACEWORD . ':r>';
    }

    protected function fGeneratePSTYLE($val = 'Textonotaalfinal') {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':pStyle ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':pStyle>', $this->xml);
    }

    protected function fGenerateRSTYLE($val = 'Refdenotaalfinal') {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':rStyle ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':rStyle>', $this->xml);
    }

    protected function fGenerateRFONTS($strFont) {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':rFonts ' . cCreateElement::NAMESPACEWORD . ':ascii="' . $strFont . '" ' . cCreateElement::NAMESPACEWORD . ':hAnsi="' . $strFont . '" ' . cCreateElement::NAMESPACEWORD . ':cs="' . $strFont . '"></' . cCreateElement::NAMESPACEWORD . ':rFonts>__GENERATERPR__', $this->xml);
    }

}
?>