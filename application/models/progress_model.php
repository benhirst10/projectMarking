<?php
class progress_model extends Model {

    var $progressDB; 
    var $componentid;   
    var $componentVal;
    var $numericVal;
    var $choiceVal;
    var $compNo;
    var $assessment;
    var $dataEntryReportType;

    function progress_model()
    {
        parent::Model();
        $this->progressDB = $this->load->database('progress', TRUE); 

    }
    function getAssessmentMarksForStudent($stuid,$assessmentid)
    {
        // This function will find the mark for a particular student.
         $mark="";
         $sql = "SELECT mark,assessmentId FROM assessmentMarks WHERE uid =? and assessmentId=?";
         $query=$this->progressDB->query($sql, array($stuid,$assessmentid));     
         foreach($query->result() as $row)  if ($row->mark>0) $mark=$row->mark;
         return $mark;
    }   


    function getAssessmentChoiceForStudent($stuid,$assessmentid)
    {   
         // This function will display a list of enumerated types that are ranked according to sequence. These are usually associated with one choice
         // which is according to do with a radio button that is set in the interface. This may be if you require a boolean answer.
         $choice="";
         $sql="SELECT feedback FROM assessmentComponentMarks WHERE uid =? and assessmentId=? and type='choice'";
         $query=$this->progressDB->query($sql, array($stuid,$assessmentid));
         foreach($query->result() as $row)  $choice=$row->feedback;
             return $choice;
    }

    function checkIfReleasedFeedback($assessmentid)
    {
        
        // This function will give a true feedback that is assoiciated with an assessment.
        $sql="SELECT * FROM releaseFeedback WHERE assessmentId = ?";
        $releasedFeedbackQuery=$this->progressDB->query($sql,array($assessmentid));
        return ($releasedFeedbackQuery->num_rows()==1);
    }

    function checkIfAssessmentNotAvailable($stuid,$assessmentid)
    {
        // This function will see if a feedback should not be released for an individual student.
        $sql = "SELECT * FROM assessmentNotAvailable WHERE assessmentId = ? and uid = ?";                                
        $showFeedbackQuery = $this->progressDB->query($sql,array($assessmentid,$stuid));
        return ($showFeedbackQuery->num_rows()==0);
    }
    
    function getAsssementFinalMarks($sortSpread)
    {
        // This will give a list of sorted marks according to a parameter that has been passed into the function.
        $sql = "SELECT * FROM finalMarks ORDER BY mark $sortSpread,uid";
        return $this->progressDB->query($sql);
    }
    
    
    function setComponentValueArrays($assessment,$uid,$dataEntryReportType)
    {
          
            // This function's primary purpose is to enable the placement of items that are required to be attributed to input sources which will allow
            // alterations of data. These are associated with marking scheme elements.
          
            $this->compNo=0;
          
            // This obtains a list of component marking scheme elements that are associated with an assessment.
            $components=$this->markingscheme_model->getAssessmentComponents($assessment);
            foreach ($components as $entry) 
            {
                // The following variable is associated with the array sequence that is connected with assessment components.
                $this->compNo++;
            
                // This will obtain the primary labeling of the component which is a sub index of assessment and a relative value.
                $this->componentid[$this->compNo]=$entry->getAttribute('id');
            
                $this->componentVal[$this->compNo]="";
                $this->numericVal[$this->compNo]=0;
                $this->choiceVal[$this->compNo]="";
                $outOf=$this->markingscheme_model->getOutOf($assessment,$entry->getAttribute('id'));

                // This will find the mark for the assessment component for a particular assessment and student.
                $sql="SELECT feedback,mark,type,componentId FROM assessmentComponentMarks WHERE uid =? and assessmentId = ? and componentId = ? ";
                $feedbackQuery = $this->progressDB->query($sql,array($uid,$assessment,$entry->getAttribute('id')));
                foreach($feedbackQuery->result() as $row) 
                {
                        // When the feedback variable is attributed a value of feedback it will use this row of the table to assign a value to a question which
                        // has a textual description. This may have an associated numeric value.
                        if ($row->type=="feedback") 
                        {
                            $this->componentVal[$this->compNo]=$row->feedback;
                            $this->numericVal[$this->compNo]=($row->mark)*$outOf;
                        }
            
                        // In such cases where one value has been chosen from a set of choices this is attrbuted to the value of the component.
                        if ($row->type=="choice")  $this->choiceVal[$this->compNo]=$row->feedback;
                    }           

                }
                // This will determine the assessment that is to be used to save the data.
                $this->assessment=$assessment;
           
                // A report type that is dependable on factors which may influence the changes of values.
                $this->dataEntryReportType=$dataEntryReportType;
     }
     
