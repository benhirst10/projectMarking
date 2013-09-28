<?php
class proposals_model extends CI_Model {


    var $proposalsXpath;  
    var $proposalsSortXSLFile='./../application/xsl/sortProposals.xsl';
    var $proposalsXMLFile='../common/generated/xml/proposals.xml';
    

    function __construct() {
        parent::__construct();
        $proposalsXsltProc = new XSLTProcessor();
        $proposalsXsltProc->importStylesheet( DOMDocument::load($this->proposalsSortXSLFile) );
        $proposalsDom=new DOMDocument();    
        $proposalsDom->load($this->proposalsXMLFile);        
        $result= $proposalsXsltProc->transformToXML($proposalsDom);
        $proposalsDom=new DOMDocument();  
        $proposalsDom->loadXML($result);
        $this->proposalsXpath= new DOMXPath($proposalsDom);        
    }
    

    function checkIfProposalsFileExists()
    {
        // This will still check that the proposals file is found within the directory in which it is placed.
	if (file_exists($this->proposalsXMLFile)) return true; else return false;
    
        
    }

    function findDegreeRestrictions()
    {
             // This will give the number of abreviatted degrees.
	     
	     $queryProfiles = "//project/profiles";
             return $this->proposalsXpath->query($queryProfiles)->length;
    }
    
    
    function getProjectTitleByLabel($projid)
    {
    
    	// This will obtain the projects title.
    
    	$queryProjects="//project[@label='$projid']";
	$projects=$this->proposalsXpath->query($queryProjects);
	$projectTitle="";
	foreach($projects as $prj) $projectTitle.=$this->getProjectTitle($prj->getElementsByTagName('title'));
	return $projectTitle;
    
    }
    
    
    
    function getAllProjectChoices()
    {
        
	// This will obtain the full list of project titles.
	
	$queryProjects="//project";
        return $this->proposalsXpath->query($queryProjects);
    }
    

    function checkIfdegreeRestricted($abreviation,$profiles)
    {
    	// This obtains which degrees are restricting the choices within the file.
            $profs = $profiles->item(0)->getElementsByTagName( "*" );
            $profsFound=0;
            for ( $i = 0; $i < $profs->length; $i++ ) {
                        if ($abreviation==$profs->item( $i )->nodeName) {$profsFound++;$i=$profs->length;}
            }
            return $profsFound;
    }   
   


     function getSupervisorList($supervisors)
     { 
     	
     	// This will obtain a list of staff user names that will be viewed in the interface.
     
        $supids = $supervisors->item(0)->getElementsByTagName( "*" );
        $supidsText=" (";
        for ( $i = 0; $i < $supids->length; $i++ ) {
            if ($i>0) $supidsText.=", ";    
            $supidsText.=$supids->item( $i )->nodeName;
        }
        if ($supidsText=="(") $supidsText="";
        else $supidsText.=")";     
        return $supidsText;
    }
    
    function checkIfSupervisorProject($supervisors,$uid)
    { 
    	// This will see if the specified supervisor has been given.
    
        $supids = $supervisors->item(0)->getElementsByTagName( "*" );
        $foundSup=false;
        for ( $i = 0; $i < $supids->length; $i++ ) {
            if ($supids->item( $i )->nodeName==$uid) $foundSup=true;
        }
        return $foundSup;
    } 
    
    function getProjectTitle($titleTag)                            
    {
    	// This will optain the title of the project.
    
        $projTitle="";
        foreach($titleTag as $ttag) $projTitle=$ttag->nodeValue;  
        return $projTitle;             
    }
    function getHiddenInfo($hiddenTag) 
    {                           
        $hiddenInfo="";
                
        // Sets the hidden information of the project to that which is contained within the xml proposals element.
        foreach($hiddenTag as $htag) $hiddenInfo=$htag->nodeValue;
        if (!empty($hiddenInfo)) $hiddenInfo=" (Hidden: $hiddenInfo)";   
        return $hiddenInfo;     
    }
        
}
?>
