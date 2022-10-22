#pragma once
#include "../pch.h"
//#include <render/Overlay.hpp>
class AimForm
{
public:
	AimForm();
	~AimForm();
	
	float g_Height = 0, g_Width = 0;

	Vector2 WndSight;
	void UpdateAim();
	void UpdateCarTrackAim();

	static Vector2 TargetBoneReq;
	static Vector3 TargetVehiclePos;
};
extern AimForm* g_AimForm;
