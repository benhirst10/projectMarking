		<div class="panel panel-warning">

<?php
$feedback = $markingSchemeXsltProc->transformToXML( $domMarkingScheme );
echo htmlspecialchars_decode($feedback,ENT_QUOTES);
?>
</div>