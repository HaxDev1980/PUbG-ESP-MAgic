#pragma once
#include <Windows.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#include "portable_executable.hpp"
#include "kernel_driver_resource.hpp"
#include "Drvutils.hpp"
#include "nt.hpp"
#include "intel_driver.hpp"

namespace DrvMapper
{
	uint64_t MapDriver(HANDLE iqvw64e_device_handle);
	bool LoadDrv();
	void RelocateImageByDelta(portable_executable::vec_relocs relocs, const uint64_t delta);
	bool ResolveImports(HANDLE iqvw64e_device_handle, portable_executable::vec_imports imports);
}