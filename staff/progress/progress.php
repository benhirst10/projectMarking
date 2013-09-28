<?php
    error_reporting(1); 
    $configPath="../config/xml/";
    include "../../common/php/progressDB.inc";
    include "../../common/php/progressFunctions.inc";
    $markersXML='../../common/generated/xml/markers.xml';
    if (!empty($_GET["uid"])) $uid=$_GET["uid"]; else $uid="";
    if (!empty($_GET["assessment"])) $assessment=$_GET["assessment"]; else $assessment="";
    if (!empty($_POST["markerSelected"]) && $_POST["markerSelected"]!="Select Choice" ) $markerSelected=$_POST["markerSelected"]; 
    else 
    {
        if ($_POST["markerSelected"]!="Select Choice") $markerSelected=$_SERVER["PHP_AUTH_USER"];
        if (($convenor && markerName($markerSelected,$markerList)=="") || !empty($_GET["showAllStudents"])) $markerSelected="";
    }
    if (!empty($_POST["secondMarkerSelected"]) && $_POST["secondMarkerSelected"]!="Select Choice" ) $secondMarkerSelected=$_POST["secondMarkerSelected"]; else $secondMarkerSelected="";
    if (!empty($_GET["markerChosen"])) $markerChosen=$_GET["uid"]; else $markerChosen="";   
    if (!empty($_GET["markerSelected"])) $markerSelected=$_GET["markerSelected"]; 
    if (!empty($_GET["secondMarkerSelected"])) $secondMarkerSelected=$_GET["secondMarkerSelected"];
    if (!empty($_GET["docxreports"])) $docxreports=$_GET["docxreports"]; else $docxreports="";
    if (!empty($_GET["sortSpread"])) $sortSpread=$_GET["sortSpread"]; else $sortSpread="";
    if (!empty($_POST["saveFeedback"])) include "progressSaveMarks.inc";
    if (!empty($_POST["makeAvailableMarks"])) saveReleaseDetails($uid,$_POST["studentAssessments"],$progressMarkingScheme,$progressMdb2);
    if (!empty($docxreports) && empty($_POST["makeAvailableMarks"])) include "progressDocx.inc";
    $supervisorHtml="";
    if (empty($uid) && !checkGroupAssessed($progressMarkingScheme))
    {
        $xsltProc = new XSLTProcessor();
        $xsltProc->importStylesheet( DOMDocument::load('markersSupSM.xslt') );  
        $xsltProc->setParameter('','markerSelected',$markerSelected); 
        $xsltProc->setParameter('','menuChoice','supervisor'); 
        $supervisorHtml = "Supervisor: ". $xsltProc->transformToXML( DOMDocument::load($markersXML) );
        
        $xsltProc->setParameter('','markerSelected',$secondMarkerSelected);     
        $xsltProc->setParameter('','menuChoice','secondMarker');
        $supervisorHtml.= "Second Marker: ".$xsltProc->transformToXML( DOMDocument::load($markersXML) );
    }
    // GROUP FORMATION: Within the displaySpreadsheet function the collection of marks that are attributed to a group which is derived from the same table which contains students. 
    // In this case a specially formed user id that will form the basis of group users will be dealt with in a according fashion. This will be in terms of making sure that only
    // group attributed marks account for the total.
    
    $spreadsheet=displaySpreadsheet($uid,$assessment,$moduleList,$markingSetup,$proposal,$markerSelected,$secondMarkerSelected,$progressMarkingScheme,"progress.php",$progressMdb2,$proposals_link,$progressMarkingScheme,$svn_repos,$docxreports,$sortSpread,"",$markerList,$convenor);
    header("Cache-Control: no-cache, must-revalidate");
    header('Content-Type: text/html; charset=utf-8'); 
    if (!empty($uid)) {$uidTitle="($uid)"; $assessmentTitle=$assessment." -";} else {$uidTitle="";$assessmentTitle="Spreadsheet -" ;}
    $html = "<html><head><title>$uidTitle $assessmentTitle Student Progress</title></head> ";
    $html.=css()."<table class='heading'>\n<tr>\n\n<td>";
    if (empty($progressMarkingScheme) || $convenor) 
    {
            $html.="<a href='$markingSchemeSetupAssessments' target='_blank'>Setup assessments using markingScheme.xml</a>&nbsp;&nbsp;&nbsp;<a href='$markingSetupLink'  target='_blank'>Setup marking and project list</a>";
    }     
    if (!empty($assessment) && !empty($uid)) $html.=headerJavaScript();
    if (!empty($assessment) && !empty($uid)) $html.="\n<form name='progress' action='progress.php?assessment=$assessment&uid=$uid&docxreports=$docxreports&sortSpread=$sortSpread' method='post' onSubmit=\"return addUpMarkBoxes();\">";
    else $html.="\n<form name='progress' action='progress.php?assessment=$assessment&uid=$uid&docxreports=$docxreports&sortSpread=$sortSpread' method='post' \">";
     
    $html.=$supervisorHtml;
    if (empty($uid)) $html.="<input type='submit' name='showMarkerList' value='Show Marker List'/>";
    $html.=$spreadsheet;
    if (!empty($uid) && !empty($assessment))
    {
      $doc = new DOMDocument;
      $doc->preserveWhiteSpace = false;
      $doc->Load($progressMarkingScheme);
      $xpath = new DOMXPath($doc);
      $query = "//assessment[@id=\"$assessment\"]/component";    
      $entries = $xpath->query($query);
      $compNo=0;
      foreach ($entries as $entry) 
      {
            $comp=$entry->getAttribute('id');
            $compNo++;
            $componentid[$compNo]=$comp;
            $componentVal[$compNo]="";
            $numericVal[$compNo]=0;
            $choiceVal[$compNo]="";
            $outOf=findOutOf($assessment,$comp,$progressMarkingScheme);
            if (empty($foundOutOf) && $outOf>0) $foundOutOf=true;

            $types = array("text","text","text");
            // This will find the mark for the assessment component for a particular assessment and student.
            $statement = $progressMdb2->prepare("SELECT feedback,mark,type,componentId FROM assessmentComponentMarks WHERE uid =? and assessmentId = ? and componentId = ? ", $types, MDB2_PREPARE_RESULT);
            $data = array($uid,$assessment,$comp);
            $assessmentComponentMarksQuery = $statement->execute($data);
            if (PEAR::isError($assessmentComponentMarksQuery)) print "Error in quering outof: ".$assessmentComponentMarksQuery;   
                while ($marks = $assessmentComponentMarksQuery->fetchRow(MDB2_FETCHMODE_ORDERED)) 
                {
                        if ($marks[2]=="feedback") 
                        {
                            $componentVal[$compNo]=$marks[0];
                //echo "<pre>$componentVal[$compNo]</pre>/n";
                            $numericVal[$compNo]=$marks[1]*$outOf;
                        }
                        if ($marks[2]=="choice")   $choiceVal[$compNo]=$marks[0];
                    }           

       }

       $maxComponents=$compNo;
       $html.="\n<table border='0' class='heading'>
          \n<tr class='heading2'><td colspan='3' align='center'><input type='submit' name='saveFeedback' value='&nbsp;&nbsp;&nbsp;&nbsp;Save&nbsp;&nbsp;&nbsp;&nbsp;'/>&nbsp;&nbsp;</td>\n</tr>\n"; 
       $html.="\n<tr class='heading2'><td colspan='3'><textarea name='markstotal1' rows=1 cols=100 readonly class='heading2' style='border:0;overflow:hidden;'></textarea>";
       $html.="<textarea name='tmarks' cols=6 readonly  class='heading2' style='border:0;overflow:hidden;'>Total:</textarea><textarea name='totalmarks1' cols=10 readonly class='heading2' style='border:0;overflow:hidden;'></textarea>\n</td>\n</tr>";

           
       $xsltProc = new XSLTProcessor();
       $xsltProc->substituteEntities = true;
       $xsltProc->importStylesheet( DOMDocument::load('../../common/xslt/markingScheme.xslt') );    
       $xsltProc->setParameter('','componentid',''); 
       $xsltProc->setParameter('','componentVal',''); 
       $xsltProc->setParameter('','numericVal','');        
       $xsltProc->setParameter('','assid',$assessment);
       $xsltProc->setParameter('','entryReport','entry');
       
       $html .= $xsltProc->transformToXML( DOMDocument::load($progressMarkingScheme) );
       $cnt=1;
       while($cnt<=$maxComponents)
       {        
           $xsltProc->setParameter('','componentid',$componentid[$cnt]);   
           $xsltProc->setParameter('','componentVal',$componentVal[$cnt]);  
           $xsltProc->setParameter('','choiceVal',$choiceVal[$cnt]);
           $xsltProc->setParameter('','entryReport','entry');
           if (isset($numericVal[$cnt])) $xsltProc->setParameter('','numericVal',$numericVal[$cnt]);
           
           // GROUP FORMATION: A derived parameter that ensures group functionality is set. This should ensure that the appropriate filtering of marker and component.
           // A notification of group items should be apparent when their are no student details.
           
           $feedback = $xsltProc->transformToXML( DOMDocument::load($progressMarkingScheme) );
        // added following line to decode special characters so that they appear as normal. This is done after xslt transform.
       $html .= htmlspecialchars_decode($feedback,ENT_QUOTES);
           $cnt++;
       }    
    
       $modcode="CO7210 1st Semester";
       $html.="<tr class='heading2'><td colspan='3' valign=top><textarea name='markstotal2' rows=1 cols=100 readonly class='heading2' style='border:0;overflow:hidden;'></textarea>";
       $html.="<textarea name='tmarks' cols=6 readonly  class='heading2' style='border:0;overflow:hidden;'>Total:</textarea><textarea name='totalmarks2' cols=5 readonly  class='heading2' style='border:0;overflow:hidden;'></textarea>";
       $html.=" <tr>\n<td colspan='3' align='center'><input type='submit' name='saveFeedback' value='&nbsp;&nbsp;&nbsp;&nbsp;Save&nbsp;&nbsp;&nbsp;&nbsp;'/></td>\n</tr>\n  
               </table>";
    } 
    $html.="</form>\n</body>\n</td>\n</tr>\n</table>\n</html>";
     echo $html;
    

?>
