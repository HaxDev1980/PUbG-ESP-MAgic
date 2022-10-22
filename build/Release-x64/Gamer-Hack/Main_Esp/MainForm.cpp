#include "MainForm.h"
#include <thread>
#include "..\OverlayDock\Overlay.hpp"
#include <sys/stat.h>

MainForm* g_MainForm = new MainForm();

MainForm::MainForm() {}


MainForm::~MainForm() {}




DWORD ProcessId = 0;
KernelHelper Driver;

int myTeamID = -1;

float DefaultRecoilInfo[7];

BOOL RecoilStarted = false;

void UpdateInfoThread()
{
	while (true)
	{
		g_MainForm->InfoThread();
		std::this_thread::sleep_for(std::chrono::milliseconds(g_Settings::IEspDelay+5));
	}
}
void UpdateFeaturesThread()
{

	while (true)
	{
		bool BFeatures = g_Settings::EnableNoRecoil || g_Settings::EnableInstantHit || g_Settings::instantstarted || g_Settings::FastRun ;
		
		if (BFeatures)
		{
			g_MainForm->UpdateKeys();
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		else
		{

			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}
	}
}

void UpdateLoofyThread()
{

	while (true)
	{
		bool BFeatures = g_Settings::loofy || g_Settings::loofyOn  || g_Settings::GodView;

		if (BFeatures)
		{
			g_MainForm->loofy();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		else
		{

			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}
	}
}

void UpdateFlyCarThread()
{

	while (true)
	{
		bool BFeatures =  g_Settings::carFly;

		if (BFeatures)
		{
			g_MainForm->carFly();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		else
		{

			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}
	}
}

void UpdateGodViewThread()
{

	while (true)
	{
		bool BFeatures =  g_Settings::GodView;

		if (BFeatures)
		{
			g_MainForm->godview();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		else
		{

			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}
	}
}


void UpdateSpeedCarThread()
{

	while (true)
	{
		bool BFeatures = g_Settings::speedCar;

		if (BFeatures)
		{
			g_MainForm->FastCar();
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		else
		{

			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}
	}
}


void UpdateBulletTrackThread()
{

	while (true)
	{
		if (g_Settings::EnableBulletTrack || g_Settings::BulletTrackTurned)
		{
			g_AimForm->UpdateAim();
			std::this_thread::sleep_for(std::chrono::milliseconds(3));
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}

	}
}

HWND EmulatorMainWnd = NULL;
HWND EmulatorRenderWnd = NULL;
void MainForm::init() {
	try
	{
		ProcessId = g_Utilities->Driver.ProcessId;
		Driver = g_Utilities->Driver;

		viewWordBase = g_Utilities->getViewWorld();

#pragma region viewWordNormalErrorValidation
		if (viewWordBase == 0 )
		{
			g_Utilities->MessageTimeout( L"Game Must Be Running Or Restart Your Emulator!!",  MB_ICONERROR);
			exit(1);
			return;
		}
#pragma endregion

	
			/*uWorld = viewWordBase - GameOffsets::GlobalUworldOffset;
			gNames = viewWordBase - GameOffsets::GlobalGNamesOffset;*/

			  uWorld = g_Utilities->Driver.ReadVirtualMemory<UINT>(viewWordBase + 110180) + 60;
			 gNames = g_Utilities->Driver.ReadVirtualMemory<UINT>(viewWordBase - 2984720) + 176;
			
		
	
		/*else
		{
			g_Utilities->MessageTimeout( L"Game Memory Error",  MB_ICONERROR);
			exit(1);
			return;
		}*/
		viewWorld = viewWordBase;
		if (uWorld > 0 && gNames > 0)
		{
		
			g_Utilities->ScanBulletTracking();
		

			if (ProcManager::TargetEmulator == 1 || ProcManager::TargetEmulator == 3)
			{
				std::vector<HWND> RunningWindows = {};
				RunningWindows = ProcManager::GetTargetHWND(L"", L"TXGuiFoundation");
				if (RunningWindows.size() == 0 || RunningWindows.size() > 1)
				{
					g_Utilities->MessageTimeout( L"Emulator Window Not Found",  MB_ICONERROR);
					exit(1);
					return;
				}
				EmulatorMainWnd = RunningWindows.at(0);
				EmulatorRenderWnd = FindWindowEx(EmulatorMainWnd, NULL, L"AEngineRenderWindowClass", NULL);
			}
			else if (ProcManager::TargetEmulator == 2)
			{
				std::vector<HWND> RunningWindows = {};
				RunningWindows = ProcManager::GetTargetHWND(L"", L"TitanRenderWindowClass");
				if (RunningWindows.size() == 0 || RunningWindows.size() > 1)
				{
					g_Utilities->MessageTimeout( L"Emulator Window Not Found",  MB_ICONERROR);
					exit(1);
					return;
				}
				EmulatorRenderWnd = RunningWindows.at(0);
				EmulatorMainWnd = EmulatorRenderWnd;
			}
			else
			{
				g_Utilities->MessageTimeout( L"Emulator Not Found",  MB_ICONERROR);
				exit(1);
				return;
			}

			if (EmulatorMainWnd == NULL || EmulatorRenderWnd == NULL)
			{
				g_Utilities->MessageTimeout( L"Error: Emulator Not Found",  MB_ICONERROR);
				exit(1);
				return;
			}
			if (!IsWindow(EmulatorMainWnd))
			{
				g_Utilities->MessageTimeout( L"Emulator Window Error",  MB_ICONERROR);
				exit(1);
				return;
			}

			Overlay::Overlay hoverlay = Overlay::Overlay();
			if (hoverlay.OverlayWndCreator())
			{
				RECT targetwndrect;
				if (hoverlay.InitiateD3D(0, 0))
				{

					auto infohandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)UpdateInfoThread, 0, 0, 0);
					if (infohandle != 0)
					{
						CloseHandle(infohandle);
					}
					auto BulletTrackhandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)UpdateBulletTrackThread, 0, 0, 0);
					if (BulletTrackhandle != 0)
					{
						CloseHandle(BulletTrackhandle);
					}
					auto Featureshandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)UpdateFeaturesThread, 0, 0, 0);
					if (Featureshandle != 0)
					{
						CloseHandle(Featureshandle);
					}
					auto Loofyhandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)UpdateLoofyThread, 0, 0, 0);
					if (Loofyhandle != 0)
					{
						CloseHandle(Loofyhandle);
					}

					auto CarFlyhandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)UpdateFlyCarThread, 0, 0, 0);
					if (CarFlyhandle != 0)
					{
						CloseHandle(CarFlyhandle);
					}

					auto GodViewFlyhandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)UpdateGodViewThread, 0, 0, 0);
					if (GodViewFlyhandle != 0)
					{
						CloseHandle(GodViewFlyhandle);
					}

					auto SpeedCarFlyhandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)UpdateSpeedCarThread, 0, 0, 0);
					if (SpeedCarFlyhandle != 0)
					{
						CloseHandle(SpeedCarFlyhandle);
					}

					hoverlay.StartRender(EmulatorRenderWnd, EmulatorMainWnd);
				}
				else
				{
					g_Utilities->MessageTimeout( L"Overlay Init Error",  MB_ICONERROR);
					exit(1);
					return;
				}

			}
			else
			{
				g_Utilities->MessageTimeout( L"Overlay Create Window Error",  MB_ICONERROR);
				exit(1);
				return;
			}
		}
		else
		{
			g_Utilities->MessageTimeout( L"Game Memory Not Found",  MB_ICONERROR);
			exit(1);
			return;
		}
	}
	catch (const std::exception&)
	{
		g_Utilities->MessageTimeout( L"Injection Error:Something Went Wrong Please Restart This Application Or Try Again",  MB_ICONERROR);
		exit(1);
		return;
	}

}
struct ObjectNameU
{
	wchar_t data[64];
};
std::string GetPlayerName(ULONG Address)
{
	ObjectNameU pBuffer = g_Utilities->Driver.ReadVirtualMemory<ObjectNameU>(Driver.ReadVirtualMemory<UINT>(Address));
	const auto player_name = std::wstring(pBuffer.data);
	if (player_name.empty())
		return "Player";

	return g_Utilities->ConvertFromUtf16ToUtf8(player_name);
}

