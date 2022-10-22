
#include "../pch.h"
#include "../api/KeyAuth.hpp"
#include "../termcolor.hpp"
//#include "../Authy/Swifty.hpp"
#include "ShObjIdl.h"
#include <openssl/MD5.h>
#include <chrono>
#include <string>

using namespace authsp;
////
std::string name = XorStr("RYZEN HAX PRO"); // RZ API
std::string ownerid = XorStr("YZDKLlcdYt");
std::string secret = XorStr("bbc5b5b3ee71e1a755fe09f342ca1444775106e689cae99d9a2528627d8ca34b");
std::string version = XorStr("1.0");


//std::string name = XorStr("RYZEN HACK"); //SM API
//std::string ownerid = XorStr("9OQoqUg1tC");
//std::string secret = XorStr("8f398647f95b88e768b6c702ab317d949698696cc95d6c2b8c6437172150bc7b");
//std::string version = XorStr("1.0");

api authspApp(name, ownerid, secret, version);

void initall()
{
    int ProcessId = ProcManager::GetRightProcId();
    g_Utilities->Driver.ProcessId = ProcessId;

    if (!g_Utilities->Driver.ProcessId)
    {
        g_Utilities->MessageTimeout(L"Emulator Not Found Please Make Sure Emulator Is Running", MB_ICONERROR);
        exit(1);
    }
    g_Utilities->Driver.LoadDriver();
    if (g_Utilities->Driver.hDriver == INVALID_HANDLE_VALUE)
    {
        g_Utilities->MessageTimeout(L"Load Driver Error", MB_ICONERROR);
        exit(1);
    }

    if (!g_Utilities->Driver.AttachProcess()) {

        g_Utilities->MessageTimeout(L"Internal Error Code X2", MB_ICONERROR);
        exit(1);
    }
    g_MainForm->init();
}

std::string GetClipboardText()
{
    if (!OpenClipboard(nullptr))
    {
        return "";
    }

    // Get handle of clipboard object for ANSI text
    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == nullptr)
    {
        return "";
    }

    // Lock the handle to get the actual text pointer
    char* pszText = static_cast<char*>(GlobalLock(hData));
    if (pszText == nullptr)
    {
        return "";
    }

    // Save text in a string class instance
    std::string text(pszText);

    // Release the lock
    GlobalUnlock(hData);

    // Release the clipboard
    CloseClipboard();

    return text;
}
bool SaveKey(std::string Keystr)
{
    try
    {
        std::ofstream MyFile(XorStr("C:\\RYZEN_Hax.lic"));
        if (!MyFile.is_open())
            return false;
        MyFile << Keystr;
        MyFile.close();
        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }


}
bool FileExist(std::string Path)
{
    try
    {

        std::string line;
        std::ifstream myfile(Path);
        if (myfile.is_open())
        {
            myfile.close();
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (const std::exception&)
    {
        return false;
    }
}
bool DeleteFiles(std::string Path)
{
    try
    {
        std::remove(Path.c_str());
        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }
}
std::string GetKey()
{
    try
    {
        std::string line;
        std::ifstream myfile(XorStr("C:\\RYZEN_Hax.lic"));
        if (!myfile.is_open())
            return "";

        getline(myfile, line);
        myfile.close();
        return line;
    }
    catch (const std::exception&)
    {
        return "";
    }


}
//c_auth::api auth_instance(c_xor("Vip Hack"), c_xor("1.0"), c_xor("x59w3bao607sxfn1c1oc2tffo9eyjnu4"), c_xor("969375")); //RYZEN

std::string GetUserLicense()
{
    std::string EnteredKey = GetKey();
    if (EnteredKey == "")
    {
        EnteredKey = GetClipboardText();
    }
    return EnteredKey;
}
bool PreventMultipleInstances()
{
    // Declare variables
    CString sMutexName = "Gamecht";
    auto m_hMutex = CreateMutex(NULL, FALSE, sMutexName);
    switch (GetLastError())
    {
        CloseHandle(m_hMutex);
    case ERROR_SUCCESS:
        break;

    case ERROR_ALREADY_EXISTS:
        return false;

    default:
        return false;
    }

    // Succeeded
    return true;
}

#pragma region Extra
//bool login = false;
inline bool exists1(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}


struct slowly_printing_string {
    std::string data;
    long int delay;
};


std::ostream& operator<<(std::ostream& out, const slowly_printing_string& s) {
    for (const auto& c : s.data) {
        out << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(s.delay));
    }
    return out;
}
BOOL WINAPI FreeConsole(void);

bool login() {
    static char str0[128] = "";
    std::string token = "";
    bool login = false;
    if (exists1(("C:\\RYZENHAX.lic")))
    {
        std::ifstream MyFile(("C:\\RYZENHAX.lic"));
        getline(MyFile, token);
        MyFile.close();
        if (!token.empty())
            strcpy(str0, token.c_str());
        login = authspApp.license(token);
        // expr = auth_instance.user_data.expires.substr(0, 10);
        std::cout << termcolor::bright_yellow << "License : " + token << std::endl;
        std::cout << termcolor::bright_green << slowly_printing_string{ "Successfully logged in !!! \n" ,20 };
        time_t rawtime = mktime(&authspApp.user_data.expiry);
        struct tm* timeinfo;
        timeinfo = localtime(&rawtime);
        std::cout << termcolor::bright_yellow << slowly_printing_string{ "Expires on : " ,20 };
        std::cout << termcolor::bright_yellow << (XorStr(" %s").c_str(), asctime(timeinfo));
        g_Settings::Expiretb = (XorStr(" %s").c_str(), asctime(timeinfo));
        std::cout << termcolor::white << ("\n");
        Sleep(1000);
       // FreeConsole();
       
        if (!login) {
            AllocConsole();
            FILE* fDummy;
            freopen_s(&fDummy, "CONOUT$", "w+", stdout);
            freopen_s(&fDummy, "CONIN$", "w+", stdin);
            freopen_s(&fDummy, "CONOUT$", "w", stderr);
            std::cout << slowly_printing_string{ "Invalid Key " ,20 };
            Sleep(500);
            std::cout << (". ");
            Sleep(500);
            std::cout << (". ");
            Sleep(500);
            std::cout << (". ");
            system("del C:\\RYZENHAX.lic");
            Sleep(500);
            system(("cls"));
        }
        else if (login)
            return true;
    }
    else {
        AllocConsole();
        FILE* fDummy;
        freopen_s(&fDummy, "CONOUT$", "w+", stdout);
        freopen_s(&fDummy, "CONIN$", "w+", stdin);
        freopen_s(&fDummy, "CONOUT$", "w", stderr);
    again:
        std::cout << slowly_printing_string{ "Please Enter Your Key\n" ,20 };
        std::cin >> token;
        login = authspApp.license(token);
        if (!login) {
            std::cout << ("Invalid Key");
            Sleep(500);
            std::cout << (". ");
            Sleep(500);
            std::cout << (". ");
            Sleep(500);
            std::cout << (". ");
            Sleep(500);
            system(("cls"));
            goto again;
        }
        else if (login) {
            std::cout << termcolor::green << slowly_printing_string{ "Logged in Successfully \n" ,20 };
            time_t rawtime = mktime(&authspApp.user_data.expiry);
            struct tm* timeinfo;
            timeinfo = localtime(&rawtime);
            std::cout << termcolor::bright_yellow << slowly_printing_string{ "Valid Till : " ,20 };
            std::cout << termcolor::bright_yellow << (XorStr(" %s").c_str(), asctime(timeinfo));
            g_Settings::Expiretb = (XorStr(" %s").c_str(), asctime(timeinfo));
            Sleep(1000);
            std::ofstream MyFile(("C:\\RYZENHAX.lic"));
            MyFile << token;
            MyFile.close();
           // FreeConsole();
            return true;
        }
    }
    return false;
}


char* calculate_file_md5(const char* filename) {
    unsigned char c[MD5_DIGEST_LENGTH];
    int i;
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];
    char* filemd5 = (char*)malloc(33 * sizeof(char));

    FILE* inFile = fopen(filename, "rb");
    if (inFile == NULL) {
        perror(filename);
        return 0;
    }

    MD5_Init(&mdContext);

    while ((bytes = fread(data, 1, 1024, inFile)) != 0)

        MD5_Update(&mdContext, data, bytes);

    MD5_Final(c, &mdContext);

    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&filemd5[i * 2], "%02x", (unsigned int)c[i]);
    }

    fclose(inFile);
    return filemd5;
}


