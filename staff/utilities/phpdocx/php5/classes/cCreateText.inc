<?php

/**
 * @author 2mdc.com
 * @version 
 */
include_once dirname(__FILE__) . '/cCreateElement.inc';

class cCreateText extends cCreateElement {
    const IDTITLE = 229998237;
    static private $rscInstance = NULL;
    static private $intIdTitle = 0;

    private function __construct() {

    }

    public function __destruct() {

    }

    public function __toString() {
        return $this->xml;
    }

    static public function getInstance() {
        if (self::$rscInstance == NULL) {
            self::$rscInstance = new cCreateText();
        }
        return self::$rscInstance;
    }

    protected function fGenerateB($strVal = 'single') {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':b ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':b>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateCOLOR($strVal = '000000') {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':color ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':color>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateJC($strVal = '') {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':jc ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':jc>__GENERATESZ__', $this->xml);
    }

    protected function fGenerateI($strVal = 'single') {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':i ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':i>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateSZ($strVal = '11') {
        $strVal *= 2;
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':sz ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':sz>__GENERATERPR__', $this->xml);
    }

    protected function fGenerateU($strVal = 'single') {
        $this->xml = str_replace('__GENERATERPR__', '<' . cCreateElement::NAMESPACEWORD . ':u ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':u>__GENERATERPR__', $this->xml);
    }

    protected function fGeneratePSTYLE($strVal = 'Ttulo') {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':pStyle ' . cCreateElement::NAMESPACEWORD . ':val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':pStyle>__GENERATEPPR__', $this->xml);
    }

    protected function fGeneratePAGEBREAKBEFORE($strVal = 'on') {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':pageBreakBefore val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':pageBreakBefore>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateWIDOWCONTROL($strVal = 'on') {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':widowControl val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':widowControl>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateWORDWRAP($strVal = 'on') {
        $this->xml = str_replace('__GENERATEPPR__', '<' . cCreateElement::NAMESPACEWORD . ':wordWrap val="' . $strVal . '"></' . cCreateElement::NAMESPACEWORD . ':wordWrap>__GENERATEPPR__', $this->xml);
    }

    protected function fGenerateBOOKMARKSTART($intId, $name) {
        $this->xml = str_replace('__GENERATER__', '<' . cCreateElement::NAMESPACEWORD . ':bookmarkStart ' . cCreateElement::NAMESPACEWORD . ':id="' . $intId . '" ' . cCreateElement::NAMESPACEWORD . ':name="' . $name . '"></' . cCreateElement::NAMESPACEWORD . ':bookmarkStart>__GENERATER____GENERATEBOOKMARKEND__', $this->xml);
    }

    protected function fGenerateBOOKMARKEND($intId) {
        $this->xml = str_replace('__GENERATEBOOKMARKEND__', '<' . cCreateElement::NAMESPACEWORD . ':bookmarkEnd ' . cCreateElement::NAMESPACEWORD . ':id="' . $intId . '"></' . cCreateElement::NAMESPACEWORD . ':bookmarkEnd>', $this->xml);
    }

    public function fCreateTitle() {
        $this->xml = '';
        $arrArgs = func_get_args();
        if (!empty($arrArgs[1]['val']) && !empty($arrArgs[0])) {
            $this->fGenerateP();
            $this->fGeneratePPR();
            if ($arrArgs[1]['type'] == 'subtitle')
                $this->fGeneratePSTYLE('Subttulo' . $arrArgs[1]['val']);
            else
                $this->fGeneratePSTYLE('Ttulo' . $arrArgs[1]['val']);
            if (!empty($arrArgs[1]['pageBreakBefore']))
                $this->fGeneratePAGEBREAKBEFORE($arrArgs[1]['pageBreakBefore']);
            if (!empty($arrArgs[1]['widowControl']))
                $this->fGenerateWIDOWCONTROL($arrArgs[1]['widowControl']);
            if (!empty($arrArgs[1]['wordWrap']))
                $this->fGenerateWORDWRAP($arrArgs[1]['wordWrap']);
            self::$intIdTitle++;
            $this->fGenerateBOOKMARKSTART(self::$intIdTitle, '_Toc' . (self::$intIdTitle + self::IDTITLE));
            $this->fGenerateR();
            if ($arrArgs[1]['b'] != '' || $arrArgs[1]['i'] != '' || $arrArgs[1]['u'] != '' || $arrArgs[1]['sz'] != '' || $arrArgs[1]['color'] != '' || $arrArgs[1]['font'] != '') {
                $this->fGenerateRPR();
                if ($arrArgs[1]['font'] != '') {
                    $this->fGenerateRFONTS($arrArgs[1]['font']);
                }
                if ($arrArgs[1]['b'] != '') {
                    $this->fGenerateB($arrArgs[1]['b']);
                }
                if ($arrArgs[1]['i'] != '') {
                    $this->fGenerateI($arrArgs[1]['i']);
                }
                if ($arrArgs[1]['u'] != '') {
                    $this->fGenerateU($arrArgs[1]['u']);
                }
                if ($arrArgs[1]['sz'] != '') {
                    $this->fGenerateSZ($arrArgs[1]['sz']);
                }
                if ($arrArgs[1]['color'] != '') {
                    $this->fGenerateCOLOR($arrArgs[1]['color']);
                }
            }
            $this->fGenerateT($arrArgs[0]);
            $this->fGenerateBOOKMARKEND(self::$intIdTitle);
            $this->fCleanTemplate();
        }
        else {
            echo 'You didn`t add the text or the title type';
            return false;
        }
    }

    public function fCreateText() {
        $this->xml = '';
        $arrArgs = func_get_args();

        $this->fGenerateP();
        if (!empty($arrArgs[1]['jc']) || !empty($arrArgs[1]['pageBreakBefore']) || !empty($arrArgs[1]['widowControl']) || !empty($arrArgs[1]['wordWrap'])) {
            $this->fGeneratePPR();
            if (!empty($arrArgs[1]['jc']))
                $this->fGenerateJC($arrArgs[1]['jc']);
            if (!empty($arrArgs[1]['pageBreakBefore']))
                $this->fGeneratePAGEBREAKBEFORE($arrArgs[1]['pageBreakBefore']);
            if (!empty($arrArgs[1]['widowControl']))
                $this->fGenerateWIDOWCONTROL($arrArgs[1]['widowControl']);
            if (!empty($arrArgs[1]['wordWrap']))
                $this->fGenerateWORDWRAP($arrArgs[1]['wordWrap']);
        }
        $this->fGenerateR();
        if ($arrArgs[1]['b'] != '' || $arrArgs[1]['i'] != '' || $arrArgs[1]['u'] != '' || $arrArgs[1]['sz'] != '' || $arrArgs[1]['color'] != '' || $arrArgs[1]['font'] != '') {
            $this->fGenerateRPR();
            if ($arrArgs[1]['font'] != '') {
                $this->fGenerateRFONTS($arrArgs[1]['font']);
            }
            if ($arrArgs[1]['b'] != '') {
                $this->fGenerateB($arrArgs[1]['b']);
            }
            if ($arrArgs[1]['i'] != '') {
                $this->fGenerateI($arrArgs[1]['i']);
            }
            if ($arrArgs[1]['u'] != '') {
                $this->fGenerateU($arrArgs[1]['u']);
            }
            if ($arrArgs[1]['sz'] != '') {
                $this->fGenerateSZ($arrArgs[1]['sz']);
            }
            if ($arrArgs[1]['color'] != '') {
                $this->fGenerateCOLOR($arrArgs[1]['color']);
            }
        }
        $this->fGenerateT($arrArgs[0]);
    }

}
?>