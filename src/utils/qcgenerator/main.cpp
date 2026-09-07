// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/qcgenerator/main.cpp
// Functions: 197
// ============================================================

#include "utils\qcgenerator\main.h"

//------------------------------------------------------------------------------
// Address: 0x00401240
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *this,
        int elem,
        const vgui::MessageMapItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::MessageMapItem_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401580
// Name: public: virtual bool CVguiSteamApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVguiSteamApp::PreInit(CVguiSteamApp *this)
{
  vgui::Panel *v1; // ecx
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+0h] [ebp-Ch] BYREF
  void *(__cdecl *factory)(const char *, int *); // [esp+4h] [ebp-8h]
  void *(__cdecl *factoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  pFactoryList = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  factory = CAppSystemGroup::GetFactory();
  CSteamApplication::PostShutdown(this: v1);
  factoryList = CAppSystemGroup::GetFactory();
  return vgui::VGui_InitInterfacesList(moduleName: "CVguiSteamApp", &factoryList, numFactories: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004015E0
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
// Address: 0x00401630
// Name: void InitializeVGUI(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitializeVGUI()
{
  vgui::Panel *v0; // esi
  vgui::Panel *v1; // eax
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  int v4; // eax
  CQCGenMain *v5; // eax
  CQCGenMain *v6; // eax

  v0 = nullptr;
  g_pVGui->SetSleep(this: g_pVGui, a2: false);
  v1 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v1 != nullptr )
    v0 = vgui::Panel::Panel(this: v1, parent: nullptr, panelName: "TopPanel");
  v0->SetVisible(this: v0, a2: true);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = v0->GetVPanel(this: v0);
  v3->SetEmbeddedPanel(this: v2, a2: v4);
  g_pVGuiSchemeManager->LoadSchemeFromFile(this: g_pVGuiSchemeManager, a2: "resource/sourcescheme.res", a3: nullptr);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/platform_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/vgui_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "QCGenerator_english.txt", a3: nullptr, a4: false);
  g_pVGui->Start(this: g_pVGui);
  v5 = (CQCGenMain *)operator new(nSize: 0x22Cu);
  if ( v5 != nullptr )
    v6 = CQCGenMain::CQCGenMain(this: v5, parent: v0, pszPath: pszPath, pszScene: pszScene, name: "CQCGenMain");
  else
    v6 = nullptr;
  g_pMainFrame = v6;
  v6->MoveToCenterOfScreen(this: v6);
  g_pMainFrame->Activate(this: g_pMainFrame);
  g_pMainFrame->SetSizeable(this: g_pMainFrame, a2: true);
  g_pMainFrame->SetMenuButtonVisible(this: g_pMainFrame, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x004017B0
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  return AppMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow, pAppSystemGroup: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x004017E0
// Name: public: virtual bool CQCGeneratorApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQCGeneratorApp::Create(CQCGeneratorApp *this)
{
  AppSystemInfo_t appSystems[3]; // [esp+0h] [ebp-1Ch] BYREF
  const char *v3; // [esp+18h] [ebp-4h]

  appSystems[2].m_pInterfaceName = defaultValue;
  v3 = defaultValue;
  appSystems[0].m_pInterfaceName = "inputsystem.dll";
  appSystems[1].m_pModuleName = "InputSystemVersion001";
  appSystems[1].m_pInterfaceName = "vgui2.dll";
  appSystems[2].m_pModuleName = "VGUI_ivgui008";
  return CAppSystemGroup::AddSystems(this, pSystemList: (AppSystemInfo_t *)&appSystems[0].m_pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x00401820
// Name: public: virtual bool CQCGeneratorApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CQCGeneratorApp::PreInit(CQCGeneratorApp *this)
{
  HMODULE AppInstance; // eax
  IFileSystem_vtbl *v4; // esi
  char *BaseDirectory; // eax
  char dirName[264]; // [esp+0h] [ebp-108h] BYREF

  if ( !CVguiSteamApp::PreInit(this) )
    return 0;
  FileSystem_SetErrorMode(errorMode: FS_ERRORMODE_AUTO);
  if ( path[0] == 0 )
  {
    AppInstance = (HMODULE)GetAppInstance();
    GetModuleFileNameA(hModule: AppInstance, lpFilename: path, nSize: 0x104u);
    V_StripLastDir(dirName: path, maxlen: 260);
    V_StripTrailingSlash(ppath: path);
  }
  V_strncpy(pDest: &dirName[4], pSrc: path, maxLen: 260);
  V_AppendSlash(pStr: &dirName[4], strSize: 260);
  V_strncat(pDest: &dirName[4], pSrc: "QCGenerator", destBufferSize: 0x104u, max_chars_to_copy: -1);
  if ( !CSteamAppSystemGroup::SetupSearchPaths(
          this,
          pStartingDir: &dirName[4],
          bOnlyUseStartingDir: true,
          bIsTool: true) )
  {
    MessageBoxA(hWnd: nullptr, lpText: "Error", lpCaption: "Unable to initialize file system\n", uType: 0);
    return 0;
  }
  v4 = g_pFullFileSystem->IAppSystem::__vftable;
  BaseDirectory = GetBaseDirectory();
  v4->AddSearchPath(this: g_pFullFileSystem, a2: BaseDirectory, a3: "MAIN", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "platform", a3: "PLATFORM", a4: PATH_ADD_TO_HEAD);
  g_pFullFileSystem->AddSearchPath(
    this: g_pFullFileSystem,
    a2: ".\\QCGenerator\\",
    a3: "DEFAULT_WRITE_PATH",
    a4: PATH_ADD_TO_HEAD);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401950
// Name: public: virtual void CQCGeneratorApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGeneratorApp::PostShutdown(CQCGeneratorApp *this)
{
  CSteamApplication::PostShutdown((vgui::Panel *)this);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00401970
// Name: public: virtual int CQCGeneratorApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CQCGeneratorApp::Main(CQCGeneratorApp *this)
{
  int v1; // eax
  int v2; // ecx
  int v3; // eax
  const char *v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  const char *v9; // eax

  v1 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v1 + 32))(a1: v1, a2: "-path", a3: 0) != 0
    && (v3 = _CommandLine(a1: v2),
        v4 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 32))(
                             a1: v3,
                             a2: "-path",
                             a3: 0),
        _V_strcpy(dest: pszPath, src: v4),
        v6 = _CommandLine(a1: v5),
        (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 32))(a1: v6, a2: "-scene", a3: 0) != 0) )
  {
    v8 = _CommandLine(a1: v7);
    v9 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 32))(
                         a1: v8,
                         a2: "-scene",
                         a3: 0);
    _V_strcpy(dest: pszScene, src: v9);
    InitializeVGUI();
    while ( g_pVGui->IsRunning(this: g_pVGui) )
    {
      Sleep(dwMilliseconds: 0xAu);
      g_pVGui->RunFrame(this: g_pVGui);
    }
    if ( g_pMainFrame != nullptr )
      ((void (__thiscall *)(CQCGenMain *, int))g_pMainFrame->dtr_Panel)(a1: g_pMainFrame, a2: 1);
    return 1;
  }
  else
  {
    MessageBoxA(
      hWnd: nullptr,
      lpText: "Usage: QCGenerator.exe -path [path to smd files] -scene [name of scene]\n",
      lpCaption: "Error",
      uType: 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401AC0
// Name: public: CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this)
{
  if ( this->m_nGrowSize >= 0 )
  {
    if ( this->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory);
      this->m_pMemory = nullptr;
    }
    this->m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401AF0
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00401B50
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
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
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C10
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int v1; // ebx
  int result; // eax
  UtlRBTreeLinks_t<unsigned short> *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : &this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( v3->m_Left == 0xFFFF )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    if ( (_WORD)result == 0xFFFF )
      result = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401CC0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // di
  int result; // eax
  int v5; // edx
  UtlRBTreeLinks_t<unsigned short> *v6; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v7; // eax
  int v8; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v9; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v11; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i)->m_Right == 0xFFFF )
  {
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                                                               this,
                                                                                               i);
    v8 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      result = v7->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v9 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v9->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v11 = m_Parent == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[m_Parent];
      if ( v11->m_Right != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = &this->m_Elements.m_pMemory[(unsigned __int16)result];
    }
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Right;
    v5 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( v6->m_Left == 0xFFFF )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( (_WORD)result == 0xFFFF )
        result = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401E70
// Name: public: CUtlVector<void __near * (*)(char const __near *,int __near *),class CUtlMemory<void __near * (*)(char const __near *,int __near *),int>>::~CUtlVector<void __near * (*)(char const __near *,int __near *),class CUtlMemory<void __near * (*)(char const __near *,int __near *),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void * (__cdecl *)(char const *,int *),CUtlMemory<void * (__cdecl *)(char const *,int *),int>>::~CUtlVector<void * (__cdecl *)(char const *,int *),CUtlMemory<void * (__cdecl *)(char const *,int *),int>>(
        CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *this)
{
  bool v2; // sf
  void *(__cdecl **m_pMemory)(const char *, int *); // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401F00
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
// Address: 0x00401FA0
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
// Address: 0x00401FF0
// Name: public: CUtlMap<char const __near *,int,unsigned short>::~CUtlMap<char const __near *,int,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CUtlMap<char const *,int,unsigned short>::~CUtlMap<char const *,int,unsigned short>(
        CUtlMap<char const *,int,unsigned short> *this)
{
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00402000
// Name: public: CAppSystemGroup::~CAppSystemGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAppSystemGroup::~CAppSystemGroup(CAppSystemGroup *this)
{
  CUtlDict<int,unsigned short> *p_m_SystemDict; // edi

  p_m_SystemDict = &this->m_SystemDict;
  CUtlDict<int,unsigned short>::RemoveAll(this: &this->m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &p_m_SystemDict->m_Elements.m_Tree);
  CUtlVector<void * (__cdecl *)(char const *,int *),CUtlMemory<void * (__cdecl *)(char const *,int *),int>>::~CUtlVector<void * (__cdecl *)(char const *,int *),CUtlMemory<void * (__cdecl *)(char const *,int *),int>>(this: &this->m_NonAppSystemFactories);
  CUtlVector<void * (__cdecl *)(char const *,int *),CUtlMemory<void * (__cdecl *)(char const *,int *),int>>::~CUtlVector<void * (__cdecl *)(char const *,int *),CUtlMemory<void * (__cdecl *)(char const *,int *),int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&this->m_Systems);
  CUtlVector<void * (__cdecl *)(char const *,int *),CUtlMemory<void * (__cdecl *)(char const *,int *),int>>::~CUtlVector<void * (__cdecl *)(char const *,int *),CUtlMemory<void * (__cdecl *)(char const *,int *),int>>(this: (CUtlVector<void * (__cdecl*)(char const *,int *),CUtlMemory<void * (__cdecl*)(char const *,int *),int> > *)&this->m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x00403260
// Name: public: void CUtlMemory<struct LODInfo,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<LODInfo,int>::Grow(CUtlMemory<LODInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  LODInfo *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 264 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (LODInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (LODInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403810
// Name: public: int CUtlVector<struct LODInfo,class CUtlMemory<struct LODInfo,int>>::InsertBefore(int,struct LODInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<LODInfo,CUtlMemory<LODInfo,int>>::InsertBefore(
        CUtlVector<LODInfo,CUtlMemory<LODInfo,int> > *this,
        int elem,
        const LODInfo *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  LODInfo *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<LODInfo,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 264 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404570
// Name: protected: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::ShiftElementsRight(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::ShiftElementsRight(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem + num],
      src: &this->m_Memory.m_pMemory[elem],
      count: 56 * (this->m_Size - elem - num));
}

