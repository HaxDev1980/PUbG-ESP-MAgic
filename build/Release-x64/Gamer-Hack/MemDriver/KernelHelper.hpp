#pragma once
#pragma warning( disable : 4101 4244)

#include "communications.hpp"
#include "..//DriverMapper/DrvMapper.hpp"
#include <map>
#include<iostream>
#include<tuple> 
//#include "..//syscall.h"

//auto NtWriteVirtualMemory = makesyscall<bool>("NtWriteVirtualMemory");
//auto NtReadVirtualMemory = makesyscall<bool>("NtReadVirtualMemory");

class KernelHelper
{

public:
	HANDLE hDriver; //DriverHandler
	HANDLE ProcessHandler;
	ULONG ProcessId = 0;

	typedef struct _MEMORY_REGION {
		DWORD_PTR dwBaseAddr;
		DWORD_PTR dwMemorySize;
	}MEMORY_REGION;
	NTSTATUS OpenDrv(HANDLE& RetHandle)
	{
		RetHandle = INVALID_HANDLE_VALUE;
		IO_STATUS_BLOCK IoStatusBlock;
		OBJECT_ATTRIBUTES ObjectAttributes;
		ObjectAttributes.SecurityDescriptor = 0;
		ObjectAttributes.SecurityQualityOfService = 0;
		ObjectAttributes.RootDirectory = 0;
		ObjectAttributes.Attributes = 0;
		ObjectAttributes.Length = sizeof(OBJECT_ATTRIBUTES);

		WCHAR stringBuffer[40];
		UNICODE_STRING  string;
		lstrcpyW(stringBuffer, L"\\Device\\");
		lstrcatW(stringBuffer, L"PrSmrtDrv64");
		string.Buffer = stringBuffer;
		string.Length = lstrlenW(stringBuffer) * 2;
		string.MaximumLength = (lstrlenW(stringBuffer) * 2) + 2;
		ObjectAttributes.ObjectName = &string;

		HANDLE lhandle = INVALID_HANDLE_VALUE;
		NTSTATUS status = NtOpenFile(&lhandle, 0xC0100000, &ObjectAttributes, &IoStatusBlock, 0, 0);
		if (NT_SUCCESS(status))
		{
			RetHandle = lhandle;
		}
		return status;
	}
	BOOL LoadDriver()
	{
		NTSTATUS lstatus;
		lstatus = OpenDrv(hDriver);
		if (!NT_SUCCESS(lstatus) || hDriver == INVALID_HANDLE_VALUE)
		{
			if (!DrvMapper::LoadDrv())
			{
				return false;
			}
			lstatus = OpenDrv(hDriver);
			if (!NT_SUCCESS(lstatus) || hDriver == INVALID_HANDLE_VALUE)
			{
				return FALSE;
			}
			return TRUE;
		}
		else
		{
			return TRUE;
		}
	}
	BOOL AttachProcess() {

		if (!ProcessId)
		{
			return FALSE;
		}
		ProcessHandler = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
		if (ProcessHandler)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}


	bool ReadBytes(ULONG ReadAddress, BYTE& Buffer, long Size)
	{
		if (hDriver == INVALID_HANDLE_VALUE)
		{
			return false;
		}
		MemStruct_t ReadRequest;
		ReadRequest.pid = ProcessId;
		ReadRequest.address = ReadAddress;
		ReadRequest.value = &Buffer;
		ReadRequest.size = Size;

		bool stat = DeviceIoControl(hDriver, IOCTL_RPM, &ReadRequest, sizeof(MemStruct_t), &ReadRequest, sizeof(MemStruct_t), 0, 0);

		return stat;


	}

