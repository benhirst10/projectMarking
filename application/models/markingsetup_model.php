<?php
class markingSetup_model extends Model {

    var $markingXpath;  
    var $markingSetupDB;
    var $markingSetupXMLFile='../common/generated/xml/markingSetup.xml';

    function markingSetup_model()
    {
        parent::Model();
        if ($this->checkIfMarkingSetupFileExists()) 
        {
                $domMarkingSetup=new DOMDocument();
                $domMarkingSetup->load($this->markingSetupXMLFile);
                $this->markingXpath = new DOMXPath($domMarkingSetup);         
        }
            
         // This will load the marking setup sql database used to sort set ups.
         $this->markingSetupDB = $this->load->database('default', TRUE);    
    }
    
    function getSavedMarkingSetup($stuid)
    {
        // This function retrieves the marking setup information saved with the marking setup xml file for a student.
        $markings="";
        
        // Checks to see if the marking setup file exists.
        if (file_exists($this->markingSetupXMLFile))
        {
            // Obtains information about marking setup for student.
            $queryMarking= "//supervisors/supervision[@student='$stuid']";
            // This will find supervisors of students.
            $markings=$this->markingXpath->query($queryMarking);
            
        }
        return $markings;
    
    }
    
    
    
    function getOwnProjects()
    {
        // This function retrieves the marking setup information saved with the marking setup xml file for own projects.
        $markings="";
        
        // Checks to see if the marking setup file exists.
        if (file_exists($this->markingSetupXMLFile))
        {
            // Obtains information about marking setup for own project.
            $queryMarking= "//supervisors/supervision[@project='own project']";
            // This will find supervisors of students.
            $markings=$this->markingXpath->query($queryMarking);
            
        }
        return $markings;
    
    }    
    

    function checkIfMarkingSetupFileExists()
    {
        // This function sees whether the xml file is their to be used.
	
	if (file_exists($this->markingSetupXMLFile)) return true; else return false;
    
        
    }   
    
    function getAllSavedMarkingSetup()
    {
        // This function retrieves the marking setup information saved with the marking setup xml file for a marker.
        $markings="";
        
        // Obtains information about marking setup for student.
        $queryMarking= "//supervisors/supervision";
    
        // This will find supervisors of students.
        $markings=$this->markingXpath->query($queryMarking);
            

        return $markings;    
    
    }

