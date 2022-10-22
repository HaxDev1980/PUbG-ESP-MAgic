
#include "Overlay.hpp"
//#include "DX11/DX11.h"
#include <thread>
#include "ShObjIdl.h"
#include "../Main_Esp/Settings.h"
#include <nlohmann/json.hpp>

//#include "../DX11/DX11.h"
using namespace g_Settings;
ID3DXLine* pLine;
#define PI 3.14159265

int m_Width = 0;
int m_Height = 0;
IDirect3DDevice9* D3DDevice;
IDirect3D9* D3D;
HWND DrawWindow;
D3DPRESENT_PARAMETERS D3DParams;
ImDrawList* ImgdrawList;
std::string AimAt[] = { "Head      ", "Body     ", "Pelvis     " };
int scrWidth = GetSystemMetrics(SM_CXSCREEN);
int scrHeight = GetSystemMetrics(SM_CYSCREEN);
KernelHelper Driver1;
Vehicle vhi;

Overlay::Overlay::Overlay()
{
	D3DDevice = nullptr;
	D3D = nullptr;
	ImgdrawList = nullptr;
	DrawWindow = NULL;
	D3DParams = {};
}
Overlay::Overlay::~Overlay() {}


#pragma region MenuRes
ImFont* Font12 = NULL;
ImFont* Font14 = NULL;
ImFont* Font16 = NULL;
ImFont* Font18 = NULL;
ImFont* Font22 = NULL;
ImFont* Font24 = NULL;
ImFont* ItemFont = NULL;
ImFont* PlayerNameFont = NULL;
ImFont* Icons = NULL;
ImFont* special;

static int iPage = 0;
bool Close = false;
int windowstate = 0;


ImColor PlayerLineColor(255, 255, 255);
ImColor PlayerBoxColor(255, 255, 255);
ImColor PlayerBoneColor(255, 255, 255);
ImColor AimLineColor(255, 0, 0);


#pragma endregion


#pragma region OverlaySetup
void ResetDevice()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	HRESULT hr = D3DDevice->Reset(&D3DParams);
	if (hr == D3DERR_INVALIDCALL)
		IM_ASSERT(0);
	ImGui_ImplDX9_CreateDeviceObjects();
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (wParam != SIZE_MINIMIZED)
		{
			if (D3DDevice != NULL)
			{
				D3DParams.BackBufferWidth = LOWORD(lParam);
				D3DParams.BackBufferHeight = HIWORD(lParam);
				ResetDevice();
			}

		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_CLOSE:
		ExitProcess(0);
		exit(0);
		return 0;
	case WM_DESTROY:
		ExitProcess(0);
		exit(0);
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}//BluetoothNotificationAreaIconWindowClass
bool Overlay::Overlay::OverlayWndCreator()
{

	WNDCLASSEX overlayWindowClass;
	ZeroMemory(&overlayWindowClass, sizeof(WNDCLASSEX));
	overlayWindowClass.cbClsExtra = NULL;
	overlayWindowClass.cbWndExtra = NULL;
	overlayWindowClass.cbSize = sizeof(WNDCLASSEX);
	overlayWindowClass.style = CS_HREDRAW | CS_VREDRAW;
	overlayWindowClass.lpfnWndProc = WndProc;
	overlayWindowClass.hInstance = NULL;
	overlayWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	overlayWindowClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	overlayWindowClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
	overlayWindowClass.hbrBackground = (HBRUSH)RGB(0, 0, 0);
	overlayWindowClass.lpszClassName = "tooltips_class32";
	overlayWindowClass.lpszMenuName = "Default IME";

	RegisterClassEx(&overlayWindowClass);

	HWND hwndOverlayWindow = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_NOACTIVATE, overlayWindowClass.lpszClassName, overlayWindowClass.lpszMenuName, WS_POPUP, 1, 1, 1, 1, 0, 0, 0, 0);

	SetMenu(hwndOverlayWindow, NULL);
	MARGINS margin = { -1, -1, -1, -1 };
	DwmExtendFrameIntoClientArea(hwndOverlayWindow, &margin);
	DrawWindow = hwndOverlayWindow;
	return hwndOverlayWindow != NULL;

}
void CustomImStyle()
{
	ImGui::SetColorEditOptions(ImGuiColorEditFlags_HEX);

	/* Setup Style */
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;
	colors[ImGuiCol_Button] = ImVec4(0.137f, 0.137f, 0.160f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.2f, 0.2f, 0.231f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.2f, 0.2f, 0.231f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.729f, 0.0F, 0.0F, 1.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.137f, 0.137f, 0.160f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2f, 0.2f, 0.231f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.862f, 0.862f, 0.862f, .50f);
	style.Alpha = 1.f;
	style.WindowPadding = ImVec2(8, 8);
	style.WindowMinSize = ImVec2(32, 32);
	style.WindowRounding = 0.0f;
	style.WindowTitleAlign = ImVec2(0.5f, 1.5f);
	style.ChildRounding = 0.0f;
	style.FramePadding = ImVec2(4, 3);
	style.FrameRounding = 0.0f; //2.0
	style.ItemSpacing = ImVec2(8, 4);
	style.ItemInnerSpacing = ImVec2(4, 4);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 21.0f;
	style.ColumnsMinSpacing = 3.0f;
	style.ScrollbarSize = 6.0f;
	style.ScrollbarRounding = 16.0f;
	style.GrabMinSize = 0.1f;
	style.GrabRounding = 16.0f;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.DisplayWindowPadding = ImVec2(22, 22);
	style.DisplaySafeAreaPadding = ImVec2(4, 4);
	style.AntiAliasedLines = true;
	style.CurveTessellationTol = 1.25f;

	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = nullptr;
	io.LogFilename = nullptr;

	/*Font16 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arialbd.ttf", 14.0f);
	Font12 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arialbd.ttf", 12.0f);*/

	/*Font16 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeui.ttf", 16.0f);
	Font12 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeui.ttf", 14.0f);*/

	Font16 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Tahoma.ttf", 16.0f);
	Font12 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Tahoma.ttf", 12.0f);

	//Font16 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\calibrib.ttf", 16.0f);
	//Font12 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\calibrib.ttf", 12.0f);

	//Font14 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Tahoma.ttf", 14.0f);
	//Font18 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Tahoma.ttf", 18.0f);
	//Font22 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Tahoma.ttf", 18.0f);
	//Font24 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Tahoma.ttf", 24.0f);
	//PlayerNameFont = Font24;
}

bool Overlay::Overlay::InitiateD3D(unsigned int X, unsigned int Y)
{
	HRESULT hr;
	if ((D3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return false;

	/* Set Params */
	D3DParams = { 0 };
	D3DParams.Windowed = true;
	D3DParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	D3DParams.hDeviceWindow = DrawWindow;
	D3DParams.BackBufferFormat = D3DFMT_A8R8G8B8;
	D3DParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	D3DParams.AutoDepthStencilFormat = D3DFMT_D16;
	D3DParams.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	D3DParams.EnableAutoDepthStencil = TRUE;
	D3DParams.MultiSampleQuality = DEFAULT_QUALITY;
	D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, DrawWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &D3DParams, &D3DDevice);
	if (D3DDevice == nullptr)
		return false;

	D3DXCreateLine(D3DDevice, &pLine);
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	CustomImStyle();;
	ImGui_ImplWin32_Init(DrawWindow);
	ImGui_ImplDX9_Init(D3DDevice);


	return true;
}
void ChangeWindowprop(bool Click, HWND ownd)
{
	ITaskbarList* pTaskList = NULL;
	HRESULT initRet = CoInitialize(NULL);
	HRESULT createRet = CoCreateInstance(CLSID_TaskbarList,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_ITaskbarList,
		(LPVOID*)&pTaskList);

	if (createRet == S_OK)
	{

		pTaskList->DeleteTab(ownd);

		pTaskList->Release();
	}
	long style = GetWindowLong(ownd, GWL_EXSTYLE);
	if (Click) {
		style &= ~WS_EX_LAYERED;
		SetWindowLong(ownd,
			GWL_EXSTYLE, style);
		SetForegroundWindow(ownd);
		windowstate = 1;
	}
	else {
		style |= WS_EX_LAYERED;
		SetWindowLong(ownd, GWL_EXSTYLE, style);
		windowstate = 0;
	}
	SetLayeredWindowAttributes(ownd, 0, (255 * 100) / 100, LWA_ALPHA);
}
void Overlay::Overlay::CleanupDeviceD3D()
{
	if (D3DDevice) { D3DDevice->Release(); D3DDevice = NULL; }
	if (D3D) { D3D->Release(); D3D = NULL; }
}

void Overlay::Overlay::ClearScreen()
{
	D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
}

void Overlay::Overlay::Shutdown()
{

}


void Overlay::Overlay::SetRenderStates()
{
	if (ShowMenu)
	{

		D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(50, 0, 0, 0), 1.0f, 0);
	}
	else
	{

		D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
	}
	D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
	D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	D3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	D3DDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
	D3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	D3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

	D3DDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	D3DDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, TRUE);
	D3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	D3DDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);

	//device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
	//device->SetRenderState(D3DRS_ANTIALIASEDLINEENABLE, TRUE);

	D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	D3DDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	D3DDevice->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE);
	D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	D3DDevice->SetRenderState(D3DRS_SRCBLENDALPHA, D3DBLEND_INVDESTALPHA);
	D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	D3DDevice->SetRenderState(D3DRS_DESTBLENDALPHA, D3DBLEND_ONE);

	D3DDevice->SetRenderState(D3DRS_SRGBWRITEENABLE, FALSE);
	D3DDevice->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_RED | D3DCOLORWRITEENABLE_GREEN |
		D3DCOLORWRITEENABLE_BLUE | D3DCOLORWRITEENABLE_ALPHA);
}
#pragma endregion



#pragma region MenuDrawing
void SafeExit()
{
	EnableBulletTrack = false;
	EnableNoRecoil = false;
	EnableInstantHit = false;
	Sleep(500);
	exit(1);
	ExitProcess(1);

}

void SameLineDummy(int xSpacing)
{
	ImGui::SameLine(); ImGui::Dummy(ImVec2(xSpacing, 0)); ImGui::SameLine();
}

void RenderButtons()
{
	SameLineDummy(30);
	if (iPage == 0)
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.729f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
		if (ImGui::Button("Visuals", ImVec2(85, 0)))
			iPage = 0;
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();

	}
	else
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.137f, 0.137f, 0.160f, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
		if (ImGui::Button("Visuals", ImVec2(85, 0)))
			iPage = 0;
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
	}
	ImGui::SameLine();
	if (iPage == 1)
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.729f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
		if (ImGui::Button("Aimbot", ImVec2(85, 0)))
			iPage = 1;
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
	}
	else
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.137f, 0.137f, 0.160f, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
		if (ImGui::Button("Aimbot", ImVec2(85, 0)))
			iPage = 1;
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
	}
	ImGui::SameLine();
	if (iPage == 2)
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.729f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
		if (ImGui::Button("Memory", ImVec2(85, 0)))
			iPage = 2;
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();

	}
	else
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.137f, 0.137f, 0.160f, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
		if (ImGui::Button("Memory", ImVec2(85, 0)))
			iPage = 2;
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
	}
	ImGui::SameLine();
	if (iPage == 3)
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.729f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
		if (ImGui::Button("Others", ImVec2(85, 0)))
			iPage = 3;
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();



	}
	else
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.137f, 0.137f, 0.160f, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
		if (ImGui::Button("Others", ImVec2(85, 0)))
			iPage = 3;
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
	}
}

void Bar()
{

	ImGui::Spacing(); ImGui::Spacing();
	ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();

}


