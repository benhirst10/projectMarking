<?php
    header("Cache-Control: no-cache, must-revalidate");
    header('Content-Type: text/html; charset=utf-8');
    include "headergroups.inc";
    include "../../common/php/progressDB.inc";

    echo "<h1><a name='section-1'>$Projects  Project Group Allocation</a></h1>";
    echo "<form name='moduleAssess' method='post'>";
    echo "<textarea name='groupcount'  rows=10 class='boxes' ></textarea>";
    echo "<br/><br/><input type='SUBMIT' value='Save and Print Groups' name='savePrintGroupAllocation' STYLE='font-family:arial;
    font-size:small; font-style:bold; background:#000066 none; color:#FFFF93; width:12.5em'>   ";
    echo "<input type='SUBMIT' value='Save and Produce Web Page' name='saveWebGroupAllocation' STYLE='font-family:arial;
    font-size:small; font-style:bold; background:#000066 none; color:#FFFF93; width:15.5em'> <br/><br/>  ";
        echo "<table width='630' border='1' cellspacing='0' cellpadding='1'>";

        ?> <th width="100" scope="col" class="navhead">Name</th>
        <th width="20" scope="col" class="navhead">Group</th>
        <?php
        $dom=new DOMDocument();
        $dom->load($moduleList);
        $studentXpath = new DOMXPath($dom);
        $queryStudents = "//student";
        $students=$studentXpath->query($queryStudents);
    // This will go through all the students.
        foreach($students as $stTag)
        {
            $uid=$stTag->getAttribute('uid');
            $surname=$stTag->getAttribute('surname');
            $forenames=$stTag->getAttribute('forenames');
            $degreecode=$groups["degreecode"];
            echo "<tr><td align=left class='boxes'><b>$surname, $forenames ($uid)</b> </td><td align=center bgcolor='#000066'><input type='text' size=2 class='boxes' value='$group' name='groupChanged[$uid]' onclick='addUpBoxes()' onfocus='addUpBoxes()'  onmouseover='addUpBoxes()' onmouseout='addUpBoxes()'></td></tr>";
        }
    echo "</table>";
    echo "<br/><br/><input type='SUBMIT' value='Save and Print Groups' name='savePrintGroupAllocation' STYLE='font-family:arial;
    font-size:small; font-style:bold; background:#000066 none; color:#FFFF93; width:12.5em'>   ";
    echo "<input type='SUBMIT' value='Save and Produce Web Page' name='saveWebGroupAllocation' STYLE='font-family:arial;
    font-size:small; font-style:bold; background:#000066 none; color:#FFFF93; width:15.5em'>   ";
    echo "<input type='hidden' name='totalmarks' value=''></form>";
?>
