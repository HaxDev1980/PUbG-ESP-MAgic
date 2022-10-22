#pragma once
#include <vector>
class Rotator {
public:
	float Pitch;
	float Yaw;
	float Roll;
	Rotator(void);
	Rotator(float X, float Y, float Z);
	inline void Zero();
	inline double	Length() const;
	inline Rotator Clamp();
	bool IsZero(float tolerance = 0.01f) const
	{
		return (Pitch > -tolerance && Pitch < tolerance&&
			Yaw > -tolerance && Yaw < tolerance&&
			Roll > -tolerance && Roll < tolerance);
	}
};


inline Rotator::Rotator(float PITCH, float YAW, float ROLL)
{
	Pitch = PITCH; Yaw = YAW; Roll = ROLL;
	//CHECK_VALID(*this);
}
inline Rotator::Rotator(void)
{
}
inline void Rotator::Zero()
{
	Pitch = Yaw = Roll = 0.f;
}
inline double Rotator::Length(void) const
{
	//..CHECK_VALID(*this);

	/*float root = 0.f;

	float sqsr = x * x + y * y + z * z;*/
	return sqrt((Pitch * Pitch) + (Yaw * Yaw) + (Roll * Roll));
	/*__asm
	{
		sqrtss xmm0, sqsr
		movss root, xmm0
	}*/

	//return root;
}
inline Rotator Rotator::Clamp()
{
	auto result = this;

	/*if (result->Pitch > 180)
		result->Pitch = result->Pitch- 360;

	else if (result->Pitch < -180)
		result->Pitch = result->Pitch+ 360;

	if (result->Pitch > 89)
		result->Pitch = 89;

	else if (result->Pitch < -89)
		result->Pitch = -89;

	if (result->Yaw > 180)
		result->Yaw = result->Yaw- 360;

	else if (result->Yaw < -180)
		result->Yaw = result->Yaw+ 360;

	while (result->Yaw < -180.0f)
		result->Yaw = result->Yaw + 360.0f;
	while (result->Yaw > 180.0f)
		result->Yaw = result->Yaw - 360.0f;*/
	
	if (result->Pitch > 180)
		result->Pitch -= 360;

	else if (result->Pitch < -180)
		result->Pitch += 360;

	if (result->Yaw > 180)
		result->Yaw -= 360;

	else if (result->Yaw < -180)
		result->Yaw += 360;

	if (result->Pitch < -89)
		result->Pitch = -89;

	else if (result->Pitch > 89)
		result->Pitch = 89;

	result->Roll = 0;

	return *result;




}
//inline Rotator Rotator::Clamp()
//{
//	auto result = this;
//
//	if (result->Pitch > 180)
//		result->Pitch -= 360;
//
//	else if (result->Pitch < -180)
//		result->Pitch += 360;
//
//	if (result->Yaw > 180)
//		result->Yaw -= 360;
//
//	else if (result->Yaw < -180)
//		result->Yaw += 360;
//
//	if (result->Pitch < -89)
//		result->Pitch = -89;
//
//	if (result->Pitch > 89)
//		result->Pitch = 89;
//
//	while (result->Yaw < -180.0f)
//		result->Yaw += 360.0f;
//
//	while (result->Yaw > 180.0f)
//		result->Yaw -= 360.0f;
//
//	result->Roll = 0;
//
//	return *result;
//
//
//
//
//}