void DrawMenu() {


	std::string expiretimed = "Expire Time: ";
	std::string expiretimea = g_Settings::Expiretb;

	if (!expiretimea.empty())
	{
		expiretimed.append(expiretimea);
	}
	static bool DoOnce = true;
	if (DoOnce)
	{
		ImGui::SetNextWindowPos(ImVec2(20, 20));
		ImGui::SetNextWindowSize(ImVec2(496, 301));
		DoOnce = false;

	}

	// Style
	auto& style = ImGui::GetStyle();

	float WidthM = 396;
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect);

	auto x = float(screen_rect.right - WidthM) / 2.5f;
	auto y = float(screen_rect.bottom - WidthM) / 2.f;
	ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
	ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
	ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
	ImGui::SetNextWindowBgAlpha(0.90f);

	// Menu
	//ImGui::SetNextWindowPos(ImVec2(20, 0));
	std::string tmp1;
	std::string tmp2;
	std::string tmp3;
	std::string tmp4;
	std::string tmp5;
	static const auto dwFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize;

	if (ImGui::Begin("MainMen", 0, dwFlags)) {

		ImGui::Spacing();
		ImGui::PushFont(Font22);
		SameLineDummy(150);
		ImGui::Text("WELCOME TO PC GAMER ");
		ImGui::SetCursorPosX(8);
		ImGui::SetCursorPosY(32);
		ImGui::BeginChild("Main", ImVec2(480, 0), true);
		{
			ImGui::PushFont(Font18);
			RenderButtons();

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing(); ImGui::Spacing();
			if (iPage == 0)
			{
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Spacing();
				SameLineDummy(1);
				ImGui::Checkbox("Player Box", &PlayerBox);
				SameLineDummy(12);
				ImGui::Checkbox("Player Line", &PlayerLines);
				SameLineDummy(12);
				ImGui::ColorEdit4("pName", (float*)&Colors::playerline, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				SameLineDummy(25);
				ImGui::Checkbox("Player Bones", &PlayerSkeleton);

				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Spacing();
				SameLineDummy(1);
				ImGui::Checkbox("Item Esp", &ShowItems);
				ImGui::SameLine();


				SameLineDummy(24);
				ImGui::Checkbox("Vehicle Esp", &vehicleEsp);
				SameLineDummy(8);
				ImGui::ColorEdit4("Vehicle Esp", (float*)&weapon::vehicle, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				SameLineDummy(25);
				ImGui::Checkbox("LootBox Item", &LootBoxItems);
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Spacing();
				SameLineDummy(1);
				ImGui::Checkbox("Grenade Warning", &GrenadeAlert);
				SameLineDummy(155);
				ImGui::Checkbox("Enemy Weapon", &HandGun);
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Spacing();
				SameLineDummy(1);
				ImGui::Checkbox("Bot Line", &g_Settings::BotLines);
				SameLineDummy(12);
				ImGui::ColorEdit4("bName", (float*)&Colors::botline, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				SameLineDummy(158);
				ImGui::Checkbox("Vehicle Energy", &vehicleHealth);
				ImGui::Spacing();
				ImGui::Separator();
				ImGui::Spacing();
				ImGui::Spacing();
				SameLineDummy(30);
				if (iPage == 4)
				{
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.729f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
					if (ImGui::Button("Weapon", ImVec2(85, 0)))
						iPage = 4;
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();

				}
				else
				{
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.137f, 0.137f, 0.160f, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
					if (ImGui::Button("Weapon", ImVec2(85, 0)))
						iPage = 4;
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
				}
				ImGui::SameLine();
				if (iPage == 5)
				{
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.729f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
					if (ImGui::Button("Scope Item", ImVec2(85, 0)))
						iPage = 5;
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();

				}
				else
				{
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.137f, 0.137f, 0.160f, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
					if (ImGui::Button("Scope|Health", ImVec2(85, 0)))
						iPage = 5;
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
				}

				ImGui::SameLine();
				if (iPage == 6)
				{
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.729f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
					if (ImGui::Button("Attachment", ImVec2(85, 0)))
						iPage = 6;
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();

				}
				else
				{
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.137f, 0.137f, 0.160f, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
					if (ImGui::Button("Attachment", ImVec2(85, 0)))
						iPage = 6;
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
				}

				ImGui::SameLine();
				if (iPage == 7)
				{
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.729f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
					if (ImGui::Button("Bomb Items", ImVec2(85, 0)))
						iPage = 7;
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();

				}
				else
				{
					ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.137f, 0.137f, 0.160f, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.829f, 0.0F, 0.0F, 1.00f));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.629f, 0.0F, 0.0F, 1.00f));
					if (ImGui::Button("Bomb Items", ImVec2(85, 0)))
						iPage = 7;
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
					ImGui::PopStyleColor();
				}


				ImGui::SetCursorPosY(210);
				Bar();
				ImGui::SetCursorPosX(20);
				ImGui::Text(expiretimed.c_str());
			}

			else if (iPage == 1)
			{
				ImGui::Spacing();
				SameLineDummy(10);
				ImGui::Checkbox("Bullet Track", &EnableBulletTrack);
				SameLineDummy(30);
				ImGui::Checkbox("Skip Knock", &SkipKnock);
				SameLineDummy(30);
				ImGui::Checkbox("Aim Line", &AimLine);
				ImGui::Spacing();
				Bar();
				ImGui::PushItemWidth(144);
				ImGui::Text("                Aim Priority                            Aim Bone");
				ImGui::SetCursorPosX(55);
				tmp1 = "Closest Crosshair";
				tmp2 = "Closest Distance";
				const char* SelectionType[] = { tmp1.c_str() , tmp2.c_str() };
				if (ImGui::Combo("##   ", &g_Settings::iAimSelection, SelectionType, IM_ARRAYSIZE(SelectionType)))
					g_Settings::bUpdateSettings = true;
				tmp1.clear();
				tmp2.clear();
				ImGui::SameLine();
				ImGui::PushItemWidth(144);
				ImGui::SetCursorPosX(235 + 16);
				tmp1 = "Head";
				tmp2 = "Body";
				const char* BoneType[] = { tmp1.c_str() , tmp2.c_str() };
				if (ImGui::Combo("####      ", &g_Settings::iAimBone, BoneType, IM_ARRAYSIZE(BoneType)))
					g_Settings::bUpdateSettings = true;
				tmp1.clear();
				tmp2.clear();
			}
			else if (iPage == 4)
			{
				ImGui::Text("Assualt Riffles");
				SameLineDummy(1);
				ImGui::Checkbox("Weapon", &impitems);
				ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
				SameLineDummy(1);
				ImGui::Checkbox("M416", &g_Settings::Esp_Item_M416);
				SameLineDummy(12);
				ImGui::ColorEdit4("M416", (float*)&weapon::m416, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				SameLineDummy(12);
				ImGui::Checkbox("AKM", &g_Settings::Esp_Item_AKM);
				SameLineDummy(24);
				ImGui::ColorEdit4("AKM", (float*)&weapon::AKM, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				SameLineDummy(25);
				ImGui::Checkbox("SCAR-L", &g_Settings::Esp_Item_SCARL);
				SameLineDummy(12);
				ImGui::ColorEdit4("SCAR", (float*)&weapon::scarl, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Spacing();
				SameLineDummy(1);
				ImGui::Checkbox("M762", &g_Settings::Esp_Item_M762);
				SameLineDummy(12);
				ImGui::ColorEdit4("M762", (float*)&weapon::m762, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				SameLineDummy(12);
				ImGui::Checkbox("DP28", &g_Settings::Esp_Item_DP28);
				SameLineDummy(21);
				ImGui::ColorEdit4("DP28", (float*)&weapon::DP, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				SameLineDummy(22);
				ImGui::Checkbox("M16A4", &g_Settings::Esp_Item_M16A4);
				SameLineDummy(22);
				ImGui::ColorEdit4("M16A4", (float*)&weapon::m16A4, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::Spacing();
				ImGui::Text("Sniper  Riffles");
				ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
				SameLineDummy(1);
				ImGui::Checkbox("AWM", &g_Settings::Esp_Item_Awm);
				SameLineDummy(12);
				ImGui::ColorEdit4("AMW", (float*)&weapon::AWM, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				SameLineDummy(12);
				ImGui::Checkbox("M24", &g_Settings::Esp_Item_M24);
				SameLineDummy(27);
				ImGui::ColorEdit4("M24", (float*)&weapon::M24, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				SameLineDummy(25);
				ImGui::Checkbox("KAR98", &g_Settings::Esp_Item_Kar98k);
				SameLineDummy(20);
				ImGui::ColorEdit4("kar98", (float*)&weapon::kar98, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Text("Special Items");
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::SetCursorPos({ 25.f,220.0f });
				ImGui::Checkbox("Flare Gun", &g_Settings::Esp_Item_FlareGun);
				ImGui::SetCursorPos({ 255.f,220.0f });
				ImGui::ColorEdit4("Flare", (float*)&weapon::Flaregun, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,250.0f });
				ImGui::Checkbox("Flare", &g_Settings::Esp_Item_Flare);
				ImGui::SetCursorPos({ 255.f,250.0f });
				ImGui::ColorEdit4("Flareg", (float*)&weapon::Flare, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,280.0f });
				ImGui::Checkbox("AirDrop", &g_Settings::airdrop);
				ImGui::SetCursorPos({ 255.f,280.0f });
				ImGui::ColorEdit4("Airdrop", (float*)&weapon::Airdrop, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,310.0f });
				ImGui::Checkbox("Bag Lv.3", &g_Settings::Esp_Item_Bag3);
				ImGui::SetCursorPos({ 255.f,310.0f });
				ImGui::ColorEdit4("Bag Lv.3", (float*)&weapon::Bag3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,340.0f });
				ImGui::Checkbox("Helmet 3", &g_Settings::Esp_Item_Helmet3);
				ImGui::SetCursorPos({ 255.f,340.0f });
				ImGui::ColorEdit4("Helmet 3", (float*)&weapon::Helmet3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,370.0f });
				ImGui::Checkbox("AWM immo", &g_Settings::Esp_Item_Awmimo);
				ImGui::SetCursorPos({ 255.f,370.0f });
				ImGui::ColorEdit4("AWM immo", (float*)&weapon::AWMimmo, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,400.0f });
				ImGui::Checkbox("AirDrop-lists", &g_Settings::airdropitem);
				ImGui::SetCursorPos({ 255.f,400.0f });
				ImGui::ColorEdit4("air-Boxi ", (float*)&Colors::airdropitem, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,430.0f });
				ImGui::Checkbox("Armour Lv.3", &g_Settings::Esp_Item_Armor3);
				ImGui::SetCursorPos({ 255.f,430.0f });
				ImGui::ColorEdit4("762mm", (float*)&weapon::Armor3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Text("All Items");
				ImGui::SetCursorPos({ 25.f,490.0f });
				ImGui::Checkbox("Helmet 1", &g_Settings::Esp_Item_Helmet1);
				ImGui::SetCursorPos({ 255.f,490.0f });
				ImGui::ColorEdit4("Helmet 1", (float*)&weapon::Helmet1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,520.0f });
				ImGui::Checkbox("Helmet 2", &g_Settings::Esp_Item_Helmet2);
				ImGui::SetCursorPos({ 255.f,520.0f });
				ImGui::ColorEdit4("Helmet 2", (float*)&weapon::Helmet2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,550.0f });
				ImGui::Checkbox("Bag 1", &g_Settings::Esp_Item_Bag1);
				ImGui::SetCursorPos({ 255.f,550.0f });
				ImGui::ColorEdit4("Bag 1", (float*)&weapon::Bag1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,580.0f });
				ImGui::Checkbox("Bag 2", &g_Settings::Esp_Item_Bag2);
				ImGui::SetCursorPos({ 255.f,580.0f });
				ImGui::ColorEdit4("Bag 2", (float*)&weapon::Bag2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,610.0f });
				ImGui::Checkbox("Armor 1", &g_Settings::Esp_Item_Armor1);
				ImGui::SetCursorPos({ 255.f,610.0f });
				ImGui::ColorEdit4("Armor 1", (float*)&weapon::Armor1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,640.0f });
				ImGui::Checkbox("Armor 2", &g_Settings::Esp_Item_Armor2);
				ImGui::SetCursorPos({ 255.f,640.0f });
				ImGui::ColorEdit4("Armor 2", (float*)&weapon::Armor2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,670.0f });
				ImGui::Checkbox("Armor 3", &g_Settings::Esp_Item_Armor3);
				ImGui::SetCursorPos({ 255.f,670.0f });
				ImGui::ColorEdit4("Armor 3", (float*)&weapon::Armor3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,700.0f });
				ImGui::Checkbox("G36C", &g_Settings::Esp_Item_G36C);
				ImGui::SetCursorPos({ 255.f,700.0f });
				ImGui::ColorEdit4("G36C", (float*)&weapon::G36C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,730.0f });
				ImGui::Checkbox("QBZ", &g_Settings::Esp_Item_QBZ);
				ImGui::SetCursorPos({ 255.f,730.0f });
				ImGui::ColorEdit4("QBZ", (float*)&weapon::QBZ, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,760.0f });
				ImGui::Checkbox("QBU", &g_Settings::Esp_Item_QBU);
				ImGui::SetCursorPos({ 255.f,760.0f });
				ImGui::ColorEdit4("QBU", (float*)&weapon::QBU, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,790.0f });
				ImGui::Checkbox("SLR", &g_Settings::Esp_Item_SLR);
				ImGui::SetCursorPos({ 255.f,790.0f });
				ImGui::ColorEdit4("SLR", (float*)&weapon::SLR, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,820.0f });
				ImGui::Checkbox("SKS", &g_Settings::Esp_Item_SKS);
				ImGui::SetCursorPos({ 255.f,820.0f });
				ImGui::ColorEdit4("SKS", (float*)&weapon::SKS, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,850.0f });
				ImGui::Checkbox("Mini14", &g_Settings::Esp_Item_Mini14);
				ImGui::SetCursorPos({ 255.f,850.0f });
				ImGui::ColorEdit4("Mini14", (float*)&weapon::Mini14, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,880.0f });
				ImGui::Checkbox("PP19", &g_Settings::Esp_Item_PP19);
				ImGui::SetCursorPos({ 255.f,880.0f });
				ImGui::ColorEdit4("PP19", (float*)&weapon::PP19, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,910.0f });
				ImGui::Checkbox("Tommy Gun", &g_Settings::Esp_Item_TommyGun);
				ImGui::SetCursorPos({ 255.f,910.0f });
				ImGui::ColorEdit4("Tommy Gun", (float*)&weapon::TommyGun, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,940.0f });
				ImGui::Checkbox("MP5K", &g_Settings::Esp_Item_MP5K);
				ImGui::SetCursorPos({ 255.f,940.0f });
				ImGui::ColorEdit4("MP5K", (float*)&weapon::MP5K, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,970.0f });
				ImGui::Checkbox("UMP9", &g_Settings::Esp_Item_UMP9);
				ImGui::SetCursorPos({ 255.f,970.0f });
				ImGui::ColorEdit4("UMP9", (float*)&weapon::UMP9, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,1000.0f });
				ImGui::Checkbox("Vector", &g_Settings::Esp_Item_Vector);
				ImGui::SetCursorPos({ 255.f,1000.0f });
				ImGui::ColorEdit4("Vector", (float*)&weapon::Vector, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,1030.0f });
				ImGui::Checkbox("Uzi", &g_Settings::Esp_Item_Uzi);
				ImGui::SetCursorPos({ 255.f,1030.0f });
				ImGui::ColorEdit4("Uzi", (float*)&weapon::Uzi, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,1060.0f });
				ImGui::Checkbox("7.62mm", &g_Settings::Esp_Item_762mm);
				ImGui::SetCursorPos({ 255.f,1060.0f });
				ImGui::ColorEdit4("762mm", (float*)&weapon::Ammo762, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,1090.0f });
				ImGui::Checkbox("5.56mm", &g_Settings::Esp_Item_556mm);
				ImGui::SetCursorPos({ 255.f,1090.0f });
				ImGui::ColorEdit4("5.56mm", (float*)&weapon::Ammo556, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1120.0f });
				ImGui::Checkbox("9mm", &g_Settings::Esp_Item_9mm);
				ImGui::SetCursorPos({ 255.f,1120.0f });
				ImGui::ColorEdit4("9mm", (float*)&weapon::Ammo9mm, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,1150.0f });
				ImGui::Checkbox("45ACP", &g_Settings::Esp_Item_45ACP);
				ImGui::SetCursorPos({ 255.f,1150.0f });
				ImGui::ColorEdit4("45ACP", (float*)&weapon::ACP45, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,1180.0f });
				ImGui::Checkbox("Holo", &g_Settings::Esp_Item_Holo);
				ImGui::SetCursorPos({ 255.f,1180.0f });
				ImGui::ColorEdit4("Holo", (float*)&weapon::Holo, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,1210.0f });
				ImGui::Checkbox("Mk47-Mutant", &g_Settings::Esp_Item_Mk47Mutant);
				ImGui::SetCursorPos({ 255.f,1210.0f });
				ImGui::ColorEdit4("Mk47-Mutant", (float*)&weapon::Mk47Mutant, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
				ImGui::SetCursorPos({ 25.f,1240.0f });
				ImGui::Checkbox("M249", &g_Settings::Esp_Item_M249);
				ImGui::SetCursorPos({ 255.f,1240.0f });
				ImGui::ColorEdit4("M249", (float*)&weapon::M249, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1270.0f });
				ImGui::Checkbox("MK12", &g_Settings::Esp_Item_MK12);
				ImGui::SetCursorPos({ 255.f,1270.0f });
				ImGui::ColorEdit4("MK12", (float*)&weapon::MK12, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1300.0f });
				ImGui::Checkbox("Mosin", &g_Settings::Esp_Item_Mosin);
				ImGui::SetCursorPos({ 255.f,1300.0f });
				ImGui::ColorEdit4("Mosin", (float*)&weapon::Mosin, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1330.0f });
				ImGui::Checkbox("MK14", &g_Settings::Esp_Item_Mk14);
				ImGui::SetCursorPos({ 255.f,1330.0f });
				ImGui::ColorEdit4("MK14", (float*)&weapon::MK14, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1360.0f });
				ImGui::Checkbox("Groza", &g_Settings::Esp_Item_Groza);
				ImGui::SetCursorPos({ 255.f,1360.0f });
				ImGui::ColorEdit4("Groza", (float*)&weapon::Groza, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1390.0f });
				ImGui::Checkbox("R1895", &g_Settings::Esp_Item_R1895);
				ImGui::SetCursorPos({ 255.f,1390.0f });
				ImGui::ColorEdit4("R1895", (float*)&weapon::R1895, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1420.0f });
				ImGui::Checkbox("300 Magnum", &g_Settings::Esp_Item_Awmimo);
				ImGui::SetCursorPos({ 255.f,1420.0f });
				ImGui::ColorEdit4("300 Magnum", (float*)g_Settings::Esp_Item_Awmimo_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1450.0f });
				ImGui::Checkbox("Cross Bow", &g_Settings::Esp_Item_CrossBow);
				ImGui::SetCursorPos({ 255.f,1450.0f });
				ImGui::ColorEdit4("Cross Bow", (float*)&weapon::CrossBow, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1480.0f });
				ImGui::Checkbox("AUG", &g_Settings::Esp_Item_AUG);
				ImGui::SetCursorPos({ 255.f,1480.0f });
				ImGui::ColorEdit4("AUG", (float*)&weapon::AUG, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1510.0f });
				ImGui::Checkbox("PAN", &g_Settings::Esp_Item_Pan);
				ImGui::SetCursorPos({ 255.f,1510.0f });
				ImGui::ColorEdit4("PAN", (float*)&weapon::Pan, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1540.0f });
				ImGui::Checkbox("Sickle", &g_Settings::Esp_Item_Sickle);
				ImGui::SetCursorPos({ 255.f,1540.0f });
				ImGui::ColorEdit4("Sickle", (float*)&weapon::Sickle, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1570.0f });
				ImGui::Checkbox("Machete", &g_Settings::Esp_Item_Machete);
				ImGui::SetCursorPos({ 255.f,1570.0f });
				ImGui::ColorEdit4("Machete", (float*)&weapon::Machete, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1600.0f });
				ImGui::Checkbox("VSS", &g_Settings::Esp_Item_VSS);
				ImGui::SetCursorPos({ 255.f,1600.0f });
				ImGui::ColorEdit4("VSS", (float*)g_Settings::Esp_Item_VSS_Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1630.0f });
				ImGui::Checkbox("Famas", &g_Settings::Esp_Item_Famas);
				ImGui::SetCursorPos({ 255.f,1630.0f });
				ImGui::ColorEdit4("Famas", (float*)&weapon::Famas, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1660.0f });
				ImGui::Checkbox("Sawed", &g_Settings::Esp_Item_SawedOff);
				ImGui::SetCursorPos({ 255.f,1660.0f });
				ImGui::ColorEdit4("Sawed", (float*)&weapon::SawedOff, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1690.0f });
				ImGui::Checkbox("DBS", &g_Settings::Esp_Item_DBS);
				ImGui::SetCursorPos({ 255.f,1690.0f });
				ImGui::ColorEdit4("DBS", (float*)&weapon::DBS, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1720.0f });
				ImGui::Checkbox("S12K", &g_Settings::Esp_Item_S12K);
				ImGui::SetCursorPos({ 255.f,1720.0f });
				ImGui::ColorEdit4("S12K", (float*)&weapon::S12K, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1750.0f });
				ImGui::Checkbox("M1014", &g_Settings::Esp_Item_M1014);
				ImGui::SetCursorPos({ 255.f,1750.0f });
				ImGui::ColorEdit4("M1014", (float*)&weapon::M1014, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1780.0f });
				ImGui::Checkbox("S1897", &g_Settings::Esp_Item_S1897);
				ImGui::SetCursorPos({ 255.f,1780.0f });
				ImGui::ColorEdit4("S1897", (float*)&weapon::S1897, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1810.0f });
				ImGui::Checkbox("S686", &g_Settings::Esp_Item_S686);
				ImGui::SetCursorPos({ 255.f,1810.0f });
				ImGui::ColorEdit4("S686", (float*)&weapon::S686, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1840.0f });
				ImGui::Checkbox("12 GUAGE", &g_Settings::Esp_Item_12Guage);
				ImGui::SetCursorPos({ 255.f,1840.0f });
				ImGui::ColorEdit4("12 GUAGE", (float*)&weapon::GUAGE12, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1870.0f });
				ImGui::Checkbox("R45", &g_Settings::Esp_Item_R45);
				ImGui::SetCursorPos({ 255.f,1870.0f });
				ImGui::ColorEdit4("R45", (float*)&weapon::R45, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1900.0f });
				ImGui::Checkbox("Vz61", &g_Settings::Esp_Item_Vz61);
				ImGui::SetCursorPos({ 255.f,1900.0f });
				ImGui::ColorEdit4("Vz61", (float*)&weapon::Vz61, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1930.0f });
				ImGui::Checkbox("P18C", &g_Settings::Esp_Item_P18C);
				ImGui::SetCursorPos({ 255.f,1930.0f });
				ImGui::ColorEdit4("P18C", (float*)&weapon::P18C, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1960.0f });
				ImGui::Checkbox("P92", &g_Settings::Esp_Item_P92);
				ImGui::SetCursorPos({ 255.f,1960.0f });
				ImGui::ColorEdit4("P92", (float*)&weapon::P92, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,1990.0f });
				ImGui::Checkbox("Win94", &g_Settings::Esp_Item_Win94);
				ImGui::SetCursorPos({ 255.f,1990.0f });
				ImGui::ColorEdit4("Win94", (float*)&weapon::Win94, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,2020.0f });
				ImGui::Checkbox("Desert Eagle", &g_Settings::Esp_Item_DesertEagle);
				ImGui::SetCursorPos({ 255.f,2020.0f });
				ImGui::ColorEdit4("Desert Eagle", (float*)&weapon::DesertEagle, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,2050.0f });
				ImGui::Checkbox("P1911", &g_Settings::Esp_Item_P1911);
				ImGui::SetCursorPos({ 255.f,2050.0f });
				ImGui::ColorEdit4("P1911", (float*)&weapon::P1911, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,2080.0f });
				ImGui::Checkbox("Arrow", &g_Settings::Esp_Item_Arrows);
				ImGui::SetCursorPos({ 255.f,2080.0f });
				ImGui::ColorEdit4("Arrow", (float*)&weapon::Arrow, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::Spacing(); ImGui::Spacing();
				Bar();


			}
			else if (iPage == 5)
			{
				ImGui::Text("Scope");
				SameLineDummy(1);
				ImGui::Checkbox("Scope", &scope);
				ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
				ImGui::Spacing();
				ImGui::Spacing();

				ImGui::SetCursorPos({ 25.f,70.0f });
				ImGui::Checkbox("Holo", &g_Settings::Esp_Item_Holo);
				ImGui::SetCursorPos({ 255.f,70.0f });

				ImGui::ColorEdit4("Holo", (float*)&weapon::Holo, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,100.0f });
				ImGui::Checkbox("2x", &g_Settings::Esp_Item_x2);
				ImGui::SetCursorPos({ 255.f,100.0f });

				ImGui::ColorEdit4("2x", (float*)&weapon::x2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,130.0f });
				ImGui::Checkbox("3X", &g_Settings::Esp_Item_x3);
				ImGui::SetCursorPos({ 255.f,130.0f });

				ImGui::ColorEdit4("3x", (float*)&weapon::x3, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


				ImGui::SetCursorPos({ 25.f,160.0f });
				ImGui::Checkbox("4x", &g_Settings::Esp_Item_x4);
				ImGui::SetCursorPos({ 255.f,160.0f });

				ImGui::ColorEdit4("4x", (float*)&weapon::x4, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



				ImGui::SetCursorPos({ 25.f,190.0f });
				ImGui::Checkbox("6x", &g_Settings::Esp_Item_x6);
				ImGui::SetCursorPos({ 255.f,190.0f });

				ImGui::ColorEdit4("6x", (float*)&weapon::x6, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


				ImGui::SetCursorPos({ 25.f,220.0f });
				ImGui::Checkbox("8x", &g_Settings::Esp_Item_x8);
				ImGui::SetCursorPos({ 255.f,220.0f });

				ImGui::ColorEdit4("8x", (float*)&weapon::x8, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);



				ImGui::SetCursorPos({ 25.f,250.0f });
				ImGui::Checkbox("Red Dot", &g_Settings::Esp_Item_HD);
				ImGui::SetCursorPos({ 255.f,250.0f });

				ImGui::ColorEdit4("Red Dot", (float*)&weapon::HD, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);




				ImGui::Spacing();
				ImGui::Text("Health");
				SameLineDummy(1);
				ImGui::Checkbox("Health", &healthitem);
				ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
				ImGui::Spacing();

				ImGui::SetCursorPos({ 25.f,300.0f });
				ImGui::Checkbox("Med Kit", &g_Settings::Esp_Item_MedKit);
				ImGui::SetCursorPos({ 255.f,300.0f });
				ImGui::ColorEdit4("Med Kit", (float*)&weapon::MedKit, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,330.0f });
				ImGui::Checkbox("First Aid Kit", &g_Settings::Esp_Item_FirstAidKit);
				ImGui::SetCursorPos({ 255.f,330.0f });
				ImGui::ColorEdit4("First Aid Kit", (float*)&weapon::FirstAidKit, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,360.0f });
				ImGui::Checkbox("Painkiller", &g_Settings::Esp_Item_Painkiller);
				ImGui::SetCursorPos({ 255.f,360.0f });
				ImGui::ColorEdit4("Painkiller", (float*)&weapon::Painkiller, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,390.0f });
				ImGui::Checkbox("Energy Drink", &g_Settings::Esp_Item_EnergyDrink);
				ImGui::SetCursorPos({ 255.f,390.0f });
				ImGui::ColorEdit4("Energy Drink", (float*)&weapon::EnergyDrink, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,420.0f });
				ImGui::Checkbox("Adrenaline Syringe", &g_Settings::Esp_Item_AdrenalineSyringe);
				ImGui::SetCursorPos({ 255.f,420.0f });
				ImGui::ColorEdit4("Adrenaline Syringe", (float*)&weapon::AdrenalineSyringe, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,450.0f });
				ImGui::Checkbox("Bandage", &g_Settings::Esp_Item_Bandage);
				ImGui::SetCursorPos({ 255.f,450.0f });
				ImGui::ColorEdit4("Bandage", (float*)&weapon::Bandage, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,480.0f });
				ImGui::Checkbox("Apple", &g_Settings::Esp_Item_Apple_Weapon);
				ImGui::SetCursorPos({ 255.f,480.0f });
				ImGui::ColorEdit4("Apple", (float*)&weapon::Apple, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

			}
			else if (iPage == 6)
			{
				ImGui::Text("All Attatchment");
				SameLineDummy(1);
				ImGui::Checkbox("Attatchment", &attatchment);
				ImGui::Spacing();
				ImGui::Spacing();

				ImGui::SetCursorPos({ 25.f,70.0f });
				ImGui::Checkbox("Extended Mag (SMG,Pistol)", &g_Settings::Esp_Item_Mid_E);
				ImGui::SetCursorPos({ 255.f,70.0f });
				ImGui::ColorEdit4("Extended Mag (SMG,Pistol)", (float*)&weapon::Mid_E, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,100.0f });
				ImGui::Checkbox("QuikDraw Mag (SMG,Pistol)", &g_Settings::Esp_Item_Mid_Q);
				ImGui::SetCursorPos({ 255.f,100.0f });
				ImGui::ColorEdit4("QuikDraw Mag (SMG,Pistol)", (float*)&weapon::Mid_Q, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,130.0f });
				ImGui::Checkbox("Extended QuickDraw Mag(SMG)", &g_Settings::Esp_Item_Mid_EQ);
				ImGui::SetCursorPos({ 255.f,130.0f });
				ImGui::ColorEdit4("Extended QuickDraw Mag(SMG)", (float*)&weapon::Mid_EQ, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,160.0f });
				ImGui::Checkbox("Extended Mag AR", &g_Settings::Esp_Item_Large_E);
				ImGui::SetCursorPos({ 255.f,160.0f });
				ImGui::ColorEdit4("Extended Mag AR", (float*)&weapon::Large_E, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,190.0f });
				ImGui::Checkbox("QuikDraw Mag AR", &g_Settings::Esp_Item_Large_Q);
				ImGui::SetCursorPos({ 255.f,190.0f });
				ImGui::ColorEdit4("QuikDraw Mag AR", (float*)&weapon::Large_Q, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,220.0f });
				ImGui::Checkbox("Extended QuickDraw Mag AR", &g_Settings::Esp_Item_Large_EQ);
				ImGui::SetCursorPos({ 255.f,220.0f });
				ImGui::ColorEdit4("Extended QuickDraw Mag AR", (float*)&weapon::Large_EQ, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,250.0f });
				ImGui::Checkbox("Extended Mag Sniper", &g_Settings::Esp_Item_Sniper_E);
				ImGui::SetCursorPos({ 255.f,250.0f });
				ImGui::ColorEdit4("Extended Mag Sniper", (float*)&weapon::Sniper_E, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,280.0f });
				ImGui::Checkbox("QuikDraw Mag Sniper", &g_Settings::Esp_Item_Sniper_Q);
				ImGui::SetCursorPos({ 255.f,280.0f });
				ImGui::ColorEdit4("QuikDraw Mag Sniper", (float*)&weapon::Sniper_Q, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,310.0f });
				ImGui::Checkbox("Extended QuickDraw Mag Sniper", &g_Settings::Esp_Item_Sniper_EQ);
				ImGui::SetCursorPos({ 255.f,310.0f });
				ImGui::ColorEdit4("Extended QuickDraw Mag Sniper", (float*)&weapon::Sniper_EQ, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,340.0f });
				ImGui::Checkbox("Compensator (SMG,Pistol)", &g_Settings::Esp_Item_Mid_Compensator);
				ImGui::SetCursorPos({ 255.f,340.0f });
				ImGui::ColorEdit4("Compensator (SMG,Pistol)", (float*)&weapon::Mid_Compensator, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,370.0f });
				ImGui::Checkbox("Suppressor (SMG,Pistol)", &g_Settings::Esp_Item_Mid_Suppressor);
				ImGui::SetCursorPos({ 255.f,370.0f });
				ImGui::ColorEdit4("Suppressor (SMG,Pistol)", (float*)&weapon::Mid_Suppressor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,400.0f });
				ImGui::Checkbox("Compensator AR", &g_Settings::Esp_Item_Large_Compensator);
				ImGui::SetCursorPos({ 255.f,400.0f });
				ImGui::ColorEdit4("Compensator AR", (float*)&weapon::Large_Compensator, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,430.0f });
				ImGui::Checkbox("Suppressor AR", &g_Settings::Esp_Item_Large_Suppressor);
				ImGui::SetCursorPos({ 255.f,430.0f });
				ImGui::ColorEdit4("Suppressor AR", (float*)&weapon::Large_Suppressor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,460.0f });
				ImGui::Checkbox("Suppressor Sniper", &g_Settings::Esp_Item_Sniper_Suppressor);
				ImGui::SetCursorPos({ 255.f,460.0f });
				ImGui::ColorEdit4("Suppressor Sniper", (float*)&weapon::Sniper_Suppressor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,490.0f });
				ImGui::Checkbox("Angle Forgrip", &g_Settings::Esp_Item_Vertical);
				ImGui::SetCursorPos({ 255.f,490.0f });
				ImGui::ColorEdit4("Angle Forgrip", (float*)&weapon::Vertical, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,520.0f });
				ImGui::Checkbox("Choke", &g_Settings::Esp_Item_Choke);
				ImGui::SetCursorPos({ 255.f,520.0f });
				ImGui::ColorEdit4("Choke", (float*)&weapon::Choke, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

			}
			else if (iPage == 7)
			{
				ImGui::Text("Grenade Item");
				SameLineDummy(1);
				ImGui::Checkbox("Granade", &graned);
				ImGui::Spacing();
				ImGui::Spacing();

				ImGui::SetCursorPos({ 25.f,70.0f });
				ImGui::Checkbox("Frag", &g_Settings::Esp_Item_Frag);
				ImGui::SetCursorPos({ 255.f,70.0f });

				ImGui::ColorEdit4("Frag", (float*)&weapon::Frag, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,100.0f });
				ImGui::Checkbox("Smoke", &g_Settings::Esp_Item_Smoke);
				ImGui::SetCursorPos({ 255.f,100.0f });

				ImGui::ColorEdit4("Smoke", (float*)&weapon::Smoke, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

				ImGui::SetCursorPos({ 25.f,130.0f });
				ImGui::Checkbox("Molotof", &g_Settings::Esp_Item_Molotof);
				ImGui::SetCursorPos({ 255.f,130.0f });

				ImGui::ColorEdit4("Molotof", (float*)&weapon::Molotof, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);


			}
			else if (iPage == 2)
			{
				ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
				SameLineDummy(10);
				ImGui::Checkbox("Instant Hit", &EnableInstantHit);
				SameLineDummy(10);
				ImGui::Checkbox("No Recoil", &EnableNoRecoil);
				SameLineDummy(10);
				ImGui::Checkbox("Fast Run", &FastRun);
				SameLineDummy(10);
				ImGui::Checkbox("Loofy", &loofy);
				ImGui::Spacing(); ImGui::Spacing();
				SameLineDummy(10);
				ImGui::Checkbox("God View", &GodView);
				SameLineDummy(10);
				ImGui::Checkbox("Car Fly", &carFly);
				SameLineDummy(10);
				ImGui::Checkbox("Car Speed", &speedCar);
				Bar();
				
			}

			else if (iPage == 3)
			{
				ImGui::Spacing();

				ImGui::PushFont(Font18);
				ImGui::SetCursorPosX(20);
				ImGui::Text("R => Refresh Magic");
				ImGui::SetCursorPosX(20);
				ImGui::Text("End => End Cheat");
				ImGui::SetCursorPosY(130);
				Bar();
				ImGui::SetCursorPosX(140);
				ImGui::PushItemWidth(175);
				if (ImGui::Button("End Cheat", ImVec2(200, 50)))
				{
					SafeExit();
					bEnd = true;
				}
				ImGui::SetCursorPos({ 50.0f,120.0f });
				ImGui::Text("Refresh Rate");
				ImGui::SetCursorPos({ 130.f,120.0f });
				ImGui::SliderInt("												Refresh Rate", &g_Settings::IEspDelay, 0.0f, 40.0f);

				ImGui::SetCursorPosY(210);
				Bar();

				ImGui::SetCursorPos({ 20.0f,237.0f });
				//ImGui::SetCursorPosX(20);
				ImGui::Text(expiretimed.c_str());
				ImGui::PopFont();
			}

			ImGui::PopFont();
		}
		ImGui::EndChild();
		ImGui::End();

		expiretimed.clear();
	}
	// Rendering
}
#pragma endregion



