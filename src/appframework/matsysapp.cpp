// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: appframework/matsysapp.cpp
// Functions: 9
// ============================================================

#include "appframework\matsysapp.h"

//------------------------------------------------------------------------------
// Address: 0x00404710
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004047D0
// Name: public: virtual bool CMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::Create(CMatSysApp *this)
{
  IAppSystem *System; // eax
  AppSystemInfo_t appSystems[3]; // [esp+4h] [ebp-18h] BYREF

  appSystems[2].m_pModuleName = defaultValue;
  appSystems[2].m_pInterfaceName = defaultValue;
  appSystems[0].m_pModuleName = "inputsystem.dll";
  appSystems[0].m_pInterfaceName = "InputSystemVersion001";
  appSystems[1].m_pModuleName = "materialsystem.dll";
  appSystems[1].m_pInterfaceName = "VMaterialSystem080";
  if ( CAppSystemGroup::AddSystems(this, pSystemList: appSystems) == 0 )
    return 0;
  System = CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem080");
  if ( System == nullptr )
  {
    _Warning(a1: "CMatSysApp::Create: Unable to connect to necessary interface!\n");
    return 0;
  }
  ((void (__thiscall *)(IAppSystem *, const char *))System->__vftable[1].Disconnect)(a1: System, a2: "shaderapidx9.dll");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404850
// Name: protected: void CMatSysApp::AppPumpMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::AppPumpMessages(CMatSysApp *this)
{
  g_pInputSystem->PollInputState(this: g_pInputSystem);
}

//------------------------------------------------------------------------------
// Address: 0x00404860
// Name: protected: bool CMatSysApp::SetupSearchPaths(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetupSearchPaths(
        CMatSysApp *this,
        const char *pStartingDir,
        bool bOnlyUseStartingDir,
        bool bIsTool)
{
  char result; // al
  IFileSystem_vtbl *v6; // esi
  char *GameInfoPath; // eax

  result = CSteamAppSystemGroup::SetupSearchPaths(this, pStartingDir, bOnlyUseStartingDir, bIsTool);
  if ( result != 0 )
  {
    v6 = g_pFullFileSystem->IAppSystem::__vftable;
    GameInfoPath = CSteamAppSystemGroup::GetGameInfoPath(this);
    v6->AddSearchPath(this: g_pFullFileSystem, a2: GameInfoPath, a3: "SKIN", a4: PATH_ADD_TO_HEAD);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004048B0
// Name: public: virtual bool CMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CMatSysApp::PreInit@<al>(CMatSysApp *this@<ecx>, int a2@<ebx>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  CMatSysApp_vtbl *v7; // ebx
  const char *(__thiscall *GetAppName)(CMatSysApp *); // eax
  int v9; // edx
  void *AppInstance; // eax
  void *v11; // eax
  int v12; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // [esp-Ch] [ebp-24h]
  int v17; // [esp-Ch] [ebp-24h]
  const char *pAdapterString; // [esp+4h] [ebp-14h] BYREF
  int bWindowed; // [esp+8h] [ebp-10h]
  int iWidth; // [esp+Ch] [ebp-Ch] BYREF
  int iHeight; // [esp+10h] [ebp-8h]
  const char *pArg; // [esp+14h] [ebp-4h] BYREF

  iWidth = (int)CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&iWidth, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&iWidth, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || g_pMaterialSystem == nullptr || g_pInputSystem == nullptr )
  {
    _Warning(a1: "CMatSysApp::PreInit: Unable to connect to necessary interface!\n");
  }
  else if ( CMatSysApp::SetupSearchPaths(this, pStartingDir: nullptr, bOnlyUseStartingDir: false, bIsTool: true) != 0 )
  {
    iWidth = 1024;
    iHeight = 768;
    v3 = _CommandLine();
    LOBYTE(bWindowed) = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(
                          a1: v3,
                          a2: "-fullscreen",
                          a3: 0) == 0;
    v4 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-width", a3: &pArg) != 0 )
      iWidth = atoi(nptr: pArg);
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v5 + 12))(
           a1: v5,
           a2: "-height",
           a3: &pArg) != 0 )
      iHeight = atoi(nptr: pArg);
    v6 = iWidth;
    v7 = this->__vftable;
    v16 = iHeight;
    GetAppName = this->GetAppName;
    this->m_nHeight = iHeight;
    v9 = bWindowed;
    this->m_nWidth = v6;
    v17 = ((int (__thiscall *)(CMatSysApp *, int, int, int))GetAppName)(a1: this, a2: v9, a3: v6, a4: v16);
    AppInstance = GetAppInstance();
    v11 = (void *)((int (__thiscall *)(CMatSysApp *, void *, int))v7->CreateAppWindow)(
                    a1: this,
                    a2: AppInstance,
                    a3: v17);
    v12 = 0;
    this->m_HWnd = v11;
    if ( v11 == nullptr )
      return 0;
    ((void (__thiscall *)(IInputSystem *, void *, _DWORD, int))g_pInputSystem->AttachToWindow)(
      a1: g_pInputSystem,
      a2: v11,
      a3: 0,
      a4: a2);
    iWidth = 0;
    v14 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v14 + 12))(
           a1: v14,
           a2: "-adapter",
           a3: &pAdapterString) != 0 )
      iWidth = atoi(nptr: pAdapterString);
    v15 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v15 + 12))(a1: v15, a2: "-ref", a3: 0) != 0 )
      v12 = 4;
    if ( this->AppUsesReadPixels(this) )
      v12 |= 2u;
    g_pMaterialSystem->SetAdapter(this: g_pMaterialSystem, a2: iWidth, a3: v12);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404A80