//------------------------------------------------------------------------------
// Address: 0x004045D0
// Name: public: void CUtlMemory<class CUtlSymbolTable,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbolTable,int>::Grow(CUtlMemory<CUtlSymbolTable,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable *m_pMemory; // edx
  bool v7; // zf

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404730
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004047D0
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::RemoveAll(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // edi

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3]);
      --v2;
      --v3;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404810
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
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
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
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404920
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebp
  int m_nAllocationCount; // eax
  unsigned __int16 v5; // cx
  unsigned __int16 index; // di
  int v7; // ebx
  CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>::Iterator_t *v8; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v11; // edx
  CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>::Iterator_t v12; // [esp+6h] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == 0xFFFF )
  {
    p_m_LastAlloc = &this->m_LastAlloc;
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
    {
      v5 = -1;
    }
    else
    {
      v5 = p_m_LastAlloc->index + 1;
    }
    v12.index = v5;
    index = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( p_m_LastAlloc->index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v12.index = (v7 > 0) - 1;
        v8 = &v12;
      }
      else
      {
        v8 = CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>::Next(
               this: (CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> *)&this->m_Elements,
               result: &v12,
               it: (const CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>::Iterator_t *)&this->m_LastAlloc);
      }
      index = v8->index;
      if ( v8->index >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    p_m_LastAlloc->index = index;
    this->m_pElements = m_pMemory;
    return index;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[m_FirstFree].m_Right;
    this->m_pElements = v11;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404A30
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00404B20
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00404E10
// Name: public: int CUtlVector<struct vgui::Label::TImageInfo,class CUtlMemory<struct vgui::Label::TImageInfo,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::Label::TImageInfo,CUtlMemory<vgui::Label::TImageInfo,int>>::InsertBefore(
        CUtlVector<vgui::Label::TImageInfo,CUtlMemory<vgui::Label::TImageInfo,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::Label::TImageInfo *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404E70
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bp
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
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
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
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00404F70
// Name: public: int CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbolTable *m_pMemory; // eax
  int v9; // ebx
  CUtlSymbolTable *v10; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size += num;
  this->m_pElements = m_pMemory;
  CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::ShiftElementsRight(this, elem, num);
  if ( num > 0 )
  {
    v9 = elem;
    do
    {
      v10 = &this->m_Memory.m_pMemory[v9];
      if ( v10 != nullptr )
        CUtlSymbolTable::CUtlSymbolTable(this: v10, growSize: 0, initSize: 16, caseInsensitive: false);
      ++v9;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404FF0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v10; // ecx
  unsigned __int16 v11; // bp
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v12; // ecx
  unsigned __int16 v13; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v15; // ecx
  unsigned __int16 m_Right; // dx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v17; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v18; // ecx
  unsigned __int16 v19; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v20; // eax
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v23; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v24; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v25; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v26; // ecx
  unsigned __int16 v27; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v28; // eax
  int v29; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v30; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Parent == 0xFFFF )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v13 == 0xFFFF )
        v14 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v17 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v18 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = &this->m_Elements.m_pMemory[elem];
        v19 = v18->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v19 == 0xFFFF )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v19];
        if ( v20->m_Right == elem )
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
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v22 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = &this->m_Elements.m_pMemory[v9];
          v9 = v22->m_Parent;
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v11 = v23->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
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
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v24 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = &this->m_Elements.m_pMemory[v11];
        m_Right = v24->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v25 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[m_Right];
        if ( v25->m_Tag == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v26 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[elem];
        v27 = v26->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v27 == 0xFFFF )
          v28 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[v27];
        if ( v28->m_Left == elem )
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
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v30 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[v9];
          v9 = v30->m_Parent;
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v31 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[v9];
          v11 = v31->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
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
// Address: 0x004055D0
// Name: public: CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::~CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::~CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable *m_pMemory; // eax

  CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405630
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
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
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
    v6 = parent;
    if ( isLeft )
      m_pMemory[v6].m_Left = i;
    else
      m_pMemory[v6].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A80
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}

//------------------------------------------------------------------------------
// Address: 0x00405B60
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *insert)
{
  unsigned __int16 v3; // di
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v5; // ecx
  BOOL parent; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int16 v8[2]; // [esp+10h] [ebp-4h] BYREF

  *(_DWORD *)v8 = 0xFFFF;
  LOBYTE(parent) = 0;
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    parent: v8,
    leftchild: (bool *)&parent);
  v3 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent: v8[0],
    isLeft: parent);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  v5 = v3;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)-8 )
    m_pMemory[v5].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040A950
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this)
{
  bool v2; // sf
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DC00
// Name: public: class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>::Iterator_t CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>::Next(class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *__thiscall CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>::Next(
        CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *result,
        const CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>::Iterator_t *it)
{
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v3; // eax

  v3 = result;
  if ( (unsigned __int16)(it->index + 1) >= this->m_nAllocationCount )
    result->index = -1;
  else
    result->index = it->index + 1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040DDF0
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
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
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
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DF00
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040E000
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0040E140
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(int,int,class CUtlSymbolTable::CLess const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *__thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        int growSize,
        int initSize,
        const CUtlSymbolTable::CLess *lessfunc)
{
  this->m_Elements.m_pMemory = nullptr;
  this->m_Elements.m_nAllocationCount = initSize;
  this->m_Elements.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * initSize);
  this->m_Root = -1;
  this->m_FirstFree = -1;
  this->m_NumElements = 0;
  this->m_LastAlloc.index = -1;
  this->m_pElements = this->m_Elements.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040E1A0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bp
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
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
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
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0040E2B0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
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
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E370
// Name: public: int CUtlVector<class vgui::ClickPanel __near *,class CUtlMemory<class vgui::ClickPanel __near *,int>>::InsertBefore(int,class vgui::ClickPanel __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        int elem,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  vgui::TreeNode **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040E3E0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v10; // ecx
  unsigned __int16 v11; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx
  unsigned __int16 v13; // dx
  UtlRBTreeLinks_t<unsigned short> *v14; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v15; // edx
  unsigned __int16 m_Right; // dx
  UtlRBTreeLinks_t<unsigned short> *v17; // ebp
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v18; // edx
  unsigned __int16 v19; // dx
  UtlRBTreeLinks_t<unsigned short> *v20; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v21; // edx
  unsigned __int16 m_Left; // dx
  UtlRBTreeLinks_t<unsigned short> *v23; // ebp
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v24; // edx
  unsigned __int16 v25; // dx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v26; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = m_Parent == 0xFFFF
         ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v14 = v13 == 0xFFFF
          ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v17 = m_Right == 0xFFFF
            ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v18 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[elem];
          v19 = v18->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          v20 = v19 == 0xFFFF
              ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
              : &this->m_Elements.m_pMemory[v19];
          if ( v20->m_Right == elem )
          {
            elem = v9;
            CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
              this,
              elem: v9);
            v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v21 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[v11];
        m_Left = v21->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v23 = m_Left == 0xFFFF
            ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Left];
        if ( v23->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v24 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          v25 = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v25 == 0xFFFF )
            v26 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v26 = &this->m_Elements.m_pMemory[v25];
          if ( v26->m_Left == elem )
          {
            elem = v9;
            CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
              this,
              elem: v9);
            v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040EA10
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
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
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
// Address: 0x0040EB00
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
// Address: 0x0040EB80
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v3; // di
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  BOOL parent; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int16 v7[2]; // [esp+10h] [ebp-4h] BYREF

  *(_DWORD *)v7 = 0xFFFF;
  LOBYTE(parent) = 0;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    parent: v7,
    leftchild: (bool *)&parent);
  v3 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::NewNode((CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)this);
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent: v7[0],
    isLeft: parent);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040EEA0
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx
  bool v7; // zf

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 32;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413E40
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  PanelAnimationMapEntry *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004142A0
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  vgui::OverridableColorEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041B6D0
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
    dword_4C23B8 = -1;
    dword_4C23BC = -1;
    dword_4C23C0 = 1;
  }
  if ( i == -1 )
    return dword_4C23BC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0041CF40
