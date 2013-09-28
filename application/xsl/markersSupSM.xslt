<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html"
              doctype-public="-//W3C//DTD HTML 4.0 Transitional//EN"/>

<xsl:template match="/">
        <xsl:variable name="markerSelectName">
            <xsl:choose>
                  <xsl:when test="$menuChoice='supervisor'">markerSelected</xsl:when>
              <xsl:when test="$menuChoice='secondMarker'">secondMarkerSelected</xsl:when>
              <xsl:otherwise>none</xsl:otherwise>
        </xsl:choose>
    </xsl:variable>       
    <SELECT CLASS='form-control'>
        <xsl:attribute name="name"><xsl:value-of select="$markerSelectName"/></xsl:attribute>
        <OPTION>Select             <xsl:choose>
                  <xsl:when test="$menuChoice='supervisor'">Marker</xsl:when>
              <xsl:when test="$menuChoice='secondMarker'">Second Marker</xsl:when>
              <xsl:otherwise>none</xsl:otherwise>
        </xsl:choose>
        </OPTION>           
        <xsl:for-each select="//marker">
        <xsl:sort select="@surname"/>
        <xsl:sort select="@firstname"/>
        <xsl:variable name="staffid"><xsl:value-of select="@uid"/></xsl:variable>
                <xsl:variable name="marker">
                  <xsl:choose>
                    <xsl:when test="$menuChoice='supervisor'"><xsl:value-of select="document('../../common/generated/xml/markingSetup.xml')//supervision[@supervisor=$staffid]/@supervisor"/></xsl:when>
                    <xsl:when test="$menuChoice='secondMarker'"><xsl:value-of select="document('../../common/generated/xml/markingSetup.xml')//supervision[@secondmarker=$staffid]/@secondmarker"/></xsl:when>
                    <xsl:otherwise>none</xsl:otherwise>
                  </xsl:choose>
                </xsl:variable>
           <xsl:if test="not($staffid='')">      
            <OPTION>
                    <xsl:if test="$staffid = $markerSelected">
                        <xsl:attribute name="SELECTED">SELECTED</xsl:attribute>
                    </xsl:if>       
                <xsl:attribute name="value"><xsl:value-of select="@uid"/></xsl:attribute>
                <xsl:text> </xsl:text>
                <xsl:value-of select="/markers/marker[@uid=$staffid]/@title"/> 
                <xsl:text> </xsl:text>
                <xsl:value-of select="/markers/marker[@uid=$staffid]/@firstname"/>
                <xsl:text> </xsl:text>
                <xsl:value-of select="/markers/marker[@uid=$staffid]/@surname"/> 
            </OPTION>
          </xsl:if>   
        </xsl:for-each> 
    </SELECT>
 

    
    
</xsl:template>     


</xsl:stylesheet>
