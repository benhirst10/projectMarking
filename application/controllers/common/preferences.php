<?php

// Title: Progress Monitoring controller for marking system
// Author: B. M. Hirst
// Year: 2011

class preferences extends CI_Controller {


    public function __construct() {
        parent::__construct();
		error_reporting(E_ALL);
		ini_set('display_errors', '1');
        $this->load->model('preferences_model');
    
    
    }
    
  
    
    
    
    function preferencepage()
    {   
    
        $this->load->helper('url');
        $this->load->helper('form');
		$stuid="std1";
		$projectsDegreeRestrictions="./../common/generated/xml/projects.xml";
		$proposalFile="./../common/generated/xml/proposals.xml";
		$markerList="./../common/generated/xml/markers.xml";
		$this->preferences_model->checkFileExists($markerList,"marker list file");
		$studentList="./../common/generated/xml/studentlist.xml";
		$this->preferences_model->checkFileExists($studentList,"student list file");
		$versionFile="./../common/config/xml/version.xml";
		$this->preferences_model->checkFileExists($versionFile,"generated marking scheme file");
		$degreeAbreviationsFile="./../common/xml/degreeAbreviations.xml";		
		$preferencePageSetup="./../common/config/xml/preferencePage.xml";		
        $this->preferences_model->checkFileExists($preferencePageSetup,"preference page setup file");
        $this->preferences_model->checkFileExists($proposalFile,"proposal file"); 
        if (!file_exists($projectsDegreeRestrictions)) $profilesNo=$this->preferences_model->createListOfDegreeProjects();
        else  $profilesNo=$this->preferences_model->degreeRestrictions();
		$data['dateClose']=$this->preferences_model->getDateTimeClose("date"); 
		$data['timeClose']=$this->preferences_model->getDateTimeClose("time");
        $todays_date = date("Y-m-d h:i:s"); 
        $dateA = $data['dateClose']." ".$data['timeClose']; 
        $dateB = $todays_date;

      //  if(strtotime($dateA) > strtotime($dateB))
      //  { 
           $sameChoices=""; 
           if ($this->input->get_post('Save',TRUE)) 
                        $sameChoices==$this->preferences_model->savePreferences($stuid,$this->input->get_post('colfirstchoice',TRUE),$this->input->get_post('colsecondchoice',TRUE),$this->input->get_post('colthirdchoice',TRUE),$this->input->get_post('colfourthchoice',TRUE));
		   $this->load->view('common/preferences/headerPref',$data);
		  $students=$this->preferences_model->getStudent($stuid);
          //     if ($students->length==0) $html.="<h3>You are not registered to use the preference page on this module.</h3>";
          //     if (!$sameChoices) $html.=displayPrefSaved($stuid,$projectPreferencesMdb2,$proposalFile,$markerList,$student_proposals_link);
          //      else 
          //      $html.="<hl> PLEASE NOTE: Unable to save choices as you have chosen too many preferences with an individual supervisor!!!!!! Maximum projects per staff is: ".findLimitChoiceNo($preferencePageSetup).".</h1>";
          //     $cnt=1;
           $degreeAbreviationsXpath=$this->preferences_model->getDegreeAbbreviationsXpath();
		   $proposals=$this->preferences_model->getProposalsXpath();
		   $propRXpath=$this->preferences_model->getDegreeRestrictionsXpath();
             // This will obtain details of the one student.
               foreach($students as $stTag)
               {

                   $data['stuid']=$stTag->getAttribute('uid');
                   $data['surname']=$stTag->getAttribute('surname');
                   $data['forenames']=$stTag->getAttribute('forenames');
                   $data['candidate_number']=$stTag->getAttribute('candidate_number');
                   $data['degreecode']=$stTag->getAttribute('degreecode');
				   $this->load->view('common/preferences/prefStudentName',$data);
                   $data['degreecode']=$this->preferences_model->findDegreeCodeAbreviation($degreeAbreviationsXpath, $data['degreecode']);     
                   // This will find the proposals that are specific to the degreecode.
                   
                   foreach($proposals as $prop)
                   {
                        $data['label']=$prop->getAttribute('label');
						$label=$prop->getAttribute('label');
                       // $hiddenProp=hiddenProject($label,$proposalFile);
                        if ($profilesNo>0)
                        {
                            $proposalsR=$propRXpath->query($queryProjects)->length;
                            if ($degreecode<>"_all_") $query2="//project[@label=\"$label\"]/degree[@id=\"$degreecode\"]";
                            else $query2="//project[@label=\"$label\"]/degree";
                            $proposalsR=$propRXpath->query($query2)->length;
                            if ($proposalsR==0) $label="";
                        }   
                        if (!empty($_POST["colfirstchoice"])) $pref1=$this->input->get_post('colfirstchoice',TRUE); else $pref1="";
                        if (!empty($_POST["colsecondchoice"])) $pref2=$this->input->get_post('colsecondchoice',TRUE); else $pref2="";
                        if (!empty($_POST["colthirdchoice"])) $pref3=$this->input->get_post('colthirdchoice',TRUE); else $pref3="";
                        if (!empty($_POST["colfourthchoice"])) $pref4=$this->input->get_post('colfourthchoice',TRUE); else $pref4="";
                        //if (empty($hiddenProp) && !empty($label))         
                       //     $html.="\n".displayPreferenceChoices($stuid,$label,true,$proposalFile,$markerList,$projectPreferencesMdb2,$student_proposals_link,$colfirstchoice,$colsecondchoice,$colthirdchoice,$colfourthchoice,$sameChoices);
					     $data['title']=$this->preferences_model->getProposalTitle($label);
						 $data['saved']=$this->preferences_model->checkIfPrefSaved($stuid,$label,1);
						 $html="";
						 if (empty($data['saved'])) $data['saved']=$this->preferences_model->checkIfPrefSaved($stuid,$label,2);
						 if (empty($data['saved'])) $data['saved']=$this->preferences_model->checkIfPrefSaved($stuid,$label,3);
						 if (empty($data['saved'])) $data['saved']=$this->preferences_model->checkIfPrefSaved($stuid,$label,4);   
						 
						 if (!empty($data['title']))
						 {
							$this->load->view('common/preferences/projectTitle',$data);
							if ($this->preferences_model->checkIfPrefSaved($stuid,$label,1)!="" && !$sameChoices) $data['checked']="checked"; else $data['checked']="";
							if ($pref1==$label && $sameChoices)  $data['checked']="checked"; else if ($sameChoices) $data['checked']="";
							$this->load->view('common/preferences/pref1',$data);
							if ($this->preferences_model->checkIfPrefSaved($stuid,$label,2)!="" && !$sameChoices) $data['checked']="checked"; else $data['checked']="";
							if ($pref2==$label && $sameChoices)  $data['checked']="checked"; else if ($sameChoices) $data['checked']="";
							$this->load->view('common/preferences/pref2',$data);
							if ($this->preferences_model->checkIfPrefSaved($stuid,$label,3)!="" && !$sameChoices) $data['checked']="checked"; else $data['checked']="";
							if ($pref3==$label && $sameChoices)  $data['checked']="checked"; else if ($sameChoices) $data['checked']="";
							$this->load->view('common/preferences/pref3',$data);
							if ($this->preferences_model->checkIfPrefSaved($stuid,$label,4)!="" && !$sameChoices) $data['checked']="checked"; else $data['checked']="";
							if ($pref4==$label && $sameChoices)  $data['checked']="checked"; else if ($sameChoices)  $data['checked']="";
							$this->load->view('common/preferences/pref4',$data);	
						 } //else if (!$tableFormat) $html.= "$title <br/>"; 
                    }
               }
              // $html.="<tr><td colspan=5 align=center><INPUT type='submit' value='Save' name='Save' size='20'></td></tr></form></tbody></table></body></html>";
			  $this->load->view('common/preferences/footerPref');
     //   } 
		echo "got here";
    
    }
    
    
    
    
}






?>