#pragma region Imgui Draw Functions

void DrawCorneredBox(int X, int Y, int W, int H, ImColor color, float thickness) {
	float lineW = (W / 3);
	float lineH = (H / 4);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), color, thickness);


}
void DrawRectIM(int x, int y, int width, int height, float thickness, ImColor color)
{
	ImGui::GetBackgroundDrawList()->AddRect(ImVec2(x, y), ImVec2(width + x, height + y), color, 0.0f, 0, thickness);

}
void DrawFilledRectIM(int x, int y, int width, int height, ImColor color)
{
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(width + x, height + y), color);

}

int DiffX;
int DiffY;
int UsableW;
int UsableH;
ImDrawList* pImGuiDraw;

void DrawLine(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, ImColor Color, FLOAT Thickness)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddLine(ImVec2(X1, Y1), ImVec2(X2, Y2), Color, Thickness);
}


void DrawFilledRectIM2(FLOAT X, FLOAT Y, FLOAT W, FLOAT H, ImColor Color)
{
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(X, Y), ImVec2(X - W, Y - H), Color);

}


void DrawStringText(int x, int y, const char* Text, ImColor color, bool outlined = false)
{
	if (outlined)
	{

		ImgdrawList->AddText(ImVec2(x - 1.0, y - 1.0), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(ImVec2(x + 1.0, y + 1.0), ImColor(0, 0, 0), Text);
	}

	ImgdrawList->AddText(ImVec2(x, y), color, Text);
}


void DrawString(ImFont* pFont, FLOAT FontSize, const char* Text, FLOAT X, FLOAT Y, ImColor Color, bool Center)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Text);
	}
	else
	{
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X, Y), Color, Text);
	}
}


