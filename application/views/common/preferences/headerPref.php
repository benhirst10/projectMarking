<!DOCTYPE html>
<html lang="en">
  <head>
<html lang="en">
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="shortcut icon" href="../../assets/ico/favicon.png">
<title><?php $modcode ?> Progress Monitoring</title>

<?php
echo "	<link rel='stylesheet' href='".base_url()."../application/assets/css/jumbotron.css' type='text/css' media='screen'//>\n";
echo "	<link rel='stylesheet' href='".base_url()."../application/dist/css/bootstrap.css' type='text/css' media='screen'/>\n";
echo "	<link rel='stylesheet' href='".base_url()."../application/assets/css/sticky-footer-navbar.css' type='text/css' media='screen'//>\n";
echo "	<link rel='stylesheet' href='".base_url()."../application/css/progress.css' type='text/css' media='screen'//>\n";
?>
<script type="text/javascript" src="<?= base_url();?>../application/js/preferences.js"></script>


</head>
<body onLoad="addUpMarkBoxes();">
    <div class="navbar navbar-inverse navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>

        </div>
        <div class="navbar-collapse collapse">
          <ul class="nav navbar-nav">
            <li class="active"><a href="#">Student Preferences</a></li>
         <!--  <li><a href='../markingSetup/markingSetupPage'  target='_blank'  class='btn btn-link'>Setup marking and project list</a></li>
            <li class="dropdown">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown">Setup<b class="caret"></b></a>
              <ul class="dropdown-menu">
               <li><a href='<?php echo base_url();?>../staff/markingScheme/markingSchemeSetupAssessments.php' target='_blank'  class='btn btn-link'>Setup assessments using markingScheme.xml</a></li> 
                <li><a href='../markingSetup/markingSetupPage'  target='_blank'  class='btn btn-link'>Setup marking and project list</a></li>
              </ul>
			  
            </li>-->
          </ul>
		  <!--
          <form class="navbar-form navbar-right">
            <div class="form-group">
              <input type="text" placeholder="Email" class="form-control">
            </div>
            <div class="form-group">
              <input type="password" placeholder="Password" class="form-control">
            </div>
            <button type="submit" class="btn btn-success">Sign in</button>
          </form>-->
        </div><!--/.navbar-collapse -->
      </div>
    </div>
    <div class="container">
      <!-- Example row of columns -->
      <div class="row">
		<br/><br/><br/><br/><br/>
		
      </div>

    </div>	
    <div class="container">
      <!-- Example row of columns -->
      <div class="row">
        <div class="col-lg-12">
<h1>Project Preference Page</h1>
<p>Please save your preferences before <b><?=$dateClose?> <?=$timeClose?>.</b> To ensure that you have properly <b>saved</b> your preferences, <b>a list should appear at
 the top of the page</b> showing your preferences. To <b>select preferences</b>, click on four different project preference radio 
 buttons and then press the save button. It is possible to re-save different preferences before the deadline.</p>
<div class='table-responsive'>
<TABLE class='table'>


                   <tbody>


                   <form  name='projectform' method='post' onSubmit='return checkformradio( );' class='form-horizontal'>
               <tr><td colspan='5' align=center><INPUT type='submit' value='Save' name='Save' class'btn btn-xs btn-link'></td></tr>