     function getMaximumComponents()
     {
        // The function is connected to the looped parameter that has been associated with attributing
        // values to components in the marking scheme is passed back to another variable.
        return $this->compNo;
     }
     
     function setTransformForAssessmentTitle()
     {
            
        // This function will determine a partial appliance of the transform of the marking scheme so that an assessment title will be displayed.
        
        $assessmentXsltProc=$this->markingscheme_model->getMarkingSchemeXsltProc();
        $assessmentXsltProc->setParameter('','componentid',''); 
        $assessmentXsltProc->setParameter('','componentVal',''); 
        $assessmentXsltProc->setParameter('','numericVal','');        
        $assessmentXsltProc->setParameter('','assid',$this->assessment);
        $assessmentXsltProc->setParameter('','entryReport',$this->dataEntryReportType);
        return $assessmentXsltProc;
     
     }
     
     function setTransformForComponent($cnt)
     {
          // This function will attribute values that are connected with a partial transform that enable values to be picked.   
     
           $assessmentXsltProc=$this->markingscheme_model->getMarkingSchemeXsltProc();  
           $assessmentXsltProc->setParameter('','componentid',$this->componentid[$cnt]);   
           $assessmentXsltProc->setParameter('','componentVal',$this->componentVal[$cnt]);  
           $assessmentXsltProc->setParameter('','choiceVal',$this->choiceVal[$cnt]);
           $assessmentXsltProc->setParameter('','entryReport',$this->dataEntryReportType);
           if (isset($this->numericVal[$cnt])) $assessmentXsltProc->setParameter('','numericVal',$this->numericVal[$cnt]);   
           return $assessmentXsltProc;
     }
     function saveFeedback($feedback,$uid,$type)
     {
        // This function is multiple purpose as it is attributed to values which are specificaly placed within the sequence associated with 
        // the elements that make up the components. These component are array based in their form as inputting devices. 
        // The elements in concern are feedback, choice and mark. Both feedback and mark are dealt with accordingly.
        
        if ($type=="feedback" || $type=="choice") $typeField="feedback";
        else {$typeField="mark"; $type="feedback";}
        
        // In such cases where feedback has been given a value both the method of indexing according to assessment and its derived components is 
        // decomposed.
            if (isset($feedback)) while (list($assid,$component) = each($feedback))
            while (list($compno,$componentval) = each($component)) 
        {
            // This will get the out of mark when a value greater than 0 has been assigned a value;
            if ($typeField=="mark" && $componentval>0) 
            {
                $outOf=$this->markingscheme_model->getOutOf($assid,$compno);
                if ($outOf>0) $componentval=$componentval/$outOf;
            
            }
            $componentval=  htmlspecialchars($componentval,ENT_QUOTES);
            $sql = "SELECT * FROM assessmentComponentMarks WHERE uid=? and assessmentId = ? and componentId = ? and type = ?";
            $findSavedFeedback = $this->progressDB->query($sql,array($uid,$assid,$compno,$type));
            if ($findSavedFeedback->num_rows()==0)
            {
                $data = array(

                            'uid' => $uid,
                            'componentId' => $compno,
                            'assessmentId' => $assid,
                            $typeField=> $componentval,
                            'type'=> $type
                        );
                $this->progressDB->insert('assessmentComponentMarks', $data); 
            
            } else
            {
                $data = array(

                            $typeField=> $componentval
                        );          
                $this->progressDB->where('componentId', $compno);
                $this->progressDB->where('assessmentId', $assid);
                $this->progressDB->where('uid', $uid);
                $this->progressDB->where('type', $type);
                $this->progressDB->update('assessmentComponentMarks', $data); 
            }

        }

    }
    
     function saveFinalMark($finalMark,$uid)
     {
        // This function will save different marks when establishment of the spreadsheet has taken place.    
        
        $sql="SELECT * FROM finalMarks WHERE uid=? group by uid,mark";
        $findSavedFinalMarksQuery = $this->progressDB->query($sql,array($uid));
        if ($findSavedFinalMarksQuery->num_rows()==0)
        {
                            $data = array('uid' => $uid, 'mark' => $finalMark);
                            $this->progressDB->insert('finalMarks', $data);
        } else
        {
                    
            $data = array('mark' => $finalMark);
            $this->progressDB->where('uid', $uid);
            $this->progressDB->update('finalMarks', $data); 
        }  
     }
    
