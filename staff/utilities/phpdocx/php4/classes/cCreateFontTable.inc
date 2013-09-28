<?php
  /**
   * @author
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';

  class cCreateFontTable extends cCreateElement {
    var $rscInstance = NULL;
    var $xml;

    function toString() {
      return $this->xml;
    }

    function getInstance() {
       if($this->rscInstance == NULL) {
          $this->rscInstance = new cCreateFontTable();
       }
       return $this->rscInstance;
    }

    function fGenerateFONT($name= 'Calibri'){
      $this->xml = '<'.NAMESPACE.':font '.NAMESPACE.':name="' . $name . '">__GENERATEFONT__</'.NAMESPACE.':font>';
    }
    
    function fGeneratePANOSE1($val = '020F0502020204030204') {
       	$this->xml = str_replace('__GENERATEFONT__', '<'.NAMESPACE.':panose1 '.NAMESPACE.':val="'.$val.'"></'.NAMESPACE.':panose1>__GENERATEPANOSE1__', $this->xml);
    }
    
    function fGenerateCHARSET($val = '00') {
       	$this->xml = str_replace('__GENERATEPANOSE1__', '<'.NAMESPACE.':charset '.NAMESPACE.':val="'.$val.'"></'.NAMESPACE.':charset>__GENERATECHARSET__', $this->xml);
    }
    
  	function fGenerateFAMILY($val = 'swiss') {
       	$this->xml = str_replace('__GENERATECHARSET__', '<'.NAMESPACE.':family '.NAMESPACE.':val="'.$val.'"></'.NAMESPACE.':family>__GENERATEFAMILY__', $this->xml);
    }
    
  	function fGeneratePITCH($val = '00') {
       	$this->xml = str_replace('__GENERATEFAMILY__', '<'.NAMESPACE.':pitch '.NAMESPACE.':val="'.$val.'"></'.NAMESPACE.':pitch>__GENERATEPITCH__', $this->xml);
    }
    
  	function fGenerateSIG($usb0 = 'A00002EF', $usb1 = '4000207B', $usb2 = '00000000', $usb3 = '00000000', $csb0 = '0000009F', $csb1 = '00000000') {
       	$this->xml = str_replace('__GENERATEPITCH__', '<'.NAMESPACE.':sig '.NAMESPACE.':usb0="'.$usb0.'" '.NAMESPACE.':usb1="'.$usb1.'" '.
       	NAMESPACE.':usb2="'.$usb2.'" '.NAMESPACE.':usb3="'.$usb3.'" '.NAMESPACE.':csb0="'.$csb0.'" '.
       	NAMESPACE.':csb1="'.$csb1.'"></'.NAMESPACE.':sig>', $this->xml);
    }
    
    function fCreateFont(){
      $this->xml='';
      $arrArgs = func_get_args();
      if(!empty($arrArgs[0]['name']) && !empty($arrArgs[0]['pitch']) &&!empty($arrArgs[0]['usb0']) && !empty($arrArgs[0]['usb1']) && !empty($arrArgs[0]['usb2']) && !empty($arrArgs[0]['usb3']) 
      && !empty($arrArgs[0]['csb0']) && !empty($arrArgs[0]['csb1']) && !empty($arrArgs[0]['family']) && !empty($arrArgs[0]['charset']) && !empty($arrArgs[0]['panose1'])){
        $this->fGenerateFONT($arrArgs[0]['name']);
        $this->fGeneratePANOSE1($arrArgs[0]['panose1']);
        $this->fGenerateCHARSET($arrArgs[0]['charset']);
        $this->fGenerateFAMILY($arrArgs[0]['family']);
        $this->fGeneratePITCH($arrArgs[0]['pitch']);
        $this->fGenerateSIG($arrArgs[0]['usb0'], $arrArgs[0]['usb1'], $arrArgs[0]['usb2'], $arrArgs[0]['usb3'], $arrArgs[0]['csb0'], $arrArgs[0]['csb1']);
      }else{
        exit('Se ha intentado introducir una fuente vacía');
      }
   }
  }
?>