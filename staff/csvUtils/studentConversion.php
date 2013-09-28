<?php
echo "csv tool<br/>Converting: ";
$row = 1;
$csvFile=$_GET["csvFile"];
$csvFile="../../common/generated/csv/$csvFile";
echo $csvFile;
$dom = new DOMDocument('1.0','UTF-8');
$dom->formatOutput = true;
$root = $dom->createElement ("studentlist");
$root = $dom->appendChild ($root);



if (($handle = fopen($csvFile, "r")) !== FALSE) {
    while (($Students = fgetcsv($handle, 1000, ",")) !== FALSE) 
    {
      if ($row>1)
      {
        $student = $dom->createElement ("student");
        $student = $root->appendChild ($student);
        $attr_uid = $dom->createAttribute ('uid');
        $attr_uid = $student->appendChild ($attr_uid);  
        $uid =$Students[3];
        $student->setAttribute('uid', $uid);
    
        $attr_forenames = $dom->createAttribute ('forenames');
        $attr_forenames = $student->appendChild ($attr_forenames);
        $forenames = $Students[2];
        $student->setAttribute('forenames',$forenames);

        $attr_surname = $dom->createAttribute ('surname');
        $attr_surname = $student->appendChild ($attr_surname);
        $surname = $Students[1];
        $student->setAttribute('surname',$surname);

        $attr_candidate_number = $dom->createAttribute ('candidate_number');
        $attr_candidate_number = $student->appendChild ($attr_candidate_number);
        $candidate_number = $Students[0];
        $student->setAttribute('candidate_number',$candidate_number);

        $attr_degreecode = $dom->createAttribute ('degreecode');
        $attr_degreecode = $student->appendChild ($attr_degreecode);
        $degreecode = $Students[4];
        $student->setAttribute('degreecode', $degreecode);    
        $num = count($Students);
        echo "<p> $num fields in line $row: <br /></p>\n";
    
        for ($c=0; $c < $num; $c++) {
            echo $Students[$c] . "<br />\n";
        }
      }
      $row++;
    }
    fclose($handle);
    
    if ($row>1) $dom->save('../../common/generated/xml/studentlist.xml');

}
?>
