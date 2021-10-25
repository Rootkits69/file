void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	//MODDED LOADOUTS - BEGIN-----------------------------------
	EntityAI randomMaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin","PowderedMilk","Rice","BakedBeansCan_Opened","PeachesCan_Opened","SpaghettiCan_Opened","SardinesCan_Opened","TunaCan_Opened","Apple","Tomato","GreenBellPepper","Zucchini","SlicedPumpkin","Potato","SambucusBerry","CaninaBerry","Plum","Pear","AgaricusMushroom","AmanitaMushroom","MacrolepiotaMushroom","LactariusMushroom","PsilocybeMushroom","AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","SodaCan_Kvass","WaterBottle"};
		ref TStringArray hatArray = {"BaseballCap_Blue","","","","BaseballCap_Beige","","","","BaseballCap_Black","","","","BaseballCap_Olive","","","","BaseballCap_Pink","","","","BaseballCap_Red","","","","BaseballCap_Camo","","","","BaseballCap_CMMG_Black","","","","BaseballCap_CMMG_Pink","","","","BeanieHat_Beige","","","","BeanieHat_Black","","","","BeanieHat_Blue","","","","BeanieHat_Brown","","","","BeanieHat_Green","","","","BeanieHat_Grey","","","","BeanieHat_Pink","","","","BeanieHat_Red","","","","Ushanka_Black","","","","Ushanka_Blue","","","","Ushanka_Green","","","","RadarCap_Black","","","","RadarCap_Blue","","","","RadarCap_Brown","","","","RadarCap_Green","","","","RadarCap_Red","","","","FlatCap_Black","","","","FlatCap_Blue","","","","FlatCap_Red","","","","FlatCap_Brown","","","","FlatCap_Grey","","","","FlatCap_BrownCheck","","","","FlatCap_GreyCheck","","","","FlatCap_BlackCheck","","","","ZmijovkaCap_Black","","","","ZmijovkaCap_Blue","","","","ZmijovkaCap_Brown","","","","ZmijovkaCap_Green","","","","ZmijovkaCap_Red","","","","CowboyHat_Brown","","","","CowboyHat_black","","","","CowboyHat_darkBrown","","","","CowboyHat_green","","","","SkateHelmet_Black","","","","SkateHelmet_Blue","","","","SkateHelmet_Gray","","","","SkateHelmet_Green","","","","SkateHelmet_Red","","","","WeldingMask","","","","LeatherHat_Natural","","","","LeatherHat_Beige","","","","LeatherHat_Brown","","","","LeatherHat_Black","","","","GreatHelm","","",""};
		ref TStringArray topArray = {"Paradise_Hoodie_blue",""};
		ref TStringArray pantsArray = {"Jeans_Black","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey","Jeans_BlueDark","CargoPants_Beige","CargoPants_Black","CargoPants_Blue","CargoPants_Green","CargoPants_Grey","CanvasPants_Beige","CanvasPants_Blue","CanvasPants_Grey","CanvasPants_Red","CanvasPants_Violet","CanvasPantsMidi_Beige","CanvasPantsMidi_Blue","CanvasPantsMidi_Grey","CanvasPantsMidi_Red","CanvasPantsMidi_Violet","TrackSuitPants_Black","TrackSuitPants_Blue","TrackSuitPants_Green","TrackSuitPants_Red","TrackSuitPants_LightBlue","LeatherPants_Natural","LeatherPants_Beige","LeatherPants_Brown","LeatherPants_Black","SlacksPants_Beige","SlacksPants_Black","SlacksPants_Blue","SlacksPants_Brown","SlacksPants_DarkGrey","SlacksPants_Khaki","SlacksPants_LightGrey","SlacksPants_White","Breeches_Pink","Breeches_Red","Breeches_White","Breeches_Green","Breeches_Browncheck","Breeches_Blue","Breeches_Blackcheck","Breeches_Black","Breeches_Beige","Breeches_Beetcheck","ShortJeans_Black","ShortJeans_Blue","ShortJeans_Brown","ShortJeans_Darkblue","ShortJeans_Green","ShortJeans_Red"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","","SportGlasses_Black","","","","SportGlasses_Green","","","","SportGlasses_Orange","","","","AviatorGlasses","","","","ThickFramesGlasses","","","","ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"AthleticShoes_Blue","AthleticShoes_Black","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey","DressShoes_Beige","DressShoes_Black","DressShoes_Brown","DressShoes_Sunburst","DressShoes_White","HikingBoots_Brown","HikingBoots_Black","HikingBootsLow_Black","HikingBootsLow_Blue","HikingBootsLow_Beige","HikingBootsLow_Grey","Wellies_Black","Wellies_Brown","Wellies_Green","Wellies_Grey","WorkingBoots_Grey","WorkingBoots_Brown","WorkingBoots_Green","WorkingBoots_Yellow","WorkingBoots_Beige","JoggingShoes_Black","JoggingShoes_Blue","JoggingShoes_Red","JoggingShoes_Violet","JoggingShoes_White","Sneakers_Black","Sneakers_Gray","Sneakers_Green","Sneakers_Red","Sneakers_White"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","","","BandanaMask_BlackPattern","","","","","","BandanaMask_PolkaPattern","","","","","","BandanaMask_GreenPattern","","","","","","BandanaMask_CamoPattern","","","","","","NioshFaceMask","","","","","","HockeyMask","","","","","","BalaclavaMask_Black","","","","","","BalaclavaMask_Blackskull","","","","","","BalaclavaMask_Beige","","","","","","BalaclavaMask_Blue","","","","","","BalaclavaMask_Green","","","","","","BalaclavaMask_Pink","","","","","","BalaclavaMask_White","","","","","","GP5GasMask","","","","",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("RoadFlare");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		return rags;
	}

	EntityAI randomFemaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin", "PowderedMilk", "Rice", "BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "SlicedPumpkin", "Potato", "SambucusBerry", "CaninaBerry", "Plum", "Pear", "AgaricusMushroom", "AmanitaMushroom", "MacrolepiotaMushroom", "LactariusMushroom", "PsilocybeMushroom", "AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"BaseballCap_Blue","","","", "BaseballCap_Beige","","","", "BaseballCap_Black","","","", "BaseballCap_Olive","","","", "BaseballCap_Pink","","","", "BaseballCap_Red","","","", "BaseballCap_Camo","","","", "BaseballCap_CMMG_Black","","","", "BaseballCap_CMMG_Pink","","","", "BeanieHat_Beige","","","", "BeanieHat_Black","","","", "BeanieHat_Blue","","","", "BeanieHat_Brown","","","", "BeanieHat_Green","","","", "BeanieHat_Grey","","","", "BeanieHat_Pink","","","", "BeanieHat_Red","","","", "Ushanka_Black","","","", "Ushanka_Blue","","","", "Ushanka_Green","","","", "RadarCap_Black","","","", "RadarCap_Blue","","","", "RadarCap_Brown","","","", "RadarCap_Green","","","", "RadarCap_Red","","","", "FlatCap_Black","","","", "FlatCap_Blue","","","", "FlatCap_Red","","","", "FlatCap_Brown","","","", "FlatCap_Grey","","","", "FlatCap_BrownCheck","","","", "FlatCap_GreyCheck","","","", "FlatCap_BlackCheck","","","", "ZmijovkaCap_Black","","","", "ZmijovkaCap_Blue","","","", "ZmijovkaCap_Brown","","","", "ZmijovkaCap_Green","","","", "ZmijovkaCap_Red","","","", "CowboyHat_Brown","","","", "CowboyHat_black","","","", "CowboyHat_darkBrown","","","", "CowboyHat_green","","","", "SkateHelmet_Black","","","", "SkateHelmet_Blue","","","", "SkateHelmet_Gray","","","", "SkateHelmet_Green","","","", "SkateHelmet_Red","","","", "WeldingMask","","","", "LeatherHat_Natural","","","", "LeatherHat_Beige","","","", "LeatherHat_Brown","","","", "LeatherHat_Black","","","", "GreatHelm","","",""}; 		
        ref TStringArray topArray = {"Paradise_Hoodie_blue",""};
		ref TStringArray pantsArray = {"ShortJeans_Black", "ShortJeans_Blue", "ShortJeans_Brown", "ShortJeans_Darkblue", "ShortJeans_Green", "ShortJeans_Red", "Skirt_Blue", "Skirt_Red", "Skirt_White", "Skirt_Yellow"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","", "SportGlasses_Black","","","", "SportGlasses_Green","","","", "SportGlasses_Orange","","","", "AviatorGlasses","","","", "ThickFramesGlasses","","","", "ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"AthleticShoes_Blue", "AthleticShoes_Black", "AthleticShoes_Brown", "AthleticShoes_Green", "AthleticShoes_Grey", "DressShoes_Beige", "DressShoes_Black", "DressShoes_Brown", "DressShoes_Sunburst", "DressShoes_White", "HikingBoots_Brown", "HikingBoots_Black", "HikingBootsLow_Black", "HikingBootsLow_Blue", "HikingBootsLow_Beige", "HikingBootsLow_Grey", "Wellies_Black", "Wellies_Brown", "Wellies_Green", "Wellies_Grey", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Green", "WorkingBoots_Yellow", "WorkingBoots_Beige", "JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey", "JoggingShoes_Black", "JoggingShoes_Blue", "JoggingShoes_Red", "JoggingShoes_Violet", "JoggingShoes_White", "Sneakers_Black", "Sneakers_Gray", "Sneakers_Green", "Sneakers_Red", "Sneakers_White"};
		ref TStringArray glovesArray = {"WorkingGloves_Black","","","", "WorkingGloves_Beige","","","", "WorkingGloves_Brown","","","", "WorkingGloves_Yellow","","","", "TacticalGloves_Beige","","","", "TacticalGloves_Black","","","", "TacticalGloves_Green","","","", "OMNOGloves_Brown","","","", "OMNOGloves_Gray","","","", "SurgicalGloves_White","","","", "SurgicalGloves_LightBlue","","","", "SurgicalGloves_Blue","","","", "SurgicalGloves_Green","","",""};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","","", "BandanaMask_BlackPattern","","","","","", "BandanaMask_PolkaPattern","","","","","", "BandanaMask_GreenPattern","","","","","", "BandanaMask_CamoPattern","","","","","", "NioshFaceMask","","","","","", "HockeyMask","","","","","", "BalaclavaMask_Black","","","","","", "BalaclavaMask_Blackskull","","","","","", "BalaclavaMask_Beige","","","","","", "BalaclavaMask_Blue","","","","","", "BalaclavaMask_Green","","","","","", "BalaclavaMask_Pink","","","","","", "BalaclavaMask_White","","","","","", "GP5GasMask","","","","",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("RoadFlare");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		return rags;
	}

	EntityAI randomFemale2Class(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin", "PowderedMilk", "Rice", "BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "SlicedPumpkin", "Potato", "SambucusBerry", "CaninaBerry", "Plum", "Pear", "AgaricusMushroom", "AmanitaMushroom", "MacrolepiotaMushroom", "LactariusMushroom", "PsilocybeMushroom", "AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"BaseballCap_Blue","","","","", "BaseballCap_Beige","","","","", "BaseballCap_Black","","","","", "BaseballCap_Olive","","","","", "BaseballCap_Pink","","","","", "BaseballCap_Red","","","","", "BaseballCap_Camo","","","","", "BaseballCap_CMMG_Black","","","","", "BaseballCap_CMMG_Pink","","","","", "BeanieHat_Beige","","","","", "BeanieHat_Black","","","","", "BeanieHat_Blue","","","","", "BeanieHat_Brown","","","","", "BeanieHat_Green","","","","", "BeanieHat_Grey","","","","", "BeanieHat_Pink","","","","", "BeanieHat_Red","","","","", "Ushanka_Black","","","","", "Ushanka_Blue","","","","", "Ushanka_Green","","","","", "RadarCap_Black","","","","", "RadarCap_Blue","","","","", "RadarCap_Brown","","","","", "RadarCap_Green","","","","", "RadarCap_Red","","","","", "FlatCap_Black","","","","", "FlatCap_Blue","","","","", "FlatCap_Red","","","","", "FlatCap_Brown","","","","", "FlatCap_Grey","","","","", "FlatCap_BrownCheck","","","","", "FlatCap_GreyCheck","","","","", "FlatCap_BlackCheck","","","","", "ZmijovkaCap_Black","","","","", "ZmijovkaCap_Blue","","","","", "ZmijovkaCap_Brown","","","","", "ZmijovkaCap_Green","","","","", "ZmijovkaCap_Red","","","","", "CowboyHat_Brown","","","","", "CowboyHat_black","","","","", "CowboyHat_darkBrown","","","","", "CowboyHat_green","","","","", "SkateHelmet_Black","","","","", "SkateHelmet_Blue","","","","", "SkateHelmet_Gray","","","","", "SkateHelmet_Green","","","","", "SkateHelmet_Red","","","","", "WeldingMask","","","","", "LeatherHat_Natural","","","","", "LeatherHat_Beige","","","","", "LeatherHat_Brown","","","","", "LeatherHat_Black","","","","", "GreatHelm","","","",""};
        ref TStringArray topArray = {"Paradise_Hoodie_blue",""};
		ref TStringArray pantsArray = {"", ""};
		ref TStringArray vestArray  = {"ChestHolster","", "","", "","", "","", "",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","", "SportGlasses_Black","","","", "SportGlasses_Green","","","", "SportGlasses_Orange","","","", "AviatorGlasses","","","", "ThickFramesGlasses","","","", "ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"AthleticShoes_Blue", "AthleticShoes_Black", "AthleticShoes_Brown", "AthleticShoes_Green", "AthleticShoes_Grey", "DressShoes_Beige", "DressShoes_Black", "DressShoes_Brown", "DressShoes_Sunburst", "DressShoes_White", "HikingBoots_Brown", "HikingBoots_Black", "HikingBootsLow_Black", "HikingBootsLow_Blue", "HikingBootsLow_Beige", "HikingBootsLow_Grey", "Wellies_Black", "Wellies_Brown", "Wellies_Green", "Wellies_Grey", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Green", "WorkingBoots_Yellow", "WorkingBoots_Beige", "JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey", "JoggingShoes_Black", "JoggingShoes_Blue", "JoggingShoes_Red", "JoggingShoes_Violet", "JoggingShoes_White", "Sneakers_Black", "Sneakers_Gray", "Sneakers_Green", "Sneakers_Red", "Sneakers_White"};
		ref TStringArray glovesArray = {"WorkingGloves_Black","","","", "WorkingGloves_Beige","","","", "WorkingGloves_Brown","","","", "WorkingGloves_Yellow","","","", "TacticalGloves_Beige","","","", "TacticalGloves_Black","","","", "TacticalGloves_Green","","","", "OMNOGloves_Brown","","","", "OMNOGloves_Gray","","","", "SurgicalGloves_White","","","", "SurgicalGloves_LightBlue","","","", "SurgicalGloves_Blue","","","", "SurgicalGloves_Green","","",""};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","", "BandanaMask_BlackPattern","","","","", "BandanaMask_PolkaPattern","","","","", "BandanaMask_GreenPattern","","","","", "BandanaMask_CamoPattern","","","","", "NioshFaceMask","","","","", "HockeyMask","","","","","", "BalaclavaMask_Black","","","","", "BalaclavaMask_Blackskull","","","","", "BalaclavaMask_Beige","","","","", "BalaclavaMask_Blue","","","","", "BalaclavaMask_Green","","","","", "BalaclavaMask_Pink","","","","", "BalaclavaMask_White","","","","", "GP5GasMask","","","",""};
		ref TStringArray backpackArray = {"BagTaloon_Blue", "BagTaloon_Green", "BagTaloon_Orange", "BagTaloon_Violet", "BagCourierImprovised", "BagCourierImprovisedFur", "BagImprovised", "BagImprovisedFur", "BagHunting", "BagMountain_Blue", "BagMountain_Green", "BagMountain_Orange", "BagMountain_Red", "ChildBag_Blue", "ChildBag_Green", "ChildBag_Red", "ChildBag_Blue", "ChildBag_Green", "ChildBag_Red", "ChildBag_Blue", "ChildBag_Green", "ChildBag_Red", "ChildBag_Blue", "ChildBag_Green", "ChildBag_Red", "LeatherSack_Natural", "LeatherSack_Black", "LeatherSack_Beige", "LeatherSack_Brown", "AssaultBag_Ttsko", "AssaultBag_Black", "AssaultBag_Green", "CoyoteBag_Brown", "CoyoteBag_Green"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("RoadFlare");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		return rags;
	}

	EntityAI scientistClass(PlayerBase player)
	{
		player.GetInventory().CreateInInventory("Skirt_White");
		player.GetInventory().CreateInInventory("LabCoat");
		player.GetInventory().CreateInInventory("ThinFramesGlasses");
		player.GetInventory().CreateInInventory("DressShoes_White");
		player.GetInventory().CreateInInventory("WaterBottle");
		player.GetInventory().CreateInInventory("Apple");
		player.GetInventory().CreateInInventory("BloodTestKit");
		player.GetInventory().CreateInInventory("Screwdriver");
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		return rags;
	}

	EntityAI doctorClass(PlayerBase player)
	{
		player.GetInventory().CreateInInventory("SlacksPants_Black");
		player.GetInventory().CreateInInventory("LabCoat");
		player.GetInventory().CreateInInventory("ThinFramesGlasses");
		player.GetInventory().CreateInInventory("DressShoes_Brown");
		ItemBase rags = player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("WaterBottle");
		player.GetInventory().CreateInInventory("Apple");
		player.GetInventory().CreateInInventory("Thermometer");
		player.GetInventory().CreateInInventory("PainkillerTablets");
		player.GetInventory().CreateInInventory("Morphine");
		ItemBase light = player.GetInventory().CreateInInventory("Headtorch_Grey");
		light.GetInventory().CreateAttachment("Battery9V");
		return rags;
	}

	EntityAI nurseClass(PlayerBase player)
	{
		ref TStringArray hatArray = {"MedicalScrubsHat_Blue","","","","","","MedicalScrubsHat_Green","","","","","","MedicalScrubsHat_White","","","","",""};
		ref TStringArray dressArray = {"NurseDress_White","NurseDress_Blue"};
		ref TStringArray backpackArray  = {"ChildBag_Blue","SmershBag"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","ThickFramesGlasses","ThinFramesGlasses","","","","","",""};
		ref TStringArray shoesArray = {"JoggingShoes_White","Ballerinas_White","DressShoes_White","Ballerinas_White","Ballerinas_Blue","Ballerinas_Red","Ballerinas_White"};
		ref TStringArray glovesArray = {"SurgicalGloves_White","SurgicalGloves_LightBlue","SurgicalGloves_Blue","SurgicalGloves_Green"};
		ref TStringArray maskArray = {"SurgicalMask","","SurgicalMask"};
		ref TStringArray medsArray = {"PainkillerTablets","Morphine","BloodTestKit","DisinfectantAlcohol"};
		ref TStringArray meds2Array = {"TetracyclineAntibiotics","Epinephrine","Thermometer","VitaminBottle"};
		ref TStringArray meds3Array = {"BloodBagIV","BloodBagFull","BloodBagEmpty","SalineBag","SalineBagIV","StartKitIV"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(dressArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(medsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(meds2Array.GetRandomElement());
		player.GetInventory().CreateInInventory(meds3Array.GetRandomElement());
		ItemBase rags = player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("WaterBottle");
		player.GetInventory().CreateInInventory("Apple");
		ItemBase light = player.GetInventory().CreateInInventory("Headtorch_Grey");
		light.GetInventory().CreateAttachment("Battery9V");
		return rags;
	}

	EntityAI nurseMaleClass(PlayerBase player)
	{
		ref TStringArray hatArray = {"MedicalScrubsHat_Blue","MedicalScrubsHat_Green","MedicalScrubsHat_White"};
		ref TStringArray topArray = {"MedicalScrubsShirt_Blue","MedicalScrubsShirt_Green","MedicalScrubsShirt_White"};
		ref TStringArray pantsArray = {"MedicalScrubsPants_Blue","MedicalScrubsPants_Green","MedicalScrubsPants_White"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","ThickFramesGlasses","ThinFramesGlasses","","","","","",""};
		ref TStringArray shoesArray = {"JoggingShoes_White","DressShoes_White"};
		ref TStringArray glovesArray = {"SurgicalGloves_White","SurgicalGloves_LightBlue","SurgicalGloves_Blue","SurgicalGloves_Green"};
		ref TStringArray medsArray = {"PainkillerTablets","Morphine","BloodTestKit","DisinfectantAlcohol"};
		ref TStringArray meds2Array = {"TetracyclineAntibiotics","Epinephrine","Thermometer","VitaminBottle"};
		ref TStringArray meds3Array = {"BloodBagIV","BloodBagFull","BloodBagEmpty","SalineBag","SalineBagIV","StartKitIV"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(medsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(meds2Array.GetRandomElement());
		player.GetInventory().CreateInInventory(meds3Array.GetRandomElement());
		player.GetInventory().CreateInInventory("SurgicalMask");
		ItemBase rags = player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("WaterBottle");
		player.GetInventory().CreateInInventory("Apple");
		player.GetInventory().CreateInInventory("RoadFlare");
		return rags;
	}


	EntityAI prisonerClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin", "PowderedMilk", "Rice", "BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "SlicedPumpkin", "Potato", "SambucusBerry", "CaninaBerry", "Plum", "Pear", "AgaricusMushroom", "AmanitaMushroom", "MacrolepiotaMushroom", "LactariusMushroom", "PsilocybeMushroom", "AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"PrisonerCap","PrisonerCap"};
		ref TStringArray topArray = {"PrisonUniformJacket","PrisonUniformJacket"};
		ref TStringArray pantsArray = {"PrisonUniformPants","PrisonUniformPants"};
		ref TStringArray shoesArray = {"AthleticShoes_Blue", "AthleticShoes_Black", "AthleticShoes_Brown", "AthleticShoes_Green", "AthleticShoes_Grey", "JoggingShoes_Black", "JoggingShoes_Blue", "JoggingShoes_Red", "JoggingShoes_Violet", "JoggingShoes_White"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","", "BandanaMask_BlackPattern","","","","", "BandanaMask_PolkaPattern","","","","", "BandanaMask_GreenPattern","","","","", "BandanaMask_CamoPattern","","","","", "HockeyMask","","","HockeyMask","","","","", "BalaclavaMask_Black","","","","", "BalaclavaMask_Blackskull","","","","","","","","", "BalaclavaMask_Blue","","","","","","","","","","","",""};
		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("RoadFlare");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		return rags;
	}

	
	EntityAI cowboyClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"CowSteakMeat","PowderedMilk","Rice","BakedBeansCan_Opened","Potato"};
		ref TStringArray drinkArray = {"SodaCan_Kvass","SodaCan_Kvass"};
		ref TStringArray hatArray = {"CowboyHat_Brown","CowboyHat_black","CowboyHat_darkBrown","CowboyHat_green"};
        ref TStringArray topArray = {"Paradise_Hoodie_blue",""};
		ref TStringArray pantsArray = {"Jeans_Blue","Jeans_BlueDark"};
		ref TStringArray vestArray  = {"LeatherStorageVest_Natural","", "LeatherStorageVest_Beige","", "LeatherStorageVest_Brown","", "LeatherStorageVest_Black","","ChestHolster","ChestHolster","ChestHolster","ChestHolster"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","","SportGlasses_Black","","","","SportGlasses_Green","","","","SportGlasses_Orange","","","","AviatorGlasses","","","",""};
		ref TStringArray shoesArray = {"Wellies_Black","Wellies_Brown","Wellies_Green","Wellies_Grey","WorkingBoots_Grey","WorkingBoots_Brown","WorkingBoots_Green","WorkingBoots_Beige"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","","","BandanaMask_BlackPattern","","","","","","BandanaMask_PolkaPattern","","","","","","BandanaMask_GreenPattern","","","","","",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("RoadFlare");
		player.GetInventory().CreateInInventory("Rope");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		return rags;
	}
	
	EntityAI cowgirlClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"CowSteakMeat","PowderedMilk","Rice","BakedBeansCan_Opened","Tomato","GreenBellPepper","SlicedPumpkin","Potato"};
		ref TStringArray drinkArray = {"SodaCan_Kvass","SodaCan_Kvass"};
		ref TStringArray hatArray = {"CowboyHat_Brown","CowboyHat_black","CowboyHat_darkBrown","CowboyHat_green"};
        ref TStringArray topArray = {"Paradise_Hoodie_blue",""};
		ref TStringArray pantsArray = {"ShortJeans_Black", "ShortJeans_Blue", "ShortJeans_Brown", "ShortJeans_Darkblue", "ShortJeans_Green", "ShortJeans_Red", "Skirt_Blue", "Skirt_Red", "Skirt_White", "Skirt_Yellow"};
		ref TStringArray vestArray  = {"LeatherStorageVest_Natural","","","", "LeatherStorageVest_Beige","","","", "LeatherStorageVest_Brown","","","", "LeatherStorageVest_Black","","","","ChestHolster","ChestHolster","ChestHolster","ChestHolster"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","","SportGlasses_Black","","","","SportGlasses_Green","","","","SportGlasses_Orange","","","","AviatorGlasses","","","",""};
		ref TStringArray shoesArray = {"Wellies_Black","Wellies_Brown","Wellies_Green","Wellies_Grey","WorkingBoots_Grey","WorkingBoots_Brown","WorkingBoots_Green","WorkingBoots_Beige"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","","","BandanaMask_BlackPattern","","","","","","BandanaMask_PolkaPattern","","","","","","BandanaMask_GreenPattern","","","","","",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("RoadFlare");
		player.GetInventory().CreateInInventory("Rope");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		return rags;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();

		if(player.IsMale())
		{
			EntityAI male;
			switch (Math.RandomInt(0, 30))
			{
				case 0: male = randomMaleClass(player); break;
				case 1: male = doctorClass(player); break;
				case 2: male = nurseMaleClass(player); break;
				case 3: male = randomMaleClass(player); break;
				case 4: male = randomMaleClass(player); break;
				case 5: male = randomMaleClass(player); break;
				case 6: male = prisonerClass(player); break;
				case 7: male = randomMaleClass(player); break;
				case 8: male = randomMaleClass(player); break;
				case 9: male = randomMaleClass(player); break;
				case 10: male = randomMaleClass(player); break;
				case 11: male = randomMaleClass(player); break;
				case 12: male = randomMaleClass(player); break;
				case 13: male = randomMaleClass(player); break;
				case 14: male = cowboyClass(player); break;
				case 15: male = prisonerClass(player); break;
				case 16: male = randomMaleClass(player); break;
				case 17: male = randomMaleClass(player); break;
				case 18: male = randomMaleClass(player); break;
				case 19: male = randomMaleClass(player); break;
				case 20: male = randomMaleClass(player); break;
				case 21: male = randomMaleClass(player); break;
				case 22: male = randomMaleClass(player); break;
				case 23: male = randomMaleClass(player); break;
				case 24: male = randomMaleClass(player); break;
				case 25: male = randomMaleClass(player); break;
				case 26: male = nurseMaleClass(player); break;
				case 27: male = prisonerClass(player); break;
				case 28: male = prisonerClass(player); break;
				case 29: male = prisonerClass(player); break;
			}
		}
		else
		{
			EntityAI female;
			switch (Math.RandomInt(0, 30))
			{
				case 0: female = randomFemaleClass(player); break;
				case 1: female = randomFemale2Class(player); break;
				case 2: female = nurseClass(player); break;
				case 3: female = randomFemaleClass(player); break;
				case 4: female = randomFemaleClass(player); break;
				case 5: female = randomFemaleClass(player); break;
				case 6: female = randomFemaleClass(player); break;
				case 7: female = hunterFemaleClass(player); break;
				case 8: female = randomFemaleClass(player); break;
				case 9: female = randomFemaleClass(player); break;
				case 10: female = randomFemaleClass(player); break;
				case 11: female = randomFemaleClass(player); break;
				case 12: female = scientistClass(player); break;
				case 13: female = randomFemaleClass(player); break;
				case 14: female = prisonerClass(player); break;
				case 15: female = prisonerClass(player); break;
				case 16: female = nurseClass(player); break;
				case 17: female = cowgirlClass(player); break;
				case 18: female = randomFemaleClass(player); break;
				case 19: female = randomFemaleClass(player); break;
				case 20: female = randomFemaleClass(player); break;
				case 21: female = randomFemaleClass(player); break;
				case 22: female = randomFemaleClass(player); break;
				case 23: female = randomFemaleClass(player); break;
				case 24: female = randomFemaleClass(player); break;
				case 25: female = randomFemale2Class(player); break;
				case 26: female = randomFemale2Class(player); break;
				case 27: female = randomFemale2Class(player); break;
				case 28: female = randomFemale2Class(player); break;
				case 29: female = randomFemale2Class(player); break;
			}
		}
	}
	//MODDED LOADOUTS - END-------------------------------------
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}