	template <typename type>
	type ReadVirtualMemory(ULONG ReadAddress)
	{

		type Buffer{};
		MemStruct_t ReadRequest;
		ReadRequest.pid = ProcessId;
		ReadRequest.address = ReadAddress;
		ReadRequest.value = &Buffer;
		ReadRequest.size = sizeof(type);

		DeviceIoControl(hDriver, IOCTL_RPM, &ReadRequest, sizeof(MemStruct_t), &ReadRequest, sizeof(MemStruct_t), 0, 0);
		return Buffer;
	}

	template <typename T>
	T ReadMemoryEx(DWORD BaseAddress)
	{
		T Buffer;
		ReadProcessMemory(hDriver, (LPCVOID)BaseAddress, &Buffer, sizeof(Buffer), nullptr);

		return Buffer;
	}

	template <typename T>
	void WriteMemoryEx(DWORD BaseAddress, T WriteValue)
	{
		WriteProcessMemory(hDriver, (LPVOID)BaseAddress, &WriteValue, sizeof(WriteValue), nullptr);
	}

	ULONG AllocateMemory(SIZE_T Size)
	{
		auto allocatedSpace = malloc(64);
		memset(&allocatedSpace, 0, 64);
		MemStruct_t AllocRequest;
		AllocRequest.pid = ProcessId;
		AllocRequest.address = 0;
		AllocRequest.value = &allocatedSpace;
		AllocRequest.size = Size;

		BOOL drvres = DeviceIoControl(hDriver, IOCTL_ALLOC, &AllocRequest, sizeof(MemStruct_t), &AllocRequest, sizeof(MemStruct_t), 0, 0);
		ULONG obj = 0;
		obj = (ULONG)allocatedSpace;
		if (drvres)
		{
			return obj;
		}
		return 0;
	}
	template <typename type>
	bool WriteVirtualMemory(ULONG WriteAddress, type WriteValue)
	{
		if (hDriver == INVALID_HANDLE_VALUE)
			return false;
		DWORD Bytes;

		MemStruct_t  WriteRequest;
		WriteRequest.pid = ProcessId;
		WriteRequest.address = WriteAddress;
		WriteRequest.value = &WriteValue;
		WriteRequest.size = sizeof(type);

		return DeviceIoControl(hDriver, IOCTL_WPM, &WriteRequest, sizeof(MemStruct_t), 0, 0, &Bytes, NULL);;
	}



#pragma optimize( "", off )
	bool WriteBytes(ULONG WriteAddress, BYTE Buffer[], SIZE_T Size)
	{
		if (hDriver == INVALID_HANDLE_VALUE)
		{
			return false;
		}
		auto allocatedPointer = malloc(Size);
		memset(&allocatedPointer, 0, Size);
		memcpy(&allocatedPointer, Buffer, Size);

		DWORD Bytes;

		MemStruct_t  WriteRequest;
		WriteRequest.pid = ProcessId;
		WriteRequest.address = WriteAddress;
		WriteRequest.value = &allocatedPointer;
		WriteRequest.size = Size;

		return DeviceIoControl(hDriver, IOCTL_WPM, &WriteRequest, sizeof(MemStruct_t), 0, 0, &Bytes, NULL);;


	}


	BOOL DataCompare(const BYTE* pData, const BYTE* pMask, const char* pszMask)
	{
		for (; *pszMask; ++pszMask, ++pData, ++pMask)
		{
			if (*pszMask == 'x' && *pData != *pMask)
			{
				return FALSE;
			}
		}
		return (*pszMask == 0);
	}



