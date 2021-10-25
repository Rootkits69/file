//Spawn helper function
void SpawnObject( string type, vector position, vector orientation )
{
    auto obj = GetGame().CreateObject( type, position );
    obj.SetPosition( position );
    obj.SetOrientation( orientation );
    obj.SetOrientation( obj.GetOrientation() ); //Collision fix
    obj.Update();
    obj.SetAffectPathgraph( true, false );
    if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
}

/*
//Spawn helper function
void SpawnObject( string type, vector position, vector orientation )
{
    auto obj = GetGame().CreateObject_WIP( type, position, ECE_CREATEPHYSICS );
    obj.SetFlags( EntityFlags.STATIC, false );
    obj.SetPosition( position );
    obj.SetOrientation( orientation );
    obj.SetOrientation( obj.GetOrientation() ); //Collision fix
    obj.Update();
    obj.SetAffectPathgraph( true, false );
    if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
}
*/

#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\Locations\NEAF.c"
#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\Locations\balota.c"
#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\Locations\Stary.c"
#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\Locations\NWAF.c"
#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\Locations\Skalistyisland.c"
#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\Locations\abandonedBunker.c"
#include "$CurrentDir:\mpmissions\dayzOffline.chernarusplus\Locations\VyborVMC.c"

void main()
{

   balota();
   NWAF();
   NEAF();
   Stary();
   Skalistyisland();
   abandonedBunker();
   VyborVMC();

/*
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0, 0.0), 0.0, 0);
	weather.GetRain().Set( 0, 0, 0);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.0), 0, 0);
*/

   //INIT WEATHER BEFORE ECONOMY INIT------------------------
    Weather weather = g_Game.GetWeather();
    weather.MissionWeather(false);    // false = use weather controller from Weather.c

    weather.GetOvercast().SetLimits( 0.0 , 0.0 );
    weather.GetRain().SetLimits(0.0, 0.0);
    weather.GetFog().SetLimits(0.0, 0.0);

    weather.GetOvercast().SetForecastChangeLimits(0.0, 0.0);
    weather.GetRain().SetForecastChangeLimits(0.0, 0.0);
    weather.GetFog().SetForecastChangeLimits(0.0, 0.0);

    weather.GetOvercast().SetForecastTimeLimits(0, 0);
    weather.GetRain().SetForecastTimeLimits(0, 0);
    weather.GetFog().SetForecastTimeLimits(0, 0);

    weather.GetOvercast().Set(Math.RandomFloatInclusive(0.0, 0.0), 0, 0);
    weather.GetRain().Set(Math.RandomFloatInclusive(0.0, 0.0), 0, 0);
    weather.GetFog().Set(Math.RandomFloatInclusive(0, 0), 0, 0);

    weather.SetWindMaximumSpeed(30);
    weather.SetWindFunctionParams(0.0, 0.0, 0);



	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();


//	GetCEApi().ExportProxyData( "7500 0 7500", 10000 );

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


   override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
{
	player.RemoveAllItems();

	EntityAI itemEnt;
	ItemBase itemBs;

    switch (Math.RandomInt(0,1)) { 
    case 0:
    // 0
    player.GetInventory().CreateInInventory("Paradise_Hoodie_Blue");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("TrackSuitPants_Red");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("Sneakers_Red");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("BandanaMask_RedPattern");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("StoneKnife");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("Rag");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("SodaCan_Pipsi");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("PowderedMilk");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("TunaCan");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("Apple");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("SuperHeatpack");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("SuperHeatpack");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("Headtorch_Grey");itemBs = ItemBase.Cast(itemEnt);
    player.GetInventory().CreateInInventory("Battery9V");itemBs = ItemBase.Cast(itemEnt);
    //player.GetInventory().CreateInInventory("ChernorusMap");itemBs = ItemBase.Cast(itemEnt);
    //player.GetInventory().CreateInInventory("PurificationTablets");itemBs = ItemBase.Cast(itemEnt);
        break; 

									}
    //Give universal gear
	//itemEnt = player.GetInventory().CreateInInventory("Rag");
	//itemBs = ItemBase.Cast(itemEnt);
	//itemBs.SetQuantity(4);
    //SetRandomHealth(itemEnt);
    //player.GetInventory().CreateInInventory("HuntingKnife");
}
};


/*
	//MODDED LOADOUTS - BEGIN-----------------------------------
	EntityAI randomMaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"PeachesCan_Opened","TacticalBaconCan_Opened"};
		ref TStringArray drinkArray = {"WaterBottle"};
		ref TStringArray hatArray = {"Headtorch_Grey"};
		ref TStringArray topArray = {"Paradise_Hoodie_Blue"};
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
		player.GetInventory().CreateInInventory("KitchenKnife");
		player.GetInventory().CreateInInventory("Battery9V");
		ItemBase rags = player.GetInventory().CreateInInventory("BandageDressing");
		rags.SetQuantity(4);
		return rags;
	}

	EntityAI randomFemaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"PeachesCan_Opened","TacticalBaconCan_Opened"};
		ref TStringArray drinkArray = {"WaterBottle"};
		ref TStringArray hatArray = {"Headtorch_Grey"}; 		
        ref TStringArray topArray = {"Paradise_Hoodie_Blue"};
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
		player.GetInventory().CreateInInventory("KitchenKnife");
		player.GetInventory().CreateInInventory("Battery9V");
		ItemBase rags = player.GetInventory().CreateInInventory("BandageDressing");
		rags.SetQuantity(4);
		return rags;
	}

	

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();

		if(player.IsMale())
		{
			EntityAI male;
			switch (Math.RandomInt(0, 2))
			{
				case 0: male = randomMaleClass(player); break;
				case 1: male = randomMaleClass(player); break;
			}
		}
		else
		{
			EntityAI female;
			switch (Math.RandomInt(0, 2))
			{
				case 0: female = randomFemaleClass(player); break;
				case 1: female = randomFemaleClass(player); break;
			}
		}
	}
	//MODDED LOADOUTS - END-------------------------------------
};
*/
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}