<?php
class degreeabreviations_model extends CI_Model {

    var $degreeAbreviationsXpath;   
    var $degreeAbreviationsXMLFile='../common/xml/degreeAbreviations.xml';
    

     function __construct() {
        parent::__construct();
        // This will load the degree abreviations file to be used to check against for each student.
        if ($this->checkIfDegreeAbreviationsFileExists())
        {
                $domAbreviations = new DOMDocument;
                $domAbreviations->preserveWhiteSpace = false;
                $domAbreviations->Load($this->degreeAbreviationsXMLFile);
		
		// Sets xpath to be used for more queries in model.
                $this->degreeAbreviationsXpath = new DOMXPath($domAbreviations);      
        }   
        
    }
    
    
    function checkIfDegreeAbreviationsFileExists()
    {
    
    	// This function checks whether the degree abreviations xml file exists.
    	
        if (file_exists($this->degreeAbreviationsXMLFile)) return true; else return false;
    
        
    } 
        function getDegreeCodeAbreviation($degreecode)
        {
            // This function will retrieve the abreviation of a particular degree a student is doing.
            
            // Retrieves the degree abreviation information from the xml file.
            $query = "//degree[@degreecode='$degreecode']";
            $abreviations=$this->degreeAbreviationsXpath->query($query);
            $allocateAll=false;
            foreach ($abreviations as $ab) 
            {
                 $degreecode=$ab->getAttribute('abreviation');
                 $allocateAll=$ab->getAttribute('allocateAll');
            }
            
            // Sets the degreecode abreviation to _all_ when all projects may be chosen by the student.
            if ($allocateAll) $degreecode="_all_";

            return $degreecode;
        }
    
     


        
}
?>