	bool SearchPattern(BYTE* bSearchData, int nSearchSize, DWORD_PTR dwStartAddr, DWORD_PTR dwEndAddr, BOOL SingleMode, std::vector<UINT>& vRet)
	{


		BYTE* pCurrMemoryData = NULL;
		MEMORY_BASIC_INFORMATION	mbi;
		mbi.RegionSize = 0x1000;
		DWORD dwAddress = dwStartAddr;
		while (VirtualQueryEx(ProcessHandler, (LPCVOID)dwAddress, &mbi, sizeof(mbi)) && (dwAddress < dwEndAddr) && ((dwAddress + mbi.RegionSize) > dwAddress))
		{

			if ((mbi.State == MEM_COMMIT) && ((mbi.Protect & PAGE_GUARD) == 0) && (mbi.Protect != PAGE_NOACCESS) && ((mbi.AllocationProtect & PAGE_NOCACHE) != PAGE_NOCACHE))
			{
				DWORD_PTR dwNumberOfBytesRead = 0;


				pCurrMemoryData = new BYTE[mbi.RegionSize];
				ZeroMemory(pCurrMemoryData, mbi.RegionSize);
				ReadBytes((DWORD_PTR)mbi.BaseAddress, *pCurrMemoryData, mbi.RegionSize);
				dwNumberOfBytesRead = mbi.RegionSize;
				if ((int)dwNumberOfBytesRead <= 0)
				{
					dwNumberOfBytesRead = 0;
					delete[] pCurrMemoryData;
					continue;
				}

				DWORD_PTR dwOffset = 0;
				int iOffset = find(pCurrMemoryData, dwNumberOfBytesRead, bSearchData, nSearchSize);
				while (iOffset != -1)
				{
					dwOffset += iOffset;
					vRet.push_back(dwOffset + (DWORD_PTR)mbi.BaseAddress);
					if (SingleMode)
					{
						if (pCurrMemoryData != NULL)
						{
							delete[] pCurrMemoryData;
							pCurrMemoryData = NULL;
						}
						return true;

					}
					dwOffset += nSearchSize;
					iOffset = find(pCurrMemoryData + dwOffset, dwNumberOfBytesRead - dwOffset - nSearchSize, bSearchData, nSearchSize);
				}

				if (pCurrMemoryData != NULL)
				{
					delete[] pCurrMemoryData;
					pCurrMemoryData = NULL;
				}

			}
			dwAddress = (DWORD)mbi.BaseAddress + mbi.RegionSize;

		}



		return TRUE;

	}
	int find(BYTE* buffer, int dwBufferSize, BYTE* bstr, DWORD dwStrLen) {
		if (dwBufferSize < 0)
		{
			return -1;
		}
		DWORD  i, j;
		for (i = 0; i < dwBufferSize; i++)
		{
			for (j = 0; j < dwStrLen; j++)
			{
				if (buffer[i + j] != bstr[j] && bstr[j] != '?')
					break;
			}
			if (j == dwStrLen)
				return i;
		}
		return -1;
	}




	/////////////////////////////////extra////////////////////////////////


#pragma region Extra memory funcion

	int MemFind(BYTE* buffer, int dwBufferSize, BYTE* bstr, DWORD dwStrLen)
	{
		if (dwBufferSize < 0)
		{
			return -1;
		}

		DWORD  i, j;
		for (i = 0; i < dwBufferSize; i++)
		{
			for (j = 0; j < dwStrLen; j++)
			{
				if (buffer[i + j] != bstr[j] && bstr[j] != '?')
					break;
			}

			if (j == dwStrLen)
				return i;
		}

		return -1;
	}

	int SundaySearch(BYTE* bStartAddr, int dwSize, BYTE* bSearchData, DWORD dwSearchSize)
	{
		if (dwSize < 0)
		{
			return -1;
		}

		int iIndex[256] = { 0 };
		int i, j;
		DWORD k;
		for (i = 0; i < 256; i++)
		{
			iIndex[i] = -1;
		}

		j = 0;
		for (i = dwSearchSize - 1; i >= 0; i--)
		{
			if (iIndex[bSearchData[i]] == -1)
			{
				iIndex[bSearchData[i]] = dwSearchSize - i;
				if (++j == 256)
					break;
			}
		}

		i = 0;
		BOOL bFind = FALSE;
		j = dwSize - dwSearchSize + 1;
		while (i < j)
		{
			for (k = 0; k < dwSearchSize; k++)
			{
				if (bStartAddr[i + k] != bSearchData[k])
					break;
			}

			if (k == dwSearchSize)
			{
				bFind = TRUE;
				break;
			}

			if (i + dwSearchSize >= dwSize)
			{

				return -1;
			}

			k = iIndex[bStartAddr[i + dwSearchSize]];
			if (k == -1)
				i = i + dwSearchSize + 1;
			else
				i = i + k;
		}

		if (bFind)
		{
			return i;
		}
		else
			return -1;
	}