float NormalizeHealth(float Health)
{
	if (Health > 100.0f)
		return 100.0f;
	if (Health < 0.0f)
		return 0.0f;
	return Health;
}
bool turne = false;
void MainForm::InfoThread()
{
	try {

		VehicleTmpData.clear();
		PlayertmpData.clear();
		ItemTmpData.clear();
		LootBoxTmpData.clear();
		GrenadeAlertDataTmp.clear();
		PlayersCounttmp.clear();
		BotsCounttmp.clear();

		uWorlds = Driver.ReadVirtualMemory<UINT>(uWorld);
		if (uWorlds != 0)
		{
			uLevel = Driver.ReadVirtualMemory<UINT>(uWorlds + GameOffsets::PersistentLevelOffset);
			gameInstance = Driver.ReadVirtualMemory<long>(uWorlds + GameOffsets::NetDriverOffset);
			if (gameInstance != 0)
			{
				playerController = Driver.ReadVirtualMemory<UINT>(gameInstance + GameOffsets::ServerConnectionOffset);
				if (playerController != 0)
				{
					playerCarry = Driver.ReadVirtualMemory<UINT>(playerController + GameOffsets::PlayerControllerOffset);
					if (playerCarry != 0)
					{
						LocalPawn = Driver.ReadVirtualMemory<UINT>(playerCarry + GameOffsets::LocalPawnOffset);
				
						bool stat = g_Settings::EnableBulletTrack || g_Settings::EnableNoRecoil || RecoilStarted || g_Settings::EnableInstantHit || g_Settings::instantstarted;
						if (stat && LocalPawn != 0)
						{
							CurrentWeapon = g_Utilities->Driver.ReadVirtualMemory<UINT>(LocalPawn + GameOffsets::WeaponOffset);
							ShootWeaponEntity = 0;
							if (CurrentWeapon != 0)
							{
								ShootWeaponEntity = g_Utilities->Driver.ReadVirtualMemory<UINT>(CurrentWeapon + GameOffsets::ShootOffset);
							}

						}
					
					}


				}
				entityEntry = Driver.ReadVirtualMemory<UINT>(uLevel + GameOffsets::EntityEntryOffset);
				entityCount = Driver.ReadVirtualMemory<int>(uLevel + GameOffsets::EntitiesCountOffset);

				viewMatrixAddr = Driver.ReadVirtualMemory<UINT>(Driver.ReadVirtualMemory<UINT>(viewWorld) + 32) + 512;
				ViewMatrix = Driver.ReadVirtualMemory<D3DMatrix>(viewMatrixAddr);

				for (int i = 0; i < entityCount; i++)
				{
					entityAddv = Driver.ReadVirtualMemory<UINT>(entityEntry + i * 4);
					UINT IsEntityItem = Driver.ReadVirtualMemory<UINT>(entityAddv + GameOffsets::ItemDefineIDOffset + GameOffsets::TypeSpecificIDOffset);

				if(IsEntityItem ==0|| IsEntityItem == 3)
				{
					entityStruct = Driver.ReadVirtualMemory<UINT>(entityAddv + 16);
					entityType = g_Utilities->GetEntityType(gNames, entityStruct);

					if (entityType.find("BP_PlayerPawn") != std::string::npos
						|| entityType.find("BP_PlayerCharacter") != std::string::npos
						|| entityType.find("ET_FakePlayer") != std::string::npos
						|| entityType.find("PlanET_FakePlayer") != std::string::npos
						|| entityType.find("PlayerPawn_Infec") != std::string::npos){


						auto PlayerDead = g_Utilities->Driver.ReadVirtualMemory<bool>(entityAddv + GameOffsets::DeadOffset);
						//Skip Dead Entity
						if (PlayerDead)
							continue;


						auto SceneComponent = Driver.ReadVirtualMemory<UINT>(entityAddv + GameOffsets::RootComponentOffset);
						playerData pdata;
						pdata.TeamID = Driver.ReadVirtualMemory<int>(entityAddv + GameOffsets::teamIDOffset);

						if (entityAddv == LocalPawn)
						{
							// Skip Local Player 
							myTeamID = pdata.TeamID;
							continue;
						}
						if (pdata.TeamID == myTeamID)
						{
							//Skip Team
							continue;
						}
						pdata.Position = Driver.ReadVirtualMemory<Vector3>(SceneComponent + GameOffsets::positionOffset);
						bool BisRobot = !Driver.ReadVirtualMemory<bool>(entityAddv + GameOffsets::IsRobotOffset);


						//Player Health
						float phealth = Driver.ReadVirtualMemory<float>(entityAddv + GameOffsets::healthOffset);

						//Normalize Health
						if (phealth > 100.0f) { phealth = 100.0f; }

						bool pknocked = false;
						if (phealth <= 0.0f)
						{
							pknocked = true;
						}



						pdata.Address = entityAddv;
						pdata.Status = status;
						pdata.Pose = Driver.ReadVirtualMemory<int>(SceneComponent + GameOffsets::poseOffset);
						pdata.IsRobot = BisRobot;
						pdata.Health = phealth;
						pdata.IsKnocked = pknocked;
						if (!BisRobot)
						{
							PlayersCounttmp.push_back(entityAddv);
							pdata.Name = GetPlayerName(entityAddv + GameOffsets::nameOffset);
							std::string sta = Utilities::getState(Driver.ReadVirtualMemory<UINT>(entityAddv + GameOffsets::ofStateInt));
							std::string wep = Utilities::PlayerWeapon(g_Utilities->GetEntityType(gNames, Driver.ReadVirtualMemory<UINT>(Driver.ReadVirtualMemory<UINT>(entityAddv + GameOffsets::WeaponOffset) + 16)));
							if (sta == "")
								sta = "UNKO";
							pdata.stateInt = sta;

							if (wep == "")
								wep = "Fist";
							pdata.weapon = wep;
						}
						else
						{
							std::string sta = Utilities::getState(Driver.ReadVirtualMemory<UINT>(entityAddv + GameOffsets::ofStateInt));
							if (sta == "")
								sta = "UNKO";
							pdata.stateInt = sta;
							pdata.Name = "BOT";
							BotsCounttmp.push_back(entityAddv);
						}

						PlayertmpData.push_back(pdata);
						continue;
					}
					else {

						if (g_Settings::GrenadeAlert && entityType.find("BP_") != std::string::npos)
						{

							alert = g_Utilities->GetGrenadeType(entityType);

							if (!alert.empty())
							{
								tempb.displayName = alert;
								tempb.Position = Driver.ReadVirtualMemory<Vector3>(Driver.ReadVirtualMemory<UINT>(entityAddv + GameOffsets::RootComponentOffset) + GameOffsets::positionOffset);
								GrenadeAlertDataTmp.push_back(tempb);
								continue;
							}
						}

						if (g_Settings::vehicleEsp)
						{

							vehicle = g_Utilities->GetVehicleType(entityType);

							if (!vehicle.empty())
							{
								vhi.Address = entityAddv;
								vhi.displayName = vehicle;
								vhi.Position = Driver.ReadVirtualMemory<Vector3>(Driver.ReadVirtualMemory<UINT>(entityAddv + GameOffsets::RootComponentOffset) + GameOffsets::positionOffset);
								vhi.driving = Driver.ReadVirtualMemory<DWORD>(entityAddv + 0x681); // bool bIsEngineStarted;//(ByteOffset:
								auto VehicleCommon = Driver.ReadMemoryEx<DWORD>(entityAddv + GameOffsets::VehicleCommonOffset);
								/*vhi.CurrHealth = Driver.ReadMemoryEx<float>(VehicleCommon + GameOffsets::HPOffset) * 100 / Driver.ReadVirtualMemory<float>(VehicleCommon + GameOffsets::HPMaxOffset);
								vhi.CurrFuel = Driver.ReadMemoryEx<float>(VehicleCommon + GameOffsets::FuelOffset) * 100 / Driver.ReadVirtualMemory<float>(VehicleCommon + GameOffsets::FuelMaxOffset);
								if (vhi.CurrHealth == 0.0f)
									continue;
								vhi.CurrHealth = NormalizeHealth(vhi.CurrHealth);
								vhi.CurrFuel = NormalizeHealth(vhi.CurrFuel);*/

								float HP = Driver.ReadMemoryEx<float>(VehicleCommon + GameOffsets::HPOffset);
								float HPMax = Driver.ReadMemoryEx<float>(VehicleCommon + GameOffsets::HPMaxOffset);
							
								vhi.CurrHealth = (int)(HP * 100 / HPMax);
								
								float Fuel = Driver.ReadMemoryEx<float>(VehicleCommon + GameOffsets::FuelOffset);
								float FuelMax = Driver.ReadMemoryEx<float>(VehicleCommon + GameOffsets::FuelMaxOffset);

								vhi.CurrFuel = (int)(Fuel * 100 / FuelMax);

								


								VehicleTmpData.push_back(vhi);
								continue;
							}
						}
						if (g_Settings::LootBoxItems)
						{
							std::string IsBoxI = Utilities::IsBox(entityType);
							if (IsBoxI != "")
							{

								Itemb temo;
								temo.Displayname = IsBoxI;
								temo.ItemColor = ImColor(255, 255, 255, 230);
								lbox.boxitem.clear();
								lbox.boxitem.push_back(temo);
								if (g_Settings::ShowItems)
								{
									auto boxItemsCount = Driver.ReadVirtualMemory<int>(entityAddv + GameOffsets::PickUpItemDataOffset + GameOffsets::TypeSpecificIDOffset);
									if (boxItemsCount > 15)
										boxItemsCount = 15;
									UINT itemBase = Driver.ReadVirtualMemory<UINT>(entityAddv + GameOffsets::PickUpItemDataOffset-0x03);
									long itemAddv, ammoCount;

									for (int count = 0; count < boxItemsCount; count++)
									{
										itemAddv = itemBase + count * 48;
										auto boxentitystruct = Driver.ReadVirtualMemory<int>(itemAddv + 0x4);
										if (boxentitystruct >= 101001 && boxentitystruct <= 602004)
										{
											Itemb boxItem = g_Utilities->GetItemWTCode(boxentitystruct);
											if (boxItem.Displayname.empty())
												continue;
											ammoCount = Driver.ReadVirtualMemory<int>(itemAddv + 0x18);
											if (ammoCount > 1)
											{
												boxItem.Displayname.append(" * ").append(std::to_string(ammoCount));
											}
											temo.Displayname = boxItem.Displayname;
											temo.ItemColor = boxItem.ItemColor;
											lbox.boxitem.push_back(temo);
										}
										continue;

									}

									if (lbox.boxitem.size() <= 0)
										continue;
								}

								lbox.Position = Driver.ReadVirtualMemory<Vector3>(Driver.ReadVirtualMemory<UINT>(entityAddv + GameOffsets::RootComponentOffset) + GameOffsets::positionOffset);
								LootBoxTmpData.push_back(lbox);
								continue;

							}
						}
					}
				}else if (IsEntityItem >= 101001 && IsEntityItem <= 602004)
				{
					if (g_Settings::ShowItems)
					
					{
						auto imptm = g_Utilities->GetItemWTCode(IsEntityItem);
						if (!imptm.Displayname.empty())
						{
							itm.displayName = imptm.Displayname;
							itm.ItemColor = imptm.ItemColor;

							itm.Position = Driver.ReadVirtualMemory<Vector3>(Driver.ReadVirtualMemory<UINT>(entityAddv + GameOffsets::RootComponentOffset) + GameOffsets::positionOffset);
							ItemTmpData.push_back(itm);
							continue;
						}
					}
					continue;
				}
				continue;

				}

				PlayersCount = PlayersCounttmp;
				BotsCount = BotsCounttmp;
				PlayersCounttmp.clear();
				BotsCounttmp.clear();
				PlayerData = PlayertmpData;
				ItemData = ItemTmpData;
				VehicleData = VehicleTmpData;
				LootBoxData = LootBoxTmpData;
				GrenadeAlertData = GrenadeAlertDataTmp;
			}

		}
		else
		{

			if (!ProcManager::ProcessExist(ProcessId))
			{
				exit(1);
				ExitProcess(1);
			}
			Sleep(2000);
		}

	}
	catch (...) {
	}
}
float BackupInstantValue = 0;
void MainForm::UpdateKeys()
{

#pragma region NoRecoil

	if (g_Settings::EnableNoRecoil && CurrentWeapon != 0 && ShootWeaponEntity != 0)
	{
		try
		{
			float RecoilWriteVal = 0.0f;

			if (GetAsyncKeyState(MK_LBUTTON))
			{
				float VRFactor = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AVRecoilFactorOffset);

				if (VRFactor != RecoilWriteVal)
				{
					DefaultRecoilInfo[0] = VRFactor;
					Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AVRecoilFactorOffset, RecoilWriteVal);
				}

				float HRFactor = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AHRecoilFactorOffset);
				if (HRFactor != RecoilWriteVal)
				{
					DefaultRecoilInfo[1] = HRFactor;
					Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AHRecoilFactorOffset, RecoilWriteVal);
				}


				float RFactor = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::ARecoveryFactorOffset);
				if (RFactor != RecoilWriteVal)
				{
					DefaultRecoilInfo[2] = RFactor;
					Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::ARecoveryFactorOffset, RecoilWriteVal);
				}
				RecoilStarted = true;
			}
			else
			{
				if (RecoilStarted)
				{
					if (DefaultRecoilInfo[0] != 0.0f)
					{
						float VRFactor = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AVRecoilFactorOffset);
						if (VRFactor != DefaultRecoilInfo[0])
						{
							Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AVRecoilFactorOffset, DefaultRecoilInfo[0]);
							DefaultRecoilInfo[0] = 0.0f;
						}

					}


					if (DefaultRecoilInfo[1] != 0.0f)
					{
						float HRFactor = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AHRecoilFactorOffset);
						if (HRFactor != DefaultRecoilInfo[1])
						{
							Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AHRecoilFactorOffset, DefaultRecoilInfo[1]);
							DefaultRecoilInfo[1] = 0.0f;
						}

					}

					if (DefaultRecoilInfo[2] != 0.0f)
					{
						float RFactor = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::ARecoveryFactorOffset);
						if (RFactor != DefaultRecoilInfo[2])
						{
							Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::ARecoveryFactorOffset, DefaultRecoilInfo[2]);
							DefaultRecoilInfo[2] = 0.0f;
						}

					}
					RecoilStarted = false;
				}
			}

		}
		catch (const std::exception&)
		{

		}
	}
	else {
		if (RecoilStarted)
		{
			if (DefaultRecoilInfo[0] != 0.0f)
			{
				float VRFactor = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AVRecoilFactorOffset);
				if (VRFactor != DefaultRecoilInfo[0])
				{
					Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AVRecoilFactorOffset, DefaultRecoilInfo[0]);
					DefaultRecoilInfo[0] = 0.0f;
				}

			}


			if (DefaultRecoilInfo[1] != 0.0f)
			{
				float HRFactor = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AHRecoilFactorOffset);
				if (HRFactor != DefaultRecoilInfo[1])
				{
					Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::AHRecoilFactorOffset, DefaultRecoilInfo[1]);
					DefaultRecoilInfo[1] = 0.0f;
				}

			}

			if (DefaultRecoilInfo[2] != 0.0f)
			{
				float RFactor = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::ARecoveryFactorOffset);
				if (RFactor != DefaultRecoilInfo[2])
				{
					Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::ARecoveryFactorOffset, DefaultRecoilInfo[2]);
					DefaultRecoilInfo[2] = 0.0f;
				}

			}
			RecoilStarted = false;
		}
			
	}
