<?php


function headerJavaScript()
{
    
return "
<script>
    function checkradio() {
    var radio_choice1 = -1;
    var radio_choice2 = -1;
    var radio_choice3 = -1;
    var radio_choice4 = -1;
    var msgdisp = false;
    var firstChoiceSup = -1;
    var secondChoiceSup = -1;
    var thirdChoiceSup = -1;
    var fourthChoiceSup = -1;
    var s1 = 0;
    var s2 = 0;
    var s3 = 0;
    var s4 = 0;
    var s5 = 0;
    var s6 = 0;

    var posRadio=0;

    for (i=0;i<document.projectform.length;i++)
    {
        var tempobj=document.projectform.elements[i];
        if (tempobj.type==\"radio\" && posRadio==0)
        {
            posRadio=i;
        }
    }


    // Loop from zero to the one minus the number of radio button selections
    for (counter = 0; counter < document.projectform.colfirstchoice.length; counter++)
    {
        if (document.projectform.colfirstchoice[counter].checked)
        {
            radio_choice1 = counter;
            firstChoiceSup=counter;
        }
    }
    for (counter = 0; counter < document.projectform.colsecondchoice.length; counter++)
    {
        if (document.projectform.colsecondchoice[counter].checked)
        {
            radio_choice2 = counter;
            secondChoiceSup=counter;
        }
    }

    for (counter = 0; counter < document.projectform.colthirdchoice.length; counter++)
    {
        if (document.projectform.colthirdchoice[counter].checked)
        {
            radio_choice3 = counter;
            thirdChoiceSup=counter;
        }
    }

    for (counter = 0; counter < document.projectform.colfourthchoice.length; counter++)
    {
        if (document.projectform.colfourthchoice[counter].checked)
        {
            radio_choice4 = counter;
            fourthChoiceSup=counter;
        }
    }


    if (radio_choice1!=-1)
    {
        if (radio_choice1==radio_choice2 || radio_choice1==radio_choice3 || radio_choice1==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the first \");
            return false;
        }


    }

    if (radio_choice2!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice2 || radio_choice2==radio_choice3 || radio_choice2==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the second\");
            return false;
        }

    }

    if (radio_choice3!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice3 || radio_choice2==radio_choice3 || radio_choice3==radio_choice4)
        {
        alert (\"Please make sure that preferences are for a different project rather than the same as the third\");
        return false;
        }

    }

    if (radio_choice4!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice4 || radio_choice2==radio_choice4 || radio_choice3==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the fourth\");
            return false;
        }

    }

    return true;


    }
    function checkformradio() {
    var radio_choice1 = -1;
    var radio_choice2 = -1;
    var radio_choice3 = -1;
    var radio_choice4 = -1;
    var msgdisp = false;
    var firstChoiceSup = -1;
    var secondChoiceSup = -1;
    var thirdChoiceSup = -1;
    var fourthChoiceSup = -1;
    var s1 = 0;
    var s2 = 0;
    var s3 = 0;
    var s4 = 0;
    var s5 = 0;
    var s6 = 0;

    var posRadio=0;


    for (i=0;i<document.projectform.length;i++)
    {
        var tempobj=document.projectform.elements[i];
        if (tempobj.type==\"radio\" && posRadio==0)
        {
            posRadio=i;
        }
    }


    // Loop from zero to the one minus the number of radio button selections
    for (counter = 0; counter < document.projectform.colfirstchoice.length; counter++)
    {
        if (document.projectform.colfirstchoice[counter].checked)
        {
            radio_choice1 = counter;
            firstChoiceSup=counter;
        }
    }
    for (counter = 0; counter < document.projectform.colsecondchoice.length; counter++)
    {
        if (document.projectform.colsecondchoice[counter].checked)
        {
            radio_choice2 = counter;
            secondChoiceSup=counter;
        }
    }

    for (counter = 0; counter < document.projectform.colthirdchoice.length; counter++)
    {
        if (document.projectform.colthirdchoice[counter].checked)
        {
            radio_choice3 = counter;
            thirdChoiceSup=counter;
        }
    }

    for (counter = 0; counter < document.projectform.colfourthchoice.length; counter++)
    {
        if (document.projectform.colfourthchoice[counter].checked)
        {
            radio_choice4 = counter;
            fourthChoiceSup=counter;
        }
    }


    if (radio_choice1!=-1)
    {
        if (radio_choice1==radio_choice2 || radio_choice1==radio_choice3 || radio_choice1==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the first\");
            return false;
        }


    }

    if (radio_choice2!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice2 || radio_choice2==radio_choice3 || radio_choice2==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the second\");
            return false;
        }

    }

    if (radio_choice3!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice3 || radio_choice2==radio_choice3 || radio_choice3==radio_choice4)
        {
        alert (\"Please make sure that preferences are for a different project rather than the same as the third\");
        return false;
        }

    }

    if (radio_choice4!=-1  && !msgdisp)
    {
        if (radio_choice1==radio_choice4 || radio_choice2==radio_choice4 || radio_choice3==radio_choice4)
        {
            alert (\"Please make sure that preferences are for a different project rather than the same as the fourth\");
            return false;
        }

    }

    if (radio_choice1==-1 || radio_choice2==-1 || radio_choice3==-1 || radio_choice4==-1)
    {
        alert (\"Not all choices have been made\");
        return false;
    }


    return true;


    }


</script>";
}

function findLimitChoiceNo($preferencePageSetup)
{
    // This gains information about how many supervisors may be chosen for any given supervisor by students.

    $doc = new DOMDocument;
    $doc->preserveWhiteSpace = false;
    $doc->Load($preferencePageSetup);
    $xpath = new DOMXPath($doc);
    $query = "//limitSupervisorChoice";
    $supervisorChoice = $xpath->query($query);
    $limitChoice=0;
    foreach ($supervisorChoice as $sc) $limitChoice=$sc->getAttribute('limitChoice');
    return $limitChoice;
}


function savePreferences($uid,$pref1,$pref2,$pref3,$pref4,$projectPreferencesMdb2,$preferencePageSetup,$proposalFile,$markerList)
{
    // This will save preferences that students have saved and also check that they have not gone over the quota allocated for each supervisor.
    $limitChoice=findLimitChoiceNo($preferencePageSetup);
    $sameCnt=1;
    while($sameCnt++<5)
    {
        if ($same<=$limitChoice)
        {
            $same=0;
            if ($sameCnt==1) $match=getProposalStaff($pref1,$proposalFile,$markerList);
            if ($sameCnt==2) $match=getProposalStaff($pref2,$proposalFile,$markerList);
            if ($sameCnt==3) $match=getProposalStaff($pref3,$proposalFile,$markerList);
            if ($sameCnt==4) $match=getProposalStaff($pref4,$proposalFile,$markerList);
        
            if ($match==getProposalStaff($pref1,$proposalFile,$markerList)) $same++;
            if ($match==getProposalStaff($pref2,$proposalFile,$markerList)) $same++;
            if ($match==getProposalStaff($pref3,$proposalFile,$markerList)) $same++;
            if ($match==getProposalStaff($pref4,$proposalFile,$markerList)) $same++;
        }
        
    }
    
    if ($same<=$limitChoice) 
    {

       $prefToDelete = array($uid);
       $deletePrefQuery = 'DELETE FROM projectPreferences where uid = ?';
       $statement = $projectPreferencesMdb2->prepare($deletePrefQuery);
       $statement->execute($prefToDelete);
       if (PEAR::isError($statement)) print "Error in deleting into projectPreferences: ".$statement;
       $statement->free();

       $prefToSave = array($uid,"1",$pref1);
       $savePrefQuery = 'INSERT INTO projectPreferences (uid,pref,project) VALUES (?,?,?)';
       $statement = $projectPreferencesMdb2->prepare($savePrefQuery);
       $statement->execute($prefToSave);
       if (PEAR::isError($statement)) print "Error in inserting into projectPreferences: ".$statement;
       $statement->free();  

       $prefToSave = array($uid,"2",$pref2);
       $savePrefQuery = 'INSERT INTO projectPreferences (uid,pref,project) VALUES (?,?,?)';
       $statement = $projectPreferencesMdb2->prepare($savePrefQuery);
       $statement->execute($prefToSave);
       if (PEAR::isError($statement)) print "Error in inserting into projectPreferences: ".$statement;
       $statement->free();  

       $prefToSave = array($uid,"3",$pref3);
       $savePrefQuery = 'INSERT INTO projectPreferences (uid,pref,project) VALUES (?,?,?)';
       $statement = $projectPreferencesMdb2->prepare($savePrefQuery);
       $statement->execute($prefToSave);
       if (PEAR::isError($statement)) print "Error in inserting into projectPreferences: ".$statement;
       $statement->free();

       $prefToSave = array($uid,"4",$pref4);
       $savePrefQuery = 'INSERT INTO projectPreferences (uid,pref,project) VALUES (?,?,?)';
       $statement = $projectPreferencesMdb2->prepare($savePrefQuery);
       $statement->execute($prefToSave);
       if (PEAR::isError($statement)) print "Error in inserting into projectPreferences: ".$statement;
       $statement->free();
    }
    return $same>$limitChoice;
}

function checkIfPrefSaved($uid,$pref,$prefno,$projectPreferencesMdb2)
{
    // This will find the saved preference and display a message showing that the preference has been saved.
    
    $types = array("text","text","integer");
    $statement = $projectPreferencesMdb2->prepare("SELECT * FROM projectPreferences WHERE uid =? and project = ? and pref = ?", $types, MDB2_PREPARE_RESULT);
    $data = array($uid,$pref,$prefno);
    $projectPrefQuery = $statement->execute($data);
    if (PEAR::isError($projectPrefQuery)) print "Error in querying projectPreferences: ".$projectPrefQuery;
    else if ($projectPrefQuery->numRows()==0) {$statement->free();return "";} 
    $statement->free();
    
    return "<b>(Saved Preference ".$prefno.")</b>";
}

function displayPrefSaved($uid,$projectPreferencesMdb2,$proposalFile,$markerList,$student_proposals_link)
{
    // This will display a list of preferences that were saved by the student.
    
    $types = array("text");
    $statement = $projectPreferencesMdb2->prepare("SELECT * FROM projectPreferences WHERE uid =? ORDER BY pref", $types, MDB2_PREPARE_RESULT);
    $data = array($uid);
    $projectPrefQuery = $statement->execute($data);
    $html="";
    $cnt=1;
    while ($prefs = $projectPrefQuery->fetchRow(MDB2_FETCHMODE_ORDERED)) 
    {
         if ($cnt==1) $html.="<h1><b>Congratulations you have saved your preferences!!!</h1><p><b>Following is your list of ordered preferences:</b></p>";  
             $label=$prefs[2];
             $html.="(".$prefs[1].") ".displayPreferenceChoices($uid,$label,false,$proposalFile,$markerList,$projectPreferencesMdb2,$student_proposals_link,"","","","",false);
         $cnt++;
    
    }
    $statement->free();
    
    return $html;
}



function displayPreferenceChoices($stuid,$label,$tableFormat,$proposalFile,$markerList,$projectPreferencesMdb2,$student_proposals_link,$pref1,$pref2,$pref3,$pref4,$sameChoices)
{
    // This will set the radio button to the choice that has been saved. When too many people have been chosen preferences will not be saved and the previously submitted preferences will be displayed.
    
         $title=getProposalTitle($label,$proposalFile,$student_proposals_link,$markerList);
         $saved=checkIfPrefSaved($stuid,$label,1,$projectPreferencesMdb2);
         $html="";
         if (empty($saved)) $saved=checkIfPrefSaved($stuid,$label,2,$projectPreferencesMdb2);
         if (empty($saved)) $saved=checkIfPrefSaved($stuid,$label,3,$projectPreferencesMdb2);
         if (empty($saved)) $saved=checkIfPrefSaved($stuid,$label,4,$projectPreferencesMdb2);   
         
         if ($tableFormat && !empty($title))
         {
            $html.= "<tr><td align=center>$title $saved</td>";
        if (checkIfPrefSaved($stuid,$label,1,$projectPreferencesMdb2)!="" && !$sameChoices) $checked="checked"; else $checked="";
        if ($pref1==$label && $sameChoices)  $checked="checked"; else if ($sameChoices) $checked="";
                $html.="<td align=center><INPUT type='radio' name='colfirstchoice' value='$label' $checked onclick='checkradio()'></td>";
        if (checkIfPrefSaved($stuid,$label,2,$projectPreferencesMdb2)!="" && !$sameChoices) $checked="checked"; else $checked="";
        if ($pref2==$label && $sameChoices)  $checked="checked"; else if ($sameChoices) $checked="";
                $html.="<td align=center><INPUT type='radio' name='colsecondchoice' value='$label' $checked onclick='checkradio()'></td>";
        if (checkIfPrefSaved($stuid,$label,3,$projectPreferencesMdb2)!="" && !$sameChoices) $checked="checked"; else $checked="";
        if ($pref3==$label && $sameChoices)  $checked="checked"; else if ($sameChoices) $checked="";
                $html.="<td align=center><INPUT type='radio' name='colthirdchoice' value='$label' $checked onclick='checkradio()'></td>";
        if (checkIfPrefSaved($stuid,$label,4,$projectPreferencesMdb2)!="" && !$sameChoices) $checked="checked"; else $checked="";
        if ($pref4==$label && $sameChoices)  $checked="checked"; else if ($sameChoices)  $checked="";
                $html.="<td align=center><INPUT type='radio' name='colfourthchoice' value='$label' $checked onclick='checkradio()'></td></tr>";    

         } else if (!$tableFormat) $html.= "$title <br/>"; 
                
         return $html;       
}


?>
