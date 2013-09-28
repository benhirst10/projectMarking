<?php
    error_reporting(0); 
    include "markingSchemeDB.inc";
    
    $html="<form name='markingScheme' action='markingSchemeSave.php' method='post' onSubmit=\"return addUpMarkBoxes();\">
          <table border='2'>
          <tr><td colspan='3' align='center'><input type='submit' name='checkScheme' value='Next'/></td></tr>"; 

        $xsltProc = new XSLTProcessor();
    // This will load the present stylesheet for marking schemes 
    $xsltProc->importStylesheet( DOMDocument::load('../../common/xslt/markingScheme.xslt') ); 
    $xsltProc->setParameter('','componentid','_all_'); 
    $xsltProc->setParameter('','componentVal',''); 
    $xsltProc->setParameter('','choiceVal',''); 
    $xsltProc->setParameter('','numericVal','');       
    $xsltProc->setParameter('','assid','_all_');
    $xsltProc->setParameter('','entryReport','entry');
    // This will process marking scheme using the sylesheet to give a preview of the whole marking scheme.
    $html .= $xsltProc->transformToXML( DOMDocument::load('../config/xml/markingScheme.xml') );
    $html .="</table>";
    $html .="</form>";
    echo $html;
?>
