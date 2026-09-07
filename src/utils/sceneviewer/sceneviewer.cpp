// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/sceneviewer/sceneviewer.cpp
// Functions: 11
// ============================================================

#include "utils\sceneviewer\sceneviewer.h"

//------------------------------------------------------------------------------
// Address: 0x00401D00
// Name: public: virtual bool CSceneViewerApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneViewerApp::Create(CSceneViewerApp *this)
{
  int v2; // eax
  char v3; // bl
  HANDLE StdHandle; // eax
  int v6; // eax
  IDmeMakefileUtils *DefaultDmeMakefileUtils; // eax
  AppSystemInfo_t appSystems[7]; // [esp+8h] [ebp-40h] BYREF
  unsigned int cRead; // [esp+40h] [ebp-8h] BYREF
  char tmpBuf[2]; // [esp+44h] [ebp-4h] BYREF

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-help") != 0 )
  {
    v3 = _SetupWin32ConsoleIO();
    _Msg(a1: "\n\n Sceneviewer - Loads and views Valve DMX Assets\n\n");
    _Msg(a1: " Synopsis: sceneviewer [ vgui opts ] [ -help ] [ filename.[dmx|obj] ]\n");
    _Msg(
      a1: "\n"
      " Where:\n"
      "\n"
      " Sceneviewer Options:\n"
      "\n"
      " -help . . . . . . Prints this information\n"
      " -nozoom . . . . . Stop sceneviewer zooming model viewer to occupy all client\n"
      "                   space when a dmx is specified on the command line\n"
      " -showasset  . . . Stop sceneviewer from hiding the asset builder when a dmx\n"
      "                   file is specified on the command line.\n"
      "  filename.dmx . . The name of a dmx file to load on start\n"
      "\n"
      " VGUI Options:\n"
      "\n"
      " -vproject <$> . . Override VPROJECT environment variable\n"
      " -game <$> . . . . Override VPROJECT environment variable\n"
      " -remote <$> . . . Add the remote share name\n"
      " -host <$> . . . . Set the host name\n"
      " -norfs  . . . . . Do not use remote filesystem\n"
      " -fullscreen . . . Run application fullscreen rather than in a window\n"
      " -width <#>  . . . Set the window width when running windowed\n"
      " -height <#> . . . Set the window height when running windowed\n"
      " -adapter <$>  . . Set the adapter??\n"
      " -ref  . . . . . . Set MATERIAL_INIT_REFERENCE_RASTERIZER on adapter??\n"
      " -resizing . . . . Allow the window to be resized\n"
      " -mat_vsync  . . . Wait for VSYNC\n"
      " -mat_antialias  . Turn on Anti-Aliasing\n"
      " -mat_aaquality  . Antialiasing quality (set to zero unless you know what you're doing)\n"
      "\n");
    if ( v3 != 0 )
    {
      _Msg(a1: "\n\nPress Any Key Continue...");
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF6);
      ReadConsoleA(
        hConsoleInput: StdHandle,
        lpBuffer: tmpBuf,
        nNumberOfCharsToRead: 1u,
        lpNumberOfCharsRead: &cRead,
        pInputControl: nullptr);
    }
    return false;
  }
  v6 = _CommandLine();
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 20))(a1: v6, a2: "-box", a3: 0);
  if ( !CVguiMatSysApp::Create(this) )
    return false;
  appSystems[2].m_pModuleName = "datacache.dll";
  appSystems[3].m_pModuleName = "datacache.dll";
  appSystems[0].m_pModuleName = "vstdlib.dll";
  appSystems[0].m_pInterfaceName = "VProcessUtils002";
  appSystems[1].m_pModuleName = "studiorender.dll";
  appSystems[1].m_pInterfaceName = "VStudioRender026";
  appSystems[2].m_pInterfaceName = "VDataCache003";
  appSystems[3].m_pInterfaceName = "MDLCache004";
  appSystems[4].m_pModuleName = "vphysics.dll";
  appSystems[4].m_pInterfaceName = "VPhysics031";
  appSystems[5].m_pModuleName = "p4lib.dll";
  appSystems[5].m_pInterfaceName = "VP4002";
  appSystems[6].m_pModuleName = defaultValue;
  appSystems[6].m_pInterfaceName = defaultValue;
  CAppSystemGroup::AddSystem(
    this,
    pAppSystem: (IAppSystem *)g_pDataModel.u.m_Id,
    pInterfaceName: "VDataModelVersion001");
  CAppSystemGroup::AddSystem(this, pAppSystem: g_pDmElementFramework, pInterfaceName: "VDmElementFrameworkVersion001");
  CAppSystemGroup::AddSystem(this, pAppSystem: g_pDmSerializers, pInterfaceName: "VDmSerializers001");
  DefaultDmeMakefileUtils = GetDefaultDmeMakefileUtils();
  CAppSystemGroup::AddSystem(this, pAppSystem: DefaultDmeMakefileUtils, pInterfaceName: "VDmeMakeFileUtils001");
  return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
}