    function sortSpreadsheet($sortType)
    {
            // This will sort marks in the spreadsheet according to a particular sort type in connection with overall mark.
            // It is dependent on establishment of a spreadsheet before access to marks takes place. This will be direct replacement for the established xml form of student list.
    
            $domStudentSort = new DOMDocument('1.0','UTF-8');
            $domStudentSort->formatOutput = true;
            $root = $domStudentSort->createElement ("studentlist");
            $root = $domStudentSort->appendChild ($root);          
            $sql="SELECT * FROM finalMarks order by mark $sortType";
            $findSavedFeedbackQuery = $this->progressDB->query($sql);
            foreach ($findSavedFeedbackQuery->result() as $row) 
            {
                    
                // find student information.
                $student=$this->students_model->getStudent($row->uid);
                $uid=$row->uid;
                foreach($student as $st)
                {
                    $forenames=$st->getAttribute('forenames');
                    $surname=$st->getAttribute('surname');
                    $candidate_number=$st->getAttribute('candidate_number');
                    $degreecode=$st->getAttribute('degreecode');
                }
        
                $studentTag = $domStudentSort->createElement ("student");
                $studentTag = $root->appendChild ($studentTag);
        
                $attr_uid = $domStudentSort->createAttribute ('uid');
                $attr_uid = $studentTag->appendChild ($attr_uid);
                $studentTag->setAttribute('uid', $uid); 
                
                $attr_forenames = $domStudentSort->createAttribute ('forenames');
                $attr_forenames = $studentTag->appendChild ($attr_forenames);
                $studentTag->setAttribute('forenames', $forenames);
                
                $attr_surname = $domStudentSort->createAttribute ('surname');
                $attr_surname = $studentTag->appendChild ($attr_surname);
                $studentTag->setAttribute('surname', $surname);
                                    
                $attr_candidate_number = $domStudentSort->createAttribute ('candidate_number');
                $attr_candidate_number = $studentTag->appendChild ($attr_candidate_number);
                $studentTag->setAttribute('candidate_number', $candidate_number);
                
                $attr_degreecode = $domStudentSort->createAttribute ('degreecode');
                $attr_degreecode = $studentTag->appendChild ($attr_degreecode);
                $studentTag->setAttribute('degreecode', $degreecode);
        
            }        
        $studentXpath = new DOMXPath($domStudentSort);
        $queryStudent = "//student";
        $studentDetails=$studentXpath->query($queryStudent);              
        
        return $studentDetails;
    
    }
    
    
    function saveAssessmentTotal($totalmark,$uid,$assid)
    {
        
        // This function will assign values that are saved when input has been given in a form.
        $sql="SELECT * FROM assessmentMarks WHERE uid = ? and assessmentId = ?";
            $findSavedFeedback = $this->progressDB->query($sql,array($uid,$assid));
        
        // In such circumstances where there are no returning rows this means that initial entry is required for the unique indentifiers.
        // Otherwise it requires an update of the altered value.
        if ($findSavedFeedback->num_rows()==0)
        {
                $data = array(

                            'uid' => $uid,
                            'assessmentId' => $assid,
                            'mark'=> $totalmark
                        );   
                $this->progressDB->insert('assessmentMarks', $data);        
        } else
        {
                $data = array(
                            'mark'=> $totalmark
                        );  
                $this->progressDB->where('assessmentId', $assid);
                $this->progressDB->where('uid', $uid);
                $this->progressDB->update('assessmentMarks', $data); 
        }
     
    }
    
    
    function saveReleaseDetails($stuid,$studentAssessments,$assessments)
    {
       // In this function where needs arise to release feedback after their has been agreement with staff. 
    
       $cnt=1;
       if (isset($studentAssessments)) while (list($assid,$value) = each($studentAssessments))
       {
        
           if (empty($stuid))
           {    
               if ($cnt==1) {
            $sql="DELETE FROM releaseFeedback";
            $this->progressDB->query($sql);
           }
           $data = array(
                            'assessmentId'=> $assid
                        );         
           $this->progressDB->insert('releaseFeedback', $data);
           } else
           {
               if ($cnt==1)
               {

                   $counter=1;  
                   // This will go through all the assessments that have been selected on a individual basis for a student 
               // and insert a not availability flat too students that are not available.
                   foreach($assessments as $spreadsheetTag)
                   {   
                   
               // A check is first established to obtain which assessment have been inserted into the database on the above conditions.
               $sql="SELECT * FROM assessmentNotAvailable WHERE uid = ? and assessmentId = ?";
               $findAssessmentQuery = $this->progressDB->query($sql,array($stuid,$spreadsheetTag->getAttribute('id')));
               
               $data = array(
                            'assessmentId' => $spreadsheetTag->getAttribute('id'),
                    'uid' => $stuid
                    
                       );
               
               if ($findAssessmentQuery->num_rows()==0) 
                $this->progressDB->insert('assessmentNotAvailable', $data);     

                   }
               }  
           
           // It then goes through deleting items that have been not ticked to be assessed.
               $sql = 'DELETE FROM assessmentNotAvailable WHERE uid = ? and assessmentId = ?';
               $query = $this->progressDB->query($sql,array($stuid,$assid));

           }
           $cnt++;
       }
    }
     
}
