<?php
class studentpreferences_model extends Model {

    var	$projectPreferencesDB;

    function studentpreferences_model()
    {
        parent::Model();
	// Loads student preference database to be used in project choices menu.
        $this->projectPreferencesDB = $this->load->database('pref', TRUE);  
        
    }
    

    
    function getPreferences($stuid)
    {
        $sql = "SELECT * FROM projectPreferences WHERE uid =? ORDER BY pref";
        return $query=$this->projectPreferencesDB->query($sql, array($stuid)); 

    }
    function createListOfStudentChoices($students,$projects)
    {
      // This will create a list of student choices. It is based on items that are held within a student choices database.


        $domStudentPreferences = new DOMDocument('1.0','UTF-8');
        $domStudentPreferences->formatOutput = true;
        $root = $domStudentPreferences->createElement ("studentPreferences");
        $root = $domStudentPreferences->appendChild ($root);
    
        foreach($students as $stTag)
        {
            $uid=$stTag->getAttribute('uid');
            $surname=$stTag->getAttribute('surname');
            $forenames=$stTag->getAttribute('forenames');
            $candidate_number=$stTag->getAttribute('candidate_number');
            $degreecode=$stTag->getAttribute('degreecode');    
            $student="$forenames $surname ($degreecode $uid)";        
            
            $studentChoice = $domStudentPreferences->createElement ("studentChoice");
            $studentChoice = $root->appendChild ($studentChoice);
            $attr_student = $domStudentPreferences->createAttribute ('student');
            $attr_student = $studentChoice->appendChild ($attr_student);
            $studentChoice->setAttribute('student',$student);
            
            $sql = "SELECT * FROM projectPreferences WHERE uid =? ORDER BY pref";
            $query=$this->projectPreferencesDB->query($sql, array($uid)); 
             // Goes through each database entry for student preferences.
            foreach($query->result() as $row)
            {
                $data['projid']=$row->project;
                $rank=$row->pref;

                $pref = $domStudentPreferences->createElement ("pref");
                $pref = $studentChoice->appendChild ($pref);
                $attr_rank = $domStudentPreferences->createAttribute ('rank');
                $attr_rank = $pref->appendChild ($attr_rank);
                $pref->setAttribute('rank', $rank);
        
                $attr_projectTitle = $domStudentPreferences->createAttribute ('projectTitle');
                $attr_projectTitle = $pref->appendChild ($attr_projectTitle);
               
                foreach($projects as $prj)
                {
                    $projid=$prj->getAttribute('label');
                         
                     // Checks to see if the project id matches the preference chosen by the student.
                     if ($projid==$data['projid']) 
                     {
                        $titleTag=$prj->getElementsByTagName('title');
                                
                        // Sets the title of the project to that which is contained within the xml proposals element.
                        foreach($titleTag as $ttag) $projectTitle=$ttag->nodeValue;
                                
                        // Retrieves information about supervisors held with the supervisor node for xml proposals.
                        $supidsText=$this->proposals_model->getSupervisorList($prj->getElementsByTagName('supervisor'));
                     } 
                }       
                 $pref->setAttribute('projectTitle', $projectTitle." ".$supidsText);
            }
        
        } 
        $studentPrefsXpath = new DOMXPath($domStudentPreferences);
        $queryStudentPrefs = "//studentChoice";
        return $studentPrefs=$studentPrefsXpath->query($queryStudentPrefs);        
    }
        
}
?>
