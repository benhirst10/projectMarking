<?php
    error_reporting(0); 
    $configPath="";
    if (!empty($_GET["uid"])) $uid=$_GET["uid"]; else $uid="";
    $configPathStudent="../config/xml/";
    include "../../common/php/progressDB.inc";
    include "../../common/php/progressFunctions.inc";
  
    include "../../common/php/progressStudentReport.inc"	    

?>