// Name: public: bool CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::FindAndRemove(class vgui::PHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041CFA0
// Name: public: int CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::LeftChild(
        CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl*)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23A4 = -1;
    dword_4C23A8 = -1;
    dword_4C23AC = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041CFF0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23B8 = -1;
    dword_4C23BC = -1;
    dword_4C23C0 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041D040
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
    dword_4C23B8 = -1;
    dword_4C23BC = -1;
    dword_4C23C0 = 1;
  }
  if ( i == -1 )
    return dword_4C23B8;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041D090
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
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
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
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D180
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
    dword_4C23CC = -1;
    dword_4C23D0 = -1;
    dword_4C23D4 = 1;
  }
  if ( i == -1 )
    return dword_4C23D0;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0041D1D0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23CC = -1;
    dword_4C23D0 = -1;
    dword_4C23D4 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041D220
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
    dword_4C23CC = -1;
    dword_4C23D0 = -1;
    dword_4C23D4 = 1;
  }
  if ( i == -1 )
    return dword_4C23CC;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041D270
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
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
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
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D360
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
    dword_4C23E0 = -1;
    dword_4C23E4 = -1;
    dword_4C23E8 = 1;
  }
  if ( i == -1 )
    return dword_4C23E4;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0041D3B0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23E0 = -1;
    dword_4C23E4 = -1;
    dword_4C23E8 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041D400
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
    dword_4C23E0 = -1;
    dword_4C23E4 = -1;
    dword_4C23E8 = 1;
  }
  if ( i == -1 )
    return dword_4C23E0;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0041D450
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
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
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
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D540
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
      dword_4C23B8 = -1;
      dword_4C23BC = -1;
      dword_4C23C0 = 1;
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
      dword_4C23B8 = -1;
      dword_4C23BC = -1;
      dword_4C23C0 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041D5E0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v3; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
         this,
         i);
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23B8 = -1;
    dword_4C23BC = -1;
    dword_4C23C0 = 1;
  }
  if ( v3 == -1 )
    return `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v3].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041D650
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v5; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
         this,
         i: elem);
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23B8 = -1;
    dword_4C23BC = -1;
    dword_4C23C0 = 1;
  }
  if ( v3 == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[v3];
  this->m_Elements.m_pMemory[elem].m_Right = v4->m_Left;
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23B8 = -1;
    dword_4C23BC = -1;
    dword_4C23C0 = 1;
  }
  if ( v3 == -1 )
    v5 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v5 = &this->m_Elements.m_pMemory[v3];
  if ( v5->m_Left != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::LeftChild(
                                 this,
                                 i: v3)].m_Parent = elem;
  if ( v3 != -1 )
    this->m_Elements.m_pMemory[v3].m_Parent = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v3;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = v3;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = v3;
  }
  this->m_Elements.m_pMemory[v3].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041D780
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int elem)
{
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v3; // eax
  int m_Left; // edi
  int v5; // eax

  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23B8 = -1;
    dword_4C23BC = -1;
    dword_4C23C0 = 1;
  }
  if ( elem == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[elem];
  m_Left = v3->m_Left;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
                                              this,
                                              i: v3->m_Left);
  if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
         this,
         i: m_Left) != -1 )
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
  else
  {
    v5 = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
           this,
           i: v5) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041D880
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v3; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
         this,
         i);
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23CC = -1;
    dword_4C23D0 = -1;
    dword_4C23D4 = 1;
  }
  if ( v3 == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v3].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041D8F0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v5; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
         this,
         i: elem);
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23CC = -1;
    dword_4C23D0 = -1;
    dword_4C23D4 = 1;
  }
  if ( v3 == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[v3];
  this->m_Elements.m_pMemory[elem].m_Right = v4->m_Left;
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23CC = -1;
    dword_4C23D0 = -1;
    dword_4C23D4 = 1;
  }
  if ( v3 == -1 )
    v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v5 = &this->m_Elements.m_pMemory[v3];
  if ( v5->m_Left != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(
                                 this,
                                 i: v3)].m_Parent = elem;
  if ( v3 != -1 )
    this->m_Elements.m_pMemory[v3].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v3;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = v3;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = v3;
  }
  this->m_Elements.m_pMemory[v3].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041DA20
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Left; // edi
  int v5; // eax

  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23CC = -1;
    dword_4C23D0 = -1;
    dword_4C23D4 = 1;
  }
  if ( elem == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[elem];
  m_Left = v3->m_Left;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
                                              this,
                                              i: v3->m_Left);
  if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
         this,
         i: m_Left) != -1 )
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
  else
  {
    v5 = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
           this,
           i: v5) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041DB20
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v3; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
         this,
         i);
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23E0 = -1;
    dword_4C23E4 = -1;
    dword_4C23E8 = 1;
  }
  if ( v3 == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v3].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0041DB90
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v5; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
         this,
         i: elem);
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23E0 = -1;
    dword_4C23E4 = -1;
    dword_4C23E8 = 1;
  }
  if ( v3 == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[v3];
  this->m_Elements.m_pMemory[elem].m_Right = v4->m_Left;
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23E0 = -1;
    dword_4C23E4 = -1;
    dword_4C23E8 = 1;
  }
  if ( v3 == -1 )
    v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v5 = &this->m_Elements.m_pMemory[v3];
  if ( v5->m_Left != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(
                                 this,
                                 i: v3)].m_Parent = elem;
  if ( v3 != -1 )
    this->m_Elements.m_pMemory[v3].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v3;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = v3;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = v3;
  }
  this->m_Elements.m_pMemory[v3].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041DCC0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Left; // edi
  int v5; // eax

  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C23E0 = -1;
    dword_4C23E4 = -1;
    dword_4C23E8 = 1;
  }
  if ( elem == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[elem];
  m_Left = v3->m_Left;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
                                              this,
                                              i: v3->m_Left);
  if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
         this,
         i: m_Left) != -1 )
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
  else
  {
    v5 = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
           this,
           i: v5) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0041DE80
// Name: public: int CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>::Find(struct CKeyBindingsMgr::KBContext_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Find(
        CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl*)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int> > *this,
        const CKeyBindingsMgr::KBContext_t *search)
{
  int m_Root; // ebp
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
        dword_4C23A4 = -1;
        dword_4C23A8 = -1;
        dword_4C23AC = 1;
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
        dword_4C23A4 = -1;
        dword_4C23A8 = -1;
        dword_4C23AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041DF70
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  vgui::BoundKey_t *v9; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: v9, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041DFE0
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
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
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
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041E0D0
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
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
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
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041E1C0
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E250
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
      dword_4C23CC = -1;
      dword_4C23D0 = -1;
      dword_4C23D4 = 1;
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
      dword_4C23CC = -1;
      dword_4C23D0 = -1;
      dword_4C23D4 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041E2F0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // esi
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int v7; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int m_Parent; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
         this,
         i) == -1 )
  {
    result = CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
               this,
               i);
    v7 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v8->m_Parent;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
      }
      v10 = m_Parent == -1
          ? &`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v10[1] != v2 )
        break;
      v2 = result;
      if ( result == -1 )
        break;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
      }
      result = this->m_Elements.m_pMemory[result].m_Parent;
    }
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
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
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
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
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
// Address: 0x0041E480
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
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
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
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041E570
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E600
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
      dword_4C23E0 = -1;
      dword_4C23E4 = -1;
      dword_4C23E8 = 1;
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
      dword_4C23E0 = -1;
      dword_4C23E4 = -1;
      dword_4C23E8 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041E6A0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // esi
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int v7; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int m_Parent; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
         this,
         i) == -1 )
  {
    result = CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
               this,
               i);
    v7 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v8->m_Parent;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
      }
      v10 = m_Parent == -1
          ? &`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v10[1] != v2 )
        break;
      v2 = result;
      if ( result == -1 )
        break;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
      }
      result = this->m_Elements.m_pMemory[result].m_Parent;
    }
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
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
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
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
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
// Address: 0x0041E830
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E8C0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // esi
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int v7; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v8; // ecx
  int m_Parent; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RightChild(
         this,
         i) == -1 )
  {
    result = CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Parent(
               this,
               i);
    v7 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v8->m_Parent;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
      }
      v10 = m_Parent == -1
          ? &`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v10[1] != v2 )
        break;
      v2 = result;
      if ( result == -1 )
        break;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
      }
      result = this->m_Elements.m_pMemory[result].m_Parent;
    }
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
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
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
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
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
// Address: 0x0041EA50
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  int *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v10; // ecx
  int v11; // ebp
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v15; // ecx
  int m_Right; // ecx
  int *v17; // edx
  int v18; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v19; // ecx
  int v20; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v21; // eax
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v24; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v25; // ecx
  int m_Left; // ecx
  int *v27; // eax
  int v28; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v29; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *v30; // eax

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
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
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
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7[3] != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
      }
      if ( v9 == -1 )
        v12 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23B8 = -1;
        dword_4C23BC = -1;
        dword_4C23C0 = 1;
      }
      v14 = v13 == -1
          ? &`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v13];
      if ( *v14 == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23B8 = -1;
          dword_4C23BC = -1;
          dword_4C23C0 = 1;
        }
        if ( v11 == -1 )
          v15 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23B8 = -1;
          dword_4C23BC = -1;
          dword_4C23C0 = 1;
        }
        v17 = m_Right == -1
            ? &`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Right];
        if ( v17[3] != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C23B8 = -1;
            dword_4C23BC = -1;
            dword_4C23C0 = 1;
          }
          v18 = elem;
          if ( elem == -1 )
          {
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          }
          else
          {
            v19 = &this->m_Elements.m_pMemory[elem];
            v18 = elem;
          }
          v20 = v19->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C23B8 = -1;
            dword_4C23BC = -1;
            dword_4C23C0 = 1;
          }
          if ( v20 == -1 )
            v21 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v21 = &this->m_Elements.m_pMemory[v20];
          if ( v21->m_Right == v18 )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateLeft(
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
              dword_4C23B8 = -1;
              dword_4C23BC = -1;
              dword_4C23C0 = 1;
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
              dword_4C23B8 = -1;
              dword_4C23BC = -1;
              dword_4C23C0 = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v11 = v24->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23B8 = -1;
          dword_4C23BC = -1;
          dword_4C23C0 = 1;
        }
        if ( v11 == -1 )
          v25 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[v11];
        m_Left = v25->m_Left;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23B8 = -1;
          dword_4C23BC = -1;
          dword_4C23C0 = 1;
        }
        v27 = m_Left == -1
            ? &`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( v27[3] != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v28 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v28 = `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C23B8 = -1;
              dword_4C23BC = -1;
              dword_4C23C0 = 1;
            }
            if ( v9 == -1 )
              v29 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v29 = &this->m_Elements.m_pMemory[v9];
            v9 = v29->m_Parent;
            if ( (v28 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v28 | 1;
              `CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C23B8 = -1;
              dword_4C23BC = -1;
              dword_4C23C0 = 1;
            }
            if ( v9 == -1 )
              v30 = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v30 = &this->m_Elements.m_pMemory[v9];
            v11 = v30->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041EF90
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  int *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v10; // ecx
  int v11; // ebp
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v15; // ecx
  int m_Right; // ecx
  int *v17; // edx
  int v18; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v19; // ecx
  int v20; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v21; // eax
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v24; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v25; // ecx
  int m_Left; // ecx
  int *v27; // eax
  int v28; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v29; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *v30; // eax

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
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
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
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7[3] != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
      }
      if ( v9 == -1 )
        v12 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23CC = -1;
        dword_4C23D0 = -1;
        dword_4C23D4 = 1;
      }
      v14 = v13 == -1
          ? &`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v13];
      if ( *v14 == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23CC = -1;
          dword_4C23D0 = -1;
          dword_4C23D4 = 1;
        }
        if ( v11 == -1 )
          v15 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23CC = -1;
          dword_4C23D0 = -1;
          dword_4C23D4 = 1;
        }
        v17 = m_Right == -1
            ? &`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Right];
        if ( v17[3] != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C23CC = -1;
            dword_4C23D0 = -1;
            dword_4C23D4 = 1;
          }
          v18 = elem;
          if ( elem == -1 )
          {
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          }
          else
          {
            v19 = &this->m_Elements.m_pMemory[elem];
            v18 = elem;
          }
          v20 = v19->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C23CC = -1;
            dword_4C23D0 = -1;
            dword_4C23D4 = 1;
          }
          if ( v20 == -1 )
            v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v21 = &this->m_Elements.m_pMemory[v20];
          if ( v21->m_Right == v18 )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
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
              dword_4C23CC = -1;
              dword_4C23D0 = -1;
              dword_4C23D4 = 1;
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
              dword_4C23CC = -1;
              dword_4C23D0 = -1;
              dword_4C23D4 = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v11 = v24->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23CC = -1;
          dword_4C23D0 = -1;
          dword_4C23D4 = 1;
        }
        if ( v11 == -1 )
          v25 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[v11];
        m_Left = v25->m_Left;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23CC = -1;
          dword_4C23D0 = -1;
          dword_4C23D4 = 1;
        }
        v27 = m_Left == -1
            ? &`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( v27[3] != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v28 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v28 = `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C23CC = -1;
              dword_4C23D0 = -1;
              dword_4C23D4 = 1;
            }
            if ( v9 == -1 )
              v29 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v29 = &this->m_Elements.m_pMemory[v9];
            v9 = v29->m_Parent;
            if ( (v28 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v28 | 1;
              `CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C23CC = -1;
              dword_4C23D0 = -1;
              dword_4C23D4 = 1;
            }
            if ( v9 == -1 )
              v30 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v30 = &this->m_Elements.m_pMemory[v9];
            v11 = v30->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F4D0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  int *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v10; // ecx
  int v11; // ebp
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v15; // ecx
  int m_Right; // ecx
  int *v17; // edx
  int v18; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v19; // ecx
  int v20; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v21; // eax
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v24; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v25; // ecx
  int m_Left; // ecx
  int *v27; // eax
  int v28; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v29; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *v30; // eax

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
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
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
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7[3] != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
      }
      if ( v9 == -1 )
        v12 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C23E0 = -1;
        dword_4C23E4 = -1;
        dword_4C23E8 = 1;
      }
      v14 = v13 == -1
          ? &`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v13];
      if ( *v14 == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23E0 = -1;
          dword_4C23E4 = -1;
          dword_4C23E8 = 1;
        }
        if ( v11 == -1 )
          v15 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23E0 = -1;
          dword_4C23E4 = -1;
          dword_4C23E8 = 1;
        }
        v17 = m_Right == -1
            ? &`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Right];
        if ( v17[3] != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C23E0 = -1;
            dword_4C23E4 = -1;
            dword_4C23E8 = 1;
          }
          v18 = elem;
          if ( elem == -1 )
          {
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          }
          else
          {
            v19 = &this->m_Elements.m_pMemory[elem];
            v18 = elem;
          }
          v20 = v19->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C23E0 = -1;
            dword_4C23E4 = -1;
            dword_4C23E8 = 1;
          }
          if ( v20 == -1 )
            v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v21 = &this->m_Elements.m_pMemory[v20];
          if ( v21->m_Right == v18 )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
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
              dword_4C23E0 = -1;
              dword_4C23E4 = -1;
              dword_4C23E8 = 1;
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
              dword_4C23E0 = -1;
              dword_4C23E4 = -1;
              dword_4C23E8 = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v11 = v24->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23E0 = -1;
          dword_4C23E4 = -1;
          dword_4C23E8 = 1;
        }
        if ( v11 == -1 )
          v25 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[v11];
        m_Left = v25->m_Left;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C23E0 = -1;
          dword_4C23E4 = -1;
          dword_4C23E8 = 1;
        }
        v27 = m_Left == -1
            ? &`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( v27[3] != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v28 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v28 = `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C23E0 = -1;
              dword_4C23E4 = -1;
              dword_4C23E8 = 1;
            }
            if ( v9 == -1 )
              v29 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v29 = &this->m_Elements.m_pMemory[v9];
            v9 = v29->m_Parent;
            if ( (v28 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v28 | 1;
              `CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C23E0 = -1;
              dword_4C23E4 = -1;
              dword_4C23E8 = 1;
            }
            if ( v9 == -1 )
              v30 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v30 = &this->m_Elements.m_pMemory[v9];
            v11 = v30->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041FDE0
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
// Address: 0x0041FE40
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
// Address: 0x0041FEA0
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
// Address: 0x0041FF10
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
// Address: 0x0041FF80
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
// Address: 0x00422540
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
// Address: 0x00422AD0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int,class CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t,int>,int>>::Insert(struct CUtlMap<char const __near *,class vgui::IPanelAnimationPropertyConverter __near *,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::Insert(
        CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t *insert)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  v7 = -1;
  LOBYTE(parent) = 0;
  CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    parent: &v7,
    leftchild: (bool *)&parent);
  v3 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int,CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent: v7,
    isLeft: parent);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00422B40
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Insert(struct CUtlMap<char const __near *,struct CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::Insert(
        CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t *insert)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  v7 = -1;
  LOBYTE(parent) = 0;
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    parent: &v7,
    leftchild: (bool *)&parent);
  v3 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent: v7,
    isLeft: parent);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00422BB0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Insert(struct CUtlMap<char const __near *,struct CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::Insert(
        CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t *insert)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  v7 = -1;
  LOBYTE(parent) = 0;
  CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    parent: &v7,
    leftchild: (bool *)&parent);
  v3 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode(this);
  CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent: v7,
    isLeft: parent);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00422C20
// Name: public: void CUtlRBTree<struct CKeyBindingsMgr::KBContext_t,int,bool (*)(struct CKeyBindingsMgr::KBContext_t const __near &,struct CKeyBindingsMgr::KBContext_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyBindingsMgr::KBContext_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::RemoveAll(
        CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl*)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // ebx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Elements.m_pMemory[v3].m_Data.m_Panels);
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422D50
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
// Address: 0x00426F60
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
    dword_4C3B6C = -1;
    dword_4C3B70 = -1;
    dword_4C3B74 = 1;
  }
  if ( i == -1 )
    return dword_4C3B70;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00426FB0
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
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
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
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004270C0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C3B6C = -1;
    dword_4C3B70 = -1;
    dword_4C3B74 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00427110
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
    dword_4C3B6C = -1;
    dword_4C3B70 = -1;
    dword_4C3B74 = 1;
  }
  if ( i == -1 )
    return dword_4C3B6C;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00427160
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
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
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
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427250
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebp
  int m_nAllocationCount; // eax
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // ebx
  unsigned __int16 *v8; // eax
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<void *,unsigned short> *v11; // edx
  CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>::Iterator_t v12; // [esp+6h] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == 0xFFFF )
  {
    p_m_LastAlloc = &this->m_LastAlloc;
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
    {
      v5 = -1;
    }
    else
    {
      v5 = p_m_LastAlloc->index + 1;
    }
    v12.index = v5;
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( p_m_LastAlloc->index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v12.index = (v7 > 0) - 1;
        v8 = (unsigned __int16 *)&v12;
      }
      else
      {
        v8 = (unsigned __int16 *)CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>::Next(
                                   this: &this->m_Elements,
                                   result: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *)&v12,
                                   it: &this->m_LastAlloc);
      }
      v6 = *v8;
      if ( *v8 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    p_m_LastAlloc->index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[m_FirstFree].m_Right;
    this->m_pElements = v11;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427360
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
      dword_4C3B6C = -1;
      dword_4C3B70 = -1;
      dword_4C3B74 = 1;
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
      dword_4C3B6C = -1;
      dword_4C3B70 = -1;
      dword_4C3B74 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427400
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00427500
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00427600
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v3; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
         this,
         i);
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C3B6C = -1;
    dword_4C3B70 = -1;
    dword_4C3B74 = 1;
  }
  if ( v3 == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v3].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00427670
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v5; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
         this,
         i: elem);
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C3B6C = -1;
    dword_4C3B70 = -1;
    dword_4C3B74 = 1;
  }
  if ( v3 == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[v3];
  this->m_Elements.m_pMemory[elem].m_Right = v4->m_Left;
  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C3B6C = -1;
    dword_4C3B70 = -1;
    dword_4C3B74 = 1;
  }
  if ( v3 == -1 )
    v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v5 = &this->m_Elements.m_pMemory[v3];
  if ( v5->m_Left != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(
                                 this,
                                 i: v3)].m_Parent = elem;
  if ( v3 != -1 )
    this->m_Elements.m_pMemory[v3].m_Parent = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v3;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = v3;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = v3;
  }
  this->m_Elements.m_pMemory[v3].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = v3;
}

//------------------------------------------------------------------------------
// Address: 0x004277A0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v3; // eax
  int m_Left; // edi
  int v5; // eax

  if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C3B6C = -1;
    dword_4C3B70 = -1;
    dword_4C3B74 = 1;
  }
  if ( elem == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[elem];
  m_Left = v3->m_Left;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
                                              this,
                                              i: v3->m_Left);
  if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
         this,
         i: m_Left) != -1 )
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
  else
  {
    v5 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
           this,
           i: v5) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00427950
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  vgui::AnimationController::ActiveAnimation_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004279D0
// Name: public: unsigned short CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::Find(void __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        void *const *search)
{
  unsigned __int16 m_Root; // bp
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
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
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
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00427AE0
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
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
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
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00427BD0
// Name: public: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
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
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427C90
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427D20
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // esi
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int v7; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int m_Parent; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RightChild(
         this,
         i) == -1 )
  {
    result = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Parent(
               this,
               i);
    v7 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v8->m_Parent;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
      }
      v10 = m_Parent == -1
          ? &`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v10[1] != v2 )
        break;
      v2 = result;
      if ( result == -1 )
        break;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
      }
      result = this->m_Elements.m_pMemory[result].m_Parent;
    }
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
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
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
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
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
// Address: 0x00427EB0
// Name: protected: void CUtlRBTree<void __near *,unsigned short,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  UtlRBTreeNode_t<void *,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v7; // ecx
  UtlRBTreeNode_t<void *,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<void *,unsigned short> *v10; // ecx
  unsigned __int16 v11; // cx
  UtlRBTreeNode_t<void *,unsigned short> *v12; // edx
  unsigned __int16 v13; // dx
  UtlRBTreeLinks_t<unsigned short> *v14; // edx
  UtlRBTreeNode_t<void *,unsigned short> *v15; // edx
  unsigned __int16 m_Right; // dx
  UtlRBTreeLinks_t<unsigned short> *v17; // ebp
  UtlRBTreeNode_t<void *,unsigned short> *v18; // edx
  unsigned __int16 v19; // dx
  UtlRBTreeLinks_t<unsigned short> *v20; // eax
  UtlRBTreeNode_t<void *,unsigned short> *v21; // edx
  unsigned __int16 m_Left; // dx
  UtlRBTreeLinks_t<unsigned short> *v23; // ebp
  UtlRBTreeNode_t<void *,unsigned short> *v24; // edx
  unsigned __int16 v25; // dx
  UtlRBTreeNode_t<void *,unsigned short> *v26; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<void *,unsigned short> *)&`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = m_Parent == 0xFFFF
         ? &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<void *,unsigned short> *)&`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<void *,unsigned short> *)&`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<void *,unsigned short> *)&`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v14 = v13 == 0xFFFF
          ? &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<void *,unsigned short> *)&`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v17 = m_Right == 0xFFFF
            ? &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v18 = (UtlRBTreeNode_t<void *,unsigned short> *)&`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[elem];
          v19 = v18->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          v20 = v19 == 0xFFFF
              ? &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
              : &this->m_Elements.m_pMemory[v19];
          if ( v20->m_Right == elem )
          {
            elem = v9;
            CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateLeft(
              this,
              elem: v9);
            v9 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v21 = (UtlRBTreeNode_t<void *,unsigned short> *)&`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[v11];
        m_Left = v21->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v23 = m_Left == 0xFFFF
            ? &`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Left];
        if ( v23->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v24 = (UtlRBTreeNode_t<void *,unsigned short> *)&`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          v25 = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v25 == 0xFFFF )
            v26 = (UtlRBTreeNode_t<void *,unsigned short> *)&`CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v26 = &this->m_Elements.m_pMemory[v25];
          if ( v26->m_Left == elem )
          {
            elem = v9;
            CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateRight(
              this,
              elem: v9);
            v9 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00428420
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  int *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v10; // ecx
  int v11; // ebp
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v15; // ecx
  int m_Right; // ecx
  int *v17; // edx
  int v18; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v19; // ecx
  int v20; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v21; // eax
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v24; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v25; // ecx
  int m_Left; // ecx
  int *v27; // eax
  int v28; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v29; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *v30; // eax

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
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
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
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7[3] != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
      }
      if ( v9 == -1 )
        v12 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C3B6C = -1;
        dword_4C3B70 = -1;
        dword_4C3B74 = 1;
      }
      v14 = v13 == -1
          ? &`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v13];
      if ( *v14 == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C3B6C = -1;
          dword_4C3B70 = -1;
          dword_4C3B74 = 1;
        }
        if ( v11 == -1 )
          v15 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C3B6C = -1;
          dword_4C3B70 = -1;
          dword_4C3B74 = 1;
        }
        v17 = m_Right == -1
            ? &`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Right];
        if ( v17[3] != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C3B6C = -1;
            dword_4C3B70 = -1;
            dword_4C3B74 = 1;
          }
          v18 = elem;
          if ( elem == -1 )
          {
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          }
          else
          {
            v19 = &this->m_Elements.m_pMemory[elem];
            v18 = elem;
          }
          v20 = v19->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C3B6C = -1;
            dword_4C3B70 = -1;
            dword_4C3B74 = 1;
          }
          if ( v20 == -1 )
            v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v21 = &this->m_Elements.m_pMemory[v20];
          if ( v21->m_Right == v18 )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
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
              dword_4C3B6C = -1;
              dword_4C3B70 = -1;
              dword_4C3B74 = 1;
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
              dword_4C3B6C = -1;
              dword_4C3B70 = -1;
              dword_4C3B74 = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v11 = v24->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C3B6C = -1;
          dword_4C3B70 = -1;
          dword_4C3B74 = 1;
        }
        if ( v11 == -1 )
          v25 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[v11];
        m_Left = v25->m_Left;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C3B6C = -1;
          dword_4C3B70 = -1;
          dword_4C3B74 = 1;
        }
        v27 = m_Left == -1
            ? &`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( v27[3] != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v28 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v28 = `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C3B6C = -1;
              dword_4C3B70 = -1;
              dword_4C3B74 = 1;
            }
            if ( v9 == -1 )
              v29 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v29 = &this->m_Elements.m_pMemory[v9];
            v9 = v29->m_Parent;
            if ( (v28 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v28 | 1;
              `CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C3B6C = -1;
              dword_4C3B70 = -1;
              dword_4C3B74 = 1;
            }
            if ( v9 == -1 )
              v30 = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v30 = &this->m_Elements.m_pMemory[v9];
            v11 = v30->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00428960
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
// Address: 0x00428A70
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
// Address: 0x00428CF0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,class CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Insert(struct CUtlMap<char const __near *,struct CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::Insert(
        CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t *insert)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  v7 = -1;
  LOBYTE(parent) = 0;
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    parent: &v7,
    leftchild: (bool *)&parent);
  v3 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent: v7,
    isLeft: parent);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00428D60
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // ebp
  bool v3; // sf
  CUtlVector<vgui::AnimationController::AnimCommand_t,CUtlMemory<vgui::AnimationController::AnimCommand_t,int> > *p_cmdList; // esi
  vgui::AnimationController::AnimCommand_t *m_pMemory; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = this->m_Memory.m_pMemory[v2].cmdList.m_Memory.m_nGrowSize < 0;
      p_cmdList = &this->m_Memory.m_pMemory[v2].cmdList;
      this->m_Memory.m_pMemory[v2].cmdList.m_Size = 0;
      if ( !v3 )
      {
        if ( p_cmdList->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_cmdList->m_Memory.m_pMemory);
          this = v6;
          p_cmdList->m_Memory.m_pMemory = nullptr;
        }
        p_cmdList->m_Memory.m_nAllocationCount = 0;
      }
      v3 = p_cmdList->m_Memory.m_nGrowSize < 0;
      m_pMemory = p_cmdList->m_Memory.m_pMemory;
      p_cmdList->m_pElements = p_cmdList->m_Memory.m_pMemory;
      if ( !v3 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          this = v6;
          p_cmdList->m_Memory.m_pMemory = nullptr;
        }
        p_cmdList->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428FE0
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004330E0
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
    dword_4C5534 = -1;
    dword_4C5538 = -1;
    dword_4C553C = 1;
  }
  if ( i == -1 )
    return dword_4C553C;
  else
    return this->m_Elements.m_pMemory[i].m_Tag;
}

//------------------------------------------------------------------------------
// Address: 0x00433130
// Name: protected: bool CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::IsBlack(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsBlack(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C5534 = -1;
    dword_4C5538 = -1;
    dword_4C553C = 1;
  }
  if ( i == -1 )
    return dword_4C553C == 1;
  else
    return this->m_Elements.m_pMemory[i].m_Tag == 1;
}

//------------------------------------------------------------------------------
// Address: 0x00434D00
// Name: public: int CUtlVector<class vgui::Panel __near *,class CUtlMemory<class vgui::Panel __near *,int>>::Find(class vgui::Panel __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int>>::Find(
        CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *this,
        vgui::Panel **src)
{
  int m_Size; // edx
  int result; // eax
  vgui::Panel **i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00434D30
// Name: public: bool CUtlVector<int,class CUtlMemory<int,int>>::HasElement(int const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlVector<int,CUtlMemory<int,int>>::HasElement(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        const int *src)
{
  int m_Size; // edx
  int v3; // eax
  int *m_pMemory; // ecx

  m_Size = this->m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    while ( *m_pMemory != *src )
    {
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_5;
    }
  }
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00434D60
// Name: public: int CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::InsertBefore(int,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertBefore(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int elem,
        unsigned __int8 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  unsigned __int8 *v9; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00434DC0
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
    dword_4C5534 = -1;
    dword_4C5538 = -1;
    dword_4C553C = 1;
  }
  if ( i == -1 )
    return dword_4C5538;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00434E10
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
    dword_4C5534 = -1;
    dword_4C5538 = -1;
    dword_4C553C = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00434E60
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
    dword_4C5534 = -1;
    dword_4C5538 = -1;
    dword_4C553C = 1;
  }
  if ( i == -1 )
    return dword_4C5534;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00434EB0
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
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
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
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434FA0
// Name: public: bool CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  int v3; // eax

  v3 = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
         this,
         i);
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C5534 = -1;
    dword_4C5538 = -1;
    dword_4C553C = 1;
  }
  if ( v3 == -1 )
    return `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v3].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00435010
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
// Address: 0x00435370
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v3; // edi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v4; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v5; // eax

  v3 = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
         this,
         i: elem);
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C5534 = -1;
    dword_4C5538 = -1;
    dword_4C553C = 1;
  }
  if ( v3 == -1 )
    v4 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[v3];
  this->m_Elements.m_pMemory[elem].m_Right = v4->m_Left;
  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C5534 = -1;
    dword_4C5538 = -1;
    dword_4C553C = 1;
  }
  if ( v3 == -1 )
    v5 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v5 = &this->m_Elements.m_pMemory[v3];
  if ( v5->m_Left != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
                                 this,
                                 i: v3)].m_Parent = elem;
  if ( v3 != -1 )
    this->m_Elements.m_pMemory[v3].m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v3;
  }
  else if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = v3;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = v3;
  }
  this->m_Elements.m_pMemory[v3].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = v3;
}

