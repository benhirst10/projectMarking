<?php

// Title: Marking setup controller for marking system
// Author: B. M. Hirst
// Year: 2011

class markingSetup extends CI_Controller {

    var $projects;  
    var $markers;
    var $versionInfo;
    var $students;
    var $markersMax;
    var $profilesNo;
    var $markings;
    var $modcode;	

    public function __construct() {
        parent::__construct();
        $this->load->model('markingsetup_model');
        $this->load->model('students_model');
        $this->load->model('markers_model');
        $this->load->model('markersmax_model');
        $this->load->model('proposals_model');
        $this->load->model('studentpreferences_model');
        $this->load->model('degreeabreviations_model');
        $this->load->model('version_model');
        $this->load->model('ownproject_model');
	$this->load->model('emailed_model');
	$this->load->model('markingscheme_model');
        $this->load->library('session');
    
        // Loads projects from xml file to be used in project choices menu.     
        if ($this->proposals_model->checkIfProposalsFileExists()) $this->projects = $this->proposals_model->getAllProjectChoices(); else $this->projects="";
    
        // Loads markers from xml file to be used in markers menu and allocations information.
        if ($this->markers_model->checkIfMarkersFileExists()) $this->markers = $this->markers_model->getMarkers(); else $this->markers="";
    
   	 // Loads information about links to proposals and svn.
    	$this->versionInfo=$this->version_model->getVersionInfo();
    
        // Loads markers maximums if file exists.
        if ($this->markersmax_model->checkIfMarkersMaxFileExists()) $this->markersMax  = $this->markersmax_model->getMarkersMax(); else $this->markersMax="";   
	
	// Gets the modcode from the marking scheme xml file;
	$this->modcode=$this->markingscheme_model->getMarkingSchemeModcode();
    
    }
    function markersMenu($studentCount,$supervisorChoice,$secondMarkerChoice)
    {
        // This function displays drop down menus for both second marker and supervisor.
        
        // Sets the student count to be displayed in menu.
        $data['$studentCount']=$studentCount;
        
        $menucnt=1;
        while($menucnt<=2)
        {

            // Checks to see which menu name is to be displayed.
            if ($menucnt==1) $data['menuChoice']="markerSelected";
            else $data['menuChoice']="secondMarkerSelected";
            
            // Displays the drop down menu start information.
            $this->load->view('staff/markingSetup/markersSupSMSelectStart', $data);
            
            // Goes through all the choice of markers.
            if ($this->markers_model->checkIfMarkersFileExists()) foreach($this->markers as $mkTag)
            {
                $uid=$mkTag->getAttribute('uid');
                $firstname=$mkTag->getAttribute('firstname');
                $surname=$mkTag->getAttribute('surname');
                $title=$mkTag->getAttribute('title');
                $data['selectedTag']="";
                
                // Checks which menu is being displayed and sets the id to check to supervisor or second marker.
                if ($menucnt==1) $markerID=$supervisorChoice; else $markerID=$secondMarkerChoice;
                
                // Checks the marker id set against the saved marker and makes sure that this will be selected in the menu.
                if ($uid==$markerID) $data['selectedTag']="SELECTED";
               
                // Sets the information to be shown in menu option view.
                $data['markerid']=$uid;
                $data['markerName']="$title $firstname $surname";
                
                // Displays a marker choice.
                $this->load->view('staff/markingSetup/markersSupSMSelectOption',$data);


            }
            // Displays the end of the drop down menu.
            $this->load->view('staff/markingSetup/markersSupSMSelectEnd');
            
            $menucnt++;
        }   
    
    
    }
    
