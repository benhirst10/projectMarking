<?php

/**
 * @author
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateFontTable extends cCreateElement {

    static private $rscInstance = NULL;
    protected $xml;

    private function __construct() {

    }

    public function __destruct() {

    }

    public function __toString() {
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateFontTable();
        }
        return self::$rscInstance;
    }

    protected function fGenerateFONT($name= 'Calibri') {
        $this->xml = '<' . cCreateElement::NAMESPACEWORD . ':font ' . cCreateDocx::NAMESPACEWORD . ':name="' . $name . '">__GENERATEFONT__</' . cCreateElement::NAMESPACEWORD . ':font>';
    }

    protected function fGeneratePANOSE1($val = '020F0502020204030204') {
        $this->xml = str_replace('__GENERATEFONT__', '<' . cCreateElement::NAMESPACEWORD . ':panose1 ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':panose1>__GENERATEPANOSE1__', $this->xml);
    }

    protected function fGenerateCHARSET($val = '00') {
        $this->xml = str_replace('__GENERATEPANOSE1__', '<' . cCreateElement::NAMESPACEWORD . ':charset ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':charset>__GENERATECHARSET__', $this->xml);
    }

    protected function fGenerateFAMILY($val = 'swiss') {
        $this->xml = str_replace('__GENERATECHARSET__', '<' . cCreateElement::NAMESPACEWORD . ':family ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':family>__GENERATEFAMILY__', $this->xml);
    }

    protected function fGeneratePITCH($val = '00') {
        $this->xml = str_replace('__GENERATEFAMILY__', '<' . cCreateElement::NAMESPACEWORD . ':pitch ' . cCreateElement::NAMESPACEWORD . ':val="' . $val . '"></' . cCreateElement::NAMESPACEWORD . ':pitch>__GENERATEPITCH__', $this->xml);
    }

    protected function fGenerateSIG($usb0 = 'A00002EF', $usb1 = '4000207B', $usb2 = '00000000', $usb3 = '00000000', $csb0 = '0000009F', $csb1 = '00000000') {
        $this->xml = str_replace('__GENERATEPITCH__', '<' . cCreateElement::NAMESPACEWORD . ':sig ' . cCreateElement::NAMESPACEWORD . ':usb0="' . $usb0 . '" ' . cCreateElement::NAMESPACEWORD . ':usb1="' . $usb1 . '" ' .
                        cCreateElement::NAMESPACEWORD . ':usb2="' . $usb2 . '" ' . cCreateElement::NAMESPACEWORD . ':usb3="' . $usb3 . '" ' . cCreateElement::NAMESPACEWORD . ':csb0="' . $csb0 . '" ' .
                        cCreateElement::NAMESPACEWORD . ':csb1="' . $csb1 . '"></' . cCreateElement::NAMESPACEWORD . ':sig>', $this->xml);
    }

    public function fCreateFont() {
        $this->xml = '';
        $arrArgs = func_get_args();
        if (!empty($arrArgs[0]['name']) && !empty($arrArgs[0]['pitch']) && !empty($arrArgs[0]['usb0']) && !empty($arrArgs[0]['usb1']) && !empty($arrArgs[0]['usb2']) && !empty($arrArgs[0]['usb3'])
                && !empty($arrArgs[0]['csb0']) && !empty($arrArgs[0]['csb1']) && !empty($arrArgs[0]['family']) && !empty($arrArgs[0]['charset']) && !empty($arrArgs[0]['panose1'])) {
            $this->fGenerateFONT($arrArgs[0]['name']);
            $this->fGeneratePANOSE1($arrArgs[0]['panose1']);
            $this->fGenerateCHARSET($arrArgs[0]['charset']);
            $this->fGenerateFAMILY($arrArgs[0]['family']);
            $this->fGeneratePITCH($arrArgs[0]['pitch']);
            $this->fGenerateSIG($arrArgs[0]['usb0'], $arrArgs[0]['usb1'], $arrArgs[0]['usb2'], $arrArgs[0]['usb3'], $arrArgs[0]['csb0'], $arrArgs[0]['csb1']);
        }
        else {
            exit('You`re adding an empty font');
        }
    }

}
?>