<?php
class markersmax_model extends CI_Model {

    var $markersMaxXpath;
    var $markersMaxXMLFile='../staff/generated/xml/markersMax.xml';
    
     function __construct() {
        parent::__construct();
        $domMarkersMax=new DOMDocument();
        $domMarkersMax->load($this->markersMaxXMLFile);
	
	// Sets xpath to be used for more queries in model.
        $this->markersMaxXpath = new DOMXPath($domMarkersMax);
    }
    

    
    function checkIfMarkersMaxFileExists()
    {
       // This function sees that the required store is in place for formating.
       
        if (file_exists($this->markersMaxXMLFile)) return true; else return false;
    
        
    }
    function getMarkersMax()
    {
       // This function will return whether a total number of markers has been passed.
        $queryMarkersMax = "//marker";
        return $this->markersMaxXpath->query($queryMarkersMax);
    }
    function getMaxForMarker($uid,$markerType)
    {
	// This function will pass all the assignments for that marker and see if it has been attributed to that marker.

        $queryMarkersMax = "//marker[@uid='$uid']";
        $markersMax=$this->markersMaxXpath->query($queryMarkersMax);
        $mkmax=0;
        foreach($markersMax as $mm) if ($mm->getAttribute('uid')==$uid) $mkmax=$mm->getAttribute($markerType);
                
        return $mkmax; 
     
    }
    function saveMarkingMax($marker,$supervisor,$secondMarker)
    {
    
        // This function will save the marking maximums of staff into an xml file.
        $cntMrk=1;
    
        foreach ($marker as $mks) 
        {
            $uid=$mks->getAttribute('uid'); 
            $markers[$cntMrk]=$uid;
            $cntMrk++;
        }
        $cntMrk--;
	// This will determine that you have counted one too many.
	
	
	// This will loop through items that have been attributed in the form. This is to do with supervisor.
        if (isset($supervisor)) while (list($uid,$max) = each($supervisor))
        {   
            $cntSp=0;
            while($cntSp++<$cntMrk) if ($markers[$cntSp]==$uid && $uid!="total") $spIndex=$cntSp;
            $supervisors[$spIndex]=$max;
            $cntSp++;
        }
	
	
	// This does the same as the above loop but is determined by the second marker.
        if (isset($secondMarker)) while (list($uid,$max) = each($secondMarker))
        {
            $cntSM=0;
            while($cntSM++<$cntMrk) if ($markers[$cntSM]==$uid && $uid!="total") $smIndex=$cntSM;
            $secondMarkers[$smIndex]=$max;
        }   

        $dom2 = new DOMDocument('1.0','UTF-8');
        $dom2->formatOutput = true;
        $root = $dom2->createElement ("markersMax");
        $root = $dom2->appendChild ($root);
    
        $cntMrk=1;
        foreach ($marker as $mks) 
        {
            $uid=$mks->getAttribute('uid'); 
            $supMax=$supervisors[$cntMrk];  
            $secondMarkerMax=$secondMarkers[$cntMrk];   
        
            $markerTag = $dom2->createElement ("marker");
            $markerTag = $root->appendChild ($markerTag);
        
            $attr_uid = $dom2->createAttribute ('uid');
            $attr_uid = $markerTag->appendChild ($attr_uid);
            $markerTag->setAttribute('uid', $uid);
        
            $attr_supervisorMax = $dom2->createAttribute ('supervisorMax');
            $attr_supervisorMax = $markerTag->appendChild ($attr_supervisorMax);
            $markerTag->setAttribute('supervisorMax', $supMax);
        
            $attr_secondMarkerMax = $dom2->createAttribute ('secondMarkerMax');
            $attr_secondMarkerMax = $markerTag->appendChild ($attr_secondMarkerMax);
            $markerTag->setAttribute('secondMarkerMax', $secondMarkerMax);
        
            $cntMrk++;  
        }
    
        $dom2->save($this->markersMaxXMLFile);

    }           
    
    
}
