<?php
    $domStudent = new DOMDocument;
    $domStudent->preserveWhiteSpace = false;
    $studentList="../../generated/xml/studentlist.xml";
    $domStudent->Load($studentList);
    $studentXpath = new DOMXPath($domStudent);
    $queryStudents = "//student";
    $cnt++;
    $students=$studentXpath->query($queryStudents);

    $dom = new DOMDocument('1.0','UTF-8');
    $dom->formatOutput = true;
    $root = $dom->createElement ("studentProjectSetup");
    $root = $dom->appendChild ($root);
    foreach($students as $stTag)
    {

        $dom_student = $dom->importNode($stTag, true);
        $dom_student = $root->appendChild($dom_student);
        $stuid=$stTag->getAttribute('uid');

        $domPref = new DOMDocument('1.0');
        $studentPref="../../generated/xml/studentchoices.xml";
        $query = "//studentChoice[@uid='$stuid']/";

        $studentChoicesXpath = new DOMXPath($domPref);
        $prefs=$studentChoicesXpath->query($query);
        foreach($prefs as $pf)
        {
            // create element called preferences.

            $projectChoice=$pf->getAttribute('projid');
            $rank=$pf->getAttribute('rank');

            $prefs=$dom->createElement ('prefs');
            $prefs = $dom_root->appendChild ($prefs);

            $attr_projid = $dom->createAttribute ('projid');
            $attr_projid = $prefs->appendChild ($attr_projid);
            $attr_projid = $projectChoice;

            $prefs->setAttribute('projid', $attr_projid);

            $attr_rank = $dom->createAttribute ('rank');
            $attr_rank = $prefs->appendChild ($attr_rank);
            $attr_rank = $projectChoice;

            $prefs->setAttribute('rank', $attr_rank);

        }

        // add to element that is being appended too a child that contains information about preferences.

    }

    $dom=new DOMDocument();
    $dom->load("../../generated/xml/proposals.xml");
    $profilesXpath = new DOMXPath($dom);
    $queryProjects = "//project";
    $projects=$profilesXpath->query($queryProjects);
    foreach($projects as $proj)
    {
         $label=$proj->getAttribute('label');
         $title=$proj->getAttribute('title');

         $domPropInfo=new DOMDocument();
         $domPropInfo->load($proposalFile);
         $propInfoXpath = new DOMXPath($domPropInfo);

         $queryProjects="//project[@label='$label']/supervisor/*";
         $proposalsInfo=$propInfoXpath->query($queryProjects);

         // replace degree abbreviations with actual degree codes reduce the need for lookup.

         $cnt=1;
         $supervisors="(";
         $project=$dom->createElement ('project');
         $project  = $dom_sxe->appendChild ($project);

         foreach($proposalsInfo as $propinf)
         {
                if ($cnt>1) $supervisors.=", ";
                $markerId=$propinf->nodeName;
                $cnt++;
                $marker=$dom->createElement ('marker');
                $marker = $project->appendChild ($marker);

                $attr_marker = $dom->createAttribute ('marker');
                $attr_marker = $prefs->appendChild ($attr_marker);
                $attr_marker = $markerId;
         }
    }
    echo $dom->saveXML();

?>