	BOOL MemSearch(BYTE* bSearchData, int nSearchSize, DWORD_PTR dwStartAddr, DWORD_PTR dwEndAddr, BOOL bIsCurrProcess, int iSearchMode, std::vector<DWORD_PTR>& vRet)
	{
		BYTE* pCurrMemoryData = NULL;
		MEMORY_BASIC_INFORMATION	mbi;
		std::vector<MEMORY_REGION> m_vMemoryRegion;
		mbi.RegionSize = 0x1000;
		DWORD dwAddress = dwStartAddr;

		while (VirtualQueryEx(ProcessHandler, (LPCVOID)dwAddress, &mbi, sizeof(mbi)) && (dwAddress < dwEndAddr) && ((dwAddress + mbi.RegionSize) > dwAddress))
		{
			if ((mbi.State == MEM_COMMIT) && ((mbi.Protect & PAGE_GUARD) == 0) && (mbi.Protect != PAGE_NOACCESS) && ((mbi.AllocationProtect & PAGE_NOCACHE) != PAGE_NOCACHE))
			{

				MEMORY_REGION mData = { 0 };
				mData.dwBaseAddr = (DWORD_PTR)mbi.BaseAddress;
				mData.dwMemorySize = mbi.RegionSize;
				m_vMemoryRegion.push_back(mData);
			}

			dwAddress = (DWORD)mbi.BaseAddress + mbi.RegionSize;
		}

		std::vector<MEMORY_REGION>::iterator it;
		for (it = m_vMemoryRegion.begin(); it != m_vMemoryRegion.end(); it++)
		{
			MEMORY_REGION mData = *it;
			DWORD_PTR dwNumberOfBytesRead = 0;
			if (bIsCurrProcess)
			{
				pCurrMemoryData = (BYTE*)mData.dwBaseAddr;
				dwNumberOfBytesRead = mData.dwMemorySize;
			}
			else
			{
				pCurrMemoryData = new BYTE[mData.dwMemorySize];
				ZeroMemory(pCurrMemoryData, mData.dwMemorySize);
				ReadProcessMemory(ProcessHandler, (LPCVOID)mData.dwBaseAddr, pCurrMemoryData, mData.dwMemorySize, &dwNumberOfBytesRead);

				if ((int)dwNumberOfBytesRead <= 0)
				{
					delete[] pCurrMemoryData;
					continue;
				}
			}

			if (iSearchMode == 0)
			{
				DWORD_PTR dwOffset = 0;
				int iOffset = MemFind(pCurrMemoryData, dwNumberOfBytesRead, bSearchData, nSearchSize);
				while (iOffset != -1)
				{
					dwOffset += iOffset;
					vRet.push_back(dwOffset + mData.dwBaseAddr);
					dwOffset += nSearchSize;
					iOffset = MemFind(pCurrMemoryData + dwOffset, dwNumberOfBytesRead - dwOffset - nSearchSize, bSearchData, nSearchSize);
				}
			}
			else if (iSearchMode == 1)
			{
				DWORD_PTR dwOffset = 0;
				int iOffset = SundaySearch(pCurrMemoryData, dwNumberOfBytesRead, bSearchData, nSearchSize);

				while (iOffset != -1)
				{
					dwOffset += iOffset;
					vRet.push_back(dwOffset + mData.dwBaseAddr);
					dwOffset += nSearchSize;
					iOffset = MemFind(pCurrMemoryData + dwOffset, dwNumberOfBytesRead - dwOffset - nSearchSize, bSearchData, nSearchSize);
				}
			}

			if (!bIsCurrProcess && (pCurrMemoryData != NULL))
			{
				delete[] pCurrMemoryData;
				pCurrMemoryData = NULL;
			}
		}

		return TRUE;
	}