// Name: public: virtual void CMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::PostShutdown(CMatSysApp *this)
{
  if ( g_pInputSystem != nullptr )
    g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00404AA0
// Name: public: int CMatSysApp::GetWindowWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatSysApp::GetWindowWidth(CMatSysApp *this)
{
  return this->m_nWidth;
}

//------------------------------------------------------------------------------
// Address: 0x00404AC0
// Name: protected: bool CMatSysApp::SetVideoMode(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetVideoMode(CMatSysApp *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  void *m_HWnd; // eax
  int v9; // eax
  char pModPath[260]; // [esp+Ch] [ebp-188h] BYREF
  char pModName[32]; // [esp+110h] [ebp-84h] BYREF
  MaterialSystem_Config_t config; // [esp+130h] [ebp-64h] BYREF

  MaterialSystem_Config_t::MaterialSystem_Config_t(this: &config);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-fullscreen", a3: 0) != 0 )
    config.m_Flags &= ~1u;
  else
    config.m_Flags |= 1u;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-resizing", a3: 0) != 0 )
    config.m_Flags |= 2u;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-mat_vsync", a3: 0) != 0 )
    config.m_Flags &= ~8u;
  v5 = _CommandLine();
  config.m_nAASamples = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 28))(
                          a1: v5,
                          a2: "-mat_antialias",
                          a3: 1);
  v6 = _CommandLine();
  config.m_nAAQuality = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 28))(
                          a1: v6,
                          a2: "-mat_aaquality",
                          a3: 0);
  config.m_Flags |= 0x10u;
  config.m_VideoMode.m_Format = IMAGE_FORMAT_BGRX8888;
  m_HWnd = this->m_HWnd;
  config.m_VideoMode.m_Height = 0;
  config.m_VideoMode.m_Width = 0;
  config.m_VideoMode.m_RefreshRate = 0;
  if ( g_pMaterialSystem->SetMode(this: g_pMaterialSystem, a2: m_HWnd, a3: &config) )
  {
    V_snprintf(pDest: pModPath, maxLen: 260, pFormat: defaultValue);
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pModPath, a5: 260);
    V_StripTrailingSlash(ppath: pModPath);
    V_FileBase(in: pModPath, out: pModName, maxlen: 32);
    v9 = 0;
    if ( pModName[0] != 0 )
    {
      while ( pModName[v9] != 95 )
      {
        if ( pModName[++v9] == 0 )
          goto LABEL_15;
      }
      pModName[v9] = 0;
    }
