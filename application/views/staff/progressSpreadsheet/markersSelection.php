  <div class="col-sm-7 col-md-5">
 <?php
        echo $xsltMarkersSelectionBoxSupProc->transformToXML( $domMarkersXML );
  	echo $xsltMarkersSelectionBoxSndMarkerProc->transformToXML( $domMarkersXML );
?>
<p class="text-center">	<input type='submit' name='showMarkerList'  class='btn btn-xs btn-link' value='Show Marker List'/></p>
</div>
</div>