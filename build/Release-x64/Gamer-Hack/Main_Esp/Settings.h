#pragma once
#include <string>
#include <d3d9.h>
#include <vector>
#include "../pch.h"
namespace g_Settings
{
#pragma region Misc
	extern bool GlobalSelected ;
	extern bool BgmiSelected;

#pragma endregion

#pragma region Menu

	extern bool bUpdateSettings;
	extern bool bReset;
	extern bool bEnd;
#pragma endregion

#pragma region PlayerEsp
	/**extern bool ShowMenu;
	extern bool PlayerEsp ;
	extern bool PlayerLines ;
	extern bool ShowItems ;
	extern bool PlayerBox ;
	extern bool vehicleEsp;
	extern bool LootBoxItems;
	extern bool PlayerSkeleton ;
	extern bool GrenadeAlert ;
	extern bool FightMode;

	extern bool menu;*/





	extern int iEspMaxDist;
	extern int IEspDelay;

	extern bool ShowMenu;
	extern bool PlayerEsp;
	extern bool PlayerLines;

	extern bool BotLines;


	extern bool ShowItems;
	extern bool PlayerBox;
	extern bool vehicleEsp;

	extern bool vehicleHealth;

	extern bool LootBoxItems;

	extern bool HandGun;
	extern bool PlayerSkeleton;
	extern bool Name;
	extern bool GrenadeAlert;
	extern int iEspMaxDist;
	extern int IEspDelay;
	extern bool FightMode;
	///
	extern bool menu;
	extern bool  Bone;
	extern bool graned;
	//
	extern bool impitems;
	extern bool Item;
	extern bool scope;
	extern bool healthitem;
	extern bool attatchment;
	extern bool IPad;
	extern bool Esp_Item_M416;
	extern float Esp_Item_M416_Color[4];
	extern float Esp_Item_M416_TextSize;
	extern bool Esp_Item_AirDrop;
	extern float Esp_Item_AirDrop_Color[4];
	extern float Esp_Item_AirDrop_TextSize;
	extern bool Esp_Item_MedKit;
	extern float Esp_Item_MedKit_Color[4];
	extern float Esp_Item_MedKit_TextSize;
	extern bool Esp_Item_FirstAidKit;
	extern float Esp_Item_FirstAidKit_Color[4];
	extern float Esp_Item_FirstAidKit_TextSize;
	extern bool Esp_Item_Painkiller;
	extern float Esp_Item_Painkiller_Color[4];
	extern float Esp_Item_Painkiller_TextSize;
	extern bool Esp_Item_EnergyDrink;
	extern float Esp_Item_EnergyDrink_Color[4];
	extern float Esp_Item_EnergyDrink_TextSize;
	extern bool Esp_Item_AdrenalineSyringe;
	extern float Esp_Item_AdrenalineSyringe_Color[4];
	extern float Esp_Item_AdrenalineSyringe_TextSize;
	extern bool Esp_Item_Bandage;
	extern float Esp_Item_Bandage_Color[4];
	extern float Esp_Item_Bandage_TextSize;
	extern bool Esp_Item_AKM;
	extern float Esp_Item_AKM_Color[4];
	extern float Esp_Item_AKM_TextSize;
	extern bool Esp_Item_SCARL;
	extern float Esp_Item_SCARL_Color[4];
	extern float Esp_Item_SCARL_TextSize;
	extern bool Esp_Item_M762;
	extern float Esp_Item_M762_Color[4];
	extern float Esp_Item_M762_TextSize;
	extern bool Esp_Item_DP28;
	extern float Esp_Item_DP28_Color[4];
	extern float Esp_Item_DP28_TextSize;
	extern bool Esp_Item_Awm;
	extern float Esp_Item_Awm_Color[4];
	extern float Esp_Item_Awm_TextSize;
	extern bool Esp_Item_M24;
	extern float Esp_Item_M24_Color[4];
	extern float Esp_Item_M24_TextSize;
	extern bool Esp_Item_Kar98k;
	extern float Esp_Item_Kar98k_Color[4];
	extern float Esp_Item_Kar98k_TextSize;
	extern bool Esp_Item_FlareGun;
	extern float Esp_Item_FlareGun_Color[4];
	extern float Esp_Item_FlareGun_TextSize;
	extern bool Esp_Item_Flare;
	extern float Esp_Item_Flare_Color[4];
	extern float Esp_Item_Flare_TextSize;
	extern bool Esp_Item_Bag1;
	extern float Esp_Item_Bag1_Color[4];
	extern float Esp_Item_Bag1_TextSize;
	extern bool Esp_Item_Bag2;
	extern float Esp_Item_Bag2_Color[4];
	extern float Esp_Item_Bag2_TextSize;
	extern bool Esp_Item_Helmet1;
	extern float Esp_Item_Helmet1_Color[4];
	extern float Esp_Item_Helmet1_TextSize;
	extern bool Esp_Item_Helmet2;
	extern float Esp_Item_Helmet2_Color[4];
	extern float Esp_Item_Helmet2_TextSize;
	extern bool Esp_Item_Armor1;
	extern float Esp_Item_Armor1_Color[4];
	extern float Esp_Item_Armor1_TextSize;
	extern bool Esp_Item_Armor2;
	extern float Esp_Item_Armor2_Color[4];
	extern float Esp_Item_Armor2_TextSize;
	extern bool Esp_Item_Mk47Mutant;
	extern float Esp_Item_Mk47Mutant_Color[4];
	extern float Esp_Item_Mk47Mutant_TextSize;
	extern bool Esp_Item_M16A4;
	extern float Esp_Item_M16A4_Color[4];
	extern float Esp_Item_M16A4_TextSize;
	extern bool Esp_Item_G36C;
	extern float Esp_Item_G36C_Color[4];
	extern float Esp_Item_G36C_TextSize;
	extern bool Esp_Item_QBZ;
	extern float Esp_Item_QBZ_Color[4];
	extern float Esp_Item_QBZ_TextSize;
	extern bool Esp_Item_QBU;
	extern float Esp_Item_QBU_Color[4];
	extern float Esp_Item_QBU_TextSize;
	extern bool Esp_Item_SLR;
	extern float Esp_Item_SLR_Color[4];
	extern float Esp_Item_SLR_TextSize;
	extern bool Esp_Item_SKS;
	extern float Esp_Item_SKS_Color[4];
	extern float Esp_Item_SKS_TextSize;
	extern bool Esp_Item_Mini14;
	extern float Esp_Item_Mini14_Color[4];
	extern float Esp_Item_Mini14_TextSize;
	extern bool Esp_Item_M249;
	extern float Esp_Item_M249_Color[4];
	extern float Esp_Item_M249_TextSize;
	extern bool Esp_Item_MK12;
	extern float Esp_Item_MK12_Color[4];
	extern float Esp_Item_MK12_TextSize;
	extern bool Esp_Item_Mosin;
	extern float Esp_Item_Mosin_Color[4];
	extern float Esp_Item_Mosin_TextSize;
	extern bool Esp_Item_PP19;
	extern float Esp_Item_PP19_Color[4];
	extern float Esp_Item_PP19_TextSize;
	extern bool Esp_Item_TommyGun;
	extern float Esp_Item_TommyGun_Color[4];
	extern float Esp_Item_TommyGun_TextSize;
	extern bool Esp_Item_MP5K;
	extern float Esp_Item_MP5K_Color[4];
	extern float Esp_Item_MP5K_TextSize;
	extern bool Esp_Item_UMP9;
	extern float Esp_Item_UMP9_Color[4];
	extern float Esp_Item_UMP9_TextSize;
	extern bool Esp_Item_Vector;
	extern float Esp_Item_Vector_Color[4];
	extern float Esp_Item_Vector_TextSize;
	extern bool Esp_Item_Uzi;
	extern float Esp_Item_Uzi_Color[4];
	extern float Esp_Item_Uzi_TextSize;
	extern bool Esp_Item_762mm;
	extern float Esp_Item_762mm_Color[4];
	extern float Esp_Item_762mm_TextSize;
	extern bool Esp_Item_556mm;
	extern float Esp_Item_556mm_Color[4];
	extern float Esp_Item_556mm_TextSize;
	extern bool Esp_Item_9mm;
	extern float Esp_Item_9mm_Color[4];
	extern float Esp_Item_9mm_TextSize;
	extern bool Esp_Item_45ACP;
	extern float Esp_Item_45ACP_Color[4];
	extern float Esp_Item_45ACP_TextSize;
	extern bool airdrop;
	extern bool airdropitem;
	extern bool Esp_Item_Bag3;
	extern float Esp_Item_Bag3_Color[4];
	extern float Esp_Item_Bag3_TextSize;
	extern bool Esp_Item_Helmet3;
	extern float Esp_Item_Helmet3_Color[4];
	extern float Esp_Item_Helmet3_TextSize;
	extern bool Esp_Item_Armor3;
	extern float Esp_Item_Armor3_Color[4];
	extern float Esp_Item_Armor3_TextSize;
	extern bool Esp_Item_CrossBow;
	extern float Esp_Item_CrossBow_Color[4];
	extern float Esp_Item_CrossBow_TextSize;
	extern bool Esp_Item_Arrows;
	extern float Esp_Item_Arrows_Color[4];
	extern float Esp_Item_Arrows_TextSize;
	extern bool Esp_Item_Pan;
	extern float Esp_Item_Pan_Color[4];
	extern float Esp_Item_Pan_TextSize;
	extern bool Esp_Item_Sickle;
	extern float Esp_Item_Sickle_Color[4];
	extern float Esp_Item_Sickle_TextSize;
	extern bool Esp_Item_Machete;
	extern float Esp_Item_Machete_Color[4];
	extern float Esp_Item_Machete_TextSize;
	extern bool Esp_Item_ASM_Abakan;
	extern float Esp_Item_ASM_Abakan_Color[4];
	extern float Esp_Item_ASM_Abakan_TextSize;
	extern bool Esp_Item_Apple_Weapon;
	extern float Esp_Item_Apple_Weapon_Color[4];
	extern float Esp_Item_Apple_Weapon_TextSize;
	extern bool Esp_Item_Vertical;
	extern float Esp_Item_Vertical_Color[4];
	extern float Esp_Item_Vertical_TextSize;
	extern bool Esp_Item_Mk14;
	extern float Esp_Item_Mk14_Color[4];
	extern float Esp_Item_Mk14_TextSize;
	extern bool Esp_Item_Sniper_EQ;
	extern float Esp_Item_Sniper_EQ_Color[4];
	extern float Esp_Item_Sniper_EQ_TextSize;
	extern bool Esp_Item_Large_Suppressor;
	extern float Esp_Item_Large_Suppressor_Color[4];
	extern float Esp_Item_Large_Suppressor_TextSize;
	extern bool Esp_Item_Large_EQ;
	extern float Esp_Item_Large_EQ_Color[4];
	extern float Esp_Item_Large_EQ_TextSize;
	extern bool Esp_Item_Large_E;
	extern float Esp_Item_Large_E_Color[4];
	extern float Esp_Item_Large_E_TextSize;
	extern bool Esp_Item_Mid_EQ;
	extern float Esp_Item_Mid_EQ_Color[4];
	extern float Esp_Item_Mid_EQ_TextSize;
	extern bool Esp_Item_Mid_E;
	extern float Esp_Item_Mid_E_Color[4];
	extern float Esp_Item_Mid_E_TextSize;
	extern bool Esp_Item_Mid_Q;
	extern float Esp_Item_Mid_Q_Color[4];
	extern float Esp_Item_Mid_Q_TextSize;
	extern bool Esp_Item_Large_Q;
	extern float Esp_Item_Large_Q_Color[4];
	extern float Esp_Item_Large_Q_TextSize;
	extern bool Esp_Item_Sniper_E;
	extern float Esp_Item_Sniper_E_Color[4];
	extern float Esp_Item_Sniper_E_TextSize;
	extern bool Esp_Item_Sniper_Q;
	extern float Esp_Item_Sniper_Q_Color[4];
	extern float Esp_Item_Sniper_Q_TextSize;
	extern bool Esp_Item_Sniper_Suppressor;
	extern float Esp_Item_Sniper_Suppressor_Color[4];
	extern float Esp_Item_Sniper_Suppressor_TextSize;
	extern bool Esp_Item_ThumbGrip;
	extern float Esp_Item_ThumbGrip_Color[4];
	extern float Esp_Item_ThumbGrip_TextSize;
	extern bool Esp_Item_Lasersight;
	extern float Esp_Item_Lasersight_Color[4];
	extern float Esp_Item_Lasersight_TextSize;
	extern bool Esp_Item_Angled;
	extern float Esp_Item_Angled_Color[4];
	extern float Esp_Item_Angled_TextSize;
	extern bool Esp_Item_LightGrip;
	extern float Esp_Item_LightGrip_Color[4];
	extern float Esp_Item_LightGrip_TextSize;
	extern bool Esp_Item_HalfGrip;
	extern float Esp_Item_HalfGrip_Color[4];
	extern float Esp_Item_HalfGrip_TextSize;
	extern bool Esp_Item_Large_Compensator;
	extern float Esp_Item_Large_Compensator_Color[4];
	extern float Esp_Item_Large_Compensator_TextSize;
	extern bool Esp_Item_Mid_Compensator;
	extern float Esp_Item_Mid_Compensator_Color[4];
	extern float Esp_Item_Mid_Compensator_TextSize;
	extern bool Esp_Item_A;
	extern float Esp_Item_A_Color[4];
	extern float Esp_Item_A_TextSize;
	extern bool Esp_Item_DuckBill;
	extern float Esp_Item_DuckBill_Color[4];
	extern float Esp_Item_DuckBill_TextSize;
	extern bool Esp_Item_Mid_Suppressor;
	extern float Esp_Item_Mid_Suppressor_Color[4];
	extern float Esp_Item_Mid_Suppressor_TextSize;
	extern bool Esp_Item_Sniper;
	extern float Esp_Item_Sniper_Color[4];
	extern float Esp_Item_Sniper_TextSize;
	extern bool Esp_Item_Choke;
	extern float Esp_Item_Choke_Color[4];
	extern float Esp_Item_Choke_TextSize;
	extern bool Esp_Item_UZI;
	extern float Esp_Item_UZI_Color[4];
	extern float Esp_Item_UZI_TextSize;
	extern bool Esp_Item_Holo;
	extern float Esp_Item_Holo_Color[4];
	extern float Esp_Item_Holo_TextSize;
	extern bool Esp_Item_x2;
	extern float Esp_Item_x2_Color[4];
	extern float Esp_Item_x2_TextSize;
	extern bool Esp_Item_x3;
	extern float Esp_Item_x3_Color[4];
	extern float Esp_Item_x3_TextSize;
	extern bool Esp_Item_x4;
	extern float Esp_Item_x4_Color[4];
	extern float Esp_Item_x4_TextSize;
	extern bool Esp_Item_x6;
	extern float Esp_Item_x6_Color[4];
	extern float Esp_Item_x6_TextSize;
	extern bool Esp_Item_x8;
	extern float Esp_Item_x8_Color[4];
	extern float Esp_Item_x8_TextSize;
	extern bool Esp_Item_HD;
	extern float Esp_Item_HD_Color[4];
	extern float Esp_Item_HD_TextSize;
	extern bool Esp_Item_Frag;
	extern float Esp_Item_Frag_Color[4];
	extern float Esp_Item_Frag_TextSize;
	extern bool Esp_Item_Smoke;
	extern float Esp_Item_Smoke_Color[4];
	extern float Esp_Item_Smoke_TextSize;
	extern bool Esp_Item_Molotof;
	extern float Esp_Item_Molotof_Color[4];
	extern float Esp_Item_Molotof_TextSize;
	extern bool Esp_Item_Groza;
	extern float Esp_Item_Groza_Color[4];
	extern float Esp_Item_Groza_TextSize;
	extern bool Esp_Item_R1895;
	extern float Esp_Item_R1895_Color[4];
	extern float Esp_Item_R1895_TextSize;
	extern bool Esp_Item_AUG;
	extern float Esp_Item_AUG_Color[4];
	extern float Esp_Item_AUG_TextSize;
	extern bool Esp_Item_SawedOff;
	extern float Esp_Item_SawedOff_Color[4];
	extern float Esp_Item_SawedOff_TextSize;
	extern bool Esp_Item_S12K;
	extern float Esp_Item_S12K_Color[4];
	extern float Esp_Item_S12K_TextSize;
	extern bool Esp_Item_S1897;
	extern float Esp_Item_S1897_Color[4];
	extern float Esp_Item_S1897_TextSize;
	extern bool Esp_Item_S686;
	extern float Esp_Item_S686_Color[4];
	extern float Esp_Item_S686_TextSize;