LABEL_15:
    UpdateSystemLevel(nCPULevel: 2, nGPULevel: 3, nMemLevel: 2, nGPUMemLevel: 2, bVGUIIsSplitscreen: false, pModName);
    g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &config, a3: false);
    return 1;
  }
  else
  {
    _Error(a1: "Unable to set mode\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404C60
// Name: public: CMatSysApp::CMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CMatSysApp *__thiscall CMatSysApp::CMatSysApp(CMatSysApp *this)
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(this, pFileSystem: nullptr, pAppSystemParent: nullptr);
  this->__vftable = (CMatSysApp_vtbl *)&CMatSysApp::`vftable';
  return this;
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00405D70
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405E30
// Name: public: virtual bool CMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::Create(CMatSysApp *this)
{
  IAppSystem *System; // eax
  AppSystemInfo_t appSystems[3]; // [esp+4h] [ebp-18h] BYREF

  appSystems[2].m_pModuleName = defaultValue;
  appSystems[2].m_pInterfaceName = defaultValue;
  appSystems[0].m_pModuleName = "inputsystem.dll";
  appSystems[0].m_pInterfaceName = "InputSystemVersion001";
  appSystems[1].m_pModuleName = "materialsystem.dll";
  appSystems[1].m_pInterfaceName = "VMaterialSystem080";
  if ( CAppSystemGroup::AddSystems(this, pSystemList: appSystems) == 0 )
    return 0;
  System = CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem080");
  if ( System == nullptr )
  {
    _Warning(a1: "CMatSysApp::Create: Unable to connect to necessary interface!\n");
    return 0;
  }
  ((void (__thiscall *)(IAppSystem *, const char *))System->__vftable[1].Disconnect)(a1: System, a2: "shaderapidx9.dll");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405EB0
// Name: protected: void CMatSysApp::AppPumpMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::AppPumpMessages(CMatSysApp *this)
{
  g_pInputSystem->PollInputState(this: g_pInputSystem);
}

//------------------------------------------------------------------------------
// Address: 0x00405EC0
// Name: protected: bool CMatSysApp::SetupSearchPaths(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetupSearchPaths(
        CMatSysApp *this,
        const char *pStartingDir,
        bool bOnlyUseStartingDir,
        bool bIsTool)
{
  char result; // al
  IFileSystem_vtbl *v6; // esi
  char *GameInfoPath; // eax

  result = CSteamAppSystemGroup::SetupSearchPaths(this, pStartingDir, bOnlyUseStartingDir, bIsTool);
  if ( result != 0 )
  {
    v6 = g_pFullFileSystem->IAppSystem::__vftable;
    GameInfoPath = CSteamAppSystemGroup::GetGameInfoPath(this);
    v6->AddSearchPath(this: g_pFullFileSystem, a2: GameInfoPath, a3: "SKIN", a4: PATH_ADD_TO_HEAD);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405F10
// Name: public: virtual bool CMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CMatSysApp::PreInit@<al>(CMatSysApp *this@<ecx>, int a2@<ebx>)
{
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  CMatSysApp_vtbl *v10; // ebx
  const char *(__thiscall *GetAppName)(CMatSysApp *); // eax
  int v12; // edx
  void *AppInstance; // eax
  void *v14; // eax
  int v15; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // [esp-Ch] [ebp-24h]
  int v22; // [esp-Ch] [ebp-24h]
  const char *pAdapterString; // [esp+4h] [ebp-14h] BYREF
  int bWindowed; // [esp+8h] [ebp-10h]
  int iWidth; // [esp+Ch] [ebp-Ch] BYREF
  int iHeight; // [esp+10h] [ebp-8h]
  const char *pArg; // [esp+14h] [ebp-4h] BYREF

  iWidth = (int)CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&iWidth, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&iWidth, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || g_pMaterialSystem == nullptr || g_pInputSystem == nullptr )
  {
    _Warning(a1: "CMatSysApp::PreInit: Unable to connect to necessary interface!\n");
  }
  else if ( CMatSysApp::SetupSearchPaths(this, pStartingDir: nullptr, bOnlyUseStartingDir: false, bIsTool: true) != 0 )
  {
    iWidth = 1024;
    iHeight = 768;
    v4 = _CommandLine(a1: v3);
    LOBYTE(v5) = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(
                   a1: v4,
                   a2: "-fullscreen",
                   a3: 0) == 0;
    LOBYTE(bWindowed) = v5;
    v6 = _CommandLine(a1: v5);
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-width", a3: &pArg) != 0 )
      iWidth = atoi(nptr: pArg);
    v8 = _CommandLine(a1: v7);
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v8 + 12))(
           a1: v8,
           a2: "-height",
           a3: &pArg) != 0 )
      iHeight = atoi(nptr: pArg);
    v9 = iWidth;
    v10 = this->__vftable;
    v21 = iHeight;
    GetAppName = this->GetAppName;
    this->m_nHeight = iHeight;
    v12 = bWindowed;
    this->m_nWidth = v9;
    v22 = ((int (__thiscall *)(CMatSysApp *, int, int, int))GetAppName)(a1: this, a2: v12, a3: v9, a4: v21);
    AppInstance = GetAppInstance();
    v14 = (void *)((int (__thiscall *)(CMatSysApp *, void *, int))v10->CreateAppWindow)(
                    a1: this,
                    a2: AppInstance,
                    a3: v22);
    v15 = 0;
    this->m_HWnd = v14;
    if ( v14 == nullptr )
      return 0;
    ((void (__thiscall *)(IInputSystem *, void *, _DWORD, int))g_pInputSystem->AttachToWindow)(
      a1: g_pInputSystem,
      a2: v14,
      a3: 0,
      a4: a2);
    iWidth = 0;
    v18 = _CommandLine(a1: v17);
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v18 + 12))(
           a1: v18,
           a2: "-adapter",
           a3: &pAdapterString) != 0 )
      iWidth = atoi(nptr: pAdapterString);
    v20 = _CommandLine(a1: v19);
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v20 + 12))(a1: v20, a2: "-ref", a3: 0) != 0 )
      v15 = 4;
    if ( this->AppUsesReadPixels(this) )
      v15 |= 2u;
    g_pMaterialSystem->SetAdapter(this: g_pMaterialSystem, a2: iWidth, a3: v15);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004060E0
// Name: public: virtual void CMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::PostShutdown(CMatSysApp *this)
{
  if ( g_pInputSystem != nullptr )
    g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00406100
// Name: public: int CMatSysApp::GetWindowWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatSysApp::GetWindowWidth(CMatSysApp *this)
{
  return this->m_nWidth;
}

//------------------------------------------------------------------------------
// Address: 0x00406120
// Name: protected: bool CMatSysApp::SetVideoMode(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetVideoMode(CMatSysApp *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *m_HWnd; // eax
  int v14; // eax
  char pModPath[260]; // [esp+Ch] [ebp-188h] BYREF
  char pModName[32]; // [esp+110h] [ebp-84h] BYREF
  MaterialSystem_Config_t config; // [esp+130h] [ebp-64h] BYREF

  MaterialSystem_Config_t::MaterialSystem_Config_t(this: &config);
  v3 = _CommandLine(a1: v2);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-fullscreen", a3: 0) != 0 )
    config.m_Flags &= ~1u;
  else
    config.m_Flags |= 1u;
  v5 = _CommandLine(a1: v4);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-resizing", a3: 0) != 0 )
    config.m_Flags |= 2u;
  v7 = _CommandLine(a1: v6);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v7 + 12))(a1: v7, a2: "-mat_vsync", a3: 0) != 0 )
    config.m_Flags &= ~8u;
  v9 = _CommandLine(a1: v8);
  config.m_nAASamples = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 28))(
                          a1: v9,
                          a2: "-mat_antialias",
                          a3: 1);
  v11 = _CommandLine(a1: v10);
  config.m_nAAQuality = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v11 + 28))(
                          a1: v11,
                          a2: "-mat_aaquality",
                          a3: 0);
  config.m_Flags |= 0x10u;
  config.m_VideoMode.m_Format = IMAGE_FORMAT_BGRX8888;
  m_HWnd = this->m_HWnd;
  config.m_VideoMode.m_Height = 0;
  config.m_VideoMode.m_Width = 0;
  config.m_VideoMode.m_RefreshRate = 0;
  if ( g_pMaterialSystem->SetMode(this: g_pMaterialSystem, a2: m_HWnd, a3: &config) )
  {
    V_snprintf(pDest: pModPath, maxLen: 260, pFormat: defaultValue);
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pModPath, a5: 260);
    V_StripTrailingSlash(ppath: pModPath);
    V_FileBase(in: pModPath, out: pModName, maxlen: 32);
    v14 = 0;
    if ( pModName[0] != 0 )
    {
      while ( pModName[v14] != 95 )
      {
        if ( pModName[++v14] == 0 )
          goto LABEL_15;
      }
      pModName[v14] = 0;
    }
LABEL_15:
    UpdateSystemLevel(nCPULevel: 2, nGPULevel: 3, nMemLevel: 2, nGPUMemLevel: 2, bVGUIIsSplitscreen: false, pModName);
    g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &config, a3: false);
    return 1;
  }
  else
  {
    _Error(a1: "Unable to set mode\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004062C0
// Name: public: CMatSysApp::CMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CMatSysApp *__thiscall CMatSysApp::CMatSysApp(CMatSysApp *this)
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(this, pFileSystem: nullptr, pAppSystemParent: nullptr);
  this->__vftable = (CMatSysApp_vtbl *)&CMatSysApp::`vftable';
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004068D0
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00406990
// Name: public: virtual bool CMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::Create(CMatSysApp *this)
{
  void *System; // eax
  AppSystemInfo_t appSystems[3]; // [esp+4h] [ebp-18h] BYREF

  appSystems[2].m_pModuleName = defaultValue;
  appSystems[2].m_pInterfaceName = defaultValue;
  appSystems[0].m_pModuleName = "inputsystem.dll";
  appSystems[0].m_pInterfaceName = "InputSystemVersion001";
  appSystems[1].m_pModuleName = "materialsystem.dll";
  appSystems[1].m_pInterfaceName = "VMaterialSystem080";
  if ( CAppSystemGroup::AddSystems(this, pSystemList: appSystems) == 0 )
    return 0;
  System = CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem080");
  if ( System == nullptr )
  {
    _Warning(a1: "CMatSysApp::Create: Unable to connect to necessary interface!\n");
    return 0;
  }
  (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)System + 36))(a1: System, a2: "shaderapidx9.dll");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406A10
// Name: protected: void CMatSysApp::AppPumpMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::AppPumpMessages(CMatSysApp *this)
{
  g_pInputSystem->PollInputState(this: g_pInputSystem);
}

//------------------------------------------------------------------------------
// Address: 0x00406A20
// Name: protected: bool CMatSysApp::SetupSearchPaths(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetupSearchPaths(
        CMatSysApp *this,
        const char *pStartingDir,
        bool bOnlyUseStartingDir,
        bool bIsTool)
{
  char result; // al
  IFileSystem_vtbl *v6; // esi
  char *GameInfoPath; // eax

  result = CSteamAppSystemGroup::SetupSearchPaths(this, pStartingDir, bOnlyUseStartingDir, bIsTool);
  if ( result != 0 )
  {
    v6 = g_pFullFileSystem->IAppSystem::__vftable;
    GameInfoPath = CSteamAppSystemGroup::GetGameInfoPath(this);
    v6->AddSearchPath(this: g_pFullFileSystem, a2: GameInfoPath, a3: "SKIN", a4: PATH_ADD_TO_HEAD);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406A70
// Name: public: virtual bool CMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CMatSysApp::PreInit@<al>(CMatSysApp *this@<ecx>, int a2@<ebx>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  CMatSysApp_vtbl *v7; // ebx
  const char *(__thiscall *GetAppName)(CMatSysApp *); // eax
  int v9; // edx
  void *AppInstance; // eax
  void *v11; // eax
  int v12; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // [esp-Ch] [ebp-24h]
  int v17; // [esp-Ch] [ebp-24h]
  const char *pAdapterString; // [esp+4h] [ebp-14h] BYREF
  int bWindowed; // [esp+8h] [ebp-10h]
  int iWidth; // [esp+Ch] [ebp-Ch] BYREF
  int iHeight; // [esp+10h] [ebp-8h]
  const char *pArg; // [esp+14h] [ebp-4h] BYREF

  iWidth = (int)CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&iWidth, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&iWidth, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || g_pMaterialSystem == nullptr || g_pInputSystem == nullptr )
  {
    _Warning(a1: "CMatSysApp::PreInit: Unable to connect to necessary interface!\n");
  }
  else if ( CMatSysApp::SetupSearchPaths(this, pStartingDir: nullptr, bOnlyUseStartingDir: false, bIsTool: true) != 0 )
  {
    iWidth = 1024;
    iHeight = 768;
    v3 = _CommandLine();
    LOBYTE(bWindowed) = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(
                          a1: v3,
                          a2: "-fullscreen",
                          a3: 0) == 0;
    v4 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-width", a3: &pArg) != 0 )
      iWidth = atoi(nptr: pArg);
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v5 + 12))(
           a1: v5,
           a2: "-height",
           a3: &pArg) != 0 )
      iHeight = atoi(nptr: pArg);
    v6 = iWidth;
    v7 = this->__vftable;
    v16 = iHeight;
    GetAppName = this->GetAppName;
    this->m_nHeight = iHeight;
    v9 = bWindowed;
    this->m_nWidth = v6;
    v17 = ((int (__thiscall *)(CMatSysApp *, int, int, int))GetAppName)(a1: this, a2: v9, a3: v6, a4: v16);
    AppInstance = GetAppInstance();
    v11 = (void *)((int (__thiscall *)(CMatSysApp *, void *, int))v7->CreateAppWindow)(
                    a1: this,
                    a2: AppInstance,
                    a3: v17);
    v12 = 0;
    this->m_HWnd = v11;
    if ( v11 == nullptr )
      return 0;
    ((void (__thiscall *)(IInputSystem *, void *, _DWORD, int))g_pInputSystem->AttachToWindow)(
      a1: g_pInputSystem,
      a2: v11,
      a3: 0,
      a4: a2);
    iWidth = 0;
    v14 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v14 + 12))(
           a1: v14,
           a2: "-adapter",
           a3: &pAdapterString) != 0 )
      iWidth = atoi(nptr: pAdapterString);
    v15 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v15 + 12))(a1: v15, a2: "-ref", a3: 0) != 0 )
      v12 = 4;
    if ( this->AppUsesReadPixels(this) )
      v12 |= 2u;
    g_pMaterialSystem->SetAdapter(this: g_pMaterialSystem, a2: iWidth, a3: v12);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406C40