    function projectChoicesMenu($stuid,$studentCount,$projectChoice,$prefDisplay,$abreviation,$allPref,$proposals_link,$ownProjectTitle,$supervisorOwnChoice)
    {
        // This function displays a list of all preferences when chosen. It also displays a project choices menu.
        
        // Sets the student count to be displayed in project choices menu.
        $data['studentCount']=$studentCount;
    
        // Sets the student userid to be used in div.
        $data['stuid']=$stuid;
    
        // Sets the student project choice to see if div should be displayed for own project.
        $data['projectChoice']=$projectChoice;  
	
	// Sets the own project title to be displayed.
	$data['ownProjectTitle']=$ownProjectTitle;
	
	// Sets the own project supervisor to be displayed.
	$data['supervisorOwnChoice']=$supervisorOwnChoice;
        
        // Displays the start of thet table cell for project choices.
        $this->load->view('staff/markingSetup/projectChoicesStart');
       
    
        // Displays a list of all preferences before drop down menu if option chosen.
        if (!empty($allPref)) $this->studentPreferenceChoicesSubMenuList($stuid,$studentCount,$projectChoice,$prefDisplay,"list",$proposals_link);      
        
        // Displays the start of the project choices start menu.
        $this->load->view('staff/markingSetup/projectChoiceSelectStart', $data);
        
        // Displays the student preferences in the project choices menu.
        $stchoicescnt=$this->studentPreferenceChoicesSubMenuList($stuid,$studentCount,$projectChoice,$prefDisplay,"menu","");
        
        // Displays all project choices excluding student preferences in the project choices menu.
        $this->allProjectChoicesSubMenu($this->session->userdata('projids'),$projectChoice,$studentCount,$stchoicescnt,$abreviation);
        
        // Displays the end of the drop down menu and also the end of the table cell.
        $this->load->view('staff/markingSetup/projectChoiceSelectEnd',$data); 
    
    
    }
    
    
    function studentPreferenceChoicesSubMenuList($stuid,$studentCount,$projectChoice,$prefDisplay,$listType,$proposals_link)
    {
        // This function is used to display a list of preferences or student preferences menu items.
        $stchoicescnt=1;
        
        // This setups up data that is to be shown in the menu;
        $data['stuid']=$stuid;
        $data['studentCount']=$studentCount;
        
        // This sets up the link to staff proposals for the list of student preferences.
        $data['proposals_link']=$proposals_link;
        
        $projids="";
        
        // This retrieves a list of student preferences for a particular student from the preference database.
        $studentChoicesQuery=$this->studentpreferences_model->getPreferences($data['stuid']);
        
         // Goes through each database entry for student preferences.
         foreach($studentChoicesQuery->result() as $row)
         {
                       $data['projid']=$row->project;
                       $rank=$row->pref;
                        $projids[$stchoicescnt]=$data['projid'];
                        $data['selectedTag']="";
                        
                        // Checks if the project id saved set up matches the present student preference. If it does this chosen to be selected in menu.
                        if ($data['projid']==$projectChoice && !empty($projectChoice) &&  $projectChoice!="Select Choice") $data['selectedTag']="SELECTED";
                        
                        // Sets the preference to be selected in menu to the first preference when no project id set up saved or rank chosen.
                        if ((empty($projectChoice) || $projectChoice=="Select Choice") && empty($prefDisplay) && $rank=='1') $data['selectedTag']="SELECTED";
                        
                        // Sets the preference to be selected in menu to that which set for rank, if not project id setup is saved.
                        if ((empty($projectChoice) || $projectChoice=="Select Choice") && $rank==$prefDisplay) $data['selectedTag']="SELECTED";
                        
                        $foundTitle=false;
                        $data['projectTitle']="";
                        $supidsText="";
                        // Gathers more information about the preferences selected by student.
                        if ($this->proposals_model->checkIfProposalsFileExists()) foreach($this->projects as $prj)
                        {
                            $projid=$prj->getAttribute('label');
                            
                            // Checks to see if the project id matches the preference chosen by the student.
                            if ($projid==$data['projid']) 
                            {
                                // Sets the title of the project to that which is contained within the xml proposals element.
                                $data['projectTitle']=$this->proposals_model->getProjectTitle($prj->getElementsByTagName('title')); 
                                
                                // Retrieves information about supervisors held with the supervisor node for xml proposals.
                                $supidsText=$this->proposals_model->getSupervisorList($prj->getElementsByTagName('supervisor'));
                            } 
                        }
                        // Sets the project title to be diplayed in menu to that containing the project title and associated supervisors.    
                        $data['projectTitle'].="$supidsText (P$rank)";   
                        
                        // Displays drop down menu items when function called with list type of menu.
                        if ($listType=="menu") $this->load->view('staff/markingSetup/projectChoiceSelectPrefOption', $data);
                        
                        // Displays list items when fun (fdv1)ction called with list type of list.
                        if ($listType=="list") $this->load->view('staff/markingSetup/projectChoiceSelectPrefListItem', $data);
                        $stchoicescnt++;

        }
        // Stores project preferences for student in a session to make sure they are not repeated in all projects choice menu.
        $this->session->set_userdata('projids',$projids);
        return $stchoicescnt;
    }
    