#pragma endregion

#pragma region InstantHit
	if (g_Settings::EnableInstantHit && CurrentWeapon != 0 && ShootWeaponEntity != 0 && !g_Settings::ShowMenu)
	{
		float BulletSpeedr = 0.0f;
		if (GetAsyncKeyState(MK_LBUTTON))
		{
			float changeval = 770000.0f ;
			BulletSpeedr = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::BulletFireSpeedOffset);
			if (BulletSpeedr != changeval && BulletSpeedr != 0)
			{
				BackupInstantValue = BulletSpeedr;
				Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::BulletFireSpeedOffset, changeval);
				g_Settings::instantstarted = true;
			}
		}
		else
		{
			if (g_Settings::instantstarted)
			{
				BulletSpeedr = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::BulletFireSpeedOffset);

				if (BulletSpeedr != 0 && BulletSpeedr != BackupInstantValue)
				{
					Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::BulletFireSpeedOffset, BackupInstantValue);
					
				}
				g_Settings::instantstarted = false;
			}

		}


	}
	else 
	{
		float BulletSpeedr = 0.0f;
		if (g_Settings::instantstarted)
		{
			BulletSpeedr = Driver.ReadVirtualMemory<float>(ShootWeaponEntity + GameOffsets::BulletFireSpeedOffset);

			if (BulletSpeedr != 0 && BulletSpeedr != BackupInstantValue)
			{
				Driver.WriteVirtualMemory<float>(ShootWeaponEntity + GameOffsets::BulletFireSpeedOffset, BackupInstantValue);

			}
			g_Settings::instantstarted = false;
		}
		
	}
