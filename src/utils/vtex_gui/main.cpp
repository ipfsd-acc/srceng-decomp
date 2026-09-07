// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vtex_gui/main.cpp
// Functions: 144
// ============================================================

#include "utils\vtex_gui\main.h"

//------------------------------------------------------------------------------
// Address: 0x00402D80
// Name: public: virtual bool CVguiSteamApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVguiSteamApp::PreInit(CVguiSteamApp *this)
{
  vgui::Panel *v1; // ecx
  void *(__cdecl *factory)(const char *, int *); // [esp+0h] [ebp-Ch] BYREF
  void *(__cdecl *v4)(const char *, int *); // [esp+4h] [ebp-8h]
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  pFactoryList = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  v4 = CAppSystemGroup::GetFactory();
  CSteamApplication::PostShutdown(this: v1);
  factory = CAppSystemGroup::GetFactory();
  return vgui::VGui_InitInterfacesList(moduleName: "CVguiSteamApp", factoryList: &factory, numFactories: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00402DE0
// Name: char const __near * GetBaseDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetBaseDirectory()
{
  HMODULE AppInstance; // eax

  if ( path[0] == 0 )
  {
    AppInstance = (HMODULE)GetAppInstance();
    GetModuleFileNameA(hModule: AppInstance, lpFilename: path, nSize: 0x104u);
    V_StripLastDir(dirName: path, maxlen: 260);
    V_StripTrailingSlash(ppath: path);
  }
  return path;
}

//------------------------------------------------------------------------------
// Address: 0x00402E30
// Name: messageProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall messageProc(HWND__ *hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
  return DefWindowProcA(hWnd: hwnd, Msg: msg, wParam: wparam, lParam: lparam);
}

//------------------------------------------------------------------------------
// Address: 0x00402E40
// Name: void CreateMessageWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateMessageWindow()
{
  HMODULE ModuleHandleA; // eax

  *(_QWORD *)&staticWndclass.cbClsExtra = 0;
  *(_QWORD *)&staticWndclass.hInstance = 0;
  *(_QWORD *)&staticWndclass.hCursor = 0;
  *(_QWORD *)&staticWndclass.lpszMenuName = 0;
  staticWndclass.style = 0;
  staticWndclass.lpfnWndProc = messageProc;
  staticWndclass.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  staticWndclass.lpszClassName = "VTEXGUI_Window";
  staticWndclassAtom = RegisterClassA(lpWndClass: &staticWndclass);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  staticHwnd = CreateWindowExA(
                 dwExStyle: 0,
                 lpClassName: "VTEXGUI_Window",
                 lpWindowName: "Hidden Window",
                 dwStyle: 0,
                 X: 0,
                 Y: 0,
                 nWidth: 1,
                 nHeight: 1,
                 hWndParent: nullptr,
                 hMenu: nullptr,
                 hInstance: ModuleHandleA,
                 lpParam: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00402EE0
// Name: bool InitializeVGUI(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InitializeVGUI()
{
  vgui::Panel *v0; // eax
  vgui::Panel *v1; // esi
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  int v4; // eax
  CVtexDialog *v5; // eax
  CVtexDialog *v6; // eax

  g_pVGui->SetSleep(this: g_pVGui, a2: false);
  v0 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v0 != nullptr )
    v1 = vgui::Panel::Panel(this: v0, parent: nullptr, panelName: "TopPanel");
  else
    v1 = nullptr;
  v1->SetVisible(this: v1, a2: true);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = v1->GetVPanel(this: v1);
  v3->SetEmbeddedPanel(this: v2, a2: v4);
  g_pVGuiSchemeManager->LoadSchemeFromFile(this: g_pVGuiSchemeManager, a2: "tools_scheme.res", a3: "tools_scheme");
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/platform_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/vgui_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "tools_english.txt", a3: nullptr, a4: false);
  g_pVGui->Start(this: g_pVGui);
  v5 = (CVtexDialog *)operator new(nSize: 0x34Cu);
  if ( v5 != nullptr )
    v6 = CVtexDialog::CVtexDialog(this: v5, parent: v1, name: "VtexDialog");
  else
    v6 = nullptr;
  g_pMainFrame = v6;
  v6->MoveToCenterOfScreen(this: v6);
  g_pMainFrame->Activate(this: g_pMainFrame);
  g_pMainFrame->SetSizeable(this: g_pMainFrame, a2: false);
  g_pMainFrame->SetMenuButtonVisible(this: g_pMainFrame, a2: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403010
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  return AppMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow, pAppSystemGroup: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x00403040
// Name: public: virtual bool CVConfigApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVConfigApp::Create(CVConfigApp *this)
{
  AppSystemInfo_t appSystems[4]; // [esp+0h] [ebp-20h] BYREF

  appSystems[3].m_pModuleName = defaultValue;
  appSystems[3].m_pInterfaceName = defaultValue;
  appSystems[0].m_pModuleName = "inputsystem.dll";
  appSystems[0].m_pInterfaceName = "InputSystemVersion001";
  appSystems[1].m_pModuleName = "vgui2.dll";
  appSystems[1].m_pInterfaceName = "VGUI_ivgui008";
  appSystems[2].m_pModuleName = "p4lib.dll";
  appSystems[2].m_pInterfaceName = "VP4002";
  return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
}

//------------------------------------------------------------------------------
// Address: 0x00403090
// Name: public: virtual bool CVConfigApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVConfigApp::PreInit(CVConfigApp *this)
{
  const char *v2; // eax
  HMODULE AppInstance; // eax
  IFileSystem_vtbl *v5; // esi
  char *BaseDirectory; // eax
  char dirName[260]; // [esp+4h] [ebp-104h] BYREF

  if ( !CVguiSteamApp::PreInit(this) )
    return 0;
  CreateMessageWindow();
  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  v2 = getenv(option: "VProject");
  V_strncpy(pDest: TheVProjectDir, pSrc: v2, maxLen: 260);
  V_strncat(pDest: TheVProjectDir, pSrc: "\\", destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_FixSlashes(pname: TheVProjectDir, separator: 92);
  if ( path[0] == 0 )
  {
    AppInstance = (HMODULE)GetAppInstance();
    GetModuleFileNameA(hModule: AppInstance, lpFilename: path, nSize: 0x104u);
    V_StripLastDir(dirName: path, maxlen: 260);
    V_StripTrailingSlash(ppath: path);
  }
  V_strncpy(pDest: dirName, pSrc: path, maxLen: 260);
  V_AppendSlash(pStr: dirName, strSize: 260);
  V_strncat(pDest: dirName, pSrc: "tools", destBufferSize: 0x104u, max_chars_to_copy: -1);
  if ( !CSteamAppSystemGroup::SetupSearchPaths(this, pStartingDir: dirName, bOnlyUseStartingDir: true, bIsTool: true) )
  {
    MessageBoxA(hWnd: nullptr, lpText: "Error", lpCaption: "Unable to initialize file system\n", uType: 0);
    return 0;
  }
  v5 = g_pFullFileSystem->IAppSystem::__vftable;
  BaseDirectory = GetBaseDirectory();
  v5->AddSearchPath(this: g_pFullFileSystem, a2: BaseDirectory, a3: "MAIN", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "platform", a3: "PLATFORM", a4: PATH_ADD_TO_HEAD);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004031F0
// Name: public: virtual void CVConfigApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVConfigApp::PostShutdown(CVConfigApp *this)
{
  HMODULE ModuleHandleA; // eax
  vgui::Panel *v2; // ecx

  DestroyWindow(hWnd: staticHwnd);
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  UnregisterClassA(lpClassName: "VTEXGUI_Window", hInstance: ModuleHandleA);
  CSteamApplication::PostShutdown(this: v2);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00403230
// Name: public: virtual int CVConfigApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVConfigApp::Main(CVConfigApp *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  const char *v5; // eax
  int v6; // eax

  if ( InitializeVGUI() == 0 )
    return 0;
  CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "VTex Auto Checkout");
  v2 = 1;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 36))(a1: v3) > 1 )
  {
    do
    {
      v4 = _CommandLine();
      v5 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 44))(a1: v4, a2: v2);
      CVtexDialog::AddTarga(this: g_pMainFrame, path: v5);
      ++v2;
      v6 = _CommandLine();
    }
    while ( v2 < (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6) );
  }
  while ( g_pVGui->IsRunning(this: g_pVGui) )
  {
    Sleep(dwMilliseconds: 0xAu);
    g_pVGui->RunFrame(this: g_pVGui);
  }
  if ( g_pMainFrame != nullptr )
    ((void (__thiscall *)(CVtexDialog *, int))g_pMainFrame->dtr_Panel)(a1: g_pMainFrame, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004032F0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4C2090 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_4C2090;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00403350
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4C2090 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004033B0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4C2090 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00403410
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004034C0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4C2090 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4C2090 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403590
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // si
  int v4; // edx
  int result; // eax
  int *v6; // ecx
  int v7; // edx
  int *v8; // ecx
  int v9; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i) == 0xFFFF )
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                       this,
                       i);
    v7 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    for ( result = (unsigned __int16)result; ; result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Parent )
    {
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      v10 = (_WORD)v9 == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v9];
      if ( *((_WORD *)v10 + 1) != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
    }
  }
  else
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                       this,
                       i);
    v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    result = (unsigned __int16)result;
    while ( 1 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( *(_WORD *)v6 == 0xFFFF )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)result == 0xFFFF )
        result = (unsigned __int16)`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403780
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004037F0
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
// Address: 0x00406770
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406860
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406960
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00406A50
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00406DA0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00406F70
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // ecx
  int v11; // ebx
  int *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  int *v15; // ecx
  int v16; // edx
  int *v17; // ecx
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int *v30; // eax
  int *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C2090 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C2090 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C2090 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C2090 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C2090 = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_4C2090 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_4C2090 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C2090 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C2090 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v25 + 3) == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v16].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C2090 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C2090 = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_4C2090 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_4C2090 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004075B0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004079F0
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}

//------------------------------------------------------------------------------
// Address: 0x00407AD0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040E0D0
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<void *,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E1D0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4C4BF8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_4C4BF8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0040E350
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4C4BF8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0040E3B0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4C4BF8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040E420
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C4BF8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C4BF8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E510
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040E610
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040E750
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C4BF8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C4BF8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0040E850
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E910
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4C4BF8 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4C4BF8 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4C4BF8 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4C4BF8 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4C4BF8 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4C4BF8 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C4BF8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C4BF8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C4BF8 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C4BF8 = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C4BF8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4C4BF8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C4BF8 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4C4BF8 = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040EFA0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F0A0
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F130
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::NewNode((CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)this);
  v4 = v3;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00417AD0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( i == -1 )
    return dword_4C61DC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00419680
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( i == -1 )
    return dword_4C61D8;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004196E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61D8 = -1;
        dword_4C61DC = -1;
        dword_4C61E0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61D8 = -1;
        dword_4C61DC = -1;
        dword_4C61E0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004197D0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( i == -1 )
    return dword_4C61F0;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00419830
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( i == -1 )
    return dword_4C61EC;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00419890
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4C61EC == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00419940
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61EC = -1;
        dword_4C61F0 = -1;
        dword_4C61F4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61EC = -1;
        dword_4C61F0 = -1;
        dword_4C61F4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419A30
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( i == -1 )
    return dword_4C6204;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00419A90
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( i == -1 )
    return dword_4C6200;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00419AF0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4C6200 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00419BA0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C6200 = -1;
        dword_4C6204 = -1;
        dword_4C6208 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C6200 = -1;
        dword_4C6204 = -1;
        dword_4C6208 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419C90
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C61D8 = -1;
      dword_4C61DC = -1;
      dword_4C61E0 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C61D8 = -1;
      dword_4C61DC = -1;
      dword_4C61E0 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419D30
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419DF0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4C61D8 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00419EA0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00419F50
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C61D8 = -1;
      dword_4C61DC = -1;
      dword_4C61E0 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041A100
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041A270
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041A320
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C61EC = -1;
      dword_4C61F0 = -1;
      dword_4C61F4 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041A4D0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041A640
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041A6F0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C6200 = -1;
      dword_4C6204 = -1;
      dword_4C6208 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041A8A0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041AAD0
// Name: public: int CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>::Find(struct CKeyBindingsMgr::KBContext_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Find(
        CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl*)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int> > *this,
        const CKeyBindingsMgr::KBContext_t *search)
{
  int m_Root; // ebx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61C4 = -1;
        dword_4C61C8 = -1;
        dword_4C61CC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61C4 = -1;
        dword_4C61C8 = -1;
        dword_4C61CC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041AD30
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61D8 = -1;
        dword_4C61DC = -1;
        dword_4C61E0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61D8 = -1;
        dword_4C61DC = -1;
        dword_4C61E0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041AE20
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61EC = -1;
        dword_4C61F0 = -1;
        dword_4C61F4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61EC = -1;
        dword_4C61F0 = -1;
        dword_4C61F4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041AF10
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61EC = -1;
            dword_4C61F0 = -1;
            dword_4C61F4 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AFD0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C61EC = -1;
      dword_4C61F0 = -1;
      dword_4C61F4 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C61EC = -1;
      dword_4C61F0 = -1;
      dword_4C61F4 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041B070
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61EC = -1;
    dword_4C61F0 = -1;
    dword_4C61F4 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C61EC = -1;
          dword_4C61F0 = -1;
          dword_4C61F4 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61EC = -1;
        dword_4C61F0 = -1;
        dword_4C61F4 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61EC = -1;
        dword_4C61F0 = -1;
        dword_4C61F4 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041B1E0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C6200 = -1;
        dword_4C6204 = -1;
        dword_4C6208 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C6200 = -1;
        dword_4C6204 = -1;
        dword_4C6208 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041B2D0
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C6200 = -1;
            dword_4C6204 = -1;
            dword_4C6208 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B390
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C6200 = -1;
      dword_4C6204 = -1;
      dword_4C6208 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C6200 = -1;
      dword_4C6204 = -1;
      dword_4C6208 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041B430
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C6200 = -1;
    dword_4C6204 = -1;
    dword_4C6208 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C6200 = -1;
          dword_4C6204 = -1;
          dword_4C6208 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C6200 = -1;
        dword_4C6204 = -1;
        dword_4C6208 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C6200 = -1;
        dword_4C6204 = -1;
        dword_4C6208 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041B5A0
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61D8 = -1;
            dword_4C61DC = -1;
            dword_4C61E0 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B660
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C61D8 = -1;
    dword_4C61DC = -1;
    dword_4C61E0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C61D8 = -1;
          dword_4C61DC = -1;
          dword_4C61E0 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61D8 = -1;
        dword_4C61DC = -1;
        dword_4C61E0 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61D8 = -1;
        dword_4C61DC = -1;
        dword_4C61E0 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041B7D0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61D8 = -1;
        dword_4C61DC = -1;
        dword_4C61E0 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61D8 = -1;
        dword_4C61DC = -1;
        dword_4C61E0 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61D8 = -1;
        dword_4C61DC = -1;
        dword_4C61E0 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61D8 = -1;
        dword_4C61DC = -1;
        dword_4C61E0 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C61D8 = -1;
          dword_4C61DC = -1;
          dword_4C61E0 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C61D8 = -1;
          dword_4C61DC = -1;
          dword_4C61E0 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61D8 = -1;
            dword_4C61DC = -1;
            dword_4C61E0 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61D8 = -1;
            dword_4C61DC = -1;
            dword_4C61E0 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C61D8 = -1;
          dword_4C61DC = -1;
          dword_4C61E0 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C61D8 = -1;
          dword_4C61DC = -1;
          dword_4C61E0 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61D8 = -1;
            dword_4C61DC = -1;
            dword_4C61E0 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61D8 = -1;
            dword_4C61DC = -1;
            dword_4C61E0 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041BC30
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61EC = -1;
        dword_4C61F0 = -1;
        dword_4C61F4 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61EC = -1;
        dword_4C61F0 = -1;
        dword_4C61F4 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61EC = -1;
        dword_4C61F0 = -1;
        dword_4C61F4 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C61EC = -1;
        dword_4C61F0 = -1;
        dword_4C61F4 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C61EC = -1;
          dword_4C61F0 = -1;
          dword_4C61F4 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C61EC = -1;
          dword_4C61F0 = -1;
          dword_4C61F4 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61EC = -1;
            dword_4C61F0 = -1;
            dword_4C61F4 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61EC = -1;
            dword_4C61F0 = -1;
            dword_4C61F4 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C61EC = -1;
          dword_4C61F0 = -1;
          dword_4C61F4 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C61EC = -1;
          dword_4C61F0 = -1;
          dword_4C61F4 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61EC = -1;
            dword_4C61F0 = -1;
            dword_4C61F4 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61EC = -1;
            dword_4C61F0 = -1;
            dword_4C61F4 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C090
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C6200 = -1;
        dword_4C6204 = -1;
        dword_4C6208 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C6200 = -1;
        dword_4C6204 = -1;
        dword_4C6208 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C6200 = -1;
        dword_4C6204 = -1;
        dword_4C6208 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C6200 = -1;
        dword_4C6204 = -1;
        dword_4C6208 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C6200 = -1;
          dword_4C6204 = -1;
          dword_4C6208 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C6200 = -1;
          dword_4C6204 = -1;
          dword_4C6208 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C6200 = -1;
            dword_4C6204 = -1;
            dword_4C6208 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C6200 = -1;
            dword_4C6204 = -1;
            dword_4C6208 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C6200 = -1;
          dword_4C6204 = -1;
          dword_4C6208 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C6200 = -1;
          dword_4C6204 = -1;
          dword_4C6208 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C6200 = -1;
            dword_4C6204 = -1;
            dword_4C6208 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C6200 = -1;
            dword_4C6204 = -1;
            dword_4C6208 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C870
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C8D0
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C930
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C9A0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CA10
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EDE0
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F3E0
// Name: public: void CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::RemoveAll(
        CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl*)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int> > *this)
{
  int index; // eax
  BOOL v3; // ecx
  int v4; // esi
  int v5; // edi

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = this->m_Elements.m_nAllocationCount > 0;
    v4 = v3 - 1;
    if ( v3 )
    {
      do
      {
        if ( v4 >= 0 && v4 < this->m_Elements.m_nAllocationCount && v4 <= index )
        {
          if ( (`CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C61C4 = -1;
            dword_4C61C8 = -1;
            dword_4C61CC = 1;
          }
          if ( this->m_Elements.m_pMemory[v4].m_Left != v4 )
          {
            v5 = v4;
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Elements.m_pMemory[v4].m_Data.m_Panels);
            this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v5].m_Left = v4;
            this->m_FirstFree = v4;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        if ( ++v4 < 0 || v4 >= this->m_Elements.m_nAllocationCount )
          v4 = -1;
      }
      while ( v4 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F6B0
// Name: public: CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>(
        CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl*)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int> > *this)
{
  CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DC50
// Name: protected: enum CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::NodeColor_t CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::Color(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Color(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( i == -1 )
    return dword_4C9194;
  else
    return this->m_Elements.m_pMemory[i].m_Tag;
}

