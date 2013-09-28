<?php
class convenors_model extends Model {

    var $adminFile="../staff/config/xml/administrators.xml";
    var $convenorXpath;

    function convenors_model()
    {
    	// This function initialies the dom xpath so that it can be used for more quering of markers. In doing so it sorts the markers file by marker name.
    
        parent::Model();
    	$doc1 = new DOMDocument;
	$doc1->preserveWhiteSpace = false;
	$doc1->Load($this->adminFile);
	$this->convenorXpath = new DOMXPath($doc1);

    }
	function checkIfAdministrator($uid)
	{
	  // This will return whether the administrator has accessed the page.
	  
	    $query = "//user[@uid=\"$uid\"]";
	    if ($this->convenorXpath->query($query)->length==1) return true;
	    else return false;
	}
}