#pragma endregion

#pragma region Fast Run

	if (g_Settings::FastRun)
	{

			if (GetAsyncKeyState(VK_LSHIFT))
			{
				float write = 6.0f;
				Driver.WriteVirtualMemory<float>(MainForm::LocalPawn + GameOffsets::CharacterOverrideAttrs, write); //CharacterOverrideAttrs CharacterOverrideAttrs;//[Offset:
			}
			else if (GetAsyncKeyState(VK_LSHIFT) == 0)
			{
				float write = 1.0f;
				Driver.WriteVirtualMemory<float>(MainForm::LocalPawn + GameOffsets::CharacterOverrideAttrs, write);

			}

	}
#pragma endregion

}

int getue4header()
{
	int libue4header = 0;
	BYTE ue4head[] = { 0x7F, 0x45, 0x4C, 0x46, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x28, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x24, 0x06, 0x80, 0x07, 0x00, 0x02, 0x00, 0x05, 0x34, 0x00, 0x20, 0x00, 0x0A, 0x00, 0x28, 0x00, 0x1A, 0x00, 0x19, 0x00, 0x06, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x74, 0x01, 0x00, 0x00, 0x74, 0x01, 0x00, 0x00 };
	libue4header = Driver.SINGLEAOBSCAN(ue4head, sizeof(ue4head));
	return libue4header;
}