// Name: public: virtual void CMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::PostShutdown(CMatSysApp *this)
{
  if ( g_pInputSystem != nullptr )
    g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00406C60
// Name: protected: bool CMatSysApp::SetVideoMode(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetVideoMode(CMatSysApp *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  void *m_HWnd; // eax
  int v9; // eax
  char pModPath[260]; // [esp+Ch] [ebp-188h] BYREF
  char pModName[32]; // [esp+110h] [ebp-84h] BYREF
  MaterialSystem_Config_t config; // [esp+130h] [ebp-64h] BYREF

  MaterialSystem_Config_t::MaterialSystem_Config_t(this: &config);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-fullscreen", a3: 0) != 0 )
    config.m_Flags &= ~1u;
  else
    config.m_Flags |= 1u;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-resizing", a3: 0) != 0 )
    config.m_Flags |= 2u;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-mat_vsync", a3: 0) != 0 )
    config.m_Flags &= ~8u;
  v5 = _CommandLine();
  config.m_nAASamples = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 28))(
                          a1: v5,
                          a2: "-mat_antialias",
                          a3: 1);
  v6 = _CommandLine();
  config.m_nAAQuality = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 28))(
                          a1: v6,
                          a2: "-mat_aaquality",
                          a3: 0);
  config.m_Flags |= 0x10u;
  config.m_VideoMode.m_Format = IMAGE_FORMAT_BGRX8888;
  m_HWnd = this->m_HWnd;
  config.m_VideoMode.m_Height = 0;
  config.m_VideoMode.m_Width = 0;
  config.m_VideoMode.m_RefreshRate = 0;
  if ( g_pMaterialSystem->SetMode(this: g_pMaterialSystem, a2: m_HWnd, a3: &config) )
  {
    V_snprintf(pDest: pModPath, maxLen: 260, pFormat: defaultValue);
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pModPath, a5: 260);
    V_StripTrailingSlash(ppath: pModPath);
    V_FileBase(in: pModPath, out: pModName, maxlen: 32);
    v9 = 0;
    if ( pModName[0] != 0 )
    {
      while ( pModName[v9] != 95 )
      {
        if ( pModName[++v9] == 0 )
          goto LABEL_15;
      }
      pModName[v9] = 0;
    }
