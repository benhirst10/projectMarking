<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html"
              doctype-public="-//W3C//DTD HTML 4.0 Transitional//EN"/>

<xsl:template match="/">
        <xsl:variable name="markerSelectName">
            <xsl:choose>
                  <xsl:when test="$menuChoice='supervisor'">markerSelected[<xsl:value-of select="$studentCount"/>]</xsl:when>
              <xsl:when test="$menuChoice='secondMarker'">secondMarkerSelected[<xsl:value-of select="$studentCount"/>]</xsl:when>
              <xsl:otherwise>none</xsl:otherwise>
        </xsl:choose>
    </xsl:variable>       
    <SELECT CLASS='selectBox' onChange='document.markingSetup.calculateTotals.checked=false;'>
        <xsl:attribute name="name"><xsl:value-of select="$markerSelectName"/></xsl:attribute>
        <OPTION>Select Choice
        </OPTION>           
        <xsl:for-each select="//marker">
        <xsl:sort select="@surname"/>
        <xsl:sort select="@firstname"/>

        <xsl:variable name="staffid"><xsl:value-of select="@uid"/></xsl:variable>
           <OPTION>
                <xsl:if test="@uid = $marker">
                    <xsl:attribute name="SELECTED">SELECTED</xsl:attribute>
                </xsl:if>       
            <xsl:attribute name="value"><xsl:value-of select="@uid"/></xsl:attribute>
            <xsl:text> </xsl:text>
            <xsl:value-of select="@title"/> 
            <xsl:text> </xsl:text>
            <xsl:value-of select="@firstname"/>
            <xsl:text> </xsl:text>
            <xsl:value-of select="@surname"/> 
           </OPTION>
        </xsl:for-each> 
    </SELECT>
 

    
    
</xsl:template>     


</xsl:stylesheet>
