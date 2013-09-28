<?php
require_once 'Spreadsheet/Excel/Writer.php';
$workbook = new Spreadsheet_Excel_Writer();

$format_bold =& $workbook->addFormat();
$format_bold->setBold();

// We need a worksheet in which to put our data
$worksheet =& $workbook->addWorksheet();
// This is our title
$worksheet->write(0, 0, "Profits for Dotcom.Com", $format_bold);
// And now the data
$worksheet->write(0, 0, 0);

?> 