LABEL_15:
    UpdateSystemLevel(nCPULevel: 2, nGPULevel: 3, nMemLevel: 2, nGPUMemLevel: 2, bVGUIIsSplitscreen: false, pModName);
    g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &config, a3: false);
    return 1;
  }
  else
  {
    _Error(a1: "Unable to set mode\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406E00
// Name: public: CMatSysApp::CMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CMatSysApp *__thiscall CMatSysApp::CMatSysApp(CMatSysApp *this)
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(this, pFileSystem: nullptr, pAppSystemParent: nullptr);
  this->__vftable = (CMatSysApp_vtbl *)&CMatSysApp::`vftable';
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0040A090
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040A150
// Name: public: virtual bool CMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::Create(CMatSysApp *this)
{
  IAppSystem *System; // eax
  AppSystemInfo_t appSystems[3]; // [esp+4h] [ebp-18h] BYREF

  appSystems[2].m_pModuleName = defaultValue;
  appSystems[2].m_pInterfaceName = defaultValue;
  appSystems[0].m_pModuleName = "inputsystem.dll";
  appSystems[0].m_pInterfaceName = "InputSystemVersion001";
  appSystems[1].m_pModuleName = "materialsystem.dll";
  appSystems[1].m_pInterfaceName = "VMaterialSystem080";
  if ( CAppSystemGroup::AddSystems(this, pSystemList: appSystems) == 0 )
    return 0;
  System = CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem080");
  if ( System == nullptr )
  {
    _Warning(a1: "CMatSysApp::Create: Unable to connect to necessary interface!\n");
    return 0;
  }
  ((void (__thiscall *)(IAppSystem *, const char *))System->__vftable[1].Disconnect)(a1: System, a2: "shaderapidx9.dll");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A1D0
// Name: protected: void CMatSysApp::AppPumpMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::AppPumpMessages(CMatSysApp *this)
{
  g_pInputSystem->PollInputState(this: g_pInputSystem);
}

//------------------------------------------------------------------------------
// Address: 0x0040A1E0
// Name: protected: bool CMatSysApp::SetupSearchPaths(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetupSearchPaths(
        CMatSysApp *this,
        const char *pStartingDir,
        bool bOnlyUseStartingDir,
        bool bIsTool)
{
  char result; // al
  IFileSystem_vtbl *v6; // esi
  char *GameInfoPath; // eax

  result = CSteamAppSystemGroup::SetupSearchPaths(this, pStartingDir, bOnlyUseStartingDir, bIsTool);
  if ( result != 0 )
  {
    v6 = g_pFullFileSystem->IAppSystem::__vftable;
    GameInfoPath = CSteamAppSystemGroup::GetGameInfoPath(this);
    v6->AddSearchPath(this: g_pFullFileSystem, a2: GameInfoPath, a3: "SKIN", a4: PATH_ADD_TO_HEAD);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A230
// Name: public: virtual bool CMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CMatSysApp::PreInit@<al>(CMatSysApp *this@<ecx>, int a2@<ebx>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  CMatSysApp_vtbl *v7; // ebx
  const char *(__thiscall *GetAppName)(CMatSysApp *); // eax
  int v9; // edx
  void *AppInstance; // eax
  void *v11; // eax
  int v12; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // [esp-Ch] [ebp-24h]
  int v17; // [esp-Ch] [ebp-24h]
  const char *pAdapterString; // [esp+4h] [ebp-14h] BYREF
  int bWindowed; // [esp+8h] [ebp-10h]
  int iWidth; // [esp+Ch] [ebp-Ch] BYREF
  int iHeight; // [esp+10h] [ebp-8h]
  const char *pArg; // [esp+14h] [ebp-4h] BYREF

  iWidth = (int)CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&iWidth, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&iWidth, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || g_pMaterialSystem == nullptr || g_pInputSystem == nullptr )
  {
    _Warning(a1: "CMatSysApp::PreInit: Unable to connect to necessary interface!\n");
  }
  else if ( CMatSysApp::SetupSearchPaths(this, pStartingDir: nullptr, bOnlyUseStartingDir: false, bIsTool: true) != 0 )
  {
    iWidth = 1024;
    iHeight = 768;
    v3 = _CommandLine();
    LOBYTE(bWindowed) = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(
                          a1: v3,
                          a2: "-fullscreen",
                          a3: 0) == 0;
    v4 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-width", a3: &pArg) != 0 )
      iWidth = atoi(nptr: pArg);
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v5 + 12))(
           a1: v5,
           a2: "-height",
           a3: &pArg) != 0 )
      iHeight = atoi(nptr: pArg);
    v6 = iWidth;
    v7 = this->__vftable;
    v16 = iHeight;
    GetAppName = this->GetAppName;
    this->m_nHeight = iHeight;
    v9 = bWindowed;
    this->m_nWidth = v6;
    v17 = ((int (__thiscall *)(CMatSysApp *, int, int, int))GetAppName)(a1: this, a2: v9, a3: v6, a4: v16);
    AppInstance = GetAppInstance();
    v11 = (void *)((int (__thiscall *)(CMatSysApp *, void *, int))v7->CreateAppWindow)(
                    a1: this,
                    a2: AppInstance,
                    a3: v17);
    v12 = 0;
    this->m_HWnd = v11;
    if ( v11 == nullptr )
      return 0;
    ((void (__thiscall *)(IInputSystem *, void *, _DWORD, int))g_pInputSystem->AttachToWindow)(
      a1: g_pInputSystem,
      a2: v11,
      a3: 0,
      a4: a2);
    iWidth = 0;
    v14 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v14 + 12))(
           a1: v14,
           a2: "-adapter",
           a3: &pAdapterString) != 0 )
      iWidth = atoi(nptr: pAdapterString);
    v15 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v15 + 12))(a1: v15, a2: "-ref", a3: 0) != 0 )
      v12 = 4;
    if ( this->AppUsesReadPixels(this) )
      v12 |= 2u;
    g_pMaterialSystem->SetAdapter(this: g_pMaterialSystem, a2: iWidth, a3: v12);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A400
// Name: public: virtual void CMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::PostShutdown(CMatSysApp *this)
{
  if ( g_pInputSystem != nullptr )
    g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x0040A420
// Name: protected: bool CMatSysApp::SetVideoMode(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetVideoMode(CMatSysApp *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  void *m_HWnd; // eax
  int v9; // eax
  char pModPath[260]; // [esp+Ch] [ebp-188h] BYREF
  char pModName[32]; // [esp+110h] [ebp-84h] BYREF
  MaterialSystem_Config_t config; // [esp+130h] [ebp-64h] BYREF

  MaterialSystem_Config_t::MaterialSystem_Config_t(this: &config);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-fullscreen", a3: 0) != 0 )
    config.m_Flags &= ~1u;
  else
    config.m_Flags |= 1u;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-resizing", a3: 0) != 0 )
    config.m_Flags |= 2u;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-mat_vsync", a3: 0) != 0 )
    config.m_Flags &= ~8u;
  v5 = _CommandLine();
  config.m_nAASamples = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 28))(
                          a1: v5,
                          a2: "-mat_antialias",
                          a3: 1);
  v6 = _CommandLine();
  config.m_nAAQuality = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 28))(
                          a1: v6,
                          a2: "-mat_aaquality",
                          a3: 0);
  config.m_Flags |= 0x10u;
  config.m_VideoMode.m_Format = IMAGE_FORMAT_BGRX8888;
  m_HWnd = this->m_HWnd;
  config.m_VideoMode.m_Height = 0;
  config.m_VideoMode.m_Width = 0;
  config.m_VideoMode.m_RefreshRate = 0;
  if ( g_pMaterialSystem->SetMode(this: g_pMaterialSystem, a2: m_HWnd, a3: &config) )
  {
    V_snprintf(pDest: pModPath, maxLen: 260, pFormat: defaultValue);
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pModPath, a5: 260);
    V_StripTrailingSlash(ppath: pModPath);
    V_FileBase(in: pModPath, out: pModName, maxlen: 32);
    v9 = 0;
    if ( pModName[0] != 0 )
    {
      while ( pModName[v9] != 95 )
      {
        if ( pModName[++v9] == 0 )
          goto LABEL_15;
      }
      pModName[v9] = 0;
    }
LABEL_15:
    UpdateSystemLevel(nCPULevel: 2, nGPULevel: 3, nMemLevel: 2, nGPUMemLevel: 2, bVGUIIsSplitscreen: false, pModName);
    g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &config, a3: false);
    return 1;
  }
  else
  {
    _Error(a1: "Unable to set mode\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A5C0
// Name: public: CMatSysApp::CMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CMatSysApp *__thiscall CMatSysApp::CMatSysApp(CMatSysApp *this)
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(this, pFileSystem: nullptr, pAppSystemParent: nullptr);
  this->__vftable = (CMatSysApp_vtbl *)&CMatSysApp::`vftable';
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x0040F8F0
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F9B0
// Name: public: virtual bool CMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::Create(CMatSysApp *this)
{
  IAppSystem *System; // eax
  AppSystemInfo_t appSystems[3]; // [esp+4h] [ebp-18h] BYREF

  appSystems[2].m_pModuleName = &defaultValue;
  appSystems[2].m_pInterfaceName = &defaultValue;
  appSystems[0].m_pModuleName = "inputsystem.dll";
  appSystems[0].m_pInterfaceName = "InputSystemVersion001";
  appSystems[1].m_pModuleName = "materialsystem.dll";
  appSystems[1].m_pInterfaceName = "VMaterialSystem080";
  if ( CAppSystemGroup::AddSystems(this, pSystemList: appSystems) == 0 )
    return 0;
  System = CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem080");
  if ( System == nullptr )
  {
    _Warning(a1: "CMatSysApp::Create: Unable to connect to necessary interface!\n");
    return 0;
  }
  ((void (__thiscall *)(IAppSystem *, const char *))System->__vftable[1].Disconnect)(a1: System, a2: "shaderapidx9.dll");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040FA30
// Name: protected: void CMatSysApp::AppPumpMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::AppPumpMessages(CMatSysApp *this)
{
  g_pInputSystem->PollInputState(this: g_pInputSystem);
}

//------------------------------------------------------------------------------
// Address: 0x0040FA40
// Name: protected: bool CMatSysApp::SetupSearchPaths(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetupSearchPaths(
        CMatSysApp *this,
        const char *pStartingDir,
        bool bOnlyUseStartingDir,
        bool bIsTool)
{
  char result; // al
  IFileSystem_vtbl *v6; // esi
  char *GameInfoPath; // eax

  result = CSteamAppSystemGroup::SetupSearchPaths(this, pStartingDir, bOnlyUseStartingDir, bIsTool);
  if ( result != 0 )
  {
    v6 = g_pFullFileSystem->IAppSystem::__vftable;
    GameInfoPath = CSteamAppSystemGroup::GetGameInfoPath(this);
    v6->AddSearchPath(this: g_pFullFileSystem, a2: GameInfoPath, a3: "SKIN", a4: PATH_ADD_TO_HEAD);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040FA90
// Name: public: virtual bool CMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CMatSysApp::PreInit@<al>(CMatSysApp *this@<ecx>, int a2@<ebx>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  CMatSysApp_vtbl *v7; // ebx
  const char *(__thiscall *GetAppName)(CMatSysApp *); // eax
  int v9; // edx
  void *AppInstance; // eax
  void *v11; // eax
  int v12; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // [esp-Ch] [ebp-24h]
  int v17; // [esp-Ch] [ebp-24h]
  const char *pAdapterString; // [esp+4h] [ebp-14h] BYREF
  int bWindowed; // [esp+8h] [ebp-10h]
  int iWidth; // [esp+Ch] [ebp-Ch] BYREF
  int iHeight; // [esp+10h] [ebp-8h]
  const char *pArg; // [esp+14h] [ebp-4h] BYREF

  iWidth = (int)CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&iWidth, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&iWidth, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || g_pMaterialSystem == nullptr || g_pInputSystem == nullptr )
  {
    _Warning(a1: "CMatSysApp::PreInit: Unable to connect to necessary interface!\n");
  }
  else if ( CMatSysApp::SetupSearchPaths(this, pStartingDir: nullptr, bOnlyUseStartingDir: false, bIsTool: true) != 0 )
  {
    iWidth = 1024;
    iHeight = 768;
    v3 = _CommandLine();
    LOBYTE(bWindowed) = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(
                          a1: v3,
                          a2: "-fullscreen",
                          a3: 0) == 0;
    v4 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-width", a3: &pArg) != 0 )
      iWidth = atoi(nptr: pArg);
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v5 + 12))(
           a1: v5,
           a2: "-height",
           a3: &pArg) != 0 )
      iHeight = atoi(nptr: pArg);
    v6 = iWidth;
    v7 = this->__vftable;
    v16 = iHeight;
    GetAppName = this->GetAppName;
    this->m_nHeight = iHeight;
    v9 = bWindowed;
    this->m_nWidth = v6;
    v17 = ((int (__thiscall *)(CMatSysApp *, int, int, int))GetAppName)(a1: this, a2: v9, a3: v6, a4: v16);
    AppInstance = GetAppInstance();
    v11 = (void *)((int (__thiscall *)(CMatSysApp *, void *, int))v7->CreateAppWindow)(
                    a1: this,
                    a2: AppInstance,
                    a3: v17);
    v12 = 0;
    this->m_HWnd = v11;
    if ( v11 == nullptr )
      return 0;
    ((void (__thiscall *)(IInputSystem *, void *, _DWORD, int))g_pInputSystem->AttachToWindow)(
      a1: g_pInputSystem,
      a2: v11,
      a3: 0,
      a4: a2);
    iWidth = 0;
    v14 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v14 + 12))(
           a1: v14,
           a2: "-adapter",
           a3: &pAdapterString) != 0 )
      iWidth = atoi(nptr: pAdapterString);
    v15 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v15 + 12))(a1: v15, a2: "-ref", a3: 0) != 0 )
      v12 = 4;
    if ( this->AppUsesReadPixels(this) )
      v12 |= 2u;
    g_pMaterialSystem->SetAdapter(this: g_pMaterialSystem, a2: iWidth, a3: v12);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040FC60
