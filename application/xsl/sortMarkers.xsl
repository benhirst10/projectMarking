<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
      <xsl:template match="markers">
          <xsl:copy>
            <xsl:apply-templates>
              <xsl:sort select="@surname"/>
	      <xsl:sort select="@firstname"/>
	      <xsl:sort select="@title"/>
            </xsl:apply-templates>
          </xsl:copy>

      </xsl:template>

      <xsl:template match="marker">
        <marker>
        	<xsl:attribute name="uid"><xsl:value-of select="@uid"/></xsl:attribute>
		<xsl:attribute name="firstname"><xsl:value-of select="@firstname"/></xsl:attribute>
		<xsl:attribute name="surname"><xsl:value-of select="@surname"/></xsl:attribute>
		<xsl:attribute name="title"><xsl:value-of select="@title"/></xsl:attribute>
        </marker>
      </xsl:template>




</xsl:stylesheet>