//------------------------------------------------------------------------------
// Address: 0x004354A0
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v3; // eax
  int m_Left; // edi
  int v5; // eax

  if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C5534 = -1;
    dword_4C5538 = -1;
    dword_4C553C = 1;
  }
  if ( elem == -1 )
    v3 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[elem];
  m_Left = v3->m_Left;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
                                              this,
                                              i: v3->m_Left);
  if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
         this,
         i: m_Left) != -1 )
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
  else
  {
    v5 = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
           this,
           i: v5) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004355A0
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::InsertRebalance(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int v4; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v5; // ecx
  int m_Parent; // ecx
  int *v7; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v10; // ecx
  int v11; // ebp
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v15; // ecx
  int m_Right; // ecx
  int *v17; // edx
  int v18; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v19; // ecx
  int v20; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v21; // eax
  int v22; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v23; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v24; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v25; // ecx
  int m_Left; // ecx
  int *v27; // eax
  int v28; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v29; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v30; // eax

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
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
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
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7[3] != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( v9 == -1 )
        v12 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      v14 = v13 == -1
          ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v13];
      if ( *v14 == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( v11 == -1 )
          v15 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        v17 = m_Right == -1
            ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Right];
        if ( v17[3] != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C5534 = -1;
            dword_4C5538 = -1;
            dword_4C553C = 1;
          }
          v18 = elem;
          if ( elem == -1 )
          {
            v19 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          }
          else
          {
            v19 = &this->m_Elements.m_pMemory[elem];
            v18 = elem;
          }
          v20 = v19->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C5534 = -1;
            dword_4C5538 = -1;
            dword_4C553C = 1;
          }
          if ( v20 == -1 )
            v21 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v21 = &this->m_Elements.m_pMemory[v20];
          if ( v21->m_Right == v18 )
          {
            elem = v9;
            CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
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
              dword_4C5534 = -1;
              dword_4C5538 = -1;
              dword_4C553C = 1;
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
              dword_4C5534 = -1;
              dword_4C5538 = -1;
              dword_4C553C = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v11 = v24->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( v11 == -1 )
          v25 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[v11];
        m_Left = v25->m_Left;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        v27 = m_Left == -1
            ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( v27[3] != 0 )
        {
          if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v28 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v28 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C5534 = -1;
              dword_4C5538 = -1;
              dword_4C553C = 1;
            }
            if ( v9 == -1 )
              v29 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v29 = &this->m_Elements.m_pMemory[v9];
            v9 = v29->m_Parent;
            if ( (v28 & 1) == 0 )
            {
              `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v28 | 1;
              `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C5534 = -1;
              dword_4C5538 = -1;
              dword_4C553C = 1;
            }
            if ( v9 == -1 )
              v30 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v30 = &this->m_Elements.m_pMemory[v9];
            v11 = v30->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00436800
// Name: public: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436890
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
      dword_4C5534 = -1;
      dword_4C5538 = -1;
      dword_4C553C = 1;
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
      dword_4C5534 = -1;
      dword_4C5538 = -1;
      dword_4C553C = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00436930
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::NextInorder(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i)
{
  int v2; // esi
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int v7; // edx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v8; // ecx
  int m_Parent; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
         this,
         i) == -1 )
  {
    result = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
               this,
               i);
    v7 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v8->m_Parent;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      v10 = m_Parent == -1
          ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v10[1] != v2 )
        break;
      v2 = result;
      if ( result == -1 )
        break;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      result = this->m_Elements.m_pMemory[result].m_Parent;
    }
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
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
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
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
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
// Address: 0x00436AC0
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
      dword_4C5534 = -1;
      dword_4C5538 = -1;
      dword_4C553C = 1;
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
      dword_4C5534 = -1;
      dword_4C5538 = -1;
      dword_4C553C = 1;
    }
    if ( result == -1 )
      result = dword_4C5534;
    else
      result = this->m_Elements.m_pMemory[result].m_Right;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00436B60
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(CUtlVector<int,CUtlMemory<int,int> > *this, int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00436BC0
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LinkToParent(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v4; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::InsertRebalance(
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
    CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436C30
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::RemoveRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveRebalance(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v2; // edi
  int v4; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v5; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v6; // ecx
  int m_Parent; // ebp
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v8; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v9; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v11; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v12; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v13; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v14; // ecx
  int m_Left; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v16; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v17; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v18; // ecx
  int v19; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v20; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v21; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v22; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v23; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v24; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v25; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v26; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v27; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v28; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v29; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v30; // ecx
  int v31; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v32; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v33; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v34; // ecx
  int v35; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v36; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v37; // eax
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v38; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v39; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v40; // ecx
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *v41; // ecx

  v2 = elem;
  while ( elem != this->m_Root )
  {
    v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4C5534 = -1;
      dword_4C5538 = -1;
      dword_4C553C = 1;
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
      dword_4C5534 = -1;
      dword_4C5538 = -1;
      dword_4C553C = 1;
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
      dword_4C5534 = -1;
      dword_4C5538 = -1;
      dword_4C553C = 1;
    }
    if ( m_Parent == -1 )
      v8 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v8 = &this->m_Elements.m_pMemory[m_Parent];
    if ( v2 == v8->m_Left )
    {
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
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
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
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
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
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
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
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
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
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
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( m_Left == -1 )
        v16 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v16 = &this->m_Elements.m_pMemory[m_Left];
      if ( v16->m_Tag == 1 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( m_Right == -1 )
          v17 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v17 = &this->m_Elements.m_pMemory[m_Right];
        if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsBlack(
               this,
               i: v17->m_Right) )
        {
          goto LABEL_136;
        }
        v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      }
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( m_Right == -1 )
        v18 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v18 = &this->m_Elements.m_pMemory[m_Right];
      v19 = v18->m_Right;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( v19 == -1 )
        v20 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v20 = &this->m_Elements.m_pMemory[v19];
      if ( v20->m_Tag == 1 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v21->m_Left].m_Tag = 1;
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
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( elem == -1 )
          v22 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v22 = &this->m_Elements.m_pMemory[elem];
        m_Parent = v22->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( m_Parent == -1 )
          v23 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v23 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v23->m_Right;
      }
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( m_Parent == -1 )
        v24 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v24 = &this->m_Elements.m_pMemory[m_Parent];
      this->m_Elements.m_pMemory[m_Right].m_Tag = v24->m_Tag;
      this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
      if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( m_Right == -1 )
        v25 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v25 = &this->m_Elements.m_pMemory[m_Right];
      this->m_Elements.m_pMemory[v25->m_Right].m_Tag = 1;
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
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( m_Parent == -1 )
        v26 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v26 = &this->m_Elements.m_pMemory[m_Parent];
      m_Right = v26->m_Left;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( m_Right == -1 )
        v27 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v27 = &this->m_Elements.m_pMemory[m_Right];
      if ( v27->m_Tag == 0 )
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
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( elem == -1 )
          v28 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[elem];
        m_Parent = v28->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( m_Parent == -1 )
          v29 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v29 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v29->m_Left;
      }
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( m_Right == -1 )
        v30 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v30 = &this->m_Elements.m_pMemory[m_Right];
      v31 = v30->m_Right;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( v31 == -1 )
        v32 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v32 = &this->m_Elements.m_pMemory[v31];
      if ( v32->m_Tag == 1 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( m_Right == -1 )
          v33 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v33 = &this->m_Elements.m_pMemory[m_Right];
        if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::IsBlack(
               this,
               i: v33->m_Left) )
        {
LABEL_136:
          if ( m_Right != -1 )
            this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          elem = m_Parent;
          goto LABEL_179;
        }
        v4 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      }
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( m_Right == -1 )
        v34 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v34 = &this->m_Elements.m_pMemory[m_Right];
      v35 = v34->m_Left;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( v35 == -1 )
        v36 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v36 = &this->m_Elements.m_pMemory[v35];
      if ( v36->m_Tag == 1 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( m_Right == -1 )
          v37 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v37 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v37->m_Right].m_Tag = 1;
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
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( elem == -1 )
          v38 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v38 = &this->m_Elements.m_pMemory[elem];
        m_Parent = v38->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( m_Parent == -1 )
          v39 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v39 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v39->m_Left;
      }
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( m_Parent == -1 )
        v40 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v40 = &this->m_Elements.m_pMemory[m_Parent];
      this->m_Elements.m_pMemory[m_Right].m_Tag = v40->m_Tag;
      this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
      if ( (`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C5534 = -1;
        dword_4C5538 = -1;
        dword_4C553C = 1;
      }
      if ( m_Right == -1 )
        v41 = (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)&`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v41 = &this->m_Elements.m_pMemory[m_Right];
      this->m_Elements.m_pMemory[v41->m_Left].m_Tag = 1;
      CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RotateRight(
        this,
        elem: m_Parent);
    }
    elem = this->m_Root;
LABEL_179:
    v2 = elem;
  }
  this->m_Elements.m_pMemory[v2].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00437890