//------------------------------------------------------------------------------
// Address: 0x00401E60
// Name: public: virtual bool CSceneViewerApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneViewerApp::PreInit(CSceneViewerApp *this)
{
  void *(__cdecl *appFactory)(const char *, int *); // [esp+20h] [ebp-4h] BYREF

  appFactory = (void *(__cdecl *)(const char *, int *))this;
  if ( CVguiMatSysApp::PreInit(this) )
  {
    MathLib_Init(
      gamma: 2.2,
      texGamma: 2.2,
      brightness: 0.0,
      overbright: 2,
      bAllow3DNow: false,
      bAllowSSE: false,
      bAllowSSE2: false,
      bAllowMMX: false);
    if ( g_pFullFileSystem != nullptr
      && g_pMaterialSystem != nullptr
      && g_pDataModel.u.m_Id != 0
      && g_pDmElementFramework != nullptr
      && g_pStudioRender != nullptr
      && g_pDataCache != nullptr
      && g_pVGuiSurface != nullptr
      && g_pVGui != nullptr )
    {
      appFactory = CAppSystemGroup::GetFactory();
      return vgui::VGui_InitDmeInterfacesList(moduleName: "SceneViewer", factoryList: &appFactory, numFactories: 1);
    }
    _Warning(a1: "CSceneViewerApp::PreInit: Unable to connect to necessary interface!\n");
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00401F20
// Name: public: virtual void CSceneViewerApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSceneViewerApp::PostShutdown(CSceneViewerApp *this)
{
  CVguiMatSysApp::PostShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00401F30
// Name: public: CMatRenderContextPtr::~CMatRenderContextPtr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::~CMatRenderContextPtr(CMatRenderContextPtr *this)
{
  IMatRenderContext *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    if ( this->m_pObject != nullptr )
      this->m_pObject->Release(this: this->m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401F50
// Name: public: virtual void CConsoleLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConsoleLoggingListener::Log(CConsoleLoggingListener *this, int pContext, const char *pMessage)
{
  const LoggingContext_t *v3; // ecx
  Color *p_pContext; // eax
  int m_ChannelID; // [esp-8h] [ebp-14h]
  Color c; // [esp+0h] [ebp-Ch] BYREF
  int v7; // [esp+4h] [ebp-8h] BYREF
  int v8; // [esp+8h] [ebp-4h] BYREF

  v3 = (const LoggingContext_t *)pContext;
  if ( (*(_BYTE *)(pContext + 4) & 2) == 0 )
  {
    switch ( *(_DWORD *)(pContext + 8) )
    {
      case 0:
        p_pContext = (Color *)(pContext + 12);
        if ( *(_DWORD *)(pContext + 12) == UNSPECIFIED_LOGGING_COLOR_1 )
        {
          pContext = -1;
          p_pContext = (Color *)&pContext;
        }
        m_ChannelID = v3->m_ChannelID;
        c = *p_pContext;
        if ( (unsigned __int8)_LoggingSystem_HasTag(a1: m_ChannelID, a2: "Developer") != 0 )
          g_pCVar->ConsoleDPrintf(this: g_pCVar, a2: pMessage);
        else
          g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: &c, a3: pMessage);
        break;
      case 1:
        v7 = -16727872;
        g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: (const Color *)&v7, a3: pMessage);
        break;
      case 2:
        pContext = -16727809;
        g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: (const Color *)&pContext, a3: pMessage);
        break;
      case 3:
        v8 = -16776961;
        g_pCVar->ConsoleColorPrintf(this: g_pCVar, a2: (const Color *)&v8, a3: pMessage);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402020
// Name: public: CMatRenderContextPtr::CMatRenderContextPtr(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContextPtr *__thiscall CMatRenderContextPtr::CMatRenderContextPtr(
        CMatRenderContextPtr *this,
        IMaterialSystem *pFrom)
{
  IMatRenderContext *v3; // eax

  v3 = pFrom->GetRenderContext(this: pFrom);
  this->m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402050
// Name: private: void CSceneViewerApp::InitDefaultEnvCubemap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerApp::InitDefaultEnvCubemap(CSceneViewerApp *this)
{
  IMatRenderContext *v2; // esi
  ITexture *v3; // edi

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = g_pMaterialSystem->FindTexture(this: g_pMaterialSystem, a2: "editor/cubemap", a3: 0, a4: 1, a5: 0);
  CTextureReference::Init(this: &this->m_DefaultEnvCubemap, pTexture: v3);
  v2->BindLocalCubemap(this: v2, a2: v3);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004020C0
// Name: public: virtual int CSceneViewerApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CSceneViewerApp::Main@<eax>(CSceneViewerApp *this@<ecx>, int a2@<edi>)
{
  CSceneViewerApp *v2; // ebx
  IMatRenderContext *v4; // esi
  int v5; // eax
  int v6; // edi
  int v7; // eax
  const char *v8; // eax
  const char *v9; // ebx
  int v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  vgui::Panel *v13; // edi
  KeyValues *v14; // eax
  int v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  int v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  int v21; // edi
  int v22; // eax
  vgui::AnimationController *AnimationController; // eax
  IMatRenderContext *v24; // eax
  IMatRenderContext *v25; // edi
  int v26; // ebx
  int i; // edi
  int v28; // eax
  float currentTime; // [esp+8Ch] [ebp-1Ch]
  int root; // [esp+98h] [ebp-10h]
  KeyValues *ofs; // [esp+A0h] [ebp-8h]
  vgui::Panel *pMainPanel; // [esp+A4h] [ebp-4h]

  v2 = this;
  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &s_ConsoleLoggingListener);
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "Console", a2: 0);
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "Developer", a2: 3);
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "DeveloperVerbose", a2: 3);
  g_pMaterialSystem->ModInit(this: g_pMaterialSystem);
  if ( !CMatSysApp::SetVideoMode(this: v2) )
    return 0;
  g_pDataCache->SetSize(this: g_pDataCache, a2: 0x4000000);
  CSceneViewerApp::InitDefaultEnvCubemap(this: v2);
  g_pMaterialSystemConfig = g_pMaterialSystem->GetCurrentConfigForVideoCard(this: g_pMaterialSystem);
  g_pVGuiSystem->SetUserConfigFile(this: g_pVGuiSystem, a2: "sceneviewer.vdf", a3: "EXECUTABLE_PATH");
  g_pVGuiSchemeManager->LoadSchemeFromFile(this: g_pVGuiSchemeManager, a2: "resource/BoxRocket.res", a3: "SceneViewer");
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/boxrocket_%language%.txt", a3: nullptr, a4: false);
  g_pVGui->Start(this: g_pVGui);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/valve_%language%.txt", a3: nullptr, a4: false);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/vgui_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/dmecontrols_%language%.txt", a3: nullptr, a4: false);
  pMainPanel = CreateSceneViewerPanel();
  v4 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  root = ((int (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->GetEmbeddedPanel)(a1: g_pVGuiSurface, a2);
  g_pVGuiSurface->Invalidate(this: g_pVGuiSurface, a2: root);
  v5 = _CommandLine();
  v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 36))(a1: v5) - 1;
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      v7 = _CommandLine();
      v8 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 44))(a1: v7, a2: v6);
      v9 = v8;
      if ( v8 != nullptr && *v8 != 0 && _access(path: v8, amode: 4) == 0 )
        break;
      if ( --v6 <= 0 )
        goto LABEL_30;
    }
    v10 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(a1: v10, a2: "-nozoom") != 0 )
    {
      v13 = pMainPanel;
    }
    else
    {
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v11 != nullptr )
        v12 = KeyValues::KeyValues(this: v11, setName: "PinAndZoomIt");
      else
        v12 = nullptr;
      v13 = pMainPanel;
      ((void (__thiscall *)(vgui::Panel *, vgui::Panel *, KeyValues *, _DWORD))pMainPanel->PostMessage)(
        a1: pMainPanel,
        a2: pMainPanel,
        a3: v12,
        a4: 0);
    }
    v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v14 != nullptr )
    {
      ofs = KeyValues::KeyValues(this: v14, setName: "LoadFile");
      KeyValues::SetString(this: ofs, keyName: "fullpath", value: v9);
    }
    else
    {
      ofs = nullptr;
      KeyValues::SetString(this: nullptr, keyName: "fullpath", value: v9);
    }
    ((void (__thiscall *)(vgui::Panel *, vgui::Panel *, KeyValues *, _DWORD))v13->PostMessage)(
      a1: v13,
      a2: v13,
      a3: ofs,
      a4: 0);
    v15 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v15 + 40))(a1: v15, a2: "-showasset") != 0 )
    {
      v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v16 != nullptr )
        v17 = KeyValues::KeyValues(this: v16, setName: "ShowAssetBuilder");
      else
        v17 = nullptr;
      ((void (__thiscall *)(vgui::Panel *, vgui::Panel *, KeyValues *, _DWORD))v13->PostMessage)(
        a1: v13,
        a2: v13,
        a3: v17,
        a4: 0);
    }
    v18 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v18 + 40))(a1: v18, a2: "-showcomboeditor") != 0 )
    {
      v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v19 != nullptr )
        v20 = KeyValues::KeyValues(this: v19, setName: "ShowComboBuilder");
      else
        v20 = nullptr;
      ((void (__stdcall *)(vgui::Panel *, KeyValues *, _DWORD))pMainPanel->PostMessage)(a1: pMainPanel, a2: v20, a3: 0);
    }
