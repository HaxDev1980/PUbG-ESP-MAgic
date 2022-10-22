#pragma once


#include "KernelHelper.hpp"
#include "../Game Misc/GStructs.h"



class Utilities
{
public :
	Utilities();
	~Utilities();
	KernelHelper Driver;
	
	UINT getViewWorld();
	void ScanBulletTracking(bool Mstat = false);
	std::string GetEntityType(UINT gNames, UINT id);
	static std::string ConvertFromUtf16ToUtf8(const std::wstring& wstr);
	static Itemb GetItemWTCode(int code);
	static std::string GetVehicleType(std::string str);
	static std::string GetGrenadeType(std::string classname);
	static std::string IsBox(std::string classname);
	static int MessageTimeout(LPCWSTR lpText, UINT uType);
	static std::string getState(int state);

	static std::string PlayerWeapon(std::string str);

	static bool WorldToScreen(D3DMatrix viewMatrix, Vector3 pos, Vector3& screen, int* distance, float m_Width, float m_Height);
	static bool WorldToScreenBone(D3DMatrix viewMatrix, Vector3 pos, Vector2& screen, int* distance, float m_Width, float m_Height);
	static bool WorldToScreenPlayer(Vector3 pos, Vector3& screen, int* distance, D3DMatrix viewMatrix, float m_Width, float m_Height);
	static D3DMatrix ToMatrixWithScale(Vector3 translation, Vector3 scale, Quat rot);
	static D3DMatrix MatrixMultiplication(D3DMatrix pM1, D3DMatrix pM2);
	static Vector3 GetBoneWorldPosition(ULONG actorAddv, ULONG boneAddv);
};
extern Utilities* g_Utilities;

extern struct Vehicle {
	DWORD Address;
	DWORD VehicleComm;
	std::string displayName;
	Vector3 Position;
	bool driving;
	float CurrFuel;
	float CurrHealth;
	int MaxHP, MaxFuel;
	int HP, Fuel;

};
struct Lootbox {
	Vector3 Position;
	std::string Items;
	std::vector<Itemb> boxitem;
};

struct playerData
{
	UINT Address, Pose;
	Vector3 Position;
	int Status, TeamID;
	bool IsRobot, IsKnocked;
	std::string  Name, weapon, stateInt;
	float Health;
};