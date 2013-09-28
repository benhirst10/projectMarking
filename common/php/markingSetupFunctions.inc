<?php

function css()
{

    return  $html="
        <style>
             .heading {
                 font-size: 15px;
                font-family: Verdana, Arial, Helvetica, Swiss, 'Arial MT', Franklin, 'Humanist 777', sans-serif;
                 background-color:#B0C4DE;
                color: black;
                }
                 .heading2 {
                 font-size: 15px;
                font-family: Verdana, Arial, Helvetica, Swiss, 'Arial MT', Franklin, 'Humanist 777', sans-serif;
                 background-color:#B0C4DE;
                color: black;
                }       
                 .heading3 {
                 font-size: 15px;
                font-family: Verdana, Arial, Helvetica, Swiss, 'Arial MT', Franklin, 'Humanist 777', sans-serif;
                 background-color:#B0C4DE;
                color:black;
                }
            
              .heading4 {
                 font-size: 15px;
                font-family: Verdana, Arial, Helvetica, Swiss, 'Arial MT', Franklin, 'Humanist 777', sans-serif;
                 background-color:#62A0E3;
                color: white;
                }
            
             .heading5 {
                 font-size: 15px;
                font-family: Verdana, Arial, Helvetica, Swiss, 'Arial MT', Franklin, 'Humanist 777', sans-serif;
                 background-color:#62A0E3;
                color:black;
                }                       
   
            .selectBox {
                  margin: 0;
                  background-color: #FFEC8B;
                  color: black;
                  line-height: normal;
                  white-space: nowrap;
                  word-wrap: normal;
                  text-align: start; 
                  cursor: default;
                  border-width: 2px;
                  border-style: inset;
                  text-indent: 0;
                  text-shadow: none;
            }

             
               .bkgr {font-style: bold;font-weight: bold;
                font-family: Verdana, Arial, Helvetica, Swiss, 'Arial MT', Franklin, 'Humanist 777', sans-serif;
                font-size: 10px;

                background-color:white; color:black ;
                padding-left: 0.5em}            
            
            a:link {color: yellow;}
            a:visited {color:  white;}
            a:active {color: #00FF00;}
            a:hover {background-color: green;}
            a {text-decoration: none;}
            
            .boxes {background-color:#FFEC8B; color: black;  font-style: bold;font-weight: bold; font-size: 15px;}      

            
    </style>";

}
    function headerJavaScriptMarkingSetup()
    {
    
        return $html=" <script language=\"javascript\" type=\"text/javascript\">
        function countSupervisorSecondMarker() 
        {
            var returnVal=true;  
            var hiddenStart=0;
            var selectStart=0;
            for (i=0;i<document.markingSetup.length;i++)
            {
               var tempobj=document.markingSetup.elements[i];
               if (tempobj.type==\"hidden\")
               {
                   tempobj.value=0;
           
                   if (tempobj.name.substr(0,5)==\"proj[\")
                   {
                         document.markingSetup.elements[i].value=0;
                   }    
                   if (hiddenStart==0) hiddenStart=i;
            }
            if (tempobj.type==\"select-one\" && selectStart==0) selectStart=i;
            if (tempobj.type==\"textarea\") document.markingSetup.elements[i].value=\"\";
        
        
        }
        var smNoneAlloc=0;
        var supNoneAlloc=0;
        var smTotalAlloc=0;
        var supTotalAlloc=0;    
        var studentCount=0;
        for (i=selectStart;i<hiddenStart+1;i++)
        {
            var tempobj=document.markingSetup.elements[i];
            var tempobj2=document.markingSetup.elements[i+1];
            var tempobj3=document.markingSetup.elements[i+2];
            if (tempobj.name.substr(0,14)==\"markerSelected\") ++studentCount;
            if (tempobj.type==\"select-one\" && tempobj.options[tempobj.selectedIndex].value!=\"Select Choice\")
            {
              var supervisor = tempobj.options[tempobj.selectedIndex].value;
              var secondmarkerID = \"\";
              if (supervisor!=\"\" && document.markingSetup.elements[supervisor]!=undefined)
              {
                     document.markingSetup.elements[supervisor].value++;
                 smNoneAlloc++;
              } 
//            alert(supervisor);
           
             if (tempobj2.type==\"select-one\" && tempobj2.options[tempobj2.selectedIndex].value!=\"Select Choice\")
             {
                  var secondmarker = \"sm_\"+tempobj2.options[tempobj2.selectedIndex].value;
                  secondmarkerID=tempobj2.options[tempobj2.selectedIndex].value;
                  if (secondmarker!=\"sm_\" && document.markingSetup.elements[secondmarker]!=undefined)
                  {
                         document.markingSetup.elements[secondmarker].value++;
                     supNoneAlloc++;
                  }
                     
              }
             if (tempobj3.type==\"select-one\" && tempobj3.options[tempobj3.selectedIndex].value!=\"Select Choice\")
             {
               var supervisorproj=\"proj[\"+supervisor+\"][\"+tempobj3.options[tempobj3.selectedIndex].value+\"]\";
               var secondmarkerproj=\"proj[\"+secondmarkerID+\"][\"+tempobj3.options[tempobj3.selectedIndex].value+\"]\";
              // alert(supproj);
               if (supervisorproj!=\"proj[][]\" && document.markingSetup.elements[supervisorproj]!=undefined)
                document.markingSetup.elements[supervisorproj].value++;
               if (secondmarkerproj!=\"proj[][]\" && document.markingSetup.elements[secondmarkerproj]!=undefined)
                    document.markingSetup.elements[secondmarkerproj].value++;    
               
             }
             i=i+2;
            }
            if (tempobj.type==\"select-one\") {supTotalAlloc++;smTotalAlloc++;}
        }
        supNoneAlloc=supTotalAlloc-supNoneAlloc;    
        smNoneAlloc=smTotalAlloc-smNoneAlloc;
        var message=\"<uid>:<supervisor>:<2nd_Marker> \";
        var cnt=1;
        var oRed = '#ff0000';
        var supervisorCountOver=0;
        var smCountOver=0;
        var supervisorCountUnder=0;
        var supTCount=0;
        var smTCount=0;
        var smCountUnder=0;     

        for (i=hiddenStart;i<document.markingSetup.length;i++)
        {
            var tempobj=document.markingSetup.elements[i];
            if (tempobj.type==\"hidden\")
        {
            if (tempobj.name.substr(0,5)==\"proj[\") 
            {
                var projname=tempobj.name;
                var projname=projname.split(\"[\");
                
                var temp1 = new String(projname[1]);
                temp1=temp1.split(\"]\");
                var markerId=\"\"+temp1[0];
                
                var temp2= new String(projname[2]);
                temp2=temp2.split(\"]\");
                var projid=\"\"+temp2[0];
                
                var projDisp=\"projectDisp[\"+projid+\"]\";
                if (document.markingSetup.elements[projDisp]!=undefined && parseInt(tempobj.value)>0) 
                    document.markingSetup.elements[projDisp].value=document.markingSetup.elements[projDisp].value+markerId+\":\"+tempobj.value+\" \";
            }
        
            if (cnt%2>0 && tempobj.name.substr(0,5)!=\"proj[\") 
            {
                message=message+tempobj.name+\":\"+parseFloat(tempobj.value);
                var supervisor=\"supT[\"+tempobj.name+\"]\";
                var supervisorDisp=\"supDisp[\"+tempobj.name+\"]\";
                if (document.markingSetup.elements[supervisor]!=undefined)
                {
                    if (parseInt(tempobj.value)>parseInt(document.markingSetup.elements[supervisor].value)) 
                    {
                        var needs=parseInt(tempobj.value)-parseInt(document.markingSetup.elements[supervisor].value);
                        message=message+\"(-\"+needs+\"!!)\";
                        document.markingSetup.elements[supervisorDisp].value=\"-\"+needs+\"!!\";
                        supervisorCountOver+=needs;
                        retrunVal=false;
                    }
                    if (parseInt(tempobj.value)<=parseInt(document.markingSetup.elements[supervisor].value))
                    {
                        var needs=parseInt(document.markingSetup.elements[supervisor].value)-parseInt(tempobj.value);
                        message=message+\"(+\"+needs+\")\";
                        if (needs>0) document.markingSetup.elements[supervisorDisp].value=\"+\"+needs;
                        else document.markingSetup.elements[supervisorDisp].value=needs;
                        if (needs>0) supervisorCountUnder+=needs;
                    }
                    supTCount+=parseInt(document.markingSetup.elements[supervisor].value);
                }
                
                
                
            }
            else if (cnt>0 && tempobj.name.substr(0,5)!=\"proj[\") 
            {
                message=message+\":\"+parseFloat(tempobj.value);
                var tempobj2=document.markingSetup.elements[i-1];
                var sm=\"smT[\"+tempobj2.name+\"]\";
                var smDisp=\"smDisp[\"+tempobj2.name+\"]\";
                if (document.markingSetup.elements[sm]!=undefined) 
                {
                    if (parseInt(tempobj.value)>parseInt(document.markingSetup.elements[sm].value))
                    { 
                        var needs=parseInt(tempobj.value)-parseInt(document.markingSetup.elements[sm].value);
                        message=message+\"(-\"+needs+\"!!)\";
                        document.markingSetup.elements[smDisp].value=\"-\"+needs+\"!!\";
                        smCountOver+=needs;
                        
                        returnVal=false;
                    }
                    if (parseInt(tempobj.value)<=parseInt(document.markingSetup.elements[sm].value))
                    {
                        var needs=parseInt(document.markingSetup.elements[sm].value)-parseInt(tempobj.value);
                        message=message+\"(+\"+needs+\")\";
                        if (needs>0) document.markingSetup.elements[smDisp].value=\"+\"+needs;
                        else document.markingSetup.elements[smDisp].value=needs;
                        if (needs>0) smCountUnder+=needs;
                        
                    }
                    smTCount+=parseInt(document.markingSetup.elements[sm].value);
                }
                message=message+\" \";
            }
            cnt++;
            
        }
            
        
        }
        var dispTotalOver=\"\";
        var dispTotalUnder=\"\";
        var dispSupTotalOver=\"\";
        var dispSupTotalUnder=\"\"      
        if (supervisorCountOver>0) dispSupTotalOver=\"(-\"+supervisorCountOver+\")\"; else dispSupTotalOver=\"\";
        if (supervisorCountUnder>0) dispSupTotalUnder=\"(+\"+supervisorCountUnder+\")\"; else dispSupTotalUnder=\"\";
        document.markingSetup.elements[\"supDispTotal\"].value=dispSupTotalOver+\" \"+dispSupTotalUnder;
        if (smCountOver>0) dispTotalOver=\"(-\"+smCountOver+\")\"; else dispTotalOver=\"\";
        if (smCountUnder>0) dispTotalUnder=\"(+\"+smCountUnder+\")\"; else dispTotalUnder=\"\";
        document.markingSetup.elements[\"smDispTotal\"].value=dispTotalOver+dispTotalUnder;
        document.markingSetup.elements[\"supTTotal\"].value=supTCount+\" (Sts:\"+studentCount+\")\";
        document.markingSetup.elements[\"smTTotal\"].value=smTCount+\" (Sts:\"+studentCount+\")\";
        message=message+\"Total:\"+supTCount+dispSupTotalOver+dispSupTotalUnder+\":\"+smTCount+dispTotalOver+dispTotalUnder;
        message=message+\" Students:\"+studentCount;
        document.markingSetup.elements[\"countSupSM\"].value=message;
        return false;       
    }
    
    function checkIfUpToDateList()
    {
        if (document.markingSetup.calculateTotals.checked==false) countSupervisorSecondMarker();    
    
    }
    
    
    </script>";
    
    
    }   

    function saveMarkingSetup($markerList,$markingSetupFile,$markerSelected,$projectChoice,$secondMarkerSelected,$studentList,$proposalFile,$markingSetupMdb2)
    {

            $domBackup=new DOMDocument();
            $domBackup->load($markingSetupFile);
            $time = date("YmdHis");
            $newname="$markingSetupFile.$time";
            // This will save another copy of the marking setup file.
            file_put_contents($newname, $domBackup->saveXML());
            
            $domSave = new DOMDocument('1.0','UTF-8');
            $domSave->formatOutput = true;
            $root = $domSave->createElement ("markingSetup");
            $root = $domSave->appendChild ($root);
            $supervisors = $domSave->createElement ("supervisors");
            $supervisors = $root->appendChild ($supervisors);
            $cnt=1;     
            // This will clear the contents of the markingSetup file.
            $resetMarkingSetupTable=$markingSetupMdb2->exec("DELETE FROM markingSetup");
            $dom=new DOMDocument();
            $dom->load($studentList);
            $studentXpath = new DOMXPath($dom);
            $queryStudents = "//student";
            $students=$studentXpath->query($queryStudents);
            // This will go through all the students in the file and save information about who their first and second supervisor.
            foreach($students as $stTag)
            {
                $uid=$stTag->getAttribute('uid');
                $surname=$stTag->getAttribute('surname');
                $forenames=$stTag->getAttribute('forenames');
                $candidate_number=$stTag->getAttribute('candidate_number');
                $degreecode=$stTag->getAttribute('degreecode');
        
                $supervision = $domSave->createElement ("supervision");
                $supervision = $supervisors->appendChild ($supervision);

                $attr_supervisor = $domSave->createAttribute ('supervisor');
                $attr_supervisor = $supervision->appendChild ($attr_supervisor);
                $supervision->setAttribute('supervisor', $markerSelected[$cnt]);

                $attr_student = $domSave->createAttribute ('student');
                $attr_student = $supervision->appendChild ($attr_student);
                $supervision->setAttribute('student', $uid);
                if ($markerSelected[$cnt]!="Select Choice" || $secondMarkerSelected[$cnt]!="Select Choice") $project=$projectChoice[$cnt]; else $project="";
                // The above line will check to see if a second marker of supervisor has been chosen in order to save project details.
                
                $attr_project = $domSave->createAttribute ('project');
                $attr_project = $supervision->appendChild ($attr_project);
                $supervision->setAttribute('project', htmlentities($project));
    
                $attr_smuid = $domSave->createAttribute ('secondmarker');
                $attr_smuid = $supervision->appendChild ($attr_smuid);
                $supervision->setAttribute('secondmarker', $secondMarkerSelected[$cnt]);
        
                $title="";
                $title=getProposalTitle($projectChoice[$cnt],$proposalFile,"",$markerList); 
                // The above line will get the the title of the proposal so that it can be used to sort entries alphabetically by title in the results.
                
                $markingSetupToSave = array($uid,$surname,$forenames,$markerSelected[$cnt],$secondMarkerSelected[$cnt],$title);
                $markingSetupQuery = 'INSERT INTO markingSetup (uid,surname,forenames,supervisor,secondmarker,project) VALUES (?,?,?,?,?,?)';
                $statement = $markingSetupMdb2->prepare($markingSetupQuery);
                $statement->execute($markingSetupToSave);
                if (PEAR::isError($statement)) print "Error in inserting into marking setup: ".$statement;
                $statement->free(); 
        
                $markingSetupToSave = array($degreecode,$candidate_number,$uid);
                $markingSetupQuery = 'UPDATE markingSetup set degreecode=?,candidate_number=? WHERE uid=?';
                $statement = $markingSetupMdb2->prepare($markingSetupQuery);
                $statement->execute($markingSetupToSave);
                if (PEAR::isError($statement)) print "Error in inserting into marking setup: ".$statement;
                $statement->free();

                $markingSetupToSave = array(markerName($markerSelected[$cnt],$markerList),markerName($secondMarkerSelected[$cnt],$markerList),$uid);
                $markingSetupQuery = 'UPDATE markingSetup set supervisorFullName=?,secondMarkerFullName=? WHERE uid=?';
                $statement = $markingSetupMdb2->prepare($markingSetupQuery);
                $statement->execute($markingSetupToSave);
                if (PEAR::isError($statement)) print "Error in inserting into marking setup: ".$statement;
                $statement->free();
        
                $cnt++;
            }
            $domSave->save($markingSetupFile);
    }
    
    function createListOfStudentChoices($projectPreferencesMdb2,$studentList,$studentChoices)
    {
      // This will create a list of student choices. It is based on items that are held within a student choices database.
        $dom=new DOMDocument();
        $dom->load($studentList);
        $studentXpath = new DOMXPath($dom);
        $queryStudents = "//student";
        $students=$studentXpath->query($queryStudents);

        $dom2 = new DOMDocument('1.0','UTF-8');
        $dom2->formatOutput = true;
        $root = $dom2->createElement ("studentPreferences");
        $root = $dom2->appendChild ($root);
    
        foreach($students as $stTag)
        {
            $uid=$stTag->getAttribute('uid');
            $studentChoice = $dom2->createElement ("studentChoice");
            $studentChoice = $root->appendChild ($studentChoice);
            $attr_uid = $dom2->createAttribute ('uid');
            $attr_uid = $studentChoice->appendChild ($attr_uid);
            $studentChoice->setAttribute('uid',$uid);
            $types = array("text");
            $statement = $projectPreferencesMdb2->prepare("SELECT * FROM projectPreferences WHERE uid =? ORDER BY pref", $types, MDB2_PREPARE_RESULT);
            $data = array($uid);
            $projectPrefQuery = $statement->execute($data);
        
            while ($prefs = $projectPrefQuery->fetchRow(MDB2_FETCHMODE_ORDERED))
            {
                $projid=$prefs[2];
                $rank=$prefs[1];
        
                $pref = $dom2->createElement ("pref");
                $pref = $studentChoice->appendChild ($pref);
                $attr_rank = $dom2->createAttribute ('rank');
                $attr_rank = $pref->appendChild ($attr_rank);
                $pref->setAttribute('rank', $rank);
        
                $attr_projid = $dom2->createAttribute ('projid');
                $attr_projid = $pref->appendChild ($attr_projid);
                $pref->setAttribute('projid', $projid);
        
        
            }
        
        } 
        $dom2->save($studentChoices);
    }
    function hiddenProject($projid,$proposalFile)
    {
        // This will check to see if the hidden section has been filled in for a particular project proposal.
        $dom=new DOMDocument();
        $dom->load($proposalFile);
        $profilesXpath = new DOMXPath($dom);    
        $queryHidden = "//project[@label=\"$projid\"]/hidden";
        $proposalHidden=$profilesXpath->query($queryHidden);
        $hiddenProp="";
        foreach($proposalHidden as $hid) $hiddenProp=$hid->nodeValue;
        return $hiddenProp;
    }   
    function createListOfDegreeProjects($proposalFile)
    {
        // This will process the proposals file and just leave the identifier for the projects and which degrees it is appropriate for in a new xml file.
        $profilesNo=0;
        $dom2 = new DOMDocument('1.0','UTF-8');
        $dom2->formatOutput = true;
        $root = $dom2->createElement ("projectList");
        $root = $dom2->appendChild ($root);
        $dom=new DOMDocument();
        $dom->load($proposalFile);
        $profilesXpath = new DOMXPath($dom);    
        $queryProjects = "//project";
        $projects=$profilesXpath->query($queryProjects);
        foreach($projects as $proj)
        {
        $projid=$proj->getAttribute('label');
        $hiddenProp=hiddenProject($projid,$proposalFile);
        if (empty($hiddenProp))
        {
               $queryProfiles = "//project[@label=\"$projid\"]/profiles/*";

               $projectid = $dom2->createElement ("project");
               $projectid = $root->appendChild ($projectid);
               $attr_uid = $dom2->createAttribute ('label');
               $attr_uid = $projectid->appendChild ($attr_uid);
               $projectid->setAttribute('label', htmlentities($projid));

               $profilesNames=$profilesXpath->query($queryProfiles);
               foreach($profilesNames as $profName)
               {
                   $degree = $dom2->createElement ("degree");
                   $degree = $projectid->appendChild ($degree);
                   $attr_uid = $dom2->createAttribute ('id');
                   $attr_uid = $degree->appendChild ($attr_uid);
                   $degree->setAttribute('id', $profName->nodeName);
               }
        }
        }
        $dom2->save('../../common/generated/xml/projects.xml');
        return $profilesNo;
    }

    function degreeRestricted($profilesNo,$projid,$degreecode,$degreeRestrictionXpath)
    {
    
        // A check to see whether degree codes are found within the proposal file so that restricted list can be created to chose from for students.
        $restrictedListItem=0;
        if ($profilesNo>0)
        {
           $query = "//project[@label=\"$projid\"]/degree[@id=\"$degreecode\"]";
           $restrictedListItem=$degreeRestrictionXpath->query($query)->length;
        } 
        return $restrictedListItem;
    }
    function hiddenProposal($projid,$studentProposalXpath)
    {
        // This will check whether a proposal is hidden and should be displayed to students.
        $queryHiddenProjects="//project[@label=\"$projid\"]/hidden";
        $hiddenProjs=$studentProposalXpath->query($queryHiddenProjects);
        $hiddenVal="";
        foreach ($hiddenProjs as $hp) $hiddenVal=$hp->nodeValue;
        return $hiddenVal;        
    } 

    function findDegreeCodeAbreviation($degreeAbreviationsXpath,$degreecode)
    {
        // this will check to see if the abreviation in the file exists for a particular degree.
        $query = "//degree[@degreecode='$degreecode']";
        $abreviations=$degreeAbreviationsXpath->query($query);
        $allocateAll=false;
        foreach ($abreviations as $ab) 
        {
             $degreecode=$ab->getAttribute('abreviation');
             $allocateAll=$ab->getAttribute('allocateAll');
        }
        if ($allocateAll) $degreecode="_all_";
    
        return $degreecode;
    }
    
    function markerName($markerUid,$markerList)
    {
         $doc1 = new DOMDocument;
         $doc1->preserveWhiteSpace = false;
         $doc1->Load($markerList);
         $xpath1 = new DOMXPath($doc1);
         // this queries the markers xml file to obtain details about the marker.
         $query = "//marker[@uid=\"$markerUid\"]";
         $marker = $xpath1->query($query);
         $name="";
         foreach ($marker as $mk)  $name=htmlspecialchars($mk->getAttribute('surname')).", ".htmlspecialchars($mk->getAttribute('firstname'))." (".$mk->getAttribute('uid').")";
         return $name;
     }
     
    function degreeRestrictions($proposalFile)
    {
        $dom2=new DOMDocument();
        $dom2->load($proposalFile);
        $profilesXpath = new DOMXPath($dom2);
        // this finds a list of which degrees a particular project proposal is for.
        $queryProfiles = "//project/profiles";
        return $profilesNo=$profilesXpath->query($queryProfiles)->length;
    }     
    
    function displayMaxMarking($markerList,$markerMaxList)
    {
        // This creates the area in which the assessment maximums are to be entered.
         $html="<h3>Number of Allocations</h3>Up to date list:<input type='checkbox' name='calculateTotals' onClick='countSupervisorSecondMarker();' value='&nbsp;&nbsp;Update&nbsp;&nbsp;'/>(Tick Box)<table border='1'><thead><th>Tutor</th>\n<th>Sup. Max</th></th>\n<th>Info.</th>\n<th>2nd Max</th>\n<th>Info.</th>\n</thead>\n<tbody>";
         $dom=new DOMDocument();
         $dom->load($markerList);
         $markersXpath = new DOMXPath($dom);
         $queryMarkers = "//marker";
         $markers=$markersXpath->query($queryMarkers);       
         $maxSupTotal=0;
         $maxSMTotal=0;
         foreach ($markers as $mks) 
         {
            $uid=$mks->getAttribute('uid');
            $maxSup=findMaxMarker($uid,$markerMaxList,"supervisorMax");
            $maxSupTotal+=$maxSup;
            $maxSM=findMaxMarker($uid,$markerMaxList,"secondMarkerMax");
            $maxSMTotal+=$maxSM;
            // onMouseOut='countSupervisorSecondMarker()'
            $html.="\n<tr><td>$uid</td><td><input type='text' name='supT[$uid]' value='$maxSup' class='boxes' maxlength = '4' size = '5' onClick='document.markingSetup.calculateTotals.checked=false;' ></td>";
            $html.="\n<td><input type='text' name='supDisp[$uid]' maxlength = '4' size = '5' class='heading2' value='' readonly></td>";
            $html.="\n<td><input type='text' name='smT[$uid]'  maxlength = '4' size = '5' value='$maxSM' class='boxes' onClick='document.markingSetup.calculateTotals.checked=false;'></td>";   
            $html.="\n<td><input type='text' name='smDisp[$uid]' maxlength = '4' size = '5' class='heading2' readonly></td></tr>";  
         }
        $html.="\n<tr><td>Total</td><td><input type='text' name='supTTotal' class='heading2' value='' maxlength = '4' size = '10' readonly></td>";
        $html.="\n<td><input type='text' name='supDispTotal' maxlength = '4' size = '5' class='heading2' value='' readonly></td>";
        $html.="\n<td><input type='text' name='smTTotal'  maxlength = '4' size = '10' class='heading2' value='' readonly></td>";    
        $html.="\n<td><input type='text' name='smDispTotal' maxlength = '4' size = '5' class='heading2'  readonly></td></tr>\n</tbody></table>";         
        return $html;
     }
     
     function displayProjectCounts($proposalFile,$proposals_link,$markerList)
     {
        // This gives a list of boxes that are used to show project counts.
        
        $html="<table border='1'><thead><th>Project</th>\n<th>Info.</th>\n</thead>\n<tbody>";
        $dom=new DOMDocument();
        $dom->load($proposalFile);
        $profilesXpath = new DOMXPath($dom);    
        $queryProjects = "//project";
        $projects=$profilesXpath->query($queryProjects);
        foreach($projects as $proj)
        {
            $projid=$proj->getAttribute('label');
            $title="";
            $title=getProposalTitle($projid,$proposalFile,$proposals_link,$markerList);
            if (!empty($title)) 
            {
                $html.="\n<tr><td>$title</td>";
                $html.="\n<td><textarea name='projectDisp[$projid]' cols='10' rows='2' value='' class='heading2' readonly></textarea></td></tr>";
         }
        }     
        return $html.="</tbody></table>";
     
     }
     
     
     function addHiddenMarkingCounts($markerList,$proposalFile)
     {
     
     // This gives a form which is used for the counts that are used by the javascript for allocated staff and projects.
     
        $dom=new DOMDocument();
        $dom->load($markerList);
        $markersXpath = new DOMXPath($dom);
        $queryMarkers = "//marker";
        $markers=$markersXpath->query($queryMarkers);   
        $html="";
        foreach ($markers as $mks) 
        {
            $uid=$mks->getAttribute('uid');
            $html.="\n<input type='hidden' name='$uid' value='0'>";
            $html.="\n<input type='hidden' name='sm_$uid' value='0'>";
        } 
        $dom=new DOMDocument();
        $dom->load($proposalFile);
        $profilesXpath = new DOMXPath($dom);    
        $queryProjects = "//project";
        $projects=$profilesXpath->query($queryProjects);        
        foreach($projects as $proj)
        {
        
            $projid=$proj->getAttribute('label');
            if (!empty($projid)) foreach ($markers as $mks)     
            {
                $uid=$mks->getAttribute('uid');
                $html.="\n<input type='hidden' name='proj[$uid][$projid]' value='0'>";
        
            }
        }
        $projid="Own Project";
         foreach ($markers as $mks) 
        {
            $uid=$mks->getAttribute('uid');
            $html.="\n<input type='hidden' name='proj[$uid][$projid]' value='0'>";
        }
        return $html;
     }
     function findMaxMarker($uid,$markerMaxList,$markerType)
     {
        if (file_exists($markerMaxList))
        {
            $dom=new DOMDocument();
            $dom->load($markerMaxList);
            $markersXpath = new DOMXPath($dom);
            $queryMarkers = "//marker[@uid=\"$uid\"]";
            $markers=$markersXpath->query($queryMarkers);   
            $max=0;
            foreach ($markers as $mks) $max=$mks->getAttribute($markerType);
            return $max;    
        } else return $max=0;
     }
     
    function saveMarkingMax($markerMaxList,$markerList,$supervisor,$secondMarker)
    {
    
        // This will save the marking maximums of staff into an xml file.
        $dom=new DOMDocument();
        $dom->load($markerList);
        $markersXpath = new DOMXPath($dom);
        $queryMarkers = "//marker";
        $marker=$markersXpath->query($queryMarkers);    
        $cntMrk=1;
    
        foreach ($marker as $mks) 
        {
            $uid=$mks->getAttribute('uid'); 
            $markers[$cntMrk]=$uid;
            $cntMrk++;
        }

        if (isset($supervisor)) while (list($uid,$max) = each($supervisor))
        {   
            $cntSp=0;
            while($cntSp++<$cntMrk) if ($markers[$cntSp]==$uid && $uid!="total") $spIndex=$cntSp;
            $supervisors[$spIndex]=$max;
            $cntSp++;
        }
        if (isset($secondMarker)) while (list($uid,$max) = each($secondMarker))
        {
            $cntSM=0;
            while($cntSM++<$cntMrk) if ($markers[$cntSM]==$uid && $uid!="total") $smIndex=$cntSM;
            $secondMarkers[$smIndex]=$max;
            $cnt++;
        }   

        $dom2 = new DOMDocument('1.0','UTF-8');
        $dom2->formatOutput = true;
        $root = $dom2->createElement ("markersMax");
        $root = $dom2->appendChild ($root);
    
        $cntMrk=1;
        foreach ($marker as $mks) 
        {
            $uid=$mks->getAttribute('uid'); 
            $supMax=$supervisors[$cntMrk];  
            $secondMarkerMax=$secondMarkers[$cntMrk];   
        
            $markerTag = $dom2->createElement ("marker");
            $markerTag = $root->appendChild ($markerTag);
        
            $attr_uid = $dom2->createAttribute ('uid');
            $attr_uid = $markerTag->appendChild ($attr_uid);
            $markerTag->setAttribute('uid', $uid);
        
            $attr_supervisorMax = $dom2->createAttribute ('supervisorMax');
            $attr_supervisorMax = $markerTag->appendChild ($attr_supervisorMax);
            $markerTag->setAttribute('supervisorMax', $supMax);
        
            $attr_secondMarkerMax = $dom2->createAttribute ('secondMarkerMax');
            $attr_secondMarkerMax = $markerTag->appendChild ($attr_secondMarkerMax);
            $markerTag->setAttribute('secondMarkerMax', $secondMarkerMax);
        
            $cntMrk++;  
        }
    
        $dom2->save($markerMaxList);

    }   
    function getProposalTitle($label,$proposalFile,$student_proposals_link,$markerList)
    {
        // This returns the title of the proposal. 
        $domPropInfo=new DOMDocument();
        $domPropInfo->load($proposalFile);
        $propInfoXpath = new DOMXPath($domPropInfo);
        $queryProjects="//project[@label='$label']/title";
        $proposalsInfo=$propInfoXpath->query($queryProjects);
        $title="";
        foreach($proposalsInfo as $propinf) 
        if (!empty($student_proposals_link)) 
            $title="<a href=\"$student_proposals_link#$label\">".$propinf->nodeValue." ".getProposalStaff($label,$proposalFile,$markerList)."</a>";
        else $title=$propinf->nodeValue;
        return $title;
    }      
    function getProposalStaff($label,$proposalFile,$markerList)  
    {        
             // This gathers all the proposal staff.
             $domPropInfo=new DOMDocument();
             $domPropInfo->load($proposalFile);
             $propInfoXpath = new DOMXPath($domPropInfo);
             
             $queryProjects="//project[@label='$label']/supervisor/*";
             $proposalsInfo=$propInfoXpath->query($queryProjects);
         
             $cnt=1;
             $supervisors="(";

             foreach($proposalsInfo as $propinf)
             {
                 if ($cnt>1) $supervisors.=", ";
                 if (!empty($propinf->nodeName)) $supervisors.=markerName($propinf->nodeName,$markerList);
                 $cnt++; 

             }
         
             return $supervisors.=")";  
    }
   function sortListByMarkerProject($studentList,$typeOrder,$markingSetupMdb2,$outputFile)
   {
   // This sorts the marking setup file into the order that was requested.
   
        $dom = new DOMDocument('1.0','UTF-8');
        $dom->formatOutput = true;
        $root = $dom->createElement ("studentlist");
        $root = $dom->appendChild ($root);
        if ($typeOrder=="supervisor") $query="SELECT uid,forenames,surname,candidate_number,degreecode FROM markingSetup ORDER BY supervisorFullName,surname,forenames";
        if ($typeOrder=="secondmarker") $query="SELECT uid,forenames,surname,candidate_number,degreecode FROM markingSetup ORDER BY secondmarkerFullName,surname,forenames";
        if ($typeOrder=="project") $query="SELECT uid,forenames,surname,candidate_number,degreecode FROM markingSetup ORDER BY project,surname,forenames";
        if ($typeOrder=="alpha") $query="SELECT uid,forenames,surname,candidate_number,degreecode FROM markingSetup ORDER BY surname,forenames,project";
    
        $sortMarkingSetupQuery=$markingSetupMdb2->query($query);
    if (PEAR::isError($sortMarkingSetupQuery))  echo "Error with student sort query<br/>";
    else
    {
       while ($Students = $sortMarkingSetupQuery->fetchRow(MDB2_FETCHMODE_ORDERED))
       {

           $student = $dom->createElement ("student");
           $student = $root->appendChild ($student);
           $attr_uid = $dom->createAttribute ('uid');
           $attr_uid = $student->appendChild ($attr_uid);
           $uid = $Students[0];
           $student->setAttribute('uid', $uid);

           $attr_forenames = $dom->createAttribute ('forenames');
           $attr_forenames = $student->appendChild ($attr_forenames);
           $forenames = $Students[1];
           $student->setAttribute('forenames', $forenames);

           $attr_surname = $dom->createAttribute ('surname');
           $attr_surname = $student->appendChild ($attr_surname);
           $surname = $Students[2];
           $student->setAttribute('surname', $surname);

           $attr_candidate_number = $dom->createAttribute ('candidate_number');
           $attr_candidate_number = $student->appendChild ($attr_candidate_number);
           $candidate_number = $Students[3];
           $student->setAttribute('candidate_number', $candidate_number);

           $attr_degreecode = $dom->createAttribute ('degreecode');
           $attr_degreecode = $student->appendChild ($attr_degreecode);
           $degreecode = $Students[4];
           $student->setAttribute('degreecode', $degreecode);

       } 

       $dom->save($outputFile);
    }
    
    return $outputFile;
    
   }
   function displayPreferences($studentChoices,$studentChoicesDom,$proposals_link,$stuid)
   {
            // This will display the list of preferences.
            $xsltProc1 = new XSLTProcessor();
            $xsltProc1->importStylesheet( DOMDocument::load('projectPreferences.xslt') );
            $xsltProc1->setParameter('','stuid',$stuid);
            $xsltProc1->setParameter('','proposals_link',$proposals_link);
            return $projectPreferences=$xsltProc1->transformToXML($studentChoicesDom);   
   }
   function findPreferenceChosen($studentChoicesXpath,$prefDisplay,$stuid)
   {
            // This will find the preferences that have been chosen and show the selected choice.
            if (empty($prefDisplay)) $prefDisplay=1; 
            $query = "//studentChoice[@uid='$stuid']/pref[@rank='$prefDisplay']";
            $prefFirst=$studentChoicesXpath->query($query);
            $projectChoice="";
            foreach($prefFirst as $pf) $projectChoice=$pf->getAttribute('projid');
            return $projectChoice;
   }
?>
