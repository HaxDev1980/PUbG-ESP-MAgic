#include "AimForm.h"
#define M_PI 3.14159265358979323846

AimForm* g_AimForm = new AimForm();

AimForm::AimForm() {}
AimForm::~AimForm() {}

playerData targetEnemy;
Vector2 AimForm::TargetBoneReq;

bool MagicReStat = false;
#pragma region Aim Method


bool bareEqual(byte cmp1[], byte cmp2[],int Size)
{
	
	try {
		for (int i = 0; i < Size; i++)
		{
			if (cmp1[i] != cmp2[i])
			{
				return false;
			}
			
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}



static Rotator CalcAngle(Vector3 local, Vector3 target)
{
	
	Vector3 rotation = local - target;
	Rotator ViewAngle = Rotator();
	Rotator hekk;

	float hyp = (float)sqrt(rotation.x * rotation.x + rotation.y * rotation.y);
	ViewAngle.Pitch = -atan(rotation.z / hyp) * 180.0f / M_PI;
	ViewAngle.Yaw = atan(rotation.y / rotation.x) * 180.0f / M_PI;
	ViewAngle.Roll = 0.0f;

	if (rotation.x >= 0.0f)
		ViewAngle.Yaw += 180.0f;

	return ViewAngle.Clamp();
};


static void RestoreMagic(bool Status) {
	if (Status)
	{
		if (g_Settings::MagicBulletHook != NULL)
		{
			//Close CMP GATE
			g_Utilities->Driver.WriteVirtualMemory<int>(g_Settings::MagicBulletHook + 106, 0);
		}
	}
	else
	{
		MagicReStat = false;
		if (g_Settings::MagicData[0] != 0 && g_Settings::MagicBulletHook != NULL)
		{
			for (auto addv : g_Settings::MagicBulletList) {
				if (g_Utilities->Driver.ReadVirtualMemory<byte>(addv + 8) == 232)
				{
					g_Utilities->Driver.WriteBytes(addv + 8, g_Settings::MagicData, 7);
				}

			}

		}
	}
}

static bool VerifyAddress(UINT adresss)
{
	if (ProcManager::TargetEmulator == 1)
	{
		if (g_Utilities->Driver.ReadVirtualMemory<int>(adresss - 4) != 168)
		{
			return false;
		}
	}
	else
	{
		if (g_Utilities->Driver.ReadVirtualMemory<byte>(adresss) != 0x66)
		{
			return false;
		}
	}
	return true;
}

static void RefreshTracking()
{
	RestoreMagic(false);
	g_Utilities->ScanBulletTracking(false);
}

static void InitMagic() {
	if (!g_Settings::MagicSearching) {

		if (g_Settings::MagicBulletList.size() > 0)
		{

			for (auto saddv : g_Settings::MagicBulletList)
			{
				if (!VerifyAddress(saddv))
				{
					RefreshTracking();
					return;
				}
			}

			long addv = g_Settings::MagicBulletList[0];
			if (g_Settings::MagicAllocateMem == 0)
			{
				long magicAddv = g_Utilities->Driver.AllocateMemory(500);
				if (magicAddv == 0)
				{
					g_Settings::MagicError = true;
					g_Settings::MagicInitialized = false;
					g_Settings::MagicInitializing = false;
					return;
				}
				g_Settings::MagicAllocateMem = magicAddv;
			}
			

			if(g_Settings::GlobalSelected&& !g_Settings::BgmiSelected)
			{
				g_Settings::magicByte2[11] = GameOffsets::GlXAxis;
				g_Settings::magicByte3[5] = GameOffsets::GlYAxis;
			}
			else if (g_Settings::BgmiSelected && !g_Settings::GlobalSelected)
			{
				g_Settings::magicByte2[11] = GameOffsets::BGXAxis;
				g_Settings::magicByte3[5] = GameOffsets::BGYAxis;
			}else
			{
				g_Settings::MagicError = true;
				g_Settings::MagicInitialized = false;
				g_Settings::MagicInitializing = false;
				return;
			}
			g_Settings::magicByte2[4] = ProcManager::TargetEmulator == 1 ? 0x40 : 0x50;
			g_Settings::magicByte3[10] = 0x30;//Need Update According to Pattern
			g_Settings::magicByte4[5] = 0x34;//Need Update According to Pattern

			g_Utilities->Driver.WriteBytes(g_Settings::MagicAllocateMem, g_Settings::magicByte1, 15);
			g_Utilities->Driver.WriteBytes(g_Settings::MagicAllocateMem + 15, g_Settings::magicByte2, 15);
			g_Utilities->Driver.WriteBytes(g_Settings::MagicAllocateMem + 30, g_Settings::magicByte3, 15);
			g_Utilities->Driver.WriteBytes(g_Settings::MagicAllocateMem + 45, g_Settings::magicByte4, 15);


			g_Utilities->Driver.ReadBytes(addv + 8, *g_Settings::MagicData, 7);
			g_Utilities->Driver.WriteBytes(g_Settings::MagicAllocateMem, g_Settings::MagicData, 7);
			g_Utilities->Driver.WriteVirtualMemory<int>(g_Settings::MagicAllocateMem + 9, g_Settings::MagicAllocateMem + 106);
			
			g_Settings::MagicBulletHook = g_Settings::MagicAllocateMem;

		}
		else {
			g_Settings::MagicError = true;
			g_Settings::MagicInitialized = false;
			g_Settings::MagicInitializing = false;
		}
	}
}

static void HookAddress(uintptr_t Address, uintptr_t HookAdress)
{

	if (Address != 0 && HookAdress != 0)
	{
		unsigned char Shell[7] = { 0xE8,0x00,0x00,0x00,0x00,0x00,0x00 };
		*(uintptr_t*)(Shell + 1) = (uintptr_t)HookAdress - Address - 5;
		*(uintptr_t*)(Shell + 5) = 144;
		*(uintptr_t*)(Shell + 6) = 144;
		g_Utilities->Driver.WriteBytes(Address, Shell, 7);
	}
}

static bool HookBulletTrack(float PosX, float PosY) {

	if (g_Settings::MagicSearching) {
		return false;
	}
	if(g_Settings::MagicBulletList.empty())
	{
		RefreshTracking();
		return false;
	}
	if (g_Settings::MagicBulletList.size() > 0)
	{
	
		if (g_Settings::MagicData[0] != 0 && g_Settings::MagicBulletHook != NULL)
		{
			for (auto addv : g_Settings::MagicBulletList) {
				if (!VerifyAddress(addv))
				{
				//	std::cout << "HookVerifyAddress\n";
					RefreshTracking();
					return false;
				}
				byte tmp[7];
				g_Utilities->Driver.ReadBytes(addv+8, *tmp, 7);

				if (bareEqual(tmp, g_Settings::MagicData, 7))
				{
					HookAddress(addv + 8, g_Settings::MagicBulletHook);
				}
				else if (g_Utilities->Driver.ReadVirtualMemory<byte>(addv + 8) != 0xE8)
				{
				//	std::cout << "addv 0xE8\n";
					RefreshTracking();
					return false;
				}
			}
			MagicReStat = true;
			g_Utilities->Driver.WriteVirtualMemory<int>(g_Settings::MagicBulletHook + 106, 1);
			g_Utilities->Driver.WriteVirtualMemory<float>(g_Settings::MagicBulletHook + 44, PosX);
			g_Utilities->Driver.WriteVirtualMemory<float>(g_Settings::MagicBulletHook + 54, PosY);
			return true;
		}
		else {
			//std::cout << "hook else\n";
			InitMagic();
			return false;
		}

	}
	else
	{
		RefreshTracking();
		return false;
	}
	return false;
}




#pragma endregion

#pragma region Prediction
Vector3 GetPlayerVelocity(UINT address)
{
	Vector3 pVelocity = Vector3(0, 0, 0);
	auto curVehicle = g_Utilities->Driver.ReadVirtualMemory<UINT>(address + GameOffsets::CurrentVehicleOffset);
	if (curVehicle == 0)
	{

		pVelocity = g_Utilities->Driver.ReadVirtualMemory<Vector3>(g_Utilities->Driver.ReadVirtualMemory<UINT>(address + GameOffsets::STCharacterMovementOffset) + GameOffsets::LastUpdateVelocityOffset);

	}
	else
	{
		pVelocity = g_Utilities->Driver.ReadVirtualMemory<Vector3>(address + GameOffsets::RepMovement);

	}
	return pVelocity;
}

Vector3 PredictAimX(Vector3 vecLocalPlayer, Vector3 vecTargetPlayer, UINT shootOffset) {
	Vector3 TargetVelocity = GetPlayerVelocity(targetEnemy.Address);
	Vector3 MyVelocity = GetPlayerVelocity(g_MainForm->LocalPawn);
	float BulletVelocity =  g_Utilities->Driver.ReadVirtualMemory<float>(shootOffset + GameOffsets::BulletFireSpeedOffset) / 100;
	float Distance = (vecTargetPlayer - vecLocalPlayer).Length() / 100;

	float timeToTravel = Distance / BulletVelocity;
	Vector3 FinalVelocity = TargetVelocity - MyVelocity;
	vecTargetPlayer += FinalVelocity * timeToTravel;
	vecTargetPlayer.z += 0.5f * 9.81f * timeToTravel * timeToTravel;

	//D = Vi * t + .5 * a * t *t

	return vecTargetPlayer;
}

Vector3 GetClosestEnemy()
{
	Vector3 target = Vector3(0, 0, 0);
	Vector2 lasttarget;
	Vector3 headPos3 = Vector3(0.0f, 0.0f, 0.0f);
	Vector2 headPos2 = Vector2();
	int distance = 0;
	double dist = 100000000.0f;
	double newDist = 100000001.0f;
	for (auto player : g_MainForm->PlayerData)
	{
		if (g_Settings::SkipKnock && player.IsKnocked)
		{
			//Skip Knock
			continue;
		}

		auto tmpAddv = g_Utilities->Driver.ReadVirtualMemory<UINT>(player.Address + GameOffsets::Meshoffset);
		auto bodyAddv = tmpAddv + GameOffsets::bodyoffset;
		auto boneAddv = g_Utilities->Driver.ReadVirtualMemory<UINT>(tmpAddv + GameOffsets::MinLODoffset) + 48;
		if (g_Settings::iAimBone == 0)
		{

			headPos3 = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->Head * 48);//--Head
			headPos3.z = headPos3.z + 13;//--Adjust Head Pos
		}
		else if (g_Settings::iAimBone == 1)
		{
			headPos3 = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->Chest * 48);//--Body
			headPos3.z = headPos3.z - 5;//--Adjust chest Pos
		}
		else if (g_Settings::iAimBone == 2)
		{
			headPos3 = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->Pelvis * 48);//--Pelvis
			headPos3.z = headPos3.z - 5;//--Adjust chest Pos
		}
		if (g_Utilities->WorldToScreenBone(g_MainForm->ViewMatrix, headPos3, headPos2, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
		{
			if (g_Settings::iAimSelection == 0)
			{
				newDist = sqrt(pow(headPos2.x - g_AimForm->WndSight.x, 2) + pow(headPos2.y - g_AimForm->WndSight.y, 2));
			}
			else
			{
				newDist = distance;
			}

			if (newDist < dist)
			{
				target = headPos3;
				lasttarget = headPos2;
				targetEnemy = player;
				dist = newDist;


			}
		}


	}

	g_AimForm->TargetBoneReq = lasttarget;
	return target;
}
#pragma endregion


void AimForm::UpdateAim()
{
	
#pragma region Bullet Track

	if (g_Settings::EnableBulletTrack)
	{

			//Bullet Track
			/*if (GetAsyncKeyState(0x52))
			{
				RestoreMagic(false);
			}*/

			if (g_MainForm->gameInstance != 0 && !g_Settings::ShowMenu)
			{
				if (GetAsyncKeyState(0x52))//VK_F10
				{
					//ReFresh Magic
					RestoreMagic(false);
					g_Utilities->ScanBulletTracking(true);
					return;
				}
				if (g_MainForm->PlayerData.size() > 0)
				{
					auto Shootweapon = g_MainForm->ShootWeaponEntity;
					auto CurrWeapon = g_MainForm->CurrentWeapon;
					if (CurrWeapon != 0 && Shootweapon != 0)
					{
							auto STPlayerController = g_Utilities->Driver.ReadVirtualMemory<UINT>(g_MainForm->LocalPawn + GameOffsets::STExtraPlayerControllerOffset);//-- STPlayerController
						if (STPlayerController == 0)
						{
							g_AimForm->TargetBoneReq.x = 0;
							g_AimForm->TargetBoneReq.y = 0;
							Sleep(100);
							return;
						}

						auto PlayerCameraManager = g_Utilities->Driver.ReadVirtualMemory<UINT>(STPlayerController + GameOffsets::PlayerCameraManagerOffset);
						if (PlayerCameraManager == 0)
						{
							g_AimForm->TargetBoneReq.x = 0;
							g_AimForm->TargetBoneReq.y = 0;
							Sleep(100);
							return;
						}
						Vector3 vecLocalPlayer;
						auto WeaponRootcomp = g_Utilities->Driver.ReadVirtualMemory<UINT>(CurrWeapon + GameOffsets::RootComponentOffset);
						vecLocalPlayer = g_Utilities->Driver.ReadVirtualMemory<Vector3>(WeaponRootcomp + GameOffsets::positionOffset);

						Vector3 vecTargetPlayer = GetClosestEnemy();

						float Pdist = (vecTargetPlayer - vecLocalPlayer).Length() / 100;
						if (vecTargetPlayer.x != 0.0f && vecTargetPlayer.y != 0.0f)
						{

							Vector3 TargetPlayer = PredictAimX(vecLocalPlayer, vecTargetPlayer, Shootweapon);

							if (GetAsyncKeyState(VK_LBUTTON))
							{
								Rotator MagicRotation = CalcAngle(vecLocalPlayer, TargetPlayer);
								if (!HookBulletTrack(MagicRotation.Pitch, MagicRotation.Yaw))
								{
									g_Settings::MagicInitialized = false;
									g_Settings::MagicInitializing = true;

								}
								else
								{
									g_Settings::MagicError = false;
									g_Settings::BulletTrackTurned = true;
									g_Settings::MagicInitialized = true;
									g_Settings::MagicInitializing = false;
								}
							}
							else
							{
								RestoreMagic(true);
							}

						}



					}
					else
					{
						g_AimForm->TargetBoneReq.x = 0;
						g_AimForm->TargetBoneReq.y = 0;
					}
				}
				else
				{
					if (MagicReStat)
					{
						RestoreMagic(false);
					}
					g_AimForm->TargetBoneReq.x = 0;
					g_AimForm->TargetBoneReq.y = 0;
					std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				}


			}
			else
			{
				if (MagicReStat)
				{
					RestoreMagic(false);
				}
				g_AimForm->TargetBoneReq.x = 0;
				g_AimForm->TargetBoneReq.y = 0;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));

			}

		
	}
	else
	{
		if (g_Settings::BulletTrackTurned)
			{
				RestoreMagic(false);
				g_Settings::BulletTrackTurned = false;

			}
		
	}

#pragma endregion



}
