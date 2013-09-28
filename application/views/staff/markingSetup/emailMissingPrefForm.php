<?php
$attributes = array('name' => 'emailMissingPreferences');
echo form_open('staff/markingSetup/emailMissingPreferences',$attributes);
$data = array(
              'name'        => 'emailSubject',
              'id'          => 'emailSubject',
              'value'       => $modcode.' Project Preferences',
              'rows'   	    => '3',
              'cols'        => '100',
	      'class'	    => 'boxes', 
              'style'       => 'width:50%',
            );
	    
	    
$emailSubject=form_textarea($data);


$data = array(
              'name'        => 'emailBody',
              'id'          => 'emailBody',
              'value'       => 'You have not yet submitted your preferences for the project.',
              'rows'   	    => '10',
              'cols'        => '100',
	      'class'	    => 'boxes', 
              'style'       => 'width:50%',
            );
	    
	    
$emailBody=form_textarea($data);
$emailSubmit=form_submit('Email','Email');
$emailCancel=form_submit('Cancel','Cancel');
	     
$tmpl = array (
                    'table_open'          => '<table border="0" cellpadding="4" cellspacing="0" class="heading5">',

                    'heading_row_start'   => '<tr class="heading">',
                    'heading_row_end'     => '</tr>',
                    'heading_cell_start'  => '<th align=center colspan=2>',
                    'heading_cell_end'    => '</th>',

                    'row_start'           => '<tr>',
                    'row_end'             => '</tr>',
                    'cell_start'          => '<td align=center>',
                    'cell_end'            => '</td>',

                    'row_alt_start'       => '<tr>',
                    'row_alt_end'         => '</tr>',
                    'cell_alt_start'      => '<td align=center>',
                    'cell_alt_end'        => '</td>',

                    'table_close'         => '</table>'
              );

$this->table->set_template($tmpl);  
$this->table->set_heading(array('Email Students who have not submitted Preferences.'));
$data = array(
             array('Subject:', $emailSubject),
             array('Body:', $emailBody),
             array($emailSubmit.$emailCancel,"&nbsp")
             );
echo $this->table->generate($data); 


echo form_close();
echo "</body></html>";
?>
