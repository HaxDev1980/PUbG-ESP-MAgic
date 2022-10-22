#include "../pch.h"
#include <thread>
Utilities* g_Utilities = new Utilities();

Utilities::Utilities() {}


Utilities::~Utilities() {}
typedef int(__stdcall* MSGBOXWAPI)
(

    HWND hWnd,
    LPCWSTR lpText,
    LPCWSTR lpCaption,
    UINT uType,
    WORD wLanguageId,
    DWORD dwMilliseconds
    );

bool TryAgain = false;


UINT Utilities::getViewWorld() {
    BYTE pattern[] = { 0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x01 };

    std::vector<UINT> foundedBases;
    DWORD_PTR StartRange = 0;
    DWORD_PTR EndRange = 0;
    if (ProcManager::TargetEmulator == 1)
    {
        StartRange = 0x26000000;
        EndRange = 0x30000000;
    }
    else if (ProcManager::TargetEmulator == 2)
    {
        StartRange = 0x70000000;
        EndRange = 0x90000000;
    }
    else if (ProcManager::TargetEmulator == 3)
    {
        StartRange = 0x3D000000;
        EndRange = 0x60000000;
    }
    else
    {
        exit(1);
        ExitProcess(1);
    }
    if(TryAgain)
    {
        StartRange = 0x3D000000;
        EndRange = 0x60000000;
    }
    Driver.SearchPattern(pattern, sizeof(pattern), StartRange, EndRange, false, foundedBases);
    long tmp;
    float v1, v2, v3, v4;
    for (int i = 0; i < foundedBases.size(); i++) {
        DWORD cand = foundedBases[i] - 0x20;
        auto eng = Driver.ReadVirtualMemory<UINT>(cand) + 0x20;
        auto tmp = Driver.ReadVirtualMemory<UINT>(eng) + 0x200;
        v1 = Driver.ReadVirtualMemory<float>(tmp + 56);
        v2 = Driver.ReadVirtualMemory<float>(tmp + 40);
        v3 = Driver.ReadVirtualMemory<float>(tmp + 24);
        v4 = Driver.ReadVirtualMemory<float>(tmp + 8);
        if (v1 >= 3 && v2 == 0 && v3 == 0 && v4 == 0)
        {
            foundedBases.clear();
            
                return cand;
           
        }
    }
    foundedBases.clear();
    if(!TryAgain&& ProcManager::TargetEmulator == 1)
    {
        TryAgain = true;
       return getViewWorld();
    }
    return 0;
}

void Utilities::ScanBulletTracking(bool Mstat) {
    if(Mstat)
    {

        g_Settings::MagicRefresh = true;
       

    }
    ZeroMemory(g_Settings::MagicData,0);
    g_Settings::MagicSearching = true;
    g_Settings::MagicError = false;
    if(!g_Settings::MagicBulletList.empty())
    {
        g_Settings::MagicBulletList.clear();
    }
  
    DWORD_PTR StartRange = 0;
    DWORD_PTR EndRange = 0;
    if (ProcManager::TargetEmulator == 1)
    {
        StartRange = 0x18000000;
        EndRange = 0x20000000;
    }
    else if (ProcManager::TargetEmulator == 2)
    {
        StartRange = 0x0D000DD2;
        EndRange = 0x12000000;
    }
    else if (ProcManager::TargetEmulator == 3)
    {
        StartRange = 0x0D000DD2;
        EndRange = 0x13000000;
    }else
    {
        g_Settings::MagicSearching = true;
        g_Settings::MagicError = true;
        return;
    }

    std::vector<UINT> TrackSearch;
    Driver.SearchPattern((BYTE*)GameOffsets::BtPatn, 8, StartRange, EndRange, false, TrackSearch);
    for (auto addv : TrackSearch)
    {
        if (Driver.ReadVirtualMemory<byte>(addv + 12) == GameOffsets::MainIdentifierByte && Driver.ReadVirtualMemory<byte>(addv + 8) == 0xC7)
        {
            if (ProcManager::TargetEmulator == 1)
            {
                if (Driver.ReadVirtualMemory<int>(addv - 4) == 168)
                {
                    g_Settings::MagicBulletList.push_back(addv);
                }
            }
            else
            {
                g_Settings::MagicBulletList.push_back(addv);
            }
        }
    }
    TrackSearch.clear();

    if (Mstat)
    {
        g_Settings::MagicRefresh = false;
    }
    g_Settings::MagicSearching = false;
}