    function allProjectChoicesSubMenu($projids,$projectChoice,$studentCount,$stchoicescnt,$abreviation)
    {       
        // This function displays all project choices for the student in a drop down menu.
        
        // Displays the option group heading for all choices within the project choices menu.
        $this->load->view('staff/markingSetup/projectChoiceSelectAllChoices');
        
        // Sets the student count to be displayed in menu.
        $data['studentCount']=$studentCount;    
        
        // Goes through all the project proposals.  
        if ($this->proposals_model->checkIfProposalsFileExists()) foreach($this->projects as $prj)
        {
            $data['projid']=$prj->getAttribute('label');    
            $cnt=1;
            
            // Sets the project to be displayed if it matches the saved setup project choice held within xml file.
            if ($data['projid']==$projectChoice && $projectChoice!="Select Choice") $data['selectedTag']="SELECTED"; else $data['selectedTag']="";
            
            // Checks to see if preferences have been saved for student to avoid looping through them.
            if ($stchoicescnt>1) $prefProjid=false; else $prefProjid=true;
            
            // Loops through preferences chosen by student to see if current project matches the preference. When matching it makes sure this is not displayed in list of all choices.
            while(!$prefProjid && $cnt<=4)
            {
                if ($data['projid']==$projids[$cnt]) $prefProjid=true;
                $cnt++;
            }
            
            // Checks to see if profile restrictions have been setup and if this project is part of choices for the degree the student has chosen.
            // It is also checks for where no profile restrictions have been chosen it is possible to display project choice.
            if ((($this->profilesNo>0 && $this->proposals_model->checkIfdegreeRestricted($abreviation,$prj->getElementsByTagName('profiles'))>0) ||  $abreviation=="_all_") || $this->profilesNo==0) 
            {
                 // Sets the title of the project to that which is contained within the xml proposals element.
                $data['projectTitle']=$this->proposals_model->getProjectTitle($prj->getElementsByTagName('title'));  
                
                // Retrieves information about supervisors held with the supervisor node for xml proposals.
                $supidsText=$this->proposals_model->getSupervisorList($prj->getElementsByTagName('supervisor'));
                
                // Sets the hidden information of the project to that which is contained within the xml proposals element.
                $hiddenInfo=$this->proposals_model->getHiddenInfo($prj->getElementsByTagName('hidden'));
                
                // Sets the project title to contain the title, list of supervisors and found hidden information.           
                $data['projectTitle'].=$supidsText.$hiddenInfo;
                
                // Displays the project choice option if it is not part of the student preference list or no preferences have been chosen.
                if (!$prefProjid || $stchoicescnt==1) $this->load->view('staff/markingSetup/projectChoiceSelectAllOption', $data);
            }

        }   
    
    }
    function markersAndProjectChoiceInfoTable($proposals_link)
    {
        // This function displays information about how many staff have been allocated as supervisor and second marker. It also displays details on each project's allocations of different staff.
        // Sets the link to proposals to given for each project in the table.
        $data['proposals_link']=$proposals_link;
        

            // Displays the top of the number of allocations table for staff.
            $this->load->view('staff/markingSetup/markersMaxTableTop');
            
            $maxSupTotal=0;
            $maxSMTotal=0;
            
            // Goes through all the markers.
            if ($this->markers_model->checkIfMarkersFileExists()) foreach ($this->markers as $mks) 
            {
                $data['uid']=$mks->getAttribute('uid');
                $data['maxSup']=0;
                $data['maxSM']=0;
                if ($this->markersmax_model->checkIfMarkersMaxFileExists())
                {
                         
                        // Gets both supervisor and second marker maximums data.
                        $data['maxSup']=$this->markersmax_model->getMaxForMarker($data['uid'],'supervisorMax');
                        $data['maxSM']=$this->markersmax_model->getMaxForMarker($data['uid'],'secondMarkerMax');
                        if (empty($data['maxSup'])) $data['maxSup']=0;
                        if (empty($data['maxSM'])) $data['maxSM']=0;
                } 
                
                // Displays markers maximum data entry boxes and sets their maximums to data stored. It also displays text boxes that show information on how far maximum is met.
                $this->load->view('staff/markingSetup/markersMaxTableRow',$data);

            }
            // Displays the end of the markers maximums and information table.
            $this->load->view('staff/markingSetup/markersMaxTableBottom');
            
            // Displays the top of the information about markers allocated to each project title.
            $this->load->view('staff/markingSetup/projectCountsTableTop');
            
            // Goes through all the projects.
            if ($this->proposals_model->checkIfProposalsFileExists()) foreach($this->projects as $prj)
            {
                $data['projid']=$prj->getAttribute('label');

                 // Sets the title of the project to that which is contained within the xml proposals element.
                $data['projectTitle']=$this->proposals_model->getProjectTitle($prj->getElementsByTagName('title'));                     
                
                // Sets the hidden information of the project to that which is contained within the xml proposals element.
                $hiddenInfo=$this->proposals_model->getHiddenInfo($prj->getElementsByTagName('hidden'));
                
                // Retrieves information about supervisors held with the supervisor node for xml proposals.
                $supidsText=$this->proposals_model->getSupervisorList($prj->getElementsByTagName('supervisor'));
                
                // Sets the project title to contain the title, list of supervisors and found hidden information.   
                $data['projectTitle'].=$supidsText.$hiddenInfo;
                
                // Displays a text area for each project choice ready display information about staff allocations to projects.
                $this->load->view('staff/markingSetup/projectCountsTableRow',$data);

            }
            
            // Displays the end of the project staff allocation information table.
            $this->load->view('staff/markingSetup/projectCountsTableBottom');


  
    }   
    
