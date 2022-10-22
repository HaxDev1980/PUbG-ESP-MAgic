#pragma once
//#include "../pch.h"
#include <string>
#include <vector>
#include "../Structss/Vector3s.h"
#include "../Structss/Rotator-s.h"
#include <imgui/imgui.h>

extern struct D3DMatrix {
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;
};
extern class Quat {
public:
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;
};

extern struct FTTransform2_t {
	Quat Rotation;
	Vector3 Translation;
	float ddd;
	Vector3 Scale3D;
};

extern struct Item {
	std::string displayName;
	Vector3 Position;
	ImColor ItemColor;
};


extern struct Itemb {
	std::string Displayname;
	ImColor ItemColor;
};