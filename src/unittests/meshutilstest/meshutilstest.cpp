// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: unittests/meshutilstest/meshutilstest.cpp
// Functions: 40
// ============================================================

#include "unittests\meshutilstest\meshutilstest.h"

//------------------------------------------------------------------------------
// Address: 0x00401160
// Name: public: RenderDeviceInfo_t::RenderDeviceInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
RenderDeviceInfo_t *__thiscall RenderDeviceInfo_t::RenderDeviceInfo_t(RenderDeviceInfo_t *this)
{
  *(_QWORD *)&this->m_DisplayMode.m_nVersion = 0;
  *(_QWORD *)&this->m_DisplayMode.m_nHeight = 0;
  *(_QWORD *)&this->m_DisplayMode.m_nRefreshRateNumerator = 0;
  *(_QWORD *)&this->m_nVersion = 0;
  *(_QWORD *)&this->m_DisplayMode.m_nWidth = 0;
  *(_QWORD *)&this->m_DisplayMode.m_Format = 0;
  *(_QWORD *)&this->m_DisplayMode.m_nRefreshRateDenominator = 0;
  *(_QWORD *)&this->m_nMultisampleType = 0;
  this->m_nVersion = 1;
  this->m_DisplayMode.m_nVersion = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004011A0
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  return AppMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow, pAppSystemGroup: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x004011D0
// Name: public: virtual bool CMeshUtilsTestApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMeshUtilsTestApp::Create(CMeshUtilsTestApp *this)
{
  int v2; // eax
  const char *v3; // eax
  ThreeState_t v4; // eax
  int v5; // eax
  const char *v6; // esi
  int Module; // eax
  AppSystemInfo_t appSystems[4]; // [esp+12h] [ebp-138h] BYREF
  ThreadPoolStartParams_t sparms; // [esp+32h] [ebp-118h] BYREF
  char v11; // [esp+146h] [ebp-4h]

  appSystems[3].m_pInterfaceName = defaultValue;
  sparms.nThreads = (int)defaultValue;
  this->m_bExit = false;
  appSystems[0].m_pInterfaceName = "inputsystem";
  appSystems[1].m_pModuleName = "InputSystemVersion001";
  appSystems[1].m_pInterfaceName = "materialsystem2";
  appSystems[2].m_pModuleName = "VMaterialSystem2_001";
  appSystems[2].m_pInterfaceName = "meshsystem";
  appSystems[3].m_pModuleName = "MeshSystem001";
  CAppSystemGroup::AddSystems(this, pSystemList: (AppSystemInfo_t *)&appSystems[0].m_pInterfaceName);
  HIBYTE(appSystems[0].m_pModuleName) = _Plat_GetOSVersion() >= 6;
  s_nNumThreads = *(unsigned __int8 *)(_GetCPUInformation() + 5) - 1;
  v2 = _CommandLine();
  v3 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 32))(
                       a1: v2,
                       a2: "-threads",
                       a3: 0);
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    s_nNumThreads = v4;
  }
  else
  {
    v4 = s_nNumThreads;
  }
  sparms.fDistribute = v4;
  sparms.nStackSize = 2;
  sparms.iThreadPriority = -1;
  sparms.iAffinityTable[0] = -32768;
  v11 &= 0xFCu;
  _g_pThreadPool->Start_2(this: _g_pThreadPool, a2: (const ThreadPoolStartParams_t *)&sparms.fDistribute);
  v5 = _CommandLine();
  v6 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 32))(
                       a1: v5,
                       a2: "-rendersystemdll",
                       a3: 0);
  if ( v6 == nullptr )
    v6 = "rendersystemdx11.dll";
  if ( HIBYTE(appSystems[0].m_pModuleName) == 0 && _stricmp(dst: v6, src: "rendersystemdx11.dll") == 0 )
    v6 = "rendersystemdx9.dll";
  Module = CAppSystemGroup::LoadModule(this, pDLLName: v6);
  if ( Module == -1 )
  {
    Module = CAppSystemGroup::LoadModule(this, pDLLName: "rendersystemdx9.dll");
    if ( Module == -1 )
    {
      Module = CAppSystemGroup::LoadModule(this, pDLLName: "rendersystemempty.dll");
      if ( Module == -1 )
        return false;
    }
  }
  g_pRenderDeviceMgr = (IRenderDeviceMgr *)CAppSystemGroup::AddSystem(
                                             this,
                                             module: Module,
                                             pInterfaceName: "RenderDeviceMgr001");
  g_pMaterialSystem2 = (IMaterialSystem2 *)CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem2_001");
  return g_pRenderDeviceMgr != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004013A0
// Name: private: bool CMeshUtilsTestApp::SetupSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMeshUtilsTestApp::SetupSearchPaths(CMeshUtilsTestApp *this)
{
  int v2; // eax
  const char *v3; // eax

  v2 = _CommandLine();
  v3 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 32))(a1: v2, a2: "-game", a3: 0);
  if ( v3 != nullptr )
    return CSteamAppSystemGroup::SetupSearchPaths(this, pStartingDir: v3, bOnlyUseStartingDir: true, bIsTool: false);
  _Error(a1: "FileSystem_LoadFileSystemModule: no -game specified.");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004013E0