#pragma region Loofy
void MainForm::loofy()
{
	
	if (g_Settings::loofy)
	{
		BYTE Scan[] = { 0x95, 0x2D, 0xBC, 0x41, 0x00, 0x80, 0x6F, 0x39, 0x00, 0x90, 0xC7, 0x3B, 0x01, 0x00, 0x00, 0x27 };
		BYTE Replace[] = { 0x00, 0x00, 0xC8, 0x42, 0x00, 0x00, 0x48, 0x43, 0x00, 0x90, 0xC7, 0x3B, 0x01, 0x00, 0x00, 0x27 };
		Driver.AOBREP(Scan, Replace, sizeof(Scan), sizeof(Replace), 5000);
		g_Settings::loofyOn = true;
	}
	else if (!g_Settings::loofy)
	{
		BYTE Scan[] = { 0x00, 0x00, 0xC8, 0x42, 0x00, 0x00, 0x48, 0x43, 0x00, 0x90, 0xC7, 0x3B, 0x01, 0x00, 0x00, 0x27 };
		BYTE Replace[] = { 0x95, 0x2D, 0xBC, 0x41, 0x00, 0x80, 0x6F, 0x39, 0x00, 0x90, 0xC7, 0x3B, 0x01, 0x00, 0x00, 0x27 };
		Driver.AOBREP(Scan, Replace, sizeof(Scan), sizeof(Replace), 5000);
		g_Settings::loofyOn = false;
	}

	/*if (g_Settings::loofy)
	{
		BYTE Scan[] = { 0x00, 0x00, 0xB4, 0x43, 0x78, 0x17, 0x9C, 0x03, 0x84, 0xAE, 0x7E, 0x03, 0x30, 0x48 };
		BYTE Replace[] = { 0x00, 0x00, 0x82, 0x43, 0x78, 0x17, 0x9C, 0x03, 0x84, 0xAE, 0x7E, 0x03, 0x30, 0x48 };
		Driver.AOBREP(Scan, Replace, sizeof(Scan), sizeof(Replace), 5000);
		g_Settings::loofyOn = true;
	}
	else if (g_Settings::loofyOn)
	{
		BYTE Scan[] = { 0x00, 0x00, 0x82, 0x43, 0x78, 0x17, 0x9C, 0x03, 0x84, 0xAE, 0x7E, 0x03, 0x30, 0x48 };
		BYTE Replace[] = { 0x00, 0x00, 0xB4, 0x43, 0x78, 0x17, 0x9C, 0x03, 0x84, 0xAE, 0x7E, 0x03, 0x30, 0x48 };
		Driver.AOBREP(Scan, Replace, sizeof(Scan), sizeof(Replace), 5000);
		g_Settings::loofyOn = false;
	}*/



	

}
#pragma endregion




