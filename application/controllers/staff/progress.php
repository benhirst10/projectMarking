<?php

// Title: Progress Monitoring controller for marking system
// Author: B. M. Hirst
// Year: 2011

class progress extends Controller {

    var $projects;  
    var $markers;
    var $versionInfo;
    var $students;
    var $markings;
    var $modcode;
    var $proposals_link;
    var $svn_repos;
    var $assessments;
    var $weightings;
    var $assessment;
    var $studentId;
    var $adminUser;

    function progress()
    {
        // This function initialises all associated models and sets up a session to retain session data.
        
        parent::Controller();
		error_reporting(E_ALL);
		ini_set('display_errors', '1');
        $this->load->model('markingsetup_model');
        $this->load->model('students_model');
        $this->load->model('markers_model');
        $this->load->model('proposals_model');
        $this->load->model('studentpreferences_model');
        $this->load->model('version_model');
        $this->load->model('ownproject_model');
        $this->load->model('markingscheme_model');
        $this->load->model('progress_model');
        $this->load->model('convenors_model');
    
        $adminUser="bmh2";
    
        $this->adminUser=$this->convenors_model->checkIfAdministrator($adminUser);
    
        $this->load->library('session');
    
        // Loads projects from xml file to be used in project choices menu.     
        if ($this->proposals_model->checkIfProposalsFileExists()) $this->projects = $this->proposals_model->getAllProjectChoices(); else $this->projects="";
    
        // Loads markers from xml file to be used in markers menu and allocations information.
        if ($this->markers_model->checkIfMarkersFileExists()) $this->markers = $this->markers_model->getMarkers(); else $this->markers="";

        // Gets the modcode from the marking scheme xml file;
        $this->modcode=$this->markingscheme_model->getMarkingSchemeModcode();
    
        // Gets a list of students from the model ordered alphabetically.
        if ($this->students_model->checkIfStudentsFileExists()) $this->students=$this->students_model->getAllStudentsAlphaOrder('');
        else die("<h1>No common/generated/xml/studentlist.xml file exists</h1>");
    
        // Loads information about links to proposals and svn.
        $this->versionInfo=$this->version_model->getVersionInfo();
        
        foreach ($this->versionInfo as $version) 
        {
            $this->proposals_link=$version->getAttribute('proposals_link');
            $this->svn_repos=$version->getAttribute('repository');
            $this->excel_gen_link=$version->getAttribute('excel_gen_link');
        }
    
        $this->assessments=$this->markingscheme_model->getAssessments();
    
        // Made sure get variables are allowed
        parse_str($_SERVER['QUERY_STRING'], $_GET);
    
    }
    
  
    
    function markerMenus()
    {
    
        // This function displays both selection boxes to do with markers for the module.
        $staff="bmh2";
        $data['domMarkersXML']=$this->markers_model->getDomMarkersXML();
        $data['secondMarkerSelected']=$this->session->userdata('secondMarkerSelected');
        $data['markerSelected']=$this->session->userdata('markerSelected');
        // This will set the transform which is applied to be applied markers list.
        $this->markers_model->setMarkersSelectionBoxXSL();
        
        // This will determine the list of supervisor markers that will be shown in the selection box.
        $data['xsltMarkersSelectionBoxSupProc']=$this->markers_model->setTransformForSupervisorSelectionBox($data['markerSelected'],$this->session->userdata('showAllStudents'));
        
        // This will determine the list of second markers that will be shown in the selection box.
        $data['xsltMarkersSelectionBoxSndMarkerProc']=$this->markers_model->setTransformForSndMarkerSelectionBox($data['secondMarkerSelected'],$this->session->userdata('showAllStudents'));
        
        // This will display the marker selection boxes.
        $this->load->view('staff/progressSpreadsheet/markersSelection',$data);   
    
    }
    
    
    function notListedGlobalSpreadsheetItems()
    {
        // This function will filter excluded items.
        $assessmentsQuery=$this->markingscheme_model->getAssessments();
    
    
        foreach ($assessmentsQuery as $ass) 
        {
            $data['assessmentTitle']=$ass->getAttribute('id');
            if ($this->assessment==$data['assessmentTitle'] && !$this->session->userdata('staffReport'))
                    $data['highlightClass']="heading3";
            else $data['highlightClass']='heading4';
                
            if ($ass->hasAttribute('excludeFromSpread'))
            {
            
                    $data['mark']=$this->progress_model->getAssessmentMarksForStudent($this->studentId,$ass->getAttribute('id'));
                    // Display a non linked assessment title when assessment selected otherwise display a link to an assessment.
                    if ($this->assessment==$data['assessmentTitle'])
                        $this->load->view('staff/progressSpreadsheet/notListedGlobalSpreadsheetItems',$data); // This displays a none include global spreadsheet as just text.
                else $this->load->view('staff/progressSpreadsheet/notListedGlobalSpreadsheetItemsLink',$data);  // This displays a included global spreadsheet as a link.    
            }
        }
    
    }
    
    
    