    function hiddenProjectChoicesAndMarkers()
    {
        // This function creates hidden input for storing totals used by javascript to generate information about allocations.
        
        // Goes through all the markers.
        if ($this->markers_model->checkIfMarkersFileExists()) foreach ($this->markers as $mks) 
        {
                $data['uid']=$mks->getAttribute('uid');
                
                // Creates a hidden input for calculation of marker allocations.
                $this->load->view('staff/markingSetup/markerHidden',$data);
        
        }
        
        // Goes through all the projects.
        if ($this->proposals_model->checkIfProposalsFileExists()) foreach($this->projects as $proj)
        {
                $data['projid']=$proj->getAttribute('label');
                
                // Goes through all the markers if project id is not empty.
                if (!empty($data['projid']) && $this->markers_model->checkIfMarkersFileExists()) foreach ($this->markers as $mks)     
                {
                        $data['uid']=$mks->getAttribute('uid');
                        
                        // Creates a hidden input for storing totals about allocations for staff member for a project.
                        $this->load->view('staff/markingSetup/projectChoiceHidden',$data);
        
                }
        }   
        
        $data['projid']="Own Project";
        
        // Goes through all the markers.
        if ($this->markers_model->checkIfMarkersFileExists()) foreach ($this->markers as $mks) 
        {
                 $data['uid']=$mks->getAttribute('uid');
                 
                  // Creates a hidden input for storing totals about allocations for staff member for own project.
                 $this->load->view('staff/markingSetup/projectChoiceHidden',$data);
        }
    }

    
    function missingXmlFiles()
    {
        // This function will check if markers and proposals xml files are present. If any are missing an error message is displayed as a row
        // in the main table.
    
        $data['missingFile']="";
        
        // Checks to see if the files are missing and creates error message accordingly. 
        if (!$this->proposals_model->checkIfProposalsFileExists()) $data['missingFile'].="common/generated/xml/proposals.xml<br/>";
        if (!$this->markers_model->checkIfMarkersFileExists()) $data['missingFile'].="common/generated/xml/markers.xml<br/>";
        
        // Displays error message within main marking setup table.
        if (!empty($data['missingFile'])) $this->load->view('staff/markingSetup/missingFile',$data);        
    
    
    }
    
    
    function emailMissingPreferencesConfirmed()
    {
       $this->load->library('email');
       
       // Retrieves a list of students on the module.
       $this->students = $this->students_model->getAllStudentsAlphaOrder('');
    
       // Goes through all the students on the module.	
       foreach($this->students as $stTag)
       {
            $stuid=$stTag->getAttribute('uid');
            $surname=$stTag->getAttribute('surname');
            $forenames=$stTag->getAttribute('forenames');
            $candidate_number=$stTag->getAttribute('candidate_number');
            $degreecode=$stTag->getAttribute('degreecode');	    
	    $projectChoice="";
            if ($this->markingsetup_model->checkIfMarkingSetupFileExists()) 
            {
                    // Retrieves the saved marking setup for the particular student.
                    $studentMarkings=$this->markingsetup_model->getSavedMarkingSetup($stuid);
                
                    // Goes through saved markings for the student.
                    foreach ($studentMarkings as $mks) $projectChoice=$mks->getAttribute('project');

                    
            }
	    
	    // Retrieves the preferences for the student.
	    $studentChoicesQuery=$this->studentpreferences_model->getPreferences($stuid);
	    if ($studentChoicesQuery->num_rows()==0 && empty($projectChoice))
	    {
	    	    echo "Emailing $forenames $surname ($stuid)<br/>";
		    
        	    // Emails the student reminder about submitting preferences.
        	    $this->email->from('bmh2@le.ac.uk', 'Ben Hirst');
        	    $this->email->to('bmh2@le.ac.uk');
        	    $this->email->subject($this->input->post('emailSubject'));
        	    $this->email->message($this->input->post('emailBody'));
        	    $this->email->logandsend('./../application/log/emaillog.log');		 
	    }
       }
    
    }
    
    
    function emailMissingPreferences()
    {
	
	// This function will display a form to allow a customized message to be sent to students who have
	// not submitted their project preferences. If a button is pressed on this form this function will be called again.
	// The form will then not be displayed again and emails will be sent if the coresponding email button was pressed.
	
	$this->load->helper('url');
	
	// Checks that this function has not been called after a button has been pressed on the customized email form.
	if ($this->input->post('Email',TRUE)!="Email" && $this->input->post('Cancel',TRUE)!="Cancel")
	{
		$this->load->helper('form');
		
		// This will load header information for cutomized email html page.
		$this->load->view("staff/markingSetup/headerMissingPreferences");  
		
    		$this->load->library('table');
		$data['modcode']=$this->modcode;
		
		// This will display the customized email form.
	    	$this->load->view("staff/markingSetup/emailMissingPrefForm",$data);
	} else
	{
		
		// When the email button has been pressed on the customized email form it will direct to another function to email students. 
		if ($this->input->post('Email',TRUE)=="Email") echo $this->emailMissingPreferencesConfirmed();
		
		// Goes back to main setup page when either email or cancel button has been pressed. 
		redirect('staff/markingSetup/markingSetupPage','refresh');
	}
    
    
    }
    
    
    function markingSetupPage()
    {   
    
        // This function displays the whole marking setup page. It shows for each student, drop down menus for supervisor, second markers and projects. 
        // There is also information about supervisor and second marker allocations for each staff and project marker allocations.
            
        $this->load->helper('url');
        $this->load->helper('form');
    
        // The following sets up session stamp to make sure that only a seperate copy of students list is used per marking set up.
        $data['sessionStamp']=$this->session->userdata('sessionStamp');
        if ($this->students_model->checkIfStudentsFileExists()) $data['sessionStamp']=$this->students_model->getStudentSessionStamp($data['sessionStamp']);
        else die("<h1>No common/generated/xml/studentlist.xml file exists</h1>");
        
        // Sets the type order (order of students) variable to be shown in marking setup page to that which is contained within the session.     
        $data['typeOrder']=$this->session->userdata('typeOrder');

        // Retrieves which preference to display from session data.
        $data['prefDisplay']=$this->session->userdata('prefDisplay');
        
        // Retrieves from sesison data, whether a list of all student preference choices should be displayed before project choices drop down menu.
        $data['allPref']=$this->session->userdata('allPref');  
        
         // Retrieves from sesison data, whether a csv of all student preference choices should be created.
        $data['prefCSV']=$this->session->userdata('prefCSV');
        
        // Retrieves from sesison data, whether to show students that have been ticked to be hidden.
        $data['showAll']=$this->session->userdata('showAll');
        
        $proposals_link="";
        // Retrieves the link to staff proposals file from version xml data.
        foreach ($this->versionInfo as $version) $proposals_link=$version->getAttribute('proposals_link');
        
        // Obtains how many profile restrictions are found within the proposals file.
        if ($this->proposals_model->checkIfProposalsFileExists()) $this->profilesNo=$this->proposals_model->findDegreeRestrictions(); else $this->profilesNo=0;
        
        $data['studentCount']=0;     
        $projectChoice="";
        $supervisorChoice="";
        $secondMarkerChoice="";                 
        $data['modcode']=$this->modcode;
	
        // The following if statements see which ordering of students is required and loads the associated ordered student list.
        if (empty($data['typeOrder'])) $this->students = $this->students_model->getAllStudentsAlphaOrder('');
        if ($data['typeOrder']=='alpha') $this->students = $this->students_model->getAllStudentsAlphaOrder($data['sessionStamp']);
        if ($data['typeOrder']=='supervisor')   $this->students = $this->students_model->getAllStudentsSupervisorOrder($data['sessionStamp']);
        if ($data['typeOrder']=='secondmarker') $this->students = $this->students_model->getAllStudentsSecondMarkerOrder($data['sessionStamp']);
        if ($data['typeOrder']=='project') $this->students = $this->students_model->getAllStudentsProjectOrder($data['sessionStamp']);
        if ($data['typeOrder']=='uid') $this->students = $this->students_model->getAllStudentsUidOrder($data['sessionStamp']);
	
	// This will load header information for html page.
	$this->load->view("staff/markingSetup/headerMarkingSetup");
	
        // This will create the top of the marking setup form.
        $this->load->view('staff/markingSetup/markingSetupFormPart1',$data);
        
        // This will display the main marking setup table top.
        $this->load->view('staff/markingSetup/tableTop',$data); 
        
        // Displays a row in the table giving information when missing proposals file and/or markers file.
        $this->missingXmlFiles();       
        
        $stdispcnt=0;
        
        // Goes through all the students.
        $displayInfoTable=0;
        foreach($this->students as $stTag)
        {
            $data['studentCount']++;
            $data['stuid']=$stTag->getAttribute('uid');
            $data['surname']=$stTag->getAttribute('surname');
            $data['forenames']=$stTag->getAttribute('forenames');
            $data['candidate_number']=$stTag->getAttribute('candidate_number');
            $data['degreecode']=$stTag->getAttribute('degreecode');
	    
	    // Retrieves whether the an email of allocations was sent.
	    $emailStudent=$this->emailed_model->getEmailedAllocation($data['stuid']);
	    if (!empty($emailStudent)) $data['emailedStudent']="(Email: $emailStudent)"; else $data['emailedStudent']="";
            
            // Retrieves the degree abreviation code for the degree the student is doing when degree profile restrictions are in place.
            if ($this->profilesNo>0 && $this->degreeabreviations_model->checkIfDegreeAbreviationsFileExists())
	    	 $abreviation=$this->degreeabreviations_model->getDegreeCodeAbreviation($data['degreecode']);
            else $abreviation=$data['degreecode'];
            
            if ($this->markingsetup_model->checkIfMarkingSetupFileExists()) 
            {
                    // Retrieves the saved marking setup for the particular student.
                    $studentMarkings=$this->markingsetup_model->getSavedMarkingSetup($data['stuid']);
                
                    // Goes through saved markings for the student.
                    foreach ($studentMarkings as $mks)
                    {
                        $supervisorChoice=$mks->getAttribute('supervisor');
                        $secondMarkerChoice=$mks->getAttribute('secondmarker');
                        $projectChoice=$mks->getAttribute('project');
                        $hideChoice=$mks->getAttribute('hide');
                    
                    }
            }
	    
	    $ownProjectTitle="";
	    $supervisorOwnChoice="";
            if ($this->ownproject_model->checkIfOwnProjectSetupFileExists() && $projectChoice=="own project") 
            {
                    // Retrieves the saved own project setup for the particular student.
                    $studentOwnProject=$this->ownproject_model->getSavedOwnProjectSetup($data['stuid']);
                
                    // Goes through saved own projects for the student.
                    foreach ($studentOwnProject as $op)
                    {
                        $supervisorOwnChoice=$op->getAttribute('supervisor');
                        $ownProjectTitle=$op->getAttribute('projectTitle');
                    }
            }	    
	    
        
            // This checks to see if the student is not hidden or all students are to be shown.
            if (empty($hideChoice) || !empty($data['showAll']))
            {
                if (!empty($data['showAll']) && !empty($hideChoice)) $data['checkedTag']="CHECKED"; else $data['checkedTag']="";
            
                // Displays information about student such as their name.
                $this->load->view('staff/markingSetup/markingSetup', $data);
            
                // Displays both markers menu for supervisor and student marker.
                $this->markersMenu($data['studentCount'],$supervisorChoice,$secondMarkerChoice);
            
                // Displays project choices menu for student.
                $this->projectChoicesMenu($data['stuid'],$data['studentCount'],$projectChoice,$data['prefDisplay'],$abreviation,$data['allPref'],$proposals_link,$ownProjectTitle,$supervisorOwnChoice);
                
                // Will make sure the table is shown at the first non hidden student.
                $displayInfoTable++;
        
                // Used to show extra rows at the end of the marking setup table.
                $stdispcnt++;
            } 
         
            // Checks to see if the student has been hidden     
            if (!empty($hideChoice) && empty($data['showAll']))
            {
                $data['supervisorChoice']=$supervisorChoice;
                $data['secondMarkerChoice']=$secondMarkerChoice;
                $data['projectChoice']=$projectChoice;
                $data['hideChoice']=$hideChoice;
		$data['ownProjectTitle']=$ownProjectTitle;
                // Displays hidden input boxes with the above already selected values for student.
                $this->load->view('staff/markingSetup/hiddenMarkingSetup', $data);
            }
        
             // Checks to see if this is the first student row so that a table can be added in the subsequent cell.
            if ($displayInfoTable==1) 
            {
                // Displays a table given information about marker and project allocations.
               // $this->markersAndProjectChoiceInfoTable($proposals_link);
        
                // Makes sure that the table is not shown again.
                //$displayInfoTable++;  
            }
        }
		 $this->markersAndProjectChoiceInfoTable($proposals_link);
        // Checks to see if students who have been displayed are less that 100 so that extra rows can be added.
		/*
        if ($stdispcnt<100)
        {
            $cnt=$stdispcnt-1;
            while($cnt++<=98) $this->load->view('staff/markingSetup/mainTableExtraRows');
            
        } */
        // Creates hidden input boxes for totals associated with allocations.
        $this->hiddenProjectChoicesAndMarkers();
        
        // Creates the end of the marking setup form.
        $this->load->view('staff/markingSetup/markingSetupFormPart2',$data);
		$this->load->view("staff/markingSetup/footerMarkingSetup");
        
    }
    
