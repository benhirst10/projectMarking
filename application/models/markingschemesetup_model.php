<?php
 class markingschemesetup_model extends CI_Model {       
	
    function __construct() {
        parent::__construct();
		$this->versionInfo=$this->version_model->getVersionInfo();
		$this->domMarkingScheme=new DOMDocument();
        	$this->markingSchemeXMLFile="../common/generated/xml/markingScheme".$this->fileno.".xml";
	        $this->domMarkingScheme->load($this->markingSchemeXMLFile); 
        	$this->markingSchemeXpath = new DOMXPath($this->domMarkingScheme);
        	$this->markingSchemeXsltProc = new XSLTProcessor();
	        $this->markingSchemeXsltProc->substituteEntities = true;
    
        	$this->markingSchemeDB = $this->load->database('markingScheme', TRUE);
	}

    function compareNewMarkingSchemeAssessmentWeighting($assessment,$weightingPrevious)
    {
    
        $queryMarkingScheme = "/markingScheme/assessments/assessment[@id='$assessment']/[@weighting='$weightingPrevious']/";
        return ($this->newMarkingSchemeXpath->query($queryMarkingScheme)->length>0);   
    }
    
    function compareAssessmentComponentWeighting($assessment,$componentIdPrevious,$weightingPrevious)
    {
        $queryMarkingScheme = "//assessment[@id=\"$assessment\"]/component[@id=\"$componentIdPrevious\" and @weightingPrevious=\"$weightingPrevious\"]";
        return ($this->newMarkingSchemeXpath->query($queryMarkingScheme)->length>0);
    }
    
    function setUpNewlyCreatedAssessment()
    {
        $this->markingSchemeDB->query("DELETE FROM assessment");
        $this->markingSchemeDB->query("DELETE FROM assessmentComponent");
        $saveMarkingScheme=true;
    }
    
    function saveNewlyCreatedAssessment($weightingAssessment,$weightingComponent)
    {
            if (isset($weightingAssessment)) while (list($assessid,$weight) = each($weightingAssessment))
            {
                $newAssessmentQuery = 'INSERT INTO assessment (id, weighting) VALUES (?, ?)';
                $this->markingSchemeDB->query($sql, array($assessid, $weight));  
            }
            if (isset($weightingComponent)) while (list($assessid,$compids) = each($weightingComponent))
            while (list($compid,$weight) = each($compids)) 
            {
                    $newAssessmentComponentQuery = 'INSERT INTO assessmentComponent (id,assessmentId,outof,weighting) VALUES (?,?,?,?)';
                    $this->markingSchemeDB->query($sql, array($compid,$assessid,$this->getOutOf($assessid,$compid),$weight)); 
            }    
    }

    function firstMarkingScheme()
    {   
        $this->markingSchemeDB->query("INSERT INTO markingScheme (fileno) VALUES ('1')");
    
    }   
 

    function setMarkingSchemeNew()
    {
        $domNewMarkingScheme = new DOMDocument();
        $domNewMarkingScheme->load($this->newMarkingSchemeXMLFile);   
        $this->newMarkingSchemeXpath = new DOMXPath($domNewMarkingScheme);
    }    

    function setMarkingScheme()
    {
        $this->markingSchemeXsltProc = new XSLTProcessor();
    // This will load the present stylesheet for marking schemes 
        $this->markingSchemeXsltProc->importStylesheet( DOMDocument::load($this->markingSchemeXSLFile) ); 
        $this->markingSchemeXsltProc->setParameter('','componentid','_all_'); 
        $this->markingSchemeXsltProc->setParameter('','componentVal',''); 
        $this->markingSchemeXsltProc->setParameter('','choiceVal',''); 
        $this->markingSchemeXsltProc->setParameter('','numericVal','');       
        $this->markingSchemeXsltProc->setParameter('','assid','_all_');
        $this->markingSchemeXsltProc->setParameter('','entryReport','entry');    
    }
    
    
    function newMarkingSchemeItemsSave($weightingAssessment)
    {
    
            if (isset($weightingAssessment)) while (list($assessid,$weight) = each($weightingAssessment))
            {
                $assessmentToSave = array($assessid, $weight);
                $newAssessmentQuery = 'INSERT INTO assessment (id, weighting) VALUES (?, ?)';
                $statement = $markingSchemeMdb2->prepare($newAssessmentQuery);
                $statement->execute($assessmentToSave);
                // This will save the associated weightings of the new marking scheme assessments
                echo "<br/><b>Saving assessment:</b> $assessid <b>Weighting:</b> $weight";
            
            }
                if (isset($weightingComponent)) while (list($assessid,$compids) = each($weightingComponent))
                while (list($compid,$weight) = each($compids)) 
                {
                    $assessmentComponentToSave = array($compid,$assessid,$weight,findOutOf($assessid,$compid,$markingScheme));
                    $newAssessmentComponentQuery = 'INSERT INTO assessmentComponent (id,assessmentId,outof,weighting) VALUES (?,?,?,?)';
                    // This will save the associated weightings of the new marking scheme assessment components
                    $statement = $markingSchemeMdb2->prepare($newAssessmentComponentQuery);
                    $statement->execute($assessmentComponentToSave);
                    echo "<br/><b>Saving assessment component. Assessment:</b> $assessid <b>Component:</b> $compid <b>Weighting:</b> $weight";
                    echo " <b>Out of:</b> ".findOutOf($assessid,$compid,$markingScheme);
            }           
    }

    function getNewMarkingSchemeAssessmentWeighting($assessment)
    {
    
        $weighting="";
        $queryMarkingScheme = "/markingScheme/assessments/assessment[@id='$assessment']/";
        $markingSchemeNode=$this->newMarkingSchemeXpath->query($queryMarkingScheme);
        foreach($markingSchemeNode as $mn) $weighting=$mn->getAttribute('weighting');
        return $weighting;
    
    }
        
	
}
?>