#pragma region God View 

void MainForm::godview()
{
	if (g_Settings::GodView)
	{
		
		int libue4 = getue4header();
		//std::cout << libue4 << std::endl;
			if (GetAsyncKeyState(VK_LSHIFT))
			{
				BYTE jLaynZ[] = { 0x00, 0x00, 0x8C, 0x43 };
				Driver.INJECT(0x3A05C20, jLaynZ, sizeof(jLaynZ), libue4);
			
				/*BYTE writes[] = { 0x00, 0x00, 0x82, 0x43, 0x28, 0x54, 0x72, 0x03, 0x94, 0xF9, 0x54, 0x03, 0x30, 0x48 };
				Driver.INJECT(0x3DB3C60, writes, sizeof(writes), libue4);*/
				
				
			}
			else if (GetAsyncKeyState(VK_LSHIFT) == 0)
			{
				BYTE jLaynZ[] = { 0xD5, 0x16, 0x93, 0x41 };
				Driver.INJECT(0x3A05C20, jLaynZ, sizeof(jLaynZ), libue4);
				/*BYTE writes[] = { 00,0x00, 0xB4, 0x43, 0x28, 0x54, 0x72, 0x03, 0x94, 0xF9, 0x54, 0x03, 0x30, 0x48 };
				Driver.INJECT(0x3DB3C60, writes, sizeof(writes), libue4);*/
				

			}

	}
}
#pragma endregion