// Name: public: virtual bool CMeshUtilsTestApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMeshUtilsTestApp::PreInit(CMeshUtilsTestApp *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int m_nWindowHeight; // ecx
  int m_nWindowWidth; // edx
  CMeshUtilsTestApp_vtbl *v9; // edi
  bool v10; // zf
  void *AppInstance; // eax
  void *v12; // eax
  void *m_hWnd; // esi
  int v15; // [esp+0h] [ebp-20h]
  int v16; // [esp+4h] [ebp-1Ch]
  int v17; // [esp+8h] [ebp-18h]
  int v18; // [esp+Ch] [ebp-14h]
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+1Ch] [ebp-4h] BYREF

  pFactoryList = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || g_pRenderDeviceMgr == nullptr )
    return 0;
  if ( !CMeshUtilsTestApp::SetupSearchPaths(this) )
    _Warning(a1: "couldn't set paths - running with no paths.");
  this->m_nWindowWidth = 1280;
  this->m_nWindowHeight = 960;
  v2 = _CommandLine();
  this->m_bFullscreen = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(
                          a1: v2,
                          a2: "-fullscreen",
                          a3: 0) != 0;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, void *(__cdecl **)(const char *, int *)))(*(_DWORD *)v3 + 12))(
         a1: v3,
         a2: "-width",
         a3: &pFactoryList) != 0 )
    this->m_nWindowWidth = atoi(nptr: (const char *)pFactoryList);
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, void *(__cdecl **)(const char *, int *)))(*(_DWORD *)v4 + 12))(
         a1: v4,
         a2: "-height",
         a3: &pFactoryList) != 0 )
    this->m_nWindowHeight = atoi(nptr: (const char *)pFactoryList);
  v5 = _CommandLine();
  v6 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-resizing", a3: 0);
  m_nWindowHeight = this->m_nWindowHeight;
  m_nWindowWidth = this->m_nWindowWidth;
  v9 = this->__vftable;
  LOBYTE(v6) = v6 != 0;
  v10 = !this->m_bFullscreen;
  this->m_bResizing = v6;
  v18 = v6;
  LOBYTE(v6) = v10;
  v17 = m_nWindowHeight;
  v16 = m_nWindowWidth;
  v15 = v6;
  AppInstance = GetAppInstance();
  v12 = v9->CreateAppWindow(this, a2: AppInstance, a3: "Press Space To Continue", a4: v15, a5: v16, a6: v17, a7: v18);
  this->m_hWnd = v12;
  g_hWnd = v12;
  m_hWnd = this->m_hWnd;
  if ( m_hWnd == nullptr )
    return 0;
  g_pInputSystem->AttachToWindow(this: g_pInputSystem, a2: m_hWnd);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401560
