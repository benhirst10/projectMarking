<?php
class ownproject_model extends CI_Model {

	var $markingOwnProjectXpath;
 	var $ownProjectXMLFile='../common/generated/xml/ownProject.xml';

    function __construct() {
        parent::__construct();
        	if ($this->checkIfOwnProjectSetupFileExists()) 
        	{
                	$domOwnProjectSetup=new DOMDocument();
                	$domOwnProjectSetup->load($this->ownProjectXMLFile);
                	$this->markingOwnProjectXpath = new DOMXPath($domOwnProjectSetup);         
        	}
           		
    	}
	
    	function checkIfOwnProjectSetupFileExists()
    	{
       	 	if (file_exists($this->ownProjectXMLFile)) return true; else return false;
    	} 	

    	function getSavedOwnProjectSetup($stuid)
    	{
       		 // This function retrieves the own project setup information saved with the own project setup xml file for a student.
        	$ownprojects="";
        
        	// Checks to see if the own project file exists.
        	if ($this->checkIfOwnProjectSetupFileExists())
        	{
          	  	// Obtains information about own project setup for student.
           		$queryOwnProject= "//projects/ownProject[@student='$stuid']";
			
            		// This will find own project information for student.
            		$ownprojects=$this->markingOwnProjectXpath->query($queryOwnProject);
            
        	}
        	return $ownprojects;
    
    	}
	
    	function getSavedOwnProjectSetupForMarker($uid)
    	{
       		 // This function retrieves the own project setup information saved with the own project setup xml file for a marker.
        	$ownprojects="";
        
        	// Checks to see if the own project file exists.
        	if ($this->checkIfOwnProjectSetupFileExists())
        	{
          	  	// Obtains information about own project setup for supervisor.
           		$queryOwnProject= "//projects/ownProject[@supervisor='$uid']";
			
            		// This will find own project information for supervisor.
            		$ownprojects=$this->markingOwnProjectXpath->query($queryOwnProject);
            
        	}
        	return $ownprojects;
    
    	}
	function saveOwnProjectSetup($markerSelected,$projectChoice,$ownProjects,$students)
	{
	    		 
            if ($this->checkIfOwnProjectSetupFileExists())
	    {
		    $domBackup=new DOMDocument();
        	    $domBackup->load($this->ownProjectXMLFile);
	            $time = date("YmdHis");
        	    $newname=$this->ownProjectXMLFile.$time;
	
        	    // This will save another copy of the own project setup file.
	            file_put_contents($newname, $domBackup->saveXML());	
	    }
	    
            // This will create the ownProject root element within the xml file.
            $domSave = new DOMDocument('1.0','UTF-8');
            $domSave->formatOutput = true;
            $root = $domSave->createElement ("ownProjects");
            $root = $domSave->appendChild ($root);	

            // This will create a sub element of root called projects.
            $projects = $domSave->createElement ("projects");
            $projects = $root->appendChild ($projects);
	    	    
	    $cnt=1;
            // This will go through all the students;
            foreach($students as $stTag)
            {
                $uid=$stTag->getAttribute('uid');

                if ($markerSelected[$cnt]!="Select Choice" && $projectChoice[$cnt]=="own project" && !empty($ownProjects[$cnt]))
		{                
	                // This will create a sub element of own project called ownProject.
        	        $ownProject = $domSave->createElement ("ownProject");
                	$ownProject = $projects->appendChild ($ownProject);
                
	                // This will create an attribute of ownProject called supervisor and set this to the value posted from the marking setup form.
        	        $attr_supervisor = $domSave->createAttribute ('supervisor');
                	$attr_supervisor = $ownProject->appendChild ($attr_supervisor);
	                $ownProject->setAttribute('supervisor', $markerSelected[$cnt]);
			
                	// This will create an attribute of ownProject called project and set this to the value posted from the marking setup form. 
        	        $attr_project = $domSave->createAttribute ('projectTitle');
                	$attr_project = $ownProject->appendChild ($attr_project);
	                $ownProject->setAttribute('projectTitle', $ownProjects[$cnt]);	
			
	                // This will create an attribute of ownProject called student and set this to the value posted from the marking setup form.
	                $attr_student = $domSave->createAttribute ('student');
        	        $attr_student = $ownProject->appendChild ($attr_student);
                	$ownProject->setAttribute('student', $uid);				
			    	    
	    	}
		$cnt++;
	    }
            // Saves the generated xml data.
            $domSave->save($this->ownProjectXMLFile);	    
	
	}

}
