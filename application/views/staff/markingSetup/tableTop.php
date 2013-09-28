<div class="panel panel-info">
<div class="panel-heading">List Preferences</h4></div>
Hide(Show All:<input type='checkbox' name='showAll' <?php if (!empty($showAll)) echo "CHECKED";?> class='form-inline'/>) 
<br/>Student User id:<input type='radio' name='typeOrder' value='uid' <?php if ($typeOrder=="uid") echo "CHECKED";?>>
Student Alphabetic<input type='radio' name='typeOrder' value='alpha' <?php if ($typeOrder=="alpha") echo "CHECKED";?>>
Supervisor <input type='radio' name='typeOrder' value='supervisor' <?php if ($typeOrder=="supervisor") echo "CHECKED";?>>
2nd Marker <input type='radio' name='typeOrder' value='secondmarker' <?php if ($typeOrder=="secondmarker") echo "CHECKED";?> >
Project <input type='radio' name='typeOrder' value='project' <?php if ($typeOrder=="project") echo "CHECKED"; ?> >
<br/>Not saved preference display (e.g. 2): <input type='text' name='prefDisplay' maxlength = '4' size = '3' value='<?=$prefDisplay ?>'>
<br/>List Preferences:<input type='checkbox' name='allPref' <?php if (!empty($allPref)) echo "CHECKED";?> /><br/>
</div>