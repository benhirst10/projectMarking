<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html"
              doctype-public="-//W3C//DTD HTML 4.0 Transitional//EN"/>


          
<xsl:template match="/" xml:space="preserve">
        <xsl:apply-templates/>
</xsl:template>

<xsl:template match="/assessments">

                <xsl:apply-templates select="assessment"/>
</xsl:template>

<xsl:template match="assessment">
  <xsl:if test="@id=$assid or $assid='_all_'">
      <xsl:if test="$componentid='' or $componentid='_all_'">
          <xsl:attribute name="colspan"><xsl:choose><xsl:when test="@weighting">3</xsl:when><xsl:otherwise>4</xsl:otherwise></xsl:choose></xsl:attribute>
		  <div class="panel-heading"><b>Assessment</b>:  <xsl:value-of select="@id"/>
          <xsl:if test="@weighting">
              (Weighting: <xsl:value-of select="@weighting"/>)
          </xsl:if>
		  </div>
              <input type="hidden">
                <xsl:attribute name="name">weightingAssessment[<xsl:value-of select="@id"/>]</xsl:attribute>
            <xsl:attribute name="value"><xsl:value-of select="@weighting"/></xsl:attribute>
              </input>        
      </xsl:if>
      <xsl:if test="$componentid!=''">

          <xsl:apply-templates select="component">  
             <xsl:with-param name="assid" select="@id"/>
          </xsl:apply-templates>
 
      </xsl:if> 
  </xsl:if>   
</xsl:template>
        
<xsl:template match="component">  
<xsl:param name="assid" select="0"/>
    <xsl:if test="$entryReport!='studentReport' or ($entryReport='studentReport' and not(feedback/@staffonly))">
    <xsl:if test="@id=$componentid or $componentid='_all_'">
		<xsl:variable name='grp'></xsl:variable>
        <xsl:apply-templates select="description"/><xsl:value-of select="$grp"/>
        <xsl:if test="@groupAssessed='true'">
                     (Group Assessed)
              <input type="hidden">
            <xsl:attribute name="name">groupAssessed[<xsl:value-of select="$assid"/>][<xsl:value-of select="@id"/>]</xsl:attribute>
            <xsl:attribute name="value">true</xsl:attribute>
              </input>           
            </xsl:if>   
        <xsl:apply-templates select="markingGuide"/>
		<div class="panel-heading">
        <xsl:if test="@weighting and $entryReport!='studentReport'">
            (Weighting: <xsl:value-of select="@weighting"/>
        </xsl:if>
        <xsl:if test="mark/numeric/@outof and $entryReport!='studentReport'">
             Out of:<xsl:value-of select="mark/numeric/@outof"/>)
        </xsl:if>
		</div>
           <xsl:attribute name="width"><xsl:choose><xsl:when test="mark/numeric/@outof">50%</xsl:when><xsl:otherwise>60%</xsl:otherwise></xsl:choose></xsl:attribute>
           <xsl:attribute name="colspan"><xsl:choose><xsl:when test="mark/numeric/@outof">1</xsl:when><xsl:otherwise>2</xsl:otherwise></xsl:choose></xsl:attribute>
           <xsl:apply-templates select="feedback">
               <xsl:with-param name="cid" select="@id"/>        
               <xsl:with-param name="assid" select="$assid"/>
           </xsl:apply-templates>
           <input type="hidden">
               <xsl:attribute name="name">weightingComponent[<xsl:value-of select="$assid"/>][<xsl:value-of select="@id"/>]</xsl:attribute>
               <xsl:attribute name="value"><xsl:value-of select="@weighting"/></xsl:attribute>
           </input> 

           <xsl:apply-templates select="mark">
               <xsl:with-param name="cid" select="@id"/>        
               <xsl:with-param name="assid" select="$assid"/>
               <xsl-with-param name="weighting" select="@weighting"/>
           </xsl:apply-templates>
       </xsl:if>
       </xsl:if>
</xsl:template>    

<xsl:template match="description">
          <div class="panel-heading"><xsl:value-of select="."/></div>
</xsl:template>

<xsl:template match="markingGuide">
<xsl:if test="$entryReport!='studentReport' or @availableToStudents">
         <div class="panel-heading"><xsl:value-of disable-output-escaping="yes" select="."/></div>
</xsl:if>           
</xsl:template>

<xsl:template match="feedback">
    <xsl:param name="assid" select="0"/>
    <xsl:param name="cid" select="0"/>
    
    <xsl:if test="@style='textarea' and $entryReport='entry'">
        <textarea class="form-control">
        <xsl:if test="$componentid!='_all_'">
          <xsl:attribute name="onmouseover">addUpMarkBoxes()</xsl:attribute>
          <xsl:attribute name="onclick">altervalues();addUpMarkBoxes()</xsl:attribute>
        </xsl:if> 
                
             <xsl:attribute name="name">feedback[<xsl:value-of select="normalize-space($assid)"/>][<xsl:value-of select="normalize-space($cid)"/>]</xsl:attribute>
            <xsl:value-of select="$componentVal"/>

        </textarea>      
    </xsl:if>
    <xsl:if test="$entryReport='report' and @style='textarea'">
        <xsl:value-of select="$componentVal"/>
    </xsl:if>
    <xsl:if test="$entryReport='studentReport' and @style='textarea' and not(@staffonly)">
        <xsl:value-of select="$componentVal"/>
    </xsl:if>   