    function spreadsheet()
    {
        // This function will give a spreadsheet that shows marks in a row for the module and gives the total contribution to overall percentage.
        if (!$this->session->userdata('staffReport') && !$this->session->userdata('studentReport') && $this->adminUser)
            $this->load->view('staff/progressSpreadsheet/setupLinks'); // This will add links to setup different list of markers.
        if (empty($this->studentId)) $this->markerMenus();
        else $this->load->view('staff/progressSpreadsheet/noMarkersSelection');   
        $this->load->view('staff/progressSpreadsheet/tableTop'); // This will setup the formatting of the table that contains the students marks.
        $this->spreadsheetHeadings();
        $this->spreadsheetStudentRow();
        // Loop through items that are not to be shown within the spreadsheet.
        if (!$this->session->userdata('studentReport') && !$this->session->userdata('staffReport') && !empty($this->studentId))
            $this->notListedGlobalSpreadsheetItems();   
    
    }
    
    
    
    function spreadsheetAssessmentHeadings()
    {
        // This function gives the each of the summative assessment titles for the module.
        $counter=1; 
        if (!$this->session->userdata('studentReport')) foreach($this->assessments as $spreadsheetTag)
        {
            $data['assessmentTitle']=$spreadsheetTag->getAttribute('id'); 
        
                if ($spreadsheetTag->hasAttribute('id') && !$spreadsheetTag->hasAttribute('excludeFromSpread'))
                {
                    if ($counter==1 && empty($this->assessment)) $this->assessment=$spreadsheetTag->getAttribute('id');
                    if ($this->assessment==$data['assessmentTitle'] && !$this->session->userdata('staffReport'))
                        $data['highlightClass']="heading3";
                    else $data['highlightClass']='heading4';

                    if (!empty($this->studentId) && $this->assessment!=$data['assessmentTitle']) 
                    {
                    if (!$this->session->userdata('staffReport')) 
                            $this->load->view('staff/progressSpreadsheet/notChosenAssessmentColTitle',$data);       // This will display the assessment title as a linked item.
                    else $this->load->view('staff/progressSpreadsheet/notChosenAssessmentColTitleReport',$data);    // This will display the assessment title as a none linked item.
                    } else
           
                    if (!$spreadsheetTag->hasAttribute('excludeFromSpread')) 
                    {
                        // This will display the title of the assessment chosen.
                        $this->load->view('staff/progressSpreadsheet/spreadsheetAssessmentColTitle',$data); // This will display the main spreadsheet title.
                    }
                    $counter++;
            }

        }   
    
    }
    function spreadsheetAssessmentWeightingHeadings()
    {
        // This function gives the weighting for each assessment.
    
        $this->load->view('staff/progressSpreadsheet/secondRowStartTitles');    //This will display the start of the second row in the spreadsheet table.
        $assCnt=1;
        if (!$this->session->userdata('studentReport')) foreach($this->assessments as $spreadsheetTag)
        {
            if (!$spreadsheetTag->hasAttribute('excludeFromSpread'))
            {
                if ($this->assessment!=$spreadsheetTag->getAttribute('id') || $this->session->userdata('staffReport'))
                    $data['highlightClass']="heading5";
                else $data['highlightClass']="heading3";    
                   // This will display the weighting of a non chosen assessment. 
                $this->weightings[$assCnt]=$spreadsheetTag->getAttribute('weighting');
                $data['weighting']=$spreadsheetTag->getAttribute('weighting');
                $this->load->view('staff/progressSpreadsheet/weightingColTitle',$data); 
                $assCnt++;   
            }   
        }
        if ($this->session->userdata('staffReport'))
            $this->load->view('staff/progressSpreadsheet/secondRowEndTitleTotals'); // This ends the weighting headings row.   
    }
    
    
    
