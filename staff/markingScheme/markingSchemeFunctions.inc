<?php
function findOutOf($assessment,$comp,$markingScheme)
{
// This will retrieve the out of for a particular assessment component
    $doc = new DOMDocument;
    $doc->preserveWhiteSpace = false;
    $doc->Load($markingScheme);
    $xpath = new DOMXPath($doc);
    $query = "//assessment[@id=\"$assessment\"]/component[@id=\"$comp\"]/mark/numeric";
    $outOf=0;
    $outofs = $xpath->query($query);
    foreach ($outofs as $oo) $outOf=$outOf+$oo->getAttribute('outof');
    return $outOf;
}
function checkGroupAssessed($assessment,$comp,$markingScheme)
{
// This will retrieve the out of for a group assessessed component.
    $doc = new DOMDocument;
    $doc->preserveWhiteSpace = false;
    $doc->Load($markingScheme);
    $xpath = new DOMXPath($doc);
    $query = "//assessment/component/@groupAssessed";
    $outOf=0;
    $outofs = $xpath->query($query);
    foreach ($outofs as $oo) $outOf=$outOf+$oo->getAttribute('outof');
    return $outOf;
}
?>