void DrawStringText1(ImFont* pFont, FLOAT FontSize, const char* Text, FLOAT X, FLOAT Y, ImColor Color, bool outlined = false)
{
	ImgdrawList = ImGui::GetBackgroundDrawList();
	if (outlined)
	{

		/*ImgdrawList->AddText(ImVec2(x - 1.0, y - 1.0), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(ImVec2(x + 1.0, y + 1.0), ImColor(0, 0, 0), Text);*/
		ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Text);
		ImgdrawList->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y + 1.0f), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y - 1.0f), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y - 1.0f), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y + 1.0f), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Text);
	}

	else
	{
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X - 1.0f, Y - 1.0f), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X - 1.0f, Y + 1.0f), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X + 1.0f, Y - 1.0f), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X + 1.0f, Y + 1.0f), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X, Y), Color, Text);
	}
}


void DrawStringText2(ImFont* pFont, FLOAT FontSize, std::string& Text, FLOAT X, FLOAT Y, ImColor Color, bool outlined = false)
{
	ImgdrawList = ImGui::GetBackgroundDrawList();
	if (outlined)
	{

		/*ImgdrawList->AddText(ImVec2(x - 1.0, y - 1.0), ImColor(0, 0, 0), Text);
		ImgdrawList->AddText(ImVec2(x + 1.0, y + 1.0), ImColor(0, 0, 0), Text);*/
		ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Text.c_str());
		ImgdrawList->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y + 1.0f), ImColor(0, 0, 0), Text.c_str());
		ImgdrawList->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y - 1.0f), ImColor(0, 0, 0), Text.c_str());
		ImgdrawList->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y - 1.0f), ImColor(0, 0, 0), Text.c_str());
		ImgdrawList->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y + 1.0f), ImColor(0, 0, 0), Text.c_str());
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Text.c_str());
	}

	else
	{
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X - 1.0f, Y - 1.0f), ImColor(0, 0, 0), Text.c_str());
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X - 1.0f, Y + 1.0f), ImColor(0, 0, 0), Text.c_str());
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X + 1.0f, Y - 1.0f), ImColor(0, 0, 0), Text.c_str());
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X + 1.0f, Y + 1.0f), ImColor(0, 0, 0), Text.c_str());
		ImgdrawList->AddText(pFont, FontSize, ImVec2(X, Y), Color, Text.c_str());
	}
}