</xsl:template> 
    
<xsl:template match="mark">
    <xsl:param name="assid" select="0"/>
    <xsl:param name="cid" select="0"/>
    <xsl:param name="weighting" select="0"/>
    <br/>
    <xsl:if test="numeric/@outof">
        <td width="10%" align="center">
        
        <xsl:if test="$entryReport='entry'">
            <input type='text' size='5' class='boxes'>
            <xsl:if test="$componentid!='_all_'">
                 <xsl:attribute name="onmouseover">addUpMarkBoxes()</xsl:attribute>
                <xsl:attribute name="onclick">altervalues();addUpMarkBoxes()</xsl:attribute>
            </xsl:if> 
                <xsl:attribute name="name">mark[<xsl:value-of select="normalize-space($assid)"/>][<xsl:value-of select="normalize-space($cid)"/>]</xsl:attribute>
            <xsl:attribute name="value"><xsl:value-of select="$numericVal"/></xsl:attribute>
            </input>
            <input type="hidden">
                <xsl:attribute name="name">outof[<xsl:value-of select="normalize-space($assid)"/>][<xsl:value-of select="normalize-space($cid)"/>]</xsl:attribute>
                <xsl:attribute name="value"><xsl:value-of select="numeric/@outof"/></xsl:attribute>
            </input> 
        </xsl:if>
        <xsl:if test="$entryReport='report'">
            <xsl:value-of select="$numericVal"/> 
            <xsl:if test="document('../../common/config/xml/version.xml')//version/@student_type='undergraduate'">
                (<xsl:value-of select="document('../../common/xml/gradeBands.xml')//grades[@intake='undergraduate']/grade[$numericVal&gt;=@start and $numericVal&lt;@end]/@id"/>)
            </xsl:if>
             <xsl:if test="document('../../common/config/xml/version.xml')//version/@student_type='postgraduate'">
                (<xsl:value-of select="document('../../common/xml/gradeBands.xml')//grades[@intake='postgraduate']/grade[$numericVal&gt;=@start and $numericVal&lt;@end]/@id"/>)
            </xsl:if>            
        </xsl:if>   
        <xsl:if test="$entryReport='studentReport'">
            <xsl:if test="document('../../common/config/xml/version.xml')//version/@student_type='undergraduate'">
                <xsl:value-of select="document('../../common/xml/gradeBands.xml')//grades[@intake='undergraduate']/grade[$numericVal&gt;=@start and $numericVal&lt;@end]/@id"/>
            </xsl:if>
            <xsl:if test="document('../../common/config/xml/version.xml')//version/@student_type='postgraduate'">
                <xsl:value-of select="document('../../common/xml/gradeBands.xml')//grades[@intake='postgraduate']/grade[$numericVal&gt;=@start and $numericVal&lt;@end]/@id"/>
            </xsl:if>           
        </xsl:if>   
        
        </td>
        
        
    </xsl:if>
    <xsl:if test="$entryReport='entry'">    
        <xsl:for-each select="choice">
          <xsl:value-of select="."/><xsl:text disable-output-escaping="yes"><![CDATA[&nbsp;&nbsp;]]></xsl:text>
              <input type="radio">
          <xsl:if test="$componentid!='_all_'">
               <xsl:attribute name="onchange">altervalues();addUpMarkBoxes()</xsl:attribute>
          </xsl:if>  
              <xsl:attribute name="value">
                    <xsl:value-of select="." />
              </xsl:attribute>
             <xsl:if test="$choiceVal=.">
                <xsl:attribute name="checked"/>
             </xsl:if>  
              <xsl:if test="@defaultOption and $choiceVal=''">
                  <xsl:attribute name="checked"/>
              </xsl:if>                
              <xsl:attribute name="name">choice[<xsl:value-of select="normalize-space($assid)"/>][<xsl:value-of select="normalize-space($cid)"/>]</xsl:attribute>
              </input><xsl:text disable-output-escaping="yes"><![CDATA[&nbsp;&nbsp;&nbsp;]]></xsl:text>
        </xsl:for-each>
    </xsl:if> 
    <xsl:if test="$entryReport='report' or $entryReport='studentReport'">   
            <xsl:for-each select="choice">
             <xsl:if test="$choiceVal=.">
            <b><xsl:value-of select="." /></b>
             </xsl:if>  
            </xsl:for-each>
    </xsl:if> 
    
</xsl:template>


</xsl:stylesheet>