#pragma region CarFly

bool IsFlyCarInitialized = false;
DWORD FlyCarAddress = 0;

VOID SetFlyCarAddress()
{
	BYTE FlyCarSearch[] = { 0x00, 0x00, 0x75, 0xC4, 0x00, 0x00, 0x7A, 0x45, 0x9A, 0x99 };

	std::vector<UINT> FoundedBase;
	Driver.SearchPattern(FlyCarSearch, sizeof(FlyCarSearch), 0x10000000, 0xA0000000, false, FoundedBase);
	FlyCarAddress = FoundedBase[0];
	//return FoundedBase;
}

void MainForm::carFly()
{

if (g_Settings::carFly)
{

	

		if (IsFlyCarInitialized == false)
		{
			SetFlyCarAddress();

			IsFlyCarInitialized = true;
		}

		if (GetAsyncKeyState(VK_SPACE) & 1)
		{
			Driver.WriteVirtualMemory<float>(FlyCarAddress, 27000.0f);
		}
		else if (GetAsyncKeyState(VK_SPACE) == 0)
		{
			if (Driver.ReadVirtualMemory<float>(FlyCarAddress) != -980.0f)
			{
				Driver.WriteVirtualMemory<float>(FlyCarAddress, -980.0f);
			}
		}

	
}


}
#pragma endregion

