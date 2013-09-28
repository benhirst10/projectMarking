
<input type='text' name='previousTypeOrder' readonly value='<?=$typeOrder ?>'/>
<input type='text' name='sessionStamp' readonly value='<?= $sessionStamp ?>'/>

<?php 

echo form_submit("submit","Save","class='btn btn-xs btn-link'");
echo form_close();



?>
 </div>


