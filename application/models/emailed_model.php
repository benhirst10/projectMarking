<?php
class emailed_model extends CI_Model {

	var $emailedXpath;
 	var $emailedXMLFile='../staff/generated/xml/emailed.xml';

     function __construct() {
        parent::__construct();
        	if ($this->checkIfEmailedFileExists()) 
        	{
                	$domEmailed=new DOMDocument();
                	$domEmailed->load($this->emailedXMLFile);
                	$this->emailedXpath = new DOMXPath($domEmailed);         
        	}
           		
    	}
	
    	function checkIfEmailedFileExists()
    	{
       	 	// This function sese that the file that contains a list of students who have been assigned allocations is present.
		
		if (file_exists($this->emailedXMLFile)) return true; else return false;
    	} 	

    	function getEmailedAllocation($stuid)
    	{
       		 // This function retrieves information about whether the student has been emailed.
        	$emailedStudentDateTime="";
        
        	// Checks to see if the own project file exists.
        	if ($this->checkIfEmailedFileExists())
        	{
          	  	// Obtains information about own emailed allocations for the student.
           		$queryEmailedStudent= "//emailedAllocations/emailed[@student='$stuid']";
			
            		// This will find emailed allocation information for student.
            		$emailedStudents=$this->emailedXpath->query($queryEmailedStudent);
            
        	}
		if ($this->checkIfEmailedFileExists()) foreach ($emailedStudents as $es) $emailedStudentDateTime.="&nbsp;".$es->getAttribute('dateAndTime');
		
        	return $emailedStudentDateTime;
    
    	}
	

	function saveEmailedAllocations($emailedStudents,$students)
	{
	
	    // This function records the allocations that have been sent at a specified time interval.		
	    		 
            if ($this->checkIfEmailedFileExists())
	    {
		    $domBackup=new DOMDocument();
        	    $domBackup->load($this->emailedXMLFile);
	            $time = date("YmdHis");
        	    $newname=$this->emailedXMLFile.$time;
	
        	    // This will save another copy of the own project setup file.
	            file_put_contents($newname, $domBackup->saveXML());	
		    $newFile=false;
 
		    
	    } else $newFile=true;
	    
	    
	    
            // This will create the emailed root element within the xml file.
            $domSave = new DOMDocument('1.0','UTF-8');
            $domSave->formatOutput = true;
            $root = $domSave->createElement ("emailedStudents");
            $root = $domSave->appendChild ($root);	

            // This will create a sub element of root called emailedAllocations.
            $emailedAllocations = $domSave->createElement ("emailedAllocations");
            $emailedAllocations = $root->appendChild ($emailedAllocations);
	    	    
	    $cnt=1;
            // This will go through all the students.
            foreach($students as $stTag)
            {
                $uid=$stTag->getAttribute('uid');

                if ($emailedStudents[$cnt]=="emailed")
		{                
	                // This will create a sub element of emailedAllocations called emailed.
        	        $emailed = $domSave->createElement ("emailed");
                	$emailed = $emailedAllocations->appendChild ($emailed);
                
	                // This will create an attribute of emailed called student and set this to the value posted from the marking setup form.
        	        $attr_student = $domSave->createAttribute ('student');
                	$attr_student = $emailed->appendChild ($attr_student);
	                $emailed->setAttribute('student', $uid);
			
        	        $attr_dateAndTime = $domSave->createAttribute ('dateAndTime');
                	$attr_dateAndTime = $emailed->appendChild ($attr_dateAndTime);
	                $emailed->setAttribute('dateAndTime',date("Y-m-d G:i:s"));
			
							
			    	    
	    	}
		$cnt++;
	    }
	    if (!$newFile)
	    {
	    	
		// This finds derived tags that do not constitue attributes of the enclosing tag. The enclosing tag in this instance is emailed allocations.
		$previousAllocations = $domBackup->getElementsByTagName("emailedAllocations")->item(0)->getElementsByTagName( "*" );
		for ( $i = 0; $i < $previousAllocations->length; $i++ ) {
			$pa=$previousAllocations->item( $i );
			
			// A node is imported from the previous file with its own unique identifiers.
			$node = $domSave->importNode($pa, true);
			
			// This will add the node with the set format into the appropriate space within in the file.
			$emailed = $emailedAllocations->appendChild($node);
			
		}
	    }		    
            // Saves the generated xml data.
            $domSave->save($this->emailedXMLFile);

	    	    
	
	}

}
