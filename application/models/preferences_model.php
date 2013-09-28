<?php
class preferences_model extends Model {

    var $progressDB; 
    var $componentid;   
    var $componentVal;
    var $numericVal;
    var $choiceVal;
    var $compNo;
    var $assessment;
    var $dataEntryReportType;
	var $preferencePageSetup="./../common/config/xml/preferencePage.xml";
	var $projectsDegreeRestrictions="./../common/generated/xml/projects.xml";
	var $proposalFile="./../common/generated/xml/proposals.xml";
	var $markerList="./../common/generated/xml/markers.xml";
	var $studentList="./../common/generated/xml/studentlist.xml";
	var $versionFile="./../common/config/xml/version.xml";
	var $degreeAbreviationsFile="./../common/xml/degreeAbreviations.xml";
	var	$projectPreferencesDB;
	
    function preferences_model()
    {
        parent::Model();
        $this->progressDB = $this->load->database('progress', TRUE); 
		$this->projectPreferencesDB = $this->load->database('pref', TRUE);  

    }
	function checkFileExists($filename,$message)
	{
	
		if (!file_exists($filename)) die("<h3>Unable to continue as missing  ".$message."</h3>"); 
	}
	
	
    function createListOfDegreeProjects()
    {
		
        // This will process the proposals file and just leave the identifier for the projects and which degrees it is appropriate for in a new xml file.
        $profilesNo=0;
        $dom2 = new DOMDocument('1.0','UTF-8');
        $dom2->formatOutput = true;
        $root = $dom2->createElement ("projectList");
        $root = $dom2->appendChild ($root);
        $dom=new DOMDocument();
        $dom->load($this->$proposalFile);
        $profilesXpath = new DOMXPath($dom);    
        $queryProjects = "//project";
        $projects=$profilesXpath->query($queryProjects);
        foreach($projects as $proj)
        {
        $projid=$proj->getAttribute('label');
        $hiddenProp=hiddenProject($projid,$this->proposalFile);
        if (empty($hiddenProp))
        {
               $queryProfiles = "//project[@label=\"$projid\"]/profiles/*";

               $projectid = $dom2->createElement ("project");
               $projectid = $root->appendChild ($projectid);
               $attr_uid = $dom2->createAttribute ('label');
               $attr_uid = $projectid->appendChild ($attr_uid);
               $projectid->setAttribute('label', htmlentities($projid));

               $profilesNames=$profilesXpath->query($queryProfiles);
               foreach($profilesNames as $profName)
               {
                   $degree = $dom2->createElement ("degree");
                   $degree = $projectid->appendChild ($degree);
                   $attr_uid = $dom2->createAttribute ('id');
                   $attr_uid = $degree->appendChild ($attr_uid);
                   $degree->setAttribute('id', $profName->nodeName);
               }
        }
        }
        $dom2->save('../../../common/generated/xml/projects.xml');
        return $profilesNo;
    }
	function findLimitChoiceNo()
	{
		// This gains information about how many supervisors may be chosen for any given supervisor by students.

		$doc = new DOMDocument;
		$doc->preserveWhiteSpace = false;
		$doc->Load($this->preferencePageSetup);
		$xpath = new DOMXPath($doc);
		$query = "//limitSupervisorChoice";
		$supervisorChoice = $xpath->query($query);
		$limitChoice=0;
		foreach ($supervisorChoice as $sc) $limitChoice=$sc->getAttribute('limitChoice');
		return $limitChoice;
	}	
	