std::string Utilities::ConvertFromUtf16ToUtf8(const std::wstring& wstr)
{
    std::string convertedString;
    int requiredSize = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, 0, 0, 0, 0);
    if (requiredSize > 0)
    {
        std::vector<char> buffer(requiredSize);
        WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &buffer[0], requiredSize, 0, 0);
        convertedString.assign(buffer.begin(), buffer.end() - 1);
    }
    return convertedString;
}

struct ObjectNameA
{
    char data[64];
};


std::string Utilities::GetEntityType(UINT gNames, UINT id)
{

    auto gname = Driver.ReadVirtualMemory<UINT>(gNames);
    if (id > 0 && id < 2000000)
    {
        auto page = id / 16384;
        DWORD index = id % 16384;
        auto secPartAddv = Driver.ReadVirtualMemory<UINT>(gname + page * 4);
        if (secPartAddv > 0)
        {
            auto nameAddv = Driver.ReadVirtualMemory<UINT>(secPartAddv + index * 4);
          
            if (nameAddv > 0)
            {
                ObjectNameA pBuffer = g_Utilities->Driver.ReadVirtualMemory<ObjectNameA>(nameAddv + 0x8);
                return pBuffer.data;
            }
        }
    }
    return std::string("");
}

int Utilities::MessageTimeout(LPCWSTR lpText, UINT uType)
{
    MSGBOXWAPI MsgBoxTOW = NULL;
   
    HMODULE hUser32 = GetModuleHandle(L"user32.dll");
    if (hUser32)
    {
        MsgBoxTOW = (MSGBOXWAPI)GetProcAddress(hUser32, "MessageBoxTimeoutW");
       
        return MsgBoxTOW(0, lpText, L"RYZEN VIP", uType | MB_SYSTEMMODAL, 0, 3000);
        
    }
    exit(0);
    ExitProcess(0);
    return 1;
}