// Name: public: virtual void CMeshUtilsTestApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshUtilsTestApp::PostShutdown(CMeshUtilsTestApp *this)
{
  CSteamApplication *v1; // ecx

  g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
  CSteamApplication::PostShutdown(this: v1);
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00401580
// Name: private: bool CMeshUtilsTestApp::SetMode(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMeshUtilsTestApp::SetMode(CMeshUtilsTestApp *this)
{
  int v2; // ebp
  int v3; // eax
  int v4; // eax
  int v5; // edi
  void *(__cdecl *v7)(const char *, int *); // ebp
  IRenderDevice *v8; // eax
  IHardwareConfig *v9; // eax
  ImageFormat m_nWindowHeight; // edx
  bool m_bFullscreen; // al
  int v12; // eax
  int v13; // eax
  IRenderDevice *m_pRenderDevice; // ecx
  int m_nWindowWidth; // eax
  int v16; // ecx
  RenderDeviceInfo_t mode; // [esp+20h] [ebp-2Ch] BYREF
  char v18; // [esp+48h] [ebp-4h]

  v2 = g_pRenderDeviceMgr->GetAdapterCount(this: g_pRenderDeviceMgr);
  v3 = _CommandLine();
  v4 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 28))(a1: v3, a2: "-adapter", a3: 0);
  v5 = v4;
  if ( v4 < v2 )
  {
    v7 = g_pRenderDeviceMgr->CreateDevice(this: g_pRenderDeviceMgr, a2: v4, a3: this->m_bResizing, a4: 0);
    g_pRenderDeviceMgr->GetAdapterInfo(this: g_pRenderDeviceMgr, a2: v5, a3: &g_AdapterInfo);
    if ( v7 != nullptr )
    {
      v8 = (IRenderDevice *)v7(a1: "RenderDevice001", a2: nullptr);
      this->m_pRenderDevice = v8;
      g_pRenderDevice = v8;
      v9 = (IHardwareConfig *)v7(a1: "HardwareConfig001", a2: nullptr);
      this->m_pHardwareConfig = v9;
      if ( v9 != nullptr && this->m_pRenderDevice != nullptr )
      {
        RenderDeviceInfo_t::RenderDeviceInfo_t(this: (RenderDeviceInfo_t *)&mode.m_DisplayMode);
        m_nWindowHeight = this->m_nWindowHeight;
        m_bFullscreen = this->m_bFullscreen;
        mode.m_DisplayMode.m_nHeight = this->m_nWindowWidth;
        mode.m_DisplayMode.m_Format = m_nWindowHeight;
        v18 ^= (v18 ^ m_bFullscreen) & 1;
        mode.m_DisplayMode.m_nRefreshRateNumerator = 0;
        mode.m_DisplayMode.m_nRefreshRateDenominator = 60;
        mode.m_nBackBufferCount = 1;
        mode.m_nMultisampleType = m_bFullscreen + 1;
        v12 = _CommandLine();
        v13 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v12 + 12))(a1: v12, a2: "-vsync", a3: 0);
        m_pRenderDevice = this->m_pRenderDevice;
        v18 ^= (v18 ^ (4 * (v13 != 0))) & 4;
        g_hSwapChain = (SwapChainHandle_t__ *)m_pRenderDevice->CreateSwapChain(
                                                this: m_pRenderDevice,
                                                a2: this->m_hWnd,
                                                a3: (const RenderDeviceInfo_t *)&mode.m_DisplayMode);
        m_nWindowWidth = this->m_nWindowWidth;
        v16 = this->m_nWindowHeight;
        this->m_viewport.m_flMinZ = 0.0;
        this->m_viewport.m_nWidth = m_nWindowWidth;
        this->m_viewport.m_nVersion = 1;
        this->m_viewport.m_nTopLeftX = 0;
        this->m_viewport.m_nTopLeftY = 0;
        this->m_viewport.m_nHeight = v16;
        this->m_viewport.m_flMaxZ = 1.0;
        return 1;
      }
      else
      {
        _Warning(a1: "Unable to get IHardwareConfig or IRenderDevice interface!\n");
        return 0;
      }
    }
    else
    {
      _Warning(a1: "Unable to set mode!\n");
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Specified too high an adapter number on the command-line (%d/%d)!\n", v4, v2);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401770
// Name: public: void CUtlMemory<unsigned char,int>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::Purge(CUtlMemory<unsigned char,int> *this)
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
// Address: 0x004017A0
// Name: public: class CUtlMemory<struct UtlLinkedListElem_t<int,unsigned short>,unsigned short>::Iterator_t CUtlMemory<struct UtlLinkedListElem_t<int,unsigned short>,unsigned short>::Next(class CUtlMemory<struct UtlLinkedListElem_t<int,unsigned short>,unsigned short>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *__thiscall CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>::Next(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *result,
        const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *it)
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
// Address: 0x004017E0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: json
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
// Address: 0x00401840
// Name: public: void CUtlLinkedList<int,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<int,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004018B0
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
// Address: 0x00401970
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
// Address: 0x00401A20
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
    v7 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
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
// Address: 0x00401BD0
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
// Address: 0x00401C30
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
// Address: 0x00401C80
// Name: private: void CMeshUtilsTestApp::RunTests(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMeshUtilsTestApp::RunTests(CMeshUtilsTestApp *this)
{
  _BYTE *v1; // esi
  int i; // edi
  int v3; // eax
  int *v4; // esi
  int v5; // eax
  int m_nVertexStrideFloats; // esi
  int v7; // ecx
  int *v8; // eax
  int v9; // ecx
  CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short> > *v10; // edi
  _DWORD *j; // eax
  int v12; // edx
  int v13; // ebx
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<int,unsigned short> *m_pMemory; // esi
  void (*v16)(const char *, ...); // esi
  UtlLinkedListElem_t<int,unsigned short> *m_pElements; // ebx
  int v18; // eax
  int v19; // ebx
  CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short> > *k; // esi
  int v21; // ebp
  float *p_m_nOffsetFloats; // esi
  int v23; // ebx
  int v24; // edx
  float *v25; // ecx
  void (*v26)(const char *, ...); // esi
  int *v27; // esi
  int v28; // edx
  int v29; // eax
  void (*v30)(const char *, ...); // edi
  CMeshVertexAttribute *m_pAttributes; // esi
  int nFaces[5]; // [esp+4h] [ebp-328h] BYREF
  CMesh cubeMesh; // [esp+18h] [ebp-314h] BYREF
  Vector vLeftMin; // [esp+38h] [ebp-2F4h] BYREF
  Vector vRightMin; // [esp+44h] [ebp-2E8h] BYREF
  Vector vRightMax; // [esp+50h] [ebp-2DCh] BYREF
  Vector vLeftMax; // [esp+5Ch] [ebp-2D0h] BYREF
  CMeshVertexAttribute vertAttributes[3]; // [esp+68h] [ebp-2C4h] BYREF
  Vector vMinBounds; // [esp+80h] [ebp-2ACh] BYREF
  Vector vMaxBounds; // [esp+8Ch] [ebp-2A0h] BYREF
  float pEpsilons[8]; // [esp+98h] [ebp-294h] BYREF
  Vector4D vClipPlane; // [esp+B8h] [ebp-274h] BYREF
  CMesh oneBigTriangleMesh; // [esp+C8h] [ebp-264h] BYREF
  CMesh weldedCube; // [esp+E8h] [ebp-244h] BYREF
  CMesh weldedLeftMesh; // [esp+108h] [ebp-224h] BYREF
  CMesh leftMesh; // [esp+128h] [ebp-204h] BYREF
  CMesh deIndexedCubeMesh; // [esp+148h] [ebp-1E4h] BYREF
  CMesh rightMesh; // [esp+168h] [ebp-1C4h] BYREF
  CMesh tessellatedMesh1; // [esp+188h] [ebp-1A4h] BYREF
  CMesh dupCubeMesh; // [esp+1A8h] [ebp-184h] BYREF
  CMesh tessellatedMesh2; // [esp+1C8h] [ebp-164h] BYREF
  CMesh tessellatedMesh3; // [esp+1E8h] [ebp-144h] BYREF
  _BYTE corners_4[257]; // [esp+20Ch] [ebp-120h] OVERLAPPED BYREF

  vertAttributes[0].m_nType = VERTEX_ELEMENT_POSITION;
  vertAttributes[1].m_nOffsetFloats = 0;
  vertAttributes[1].m_nType = VERTEX_ELEMENT_NORMAL4D;
  vertAttributes[2].m_nOffsetFloats = 2;
  vertAttributes[2].m_nType = VERTEX_ELEMENT_TANGENT_S;
  LODWORD(vMinBounds.x) = 26;
  *(_DWORD *)corners_4 = -1082130432;
  *(_DWORD *)&corners_4[4] = -1082130432;
  *(_DWORD *)&corners_4[8] = -1082130432;
  *(_DWORD *)&corners_4[32] = 1065353216;
  *(_DWORD *)&corners_4[36] = -1082130432;
  *(_DWORD *)&corners_4[40] = -1082130432;
  *(_DWORD *)&corners_4[64] = 1065353216;
  *(_DWORD *)&corners_4[68] = 1065353216;
  *(_DWORD *)&corners_4[72] = -1082130432;
  *(_DWORD *)&corners_4[96] = -1082130432;
  *(_DWORD *)&corners_4[100] = 1065353216;
  *(_DWORD *)&corners_4[104] = -1082130432;
  *(_DWORD *)&corners_4[128] = -1082130432;
  *(_DWORD *)&corners_4[132] = -1082130432;
  *(_DWORD *)&corners_4[136] = 1065353216;
  *(_DWORD *)&corners_4[160] = 1065353216;
  *(_DWORD *)&corners_4[164] = -1082130432;
  *(_DWORD *)&corners_4[168] = 1065353216;
  *(_DWORD *)&corners_4[192] = 1065353216;
  *(_DWORD *)&corners_4[196] = 1065353216;
  *(_DWORD *)&corners_4[200] = 1065353216;
  *(_DWORD *)&corners_4[224] = -1082130432;
  *(_DWORD *)&corners_4[228] = 1065353216;
  *(_DWORD *)&corners_4[232] = 1065353216;
  v1 = &corners_4[20];
  for ( i = 8; i != 0; --i )
  {
    v3 = *((_DWORD *)v1 - 3);
    *(_QWORD *)&nFaces[1] = *(_QWORD *)(v1 - 20);
    nFaces[3] = v3;
    pfVectorNormalize(a1: (Vector *)&nFaces[1]);
    *((_QWORD *)v1 - 1) = *(_QWORD *)&nFaces[1];
    *(_DWORD *)v1 = nFaces[3];
    *((float *)v1 + 1) = *((float *)v1 - 5);
    v1 += 32;
    *((float *)v1 - 6) = *((float *)v1 - 12);
  }
  CMesh::CMesh(this: (CMesh *)&cubeMesh.m_pAttributes);
  CMesh::AllocateMesh(
    this: (CMesh *)&cubeMesh.m_pAttributes,
    nVertexCount: 8,
    nIndexCount: 36,
    nVertexStride: 8,
    pAttributes: (CMeshVertexAttribute *)&vertAttributes[0].m_nType,
    nAtrributeCount: 3);
  memcpy(dst: (unsigned __int8 *)cubeMesh.m_pAttributes, src: corners_4, count: 0x100u);
  memcpy(dst: (unsigned __int8 *)cubeMesh.m_nVertexCount, src: (unsigned __int8 *)g_pBoxIndices, count: 0x90u);
  v4 = (int *)operator new(nSize: 0x90u);
  CMesh::CalculateAdjacency(this: (CMesh *)&cubeMesh.m_pAttributes, pAdjacencyOut: v4, nSizeAdjacencyOut: 36);
  v5 = 0;
  while ( v4[v5] != -1 )
  {
    if ( ++v5 >= 36 )
      goto LABEL_8;
  }
  _Warning(a1: "CalculateAdjacency bug!\n");
LABEL_8:
  free(pMem: v4);
  m_nVertexStrideFloats = cubeMesh.m_nVertexStrideFloats;
  v7 = (28 * (unsigned __int64)(unsigned int)cubeMesh.m_nVertexStrideFloats) >> 32 != 0
     ? -1
     : 28 * cubeMesh.m_nVertexStrideFloats;
  v8 = (int *)operator new(nSize: __CFADD__(v7, 4) ? -1 : v7 + 4);
  if ( v8 != nullptr )
  {
    v9 = m_nVertexStrideFloats - 1;
    v10 = (CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short> > *)(v8 + 1);
    *v8 = m_nVertexStrideFloats;
    for ( j = v8 + 1; v9 >= 0; --v9 )
    {
      *j = 0;
      j[1] = 0;
      j[2] = 0;
      *((_WORD *)j + 11) = -1;
      v12 = *j;
      *((_WORD *)j + 6) = -1;
      *((_WORD *)j + 7) = -1;
      *((_WORD *)j + 8) = -1;
      *((_WORD *)j + 9) = 0;
      *((_WORD *)j + 10) = 0;
      j[6] = v12;
      j += 7;
    }
  }
  else
  {
    v10 = nullptr;
  }
  CMesh::CalculateIndicentFacesForVertices(
    this: (CMesh *)&cubeMesh.m_pAttributes,
    pFacesPerVertex: v10,
    nFacesPerVertexSize: cubeMesh.m_nVertexStrideFloats);
  nFaces[1] = 1;
  nFaces[2] = 6;
  nFaces[3] = 7;
  nFaces[4] = 9;
  cubeMesh.m_pVerts = (float *)8;
  v13 = 0;
  while ( 1 )
  {
    m_Head = v10[3].m_Head;
    if ( m_Head == 0xFFFF )
    {
LABEL_18:
      m_Head = -1;
    }
    else
    {
      m_pMemory = v10[3].m_Memory.m_pMemory;
      while ( m_pMemory[m_Head].m_Element != nFaces[v13 + 1] )
      {
        m_Head = m_pMemory[m_Head].m_Next;
        if ( m_Head == 0xFFFF )
          goto LABEL_18;
      }
    }
    if ( m_Head == -1 )
      break;
    if ( ++v13 >= 5 )
    {
      v16 = (void (*)(const char *, ...))_Warning;
      goto LABEL_24;
    }
  }
  v16 = (void (*)(const char *, ...))_Warning;
  _Warning(a1: "CalculateIndicentFacesForVertices bug!\n");
LABEL_24:
  if ( v10 != nullptr )
  {
    m_pElements = v10[-1].m_pElements;
    v18 = (int)m_pElements;
    v19 = (int)&m_pElements[-1].m_Next + 1;
    for ( k = &v10[v18]; v19 >= 0; --v19 )
    {
      CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::RemoveAll(this: --k);
      if ( k->m_Memory.m_nGrowSize >= 0 )
      {
        if ( k->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: k->m_Memory.m_pMemory);
          k->m_Memory.m_pMemory = nullptr;
        }
        k->m_Memory.m_nAllocationCount = 0;
      }
    }
    free(pMem: &v10[-1].m_pElements);
    v16 = (void (*)(const char *, ...))_Warning;
  }
  CMesh::CMesh(this: (CMesh *)&dupCubeMesh.m_pAttributes);
  DuplicateMesh(pMeshOut: (CMesh *)&dupCubeMesh.m_pAttributes, inputMesh: (const CMesh *)&cubeMesh.m_pAttributes);
  CMesh::CalculateBounds(
    this: (CMesh *)&dupCubeMesh.m_pAttributes,
    pMinOut: (Vector *)&vMinBounds.y,
    pMaxOut: (Vector *)&vMaxBounds.y);
  if ( vMinBounds.y != -1.0
    || vMinBounds.z != -1.0
    || vMaxBounds.x != -1.0
    || vMaxBounds.y != 1.0
    || vMaxBounds.z != 1.0
    || pEpsilons[0] != 1.0 )
  {
    v16(a1: "CalculateBounds bug!\n");
  }
  CMesh::CMesh(this: (CMesh *)&deIndexedCubeMesh.m_pAttributes);
  DeIndexMesh(pMeshOut: (CMesh *)&deIndexedCubeMesh.m_pAttributes, inputMesh: (const CMesh *)&cubeMesh.m_pAttributes);
  if ( *(_DWORD *)&deIndexedCubeMesh.m_bAllocatedMeshData != deIndexedCubeMesh.m_nVertexStrideFloats )
    v16(a1: "DeIndexMesh bug!\n");
  CMesh::CMesh(this: (CMesh *)&weldedCube.m_pAttributes);
  pEpsilons[1] = 0.0099999998;
  pEpsilons[2] = 0.0099999998;
  pEpsilons[3] = 0.0099999998;
  pEpsilons[4] = 0.000099999997;
  pEpsilons[5] = 0.000099999997;
  pEpsilons[6] = 0.000099999997;
  pEpsilons[7] = 0.001;
  vClipPlane.x = 0.001;
  WeldVertices(
    pMeshOut: (CMesh *)&weldedCube.m_pAttributes,
    inputMesh: (const CMesh *)&deIndexedCubeMesh.m_pAttributes,
    pEpsilons: &pEpsilons[1],
    nEpsilons: 8);
  v21 = cubeMesh.m_nVertexStrideFloats;
  if ( weldedCube.m_nVertexStrideFloats != cubeMesh.m_nVertexStrideFloats )
  {
    v16(a1: "WeldVertices bug!\n");
    v21 = cubeMesh.m_nVertexStrideFloats;
  }
  nFaces[0] = 0;
  if ( weldedCube.m_nVertexStrideFloats > 0 )
  {
    p_m_nOffsetFloats = (float *)&weldedCube.m_pAttributes->m_nOffsetFloats;
    v23 = 0;
    while ( 1 )
    {
      v24 = 0;
      if ( v21 <= 0 )
        break;
      v25 = (float *)&cubeMesh.m_pAttributes[1].m_nOffsetFloats;
      while ( *p_m_nOffsetFloats != *(v25 - 2)
           || p_m_nOffsetFloats[1] != *(v25 - 1)
           || *((float *)&weldedCube.m_pAttributes[1].m_nOffsetFloats + v23) != *v25 )
      {
        ++v24;
        v25 += cubeMesh.m_nAttributeCount;
        if ( v24 >= v21 )
          goto LABEL_51;
      }
      v23 += weldedCube.m_nAttributeCount;
      p_m_nOffsetFloats += weldedCube.m_nAttributeCount;
      if ( ++nFaces[0] >= weldedCube.m_nVertexStrideFloats )
        goto LABEL_52;
    }
LABEL_51:
    _Warning(a1: "WeldVertices bug!\n");
  }