// Name: public: virtual void CMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::PostShutdown(CMatSysApp *this)
{
  if ( g_pInputSystem != nullptr )
    g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x0040FC80
// Name: protected: bool CMatSysApp::SetVideoMode(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetVideoMode(CMatSysApp *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  void *m_HWnd; // eax
  int v9; // eax
  char pModPath[260]; // [esp+Ch] [ebp-188h] BYREF
  char pModName[32]; // [esp+110h] [ebp-84h] BYREF
  MaterialSystem_Config_t config; // [esp+130h] [ebp-64h] BYREF

  MaterialSystem_Config_t::MaterialSystem_Config_t(this: &config);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-fullscreen", a3: 0) != 0 )
    config.m_Flags &= ~1u;
  else
    config.m_Flags |= 1u;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-resizing", a3: 0) != 0 )
    config.m_Flags |= 2u;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-mat_vsync", a3: 0) != 0 )
    config.m_Flags &= ~8u;
  v5 = _CommandLine();
  config.m_nAASamples = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 28))(
                          a1: v5,
                          a2: "-mat_antialias",
                          a3: 1);
  v6 = _CommandLine();
  config.m_nAAQuality = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 28))(
                          a1: v6,
                          a2: "-mat_aaquality",
                          a3: 0);
  config.m_Flags |= 0x10u;
  config.m_VideoMode.m_Format = IMAGE_FORMAT_BGRX8888;
  m_HWnd = this->m_HWnd;
  config.m_VideoMode.m_Height = 0;
  config.m_VideoMode.m_Width = 0;
  config.m_VideoMode.m_RefreshRate = 0;
  if ( g_pMaterialSystem->SetMode(this: g_pMaterialSystem, a2: m_HWnd, a3: &config) )
  {
    V_snprintf(pDest: pModPath, maxLen: 260, pFormat: &defaultValue);
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pModPath, a5: 260);
    V_StripTrailingSlash(ppath: pModPath);
    V_FileBase(in: pModPath, out: pModName, maxlen: 32);
    v9 = 0;
    if ( pModName[0] != 0 )
    {
      while ( pModName[v9] != 95 )
      {
        if ( pModName[++v9] == 0 )
          goto LABEL_15;
      }
      pModName[v9] = 0;
    }