// Name: protected: void CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Unlink(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        int elem)
{
  int v4; // eax
  int v5; // ecx
  int m_Left; // edi
  int *v7; // eax
  int v8; // ebp
  int v9; // [esp+Ch] [ebp-4h]
  int x; // [esp+14h] [ebp+4h]

  if ( elem != -1 )
  {
    if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
           this,
           i: elem) == -1
      || CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
           this,
           i: elem) == -1 )
    {
      m_Left = elem;
    }
    else
    {
      v4 = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
             this,
             i: elem);
      v5 = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard';
      m_Left = v4;
      while ( 1 )
      {
        if ( (v5 & 1) == 0 )
        {
          v5 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v5;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        v7 = m_Left == -1
           ? &`CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel
           : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( *v7 == -1 )
          break;
        if ( (v5 & 1) == 0 )
        {
          v5 |= 1u;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::`local static guard' = v5;
          `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C5534 = -1;
          dword_4C5538 = -1;
          dword_4C553C = 1;
        }
        if ( m_Left == -1 )
          m_Left = `CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          m_Left = this->m_Elements.m_pMemory[m_Left].m_Left;
      }
    }
    if ( CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
           this,
           i: m_Left) == -1 )
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
    v9 = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Color(
           this,
           i: m_Left);
    if ( m_Left != elem )
    {
      this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Parent(
                                                      this,
                                                      i: elem);
      this->m_Elements.m_pMemory[m_Left].m_Right = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RightChild(
                                                     this,
                                                     i: elem);
      this->m_Elements.m_pMemory[m_Left].m_Left = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LeftChild(
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
      this->m_Elements.m_pMemory[m_Left].m_Tag = CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Color(
                                                   this,
                                                   i: elem);
      v8 = x;
    }
    if ( v8 != -1 && v9 == 1 )
      CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveRebalance(
        this,
        elem: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437AD0
// Name: public: CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::~CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::~CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this)
{
  CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this);
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
// Address: 0x00438000
// Name: public: int CUtlRBTree<struct vgui::ListPanel::IndexItem_t,int,bool (*)(struct vgui::ListPanel::IndexItem_t const __near &,struct vgui::ListPanel::IndexItem_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct vgui::ListPanel::IndexItem_t,int>,int>>::Insert(struct vgui::ListPanel::IndexItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::Insert(
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl*)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int> > *this,
        const vgui::ListPanel::IndexItem_t *insert)
{
  int v3; // edi
  UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  v7 = -1;
  LOBYTE(parent) = 0;
  CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    parent: &v7,
    leftchild: (bool *)&parent);
  v3 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent: v7,
    isLeft: parent);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004452E0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x00445EB0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004461B0
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  vgui::RichText::TFormatStream *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0044E1C0
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00450170
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::CopyArray(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::CopyArray(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        const wchar_t *pArray,
        int size)
{
  int i; // eax

  this->m_Size = 0;
  CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x00452340
// Name: public: void CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::Remove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004527C0
// Name: public: void CUtlVector<int,class CUtlMemory<int,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<int,CUtlMemory<int,int>>::EnsureCapacity(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int num)
{
  int *m_pMemory; // edx
  unsigned int v4; // eax
  int *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 4 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004554F0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455AD0
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00457D90
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class CUtlString,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int v1; // ebx
  int result; // eax
  UtlRBTreeLinks_t<unsigned short> *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : &this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( v3->m_Left == 0xFFFF )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
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
// Address: 0x00457F50
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
  unsigned __int16 m_Parent; // cx
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
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v9 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v9->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v11 = m_Parent == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[m_Parent];
      if ( v11->m_Right != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
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
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( v6->m_Left == 0xFFFF )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
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
// Address: 0x00458C10
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  bool v4; // sf
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v5; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v4 = v3->m_Storage.m_Memory.m_nGrowSize < 0;
      v3->m_Storage.m_nActualLength = 0;
      if ( !v4 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v5;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458C70
// Name: public: int CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::InsertBefore(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::FileData_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  vgui::FileData_t *v8; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::FileData_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 288 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_FileAttributes);
    CUtlString::CUtlString(this: &v8->m_CreationTime);
    CUtlString::CUtlString(this: &v8->m_LastAccessTime);
    CUtlString::CUtlString(this: &v8->m_LastWriteTime);
    CUtlString::CUtlString(this: &v8->m_FileName);
    CUtlString::CUtlString(this: &v8->m_FullPath);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00458D10
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class CUtlString,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // bx
  unsigned __int16 v4; // bp
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  unsigned int v6; // esi
  bool v7; // sf
  int p_elem; // ebp
  unsigned __int16 i; // [esp+4h] [ebp-8h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        v4 = v3;
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
        {
          m_pMemory = this->m_Elements.m_pMemory;
          v6 = v3;
          v7 = m_pMemory[v6].m_Data.elem.m_Storage.m_Memory.m_nGrowSize < 0;
          p_elem = (int)&m_pMemory[v6].m_Data.elem;
          m_pMemory[v6].m_Data.elem.m_Storage.m_nActualLength = 0;
          if ( !v7 )
          {
            if ( *(_DWORD *)p_elem != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)p_elem);
              *(_DWORD *)p_elem = 0;
            }
            *(_DWORD *)(p_elem + 4) = 0;
          }
          v4 = v3;
          this->m_Elements.m_pMemory[v6].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v6].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        v3 = v4 + 1;
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459BF0
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459C50
// Name: public: void CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::Purge(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  bool v4; // sf
  vgui::FileData_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      vgui::FileData_t::~FileData_t(this: &this->m_Memory.m_pMemory[v3]);
      --v2;
      --v3;
    }
    while ( v2 >= 0 );
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459F50
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
// Address: 0x00459FB0
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
// Address: 0x0045BB10
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x0045D270
// Name: public: int CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0045D870
// Name: public: int CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>>::InsertBefore(int,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        wchar_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  wchar_t *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0045D8E0
// Name: public: int CUtlVector<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    *(_DWORD *)v8 = 0;
    v8->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0045FA30
// Name: public: void CUtlMemory<struct PanelItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<PanelItem_t,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  PanelItem_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FEF0
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
    dword_4C78B0 = -1;
    dword_4C78B4 = -1;
    dword_4C78B8 = 1;
  }
  if ( i == -1 )
    return dword_4C78B4;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0045FF40
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::LeftChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C78B0 = -1;
    dword_4C78B4 = -1;
    dword_4C78B8 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0045FF90
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
    dword_4C78B0 = -1;
    dword_4C78B4 = -1;
    dword_4C78B8 = 1;
  }
  if ( i == -1 )
    return dword_4C78B0;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0045FFE0
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
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
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
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004600D0
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
// Address: 0x004601A0
// Name: public: bool CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  int v3; // eax

  v3 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
         this,
         i);
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C78B0 = -1;
    dword_4C78B4 = -1;
    dword_4C78B8 = 1;
  }
  if ( v3 == -1 )
    return `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v3].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00460210
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v3; // edi
  UtlRBTreeNode_t<char const *,int> *v4; // eax
  UtlRBTreeNode_t<char const *,int> *v5; // eax

  v3 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
         this,
         i: elem);
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C78B0 = -1;
    dword_4C78B4 = -1;
    dword_4C78B8 = 1;
  }
  if ( v3 == -1 )
    v4 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[v3];
  this->m_Elements.m_pMemory[elem].m_Right = v4->m_Left;
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C78B0 = -1;
    dword_4C78B4 = -1;
    dword_4C78B8 = 1;
  }
  if ( v3 == -1 )
    v5 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v5 = &this->m_Elements.m_pMemory[v3];
  if ( v5->m_Left != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::LeftChild(
                                 this,
                                 i: v3)].m_Parent = elem;
  if ( v3 != -1 )
    this->m_Elements.m_pMemory[v3].m_Parent = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v3;
  }
  else if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = v3;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = v3;
  }
  this->m_Elements.m_pMemory[v3].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00460340
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  UtlRBTreeNode_t<char const *,int> *v3; // eax
  int m_Left; // edi
  int v5; // eax

  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C78B0 = -1;
    dword_4C78B4 = -1;
    dword_4C78B8 = 1;
  }
  if ( elem == -1 )
    v3 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[elem];
  m_Left = v3->m_Left;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
                                              this,
                                              i: v3->m_Left);
  if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
         this,
         i: m_Left) != -1 )
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
  else
  {
    v5 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
           this,
           i: v5) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004604B0
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
      dword_4C78B0 = -1;
      dword_4C78B4 = -1;
      dword_4C78B8 = 1;
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
      dword_4C78B0 = -1;
      dword_4C78B4 = -1;
      dword_4C78B8 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00460550
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NextInorder(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  int v2; // esi
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int v7; // edx
  UtlRBTreeNode_t<char const *,int> *v8; // ecx
  int m_Parent; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
         this,
         i) == -1 )
  {
    result = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
               this,
               i);
    v7 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v8->m_Parent;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
      }
      v10 = m_Parent == -1
          ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v10[1] != v2 )
        break;
      v2 = result;
      if ( result == -1 )
        break;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
      }
      result = this->m_Elements.m_pMemory[result].m_Parent;
    }
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
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
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
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
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
// Address: 0x004606E0
// Name: public: int CUtlVector<struct PanelItem_t,class CUtlMemory<struct PanelItem_t,int>>::InsertBefore(int,struct PanelItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelItem_t,CUtlMemory<PanelItem_t,int>>::InsertBefore(
        CUtlVector<PanelItem_t,CUtlMemory<PanelItem_t,int> > *this,
        int elem,
        const PanelItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelItem_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<PanelItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 84 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00460750
// Name: public: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RemoveAll(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004607E0
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int v4; // eax
  UtlRBTreeNode_t<char const *,int> *v5; // ecx
  int m_Parent; // ecx
  int *v7; // ecx
  UtlRBTreeNode_t<char const *,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<char const *,int> *v10; // ecx
  int v11; // ebp
  UtlRBTreeNode_t<char const *,int> *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  UtlRBTreeNode_t<char const *,int> *v15; // ecx
  int m_Right; // ecx
  int *v17; // edx
  int v18; // edx
  UtlRBTreeNode_t<char const *,int> *v19; // ecx
  int v20; // ecx
  UtlRBTreeNode_t<char const *,int> *v21; // eax
  int v22; // eax
  UtlRBTreeNode_t<char const *,int> *v23; // ecx
  UtlRBTreeNode_t<char const *,int> *v24; // eax
  UtlRBTreeNode_t<char const *,int> *v25; // ecx
  int m_Left; // ecx
  int *v27; // eax
  int v28; // eax
  UtlRBTreeNode_t<char const *,int> *v29; // ecx
  UtlRBTreeNode_t<char const *,int> *v30; // eax

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
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
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
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7[3] != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
      }
      if ( v9 == -1 )
        v12 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4C78B0 = -1;
        dword_4C78B4 = -1;
        dword_4C78B8 = 1;
      }
      v14 = v13 == -1
          ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v13];
      if ( *v14 == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C78B0 = -1;
          dword_4C78B4 = -1;
          dword_4C78B8 = 1;
        }
        if ( v11 == -1 )
          v15 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C78B0 = -1;
          dword_4C78B4 = -1;
          dword_4C78B8 = 1;
        }
        v17 = m_Right == -1
            ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Right];
        if ( v17[3] != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C78B0 = -1;
            dword_4C78B4 = -1;
            dword_4C78B8 = 1;
          }
          v18 = elem;
          if ( elem == -1 )
          {
            v19 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          }
          else
          {
            v19 = &this->m_Elements.m_pMemory[elem];
            v18 = elem;
          }
          v20 = v19->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4C78B0 = -1;
            dword_4C78B4 = -1;
            dword_4C78B8 = 1;
          }
          if ( v20 == -1 )
            v21 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v21 = &this->m_Elements.m_pMemory[v20];
          if ( v21->m_Right == v18 )
          {
            elem = v9;
            CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
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
              dword_4C78B0 = -1;
              dword_4C78B4 = -1;
              dword_4C78B8 = 1;
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
              dword_4C78B0 = -1;
              dword_4C78B4 = -1;
              dword_4C78B8 = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v11 = v24->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C78B0 = -1;
          dword_4C78B4 = -1;
          dword_4C78B8 = 1;
        }
        if ( v11 == -1 )
          v25 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[v11];
        m_Left = v25->m_Left;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4C78B0 = -1;
          dword_4C78B4 = -1;
          dword_4C78B8 = 1;
        }
        v27 = m_Left == -1
            ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( v27[3] != 0 )
        {
          if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
              this,
              elem: v9);
            v28 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v28 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C78B0 = -1;
              dword_4C78B4 = -1;
              dword_4C78B8 = 1;
            }
            if ( v9 == -1 )
              v29 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v29 = &this->m_Elements.m_pMemory[v9];
            v9 = v29->m_Parent;
            if ( (v28 & 1) == 0 )
            {
              `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v28 | 1;
              `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4C78B0 = -1;
              dword_4C78B4 = -1;
              dword_4C78B8 = 1;
            }
            if ( v9 == -1 )
              v30 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v30 = &this->m_Elements.m_pMemory[v9];
            v11 = v30->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00460E00
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::LinkToParent(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<char const *,int> *v4; // eax
  UtlRBTreeNode_t<char const *,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
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
    CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461C80
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::Insert(char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Insert(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        const char *const *insert)
{
  int v3; // edi
  UtlRBTreeNode_t<char const *,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  v7 = -1;
  LOBYTE(parent) = 0;
  CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FindInsertionPosition(
    this,
    insert,
    parent: &v7,
    leftchild: (bool *)&parent);
  v3 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(this);
  CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent: v7,
    isLeft: parent);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<char const *,int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00484530
// Name: public: int CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<0>,0>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::LeftChild(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4C8948 = -1;
    dword_4C894C = -1;
    dword_4C8950 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00484580
// Name: public: void CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<0>,0>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484610
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

//------------------------------------------------------------------------------
// Address: 0x00401A60
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x00402090
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x0040DC40
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *__thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}