void Overlay::Overlay::DrawBone(Vector2 p1, Vector2 p2)
{
	ImgdrawList->AddLine(ImVec2(p1.x, p1.y), ImVec2(p2.x, p2.y), PlayerBoneColor, 1.3f);
}
#pragma endregion


bool IsValid(Vector2 vec)
{
	if (vec.x != 0.0f && vec.y != 0.0f)
		return true;
	return false;
}
void Overlay::Overlay::DrawPlayerBone(UINT bodyAddv, UINT boneAddv, Vector3 screen)
{
	Vector3 headPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->Head * 48);
	headPos.z += 7;
	Vector2 head;
	int distance;
	D3DMatrix viewMatrix = g_MainForm->ViewMatrix;

	g_Utilities->WorldToScreenBone(viewMatrix, headPos, head, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 neck = head;
	Vector2 chest;
	Vector3 chestPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->Chest * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, chestPos, chest, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 pelvis;
	Vector3 pelvisPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->Pelvis * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, pelvisPos, pelvis, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 lSholder;
	Vector3 lSholderPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->LeftSholder * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, lSholderPos, lSholder, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 rSholder;
	Vector3 rSholderPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->RightSholder * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, rSholderPos, rSholder, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 lElbow;
	Vector3 lElbowPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->LeftElbow * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, lElbowPos, lElbow, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 rElbow;
	Vector3 rElbowPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->RightElbow * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, rElbowPos, rElbow, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 lWrist;
	Vector3 lWristPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->LeftWrist * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, lWristPos, lWrist, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 rWrist;
	Vector3 rWristPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->RightWrist * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, rWristPos, rWrist, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 lThigh;
	Vector3 lThighPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->LeftThigh * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, lThighPos, lThigh, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 rThigh;
	Vector3 rThighPos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->RightThigh * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, rThighPos, rThigh, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 lKnee;
	Vector3 lKneePos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->LeftKnee * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, lKneePos, lKnee, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	Vector2 rKnee;
	Vector3 rKneePos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->RightKnee * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, rKneePos, rKnee, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);
	Vector2 lAnkle;
	Vector3 lAnklePos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->LeftAnkle * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, lAnklePos, lAnkle, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);
	Vector2 rAnkle;
	Vector3 rAnklePos = g_Utilities->GetBoneWorldPosition(bodyAddv, boneAddv + g_MainForm->RightAnkle * 48);
	g_Utilities->WorldToScreenBone(viewMatrix, rAnklePos, rAnkle, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y);

	if (IsValid(head) && IsValid(chest) && IsValid(pelvis) && IsValid(lSholder)
		&& IsValid(rSholder) && IsValid(lElbow) && IsValid(rElbow) && IsValid(lWrist)
		&& IsValid(rWrist) && IsValid(lThigh) && IsValid(rThigh) && IsValid(lKnee)
		&& IsValid(rKnee) && IsValid(lAnkle) && IsValid(rAnkle))
	{
		//Player HeadS
		ImgdrawList->AddCircle(ImVec2(head.x, head.y), screen.z / 12, ImColor(255, 255, 0, 255), 0, 1.5f);

		DrawBone(neck, chest);
		DrawBone(chest, pelvis);

		DrawBone(chest, lSholder);
		DrawBone(chest, rSholder);

		DrawBone(lSholder, lElbow);
		DrawBone(rSholder, rElbow);

		DrawBone(lElbow, lWrist);
		DrawBone(rElbow, rWrist);

		DrawBone(pelvis, lThigh);
		DrawBone(pelvis, rThigh);

		DrawBone(lThigh, lKnee);
		DrawBone(rThigh, rKnee);

		DrawBone(lKnee, lAnkle);
		DrawBone(rKnee, rAnkle);
	}

}

bool GetFrontWindow(HWND Targetwnd)
{
	HWND foregroundWindow = GetForegroundWindow();
	if (ShowMenu)
	{
		if (Targetwnd == foregroundWindow || DrawWindow == foregroundWindow)
		{
			return true;
		}
		return false;
	}
	else
	{
		if (Targetwnd == foregroundWindow)
		{
			return true;
		}
		return false;
	}

}


ImColor HealthColors[]
{
ImColor(234, 30, 46, 255),
ImColor(255, 255, 0, 255),
ImColor(0, 255, 0, 255),
ImColor(0, 255, 0, 255)
};