std::string Utilities::GetVehicleType(std::string classname)
{
   
    if (classname.find("Coupe") != std::string::npos)
    {
        return "Coupe RB";
    }
    else if (classname.find("Buggy") != std::string::npos)
    {
        return "Buggy";
    }
    else if (classname.find("Mirado") != std::string::npos)
    {
        return "Mirado";
    }
    else if (classname.find("Dacia") != std::string::npos)
    {
        return "Dacia";
    }
    else if (classname.find("UAZ") != std::string::npos)
    {
        return "UAZ";
    }
    else if (classname.find("BRDM") != std::string::npos)
    {
        return "BRDM";
    }
    else if (classname.find("Scooter") != std::string::npos)
    {
        return "Scooter";
    }
    else if (classname.find("Motorcycle") != std::string::npos)
    {
        return "Bike";
    }
    else if (classname.find("MotorcycleCart") != std::string::npos)
    {
        return "Motorcycle Cart";
    }
    else if (classname.find("Snowmobile") != std::string::npos)
    {
        return "Snowmobile";
    }
    else if (classname.find("Tuk") != std::string::npos)
    {
        return "Tuk";
    }
    else if (classname.find("Rony") != std::string::npos)
    {
        return "Rony";
    }
    else if (classname.find("MiniBus") != std::string::npos)
    {
        return "MiniBus";
    }
    else if (classname.find("PG117") != std::string::npos)
    {
        return "PG117";
    }
    else if (classname.find("AquaRail") != std::string::npos)
    {
        return "AquaRail";
    }
    return "";
}
std::string Utilities::IsBox(std::string classname)
{
    if (classname.find("PickUpListWrapperActor") != std::string::npos)
    {
        return "LootBox ";
    }
    else if (classname.find("AirDrop") != std::string::npos && classname.find("plane") == std::string::npos)
    {
        return "AirDrop ";
    }
    return "";
}
std::string  Utilities::PlayerWeapon(std::string str)
{
    if (str == "BP_Sniper_AWM_C")
        return "AWM";
    else if (str == "BP_Sniper_QBU_C")
        return "QBU";
    else if (str == "BP_Sniper_SLR_C")
        return "SLR";
    else if (str == "BP_Sniper_SKS_C")
        return "SKS";
    else if (str == "BP_Sniper_Mini14_C")
        return "Mini14";
    else if (str == "BP_Sniper_M24_C")
        return "M24";
    else if (str == "BP_Sniper_Kar98k_C")
        return "Kar98k";
    else if (str == "BP_Sniper_VSS_C")
        return "VSS";
    else if (str == "BP_Sniper_Win94_C")
        return "Win94";
    else if (str == "BP_Sniper_Mosin_C")
        return "Mosin";
    else if (str == "BP_Sniper_MK12_C")
        return "MK12";
    else if (str == "BP_Rifle_AUG_C")
        return "AUG";
    else if (str == "BP_Rifle_M762_C")
        return "M762";
    else if (str == "BP_Rifle_SCAR_C")
        return "SCAR";
    else if (str == "BP_Rifle_M416_C")
        return "M416";
    else if (str == "BP_Rifle_M16A4_C")
        return "M16A4";
    else if (str == "BP_Rifle_Mk47_C")
        return "Mk47";
    else if (str == "BP_Rifle_G36_C")
        return "G36";
    else if (str == "BP_Rifle_QBZ_C")
        return "QBZ";
    else if (str == "BP_Rifle_AKM_C")
        return "AKM";
    else if (str == "BP_Rifle_Groza_C")
        return "Groza";
    else if (str == "BP_Other_DP28_C")
        return "DP28";
    else if (str == "BP_Other_M249_C")
        return "M249";
    else if (str == "BP_MachineGun_P90_C")
        return "P90";
    else if (str == "BP_ShotGun_S12K_C")
        return "S12K";
    else if (str == "BP_ShotGun_DP12_C")
        return "DP12";
    else if (str == "BP_ShotGun_S686_C")
        return "S686";
    else if (str == "BP_ShotGun_S1897_C")
        return "S1897";
    else if (str == "BP_ShotGun_SawedOff_C")
        return "SawedOff";
    else if (str == "BP_MachineGun_PP19_C")
        return "PP19";
    else if (str == "BP_MachineGun_TommyGun_C")
        return "TommyGu";
    else if (str == "BP_MachineGun_MP5K_C")
        return "MP5K";
    else if (str == "BP_MachineGun_UMP9_C")
        return "UMP9";
    else if (str == "BP_MachineGun_Vector_C")
        return "Vector";
    else if (str == "BP_MachineGun_Uzi_C")
        return "Uzi";
    else if (str == "BP_Pistol_Flaregun_C")
        return "Flaregun";
    else if (str == "BP_Pistol_R1895_C")
        return "R1895";
    else if (str == "BP_Pistol_Vz61_C")
        return "Vz61";
    else if (str == "BP_Pistol_P92_C")
        return "P92";
    else if (str == "BP_Pistol_P18C_C")
        return "P18C";
    else if (str == "BP_Pistol_R45_C")
        return "R45";
    else if (str == "BP_Pistol_P1911_C")
        return "P1911";
    else if (str == "BP_Pistol_DesertEagle_C")
        return "DesertEagle";
    else if (str == "BP_WEP_Mk14_C")
        return "Mk14";
    else if (str == "BP_Other_CrossBow_C")
        return "CrossBow";
    else if (str == "BP_Grenade_Shoulei_C")
        return "Shoulei Grenade";
    else if (str == "BP_Grenade_Smoke_C")
        return "Smoke Grenade";
    else if (str == "BP_Grenade_Burn_C")
        return "Burn Grenade";
    else if (str == "")
        return "Fist";
    else
        return "";
    return "";
}

