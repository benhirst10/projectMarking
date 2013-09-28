<?php
    if ($_POST["typeOrder"]=="supervisor") $studentList="../../common/generated/xml/studentlistSup$sessionStamp.xml"; 
    if ($_POST["typeOrder"]=="secondmarker") $studentList="../../common/generated/xml/studentlistSM$sessionStamp.xml";
    if ($_POST["typeOrder"]=="project") $studentList="../../common/generated/xml/studentlistProject$sessionStamp.xml";
    
    
    $html = "<html>";
    $html.="\n<head><title>Project Allocations</title></head>\n<body>\n";
    $html.="\n<table border='1'>\n<tr><th>Student </th>";
    $html.="\n<th>Supervisor</th>";
    $html.="\n<th>2nd Marker</th>";
    $html.="\n<th>Project</th></tr>";
    
    $dom=new DOMDocument();
    $dom->load($studentList);
    $studentXpath = new DOMXPath($dom);
    $queryStudents = "//student";
    $students=$studentXpath->query($queryStudents);
    
    $studentChoicesDom=new DOMDocument();    
    $studentChoicesDom->load($studentChoices);
    $studentChoicesXpath = new DOMXPath($studentChoicesDom);
             
    $studentCount=1;
    // This will go through a list of students.
    foreach($students as $stTag)
    {

            $stuid=$stTag->getAttribute('uid');
            $surname=$stTag->getAttribute('surname');
            $forenames=$stTag->getAttribute('forenames');
            $candidate_number=$stTag->getAttribute('candidate_number');
            $degreecode=$stTag->getAttribute('degreecode');
            $html.= "<tr><td>$surname, $forenames ($degreecode, $stuid)</td>";
            if ($profilesNo>0)
            {
               $degreecode=findDegreeCodeAbreviation($degreeAbreviationsFile,$degreecode);
               // This will find the abreviated degree code that is used for students.
            } else $degreecode="";
            $supervisor="";
            $sndMarker="";
            $projectChoice="";
            if (file_exists($markingSetupFile))
            {
                $dom3=new DOMDocument();
                $dom3->load($markingSetupFile);
                $markingXpath = new DOMXPath($dom3);
                $queryMarking= "//supervisors/supervision[@student='$stuid']";
                // This will find the information about the marker.
                $markings=$markingXpath->query($queryMarking);
                foreach ($markings as $mks)
                {
                    $supervisor=$mks->getAttribute('supervisor');
                    $sndMarker=$mks->getAttribute('secondmarker');
                    $projectChoice=$mks->getAttribute('project');
                }
            }
            // This will obtain a list of project preferences.
            if (!empty($_POST["allPref"])) $projectPreferences=displayPreferences($studentChoices,$studentChoicesDom,$proposals_link,$stuid); else $projectPreferences="";
            
            $notSaved="";
            if ($projectChoice=="Select Choice" || empty($projectChoice))
            {
                $projectChoice=findPreferenceChosen($studentChoicesXpath,$_POST["prefDisplay"],$stuid);
                if ($projectChoice!="Select Choice") $notSaved="(Not Saved)";

            }       
            if (markerName($supervisor,$markerList)!="") $html.= "\n<td>".markerName($supervisor,$markerList)."</td>";
            else  $html.= "\n<td $colspan>Not allocated</td>";
            if (markerName($sndMarker,$markerList)!="")  $html.= "\n<td>".markerName($sndMarker,$markerList)."</td>";
            else  $html.= "\n<td $colspan>Not allocated</td>";
            if (!empty($projectChoice) && $projectChoice!="Own Project") $html.= "\n<td $colspan>$projectPreferences". getProposalTitle($projectChoice,$proposalFile,$proposals_link,$markerList)." $notSaved</td>";
            else if ($projectChoice!="Own Project") $html.= "\n<td $colspan>$projectPreferences Not allocated</td>";
            if ($projectChoice=="Own Project") $html.= "\n<td $colspan>$projectPreferences$projectChoice</td>";
    }
    // This will display the contents of list box.
    $html.="</table><h3>Staff Allocated</h3><p>(Warning: This is based on previous page which may not be saved. Use the back button on browser and then press save.)</p>".str_replace(" ","<br/>",htmlspecialchars($_POST["countSupSM"]))."</body></html>";
    
    echo $html;


?>
