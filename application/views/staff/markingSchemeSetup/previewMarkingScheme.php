 <?php
        echo "Supervisor: ". $xsltMarkersSelectionBoxSupProc->transformToXML( $domMarkersXML );
  	echo "Second Marker: ".$xsltMarkersSelectionBoxSndMarkerProc->transformToXML( $domMarkersXML );
?>
	<input type='submit' name='showMarkerList' value='Show Marker List'/>