LABEL_52:
  CMesh::CMesh(this: (CMesh *)&corners_4[256]);
  RationalizeUVs(pRationalMeshOut: (CMesh *)&corners_4[256], inputMesh: (const CMesh *)&cubeMesh.m_pAttributes);
  CMesh::CMesh(this: (CMesh *)&leftMesh.m_pAttributes);
  CMesh::CMesh(this: (CMesh *)&rightMesh.m_pAttributes);
  vClipPlane.y = 1.0;
  vClipPlane.z = 0.0;
  vClipPlane.w = 0.0;
  oneBigTriangleMesh.m_pVerts = (float *)1056964608;
  ClipMeshToHalfSpace(
    pMeshBack: (CMesh *)&leftMesh.m_pAttributes,
    pMeshFront: (CMesh *)&rightMesh.m_pAttributes,
    inputMesh: (const CMesh *)&cubeMesh.m_pAttributes,
    vClipPlane: (Vector4D *)&vClipPlane.y);
  if ( *(_DWORD *)&leftMesh.m_bAllocatedMeshData == 42 && *(_DWORD *)&rightMesh.m_bAllocatedMeshData == 42 )
  {
    v26 = (void (*)(const char *, ...))_Warning;
  }
  else
  {
    v26 = (void (*)(const char *, ...))_Warning;
    _Warning(a1: "ClipMeshToHalfSpace bug!\n");
  }
  CMesh::CalculateBounds(
    this: (CMesh *)&leftMesh.m_pAttributes,
    pMinOut: (Vector *)&vLeftMin.y,
    pMaxOut: (Vector *)&vLeftMax.y);
  CMesh::CalculateBounds(
    this: (CMesh *)&rightMesh.m_pAttributes,
    pMinOut: (Vector *)&vRightMin.y,
    pMaxOut: (Vector *)&vRightMax.y);
  if ( vLeftMin.y != -1.0
    || vLeftMin.z != -1.0
    || vRightMin.x != -1.0
    || vLeftMax.y != 0.5
    || vLeftMax.z != 1.0
    || *(float *)&vertAttributes[0].m_nOffsetFloats != 1.0 )
  {
    v26(a1: "ClipMeshToHalfSpace bug!\n");
  }
  if ( vRightMin.y != 0.5
    || vRightMin.z != -1.0
    || vRightMax.x != -1.0
    || vRightMax.y != 1.0
    || vRightMax.z != 1.0
    || vLeftMax.x != 1.0 )
  {
    v26(a1: "ClipMeshToHalfSpace bug!\n");
  }
  CMesh::CMesh(this: (CMesh *)&weldedLeftMesh.m_pAttributes);
  WeldVertices(
    pMeshOut: (CMesh *)&weldedLeftMesh.m_pAttributes,
    inputMesh: (const CMesh *)&leftMesh.m_pAttributes,
    pEpsilons: &pEpsilons[1],
    nEpsilons: 8);
  v27 = (int *)operator new(nSize: 4 * *(_DWORD *)&weldedLeftMesh.m_bAllocatedMeshData);
  CMesh::CalculateAdjacency(
    this: (CMesh *)&weldedLeftMesh.m_pAttributes,
    pAdjacencyOut: v27,
    nSizeAdjacencyOut: *(int *)&weldedLeftMesh.m_bAllocatedMeshData);
  v28 = 0;
  v29 = 0;
  if ( *(int *)&weldedLeftMesh.m_bAllocatedMeshData <= 0 )
    goto LABEL_77;
  do
  {
    if ( v27[v29] == -1 )
      ++v28;
    ++v29;
  }
  while ( v29 < *(int *)&weldedLeftMesh.m_bAllocatedMeshData );
  if ( v28 == 8 )
  {
    v30 = (void (*)(const char *, ...))_Warning;
  }
  else
  {
LABEL_77:
    v30 = (void (*)(const char *, ...))_Warning;
    _Warning(a1: "CalculateAdjacency bug!\n");
  }
  free(pMem: v27);
  CMesh::CMesh(this: (CMesh *)&oneBigTriangleMesh.m_pAttributes);
  CMesh::AllocateMesh(
    this: (CMesh *)&oneBigTriangleMesh.m_pAttributes,
    nVertexCount: 3,
    nIndexCount: 3,
    nVertexStride: 8,
    pAttributes: (CMeshVertexAttribute *)&vertAttributes[0].m_nType,
    nAtrributeCount: 3);
  *(_DWORD *)oneBigTriangleMesh.m_nVertexCount = 0;
  *(_DWORD *)(oneBigTriangleMesh.m_nVertexCount + 4) = 1;
  *(_DWORD *)(oneBigTriangleMesh.m_nVertexCount + 8) = 2;
  m_pAttributes = oneBigTriangleMesh.m_pAttributes;
  oneBigTriangleMesh.m_pAttributes->m_nOffsetFloats = -1082130432;
  m_pAttributes->m_nType = VERTEX_ELEMENT_POSITION;
  m_pAttributes[1].m_nOffsetFloats = 1065353216;
  m_pAttributes[1].m_nType = VERTEX_ELEMENT_POSITION;
  m_pAttributes[2].m_nOffsetFloats = 1065353216;
  m_pAttributes[2].m_nType = VERTEX_ELEMENT_POSITION;
  m_pAttributes[3].m_nOffsetFloats = 0;
  m_pAttributes[3].m_nType = 1065353216;
  m_pAttributes[4].m_nOffsetFloats = -1082130432;
  m_pAttributes[4].m_nType = VERTEX_ELEMENT_POSITION;
  m_pAttributes[5].m_nOffsetFloats = -1082130432;
  m_pAttributes[5].m_nType = VERTEX_ELEMENT_POSITION;
  m_pAttributes[6].m_nOffsetFloats = 1065353216;
  m_pAttributes[6].m_nType = VERTEX_ELEMENT_POSITION;
  m_pAttributes[7].m_nOffsetFloats = 0;
  m_pAttributes[7].m_nType = VERTEX_ELEMENT_POSITION;
  m_pAttributes[8].m_nOffsetFloats = 1065353216;
  m_pAttributes[8].m_nType = VERTEX_ELEMENT_POSITION;
  m_pAttributes[9].m_nOffsetFloats = 0;
  m_pAttributes[9].m_nType = VERTEX_ELEMENT_POSITION;
  m_pAttributes[10].m_nOffsetFloats = 1065353216;
  m_pAttributes[10].m_nType = VERTEX_ELEMENT_POSITION;
  m_pAttributes[11].m_nOffsetFloats = 1065353216;
  m_pAttributes[11].m_nType = VERTEX_ELEMENT_POSITION;
  CMesh::CMesh(this: (CMesh *)&tessellatedMesh1.m_pAttributes);
  TessellateOnWrappedUV(
    pMeshOut: (CMesh *)&tessellatedMesh1.m_pAttributes,
    inputMesh: (const CMesh *)&oneBigTriangleMesh.m_pAttributes);
  if ( *(_DWORD *)&tessellatedMesh1.m_bAllocatedMeshData != 3 )
    v30(a1: "TessellateOnWrappedUV bug!\n");
  m_pAttributes[11].m_nOffsetFloats = 0x40000000;
  m_pAttributes[11].m_nType = VERTEX_ELEMENT_POSITION;
  CMesh::CMesh(this: (CMesh *)&tessellatedMesh2.m_pAttributes);
  TessellateOnWrappedUV(
    pMeshOut: (CMesh *)&tessellatedMesh2.m_pAttributes,
    inputMesh: (const CMesh *)&oneBigTriangleMesh.m_pAttributes);
  if ( *(_DWORD *)&tessellatedMesh2.m_bAllocatedMeshData != 9 )
    v30(a1: "TessellateOnWrappedUV bug!\n");
  m_pAttributes[11].m_nOffsetFloats = 1081711002;
  m_pAttributes[11].m_nType = VERTEX_ELEMENT_POSITION;
  CMesh::CMesh(this: (CMesh *)&tessellatedMesh3.m_pAttributes);
  TessellateOnWrappedUV(
    pMeshOut: (CMesh *)&tessellatedMesh3.m_pAttributes,
    inputMesh: (const CMesh *)&oneBigTriangleMesh.m_pAttributes);
  if ( *(_DWORD *)&tessellatedMesh3.m_bAllocatedMeshData != 27 )
    v30(a1: "TessellateOnWrappedUV bug!\n");
  _Msg(a1: "Done\n");
  CMesh::~CMesh(this: (CMesh *)&tessellatedMesh3.m_pAttributes);
  CMesh::~CMesh(this: (CMesh *)&tessellatedMesh2.m_pAttributes);
  CMesh::~CMesh(this: (CMesh *)&tessellatedMesh1.m_pAttributes);
  CMesh::~CMesh(this: (CMesh *)&oneBigTriangleMesh.m_pAttributes);
  CMesh::~CMesh(this: (CMesh *)&weldedLeftMesh.m_pAttributes);
  CMesh::~CMesh(this: (CMesh *)&rightMesh.m_pAttributes);
  CMesh::~CMesh(this: (CMesh *)&leftMesh.m_pAttributes);
  CMesh::~CMesh(this: (CMesh *)&corners_4[256]);
  CMesh::~CMesh(this: (CMesh *)&weldedCube.m_pAttributes);
  CMesh::~CMesh(this: (CMesh *)&deIndexedCubeMesh.m_pAttributes);
  CMesh::~CMesh(this: (CMesh *)&dupCubeMesh.m_pAttributes);
  CMesh::~CMesh(this: (CMesh *)&cubeMesh.m_pAttributes);
}

