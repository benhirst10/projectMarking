                
                <SELECT CLASS="form-inline" onChange="document.markingSetup.calculateTotals.checked=false;displayOwnProjectDiv('div_<?= $stuid ?>','projectChoice[<?= $studentCount?>]');"
        " name="projectChoice[<?= $studentCount?>]">
                <OPTION>Select Choice</OPTION><OPTION <?php if ($projectChoice=="own project") echo "SELECTED";?> VALUE="own project"><?=$ownProjectTitle ?> <?php if (!empty($supervisorOwnChoice)) echo "($supervisorOwnChoice)";?> (Own Project)</OPTION>";
        <OPTGROUP LABEL="Preferences">