#pragma region Speed Car

void MainForm::FastCar() {
	
		if (g_Settings::speedCar)
		{
			if (GetAsyncKeyState(VK_LSHIFT)) {
				/*DWORD gameInstance = Driver.ReadMemoryEx<INT>(UWorlds + 0x24);
				DWORD playerController = Driver.ReadMemoryEx<INT>(gameInstance + 0x60);
				DWORD playerCarry = Driver.ReadMemoryEx<INT>(playerController + 0x20);
				DWORD uMyObject = Driver.ReadMemoryEx<INT>(playerCarry + 0x330);*/
				DWORD num12 = Driver.ReadVirtualMemory<DWORD>(LocalPawn + 0x150L + 0x6f0 + 1776 + 416 + 88);
				//DWORD num12 = Driver.ReadVirtualMemory<DWORD>(Driver.ReadMemoryEx<DWORD>(Driver.ReadMemoryEx<DWORD>(Driver.ReadMemoryEx<DWORD>(Driver.ReadMemoryEx<DWORD>(LocalPawn + 0x150L) + 0x6f0) + 1776) + 416) + 88); //float EnActiveTimeThreshold;//[Offset: 0x6d0,
				Driver.WriteVirtualMemory<float>(num12, 320.0f);
				Driver.WriteVirtualMemory<float>(num12 + 4, 320.0f);
				Driver.WriteVirtualMemory<float>(num12 + 8, 320.0f);
				Driver.WriteVirtualMemory<float>(num12 + 12, 320.0f);
				Driver.WriteVirtualMemory<float>(num12 + 16, 320.0f);
				Driver.WriteVirtualMemory<float>(num12 + 20, 320.0f);
				Driver.WriteVirtualMemory<float>(num12 + 24, 320.0f);
				Driver.WriteVirtualMemory<float>(num12 + 28, 320.0f);
			}
		}
		
}
#pragma endregion
