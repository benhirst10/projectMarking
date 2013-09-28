<?php
require_once 'MDB2.php';   
include "../../common/php/generalFunctions.inc";

$projectPreferencesDatabase="../../common/generated/sqlite/projectPreferences.db";
$dsn = array(
    'phptype'  => 'sqlite',
    'database' => $projectPreferencesDatabase,
    'mode'     => '0644',
);
$options = array(
    'debug'       => 2,
    'portability' => MDB2_PORTABILITY_ALL,
);


$projectPreferencesMdb2 =& MDB2::factory($dsn, $options);


if (PEAR::isError($projectPreferencesMdb2)) 
{
    die($projectPreferencesMdb2->getMessage());
}

$result = $projectPreferencesMdb2->query("SELECT * FROM projectPreferences");

if (PEAR::isError($result)) {

    if ($result=="MDB2 Error: no such table")
    {
      $createTable=$projectPreferencesMdb2->exec("CREATE TABLE projectPreferences(uid TEXT,pref INTEGER,project BLOB,PRIMARY KEY(uid,pref))");
      if (PEAR::isError($createTable)) echo "Error create table release feedback:".$createTable;
    }

} 
$html="<html>";
header('Content-Type: text/html; charset=utf-8'); 
$projectsDegreeRestrictions="../../common/generated/xml/projects.xml";
$proposalFile="../../common/generated/xml/proposals.xml";
$markerList="../../common/generated/xml/markers.xml";
checkFileExists($markerList,"marker list file");
$studentList="../../common/generated/xml/studentlist.xml";
checkFileExists($studentList,"student list file");
$versionFile="../../common/config/xml/version.xml";
checkFileExists($versionFile,"generated marking scheme file");
$degreeAbreviationsFile="../../common/xml/degreeAbreviations.xml";

?>