LABEL_15:
    UpdateSystemLevel(nCPULevel: 2, nGPULevel: 3, nMemLevel: 2, nGPUMemLevel: 2, bVGUIIsSplitscreen: false, pModName);
    g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &config, a3: false);
    return 1;
  }
  else
  {
    _Error(a1: "Unable to set mode\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FE20
// Name: public: CMatSysApp::CMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CMatSysApp *__thiscall CMatSysApp::CMatSysApp(CMatSysApp *this)
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(this, pFileSystem: nullptr, pAppSystemParent: nullptr);
  this->__vftable = (CMatSysApp_vtbl *)&CMatSysApp::`vftable';
  return this;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00406250
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (int)this, value: nullptr, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  this->m_bSupportFlashlight = true;
  this->bCompressedTextures = true;
  this->bShowSpecular = true;
  this->bShowDiffuse = true;
  this->bFilterLightmaps = true;
  this->bFilterTextures = true;
  this->bMipMapTextures = true;
  this->bBufferPrimitives = true;
  this->dxSupportLevel = 0;
  this->m_bGammaTVEnabled = false;
  this->m_bWantTripleBuffered = false;
  this->m_bShadowDepthTexture = false;
  this->m_bMotionBlur = false;
  this->bAllowCheats = false;
  this->bEditMode = false;
  this->nFullbright = 0;
  this->bShowNormalMap = false;
  this->nShowMipLevels = 0;
  this->bShowLowResImage = false;
  this->bReverseDepth = false;
  this->bDrawFlat = false;
  this->bMeasureFillRate = false;
  this->bVisualizeFillRate = false;
  this->bSoftwareLighting = false;
  this->bNoTransparency = false;
  this->proxiesTestMode = 0;
  this->m_bFastNoBump = false;
  this->m_bSuppressRendering = false;
  this->m_bPaintInGame = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00406330
// Name: public: virtual bool CMatSysApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::Create(CMatSysApp *this)
{
  IAppSystem *System; // eax
  AppSystemInfo_t appSystems[3]; // [esp+0h] [ebp-1Ch] BYREF
  const char *v5; // [esp+18h] [ebp-4h]

  appSystems[2].m_pInterfaceName = defaultValue;
  v5 = defaultValue;
  appSystems[0].m_pInterfaceName = "inputsystem.dll";
  appSystems[1].m_pModuleName = "InputSystemVersion001";
  appSystems[1].m_pInterfaceName = "materialsystem.dll";
  appSystems[2].m_pModuleName = "VMaterialSystem080";
  if ( CAppSystemGroup::AddSystems(this, pSystemList: (AppSystemInfo_t *)&appSystems[0].m_pInterfaceName) == 0 )
    return 0;
  System = CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem080");
  if ( System == nullptr )
  {
    _Warning(a1: "CMatSysApp::Create: Unable to connect to necessary interface!\n");
    return 0;
  }
  ((void (__thiscall *)(IAppSystem *, const char *))System->__vftable[1].Disconnect)(a1: System, a2: "shaderapidx9.dll");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004063B0
// Name: protected: void CMatSysApp::AppPumpMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::AppPumpMessages(CMatSysApp *this)
{
  g_pInputSystem->PollInputState(this: g_pInputSystem);
}

//------------------------------------------------------------------------------
// Address: 0x004063C0
// Name: protected: bool CMatSysApp::SetupSearchPaths(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatSysApp::SetupSearchPaths(
        CMatSysApp *this,
        const char *pStartingDir,
        bool bOnlyUseStartingDir,
        bool bIsTool)
{
  bool result; // al
  IFileSystem_vtbl *v6; // esi
  const char *GameInfoPath; // eax

  result = CSteamAppSystemGroup::SetupSearchPaths(this, pStartingDir, bOnlyUseStartingDir, bIsTool);
  if ( result )
  {
    v6 = g_pFullFileSystem->IAppSystem::__vftable;
    GameInfoPath = CSteamAppSystemGroup::GetGameInfoPath(this);
    v6->AddSearchPath(this: g_pFullFileSystem, a2: GameInfoPath, a3: "SKIN", a4: PATH_ADD_TO_HEAD);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406410
// Name: public: virtual bool CMatSysApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CMatSysApp::PreInit@<al>(CMatSysApp *this@<ecx>, int a2@<ebx>, int a3, char *nptr)
{
  int v5; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // eax
  CMatSysApp_vtbl *v9; // ebx
  const char *(__thiscall *GetAppName)(CMatSysApp *); // edx
  void *AppInstance; // eax
  void *v12; // eax
  int v14; // ebp
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  int v18; // [esp+1Ch] [ebp-24h]
  int v19; // [esp+1Ch] [ebp-24h]
  int bWindowed; // [esp+34h] [ebp-Ch] BYREF
  const char *pAdapterString; // [esp+38h] [ebp-8h] BYREF
  int v23; // [esp+3Ch] [ebp-4h]
  void *retaddr; // [esp+40h] [ebp+0h]

  bWindowed = (int)CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&bWindowed, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(pFactoryList: (void *(__cdecl **)(const char *, int *))&bWindowed, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || g_pMaterialSystem == nullptr || g_pInputSystem == nullptr )
  {
    _Warning(a1: "CMatSysApp::PreInit: Unable to connect to necessary interface!\n");
  }
  else if ( CMatSysApp::SetupSearchPaths(this, pStartingDir: nullptr, bOnlyUseStartingDir: false, bIsTool: true) )
  {
    bWindowed = 1024;
    v5 = 768;
    v6 = _CommandLine();
    LOBYTE(retaddr) = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 12))(
                        a1: v6,
                        a2: "-fullscreen",
                        a3: 0) == 0;
    v7 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v7 + 12))(
           a1: v7,
           a2: "-width",
           a3: &pAdapterString) != 0 )
      v23 = atoi(nptr: pAdapterString);
    v8 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v8 + 12))(
           a1: v8,
           a2: "-height",
           a3: &pAdapterString) != 0 )
      v5 = atoi(nptr: pAdapterString);
    v9 = this->__vftable;
    v18 = v23;
    GetAppName = this->GetAppName;
    this->m_nWidth = v23;
    this->m_nHeight = v5;
    v19 = ((int (__thiscall *)(CMatSysApp *, void *, int))GetAppName)(a1: this, a2: retaddr, a3: v18);
    AppInstance = GetAppInstance();
    v12 = (void *)((int (__thiscall *)(CMatSysApp *, void *, int))v9->CreateAppWindow)(
                    a1: this,
                    a2: AppInstance,
                    a3: v19);
    this->m_HWnd = v12;
    if ( v12 == nullptr )
      return 0;
    ((void (__thiscall *)(IInputSystem *, void *, int, _DWORD, int))g_pInputSystem->AttachToWindow)(
      a1: g_pInputSystem,
      a2: v12,
      a3: v5,
      a4: 0,
      a5: a2);
    v14 = 0;
    v15 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, char **))(*(_DWORD *)v15 + 12))(a1: v15, a2: "-adapter", a3: &nptr) != 0 )
      v14 = atoi(nptr);
    v16 = 0;
    v17 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v17 + 12))(a1: v17, a2: "-ref", a3: 0) != 0 )
      v16 = 4;
    if ( this->AppUsesReadPixels(this) )
      v16 |= 2u;
    g_pMaterialSystem->SetAdapter(this: g_pMaterialSystem, a2: v14, a3: v16);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004065E0
// Name: public: virtual void CMatSysApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSysApp::PostShutdown(CMatSysApp *this)
{
  if ( g_pInputSystem != nullptr )
    g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00406600
// Name: protected: bool CMatSysApp::SetVideoMode(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatSysApp::SetVideoMode(CMatSysApp *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  void *m_HWnd; // eax
  int v9; // eax
  MaterialSystem_Config_t config; // [esp+3Ch] [ebp-18Ch] BYREF
  char pModName[32]; // [esp+A0h] [ebp-128h] BYREF
  char pModPath[264]; // [esp+C0h] [ebp-108h] BYREF

  MaterialSystem_Config_t::MaterialSystem_Config_t(this: (MaterialSystem_Config_t *)&config.m_VideoMode.m_Height);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-fullscreen", a3: 0) != 0 )
    *(_DWORD *)&config.bEditMode &= ~1u;
  else
    *(_DWORD *)&config.bEditMode |= 1u;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-resizing", a3: 0) != 0 )
    *(_DWORD *)&config.bEditMode |= 2u;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-mat_vsync", a3: 0) != 0 )
    *(_DWORD *)&config.bEditMode &= ~8u;
  v5 = _CommandLine();
  config.m_nForceAnisotropicLevel = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 28))(
                                      a1: v5,
                                      a2: "-mat_antialias",
                                      a3: 1);
  v6 = _CommandLine();
  *(_DWORD *)&config.m_bShadowDepthTexture = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 28))(
                                               a1: v6,
                                               a2: "-mat_aaquality",
                                               a3: 0);
  *(_DWORD *)&config.bEditMode |= 0x10u;
  config.m_VideoMode.m_RefreshRate = 16;
  m_HWnd = this->m_HWnd;
  config.m_VideoMode.m_Format = IMAGE_FORMAT_RGBA8888;
  config.m_VideoMode.m_Height = 0;
  config.m_fMonitorGamma = 0.0;
  if ( g_pMaterialSystem->SetMode(
         this: g_pMaterialSystem,
         a2: m_HWnd,
         a3: (const MaterialSystem_Config_t *)&config.m_VideoMode.m_Height) )
  {
    V_snprintf(pDest: &pModPath[4], maxLen: 260, pFormat: defaultValue);
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: &pModPath[4], a5: 260);
    V_StripTrailingSlash(ppath: &pModPath[4]);
    V_FileBase(in: &pModPath[4], out: &pModName[4], maxlen: 32);
    v9 = 0;
    if ( pModName[4] != 0 )
    {
      while ( pModName[v9 + 4] != 95 )
      {
        if ( pModName[++v9 + 4] == 0 )
          goto LABEL_15;
      }
      pModName[v9 + 4] = 0;
    }
LABEL_15:
    UpdateSystemLevel(
      nCPULevel: 2,
      nGPULevel: 3,
      nMemLevel: 2,
      nGPUMemLevel: 2,
      bVGUIIsSplitscreen: false,
      pModName: &pModName[4]);
    g_pMaterialSystem->OverrideConfig(
      this: g_pMaterialSystem,
      a2: (const MaterialSystem_Config_t *)&config.m_VideoMode.m_Height,
      a3: false);
    return 1;
  }
  else
  {
    _Error(a1: "Unable to set mode\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004067A0
// Name: public: CMatSysApp::CMatSysApp(void)
// Source: json
//------------------------------------------------------------------------------
CMatSysApp *__thiscall CMatSysApp::CMatSysApp(CMatSysApp *this)
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(this, pFileSystem: nullptr, pAppSystemParent: nullptr);
  this->__vftable = (CMatSysApp_vtbl *)&CMatSysApp::`vftable';
  return this;
}

} // namespace vgui_perftest
