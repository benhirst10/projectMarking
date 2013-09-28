<?php
    
    include "auth.inc";
    $modcode=$_GET["Projects"];
    $modcode2=$_GET["Projects2"];
    $modcode3=$_GET["Projects3"];
    
    $dom = new DOMDocument('1.0','UTF-8');
    $dom->formatOutput = true;
    $root = $dom->createElement ("markers");
    $root = $dom->appendChild ($root);
    
    // This will be used to find the markers that are presently assigned in the previous marking system.
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
