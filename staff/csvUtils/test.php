<?php
echo "csv tool";
$row = 1;
$csvFile="../../common/generated/csv/CO7201_SPRING.10.11_students_list.csv";
if (($handle = fopen($csvFile, "r")) !== FALSE) {
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        $num = count($data);
        echo "<p> $num fields in line $row: <br /></p>\n";
        $row++;
        for ($c=0; $c < $num; $c++) {
            echo $data[$c] . "<br />\n";
        }
    }
    fclose($handle);
}
?>
