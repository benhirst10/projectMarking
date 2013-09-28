<?php
    
    include "auth.inc";
    $modcode=$_GET["Projects"];
    $modcode2=$_GET["Projects2"];
    $modcode3=$_GET["Projects3"];
    
    $dom = new DOMDocument('1.0','UTF-8');
    $dom->formatOutput = true;
    $root = $dom->createElement ("studentlist");
    $root = $dom->appendChild ($root);

    // This will transfer students who are doing 3 project modules that make the cohort of undergraduate project students.
    $findProjectModuleStudents_SQL="select distinct person.uid,forenames,surname,candidate_number,degreecode from person,students,studentModules
                                    where person.uid=studentModules.uid and students.uid=person.uid
                                          and (modcode=\"$modcode\" or modcode=\"$modcode2\" or modcode=\"$modcode3\") order by surname,forenames,person.uid";
    echo  $findProjectModuleStudents_SQL;
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

    
?>