std::string Utilities::GetGrenadeType(std::string classname)
{
    if (classname.find("BP_Grenade_Shoulei_C") != std::string::npos)
    {
        return "[ALERT]!FRAG GRENADE!";
    }
    else if (classname.find("BP_Grenade_Smoke_C") != std::string::npos)
    {
        return "SMOKE";
    }
    else if (classname.find("BP_Grenade_Burn_C") != std::string::npos)
    {
        return "[ALERT]!MOLOTOV!";
    }
    else if (classname.find("BP_Grenade_tun_C") != std::string::npos)
    {
        return "FLASH GRENADE";
    }
    else
    {

        return "";
    }
      
}
std::string Utilities::getState(int state)
{
    switch (state)
    {
    case 0:
        return "AFK";
    case 1:
        return "In Water";
    case 8:
        return "Standing";
    case 9:
        return "Walking";
    case 10:
        return "Landing";
    case 11:
        return "Running";
    case 16:
        return "Crouching";
    case 17:
        return "Crouching Walk";
    case 19:
        return "Crouching Run";
    case 32:
        return "Snaking";
    case 33:
        return "Snaking Walk";
    case 35:
        return "Snaking Run";
    case 5445:
    case 762:
        return "Snake";
    case 72:
    case 73:
    case 75:
        return "Jumping";
    case 264:
    case 272:
    case 273:
    case 288:
    case 265:
    case 329:
        return "Relaoding";
    case 136:
    case 137:
    case 144:
    case 145:
    case 160:
    case 648:
    case 649:
    case 1160:
    case 1161:
    case 1169:
    case 201:
        return "Firing";
    case 4194304:
    case 4194307:
        return "Swimming";
    case 131070:
    case 131071:
    case 131072:
    case 131073:
    case 131074:
    case 131075:
        return "Knocked";
    case 524296:
        return "Driving Vehicle";
    case 524288:
        return "Driving Boat";
    case 1048584:
        return "Set in Vehicle";
    case 1048576:
        return "Set in Boat";
    case 33554440:
        return "Set in Plane";
    case 3146248:
        return "Aim in vehicle";
    case 3146240:
        return "Aim in boat";
    case 3145736:
        return "Beek in vehicle";
    case 3145728:
        return "Beek in boat";
    case 1050632:
        return "Change vehicle seat";
    case 1050624:
        return "Change boat seat";
    case 32784:
        return "Reviving";
    case 16392:
    case 16393:
    case 16401:
    case 16416:
    case 16417:
    case 16457:
    case 16400:
    case 17401:
    case 17417:
    case 17424:
    case 17425:
        return "Throwing Bomp";
    case 16777224:
        return "Climping";
    case 8200:
    case 8208:
        return "Punish, Stab";
    case 520:
    case 544:
    case 521:
    case 656:
    case 528:
        return "Aiming";
    case 1680:
    case 1672:
    case 1673:
    case 1032:
    case 1544:
    case 1545:
    case 1033:
        return "Peeking";
    case 2056:
        return "Change Weapon";
    case 65544:
        return "Healing";
    case 65545:
        return "Healing & Walk";
    case 268435464:
        return "Playing Emotion";
    case 4194305:
        return "Diving, Floating";
    }

    return std::to_string(state);
}


ImColor Red = ImColor(195, 36, 24, 220);
ImColor yellow = ImColor(255, 233, 91, 220);
ImColor green = ImColor(28, 197, 50, 220);
ImColor blue = ImColor(0, 69, 255, 220);
ImColor orange = ImColor(255, 165, 0, 220);
ImColor white = ImColor(230, 230, 178, 230);
ImColor black = ImColor(0, 0, 24, 225);
ImColor purple = ImColor(128, 0, 128, 220);
ImColor pink = ImColor(199, 21, 133, 220);


