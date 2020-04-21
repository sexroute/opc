<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns="http://EmersonProcess.WebServices/CampaignManager/DataContracts"
                xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
  <xsl:output method="xml" encoding="UTF-8" indent="yes"/>
  
  <!-- Campaign Template -->
  <xsl:template match="CampaignInfo">
    <xsl:element name="{local-name()}">
      <!--<xsl:apply-templates/>-->
      <xsl:for-each select="*">
        <xsl:choose>
          <xsl:when test="@nil = 'true'"/>
          <xsl:otherwise>
            <xsl:choose>
              <xsl:when test="count(child::*) = 0">
                <xsl:attribute name="{local-name()}">
                  <xsl:value-of select="."/>
                </xsl:attribute>
              </xsl:when>
            </xsl:choose>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>
      <xsl:apply-templates select="BatchList"/>
      <xsl:apply-templates select="BaseRecipe"/>
      <xsl:apply-templates select="UserComments" mode="stringArray"/>
    </xsl:element>
  </xsl:template>

  <!-- BatchList Template -->
  <xsl:template match="BatchList">
    <xsl:element name="BatchList">
      <xsl:apply-templates/>
    </xsl:element>
  </xsl:template>
  
  <!-- Batch Template -->
  <xsl:template match="BatchInfo">
    <xsl:element name="BatchInfo">
      <xsl:for-each select="*">
        <xsl:choose>
          <xsl:when test="@nil = 'true'"/>
          <xsl:otherwise>
            <xsl:choose>
              <xsl:when test="count(child::*) = 0">
                <xsl:attribute name="{local-name()}">
                  <xsl:value-of select="."/>
                </xsl:attribute>
              </xsl:when>
            </xsl:choose>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>
      <xsl:apply-templates select="Recipe"/>
      <xsl:apply-templates select="UserComments" mode="stringArray"/>
    </xsl:element>
  </xsl:template>
  
  <!-- Recipe Template -->
  <xsl:template match="BaseRecipe|Recipe|RecipeInfo">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:choose>
          <xsl:when test="@nil = 'true'"/>
          <xsl:when test="local-name() = 'EquipmentTrain'"/>
          <xsl:when test="local-name() = 'Formula'"/>
          <xsl:when test="local-name() = 'UnitBindings'"/>
          <xsl:when test="local-name() = 'UnitAliasing'"/>
          <xsl:otherwise>
            <xsl:choose>
              <xsl:when test="count(child::*) = 0">
                <xsl:attribute name="{local-name()}">
                  <xsl:value-of select="."/>
                </xsl:attribute>
              </xsl:when>
            </xsl:choose>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>
      <xsl:apply-templates select="EquipmentTrain"/>
      <xsl:apply-templates select="Formula"/>
      <xsl:apply-templates select="UnitBindings"/>
      <xsl:apply-templates select="UnitAliasing"/>
    </xsl:element>
  </xsl:template>
  
  <!-- Executive Recipe Template -->
  <xsl:template match="ExecRecipeInfo">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:choose>
          <xsl:when test="@nil = 'true'"/>
          <xsl:when test="local-name() = 'FormulaList'" />
          <xsl:when test="local-name() = 'Parameters'" />
          <xsl:when test="local-name() = 'EquipmentTrains'" />
          <xsl:when test="local-name() = 'Aliases'" />
          <xsl:when test="local-name() = 'Steps'" />
          <xsl:otherwise>
            <xsl:choose>
              <xsl:when test="count(child::*) = 0">
                <xsl:attribute name="{local-name()}">
                  <xsl:value-of select="."/>
                </xsl:attribute>
              </xsl:when>
            </xsl:choose>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>
      <xsl:apply-templates select="FormulaList" mode="stringArray" />
      <xsl:apply-templates select="Parameters" />
      <xsl:apply-templates select="EquipmentTrains" mode="stringArray" />
      <xsl:apply-templates select="Aliases" mode="stringArray" />
      <xsl:apply-templates select="Steps" mode="stringArray" />
    </xsl:element>
  </xsl:template>
  
  <!-- string array -->
  <xsl:template match="*" mode="stringArray">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="child::*">
        <xsl:element name="{local-name()}">
          <xsl:value-of select="."/>
        </xsl:element>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>

  <!-- Equipment Train Template -->
  <xsl:template match="EquipmentTrain">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:attribute name="{local-name()}">
          <xsl:value-of select="."/>
        </xsl:attribute>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>
  
  <!-- Formula Template -->
  <xsl:template match="Formula|Formula">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:choose>
          <xsl:when test="local-name()='Parameters'"/>
          <xsl:otherwise>
            <xsl:attribute name="{local-name()}">
              <xsl:value-of select="."/>
            </xsl:attribute>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>
      <xsl:apply-templates select="Parameters"/>
    </xsl:element>
  </xsl:template>

  <!-- Parameter Template -->
  <xsl:template match="Parameters">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:apply-templates select="."/>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>
  <xsl:template match="Parameter">
    <xsl:element name="Parameter">
      <xsl:for-each select="*">
        <xsl:attribute name="{local-name()}">
          <xsl:value-of select="."/>
        </xsl:attribute>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>

  <!-- UnitAliasing Template -->
  <xsl:template match="UnitAliasing">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:apply-templates select="."/>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>
  <xsl:template match="UnitAlias">
    <xsl:element name="UnitAlias">
      <xsl:for-each select="*">
        <xsl:attribute name="{local-name()}">
          <xsl:value-of select="."/>
        </xsl:attribute>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>

  <!-- UnitBinding Template -->
  <xsl:template match="UnitBindings">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:apply-templates select="."/>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>
  <xsl:template match="UnitBinding">
    <xsl:element name="UnitBinding">
      <xsl:for-each select="*">
        <xsl:attribute name="{local-name()}">
          <xsl:value-of select="."/>
        </xsl:attribute>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>
  
  <!-- ConfiguredAction Template -->
  <xsl:template match="ConfiguredActionInfo">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:attribute name="{local-name()}">
          <xsl:value-of select="."/>
        </xsl:attribute>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>

  <!-- Unit Template -->
  <xsl:template match="ArrayOfUnit">
    <xsl:element name="Units">
      <xsl:for-each select="child::*">
        <xsl:apply-templates select="."/>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>
  <xsl:template match="Unit">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:choose>
          <xsl:when test="@nil = 'true'"/>
          <xsl:when test="local-name() = 'DownstreamUnits'" />
          <xsl:otherwise>
            <xsl:choose>
              <xsl:when test="count(child::*) = 0">
                <xsl:attribute name="{local-name()}">
                  <xsl:value-of select="."/>
                </xsl:attribute>
              </xsl:when>
            </xsl:choose>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>
      <xsl:apply-templates select="DownstreamUnits" mode="stringArray" />
    </xsl:element>
  </xsl:template>
  
  <!-- Alias Template -->
  <xsl:template match="ArrayOfAlias">
    <xsl:element name="Aliases">
      <xsl:for-each select="child::*">
        <xsl:apply-templates select="."/>
      </xsl:for-each>
    </xsl:element>
  </xsl:template>
  <xsl:template match="Alias">
    <xsl:element name="{local-name()}">
      <xsl:for-each select="*">
        <xsl:choose>
          <xsl:when test="@nil = 'true'"/>
          <xsl:when test="local-name() = 'DownstreamAliases'" />
          <xsl:otherwise>
            <xsl:choose>
              <xsl:when test="count(child::*) = 0">
                <xsl:attribute name="{local-name()}">
                  <xsl:value-of select="."/>
                </xsl:attribute>
              </xsl:when>
            </xsl:choose>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:for-each>
      <xsl:apply-templates select="DownstreamAliases" mode="stringArray" />
    </xsl:element>
  </xsl:template>
</xsl:stylesheet>