    function saveMarkingSetupProduceCSVEmailInfo()
    {
        // This function will save marking setup if the email button is pressed or save button. It will also create a csv file for either
        // supervisors or student preferences if either button is pressed.
    
        $this->load->helper('url');
        
        // The following if statements check which CSV button has been pressed.
        if ($this->input->post('prefCSV')=="Preferences CSV") $producePrefCSV=true; else $producePrefCSV=false;
        if ($this->input->post('supervisorsCSV')=="Supervisors CSV") $produceSupCSV=true; else $produceSupCSV=false;

        // Will check to see that a csv is not required.
        if (!$producePrefCSV && !$produceSupCSV)
        {

            // This stores posted variable in a session to be used by marking setup page.
            $this->session->set_userdata('prefDisplay',$this->input->post('prefDisplay',TRUE));
            $this->session->set_userdata('typeOrder',$this->input->post('typeOrder',TRUE));
            $this->session->set_userdata('allPref',$this->input->post('allPref',TRUE));
            $this->session->set_userdata('previousTypeOrder',$this->input->post('previousTypeOrder',TRUE));
            $this->session->set_userdata('sessionStamp',$this->input->post('sessionStamp',TRUE));
            $this->session->set_userdata('showAll',$this->input->post('showAll',TRUE));
        }
        
        // The following if statements make sure that the correct list of students is retrieved in order to save marking setups.
        if ($this->input->post('previousTypeOrder')=='alpha' || $this->input->post('previousTypeOrder')=='' ) $this->students = $this->students_model->getAllStudentsAlphaOrder($this->input->post('sessionStamp'));
        if ($this->input->post('previousTypeOrder')=='supervisor') $this->students = $this->students_model->getAllStudentsSupervisorOrder($this->input->post('sessionStamp'));        
        if ($this->input->post('previousTypeOrder')=='secondmarker') $this->students = $this->students_model->getAllStudentsSecondMarkerOrder($this->input->post('sessionStamp'));        
        if ($this->input->post('previousTypeOrder')=='project') $this->students = $this->students_model->getAllStudentsProjectOrder($this->input->post('sessionStamp'));
        if ($this->input->post('previousTypeOrder')=='uid') $this->students = $this->students_model->getAllStudentsUidOrder($this->input->post('sessionStamp'));        
        // Will check to see that a csv is not required.
        if (!$producePrefCSV && !$produceSupCSV)
        {
            // This will save marking setups to xml file if either supervisor or second marker has been set. It will save all information to a marking setup file independent of markers set.
            $this->markingsetup_model->saveMarkingSetup($this->input->post('markerSelected'),$this->input->post('projectChoice'),$this->input->post('secondMarkerSelected'),$this->input->post('ownProject'),$this->students,$this->markers,$this->projects,$this->input->post('hideStudent'));
	    
	     // This will save own project setups to xml file when supervisor has been set.  
$this->ownproject_model->saveOwnProjectSetup($this->input->post('markerSelected'),$this->input->post('projectChoice'),$this->input->post('ownProject'),$this->students);
            // This will create a new ordered list if a new ordering of students is required.
            $this->students_model->sortListByMarkerProject($this->input->post('typeOrder'),$this->load->database('default', TRUE),$this->input->post('sessionStamp'));
        
            // This will save all the marking maximum totals for a staff.
            $this->markersmax_model->saveMarkingMax($this->markers,$this->input->post('supT'),$this->input->post('smT'));
        }
        
        // The following 2 lines will produce a csv for students or supervisors.
        if ($producePrefCSV) $this->studentPreferencesCSV();
        if ($produceSupCSV) $this->supervisorProjectsCSV();
    
        // This will email allocations when required.
        if ($this->input->post('emailAllocations')=="Email All Allocations") $this->emailMarkingSetup("all");
        if ($this->input->post('emailAllocations')=="Email Displayed Allocations") $this->emailMarkingSetup("none hidden");
	if ($this->input->post('emailMissingPreferences')=="Email Students who have missing Preferences") $this->emailMissingPreferences();
    	
        // This will redirect to load the main marking setup page when a csv is not required.
        if (!$producePrefCSV && !$produceSupCSV && $this->input->post('emailMissingPreferences')!="Email Students who have missing Preferences")
		redirect('/staff/markingSetup/markingSetupPage', 'refresh');
        
    
    }
    function studentPreferencesCSV()
    {
            // This function creates a csv file containing student preferences.
            
            // Creates a xml variable that will contain the full list of preferences in the format needed for csv file.
            $studentPrefs=$this->studentpreferences_model->createListOfStudentChoices($this->students,$this->projects);
        
            // Sends header information to create csv file.
            $this->load->view('staff/markingSetup/headerPreferencesCSV');
        
            // Goes through all student preferences.
            foreach($studentPrefs as $stprefTag)
            {
                $student=$stprefTag->getAttribute('student');
                
                $prefTag=$stprefTag->getElementsByTagName('pref');
                $pref1="";
                $pref2="";
                $pref3="";
                $pref4="";
                
                // Goes through all the ranked preferences and gets the title of the project;
                foreach($prefTag as $ptag) 
                {
                    $rank=$ptag->getAttribute('rank');
                    if ($rank==1) $pref1=$ptag->getAttribute('projectTitle');
                    if ($rank==2) $pref2=$ptag->getAttribute('projectTitle');
                    if ($rank==3) $pref3=$ptag->getAttribute('projectTitle');
                    if ($rank==4) $pref4=$ptag->getAttribute('projectTitle');
                }  
                 
                // Outputs a student row in the csv file with each of the 4 preferences.
                echo "$student,$pref1,$pref2,$pref3,$pref4\n";
            }      
    }
    function supervisorProjectsCSV()
    {
            // This function creates a csv file containing supervisor created proposals.
            
            // Sends header information to create csv file.
            $this->load->view('staff/markingSetup/headerSupervisorsCSV');
            
            // Goes through all the markers.
            if ($this->markers_model->checkIfMarkersFileExists()) foreach($this->markers as $mks) 
            {
                $uid=$mks->getAttribute('uid');  
                $projectTitle="";
                if ($this->proposals_model->checkIfProposalsFileExists()) foreach($this->projects as $prj)
                {
                        if ($this->proposals_model->checkIfSupervisorProject($prj->getElementsByTagName('supervisor'),$uid)) 
                        {
                            // Retrieves information about supervisors held with the supervisor node for xml proposals.
                            $supidsText=$this->proposals_model->getSupervisorList($prj->getElementsByTagName('supervisor'));                        
                            $projectTitle.=",";  
                            
                            // Sets the title of the project to that which is contained within the xml proposals element.
                            $projectTitle.=$this->proposals_model->getProjectTitle($prj->getElementsByTagName('title'));              
                            $projectTitle.="$supidsText";
                
                        }

                }

		if ($this->ownproject_model->checkIfOwnProjectSetupFileExists()) 
		{

			// Retrieves all own projects for marker.
			$ownprojects=$this->ownproject_model->getSavedOwnProjectSetupForMarker($uid);
			
			// Goes through all own projects for marker.
			foreach($ownprojects as $op) 
			{ 
				$projectTitle.=",";  

				$projectTitle.=$op->getAttribute('projectTitle');
				$ownProjectStudent=$op->getAttribute('student');

                        	// Goes through all the students.
                        	foreach($this->students as $stTag)
                        	{           

                        	   $stuid=$stTag->getAttribute('uid');

                        	   // Checks to see if the student id matches the one for own project setup of the marker.
                        	    if ($stuid==$ownProjectStudent)
                        	    {
                                	$surname=$stTag->getAttribute('surname');
                                	$forenames=$stTag->getAttribute('forenames');
                                	$candidate_number=$stTag->getAttribute('candidate_number');
                                	$degreecode=$stTag->getAttribute('degreecode');

                                	// Sets the project for supervisor to be displayed in the csv.
                                	$projectTitle.=" (Own Project: $forenames $surname ($candidate_number $degreecode)) ($uid)";
                        	    }
                        	} 					
			}
		}		  
                // Outputs the user id of the supervisor and a list of projects each has proposed.
                echo "$uid$projectTitle\n";            
            }
    }
    
    
    function emailMarkersSetup($emailCohort)
    {
                // This function will email markers their allocations. 
		// The list of allocations is dependent on whether all students with allocated supervisor and second marker are required
                // or just those that are displayed.
		
		// Goes through all the markers.    
                if ($this->markers_model->checkIfMarkersFileExists()) foreach($this->markers as $mkTag)
                {
                    $uidMarker=$mkTag->getAttribute('uid');
                    $firstnameMarker=$mkTag->getAttribute('firstname');
                    $surnameMarker=$mkTag->getAttribute('surname');
                    $markertitle=$mkTag->getAttribute('title');
                    $emailMessage="$markertitle $firstnameMarker $surnameMarker ($uidMarker:) project allocations:\n";  
                    $projCnt=0;
                    $markerCnt=1;
                    while($markerCnt<3)
                    {

                        // Goes through saved marking setups for the student.
                        if ($this->markingsetup_model->checkIfMarkingSetupFileExists()) foreach ($this->markings as $mks)
                        {
                            $studentChoice=$mks->getAttribute('student');
                            $supervisorChoice=$mks->getAttribute('supervisor');
                            $secondMarkerChoice=$mks->getAttribute('secondmarker');
                            $projectChoice=$mks->getAttribute('project');
                            
                            
                            if ($markerCnt==1) {$markerID=$supervisorChoice;$markerType="supervisor";} 
                            else {$markerID=$secondMarkerChoice;$markerType="second marker";} 
                            
                            // Checks to see if the marking setup is hidden or all students should be emailed and whether the marking setup is assigned to the marker.
                            if ((!$studentChoice==$mks->getAttribute('hide') || $emailCohort=="all")  && $markerID==$uidMarker)
                            {
                                	// Goes through all the students.
                                	foreach($this->students as $stTag)
                                	{           

                                	   $stuid=$stTag->getAttribute('uid');

                                	   // Checks to see if the student id matches the one for marking setup of the marker.
                                	    if ($stuid==$studentChoice)
                                	    {
                                        	$surname=$stTag->getAttribute('surname');
                                        	$forenames=$stTag->getAttribute('forenames');
                                        	$candidate_number=$stTag->getAttribute('candidate_number');
                                        	$degreecode=$stTag->getAttribute('degreecode');

                                        	// Sets the student name to be displayed in the email.
                                        	$studentName="$surname, $forenames ($candidate_number $degreecode)";
                                	    }
                                	} 

                                	if ($this->proposals_model->checkIfProposalsFileExists() && $projectChoice!="own project") 
						foreach($this->projects as $prj)
                                		{
                                		    $projid=$prj->getAttribute('label');

                                		    // Checks to see if the project id matches the preference chosen by the student.
                                		    if ($projid==$projectChoice) 
                                		    {

                                        		// Sets the title of the project to that which is contained within the xml proposals element.
                                        		$projTitle=$this->proposals_model->getProjectTitle($prj->getElementsByTagName('title')); 
                                        		if ($supervisorChoice!="" && $supervisorChoice!="Select Choice"
                                        		&& $secondMarkerChoice!="Select Choice" && $secondMarkerChoice!="") 
                                        		{
                                        		    $emailMessage.="$studentName $projTitle ($markerType)\n";      
                                        		    $projCnt++;
                                        		}

                                		    } 
                                		 }
						 
					 // This will check if the marker project is a student own project.
					 if ($this->ownproject_model->checkIfOwnProjectSetupFileExists() && $projectChoice=="own project") 
					 {
						// This will retrieve details of the student own project.
						$ownprojects=$this->ownproject_model->getSavedOwnProjectSetup($studentChoice);
						
						// This goes through all own projects for student. In this case it is only one.
						foreach($ownprojects as $op) 
						{ 
							$projTitle=$op->getAttribute('projectTitle');
							$emailMessage.="Own Project: $studentName $projTitle ($markerType)\n";
							$projCnt++;
						}
					 }				 
                     
                                }   
                                     
                  
                           }  
               $markerCnt++;
                }   
                // Checks to see if projects have been found for marker.
                if ($projCnt>0) 
                {
                
                    // Emails the marker details of marking allocations.
                    $this->email->from('bmh2@le.ac.uk', 'Ben Hirst');
                    $this->email->to('bmh2@le.ac.uk');
                    $this->email->subject($this->modcode.' Staff Project Allocations');
                    $this->email->message($emailMessage);
                    $this->email->logandsend('./../application/log/emaillog.log');
                }
                      
            }  
    }    
    
