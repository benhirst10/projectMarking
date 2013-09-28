<th colspan="4"><a href='progresspage?assessment=<?php echo $assessment; ?>&sortSpread=<?php echo $sortSpread; ?>&showAllStudents=yes' class='btn btn-xs btn-link'>Show all students</a><br/><br/>
<?php
if (!empty($markerSelected)) 
	echo "<a href='progresspage?assessment=$assessment&markerSelected=$markerSelected&sortSpread=$sortSpread' class='btn btn-xs btn-link'>Show all supervisor $markerSelected 
	students</a><br/>";
if (!empty($secondMarkerSelected)) 
	echo  "<br/><a href='progresspage?assessment=$assessment&secondMarkerSelected=$secondMarkerSelected&sortSpread=$sortSpread' class='btn btn-xs btn-link'>
	Show all 2nd Marker $secondMarkerSelected students</a><br/>";
	
if (!empty($secondMarkerSelected) && !empty($markerSelected)) 
	echo "<br/><a 		
href='progresspage?assessment=$assessment&markerSelected=$markerSelected&secondMarkerSelected=$secondMarkerSelected&sortSpread=$sortSpread' class='btn btn-xs btn-link'>
	Show both supervisor and second marker students</a>";
?>
	    
</th>
