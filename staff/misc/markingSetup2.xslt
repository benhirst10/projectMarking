<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html"
              doctype-public="-//W3C//DTD HTML 4.0 Transitional//EN"/>
              
<xsl:template match="/" xml:space="preserve">
        <xsl:apply-templates/>
</xsl:template>

<xsl:template match="/student">
                <xsl:apply-templates select="student"/>
                // set variable to that which has been saved depending on which file it is into.
</xsl:template>

<xsl:template match="student">
    <xsl:variable name="studentUid"><xsl:value-of select="@uid"/></xsl:variable>
    <xsl:variable name="projectSetup"><xsl:value-of select="projectSetup/@label"/></xsl:variable>
    <xsl:variable name="studentCount"><xsl:value-of select="position()" /></xsl:variable>

    <tr><td>
    <xsl:apply-templates select="supervisor">
            <xsl:with-param name="supervisorId" select="supervisor/@id"/>
            <xsl:with-param name="studentCount" select="$studentCount"/>
    </xsl:apply-templates>
    </td>
    <td>
    <xsl:apply-templates select="secondMarker">
            <xsl:with-param name="secondMarkeId" select="secondMarker/@id"/>
            <xsl:with-param name="studentCount" select="$studentCount"/>
    </xsl:apply-templates>
    </td>

    <td><xsl:value-of select="@surname"/><xsl:text>, </xsl:text> <xsl:value-of select="@forenames"/>
    <xsl:text>(</xsl:text> <xsl:value-of select="@candidate_number"/><xsl:text>, </xsl:text><xsl:value-of select="@degreecode"/><xsl:text>)</xsl:text> </td>
// set a variable up to hold the preference that has been chosen

    <td><SELECT CLASS="selectBox" onChange='document.markingSetup.calculateTotals.checked=false;'>
     <xsl:attribute name="name">projectChoice[<xsl:value-of select="$studentCount"/>]</xsl:attribute>
     <optgroup label="Project Menu">
        <OPTION>Select Choice
        </OPTION>

        <xsl:for-each select="/student[@uid=$studentUid]/preferences">
           <OPTION>

            <xsl:if test="@flagForChosen">
                <xsl:variable name="flagForChosenPref"><xsl:value-of select="@label"/></xsl:variable>
                <xsl:attribute name="SELECTED">SELECTED</xsl:attribute>
            </xsl:if>
            <xsl:attribute name="value"><xsl:value-of select="@label"/></xsl:attribute><xsl:value-of select="title"/>
            </OPTION>
        </xsl:for-each>

        <xsl:for-each select="//project">
          <OPTION>
            <xsl:if test="$projectSetup=@label and $flagForChosenPref=''">
                <xsl:attribute name="SELECTED">SELECTED</xsl:attribute>
            </xsl:if>
            <xsl:if test="$flagForChosenPref<>@label">
                <xsl:attribute name="value"><xsl:value-of select="@label"/></xsl:attribute><xsl:value-of select="title"/>
            </xsl:if>
          </OPTION>
        </xsl:for-each>
    </SELECT></td></tr>
</xsl:template>
// When it has been gathered that a preference has been chosen we need to exclude this choice from the other possible projects.

<xsl:template match="supervisor">
    <xsl:param name="supervisorId" select="0"/>
    <xsl:param name="studentCount" select="0"/>
     <SELECT CLASS='selectBox' onChange='document.markingSetup.calculateTotals.checked=false;'>
       <xsl:attribute name="name">markerSelected[<xsl:value-of select="$studentCount"/>]</xsl:attribute>
        <OPTION>Select Choice
        </OPTION>
        <xsl:for-each select="//markers">
            <xsl:sort select="@surname"/>
            <xsl:sort select="@firstname"/>
            <xsl:if test="$supervisorId=@uid">
                <xsl:attribute name="SELECTED">SELECTED</xsl:attribute>
            </xsl:if>
            <xsl:attribute name="value"><xsl:value-of select="@uid"/></xsl:attribute><xsl:value-of select="@surname"/><xsl:text>, </xsl:text><xsl:value-of select="@firstname"/><xsl:text> (</xsl:text><xsl:value-of select="@uid"/> <xsl:text>) </xsl:text>
        </xsl:for-each>
     </SELECT>
</xsl:template>

<xsl:template match="secondMarker">
    <xsl:param name="secondMarkeId" select="0"/>
    <xsl:param name="studentCount" select="0"/>
     <SELECT CLASS='selectBox' onChange='document.markingSetup.calculateTotals.checked=false;'>
       <xsl:attribute name="name">secondMarkerSelected[<xsl:value-of select="$studentCount"/>]</xsl:attribute>
        <OPTION>Select Choice
        </OPTION>
        <xsl:for-each select="//markers">
            <xsl:sort select="@surname"/>
            <xsl:sort select="@firstname"/>
            <xsl:if test="$supervisorId=@uid">
                <xsl:attribute name="SELECTED">SELECTED</xsl:attribute>
            </xsl:if>
            <xsl:attribute name="value"><xsl:value-of select="@uid"/></xsl:attribute><xsl:value-of select="@surname"/><xsl:text>, </xsl:text><xsl:value-of select="@firstname"/><xsl:text> (</xsl:text><xsl:value-of select="@uid"/> <xsl:text>) </xsl:text>
        </xsl:for-each>
     </SELECT>
</xsl:template>

</xsl:template>


//<xsl:template match="projects">
// Possibility of non matching tags when formulated not within the student match (Compile error possibility). This may be got over by instead including the expectant loop within the student match.

// Pass values into to show which is preferred or already setup and it is
// wanted to show preferences and also projects
// from one select box.

// Loop through all project proposals and set the preference that has not been saved.
// If a preference has not been saved or no attributed set up items which are preferences, should be flagged as being selected.

//</xsl:template>