	VOID ChangeClickability(BOOL CanClick, HWND hWindow)
	{
		LONG Style = GetWindowLong(hWindow, GWL_EXSTYLE);

		if (CanClick)
		{
			Style &= ~WS_EX_LAYERED;
			SetWindowLong(hWindow, GWL_EXSTYLE, Style);
			SetForegroundWindow(hWindow);
		}
		else
		{
			Style |= WS_EX_LAYERED;
			SetWindowLong(hWindow, GWL_EXSTYLE, Style);
		}
	}
	bool patcher(long addr, BYTE write[], SIZE_T sizee) {
		/*MemStruct_t ReadRequest;
		ReadRequest.pid = ProcessId;
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcessId);*/
		HANDLE phandle;
		MemStruct_t ReadRequest;
		if (phandle == NULL)
		{
			ReadRequest.pid = ProcessId;
			phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcessId);
		}
		unsigned long OldProtect;
		unsigned long OldProtect2;
		VirtualProtectEx(phandle, (void*)addr, sizee, PAGE_EXECUTE_READWRITE, &OldProtect);
		WriteProcessMemory(phandle, (void*)addr, write, sizee, NULL);
		VirtualProtectEx(phandle, (void*)addr, sizee, OldProtect, NULL);
		return true;
	}

	void AOBREP(BYTE BypaRep[], BYTE write[], SIZE_T size, SIZE_T sizee, int numbers)
	{

		//HANDLE phandle;
		//MemStruct_t ReadRequest;
		//if (phandle == NULL)
		//{
		//	ReadRequest.pid = ProcessId;
		//	phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcessId);
		//}
		std::vector<DWORD_PTR> Bypassdo;
		MemSearch(BypaRep, size, 0x00000000, 0x7fffffff, false, 0, Bypassdo);

		if (Bypassdo.size() != 0) {
			for (int i = 0; i < Bypassdo.size() && i < numbers; i++)
			{
				int results = Bypassdo[i];
				patcher(results, write, sizee);
			}

		}
		else
		{
			//cout << "no results found" << endl;
		}

	}



	int SINGLEAOBSCAN(BYTE BypaRep[], SIZE_T size)
	{
		HANDLE phandle;
		MemStruct_t ReadRequest;
		if (phandle == NULL)
		{
			ReadRequest.pid = ProcessId;
			phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcessId);
		}
		std::vector<DWORD_PTR> Bypassdo;
		MemSearch(BypaRep, size, 0x26000000, 0xB0000000, false, 0, Bypassdo);

		if (Bypassdo.size() != 0) {
			return Bypassdo[0];
		}
	}

	void INJECT(int offset, BYTE write[], SIZE_T size, int header)
	{
		HANDLE phandle;
		MemStruct_t ReadRequest;
		if (phandle == NULL)
		{
			ReadRequest.pid = ProcessId;
			phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcessId);
		}
		
		if (!phandle == NULL)
		{
			int addr = header + offset;
			unsigned long OldProtect;
			unsigned long OldProtect2;
			VirtualProtectEx(phandle, (BYTE*)addr, size, PAGE_EXECUTE_READWRITE, &OldProtect);
			WriteProcessMemory(phandle, (BYTE*)addr, write, size, NULL);
			VirtualProtectEx(phandle, (BYTE*)addr, size, OldProtect, NULL);
			VirtualProtectEx(phandle, (BYTE*)addr, size, OldProtect, &OldProtect2);
		}
		
	}

#pragma endregion
};