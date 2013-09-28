<?php

if (!empty($_POST["saveFeedback"]))
{
    if (!empty($_POST["uid"])) $uid=$_POST["uid"];

    if (isset($_POST["feedback"])) while (list($assid,$component) = each($_POST["feedback"]))
    {
        
        while (list($compno,$componentval) = each($component)) 
        {
                 
            $types = array("text","text","text","text");
            // This will check to see if the components have been saved for a student.    
            $statement = $progressMdb2->prepare("SELECT * FROM assessmentComponentMarks WHERE uid=? and assessmentId = ? and componentId = ? and type = ?", $types, MDB2_PREPARE_RESULT);
            $data = array($uid,$assid,$compno,'feedback');
            $progressQuery = $statement->execute($data);
            $compNo=0;
            $componentval=  htmlspecialchars($componentval,ENT_QUOTES,UTF-8,true);
            if (PEAR::isError($progressQuery)) print "Error in querying assessmentComponent".$progressQuery;
            else if ($progressQuery->numRows()==0)
            {
                $assessmentComponentToSave = array($uid,$compno,$assid,$componentval,"feedback");
                $types = array("text","text","text","text","text");
                $saveAssessmentComponentQuery = 'INSERT INTO assessmentComponentMarks (uid,componentId,assessmentId,feedback,type) VALUES (?,?,?,?,?)';
                // This will insert the new feedback entry for a student.
                $statement = $progressMdb2->prepare($saveAssessmentComponentQuery,$types,MDB2_PREPARE_RESULT);
                $statement->execute($assessmentComponentToSave);
                if (PEAR::isError($statement)) print "Error in inserting into assessmentComponentMarks: ".$statement;
                $statement->free();
            }   else
            {
                $assessmentComponentToSave = array($componentval,$uid,$compno,$assid,"feedback");
                $saveAssessmentComponentQuery = 'UPDATE assessmentComponentMarks set feedback=? where uid = ? and componentId=? and assessmentId=? and type=?';
                // This will update the assessment component comments that are already saved in the system.
                $statement = $progressMdb2->prepare($saveAssessmentComponentQuery);
                $statement->execute($assessmentComponentToSave);
                if (PEAR::isError($statement)) print "Error in updating assessmentComponentMarks: ".$statement;
                $statement->free(); 
            }
        }
    
    
    }
    if (isset($_POST["choice"])) while (list($assid,$component) = each($_POST["choice"]))
    {
        while (list($compno,$componentval) = each($component)) 
        {
            $types = array("text","text","text","text");
            $statement = $progressMdb2->prepare("SELECT * FROM assessmentComponentMarks WHERE uid =? and assessmentId = ? and componentId = ? and type = ?", $types, MDB2_PREPARE_RESULT);
            $data = array($uid,$assid,$compno,'choice');
            $progressQuery = $statement->execute($data);
            $compNo=0;
            $componentval=htmlspecialchars($componentval,ENT_QUOTES,UTF-8);
            if (PEAR::isError($progressQuery)) print "Error in querying assessmentComponent".$progressQuery;
            else if ($progressQuery->numRows()==0)
            {
                $assessmentComponentToSave = array($uid,$compno,$assid,$componentval,"choice");
                $saveAssessmentComponentQuery = 'INSERT INTO assessmentComponentMarks (uid,componentId,assessmentId,feedback,type) VALUES (?,?,?,?,?)';
                // This will insert feedback for certain radio choices into the database.
                $statement = $progressMdb2->prepare($saveAssessmentComponentQuery);
                $statement->execute($assessmentComponentToSave);
                if (PEAR::isError($statement)) print "Error in inserting into assessmentComponentMarks: ".$statement;
                $statement->free();
            }   else
            {
                $assessmentComponentToSave = array($componentval,$uid,$compno,$assid,"choice");
                $saveAssessmentComponentQuery = 'UPDATE assessmentComponentMarks set feedback=? where uid = ? and componentId=? and assessmentId=? and type=?';
                // This will update component feedback for radio choices
                $statement = $progressMdb2->prepare($saveAssessmentComponentQuery);
                $statement->execute($assessmentComponentToSave);
                if (PEAR::isError($statement)) print "Error in updating assessmentComponentMarks: ".$statement;
                $statement->free();          
            }
        }
    }   
    if (isset($_POST["mark"])) while (list($assid,$component) = each($_POST["mark"]))
    {
        while (list($compno,$componentval) = each($component)) 
        {
         if ($componentval>0)
         {
             $outOf=findOutOf($assid,$compno,$progressMarkingScheme);   
             if ($outOf>0) $componentval=$componentval/$outOf;
         }
         $types = array("text","text","text","text");
         $statement = $progressMdb2->prepare("SELECT * FROM assessmentComponentMarks WHERE uid = ? and assessmentId = ? and componentId = ? and type = ?", $types, MDB2_PREPARE_RESULT);
         $data = array($uid,$assid,$compno,'feedback');
         $progressQuery = $statement->execute($data);

         $compNo=0;

        if (PEAR::isError($progressQuery)) print "Error in querying assessmentComponentMarks".$markingSchemeQuery;
        else if ($progressQuery->numRows()==0)
            {
                $assessmentComponentToSave = array($uid,$compno,$assid,$componentval,"feedback");
                $saveAssessmentComponentQuery = 'INSERT INTO assessmentComponentMarks (uid,componentId,assessmentId,mark,type) VALUES (?,?,?,?,?)';
                $statement = $progressMdb2->prepare($saveAssessmentComponentQuery);
                $statement->execute($assessmentComponentToSave);
                if (PEAR::isError($statement)) print "Error in inserting into assessmentComponentMarks: ".$statement;
                $statement->free();
            } else
            {
                $assessmentComponentToSave = array($componentval,$uid,$compno,$assid,"feedback");
                $saveAssessmentComponentQuery = 'UPDATE assessmentComponentMarks set mark=? where uid=? and componentId=? and assessmentId=? and type=?';
                $statement = $progressMdb2->prepare($saveAssessmentComponentQuery);
                $statement->execute($assessmentComponentToSave);
                if (PEAR::isError($statement)) print "Error in updating assessmentComponentMarks: ".$statement;
                $statement->free();
            }
                    
        }
    }      
    if ((!empty($_POST["totalmarks1"]) && $_POST["totalmarks1"]!="NaN") || $_POST["totalmarks1"]=="0")
    {
        
         $types = array("text","text","text","text");
         $statement = $progressMdb2->prepare("SELECT * FROM assessmentMarks WHERE uid = ? and assessmentId = ?", $types, MDB2_PREPARE_RESULT);
         $data = array($uid,$assessment,$compno,'feedback');
         $progressQuery = $statement->execute($data);

         $compNo=0;

         if (PEAR::isError($progressQuery)) print "Error in querying assessmentComponentMarks".$markingSchemeQuery;
         else if ($progressQuery->numRows()==0)
        {
             $assessmentComponentToSave = array($uid,$assessment,$_POST["totalmarks1"]);
             // This will create an entry in the database when no mark has been saved for that student assessment.
             $saveAssessmentComponentQuery = 'INSERT INTO assessmentMarks (uid,assessmentId,mark) VALUES (?,?,?)';
             $statement = $progressMdb2->prepare($saveAssessmentComponentQuery);
             $statement->execute($assessmentComponentToSave);
             if (PEAR::isError($statement)) print "Error in inserting into assessmentMarks: ".$statement;
             $statement->free();
        } else
        {
             $assessmentComponentToSave = array($_POST["totalmarks1"],$uid,$assessment);
             $saveAssessmentComponentQuery = 'UPDATE assessmentMarks set mark=? where uid=? and assessmentId=?';
             // This will update the database with the new mark for that student assessment.
             $statement = $progressMdb2->prepare($saveAssessmentComponentQuery);
             $statement->execute($assessmentComponentToSave);
             if (PEAR::isError($statement)) print "Error in updating assessmentMarks: ".$statement;
             $statement->free();
        }

    }
 }
?>

