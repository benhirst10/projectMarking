<?php
class markingscheme_model extends CI_Model {

    var $markingSchemeXpath;
    var $markingSchemeXMLFile;
    var $markingSchemeXsltProc;
    var $domMarkingScheme;
    var $markingSchemeXSLFile='./../application/xsl/markingScheme.xslt';
    var $markingSchemeXSDFile='./../application/xsl/markingScheme.xsd';
    var $newMarkingSchemeXMLFile="../staff/config/xml/markingScheme.xml";
    var $domNewMarkingScheme;
    var $newMarkingSchemeXpath;
    var $markingSchemeDB;
    var $fileno;
    
    function __construct() {
        parent::__construct();
         // Loads information about which version the marking scheme is up to.
        $this->versionInfo=$this->version_model->getVersionInfo();
    
        foreach ($this->versionInfo as $version) $this->fileno=$version->getAttribute('fileno');
        $this->domMarkingScheme=new DOMDocument();
        $this->markingSchemeXMLFile="../common/generated/xml/markingScheme".$this->fileno.".xml";
        $this->domMarkingScheme->load($this->markingSchemeXMLFile); 
        $this->markingSchemeXpath = new DOMXPath($this->domMarkingScheme);
        $this->markingSchemeXsltProc = new XSLTProcessor();
        $this->markingSchemeXsltProc->substituteEntities = true;
    
      //  $this->markingSchemeDB = $this->load->database('markingScheme', TRUE); 
        
    }
    
    function checkIfMarkingSchemeFileExists()
    {
        // This function will check that there is an existing source of marking scheme derived from the version information
            if (file_exists($this->markingSchemeXMLFile)) return true; else return false;
    
        
     }  
    
    function getMarkingSchemeDom()
    {
    
        // This function will obtain the marking scheme in a format that is applicable to access.
        return $this->domMarkingScheme;
    }
    
    function getMarkingSchemeXsltProc()
    {
        
    // This function will set the format for extraction of data from the source that is applicable to markers selections.
    
        $domMarkingSchemeXSL=new DOMDocument();
        $domMarkingSchemeXSL->load($this->markingSchemeXSLFile);
        $this->markingSchemeXsltProc->importStylesheet($domMarkingSchemeXSL);   
        return $this->markingSchemeXsltProc;
    
    }
    
    
    function getMarkingSchemeModcode()
    {
        // This function will find the assigned module code for the marking scheme.
    
    
        $modcode="";
        $queryMarkingScheme = "/markingScheme";
        $markingSchemeNode=$this->markingSchemeXpath->query($queryMarkingScheme);
        if ($this->checkIfMarkingSchemeFileExists()) {
            foreach($markingSchemeNode as $mn) 
                $modcode=$mn->getAttribute('modcode');
        }
        return $modcode;
        
    }
    
    function getWeighting($assessment)
    {
        // This function will find the weighting of the assessment.
    
        $weight="";
        $queryMarkingScheme = "/markingScheme/assessments/assessment[@id='$assessment']";
        $weightings=$this->markingSchemeXpath->query($queryMarkingScheme);   
        foreach($weightings as $weights) $weight=$weights->getAttribute('weighting');
        return $weight;
    }
    
    
    function getAssessments()
    {
        // This function will get the full list of assessments.
    
        $queryMarkingScheme = "/markingScheme/assessments/assessment";
        return $this->markingSchemeXpath->query($queryMarkingScheme);
        
    } 
    

    
    function checkIfAssessmentExistsInNewMarkingScheme($assessment)
    {
    
        $queryMarkingScheme = "/markingScheme/assessments/assessment[@id='$assessment']/";
        return ($this->newMarkingSchemeXpath->query($queryMarkingScheme)->length>0);
    
    }
    
    

    function getAssessmentComponentWeighting($assessment,$componentIdPrevious)
    {
        $queryMarkingScheme = "//assessment[@id=\"$assessment\"]/component[@id=\"$componentIdPrevious\"]/";
        $markingSchemeNode=$this->newMarkingSchemeXpath->query($queryMarkingScheme);
        foreach($markingSchemeNode as $mn) $weighting=$mn->getAttribute('weighting');
        return $weighting;
    }
    
    
    function getAssessmentComponents($assessment)
    {
        // This function will get the composite of the assessments.
    
        $queryMarkingScheme = "/markingScheme/assessments/assessment[@id='$assessment']/component";
        return $this->markingSchemeXpath->query($queryMarkingScheme);    
    }
    function getOutOf($assessment,$component)  
    {
    // This function will get the specific total that is given to the composite of the assessment.
    
    	$outOf=0;
        $queryMarkingScheme = "/markingScheme/assessments/assessment[@id='$assessment']/component[@id='$component']/mark/numeric";
    	$outofs=$this->markingSchemeXpath->query($queryMarkingScheme);
        foreach ($outofs as $oo) $outOf=$outOf+$oo->getAttribute('outof');
	
	return $outOf;
    }
}
?>