LABEL_30:
    v2 = this;
  }
  v21 = _Plat_MSTime();
  while ( g_pVGui->IsRunning(this: g_pVGui) )
  {
    Sleep(dwMilliseconds: 1u);
    v22 = _Plat_MSTime();
    if ( v22 - v21 >= 16 )
    {
      v21 = v22;
      CMatSysApp::AppPumpMessages(this: v2);
      currentTime = _Plat_FloatTime();
      AnimationController = vgui::GetAnimationController();
      vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime);
      ((void (__stdcall *)(_DWORD))g_pMaterialSystem->BeginFrame)(a1: 0);
      v4->ClearColor4ub(this: v4, a2: 76u, a3: 88u, a4: 68u, a5: 255u);
      v4->ClearBuffers(this: v4, a2: true, a3: true, a4: true);
      g_pVGui->RunFrame(this: g_pVGui);
      g_pVGuiSurface->PaintTraverseEx(this: g_pVGuiSurface, a2: root, a3: true);
      g_pMaterialSystem->EndFrame(this: g_pMaterialSystem);
      g_pMaterialSystem->SwapBuffers(this: g_pMaterialSystem);
    }
  }
  if ( pMainPanel != nullptr )
    ((void (__thiscall *)(vgui::Panel *, int))pMainPanel->dtr_Panel)(a1: pMainPanel, a2: 1);
  v24 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v25 = v24;
  if ( v24 != nullptr )
    v24->BeginRender(this: v24);
  v25->BindLocalCubemap(this: v25, a2: nullptr);
  CTextureReference::Shutdown(this: &v2->m_DefaultEnvCubemap, bDeleteIfUnReferenced: false);
  v25->EndRender(this: v25);
  v25->Release(this: v25);
  g_pMaterialSystem->ModShutdown(this: g_pMaterialSystem);
  v26 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 344))(a1: g_pDataModel.u);
  for ( i = 0; i < v26; ++i )
  {
    v28 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 352))(
            a1: g_pDataModel.u,
            a2: i);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 408))(
      a1: g_pDataModel.u,
      a2: v28);
  }
  _LoggingSystem_PopLoggingState(a1: 0);
  if ( v4 != nullptr )
  {
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402AA0
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00402B00
// Name: public: virtual char const __near * CSceneViewerApp::GetAppName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSceneViewerApp::GetAppName(CSceneViewerApp *this)
{
  return "SceneViewer";
}

//------------------------------------------------------------------------------
// Address: 0x00402B10
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    CVguiMatSysApp::CVguiMatSysApp(this: &sceneViewerApp);
    sceneViewerApp.__vftable = (CSceneViewerApp_vtbl *)&CSceneViewerApp::`vftable';
    CTextureReference::CTextureReference(this: &sceneViewerApp.m_DefaultEnvCubemap);
    atexit(func: WinMain_::_2_::_dynamic_atexit_destructor_for__sceneViewerApp__);
  }
  if ( (_S1 & 2) == 0 )
  {
    _S1 |= 2u;
    CSteamApplication::CSteamApplication(this: &steamApp, pAppSystemGroup: &sceneViewerApp);
    atexit(func: WinMain_::_2_::_dynamic_atexit_destructor_for__steamApp__);
  }
  return AppMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow, pAppSystemGroup: &steamApp);
}