void Overlay::Overlay::StartRender(HWND targetWindowsHwnd, HWND TargetMainWindow)
{

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{

		if (PeekMessage(&msg, DrawWindow, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}
		else
		{

			if (targetWindowsHwnd != NULL)
			{
				if (true)
				{
#pragma region SettingsOverlay
					ShowWindow(DrawWindow, SW_RESTORE);
					RECT targetwndrect;
					GetWindowRect(targetWindowsHwnd, &targetwndrect);
					m_Width = targetwndrect.right - targetwndrect.left;
					m_Height = targetwndrect.bottom - targetwndrect.top;
					g_AimForm->g_Width = m_Width;
					g_AimForm->g_Height = m_Height;
					g_AimForm->WndSight.x = m_Width / 2;
					g_AimForm->WndSight.y = m_Height / 2;
					SetWindowPos(DrawWindow, nullptr, targetwndrect.left, targetwndrect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
					SetWindowPos(DrawWindow, nullptr, 0, 0, m_Width, m_Height, SWP_NOMOVE | SWP_NOZORDER);
#pragma endregion



#pragma region Menu Drawing
					if (GetAsyncKeyState(VK_INSERT) & 1) ShowMenu = !ShowMenu;
					if (GetAsyncKeyState(VK_END) & 1) SafeExit();
#pragma endregion

					SetRenderStates();
					if (D3DDevice->BeginScene() >= 0)
					{

						try
						{


							ImGui_ImplDX9_NewFrame();
							ImGui_ImplWin32_NewFrame();
							ImGui::NewFrame();


							if (ShowMenu)
							{
								if (windowstate != 1)
								{
									ChangeWindowprop(true, DrawWindow);
								}
								DrawMenu();

							}
							else
							{
								if (windowstate != 0)
								{
									ChangeWindowprop(false, DrawWindow);

								}

							}

							ImgdrawList = ImGui::GetBackgroundDrawList();

#pragma region AimLine
							if (g_Settings::EnableBulletTrack && g_Settings::AimLine && g_Settings::MagicInitialized)
							{
								if (g_AimForm->TargetBoneReq.x != 0 && g_AimForm->TargetBoneReq.y != 0 && g_MainForm->gameInstance != 0 && g_MainForm->PlayerData.size() != 0)
								{
									ImgdrawList->AddLine(ImVec2(g_AimForm->WndSight.x, m_Height), ImVec2(g_AimForm->TargetBoneReq.x, g_AimForm->TargetBoneReq.y - 5), AimLineColor);
								}
							}
#pragma endregion

#pragma region BulletTrackStatus
							if (g_Settings::EnableBulletTrack)
							{
								if (g_Settings::MagicRefresh)
								{
									ImgdrawList->AddText(ImVec2(g_AimForm->WndSight.x - 40.0f, g_AimForm->WndSight.y + 280.0f), ImColor(255, 255, 0, 255), "Tracking Magic Refreshing...");

								}
								else if (g_Settings::MagicError)
								{
									ImgdrawList->AddText(ImVec2(g_AimForm->WndSight.x - 40.0f, g_AimForm->WndSight.y + 280.0f), ImColor(255, 0, 0, 255), "Tracking Magic Error Occured.");

								}
								else if (g_Settings::MagicInitialized)
								{
									ImgdrawList->AddText(ImVec2(g_AimForm->WndSight.x - 40.0f, g_AimForm->WndSight.y + 280.0f), ImColor(0, 255, 0, 255), "Bullet Tracking Activated.");
								}
								else if (g_Settings::MagicInitializing)
								{
									ImgdrawList->AddText(ImVec2(g_AimForm->WndSight.x - 40.0f, g_AimForm->WndSight.y + 280.0f), ImColor(0, 0, 0, 255), "Tracking Magic Initializing...");
								}
							}
#pragma endregion



							if (g_MainForm->gameInstance != 0)
							{
								std::string status = "Enemy Aiming at you";

								DrawStringText1(Font16, 25, status.c_str(), g_AimForm->WndSight.x - 50, g_AimForm->WndSight.y - 10, ImColor(255, 255, 0, 255), true);

								DrawStringText1(Font16, 25, status.c_str(), g_AimForm->WndSight.x - 50, g_AimForm->WndSight.y - 10, ImColor(255, 0, 0, 255), true);
								if (g_MainForm->PlayerData.size() != 0)
								{
									if (g_Settings::PlayerEsp) {

										for (auto player : g_MainForm->PlayerData)
										{

											Vector3 playerScreen;
											int distance;
											if (g_Utilities->WorldToScreenPlayer(player.Position, playerScreen, &distance, g_MainForm->ViewMatrix, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
											{
												if (playerScreen.z < 0.001f)
													continue;

												//Distance Limit
												if (distance > g_Settings::iEspMaxDist)
													continue;


#pragma region Adjust Box

												if (player.Pose == 1114636288)
												{
													playerScreen.y = playerScreen.y + playerScreen.z / 5;
													playerScreen.z -= playerScreen.z / 5;
												}
												if (player.Pose == 1112014848)
												{
													playerScreen.y = playerScreen.y + playerScreen.z / 4;
													playerScreen.z -= playerScreen.z / 4;
												}
#pragma endregion



#pragma region PlayerHealth		                      
												int healthColorIndex = player.IsKnocked ? 0 : player.Health / 12 / 3;
												//DrawFilledRectIM(playerScreen.x - 52, playerScreen.y - 34, 135, 20, ImColor(0, 0, 0, 210)); name background
												//DrawFilledRectIM(playerScreen.x - 52, playerScreen.y - 34, 25, 20, player.IsRobot ? ImColor(0, 0, 255) : ImColor(225, 0, 0, 230));
												DrawFilledRectIM2(playerScreen.x - (playerScreen.z / 4) - 4, (playerScreen.y - 5) + (playerScreen.z + 5), 3, (playerScreen.z + 5), ImColor(0, 0, 0, 210));
												DrawFilledRectIM2(playerScreen.x - (playerScreen.z / 4) - 4, (playerScreen.y - 5) + (playerScreen.z + 5), 3, (playerScreen.z + 5) * player.Health / 100, healthColorIndex <= 2 ? HealthColors[healthColorIndex] : HealthColors[2]);

												std::string temp = "";
												temp = std::to_string(distance);
												temp.append(" M ");

												int disx = 15;
												if (temp.length() < 2)
												{
													temp.clear();
													temp.append("0");
													temp.append(std::to_string(distance));

													disx = 12;

												}
												else if (temp.length() > 1 && temp.length() < 3)
												{

													disx = 12;
												}

												//ImgdrawList->AddText(ImVec2(playerScreen.x - disx, playerScreen.y + playerScreen.z + 15), ImColor(255, 255, 255), temp.c_str());
												DrawStringText1(Font16, 14, temp.c_str(), playerScreen.x, playerScreen.y + playerScreen.z + 15, ImColor(255, 255, 255), true);
												temp.clear();




#pragma region TeamId&Name


												float teamidx = 50;
												float teamidy = 32;

												temp.append(std::to_string(player.TeamID));
												if (temp.length() < 2)
												{
													temp.clear();
													temp.append("0");
													temp.append(std::to_string(player.TeamID));
												}
												else if (temp.length() > 4)
												{
													temp.clear();
													if (!player.IsRobot)
													{
														temp.append(" P");
													}
													else
													{
														temp.append(" B");
													}
												}


												if (g_Settings::Name)
													if (player.Health <= 0)
													{
														std::string Enr = "K N O C K E D";
														ImgdrawList->AddText(ImVec2((g_AimForm->WndSight.x) - 50, 300), ImColor(255, 0, 0, 255), Enr.c_str());
													}

												/*	if (player.stateInt == "Firing" || player.stateInt == "Aiming" || player.stateInt == "Peeking")
													{
														std::string status = "Enemy Aiming at you";

														DrawStringText1(Font16, 25, status.c_str(), g_AimForm->WndSight.x - 50, g_AimForm->WndSight.y - 10, ImColor(255, 255, 0, 255), true);

														DrawStringText1(Font16, 25, status.c_str(), g_AimForm->WndSight.x - 50, g_AimForm->WndSight.y - 10, ImColor(255, 0, 0, 255), true);


													}*/


												if (player.Name.empty())
												{
													player.Name = "Player";
												}
												if (temp.empty())
												{
													//if (player.Health <= 0)

													ImgdrawList->AddText(ImVec2(playerScreen.x, playerScreen.y - teamidy), ImColor(255, 255, 255), player.Name.c_str()); //--PlayerName
												}
												else
												{
													temp.append("   ");
													temp.append(player.Name.c_str());
												}
												//ImgdrawList->AddText(ImVec2(playerScreen.x - teamidx, playerScreen.y - teamidy), ImColor(255, 255, 255), temp.c_str());




#pragma endregion
												if (player.Health <= 0)
												{
													//ImgdrawList->AddText(ImVec2(playerScreen.x - 40, playerScreen.y - 5 + playerScreen.z + 5), ImColor(255, 0, 0, 255), player.Name.c_str());
													DrawStringText1(Font16, 16, player.Name.c_str(), playerScreen.x - 5, playerScreen.y - 5 + playerScreen.z + 5, ImColor(255, 0, 0, 255), true);

												}
												else
												{
													if (player.IsRobot)
													{
														///ImgdrawList->AddText(ImVec2(playerScreen.x - 10, playerScreen.y - 5 + playerScreen.z + 5), ImColor(0, 213, 236, 255), player.Name.c_str());
														DrawStringText1(Font16, 16, player.Name.c_str(), playerScreen.x - 5, playerScreen.y - 5 + playerScreen.z + 5, ImColor(0, 213, 255, 255), true);
													}
													else
													{
														//ImgdrawList->AddText(ImVec2(playerScreen.x - 40, playerScreen.y - 5 + playerScreen.z + 5), ImColor(255, 200, 0, 255), player.Name.c_str());
														//DrawStringText(playerScreen.x - 40, playerScreen.y-5 + playerScreen.z + 5, player.Name.c_str(), ImColor(255, 200, 0, 255), true);
														DrawStringText1(Font16, 16, player.Name.c_str(), playerScreen.x - 5, playerScreen.y - 5 + playerScreen.z + 5, ImColor(255, 250, 0, 255), true);

													}
													//ImgdrawList->AddText(ImVec2(playerScreen.x - 40, playerScreen.y - 10), ImColor(255, 220, 0, 1000), player.Name.c_str());

												}


												if (g_Settings::PlayerSkeleton)
												{
													auto tmpAddv = g_Utilities->Driver.ReadVirtualMemory<UINT>(player.Address + GameOffsets::Meshoffset);
													auto bodyAddv = tmpAddv + GameOffsets::bodyoffset;
													auto boneAddv = g_Utilities->Driver.ReadVirtualMemory<UINT>(tmpAddv + GameOffsets::MinLODoffset) + 48;

													DrawPlayerBone(bodyAddv, boneAddv, playerScreen);
												}

												if (g_Settings::PlayerLines)
												{
													if (player.IsRobot)
													{
														if (player.Health <= 0)
														{
															DrawLine(g_AimForm->WndSight.x, 0, playerScreen.x, playerScreen.y - 20, Colors::botline2, 1.0f);
														}
														else
														{
															DrawLine(g_AimForm->WndSight.x, 0, playerScreen.x, playerScreen.y - 20, Colors::botline, 1.0f);
														}

													}
													else
													{
														if (player.Health <= 0)
														{
															DrawLine(g_AimForm->WndSight.x, 0, playerScreen.x, playerScreen.y - 20, Colors::playerline2, 1.0f);
														}
														else
														{
															DrawLine(g_AimForm->WndSight.x, 0, playerScreen.x, playerScreen.y - 20, Colors::playerline, 1.0f);
														}
													}
												}



												if (g_Settings::PlayerBox)
												{
													DrawCorneredBox(playerScreen.x - playerScreen.z / 4 - 3, playerScreen.y - 5, (playerScreen.z / 2) + 3, playerScreen.z + 5, PlayerBoxColor, 1.0f);

												}

												if (g_Settings::HandGun)
												{

													std::string Textt = player.weapon.c_str();
													//ImgdrawList->AddText(ImVec2(playerScreen.x - 20, playerScreen.y -20), ImColor(255, 220, 0, 1000), player.weapon.c_str());
													//ImgdrawList->AddText(ImVec2(playerScreen.x - 20, playerScreen.y + 35), ImColor(255, 255, 255), player.stateInt.c_str());
													if (player.stateInt == "Firing" || player.stateInt == "Aiming" || player.stateInt == "Peeking")
													{
														DrawStringText1(Font16, 16, player.stateInt.c_str(), playerScreen.x, playerScreen.y + playerScreen.z + 25, ImColor(255, 200, 0, 255), true);
													}

													//DrawStringText(playerScreen.x - 20, playerScreen.y, player.weapon.c_str(), ImColor(255, 255, 255), true);

													if (Textt == "Fist")
													{
														DrawStringText1(Font16, 14, player.weapon.c_str(), playerScreen.x - 5, playerScreen.y - 20, ImColor(0, 255, 0, 255), true);
													}
													else
													{
														DrawStringText1(Font16, 14, player.weapon.c_str(), playerScreen.x - 5, playerScreen.y - 20, ImColor(255, 250, 0, 255), true);
													}
												}

											}
										}
									}



#pragma region PlayerBotCount
									std::string pcount = "Player: ";
									pcount.append(std::to_string(g_MainForm->PlayersCount.size()));
									std::string btcount = "Bot: ";
									btcount.append(std::to_string(g_MainForm->BotsCount.size()));
									DrawFilledRectIM((g_AimForm->WndSight.x) - 100, 123, 230, 1, ImColor(0.000f, 1.000f, 0.000f, 1.000f));
									DrawFilledRectIM((g_AimForm->WndSight.x) - 100, 145, 230, 1.5, ImColor(1.000f, 0.000f, 1.000f, 1.000f));
									DrawFilledRectIM((g_AimForm->WndSight.x) - 100, 124, 230, 20, D3DCOLOR_ARGB(170, 0, 0, 0));
									ImgdrawList->AddText(ImVec2((g_AimForm->WndSight.x) - 50, 126), ImColor(255, 0, 0, 255), pcount.c_str());
									ImgdrawList->AddText(ImVec2((g_AimForm->WndSight.x) + 30, 126), ImColor(0, 255, 0, 255), btcount.c_str());

								}

#pragma region Misc Esp

								if (g_Settings::vehicleEsp)
								{
									for (auto vehicle : g_MainForm->VehicleData)
									{
										Vector3 carScreen;
										int distance;

										if (g_Utilities->WorldToScreen(g_MainForm->ViewMatrix, vehicle.Position, carScreen, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
										{
											if (carScreen.z < 0.001f || distance < 10)
												continue;
											std::string vehicleDes;
											vehicleDes.append(vehicle.displayName);
											vehicleDes.append("  ");
											vehicleDes.append(std::to_string(distance).append(" M"));

											/*float HP = Driver1.ReadVirtualMemory<float>(Vehicle.VehicleComm + GameOffsets::HPOffset);
											float MaxHP = Driver1.ReadVirtualMemory<float>(Vehicle.VehicleComm + GameOffsets::HPMaxOffset);*/



											/*Vehicle.HP = (int)(HP * 100 / MaxHP);*/

											/*float Fuel = Driver1.ReadVirtualMemory<float>(Vehicle.VehicleComm + GameOffsets::FuelOffset);
											float MaxFuel = Driver1.ReadVirtualMemory<float>(Vehicle.VehicleComm + GameOffsets::FuelMaxOffset);*/


											/*Vehicle.Fuel = (int)(Fuel * 100 / MaxFuel);*/


											std::string fuel, name = vehicle.displayName;

											//fuel.append("Fuel [").append(std::to_string((UINT)(Fuel * 100 / vhi.MaxFuel)).append("] HP [").append(std::to_string((UINT)(HP * 100 / MaxHP)).append("]")));

											fuel.append("Gas [").append(std::to_string((int)(vhi.CurrFuel)).append("] HP [").append(std::to_string((int)(vhi.CurrHealth)).append("]")));
											/*HP = HP,
												Fuel = Fuel,*/
											DrawStringText2(Font16, 16, fuel, carScreen.x - 40, carScreen.y + 3, ImColor(weapon::vehicle), true);

											//DrawStringText1(Font16, 16, fuel.c_str(), carScreen.x -40 , carScreen.y + 3 , ImColor(weapon::vehicle), true);
											//DrawStringText(carScreen.x - 40, carScreen.y + 3 , fuel.c_str(), ImColor(weapon::vehicle), true);
											//ImgdrawList->AddText(ImVec2(carScreen.x - 40, carScreen.y + 3), ImColor(weapon::vehicle), fuel.c_str());
											if (vehicle.driving)
											{
												//ImgdrawList->AddText(ImVec2(carScreen.x - 40, carScreen.y - 10), ImColor(255,130,0), vehicleDes.c_str());
												//DrawStringText(carScreen.x - 40, carScreen.y - 10, vehicleDes.c_str(), ImColor(255, 130, 0), true);
												DrawStringText1(Font16, 16, vehicleDes.c_str(), carScreen.x - 40, carScreen.y - 10, ImColor(255, 150, 0), true);
											}
											else
											{
												//ImgdrawList->AddText(ImVec2(carScreen.x - 40, carScreen.y - 10), ImColor(weapon::vehicle), vehicleDes.c_str());
												//DrawStringText(carScreen.x - 40, carScreen.y - 10, vehicleDes.c_str(), ImColor(weapon::vehicle), true);
												DrawStringText1(Font16, 16, vehicleDes.c_str(), carScreen.x - 40, carScreen.y - 10, ImColor(weapon::vehicle), true);
											}
										}


									}
								}

								if (g_Settings::ShowItems)
								{
									for (auto Item : g_MainForm->ItemData)
									{
										Vector3 itemScreen;
										int distance;

										if (g_Utilities->WorldToScreen(g_MainForm->ViewMatrix, Item.Position, itemScreen, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
										{
											if (itemScreen.z < 0.001f || distance > 150)
												continue;
											std::string ItemDes;
											ItemDes.append(Item.displayName);
											ImGui::PushFont(ItemFont);

											ImGui::PopFont();


											if (g_Settings::Esp_Item_Bag1 && Item.displayName == "Bag L.1")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Bag1), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Bag1), true);

											}
											if (g_Settings::Esp_Item_Bag2 && Item.displayName == "Bag L.2")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Bag2), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Bag2), true);

											}

											if (g_Settings::Esp_Item_Helmet1 && Item.displayName == "Helmet Lv.1")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Helmet1), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Helmet1), true);

											}

											if (g_Settings::Esp_Item_Helmet2 && Item.displayName == "Helmet Lv.2")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Helmet2), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Helmet2), true);

											}

											if (g_Settings::Esp_Item_Armor1 && Item.displayName == "Armour Lv.1")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Armor1), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Armor1), true);

											}

											if (g_Settings::Esp_Item_Armor2 && Item.displayName == "Armour Lv.2")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Armor2), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Armor2), true);

											}


											if (g_Settings::Esp_Item_Mk47Mutant && Item.displayName == "Mk47 Mutant")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Mk47Mutant), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Mk47Mutant), true);

											}

											if (g_Settings::Esp_Item_M16A4 && Item.displayName == "M16A-4")
											{

												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::m16A4), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::m16A4), true);

											}

											if (g_Settings::Esp_Item_G36C && Item.displayName == "G36C")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::G36C), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::G36C), true);

											}

											if (g_Settings::Esp_Item_QBZ && Item.displayName == "QBZ")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::QBZ), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::QBZ), true);

											}

											if (g_Settings::Esp_Item_QBU && Item.displayName == "QBU")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::QBU), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::QBZ), true);

											}

											if (g_Settings::Esp_Item_SLR && Item.displayName == "SLR")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::SLR), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::SLR), true);

											}


											if (g_Settings::Esp_Item_PP19 && Item.displayName == "PP19 Bizon")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::PP19), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::PP19), true);

											}

											if (g_Settings::Esp_Item_TommyGun && Item.displayName == "Thompson")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::TommyGun), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::TommyGun), true);

											}

											if (g_Settings::Esp_Item_MP5K && Item.displayName == "MP5K")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::MP5K), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::MP5K), true);

											}

											if (g_Settings::Esp_Item_UMP9 && Item.displayName == "UMP9")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::UMP9), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::UMP9), true);

											}

											if (g_Settings::Esp_Item_Vector && Item.displayName == "Vector")
											{

												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Vector), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Vector), true);

											}

											if (g_Settings::Esp_Item_Uzi && Item.displayName == "Uzi")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Uzi), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Uzi), true);

											}

											if (g_Settings::Esp_Item_762mm && Item.displayName == "7.62")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Ammo762), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Ammo762), true);

											}

											if (g_Settings::Esp_Item_556mm && Item.displayName == "5.56")
											{

												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Ammo556), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Ammo556), true);

											}

											if (g_Settings::Esp_Item_9mm && Item.displayName == "9mm")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Ammo9mm), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Ammo9mm), true);

											}

											if (g_Settings::Esp_Item_45ACP && Item.displayName == "45ACP")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::ACP45), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::ACP45), true);

											}


											if (g_Settings::Esp_Item_Mk14 && Item.displayName == "Mk14")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::MK14), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::MK14), true);

											}
											if (g_Settings::Esp_Item_SKS && Item.displayName == "SKS")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::SKS), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::SKS), true);

											}

											if (g_Settings::Esp_Item_Groza && Item.displayName == "Groza")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Groza), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Groza), true);

											}
											if (g_Settings::Esp_Item_R1895 && Item.displayName == "R1895")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::R1895), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::R1895), true);

											}
											if (g_Settings::Esp_Item_AUG && Item.displayName == "AUG_A3")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::AUG), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::AUG), true);

											}
											if (g_Settings::Esp_Item_SawedOff && Item.displayName == "SawedOff")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::SawedOff), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::SawedOff), true);

											}
											if (g_Settings::Esp_Item_S12K && Item.displayName == "S12K")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::S12K), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::S12K), true);

											}
											if (g_Settings::Esp_Item_S1897 && Item.displayName == "S1897")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::S1897), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::S1897), true);

											}
											if (g_Settings::Esp_Item_S686 && Item.displayName == "S686")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::S686), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::S686), true);

											}
											if (g_Settings::Esp_Item_12Guage && Item.displayName == "12Guage")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::GUAGE12), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::GUAGE12), true);

											}
											if (g_Settings::Esp_Item_VSS && Item.displayName == "VSS")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::VSS), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::VSS), true);

											}

											//start
											if (g_Settings::Esp_Item_Vz61 && Item.displayName == "Vz61")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Vz61), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Vz61), true);

											}
											if (g_Settings::Esp_Item_P92 && Item.displayName == "P92")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::P92), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::P92), true);

											}
											if (g_Settings::Esp_Item_P18C && Item.displayName == "P18C")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::P18C), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::P18C), true);

											}

											if (g_Settings::Esp_Item_Win94 && Item.displayName == "Win94")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Win94), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Win94), true);

											}
											if (g_Settings::Esp_Item_HD && Item.displayName == "Lazer")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::HD), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::HD), true);

											}
											if (g_Settings::Esp_Item_R45 && Item.displayName == "R45")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::R45), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::R45), true);

											}
											if (g_Settings::Esp_Item_DesertEagle && Item.displayName == "DesertEagle")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::DesertEagle), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::DesertEagle), true);

											}
											if (g_Settings::Esp_Item_P1911 && Item.displayName == "P1911")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::P1911), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::P1911), true);

											}
											if (g_Settings::Esp_Item_DBS && Item.displayName == "DBS")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::DBS), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::DBS), true);

											}
											if (g_Settings::Esp_Item_M1014 && Item.displayName == "M1014")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::M1014), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::M1014), true);

											}
											if (g_Settings::Esp_Item_Famas && Item.displayName == "Famas")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Famas), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Famas), true);

											}
											if (g_Settings::Esp_Item_Mini14 && Item.displayName == "Mini14")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Mini14), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Mini14), true);
											}
											if (g_Settings::Esp_Item_M249 && Item.displayName == "M249")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::M249), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::M249), true);
											}
											if (g_Settings::Esp_Item_MK12 && Item.displayName == "MK12")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::MK12), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::MK12), true);
											}
											if (g_Settings::Esp_Item_Mosin && Item.displayName == "Mosin")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Mosin), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Mosin), true);
											}
											if (g_Settings::Esp_Item_CrossBow && Item.displayName == "Cross Bow")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::CrossBow), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::CrossBow), true);
											}
											if (g_Settings::Esp_Item_Arrows && Item.displayName == "Arrows")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Arrow), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Arrow), true);
											}
											if (g_Settings::Esp_Item_Pan && Item.displayName == "Pan")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Pan), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Pan), true);
											}
											if (g_Settings::Esp_Item_Sickle && Item.displayName == "Sickle")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Sickle), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Sickle), true);
											}
											if (g_Settings::Esp_Item_Machete && Item.displayName == "Machete")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Machete), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Machete), true);
											}
											if (g_Settings::Esp_Item_ASM_Abakan && Item.displayName == "ASM Abakan AR")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::ASMAbakanAR), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::ASMAbakanAR), true);
											}
										}


									}
								}
								if (g_Settings::attatchment)
								{
									for (auto Item : g_MainForm->ItemData)
									{
										Vector3 itemScreen;
										int distance;

										if (g_Utilities->WorldToScreen(g_MainForm->ViewMatrix, Item.Position, itemScreen, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
										{
											if (itemScreen.z < 0.001f || distance > 150)
												continue;
											std::string ItemDes;
											ItemDes.append(Item.displayName);
											ImGui::PushFont(ItemFont);

											ImGui::PopFont();
											if (g_Settings::Esp_Item_Sniper_EQ && Item.displayName == "Extended QuickDraw Mag ( Snipers)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Sniper_EQ), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Sniper_EQ), true);

											}

											if (g_Settings::Esp_Item_Large_Suppressor && Item.displayName == "Suppressor(AR)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Large_Suppressor), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Large_Suppressor), true);

											}

											if (g_Settings::Esp_Item_Large_EQ && Item.displayName == "Extended QuickDraw Mag (AR)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Large_EQ), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Large_EQ), true);

											}

											if (g_Settings::Esp_Item_Large_E && Item.displayName == "Exteded AR")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Large_E), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Large_E), true);

											}

											if (g_Settings::Esp_Item_Mid_EQ && Item.displayName == "Extended QuickDraw Mag (SMG)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Mid_EQ), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Mid_EQ), true);

											}

											if (g_Settings::Esp_Item_Mid_E && Item.displayName == "Extended Mag (SMG, Pistols)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Mid_E), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Mid_E), true);
											}

											if (g_Settings::Esp_Item_Mid_Q && Item.displayName == "QuickDraw Mag(SMG, Pistols)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Mid_Q), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Mid_Q), true);
											}

											if (g_Settings::Esp_Item_Large_Q && Item.displayName == "QuickDraw Mag AR")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Large_Q), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Large_Q), true);
											}


											if (g_Settings::Esp_Item_Sniper_E && Item.displayName == "Extended Mag Sniper")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Sniper_E), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Sniper_E), true);
											}

											if (g_Settings::Esp_Item_Sniper_Q && Item.displayName == "QuickDraw Mag (Snipers)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Sniper_Q), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Sniper_Q), true);
											}


											if (g_Settings::Esp_Item_Large_Compensator && Item.displayName == "AR Compensator")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Large_Compensator), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Large_Compensator), true);
											}

											if (g_Settings::Esp_Item_Mid_Compensator && Item.displayName == "Compensator (SMG)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Mid_Compensator), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Mid_Compensator), true);
											}


											if (g_Settings::Esp_Item_A && Item.displayName == "Taktik Dipcik")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::A), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::A), true);
											}
											if (g_Settings::Esp_Item_DuckBill && Item.displayName == "Duckbill (Pompalı))")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::DuckBill), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::DuckBill), true);
											}

											if (g_Settings::Esp_Item_Mid_Suppressor && Item.displayName == "Suppressor(SMG)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Mid_Suppressor), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Mid_Suppressor), true);
											}

											if (g_Settings::Esp_Item_Sniper && Item.displayName == "Chekpad Sniper")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Sniper), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Sniper), true);
											}
											if (g_Settings::Esp_Item_Choke && Item.displayName == "Choke")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Choke), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Choke), true);
											}

											if (g_Settings::Esp_Item_UZI && Item.displayName == "Dipcik (Micro UZI)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::UZI), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::UZI), true);
											}


											if (g_Settings::Esp_Item_Sniper_Suppressor && Item.displayName == "Suppressor(Snip)")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Sniper_Suppressor), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Sniper_Suppressor), true);
											}

											if (g_Settings::Esp_Item_Sniper && Item.displayName == "Mermilik")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Sniper), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Sniper), true);
											}



											if (g_Settings::Esp_Item_Vertical && Item.displayName == "Angle Foregrip")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Vertical), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Vertical), true);
											}


											if (g_Settings::Esp_Item_ThumbGrip && Item.displayName == "Basparmaklik")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::ThumbGrip), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::ThumbGrip), true);
											}

											if (g_Settings::Esp_Item_Lasersight && Item.displayName == "Silah Lazeri")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Lasersight), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Lasersight), true);
											}

											if (g_Settings::Esp_Item_Angled && Item.displayName == "Acili El Tutamagi")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Angled), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Angled), true);
											}

											if (g_Settings::Esp_Item_LightGrip && Item.displayName == "Hafif Tutamak")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::LightGrip), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::LightGrip), true);
											}

											if (g_Settings::Esp_Item_HalfGrip && Item.displayName == "Yarım Tutamak")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::HalfGrip), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::HalfGrip), true);
											}
										}
									}
								}


								if (g_Settings::healthitem)
								{
									for (auto Item : g_MainForm->ItemData)
									{
										Vector3 itemScreen;
										int distance;

										if (g_Utilities->WorldToScreen(g_MainForm->ViewMatrix, Item.Position, itemScreen, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
										{
											if (itemScreen.z < 0.001f || distance > 150)
												continue;
											std::string ItemDes;
											ItemDes.append(Item.displayName);
											ImGui::PushFont(ItemFont);

											ImGui::PopFont();

											if (g_Settings::Esp_Item_MedKit && Item.displayName == "Medkit")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::MedKit), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::MedKit), true);

											}

											if (g_Settings::Esp_Item_FirstAidKit && Item.displayName == "FirstaidKit")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::FirstAidKit), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::FirstAidKit), true);
											}

											if (g_Settings::Esp_Item_Painkiller && Item.displayName == "Painkiller")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Painkiller), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Painkiller), true);
											}

											if (g_Settings::Esp_Item_EnergyDrink && Item.displayName == "Energy Drink")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::EnergyDrink), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::EnergyDrink), true);
											}

											if (g_Settings::Esp_Item_AdrenalineSyringe && Item.displayName == "Adrenaline Syringe")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::AdrenalineSyringe), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::AdrenalineSyringe), true);
											}
											if (g_Settings::Esp_Item_Bandage && Item.displayName == "Bandage")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Bandage), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Bandage), true);
											}
											if (g_Settings::Esp_Item_Apple_Weapon && Item.displayName == "Apple_Weapon")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Apple), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Apple), true);
											}
										}

									}
								}
								if (g_Settings::scope)
								{
									for (auto Item : g_MainForm->ItemData)
									{
										Vector3 itemScreen;
										int distance;

										if (g_Utilities->WorldToScreen(g_MainForm->ViewMatrix, Item.Position, itemScreen, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
										{
											if (itemScreen.z < 0.001f || distance > 150)
												continue;
											std::string ItemDes;
											ItemDes.append(Item.displayName);
											ImGui::PushFont(ItemFont);

											ImGui::PopFont();

											if (g_Settings::Esp_Item_Holo && Item.displayName == "Holo")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Holo), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Holo), true);
											}
											if (g_Settings::Esp_Item_x2 && Item.displayName == "2x")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::x2), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::x2), true);
											}

											if (g_Settings::Esp_Item_x3 && Item.displayName == "3X")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::x3), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::x3), true);
											}

											if (g_Settings::Esp_Item_x4 && Item.displayName == "4x")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::x4), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::x4), true);
											}

											if (g_Settings::Esp_Item_x6 && Item.displayName == "6x")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::x6), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::x6), true);
											}

											if (g_Settings::Esp_Item_x8 && Item.displayName == "8x")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::x8), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::x8), true);
											}

											if (g_Settings::Esp_Item_HD && Item.displayName == "Red Dot")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::HD), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::HD), true);
											}

										}
									}
								}


								if (g_Settings::impitems)
								{
									for (auto Item : g_MainForm->ItemData)
									{
										Vector3 itemScreen;
										int distance;

										if (g_Utilities->WorldToScreen(g_MainForm->ViewMatrix, Item.Position, itemScreen, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
										{
											if (itemScreen.z < 0.001f || distance > 150)
												continue;
											std::string ItemDes;
											ItemDes.append(Item.displayName);
											ImGui::PushFont(ItemFont);

											ImGui::PopFont();
											if (g_Settings::Esp_Item_AKM && Item.displayName == "AKM")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::AKM), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::AKM), true);
											}
											if (g_Settings::Esp_Item_M416 && Item.displayName == "M416")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::m416), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::m416), true);
											}
											if (g_Settings::Esp_Item_SCARL && Item.displayName == "SCAR-L")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::scarl), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::scarl), true);
											}
											if (g_Settings::Esp_Item_M24 && Item.displayName == "M24")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::M24), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::M24), true);
											}
											if (g_Settings::Esp_Item_Kar98k && Item.displayName == "Kar98k")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::kar98), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::kar98), true);
											}
											if (g_Settings::Esp_Item_DP28 && Item.displayName == "DP28")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::DP), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::DP), true);
											}
											if (g_Settings::Esp_Item_M762 && Item.displayName == "M762")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::m762), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::m762), true);
											}
											if (g_Settings::Esp_Item_Awm && Item.displayName == "AWM")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::AWM), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::AWM), true);
											}
											if (g_Settings::Esp_Item_FlareGun && Item.displayName == "Flaregun")
											{
												//DrawStringText(itemScreen.x - 10, itemScreen.y - 10, ItemDes.c_str(), weapon::Flaregun, true);
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Flaregun), true);
											}
											if (g_Settings::Esp_Item_Flare && Item.displayName == "FlareAmmo")
											{
												//DrawStringText(itemScreen.x - 10, itemScreen.y - 10, ItemDes.c_str(), weapon::Flare, true);
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Flare), true);
											}

											if (g_Settings::Esp_Item_Armor3 && Item.displayName == "Armour Lv.3")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Armor3), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Armor3), true);
											}
											if (g_Settings::Esp_Item_Bag3 && Item.displayName == "Bag Lv.3")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Bag3), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Bag3), true);
											}
											if (g_Settings::Esp_Item_Helmet3 && Item.displayName == "Helmet Lv.3")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Helmet3), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Helmet3), true);
											}
											if (g_Settings::Esp_Item_Awmimo && Item.displayName == "300Magnum")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::AWMimmo), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::AWMimmo), true);
											}
										}




									}
								}
								if (g_Settings::graned)
								{
									for (auto Item : g_MainForm->ItemData)
									{
										Vector3 itemScreen;
										int distance;

										if (g_Utilities->WorldToScreen(g_MainForm->ViewMatrix, Item.Position, itemScreen, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
										{
											if (itemScreen.z < 0.001f || distance > 150)
												continue;
											std::string ItemDes;
											ItemDes.append(Item.displayName);
											ImGui::PushFont(ItemFont);

											ImGui::PopFont();
											if (g_Settings::Esp_Item_Frag && Item.displayName == "Grenade")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Frag), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Frag), true);
											}
											if (g_Settings::Esp_Item_Smoke && Item.displayName == "Smoke")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Smoke), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Smoke), true);
											}
											if (g_Settings::Esp_Item_Molotof && Item.displayName == "Molotof")
											{
												//ImgdrawList->AddText(ImVec2(itemScreen.x - 10, itemScreen.y - 10), ImColor(weapon::Molotof), ItemDes.c_str());
												DrawStringText1(Font16, 14, ItemDes.c_str(), itemScreen.x - 10, itemScreen.y - 10, ImColor(weapon::Molotof), true);
											}
										}
									}

								}
								if (g_Settings::LootBoxItems)
								{
									for (auto LootBox : g_MainForm->LootBoxData)
									{
										Vector3 lootBoxScreen;
										int distance;

										if (g_Utilities->WorldToScreen(g_MainForm->ViewMatrix, LootBox.Position, lootBoxScreen, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
										{
											for (int i = 0; i < LootBox.boxitem.size(); i++)
											{
												std::string itemname = i == 0 ? LootBox.boxitem[i].Displayname + std::to_string(distance).append(" m") : LootBox.boxitem[i].Displayname;
												//ImgdrawList->AddText(ImVec2(lootBoxScreen.x, lootBoxScreen.y - 15 *(i + 1)), LootBox.boxitem[i].ItemColor, itemname.c_str());
												DrawStringText1(Font16, 14, itemname.c_str(), lootBoxScreen.x, lootBoxScreen.y - 15 * (i + 1), LootBox.boxitem[i].ItemColor, true);
												itemname.clear();
											}

										}


									}
								}


								if (g_Settings::GrenadeAlert)
								{
									for (auto grenade : g_MainForm->GrenadeAlertData)
									{
										Vector3 grenadeScreen;
										int distance;

										if (g_Utilities->WorldToScreen(g_MainForm->ViewMatrix, grenade.Position, grenadeScreen, &distance, g_AimForm->WndSight.x, g_AimForm->WndSight.y))
										{
											std::string grenadeDes;
											grenadeDes.append(grenade.displayName);
											//ImgdrawList->AddText(ImVec2(grenadeScreen.x - 40, grenadeScreen.y - 10), ImColor(255, 0, 0), grenadeDes.c_str());
											DrawStringText1(Font16, 20, grenadeDes.c_str(), grenadeScreen.x - 10, grenadeScreen.y - 10, ImColor(255, 0, 0), true);
										}


									}
								}

#pragma endregion



							}
							else {
								if (!ShowMenu)
								{
									this->ClearScreen();
									windowstate = 0;
									ChangeWindowprop(false, DrawWindow);
									std::this_thread::sleep_for(std::chrono::milliseconds(20));
								}
							}

#define shortCutDelay ImGui::GetIO().Framerate / 1000 * 300
							if (g_Settings::menu) {
								static auto Name = "Menu2";
								static auto Flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;
								static bool open = true;
								static bool no_close = true;
								DWORD dwFlag = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;
								RECT screen_rect;
								float WidthM = 396;
								GetWindowRect(GetDesktopWindow(), &screen_rect);
								auto x = float(screen_rect.right - WidthM) / 200.f;
								auto y = float(screen_rect.bottom - WidthM) / 2.f;
								ImGui::SetNextWindowPos(ImVec2(x + 15, y), ImGuiCond_Once);
								ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
								ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
								ImGui::SetNextWindowBgAlpha(0.70f);
								if (ImGui::Begin((" "), &open, dwFlag))
								{
									ImGui::Text("     PC GAMER ");
									ImGui::Separator();
									if (g_Settings::ShowItems == false)
									{
										ImGui::TextColored(ImVec4(1.00, 0.00, 0.02, 1.0f), (" F2 : Item"));
									}
									else {
										ImGui::TextColored(ImVec4(0.00, 1.00, 0.00, 1.0f), (" F2 : Item"));
									}

									if (g_Settings::EnableBulletTrack == false)
									{
										ImGui::TextColored(ImVec4(1.00, 0.00, 0.02, 1.0f), (" F3 : Magic Bullet"));
									}
									else {
										ImGui::TextColored(ImVec4(0.00, 1.00, 0.00, 1.0f), (" F3 : Magic Bullet"));
									}

									if (g_Settings::vehicleEsp == false)
									{
										ImGui::TextColored(ImVec4(1.00, 0.00, 0.02, 1.0f), (" F4 : Vehicles Esp"));
									}
									else {
										ImGui::TextColored(ImVec4(0.00, 1.00, 0.00, 1.0f), (" F4 : Vehicles Esp"));
									}

									if (g_Settings::PlayerBox == false)
									{
										ImGui::TextColored(ImVec4(1.00, 0.00, 0.02, 1.0f), (" F5 : Box"));
									}
									else {
										ImGui::TextColored(ImVec4(0.00, 1.00, 0.00, 1.0f), (" F5 : Box"));
									}

									if (g_Settings::FightMode == false)
									{

										ImGui::TextColored(ImVec4(1.00, 0.00, 0.02, 1.0f), (" F6 : Fight Mode"));
									}
									else {

										ImGui::TextColored(ImVec4(0.00, 1.00, 0.00, 1.0f), (" F6 : Fight Mode"));
									}
									ImGui::Separator();
									std::string AimDisplay = "Aim : ";
									AimDisplay.append(AimAt[g_Settings::iAimBone]);
									ImGui::Text(AimDisplay.c_str()); ImGui::SameLine(); ImGui::Text("(T)");
									ImGui::Separator();
									ImGui::Text(("   HOME    Hide"));
									ImGui::Text(("    END     Exit"));
									ImGuiStyle& style = ImGui::GetStyle();
									auto FramePadding = style.FramePadding;
									style.FramePadding = ImVec2(6, 4);
									ImGui::SetCursorPos({ 40.f,70.f });
									ImGui::EndChild();
								}
								ImGui::EndTabItem();
							}
							static int menuTimeout = 0;
#define shortCutDelay ImGui::GetIO().Framerate / 1000 * 300

							if (GetAsyncKeyState(VK_HOME) && menuTimeout >= shortCutDelay) {
								g_Settings::menu = !g_Settings::menu;
								menuTimeout = 0;
							}
							if (GetAsyncKeyState(VK_F2) && menuTimeout >= shortCutDelay) {
								g_Settings::ShowItems = !g_Settings::ShowItems;
								menuTimeout = 0;
							}
							if (GetAsyncKeyState(VK_F3) && menuTimeout >= shortCutDelay) {
								g_Settings::EnableBulletTrack = !g_Settings::EnableBulletTrack;

								menuTimeout = 0;
							}
							if (GetAsyncKeyState(VK_F4) && menuTimeout >= shortCutDelay) {
								g_Settings::vehicleEsp = !g_Settings::vehicleEsp;
								menuTimeout = 0;
							}
							if (GetAsyncKeyState(VK_F5) && menuTimeout >= shortCutDelay) {
								g_Settings::PlayerBox = !g_Settings::PlayerBox;
								menuTimeout = 0;
							}
							if (GetAsyncKeyState(VK_F6) && menuTimeout >= shortCutDelay) {
								g_Settings::FightMode = !g_Settings::FightMode;

								g_Settings::ShowItems = !g_Settings::ShowItems;
								g_Settings::vehicleEsp = !g_Settings::vehicleEsp;

								menuTimeout = 0;
							}
							if (GetAsyncKeyState(0x54) && menuTimeout >= shortCutDelay) {
								g_Settings::iAimBone++;
								if (g_Settings::iAimBone == 3)
									g_Settings::iAimBone = 0;
								std::cout << g_Settings::iAimBone << std::endl;
								menuTimeout = 0;
							}

							if (menuTimeout < shortCutDelay)
								menuTimeout++;
							// Rendering
							ImGui::EndFrame();

							ImGui::Render();
							ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

						}
						catch (...)
						{
						}

						D3DDevice->EndScene();
					}

					//this->ClearScreen();
					HRESULT result = D3DDevice->Present(NULL, NULL, NULL, NULL);
					if (result == D3DERR_DEVICELOST && D3DDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
					{

						ResetDevice();
					}


				}
				else
				{
					//Hide Overlay When TargetWND is not focused
					this->ClearScreen();
					windowstate = 0;
					ShowWindow(DrawWindow, SW_HIDE);
					std::this_thread::sleep_for(std::chrono::milliseconds(1000));

				}
			}

			D3DDevice->Present(NULL, NULL, NULL, NULL);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(g_Settings::IEspDelay));
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	CleanupDeviceD3D();
	::DestroyWindow(DrawWindow);
}