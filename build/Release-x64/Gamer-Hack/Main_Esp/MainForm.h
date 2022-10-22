#pragma once
#include "../pch.h"
class MainForm {
public:
	MainForm();
	~MainForm();

	UINT viewWordBase = 0;
	UINT viewWorld = 0;
	UINT uWorld = 0;
	UINT gNames = 0;
	
	std::vector<playerData> PlayerData,PlayertmpData;
	std::vector<Item> ItemData, ItemTmpData;
	std::vector<Vehicle> VehicleData, VehicleTmpData;
	std::vector<Lootbox> LootBoxData, LootBoxTmpData;
	std::vector<Item> GrenadeAlertData, GrenadeAlertDataTmp;
	std::vector<UINT> PlayersCounttmp, PlayersCount;
	std::vector<UINT> BotsCounttmp, BotsCount;

	D3DMatrix ViewMatrix;
	Item tempb,itm;
	Vehicle vhi;
	Lootbox lbox;
	UINT CurrentWeapon=0 ;
	UINT ShootWeaponEntity = 0;

	UINT uWorlds =0;
	UINT uLevel = 0;
	UINT gameInstance = 0;
	UINT playerController = 0;
	UINT playerCarry = 0;
	UINT LocalPawn = 0;

	UINT entityEntry = 0;
	int entityCount = 0;
	UINT viewMatrixAddr = 0;
	int status = 0;
	UINT entityAddv = 0;
	UINT entityStruct = 0;
	std::string name, entityType, alert, vehicle,boxitem;
	
	void InfoThread();
	void UpdateKeys();
	void init();
	void loofy();
	void carFly();
	void godview();
	void FastCar();
	enum BoneIndex
	{
		Head = 5,
		Chest = 4,
		Pelvis = 1,
		LeftSholder = 11,
		RightSholder = 32,
		LeftElbow = 12,
		RightElbow = 33,
		LeftWrist = 63,
		RightWrist = 62,
		LeftThigh = 52,
		RightThigh = 56,
		LeftKnee = 53,
		RightKnee = 57,
		LeftAnkle = 54,
		RightAnkle = 58


	};
};


extern MainForm* g_MainForm;