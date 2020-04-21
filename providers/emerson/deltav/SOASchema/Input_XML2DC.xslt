<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:i="http://www.w3.org/2001/XMLSchema-instance" 
                xmlns="EmersonProcess.Web.Services.CampaignManager">
  <xsl:output method="xml" encoding="UTF-8" indent="yes" omit-xml-declaration="yes"/>
  
  <!-- Campaign Template -->
  <xsl:template match="campaignInfo|CampaignInfo">
    <xsl:element name="CampaignInfo">
      <!-- these attributes should be transformed in order -->
      <xsl:apply-templates select="@ID" />
      <xsl:apply-templates select="@Description" />
      <xsl:apply-templates select="@BatchCount" />
      <xsl:apply-templates select="@MaxActiveBatches" />
      <xsl:apply-templates select="@Prefix" />
      <xsl:apply-templates select="@Suffix" />
      <xsl:apply-templates select="@StartSequence" />
      <xsl:apply-templates select="@AutoRemoveInManual" />
      <xsl:apply-templates select="@AutoRemoveInAutoRelease" />
      <xsl:apply-templates select="@AutoRemoveInAutoStart" />
      <xsl:apply-templates select="@BatchExecutionMode" />
      <xsl:apply-templates select="@ContinuousIteration" />
      <xsl:apply-templates select="@MinRemoveDelay" />
      <xsl:apply-templates select="BatchList"/>
      <xsl:apply-templates select="BaseRecipe"/>
    </xsl:element>
  </xsl:template>
  
  <!-- transform attribute to element -->
  <xsl:template match="@*">
    <xsl:element name="{local-name()}">
      <xsl:value-of select="."/>
    </xsl:element>
  </xsl:template>

  <!-- Batch Template -->
  <xsl:template match="BatchList">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:apply-templates select="." />
      </xsl:for-each>
    </xsl:element>
  </xsl:template>
  <xsl:template match="batchInfo|BatchInfo">
    <xsl:element name="BatchInfo">
      <xsl:apply-templates select="@ID" />
      <xsl:apply-templates select="@Setup" />
      <xsl:apply-templates select="@Cleanup" />
      <xsl:apply-templates select="@IsBasedOnBaseRecipe" />
      <xsl:apply-templates select="Recipe" />
    </xsl:element>
  </xsl:template>

  <!-- Recipe Template -->
  <xsl:template match="BaseRecipe|Recipe|RecipeInfo">
    <xsl:element name="{local-name()}">
      <xsl:apply-templates select="@Name" />
      <xsl:apply-templates select="@Executive" />
      <xsl:apply-templates select="@Scale" />
      <xsl:apply-templates select="@ScaleUnits" />
      <xsl:apply-templates select="EquipmentTrain"/>
      <xsl:apply-templates select="Formula"/>
      <xsl:apply-templates select="UnitBindings"/>
      <xsl:apply-templates select="UnitAliasing"/>
    </xsl:element>
  </xsl:template>

  <!-- EquipmentTrain Template -->
  <xsl:template match="EquipmentTrain">
    <xsl:element name="{local-name()}">
      <xsl:apply-templates select="@Name" />
      <xsl:apply-templates select="@Description" />
    </xsl:element>
  </xsl:template>
  
  <!-- Formula Template -->
  <xsl:template match="Formula">
    <xsl:element name="{local-name()}">
      <xsl:apply-templates select="@Name" />
      <xsl:apply-templates select="@IsCustomFormula" />
      <xsl:apply-templates select="Parameters"/>
    </xsl:element>
  </xsl:template>

  <!-- Parameter Template -->
  <xsl:template match="Parameters">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="Parameter">
        <xsl:element name="Parameter">
          <xsl:apply-templates select="@Name" />
          <xsl:apply-templates select="@Min" />
          <xsl:apply-templates select="@Value" />
          <xsl:apply-templates select="@Max" />
        </xsl:element>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>

  <!-- UnitAliasing Template -->
  <xsl:template match="UnitAliasing">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="UnitAlias">
        <xsl:element name="UnitAlias">
          <xsl:apply-templates select="@AliasName" />
          <xsl:apply-templates select="@UnitName" />
        </xsl:element>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>

  <!-- UnitBindings Template -->
  <xsl:template match="UnitBindings">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="UnitBinding">
        <xsl:element name="UnitBinding">
          <xsl:apply-templates select="@StepName" />
          <xsl:apply-templates select="@UnitName" />
        </xsl:element>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>

</xsl:stylesheet>