    function emailStudentsSetup($emailCohort)
    {
            // This function will email students their supervisor, second marker and project title.
            
	    $cntStudents=1;
	    
            // Goes through all the students.
            foreach($this->students as $stTag)
            {
                $stuid=$stTag->getAttribute('uid');
                $surname=$stTag->getAttribute('surname');
                $forenames=$stTag->getAttribute('forenames');
                $candidate_number=$stTag->getAttribute('candidate_number');
                $degreecode=$stTag->getAttribute('degreecode');         
                $emailMessage="$forenames $surname ($candidate_number $degreecode) your project allocation is: \n";
		$emailStudents[$cntStudents]="";
		

                // Retrieves the saved marking setup for the particular student.
                if ($this->markingsetup_model->checkIfMarkingSetupFileExists()) $studentMarkings=$this->markingsetup_model->getSavedMarkingSetup($stuid);
                else $studentMarkings="";

                // Goes through saved marking setup for the student.
                if ($this->markingsetup_model->checkIfMarkingSetupFileExists()) foreach ($studentMarkings as $mks)
                {
                    $supervisorChoice=$mks->getAttribute('supervisor');
                    $secondMarkerChoice=$mks->getAttribute('secondmarker');
                    $projectChoice=$mks->getAttribute('project');
                    $hideChoice=$mks->getAttribute('hide');

                }
                $markerText="\n";
                
                // Checks to see if the student is not hidden or all students are to be emailed.
                if (!$stuid==$hideChoice || $emailCohort=="all")
                {
                	    // Goes through all the markers.
                	    if ($this->markers_model->checkIfMarkersFileExists()) foreach($this->markers as $mkTag)
                	    {
                        	$uid=$mkTag->getAttribute('uid');

                        	// Checks to see if the marker matches that which is found in the setup for second marker or supervisor.
                        	if ($supervisorChoice==$uid || $secondMarkerChoice==$uid)
                        	{
                        	    $firstname=$mkTag->getAttribute('firstname');
                        	    $surname=$mkTag->getAttribute('surname');
                        	    $title=$mkTag->getAttribute('title');
                        	    if ($supervisorChoice==$uid) $markerLabel=" (supervisor)";
                        	    else $markerLabel=" (second marker)";

                        	    // Sets the marker details to be displayed in email to student.
                        	    $markerText.="$title $firstname $surname $markerLabel\n";
                        	}

                	    }
			    
			    // This checks if the student has given an own project.  
			    if ($projectChoice=="own project")
			    {

				// Retrieves own project details for student.
		    		$ownprojects=$this->ownproject_model->getSavedOwnProjectSetup($stuid);
				
				// Goes through own project details for student and gets the title.
				foreach($ownprojects as $op) $projTitle="Own Project: ".$op->getAttribute('projectTitle');
				// Checks to see that all the information about the marking setup for the student has been set.
		                if ($supervisorChoice!="" && $supervisorChoice!="Select Choice"
                        	   && $secondMarkerChoice!="Select Choice" && $secondMarkerChoice!="") 
                        	{		
					// Emails the student own project details.
	                        	$emailMessage.="$projTitle $markerText\n";      
        	                	$this->email->from('bmh2@le.ac.uk', 'Ben Hirst');
                	        	$this->email->to('bmh2@le.ac.uk');
                        		$this->email->subject($this->modcode.' Student Project Allocations');
                        		$this->email->message($emailMessage);
	                        	$this->email->logandsend('./../application/log/emaillog.log');
					$emailStudents[$cntStudents]="emailed";			
				}
			    }

                	    // Goes through all project proposals.     
                	    if ($this->proposals_model->checkIfProposalsFileExists() && $projectChoice!="own project" && $projectChoice!="Select Choice")
		    		    foreach($this->projects as $prj)
                		    {
                        		$projid=$prj->getAttribute('label');

                        		// Checks to see if the project id matches the preference chosen by the student.
                        		if ($projid==$projectChoice) 
                        		{

                        		    // Sets the title of the project to that which is contained within the xml proposals element.
                        		     $projTitle=$this->proposals_model->getProjectTitle($prj->getElementsByTagName('title')); 

                        		    // Checks to see that all the information about the marking setup for the student has been set.
                        		    if ($supervisorChoice!="" && $supervisorChoice!="Select Choice"
                        		    && $secondMarkerChoice!="Select Choice" && $secondMarkerChoice!="") 
                        		    {
                                		// Emails the student their supervisor, second marker and project title.
                                		$emailMessage.="$projTitle $markerText\n";      
                                		$this->email->from('bmh2@le.ac.uk', 'Ben Hirst');
                                		$this->email->to('bmh2@le.ac.uk');
                                		$this->email->subject($this->modcode.' Student Project Allocations');
                                		$this->email->message($emailMessage);
                                		$this->email->logandsend('./../application/log/emaillog.log');   
						$emailStudents[$cntStudents]="emailed";	               
                        		    }

                        		 } 
                		    }   

                	   }
		$cntStudents++;
            	}    
		$this->emailed_model->saveEmailedAllocations($emailStudents,$this->students);
    	
    }
    
    
    
    function emailMarkingSetup($emailCohort)
    {
                // This function will email both markers and students.
                $this->load->library('email');
                
                // Retrieves all the marking setups for the module.
                if ($this->markingsetup_model->checkIfMarkingSetupFileExists()) $this->markings=$this->markingsetup_model->getAllSavedMarkingSetup();              
                else $this->markings="";
                
                // Emails both markers and students.
                $this->emailMarkersSetup($emailCohort);
                $this->emailStudentsSetup($emailCohort);
                
    }
    
}






?>
