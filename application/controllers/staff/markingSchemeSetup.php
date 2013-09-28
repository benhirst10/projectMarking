<?php

// Title: Marking scheme setup controller for marking system
// Author: B. M. Hirst
// Year: 2011

class markingSchemeSetup extends Controller {

    var $projects;  
    var $markers;
    var $versionInfo;
    var $students;
    var $markersMax;
    var $profilesNo;
    var $markings;
    var $assessments;   

    function markingSchemeSetup()
    {
        // This function initialises all associated models and sets up session to retain session data.
        parent::Controller();
        $this->load->model('markingschemesetup_model');
        $this->load->model('version_model');
        $this->load->library('session');
        
        // obtain version number use the same function as in marking setup.
    }
 
    function markingSchemeSetupPage()
    {
    // compare with marking scheme that has not been attributed with sequenced number.
    
        $this->markingschemesetup_model->setMarkingSchemeNew();
	
	
        $changedAssTransfer=false;
        
        if (!$this->checkSchemaFormatting()) print "Invalid markingScheme.xml\n";
        else
        {
                $this->assessments=$this->markingschemesetup_model->getAssessments();
                foreach ($this->assessments as $pa) 
                {   
                    $data['assessment']=$pa->getAttribute('id');
                    $data['weigthingPrevious']=$pa->getAttribute('weighting');
                    if ($this->markingschemesetup_model->compareNewMarkingSchemeAssessmentWeighting($data['assessment'],$data['weigthingPrevious']))
                    $this->load->view('staff/markingSchemeSetup/sameAssessmentWeighting',$data);
                    else
                    {
                        $data['weightingNew']=$this->markingschemesetup_model->getNewMarkingSchemeAssessmentWeighting($data['assessment']);
                        if (!empty($data['weightingNew'])) $this->load->view('staff/markingSchemeSetup/assessmentWeightingNew',$data);
                        else $this->load->view('staff/markingSchemeSetup/assessmentWeightingNotFound',$data);
                        $this->markingschemesetup_model->saveChangesIncurredWithNewMarkingSchemeAssessment($data['assessment'],$data['weigthingPrevious']);
                        $changedAssTransfer=true;
                    }
                
                    foreach ($this->markingschemesetup_model->getAssessmentComponents($data['assessment']) as $pac)
                    {
                         $data['component']=$pa->getAttribute('id');
                         $data['componentWeightingPrevious']=$pa->getAttribute('weighting');
                         if ($this->markingschemesetup_model->compareAssessmentComponentWeighting($data['assessment'], $data['component'],$data['componentWeightingPrevious']))
                            $this->load->view('staff/markingSchemeSetup/sameAssessmentComponentWeighting',$data);
                         else 
                         {
                             $data['weightingComponentNew']=$this->markingschemesetup_model->getAssessmentComponentWeighting($data['assessment'],$data['component']);
                             if (!empty($data['weightingComponentNew'])) $this->load->view('staff/markingSchemeSetup/assessmentWeightingComponentNew',$data);
                             else $this->load->view('staff/markingSchemeSetup/assessmentWeightingComponentNotFound',$data);
                             $this->markingschemesetup_model->saveChangesIncurredWithNewMarkingSchemeComponent($data['component'],$data['assessment'],$data['componentWeightingPrevious']);
                             $changedAssTransfer=true;
                         }   
                    }  
                 }    
       
        
                }
        
        
        if ($changedAssTransfer) 
        {
            $this->markingschemesetup_model->setUpNewlyCreatedAssessment();
            $this->markingschemesetup_model->saveNewlyCreatedAssessment($weightingAssessment,$weightingComponent);
        }
            
        
    }

    function displayMarkingScheme()
    {    
        $this->load->view('staff/markingSchemeSetup/previewMarkingSchemeForm',$data);
        $data['domMarkingScheme']=$this->markingschemesetup_model->getMarkingSchemeDom();
        $data['domXsltProc']=$this->markingschemesetup_model->getMarkingSchemeXsltProc();
        $this->load->view('staff/markingSchemeSetup/previewMarkingSchemeFormView',$data);
    }    
    
}





?>
