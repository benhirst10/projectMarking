<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  include_once dirname(__FILE__) . '/cCreateElement.inc';
define("IDTITLE", 229998237);
  class cCreateText extends cCreateElement {
  	
    var $rscInstance = NULL;
    var $intIdTitle = 0;

    function cCreateText(){
    }
	 
    function toString() {
      return $this->xml;
    }

    function fGenerateB($strVal = 'single') {
      $this->xml = str_replace('__GENERATERPR__', '<'.NAMESPACE.':b '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':b>__GENERATERPR__', $this->xml);
    }

    function fGenerateCOLOR($strVal = '000000') {
      $this->xml = str_replace('__GENERATERPR__', '<'.NAMESPACE.':color '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':color>__GENERATERPR__', $this->xml);
    }

    function fGenerateJC($strVal = '') {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':jc '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':jc>__GENERATESZ__', $this->xml);
    }

    function fGenerateI($strVal = 'single') {
      $this->xml = str_replace('__GENERATERPR__', '<'.NAMESPACE.':i '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':i>__GENERATERPR__', $this->xml);
    }

    function fGenerateSZ($strVal = '11') {
      $strVal *= 2;
      $this->xml = str_replace('__GENERATERPR__', '<'.NAMESPACE.':sz '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':sz>__GENERATERPR__', $this->xml);
    }

    function fGenerateU($strVal = 'single') {
      $this->xml = str_replace('__GENERATERPR__', '<'.NAMESPACE.':u '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':u>__GENERATERPR__', $this->xml);
    }
    
    function fGeneratePSTYLE($strVal = 'Ttulo') {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':pStyle '.NAMESPACE.':val="'.$strVal.'"></'.NAMESPACE.':pStyle>__GENERATEPPR__', $this->xml);
    }
        
    function fGeneratePAGEBREAKBEFORE($strVal = 'on') {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':pageBreakBefore val="'.$strVal.'"></'.NAMESPACE.':pageBreakBefore>__GENERATEPPR__', $this->xml);
    }
        
    function fGenerateWIDOWCONTROL($strVal = 'on') {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':widowControl val="'.$strVal.'"></'.NAMESPACE.':widowControl>__GENERATEPPR__', $this->xml);
    }
      
    function fGenerateWORDWRAP($strVal = 'on') {
      $this->xml = str_replace('__GENERATEPPR__', '<'.NAMESPACE.':wordWrap val="'.$strVal.'"></'.NAMESPACE.':wordWrap>__GENERATEPPR__', $this->xml);
    }
      
    function fGenerateBOOKMARKSTART($intId, $name) {
      $this->xml = str_replace('__GENERATER__', '<'.NAMESPACE.':bookmarkStart '.NAMESPACE.':id="'.$intId.'" '.NAMESPACE.':name="'.$name.'"></'.NAMESPACE.':bookmarkStart>__GENERATER____GENERATEBOOKMARKEND__', $this->xml);
    }
      
    function fGenerateBOOKMARKEND($intId) {
      $this->xml = str_replace('__GENERATEBOOKMARKEND__', '<'.NAMESPACE.':bookmarkEnd '.NAMESPACE.':id="'.$intId.'"></'.NAMESPACE.':bookmarkEnd>', $this->xml);
    }
        
    function fCreateTitle(){
    	$this->xml = '';
    	$arrArgs = func_get_args();
    	if(!empty($arrArgs[1]['val']) && !empty($arrArgs[0])){
    		$this->fGenerateP();
    		$this->fGeneratePPR();
    		if($arrArgs[1]['type'] == 'subtitle')
    			$this->fGeneratePSTYLE('Subttulo' . $arrArgs[1]['val']);
    		else
    			$this->fGeneratePSTYLE('Ttulo' . $arrArgs[1]['val']);
    		if(!empty($arrArgs[1]['pageBreakBefore']))
	        	$this->fGeneratePAGEBREAKBEFORE($arrArgs[1]['pageBreakBefore']);
	    	if(!empty($arrArgs[1]['widowControl']))
	    		$this->fGenerateWIDOWCONTROL($arrArgs[1]['widowControl']);
	    	if(!empty($arrArgs[1]['wordWrap']))
	    		$this->fGenerateWORDWRAP($arrArgs[1]['wordWrap']);
	    	$this->$intIdTitle++;
	    	$this->fGenerateBOOKMARKSTART($this->$intIdTitle, '_Toc'. ($this->$intIdTitle + $this->IDTITLE));
    		$this->fGenerateR();
	    	if($arrArgs[1]['b'] != '' || $arrArgs[1]['i'] != '' || $arrArgs[1]['u'] != '' || $arrArgs[1]['sz'] != '' || $arrArgs[1]['color'] != '') {
	          	$this->fGenerateRPR();
		        if($arrArgs[1]['b'] != '') {
		          $this->fGenerateB($arrArgs[1]['b']);
		        }
		        if($arrArgs[1]['i'] != '') {
		          $this->fGenerateI($arrArgs[1]['i']);
		        }
		        if($arrArgs[1]['u'] != '') {
		          $this->fGenerateU($arrArgs[1]['u']);
		        }
		        if($arrArgs[1]['sz'] != '') {
		          $this->fGenerateSZ($arrArgs[1]['sz']);
		        }
		        if($arrArgs[1]['color'] != '') {
		          $this->fGenerateCOLOR($arrArgs[1]['color']);
		        }
		    }
	        $this->fGenerateT($arrArgs[0]);
	        $this->fGenerateBOOKMARKEND($this->$intIdTitle);
	        $this->fCleanTemplate();
    	}else{
    		echo 'no has pasado el texto a introducir o el tipo de titulo a introducir';
    		return false;
    	}
    		
    }    
    
    function fCreateText() {
      $this->xml = '';
      $arrArgs = func_get_args();

      $this->fGenerateP();
      if(!empty($arrArgs[1]['jc']) || !empty($arrArgs[1]['pageBreakBefore']) || !empty($arrArgs[1]['widowControl']) || !empty($arrArgs[1]['wordWrap'])) {
        $this->fGeneratePPR();
        if(!empty($arrArgs[1]['jc']))
        	$this->fGenerateJC($arrArgs[1]['jc']);
        if(!empty($arrArgs[1]['pageBreakBefore']))
        	$this->fGeneratePAGEBREAKBEFORE($arrArgs[1]['pageBreakBefore']);
    	if(!empty($arrArgs[1]['widowControl']))
    		$this->fGenerateWIDOWCONTROL($arrArgs[1]['widowControl']);
    	if(!empty($arrArgs[1]['wordWrap']))
    		$this->fGenerateWORDWRAP($arrArgs[1]['wordWrap']);
      }
      $this->fGenerateR();
      if($arrArgs[1]['b'] != '' || $arrArgs[1]['i'] != '' || $arrArgs[1]['u'] != '' || $arrArgs[1]['sz'] != '' || $arrArgs[1]['color'] != '') {
        $this->fGenerateRPR();
        if($arrArgs[1]['b'] != '') {
          $this->fGenerateB($arrArgs[1]['b']);
        }
        if($arrArgs[1]['i'] != '') {
          $this->fGenerateI($arrArgs[1]['i']);
        }
        if($arrArgs[1]['u'] != '') {
          $this->fGenerateU($arrArgs[1]['u']);
        }
        if($arrArgs[1]['sz'] != '') {
          $this->fGenerateSZ($arrArgs[1]['sz']);
        }
        if($arrArgs[1]['color'] != '') {
          $this->fGenerateCOLOR($arrArgs[1]['color']);
        }
      }
      $this->fGenerateT($arrArgs[0]);
    }
  }
?>