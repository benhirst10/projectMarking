<?php
    include "markingSchemeDB.inc";
    include "markingSchemeFunctions.inc";
    error_reporting(0); 
    echo "<html><form name='markingSchemeSave' action='$progressSpreadsheet' method='post'>";
    echo "<input type='submit' name='back' value='Return to Progress Spreadsheet'/>";
    echo "Old marking scheme is numbered $fileno<br/>";
    $markingScheme="../config/xml/markingScheme.xml";
    $doc = new DOMDocument;
    $doc->Load($markingScheme);
    $xpath = new DOMXPath($doc);    
    // The following will check the newly created marking scheme against marking scheme schema.
    if (!$doc->schemaValidate('markingScheme.xsd')) {

            print "Invalid markingScheme.xml\n";
        $markingSchemeOK=true;
        die();

    } else  
    { 
        $changed=false;
        if (!empty($fileno))
        {
            $docPrevious = new DOMDocument;
            $previousMarkingScheme=$markingSchemeDirectory."../../common/generated/xml/markingScheme$fileno.xml";
            $docPrevious->Load($previousMarkingScheme);     
            $xpathPrevious = new DOMXPath($docPrevious);
            $query = "//assessment";    
            $previousAssessments = $xpathPrevious->query($query);
            foreach ($previousAssessments as $pa) 
            {   
                $assessment=$pa->getAttribute('id');
                echo "<br/>Checking previous assessment called <b>$assessment</b> to see if found in new assessments.<br/>";
                $queryPrevious = "//assessment[@id=\"$assessment\"]";
                $found = $xpathPrevious->query($queryPrevious)->length;
                if ($found>0) 
                {
                    echo "-&gt;Found matching assessment.<br/>Checking if weighting is different for <b>$assessment.</b><br/>";
                    $matchingAssessmentsPrevious= $xpathPrevious->query($queryPrevious);
                    $weightingPrevious=0;
                    foreach ($matchingAssessmentsPrevious as $map) $weightingPrevious=$map->getAttribute('weighting');
                    if ($weightingPrevious>0) $query = "//assessment[@id=\"$assessment\" and @weighting=\"$weightingPrevious\"]";
                    else $query = "//assessment[@id=\"$assessment\" and @weighting]";
                    $foundNew = $xpath->query($query)->length;
                    echo $query."<br/>";
                    if ($weightingPrevious==0 && $foundNew==0){$changedAssTransfer=false;echo "-&gt;Both assessments do not have weighting.</br>";}
                    if ($weightingPrevious==0 && $foundNew>0) {$changedAssTransfer=false;echo "<b>-&gt;New assessment version has now a weighting.</b></br>";}
                    if ($weightingPrevious>0 && $foundNew==0) {$changedAssTransfer=true;echo "<b>-&gt;New assessment version has a different weighting.</b></br>";}
                    if ($weightingPrevious>0 && $foundNew==1) {$changedAssTransfer=false;echo "-&gt;Both assessments have same weighting.</br>";}
                    echo "Checking if assessment components both exist in new and old.<br/>";
                    $queryPrevious = "//assessment[@id=\"$assessment\"]/component"; 
                    echo $queryPrevious."<br/>";
                    $matchingAssessmentComponentsPrevious= $xpathPrevious->query($queryPrevious);
                    // This will go through assessment components found in the previous marking scheme and see if there are any differences.
                    foreach ($matchingAssessmentComponentsPrevious as $macp) 
                    {   
                        $componentIdPrevious=$macp->getAttribute('id');
                        $query = "//assessment[@id=\"$assessment\"]/component[@id=\"$componentIdPrevious\"]";
                        $found = $xpath->query($query)->length;
                        // This will see if the previous component is found in the new marking scheme.
                        if ($found>0) 
                        {
                            echo "-&gt;Both previous and new have assessment component called <b>".$componentIdPrevious.".</b><br/>";   
                            echo "Checking if weighting is different in assessment component called <b>".$componentIdPrevious.".</b><br/>"; 
                            $weightingComponentPrevious=0;
                            $weightingComponentPrevious= $macp->getAttribute('weighting');
                            if ($weightingComponentPrevious>0) $query = "//assessment[@id=\"$assessment\"]/component[@id=\"$componentIdPrevious\" and @weighting=\"$weightingComponentPrevious\"]";
                            else $query = "//assessment[@id=\"$assessment\"]/component[@id=\"$componentIdPrevious\" and @weighting]";
                            $foundNew = $xpath->query($query)->length;
                            echo $query."<br/>";
                            if ($weightingComponentPrevious==0 && $foundNew==0){$changedTransfer=false;echo "-&gt;Both components do not have weighting.</br>";}
                            if ($weightingComponentPrevious==0 && $foundNew>0) {$changedTransfer=false;echo "-&gt;New component version has now a weighting.</br>";}
                            if ($weightingComponentPrevious>0 && $foundNew==0) {$changedTransfer=true;echo "-&gt;New component version has a different weighting.</br>";}
                            if ($weightingComponentPrevious>0 && $foundNew==1) {$changedTransfer=false;echo "-&gt;Both components have same weighting.</br>";}
                        } else
                        {
                           echo "-&gt;Transfering reference to old assessment component into assessment component changes table<br/>";
                           $changedTransfer=true;   
                        }
                        if ($changedTransfer)
                        {
                        // Saves reference that is no longer available in the new system.
                            $assessmentToSave = array($componentIdPrevious,$assessment,$fileno,$weightingPrevious);
                            $changedAssessmentComponentQuery = 'INSERT INTO assessmentComponentChanged (id,assessmentId,fileno,weighting) VALUES (?,?,?)';
                            $statement = $markingSchemeMdb2->prepare($changedAssessmentComponentQuery);
                            $statement->execute($assessmentToSave);
                            $changed=true;
                        }
                    }
                }
                else 
                {
                    echo "-&gt;Transfering reference to old assessment into assessment changes table<br/>";
                    $changedAssTransfer=true;
                }
                if ($changedAssTransfer)
                {
                    // adds details of assessments that no longer exist in new marking scheme but existed in previous marking scheme.
                    $assessmentToSave = array($assessid,$fileno,$weightingPrevious);
                    $changedAssessmentQuery = 'INSERT INTO assessmentChanged (id,fileno,weighting) VALUES (?,?,?)';
                    $statement = $markingSchemeMdb2->prepare($changedAssessmentQuery);
                    $statement->execute($assessmentToSave);
                    $changed=true;
                }
            }   
            $saveMarkingScheme=false;
        }
        if ($changed)
        {
            // This will delete items in tables to ensure that newly created marking items are noted.
            echo "<h3>Please note that changes have occured with new marking scheme wich may affect marks saved for students.</h3>";
            echo "To change to a previous of markingScheme&lt;number&gt;.xml change version.xml to the correct file.";
            
            $markingSchemeQuery = $markingSchemeMdb2->query("DELETE FROM assessment");
            $markingSchemeQuery = $markingSchemeMdb2->query("DELETE FROM assessmentComponent");
            $saveMarkingScheme=true;

        } 
        
        if (!empty($_POST["weightingComponent"])) $weighting=$_POST["weightingComponent"];
        if (!empty($_POST["weightingAssessment"])) $weightingAssessment=$_POST["weightingAssessment"];
        if (!empty($_POST["outof"])) $outof=$_POST["outof"];
        if (empty($fileno)) 
        { 
            // This will create the first marking scheme generated reference.
            $saveMarkingScheme=true;
            $markingSchemeQuery = $markingSchemeMdb2->query("INSERT INTO markingScheme (fileno) VALUES ('1')");
            $fileno=1;
        }  else $fileno++;

        if ($saveMarkingScheme)
        {   

            echo "<html><h3>Setting up new marking scheme</h3>";
            if (isset($weightingAssessment)) while (list($assessid,$weight) = each($weightingAssessment))
            {
                $assessmentToSave = array($assessid, $weight);
                $newAssessmentQuery = 'INSERT INTO assessment (id, weighting) VALUES (?, ?)';
                $statement = $markingSchemeMdb2->prepare($newAssessmentQuery);
                $statement->execute($assessmentToSave);
                // This will save the associated weightings of the new marking scheme assessments
                echo "<br/><b>Saving assessment:</b> $assessid <b>Weighting:</b> $weight";
            
            }
                if (isset($weightingComponent)) while (list($assessid,$compids) = each($weightingComponent))
                while (list($compid,$weight) = each($compids)) 
                {
                    $assessmentComponentToSave = array($compid,$assessid,$weight,findOutOf($assessid,$compid,$markingScheme));
                    $newAssessmentComponentQuery = 'INSERT INTO assessmentComponent (id,assessmentId,outof,weighting) VALUES (?,?,?,?)';
                    // This will save the associated weightings of the new marking scheme assessment components
                    $statement = $markingSchemeMdb2->prepare($newAssessmentComponentQuery);
                    $statement->execute($assessmentComponentToSave);
                    echo "<br/><b>Saving assessment component. Assessment:</b> $assessid <b>Component:</b> $compid <b>Weighting:</b> $weight";
                    echo " <b>Out of:</b> ".findOutOf($assessid,$compid,$markingScheme);
            }           
        }


        $markschemeFileName=$markingSchemeDirectory."../../common/generated/xml/markingScheme$fileno.xml";
        file_put_contents($markschemeFileName, $doc->saveXML());
        
        // The following will create a new file that gives details of what version has been saved and the links to various proposals files. It also has a link to the svn repository in use.
        
        $dom = new DOMDocument('1.0','UTF-8');
        $dom->formatOutput = true;
        $root = $dom->createElement ("markingScheme");
        $root = $dom->appendChild ($root);
        $version = $dom->createElement ("version");
        $version = $root->appendChild ($version);
        $attr_p = $dom->createAttribute ('file');
        $version->setAttribute('file', $markschemeFileName);
        $attr_p = $dom->createAttribute ('dateCreated');
        $today = date("Y-m-d");    
        $version->setAttribute('dateCreated', $today);  
        $attr_p = $dom->createAttribute ('fileno');
        $version->setAttribute('fileno', $fileno);      
        
        $attr_p = $dom->createAttribute ('student_type');
        $version->setAttribute('student_type',$student_type);       
        
        $attr_p = $dom->createAttribute ('student_proposals_link');
        $version->setAttribute('student_proposals_link',$student_proposals_link);
        
        $attr_p = $dom->createAttribute ('proposals_link');
        $version->setAttribute('proposals_link',$proposals_link);
        
        $attr_p = $dom->createAttribute ('repository');
        $version->setAttribute('repository',$svn_repos);                
        $dom->save("../../common/config/xml/version.xml");
    }
    // do a revert marking scheme and save this with the latest number
        echo "<input type='submit' name='back' value='Return to Progress Spreadsheet'/></form></html>";
        
?>
