<?php
// Student Modules Page
// Author B.M. Hirst
// Date 02/07/03
// <!-- This java script I have used for calander is available free online at -->
//  <!-- The JavaScript Source!! http://javascript.internet.com -->
//  <!-- Original:  James O'Connor (joconnor@nordenterprises.com) -->
//  <!-- Web Site:  http://nordenterprises.com -->
$title = "$Projects Management - Group Allocation";

include "auth.inc";
include "lastyearSQL.inc";
if ((empty($savePrintGroupAllocation) && empty($saveWebGroupAllocation))) include "headergroups.inc";
if (!empty($saveWebGroupAllocation)) {
    $title="$Projects Software Engineering Project Groups";
    include "header.inc";
}
$currdir = exec("pwd");
$ip =   $_SERVER['REMOTE_ADDR'];
$browser =$HTTP_USER_AGENT;

$PageDisplayed="GA1";

$checkYearOfModule_SQL="select year from modulesLookup where modcode='$Projects'";
$checkYearOfModule_Query=mysql_db_query($db,$checkYearOfModule_SQL,$connection);
while ($modyr = @ mysql_fetch_array($checkYearOfModule_Query))
{
    $yearModule=$modyr["year"];
}

if ($yearModule=='7')
{
    $mscSQL1=",activeStudents";
    $mscSQL2=" and activeStudents.uid=studentModules.uid ";
}


if (!empty($savePrintGroupAllocation)) echo "<h1><a name='section-1'>$Projects  Project Group Allocation</a></h1>";
echo "<form name='moduleAssess' method='post'>";
if (!empty($savePrintGroupAllocation) || !empty($saveWebGroupAllocation))
{
   if (!empty($savePrintGroupAllocation))  $PageDisplayed="GA2";
   if (!empty($saveWebGroupAllocation)) $PageDisplayed="GA3";
   
    while (list($userid,$groupalloc) = each($groupChanged))
    {
        if ($groupalloc>0)
        {
             $checkRecordExists_SQL="select * from SEGroups where uid='$userid' and SEGroups.modcode='$Projects'";
             $checkRecordExists_Query=mysql_db_query($db,$checkRecordExists_SQL,$connection);
             if (mysql_num_rows($checkRecordExists_Query)<1)
             {
                $updateGroupAlloc_SQL="insert into SEGroups values ('$userid','$groupalloc','$Projects')";
                mysql_db_query($db,$updateGroupAlloc_SQL,$connection);
             }
            else
            {
                $updateGroupAlloc_SQL="update SEGroups set segroup='$groupalloc' where uid='$userid' and modcode='$Projects'";
                mysql_db_query($db,$updateGroupAlloc_SQL,$connection);
            }
        }
        else
        {
            $updateGroupAlloc_SQL="delete from SEGroups where uid='$userid' and modcode='$Projects'";
            mysql_db_query($db,$updateGroupAlloc_SQL,$connection);
        }
    }
    $groupStats_SQL="select segroup,count(person.uid) as secount from SEGroups,person,studentModules $mscSQL1
    where person.uid=SEGroups.uid and $yearSQL and studentModules.uid=SEGroups.uid $mscSQL2
     and studentModules.modcode='$Projects' and studentModules.modcode=SEGroups.modcode group by segroup order by segroup";
    $groupStatsQuery = mysql_db_query($db,$groupStats_SQL,$connection);
    $linecount=0;
    $pages=1;
    while ($groups = @ mysql_fetch_array($groupStatsQuery))
    {
        if ($linecount==39 && !empty($savePrintGroupAllocation))  {
                $pages++;
                 echo "<br/><h1><a name='section-$pages'>$Projects  Project Group Allocation</a></h1>";
                 $linecount=0;
        }
        $groupno=$groups["segroup"];
        $groupcount=$groups["secount"];
        $linecount++;
        echo " <hr/><h3>Group $groupno</h3>";
        $groupMembers_SQL="select distinct person.*,students.degreecode,students.yearofstudy as secount
                           from SEGroups,person,students,studentModules $mscSQL1 where person.uid=SEGroups.uid
                           and segroup='$groupno' and studentModules.modcode='$Projects' $mscSQL2
                           and $yearSQL
                           and studentModules.modcode=SEGroups.modcode and studentModules.uid=SEGroups.uid
                           and students.uid=person.uid order by surname,forenames";
        $groupMembersQuery = mysql_db_query($db,$groupMembers_SQL,$connection);
        while ($groupmemb = @ mysql_fetch_array($groupMembersQuery))
        {
            $userid=$groupmemb["uid"];
            $surname=$groupmemb["surname"];
            $forenames=$groupmemb["forenames"];
            $linecount++;
            echo "$surname, $forenames ($userid)<br/>";

        }
        if ($groupcount<8 && !empty($savePrintGroupAllocation))
        {
            $cnt=$groupcount-1;
            while ($cnt++<11)
            {
                $linecount++;
                echo " <br/>";
            }
        }
        echo "<h3>Group $groupno has $groupcount members</h3>";
    }
}

