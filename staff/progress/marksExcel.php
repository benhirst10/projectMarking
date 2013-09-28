<?php
// Marks Spreadsheet for marking system
// Author B.M. Hirst
// 2010
$configPath="../config/xml/";
include "../../common/php/progressDB.inc";
require_once "Spreadsheet/Excel/Writer.php";
   $doc = new DOMDocument;
   $doc->preserveWhiteSpace = false;
   $doc->Load($progressMarkingScheme);
   $xpath = new DOMXPath($doc);
   $query = "/markingScheme";
   $markingSchemes = $xpath->query($query);
   foreach ($markingSchemes as $ms) 
   {
       $Projects=$ms->getAttribute('modcode');
   }
   $cwkpercent=100;
   $passrate=0.4;
   $passrateabsolute=$passrate-0.005;

        $xls =& new Spreadsheet_Excel_Writer();
        // This will create a new excel writer.
        $xls->send("$Projects.xls");
        $sheet =& $xls->addWorksheet('Spreadsheet - Name Order');
        $xls->setCustomColor(12, 224, 255, 255);
        
        $cellFormat1 =& $xls->addFormat();
        $cellFormat1->setFontFamily('Sans');
        $cellFormat1->setBold();
        $cellFormat1->setSize('14');
        $cellFormat1->setFgColor('silver');
        $cellFormat2 =& $xls->addFormat();
        $cellFormat2->setFontFamily('Sans');
        $cellFormat2->setBold();
        $cellFormat2->setSize('14');
        $cellFormat2->setFgColor(12);
        $cellFormat3 =& $xls->addFormat();
        $cellFormat3->setFontFamily('Sans');
        $cellFormat3 =& $xls->addFormat();
        $cellFormat3->setBold();
        $cellFormat3->setSize('14');  
        $cellFormat4 =& $xls->addFormat();
        $cellFormat4->setFontFamily('Sans');
        $cellFormat4->setBold();
        $cellFormat4->setSize('10');
        $cellFormat4->setFgColor('silver');
        $cellFormat4->setTextWrap(); 
        $cellFormat5 =& $xls->addFormat();
        $cellFormat5->setFontFamily('Sans');
        $cellFormat5->setBold();
        $cellFormat5->setSize('10');
        $cellFormat5->setTextWrap(); 
        $cellFormat6 =& $xls->addFormat();
        $cellFormat6->setFontFamily('Sans');
        $cellFormat6->setBold();
        $cellFormat6->setSize('10');
        $cellFormat6->setFgColor(12);   
        $cellFormat6->setTextWrap();  
        $cellFormat7 =& $xls->addFormat();
        $cellFormat7->setSize('10');
        $cellFormat7->setNumFormat('0%');
        $cellFormat8 =& $xls->addFormat();
        $cellFormat8->setSize('10');
        $cellFormat8->setNumFormat('0.00%');
        $cellFormat8->setFgColor(12);   
        $cellFormat9 =& $xls->addFormat();
        $cellFormat9->setSize('10');
        $cellFormat9->setNumFormat('0.00%');
        $cellFormat9->setFgColor('silver');  
        $cellFormat10 =& $xls->addFormat();
        $cellFormat10->setSize('10');
        $cellFormat10->setFgColor('yellow');
                      
        $sheet->write(0,0,"Module Code",$cellFormat1);
        $sheet->write(0,1,$Projects,$cellFormat2);
        $sheet->write(0,5,"Module Title:",$cellFormat3);
        $sheet->write(0,6,"",$cellFormat2);
        $sheet->write(0,7,"",$cellFormat2);
        $sheet->write(1,0,"",$cellFormat1);
        $sheet->write(1,1,"Number of Students",$cellFormat4);
        
        $dom=new DOMDocument();
        $dom->load($moduleList);
        $studentXpath = new DOMXPath($dom);     
        $queryStudents = "//student";
        $sheet->write(1,2,$studentXpath->query($queryStudents)->length,$cellFormat5);
        $sheet->write(1,6,$cwkpercent,$cellFormat6);
        $sheet->write(1,7,"Assessment: % Coursework",$cellFormat5);
        $sheet->write(1,8,"(Edittable) CW Wts",$cellFormat4);
        $query = "///assessment";       
        $assessments = $xpath->query($query);
        $col=9;
        foreach($assessments as $ass)
        {
            $weighting=$ass->getAttribute('weighting');
            if (!empty($weighting))  {
                $sheet->write(1,$col,$weighting,$cellFormat6);
                $col++;
            }        
        }
        $sheet->write(1,$col,"Total Weights",$cellFormat5);
        
        $sheet->write(2,1,"Expected Average",$cellFormat4);
        $sheet->write(2,8,"Applicable CW Wts",$cellFormat5);
        $col=9;
        $totalweights=0;
        $letter=74;
        foreach($assessments as $ass)
        {
            $weighting=$ass->getAttribute('weighting');
            $totalweights=$totalweights+$weighting;
            
            $column=chr($letter)."2";
            $formula="=$column";
            if (!empty($weighting)){
                $sheet->writeFormula(2,$col,$formula);
                $letter++;
                $col++;        
            }
        }
        $formula="=SUM(J2:Q2)";
        $sheet->writeFormula(2,$col,$formula);
        
        $sheet->write(3,1,"Average:",$cellFormat4);
        $maxrows=11+($studentXpath->query($queryStudents)->length);
        $formula="=AVERAGE(F11:F$maxrows)";
        $sheet->writeFormula(3,5,$formula,$cellFormat7);
        $letter=74;
        $col=9;
        foreach($assessments as $ass)
        {   
            $column=chr($letter)."11";  
            $formula="=AVERAGE($column:$column$maxrows)";
            $weighting=$ass->getAttribute('weighting');
            if (!empty($weighting)) 
            {
                $sheet->writeFormula(3,$col,$formula,$cellFormat4);
                $letter++;
                $col++;
            }
        }
        $sheet->write(4,1,"Out of:",$cellFormat4);
        $sheet->write(4,5,"100%",$cellFormat4);
        $col=9;
        foreach($assessments as $ass)
        {
            $weighting=$ass->getAttribute('weighting');
            if (!empty($weighting)) 
            {
                $sheet->write(4,$col,"100",$cellFormat6);
                $col++;
            }
        }
        $sheet->write(5,1,"Number doing test:",$cellFormat4);
        $sheet->write(5,2,"Pass rate:",$cellFormat4);
        $sheet->write(5,3,$passrate,$cellFormat8);
        $sheet->write(5,4,$passrateabsolute,$cellFormat9);
        $finalMarksQuery = $progressMdb2->query("SELECT * FROM finalMarks WHERE mark>0");
        $nodoingtest=$finalMarksQuery->numRows(); 
        $sheet->write(5,5,$nodoingtest,$cellFormat4);
        $col=9;
        foreach($assessments as $ass)
        {
            $assessmentid=$ass->getAttribute('id');        
            $weighting=$ass->getAttribute('weighting');
            if (!empty($weighting)) 
            {     
                $types = array("text");
                $statement = $progressMdb2->prepare("SELECT * FROM assessmentMarks WHERE assessmentId = ?", $types, MDB2_PREPARE_RESULT);
                $data = array($assessmentid);
                $assessmentQuery = $statement->execute($data);                      
                $nodoingtest=$assessmentQuery->numRows(); 
                $sheet->write(5,$col,$nodoingtest,$cellFormat4);     
                $col++;   
            }
        }
        $sheet->write(6,1,"Number absences:",$cellFormat4);
        $finalMarksQuery = $progressMdb2->query("SELECT * FROM finalMarks WHERE mark=0");
        $noabs=$finalMarksQuery->numRows(); 
        $sheet->write(6,5,$noabs,$cellFormat4);
        $col=9;
        foreach($assessments as $ass)
        {
            $assessmentid=$ass->getAttribute('id'); 

            $weighting=$ass->getAttribute('weighting');
            if (!empty($weighting)) 
            {
                $types = array("text"); 
                $statement = $progressMdb2->prepare("SELECT DISTINCT uid FROM assessmentComponentMarks WHERE assessmentId = ?", $types, MDB2_PREPARE_RESULT);   
                $data = array($assessmentid);
                $assessmentQuery = $statement->execute($data);            
                $noabsences=$studentXpath->query($queryStudents)->length-$assessmentQuery->numRows(); 
                $sheet->write(6,$col,$noabsences,$cellFormat4);     
                $col++;                 
            }
        }
        $sheet->write(7,1,"Number failures:",$cellFormat4);         
        $passrateabsolutepercent=$passrateabsolute*100;
        $finalMarksQuery = $progressMdb2->query("SELECT * FROM finalMarks WHERE mark>0 and mark<$passrateabsolutepercent");
        $nofailures=$finalMarksQuery->numRows(); 
        $sheet->write(7,5,$nofailures,$cellFormat4);
        $col=0;
        while($col<5)
        {
             $sheet->write(8,$col,"",$cellFormat4);            
             $col++;
        }
        $sheet->write(8,5,"FINAL",$cellFormat10);
        $sheet->write(8,6,"Coursework Marks");
        $sheet->write(9,0,"Last name",$cellFormat8);
        $sheet->write(9,1,"First names",$cellFormat8);
        $sheet->write(9,2,"Course",$cellFormat8);
        $sheet->write(9,3,"Username",$cellFormat8);
        $sheet->write(9,4,"Idno",$cellFormat8);
        $sheet->write(9,5,"Mark(%)",$cellFormat10);
        $sheet->write(9,6,"",$cellFormat4);
        $sheet->write(9,7,"",$cellFormat4);
        $sheet->write(9,8,"",$cellFormat4);
        $rwcnt=10;
        $col=9;
        $cnt=0;
        foreach($assessments as $ass)
        {       
            $weighting=$ass->getAttribute('weighting');
            if (!empty($weighting)) 
            {
                $cnt++;    
                $sheet->write(9,$col,$cnt,$cellFormat6);
                $col++;
            }
        }      

        $students=$studentXpath->query($queryStudents);  
        foreach($students as $stTag)
        {
        
            $stuid=$stTag->getAttribute('uid');
            $surname=$stTag->getAttribute('surname');
            $forenames=$stTag->getAttribute('forenames');
            $candidate_number=$stTag->getAttribute('candidate_number');
            $degreecode=$stTag->getAttribute('degreecode');
            $sheet->write($rwcnt,0,$surname);
            $sheet->write($rwcnt,1,$forenames);
            $sheet->write($rwcnt,2,$degreecode);
            $sheet->write($rwcnt,3,$stuid);
            $sheet->write($rwcnt,4,$candidate_number);
            $types = array("text");
            $statement = $progressMdb2->prepare("SELECT * FROM finalMarks WHERE uid = ?", $types, MDB2_PREPARE_RESULT);
            $data = array($stuid);
            $finalMarksQuery = $statement->execute($data);               
            while ($marks = $finalMarksQuery->fetchRow(MDB2_FETCHMODE_ORDERED)) 
            {
                if ($marks[1]>0) $sheet->write($rwcnt,5,$marks[1]/100,$cellFormat7);
                else $sheet->write($rwcnt,5,"ABS");

            }
            $sheet->write($rwcnt,6,"",$cellFormat4);
            $sheet->write($rwcnt,7,"",$cellFormat4);
            $sheet->write($rwcnt,8,"",$cellFormat4);                
            $col=9;
             foreach($assessments as $ass)
             {
                    $assessmentid=$ass->getAttribute('id'); 
                    $weighting=$ass->getAttribute('weighting');
                    if (!empty($weighting))
                    {
                        $types = array("text","text");
                        $statement = $progressMdb2->prepare("SELECT mark,assessmentId FROM assessmentMarks WHERE assessmentId = ? and uid = ?", $types, MDB2_PREPARE_RESULT);
                        $data = array($assessmentid,$stuid);
                        $assessmentQuery = $statement->execute($data);   
                        while ($marks = $assessmentQuery->fetchRow(MDB2_FETCHMODE_ORDERED)) 
                        {
                            $sheet->write($rwcnt,$col,$marks[0]);
                            $col++;
                        }
                    }
                    
            }             
            $rwcnt++;
            
        }
    $sheet->mergeCells(8,0,8,4);
    $sheet->mergeCells(8,6,8,16);
    $sheet->setLandscape();
    $sheet->setPrintScale(100);
    $sheet->fitToPages(1,10);
    $sheet->setColumn(0,5,19);
    $dt=date('l jS \of F Y h:i:s A');
    $sheet->setHeader($Projects."    ".$dt);
$xls->close();
?>
