<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html"
              doctype-public="-//W3C//DTD HTML 4.0 Transitional//EN"/>

<xsl:template match="/">
    
    <SELECT CLASS="selectBox" onChange='document.markingSetup.calculateTotals.checked=false;'>
     <xsl:attribute name="name">projectChoice[<xsl:value-of select="$studentCount"/>]</xsl:attribute>
     <optgroup label="Project Menu">
        <OPTION>Select Choice
        </OPTION>  
               
        <optgroup label=" Preferences">
        <xsl:for-each select="//studentChoice[@uid=$stuid]/pref">
            <xsl:variable name="project"><xsl:value-of select="@projid"/></xsl:variable>
           <OPTION>
                <xsl:if test="$project = $projectChoice">
                    <xsl:attribute name="SELECTED">SELECTED</xsl:attribute>
                </xsl:if>       
            <xsl:attribute name="value"><xsl:value-of select="@projid"/></xsl:attribute>
            <xsl:text>  </xsl:text>
            <xsl:value-of select="document('../../common/generated/xml/proposals.xml')//project[@label=$project]/title"/> 
            <xsl:text> (</xsl:text>
            <xsl:for-each select="document('../../common/generated/xml/proposals.xml')//project[@label=$project]/supervisor/*">
                <xsl:value-of select="local-name()"/><xsl:text> </xsl:text>
            </xsl:for-each> 
            <xsl:text>)</xsl:text>          
            (P<xsl:value-of select="@rank"/>)<xsl:value-of select="$notSaved"/>   
           </OPTION>
        </xsl:for-each> 
        </optgroup>  
        <optgroup label=" All Choices">
         <xsl:for-each select="document('../../common/generated/xml/proposals.xml')//project">
            <xsl:variable name="projectLabel"><xsl:value-of select="@label"/></xsl:variable>
	     <xsl:variable name="hiddenVal"><xsl:value-of select="hidden/."/></xsl:variable>
          <xsl:if test="document('../../common/generated/xml/projects.xml')//project[@label=$projectLabel]/degree/@id=$degreecode or $degreecode='' or $degreecode='_all_'">      
             <xsl:if test="$projectLabel!='' and $hiddenVal=''">   
             <OPTION>
                <xsl:if test="$projectLabel = $projectChoice and $prefNo=0">
                     <xsl:attribute name="SELECTED">SELECTED</xsl:attribute>
                </xsl:if>  
                 <xsl:attribute name="value"><xsl:value-of select="$projectLabel"/></xsl:attribute>
                  <xsl:text>  </xsl:text>
                   <xsl:value-of select="document('../../common/generated/xml/proposals.xml')//project[@label=$projectLabel]/title"/>
                    <xsl:text> (</xsl:text>
                    <xsl:for-each select="document('../../common/generated/xml/proposals.xml')//project[@label=$projectLabel]/supervisor/*">
                        <xsl:value-of select="local-name()"/><xsl:text> </xsl:text>
                    </xsl:for-each> 
                    <xsl:text>)</xsl:text><xsl:value-of select="$notSaved"/>
                </OPTION>  
             </xsl:if>  
           </xsl:if>  
        </xsl:for-each> 
	</optgroup>  
	<optgroup label=" Hidden">	
         <xsl:for-each select="document('../../common/generated/xml/proposals.xml')//project">
            <xsl:variable name="projectLabel"><xsl:value-of select="@label"/></xsl:variable>
	     <xsl:variable name="hiddenVal"><xsl:value-of select="hidden/."/></xsl:variable>
             <xsl:if test="$projectLabel!='' and $hiddenVal!=''">   
             <OPTION>
                <xsl:if test="$projectLabel = $projectChoice and $prefNo=0">
                     <xsl:attribute name="SELECTED">SELECTED</xsl:attribute>
                </xsl:if>  
                 <xsl:attribute name="value"><xsl:value-of select="$projectLabel"/></xsl:attribute>
                  <xsl:text>  </xsl:text>
                   <xsl:value-of select="document('../../common/generated/xml/proposals.xml')//project[@label=$projectLabel]/title"/>
                    <xsl:text> (</xsl:text>
                    <xsl:for-each select="document('../../common/generated/xml/proposals.xml')//project[@label=$projectLabel]/supervisor/*">
                        <xsl:value-of select="local-name()"/><xsl:text> </xsl:text>
                    </xsl:for-each> 
                    <xsl:text>)</xsl:text><xsl:value-of select="$notSaved"/>(<xsl:value-of select="$hiddenVal"/>)
                </OPTION>  
             </xsl:if>  
        </xsl:for-each> 	
	</optgroup> 
	<optgroup label=" Other">	
        <OPTION value='Own Project'>
         <xsl:if test="$projectChoice='Own Project'">
             <xsl:attribute name="SELECTED">SELECTED</xsl:attribute>
         </xsl:if> 
        <xsl:text>Own Project</xsl:text>
        </OPTION>
        </optgroup>        
       </optgroup>    
    </SELECT>
</xsl:template>     


</xsl:stylesheet>
