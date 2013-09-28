<?php
function administrator($uid,$adminFile)
{
    $doc1 = new DOMDocument;
    $doc1->preserveWhiteSpace = false;
    $doc1->Load($adminFile);
    $xpath1 = new DOMXPath($doc1);
    // This will check to see if the user is in the list of administrators.
    $query = "//user[@uid=\"$uid\"]";
    if ($xpath1->query($query)->length==1) return true;
    else return false;
}

?>
