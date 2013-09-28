<?php
    
    include "auth.inc";
    $modcode=$_GET["Projects"];
    $modcode2=$_GET["Projects2"];
    $modcode3=$_GET["Projects3"];
    
    $dom = new DOMDocument('1.0','UTF-8');
    $dom->formatOutput = true;
    $root = $dom->createElement ("studentlist");
    $root = $dom->appendChild ($root);
    
    // This will find the projects that have been setup.
    $findProjectModuleStudents_SQL="select distinct person.uid,forenames,surname,candidate_number,degreecode from person,students,studentModules
                                    where person.uid=studentModules.uid and students.uid=person.uid
                                          and (modcode=\"$modcode\" or modcode=\"$modcode2\" or modcode=\"$modcode3\") order by surname,forenames,person.uid";
    $findStudentsList_query =  mysql_db_query($db,$findProjectModuleStudents_SQL,$connection);

    while ($Students = @ mysql_fetch_array($findStudentsList_query))
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

    $dom->save('../../common/generated/xml/studentlist.xml');
    // This will find the assigned markers to students.
    $markingSetup_SQL="select distinct projsupervisor.projsupid as supervisor,
                              projsupervisor.stuid as student,Projects.link as project,smuid as secondmarker from
                               projsupervisor,secondMarker,studentModules,Projects,studentProject
                                    where studentModules.uid=projsupervisor.stuid
                                          and studentModules.uid=projsupervisor.stuid
                                          and secondMarker.stuid=studentModules.uid
                                          and Projects.projid=studentProject.projid
                                          and studentProject.stuid=studentModules.uid
                                          and (studentModules.modcode=\"$modcode\" or studentModules.modcode=\"$modcode2\" or studentModules.modcode=\"$modcode3\") ";
                      
    $markingSetup_query =  mysql_db_query($db,$markingSetup_SQL,$connection);

    $dom = new DOMDocument('1.0','UTF-8');
    $dom->formatOutput = true;
    $root = $dom->createElement ("markingSetup");
    $root = $dom->appendChild ($root);
    $supervisors = $dom->createElement ("supervisors");
    $supervisors = $root->appendChild ($supervisors);
    
    while ($markingSetup = @ mysql_fetch_array($markingSetup_query))
    {


            $supervision = $dom->createElement ("supervision");
            $supervision = $supervisors->appendChild ($supervision);

            $attr_supervisor = $dom->createAttribute ('supervisor');
            $attr_supervisor = $supervision->appendChild ($attr_supervisor);
            $supervisor = $markingSetup["supervisor"];
            $supervision->setAttribute('supervisor', $supervisor);

            $attr_student = $dom->createAttribute ('student');
            $attr_student = $supervision->appendChild ($attr_student);
            $student = $markingSetup["student"];
            $supervision->setAttribute('student', $student);

            $attr_project = $dom->createAttribute ('project');
            $attr_project = $supervision->appendChild ($attr_project);
            $project = $markingSetup["project"];
            $supervision->setAttribute('project', htmlentities($project));

            $attr_smuid = $dom->createAttribute ('secondmarker');
            $attr_smuid = $supervision->appendChild ($attr_smuid);
            $secondmarker = $markingSetup["secondmarker"];
            $supervision->setAttribute('secondmarker', $secondmarker);

    }

    $dom->save('../generated/xml/markingSetup.xml');
    
    $dom = new DOMDocument('1.0','UTF-8');
    $dom->formatOutput = true;
    $root = $dom->createElement ("markers");
    $root = $dom->appendChild ($root);
     // This will be used find the markers that are presently assigned in the previous marking system.
    $findProjectMarkers_SQL="select distinct person.uid,forenames,surname from person,projsupervisor,studentModules
                                    where person.uid=projsupervisor.projsupid and projsupervisor.stuid=studentModules.uid
                                          and (modcode=\"$modcode\" or modcode=\"$modcode2\" or modcode=\"$modcode3\") order by forenames,surname,person.uid";
    $findMarkerList_query =  mysql_db_query($db,$findProjectMarkers_SQL,$connection);

    while ($markers = @ mysql_fetch_array($findMarkerList_query))
    {
            $marker = $dom->createElement ("marker");
            $marker = $root->appendChild ($marker);
        
            $attr_uid = $dom->createAttribute ('uid');
            $attr_uid = $marker->appendChild ($attr_uid);
            $uid = $markers[0];
            $marker->setAttribute('uid', $uid);

            $attr_forenames = $dom->createAttribute ('firstname');
            $attr_forenames = $marker->appendChild ($attr_forenames);
            $forenames = $markers[1];
            $marker->setAttribute('firstname', $forenames);

            $attr_surname = $dom->createAttribute ('surname');
            $attr_surname = $marker->appendChild ($attr_surname);
            $surname = $markers[2];
            $marker->setAttribute('surname', $surname);

            $attr_title = $dom->createAttribute ('title');
            $attr_title = $marker->appendChild ($attr_title);
        

    }

    $dom->save('../../common/generated/xml/markers.xml');

?>
