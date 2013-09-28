<?php
class markers_model extends Model {

    var $markersXpath;   
    var $markersSortXSLFile='./../application/xsl/sortMarkers.xsl';
    var $markersXMLFile='../common/generated/xml/markers.xml';
    var $domMarkersXML;
    var $xsltMarkersSelectionBoxSupProc;
    var $xsltMarkersSelectionBoxSndMarkerProc;
    var $markersSelectionBoxXSLFile='./../application/xsl/markersSupSM.xslt';

    function markers_model()
    {
    	// This function initialies the dom xpath so that it can be used for more quering of markers. In doing so it sorts the markers file by marker name.
    
        parent::Model();

        $markersXsltProc = new XSLTProcessor();
        $markersXsltProc->importStylesheet( DOMDocument::load($this->markersSortXSLFile) );
        $domMarkersXML=new DOMDocument();    
        $domMarkersXML->load($this->markersXMLFile);        
	
	// Sorts the markers xml file by marker name.
        $result= $markersXsltProc->transformToXML($domMarkersXML);
        $this->domMarkersXML=new DOMDocument();
	
	// Retrieves the sorted xml file so that it can be used by xpath.  
        $this->domMarkersXML->loadXML($result);
	
	// Sets xpath to be used for more queries in model.
        $this->markersXpath = new DOMXPath($this->domMarkersXML);
	
	$this->xsltMarkersSelectionBoxSupProc = new XSLTProcessor();	
	$this->xsltMarkersSelectionBoxSndMarkerProc = new XSLTProcessor();
    }
    
    function getMarkers()
    {
    	// This function returns a full list of markers it has obtained by xpath.
    
        $queryMarkers = "//marker";
        return $this->markersXpath->query($queryMarkers);
    
    }
    
    function getMarkerName($uid)
    {
        // This will format the marker name in terms of that which is required from the graphical user interface.
       
        $markerName="";
	$queryMarkers = "//marker[@uid='$uid']";
        $markerDetails=$this->markersXpath->query($queryMarkers);   
	
	foreach ($markerDetails as $md) $markerName.=$md->getAttribute('title')." ".$md->getAttribute('firstname')." ".$md->getAttribute('surname');
	
    	return $markerName;
    }
    
    
    function getDomMarkersXML()
    {
    	// This will obtain the name of markers.
    
    	return $this->domMarkersXML;
    }
    
    
    function setMarkersSelectionBoxXSL()
    {
    	
	// This will set the transform sheet that is required for the display in the interface.
	
	$domMarkersSelectionBoxXSL=new DOMDocument(); 
	$domMarkersSelectionBoxXSL->load($this->markersSelectionBoxXSLFile);    
        $this->xsltMarkersSelectionBoxSupProc->importStylesheet( $domMarkersSelectionBoxXSL );  
	$this->xsltMarkersSelectionBoxSndMarkerProc->importStylesheet( $domMarkersSelectionBoxXSL );    
    }
    
    function setTransformForSupervisorSelectionBox($supervisor,$showAllStudents)
    {
    	// This will set the transform sheet that is required for the display of specific supervisors.
    
	if (empty($supervisor) && empty($showAllStudents)) $supervisor=$_SERVER["PHP_AUTH_USER"];
        $this->xsltMarkersSelectionBoxSupProc->setParameter('','markerSelected',$supervisor); 
        $this->xsltMarkersSelectionBoxSupProc->setParameter('','menuChoice','supervisor');
    	return $this->xsltMarkersSelectionBoxSupProc;
    }
    
    function setTransformForSndMarkerSelectionBox($secondMarker,$showAllStudents)
    {
    	// This will set the transform sheet that is required for the display of specific second markers.
    
        $this->xsltMarkersSelectionBoxSndMarkerProc->setParameter('','markerSelected',$secondMarker); 
        $this->xsltMarkersSelectionBoxSndMarkerProc->setParameter('','menuChoice','secondMarker');
    	return $this->xsltMarkersSelectionBoxSndMarkerProc;
    }    

    function checkIfMarkersFileExists()
    {
	// This function checks whether the markers xml file exists.
	
        if (file_exists($this->markersXMLFile)) return true; else return false;
    
        
    }
    
    
}