void md5hashcheck()
{
    char* new_md5 = calculate_file_md5("RYZEN HAX VIP.exe");

    std::string integritycheck = authspApp.var(XorStr("rzmd5hashax"));
    if (integritycheck != new_md5)
    {
        std::cout << termcolor::bright_yellow << "Program Hash Mismatch Exiting";

        //std::cout << printing_string{ ". . . . . . .",20 };
        Sleep(3000);
        exit(69);
    }
}


int main()
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
   
  /*  ShellExecute(0, 0, L"https://t.me/RYZENHAX", 0, 0, SW_SHOW);
    ShellExecute(0, 0, L"https://discord.gg/aUrmcETn7s", 0, 0, SW_SHOW);*/
    //authspApp.init();
    //if (!login())
    //    exit(0);

   // md5hashcheck();
    FreeConsole();
    initall();
    //if (!PreventMultipleInstances())
    //{
    //    exit(1);
    //    ExitProcess(1);
    //}
    //else
    //{
    //    // auth_instance.init();
    //   

    //    //std::string  License = GetUserLicense();
    //    //if (License.empty())
    //    //{
    //    //    g_Utilities->MessageTimeout(L"Please Enter Key", MB_ICONERROR);
    //    //    exit(1);
    //    //}

    //    //if (authspApp.license(License))
    //    //{

    //    //    //g_Settings::Expiretb =  auth_instance.user_data.expires;
    //    //    time_t rawtime = mktime(&authspApp.user_data.expiry);
    //    //    struct tm* timeinfo;
    //    //    timeinfo = localtime(&rawtime);
    //    //   // std::cout << ("Valid Till : ");
    //    //    g_Settings::Expiretb = (XorStr(" %s").c_str(), asctime(timeinfo));
    //    //    SaveKey(License);
    //    //    initall();
    //    //}
    //    //else
    //    //{
    //    //    g_Utilities->MessageTimeout(L"Please Enter Valid Key", MB_ICONERROR);
    //    //    exit(1);

    //    //}

    //   
    //}


    //return 0;
}

