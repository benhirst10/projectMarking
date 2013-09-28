<div class="panel panel-info">
<div class="panel-heading">
(<?=$studentCount ?>)
<a href="../../../../staff/studentPreferences/projectPreferences.php?stuid=<?=$stuid ?>" target="_blank" class='btn btn-xs btn-link'>

<?=$surname ?>, <?=$forenames ?> (<?=$degreecode ?>, <?=$stuid ?>) </a> <?=$emailedStudent ?>
</div>	
 <label><input type='checkbox' name='hideStudent[<?=$studentCount ?>]' value='<?=$stuid ?>'  <?=$checkedTag ?> class='form-inline'/>Hide</label>
