#pragma once
#include "../pch.h"


class ProcManager {
public:
	ProcManager();
	~ProcManager();
	//1: Gameloop-4.4 ,2:Smartgaga //3: Gameloop-7.1
	static int TargetEmulator;
	static int GetRightProcId();
	static std::vector<HWND> GetTargetHWND(std::wstring WindowName, std::wstring ClassName);
	static bool ProcessExist(DWORD Pid);
};

