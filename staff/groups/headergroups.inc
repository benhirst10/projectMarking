<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html xmlns:mcs="http://www.mcs.le.ac.uk">
<!--This file is automatically generated. DO NOT EDIT!--><head>

<link rel="icon" href="/favicon.png" type="image/png">
<link type="text/css" rel="stylesheet" title="CS Small" href="/css/csweb-green.css">
<link type="text/css" rel="alternate stylesheet" title="CS Large" href="/css/csweb-lg-green.css">
<style><!--
textarea { width: 100%;  font-size: 115%}


       .heading {font-weight: bold;
        background-color: #A52A2A;
        color: #FFFFB9;
        }

      .navheadgreen {font-weight: bold;
        background-color: green;
        color: #ffffff;}



.boxes {background-color:#FFFF93; font-size: 115%}


       .bkgr {font-style: bold;font-weight: bold; font-size: 115%;
        font-family: Verdana, Arial, Helvetica, Swiss, 'Arial MT', Franklin, 'Humanist 777', sans-serif;
        background-color:#EBE1BC; color:black ;
        padding-left: 0.5em}


      --></style>
<script type="text/javascript">

    goldbullet = new Image ();
    goldbullet.src ="/images/goldbullet.png";

    smallgoldbullet = new Image ();
    smallgoldbullet.src ="/images/smallgoldbullet.png";

    teaching_on = new Image ();
    teaching_on.src ="/images/deptnavbar/teaching_on.gif";

    research_on = new Image ();
    research_on.src ="/images/deptnavbar/research_on.gif";

    people_on = new Image ();
    people_on.src ="/images/deptnavbar/people_on.gif";

    degrees_on = new Image ();
    degrees_on.src ="/images/deptnavbar/degrees_on.gif";

    mcs_on = new Image ();
    mcs_on.src ="/images/deptnavbar/mcs_on.gif";

function addUpBoxes() {
    var highest = 0;
    for(j=0;j<document.moduleAssess.elements.length;j++){
        var formObj=document.moduleAssess.elements[j];
        if(formObj.type.toLowerCase() == "text" && parseInt(formObj.value)>highest) highest=parseInt(formObj.value);
    }
    var groupcount = new Array(highest);
    var output = "";

    for(n=0;n<=highest;n++) groupcount[n]=0;
    for(j=0;j<document.moduleAssess.elements.length;j++){
        var formObj=document.moduleAssess.elements[j];
        if(formObj.type.toLowerCase() == "text"){
         for(n=0;n<=highest;n++)
             if(formObj.value==n) groupcount[n]=groupcount[n]+1;
      }
    }
    for(n=0;n<=highest;n++) output=output+"Group "+n+" has "+groupcount[n]+" members\n";
    document.moduleAssess.groupcount.value=output;
    return true;
}
function linktoind() {

return true;
}
    </script>

</head>
<body onLoad="addUpBoxes();">
<!--
      header bar starts
    --><div id="headerbar"><table class="headertable" width="100%" border="0" cellspacing="0" cellpadding="0" summary="Table used for layout">
    <tr>
      <td rowspan="2">
        <a href="http://www.le.ac.uk/">
          <img alt="University of Leicester" border="0" src="/images/unilogo-ffffff.gif" width="224" height="62" />
        </a>
      </td>
      <td colspan="3"><div align="right"><h1>computer science</h1></div></td>
    </tr>
    <tr>
    <td class="topbarlinks"><p class="newsjobs"><a href="/">HOME</a></p></td>
    <td class="topbarlinks"><p class="newsjobs"><a href="http://www.le.ac.uk/maps/maps.html">MAP</a></p></td>
    <td class="topbarendlinks"><p class="newsjobs"><a href="/enquiries.html">CONTACT</a></p></td>
    </tr>
</table></div>
<!--
      top navigation bar starts : it can be orange, blue, green or
      grey depending on which class you choose - see below
    --><table id="navigbar" class="maincolour" width="100%" border="0" cellspacing="0" cellpadding="0" summary="Table used for layout"><tr>
<td class="leftcorner"><h2><a href="http://www.cs.le.ac.uk/existing.html">FOR EXISTING</a></h2></td>
<td class="navbarbtns"><div class="toplist"><ul>
<li class="first"><a href="https://campus.cs.le.ac.uk/ForStudents/ForStudents.html">Students</a></li>
<li><a href="https://intranet.cs.le.ac.uk/">Staff</a></li>
<li><a href="http://www.cs.le.ac.uk/alumni/">Alumni</a></li>
</ul></div></td>
</tr></table>
<!--
      container for left/right columns and main page starts
    --><table width="100%" border="0" cellspacing="0" cellpadding="0" summary="Table used for layout"><tr>
  <td id="mainpage">
<!--mainpage area begins here--><h2 class="head"><?php echo $title ?></h2>
<?php
    if (!empty($includedfiles)) $commainc=", ";
    $includedfiles=$includedfiles.$commainc."headergroups.inc";
?>
