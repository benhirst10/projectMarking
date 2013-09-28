<?php
$doc = new DOMDocument;

// We don't want to bother with white spaces
$doc->preserveWhiteSpace = false;

$doc->Load('markingScheme.xml');

$xpath = new DOMXPath($doc);

$query = '//assessment[@id="Diaries"]/component';

$entries = $xpath->query($query);
$assessment="Diaries";

foreach ($entries as $entry) {
  $comp=$entry->getAttribute('id');
  $query = "//assessment[@id=\"$assessment\"]/component[@id=\"$comp\"]/mark/numeric";
  $outof = $xpath->query($query);
  foreach ($outof as $oo) {
  	$outof=$oo->getAttribute('outof');  
  }
}


?>
