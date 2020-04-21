)"/>
		<Column name="LeaderheadType" type="text" reference="Leaders(Type)"/>
	</Table>
	<Table name="Civilization_SpyNames">
		<Column name="CivilizationType" type="text" reference="Civilizations(Type)"/>
		<Column name="SpyName" type="text" notnull="true" reference="Language_en_US(Tag)"/>
	</Table>
	<Table name="Civilization_UnitClassOverrides">
		<Column name="CivilizationType" type="text" reference="Civilizations(Type)"/>
		<Column name="UnitClassType" type="text" notnull="true" reference="UnitClasses(Type)"/>
		<Column name="UnitType" type="text" reference="Units(Type)"/>
	</Table>
	<Table name="Civilization_Start_Along_Ocean">
		<Column name="CivilizationType" type="text" reference="Civilizations(Type)"/>
		<Column name="StartAlongOcean" type="boolean" default="false"/>
	</Table>
	<Table name="Civilization_Start_Along_River">
		<Column name="CivilizationType" type="text" reference="Civilizations(Type)"/>
		<Column name="StartAlongRiver" type="boolean" default="false"/>
	</Table>
	<Table name="Civilization_Start_Region_Priority">
		<Column name="CivilizationType" type="text" reference="Civilizations(Type)"/>
		<Column name="RegionType" type="text" reference="Regions(Type)"/>
	</Table>
	<Table name="Civilization_Start_Region_Avoid">
		<Column name="CivilizationType" type="text" reference="Civilizations(Type)"/>
		<Column name="RegionType" type="text" reference="Regions(Type)"/>
	</Table>
	<Table name="Civilization_Start_Place_First_Along_Ocean">
		<Column name="CivilizationType" type="text" reference="Civilizations(Type)"/>
		<Column name="PlaceFirst" type="boolean" default="false"/>
	</Table>
	<!-- Table data -->
	<Civilizations>
		<Row>
			<ID>0</ID>
			<Type>CIVILIZATION_ARC</Type>
			<Description>TXT_KEY_CIV_ARC_DESC</Description>
			<ShortDescription>TXT_KEY_CIV_ARC_SHORT_DESC</ShortDescription>
			<Adjective>TXT_KEY_CIV_ARC_ADJECTIVE</Adjective>
			<CivilopediaTag>TXT_KEY_CIV_ARC</CivilopediaTag>
			<DefaultPlayerColor>PLAYERCOLOR_ARC</DefaultPlayerColor>
			<ArtDefineTag>ART_DEF_CIVILIZATION_AMERICA</ArtDefineTag>
			<ArtStyleType>ARTSTYLE_EUROPEAN</ArtStyleType>
			<PortraitIndex>0</PortraitIndex>
			<IconAtlas>CIV_COLOR_ATLAS</IconAtlas>
			<AlphaIconAtlas>CIV_ALPHA_ATLAS</AlphaIconAtlas>			
			<GradientIconAtlas>CIV_GRADIENT_ATLAS</GradientIconAtlas>
			<GlowIconAtlas>CIV_GLOW_ATLAS</GlowIconAtlas>
			<MapImage/>
			<ArtStyleSuffix>_EURO</ArtStyleSuffix>
			<ArtStylePrefix>EUROPEAN </ArtStylePrefix>
			<IntroductionQuote>TXT_KEY_CIV_INTRO_ARC_TEXT%</IntroductionQuote>
			<IntroductionImage>DOM_Blue.dds</IntroductionImage>
			<IntroductionAudio>AS2D_DOM_SPEECH_UNITED_STATES</IntroductionAudio>
			<Personality>PERSONALITY_ARC</Personality>
		</Row>
		<Row>
			<Type>CIVILIZATION_AFRICAN_UNION</Type>
			<Description>TXT_KEY_CIV_AFRICAN_UNION_DESC</Description>
			<ShortDescription>TXT_KEY_CIV_AFRICAN_UNION_SHORT_DESC</ShortDescription>
			<Adjective>TXT_KEY_CIV_AFRICAN_UNION_ADJECTIVE</Adjective>
			<CivilopediaTag>TXT_KEY_CIV_AFRICAN_UNION</CivilopediaTag>
			<DefaultPlayerColor>PLAYERCOLOR_AFRICAN_UNION</DefaultPlayerColor>
			<ArtDefineTag>ART_DEF_CIVILIZATION_ARABIA</ArtDefineTag>
			<ArtStyleType>ARTSTYLE_MIDDLE_EAST</ArtStyleType>
			<ArtStyleSuffix>_AFRI</ArtStyleSuffix>
			<ArtStylePrefix>AFRICAN </ArtStylePrefix>
			<PortraitIndex>1</PortraitIndex>
			<IconAtlas>CIV_COLOR_ATLAS</IconAtlas>
			<AlphaIconAtlas>CIV_ALPHA_ATLAS</AlphaIconAtlas>
			<GradientIconAtlas>CIV_GRADIENT_ATLAS</GradientIconAtlas>
			<GlowIconAtlas>CIV_GLOW_ATLAS</GlowIconAtlas>			
			<MapImage/>
			<IntroductionQuote>TXT_KEY_CIV_INTRO_AFRICAN_UNION_TEXT%</IntroductionQuote>
			<IntroductionImage>DOM_Red.dds</IntroductionImage>
			<IntroductionAudio>AS2D_DOM_SPEECH_ARABIA</IntroductionAudio>
			<Personality>PERSONALITY_AFRICAN_UNION</Personality>
		</Row>
		<Row>
			<Type>CIVILIZATION_BRASILIA</Type>
			<Description>TXT_KEY_CIV_BRASILIA_DESC</Description>
			<ShortDescription>TXT_KEY_CIV_BRASILIA_SHORT_DESC</ShortDescription>
			<Adjective>TXT_KEY_CIV_BRASILIA_ADJECTIVE</Adjective>
			<CivilopediaTag>TXT_KEY_CIV_BRASILIA</CivilopediaTag>
			<DefaultPlayerColor>PLAYERCOLOR_BRASILIA</DefaultPlayerColor>
			<ArtDefineTag>ART_DEF_CIVILIZATION_BRAZIL</ArtDefineTag>
			<ArtStyleType>ARTSTYLE_SOUTH_AMERICA</ArtStyleType>
			<ArtStyleSuffix>_AMER</ArtStyleSuffix>
			<ArtStylePrefix>AMERICAN</ArtStylePrefix>
			<PortraitIndex>2</PortraitIndex>
			<IconAtlas>CIV_COLOR_ATLAS</IconAtlas>
			<AlphaIconAtlas>CIV_ALPHA_ATLAS</AlphaIconAtlas>
			<GradientIconAtlas>CIV_GRADIENT_ATLAS</GradientIconAtlas>
			<GlowIconAtlas>CIV_GLOW_ATLAS</GlowIconAtlas>
			<MapImage/>
			<IntroductionQuote>TXT_KEY_CIV_INTRO_BRASILIA_TEXT%</IntroductionQuote>
			<IntroductionImage>DOM_Green.dds</IntroductionImage>
			<IntroductionAudio>AS2D_DOM_SPEECH_BRAZIL</IntroductionAudio>
			<Personality>PERSONALITY_BRASILIA</Personality>
		</Row>
		<Row>
			<Type>CIVILIZATION_PAN_ASIA</Type>
			<Description>TXT_KEY_CIV_PAN_ASIA_DESC</Description>
			<ShortDescription>TXT_KEY_CIV_PAN_ASIA_SHORT_DESC</ShortDescription>
			<Adjective>TXT_KEY_CIV_PAN_ASIA_ADJECTIVE</Adjective>
			<CivilopediaTag>TXT_KEY_CIV_PAN_ASIA</CivilopediaTag>
			<DefaultPlayerColor>PLAYERCOLOR_PAN_ASIA</DefaultPlayerColor>
			<ArtDefineTag>ART_DEF_CIVILIZATION_CHINA</ArtDefineTag>
			<ArtStyleType>ARTSTYLE_ASIAN</ArtStyleType>
			<ArtStyleSuffix>_ASIA</ArtStyleSuffix>
			<ArtStylePrefix>ASIAN </ArtStylePrefix>
			<PortraitIndex>3</PortraitIndex>
			<IconAtlas>CIV_COLOR_ATLAS</IconAtlas>
			<AlphaIconAtlas>CIV_ALPHA_ATLAS</AlphaIconAtlas>
			<GradientIconAtlas>CIV_GRADIENT_ATLAS</GradientIconAtlas>
			<GlowIconAtlas>CIV_GLOW_ATLAS</GlowIconAtlas>
			<MapImage/>
			<IntroductionQuote>TXT_KEY_CIV_INTRO_PAN_ASIA_TEXT%</IntroductionQuote>
			<IntroductionImage>DOM_Blue.dds</IntroductionImage>
			<IntroductionAudio>AS2D_DOM_SPEECH_CHINA</IntroductionAudio>
			<Personality>PERSONALITY_PAN_ASIA</Personality>
		</Row>
		<Row>
			<Type>CIVILIZATION_FRANCO_IBERIA</Type>
			<Description>TXT_KEY_CIV_FRANCO_IBERIA_DESC</Description>
			<ShortDescription>TXT_KEY_CIV_FRANCO_IBERIA_SHORT_DESC</ShortDescription>
			<Adjective>TXT_KEY_CIV_FRANCO_IBERIA_ADJECTIVE</Adjective>
			<CivilopediaTag>TXT_KEY_CIV_FRANCO_IBERIA</CivilopediaTag>
			<DefaultPlayerColor>PLAYERCOLOR_FRANCO_IBERIA</DefaultPlayerColor>
			<ArtDefineTag>ART_DEF_CIVILIZATION_FRANCE</ArtDefineTag>
			<ArtStyleType>ARTSTYLE_EUROPEAN</ArtStyleType>
			<ArtStyleSuffix>_EURO</ArtStyleSuffix>
			<ArtStylePrefix>EUROPEAN </ArtStylePrefix>
			<PortraitIndex>4</PortraitIndex>
			<IconAtlas>CIV_COLOR_ATLAS</IconAtlas>
			<AlphaIconAtlas>CIV_ALPHA_ATLAS</AlphaIconAtlas>
			<GradientIconAtlas>CIV_GRADIENT_ATLAS</GradientIconAtlas>
			<GlowIconAtlas>CIV_GLOW_ATLAS</GlowIconAtlas>
			<MapImage/>
			<IntroductionQuote>TXT_KEY_CIV_INTRO_FRANCO_IBERIA_TEXT%</IntroductionQuote>
			<IntroductionImage>DOM_Red.dds</IntroductionImage>
			<IntroductionAudio>AS2D_DOM_SPEECH_FRANCE</IntroductionAudio>
			<Personality>PERSONALITY_FRANCO_IBERIA</Personality>
		</Row>
		<Row>
			<Type>CIVILIZATION_KAVITHAN</Type>
			<Description>TXT_KEY_CIV_KAVITHAN_DESC</Description>
			<ShortDescription>TXT_KEY_CIV_KAVITHAN_SHORT_DESC</ShortDescription>
			<Adjective>TXT_KEY_CI