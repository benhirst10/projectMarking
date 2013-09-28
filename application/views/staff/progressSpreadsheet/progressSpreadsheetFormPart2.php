  <input type='hidden' name='assessment' value='<?=$assessment ?>'\>
 
  <?php
  
    echo form_close();
    
   ?>
 </tbody>
</table>
</div>
</div>
</div>
<?php
echo "	<script type='text/javascript' src='".base_url()."../application/assets/js/jquery.js'></script>\n";
echo "	<script type='text/javascript' src='".base_url()."../application/dist/js/bootstrap.min.js'></script>\n";
?>
<script type="text/javascript">
//<![CDATA[
base_url = '<?php echo base_url();?>index.php/';
//]]>
</script>
<script type="text/javascript" src="<?php echo base_url();?>../application/js/progress.js"></script>
</body>
</html>