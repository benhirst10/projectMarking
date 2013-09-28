                </OPTGROUP></SELECT>
        
        <DIV ID="div_<?= $stuid ?>" NAME="div_<?= $stuid ?>" STYLE="display:<?php if ($projectChoice=="own project") echo "block;"; else echo "none;";?>;">
        
        <br/>Title:<br/><INPUT TYPE="text" CLASS='boxes' SIZE="110" NAME="ownProject[<?=$studentCount ?>]" VALUE="<?=$ownProjectTitle ?>"/>
        
        </DIV>
</div>
        
