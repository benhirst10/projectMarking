<?php
class students_model extends CI_Model {

    function __construct() {
        parent::__construct();
        
        
    }
    
    function checkIfStudentsFileExists()
    {
            if (file_exists('../common/generated/xml/studentlist.xml')) return true; else return false;
    
        
     }  
    
    
    function getStudentSessionStamp($sessionStamp)
    {
       if (empty($sessionStamp)) 
           {
                 // This creates a stamp that is used to ensure the student list is only used by session. If the list used by the marking system
             // is subsequently updated this will not affect the present setup.
                 $sessionStamp = "_".date("Ymdhis")."_".$_SERVER["PHP_AUTH_USER"];
                 $dom=new DOMDocument();
                 $dom->load('../common/generated/xml/studentlist.xml');
                 $newname="../common/generated/xml/studentlist$sessionStamp.xml";
                 file_put_contents($newname, $dom->saveXML());

       } 
       return $sessionStamp;
    
    }
    
    function getAllStudentsAlphaOrder($sessionStamp)
    {
            $domStudents=new DOMDocument();
            $domStudents->load("../common/generated/xml/studentlist$sessionStamp.xml");
            $studentXpath = new DOMXPath($domStudents);
            $queryStudents = "//student";
            return $students=$studentXpath->query($queryStudents);
    
    }
    
    function getAllStudentsSupervisorOrder($sessionStamp)
    {
            $domStudents=new DOMDocument();
            $domStudents->load("../common/generated/xml/studentlistSup$sessionStamp.xml");
            $studentXpath = new DOMXPath($domStudents);
            $queryStudents = "//student";
            return $students=$studentXpath->query($queryStudents);
    
    }   
    
    function getAllStudentsSecondMarkerOrder($sessionStamp)
    {
            $domStudents=new DOMDocument();
            $domStudents->load("../common/generated/xml/studentlistSM$sessionStamp.xml");
            $studentXpath = new DOMXPath($domStudents);
            $queryStudents = "//student";
            return $students=$studentXpath->query($queryStudents);
    
    }   
    
    function getAllStudentsProjectOrder($sessionStamp)
    {
            $domStudents=new DOMDocument();
            $domStudents->load("../common/generated/xml/studentlistProject$sessionStamp.xml");
            $studentXpath = new DOMXPath($domStudents);
            $queryStudents = "//student";
            return $students=$studentXpath->query($queryStudents);
    
    } 
    
    function getAllStudentsUidOrder($sessionStamp)
    {
            $domStudents=new DOMDocument();
            $domStudents->load("../common/generated/xml/studentlistUid$sessionStamp.xml");
            $studentXpath = new DOMXPath($domStudents);
            $queryStudents = "//student";
            return $students=$studentXpath->query($queryStudents);
    
    }       
    
    
    function getStudent($uid)
    {
    
            $domStudents=new DOMDocument();
            $domStudents->load("../common/generated/xml/studentlist.xml");
            $studentXpath = new DOMXPath($domStudents);
            $queryStudents = "//student[@uid='$uid']";
            return $student=$studentXpath->query($queryStudents);   
    }
    
    
       function sortListByMarkerProject($typeOrder,$markingSetupDB,$sessionStamp)
       {
       // This sorts the marking setup file into the order that was requested.

            $dom = new DOMDocument('1.0','UTF-8');
            $dom->formatOutput = true;
            $root = $dom->createElement ("studentlist");
            $root = $dom->appendChild ($root);
            if ($typeOrder=="supervisor") 
            {
                $query="SELECT uid,forenames,surname,candidate_number,degreecode FROM markingSetup ORDER BY supervisorFullName,surname,forenames";
                $outputFile="../common/generated/xml/studentlistSup$sessionStamp.xml";
            }
            if ($typeOrder=="secondmarker")
            {
                $query="SELECT uid,forenames,surname,candidate_number,degreecode FROM markingSetup ORDER BY secondmarkerFullName,surname,forenames";
                $outputFile="../common/generated/xml/studentlistSM$sessionStamp.xml";
            }
            if ($typeOrder=="project") 
            {
                $query="SELECT uid,forenames,surname,candidate_number,degreecode FROM markingSetup ORDER BY project,surname,forenames";
                $outputFile="../common/generated/xml/studentlistProject$sessionStamp.xml";
            
            }
            if ($typeOrder=="uid") 
            {
                $query="SELECT uid,forenames,surname,candidate_number,degreecode FROM markingSetup ORDER BY uid,surname,forenames";
                $outputFile="../common/generated/xml/studentlistUid$sessionStamp.xml";
            
            }       
            if ($typeOrder!="alpha" && $typeOrder!="") 
            {
                $studentsMarkingSetupQuery=$markingSetupDB->query($query);
                foreach($studentsMarkingSetupQuery->result() as $row)
                {

                   $student = $dom->createElement ("student");
                   $student = $root->appendChild ($student);
                   $attr_uid = $dom->createAttribute ('uid');
                   $attr_uid = $student->appendChild ($attr_uid);
                   $uid =$row->uid;
                   $student->setAttribute('uid', $uid);

                   $attr_forenames = $dom->createAttribute ('forenames');
                   $attr_forenames = $student->appendChild ($attr_forenames);
                   $forenames = $row->forenames;
                   $student->setAttribute('forenames', $forenames);

                   $attr_surname = $dom->createAttribute ('surname');
                   $attr_surname = $student->appendChild ($attr_surname);
                   $surname =$row->surname;
                   $student->setAttribute('surname', $surname);

                   $attr_candidate_number = $dom->createAttribute ('candidate_number');
                   $attr_candidate_number = $student->appendChild ($attr_candidate_number);
                   $candidate_number =$row->candidate_number;
                   $student->setAttribute('candidate_number', $candidate_number);

                   $attr_degreecode = $dom->createAttribute ('degreecode');
                   $attr_degreecode = $student->appendChild ($attr_degreecode);
                   $degreecode = $row->degreecode;
                   $student->setAttribute('degreecode', $degreecode);

                } 

                $dom->save($outputFile);
        }
        }   
    
        
}
?>