	extern bool Esp_Item_VSS;
	extern float Esp_Item_VSS_Color[4];
	extern float Esp_Item_VSS_TextSize;
	extern bool Esp_Item_12Guage;
	extern float Esp_Item_12Guage_Color[4];
	extern float Esp_Item_12Guage_TextSize;
	extern bool Esp_Item_Vz61;
	extern float Esp_Item_Vz61_Color[4];
	extern float Esp_Item_Vz61_TextSize;
	extern bool Esp_Item_P92;
	extern float Esp_Item_P92_Color[4];
	extern float Esp_Item_P92_TextSize;
	extern bool Esp_Item_P18C;
	extern float Esp_Item_P18C_Color[4];
	extern float Esp_Item_P18C_TextSize;
	extern bool Esp_Item_Win94;
	extern float Esp_Item_Win94_Color[4];
	extern float Esp_Item_Win94_TextSize;
	extern bool Esp_Item_R45;
	extern float Esp_Item_R45_Color[4];
	extern float Esp_Item_R45_TextSize;
	extern bool Esp_Item_DesertEagle;
	extern float Esp_Item_DesertEagle_Color[4];
	extern float Esp_Item_DesertEagle_TextSize;
	extern bool Esp_Item_P1911;
	extern float Esp_Item_P1911_Color[4];
	extern float Esp_Item_P1911_TextSize;
	extern bool Esp_Item_DBS;
	extern float Esp_Item_DBS_Color[4];
	extern float Esp_Item_DBS_TextSize;
	extern bool Esp_Item_M1014;
	extern float Esp_Item_M1014_Color[4];
	extern float Esp_Item_M1014_TextSize;
	extern bool Esp_Item_Famas;
	extern float Esp_Item_Famas_Color[4];
	extern float Esp_Item_Famas_TextSize;
	extern bool Esp_Item_attatchment;
	extern float Esp_Item_attatchment_Color[4];
	extern float Esp_Item_attatchment_TextSize;
	extern bool Esp_Item_Awmimo;
	