	 function savePreferences($stuid,$colfirstchoice,$colsecondchoice,$colthirdchoice,$colfourthchoice)
	 {
			   // This will save preferences that students have saved and also check that they have not gone over the quota allocated for each supervisor.
			$limitChoice=$this->findLimitChoiceNo();
			$sameCnt=1;
			while($sameCnt++<5)
			{
				if ($same<=$limitChoice)
				{
					$same=0;
					if ($sameCnt==1) $match=getProposalStaff($pref1);
					if ($sameCnt==2) $match=getProposalStaff($pref2);
					if ($sameCnt==3) $match=getProposalStaff($pref3);
					if ($sameCnt==4) $match=getProposalStaff($pref4);
				
					if ($match==getProposalStaff($pref1)) $same++;
					if ($match==getProposalStaff($pref2)) $same++;
					if ($match==getProposalStaff($pref3)) $same++;
					if ($match==getProposalStaff($pref4)) $same++;
				}
				
			}
			
			if ($same<=$limitChoice) 
			{

			   $sql="DELETE FROM projectPreferences where uid=?";
			   $this->projectPreferencesDB->query($sql,array($uid));
			   $sql = 'DELETE FROM projectPreferences where uid = ?';
			   $this->projectPreferencesDB->query($sql,array($uid));
               $data = array(
                            'uid' => $uid,
							'pref' => "1",
							'project' => $pref1
               );
			   $this->projectPreferencesDB->insert('projectPreferences', $data);  
               $data = array(
                            'uid' => $uid,
							'pref' => "2",
							'project' => $pref2
               );			   
			   $this->projectPreferencesDB->insert('projectPreferences', $data);  
               $data = array(
                            'uid' => $uid,
							'pref' => "3",
							'project' => $pref3
               );			   
			   $this->projectPreferencesDB->insert('projectPreferences', $data);  
               $data = array(
                            'uid' => $uid,
							'pref' => "4",
							'project' => $pref4
               );			   
			   $this->projectPreferencesDB->insert('projectPreferences', $data);  

			}
			return $same>$limitChoice;
	 }
    function getProposalStaff($label)  
    {        
             // This gathers all the proposal staff.
             $domPropInfo=new DOMDocument();
             $domPropInfo->load($this->proposalFile);
             $propInfoXpath = new DOMXPath($domPropInfo);
             
             $queryProjects="//project[@label='$label']/supervisor/*";
             $proposalsInfo=$propInfoXpath->query($queryProjects);
         
             $cnt=1;
             $supervisors="(";

             foreach($proposalsInfo as $propinf)
             {
                 if ($cnt>1) $supervisors.=", ";
                 if (!empty($propinf->nodeName)) $supervisors.=markerName($propinf->nodeName,$markerList);
                 $cnt++; 

             }
         
             return $supervisors.=")";  
    }
	function degreeRestrictions()
    {
        $dom2=new DOMDocument();
        $dom2->load($this->proposalFile);
        $profilesXpath = new DOMXPath($dom2);
        // this finds a list of which degrees a particular project proposal is for.
        $queryProfiles = "//project/profiles";
        return $profilesNo=$profilesXpath->query($queryProfiles)->length;
   }
   function getDateTimeClose($option)
   {
        $dom=new DOMDocument();
        $dom->load($this->preferencePageSetup);
        $prefPXpath = new DOMXPath($dom);
        $queryPrefP= "//closePage";
        $prefP=$prefPXpath->query($queryPrefP);
        foreach($prefP as $pp) {$dateClose=$pp->getAttribute('dateClose'); $timeClose=$pp->getAttribute('time');}
		if ($option=="date") return $dateClose; else return $timeClose;
   }
   function getLink()
   {
        $dom=new DOMDocument();
        $dom->load($this->preferencePageSetup);
        $prefPXpath = new DOMXPath($dom); 
        $query= "//studentWebPageLink";
        $linkResources=$prefPXpath->query($query);
        foreach($linkResources as $lr) $studentWebPageLink=$lr->getAttribute('link');
		return $studentWebPageLink;
   }
   function getStudent($stuid)
   {
               $dom=new DOMDocument();
               $dom->load($this->studentList);
               $studentXpath = new DOMXPath($dom);
               $queryStudents = "//student[@uid='$stuid']";
              return $students=$studentXpath->query($queryStudents);
    }  	
	function getDegreeAbbreviationsXpath()
	{
	           $dom = new DOMDocument;
               $dom->preserveWhiteSpace = false;
               $dom->Load($this->degreeAbreviationsFile);
               return $degreeAbreviationsXpath = new DOMXPath($dom); 
    } 
	function getProposalsXpath()
	{
	               $domProp=new DOMDocument();
                   $domProp->load($this->proposalFile);
                   $propXpath = new DOMXPath($domProp);
                   $queryProjects="//project";
                  return $proposals=$propXpath->query($queryProjects);
	}
	function getDegreeRestrictionsXpath()
	{
	   $domPropR=new DOMDocument();
       $domPropR->load($this->projectsDegreeRestrictions);
       return $propRXpath = new DOMXPath($domPropR);
	}
	
	function findDegreeCodeAbreviation($degreeAbreviationsXpath,$degreecode)
    {
        // this will check to see if the abreviation in the file exists for a particular degree.
        $query = "//degree[@degreecode='$degreecode']";
        $abreviations=$degreeAbreviationsXpath->query($query);
        $allocateAll=false;
        foreach ($abreviations as $ab) 
        {
             $degreecode=$ab->getAttribute('abreviation');
             $allocateAll=$ab->getAttribute('allocateAll');
        }
        if ($allocateAll) $degreecode="_all_";
    
        return $degreecode;
    }
	function getProposalTitle($label)
    {
        // This returns the title of the proposal. 
        $domPropInfo=new DOMDocument();
        $domPropInfo->load($this->proposalFile);
        $propInfoXpath = new DOMXPath($domPropInfo);
        $queryProjects="//project[@label='$label']/title";
        $proposalsInfo=$propInfoXpath->query($queryProjects);
        $title="";
        foreach($proposalsInfo as $propinf) 
        if (!empty($student_proposals_link)) 
            $title=$propinf->nodeValue." ".$this->getProposalStaff($label);
        else $title=$propinf->nodeValue;
        return $title;
    }

	
	function checkIfPrefSaved($uid,$pref,$prefno)
	{
		$sql="SELECT * FROM projectPreferences WHERE uid =? and project = ? and pref = ?";
		$projectPrefQuery=$this->projectPreferencesDB->query($sql,array($uid,$pref,$prefno));
		if (!$projectPrefQuery->num_rows()) return ""; 
		
		return "<b>(Saved Preference ".$prefno.")</b>";
	}
}
