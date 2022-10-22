#pragma once
/* STL */

#include <Windows.h>
#include <TlHelp32.h>
#include <Dwmapi.h> 
#include <iostream>
#include <string>
#include <sstream> 
#include<vector>

#include "../pch.h"
/* DirectX */
#include <d3d9.h>
#include <d3dx9.h>
/* Imgui */
#include <imgui/imgui_impl_dx9.h>
#include <imgui/imgui_impl_win32.h>

namespace Overlay
{
	class Overlay
	{
		
	private:
	
		struct SD3DVertex {
			float x, y, z, rhw;
			DWORD colour;
		};

	

	public:
		Overlay();
		~Overlay();
		bool InitiateD3D(unsigned int X, unsigned int Y);
		bool OverlayWndCreator();
		void StartRender(HWND targetWindowsHwnd, HWND TargetMainWindow);
		void DrawPlayerBone(UINT bodyAddv, UINT boneAddv, Vector3 screen);
		void DrawString(int x, int y, DWORD color, LPD3DXFONT font, std::wstring str, ...);
		void DrawBone(Vector2 vec1, Vector2 vec2);
		void ClearScreen();
		void Shutdown();
		void CleanupDeviceD3D();
		void SetRenderStates();

	};
	
}