#include "../pch.h"
#include <TlHelp32.h>
#include <Psapi.h>
ProcManager::ProcManager() {}


ProcManager::~ProcManager() {}

int ProcManager::TargetEmulator = 0;
int ProcessType = 0;
int ProcManager::GetRightProcId() {
	int pid = 0;
	int threadCount = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnap, &pe);
	while (Process32Next(hSnap, &pe)) {
		if (_tcsicmp(pe.szExeFile, _T("AndroidEmulator.exe")) == 0)
		{
			TargetEmulator = 1;
		}
		if (_tcsicmp(pe.szExeFile, _T("AndroidEmulatorEn.exe")) == 0)
		{
			TargetEmulator = 3;
		}
		if (_tcsicmp(pe.szExeFile, _T("aow_exe.exe")) == 0) {
			if ((int)pe.cntThreads > threadCount) {
				threadCount = pe.cntThreads;
				pid = pe.th32ProcessID;
				ProcessType = 1;
			}

		}
		if (_tcsicmp(pe.szExeFile, _T("AndroidProcess.exe")) == 0) {
			if ((int)pe.cntThreads > threadCount) {
				threadCount = pe.cntThreads;
				pid = pe.th32ProcessID;
				TargetEmulator = 2;
			}
		}

	}

	return pid;
}
struct TargetFinderParams {
	std::wstring wndClassName = L"";
	std::wstring wndName = L"";
	std::vector<HWND> hwnds;
};

BOOL CALLBACK EnumWindowsCallback(HWND hwnd, LPARAM lParam) {
	TargetFinderParams& params = *(TargetFinderParams*)lParam;

	unsigned char satisfiedCriteria = 0, unSatisfiedCriteria = 0;


	// If looking for windows of a specific class
	wchar_t className[255] = L"";
	GetClassName(hwnd, className, 255);
	std::wstring classNameWstr = className;
	if (params.wndClassName != L"")
	{
		if (params.wndClassName == classNameWstr)
		{

			++satisfiedCriteria; // Not the class targeted
		}
		else {
			++unSatisfiedCriteria;
		}
	}

	// If looking for windows with a specific name
	wchar_t windowName[255] = L"";
	GetWindowText(hwnd, windowName, 255);
	std::wstring windowNameWstr = windowName;
	if (params.wndName == windowNameWstr || L"TXMenuWindow" == windowNameWstr)
	{

		++unSatisfiedCriteria;
	}
	else
	{

		++satisfiedCriteria; // Not the class targeted
	}



	if (!satisfiedCriteria)
		return TRUE;

	if (unSatisfiedCriteria)
		return TRUE;

	// If looking for multiple windows
	params.hwnds.push_back(hwnd);
	return TRUE;
}
std::vector<HWND> TargetFinder(TargetFinderParams params) {
	EnumWindows(EnumWindowsCallback, (LPARAM)&params);
	return params.hwnds;
}
std::vector<HWND> ProcManager::GetTargetHWND(std::wstring WindowName, std::wstring ClassName)
{
	std::vector<HWND> WindowList = {};
	HWND current_hwnd = NULL;
	TargetFinderParams params;
	params.wndClassName = ClassName;
	params.wndName = WindowName;
	std::vector<HWND> hwnds = TargetFinder(params);
	//for (int i(0); i < hwnds.size(); ++i) {
	//	DWORD pid = 0;
	//	DWORD tid = GetWindowThreadProcessId(hwnds[i], &pid);
	//	std::cout << "Window #" << i + 1 << " found: HWND 0x" << std::hex << (int)hwnds[i] << " | Thread: " << std::dec << tid << " | PID: " << pid << std::endl;
	//	
	//}
	//WindowList.push_back(current_hwnd);
	return hwnds;
}
bool ProcManager::ProcessExist(DWORD Pid)
{
	try
	{
		DWORD aProcesses[1024], cbNeeded, cProcesses;
		if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
			return NULL;

		cProcesses = cbNeeded / sizeof(DWORD);
		for (unsigned int i = 0; i < cProcesses; i++)
		{
			DWORD dwProcessID = aProcesses[i];
			if (Pid == dwProcessID)
			{
				return true;
			}
		}
		return false;
	}
	catch (const std::exception&)
	{
		return false;
	}

}
