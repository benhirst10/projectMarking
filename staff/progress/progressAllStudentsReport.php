<?php
    error_reporting(0); 
    $configPath="../config/xml/";
    include "../../common/php/progressDB.inc";
    include "../../common/php/progressFunctions.inc";
    header("Cache-Control: no-cache, must-revalidate"); 
    header('Content-Type: text/html; charset=utf-8'); 
    $html = "<html>";
    $doc = new DOMDocument;
    $doc->preserveWhiteSpace = false;
    $doc->Load($progressMarkingScheme);
    $xpath = new DOMXPath($doc);
    $query = "/markingScheme";
    $markingSchemes = $xpath->query($query);
    foreach ($markingSchemes as $ms) 
    {
       $modcode=$ms->getAttribute('modcode');
    }  
    $html.="<h3>$modcode</h3>";       
    $html.="\n<table border=1><tr><td>";
    // comment next line out 
    $assessment="";
    $markerSelected="";
    $secondMarkerSelected="";
    $dom=new DOMDocument();
    $dom->load($moduleList);
    $studentXpath = new DOMXPath($dom);    
    $queryStudents = "//student";
    $students=$studentXpath->query($queryStudents);
    // This will go through all the students.
    foreach($students as $stTag)
    {
        $uid=$stTag->getAttribute('uid');
        include "progressReport.inc";
    } 
    echo $html."</body></html>";

?>
