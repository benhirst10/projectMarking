<?php

/**
 * @author 2mdc.com
 * @version 
 */
require_once('../classes/cTransformDoc.inc');

$objDocument = new cTransformDoc();
$objDocument->setStrFile('../docx/images.docx');
$objDocument->fGeneratePDF();
?>