	extern float Esp_Item_Awmimo_Color[4];
	extern float Esp_Item_Awmimo_TextSize;


	extern bool loofyOn;


#pragma endregion


#pragma region Bullet Track

	extern bool EnableBulletTrack;
	extern bool MagicInitialized;
	extern bool MagicRefresh;
	extern bool MagicError;
	extern bool MagicSearching ;
	extern bool MagicInitializing ;
	extern bool BulletTrackTurned ;
	extern bool SkipKnock ;
	extern int  iAimBone ;
	extern int  iAimSelection;
	extern bool AimLine ;
	extern std::vector<UINT>  MagicBulletList;
	extern long  MagicAllocateMem ;
	extern long  MagicBulletHook ;

#pragma optimize( "", off ) 
	extern  byte MagicData[7];
	extern  byte magicByte1[];
	extern  byte magicByte2[];
	extern  byte magicByte3[];
	extern  byte magicByte4[];

#pragma optimize( "", on ) 
#pragma endregion


#pragma region NoRecoil
	extern bool EnableNoRecoil ;
	extern bool FastRun;
	extern bool GodView;
	extern bool loofy;
	extern bool carFly;
	extern bool speedCar;

#pragma endregion

#pragma region InstantHit
	extern bool EnableInstantHit ;
	extern bool instantstarted ;
	extern float InstantDefaultValue;
#pragma endregion

#pragma region LogInfo
	extern std::string Expiretb;
	extern bool UserLoggedIn;
#pragma endregion




}