//------------------------------------------------------------------------------
// Address: 0x00402720
// Name: public: virtual int CMeshUtilsTestApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMeshUtilsTestApp::Main(CMeshUtilsTestApp *this)
{
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  if ( CMeshUtilsTestApp::SetMode(this) == 0 )
    return 0;
  this->m_pRenderDevice->EnableRenderContexts(this: this->m_pRenderDevice, a2: true);
  CMeshUtilsTestApp::RunTests(this);
  this->m_pRenderDevice->EnableRenderContexts(this: this->m_pRenderDevice, a2: false);
  if ( g_hSwapChain != nullptr )
  {
    this->m_pRenderDevice->DestroySwapChain(this: this->m_pRenderDevice, a2: g_hSwapChain);
    g_hSwapChain = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004027B0
// Name: public: virtual char const __near * CMeshUtilsTestApp::GetAppName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMeshUtilsTestApp::GetAppName(CMeshUtilsTestApp *this)
{
  return "RenderSystemTest";
}

//------------------------------------------------------------------------------
// Address: 0x00402B10
// Name: public: void CUtlMemory<class KeyValues __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<KeyValues *,int>::Grow(CUtlMemory<KeyValues *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  KeyValues **m_pMemory; // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402BA0
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
// Address: 0x00402C40
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
// Address: 0x00402D50
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
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v8; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v11; // edx
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t v12; // [esp+6h] [ebp-2h] BYREF

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
        v8 = CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>::Next(
               this: &this->m_Elements,
               result: &v12,
               it: &this->m_LastAlloc);
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
// Address: 0x00402E60
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v5; // eax

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
// Address: 0x00402F50
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v5; // eax

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
// Address: 0x004030B0
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::InsertBefore(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CAppSystemGroup::Module_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 12 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00403110
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
// Address: 0x00403210
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
// Address: 0x004037F0
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
// Address: 0x00403C60
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *insert)
{
  const CUtlMap<char const *,int,unsigned short>::Node_t *v2; // ebx
  unsigned __int16 v4; // di
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // ecx
  unsigned __int16 v8[2]; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    parent: v8,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent: v8[0],
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  v6 = v4;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)-8 )
  {
    m_pMemory[v6].m_Data.key = v2->key;
    m_pMemory[v6].m_Data.elem = v2->elem;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004050D0
// Name: public: CUtlVector<char,class CUtlMemory<char,int>>::~CUtlVector<char,class CUtlMemory<char,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(
        CUtlVector<char,CUtlMemory<char,int> > *this)
{
  bool v2; // sf
  char *m_pMemory; // eax

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
// Address: 0x004055B0
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::SetSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::SetSize(CUtlVector<char,CUtlMemory<char,int> > *this, int size)
{
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  signed int v5; // eax
  bool v6; // zf

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = (unsigned __int8 *)this->m_Memory.m_pMemory;
    v5 = this->m_Size - size;
    v6 = this->m_Size == size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 >= 0 && !v6 && size > 0 )
      memmove(dst: &m_pMemory[size], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407CC0
// Name: public: void CUtlMemory<class CUtlVector<float __near *,class CUtlMemory<float __near *,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int>>,int>::Grow(
        CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int> >,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<float *,CUtlMemory<float *,int> > *m_pMemory; // edx
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
      this->m_pMemory = (CUtlVector<float *,CUtlMemory<float *,int> > *)_g_pMemAlloc->Realloc_2(
                                                                          this: _g_pMemAlloc,
                                                                          a2: m_pMemory,
                                                                          a3: v7);
    else
      this->m_pMemory = (CUtlVector<float *,CUtlMemory<float *,int> > *)_g_pMemAlloc->Alloc_2(
                                                                          this: _g_pMemAlloc,
                                                                          a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407FA0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<int,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<int,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<int,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<int,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004082C0
// Name: protected: unsigned short CUtlLinkedList<int,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebx
  int m_nAllocationCount; // ecx
  unsigned __int16 result; // ax
  int v7; // edi
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v8; // eax
  UtlLinkedListElem_t<int,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t v11; // [esp+Eh] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_21:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result;
    if ( multilist )
    {
      m_pMemory[v10].m_Next = -1;
      this->m_Memory.m_pMemory[v10].m_Previous = -1;
    }
    else
    {
      m_pMemory[v10].m_Next = result;
      this->m_Memory.m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  p_m_LastAlloc = &this->m_LastAlloc;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
  {
    result = -1;
  }
  else
  {
    result = p_m_LastAlloc->index + 1;
  }
  v11.index = result;
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( p_m_LastAlloc->index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      v11.index = (v7 > 0) - 1;
      v8 = &v11;
    }
    else
    {
      v8 = CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>::Next(
             (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
             result: &v11,
             it: (const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *)&this->m_LastAlloc);
    }
    result = v8->index;
    if ( result >= v7 )
    {
      if ( _executeCount_0 < 10 )
      {
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
        ++_executeCount_0;
      }
      return -1;
    }
  }
  if ( result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    p_m_LastAlloc->index = result;
    goto LABEL_21;
  }
  if ( _executeCount < 10 )
  {
    _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
    ++_executeCount;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004084A0
// Name: public: int CUtlVector<float __near *,class CUtlMemory<float __near *,int>>::InsertBefore(int,float __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float *,CUtlMemory<float *,int>>::InsertBefore(
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *this,
        int elem,
        KeyValues **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  KeyValues **m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  KeyValues **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<KeyValues *,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00408670
// Name: public: void CUtlLinkedList<int,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<int,unsigned short> *m_pMemory; // eax
  unsigned __int16 m_Next; // cx
  unsigned __int16 *p_m_Previous; // ebp
  unsigned __int16 v6; // di

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      m_Next = m_pMemory[elem].m_Next;
      p_m_Previous = &m_pMemory[elem].m_Previous;
      v6 = *p_m_Previous;
      if ( *p_m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        m_pMemory[v6].m_Next = m_Next;
      if ( m_Next == 0xFFFF )
      {
        --this->m_ElementCount;
        this->m_Tail = v6;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v6;
        --this->m_ElementCount;
      }
      *p_m_Previous = elem;
      m_pMemory[elem].m_Next = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408780
// Name: public: void CUtlVector<class CUtlVector<float __near *,class CUtlMemory<float __near *,int>>,class CUtlMemory<class CUtlVector<float __near *,class CUtlMemory<float __near *,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<float *,CUtlMemory<float *,int>>,CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<float *,CUtlMemory<float *,int> >,CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // ebp
  CUtlVector<float *,CUtlMemory<float *,int> > *v3; // esi
  bool v4; // sf
  float **m_pMemory; // eax
  CUtlVector<CUtlVector<float *,CUtlMemory<float *,int> >,CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int> >,int> > *v6; // [esp+8h] [ebp-4h]

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
      v3 = &this->m_Memory.m_pMemory[v2];
      v4 = v3->m_Memory.m_nGrowSize < 0;
      v3->m_Size = 0;
      if ( !v4 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v6;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Memory.m_pMemory;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          this = v6;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408810
// Name: public: int CUtlVector<class CUtlVector<float __near *,class CUtlMemory<float __near *,int>>,class CUtlMemory<class CUtlVector<float __near *,class CUtlMemory<float __near *,int>>,int>>::InsertMultipleBefore(int,int,class CUtlVector<float __near *,class CUtlMemory<float __near *,int>> const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<float *,CUtlMemory<float *,int>>,CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<float *,CUtlMemory<float *,int> >,CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int> >,int> > *this,
        int elem,
        int num,
        const CUtlVector<float *,CUtlMemory<float *,int> > *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<float *,CUtlMemory<float *,int> > *m_pMemory; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // ecx
  int i; // edx
  CUtlVector<float *,CUtlMemory<float *,int> > *v14; // eax
  int v15; // edi
  const CUtlVector<float *,CUtlMemory<float *,int> > *v16; // ebx
  CUtlMemory<KeyValues *,int> *v17; // esi
  int v18; // edi
  int v19; // eax
  unsigned __int8 *v20; // ecx
  int v21; // eax
  bool v22; // zf
  int j; // eax
  int numa; // [esp+14h] [ebp+8h]
  const CUtlVector<float *,CUtlMemory<float *,int> > *pToInserta; // [esp+18h] [ebp+Ch]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int>>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 20 * v11);
LABEL_8:
    if ( num > 0 )
    {
      v12 = elem;
      for ( i = num; i != 0; --i )
      {
        v14 = &this->m_Memory.m_pMemory[v12];
        if ( v14 != nullptr )
        {
          v14->m_Memory.m_pMemory = nullptr;
          v14->m_Memory.m_nAllocationCount = 0;
          v14->m_Memory.m_nGrowSize = 0;
          v14->m_Size = 0;
          v14->m_pElements = nullptr;
        }
        ++v12;
      }
    }
  }
  if ( pToInsert != nullptr && num > 0 )
  {
    v15 = 20 * elem;
    numa = 20 * elem;
    v16 = pToInsert;
    pToInserta = (const CUtlVector<float *,CUtlMemory<float *,int> > *)num;
    do
    {
      v17 = (CUtlMemory<KeyValues *,int> *)((char *)this->m_Memory.m_pMemory + v15);
      v18 = v16->m_Size;
      v17[1].m_pMemory = nullptr;
      if ( v18 != 0 )
      {
        v19 = v17->m_nAllocationCount;
        if ( v18 > v19 )
          CUtlMemory<KeyValues *,int>::Grow(this: v17, num: v18 - v19);
        v17[1].m_pMemory = (KeyValues **)((char *)v17[1].m_pMemory + v18);
        v20 = (unsigned __int8 *)v17->m_pMemory;
        v21 = (int)v17[1].m_pMemory - v18;
        v22 = v17[1].m_pMemory == (KeyValues **)v18;
        v17[1].m_nAllocationCount = (int)v17->m_pMemory;
        if ( v21 >= 0 && !v22 && v18 > 0 )
          memmove(dst: &v20[4 * v18], src: v20, count: 4 * v21);
      }
      for ( j = 0; j < v18; ++j )
        v17->m_pMemory[j] = (KeyValues *)v16->m_Memory.m_pMemory[j];
      v15 = numa + 20;
      ++v16;
      v22 = pToInserta == (const CUtlVector<float *,CUtlMemory<float *,int> > *)1;
      pToInserta = (const CUtlVector<float *,CUtlMemory<float *,int> > *)((char *)pToInserta - 1);
      numa += 20;
    }
    while ( !v22 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00408960
// Name: public: unsigned short CUtlLinkedList<int,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::AddToTail(int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short> > *this,
        int *src)
{
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // di
  int v6; // ecx
  UtlLinkedListElem_t<int,unsigned short> *v7; // eax
  unsigned __int16 m_Tail; // bx
  UtlLinkedListElem_t<int,unsigned short> *v9; // esi

  v3 = CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::AllocInternal(
         this,
         multilist: false);
  v4 = v3;
  if ( v3 == 0xFFFF )
    return 0xFFFF;
  CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::Unlink(
    this,
    elem: v3);
  v6 = v4;
  v7 = &this->m_Memory.m_pMemory[v6];
  v7->m_Next = -1;
  m_Tail = this->m_Tail;
  v7->m_Previous = m_Tail;
  this->m_Tail = v4;
  if ( m_Tail == 0xFFFF )
    this->m_Head = v4;
  else
    this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
  ++this->m_ElementCount;
  v9 = &this->m_Memory.m_pMemory[v6];
  if ( v9 != nullptr )
    v9->m_Element = *src;
  return v4;
}
