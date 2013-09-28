<?php

    require_once('../utilities/phpdocx/php5/classes/cCreateDocx.inc');
    
    $markersDom=new DOMDocument();
    $markersDom->load($markingSetup);   
    $markersXpath = new DOMXPath($markersDom);
    
    $markingSchemeDom=new DOMDocument();
    $markingSchemeDom->load($markingScheme);
    $domStudents=new DOMDocument();
    $domStudents->load($moduleList);
    $objDocx = new cCreateDocx();
    $arrParamsTitle = array('b' => 'single','sz' => '14');
    $arrParamsSubTitleCentred = array('u' => 'single','sz' => '10','jc' => 'center');
    $arrParamsSubTitleLeft = array('u' => 'single','sz' => '10','jc' => 'left');
    $arrParamsPara = array('sz' => '10','jc' => 'both', 'widowControl' => 'widow');
    $arrParamsTextI = array('i' => 'single');   
    
    $studentTag=$domStudents->getElementsByTagName('student');          
    foreach($studentTag as $stTag)
    {   
        $objStudentDocx = new cCreateDocx();
        $stuid=$stTag->getAttribute('uid');
        $surname=$stTag->getAttribute('surname');
        $forenames=$stTag->getAttribute('forenames');
        $candidate_number=$stTag->getAttribute('candidate_number');
        $degreecode=$stTag->getAttribute('degreecode');
        $queryMarkers = "///supervision[@student=\"$stuid\"]";
        $markerQuery = $markersXpath->query($queryMarkers);
        $supervisor="sup";
        $sndMarker="sm";
        foreach ($markerQuery as $mk) 
        {
            $supervisor=$mk->getAttribute('supervisor');
            $sndMarker=$mk->getAttribute('secondmarker');
        }
        
        $student= "$surname, $forenames ($stuid,$candidate_number,$degreecode)";
        $markerDetails="Supervisor: $supervisor  Second Marker: $sndMarker";
        $projectTitle=projectTitle($stuid,$markingSetup,$proposal,$proposal_link);
        
        $objDocx->fAddText($student,$arrParamsTextI);
        $objStudentDocx->fAddText($student,$arrParamsTextI);
        $objDocx->fAddText($markerDetails,$arrParamsTextLeft);
        $objStudentDocx->fAddText($markerDetails,$arrParamsTextLeft);
        $objDocx->fAddText("Project: $projectTitle",$arrParamsTitle);
        $objStudentDocx->fAddText("Project: $projectTitle",$arrParamsTitle);

        $doc = new DOMDocument;
        $doc->Load($progressMarkingScheme);
        $xpath = new DOMXPath($doc);
        $query = "//assessment";    
        $assessments = $xpath->query($query);
        $overallmark=0;
        $overalltotal=0;
        $foundAss=false;
        foreach ($assessments as $as) 
        {
            if($as->hasAttribute('excludeFromSpread'))
            {
                $spreadExclude="Exclude";
            } else $spreadExclude="";           
            $assessmentid=$as->getAttribute('id');  
            $weighting=$as->getAttribute('weighting');
            $types = array("text","text");
            $statement = $progressMdb2->prepare("SELECT mark,assessmentId FROM assessmentMarks WHERE uid =? and assessmentId=?", $types, MDB2_PREPARE_RESULT);
            $data = array($stuid,$assessmentid);
            $assesmentMarksQuery = $statement->execute($data);
            if (PEAR::isError($assesmentMarksQuery)) print "Error in quering asssessment marks: ".$assesmentMarksQuery; 
            $foundAssessmentMark=false;                 
            while ($marks = $assesmentMarksQuery->fetchRow(MDB2_FETCHMODE_ORDERED)) 
            {   
                $assessmentmark=round($marks[0],2);
                $overallmark=$overallmark+($assessmentmark*$weighting);
                $total=$total+$weighting;   
                $foundAssessmentMark=true;
                $foundAss=true;
            }
            if (!$foundAssessmentMark && empty($spreadExclude)) 
            {
                $types = array("text","text");
                $statement = $progressMdb2->prepare("SELECT feedback FROM assessmentComponentMarks WHERE uid =? and assessmentId=? and type='choice'", $types, MDB2_PREPARE_RESULT);
                $data = array($stuid,$assessmentid);
                $assessmentComponentMarksQuery = $statement->execute($data);
                if ($assessmentComponentMarksQuery->numRows()==1) while ($marks = $assessmentComponentMarksQuery->fetchRow(MDB2_FETCHMODE_ORDERED))
                {
                    $objDocx->fAddText("$assessmentid:".$marks[0]); 
                    $objStudentDocx->fAddText("$assessmentid:".$marks[0]);
                }
            }
            if ($foundAssessmentMark && empty($spreadExclude)) {
                if ($weighting>0) $weightingText="(Weighting: $weighting)"; else $weightingText="";
                $objDocx->fAddText("$assessmentid: $assessmentmark% $weightingText");
                $objStudentDocx->fAddText("$assessmentid: $assessmentmark% $weightingText");
            }       
        }
        if ($foundAss)
        {
        
            if ($overallmark>0 && $total>0) $overallmark=round($overallmark/$total,2);
            if ($total>0) $weightingText="(Total: $total)"; else $weightingText="";
            $objDocx->fAddText("Overall Mark: $overallmark% $weightingText");
            $objStudentDocx->fAddText("Overall Mark: $overallmark% $weightingText");
        }
        
        
        foreach ($assessments as $as) 
        {   
            $assessmentid=$as->getAttribute('id');  
            
            $types = array("text","text");
            $statement = $progressMdb2->prepare("SELECT mark,assessmentId FROM assessmentMarks WHERE uid =? and assessmentId=?", $types, MDB2_PREPARE_RESULT);
            $data = array($stuid,$assessmentid);
            $assesmentMarksQuery = $statement->execute($data);
            if (PEAR::isError($assesmentMarksQuery)) print "Error in quering asssessment marks: ".$assesmentMarksQuery; 
            $foundAssessmentMark=false;                 
            while ($marks = $assesmentMarksQuery->fetchRow(MDB2_FETCHMODE_ORDERED)) 
            {   
                $assessmentmark=round($marks[0],2); 
                $foundAssessmentMark=true;
            }
            if ($foundAssessmentMark) {
                $objDocx->fAddText("$assessmentid",$arrParamsSubTitleCentred);
                $objStudentDocx->fAddText("$assessmentid",$arrParamsSubTitleCentred);
                $objDocx->fAddText("Total: $assessmentmark%");
                $objStudentDocx->fAddText("Total: $assessmentmark%");
            }
            $weighting=$as->getAttribute('weighting');
            $query = "//assessment[@id=\"$assessmentid\"]/component";   
            $components= $xpath->query($query);
            foreach ($components as $cp) 
            {   
                $componentId=$cp->getAttribute('id');   
                $query = "//assessment[@id=\"$assessmentid\"]/component[@id=\"$componentId\"]/mark/numeric"; 
                $outofs= $xpath->query($query);
                foreach ($outofs as $outof) 
                {
                    $outOf=$outof->getAttribute('outof');
                }
                $query = "//assessment[@id=\"$assessmentid\"]/component[@id=\"$componentId\"]/feedback"; 
                $feedbacks= $xpath->query($query);
                foreach ($feedbacks as $fbs) 
                {
                    $staffonly=$fbs->getAttribute('staffonly');
                    $style=$fbs->getAttribute('style');
                }
                                
                $query = "//assessment[@id=\"$assessmentid\"]/component[@id=\"$componentId\"]/description"; 
                $descriptions= $xpath->query($query);
                foreach ($descriptions as $ds) 
                {
                    $description=$ds->nodeValue;

                }
                $query = "//assessment[@id=\"$assessmentid\"]/component[@id=\"$componentId\"]/markingGuide"; 
                $markingGuides= $xpath->query($query);
                foreach ($markingGuides as $mg) 
                {
                    $markingGuide=$mg->nodeValue;
                }           
                $weightingcomp=$cp->getAttribute('weighting');  
                $types = array("text","text","text");
                $statement2 = $progressMdb2->prepare("SELECT feedback,mark FROM assessmentComponentMarks WHERE uid =? and assessmentId=? and componentId=?", $types, MDB2_PREPARE_RESULT);
                $data = array($stuid,$assessmentid,$componentId);
                $assessmentComponentMarksQuery = $statement2->execute($data);
                if (PEAR::isError($assessmentComponentMarksQuery)) print "Error in quering asssessment component marks: ".$assessmentComponentMarksQuery;
                $foundFeedback=false;
                $cnt=0;
                while ($marks = $assessmentComponentMarksQuery->fetchRow(MDB2_FETCHMODE_ORDERED)) 
                {
                    $cnt++;
                    if ($cnt==1)
                    {
                        $objDocx->fAddText($description,$arrParamsSubTitleLeft);
                        $objStudentDocx->fAddText($description,$arrParamsSubTitleLeft);
                    }
                
                    $componentmark=$marks[1]*$outOf;
                    $feedback=$marks[0]; 
                    $objDocx->fAddText($feedback,$arrParamsPara);
                    $objStudentDocx->fAddText(htmlspecialchars_decode($feedback),$arrParamsPara);
                    $foundFeedback=true;
                    if (empty($feedback) && !empty($staffonly)) $foundFeedback=false;
                }
                $query = "//assessment[@id=\"$assessmentid\"]/component[@id=\"$componentId\"]/description"; 
                $descriptions= $xpath->query($query);
                foreach ($descriptions as $ds) 
                {
                    $description=$ds->nodeValue;

                }

    
                $query = "//assessment[@id=\"$assessmentid\"]/component[@id=\"$componentId\"]/markingGuide"; 
                $markingGuides= $xpath->query($query);
                foreach ($markingGuides as $mg) 
                {
                    $markingGuide=$mg->nodeValue;
                }
                if ($foundFeedback)
                {

                     if (empty($staffonly) && $outOf>0) 
                     {
                        $objDocx->fAddText("Total: $componentmark/$outOf");
                        $objStudentDocx->fAddText("Total: $componentmark/$outOf");
                     }
                     $objDocx->fAddBreak("line");   
                     $objStudentDocx->fAddBreak("line");
                }
                
                                
            }
        }
        
        $objDocx->fAddBreak("page");
        $studentFeedbackdocx="../generated/feedbackdocx/studentFeedback_$stuid";
        $objStudentDocx->fCreateDocx($studentFeedbackdocx);
            
    }
    $objDocx->fCreateDocx('../generated/feedbackdocx/moduleFeedback');
?>

