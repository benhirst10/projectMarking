<?php
    error_reporting(0); 
    if (!empty($_GET["uid"])) $uid=$_GET["uid"]; else $uid="";
    $configPath="../config/xml/";
    include "../../common/php/progressDB.inc";
    include "../../common/php/progressFunctions.inc";
    header("Cache-Control: no-cache, must-revalidate"); 
    header('Content-Type: text/html; charset=utf-8'); 
    $html = "<html><head><title>Student Progress Report</title></head>";      
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
    include "progressReport.inc";
    $html.="</body></html>";
    echo $html;
    

?>
