<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
      <xsl:template match="projects">
          <xsl:copy>
            <xsl:apply-templates>
              <xsl:sort select="title"/>
            </xsl:apply-templates>
          </xsl:copy>

      </xsl:template>

      <xsl:template match="project">
        <project>
        <xsl:attribute name="label"><xsl:value-of select="@label"/></xsl:attribute>
            <xsl:apply-templates/>
        </project>
      </xsl:template>

      <xsl:template match="project/title">
          <xsl:copy>
            <xsl:apply-templates/>
          </xsl:copy>
      </xsl:template>

      <xsl:template match="project/hidden">
          <xsl:copy>
            <xsl:apply-templates/>
          </xsl:copy>
      </xsl:template>

      <xsl:template match="project/supervisor">
          <xsl:copy>
            <xsl:apply-templates/>
          </xsl:copy>
      </xsl:template>

      <xsl:template match="project/profiles">
          <xsl:copy>
            <xsl:apply-templates/>
          </xsl:copy>
      </xsl:template>

      <xsl:template match="project/supervisor/*">
          <xsl:copy>
            <xsl:apply-templates/>
          </xsl:copy>
      </xsl:template>

      <xsl:template match="project/profiles/*">
          <xsl:copy>
            <xsl:apply-templates/>
          </xsl:copy>
      </xsl:template>


</xsl:stylesheet>