if (empty($savePrintGroupAllocation) && empty($saveWebGroupAllocation))  echo "<textarea name='groupcount'  rows=10 class='boxes' ></textarea>";

if (empty($savePrintGroupAllocation) && empty($saveWebGroupAllocation))
{
    echo "<br/><br/><input type='SUBMIT' value='Save and Print Groups' name='savePrintGroupAllocation' STYLE='font-family:arial;
    font-size:small; font-style:bold; background:#000066 none; color:#FFFF93; width:12.5em'>   ";
    echo "<input type='SUBMIT' value='Save and Produce Web Page' name='saveWebGroupAllocation' STYLE='font-family:arial;
    font-size:small; font-style:bold; background:#000066 none; color:#FFFF93; width:15.5em'> <br/><br/>  ";
        echo "<table width='630' border='1' cellspacing='0' cellpadding='1'>";

        ?> <th width="100" scope="col" class="navhead">Name</th>
        <th width="20" scope="col" class="navhead">Group</th>
        <?php

        $groups_SQL="select person.*,students.degreecode,yearofstudy,segroup from (person,students,studentModules)
        left outer join SEGroups on (person.uid=SEGroups.uid and SEGroups.modcode='$Projects')
        where studentModules.uid=person.uid  and students.uid=person.uid and studentModules.modcode='$Projects'
        and $yearSQL order by surname,forenames";
        $groupsQuery = mysql_db_query($db,$groups_SQL,$connection);
        $first=1;
        while ($groups = @ mysql_fetch_array($groupsQuery))
        {
            $userid=$groups["uid"];
            $surname=$groups["surname"];
            $forenames=$groups["forenames"];
            $group=$groups["segroup"];
            $degreecode=$groups["degreecode"];
            $yearofstudy=$groups["yearofstudy"];
            echo "<tr><td align=left class='boxes'><b>$surname, $forenames ($userid) ($degreecode Year:$yearofstudy)</b> </td><td align=center bgcolor='#000066'><input type='text' size=2 class='boxes' value='$group' name='groupChanged[$userid]' onclick='addUpBoxes()' onfocus='addUpBoxes()'  onmouseover='addUpBoxes()' onmouseout='addUpBoxes()'></td></tr>";
        }
    echo "</table>";
    echo "<br/><br/><input type='SUBMIT' value='Save and Print Groups' name='savePrintGroupAllocation' STYLE='font-family:arial;
    font-size:small; font-style:bold; background:#000066 none; color:#FFFF93; width:12.5em'>   ";
    echo "<input type='SUBMIT' value='Save and Produce Web Page' name='saveWebGroupAllocation' STYLE='font-family:arial;
    font-size:small; font-style:bold; background:#000066 none; color:#FFFF93; width:15.5em'>   ";

}
echo "<input type='hidden' name='totalmarks' value=''>";
?>

<?php
 $uplink="Projects.php?Projects=$Projects";
 $uplinktitle="Introduction";
 if (empty($savePrintGroupAllocation) && empty($savePrintGroupAllocation) && empty($saveWebGroupAllocation)) include "footer.inc";
 if (!empty($saveWebGroupAllocation) || !empty($savePrintGroupAllocation)) include "footerprintsave.inc";
?>
