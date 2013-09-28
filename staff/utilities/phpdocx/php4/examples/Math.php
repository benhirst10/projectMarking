<?php
  /**
   * @author 2mdc.com
   * @version 
   */

  /**
    * Functions avaliable
    *   fAddMathEq: use OMML code to insert an equation
    *   fAddMathDocx: obtain the first equation of a DOCX and use it to insert an equation
    *   fAddMathMML: use MathML code to insert an equation
    */

  require_once '../classes/cCreateDocx.inc';

  $objDocx = new cCreateDocx();

  $objDocx->fAddMathEq('<m:oMathPara><m:oMath><m:r><m:t>∪±∞=~×</m:t></m:r></m:oMath></m:oMathPara>');

  $objDocx->fAddMathDocx('../docx/math.docx');

  $objDocx->fCreateDocx('ejemplo_math');

?>