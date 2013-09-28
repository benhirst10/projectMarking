<?php
        include "../../common/php/projectPreferencesFunctions.inc";
        include "../../common/php/markingSetupFunctions.inc";
        include "../../common/php/projectPreferencesDB.inc";
        $preferencePageSetup="../../common/config/xml/preferencePage.xml";
        checkFileExists($preferencePageSetup,"preference page setup file");
        checkFileExists($proposalFile,"proposal file"); 
        if (!file_exists($projectsDegreeRestrictions)) $profilesNo=createListOfDegreeProjects($proposalFile);
        else  $profilesNo=degreeRestrictions($proposalFile);
        $dom=new DOMDocument();
        $dom->load($preferencePageSetup);
        $prefPXpath = new DOMXPath($dom);
        $queryPrefP= "//closePage";
        $prefP=$prefPXpath->query($queryPrefP);
        foreach($prefP as $pp) {$dateClose=$pp->getAttribute('dateClose'); $timeClose=$pp->getAttribute('time');}
        $query= "//studentWebPageLink";
        $linkResources=$prefPXpath->query($query);
        foreach($linkResources as $lr) $studentWebPageLink=$lr->getAttribute('link');
        header('Content-Type: text/html; charset=utf-8'); 
        $todays_date = date("Y-m-d h:i:s"); 
        $dateA = "$dateClose $timeClose"; 
        $dateB = $todays_date;
        if((strtotime($dateA) > strtotime($dateB)) || $byPassDeadline)
        { 
           $sameChoices=""; 
           if (!empty($_POST["Save"])) 
                        $sameChoices=savePreferences($stuid,$_POST["colfirstchoice"],$_POST["colsecondchoice"],$_POST["colthirdchoice"],$_POST["colfourthchoice"],$projectPreferencesMdb2,$preferencePageSetup,$proposalFile,$markerList);
           $html.=headerJavaScript();
           $html.="<body><h1>Project Preference Page</h1><p>Please save your preferences before <b>$dateClose $timeClose.</b> To ensure that you have properly <b>saved</b> your preferences, <b>a list should appear at the top of the page</b> showing your preferences. To <b>select preferences</b>, click on four different project preference radio buttons and then press the save button. It is possible to re-save different preferences before the deadline.</p>";
               if (!empty($studentWebPageLink)) $html.="<p>After you have saved your preferences you might wish to <a href='$studentWebPageLink'>click here</a> to return to the module web page.</p>";
           $html.="\n<TABLE SUMMARY='Projects Setup' border='1' width='100%'>

                   <thead>
                   <COLGROUP>
                   <col width='60%'>
                   <col width='10%'>
                   <col width='10%'>
                   <col width='10%'>
                   <col width='10%'>
                   </colgroup>
                   </thead>

                   <tbody>


                   <form  name='projectform' method='post' onSubmit='return checkformradio( );'>
               <tr><td colspan='5' align=center><INPUT type='submit' value='Save' name='Save' size='20'></td></tr>";

               $doc = new DOMDocument;
               $doc->preserveWhiteSpace = false;
               $doc->Load($versionFile);
               $xpath = new DOMXPath($doc);
               $query = "//version";
               $entries = $xpath->query($query);
               foreach ($entries as $version)
               {
                   $student_proposals_link=$version->getAttribute('student_proposals_link');
               }
           
               $dom=new DOMDocument();
               $dom->load($studentList);
               $studentXpath = new DOMXPath($dom);
               $queryStudents = "//student[@uid='$stuid']";
               $students=$studentXpath->query($queryStudents);
               if ($studentXpath->query($queryStudents)->length==0) $html.="<h3>You are not registered to use the preference page on this module.</h3>";
               if (!$sameChoices) $html.=displayPrefSaved($stuid,$projectPreferencesMdb2,$proposalFile,$markerList,$student_proposals_link);
                else 
                $html.="<hl> PLEASE NOTE: Unable to save choices as you have chosen too many preferences with an individual supervisor!!!!!! Maximum projects per staff is: ".findLimitChoiceNo($preferencePageSetup).".</h1>";
               $cnt=1;
           
               $dom = new DOMDocument;
               $dom->preserveWhiteSpace = false;
               $dom->Load($degreeAbreviationsFile);
               $degreeAbreviationsXpath = new DOMXPath($dom);              
             // This will obtain details of the one student.
               foreach($students as $stTag)
               {

                   $stuid=$stTag->getAttribute('uid');
                   $surname=$stTag->getAttribute('surname');
                   $forenames=$stTag->getAttribute('forenames');
                   $candidate_number=$stTag->getAttribute('candidate_number');
                   $degreecode=$stTag->getAttribute('degreecode');

                   $domProp=new DOMDocument();
                   $domProp->load($proposalFile);
                   $propXpath = new DOMXPath($domProp);
                   $queryProjects="//project";
                   $proposals=$propXpath->query($queryProjects);
                   $html.="<tr><td align=center colspan=5>$surname, $forenames ($stuid)</td></tr>";
                   if ($cnt==1) $html.="<tr><td align=center>Project</td><td align=center>Preference 1</td><td align=center>Preference 2</td><td align=center>Preference 3</td><td align=center>Preference 4</td></tr>";
                   $cnt++;
                   $degreecode=findDegreeCodeAbreviation($degreeAbreviationsXpath,$degreecode);     
                   // This will find the proposals that are specific to the degreecode.
                   
                   foreach($proposals as $prop)
                   {
                        $label=$prop->getAttribute('label');
                        $hiddenProp=hiddenProject($label,$proposalFile);
                        if ($profilesNo>0)
                        {
                            $domPropR=new DOMDocument();
                            $domPropR->load($projectsDegreeRestrictions);
                            $propRXpath = new DOMXPath($domPropR);
                            $proposalsR=$propRXpath->query($queryProjects)->length;
                            if ($degreecode<>"_all_") $query2="//project[@label=\"$label\"]/degree[@id=\"$degreecode\"]";
                            else $query2="//project[@label=\"$label\"]/degree";
                            $proposalsR=$propRXpath->query($query2)->length;
                            if ($proposalsR==0) $label="";
                        }   
                        if (!empty($_POST["colfirstchoice"])) $colfirstchoice=$_POST["colfirstchoice"]; else $colfirstchoice="";
                        if (!empty($_POST["colsecondchoice"])) $colsecondchoice=$_POST["colsecondchoice"]; else $colsecondchoice="";
                        if (!empty($_POST["colthirdchoice"])) $colthirdchoice=$_POST["colthirdchoice"]; else $colthirdchoice="";
                        if (!empty($_POST["colfourthchoice"])) $colfourthchoice=$_POST["colfourthchoice"]; else $colfourthchoice="";
                        if (empty($hiddenProp) && !empty($label))         
                            $html.="\n".displayPreferenceChoices($stuid,$label,true,$proposalFile,$markerList,$projectPreferencesMdb2,$student_proposals_link,$colfirstchoice,$colsecondchoice,$colthirdchoice,$colfourthchoice,$sameChoices);
                        }
               }
               $html.="<tr><td colspan=5 align=center><INPUT type='submit' value='Save' name='Save' size='20'></td></tr></form></tbody></table></body></html>";
        } else $html.="<h3>Project preference page is closed. Please email your module convenor.</h3>";

    
        echo $html;
?>
