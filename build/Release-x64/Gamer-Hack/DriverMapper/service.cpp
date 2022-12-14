#include "service.hpp"
#include "../Authy/Swifty_hor.hpp"

bool service::RegisterAndStart(const std::string& driver_path)
{
	const static DWORD ServiceTypeKernel = 1;
	const std::string driver_name = std::filesystem::path(driver_path).filename().string();
	const std::string servicesPath = c_xor("SYSTEM\\CurrentControlSet\\Services\\") + driver_name;
	const std::string nPath = c_xor("\\??\\") + driver_path;

	HKEY dservice;
	LSTATUS status = RegCreateKey(HKEY_LOCAL_MACHINE, servicesPath.c_str(), &dservice); //Returns Ok if already exists
	if (status != ERROR_SUCCESS)
	{
		//--sup--printf("[-] Can't create service key\n");
		return false;
	}

	status = RegSetKeyValue(dservice, NULL, c_xor("ImagePath"), REG_EXPAND_SZ, nPath.c_str(), (DWORD)nPath.size());
	if (status != ERROR_SUCCESS)
	{
		RegCloseKey(dservice);
		//--sup--printf("[-] Can't create 'ImagePath' registry value\n");
		return false;
	}

	status = RegSetKeyValue(dservice, NULL, c_xor("Type"), REG_DWORD, &ServiceTypeKernel, sizeof(DWORD));
	if (status != ERROR_SUCCESS)
	{
		RegCloseKey(dservice);
		//--sup--printf("[-] Can't create 'Type' registry value\n");
		return false;
	}

	RegCloseKey(dservice);

	HMODULE ntdll = GetModuleHandle(c_xor("ntdll.dll"));
	if (ntdll == NULL) {
		return false;
	}

	auto RtlAdjustPrivilege = (nt::RtlAdjustPrivilege)GetProcAddress(ntdll, c_xor("RtlAdjustPrivilege"));
	auto NtLoadDriver = (nt::NtLoadDriver)GetProcAddress(ntdll, c_xor("NtLoadDriver"));

	ULONG SE_LOAD_DRIVER_PRIVILEGE = 10UL;
	BOOLEAN SeLoadDriverWasEnabled;
	NTSTATUS Status = RtlAdjustPrivilege(SE_LOAD_DRIVER_PRIVILEGE, TRUE, FALSE, &SeLoadDriverWasEnabled);
	if (!NT_SUCCESS(Status))
	{
		//--sup--printf("Fatal error: failed to acquire SE_LOAD_DRIVER_PRIVILEGE. Make sure you are running as administrator.\n");
		return false;
	}

	std::wstring wdriver_name(driver_name.begin(), driver_name.end());
	wdriver_name = L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\" + wdriver_name;
	UNICODE_STRING serviceStr;
	RtlInitUnicodeString(&serviceStr, wdriver_name.c_str());

	Status = NtLoadDriver(&serviceStr);
	//--sup--printf("[+] NtLoadDriver Status 0x%lx\n", Status);
	return NT_SUCCESS(Status);
}

bool service::StopAndRemove(const std::string& driver_name)
{
	HMODULE ntdll = GetModuleHandleA(c_xor("ntdll.dll"));
	if (ntdll == NULL)
		return false;

	std::wstring wdriver_name(driver_name.begin(), driver_name.end());
	wdriver_name = L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\" + wdriver_name;
	UNICODE_STRING serviceStr;
	RtlInitUnicodeString(&serviceStr, wdriver_name.c_str());

	HKEY driver_service;
	std::string servicesPath = c_xor("SYSTEM\\CurrentControlSet\\Services\\") + driver_name;
	LSTATUS status = RegOpenKey(HKEY_LOCAL_MACHINE, servicesPath.c_str(), &driver_service);
	if (status != ERROR_SUCCESS)
	{
		if (status == ERROR_FILE_NOT_FOUND) {
			return true;
		}
		return false;
	}
	RegCloseKey(driver_service);

	auto NtUnloadDriver = (nt::NtUnloadDriver)GetProcAddress(ntdll, c_xor("NtUnloadDriver"));
	NTSTATUS st = NtUnloadDriver(&serviceStr);
	//--sup--printf("[+] NtUnloadDriver Status 0x%lx\n", st);
	if (st != 0x0) {
		//--sup--printf("[-] Driver Unload Failed!!\n");
	}


	status = RegDeleteKey(HKEY_LOCAL_MACHINE, servicesPath.c_str());
	if (status != ERROR_SUCCESS)
	{
		return false;
	}
	return true;
}