    function spreadsheetHeadings()
    {
        // This function gives the spreadsheet headings.
    
        $data['markerSelected']=$this->session->userdata('markerSelected');
        $data['secondMarkerSelected']=$this->session->userdata('secondMarkerSelected');
        $data['sortSpread']=$this->session->userdata('sortSpread');
        $data['uid']=$this->studentId;
        $data['assessment']=$this->assessment;
        $data['excel_gen_link']=$this->excel_gen_link;
        
        // When there is no student or marker selected links are not given to reports. 
        if (empty($this->studentId) && ($data['markerSelected']=="Select Choice"
        || empty($data['markerSelected'])) && ($data['secondMarkerSelected']=="Select Choice" 
        || empty($data['secondMarkerSelected'])))
          $this->load->view('staff/progressSpreadsheet/noMarkerLinks'); // This will display items in the first cell of the first row of the table. 
        else 
        {
    
            if (!empty($this->studentId) && !$this->session->userdata('staffReport') && !$this->session->userdata('studentReport')) 
                    $this->load->view('staff/progressSpreadsheet/markerEditLinks',$data);  // This will give links to reports when in student editing of feedback.
            else if (!$this->session->userdata('staffReport')  && !$this->session->userdata('studentReport'))
                    $this->load->view('staff/progressSpreadsheet/showAllStudentsLink',$data); // This will give links when no student has been selected.
            if ($this->session->userdata('staffReport'))  $this->load->view('staff/progressSpreadsheet/noMarkerEditLinks'); // This will give an empty cell when a staff report is shown.
        }
        
        $this->spreadsheetAssessmentHeadings();
        $this->spreadsheetAssessmentWeightingHeadings();

        // When no report has been chosen it will display availability tick boxes.
        if (!$this->session->userdata('staffReport') && !$this->session->userdata('studentReport'))
        {
            $this->load->view('staff/progressSpreadsheet/secondRowEndTitle');   // This will end the second row containing the weightings.
            $this->load->view('staff/progressSpreadsheet/availabilityRowStart'); // This will start the availability row.
            if (empty($this->studentId) && $this->adminUser)
                $this->load->view('staff/progressSpreadsheet/availabilityRowStartConvenor'); // This will add links that are specific to a convenor.
            if (!empty($this->studentId) && !$this->session->userdata('staffReport') && !$this->session->userdata('studentReport'))
                $this->load->view('staff/progressSpreadsheet/availabilityRowReportLinks',$data); // This adds links to reports for both staff and students of feedback.
            $this->load->view('staff/progressSpreadsheet/availabilityReportConvenorLinksEnd'); // This ends the cell that contains the links to reports and convenor links.
            foreach($this->assessments as $spreadsheetTag)
            {
            
                    if ($this->assessment!=$spreadsheetTag->getAttribute('id') || $this->session->userdata('staffReport') 
                    || $this->session->userdata('studentReport'))
                        $data['highlightClass']="heading5";
                    else  if (!$spreadsheetTag->hasAttribute('excludeFromSpread')) $data['highlightClass']="heading3";  
                    if ($this->progress_model->checkIfReleasedFeedback($spreadsheetTag->getAttribute('id'))) // This will see if the feedback has been released for the assessment to students.
                        $data['checked']="checked"; else $data['checked']="";
                    $data['readonly']="";               
                    if (!empty($this->studentId))
                    {
                        if ($this->progress_model->checkIfAssessmentNotAvailable($this->studentId,$spreadsheetTag->getAttribute('id')))
                             $data['checked']="checked"; else $data['checked']=""; // This will see if a students assessment has been made not available.
                    }
                    $data['assid']=$spreadsheetTag->getAttribute('id');
                    if (!$spreadsheetTag->hasAttribute('excludeFromSpread'))
                        $this->load->view('staff/progressSpreadsheet/availabilityRowCol',$data); // This will display the tick box for chosing availability.
    
            }
            // temporary setting of form values.
            $data['uid']="";
            $data['markerSelected']=$this->session->userdata('markerSelected'); 
            $data['secondMarkerSelected']=$this->session->userdata('secondMarkerSelected');
            $data['assessment']=$this->assessment;
            if (empty($this->studentId)) $this->load->view('staff/progressSpreadsheet/availabilityRowSpreadsheetEnd',$data); // This will display the out of and total titles with links to sorting of spreadsheet requirements.
            else $this->load->view('staff/progressSpreadsheet/availabilityRowSpreadsheetEndEdit',$data); // This will display out of and total titles.
        }
    
        
    }
    
    
    function spreadsheetStudentRow()
    {
        // This function will give each row of marks for students in the spreadsheet.
    
        $projectChoice="";
        $supervisorChoice="";
        $secondMarkerChoice="";                 
        $data['modcode']=$this->modcode;
        $data['secondMarkerSelected']=$this->session->userdata('secondMarkerSelected');
        $data['markerSelected']=$this->session->userdata('markerSelected'); 
        $data['sortSpread']=$this->session->userdata('sortSpread');
    
        if (empty($data['secondMarkerSelected']) && empty($data['markerSelected'])) $showAllStudents="yes";
        else $showAllStudents=$this->session->userdata('showAllStudents'); 
    
        if ($data['secondMarkerSelected']=="Select Choice" && $data['markerSelected']=="Select Choice") $showAllStudents="yes";
        else if (empty($showAllStudents)) $showAllStudents=$this->session->userdata('showAllStudents');
            
        if ($data['secondMarkerSelected']=="Select Choice")  $data['secondMarkerSelected']="";
        if ($data['markerSelected']=="Select Choice") $data['markerSelected']="";
    
        // create a students list using dom import node and sorted file.
    
        // Goes through all the students.
        foreach($this->students as $stTag)
        {
                $data['stuid']=$stTag->getAttribute('uid');
                $stuid=$stTag->getAttribute('uid');
                $data['surname']=$stTag->getAttribute('surname');
                $data['forenames']=$stTag->getAttribute('forenames');
                $data['candidate_number']=$stTag->getAttribute('candidate_number');
                $data['degreecode']=$stTag->getAttribute('degreecode');
                if ($this->markingsetup_model->checkIfMarkingSetupFileExists()) 
                {
                    // Retrieves the saved marking setup for the particular student.
                    $studentMarkings=$this->markingsetup_model->getSavedMarkingSetup($data['stuid']);
                    $supervisorChoice="";
                    $secondMarkerChoice="";
                    $projectChoice="";
                    // Goes through saved markings for the student.
                    foreach ($studentMarkings as $mks)
                    {
                        $supervisorChoice=$mks->getAttribute('supervisor');
                        $secondMarkerChoice=$mks->getAttribute('secondmarker');
                        $projectChoice=$mks->getAttribute('project');
                    }
            
                }       
                if ((($data['secondMarkerSelected']==$secondMarkerChoice || $data['markerSelected']==$supervisorChoice 
                || $showAllStudents=="yes") && empty($this->studentId)) || $this->studentId==$data['stuid'])
                {
                
                    $data['svn_repos']=$this->svn_repos;
                    $data['uid']=$this->studentId;
                    if (empty($this->studentId)) $this->load->view('staff/progressSpreadsheet/studentDetailsSpreadsheet',$data); // Gives link to editing of students as a student name.
                    else 
                    {
                        if (!$this->session->userdata('staffReport') && !$this->session->userdata('studentReport'))
                                $this->load->view('staff/progressSpreadsheet/studentDetailsEdit',$data); // This will give the student name as a link to a svn repository.
                        if ($this->session->userdata('staffReport') || $this->session->userdata('studentReport')) 
                                $this->load->view('staff/progressSpreadsheet/studentDetailsReport',$data); // This will give a none linked student name.
                    }
            
                    $data['finalMark']=0;
                    $data['outOfs']=0;
                    $data['supervisorName']=$this->markers_model->getMarkerName($supervisorChoice);
                    $data['sndMarkerName']=$this->markers_model->getMarkerName($secondMarkerChoice);
                    $data['projectTitle']=$this->proposals_model->getProjectTitleByLabel($projectChoice);
                    $data['proposals_link']=$this->proposals_link;
                    $data['projectLabel']=$projectChoice;
                    if ($this->ownproject_model->checkIfOwnProjectSetupFileExists() && $projectChoice=="own project") 
                    {
                            // Retrieves the saved own project setup for the particular student.
                            $studentOwnProject=$this->ownproject_model->getSavedOwnProjectSetup($data['stuid']);

                            // Goes through saved own projects for the student.
                            foreach ($studentOwnProject as $op) $data['projectTitle']=$op->getAttribute('projectTitle');
                    }
                    if (!$this->session->userdata('staffReport') && !$this->session->userdata('studentReport'))
                        $this->load->view('staff/progressSpreadsheet/studentDetailsMarkersProject',$data); // This will give details of supervisor and second marker with a link to project proposal.
                    else  $this->load->view('staff/progressSpreadsheet/studentDetailsMarkersProjectReport',$data); // This will give details of supervisor, second marker and proejct title.
                    $assCnt=1;      
                    if (!$this->session->userdata('studentReport')) foreach($this->assessments as $spreadsheetTag)  
                    {
                         if ($this->assessment!=$spreadsheetTag->getAttribute('id') || $this->session->userdata('staffReport') || 
                        $this->session->userdata('studentReport'))
                        $data['highlightClass']="boxes";
                        else if (!$spreadsheetTag->hasAttribute('excludeFromSpread')) $data['highlightClass']="heading3";       
                        if ($spreadsheetTag->hasAttribute('id'))
                        {
                            $assessmentid=$spreadsheetTag->getAttribute('id');
                            $data['mark']=$this->progress_model->getAssessmentMarksForStudent($data['stuid'],$assessmentid);

                            if (is_numeric($data['mark']) && !empty($this->weightings[$assCnt])) 
                            {
                                    $data['outOfs']+=$this->weightings[$assCnt];
                                    $data['finalMark']+=($data['mark']/100)*$this->weightings[$assCnt];
                                    $data['mark']=round($data['mark'],2);
                            }
                            $displayedMark=false;
                            if (!$spreadsheetTag->hasAttribute('excludeFromSpread') && (!empty($this->weightings[$assCnt]) || is_numeric($data['mark'])))
                            {
                                    if (!$this->session->userdata('studentReport'))
                                            $this->load->view('staff/progressSpreadsheet/markAssessmentCell',$data); // This displays the mark of the student.
                                    else $this->load->view('staff/progressSpreadsheet/markAssessmentCellStudentReport',$data); // This displays an empty cell for the student report.
                                    $displayedMark=true;
                            }
                            if (!$spreadsheetTag->hasAttribute('excludeFromSpread') && empty($this->weightings[$assCnt]) && !$displayedMark)
                            {
                                $data['choice']=$this->progress_model->getAssessmentChoiceForStudent($stuid,$assessmentid);
                                $this->load->view('staff/progressSpreadsheet/markAssessmentCellChoice',$data);
                            }
                            
                            
                        }
                        $assCnt++;
                    }
                    if ($data['outOfs']>0)  $data['finalMark']=$data['finalMark']/$data['outOfs']*100;
                    if (!$this->session->userdata('studentReport'))
                        $this->load->view('staff/progressSpreadsheet/markAssessmentTotal',$data); // This gives the mark total.
                    if (!$this->session->userdata('studentReport') && !$this->studentId) $this->progress_model->saveFinalMark($data['finalMark'],$stuid);  
                    
            }
            
        }    
        
    
    }

    
    function feedbackDataEntry($type,$assessmentDisp,$stcnt)
    {
    
        // This function displays data for entry in forms that allow data entry and viewing in report format.
        
        if ($stcnt==1) $this->load->view('staff/progressSpreadsheet/feedbackEntryTableTop'); // This sets the table formatting for feedback to students.
        if ($type=="entry") $this->load->view('staff/progressSpreadsheet/feedbackDataEntryTotal'); // This gives a save button and show total mark for the assessment.
        $this->progress_model->setComponentValueArrays($assessmentDisp,$this->studentId,$type); // This allocates stored feedback to arrays for easy retreival. 
        $data['markingSchemeXsltProc']=$this->progress_model->setTransformForAssessmentTitle();  // This sets up the assessment title to be displayed.
        $data['domMarkingScheme']=$this->markingscheme_model->getMarkingSchemeDom();            // This retreives the marking scheme document file.
        if ($type!="studentReport" || ($this->progress_model->checkIfReleasedFeedback($assessmentDisp) && 
            $this->progress_model->checkIfAssessmentNotAvailable($this->studentId,$assessmentDisp) && $type=="studentReport")) 
                $this->load->view('staff/progressSpreadsheet/feedbackAssessmentTitle',$data); // This will display the assessment title when made available to students.
        $cnt=0;
        while($cnt++<$this->progress_model->getMaximumComponents())
        {
            $data['markingSchemeXsltProc']=$this->progress_model->setTransformForComponent($cnt); // This will enable assessment elements for transformation into views with component arrays.
            if ($type!="studentReport" || ($this->progress_model->checkIfReleasedFeedback($assessmentDisp) && $this->progress_model->checkIfAssessmentNotAvailable($this->studentId,$assessmentDisp) && $type=="studentReport")) 
                $this->load->view('staff/progressSpreadsheet/feedbackComponentEntry',$data); // This does the actual transformation to produce feedback elements based on stored data
        
        }
        $data['assessmentMark']=$this->progress_model->getAssessmentMarksForStudent($this->studentId,$assessmentDisp);
        if (!empty($data['assessmentMark'])) $data['assessmentMark']=round($data['assessmentMark'],2);
        if ($type=="report") $this->load->view('staff/progressSpreadsheet/staffReportAssessmentTotal',$data); // This will display a total for the assessment if a report is required.
        $data['uid']=$this->studentId;
        $data['markerSelected']=$this->session->userdata('markerSelected'); 
        $data['secondMarkerSelected']=$this->session->userdata('secondMarkerSelected'); 
        $data['sortSpread']=$this->session->userdata('sortSpread');
        if ($type=="entry") $this->load->view('staff/progressSpreadsheet/feedbackEntryTableEnd'); // This displays the end of the feedback table.
        if ($stcnt==1)  $this->load->view('staff/progressSpreadsheet/feedbackEntryHidden',$data); // Hidden items include uid, marker selected and second marker.
    }
    
    
    function saveMarks()
    {
        // This saves marks and release details for a particular student.
    
        if (!empty($this->studentId))
        {
            if ($this->session->userdata('feedback')) $this->progress_model->saveFeedback($this->session->userdata('feedback'),$this->studentId,'feedback'); // Textual feedback are saved for components.
            if ($this->session->userdata('choice')) $this->progress_model->saveFeedback($this->session->userdata('choice'),$this->studentId,'choice'); // Radio choices are saved for components.
            if ($this->session->userdata('mark')) $this->progress_model->saveFeedback($this->session->userdata('mark'),$this->studentId,'mark'); // Saves the numerical marks for components.
            if (($this->session->userdata('totalmark1') && $this->session->userdata('totalmark1')!="NaN") || $this->session->userdata('totalmark1')=="0")
                 $this->progress_model->saveAssessmentTotal($this->session->userdata('totalmark1'),$this->studentId,$this->assessment); // Saves the overall assessment total.
        }
        $this->progress_model->saveReleaseDetails($this->studentId,$this->session->userdata('studentAssessments'),$this->assessments); // Saves marks that need releasing to the student.
    
    }
    
    
    function report($type)
    {
        // This function goes through all assessment items to show in a report format which is printable.
    
        $cnt=0;
        foreach($this->assessments as $reportTag) {$cnt++;$this->feedbackDataEntry($type,$reportTag->getAttribute('id'),$cnt);}
    }
    
    
    function reportAll($type)
    {
        // This function gives a report for all students who are ont the module.
        // Go through all spreadsheets for students.
        foreach($this->students as $stTag)
        {
            $this->studentId=$stTag->getAttribute('uid');
            $data['stuid']=$stTag->getAttribute('uid');
            $assCnt=0;
            $data['finalMark']=0;
            $data['outOfs']=0;
            $data['stuid']=$stTag->getAttribute('uid');
            $data['surname']=$stTag->getAttribute('surname');
            $data['forenames']=$stTag->getAttribute('forenames');
            $data['candidate_number']=$stTag->getAttribute('candidate_number');
            $data['degreecode']=$stTag->getAttribute('degreecode');
            $data['uid']=$this->studentId;
            $data['highlightClass']="";
            $this->load->view('staff/progressSpreadsheet/reportAllSpreadRowStart');  // This opens the table for the report.
            $this->load->view('staff/progressSpreadsheet/studentDetailsReport',$data); // This gives name details of the student.
            foreach($this->assessments as $reportTag) 
            {
                    $assessmentid=$reportTag->getAttribute('id');
                    $data['mark']=$this->progress_model->getAssessmentMarksForStudent($data['stuid'],$assessmentid);
            
                    if (is_numeric($data['mark'])) 
                    {
                        $data['outOfs']+=$reportTag->getAttribute('weighting');
                        $data['finalMark']+=($data['mark']/100)*$reportTag->getAttribute('weighting');
                        $data['mark']=round($data['mark'],2);
                    }
                    
                    if (!$reportTag->hasAttribute('excludeFromSpread') && $reportTag->getAttribute('weighting'))
                    {
                        if (!$this->session->userdata('studentReport')) $this->load->view('staff/progressSpreadsheet/markAssessmentCell',$data);
                        else $this->load->view('staff/progressSpreadsheet/markAssessmentCellStudentReport',$data);
                    }
                    if (!$reportTag->hasAttribute('excludeFromSpread') && !$reportTag->getAttribute('weighting'))
                    {
                                $data['choice']=$this->progress_model->getAssessmentChoiceForStudent($data['stuid'],$assessmentid);
                                $this->load->view('staff/progressSpreadsheet/markAssessmentCellChoice',$data);
                    }                    
                            
    
            }
            if ($data['outOfs']>0)  $data['finalMark']=$data['finalMark']/$data['outOfs']*100;
                $this->load->view('staff/progressSpreadsheet/markAssessmentTotal',$data);   
                
            $this->load->view('staff/progressSpreadsheet/reportAllSpreadRowEnd');
            $cnt=0;
            foreach($this->assessments as $reportTag) 
            {
                $cnt++;
                if ($this->progress_model->getAssessmentMarksForStudent($data['stuid'],$reportTag->getAttribute('id'))>0)
                    $this->feedbackDataEntry($type,$reportTag->getAttribute('id'),$cnt);        
            
            }
        }
    
    }
    
    
    function progresspage()
    {   
    
        $this->load->helper('url');
        $this->load->helper('form');

        // The following statements will set items to be saved in the session that have been passed back to the server from the form.
        $this->session->set_userdata('markerSelected',$this->input->get_post('markerSelected',TRUE));
        $this->session->set_userdata('secondMarkerSelected',$this->input->get_post('secondMarkerSelected',TRUE));
        $this->session->set_userdata('sortSpread',$this->input->get_post('sortSpread',TRUE));
        $this->session->set_userdata('showAllStudents',$this->input->get_post('showAllStudents',TRUE));
        $this->session->set_userdata('feedback',$this->input->post('feedback',TRUE));
        $this->session->set_userdata('choice',$this->input->post('choice',TRUE));
        $this->session->set_userdata('mark',$this->input->post('mark',TRUE));
        $this->session->set_userdata('totalmark1',$this->input->post('totalmarks1',TRUE));
        $this->session->set_userdata('staffReport',$this->input->post('staffReport',TRUE));
        $this->session->set_userdata('studentReport',$this->input->post('studentReport',TRUE));
        $this->session->set_userdata('staffReportAll',$this->input->post('staffReportAll',TRUE));
        $this->session->set_userdata('studentAssessments',$this->input->post('studentAssessments',TRUE));
    
        if (!$this->input->get_post('markerSelected',TRUE) 
        && !$this->input->get_post('secondMarkerSelected',TRUE)
        && !$this->input->get_post('showAllStudents',TRUE)) 
        $this->session->set_userdata('markerSelected',"bmh2");
    
    
        // The following function to be implemented will give a spreadsheet that is dependent on a factor that has been set within the 
        // variable called sortSpread.  
        if ($this->session->userdata('sortSpread'))
            $this->students=$this->progress_model->sortSpreadsheet($this->session->userdata('sortSpread'));

        // This will assign a class variable which denotes the assessment that is connected with the group of students.
        $this->assessment=$this->input->get_post('assessment',TRUE);
    
        // This presents a student value which is attributed to selection within the spreadsheet.
        if (!$this->session->userdata('showAllStudents')) $this->studentId=$this->input->get_post('uid',TRUE);
        if ($this->input->post('saveFeedback',TRUE)) $this->saveMarks();

        // This will obtain the module code of the present system in use.   
        $data['modcode']=$this->modcode;
      //  if (!$this->session->userdata('studentReport') && !$this->session->userdata('staffReport') && !$this->session->userdata('staffReportAll'))
        $this->load->view('staff/progressSpreadsheet/headerProgress',$data);  // This will display the top of web page.
        $this->load->view('staff/progressSpreadsheet/progressSpreadsheetFormPart1'); // This will set up the web page form of input.
        if (!$this->session->userdata('staffReportAll')) $this->spreadsheet();
    
        if (!empty($this->studentId) && !empty($this->assessment) && !$this->input->post('staffReport',TRUE)
         && !$this->input->post('studentReport',TRUE) && !$this->session->userdata('staffReportAll') )
             $this->feedbackDataEntry('entry',$this->assessment,1);
        if ($this->session->userdata('staffReport')) $this->report('report');
        if ($this->session->userdata('studentReport')) $this->report('studentReport');
        if ($this->session->userdata('staffReportAll')) $this->reportAll('report');
    
        $data['assessmentTitle']=$this->assessment;
        $this->load->view('staff/progressSpreadsheet/progressSpreadsheetFormPart2',$data);
    
    }
    
    function svnLinks()
    {
        $this->load->view('staff/progressSpreadsheet/headerProgress',$data);
        $data['svn_repos']=$this->svn_repos;
        $this->load->view('staff/progressSpreadsheet/svnDetailsSVNList');
        foreach ($this->students as $stTag)
        {
                $data['stuid']=$stTag->getAttribute('uid');
                $data['surname']=$stTag->getAttribute('surname');
                $data['forenames']=$stTag->getAttribute('forenames');
                $data['candidate_number']=$stTag->getAttribute('candidate_number');     
                $this->load->view('staff/progressSpreadsheet/svnDetailsEdit',$data);
        }
    
        $this->load->view('staff/progressSpreadsheet/svnDetailsSVNListEnd');
    
    
    }
    
    
    
}






?>
