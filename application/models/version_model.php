<?php
class version_model extends Model {

    var $versionXpath;
    var $versionXMLFile="../common/config/xml/version.xml";
    var $student_type="undergraduate";
    var $proposals_link="https://intranet.cs.le.ac.uk/teaching/2010-11/ug-proj-proposals/projects";
    var $student_proposals_link="https://campus.cs.le.ac.uk/teaching/resources/CO3015/proposals/10-11/projects.xml";
    var $svn_repos="https://intranet.cs.le.ac.uk/studentviewcvs/cgi-bin/viewcvs.cgi/?root=";

    function version_model()
    {
        parent::Model();
        $versionDom = new DOMDocument;
        $versionDom->preserveWhiteSpace = false;
        $versionDom->Load($this->versionXMLFile);
        $this->versionXpath = new DOMXPath($versionDom);
                
    }
    
    function getVersionInfo()
    {
  
        // This will find information about which version of the marking scheme is in use. It will also obtain links to proposal files.
        $query = "//version";
        return $this->versionXpath->query($query);
    
    }
    
   
    function saveVersionInfo()
    {
        $student_type="undergraduate";
        $proposals_link="https://intranet.cs.le.ac.uk/teaching/2010-11/ug-proj-proposals/projects";
        $student_proposals_link="https://campus.cs.le.ac.uk/teaching/resources/CO3015/proposals/10-11/projects.xml";
        $svn_repos="https://intranet.cs.le.ac.uk/studentviewcvs/cgi-bin/viewcvs.cgi/?root=";

        $doc = new DOMDocument;
        $doc->preserveWhiteSpace = false;
        $doc->Load($versionXMLFile);
        $xpath = new DOMXPath($doc);
        $query = "//version";    
        $entries = $xpath->query($query);
        foreach ($entries as $version) 
        {
            $fileno=$version->getAttribute('fileno');
            $student_type=$version->getAttribute('student_type');
            $proposals_link=$version->getAttribute('proposals_link');
            $student_proposals_link=$version->getAttribute('student_proposals_link');
            $svn_repos=$version->getAttribute('repository');
        }    
    
        $dom = new DOMDocument('1.0','UTF-8');
        $dom->formatOutput = true;
        $root = $dom->createElement ("markingScheme");
        $root = $dom->appendChild ($root);
        $version = $dom->createElement ("version");
        $version = $root->appendChild ($version);
        $attr_p = $dom->createAttribute ('file');
        $version->setAttribute('file', $markschemeFileName);
        $attr_p = $dom->createAttribute ('dateCreated');
        $today = date("Y-m-d");    
        $version->setAttribute('dateCreated', $today);  
        $attr_p = $dom->createAttribute ('fileno');
        $version->setAttribute('fileno', $fileno);      
        
        $attr_p = $dom->createAttribute ('student_type');
        $version->setAttribute('student_type',$student_type);       
        
        $attr_p = $dom->createAttribute ('student_proposals_link');
        $version->setAttribute('student_proposals_link',$student_proposals_link);
        
        $attr_p = $dom->createAttribute ('proposals_link');
        $version->setAttribute('proposals_link',$proposals_link);
        
        $attr_p = $dom->createAttribute ('repository');
        $version->setAttribute('repository',$svn_repos); 
        $dom->save("../../common/config/xml/version.xml");               
    }
    
}