//------------------------------------------------------------------------------
// Address: 0x0042F810
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( i == -1 )
    return dword_4C9190;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0042F870
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0042F8D0
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( i == -1 )
    return dword_4C918C;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0042F930
// Name: public: bool CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4C918C == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x0042F9E0
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::FindInsertionPosition(struct vgui::ListPanel::IndexItem_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        const vgui::ListPanel::IndexItem_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FAD0
// Name: public: bool CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0042FE10
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v8; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v9; // eax

  v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C918C = -1;
      dword_4C9190 = -1;
      dword_4C9194 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0042FFC0
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v6; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v7; // eax

  v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00430130
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::InsertRebalance(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v7; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v18; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v19; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v20; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v23; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00431270
// Name: public: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431330
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::FirstInorder(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C918C = -1;
      dword_4C9190 = -1;
      dword_4C9194 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C918C = -1;
      dword_4C9190 = -1;
      dword_4C9194 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004313D0
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::NextInorder(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C918C = -1;
    dword_4C9190 = -1;
    dword_4C9194 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431540
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::LastInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LastInorder(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C918C = -1;
      dword_4C9190 = -1;
      dword_4C9194 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( v3[1] == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C918C = -1;
      dword_4C9190 = -1;
      dword_4C9194 = 1;
    }
    if ( result == -1 )
      result = dword_4C918C;
    else
      result = this->m_Elements.m_pMemory[result].m_Right;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431640
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RemoveRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveRebalance(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v5; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v6; // ecx
  int m_Parent; // edi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v8; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v9; // ecx
  int m_Right; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v11; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v12; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v13; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v14; // edx
  int m_Left; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v16; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v17; // edx
  int v18; // edx
  int *v19; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v20; // edx
  int v21; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v22; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v23; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v24; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v25; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v26; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v27; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v28; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v29; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v30; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v31; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v32; // edx
  int v33; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v34; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v35; // edx
  int v36; // edx
  int *v37; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v38; // edx
  int v39; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v40; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v41; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v42; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v43; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v44; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v45; // ecx

  v2 = elem;
  if ( elem != this->m_Root )
  {
    v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
    do
    {
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      if ( v5->m_Tag != 1 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      if ( v2 == -1 )
        v6 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v6 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v6->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C918C = -1;
        dword_4C9190 = -1;
        dword_4C9194 = 1;
      }
      if ( m_Parent == -1 )
      {
        v8 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      }
      else
      {
        v8 = &this->m_Elements.m_pMemory[m_Parent];
        v2 = elem;
      }
      if ( v2 == v8->m_Left )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Parent == -1 )
          v9 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v9 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v9->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Right == -1 )
          v11 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v11 = &this->m_Elements.m_pMemory[m_Right];
        if ( v11->m_Tag == 0 )
        {
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
            this,
            elem: m_Parent);
          v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( elem == -1 )
            v12 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v12 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v12->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( m_Parent == -1 )
            v13 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v13 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v13->m_Right;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Right == -1 )
          v14 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[m_Right];
        m_Left = v14->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Left == -1 )
          v16 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Left];
        if ( v16->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( m_Right == -1 )
            v17 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v17 = &this->m_Elements.m_pMemory[m_Right];
          v18 = v17->m_Right;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          v19 = v18 == -1
              ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v18];
          if ( v19[3] == 1 )
            goto LABEL_146;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Right == -1 )
          v20 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[m_Right];
        v21 = v20->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( v21 == -1 )
          v22 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v22 = &this->m_Elements.m_pMemory[v21];
        if ( v22->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( m_Right == -1 )
            v23 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[m_Right];
          this->m_Elements.m_pMemory[v23->m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
            this,
            elem: m_Right);
          v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( elem == -1 )
            v24 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( m_Parent == -1 )
            v25 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v25 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v25->m_Right;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Parent == -1 )
          v26 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[m_Parent];
        this->m_Elements.m_pMemory[m_Right].m_Tag = v26->m_Tag;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
        if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Right == -1 )
          v27 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v27 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v27->m_Right].m_Tag = 1;
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
          this,
          elem: m_Parent);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Parent == -1 )
          v28 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v28->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Right == -1 )
          v29 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v29 = &this->m_Elements.m_pMemory[m_Right];
        if ( v29->m_Tag == 0 )
        {
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
            this,
            elem: m_Parent);
          v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( elem == -1 )
            v30 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v30->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( m_Parent == -1 )
            v31 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v31->m_Left;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Right == -1 )
          v32 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v32 = &this->m_Elements.m_pMemory[m_Right];
        v33 = v32->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( v33 == -1 )
          v34 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v34 = &this->m_Elements.m_pMemory[v33];
        if ( v34->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( m_Right == -1 )
            v35 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v35 = &this->m_Elements.m_pMemory[m_Right];
          v36 = v35->m_Left;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          v37 = v36 == -1
              ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v36];
          if ( v37[3] == 1 )
          {
LABEL_146:
            if ( m_Right != -1 )
            {
              this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
              v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
            }
            elem = m_Parent;
            goto LABEL_188;
          }
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Right == -1 )
          v38 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v38 = &this->m_Elements.m_pMemory[m_Right];
        v39 = v38->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( v39 == -1 )
          v40 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v40 = &this->m_Elements.m_pMemory[v39];
        if ( v40->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( m_Right == -1 )
            v41 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v41 = &this->m_Elements.m_pMemory[m_Right];
          this->m_Elements.m_pMemory[v41->m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
            this,
            elem: m_Right);
          v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( elem == -1 )
            v42 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v42 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v42->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( m_Parent == -1 )
            v43 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v43 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v43->m_Left;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Parent == -1 )
          v44 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v44 = &this->m_Elements.m_pMemory[m_Parent];
        this->m_Elements.m_pMemory[m_Right].m_Tag = v44->m_Tag;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
        if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C918C = -1;
          dword_4C9190 = -1;
          dword_4C9194 = 1;
        }
        if ( m_Right == -1 )
          v45 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v45 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v45->m_Left].m_Tag = 1;
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
          this,
          elem: m_Parent);
      }
      v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      elem = this->m_Root;