Itemb Utilities::GetItemWTCode(int code)
{
    switch (code)
    {
    case 101001:
    {
        return Itemb{ "AKM",yellow };
    }
    case 101005:
    {
        return Itemb{ "Groza",yellow };
    }
    case 101008:
    {
        return  Itemb{ "M762",yellow };
    }
    case 101100:
    {
        return Itemb{ "Famas",green };
    }
    case 101003:
    {
        return Itemb{ "SCAR-L",green };
    }
    case 101004:
    {
        return Itemb{ "M416",green };
    }
    case 101002:
    {
        return Itemb{ "M16A-4",green };
    }
    case 101009:
    {
        return Itemb{ "Mk47 Mutant",yellow };
    }
    case 101010:
    {
        return Itemb{ "G36C",green };
    }
    case 101007:
    {
        return Itemb{ "QBZ",green };
    }
    case 101006:
    {
        return Itemb{ "AUG_A3",green };
    }
    case 105001:
    {
        return Itemb{ "M249",green };
    }
    case 105002:
    {
        return Itemb{ "DP28",yellow };

    }
    case 102005:
    {
        return Itemb{ "PP19 Bizon",orange };
    }
    case 102004:
    {
        return Itemb{ "Thompson",white };
    }

    case 102002:
    {
        return Itemb{ "UMP9",white };
    }
    case 102003:
    {
        return Itemb{ "Vector",white };
    }
    case 102001:
    {
        return Itemb{ "Uzi",orange };
    }
    case 103007:
    {
        return Itemb{ "Mk14",yellow };
    }
    case 103009:
    {
        return Itemb{ "SLR",orange };
    }
    case 103010:
    {
        return Itemb{ "QBU",orange };
    }
    case 103100:
    {
        return Itemb{ "MK12",orange };
    }
    case 103011:
    {
        return Itemb{ "Mosin",orange };
    }
    case 103004:
    {
        return Itemb{ "SKS",orange };
    }
    case 103006:
    {
        return Itemb{ "Mini14",orange };
    }
    case 103002:
    {
        return Itemb{ "M24",orange };
    }
    case 103001:
    {
        return Itemb{ "Kar98k",orange };
    }
    case 103005:
    {
        return Itemb{ "VSS",orange };
    }
    case 103008:
    {
        return Itemb{ "Win94",orange };
    }
    case 103003:
    {
        return Itemb{ "AWM",Red };
    }
    case 306001:
    {
        return Itemb{ "300Magnum",Red };
    }
    case 104003:
    {
        return Itemb{ "S12K",yellow };
    }

    case 104101:
    {
        return Itemb{ "M1014",yellow };
    }
    case 104004:
    {
        return Itemb{ "DBS",yellow };
    }
    case 104001:
    {
        return Itemb{ "S686",yellow };
    }
    case 104002:
    {
        return Itemb{ "S1897",yellow };
    }  case 302001:
    {
        return Itemb{ "7.62",yellow };
    }
    case 305001:
    {
        return Itemb{ "45ACP",white };
    }
    case 303001:
    {
        return Itemb{ "5.56",green };
    }
    case 301001:
    {
        return Itemb{ "9mm",orange };
    }
    case 304001:
    {
        return Itemb{ "12Guage",yellow };
    }
    case 307001:
    {
        return Itemb{ "Arrows",green };
    }
    case 308001:
    {
        return Itemb{ "FlareAmmo",Red };
    }  case 106006:
    {
        return Itemb{ "SawedOff",white };
    }
    case 106007:
    {
        return Itemb{ "Flaregun",Red };
    }
    case 102007:
    {
        return Itemb{ "MP5K",white };
    }
    case 106004:
    {
        return Itemb{ "P18C",white };
    }
    case 106003:
    {
        return Itemb{ "R1895",white };
    }
    case 106008:
    {
        return Itemb{ "Vz61",white };
    }
    case 106001:
    {
        return Itemb{ "P92",white };
    }
    case 106005:
    {
        return Itemb{ "R45",white };
    }
    case 106002:
    {
        return Itemb{ "P1911",white };
    }
    case 106010:
    {
        return Itemb{ "DesertEagle",white };
    }   case 108003:
    {
        return Itemb{ "Sickle",white };
    }
    case 108001:
    {
        return Itemb{ "Machete",white };
    }
    case 107001:
    {
        return Itemb{ "Cross Bow",white };
    }
    case 108004:
    {
        return Itemb{ "Pan",white };
    }case 203005:
    {
        return Itemb{ "8x",blue };
    }
    case 203003:
    {
        return Itemb{ "2x",blue };
    }

    case 203014:
    {
        return Itemb{ "3X",blue };
    }
    case 203002:
    {
        return Itemb{ "Holo",blue };
    }
    case 203015:
    {
        return Itemb{ "6x",blue };
    }
    case 203004:
    {
        return Itemb{ "4x",blue };
    } case 201006:
    {
        return Itemb{ "Suppressor(SMG)",yellow };
    }
    case 201007:
    {
        return Itemb{ "Suppressor(Snip)",yellow };
    }
    case 201011:
    {
        return Itemb{ "Suppressor(AR)",yellow };
    }
    case 204009:
    {
        return Itemb{ "Extended QuickDraw Mag ( Snipers)",yellow };
    }
    case 204007:
    {
        return Itemb{ "Extended Mag Sniper",yellow };
    }
    case 204008:
    {
        return Itemb{ "QuickDraw Mag (Snipers)",yellow };
    }
    case 204004:
    {
        return Itemb{ "Extended Mag (SMG, Pistols)",yellow };
    }
    case 201002:
    {
        return Itemb{ "Compensator (SMG)",yellow };
    }

    case 204012:
    {
        return Itemb{ "QuickDraw Mag AR",yellow };
    }
    case 204013:
    {
        return Itemb{ "Extended QuickDraw Mag (AR)",yellow };
    }
    case 204011:
    {
        return Itemb{ "Exteded AR",yellow };
    }
    case 204005:
    {
        return Itemb{ "QuickDraw Mag(SMG, Pistols)",yellow };
    }
    case 204006:
    {
        return Itemb{ "Extended QuickDraw Mag (SMG)",yellow };
    }case 602004:
    {
        return Itemb{ "Grenade",yellow };
    }

    case 602002:
    {
        return Itemb{ "Smoke",yellow };
    }
    case 602003:
    {
        return Itemb{ "Molotof",yellow };
    }case 601002:
    {
        return Itemb{ "Adrenaline Syringe",blue };
    }
    case 601001:
    {
        return Itemb{ "Energy Drink",blue };
    }
    case 601003:
    {
        return Itemb{ "Painkiller",blue };
    } case 601005:
    {
        return Itemb{ "FirstaidKit",blue };
    }
    case 601004:
    {
        return Itemb{ "Bandage",blue };
    }
    case 601006:
    {
        return Itemb{ "Medkit",blue };
    } case 501006:
    {
        return Itemb{ "Bag Lv.3",Red };
    }
    case 501001:
    {
        return Itemb{ "Bag L.1",yellow };
    }
    case 501002:
    {
        return Itemb{ "Bag L.2",yellow };
    }

    case 501003:
    {
        return Itemb{ "Bag Lv.3",Red };
    } case 503002:
    {
        return Itemb{ "Armour Lv.2",yellow };
    }
    case 503001:
    {
        return Itemb{ "Armour Lv.1",yellow };
    }
    case 503003:
    {
        return Itemb{ "Armour Lv.3",Red };
    } case 502002:
    {
        return Itemb{ "Helmet Lv.2",yellow };
    }
    case 502001:
    {
        return Itemb{ "Helmet Lv.1",yellow };
    }
    case 502003:
    {
        return Itemb{ "Helmet Lv.3",yellow };
    }
    case 201009:
    {
        return Itemb{ "AR Compensator",yellow };
    }
    case 201012:
    {
        return Itemb{ "Duckbill (Pompalı)",yellow };
    }
    case 205001:
    {
        return Itemb{ "Dipcik (Micro UZI)",white };
    }
    case 202001:
    {
        return Itemb{ "Acili El Tutamagi",green };
    }
    case 202006:
    {
        return Itemb{ "Basparmaklik",pink };
    }
    case 202002:
    {
        return Itemb{ "Angle Foregrip",yellow };
    }
    case 202007:
    {
        return Itemb{ "Silah Lazeri",blue };
    }
    case 202004:
    {
        return Itemb{ "Hafif Tutamak",white };
    }
    case 0:
    {
        return Itemb{ "Yarım Tutamak",yellow };
    }
    case 204014:
    {
        return Itemb{ "Mermilik",purple };
    }
    case 205003:
    {
        return Itemb{ "Chekpad Sniper",blue };
    }
    case 205002:
    {
        return Itemb{ "Taktik Dipcik",white };
    }
    case 201001:
        return { "Choke" ,yellow };
    case 602005:
    {
        return Itemb{ "Apple_Weapon",yellow };
    }

    case 203001:
        return { "Red Dot",yellow };
    default:
        return Itemb{ "",white };
    }

    return Itemb{ "",NULL };




}
 