    function saveMarkingSetup($markerSelected,$projectChoice,$secondMarkerSelected,$ownProject,$students,$markers,$projects,$hideStudent)
    {
            // This function save marking setups to an xml file which is used by student progression system. 
	    // It also saves marking setup data to a sqlite database for sorting purposes.

            $domBackup=new DOMDocument();
            $domBackup->load($this->markingSetupXMLFile);
            $time = date("YmdHis");
            $newname=$this->markingSetupXMLFile.$time;
            // This will save another copy of the marking setup file.
            file_put_contents($newname, $domBackup->saveXML());
            
            // This will create the markingSetup root element within the xml file.
            $domSave = new DOMDocument('1.0','UTF-8');
            $domSave->formatOutput = true;
            $root = $domSave->createElement ("markingSetup");
            $root = $domSave->appendChild ($root);
            
            // This will create a sub element of root called supervisors.
            $supervisors = $domSave->createElement ("supervisors");
            $supervisors = $root->appendChild ($supervisors);
            $cnt=1;     
            
            // This will clear the contents of the markingSetup table.
            $sql = "DELETE FROM markingSetup";
            $this->markingSetupDB->query($sql);       
        
            // This will go through all the students;
            foreach($students as $stTag)
            {
                $uid=$stTag->getAttribute('uid');
                $surname=$stTag->getAttribute('surname');
                $forenames=$stTag->getAttribute('forenames');
                $candidate_number=$stTag->getAttribute('candidate_number');
                $degreecode=$stTag->getAttribute('degreecode');
                $hideSt="";
                if (isset($hideStudent[$cnt])) $hideSt=$hideStudent[$cnt];
                                
                // This will create a sub element of supervisers called supervision.
                $supervision = $domSave->createElement ("supervision");
                $supervision = $supervisors->appendChild ($supervision);
                
                // This will create an attribute of supervision called supervisor and set this to the value posted from the marking setup form.
                $attr_supervisor = $domSave->createAttribute ('supervisor');
                $attr_supervisor = $supervision->appendChild ($attr_supervisor);
                $supervision->setAttribute('supervisor', $markerSelected[$cnt]);
                
                // This will create an attribute of supervision called student and set this to the value posted from the marking setup form.
                $attr_student = $domSave->createAttribute ('student');
                $attr_student = $supervision->appendChild ($attr_student);
                $supervision->setAttribute('student', $uid);
                                
                if ($markerSelected[$cnt]!="Select Choice" || $secondMarkerSelected[$cnt]!="Select Choice") $project=$projectChoice[$cnt]; else $project="";
		
		
                // The above line will check to see if a second marker of supervisor has been chosen in order to save project details.
                
                // This will create an attribute of supervision called project and set this to the value posted from the marking setup form. This is dependent on either marker being selected.
                $attr_project = $domSave->createAttribute ('project');
                $attr_project = $supervision->appendChild ($attr_project);
                $supervision->setAttribute('project', htmlentities($project));
    
                // This will create an attribute of supervision called second marker and set this to the value posted from the marking setup form.
                $attr_smuid = $domSave->createAttribute ('secondmarker');
                $attr_smuid = $supervision->appendChild ($attr_smuid);
                $supervision->setAttribute('secondmarker', $secondMarkerSelected[$cnt]);

                $attr_hide = $domSave->createAttribute ('hide');
                $attr_hide = $supervision->appendChild ($attr_hide);
                $supervision->setAttribute('hide', $hideSt);
        
                $title="";
                // This goes through all the projects.
                foreach($projects as $prj) 
                {
                    // Checks to see if project choice posted is equal to that found with proposals file.
                    if ($projectChoice[$cnt]==$prj->getAttribute('label'))
                    {
                        $titleTag=$prj->getElementsByTagName('title');
                        
                        // Sets the title of the project to that which is contained within the xml proposals element.
                        foreach($titleTag as $ttag) $title=$ttag->nodeValue;            
            
                    }
        
                }
                $supervisorFullName="";
                $secondmarkerFullName="";
                
                // Goes through all the markers.
                foreach($markers as $mkTag)
                {
                    $uidMarker=$mkTag->getAttribute('uid');
                    $firstnameMarker=$mkTag->getAttribute('firstname');
                    $surnameMarker=$mkTag->getAttribute('surname');
                    $markertitle=$mkTag->getAttribute('title');
                    $fullName="$surnameMarker $firstnameMarker $markertitle";           
                    
                    // Sets the marker and second marker full name if the posted values for markers ids match.
                    if ($uidMarker==$markerSelected[$cnt]) $supervisorFullName=$fullName;
                    if ($uidMarker==$secondMarkerSelected[$cnt]) $secondmarkerFullName=$fullName;
                }   
		if (!empty($ownProject[$cnt]) && $projectChoice[$cnt]=="own project") $title=$ownProject[$cnt]." (".$markerSelected[$cnt].")"; 
                // Sets up array for saving marking set up details to sqlite database.
                $data = array(
        
                    'uid' => $uid ,
                    'surname' => $surname ,
                    'forenames' => $forenames,
                    'supervisor'=> $markerSelected[$cnt],
                    'secondMarker'=> $secondMarkerSelected[$cnt],
                    'degreecode' => $degreecode,
                    'candidate_number' => $candidate_number,
                    'project' => $title,
                    'supervisorFullName' => $supervisorFullName,
                    'secondmarkerFullName' =>  $secondmarkerFullName,
                    'hide' =>  $hideSt
            
                );
                
                // Inserts data array into table of marking setup for student.
                $this->markingSetupDB->insert('markingSetup', $data); 
        
                $cnt++;
            }
            
            // Saves the generated xml data.
            $domSave->save($this->markingSetupXMLFile);
	    return "saved";
    }
    

        
}
?>
