<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  define("GRANAMESPACE", 'c');

  class cCreateGraphic extends cCreateElement {
    var $rscInstance = NULL;
    var $rId;
    var $type;
    var $name;
    var $xmlChart;
    function cCreateGraphic() {
    	$this->rId = '';
	    $this->type = '';
    	$this->xml='';
    	$this->name = '';
    	$this->xmlChart = '';
    }

    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateGraphic();
       }
       return $this->rscInstance;
    }
    
  	function setRId($rId) {
      $this->rId = $rId;
    }
  
  	function getRId() {
      return $this->rId;
    }
    
  	function setName($name) {
      $this->name = $name;
    }
  
  	function getName() {
      return $this->name;
    }
  
  	function setXmlChart($xmlChart) {
      $this->xmlChart = $xmlChart;
    }
  
  	function getXmlChart() {
      return $this->xmlChart;
    }
    
  	function fGenerateCHARTSPACE() {
    	$this->xmlChart = '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?><'.GRANAMESPACE.':chartSpace xmlns:c="http://schemas.openxmlformats.org/drawingml/2006/chart" xmlns:a="http://schemas.openxmlformats.org/drawingml/2006/main" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships">__GENERATECHARTSPACE__</'.GRANAMESPACE.':chartSpace>';
    }
  
    function fGenerateDATE1904($val = '1') {
    	$this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<'.GRANAMESPACE.':date1904 val="' . $val . '"></'.GRANAMESPACE.':date1904>__GENERATECHARTSPACE__', $this->xmlChart);
    }
  
    function fGenerateLANG($val = 'es-ES') {
    	$this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<'.GRANAMESPACE.':lang val="' . $val . '"></'.GRANAMESPACE.':lang>__GENERATECHARTSPACE__', $this->xmlChart);
    }
  
    function fGenerateSTYLE($val = '2') {
    	$this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<'.GRANAMESPACE.':style val="' . $val . '"></'.GRANAMESPACE.':style>__GENERATECHARTSPACE__', $this->xmlChart);
    }
  
    function fGenerateTITLE() {
    	$this->xmlChart = str_replace('__GENERATECHART__', '<'.GRANAMESPACE.':title>__GENERATETITLE__</'.GRANAMESPACE.':title>__GENERATECHART__', $this->xmlChart);
    }
    
    function fGenerateTITLETX() {
    	$this->xmlChart = str_replace('__GENERATETITLE__', '<'.GRANAMESPACE.':tx>__GENERATETITLETX__</'.GRANAMESPACE.':tx>__GENERATETITLE__', $this->xmlChart);
    }
   
    function fGenerateRICH() {
    	$this->xmlChart = str_replace('__GENERATETITLETX__', '<'.GRANAMESPACE.':rich>__GENERATERICH__</'.GRANAMESPACE.':rich>__GENERATETITLETX__', $this->xmlChart);
    }
   
    function fGenerateBODYPR() {
    	$this->xmlChart = str_replace('__GENERATERICH__', '<'.IMGNAMESPACE1.':bodyPr></'.IMGNAMESPACE1.':bodyPr>__GENERATERICH__', $this->xmlChart);
    }
  
    function fGenerateLSTSTYLE() {
    	$this->xmlChart = str_replace('__GENERATERICH__', '<'.IMGNAMESPACE1.':lstStyle></'.IMGNAMESPACE1.':lstStyle>__GENERATERICH__', $this->xmlChart);
    }
  
    function fGenerateTITLEP() {
    	$this->xmlChart = str_replace('__GENERATERICH__', '<'.IMGNAMESPACE1.':p>__GENERATETITLEP__</'.IMGNAMESPACE1.':p>__GENERATERICH__', $this->xmlChart);
    }
  
    function fGenerateTITLEPPR() {
    	$this->xmlChart = str_replace('__GENERATETITLEP__', '<'.IMGNAMESPACE1.':pPr>__GENERATETITLEPPR__</'.IMGNAMESPACE1.':pPr>__GENERATETITLEP__', $this->xmlChart);
    }
    
    function fGenerateDEFRPR() {
    	$this->xmlChart = str_replace('__GENERATETITLEPPR__', '<'.IMGNAMESPACE1.':defRPr></'.IMGNAMESPACE1.':defRPr>__GENERATETITLEPPR__', $this->xmlChart);
    }
  
    function fGenerateTITLER() {
    	$this->xmlChart = str_replace('__GENERATETITLEP__', '<'.IMGNAMESPACE1.':r>__GENERATETITLER__</'.IMGNAMESPACE1.':r>__GENERATETITLEP__', $this->xmlChart);
    }
  
    function fGenerateTITLERPR($lang = 'es-ES') {
    	$this->xmlChart = str_replace('__GENERATETITLER__', '<'.IMGNAMESPACE1.':rPr lang="'. $lang .'"></'.IMGNAMESPACE1.':rPr>__GENERATETITLER__', $this->xmlChart);
    }
    
    function fGenerateTITLET($nombre='') {
    	$this->xmlChart = str_replace('__GENERATETITLER__', '<'.IMGNAMESPACE1.':t>'. $nombre .'</'.IMGNAMESPACE1.':t>__GENERATETITLER__', $this->xmlChart);
    }
    
    function fGenerateTITLELAYOUT($nombre='') {
    	$this->xmlChart = str_replace('__GENERATETITLE__', '<'.IMGNAMESPACE1.':layout></'.IMGNAMESPACE1.':layout>', $this->xmlChart);
    }
    
    function fGenerateAUTOTITLEDELETED($val = '1') {
    	$this->xmlChart = str_replace('__GENERATECHART__', '<'.GRANAMESPACE.':autoTitleDeleted val="' . $val . '"></'.GRANAMESPACE.':autoTitleDeleted>__GENERATECHART__', $this->xmlChart);
    }

    function fGenerateCHART() {
    	$this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<'.GRANAMESPACE.':chart>__GENERATECHART__</'.GRANAMESPACE.':chart>__GENERATECHARTSPACE__', $this->xmlChart);
    }
  
    function fGeneratePLOTAREA() {
    	$this->xmlChart = str_replace('__GENERATECHART__', '<'.GRANAMESPACE.':plotArea>__GENERATEPLOTAREA__</'.GRANAMESPACE.':plotArea>__GENERATECHART__', $this->xmlChart);
    }
  
    function fGenerateLAYOUT() {
    	$this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<'.GRANAMESPACE.':layout></'.GRANAMESPACE.':layout>__GENERATEPLOTAREA__', $this->xmlChart);
    }
  
    function fGeneratePIECHART() {
    	$this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<'.GRANAMESPACE.':pieChart>__GENERATETYPECHART__</'.GRANAMESPACE.':pieChart>__GENERATEPLOTAREA__', $this->xmlChart);
    }
  
    function fGenerateBARCHART() {
    	$this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<'.GRANAMESPACE.':barChart>__GENERATETYPECHART__</'.GRANAMESPACE.':barChart>__GENERATEPLOTAREA__', $this->xmlChart);
    }
    
    function fGenerateLINECHART() {
    	$this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<'.GRANAMESPACE.':lineChart>__GENERATETYPECHART__</'.GRANAMESPACE.':lineChart>__GENERATEPLOTAREA__', $this->xmlChart);
    }
    
    function fGenerateVARYCOLORS($val='1') {
    	$this->xmlChart = str_replace('__GENERATETYPECHART__', '<'.GRANAMESPACE.':varyColors val="' . $val . '"></'.GRANAMESPACE.':varyColors>__GENERATETYPECHART__', $this->xmlChart);
    }
    
    function fGenerateBARDIR($val='bar') {
    	$this->xmlChart = str_replace('__GENERATETYPECHART__', '<'.GRANAMESPACE.':barDir val="' . $val . '"></'.GRANAMESPACE.':barDir>__GENERATETYPECHART__', $this->xmlChart);
    }
    
    function fGenerateGROUPING($val='stacked') {
    	$this->xmlChart = str_replace('__GENERATETYPECHART__', '<'.GRANAMESPACE.':grouping val="' . $val . '"></'.GRANAMESPACE.':grouping>__GENERATETYPECHART__', $this->xmlChart);
    }
  
    function fGenerateSER() {
    	$this->xmlChart = str_replace('__GENERATETYPECHART__', '<'.GRANAMESPACE.':ser>__GENERATESER__</'.GRANAMESPACE.':ser>__GENERATETYPECHART__', $this->xmlChart);
    }
  
    function fGenerateIDX($val='0') {
    	$this->xmlChart = str_replace('__GENERATESER__', '<'.GRANAMESPACE.':idx val="' . $val . '"></'.GRANAMESPACE.':idx>__GENERATESER__', $this->xmlChart);
    }
  
    function fGenerateORDER($val='0') {
    	$this->xmlChart = str_replace('__GENERATESER__', '<'.GRANAMESPACE.':order val="' . $val . '"></'.GRANAMESPACE.':order>__GENERATESER__', $this->xmlChart);
    }
  
    function fGenerateTX() {
    	$this->xmlChart = str_replace('__GENERATESER__', '<'.GRANAMESPACE.':tx>__GENERATETX__</'.GRANAMESPACE.':tx>__GENERATESER__', $this->xmlChart);
    }
  
    function fGenerateSTRREF() {
    	$this->xmlChart = str_replace('__GENERATETX__', '<'.GRANAMESPACE.':strRef>__GENERATESTRREF__</'.GRANAMESPACE.':strRef>__GENERATETX__', $this->xmlChart);
    }
  
    function fGenerateF($val='Hoja1!$B$1') {
    	$this->xmlChart = str_replace('__GENERATESTRREF__', '<'.GRANAMESPACE.':f>'. $val .'</'.GRANAMESPACE.':f>__GENERATESTRREF__', $this->xmlChart);
    }
  
    function fGenerateSTRCACHE() {
    	$this->xmlChart = str_replace('__GENERATESTRREF__', '<'.GRANAMESPACE.':strCache>__GENERATESTRCACHE__</'.GRANAMESPACE.':strCache>__GENERATESTRREF__', $this->xmlChart);
    }
  
    function fGeneratePTCOUNT($val='1') {
    	$this->xmlChart = str_replace('__GENERATESTRCACHE__', '<'.GRANAMESPACE.':ptCount val="' . $val . '"></'.GRANAMESPACE.':ptCount>__GENERATESTRCACHE__', $this->xmlChart);
    }
  
    function fGeneratePT($idx='0') {
    	$this->xmlChart = str_replace('__GENERATESTRCACHE__', '<'.GRANAMESPACE.':pt idx="' . $idx . '">__GENERATEPT__</'.GRANAMESPACE.':pt>__GENERATESTRCACHE__', $this->xmlChart);
    }
  
    function fGenerateV($idx='Ventas') {
    	$this->xmlChart = str_replace('__GENERATEPT__', '<'.GRANAMESPACE.':v>'. $idx .'</'.GRANAMESPACE.':v>', $this->xmlChart);
    }
  
    function fGenerateCAT() {
    	$this->xmlChart = str_replace('__GENERATESER__', '<'.GRANAMESPACE.':cat>__GENERATETX__</'.GRANAMESPACE.':cat>__GENERATESER__', $this->xmlChart);
    }
  
    function fGenerateVAL() {
    	$this->xmlChart = str_replace('__GENERATESER__', '<'.GRANAMESPACE.':val>__GENERATETX__</'.GRANAMESPACE.':val>__GENERATESER__', $this->xmlChart);
    }
  
    function fGenerateNUMCACHE() {
    	$this->xmlChart = str_replace('__GENERATESTRREF__', '<'.GRANAMESPACE.':numCache>__GENERATESTRCACHE__</'.GRANAMESPACE.':numCache>__GENERATESTRREF__', $this->xmlChart);
    }
  
    function fGenerateNUMREF() {
    	$this->xmlChart = str_replace('__GENERATETX__', '<'.GRANAMESPACE.':numRef>__GENERATESTRREF__</'.GRANAMESPACE.':numRef>__GENERATETX__', $this->xmlChart);
    }
  
    function fGenerateFORMATCODE($val = 'General') {
    	$this->xmlChart = str_replace('__GENERATESTRCACHE__', '<'.GRANAMESPACE.':formatCode>'.$val . '</'.GRANAMESPACE.':formatCode>__GENERATESTRCACHE__', $this->xmlChart);
    }
  
    function fGenerateLEGEND() {
    	$this->xmlChart = str_replace('__GENERATECHART__', '<'.GRANAMESPACE.':legend>__GENERATELEGEND__</'.GRANAMESPACE.':legend>__GENERATECHART__', $this->xmlChart);
    }
  
    function fGenerateLEGENDPOS($val='r') {
    	$this->xmlChart = str_replace('__GENERATELEGEND__', '<'.GRANAMESPACE.':legendPos val="' . $val . '"></'.GRANAMESPACE.':legendPos>', $this->xmlChart);
    }
  
    function fGeneratePLOTVISONLY($val='1') {
    	$this->xmlChart = str_replace('__GENERATECHART__', '<'.GRANAMESPACE.':plotVisOnly val="' . $val . '"></'.GRANAMESPACE.':plotVisOnly>__GENERATECHART__', $this->xmlChart);
    }
  
    function fGenerateEXTERNALDATA($val='rId1') {
    	$this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<'.GRANAMESPACE.':externalData r:id="' . $val . '"></'.GRANAMESPACE.':externalData>', $this->xmlChart);
    }
  
    function fGenerateSPPR() {
    	$this->xmlChart = str_replace('__GENERATECHARTSPACE__', '<'.GRANAMESPACE.':spPr>__GENERATESPPR__</'.GRANAMESPACE.':spPr>__GENERATECHARTSPACE__', $this->xmlChart);
    }
  
    function fGenerateLN() {
    	$this->xmlChart = str_replace('__GENERATESPPR__', '<'.IMGNAMESPACE1.':ln>__GENERATELN__</'.IMGNAMESPACE1.':ln>', $this->xmlChart);
    }
  
    function fGenerateNOFILL() {
    	$this->xmlChart = str_replace('__GENERATELN__', '<'.IMGNAMESPACE1.':noFill></'.IMGNAMESPACE1.':noFill>', $this->xmlChart);
    }
  
    function fGenerateOVERLAP($val='100') {
    	$this->xmlChart = str_replace('__GENERATETYPECHART__', '<'.GRANAMESPACE.':overlap val="' . $val . '"></'.GRANAMESPACE.':overlap>__GENERATETYPECHART__', $this->xmlChart);
    }
  
    function fGenerateSHAPE($val='box') {
    	$this->xmlChart = str_replace('__GENERATETYPECHART__', '<'.GRANAMESPACE.':shape val="' . $val . '"></'.GRANAMESPACE.':shape>__GENERATETYPECHART__', $this->xmlChart);
    }
      
    function fGenerateAXID($val='59034624') {
    	$this->xmlChart = str_replace('__GENERATETYPECHART__', '<'.GRANAMESPACE.':axId val="' . $val . '"></'.GRANAMESPACE.':axId>__GENERATETYPECHART__', $this->xmlChart);
    }
    
    function fGenerateFIRSTSLICEANG($val='0') {
    	$this->xmlChart = str_replace('__GENERATETYPECHART__', '<'.GRANAMESPACE.':firstSliceAng val="' . $val . '"></'.GRANAMESPACE.':firstSliceAng>', $this->xmlChart);
    }
  
    function fGenerateDLBLS() {
    	$this->xmlChart = str_replace('__GENERATETYPECHART__', '<'.GRANAMESPACE.':dLbls>__GENERATEDLBLS__</'.GRANAMESPACE.':dLbls>__GENERATETYPECHART__', $this->xmlChart);
    }
  
    function fGenerateSHOWPERCENT($val='0') {
    	$this->xmlChart = str_replace('__GENERATEDLBLS__', '<'.GRANAMESPACE.':showPercent val="' . $val . '"></'.GRANAMESPACE.':showPercent>', $this->xmlChart);
    }
  
    function fGenerateDOCUMENTCHART() {
    	$this->xml = str_replace('__GENERATEGRAPHICDATA__', '<'.GRANAMESPACE.':chart xmlns:c="http://schemas.openxmlformats.org/drawingml/2006/chart" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships" r:id="rId'. $this->getRId() .'"></'.GRANAMESPACE.':chart>', $this->xml);
    }
   
    function fGenerateCATAX() {
    	$this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<'.GRANAMESPACE.':catAx>__GENERATEAX__</'.GRANAMESPACE.':catAx>__GENERATEPLOTAREA__', $this->xmlChart);
    } 
    
    function fGenerateVALAX() {
    	$this->xmlChart = str_replace('__GENERATEPLOTAREA__', '<'.GRANAMESPACE.':valAx>__GENERATEAX__</'.GRANAMESPACE.':valAx>', $this->xmlChart);
    }
     
    function fGenerateAXAXID($val='59034624') {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':axId val="' . $val . '"></'.GRANAMESPACE.':axId>__GENERATEAX__', $this->xmlChart);
    }
  
    function fGenerateSCALING() {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':scaling>__GENERATESCALING__</'.GRANAMESPACE.':scaling>__GENERATEAX__', $this->xmlChart);
    }
  
    function fGenerateORIENTATION($val = 'minMax') {
    	$this->xmlChart = str_replace('__GENERATESCALING__', '<'.GRANAMESPACE.':orientation val="' . $val . '"></'.GRANAMESPACE.':orientation>', $this->xmlChart);
    }
  
    function fGenerateAXPOS($val = 'b') {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':axPos val="' . $val . '"></'.GRANAMESPACE.':axPos>__GENERATEAX__', $this->xmlChart);
    }
  
    function fGenerateTICKLBLPOS($val = 'nextTo') {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':tickLblPos val="' . $val . '"></'.GRANAMESPACE.':tickLblPos>__GENERATEAX__', $this->xmlChart);
    }
  
    function fGenerateCROSSAX($val = '59040512') {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':crossAx  val="' . $val . '"></'.GRANAMESPACE.':crossAx >__GENERATEAX__', $this->xmlChart);
    }
  
    function fGenerateCROSSES($val = 'autoZero') {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':crosses val="' . $val . '"></'.GRANAMESPACE.':crosses>__GENERATEAX__', $this->xmlChart);
    }
  
    function fGenerateAUTO($val = '1') {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':auto val="' . $val . '"></'.GRANAMESPACE.':auto>__GENERATEAX__', $this->xmlChart);
    }
  
    function fGenerateLBLALGN($val = 'ctr') {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':lblAlgn val="' . $val . '"></'.GRANAMESPACE.':lblAlgn>__GENERATEAX__', $this->xmlChart);
    }
  
    function fGenerateLBLOFFSET($val = '100') {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':lblOffset val="' . $val . '"></'.GRANAMESPACE.':lblOffset>', $this->xmlChart);
    }
  
    function fGenerateMAJORGRIDLINES() {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':majorGridlines></'.GRANAMESPACE.':majorGridlines>__GENERATEAX__', $this->xmlChart);
    }
  
    function fGenerateNUMFMT($formatCode='General', $sourceLinked = '1') {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':numFmt formatCode="' . $formatCode . '" sourceLinked="' . $sourceLinked . '"></'.GRANAMESPACE.':numFmt>__GENERATEAX__', $this->xmlChart);
    }
  
    function fGenerateCROSSBETWEEN($val = 'between') {
    	$this->xmlChart = str_replace('__GENERATEAX__', '<'.GRANAMESPACE.':crossBetween val="' . $val . '"></'.GRANAMESPACE.':crossBetween>', $this->xmlChart);
    }
    
    function fCleanTemplateDocument() {
      $this->xmlChart = preg_replace('/__[A-Z]+__/', '', $this->xmlChart);
    }
      
    function fCleanTemplate2() {
      $this->xmlChart = preg_replace(array('/__GENERATE[A-B,D-O,Q-R,U-Z][A-Z]+__/', '/__GENERATES[A-D,F-Z][A-Z]+__/', '/__GENERATETX__/'), '', $this->xmlChart);
    }
      
    function fCleanTemplate3() {
      $this->xmlChart = preg_replace(array('/__GENERATE[A-B,D-O,Q-S,U-Z][A-Z]+__/', '/__GENERATES[A-D,F-Z][A-Z]+__/', '/__GENERATETX__/'), '', $this->xmlChart);
    }
    
    function fCreateCHARTXML(){
  	   $this->xmlChart = '';
  	   $arrArgs = func_get_args();
       $type = $arrArgs[0][1]['type'];
       $this->setRId($arrArgs[0][0]);
       $this->fGenerateCHARTSPACE();
	   $this->fGenerateDATE1904(1);
	   $this->fGenerateLANG();
	   $this->fGenerateSTYLE();
	   $this->fGenerateCHART();
	   if(isset($arrArgs[0][1]['title'])){
	   		$this->fGenerateTITLE();
	   		$title = $arrArgs[0][1]['title'];
	   		$this->fGenerateTITLETX();
	   		$this->fGenerateRICH();
	   		$this->fGenerateBODYPR();
	   		$this->fGenerateLSTSTYLE();
	   		$this->fGenerateTITLEP();
	   		$this->fGenerateTITLEPPR();
	   		$this->fGenerateDEFRPR();
	   		$this->fGenerateTITLER();
	   		$this->fGenerateTITLERPR();
	   		$this->fGenerateTITLET($title);
	   		$this->fGenerateTITLELAYOUT();
	   }else{
	   		$this->fGenerateAUTOTITLEDELETED();
	   		$title = '';
	   }
	   if(empty($arrArgs[0][1]['data']))
	   	 exit('no has introducido datos');
	   $datos = $arrArgs[0][1]['data'];
	   $this->fGeneratePLOTAREA();
	   $this->fGenerateLAYOUT();
	   if(strpos($type, 'pie') !== false){
	   		$this->fGeneratePIECHART();
	   	 	$this->fGenerateVARYCOLORS();
	   	 	if(isset($datos[0]))
	   	 		$leyends = $datos[0];
	   	 	else
	   	 		$leyends = array($title);
	   	 	$numDatos = count($datos);
	   }elseif((strpos($type, 'bar') !== false) || (strpos($type, 'col') !== false)){
	   		$this->fGenerateBARCHART();
	   	 	$strTypeBar = 'bar';
	   	 	if(strpos($type, 'col') !== false)
	   	 		$strTypeBar = 'col';
	   	 	$this->fGenerateBARDIR($strTypeBar);
	   	 	$this->fGenerateGROUPING('clustered');
	   	 	if(isset($datos[0]))
	   	 		$leyends = $datos[0];
	   	 	else{
	   	 		echo('No has introducido ninguna leyenda 1 ');
	   	 		return false;
	   	 	}
	   	 	$numDatos = count($datos)-1;
	   }elseif(strpos($type, 'line') !== false){
	   		$this->fGenerateLINECHART();
	   	 	$this->fGenerateGROUPING('standard');
	   	 	if(isset($datos[0]))
	   	 		$leyends = $datos[0];
	   	 	else{
	   	 		echo('No has introducido ninguna leyenda 2 ');
	   	 		return false;
	   	 	}
	   	 	$numDatos = count($datos)-1;
	   	 	
	   }else{
	   	echo('tipo de gráfico desconocido o no soportado<br/>');
	   	return false;
	   }		   
	   
	   	
	   $letra = 'A';
	   for($i=0; $i < count($leyends); $i++){
		   $this->fGenerateSER();
		   $this->fGenerateIDX($i);
		   $this->fGenerateORDER($i);
		   $letra++;
		   
		   $this->fGenerateTX();
		   $this->fGenerateSTRREF();
		   $this->fGenerateF(' Hoja1!$'.$letra. '$1');//deberia introducir la celda donde se encuetra el titulo  Hoja1!$B$1
		   $this->fGenerateSTRCACHE();
		   $this->fGeneratePTCOUNT();
		   $this->fGeneratePT();
		   if(strpos($arrArgs[0][1]['type'], 'pie') !== false){
		   	 $this->fGenerateV($title);
		   }else{
		   	 $this->fGenerateV($leyends[$i]);
		   }
		   
		   $this->fCleanTemplate2();
		   $this->fGenerateCAT();
		   $this->fGenerateSTRREF();
		   $this->fGenerateF('Hoja1!$A$2:$A$'. ($numDatos+1));
		   $this->fGenerateSTRCACHE();
		   $this->fGeneratePTCOUNT($numDatos);//introducir el numero de elementos
		   
		   $num = 0;
		   foreach($datos as $legend => $dato){
		   	 if($legend == '0') continue; 
		   	 $this->fGeneratePT($num);
		   	 $this->fGenerateV($legend);
		   	 $num++;
		   }
		   $this->fCleanTemplate2();
		   $this->fGenerateVAL();
		   $this->fGenerateNUMREF();
		   $this->fGenerateF('Hoja1!$'.$letra.'$2:$B$'. ($numDatos+1));
		   $this->fGenerateNUMCACHE();
		   //$this->fGenerateNUMREF();
		   $this->fGenerateFORMATCODE();
		   $this->fGeneratePTCOUNT($numDatos);
		   $num = 0;
		   foreach($datos as $legend => $dato){
		   	 if($legend == '0')
		   	 	continue;
		   	 $this->fGeneratePT($num);
		   	 $this->fGenerateV($dato[$i]);
		   	 $num++;
		   }
		   $this->fCleanTemplate3();
	   }
	   if(strpos($arrArgs[0][1]['type'], 'pie') !== false){
		   $this->fGenerateDLBLS();
		   $this->fGenerateSHOWPERCENT();
		   $this->fGenerateFIRSTSLICEANG();
	   }else{
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
	   	   $this->fGenerateCROSSAX(59034624);
	   	   $this->fGenerateCROSSES();
	   	   $this->fGenerateCROSSBETWEEN();
	   }
	   
	   $this->fGenerateLEGEND();
	   $this->fGenerateLEGENDPOS();
	   $this->fGeneratePLOTVISONLY();
	   if(strpos($arrArgs[0][1]['type'], 'pieChart') === false){
		   $this->fGenerateSPPR();
		   $this->fGenerateLN();
		   $this->fGenerateNOFILL();
	   }
	   
	   $this->fGenerateEXTERNALDATA();
	   $this->fCleanTemplateDocument(); 
       return true;
    }
    
    function fCreateDOCUEMNTXML(){
    	$arrArgs = func_get_args();
    	$intAjusteTexto = 0;
      	  if(isset($arrArgs[0][1]['sizeX']))
      	  	$sizeX = $arrArgs[0][1]['sizeX']* CONSTWORD;
      	  else{
      	  	$sizeX = 2993296;
      	  }
       	  if(isset($arrArgs[0][1]['sizeY']))
      	  	$sizeY = $arrArgs[0][1]['sizeY']* CONSTWORD;
      	  else{
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
    		    
    function fCreateGraphic(){
       $this->xmlChart = '';
       $arrArgs = func_get_args();
       if(!empty($arrArgs[1]['type']) && !empty($arrArgs[0])){
       		if($this->fCreateCHARTXML($arrArgs) == false){
		       echo 'no has introducido las leyendas ';
		       return false;
	       	}
       	    $this->fCreateDOCUEMNTXML($arrArgs);
       	    return true;
       } else{
	       echo 'no has introducido el tipo de grafico';
	       return false;
       }
    }
}
?>