LABEL_188:
      v2 = elem;
    }
    while ( elem != this->m_Root );
  }
  this->m_Elements.m_pMemory[v2].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004323C0
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Unlink(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int m_Left; // edi
  int v4; // ecx
  int v5; // eax
  int *v6; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v7; // eax
  int v8; // ebx
  int v9; // ebx
  CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> >::NodeColor_t ycolor; // [esp+Ch] [ebp-8h]
  int x; // [esp+10h] [ebp-4h]

  m_Left = elem;
  if ( elem != -1 )
  {
    v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C918C = -1;
      dword_4C9190 = -1;
      dword_4C9194 = 1;
    }
    if ( this->m_Elements.m_pMemory[elem].m_Left != -1 )
    {
      if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
             this,
             i: elem) == -1 )
      {
        v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      }
      else
      {
        v5 = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
               this,
               i: elem);
        v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
        m_Left = v5;
        while ( 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          v6 = m_Left == -1
             ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
             : (int *)&this->m_Elements.m_pMemory[m_Left];
          if ( *v6 == -1 )
            break;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C918C = -1;
            dword_4C9190 = -1;
            dword_4C9194 = 1;
          }
          if ( m_Left == -1 )
            m_Left = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            m_Left = this->m_Elements.m_pMemory[m_Left].m_Left;
        }
      }
    }
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C918C = -1;
      dword_4C9190 = -1;
      dword_4C9194 = 1;
    }
    if ( m_Left == -1 )
      v7 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v7 = &this->m_Elements.m_pMemory[m_Left];
    if ( v7->m_Left == -1 )
    {
      x = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
            this,
            i: m_Left);
      v8 = x;
    }
    else
    {
      v8 = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
             this,
             i: m_Left);
      x = v8;
    }
    if ( v8 != -1 )
      this->m_Elements.m_pMemory[v8].m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                                  this,
                                                  i: m_Left);
    if ( m_Left == this->m_Root )
    {
      this->m_Root = v8;
    }
    else if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
                this,
                i: m_Left) )
    {
      this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                   this,
                                   i: m_Left)].m_Left = v8;
    }
    else
    {
      this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                   this,
                                   i: m_Left)].m_Right = v8;
    }
    ycolor = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Color(
               this,
               i: m_Left);
    if ( m_Left != elem )
    {
      v9 = m_Left;
      this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                                      this,
                                                      i: elem);
      this->m_Elements.m_pMemory[v9].m_Right = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
                                                 this,
                                                 i: elem);
      this->m_Elements.m_pMemory[v9].m_Left = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
                                                this,
                                                i: elem);
      if ( elem == this->m_Root )
      {
        this->m_Root = m_Left;
      }
      else if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
                  this,
                  i: elem) )
      {
        this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                     this,
                                     i: elem)].m_Left = m_Left;
      }
      else
      {
        this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                     this,
                                     i: elem)].m_Right = m_Left;
      }
      if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
             this,
             i: m_Left) != -1 )
        this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
             this,
             i: m_Left) != -1 )
        this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      this->m_Elements.m_pMemory[v9].m_Tag = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Color(
                                               this,
                                               i: elem);
      v8 = x;
    }
    if ( v8 != -1 && ycolor == BLACK )
      CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveRebalance(
        this,
        elem: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457A30
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( i == -1 )
    return dword_4CB62C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00457A90
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB61C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_4CB61C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00457B00
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB61C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00457B60
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB61C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00457BD0
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::FindInsertionPosition(void __near * const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        void *const *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB61C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB61C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457CC0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( i == -1 )
    return dword_4CB628;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00457D20
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB628 = -1;
        dword_4CB62C = -1;
        dword_4CB630 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB628 = -1;
        dword_4CB62C = -1;
        dword_4CB630 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457E10
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB628 = -1;
      dword_4CB62C = -1;
      dword_4CB630 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB628 = -1;
      dword_4CB62C = -1;
      dword_4CB630 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00457EB0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4CB628 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00457F60
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00458060
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00458160
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00458210
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB628 = -1;
      dword_4CB62C = -1;
      dword_4CB630 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004583C0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004586D0
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::Find(void __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        void *const *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB61C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB61C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x004587D0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB628 = -1;
        dword_4CB62C = -1;
        dword_4CB630 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB628 = -1;
        dword_4CB62C = -1;
        dword_4CB630 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x004588C0
// Name: public: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458980
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CB628 = -1;
            dword_4CB62C = -1;
            dword_4CB630 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458A40
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB628 = -1;
    dword_4CB62C = -1;
    dword_4CB630 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB628 = -1;
          dword_4CB62C = -1;
          dword_4CB630 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB628 = -1;
        dword_4CB62C = -1;
        dword_4CB630 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB628 = -1;
        dword_4CB62C = -1;
        dword_4CB630 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00458BB0
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB61C = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB61C = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB61C = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB61C = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB61C = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB61C = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB61C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB61C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB61C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB61C = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB61C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB61C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB61C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB61C = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00459160
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB628 = -1;
        dword_4CB62C = -1;
        dword_4CB630 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB628 = -1;
        dword_4CB62C = -1;
        dword_4CB630 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB628 = -1;
        dword_4CB62C = -1;
        dword_4CB630 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB628 = -1;
        dword_4CB62C = -1;
        dword_4CB630 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB628 = -1;
          dword_4CB62C = -1;
          dword_4CB630 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB628 = -1;
          dword_4CB62C = -1;
          dword_4CB630 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CB628 = -1;
            dword_4CB62C = -1;
            dword_4CB630 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CB628 = -1;
            dword_4CB62C = -1;
            dword_4CB630 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB628 = -1;
          dword_4CB62C = -1;
          dword_4CB630 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB628 = -1;
          dword_4CB62C = -1;
          dword_4CB630 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CB628 = -1;
            dword_4CB62C = -1;
            dword_4CB630 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CB628 = -1;
            dword_4CB62C = -1;
            dword_4CB630 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004595C0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004596D0
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B940
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class CUtlString,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  UtlRBTreeLinks_t<unsigned short> *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : &this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( v3->m_Left == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    if ( (_WORD)result == 0xFFFF )
      result = `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045BB10
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class CUtlString,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // si
  int result; // eax
  int v5; // edx
  UtlRBTreeLinks_t<unsigned short> *v6; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *v7; // eax
  int v8; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *v9; // ecx
  int m_Parent; // ecx
  UtlRBTreeLinks_t<unsigned short> *v11; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i)->m_Right == 0xFFFF )
  {
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *)CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(this, i);
    v8 = `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      result = v7->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v9 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v9->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v11 = (_WORD)m_Parent == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[m_Parent];
      if ( v11->m_Right != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v8 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = &this->m_Elements.m_pMemory[(unsigned __int16)result];
    }
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Right;
    v5 = `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( v6->m_Left == 0xFFFF )
        break;
      if ( (v5 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( (_WORD)result == 0xFFFF )
        result = `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045CB80
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class CUtlString,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // si
  int v4; // ebx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // esi
  bool v7; // sf
  int p_m_Data; // ebx
  unsigned __int16 v9; // bx
  unsigned __int16 v10; // [esp+4h] [ebp-8h]
  unsigned __int16 it; // [esp+8h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      while ( 1 )
      {
        v4 = v3;
        v10 = v3;
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i: it)->m_Left != v3 )
        {
          m_pMemory = this->m_Elements.m_pMemory;
          v6 = v3;
          v7 = m_pMemory[v4].m_Data.elem.m_Storage.m_Memory.m_nGrowSize < 0;
          p_m_Data = (int)&m_pMemory[v4].m_Data;
          *(_DWORD *)(p_m_Data + 16) = 0;
          if ( !v7 )
          {
            if ( *(_DWORD *)(p_m_Data + 4) != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(p_m_Data + 4));
              *(_DWORD *)(p_m_Data + 4) = 0;
            }
            *(_DWORD *)(p_m_Data + 8) = 0;
          }
          LOWORD(v4) = v10;
          this->m_Elements.m_pMemory[v6].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v6].m_Left = it;
          this->m_FirstFree = it;
          v3 = it;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        v9 = (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount ? -1 : v4 + 1;
        it = v9;
        if ( v9 == 0xFFFF )
          break;
        v3 = v9;
      }
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DDD0
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class CUtlString,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class CUtlString,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045DE40
// Name: public: void CUtlDict<class CUtlString,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlString,unsigned short>::RemoveAll(CUtlDict<CUtlString,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00463550
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( i == -1 )
    return dword_4CB8DC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x004635B0
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( i == -1 )
    return dword_4CB8D8;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00463610
// Name: public: bool CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<char const *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( m_Parent == -1 )
    return dword_4CB8D8 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x004636C0
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::FindInsertionPosition(char const __near * const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FindInsertionPosition(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        const char *const *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB8D8 = -1;
        dword_4CB8DC = -1;
        dword_4CB8E0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB8D8 = -1;
        dword_4CB8DC = -1;
        dword_4CB8E0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004637B0
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<char const *,int> *m_pMemory; // edx
  UtlRBTreeNode_t<char const *,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463870
// Name: public: bool CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<char const *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00463920
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<char const *,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<char const *,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<char const *,int> *v8; // ecx
  UtlRBTreeNode_t<char const *,int> *v9; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB8D8 = -1;
      dword_4CB8DC = -1;
      dword_4CB8E0 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00463AD0
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<char const *,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<char const *,int> *v6; // eax
  UtlRBTreeNode_t<char const *,int> *v7; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00463D30
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FirstInorder(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB8D8 = -1;
      dword_4CB8DC = -1;
      dword_4CB8E0 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4CB8D8 = -1;
      dword_4CB8DC = -1;
      dword_4CB8E0 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463DD0
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NextInorder(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<char const *,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4CB8D8 = -1;
    dword_4CB8DC = -1;
    dword_4CB8E0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB8D8 = -1;
          dword_4CB8DC = -1;
          dword_4CB8E0 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB8D8 = -1;
        dword_4CB8DC = -1;
        dword_4CB8E0 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB8D8 = -1;
        dword_4CB8DC = -1;
        dword_4CB8E0 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463F40
// Name: public: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RemoveAll(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CB8D8 = -1;
            dword_4CB8DC = -1;
            dword_4CB8E0 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464000
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<char const *,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<char const *,int> *v7; // ecx
  UtlRBTreeNode_t<char const *,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<char const *,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<char const *,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<char const *,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<char const *,int> *v18; // ecx
  UtlRBTreeNode_t<char const *,int> *v19; // eax
  UtlRBTreeNode_t<char const *,int> *v20; // eax
  UtlRBTreeNode_t<char const *,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<char const *,int> *v23; // ecx
  UtlRBTreeNode_t<char const *,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB8D8 = -1;
        dword_4CB8DC = -1;
        dword_4CB8E0 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB8D8 = -1;
        dword_4CB8DC = -1;
        dword_4CB8E0 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB8D8 = -1;
        dword_4CB8DC = -1;
        dword_4CB8E0 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4CB8D8 = -1;
        dword_4CB8DC = -1;
        dword_4CB8E0 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB8D8 = -1;
          dword_4CB8DC = -1;
          dword_4CB8E0 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB8D8 = -1;
          dword_4CB8DC = -1;
          dword_4CB8E0 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CB8D8 = -1;
            dword_4CB8DC = -1;
            dword_4CB8E0 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CB8D8 = -1;
            dword_4CB8DC = -1;
            dword_4CB8E0 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB8D8 = -1;
          dword_4CB8DC = -1;
          dword_4CB8E0 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4CB8D8 = -1;
          dword_4CB8DC = -1;
          dword_4CB8E0 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CB8D8 = -1;
            dword_4CB8DC = -1;
            dword_4CB8E0 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CB8D8 = -1;
            dword_4CB8DC = -1;
            dword_4CB8E0 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00486580
// Name: public: void CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<0>,0>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4CC9DC = -1;
            dword_4CC9E0 = -1;
            dword_4CC9E4 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486640
// Name: public: CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<0>,0>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::~CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<0>,0>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this)
{
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}
