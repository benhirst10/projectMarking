<?php
        include "../../common/php/markingSetupFunctions.inc";
    include "../../common/php/projectPreferencesDB.inc";
    include "markingSetupDB.inc";
    if (!empty($_POST["prefDisplay"])) $prefDisplay=$_POST["prefDisplay"]; else $prefDisplay="";
    if (!empty($_POST["previousTypeOrder"])) $previousTypeOrder=$_POST["previousTypeOrder"]; else $previousTypeOrder="";
    if (!empty($_POST["typeOrder"])) $typeOrder=$_POST["typeOrder"]; else $typeOrder="";
    
    checkFileExists($proposalFile,"generated proposal file");
    if (empty($_POST["sessionStamp"])) 
    {
             // This creates a stamp that is used to ensure the student list is only used by session. If the list used by the marking system is subsequently updated this will not affect the present setup.
             $sessionStamp = "_".date("Ymdhis")."_".$_SERVER["PHP_AUTH_USER"];
             $dom=new DOMDocument();
             $dom->load($studentList);
             $newname="../../common/generated/xml/studentlist$sessionStamp.xml";
             file_put_contents($newname, $dom->saveXML());

    } else $sessionStamp=$_POST["sessionStamp"];
    $studentList="../../common/generated/xml/studentlist$sessionStamp.xml";
    if (empty($_POST["printableVersion"])) 
    {
        if ($previousTypeOrder=="supervisor") $studentList="../../common/generated/xml/studentlistSup$sessionStamp.xml";
        if ($previousTypeOrder=="secondmarker") $studentList="../../common/generated/xml/studentlistSM$sessionStamp.xml";
        if ($previousTypeOrder=="project") $studentList="../../common/generated/xml/studentlistProject$sessionStamp.xml";

        if (!empty($_POST["saveMarkingSetup"]))
        {
            if (!empty($_POST["markerSelected"])) $markerSelected=$_POST["markerSelected"];
            if (!empty($_POST["projectChoice"])) $projectChoice=$_POST["projectChoice"];
            if (!empty($_POST["secondMarkerSelected"])) $secondMarkerSelected=$_POST["secondMarkerSelected"];
            // This will save assigned markers and projects. It will also save the maximums.
            saveMarkingSetup($markerList,$markingSetupFile,$markerSelected,$projectChoice,$secondMarkerSelected,$studentList,$proposalFile,$markingSetupMdb2);
            saveMarkingMax($markerMaxList,$markerList,$_POST["supT"],$_POST["smT"]);
        }
        $profilesNo=createListOfDegreeProjects($proposalFile); 
        $profilesNo=degreeRestrictions($proposalFile); // This finds the number of proposals that have degree restrictions.
        
    
        $outputFile="../../common/generated/xml/studentlist$sessionStamp.xml";
        $studentList="../../common/generated/xml/studentlist$sessionStamp.xml";
        if ($typeOrder=="supervisor") {$outputFile="../../common/generated/xml/studentlistSup$sessionStamp.xml";$checkedSup="checked";} else $checkedSup="";
        if ($typeOrder=="secondmarker") {$outputFile="../../common/generated/xml/studentlistSM$sessionStamp.xml";$checkedSM="checked";} else $checkedSM="";
        if ($typeOrder=="project") {$outputFile="../../common/generated/xml/studentlistProject$sessionStamp.xml";$checkedProj="checked";} else $checkedProj="";
        if ($typeOrder=="alpha" || empty($_POST["typeOrder"])) $checkedAlpha="checked"; else $checkedAlpha="";   

        $html = "<html>";
        $html.=css();
        $html.=headerJavaScriptMarkingSetup();
        // GROUP FORMATION: This should reflect choices that are given in comments further down this program that are to do with group formation.
        
        $html.="\n<head><title>Marking Setup Progress</title></head>\n<body>\n<form action='markingSetup2.php' name='markingSetup' method='post'>";
        $html.="\n<input type='submit' name='saveMarkingSetup' value='&nbsp;&nbsp;&nbsp;&nbsp;Save Marking Setup&nbsp;&nbsp;&nbsp;&nbsp;'/>";
        $html.="\n<input type='submit' name='printableVersion' value='Printable Version (Save First)' onClick='checkIfUpToDateList()'/>&nbsp;&nbsp;<h3>Students' need to use feedback link to find out who are their supervisor and second marker.</h3>";   
        $html.="\n<table border='1' class='heading'>\n<th>Student <input type='radio' name='typeOrder' value='alpha' $checkedAlpha></th>";
        $html.="\n<th>Supervisor <input type='radio' name='typeOrder' value='supervisor' $checkedSup></th>";
        $html.="\n<th>2nd Marker <input type='radio' name='typeOrder' value='secondmarker' $checkedSM></th>";
        $html.="\n<th>Project <input type='radio' name='typeOrder' value='project' $checkedProj>";
        $html.="\n<br/>Not saved preference display (e.g. 2): <input type='text' name='prefDisplay' maxlength = '4' size = '3' value='$prefDisplay'>";
        if (!empty($_POST["allPref"])) $displayAllPref="checked"; else $displayAllPref="";
        // This will give the option of including a full list of preferences.
        $html.="\n<br/>List Preferences:<input type='checkbox' name='allPref' $displayAllPref /></th>";
        $html.="\n<th>Information</th>";

        if (!empty($_POST["typeOrder"]) &&  $_POST["typeOrder"]!="alpha") $studentList=sortListByMarkerProject($studentList,$_POST["typeOrder"],$markingSetupMdb2,$outputFile);
        $dom=new DOMDocument();
        $dom->load($studentList);
        $studentXpath = new DOMXPath($dom);
        // This will obtain a list of all students for the purposes of assigning markers and projects to staff.
        $queryStudents = "//student";
        $students=$studentXpath->query($queryStudents);
        
        // This will load the the already assigned marking setup.
        $domMarkingSetup=new DOMDocument();
        $domMarkingSetup->load($markingSetupFile);
        $markingXpath = new DOMXPath($domMarkingSetup);    
        
        // This will load the student choices which is an xml file that is generated from the sqlite database containing all the preferences.
        $domStudentChoices = new DOMDocument;
        $domStudentChoices->preserveWhiteSpace = false;
        $domStudentChoices->Load($studentChoices);
        $xpathStudentChoices = new DOMXPath($domStudentChoices);  
        
        // The markers stylesheet is used to be a list of selectable markers.           
        $markerXsltProc = new XSLTProcessor();
        $markerXsltProc->importStylesheet( DOMDocument::load('markersSupSM.xslt') );
        
        // This will convert the full list of preferences, project proposals and hidden proposals and make sure the selected student is chosen.
        $projectsXsltProc = new XSLTProcessor();
        $projectsXsltProc->importStylesheet( DOMDocument::load('projectChoices.xslt') );
        
        // This will load the full list of markers.
        $domMarkerList=new DOMDocument();
        $domMarkerList->load($markerList);
        
        // This will give a list of student choices.
        $domProjectChoices=new DOMDocument();
        $domProjectChoices->load($studentChoices);
        
        
        $domAbreviations = new DOMDocument;
        $domAbreviations->preserveWhiteSpace = false;
        $domAbreviations->Load($degreeAbreviationsFile);
        $degreeAbreviationsXpath = new DOMXPath($domAbreviations);
                
        $studentChoicesDom=new DOMDocument();    
        $studentChoicesDom->load($studentChoices);
        $studentChoicesXpath = new DOMXPath( $studentChoicesDom);   
           
        $studentProposalDom=new DOMDocument();    
        $studentProposalDom->load($proposalFile);
        $studentProposalXpath = new DOMXPath($studentProposalDom);   
        
        $degreeRestrictionFile="../../common/generated/xml/projects.xml";   
        $degreeRestrictionDom=new DOMDocument();    
        $degreeRestrictionDom->load($degreeRestrictionFile);
        $degreeRestrictionXpath = new DOMXPath($degreeRestrictionDom);   
             
                 
        $studentCount=1;
        foreach($students as $stTag)
        {
                $stuid=$stTag->getAttribute('uid');
                $surname=$stTag->getAttribute('surname');
                $forenames=$stTag->getAttribute('forenames');
                $candidate_number=$stTag->getAttribute('candidate_number');
                $degreecode=$stTag->getAttribute('degreecode');
                $html.= "<tr class='heading5'><td>($studentCount)<a href=\"../studentPreferences/projectPreferences.php?stuid=$stuid\" target=\"_blank\">$surname, $forenames ($degreecode, $stuid)</a></td>";
                if ($profilesNo>0)
                {
                    // This will give you the abreviation for the degree code which is used to limit preference choices depending on degree programme.
                   $degreecode=findDegreeCodeAbreviation($degreeAbreviationsXpath,$degreecode);
                } else $degreecode="";
                $supervisor="";
                $sndMarker="";
                $projectChoice="";
                if (file_exists($markingSetupFile))
                {
                    $queryMarking= "//supervisors/supervision[@student='$stuid']";
                    // This will find supervisors of students.
                    $markings=$markingXpath->query($queryMarking);
                    foreach ($markings as $mks)
                    {
                        $supervisor=$mks->getAttribute('supervisor');
                        $sndMarker=$mks->getAttribute('secondmarker');
                        $projectChoice=$mks->getAttribute('project');
                    }
                }
                $notSaved="";
                if ($projectChoice=="Select Choice" || empty($projectChoice))
                {
                    $projectChoice=findPreferenceChosen($studentChoicesXpath,$prefDisplay,$stuid);
                    // This will give the preference that was saved previously.
                    if ($projectChoice!="Select Choice") $notSaved="(Not Saved)";

                }
                // GROUP FORMATION - A new function that is formed on basis of restrictions that are generated from the group file. This should include both choices of marker. 
                // This is the case that in certain situations there does not neeed to be assignment from several markers. It also the case that group marking systems
                // default is that they do not need a second marker. On other occassions this might be apparently not the case.                
                
                $markerXsltProc->setParameter('','marker',$supervisor);
                $markerXsltProc->setParameter('','stuid',$stuid);
                $markerXsltProc->setParameter('','menuChoice','supervisor');
                $markerXsltProc->setParameter('','studentCount',$studentCount);

                // This will create a list box to chose the marker and show the selected marker.
                $html.= "\n<td>".$markerXsltProc->transformToXML(  $domMarkerList )."</td>";

                $markerXsltProc->setParameter('','marker',$sndMarker);
                $markerXsltProc->setParameter('','menuChoice','secondMarker');
                $html.= "\n<td>".$markerXsltProc->transformToXML( $domMarkerList )."</td>";

                $query = "//studentChoice[@uid='$stuid']/pref[@projid='$projectChoice']";
                $prefNo=$xpathStudentChoices->query($query)->length;
                if (!empty($_POST["allPref"])) $projectPreferences=displayPreferences($studentChoices,$studentChoicesDom,$proposals_link,$stuid);   else $projectPreferences="";

                if ($studentCount>101) $colspan="colspan='2'"; else $colspan="";
                
                // GROUP FORMATION - A procedure that incorporates a return which in the present form does not require a project to be set up. This should be based on the general group
                // file setup and whether exclusion of individual assigned projects is present.               
                
                // There is a list of preferences for each student which they have chosen if this option has been previously chosen on the form. This gives a selection box for project proposals. 
                $html.= "<td $colspan>$projectPreferences";
                $html.="<SELECT CLASS=\"selectBox\" onChange=\"document.markingSetup.calculateTotals.checked=false;\" name=\"projectChoice[$studentCount]\">";
                $html.="<OPTION>Select Choice</OPTION>";
                
                $queryStudentChoices="//studentChoice[@uid='$stuid']/pref";
                // the above line should be dependent on what has been entered within the preference rank box.
                $studentChoices=$studentChoicesXpath->query($queryStudentChoices);
                $prefChosen="";
                $html.="<optgroup label=\"Preferences\">";
                foreach($studentChoices as $stChoice)
                {
                   $projid=$stChoice->getAttribute('projid');
                   $rank=$stChoice->getAttribute('rank');
                   if ($projid==$projectChoice) {$selectedTag="SELECTED";$prefChosen=$projid;} else $selectedTag="";
                   $html.="<OPTION VALUE='$projid' $selectedTag>";
                   $query = "//project[@label=\"$projid\"]/title";
                   $proposal= $studentProposalXpath->query($query);
                   $foundTitle=false;
                   $projectTitle="";
                   foreach ($proposal as $prop) {$projectTitle.=htmlspecialchars($prop->nodeValue)." (Preference $rank)"; $foundTitle=true;}
                   if (!$foundTitle) $projectTitle="Own Project";                   
                   $html.=$projectTitle;
                   $html.="</OPTION>";
                }
                $html.="</optgroup>";
                $html.="<optgroup label=\"Other Projects\">";
                $queryProjects="//project";
                $projects=$studentProposalXpath->query($queryProjects);
                foreach($projects as $prj)
                {
                   $projid=$prj->getAttribute('label');
                   if ($projid==$projectChoice && $prefChosen!=$projectChoice) {$selectedTag="SELECTED";$prefChosen=true;} else $selectedTag="";
                   $hiddenVal= hiddenProposal($projid,$studentProposalXpath);
                   if (degreeRestricted($profilesNo,$projid,$degreecode,$degreeRestrictionXpath)>0 || $degreecode=="_all_" || !empty($hiddenVal))
                   {               
                            $titleTag=$prj->getElementsByTagName('title');
                            $projectTitle="";
                            if (!empty($hiddenVal)) $dispHidden="(hidden: $hiddenVal)"; else $dispHidden="";
                            foreach($titleTag as $ttag) $projectTitle=$ttag->nodeValue;
                            $html.="<OPTION VALUE='$projid' $selectedTag>";
                            $html.=$projectTitle.$dispHidden;
                            $html.="</OPTION>";                
                    }
                    
                }
                $html.="</optgroup>";
                $html.="</SELECT>";                 
                $html.="</td>";
                if ($studentCount==1) 
                {
                    $html.="<td rowspan='100'>";
                    $html.=displayMaxMarking($markerList,$markerMaxList);
                    $html.=displayProjectCounts($proposalFile,$proposals_link,$markerList);
                    $html.="</td>";
                }
                $html.="</tr>";
                $studentCount++;
       }
       while ($studentCount++<102)
       {
            $html.="<tr><td colspan='4'>&nbsp;</td></tr>";
       }
       $html.="</table><input type='submit' name='saveMarkingSetup' value='&nbsp;&nbsp;&nbsp;&nbsp;Save Marking Setup&nbsp;&nbsp;&nbsp;&nbsp;'/>";
       $html.="\n<input type='text' name='previousTypeOrder' readonly value='$typeOrder'/>";
       $html.="\n<input type='text' name='sessionStamp' readonly value='$sessionStamp'/>";
       
       // This will create the hidden place holders for totals.
       $html.=addHiddenMarkingCounts($markerList,$proposalFile);

       $html.="</table><textarea cols=100 rows=100 name='countSupSM' ></form></body></html>";
       echo $html;
    } else include "markingSetupList.inc";

?>
