// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dedicated/sys_windows.cpp
// Functions: 17
// ============================================================

#include "dedicated\sys_windows.h"

//------------------------------------------------------------------------------
// Address: 0x10004480
// Name: public: virtual ISys::~ISys(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ISys::~ISys(ISys *this)
{
  this->__vftable = (ISys_vtbl *)&ISys::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100044C0
// Name: public: virtual void CSys::Sleep(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSys::Sleep(CSys *this, DWORD msec)
{
  Sleep(dwMilliseconds: msec);
}

//------------------------------------------------------------------------------
// Address: 0x100044D0
// Name: public: virtual long CSys::LoadLibraryA(char __near *)
// Source: json
//------------------------------------------------------------------------------
HMODULE __thiscall CSys::LoadLibraryA(CSys *this, char *lib)
{
  HMODULE result; // eax
  HMODULE v3; // esi

  result = LoadLibraryA(lpLibFileName: lib);
  v3 = result;
  if ( result != nullptr )
  {
    _StackToolsNotify_LoadedLibrary(a1: lib);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004500
// Name: public: virtual void CSys::FreeLibrary(long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSys::FreeLibrary(CSys *this, HMODULE library)
{
  if ( library != nullptr )
    FreeLibrary(hLibModule: library);
}

//------------------------------------------------------------------------------
// Address: 0x10004520
// Name: public: virtual bool CSys::GetExecutableName(char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSys::GetExecutableName(CSys *this, char *out)
{
  HMODULE ModuleHandleA; // eax

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  return GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: out, nSize: 0x100u) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004550
// Name: public: virtual void CSys::ErrorMessage(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSys::ErrorMessage(CSys *this, int level, const char *msg)
{
  MessageBoxA(hWnd: nullptr, lpText: msg, lpCaption: "Half-Life", uType: 0);
  PostQuitMessage(nExitCode: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10004580
// Name: public: virtual void CSys::UpdateStatus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSys::UpdateStatus(CSys *this, int force)
{
  double v2; // st7
  void (__thiscall *UpdateStatus)(IDedicatedServerAPI *, float *, int *, int *, char *, int); // eax
  char szPrompt[256]; // [esp+30h] [ebp-1D4h] BYREF
  char szHostname[128]; // [esp+130h] [ebp-D4h] BYREF
  char szMap[64]; // [esp+1B0h] [ebp-54h] BYREF
  double tCurrent; // [esp+1F0h] [ebp-14h]
  float fps; // [esp+1F8h] [ebp-Ch] BYREF
  int nMax; // [esp+1FCh] [ebp-8h] BYREF
  int n; // [esp+200h] [ebp-4h] BYREF

  if ( engine != nullptr )
  {
    v2 = _Plat_FloatTime(a1: this);
    tCurrent = v2;
    if ( force != 0 || v2 - tLast >= 0.5 )
    {
      UpdateStatus = engine->UpdateStatus;
      tLast = v2;
      UpdateStatus(this: engine, a2: &fps, a3: &n, a4: &nMax, a5: szMap, a6: 64);
      engine->UpdateHostname(this: engine, a2: szHostname, a3: 128);
      CTextConsoleWin32::SetTitle(this: (CSys *)&console, szText: szHostname);
      V_snprintf(pDest: szPrompt, maxLen: 256, pFormat: "%.1f fps %2i/%2i on map %16s", fps, n, nMax, szMap);
      CTextConsoleWin32::SetStatusLine(this: &console, pszStatus: szPrompt);
      CTextConsoleWin32::UpdateStatus(this: &console);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004670
// Name: public: virtual void CSys::ConsoleOutput(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSys::ConsoleOutput(CSys *this, char *string)
{
  if ( g_bVGui )
    VGUIPrintf(msg: string);
  else
    CTextConsole::Print(this: &console, pszMsg: string);
}

//------------------------------------------------------------------------------
// Address: 0x100046A0
// Name: public: virtual void CSys::Printf(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSys::Printf(CSys *this, char *fmt, ...)
{
  char szText[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list params; // [esp+410h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: szText, maxLen: 1024, pFormat: fmt, params);
  this->ConsoleOutput(this, a2: szText);
}

//------------------------------------------------------------------------------
// Address: 0x100046E0
// Name: public: virtual char __near * CSys::ConsoleInput(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSys::ConsoleInput(CSys *this)
{
  return CTextConsoleWin32::GetLine(this: &console);
}

//------------------------------------------------------------------------------
// Address: 0x10004700
// Name: public: virtual bool CSys::CreateConsoleWindow(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSys::CreateConsoleWindow(CSys *this)
{
  if ( !AllocConsole() )
    return 0;
  InitConProc();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004720
// Name: public: virtual void CSys::DestroyConsoleWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSys::DestroyConsoleWindow(CSys *this)
{
  FreeConsole();
  DeinitConProc();
}

//------------------------------------------------------------------------------
// Address: 0x10004730
// Name: public: virtual bool CSys::LoadModules(class CDedicatedAppSystemGroup __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSys::LoadModules(CSys *this, CDedicatedAppSystemGroup *pAppSystemGroup)
{
  bool result; // al
  void *System; // eax
  AppSystemInfo_t appSystems[14]; // [esp+4h] [ebp-70h] BYREF

  appSystems[2].m_pModuleName = "inputsystem.dll";
  appSystems[3].m_pModuleName = "inputsystem.dll";
  appSystems[7].m_pModuleName = "datacache.dll";
  appSystems[8].m_pModuleName = "datacache.dll";
  appSystems[9].m_pModuleName = "datacache.dll";
  appSystems[13].m_pModuleName = defaultValue;
  appSystems[13].m_pInterfaceName = defaultValue;
  appSystems[0].m_pModuleName = "engine.dll";
  appSystems[12].m_pModuleName = "engine.dll";
  appSystems[0].m_pInterfaceName = "VCvarQuery001";
  appSystems[1].m_pModuleName = "soundemittersystem.dll";
  appSystems[1].m_pInterfaceName = "VSoundEmitter003";
  appSystems[2].m_pInterfaceName = "InputSystemVersion001";
  appSystems[3].m_pInterfaceName = "InputStackSystemVersion001";
  appSystems[4].m_pModuleName = "materialsystem.dll";
  appSystems[4].m_pInterfaceName = "VMaterialSystem080";
  appSystems[5].m_pModuleName = "studiorender.dll";
  appSystems[5].m_pInterfaceName = "VStudioRender026";
  appSystems[6].m_pModuleName = "vphysics.dll";
  appSystems[6].m_pInterfaceName = "VPhysics031";
  appSystems[7].m_pInterfaceName = "VDataCache003";
  appSystems[8].m_pInterfaceName = "MDLCache004";
  appSystems[9].m_pInterfaceName = "VStudioDataCache005";
  appSystems[10].m_pModuleName = "vgui2.dll";
  appSystems[10].m_pInterfaceName = "VGUI_ivgui008";
  appSystems[11].m_pModuleName = "vscript.dll";
  appSystems[11].m_pInterfaceName = "VScriptManager009";
  appSystems[12].m_pInterfaceName = "VENGINE_HLDS_API_VERSION002";
  result = CAppSystemGroup::AddSystems(this: pAppSystemGroup, pSystemList: appSystems);
  if ( result )
  {
    engine = (IDedicatedServerAPI *)CAppSystemGroup::FindSystem(
                                      this: pAppSystemGroup,
                                      pSystemName: "VENGINE_HLDS_API_VERSION002");
    System = CAppSystemGroup::FindSystem(this: pAppSystemGroup, pSystemName: "VMaterialSystem080");
    (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)System + 36))(a1: System, a2: "shaderapiempty.dll");
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004840
// Name: bool NET_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_Init()
{
  WSAData wsaData; // [esp+0h] [ebp-290h] BYREF
  char msg[256]; // [esp+190h] [ebp-100h] BYREF

  if ( WSAStartup(wVersionRequested: 0x101u, lpWSAData: &wsaData) == 0 )
    return 1;
  V_snprintf(pDest: msg, maxLen: 256, pFormat: "Winsock 1.1 unavailable...\n");
  sys->Printf(this: sys, a2: "%s", msg);
  _Plat_DebugString(a1: msg);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100048B0
// Name: void NET_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall NET_Shutdown()
{
  return WSACleanup();
}

//------------------------------------------------------------------------------
// Address: 0x100048C0
// Name: void MiniDumpFunction(unsigned int,struct _EXCEPTION_POINTERS __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MiniDumpFunction(unsigned int nExceptionCode, _EXCEPTION_POINTERS *pException)
{
  _SteamAPI_WriteMiniDump(a1: nExceptionCode, a2: pException, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100048E0
// Name: _DedicatedMain
// Source: json
//------------------------------------------------------------------------------
int __cdecl DedicatedMain(HINSTANCE__ *hInstance)
{
  const wchar_t *CommandLineW; // eax
  LPWSTR *v3; // ebx
  int v4; // ecx
  int *v5; // edi
  int v6; // esi
  LPSTR CommandLineA; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // [esp+0h] [ebp-B8h] BYREF
  _OSVERSIONINFOA vinfo; // [esp+Ch] [ebp-ACh] BYREF
  int iret; // [esp+A0h] [ebp-18h]
  int argc; // [esp+A4h] [ebp-14h] BYREF
  int *v15; // [esp+A8h] [ebp-10h]
  int v16; // [esp+B4h] [ebp-4h]

  v15 = &v11;
  SetAppInstance(hInstance);
  vinfo.dwOSVersionInfoSize = 148;
  if ( !GetVersionExA(lpVersionInformation: &vinfo) || vinfo.dwPlatformId == 0 )
    return -1;
  CommandLineW = GetCommandLineW();
  v3 = CommandLineToArgvW(lpCmdLine: CommandLineW, pNumArgs: &argc);
  v5 = (int *)_CommandLine(a1: v4);
  v6 = *v5;
  CommandLineA = GetCommandLineA();
  (*(void (__thiscall **)(int *, LPSTR))(v6 + 4))(a1: v5, a2: CommandLineA);
  if ( (unsigned __int8)_Plat_IsInDebugSession() != 0
    || (v9 = _CommandLine(a1: v8),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 40))(a1: v9, a2: "-nominidumps") != 0) )
  {
    v10 = main();
  }
  else
  {
    _set_se_translator(pNew: MiniDumpFunction);
    v16 = 0;
    v10 = main();
    iret = v10;
    v16 = -1;
  }
  GlobalFree(hMem: v3);
  return v10;
}
