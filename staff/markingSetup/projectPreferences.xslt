<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html"
              doctype-public="-//W3C//DTD HTML 4.0 Transitional//EN"/>

<xsl:template match="/">
        <xsl:for-each select="//studentChoice[@uid=$stuid]/pref">
            <xsl:variable name="project"><xsl:value-of select="@projid"/></xsl:variable>
	    <a>
	    <xsl:attribute name="href"><xsl:value-of select="$proposals_link"/>#<xsl:value-of select="$project"/></xsl:attribute>
            <xsl:value-of select="document('../../common/generated/xml/proposals.xml')//project[@label=$project]/title"/> 
            <xsl:text> (</xsl:text>
            <xsl:for-each select="document('../../common/generated/xml/proposals.xml')//project[@label=$project]/supervisor/*">
                <xsl:value-of select="local-name()"/><xsl:text> </xsl:text>
            </xsl:for-each> 
            <xsl:text>)</xsl:text>          
            (P<xsl:value-of select="@rank"/>)<br/>
	    </a>
        </xsl:for-each> 
</xsl:template>     


</xsl:stylesheet>
