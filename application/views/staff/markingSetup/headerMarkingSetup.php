<!DOCTYPE html>
<html lang="en">
  <head>
<html lang="en">
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="shortcut icon" href="../../assets/ico/favicon.png">
<title>Marking Setup</title>

<?php
echo "	<link rel='stylesheet' href='".base_url()."../application/assets/css/jumbotron.css' type='text/css' media='screen'//>\n";
echo "	<link rel='stylesheet' href='".base_url()."../application/dist/css/bootstrap.css' type='text/css' media='screen'/>\n";
echo "	<link rel='stylesheet' href='".base_url()."../application/assets/css/sticky-footer-navbar.css' type='text/css' media='screen'//>\n";
echo "	<link rel='stylesheet' href='".base_url()."../application/css/progress.css' type='text/css' media='screen'//>\n";
?>
<link href="<?= base_url();?>../application/css/markingSetup.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="<?= base_url();?>../application/js/markingSetup.js"></script>
</head>
<body>
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
            <li class="dropdown active">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown">Marking Setup<b class="caret"></b></a>
              <ul class="dropdown-menu">
<?php
$attributes = array('name' => 'markingSetup','class'=>'form-horizontal');
echo "<li>".form_open('staff/markingSetup/saveMarkingSetupProduceCSVEmailInfo',$attributes)."</li>";
echo "<li>".form_submit("submit","Save","class='btn btn-xs btn-link'")."</li>";
echo "<li>".form_submit("prefCSV", "Preferences CSV","class='btn btn-xs btn-link'")."</li>";
echo "<li>".form_submit("supervisorsCSV", "Supervisors CSV","class='btn btn-xs btn-link'")."</li>";
echo "<li>".form_submit("emailAllocations", "Email All Allocations","class='btn btn-xs btn-link'")."</li>";
echo "<li>".form_submit("emailAllocations", "Email Displayed Allocations","class='btn btn-xs btn-link'")."</li>";
echo "<li>".form_submit("emailMissingPreferences", "Email Students who have missing Preferences","class='btn btn-xs btn-link'")."</li>";
?>
              </ul>
			  
            </li>
           <li><a href='../progress/progresspage'  target='_blank'  class='btn btn-link'>Progress Spreadsheet</a></li>

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
        <div class="col-lg-6">
