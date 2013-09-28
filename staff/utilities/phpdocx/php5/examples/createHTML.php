<?php

/**
 * @author 2mdc.com
 * @version 
 */
require_once('../classes/cTransformDoc.inc');

$objDocument = new cTransformDoc();
$objDocument->setStrFile('../docx/link.docx');
$objDocument->fGenerateXHTML();
$objDocument->fValidatorXHTML();
echo $objDocument->getStrXHTML();
?>