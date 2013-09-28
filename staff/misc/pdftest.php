<?php
// example creating a basic PDF (A4) document with PHP

 

try {

// create new instance of the 'PDFlib' class

$pdf=new PDFlib();

// open new PDF file

if(!$pdf->begin_document("","")){

throw new PDFlibException("Error creating PDF document. ".$pdf->get_errmsg());

}

  $pdf->set_info("Creator","pdf_example.php");

  $pdf->set_info("Author","Alejandro Gervasio");

$pdf->set_info("Title","Example on using PHP to create PDF docs");


  $pdf->begin_page_ext(595,842,"");

 

  $font=$pdf->load_font("Helvetica-Bold","winansi","");


  $pdf->setfont($font,24.0);

  $pdf->set_text_pos(50,800);

  $pdf->show("PHP is great for creating PDF documents!");

// end page

  $pdf->end_page_ext("");

 

// end document

  $pdf->end_document("");


// get buffer contents

  $buffer=$pdf->get_buffer();

// get length of buffer

  $len=strlen($buffer);

// display PDF document

  header("Content-type: application/pdf");

   header("Content-Length: $len");

   header("Content-Disposition: inline; filename=example.pdf");

 echo $buffer;

}

  catch (PDFlibException $e){

   echo 'Error Number:'.$e->get_errnum()."n";

   echo 'Error Message:'.$e->get_errmsg();

   exit();

}
?>
