<?php
  /**
   * @author 2mdc.com
   * @version 
   */

define("MATHNAMESPACE", "m");

  class cCreateElement {
    var $xml;

    function fGenerateP() {
      $this->xml = '<'.NAMESPACE.':p>__GENERATEP__</'.NAMESPACE.':p>';
    }

    function fGeneratePPR() {
      $this->xml = str_replace('__GENERATEP__', '<'.NAMESPACE.':pPr>__GENERATEPPR__</'.NAMESPACE.':pPr>__GENERATER__', $this->xml);
    }

    function fGenerateT($strDat) {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':t>'.$strDat.'</'.NAMESPACE.':t>', $this->xml);
    }

    function fGenerateRPR() {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':rPr>__GENERATERPR__</'.NAMESPACE.':rPr>__GENERATER__', $this->xml);
    }
  
    function fGenerateJC($strVal = '') {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':jc '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':jc>', $this->xml);
    }
  
    function fGenerateNOPROOF() {
      $this->xml = str_replace('__GENERATERPR__', '<'.NAMESPACE.':noProof></'.NAMESPACE.':noProof>__GENERATEPPR__', $this->xml);
    }

    function fGenerateR() {
      if(!empty($this->xml)) {
        if(preg_match("/__GENERATEP__/", $this->xml)) {
          $this->xml = str_replace('__GENERATEP__', '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>', $this->xml);
        }
        elseif(preg_match("/__GENERATER__/", $this->xml)) {
          $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>', $this->xml);
        }
      }
      else {
        $this->xml = '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>';
      }
    }

    function fGenerateDRAWING() {
    	$this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':drawing>__GENERATEDRAWING__</'.NAMESPACE.':drawing>', $this->xml);
    }
  
    function fGenerateINLINE($distT= '0', $distB='0', $distL='0', $distR='0'){
    	$this->xml = str_replace('__GENERATEDRAWING__', '<'.IMGNAMESPACE.':inline distT="'.$distT.'" distB="'.$distB.'" distL="'.$distL.'" distR="'.$distR.'">__GENERATEINLINE__</'.IMGNAMESPACE.':inline>', $this->xml);    	
    }
  
    function fGenerateANCHOR($behindDoc=0, $distT= '0', $distB='0', $distL='114300', $distR='114300', $simplePos=0, $relativeHeight='251658240', $locked=0, $layoutInCell=1, $allowOverlap=1){
    	$this->xml = str_replace('__GENERATEDRAWING__', '<'.IMGNAMESPACE.':anchor distT="'.$distT.'" distB="'.$distB.'" distL="'.$distL.'" distR="'.$distR.'" simplePos="'.$simplePos.'" relativeHeight="'.$relativeHeight.'" behindDoc="'.$behindDoc.'" locked="'.$locked.'" layoutInCell="'.$layoutInCell.'" allowOverlap="'.$allowOverlap.'">__GENERATEINLINE__</'.IMGNAMESPACE.':anchor>', $this->xml);    	
    }
  
    function fGenerateSIMPLEPOS($x='0', $y='0') {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':simplePos x="'.$x.'" y="'.$y.'"></'.IMGNAMESPACE.':simplePos>__GENERATEINLINE__', $this->xml);    	
    }
  
    function fGeneratePOSITIONH($relativeFrom = 'column') {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':positionH relativeFrom="'.$relativeFrom.'">__GENERATEPOSITION__</'.IMGNAMESPACE.':positionH>__GENERATEINLINE__', $this->xml);    	
    }
    
    function fGeneratePOSITIONV($relativeFrom = 'paragraph') {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':positionV relativeFrom="'.$relativeFrom.'">__GENERATEPOSITION__</'.IMGNAMESPACE.':positionV>__GENERATEINLINE__', $this->xml);    	
    }
    
    function fGeneratePOSOFFSET($num) {
    	$this->xml = str_replace('__GENERATEPOSITION__', '<'.IMGNAMESPACE.':posOffset>'.$num.'</'.IMGNAMESPACE.':posOffset>', $this->xml);    	
    }
    
    function fGenerateEXTENT($cx='2986543', $cy='2239906') {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':extent cx="'.$cx.'" cy="'.$cy.'"></'.IMGNAMESPACE.':extent>__GENERATEINLINE__', $this->xml);    	
    }
  
    function fGenerateEFFECTEXTENT($l="19050", $t="0", $r="4307", $b="0") {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':effectExtent l="'.$l.'" t="'.$t.'" r="'.$r.'" b="'.$b.'"></'.IMGNAMESPACE.':effectExtent>__GENERATEINLINE__', $this->xml);    	
    }
  
    function fGenerateWRAPSQUARE($wrapText="bothSides") {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':wrapSquare wrapText="'.$wrapText.'"></'.IMGNAMESPACE.':wrapSquare>__GENERATEINLINE__', $this->xml);    	
    }
  
    function fGenerateWRAPNONE() {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':wrapNone></'.IMGNAMESPACE.':wrapNone>__GENERATEINLINE__', $this->xml);    	
    }
  
    function fGenerateWRAPTOPANDBOTTOM() {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':wrapTopAndBottom></'.IMGNAMESPACE.':wrapTopAndBottom>__GENERATEINLINE__', $this->xml);    	
    }
  
    function fGenerateWRAPTHROUGH($wrapText = 'bothSides') {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':wrapThrough wrapText="' . $wrapText . '">__GENERATEWRAPTHROUGH__</'.IMGNAMESPACE.':wrapThrough>__GENERATEINLINE__', $this->xml);    	
    }
  
    function fGenerateWRAPPOLYGON($edited = '0') {
    	$this->xml = str_replace('__GENERATEWRAPTHROUGH__', '<'.IMGNAMESPACE.':wrapPolygon edited="' . $edited . '">__GENERATEWRAPPOLYGON__</'.IMGNAMESPACE.':wrapPolygon>', $this->xml);    	
    }
  
    function fGenerateSTART($x = '-198', $y = '0') {
    	$this->xml = str_replace('__GENERATEWRAPPOLYGON__', '<'.IMGNAMESPACE.':start x="' . $x . '" y="' . $y . '"></'.IMGNAMESPACE.':start>__GENERATEWRAPPOLYGON__', $this->xml);    	
    }
    
    function fGenerateLINETO($x = '-198', $y = '21342') {
    	$this->xml = str_replace('__GENERATEWRAPPOLYGON__', '<'.IMGNAMESPACE.':lineTo x="' . $x . '" y="' . $y . '"></'.IMGNAMESPACE.':lineTo>__GENERATEWRAPPOLYGON__', $this->xml);    	
    }
    
    function fGenerateDOCPR($id="1", $name="0 Imagen") {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':docPr id="'.$id.'" name="'.$name.'" descr="'.$this->getName().'"></'.IMGNAMESPACE.':docPr>__GENERATEINLINE__', $this->xml);    	
    }
  
    function fGenerateCNVGRAPHICFRAMEPR() {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE.':cNvGraphicFramePr>__GENERATECNVGRAPHICFRAMEPR__</'.IMGNAMESPACE.':cNvGraphicFramePr>__GENERATEINLINE__', $this->xml);    	
    }
  
    function fGenerateGRAPHICPRAMELOCKS($noChangeAspect = '') {
    	$xmlAux = '<'.IMGNAMESPACE1.':graphicFrameLocks xmlns:a="http://schemas.openxmlformats.org/drawingml/2006/main"';
    	if($noChangeAspect != '') 
    		$xmlAux .= ' noChangeAspect="'.$noChangeAspect.'"';
    	$xmlAux .= '></'.IMGNAMESPACE1.':graphicFrameLocks>';
    	
    	$this->xml = str_replace('__GENERATECNVGRAPHICFRAMEPR__', $xmlAux, $this->xml);    	
    }
  
    function fGenerateGRAPHIC ($xmlns="http://schemas.openxmlformats.org/drawingml/2006/main") {
    	$this->xml = str_replace('__GENERATEINLINE__', '<'.IMGNAMESPACE1.':graphic xmlns:a="'.$xmlns.'">__GENERATEGRAPHIC__</'.IMGNAMESPACE1.':graphic>', $this->xml);    	
    }
  
    function fGenerateGRAPHICDATA($uri="http://schemas.openxmlformats.org/drawingml/2006/picture") {
    	$this->xml = str_replace('__GENERATEGRAPHIC__', '<'.IMGNAMESPACE1.':graphicData uri="'.$uri.'">__GENERATEGRAPHICDATA__</'.IMGNAMESPACE1.':graphicData>', $this->xml);    	
    }
  
    function fGeneratePIC($pic="http://schemas.openxmlformats.org/drawingml/2006/picture") {
    	$this->xml = str_replace('__GENERATEGRAPHICDATA__', '<'.IMGNAMESPACE2.':pic xmlns:pic="'.$pic.'">__GENERATEPIC__</'.IMGNAMESPACE2.':pic>', $this->xml);    	
    }
  
    function fGenerateNVPICPR() {
    	$this->xml = str_replace('__GENERATEPIC__', '<'.IMGNAMESPACE2.':nvPicPr>__GENERATENVPICPR__</'.IMGNAMESPACE2.':nvPicPr>__GENERATEPIC__', $this->xml);    	
    }
  
    function fGenerateCNVPR($id='0') {
    	$this->xml = str_replace('__GENERATENVPICPR__', '<'.IMGNAMESPACE2.':cNvPr id="'.$id.'" name="'.$this->getName().'"></'.IMGNAMESPACE2.':cNvPr>__GENERATENVPICPR__', $this->xml);    	
    }
  
    function fGenerateCNVPICPR() {
    	$this->xml = str_replace('__GENERATENVPICPR__', '<'.IMGNAMESPACE2.':cNvPicPr></'.IMGNAMESPACE2.':cNvPicPr>__GENERATENVPICPR__', $this->xml);    	
    }
  
    function fGenerateBLIPFILL() {
    	$this->xml = str_replace('__GENERATEPIC__', '<'.IMGNAMESPACE2.':blipFill>__GENERATEBLIPFILL__</'.IMGNAMESPACE2.':blipFill>__GENERATEPIC__', $this->xml);    	
    }
  
    function fGenerateBLIP($cstate='print') {
    	$this->xml = str_replace('__GENERATEBLIPFILL__', '<'.IMGNAMESPACE1.':blip r:embed="rId'.$this->getRId().'" cstate="'.$cstate.'"></'.IMGNAMESPACE1.':blip>__GENERATEBLIPFILL__', $this->xml);    	
    }
  
    function fGenerateSTRETCH() {
    	$this->xml = str_replace('__GENERATEBLIPFILL__', '<'.IMGNAMESPACE1.':stretch>__GENERATESTRETCH__</'.IMGNAMESPACE1.':stretch>__GENERATEBLIPFILL__', $this->xml);    	
    }
  
    function fGenerateFILLRECT() {
    	$this->xml = str_replace('__GENERATESTRETCH__', '<'.IMGNAMESPACE1.':fillRect></'.IMGNAMESPACE1.':fillRect>', $this->xml);    	
    }
  
    function fGenerateSPPR() {
    	$this->xml = str_replace('__GENERATEPIC__', '<'.IMGNAMESPACE2.':spPr>__GENERATESPPR__</'.IMGNAMESPACE2.':spPr>', $this->xml);    	
    }
  
    function fGenerateXFRM() {
    	$this->xml = str_replace('__GENERATESPPR__', '<'.IMGNAMESPACE1.':xfrm>__GENERATEXFRM__</'.IMGNAMESPACE1.':xfrm>__GENERATESPPR__', $this->xml);    	
    }
  
    function fGenerateOFF($x='0', $y='0') {
    	$this->xml = str_replace('__GENERATEXFRM__', '<'.IMGNAMESPACE1.':off x="'.$x.'" y="'.$y.'"></'.IMGNAMESPACE1.':off>__GENERATEXFRM__', $this->xml);    	
    }
  
    function fGenerateEXT($cx='2997226', $cy='2247918') {
    	$this->xml = str_replace('__GENERATEXFRM__', '<'.IMGNAMESPACE1.':ext cx="'.$cx.'" cy="'.$cy.'"></'.IMGNAMESPACE1.':ext>__GENERATEXFRM__', $this->xml);    	
    }
  
    function fGeneratePRSTGEOM($prst='rect') {
    	$this->xml = str_replace('__GENERATESPPR__', '<'.IMGNAMESPACE1.':prstGeom prst="'.$prst.'">__GENERATEPRSTGEOM__</'.IMGNAMESPACE1.':prstGeom>__GENERATESPPR__', $this->xml);    	
    }
  
    function fGenerateAVLST() {
    	$this->xml = str_replace('__GENERATEPRSTGEOM__', '<'.IMGNAMESPACE1.':avLst></'.IMGNAMESPACE1.':avLst>__GENERATEPRSTGEOM__', $this->xml);    	
    }
  
    function fGenerateLN($w ='12700') {
    	$this->xml = str_replace('__GENERATESPPR__', '<'.IMGNAMESPACE1.':ln w="' . $w . '">__GENERATELN__</'.IMGNAMESPACE1.':ln>__GENERATESPPR__', $this->xml);    	
    }
  
    function fGenerateSOLIDFILL() {
    	$this->xml = str_replace('__GENERATELN__', '<'.IMGNAMESPACE1.':solidFill>__GENERATESOLIDFILL__</'.IMGNAMESPACE1.':solidFill>__GENERATELN__', $this->xml);    	
    }
  
    function fGenerateSCHEMECLR($val ='tx1') {
    	$this->xml = str_replace('__GENERATESOLIDFILL__', '<'.IMGNAMESPACE1.':schemeClr val="' . $val . '"></'.IMGNAMESPACE1.':schemeClr>', $this->xml);    	
    }
  
    function fGeneratePRSTDASH($val= 'sysDash') {
    	$this->xml = str_replace('__GENERATELN__', '<'.IMGNAMESPACE1.':prstDash val="' . $val . '"></'.IMGNAMESPACE1.':prstDash>__GENERATELN__', $this->xml);    	
    }
  
    function fCleanTemplate() {
      $this->xml = preg_replace('/__[A-Z]+__/', '', $this->xml);
    }
    
    function fGenerateQUITAR() {
    	$this->xml = '<'.NAMESPACE.':r>__GENERATER__</'.NAMESPACE.':r>';
    }
    
    function fGeneratePSTYLE($val = 'Textonotaalfinal') {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':pStyle '.NAMESPACE.':val="'.$val.'"></'.NAMESPACE.':pStyle>', $this->xml);
    }
  
    function fGenerateRSTYLE($val = 'Refdenotaalfinal') {
      $this->xml = str_replace('__GENERATERPR__', '<'.NAMESPACE.':rStyle '.NAMESPACE.':val="'.$val.'"></'.NAMESPACE.':rStyle>', $this->xml);
    }
  
  }
?>