#pragma region GameMath
bool Utilities::WorldToScreen(D3DMatrix viewMatrix, Vector3 pos, Vector3& screen, int* distance, float m_Width, float m_Height) {
    float screenW = (viewMatrix._14 * pos.x) + (viewMatrix._24 * pos.y) + (viewMatrix._34 * pos.z + viewMatrix._44);
    screen.z = screenW;
    *distance = (screenW / 100);
    if (screenW < 0.0001f) return false;
    screenW = 1 / screenW;
    screen.x = m_Width + (viewMatrix._11 * pos.x + viewMatrix._21 * pos.y + viewMatrix._31 * pos.z + viewMatrix._41) * screenW * m_Width;
    screen.y = m_Height - (viewMatrix._12 * pos.x + viewMatrix._22 * pos.y + viewMatrix._32 * pos.z + viewMatrix._42) * screenW * m_Height;
    return true;
}

bool Utilities::WorldToScreenPlayer(Vector3 pos, Vector3& screen, int* distance, D3DMatrix viewMatrix, float m_Width, float m_Height) {
    float screenW = (viewMatrix._14 * pos.x) + (viewMatrix._24 * pos.y) + (viewMatrix._34 * pos.z + viewMatrix._44);
    *distance = (screenW / 100);
    if (screenW < 0.0001f) return false;
    float screenY = (viewMatrix._12 * pos.x) + (viewMatrix._22 * pos.y) + (viewMatrix._32 * (pos.z + 85) + viewMatrix._42);
    float screenX = (viewMatrix._11 * pos.x) + (viewMatrix._21 * pos.y) + (viewMatrix._31 * pos.z + viewMatrix._41);
    screen.y = (m_Height)-(m_Height)*screenY / screenW;
    screen.x = (m_Width)+(m_Width)*screenX / screenW;
    float y1 = (m_Height)-(viewMatrix._12 * pos.x + viewMatrix._22 * pos.y + viewMatrix._32 * (pos.z - 95) + viewMatrix._42) * (m_Height) / screenW;
    screen.z = y1 - screen.y;
    return true;
}


