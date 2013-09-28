<?php

        echo "got here";

        $xsltProc = new XSLTProcessor();
        $xsltProc->importStylesheet( DOMDocument::load('markingSetup.xslt') );

        $html = $xsltProc->transformToXML( DOMDocument::load("projectSetupList.xml") );

        echo $html;


?>
