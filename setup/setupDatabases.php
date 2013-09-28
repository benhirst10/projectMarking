<?php
require_once 'MDB2.php';   

$markingSetupDatabase="../staff/generated/sqlite/markingSetup.db";

$dsn = array(
    'phptype'  => 'sqlite',
    'database' => $markingSetupDatabase,
    'mode'     => '0644',
);

$options = array(
    'debug'       => 2,
    'portability' => MDB2_PORTABILITY_ALL,
);

$markingSetupMdb2 =& MDB2::factory($dsn, $options);
if (PEAR::isError($markingSetupMdb2)) 
{
    die($markingSetupMdb2->getMessage());
}


$result = $markingSetupMdb2->query("SELECT * FROM markingSetup");


if (PEAR::isError($result)) {

    if ($result=="MDB2 Error: no such table")
    {
      $createTable=$markingSetupMdb2->exec("CREATE TABLE markingSetup(uid TEXT,surname TEXT,forenames TEXT,candidate_number TEXT,degreecode TEXT,supervisor TEXT,secondmarker TEXT,project TEXT,supervisorFullName TEXT,secondmarkerFullName TEXT,hide TEXT, PRIMARY KEY(uid))");
      if (PEAR::isError($createTable)) echo "Error create table marking setup:".$createTable;
    }

} 

$progressDatabase="../common/generated/sqlite/progress.db";

$dsn = array(
    'phptype'  => 'sqlite',
    'database' => $progressDatabase,
    'mode'     => '0644',
);

$options = array(
    'debug'       => 2,
    'portability' => MDB2_PORTABILITY_ALL,
);

$progressMdb2 =& MDB2::factory($dsn, $options);
if (PEAR::isError($progressMdb2)) 
{
    die($progressMdb2->getMessage());
}

$assessmentMarksFound=true;

$result = $progressMdb2->query("SELECT * FROM assessmentMarks");

if (PEAR::isError($result)) {

    if ($result=="MDB2 Error: no such table")
    {
      $createTable=$progressMdb2->exec("CREATE TABLE assessmentMarks(uid TEXT,assessmentId TEXT,mark TEXT, PRIMARY KEY(uid,assessmentId))");
      if (PEAR::isError($createTable)) echo "Error create table marks:".$createTable;
      $componentMarksFound=false;
    }

} else if ($result->numRows()==0) $assessmentMarksFound=false;


$result = $progressMdb2->query("SELECT * FROM assessmentNotAvailable");

if (PEAR::isError($result)) {

    if ($result=="MDB2 Error: no such table")
    {
      $createTable=$progressMdb2->exec("CREATE TABLE assessmentNotAvailable(assessmentId TEXT,uid TEXT,PRIMARY KEY(assessmentId,uid))");
      if (PEAR::isError($createTable)) echo "Error create table assessment available:".$createTable;
    }

} 

$result = $progressMdb2->query("SELECT * FROM releaseFeedback");

if (PEAR::isError($result)) {

    if ($result=="MDB2 Error: no such table")
    {
      $createTable=$progressMdb2->exec("CREATE TABLE releaseFeedback(assessmentId TEXT,PRIMARY KEY(assessmentId))");
      if (PEAR::isError($createTable)) echo "Error create table release feedback:".$createTable;
    }

} 


$componentMarksFound=true;

$result = $progressMdb2->query("SELECT * FROM assessmentComponentMarks");

if (PEAR::isError($result)) {

    if ($result=="MDB2 Error: no such table")
    {
      $createTable=$progressMdb2->exec("CREATE TABLE assessmentComponentMarks(uid TEXT,componentId TEXT,assessmentId TEXT,type TEXT,feedback BLOB,mark REAL, PRIMARY KEY(uid,componentId,assessmentId,type))");
      if (PEAR::isError($createTable)) echo "Error create table componentMarks:".$createTable;
      $componentMarksFound=false;
    }

} else if ($result->numRows()==0) $componentMarksFound=false;

$result = $progressMdb2->query("SELECT * FROM finalMarks");

if (PEAR::isError($result)) {

    if ($result=="MDB2 Error: no such table")
    {
      $createTable=$progressMdb2->exec("CREATE TABLE finalMarks(uid TEXT,mark REAL, PRIMARY KEY(uid))");
      if (PEAR::isError($createTable)) echo "Error create table final marks:".$createTable;
      $componentMarksFound=false;
    }

}

$projectPreferencesDatabase="../common/generated/sqlite/projectPreferences.db";
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

?>