namespace weapon {
	extern ImVec4 Ammo556;
	extern ImVec4 Ammo762;
	extern ImVec4 Compensator;
	extern ImVec4 m16A4;
	extern ImVec4 m416;
	extern ImVec4 AKM;
	extern ImVec4 DP;
	extern ImVec4 AWM;
	extern ImVec4 AWMimmo;
	extern ImVec4 scarl;
	extern ImVec4 m762;
	extern ImVec4 M24;
	extern ImVec4  GROZZA;
	extern ImVec4 scope8x;
	extern ImVec4 kar98;
	extern ImVec4  Airdrop;
	extern ImVec4 Flare;
	extern ImVec4 Flaregun;
	extern ImVec4 Bag3;
	extern ImVec4 Bag2;
	extern ImVec4 vehicle;
	extern ImVec4 Armor3;
	extern ImVec4 Armor2;
	extern ImVec4 Armor1;
	extern ImVec4 Bag1;
	extern ImVec4 Bag2;
	extern ImVec4 Bag3;
	extern ImVec4 Helmet1;
	extern ImVec4 Helmet2;
	extern ImVec4 Helmet3;
	extern ImVec4 Machete;
	extern ImVec4 Awmimo;
	extern ImVec4 Frag;
	extern ImVec4 Smoke;
	extern ImVec4 Molotof;
	extern ImVec4 ASMAbakanAR;
	extern ImVec4 Arrow;
	extern ImVec4 CrossBow;
	extern ImVec4 Mosin;
	extern ImVec4 MK14;
	extern ImVec4 Groza;
	extern ImVec4 Pan;
	extern ImVec4 Sickle;
	extern ImVec4 Vector;
	extern ImVec4 Uzi;
	extern ImVec4 Ammo9mm;
	extern ImVec4 UMP9;
	extern ImVec4 MedKit;
	extern ImVec4 FirstAidKit;
	extern ImVec4 Painkiller;
	extern ImVec4 EnergyDrink;
	extern ImVec4 AdrenalineSyringe;
	extern ImVec4 Bandage;
	extern ImVec4 Apple;
	extern ImVec4 G36C;
	extern ImVec4 QBZ;
	extern ImVec4 SLR;
	extern ImVec4 Mini14;
	extern ImVec4 Mk47Mutant;
	extern ImVec4 M249;
	extern ImVec4 MK12;
	extern ImVec4 R1895;
	extern ImVec4 AUG;
	extern ImVec4 Famas;
	extern ImVec4 SawedOff;
	extern ImVec4 DBS;
	extern ImVec4 S12K;
	extern ImVec4 M1014;
	extern ImVec4 S1897;
	extern ImVec4 S686;
	extern ImVec4 GUAGE12;
	extern ImVec4 VSS;
	extern ImVec4 R45;
	extern ImVec4 Vz61;
	extern ImVec4 P18C;
	extern ImVec4 P92;
	extern ImVec4 Win94;
	extern ImVec4 DesertEagle;
	extern ImVec4 P1911;
	extern ImVec4 SKS;
	extern ImVec4 QBU;
	extern ImVec4 PP19;
	extern ImVec4 TommyGun;
	extern ImVec4 MP5K;
	extern ImVec4 ACP45;
	extern ImVec4 Mid_E;
	extern ImVec4 Mid_Q;
	extern ImVec4 Mid_EQ;
	extern ImVec4 Large_E;
	extern ImVec4 Large_Q;
	extern ImVec4 Large_EQ;
	extern ImVec4 Sniper_E;
	extern ImVec4 Sniper_Q;
	extern ImVec4 Sniper_EQ;
	extern ImVec4 Mid_Compensator;
	extern ImVec4 Mid_Suppressor;
	extern ImVec4 Large_Compensator;
	extern ImVec4 Large_Suppressor;
	extern ImVec4 Sniper_Suppressor;
	extern ImVec4 Vertical;
	extern ImVec4 Choke;
	extern ImVec4 HalfGrip;
	extern ImVec4 ThumbGrip;
	extern ImVec4 Angled;
	extern ImVec4 LightGrip;
	extern ImVec4 Lasersight;
	extern ImVec4 Sniper;
	extern ImVec4 UZI;
	extern ImVec4 DuckBill;
	extern ImVec4 A;
	extern ImVec4 Holo;
	extern ImVec4 x2;
	extern ImVec4 x3;
	extern ImVec4 x4;
	extern ImVec4 x6;
	extern ImVec4 x8;
	extern ImVec4 HD;
}
namespace Colors {
	extern	ImVec4  playerline2;
	extern ImVec4  botline2;
	extern	ImVec4  playerline;
	extern	ImVec4  playercorner;
	extern	ImVec4  playerbox;
	extern	ImVec4  lotbox;
	extern ImVec4  helthbar;
	extern ImVec4  boxColor;
	extern ImVec4  cornerColor;
	extern ImVec4  crosshairColor;
	extern	ImVec4  bot;
	extern	ImVec4  botbone;
	extern	ImVec4  playerbone;
	extern	ImVec4  player;
	extern ImVec4  botcorner;
	extern ImVec4  botline;
	extern	ImVec4 circle;
	extern	ImVec4  enemy;
	extern	ImVec4  botbox;
	extern	ImVec4  bone;
	extern	 ImVec4  fillrect;
	extern	 ImVec4  nam;
	extern	 ImVec4  nambar;
	extern	 ImVec4  bothealth;
	extern	ImVec4  botname;
	extern	ImVec4  playerhealth;
	extern	ImVec4  textcolor;
	extern	ImVec4 Granades;
	extern	ImVec4 health;
	extern	ImVec4 deadbox;
	extern	ImVec4 deadboxitem;
	extern	ImVec4 airdrop;
	extern	ImVec4 airdropitem;
	extern	ImVec4 scopetextcolor;
	extern	ImVec4  allitem;
	extern	ImVec4  scope6x;


	
}