bool Utilities::WorldToScreenBone(D3DMatrix viewMatrix, Vector3 pos, Vector2& screen, int* distance, float m_Width, float m_Height) {
    float screenW = (viewMatrix._14 * pos.x) + (viewMatrix._24 * pos.y) + (viewMatrix._34 * pos.z + viewMatrix._44);
    *distance = (screenW / 100);
    if (screenW < 0.0001f) return false;
    screenW = 1 / screenW;
    screen.x = m_Width + (viewMatrix._11 * pos.x + viewMatrix._21 * pos.y + viewMatrix._31 * pos.z + viewMatrix._41) * screenW * m_Width;
    screen.y = m_Height - (viewMatrix._12 * pos.x + viewMatrix._22 * pos.y + viewMatrix._32 * pos.z + viewMatrix._42) * screenW * m_Height;
    return true;
}
D3DMatrix Utilities::ToMatrixWithScale(Vector3 translation, Vector3 scale, Quat rot) {
    D3DMatrix m;
    m._41 = translation.x;
    m._42 = translation.y;
    m._43 = translation.z;

    float x2 = rot.x + rot.x;
    float y2 = rot.y + rot.y;
    float z2 = rot.z + rot.z;

    float xx2 = rot.x * x2;
    float yy2 = rot.y * y2;
    float zz2 = rot.z * z2;
    m._11 = (1.0f - (yy2 + zz2)) * scale.x;
    m._22 = (1.0f - (xx2 + zz2)) * scale.y;
    m._33 = (1.0f - (xx2 + yy2)) * scale.z;

    float yz2 = rot.y * z2;
    float wx2 = rot.w * x2;
    m._32 = (yz2 - wx2) * scale.z;
    m._23 = (yz2 + wx2) * scale.y;

    float xy2 = rot.x * y2;
    float wz2 = rot.w * z2;
    m._21 = (xy2 - wz2) * scale.y;
    m._12 = (xy2 + wz2) * scale.x;

    float xz2 = rot.x * z2;
    float wy2 = rot.w * y2;
    m._31 = (xz2 + wy2) * scale.z;
    m._13 = (xz2 - wy2) * scale.x;

    m._14 = 0.0f;
    m._24 = 0.0f;
    m._34 = 0.0f;
    m._44 = 1.0f;

    return m;
}

D3DMatrix Utilities::MatrixMultiplication(D3DMatrix pM1, D3DMatrix pM2) {
    D3DMatrix pOut = {
        pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41,
        pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42,
        pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43,
        pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44,
        pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41,
        pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42,
        pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43,
        pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44,
        pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41,
        pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42,
        pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43,
        pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44,
        pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41,
        pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42,
        pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43,
        pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44
    };

    return pOut;
}
Vector3 Utilities::GetBoneWorldPosition(ULONG actorAddv, ULONG boneAddv) {
    FTTransform2_t bone = g_Utilities->Driver.ReadVirtualMemory<FTTransform2_t>(boneAddv);
    FTTransform2_t actor = g_Utilities->Driver.ReadVirtualMemory<FTTransform2_t>(actorAddv);
    D3DMatrix boneMatrix = ToMatrixWithScale(bone.Translation, bone.Scale3D, bone.Rotation);
    D3DMatrix componentToWorldMatrix = ToMatrixWithScale(actor.Translation, actor.Scale3D, actor.Rotation);
    D3DMatrix newMatrix = MatrixMultiplication(boneMatrix, componentToWorldMatrix);
    return Vector3(newMatrix._41, newMatrix._42, newMatrix._43);

}
#pragma endregion




