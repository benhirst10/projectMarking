<?php

	function checkFileExists($filename,$message)
	{
	
		if (!file_exists($filename)) die("<h3>Unable to continue as missing  ".$message."</h3>"); 
	}




?>
