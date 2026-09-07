// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: unittests/worldrenderertest/worldrenderertest.cpp
// Functions: 612
// ============================================================

#include "unittests\worldrenderertest\worldrenderertest.h"

//------------------------------------------------------------------------------
// Address: 0x00401180
// Name: public: Vector2D::Vector2D(float,float)
// Source: json
//------------------------------------------------------------------------------
Vector2D *__thiscall Vector2D::Vector2D(Vector2D *this, float X, float Y)
{
  this->x = X;
  this->y = Y;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004011A0
// Name: public: matrix3x4_t::matrix3x4_t(void)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__thiscall matrix3x4_t::matrix3x4_t(matrix3x4_t *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004011B0
// Name: public: Vector4D::Vector4D(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall Vector4D::Vector4D(Vector4D *this, float X, float Y, float Z, float W)
{
  this->x = X;
  this->y = Y;
  this->z = Z;
  this->w = W;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004011E0
// Name: enum SpewRetval_t SpewFunc(enum SpewType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
SpewRetval_t __cdecl SpewFunc(SpewType_t type, const char *pMsg)
{
  SpewRetval_t result; // eax

  result = SPEW_CONTINUE;
  if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
  {
    OutputDebugStringA(lpOutputString: pMsg);
    if ( type == SPEW_ASSERT )
      return SPEW_DEBUGGER;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401210
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  return AppMain(a1: hInstance, a2: hPrevInstance, a3: lpCmdLine, a4: nCmdShow, a5: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x00401240
// Name: public: virtual bool CRenderSystemTestApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRenderSystemTestApp::Create(CRenderSystemTestApp *this)
{
  bool v2; // bl
  int v3; // eax
  const char *v4; // ebp
  int Module; // edi
  int v7; // ebx
  IWorldRendererMgr *v8; // eax
  AppSystemInfo_t appSystems[2]; // [esp+Ch] [ebp-A8h] BYREF
  _OSVERSIONINFOA info; // [esp+1Ch] [ebp-98h] BYREF

  this->m_bExit = false;
  _SpewOutputFunc(a1: SpewFunc);
  appSystems[1].m_pInterfaceName = defaultValue;
  info.dwOSVersionInfoSize = (unsigned int)defaultValue;
  appSystems[0].m_pInterfaceName = "inputsystem.dll";
  appSystems[1].m_pModuleName = "InputSystemVersion001";
  CAppSystemGroup::AddSystems(this, a2: (struct AppSystemInfo_t *)&appSystems[0].m_pInterfaceName);
  v2 = false;
  info.dwMajorVersion = 148;
  if ( GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&info.dwMajorVersion) )
    v2 = info.dwMinorVersion >= 6;
  v3 = _CommandLine();
  v4 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 32))(
                       a1: v3,
                       a2: "-rendersystemdll",
                       a3: 0);
  if ( v4 == nullptr )
    v4 = "rendersystemdx11.dll";
  if ( !v2 && _stricmp(dst: v4, src: "rendersystemdx11.dll") == 0 )
    v4 = "rendersystemdx9.dll";
  Module = CAppSystemGroup::LoadModule(this, a2: v4);
  if ( Module == -1 )
  {
    v4 = "rendersystemdx9.dll";
    Module = CAppSystemGroup::LoadModule(this, a2: "rendersystemdx9.dll");
    if ( Module == -1 )
    {
      v4 = "rendersystemempty.dll";
      Module = CAppSystemGroup::LoadModule(this, a2: "rendersystemempty.dll");
      if ( Module == -1 )
        return false;
    }
  }
  this->m_bUseGL = V_stristr(pStr: v4, pSearch: "rendersystemgl") != nullptr;
  v7 = CAppSystemGroup::LoadModule(this, a2: "worldrenderer.dll");
  g_pRenderDeviceMgr = (IRenderDeviceMgr *)CAppSystemGroup::AddSystem(this, i: Module, a3: "RenderDeviceMgr001");
  v8 = (IWorldRendererMgr *)CAppSystemGroup::AddSystem(this, i: v7, a3: "WorldRendererMgr001");
  g_pWorldRendererMgr = v8;
  return g_pRenderDeviceMgr != nullptr && v8 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004013A0
// Name: public: virtual void CRenderSystemTestApp::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderSystemTestApp::Destroy(CRenderSystemTestApp *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004013B0
// Name: private: bool CRenderSystemTestApp::SetupSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRenderSystemTestApp::SetupSearchPaths(CRenderSystemTestApp *this)
{
  bool result; // al

  result = CSteamAppSystemGroup::SetupSearchPaths(this, a2: nullptr, a3: false, a4: false);
  if ( result )
  {
    g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "LOCAL", a4: PATH_ADD_TO_HEAD);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004013E0
// Name: public: virtual bool CRenderSystemTestApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRenderSystemTestApp::PreInit(CRenderSystemTestApp *this, char *nptr, bool a3)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  CRenderSystemTestApp_vtbl *v7; // edi
  void *AppInstance; // eax
  void *v9; // eax
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+1Ch] [ebp-4h] BYREF

  pFactoryList = (void *(__cdecl *)(const char *, int *))CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(a1: &pFactoryList, a2: 1);
  if ( g_pFullFileSystem == nullptr || g_pRenderDeviceMgr == nullptr || g_pWorldRendererMgr == nullptr )
    return 0;
  if ( !CRenderSystemTestApp::SetupSearchPaths(this) )
    _Warning(a1: "couldn't set paths - running with no paths.");
  v4 = _CommandLine();
  a3 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-fullscreen", a3: 0) == 0;
  v5 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, char **))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-width", a3: &nptr) != 0 )
    atoi(nptr);
  v6 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, char **))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-height", a3: &nptr) != 0 )
    atoi(nptr);
  v7 = this->__vftable;
  AppInstance = GetAppInstance();
  v9 = (void *)((int (__thiscall *)(CRenderSystemTestApp *, void *, const char *))v7->CreateAppWindow)(
                 a1: this,
                 a2: AppInstance,
                 a3: "Press a Key To Continue");
  this->m_hWnd = v9;
  if ( v9 == nullptr )
    return 0;
  g_pInputSystem->AttachToWindow(this: g_pInputSystem, a2: v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401520
// Name: public: virtual void CRenderSystemTestApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderSystemTestApp::PostShutdown(CRenderSystemTestApp *this)
{
  g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00401540
// Name: private: bool CRenderSystemTestApp::SetMode(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CRenderSystemTestApp::SetMode(CRenderSystemTestApp *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // edi
  void *m_hWnd; // eax
  void *(__cdecl *v8)(const char *, int *); // eax
  void *(__cdecl *v9)(const char *, int *); // edi
  IRenderDevice *v10; // eax
  IHardwareConfig *v11; // eax
  RenderDeviceInfo_t mode_4; // [esp+Ch] [ebp-38h] OVERLAPPED BYREF

  v2 = g_pRenderDeviceMgr->GetAdapterCount(this: g_pRenderDeviceMgr);
  v3 = _CommandLine();
  v4 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 28))(a1: v3, a2: "-adapter", a3: 0);
  v5 = v4;
  if ( v4 < v2 )
  {
    memset(dst: (unsigned __int8 *)&mode_4, value: 0, count: sizeof(mode_4));
    *((_BYTE *)&mode_4 + 52) |= 1u;
    m_hWnd = this->m_hWnd;
    mode_4.m_nVersion = 1;
    mode_4.m_DisplayMode.m_nVersion = 1;
    mode_4.m_DisplayMode.m_nWidth = 1024;
    mode_4.m_DisplayMode.m_nHeight = 768;
    mode_4.m_DisplayMode.m_Format = IMAGE_FORMAT_BGRA8888;
    mode_4.m_DisplayMode.m_nRefreshRateNumerator = 60;
    mode_4.m_DisplayMode.m_nRefreshRateDenominator = 1;
    mode_4.m_nBackBufferCount = 1;
    v8 = g_pRenderDeviceMgr->SetMode(this: g_pRenderDeviceMgr, a2: m_hWnd, a3: v5, a4: &mode_4);
    v9 = v8;
    if ( v8 != nullptr )
    {
      v10 = (IRenderDevice *)v8(a1: "RenderDevice001", a2: nullptr);
      this->m_pRenderDevice = v10;
      g_pRenderDevice = v10;
      v11 = (IHardwareConfig *)v9(a1: "HardwareConfig001", a2: nullptr);
      this->m_pHardwareConfig = v11;
      if ( v11 != nullptr && this->m_pRenderDevice != nullptr )
      {
        if ( this->m_bUseGL || v11->GetDXSupportLevel(this: v11) < 100 )
        {
          this->m_bUseDX11 = false;
          return 1;
        }
        else
        {
          this->m_bUseDX11 = true;
          return 1;
        }
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
// Address: 0x00401690
// Name: private: bool CRenderSystemTestApp::ProcessUserInput(float,struct usercmd_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRenderSystemTestApp::ProcessUserInput(CRenderSystemTestApp *this, float frametime, usercmd_t *cmd)
{
  char v5; // bl
  int v6; // esi
  const InputEvent_t *v7; // eax
  const InputEvent_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  unsigned int m_nKeys; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4

  if ( this->m_bExit )
    return 1;
  v5 = 0;
  g_pInputSystem->PollInputState(this: g_pInputSystem);
  v6 = g_pInputSystem->GetEventCount(this: g_pInputSystem);
  v7 = g_pInputSystem->GetEventData(this: g_pInputSystem);
  if ( v6 > 0 )
  {
    v8 = v7;
    while ( 1 )
    {
      if ( v8->m_nType == 103 || v8->m_nType == 100 )
      {
        this->m_bExit = true;
        v5 = 1;
      }
      v9 = v8->m_nType == 0;
      if ( v8->m_nType == 0 )
        goto LABEL_11;
      if ( v8->m_nType == 1 )
        break;
LABEL_24:
      ++v8;
      if ( --v6 == 0 )
        goto LABEL_25;
    }
    v9 = false;
LABEL_11:
    switch ( v8->m_nData )
    {
      case 0xB:
        v10 = 4;
        goto LABEL_13;
      case 0xE:
        v10 = 8;
        goto LABEL_13;
      case 0x1D:
        v10 = 2;
        goto LABEL_13;
      case 0x21:
        v10 = 1;
        goto LABEL_13;
      case 0x46:
        v5 = 1;
        goto LABEL_24;
      case 0x58:
        v10 = 64;
        goto LABEL_13;
      case 0x59:
        v10 = 16;
        goto LABEL_13;
      case 0x5A:
        v10 = 128;
        goto LABEL_13;
      case 0x5B:
        v10 = 32;
LABEL_13:
        if ( v9 )
          cmd->m_nKeys |= v10;
        else
          cmd->m_nKeys &= ~v10;
        break;
      default:
        goto LABEL_24;
    }
    goto LABEL_24;
  }
LABEL_25:
  m_nKeys = cmd->m_nKeys;
  v12 = 800.0;
  if ( (m_nKeys & 3) != 0 )
  {
    if ( (m_nKeys & 1) != 0 )
      v13 = 800.0;
    else
      v13 = -800.0;
  }
  else
  {
    v13 = 0.0;
  }
  cmd->m_flForwardMove = v13;
  if ( (m_nKeys & 0xC) != 0 )
  {
    if ( (m_nKeys & 8) == 0 )
      v12 = -800.0;
  }
  else
  {
    v12 = 0.0;
  }
  cmd->m_flRightMove = v12;
  if ( (m_nKeys & 0x30) != 0 )
  {
    if ( (m_nKeys & 0x10) != 0 )
      v14 = 120.0;
    else
      v14 = -120.0;
  }
  else
  {
    v14 = 0.0;
  }
  cmd->m_flYawMove = v14;
  if ( (m_nKeys & 0xC0) != 0 )
  {
    if ( (m_nKeys & 0x80u) == 0 )
      cmd->m_flPitchMove = -60.0;
    else
      cmd->m_flPitchMove = 60.0;
    return v5;
  }
  else
  {
    cmd->m_flPitchMove = 0.0;
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004018A0
// Name: public: unsigned short CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::GetIndex(class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::GetIndex(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *it)
{
  return it->index;
}

//------------------------------------------------------------------------------
// Address: 0x004018B0
// Name: public: bool CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t::operator==(class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t::operator==(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t it)
{
  return this->index == it.index;
}

//------------------------------------------------------------------------------
// Address: 0x004018C0
// Name: public: bool CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsIdxValid(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsIdxValid(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        unsigned __int16 i)
{
  return i < this->m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x004018E0
// Name: public: bool CUtlMemory<class IAppSystem __near *,int>::IsExternallyAllocated(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUtlMemory<IAppSystem *,int>::IsExternallyAllocated(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this)
{
  return this->m_nGrowSize < 0;
}

//------------------------------------------------------------------------------
// Address: 0x004018F0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> __near & CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x00401900
// Name: public: struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short> const __near & CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::operator[](unsigned short)const
// Source: json
//------------------------------------------------------------------------------
const UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *__thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::operator[](
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        unsigned __int16 i)
{
  return &this->m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x00401910
// Name: public: void CFrustum::UpdateFrustumFromCamera(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrustum::UpdateFrustumFromCamera(CFrustum *this)
{
  matrix3x4_t *p_m_cameraToWorld; // ebx
  matrix3x4_t *p_m_worldToView; // edi
  VMatrix *v4; // eax
  const VMatrix *v5; // eax
  VMatrix vm; // [esp+24h] [ebp-C0h] BYREF
  VMatrix v7; // [esp+64h] [ebp-80h] BYREF
  VMatrix result; // [esp+A4h] [ebp-40h] BYREF

  p_m_cameraToWorld = &this->m_cameraToWorld;
  p_m_worldToView = &this->m_worldToView;
  ComputeViewMatrix(a1: &this->m_worldToView, matrix: &this->m_cameraToWorld, position: &this->m_camera.m_origin);
  ComputeProjectionMatrix(
    dst: &this->m_projection,
    a2: this->m_camera.m_flZNear,
    a3: this->m_camera.m_flZFar,
    a4: this->m_camera.m_flFOVX,
    a5: this->m_flAspect);
  *(matrix3x4_t *)&vm.m[0][0] = *p_m_worldToView;
  *(_QWORD *)&vm.m[3][0] = 0;
  *(_QWORD *)&vm.m[3][2] = 0x3F80000000000000LL;
  v4 = VMatrix::operator*(this: &this->m_projection, &result, &vm);
  v5 = VMatrix::Transpose(this: v4, result: &v7);
  VMatrix::operator=(this: &this->m_viewProj, mOther: v5);
  MatrixGetColumn(in: p_m_cameraToWorld, column: 0, out: &this->m_forward);
  MatrixGetColumn(in: p_m_cameraToWorld, column: 1, out: &this->m_left);
  MatrixGetColumn(in: p_m_cameraToWorld, column: 2, out: &this->m_up);
  GeneratePerspectiveFrustum(
    origin: &vec3_origin,
    angles: &this->m_camera.m_angles,
    flZNear: this->m_camera.m_flZNear,
    flZFar: this->m_camera.m_flZFar,
    flFovX: this->m_camera.m_flFOVX,
    flAspectRatio: this->m_flAspect,
    frustum: &this->m_frustum);
}

//------------------------------------------------------------------------------
// Address: 0x00401A80
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
// Address: 0x00401AB0
// Name: public: class IAppSystem __near * __near * CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>::Base(void)
// Source: json
//------------------------------------------------------------------------------
IAppSystem **__thiscall CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Base(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this)
{
  return this->m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x00401AC0
// Name: public: static unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex()
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00401AD0
// Name: public: class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::InvalidIterator(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *__thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::InvalidIterator(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *result)
{
  result->index = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401AE0
// Name: public: struct CAppSystemGroup::Module_t __near & CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::Element(int)
// Source: json
//------------------------------------------------------------------------------
CAppSystemGroup::Module_t *__thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Element(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this,
        int i)
{
  return &this->m_Memory.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x00401AF0
// Name: public: class IAppSystem __near * __near & CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>::Element(int)
// Source: json
//------------------------------------------------------------------------------
IAppSystem **__thiscall CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Element(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this,
        int i)
{
  return &this->m_Memory.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x00401B00
// Name: public: class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::First(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *__thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::First(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *result)
{
  result->index = (this->m_nAllocationCount > 0) - 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401B20
// Name: public: class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Next(class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *__thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Next(
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
// Address: 0x00401B60
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetLeftChild(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetLeftChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 child)
{
  this->m_Elements.m_pMemory[i].m_Left = child;
}

//------------------------------------------------------------------------------
// Address: 0x00401B80
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetRightChild(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetRightChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 child)
{
  this->m_Elements.m_pMemory[i].m_Right = child;
}

//------------------------------------------------------------------------------
// Address: 0x00401BA0
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
// Address: 0x00401C00
// Name: protected: void CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::ResetDbgInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::ResetDbgInfo(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this)
{
  this->m_pElements = this->m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x00401C10
// Name: public: void CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::RemoveAll(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this)
{
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401C20
// Name: public: char const __near * __near & CUtlMap<char const __near *,int,unsigned short>::Key(unsigned short)
// Source: json
//------------------------------------------------------------------------------
CUtlMap<char const *,int,unsigned short>::Node_t *__thiscall CUtlMap<char const *,int,unsigned short>::Key(
        CUtlMap<char const *,int,unsigned short> *this,
        unsigned __int16 i)
{
  return &this->m_Tree.m_Elements.m_pMemory[i].m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x00401C40
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i)->m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00401C60
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i)->m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00401C70
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i)->m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00401C90
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v3; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i);
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v3->m_Parent)->m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00401CC0
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
// Address: 0x00401D80
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
// Address: 0x00401E30
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
// Address: 0x00401FE0
// Name: private: void CRenderSystemTestApp::DisplayAdapterInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderSystemTestApp::DisplayAdapterInfo(CRenderSystemTestApp *this)
{
  int v1; // edi
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  int v4; // ebp
  int i; // ebx
  int v6; // [esp+14h] [ebp-288h]
  const char *v7; // [esp+18h] [ebp-284h]
  int v8; // [esp+1Ch] [ebp-280h]
  int nAdapterCount; // [esp+28h] [ebp-274h]
  RenderDisplayMode_t mode; // [esp+2Ch] [ebp-270h] BYREF
  CUtlBuffer buf; // [esp+44h] [ebp-258h] BYREF
  RenderAdapterInfo_t info; // [esp+74h] [ebp-228h] BYREF

  v1 = 0;
  nAdapterCount = g_pRenderDeviceMgr->GetAdapterCount(this: g_pRenderDeviceMgr);
  if ( nAdapterCount > 0 )
  {
    do
    {
      g_pRenderDeviceMgr->GetAdapterInfo(this: g_pRenderDeviceMgr, a2: v1, a3: &info);
      _Msg(a1: "Adapter %d\n", v1);
      _Msg(
        a1: "\tName: %s\n"
        "\tVendor: 0x%X\n"
        "\tDevice: 0x%X\n"
        "\tSubSystem: 0x%X\n"
        "\tRevision: 0x%X\n"
        "\tRecommended DX Level: %d\n"
        "\tMax DX Level: %d\n",
        info.m_pDriverName,
        info.m_VendorID,
        info.m_DeviceID,
        info.m_SubSysID,
        info.m_Revision,
        info.m_nDXSupportLevel,
        info.m_nMaxDXSupportLevel);
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x20u, nBlockUse: v6, pFileName: v7, nLine: v8);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(this: v2, setName: "Config");
      else
        v3 = nullptr;
      g_pRenderDeviceMgr->GetRecommendedConfigurationInfo(
        this: g_pRenderDeviceMgr,
        a2: v1,
        a3: info.m_nDXSupportLevel,
        a4: v3);
      KeyValues::RecursiveSaveToFile(this: v3, &buf, indentLevel: 1);
      _Msg(a1: "\tConfiguration:\n%s", (const char *)buf.m_Memory.m_pMemory);
      _Msg(a1: "\n");
      v4 = g_pRenderDeviceMgr->GetModeCount(this: g_pRenderDeviceMgr, a2: v1);
      _Msg(a1: "\tMode Count : %d\n", v4);
      for ( i = 0; i < v4; ++i )
      {
        memset(&mode.m_nWidth, 0, 20);
        mode.m_nVersion = 1;
        g_pRenderDeviceMgr->GetModeInfo(this: g_pRenderDeviceMgr, a2: &mode, a3: v1, a4: i);
        _Msg(
          a1: "\t\tH: %5d W: %5d Format: %3d Refresh %3d/%3d\n",
          mode.m_nWidth,
          mode.m_nHeight,
          mode.m_Format,
          mode.m_nRefreshRateNumerator,
          mode.m_nRefreshRateDenominator);
      }
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      ++v1;
    }
    while ( v1 < nAdapterCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402190
// Name: public: virtual int CRenderSystemTestApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRenderSystemTestApp::Main(CRenderSystemTestApp *this)
{
  IRenderDevice *m_pRenderDevice; // ecx
  IRenderDevice *v4; // esi
  IRenderContext *(__thiscall *GetRenderContext)(IRenderDevice *); // edx
  unsigned int v6; // eax
  IRenderDevice *v7; // ecx
  double v8; // st7
  ConstantBufferHandle_t__ *v9; // ebx
  IWorldRenderer *(__thiscall *CreateWorldRenderer)(IWorldRendererMgr *); // eax
  IWorldRenderer *v11; // eax
  IWorldRenderer_vtbl *v12; // edx
  IRenderContext *v13; // edi
  IRenderContext *v14; // esi
  const VMatrix *v15; // eax
  int v16; // ebx
  float v17; // xmm2_4
  float v18; // xmm1_4
  IBVHNode **v19; // eax
  IRenderContext *v20; // esi
  float v21; // [esp+4C88h] [ebp-560h]
  float v22; // [esp+4C8Ch] [ebp-55Ch]
  IRenderDevice *v23; // [esp+4C8Ch] [ebp-55Ch]
  float v24; // [esp+4C90h] [ebp-558h]
  unsigned int v25; // [esp+4C90h] [ebp-558h]
  IBVHNode **v26; // [esp+4C94h] [ebp-554h] BYREF
  int v27; // [esp+4C98h] [ebp-550h]
  int v28; // [esp+4C9Ch] [ebp-54Ch]
  IRenderDevice *v29; // [esp+4CA0h] [ebp-548h]
  IBVHNode **v30; // [esp+4CA4h] [ebp-544h]
  IRenderDevice *i; // [esp+4CA8h] [ebp-540h]
  int v32; // [esp+4CACh] [ebp-53Ch]
  double v33; // [esp+4CB0h] [ebp-538h]
  ConstantBufferHandle_t__ *v34; // [esp+4CBCh] [ebp-52Ch] BYREF
  int v35; // [esp+4CC0h] [ebp-528h] BYREF
  usercmd_t v36; // [esp+4CC8h] [ebp-520h] BYREF
  IRenderContext *v37; // [esp+4CDCh] [ebp-50Ch]
  __int64 v38; // [esp+4CE4h] [ebp-504h] BYREF
  float v39; // [esp+4CECh] [ebp-4FCh]
  int v40; // [esp+4CF0h] [ebp-4F8h]
  _DWORD v41[7]; // [esp+4CF4h] [ebp-4F4h] BYREF
  double v42; // [esp+4D10h] [ebp-4D8h]
  CFrustum v43; // [esp+4D18h] [ebp-4D0h] BYREF
  VMatrix mOther; // [esp+4FD0h] [ebp-218h] BYREF
  _DWORD v45[4]; // [esp+5010h] [ebp-1D8h] BYREF
  char v46; // [esp+5120h] [ebp-C8h]
  VMatrix v47; // [esp+5128h] [ebp-C0h] BYREF
  VMatrix v48; // [esp+5168h] [ebp-80h] BYREF
  VMatrix v49; // [esp+51A8h] [ebp-40h] BYREF

  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  v45[0] = 4;
  v45[1] = 2;
  v45[2] = -1;
  v45[3] = -32768;
  v46 &= 0xFCu;
  _g_pThreadPool->Start_2(this: _g_pThreadPool, a2: (const ThreadPoolStartParams_t *)v45);
  CRenderSystemTestApp::DisplayAdapterInfo(this);
  if ( CRenderSystemTestApp::SetMode(this) == 0 )
    return 0;
  Frustum_t::Frustum_t(this: &v43.m_frustum);
  v43.m_camera.m_flFOVX = CalcFovX(flFovY: 90.0, flAspect: 1.3333);
  m_pRenderDevice = this->m_pRenderDevice;
  v43.m_camera.m_origin.x = 768.0;
  v43.m_camera.m_origin.y = 0.0;
  v43.m_camera.m_angles.x = 0.0;
  v43.m_camera.m_angles.z = 0.0;
  v43.m_camera.m_flZNear = 10.0;
  v43.m_camera.m_origin.z = 41.0;
  v43.m_camera.m_flZFar = 18000.0;
  v43.m_camera.m_angles.y = 180.0;
  v43.m_flAspect = 1.3333;
  m_pRenderDevice->EnableRenderContexts(this: m_pRenderDevice, a2: true);
  v4 = this->m_pRenderDevice;
  GetRenderContext = v4->GetRenderContext;
  i = v4;
  v6 = (int)GetRenderContext(this: v4);
  v7 = this->m_pRenderDevice;
  v36.m_nKeys = v6;
  v7->GetWindowSize(this: v7, a2: (int *)&v34, a3: &v35);
  v41[4] = 0;
  v40 = 1;
  v41[0] = 0;
  v41[1] = 0;
  v41[2] = v34;
  v41[3] = v35;
  v41[5] = 1065353216;
  v24 = _RandomFloat(a1: 0.0, a2: 0.5);
  v22 = _RandomFloat(a1: 0.0, a2: 0.5);
  v8 = _RandomFloat(a1: 0.5, a2: 1.0);
  *((float *)&v38 + 1) = v24;
  v39 = v22;
  *(float *)&v40 = v8;
  v41[0] = 1065353216;
  MatrixSetIdentity(dst: (VMatrix *)&mOther.m[0][1]);
  CFrustum::UpdateFrustumFromCamera(this: (CFrustum *)&v43.m_frustum.planes[0].nX.m128_i16[2]);
  v9 = this->m_pRenderDevice->CreateConstantBuffer(this: this->m_pRenderDevice, a2: 128);
  CreateWorldRenderer = g_pWorldRendererMgr->CreateWorldRenderer;
  v34 = v9;
  v11 = CreateWorldRenderer(this: g_pWorldRendererMgr);
  v12 = v11->__vftable;
  g_pWorldRenderer = v11;
  if ( v12->Unserialize(this: v11, a2: "maps\\testscene.bvh") )
  {
    ((void (__thiscall *)(IWorldRenderer *, IRenderDevice *, int, _DWORD, int, _DWORD))g_pWorldRenderer->Initialize)(
      a1: g_pWorldRenderer,
      a2: this->m_pRenderDevice,
      a3: 0x20000000,
      a4: 0,
      a5: 0x20000000,
      a6: 0);
    v26 = nullptr;
    v27 = 0;
    v28 = 0;
    v29 = nullptr;
    v30 = nullptr;
    v25 = 0;
    v33 = _Plat_FloatTime();
    memset(&v36, 0, sizeof(v36));
    while ( 1 )
    {
      v42 = v33;
      v33 = _Plat_FloatTime();
      v21 = v33 - v42;
      v23 = this->m_pRenderDevice;
      v14 = (IRenderContext *)((int (*)(void))v23->GetRenderContext)();
      v14->SetViewports(this: v14, a2: 1, a3: (const RenderViewport_t *)v41);
      v14->Clear(this: v14, a2: (const Vector4D *)&v38, a3: 1);
      v14->SetCullMode(this: v14, a2: RENDER_CULLMODE_CULL_BACKFACING);
      CFrustum::UpdateFrustumFromCamera(this: &v43);
      v15 = VMatrix::operator*(this: &mOther, result: &v49, vm: &v43.m_viewProj);
      VMatrix::operator=(this: &v47, mOther: v15);
      VMatrix::operator=(this: &v48, &mOther);
      v14->SetConstantBufferData(this: v14, a2: v9, a3: &v47, a4: 128);
      v14->VertexShaderBindConstantBuffer(this: v14, a2: v9, a3: 0, a4: 0);
      ((void (__thiscall *)(IWorldRenderer *, IBVHNode ***, _DWORD, int, CFrustum *, _DWORD, _DWORD, _DWORD))g_pWorldRenderer->BuildRenderList)(
        a1: g_pWorldRenderer,
        a2: &v26,
        a3: 0,
        a4: -1,
        a5: &v43,
        a6: 1.0,
        a7: 1.0,
        a8: 0.0);
      g_pWorldRenderer->CreateAndDispatchLoadRequests(this: g_pWorldRenderer, a2: this->m_pRenderDevice);
      v16 = 0;
      for ( i = v29; v16 < (int)i; ++v16 )
        g_pWorldRenderer->RenderNode(this: g_pWorldRenderer, a2: v26[v16], a3: v14, a4: v25, a5: VARIATION_DEFAULT);
      v29 = nullptr;
      v14->Submit(this: v14, a2: false);
      this->m_pRenderDevice->Present(this: this->m_pRenderDevice);
      g_pWorldRenderer->UpdateResources(this: g_pWorldRenderer, a2: this->m_pRenderDevice, a3: v14, a4: 10);
      if ( CRenderSystemTestApp::ProcessUserInput(this, frametime: v21, cmd: &v36) != 0 )
        break;
      v43.m_camera.m_origin.y = v43.m_camera.m_origin.y
                              + (float)((float)((float)(v43.m_forward.y * v36.m_flForwardMove)
                                              - (float)(v43.m_left.y * v36.m_flRightMove))
                                      * v21);
      v17 = 89.0;
      v43.m_camera.m_origin.z = v43.m_camera.m_origin.z
                              + (float)((float)((float)(v43.m_forward.z * v36.m_flForwardMove)
                                              - (float)(v43.m_left.z * v36.m_flRightMove))
                                      * v21);
      v18 = (float)(v36.m_flYawMove * v21) + v43.m_camera.m_angles.y;
      v43.m_camera.m_origin.x = v43.m_camera.m_origin.x
                              + (float)((float)((float)(v43.m_forward.x * v36.m_flForwardMove)
                                              - (float)(v43.m_left.x * v36.m_flRightMove))
                                      * v21);
      v43.m_camera.m_angles.y = v18;
      v43.m_camera.m_angles.x = (float)(v36.m_flPitchMove * v21) + v43.m_camera.m_angles.x;
      if ( v43.m_camera.m_angles.x > 89.0 || (v17 = -89.0, v43.m_camera.m_angles.x < -89.0) )
        v43.m_camera.m_angles.x = v17;
      if ( v18 > 180.0 )
      {
        v18 = v18 - 360.0;
        v43.m_camera.m_angles.y = v18;
      }
      if ( v18 < -180.0 )
        v43.m_camera.m_angles.y = v18 + 360.0;
      ++v25;
      v14->Submit(this: v14, a2: false);
      v23->ReleaseRenderContext(this: v23, a2: v14);
      v9 = v34;
    }
    if ( v14 != nullptr )
    {
      v14->Submit(this: v14, a2: false);
      v23->ReleaseRenderContext(this: v23, a2: v14);
    }
    this->m_pRenderDevice->EnableRenderContexts(this: this->m_pRenderDevice, a2: false);
    if ( s_hLayout.m_Handle != -1 )
    {
      ((void (__thiscall *)(IRenderDevice *, unsigned int))this->m_pRenderDevice->DestroyInputLayout)(
        a1: this->m_pRenderDevice,
        a2: s_hLayout.m_Handle);
      s_hLayout.m_Handle = -1;
    }
    v19 = v26;
    v29 = nullptr;
    if ( v28 >= 0 )
    {
      if ( v26 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
        v19 = nullptr;
        v26 = nullptr;
      }
      v27 = 0;
    }
    v30 = v19;
    if ( v28 >= 0 )
    {
      if ( v19 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
        v26 = nullptr;
      }
      v27 = 0;
    }
    v20 = v37;
    if ( v37 != nullptr )
    {
      v37->Submit(this: v37, a2: false);
      (*(void (__thiscall **)(int, IRenderContext *))(*(_DWORD *)v32 + 136))(a1: v32, a2: v20);
    }
  }
  else
  {
    v13 = v37;
    if ( v37 != nullptr )
    {
      v37->Submit(this: v37, a2: false);
      v4->ReleaseRenderContext(this: v4, a2: v13);
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402900
// Name: public: CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>::~CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::~CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this)
{
  bool v2; // sf
  IAppSystem **m_pMemory; // eax

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
// Address: 0x00402970
// Name: public: unsigned short CUtlMap<char const __near *,int,unsigned short>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CUtlMap<char const *,int,unsigned short>::FirstInorder(CUtlMap<char const *,int,unsigned short> *this)
{
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00402980
// Name: public: unsigned short CUtlMap<char const __near *,int,unsigned short>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CUtlMap<char const *,int,unsigned short>::NextInorder(
        CUtlMap<char const *,int,unsigned short> *this,
        unsigned __int16 i)
{
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
           this: &this->m_Tree,
           i);
}

//------------------------------------------------------------------------------
// Address: 0x00402990
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
// Address: 0x004029F0
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
// Address: 0x00402A40
// Name: public: virtual char const __near * CRenderSystemTestApp::GetAppName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRenderSystemTestApp::GetAppName(CRenderSystemTestApp *this)
{
  return "WorldRendererTest";
}

//------------------------------------------------------------------------------
// Address: 0x00403F80
// Name: protected: bool CSteamAppSystemGroup::SetupSearchPaths(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamAppSystemGroup::SetupSearchPaths(CSteamAppSystemGroup *this, const char *a2, bool a3, bool a4)
{
  _DWORD v5[133]; // [esp+D0h] [ebp-444h] BYREF
  bool v6[4]; // [esp+2E4h] [ebp-230h] BYREF
  char *v7; // [esp+2E8h] [ebp-22Ch]
  struct IFileSystem *m_pFileSystem; // [esp+2ECh] [ebp-228h]
  const char *v9; // [esp+2F8h] [ebp-21Ch] BYREF
  bool v10; // [esp+2FCh] [ebp-218h]
  bool v11; // [esp+2FDh] [ebp-217h]
  char v12; // [esp+2FEh] [ebp-216h]
  bool v13; // [esp+2FFh] [ebp-215h]
  char pSrc[523]; // [esp+301h] [ebp-213h] BYREF
  CSteamAppSystemGroup *v15; // [esp+50Ch] [ebp-8h]

  v15 = this;
  CFSSteamSetupInfo::CFSSteamSetupInfo(this: (CFSSteamSetupInfo *)&v9);
  v9 = a2;
  v10 = a3;
  v11 = a4;
  v12 = 1;
  v13 = v15->m_pFileSystem->IsSteam(this: v15->m_pFileSystem);
  if ( FileSystem_SetupSteamEnvironment(a1: (int)&v9) != 0 )
    return 0;
  CFSMountContentInfo::CFSMountContentInfo(this: (CFSMountContentInfo *)v6);
  m_pFileSystem = v15->m_pFileSystem;
  v6[0] = a4;
  v7 = pSrc;
  if ( FileSystem_MountContent(a1: (int)v6) != 0 )
    return 0;
  CFSSearchPathsInit::CFSSearchPathsInit(this: (CFSSearchPathsInit *)v5);
  v5[0] = pSrc;
  v5[2] = m_pFileSystem;
  if ( FileSystem_LoadSearchPaths(a1: v5) != 0 )
    return 0;
  FileSystem_AddSearchPath_Platform(a1: m_pFileSystem, pSrc);
  V_strncpy(pDest: v15->m_pGameInfoPath, pSrc, maxLen: 260);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404140
// Name: public: CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *__thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this,
        int a2,
        int a3)
{
  CUtlMemory<CAppSystemGroup::Module_t,int>::CUtlMemory<CAppSystemGroup::Module_t,int>(a1: a2, a2: a3);
  this->m_Size = 0;
  CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::ResetDbgInfo(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004041A0
// Name: public: struct CAppSystemGroup::Module_t __near & CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
CAppSystemGroup::Module_t *__thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this,
        int i)
{
  return CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Element(this, i);
}

//------------------------------------------------------------------------------
// Address: 0x004041F0
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(int *this)
{
  return CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::InsertBefore(i: *(this + 3));
}

//------------------------------------------------------------------------------
// Address: 0x00404240
// Name: public: CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>::CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *__thiscall CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this,
        int a2,
        int a3)
{
  CUtlMemory<IAppSystem *,int>::CUtlMemory<IAppSystem *,int>(a1: a2, a2: a3);
  this->m_Size = 0;
  CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::ResetDbgInfo(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004042A0
// Name: public: class IAppSystem __near * __near & CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
IAppSystem **__thiscall CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::operator[](
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this,
        int i)
{
  return CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Element(this, i);
}

//------------------------------------------------------------------------------
// Address: 0x004042F0
// Name: public: int CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>::AddToTail(class IAppSystem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::AddToTail(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this,
        unsigned int a2)
{
  IAppSystem **v2; // esi

  if ( CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Base(this) != nullptr
    && a2 >= (unsigned int)CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Base(this) )
  {
    v2 = CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Base(this);
    if ( a2 < (unsigned int)&v2[CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(a1: this)] )
    {
      __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlvector.h", a3: 800);
      if ( __SpewMessage(
             a1: "%s",
             "Assertion Failed: (Base() == NULL) || (&src < Base()) || (&src >= (Base() + Count()) )") == 0
        && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
         || (unsigned __int8)_DoNewAssertDialog(
                               a1: "u:\\main\\src\\public\\tier1\\utlvector.h",
                               a2: 800,
                               a3: "Assertion Failed: (Base() == NULL) || (&src < Base()) || (&src >= (Base() + Count()) )") != 0) )
      {
        __debugbreak();
      }
    }
  }
  return CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::InsertBefore(i: this->m_Size, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00404430
// Name: public: CUtlDict<int,unsigned short>::CUtlDict<int,unsigned short>(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CUtlDict<int,unsigned short>::CUtlDict<int,unsigned short>(void *this, int a2, int a3, int a4)
{
  CUtlMap<char const *,int,unsigned short>::CUtlMap<char const *,int,unsigned short>(a1: a3, a2: a4, a3: 0);
  if ( a2 == 2 )
  {
    CUtlMap<char const *,int,unsigned short>::SetLessFunc(a1: CaselessStringLessThanIgnoreSlashes);
  }
  else if ( a2 == 1 )
  {
    CUtlMap<char const *,int,unsigned short>::SetLessFunc(a1: CaselessStringLessThan);
  }
  else
  {
    CUtlMap<char const *,int,unsigned short>::SetLessFunc(a1: StringLessThan);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404690
// Name: public: int __near & CUtlDict<int,unsigned short>::operator[](unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CUtlDict<int,unsigned short>::operator[](unsigned __int16 i)
{
  return CUtlDict<int,unsigned short>::Element(i);
}

//------------------------------------------------------------------------------
// Address: 0x004046E0
// Name: public: char __near * CUtlDict<int,unsigned short>::GetElementName(unsigned short)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUtlDict<int,unsigned short>::GetElementName(
        CUtlMap<char const *,int,unsigned short> *this,
        unsigned __int16 i)
{
  return CUtlMap<char const *,int,unsigned short>::Key(this, i)->key;
}

//------------------------------------------------------------------------------
// Address: 0x00404730
// Name: public: static unsigned short CUtlDict<int,unsigned short>::InvalidIndex(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 CUtlDict<int,unsigned short>::InvalidIndex()
{
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex();
}

//------------------------------------------------------------------------------
// Address: 0x00404770
// Name: public: unsigned short CUtlDict<int,unsigned short>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CUtlDict<int,unsigned short>::Insert(void *this, char *buf, int a3)
{
  const char *v3; // eax
  __int16 v5; // [esp+12h] [ebp-EAh]
  char *v6; // [esp+1Ch] [ebp-E0h] BYREF
  CMemAllocAttributeAlloction v7; // [esp+EBh] [ebp-11h] BYREF
  void *v8; // [esp+F4h] [ebp-8h]

  v8 = this;
  v3 = type_info::name(
         this: &CUtlDict<int,unsigned short> `RTTI Type Descriptor',
         __ptype_info_node: &__type_info_root_node);
  CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v7, a2: v3, a3: 277);
  v6 = MemAlloc_StrDup(buf, a2: "u:\\main\\src\\public\\tier1\\utldict.h", a3: 0x116u);
  v5 = CUtlMap<char const *,int,unsigned short>::Insert(a1: &v6, a2: a3);
  CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v7);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004048F0
// Name: public: unsigned short CUtlDict<int,unsigned short>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<int,unsigned short>::Find(void *this, int a2)
{
  const char *v2; // eax
  __int16 v4; // [esp+12h] [ebp-EAh]
  unsigned __int16 v5; // [esp+1Eh] [ebp-DEh]
  CMemAllocAttributeAlloction v6; // [esp+EBh] [ebp-11h] BYREF
  void *v7; // [esp+F4h] [ebp-8h]

  v7 = this;
  v2 = type_info::name(
         this: &CUtlDict<int,unsigned short> `RTTI Type Descriptor',
         __ptype_info_node: &__type_info_root_node);
  CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v2, a3: 295);
  if ( a2 != 0 )
  {
    v4 = CUtlMap<char const *,int,unsigned short>::Find(a1: &a2);
    CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
    return v4;
  }
  else
  {
    v5 = CUtlDict<int,unsigned short>::InvalidIndex();
    CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004049E0
// Name: public: unsigned short CUtlDict<int,unsigned short>::First(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,unsigned short>::First(CUtlMap<char const *,int,unsigned short> *this)
{
  return CUtlMap<char const *,int,unsigned short>::FirstInorder(this);
}

//------------------------------------------------------------------------------
// Address: 0x00404A20
// Name: public: unsigned short CUtlDict<int,unsigned short>::Next(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,unsigned short>::Next(CUtlMap<char const *,int,unsigned short> *this, unsigned __int16 i)
{
  return CUtlMap<char const *,int,unsigned short>::NextInorder(this, i);
}

//------------------------------------------------------------------------------
// Address: 0x00404A70
// Name: public: CUtlMap<char const __near *,int,unsigned short>::CUtlMap<char const __near *,int,unsigned short>(int,int,bool (*)(char const __near * const __near &,char const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CUtlMap<char const *,int,unsigned short>::CUtlMap<char const *,int,unsigned short>(
        void *this,
        int a2,
        int a3,
        int a4)
{
  int v4; // eax

  v4 = CUtlMap<char const *,int,unsigned short>::CKeyLess::CKeyLess(a1: a4);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(
    a1: a2,
    a2: a3,
    a3: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404AD0
// Name: public: void CUtlMap<char const __near *,int,unsigned short>::SetLessFunc(bool (*)(char const __near * const __near &,char const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
int __stdcall CUtlMap<char const *,int,unsigned short>::SetLessFunc(int a1)
{
  int v1; // eax

  v1 = CUtlMap<char const *,int,unsigned short>::CKeyLess::CKeyLess(a1);
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetLessFunc(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00404B30
// Name: public: unsigned short CUtlMap<char const __near *,int,unsigned short>::Insert(char const __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,int,unsigned short>::Insert(void *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD v4[6]; // [esp+D0h] [ebp-18h] BYREF

  v4[4] = this;
  CUtlMap<char const *,int,unsigned short>::Node_t::Node_t(a1: v4);
  v4[0] = *a2;
  v4[1] = *a3;
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00404BC0
// Name: public: unsigned short CUtlMap<char const __near *,int,unsigned short>::Find(char const __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,int,unsigned short>::Find(void *this, _DWORD *a2)
{
  _DWORD v3[6]; // [esp+D0h] [ebp-18h] BYREF

  v3[4] = this;
  CUtlMap<char const *,int,unsigned short>::Node_t::Node_t(a1: v3);
  v3[0] = *a2;
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00404C50
// Name: public: CUtlMap<char const __near *,int,unsigned short>::Node_t::Node_t(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CUtlMap<char const *,int,unsigned short>::Node_t::Node_t(void *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404C80
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::InsertBefore(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this,
        int i)
{
  CAppSystemGroup::Module_t *v2; // eax

  if ( i != CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(a1: this)
    && (unsigned __int8)CUtlVector<char,CUtlMemory<char,int>>::IsValidIndex(a1: i) == 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlvector.h", a3: 776);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: (elem == Count()) || IsValidIndex(elem)") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlvector.h",
                             a2: 776,
                             a3: "Assertion Failed: (elem == Count()) || IsValidIndex(elem)") != 0) )
    {
      __debugbreak();
    }
  }
  CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::GrowVector(a1: 1);
  CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::ShiftElementsRight(i, a2: 1);
  v2 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Element(this, i);
  Construct<CAppSystemGroup::Module_t>(a1: v2);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x00404DC0
// Name: public: CUtlMemory<struct CAppSystemGroup::Module_t,int>::CUtlMemory<struct CAppSystemGroup::Module_t,int>(int,int)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CUtlMemory<CAppSystemGroup::Module_t,int>::CUtlMemory<CAppSystemGroup::Module_t,int>(
        CSteamApplication *this,
        int a2,
        CAppSystemGroup::Module_t *a3)
{
  const char *v3; // eax
  CSteamApplication_vtbl *v4; // eax
  CMemAllocAttributeAlloction v6; // [esp+D3h] [ebp-1Dh] BYREF
  int v7; // [esp+DCh] [ebp-14h]
  CSteamApplication *v8; // [esp+E8h] [ebp-8h]

  v8 = this;
  this->__vftable = nullptr;
  v8->m_Modules.m_Memory.m_pMemory = a3;
  v8->m_Modules.m_Memory.m_nAllocationCount = a2;
  CSteamApplication::PostShutdown(this: v8);
  if ( a2 < 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 409);
    v7 = __SpewMessage(a1: "%s", "Assertion Failed: nGrowSize >= 0");
    if ( v7 == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 409,
                             a3: "Assertion Failed: nGrowSize >= 0") != 0) )
    {
      __debugbreak();
    }
  }
  if ( v8->m_Modules.m_Memory.m_pMemory != nullptr )
  {
    v3 = type_info::name(
           this: &CUtlMemory<CAppSystemGroup::Module_t,int> `RTTI Type Descriptor',
           __ptype_info_node: &__type_info_root_node);
    CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v3, a3: 413);
    v4 = (CSteamApplication_vtbl *)_g_pMemAlloc->Alloc(
                                     this: _g_pMemAlloc,
                                     a2: 12 * (int)v8->m_Modules.m_Memory.m_pMemory,
                                     a3: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                     a4: 414);
    v8->__vftable = v4;
    CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00404F80
// Name: public: int CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>::InsertBefore(int,class IAppSystem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::InsertBefore(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this,
        int i,
        unsigned int a3)
{
  IAppSystem **v3; // esi
  IAppSystem **v4; // eax

  if ( CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Base(this) != nullptr
    && a3 >= (unsigned int)CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Base(this) )
  {
    v3 = CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Base(this);
    if ( a3 < (unsigned int)&v3[CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(a1: this)] )
    {
      __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlvector.h", a3: 816);
      if ( __SpewMessage(
             a1: "%s",
             "Assertion Failed: (Base() == NULL) || (&src < Base()) || (&src >= (Base() + Count()) )") == 0
        && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
         || (unsigned __int8)_DoNewAssertDialog(
                               a1: "u:\\main\\src\\public\\tier1\\utlvector.h",
                               a2: 816,
                               a3: "Assertion Failed: (Base() == NULL) || (&src < Base()) || (&src >= (Base() + Count()) )") != 0) )
      {
        __debugbreak();
      }
    }
  }
  if ( i != CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(a1: this)
    && (unsigned __int8)CUtlVector<char,CUtlMemory<char,int>>::IsValidIndex(a1: i) == 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlvector.h", a3: 819);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: (elem == Count()) || IsValidIndex(elem)") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlvector.h",
                             a2: 819,
                             a3: "Assertion Failed: (elem == Count()) || IsValidIndex(elem)") != 0) )
    {
      __debugbreak();
    }
  }
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::GrowVector(a1: 1);
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::ShiftElementsRight(i, a2: 1);
  v4 = CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Element(this, i);
  CopyConstruct<IAppSystem *>(a1: v4, a2: a3);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x004051B0
// Name: public: CUtlMemory<class IAppSystem __near *,int>::CUtlMemory<class IAppSystem __near *,int>(int,int)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CUtlMemory<IAppSystem *,int>::CUtlMemory<IAppSystem *,int>(
        CSteamApplication *this,
        int a2,
        CAppSystemGroup::Module_t *a3)
{
  const char *v3; // eax
  CSteamApplication_vtbl *v4; // eax
  CMemAllocAttributeAlloction v6; // [esp+D3h] [ebp-1Dh] BYREF
  int v7; // [esp+DCh] [ebp-14h]
  CSteamApplication *v8; // [esp+E8h] [ebp-8h]

  v8 = this;
  this->__vftable = nullptr;
  v8->m_Modules.m_Memory.m_pMemory = a3;
  v8->m_Modules.m_Memory.m_nAllocationCount = a2;
  CSteamApplication::PostShutdown(this: v8);
  if ( a2 < 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 409);
    v7 = __SpewMessage(a1: "%s", "Assertion Failed: nGrowSize >= 0");
    if ( v7 == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 409,
                             a3: "Assertion Failed: nGrowSize >= 0") != 0) )
    {
      __debugbreak();
    }
  }
  if ( v8->m_Modules.m_Memory.m_pMemory != nullptr )
  {
    v3 = type_info::name(
           this: &CUtlMemory<IAppSystem *,int> `RTTI Type Descriptor',
           __ptype_info_node: &__type_info_root_node);
    CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v3, a3: 413);
    v4 = (CSteamApplication_vtbl *)_g_pMemAlloc->Alloc(
                                     this: _g_pMemAlloc,
                                     a2: 4 * (int)v8->m_Modules.m_Memory.m_pMemory,
                                     a3: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                     a4: 414);
    v8->__vftable = v4;
    CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00405370
// Name: public: int __near & CUtlDict<int,unsigned short>::Element(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CUtlDict<int,unsigned short>::Element(unsigned __int16 i)
{
  return CUtlMap<char const *,int,unsigned short>::operator[](i);
}

//------------------------------------------------------------------------------
// Address: 0x004053C0
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(int,int,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess const __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        char *this,
        int a2,
        int a3,
        _DWORD *a4)
{
  *(_DWORD *)this = *a4;
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(
    a1: a2,
    a2: a3);
  *((_WORD *)this + 8) = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex();
  *((_WORD *)this + 9) = 0;
  *((_WORD *)this + 10) = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex();
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::InvalidIterator(
    this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *)(this + 4),
    result: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *)this
  + 11);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::ResetDbgInfo(a1: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405460
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetLessFunc(class CUtlMap<char const __near *,int,unsigned short>::CKeyLess const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetLessFunc(
        _DWORD *this,
        _DWORD *a2)
{
  int result; // eax

  if ( (unsigned __int8)CUtlMap<char const *,int,unsigned short>::CKeyLess::operator!(a1: this) != 0 )
  {
    *this = *a2;
    return (int)a2;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Count(a1: this);
    if ( result != 0 )
    {
      __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlrbtree.h", a3: 1436);
      if ( __SpewMessage(a1: "%s", "Assertion Failed: 0") == 0
        && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
         || (unsigned __int8)_DoNewAssertDialog(
                               a1: "u:\\main\\src\\public\\tier1\\utlrbtree.h",
                               a2: 1436,
                               a3: "Assertion Failed: 0") != 0) )
      {
        __debugbreak();
      }
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405580
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlMap<char const *,int,unsigned short> *this,
        int a2)
{
  CUtlMap<char const *,int,unsigned short>::Node_t *v2; // eax
  unsigned __int16 i; // [esp+D0h] [ebp-2Ch]
  char v5[9]; // [esp+DFh] [ebp-1Dh] BYREF
  unsigned __int16 v6[6]; // [esp+E8h] [ebp-14h] BYREF
  CUtlMap<char const *,int,unsigned short> *v7; // [esp+F4h] [ebp-8h]

  v7 = this;
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    a1: a2,
    a2: v6,
    a3: v5);
  i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertAt(
        a1: v6[0],
        a2: v5[0]);
  v2 = CUtlMap<char const *,int,unsigned short>::Key(this: v7, i);
  CopyConstruct<CUtlMap<char const *,int,unsigned short>::Node_t>(a1: v2, a2);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x00405650
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        int a2)
{
  int v2; // eax
  int v3; // eax
  unsigned __int16 i; // [esp+D0h] [ebp-20h]

  if ( (unsigned __int8)CUtlMap<char const *,int,unsigned short>::CKeyLess::operator!(a1: this) != 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlrbtree.h", a3: 1530);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: m_LessFunc") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlrbtree.h",
                             a2: 1530,
                             a3: "Assertion Failed: m_LessFunc") != 0) )
    {
      __debugbreak();
    }
  }
  i = this->m_Root;
  while ( i != CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex() )
  {
    v2 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Element(i);
    if ( (unsigned __int8)CUtlMap<char const *,int,unsigned short>::CKeyLess::operator()(a1: a2, a2: v2) != 0 )
    {
      i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
            this,
            i);
    }
    else
    {
      v3 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Element(i);
      if ( (unsigned __int8)CUtlMap<char const *,int,unsigned short>::CKeyLess::operator()(a1: v3, a2) == 0 )
        return i;
      i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
            this,
            i);
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x004057E0
// Name: public: virtual void CSteamApplication::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::PostShutdown(CSteamApplication *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00405810
// Name: public: int __near & CUtlMap<char const __near *,int,unsigned short>::operator[](unsigned short)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CUtlMap<char const *,int,unsigned short>::operator[](
        CUtlMap<char const *,int,unsigned short> *this,
        unsigned __int16 i)
{
  return &CUtlMap<char const *,int,unsigned short>::Key(this, i)->elem;
}

//------------------------------------------------------------------------------
// Address: 0x00405860
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::ResetDbgInfo(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::ResetDbgInfo(
        _DWORD *this)
{
  int result; // eax

  result = CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Base(a1: this + 1);
  *(this + 6) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004058B0
// Name: public: bool CUtlMap<char const __near *,int,unsigned short>::CKeyLess::operator!(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlMap<char const *,int,unsigned short>::CKeyLess::operator!(_DWORD *this)
{
  return *this == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004058F0
// Name: public: bool CUtlMap<char const __near *,int,unsigned short>::CKeyLess::operator()(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &,struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,int,unsigned short>::CKeyLess::operator()(
        int (__cdecl **this)(int, int),
        int a2,
        int a3)
{
  return (*this)(a1: a2, a2: a3);
}

//------------------------------------------------------------------------------
// Address: 0x00405950
// Name: protected: void CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::GrowVector(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::GrowVector(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this,
        int a2)
{
  int v2; // esi
  const char *v3; // eax
  int v4; // esi
  int v5; // eax
  CMemAllocAttributeAlloction v6; // [esp+D3h] [ebp-11h] BYREF
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *v7; // [esp+DCh] [ebp-8h]

  v7 = this;
  v2 = a2 + this->m_Size;
  if ( v2 > CUtlMemory<IAppSystem *,int>::NumAllocated(a1: this) )
  {
    v3 = type_info::name(
           this: &CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>> `RTTI Type Descriptor',
           __ptype_info_node: &__type_info_root_node);
    CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v3, a3: 656);
    v4 = a2 + v7->m_Size;
    v5 = CUtlMemory<IAppSystem *,int>::NumAllocated(a1: v7);
    CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(a1: v4 - v5);
    CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
  }
  v7->m_Size += a2;
  CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::ResetDbgInfo(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00405A40
// Name: protected: void CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::ShiftElementsRight(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::ShiftElementsRight(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this,
        int i,
        int a3)
{
  CAppSystemGroup::Module_t *v3; // eax
  CAppSystemGroup::Module_t *v4; // [esp-8h] [ebp-F8h]
  int v5; // [esp+D0h] [ebp-20h]

  if ( (unsigned __int8)CUtlVector<char,CUtlMemory<char,int>>::IsValidIndex(a1: i) == 0 && this->m_Size != 0 && a3 != 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlvector.h", a3: 729);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: IsValidIndex(elem) || ( m_Size == 0 ) || ( num == 0 )") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlvector.h",
                             a2: 729,
                             a3: "Assertion Failed: IsValidIndex(elem) || ( m_Size == 0 ) || ( num == 0 )") != 0) )
    {
      __debugbreak();
    }
  }
  v5 = this->m_Size - i - a3;
  if ( v5 > 0 && a3 > 0 )
  {
    v4 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Element(this, i);
    v3 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Element(this, i: a3 + i);
    _V_memmove(file: "u:\\main\\src\\public\\tier1\\utlvector.h", line: 732, dest: v3, src: v4, count: 12 * v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405C30
// Name: protected: void CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>::GrowVector(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::GrowVector(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this,
        int a2)
{
  int v2; // esi
  const char *v3; // eax
  int v4; // esi
  int v5; // eax
  CMemAllocAttributeAlloction v6; // [esp+D3h] [ebp-11h] BYREF
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *v7; // [esp+DCh] [ebp-8h]

  v7 = this;
  v2 = a2 + this->m_Size;
  if ( v2 > CUtlMemory<IAppSystem *,int>::NumAllocated(a1: this) )
  {
    v3 = type_info::name(
           this: &CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>> `RTTI Type Descriptor',
           __ptype_info_node: &__type_info_root_node);
    CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v3, a3: 656);
    v4 = a2 + v7->m_Size;
    v5 = CUtlMemory<IAppSystem *,int>::NumAllocated(a1: v7);
    CUtlMemory<IAppSystem *,int>::Grow(a1: v4 - v5);
    CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
  }
  v7->m_Size += a2;
  CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::ResetDbgInfo(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00405D20
// Name: protected: void CUtlVector<class IAppSystem __near *,class CUtlMemory<class IAppSystem __near *,int>>::ShiftElementsRight(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::ShiftElementsRight(
        CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *this,
        int i,
        int a3)
{
  IAppSystem **v3; // eax
  IAppSystem **v4; // [esp-8h] [ebp-F8h]
  int v5; // [esp+D0h] [ebp-20h]

  if ( (unsigned __int8)CUtlVector<char,CUtlMemory<char,int>>::IsValidIndex(a1: i) == 0 && this->m_Size != 0 && a3 != 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlvector.h", a3: 729);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: IsValidIndex(elem) || ( m_Size == 0 ) || ( num == 0 )") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlvector.h",
                             a2: 729,
                             a3: "Assertion Failed: IsValidIndex(elem) || ( m_Size == 0 ) || ( num == 0 )") != 0) )
    {
      __debugbreak();
    }
  }
  v5 = this->m_Size - i - a3;
  if ( v5 > 0 && a3 > 0 )
  {
    v4 = CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Element(this, i);
    v3 = CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::Element(this, i: a3 + i);
    _V_memmove(file: "u:\\main\\src\\public\\tier1\\utlvector.h", line: 732, dest: v3, src: v4, count: 4 * v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405F10
// Name: public: struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near & CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Element(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
CUtlMap<char const *,int,unsigned short>::Node_t *__thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Element(
        int this,
        unsigned __int16 i)
{
  return &CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::operator[](
            this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *)(this + 4),
            i)->m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x00405F60
// Name: public: unsigned int CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Count(
        unsigned __int16 *this)
{
  return *(this + 9);
}

//------------------------------------------------------------------------------
// Address: 0x00405FA0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsValid(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v2; // eax
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // ax
  int v5; // esi
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t v6; // [esp+12h] [ebp-D2h] BYREF
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *v7; // [esp+DCh] [ebp-8h]

  v7 = this;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Count((unsigned __int16 *)this) == 0 )
    return true;
  v2 = CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::InvalidIterator(
         this: &v7->m_Elements,
         result: &v6);
  if ( CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t::operator==(
         this: &v7->m_LastAlloc,
         it: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t)v2->index) )
  {
    return false;
  }
  v3 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Root(a1: v7);
  if ( !CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsIdxValid(
          this: &v7->m_Elements,
          i: v3) )
    return false;
  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Root(a1: v7);
  v5 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
         this: v7,
         i: v4);
  return v5 == CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex();
}

//------------------------------------------------------------------------------
// Address: 0x00406060
// Name: protected: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertAt(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertAt(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 a2,
        char a3)
{
  unsigned __int16 i; // [esp+DCh] [ebp-14h]

  i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(a1: this);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    i,
    a2,
    a3);
  ++this->m_NumElements;
  if ( !CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsValid(this) )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlrbtree.h", a3: 852);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: IsValid()") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlrbtree.h",
                             a2: 852,
                             a3: "Assertion Failed: IsValid()") != 0) )
    {
      __debugbreak();
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x00406190
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlMap<char const *,int,unsigned short> *this,
        int a2,
        unsigned __int16 *a3,
        _BYTE *a4)
{
  int result; // eax
  CUtlMap<char const *,int,unsigned short>::Node_t *v5; // eax
  unsigned __int16 i; // [esp+D0h] [ebp-20h]

  if ( CUtlMap<char const *,int,unsigned short>::CKeyLess::operator!(this) )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlrbtree.h", a3: 1449);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: m_LessFunc") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlrbtree.h",
                             a2: 1449,
                             a3: "Assertion Failed: m_LessFunc") != 0) )
    {
      __debugbreak();
    }
  }
  i = this->m_Tree.m_Root;
  *a3 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex();
  *a4 = 0;
  while ( 1 )
  {
    result = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex();
    if ( i == (unsigned __int16)result )
      break;
    *a3 = i;
    v5 = CUtlMap<char const *,int,unsigned short>::Key(this, i);
    if ( (unsigned __int8)CUtlMap<char const *,int,unsigned short>::CKeyLess::operator()(
                            (int (__cdecl **)(int, int))this,
                            a2,
                            a3: (int)v5) != 0 )
    {
      *a4 = 1;
      i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
            this: &this->m_Tree,
            i);
    }
    else
    {
      *a4 = 0;
      i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
            this: &this->m_Tree,
            i);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406310
// Name: public: CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(int,int)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(
        CSteamApplication *this,
        int a2,
        CAppSystemGroup::Module_t *a3)
{
  const char *v3; // eax
  CSteamApplication_vtbl *v4; // eax
  CMemAllocAttributeAlloction v6; // [esp+D3h] [ebp-1Dh] BYREF
  int v7; // [esp+DCh] [ebp-14h]
  CSteamApplication *v8; // [esp+E8h] [ebp-8h]

  v8 = this;
  this->__vftable = nullptr;
  v8->m_Modules.m_Memory.m_pMemory = a3;
  v8->m_Modules.m_Memory.m_nAllocationCount = a2;
  CSteamApplication::PostShutdown(this: v8);
  if ( a2 < 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 409);
    v7 = __SpewMessage(a1: "%s", "Assertion Failed: nGrowSize >= 0");
    if ( v7 == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 409,
                             a3: "Assertion Failed: nGrowSize >= 0") != 0) )
    {
      __debugbreak();
    }
  }
  if ( v8->m_Modules.m_Memory.m_pMemory != nullptr )
  {
    v3 = type_info::name(
           this: &CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> `RTTI Type Descriptor',
           __ptype_info_node: &__type_info_root_node);
    CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v3, a3: 413);
    v4 = (CSteamApplication_vtbl *)_g_pMemAlloc->Alloc(
                                     this: _g_pMemAlloc,
                                     a2: 16 * (int)v8->m_Modules.m_Memory.m_pMemory,
                                     a3: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                     a4: 414);
    v8->__vftable = v4;
    CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00406540
// Name: public: CUtlMap<char const __near *,int,unsigned short>::Node_t::Node_t(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall CUtlMap<char const *,int,unsigned short>::Node_t::Node_t(_DWORD *this, _DWORD *a2)
{
  *this = *a2;
  *(this + 1) = a2[1];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00406590
// Name: public: int CUtlMemory<class IAppSystem __near *,int>::NumAllocated(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMemory<IAppSystem *,int>::NumAllocated(_DWORD *this)
{
  return *(this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x004065C0
// Name: public: void CUtlMemory<struct CAppSystemGroup::Module_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int a2)
{
  const char *v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v3; // eax
  const char *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v5; // eax
  CMemAllocAttributeAlloction v6; // [esp+DFh] [ebp-65h] BYREF
  CMemAllocAttributeAlloction v7; // [esp+F7h] [ebp-4Dh] BYREF
  int v8; // [esp+10Ch] [ebp-38h]
  int v9; // [esp+118h] [ebp-2Ch]
  int v10; // [esp+130h] [ebp-14h]
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *v11; // [esp+13Ch] [ebp-8h]

  v11 = this;
  if ( a2 <= 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 683);
    v10 = __SpewMessage(a1: "%s", "Assertion Failed: num > 0");
    if ( v10 == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 683,
                             a3: "Assertion Failed: num > 0") != 0) )
    {
      __debugbreak();
    }
  }
  if ( CUtlMemory<IAppSystem *,int>::IsExternallyAllocated(this: v11) )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 688);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: 0") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 688,
                             a3: "Assertion Failed: 0") != 0) )
    {
      __debugbreak();
    }
  }
  else
  {
    v9 = a2 + v11->m_nAllocationCount;
    v8 = UtlMemory_CalcNewAllocationCount(a1: v11->m_nAllocationCount, a2: v11->m_nGrowSize, a3: v9, a4: 12);
    if ( v8 < v9 )
    {
      if ( v8 != 0 || v9 > -1 )
      {
        while ( v8 < v9 )
          v8 = (v9 + v8) / 2;
      }
      else
      {
        --v8;
      }
    }
    v11->m_nAllocationCount = v8;
    if ( v11->m_pMemory != nullptr )
    {
      v2 = type_info::name(
             this: &CUtlMemory<CAppSystemGroup::Module_t,int> `RTTI Type Descriptor',
             __ptype_info_node: &__type_info_root_node);
      CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v7, a2: v2, a3: 728);
      v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: v11->m_pMemory,
                                                                                                 a3: 12
                                                                                               * v11->m_nAllocationCount,
                                                                                                 a4: "u:\\main\\src\\public\\"
                                                                                                 "tier1\\utlmemory.h",
                                                                                                 a5: 729);
      v11->m_pMemory = v3;
      if ( v11->m_pMemory == nullptr )
      {
        __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 730);
        if ( __SpewMessage(a1: "%s", "Assertion Failed: m_pMemory") == 0
          && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
           || (unsigned __int8)_DoNewAssertDialog(
                                 a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                 a2: 730,
                                 a3: "Assertion Failed: m_pMemory") != 0) )
        {
          __debugbreak();
        }
      }
      CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v7);
    }
    else
    {
      v4 = type_info::name(
             this: &CUtlMemory<CAppSystemGroup::Module_t,int> `RTTI Type Descriptor',
             __ptype_info_node: &__type_info_root_node);
      CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v4, a3: 734);
      v5 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 12
                                                                                               * v11->m_nAllocationCount,
                                                                                                 a3: "u:\\main\\src\\public\\"
                                                                                                 "tier1\\utlmemory.h",
                                                                                                 a4: 735);
      v11->m_pMemory = v5;
      if ( v11->m_pMemory == nullptr )
      {
        __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 736);
        if ( __SpewMessage(a1: "%s", "Assertion Failed: m_pMemory") == 0
          && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
           || (unsigned __int8)_DoNewAssertDialog(
                                 a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                 a2: 736,
                                 a3: "Assertion Failed: m_pMemory") != 0) )
        {
          __debugbreak();
        }
      }
      CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406BE0
// Name: public: void CUtlMemory<class IAppSystem __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<IAppSystem *,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int a2)
{
  const char *v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v3; // eax
  const char *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v5; // eax
  CMemAllocAttributeAlloction v6; // [esp+DFh] [ebp-65h] BYREF
  CMemAllocAttributeAlloction v7; // [esp+F7h] [ebp-4Dh] BYREF
  int v8; // [esp+10Ch] [ebp-38h]
  int v9; // [esp+118h] [ebp-2Ch]
  int v10; // [esp+130h] [ebp-14h]
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *v11; // [esp+13Ch] [ebp-8h]

  v11 = this;
  if ( a2 <= 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 683);
    v10 = __SpewMessage(a1: "%s", "Assertion Failed: num > 0");
    if ( v10 == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 683,
                             a3: "Assertion Failed: num > 0") != 0) )
    {
      __debugbreak();
    }
  }
  if ( CUtlMemory<IAppSystem *,int>::IsExternallyAllocated(this: v11) )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 688);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: 0") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 688,
                             a3: "Assertion Failed: 0") != 0) )
    {
      __debugbreak();
    }
  }
  else
  {
    v9 = a2 + v11->m_nAllocationCount;
    v8 = UtlMemory_CalcNewAllocationCount(a1: v11->m_nAllocationCount, a2: v11->m_nGrowSize, a3: v9, a4: 4);
    if ( v8 < v9 )
    {
      if ( v8 != 0 || v9 > -1 )
      {
        while ( v8 < v9 )
          v8 = (v9 + v8) / 2;
      }
      else
      {
        --v8;
      }
    }
    v11->m_nAllocationCount = v8;
    if ( v11->m_pMemory != nullptr )
    {
      v2 = type_info::name(
             this: &CUtlMemory<IAppSystem *,int> `RTTI Type Descriptor',
             __ptype_info_node: &__type_info_root_node);
      CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v7, a2: v2, a3: 728);
      v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: v11->m_pMemory,
                                                                                                 a3: 4
                                                                                               * v11->m_nAllocationCount,
                                                                                                 a4: "u:\\main\\src\\public\\"
                                                                                                 "tier1\\utlmemory.h",
                                                                                                 a5: 729);
      v11->m_pMemory = v3;
      if ( v11->m_pMemory == nullptr )
      {
        __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 730);
        if ( __SpewMessage(a1: "%s", "Assertion Failed: m_pMemory") == 0
          && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
           || (unsigned __int8)_DoNewAssertDialog(
                                 a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                 a2: 730,
                                 a3: "Assertion Failed: m_pMemory") != 0) )
        {
          __debugbreak();
        }
      }
      CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v7);
    }
    else
    {
      v4 = type_info::name(
             this: &CUtlMemory<IAppSystem *,int> `RTTI Type Descriptor',
             __ptype_info_node: &__type_info_root_node);
      CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v4, a3: 734);
      v5 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 4
                                                                                               * v11->m_nAllocationCount,
                                                                                                 a3: "u:\\main\\src\\public\\"
                                                                                                 "tier1\\utlmemory.h",
                                                                                                 a4: 735);
      v11->m_pMemory = v5;
      if ( v11->m_pMemory == nullptr )
      {
        __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 736);
        if ( __SpewMessage(a1: "%s", "Assertion Failed: m_pMemory") == 0
          && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
           || (unsigned __int8)_DoNewAssertDialog(
                                 a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                 a2: 736,
                                 a3: "Assertion Failed: m_pMemory") != 0) )
        {
          __debugbreak();
        }
      }
      CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407190
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Root(void)const
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Root(
        _WORD *this)
{
  return *(this + 8);
}

//------------------------------------------------------------------------------
// Address: 0x004071D0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // esi
  const char *v2; // eax
  CUtlMap<char const *,int,unsigned short>::Node_t *v3; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v5; // [esp+Ch] [ebp-16Ch]
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v6; // [esp+Ch] [ebp-16Ch]
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t v7; // [esp+22h] [ebp-156h] BYREF
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t v8; // [esp+2Eh] [ebp-14Ah] BYREF
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v9; // [esp+38h] [ebp-140h]
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t v10; // [esp+46h] [ebp-132h] BYREF
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t v11; // [esp+52h] [ebp-126h] BYREF
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v12; // [esp+11Ch] [ebp-5Ch]
  int v13; // [esp+128h] [ebp-50h]
  int v14; // [esp+134h] [ebp-44h]
  CMemAllocAttributeAlloction v15; // [esp+143h] [ebp-35h] BYREF
  _WORD v16[6]; // [esp+14Ch] [ebp-2Ch] BYREF
  int v17; // [esp+158h] [ebp-20h]
  unsigned __int16 i; // [esp+164h] [ebp-14h]
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *v19; // [esp+170h] [ebp-8h]

  v19 = this;
  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex() )
  {
    if ( (unsigned __int8)CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsValidIterator(a1: &v19->m_LastAlloc) == 0
      && v19->m_NumElements != 0 )
    {
      __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlrbtree.h", a3: 657);
      v17 = __SpewMessage(a1: "%s", "Assertion Failed: m_Elements.IsValidIterator( m_LastAlloc ) || m_NumElements == 0");
      if ( v17 == 0
        && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
         || (unsigned __int8)_DoNewAssertDialog(
                               a1: "u:\\main\\src\\public\\tier1\\utlrbtree.h",
                               a2: 657,
                               a3: "Assertion Failed: m_Elements.IsValidIterator( m_LastAlloc ) || m_NumElements == 0") != 0) )
      {
        __debugbreak();
      }
    }
    if ( (unsigned __int8)CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsValidIterator(a1: &v19->m_LastAlloc) != 0 )
      v5 = CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Next(
             this: &v19->m_Elements,
             result: &v7,
             it: &v19->m_LastAlloc);
    else
      v5 = CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::First(
             this: &v19->m_Elements,
             result: &v8);
    v16[0] = v5->index;
    if ( (unsigned __int8)CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsValidIterator(a1: v16) == 0 )
    {
      v2 = type_info::name(
             this: &CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>> `RTTI Type Descriptor',
             __ptype_info_node: &__type_info_root_node);
      CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v15, a2: v2, a3: 661);
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(a1: 1);
      if ( (unsigned __int8)CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsValidIterator(a1: &v19->m_LastAlloc) != 0 )
        v6 = CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Next(
               this: &v19->m_Elements,
               result: &v10,
               it: &v19->m_LastAlloc);
      else
        v6 = CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::First(
               this: &v19->m_Elements,
               result: &v11);
      v9 = v6;
      v16[0] = v6->index;
      if ( (unsigned __int8)CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsValidIterator(a1: v16) == 0 )
      {
        __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlrbtree.h", a3: 666);
        v14 = __SpewMessage(a1: "%s", "Assertion Failed: m_Elements.IsValidIterator( it )");
        if ( v14 == 0
          && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
           || (unsigned __int8)_DoNewAssertDialog(
                                 a1: "u:\\main\\src\\public\\tier1\\utlrbtree.h",
                                 a2: 666,
                                 a3: "Assertion Failed: m_Elements.IsValidIterator( it )") != 0) )
        {
          __debugbreak();
        }
      }
      if ( (unsigned __int8)CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsValidIterator(a1: v16) == 0 )
        _Error(a1: "CUtlRBTree overflow!\n");
      CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v15);
    }
    v19->m_LastAlloc.index = v16[0];
    i = CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::GetIndex(
          this: &v19->m_Elements,
          it: &v19->m_LastAlloc);
    if ( (unsigned __int8)CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsValidIterator(a1: &v19->m_LastAlloc) == 0 )
    {
      __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlrbtree.h", a3: 674);
      v13 = __SpewMessage(a1: "%s", "Assertion Failed: m_Elements.IsValidIterator( m_LastAlloc )");
      if ( v13 == 0
        && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
         || (unsigned __int8)_DoNewAssertDialog(
                               a1: "u:\\main\\src\\public\\tier1\\utlrbtree.h",
                               a2: 674,
                               a3: "Assertion Failed: m_Elements.IsValidIterator( m_LastAlloc )") != 0) )
      {
        __debugbreak();
      }
    }
  }
  else
  {
    i = v19->m_FirstFree;
    v19->m_FirstFree = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                         this: v19,
                         i: v19->m_FirstFree)->m_Right;
  }
  v12 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
          this: v19,
          i);
  v12->m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex();
  v12->m_Right = v12->m_Parent;
  v12->m_Left = v12->m_Right;
  v3 = CUtlMap<char const *,int,unsigned short>::Key(this: (CUtlMap<char const *,int,unsigned short> *)v19, i);
  Construct<CUtlMap<char const *,int,unsigned short>::Node_t>(a1: v3);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::ResetDbgInfo(this: v19);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x004076D0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 a3,
        char a4)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v5; // [esp+D0h] [ebp-14h]

  v5 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i);
  v5->m_Parent = a3;
  v5->m_Right = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex();
  v5->m_Left = v5->m_Right;
  v5->m_Tag = 0;
  if ( a3 == CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex() )
  {
    this->m_Root = i;
  }
  else if ( a4 != 0 )
  {
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
      this,
      i: a3)->m_Left = i;
  }
  else
  {
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
      this,
      i: a3)->m_Right = i;
  }
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(i);
}

//------------------------------------------------------------------------------
// Address: 0x004077B0
// Name: public: bool CUtlMemory<char,int>::IsReadOnly(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlMemory<char,int>::IsReadOnly(_DWORD *this)
{
  return *(this + 2) == -2;
}

//------------------------------------------------------------------------------
// Address: 0x004077F0
// Name: public: bool CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsValidIterator(class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsValidIterator(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        unsigned __int16 *a2)
{
  return CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::IsIdxValid(
           this,
           i: *a2);
}

//------------------------------------------------------------------------------
// Address: 0x00407840
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // ax
  unsigned __int16 v4; // [esp+D0h] [ebp-38h]
  unsigned __int16 v5; // [esp+DCh] [ebp-2Ch]
  unsigned __int16 v6; // [esp+E8h] [ebp-20h]
  unsigned __int16 v7; // [esp+F4h] [ebp-14h]

  while ( (unsigned __int8)CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRoot(a1: i) == 0 )
  {
    v2 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(i: v2) != 0 )
      break;
    v7 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i);
    v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: v7);
    if ( (unsigned __int8)CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsLeftChild(i: v7) != 0 )
    {
      v5 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
             this,
             i: v6);
      if ( (unsigned __int8)CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRed(i: v5) != 0 )
      {
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
          i: v7,
          a2: 1);
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
          i: v5,
          a2: 1);
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
          i: v6,
          a2: 0);
        i = v6;
      }
      else
      {
        if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRightChild(
               this,
               i) )
        {
          i = v7;
          CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(i: v7);
          v7 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v7);
          v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v7);
        }
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
          i: v7,
          a2: 1);
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
          i: v6,
          a2: 0);
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(i: v6);
      }
    }
    else
    {
      v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this,
             i: v6);
      if ( (unsigned __int8)CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRed(i: v4) != 0 )
      {
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
          i: v7,
          a2: 1);
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
          i: v4,
          a2: 1);
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
          i: v6,
          a2: 0);
        i = v6;
      }
      else
      {
        if ( (unsigned __int8)CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsLeftChild(i) != 0 )
        {
          i = v7;
          CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(i: v7);
          v7 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v7);
          v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v7);
        }
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
          i: v7,
          a2: 1);
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
          i: v6,
          a2: 0);
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(i: v6);
      }
    }
  }
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
           i: this->m_Root,
           a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00407AB0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int a2)
{
  const char *v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v3; // eax
  const char *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v5; // eax
  CMemAllocAttributeAlloction v6; // [esp+DFh] [ebp-65h] BYREF
  CMemAllocAttributeAlloction v7; // [esp+F7h] [ebp-4Dh] BYREF
  int v8; // [esp+10Ch] [ebp-38h]
  int v9; // [esp+118h] [ebp-2Ch]
  int v10; // [esp+130h] [ebp-14h]
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *v11; // [esp+13Ch] [ebp-8h]

  v11 = this;
  if ( a2 <= 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 683);
    v10 = __SpewMessage(a1: "%s", "Assertion Failed: num > 0");
    if ( v10 == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 683,
                             a3: "Assertion Failed: num > 0") != 0) )
    {
      __debugbreak();
    }
  }
  if ( CUtlMemory<IAppSystem *,int>::IsExternallyAllocated(this: v11) )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 688);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: 0") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 688,
                             a3: "Assertion Failed: 0") != 0) )
    {
      __debugbreak();
    }
    return;
  }
  v9 = a2 + v11->m_nAllocationCount;
  v8 = UtlMemory_CalcNewAllocationCount(a1: v11->m_nAllocationCount, a2: v11->m_nGrowSize, a3: v9, a4: 16);
  if ( (unsigned __int16)v8 >= v9 )
    goto LABEL_24;
  if ( (_WORD)v8 == 0 && v9 <= 0xFFFF )
  {
    --v8;
    goto LABEL_24;
  }
  if ( (unsigned __int16)v9 == v9 )
  {
    while ( (unsigned __int16)v8 < v9 )
      v8 = (v9 + v8) / 2;
LABEL_24:
    v11->m_nAllocationCount = v8;
    if ( v11->m_pMemory != nullptr )
    {
      v2 = type_info::name(
             this: &CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> `RTTI Type Descriptor',
             __ptype_info_node: &__type_info_root_node);
      CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v7, a2: v2, a3: 728);
      v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: v11->m_pMemory,
                                                                                                 a3: 16
                                                                                               * v11->m_nAllocationCount,
                                                                                                 a4: "u:\\main\\src\\public\\"
                                                                                                 "tier1\\utlmemory.h",
                                                                                                 a5: 729);
      v11->m_pMemory = v3;
      if ( v11->m_pMemory == nullptr )
      {
        __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 730);
        if ( __SpewMessage(a1: "%s", "Assertion Failed: m_pMemory") == 0
          && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
           || (unsigned __int8)_DoNewAssertDialog(
                                 a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                 a2: 730,
                                 a3: "Assertion Failed: m_pMemory") != 0) )
        {
          __debugbreak();
        }
      }
      CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v7);
    }
    else
    {
      v4 = type_info::name(
             this: &CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> `RTTI Type Descriptor',
             __ptype_info_node: &__type_info_root_node);
      CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v4, a3: 734);
      v5 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16
                                                                                               * v11->m_nAllocationCount,
                                                                                                 a3: "u:\\main\\src\\public\\"
                                                                                                 "tier1\\utlmemory.h",
                                                                                                 a4: 735);
      v11->m_pMemory = v5;
      if ( v11->m_pMemory == nullptr )
      {
        __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 736);
        if ( __SpewMessage(a1: "%s", "Assertion Failed: m_pMemory") == 0
          && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
           || (unsigned __int8)_DoNewAssertDialog(
                                 a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                 a2: 736,
                                 a3: "Assertion Failed: m_pMemory") != 0) )
        {
          __debugbreak();
        }
      }
      CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
    }
    return;
  }
  __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 712);
  if ( __SpewMessage(a1: "%s", "Assertion Failed: 0") == 0
    && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
     || (unsigned __int8)_DoNewAssertDialog(
                           a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                           a2: 712,
                           a3: "Assertion Failed: 0") != 0) )
  {
    __debugbreak();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004080D0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsLeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // ax

  v2 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
         this,
         i);
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v2) == i;
}

//------------------------------------------------------------------------------
// Address: 0x00408130
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRoot(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRoot(
        _WORD *this,
        __int16 a2)
{
  return a2 == *(this + 8);
}

//------------------------------------------------------------------------------
// Address: 0x00408170
// Name: protected: bool CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRed(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRed(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i)->m_Tag == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004081D0
// Name: protected: enum CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NodeColor_t CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i)->m_Tag;
}

//------------------------------------------------------------------------------
// Address: 0x00408220
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(unsigned short,enum CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NodeColor_t)
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetColor(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 a3)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *result; // eax

  result = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
             this,
             i);
  result->m_Tag = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408270
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // ax
  int v3; // esi
  unsigned __int16 v4; // ax
  __int16 v5; // ax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // ax
  int result; // eax
  unsigned __int16 child; // [esp+D0h] [ebp-14h]

  child = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
            this,
            i);
  v2 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: child);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetRightChild(
    this,
    i,
    child: v2);
  v3 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: child);
  if ( v3 != CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex() )
  {
    v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: child);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetParent(
      i: v4,
      a2: i);
  }
  if ( child != CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex() )
  {
    v5 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetParent(
      i: child,
      a2: v5);
  }
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRoot(
         this,
         a2: i) )
  {
    this->m_Root = child;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsLeftChild(
              this,
              i) )
  {
    v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetLeftChild(
      this,
      i: v6,
      child);
  }
  else
  {
    v7 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetRightChild(
      this,
      i: v7,
      child);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetLeftChild(
    this,
    i: child,
    child: i);
  result = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex();
  if ( i != (unsigned __int16)result )
    return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetParent(
             i,
             a2: child);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004083E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // ax
  int v3; // esi
  unsigned __int16 v4; // ax
  __int16 v5; // ax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // ax
  int result; // eax
  unsigned __int16 child; // [esp+D0h] [ebp-14h]

  child = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
            this,
            i);
  v2 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: child);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetLeftChild(
    this,
    i,
    child: v2);
  v3 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: child);
  if ( v3 != CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex() )
  {
    v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: child);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetParent(
      i: v4,
      a2: i);
  }
  if ( child != CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex() )
  {
    v5 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetParent(
      i: child,
      a2: v5);
  }
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRoot(
         this,
         a2: i) )
  {
    this->m_Root = child;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::IsRightChild(
              this,
              i) )
  {
    v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetRightChild(
      this,
      i: v6,
      child);
  }
  else
  {
    v7 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetLeftChild(
      this,
      i: v7,
      child);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetRightChild(
    this,
    i: child,
    child: i);
  result = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InvalidIndex();
  if ( i != (unsigned __int16)result )
    return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetParent(
             i,
             a2: child);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408550
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetParent(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::SetParent(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 a3)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *result; // eax

  result = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
             this,
             i);
  result->m_Parent = a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408940
// Name: public: virtual void CSteamApplication::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Destroy(CSteamApplication *this)
{
  this->m_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00408980
// Name: public: virtual bool CSteamApplication::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::PreInit(CSteamApplication *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004089B0
// Name: public: virtual int CSteamApplication::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Main(CSteamApplication *this)
{
  if ( FileSystem_SetBasePaths(a1: this->m_pFileSystem) != 0 )
    return 0;
  CSteamAppSystemGroup::Setup(this: this->m_pChildAppSystemGroup, a2: this->m_pFileSystem, a3: this);
  return CAppSystemGroup::Run(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x0040C4A0
// Name: public: char __near * CUtlVector<char,class CUtlMemory<char,int>>::Base(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::Base(void *this)
{
  return CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Base(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x0040C590
// Name: public: char __near & CArrayAutoPtr<char>::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CArrayAutoPtr<char>::operator[](void *this, int a2)
{
  return a2 + CPlainAutoPtr<char>::Get(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x0040C670
// Name: public: CUtlMap<char const __near *,int,unsigned short>::CKeyLess::CKeyLess(bool (*)(char const __near * const __near &,char const __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall CUtlMap<char const *,int,unsigned short>::CKeyLess::CKeyLess(_DWORD *this, int a2)
{
  *this = a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040C770
// Name: public: struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short> __near * CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Base(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Base(
        _DWORD *this)
{
  if ( CUtlMemory<char,int>::IsReadOnly(this) )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 607);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: !IsReadOnly()") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 607,
                             a3: "Assertion Failed: !IsReadOnly()") != 0) )
    {
      __debugbreak();
    }
  }
  return *this;
}

//------------------------------------------------------------------------------
// Address: 0x0040C870
// Name: public: CUtlVector<char,class CUtlMemory<char,int>>::CUtlVector<char,class CUtlMemory<char,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall CUtlVector<char,CUtlMemory<char,int>>::CUtlVector<char,CUtlMemory<char,int>>(
        _DWORD *this,
        int a2,
        int a3)
{
  CUtlMemory<char,int>::CUtlMemory<char,int>(a1: a2, a2: a3);
  *(this + 3) = 0;
  CUtlVector<char,CUtlMemory<char,int>>::ResetDbgInfo(a1: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040C8D0
// Name: public: CUtlVector<char,class CUtlMemory<char,int>>::~CUtlVector<char,class CUtlMemory<char,int>>(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(void *this)
{
  CUtlVector<char,CUtlMemory<char,int>>::Purge(a1: this);
  return CUtlMemory<char,int>::~CUtlMemory<char,int>(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x0040C920
// Name: public: char __near & CUtlVector<char,class CUtlMemory<char,int>>::Element(int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CUtlVector<char,CUtlMemory<char,int>>::Element(int a1)
{
  return CUtlMemory<char,int>::operator[](a1);
}

//------------------------------------------------------------------------------
// Address: 0x0040C970
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(_DWORD *this)
{
  return *(this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x0040C9A0
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::SetSize(int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CUtlVector<char,CUtlMemory<char,int>>::SetSize(int a1)
{
  return CUtlVector<char,CUtlMemory<char,int>>::SetCount(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0040C9F0
// Name: protected: void CUtlVector<char,class CUtlMemory<char,int>>::ResetDbgInfo(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::ResetDbgInfo(_DWORD *this)
{
  int result; // eax

  result = CUtlVector<char,CUtlMemory<char,int>>::Base(this);
  *(this + 4) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CA40
// Name: public: CUtlMemory<char,int>::CUtlMemory<char,int>(int,int)
// Source: json
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CUtlMemory<char,int>::CUtlMemory<char,int>(
        CSteamApplication *this,
        int a2,
        CAppSystemGroup::Module_t *a3)
{
  const char *v3; // eax
  CSteamApplication_vtbl *v4; // eax
  CMemAllocAttributeAlloction v6; // [esp+D3h] [ebp-1Dh] BYREF
  int v7; // [esp+DCh] [ebp-14h]
  CSteamApplication *v8; // [esp+E8h] [ebp-8h]

  v8 = this;
  this->__vftable = nullptr;
  v8->m_Modules.m_Memory.m_pMemory = a3;
  v8->m_Modules.m_Memory.m_nAllocationCount = a2;
  CSteamApplication::PostShutdown(this: v8);
  if ( a2 < 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 409);
    v7 = __SpewMessage(a1: "%s", "Assertion Failed: nGrowSize >= 0");
    if ( v7 == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 409,
                             a3: "Assertion Failed: nGrowSize >= 0") != 0) )
    {
      __debugbreak();
    }
  }
  if ( v8->m_Modules.m_Memory.m_pMemory != nullptr )
  {
    v3 = type_info::name(this: &CUtlMemory<char,int> `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
    CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v3, a3: 413);
    v4 = (CSteamApplication_vtbl *)_g_pMemAlloc->Alloc(
                                     this: _g_pMemAlloc,
                                     a2: (unsigned int)v8->m_Modules.m_Memory.m_pMemory,
                                     a3: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                     a4: 414);
    v8->__vftable = v4;
    CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0040CC00
// Name: public: CUtlMemory<char,int>::~CUtlMemory<char,int>(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMemory<char,int>::~CUtlMemory<char,int>(void *this)
{
  return CUtlMemory<char,int>::Purge(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x0040CC40
// Name: public: char __near & CUtlMemory<char,int>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMemory<char,int>::operator[](_DWORD *this, int a2)
{
  if ( CUtlMemory<char,int>::IsReadOnly(this) )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 543);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: !IsReadOnly()") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 543,
                             a3: "Assertion Failed: !IsReadOnly()") != 0) )
    {
      __debugbreak();
    }
  }
  if ( (unsigned __int8)CUtlMemory<char,int>::IsIdxValid(a1: a2) == 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 544);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: IsIdxValid(i)") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 544,
                             a3: "Assertion Failed: IsIdxValid(i)") != 0) )
    {
      __debugbreak();
    }
  }
  return a2 + *this;
}

//------------------------------------------------------------------------------
// Address: 0x0040CE00
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::SetCount(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::SetCount(void *this, int a2)
{
  CUtlVector<char,CUtlMemory<char,int>>::RemoveAll(a1: this);
  return CUtlVector<char,CUtlMemory<char,int>>::AddMultipleToTail(a1: a2, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040CE50
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::Purge(_DWORD *this)
{
  CUtlVector<char,CUtlMemory<char,int>>::RemoveAll(a1: this);
  CUtlMemory<char,int>::Purge(a1: this);
  return CUtlVector<char,CUtlMemory<char,int>>::ResetDbgInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040CEA0
// Name: public: bool CUtlMemory<char,int>::IsIdxValid(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlMemory<char,int>::IsIdxValid(_DWORD *this, int a2)
{
  return a2 >= 0 && a2 < *(this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x0040CF00
// Name: public: void CUtlMemory<char,int>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMemory<char,int>::Purge(int this)
{
  int result; // eax

  result = (unsigned __int8)CUtlMemory<char,int>::IsExternallyAllocated(a1: this);
  if ( (_BYTE)result == 0 )
  {
    if ( *(_DWORD *)this != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)this);
      *(_DWORD *)this = 0;
    }
    *(_DWORD *)(this + 4) = 0;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CF90
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::AddMultipleToTail(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::AddMultipleToTail(_DWORD *this, int a2, unsigned int a3)
{
  int v3; // esi

  if ( CUtlVector<char,CUtlMemory<char,int>>::Base(this) != 0
    && a3 != 0
    && a2 + a3 >= CUtlVector<char,CUtlMemory<char,int>>::Base(this) )
  {
    v3 = CUtlVector<char,CUtlMemory<char,int>>::Base(this);
    if ( a3 < CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this) + v3 )
    {
      __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlvector.h", a3: 841);
      if ( __SpewMessage(
             a1: "%s",
             "Assertion Failed: (Base() == NULL) || !pToCopy || (pToCopy + num < Base()) || (pToCopy >= (Base() + Count()) )") == 0
        && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
         || (unsigned __int8)_DoNewAssertDialog(
                               a1: "u:\\main\\src\\public\\tier1\\utlvector.h",
                               a2: 841,
                               a3: "Assertion Failed: (Base() == NULL) || !pToCopy || (pToCopy + num < Base()) || (pToCopy >="
                               " (Base() + Count()) )") != 0) )
      {
        __debugbreak();
      }
    }
  }
  return CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(a1: *(this + 3), a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0040D0E0
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CUtlVector<char,CUtlMemory<char,int>>::RemoveAll(int *this)
{
  unsigned __int8 *v1; // eax
  int v3; // [esp+D0h] [ebp-14h]

  v3 = *(this + 3);
  while ( --v3 >= 0 )
  {
    v1 = (unsigned __int8 *)CUtlVector<char,CUtlMemory<char,int>>::Element(a1: v3);
    Destruct<char>(dst: v1);
  }
  *(this + 3) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040D150
// Name: public: bool CUtlMemory<char,int>::IsExternallyAllocated(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlMemory<char,int>::IsExternallyAllocated(int *this)
{
  return *(this + 2) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040D190
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(_DWORD *this, int a2, int a3, int a4)
{
  void *v5; // eax
  int j; // [esp+D0h] [ebp-2Ch]
  int i; // [esp+DCh] [ebp-20h]

  if ( a3 == 0 )
    return a2;
  if ( a2 != CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this)
    && (unsigned __int8)CUtlVector<char,CUtlMemory<char,int>>::IsValidIndex(a1: a2) == 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlvector.h", a3: 921);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: (elem == Count()) || IsValidIndex(elem)") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlvector.h",
                             a2: 921,
                             a3: "Assertion Failed: (elem == Count()) || IsValidIndex(elem)") != 0) )
    {
      __debugbreak();
    }
  }
  CUtlVector<char,CUtlMemory<char,int>>::GrowVector(a1: a3);
  CUtlVector<char,CUtlMemory<char,int>>::ShiftElementsRight(a1: a2, a2: a3);
  for ( i = 0; i < a3; ++i )
  {
    v5 = (void *)CUtlVector<char,CUtlMemory<char,int>>::Element(a1: i + a2);
    Construct<char>(a1: v5);
  }
  if ( a4 != 0 )
  {
    for ( j = 0; j < a3; ++j )
      *(_BYTE *)CUtlVector<char,CUtlMemory<char,int>>::Element(a1: j + a2) = *(_BYTE *)(j + a4);
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x0040D390
// Name: public: bool CUtlVector<char,class CUtlMemory<char,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlVector<char,CUtlMemory<char,int>>::IsValidIndex(_DWORD *this, int a2)
{
  return a2 >= 0 && a2 < *(this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x0040D3F0
// Name: protected: void CUtlVector<char,class CUtlMemory<char,int>>::GrowVector(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::GrowVector(_DWORD *this, int a2)
{
  int v2; // esi
  const char *v3; // eax
  int v4; // esi
  int v5; // eax
  CMemAllocAttributeAlloction v7; // [esp+D3h] [ebp-11h] BYREF
  _DWORD *v8; // [esp+DCh] [ebp-8h]

  v8 = this;
  v2 = a2 + *(this + 3);
  if ( v2 > CUtlMemory<IAppSystem *,int>::NumAllocated(this) )
  {
    v3 = type_info::name(
           this: &CUtlVector<char,CUtlMemory<char,int>> `RTTI Type Descriptor',
           __ptype_info_node: &__type_info_root_node);
    CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v7, a2: v3, a3: 656);
    v4 = a2 + v8[3];
    v5 = CUtlMemory<IAppSystem *,int>::NumAllocated(this: v8);
    CUtlMemory<char,int>::Grow(a1: v4 - v5);
    CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v7);
  }
  v8[3] += a2;
  return CUtlVector<char,CUtlMemory<char,int>>::ResetDbgInfo(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x0040D4E0
// Name: protected: void CUtlVector<char,class CUtlMemory<char,int>>::ShiftElementsRight(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::ShiftElementsRight(_DWORD *this, int a2, int a3)
{
  void *v3; // eax
  const void *v4; // [esp-8h] [ebp-F8h]
  int count; // [esp+D0h] [ebp-20h]

  if ( !CUtlVector<char,CUtlMemory<char,int>>::IsValidIndex(this, a2) && *(this + 3) != 0 && a3 != 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlvector.h", a3: 729);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: IsValidIndex(elem) || ( m_Size == 0 ) || ( num == 0 )") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlvector.h",
                             a2: 729,
                             a3: "Assertion Failed: IsValidIndex(elem) || ( m_Size == 0 ) || ( num == 0 )") != 0) )
    {
      __debugbreak();
    }
  }
  count = *(this + 3) - a2 - a3;
  if ( count > 0 && a3 > 0 )
  {
    v4 = (const void *)CUtlVector<char,CUtlMemory<char,int>>::Element(a1: a2);
    v3 = (void *)CUtlVector<char,CUtlMemory<char,int>>::Element(a1: a3 + a2);
    _V_memmove(file: "u:\\main\\src\\public\\tier1\\utlvector.h", line: 732, dest: v3, src: v4, count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D690
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(int *this, int a2)
{
  const char *v2; // eax
  void *v3; // eax
  const char *v4; // eax
  int v5; // eax
  CMemAllocAttributeAlloction v6; // [esp+DFh] [ebp-65h] BYREF
  CMemAllocAttributeAlloction v7; // [esp+F7h] [ebp-4Dh] BYREF
  int v8; // [esp+10Ch] [ebp-38h]
  int v9; // [esp+118h] [ebp-2Ch]
  int v10; // [esp+130h] [ebp-14h]
  void **v11; // [esp+13Ch] [ebp-8h]

  v11 = (void **)this;
  if ( a2 <= 0 )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 683);
    v10 = __SpewMessage(a1: "%s", "Assertion Failed: num > 0");
    if ( v10 == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 683,
                             a3: "Assertion Failed: num > 0") != 0) )
    {
      __debugbreak();
    }
  }
  if ( CUtlMemory<char,int>::IsExternallyAllocated(this: (int *)v11) )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 688);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: 0") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                             a2: 688,
                             a3: "Assertion Failed: 0") != 0) )
    {
      __debugbreak();
    }
  }
  else
  {
    v9 = (int)v11[1] + a2;
    v8 = UtlMemory_CalcNewAllocationCount(a1: (int)v11[1], a2: (int)v11[2], a3: v9, a4: 1);
    if ( v8 < v9 )
    {
      if ( v8 != 0 || v9 > -1 )
      {
        while ( v8 < v9 )
          v8 = (v9 + v8) / 2;
      }
      else
      {
        --v8;
      }
    }
    v11[1] = (void *)v8;
    if ( *v11 != nullptr )
    {
      v2 = type_info::name(
             this: &CUtlMemory<char,int> `RTTI Type Descriptor',
             __ptype_info_node: &__type_info_root_node);
      CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v7, a2: v2, a3: 728);
      v3 = _g_pMemAlloc->Realloc(
             this: _g_pMemAlloc,
             a2: *v11,
             a3: v11[1],
             a4: "u:\\main\\src\\public\\tier1\\utlmemory.h",
             a5: 729);
      *v11 = v3;
      if ( *v11 == nullptr )
      {
        __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 730);
        if ( __SpewMessage(a1: "%s", "Assertion Failed: m_pMemory") == 0
          && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
           || (unsigned __int8)_DoNewAssertDialog(
                                 a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                 a2: 730,
                                 a3: "Assertion Failed: m_pMemory") != 0) )
        {
          __debugbreak();
        }
      }
      CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v7);
    }
    else
    {
      v4 = type_info::name(
             this: &CUtlMemory<char,int> `RTTI Type Descriptor',
             __ptype_info_node: &__type_info_root_node);
      CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(this: &v6, a2: v4, a3: 734);
      v5 = _g_pMemAlloc->Alloc(
             this: _g_pMemAlloc,
             a2: (unsigned int)v11[1],
             a3: "u:\\main\\src\\public\\tier1\\utlmemory.h",
             a4: 735);
      *v11 = (void *)v5;
      if ( *v11 == nullptr )
      {
        __SpewInfo(a1: 2, a2: "u:\\main\\src\\public\\tier1\\utlmemory.h", a3: 736);
        if ( __SpewMessage(a1: "%s", "Assertion Failed: m_pMemory") == 0
          && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
           || (unsigned __int8)_DoNewAssertDialog(
                                 a1: "u:\\main\\src\\public\\tier1\\utlmemory.h",
                                 a2: 736,
                                 a3: "Assertion Failed: m_pMemory") != 0) )
        {
          __debugbreak();
        }
      }
      CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F8B0
// Name: public: virtual bool CRenderSystemTestApp::AppUsesReadPixels(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRenderSystemTestApp::AppUsesReadPixels(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00411F70
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
// Address: 0x004125E0
// Name: public: int CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>>::InsertBefore(int,class KeyValues __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::InsertBefore(
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
// Address: 0x00414610
// Name: public: matrix3x4_t::matrix3x4_t(float,float,float,float,float,float,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__thiscall matrix3x4_t::matrix3x4_t(
        matrix3x4_t *this,
        float a2,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        float a10,
        float a11,
        float a12,
        float a13)
{
  this->m_flMatVal[0][0] = a2;
  this->m_flMatVal[0][1] = a3;
  this->m_flMatVal[0][2] = a4;
  this->m_flMatVal[0][3] = a5;
  this->m_flMatVal[1][0] = a6;
  this->m_flMatVal[1][1] = a7;
  this->m_flMatVal[1][2] = a8;
  this->m_flMatVal[1][3] = a9;
  this->m_flMatVal[2][0] = a10;
  this->m_flMatVal[2][1] = a11;
  this->m_flMatVal[2][2] = a12;
  this->m_flMatVal[2][3] = a13;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423D33
// Name: public: class DName const __near & Replicator::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
const DName *__thiscall Replicator::operator[](Replicator *this, unsigned int x)
{
  if ( x > 9 )
    return &this->ErrorDName;
  if ( this->index == -1 || (signed int)x > this->index )
    return &this->InvalidDName;
  return this->dNameBuffer[x];
}

//------------------------------------------------------------------------------
// Address: 0x00402A50
// Name: public: CAppSystemGroup::CAppSystemGroup(class CAppSystemGroup __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAppSystemGroup *__thiscall CAppSystemGroup::CAppSystemGroup(CAppSystemGroup *this, struct CAppSystemGroup *a2)
{
  IAppSystemGroup::IAppSystemGroup(this);
  this->__vftable = (CAppSystemGroup_vtbl *)&CAppSystemGroup::`vftable';
  CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>(
    this: (CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *)&this->m_Modules,
    a2: 0,
    a3: 0);
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>(
    this: &this->m_Systems,
    a2: 0,
    a3: 0);
  CUtlDict<int,unsigned short>::CUtlDict<int,unsigned short>(this: &this->m_SystemDict, a2: 0, a3: 0, a4: 16);
  this->m_pParentAppSystem = a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402AE0
// Name: public: IAppSystemGroup::IAppSystemGroup(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IAppSystemGroup *__thiscall IAppSystemGroup::IAppSystemGroup(IAppSystemGroup *this)
{
  this->__vftable = (IAppSystemGroup_vtbl *)&IAppSystemGroup::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402B20
// Name: private: virtual class CSysModule __near * CAppSystemGroup::LoadModuleDLL(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CAppSystemGroup::LoadModuleDLL(CAppSystemGroup *this, char *pModuleName)
{
  return Sys_LoadModule(pModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x00402B70
// Name: protected: int CAppSystemGroup::LoadModule(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CAppSystemGroup::LoadModule(CAppSystemGroup *this, char *str)
{
  int v2; // eax
  void *v3; // esp
  CAppSystemGroup::Module_t *v4; // eax
  CAppSystemGroup::Module_t *v6; // eax
  char *v7; // esi
  CAppSystemGroup::Module_t *v8; // eax
  char *v9; // [esp-8h] [ebp-130h]
  int v10; // [esp-4h] [ebp-12Ch]
  char v11[184]; // [esp+20h] [ebp-108h] BYREF
  _RTC_ALLOCA_NODE *pAllocaInfoList; // [esp+D8h] [ebp-50h]
  int v13; // [esp+E4h] [ebp-44h]
  int v14; // [esp+F0h] [ebp-38h]
  int i; // [esp+FCh] [ebp-2Ch]
  char *out; // [esp+108h] [ebp-20h]
  int outSize; // [esp+114h] [ebp-14h]
  CAppSystemGroup *v18; // [esp+120h] [ebp-8h]

  v18 = this;
  pAllocaInfoList = nullptr;
  v2 = _V_strlen(
         file: "u:\\main\\src\\appframework\\appsystemgroup.cpp",
         line: `CAppSystemGroup::LoadModule'::`2'::__LINE__Var + 2,
         str);
  outSize = v2 + 1;
  v3 = alloca(((v2 + 16) & 0xFFFFFFF0) + 36);
  out = v11;
  V_StripExtension(in: str, out: v11, outSize: v2 + 1);
  i = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: &v18->m_Modules.m_Memory.m_pMemory);
  while ( --i >= 0 )
  {
    if ( CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
           this: &v18->m_Modules,
           i)->m_pModuleName != nullptr )
    {
      v4 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
             this: &v18->m_Modules,
             i);
      if ( _V_stricmp(
             file: "u:\\main\\src\\appframework\\appsystemgroup.cpp",
             line: `CAppSystemGroup::LoadModule'::`2'::__LINE__Var + 11,
             s1: out,
             s2: v4->m_pModuleName) == 0 )
        return i;
    }
  }
  v14 = (int)v18->LoadModuleDLL(this: v18, a2: str);
  if ( v14 != 0 )
  {
    v13 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(this: (int *)&v18->m_Modules);
    v6 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
           this: &v18->m_Modules,
           i: v13);
    v6->m_pModule = (struct CSysModule *)v14;
    CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
      this: &v18->m_Modules,
      i: v13)->m_Factory = nullptr;
    v7 = (char *)_g_pMemAlloc->Alloc(
                   this: _g_pMemAlloc,
                   a2: outSize,
                   a3: "u:\\main\\src\\appframework\\appsystemgroup.cpp",
                   a4: `CAppSystemGroup::LoadModule'::`2'::__LINE__Var + 26);
    CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
      this: &v18->m_Modules,
      i: v13)->m_pModuleName = v7;
    v10 = outSize;
    v9 = out;
    v8 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
           this: &v18->m_Modules,
           i: v13);
    V_strncpy(pDest: v8->m_pModuleName, pSrc: v9, maxLen: v10);
    return v13;
  }
  else
  {
    _Warning(a1: "AppFramework : Unable to load module %s!\n", str);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402DB0
// Name: protected: int CAppSystemGroup::LoadModule(void __near * (*)(char const __near *,int __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CAppSystemGroup::LoadModule(CAppSystemGroup *this, void *(__cdecl *a2)(const char *, int *))
{
  int v3; // [esp+D0h] [ebp-20h]
  int i; // [esp+DCh] [ebp-14h]

  if ( a2 != nullptr )
  {
    i = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: &this->m_Modules.m_Memory.m_pMemory);
    while ( --i >= 0 )
    {
      if ( CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
             this: &this->m_Modules,
             i)->m_Factory != nullptr
        && CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
             this: &this->m_Modules,
             i)->m_Factory == a2 )
      {
        return i;
      }
    }
    v3 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(this: (int *)&this->m_Modules);
    CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
      this: &this->m_Modules,
      i: v3)->m_pModule = nullptr;
    CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
      this: &this->m_Modules,
      i: v3)->m_Factory = a2;
    CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
      this: &this->m_Modules,
      i: v3)->m_pModuleName = nullptr;
    return v3;
  }
  else
  {
    _Warning(a1: "AppFramework : Unable to load module %p!\n", nullptr);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402EB0
// Name: private: void CAppSystemGroup::UnloadAllModules(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CAppSystemGroup::UnloadAllModules(CAppSystemGroup *this)
{
  CAppSystemGroup::Module_t *v1; // eax
  CAppSystemGroup::Module_t *v2; // eax
  int i; // [esp+D0h] [ebp-14h]

  i = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: &this->m_Modules.m_Memory.m_pMemory);
  while ( --i >= 0 )
  {
    if ( CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
           this: &this->m_Modules,
           i)->m_pModule != nullptr )
    {
      v1 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
             this: &this->m_Modules,
             i);
      Sys_UnloadModule(pModule: v1->m_pModule);
    }
    if ( CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
           this: &this->m_Modules,
           i)->m_pModuleName != nullptr )
    {
      v2 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
             this: &this->m_Modules,
             i);
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->m_pModuleName);
    }
  }
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::RemoveAll(this: (CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *)&this->m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x00402F90
// Name: protected: class IAppSystem __near * CAppSystemGroup::AddSystem(int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct IAppSystem *__thiscall CAppSystemGroup::AddSystem(CAppSystemGroup *this, int i, char *buf)
{
  CAppSystemGroup::Module_t *v4; // eax
  void *(__cdecl *Factory)(const char *, int *); // [esp+Ch] [ebp-130h]
  int v6; // [esp+14h] [ebp-128h]
  CMemAllocAttributeAlloction v7; // [esp+E3h] [ebp-59h] BYREF
  int v8[3]; // [esp+ECh] [ebp-50h] BYREF
  int v9[3]; // [esp+F8h] [ebp-44h] BYREF
  int v10; // [esp+104h] [ebp-38h]
  _DWORD v11[6]; // [esp+110h] [ebp-2Ch] BYREF
  int v12; // [esp+128h] [ebp-14h]
  CAppSystemGroup *v13; // [esp+134h] [ebp-8h]

  v13 = this;
  if ( i == -1 )
    return nullptr;
  if ( i < 0
    || i >= CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: &v13->m_Modules.m_Memory.m_pMemory) )
  {
    __SpewInfo(
      a1: 2,
      a2: "u:\\main\\src\\appframework\\appsystemgroup.cpp",
      a3: `CAppSystemGroup::AddSystem'::`2'::__LINE__Var + 4);
    v12 = __SpewMessage(a1: "%s", "Assertion Failed: (module >= 0) && (module < m_Modules.Count())");
    if ( v12 == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\appframework\\appsystemgroup.cpp",
                             a2: `CAppSystemGroup::AddSystem'::`2'::__LINE__Var + 4,
                             a3: "Assertion Failed: (module >= 0) && (module < m_Modules.Count())") != 0) )
    {
      __debugbreak();
    }
  }
  if ( CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
         this: &v13->m_Modules,
         i)->m_pModule != nullptr )
  {
    v4 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
           this: &v13->m_Modules,
           i);
    Factory = Sys_GetFactory(pModule: v4->m_pModule);
  }
  else
  {
    Factory = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::operator[](
                this: &v13->m_Modules,
                i)->m_Factory;
  }
  v11[3] = Factory;
  v10 = (int)Factory(a1: buf, a2: v11);
  if ( v11[0] == 0 && v10 != 0 )
  {
    v9[0] = v10;
    v8[0] = CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::AddToTail(
              this: &v13->m_Systems,
              a2: (unsigned int)v9);
    CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(
      this: &v7,
      a2: "u:\\main\\src\\appframework\\appsystemgroup.cpp",
      a3: `CAppSystemGroup::AddSystem'::`2'::__LINE__Var + 19);
    CUtlDict<int,unsigned short>::Insert(this: &v13->m_SystemDict, buf, a3: (int)v8);
    v6 = v9[0];
    CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(this: &v7);
    return (struct IAppSystem *)v6;
  }
  else
  {
    _Warning(a1: "AppFramework : Unable to create system %s!\n", buf);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403220
// Name: public: CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMemAllocAttributeAlloction *__thiscall CMemAllocAttributeAlloction::CMemAllocAttributeAlloction(
        CMemAllocAttributeAlloction *this,
        const char *a2,
        int a3)
{
  _g_pMemAlloc->PushAllocDbgInfo(this: _g_pMemAlloc, a2, a3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403290
// Name: public: CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMemAllocAttributeAlloction::~CMemAllocAttributeAlloction(CMemAllocAttributeAlloction *this)
{
  _g_pMemAlloc->PopAllocDbgInfo(this: _g_pMemAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x004032F0
// Name: private: void CAppSystemGroup::ReportStartupFailure(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CAppSystemGroup::ReportStartupFailure(CAppSystemGroup *this, unsigned int a2, int a3)
{
  unsigned __int16 i[2]; // [esp+D0h] [ebp-2Ch]
  const char *ElementName; // [esp+DCh] [ebp-20h]
  const char *v5; // [esp+E8h] [ebp-14h]

  v5 = "Unknown";
  if ( a2 <= 8 )
    v5 = off_43E0DC[a2];
  ElementName = "(Unknown)";
  for ( *(_DWORD *)i = (unsigned __int16)CUtlDict<int,unsigned short>::First(this: &this->m_SystemDict.m_Elements);
        *(_DWORD *)i != CUtlDict<int,unsigned short>::InvalidIndex();
        *(_DWORD *)i = (unsigned __int16)CUtlDict<int,unsigned short>::Next(
                                           this: &this->m_SystemDict.m_Elements,
                                           i: i[0]) )
  {
    if ( *(_DWORD *)CUtlDict<int,unsigned short>::operator[](i: i[0]) == a3 )
    {
      ElementName = CUtlDict<int,unsigned short>::GetElementName(this: &this->m_SystemDict.m_Elements, i: i[0]);
      break;
    }
  }
  _Warning(a1: "System (%s) failed during stage %s\n", ElementName, v5);
}

//------------------------------------------------------------------------------
// Address: 0x004033E0
// Name: private: void CAppSystemGroup::RemoveAllSystems(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CAppSystemGroup::RemoveAllSystems(CAppSystemGroup *this)
{
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::RemoveAll(this: &this->m_Systems);
  CUtlDict<int,unsigned short>::RemoveAll(this: &this->m_SystemDict);
}

//------------------------------------------------------------------------------
// Address: 0x00403430
// Name: protected: bool CAppSystemGroup::AddSystems(struct AppSystemInfo_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall CAppSystemGroup::AddSystems(CAppSystemGroup *this, struct AppSystemInfo_t *a2)
{
  int i; // [esp+DCh] [ebp-14h]

  while ( *a2->m_pModuleName != 0 )
  {
    i = CAppSystemGroup::LoadModule(this, str: (char *)a2->m_pModuleName);
    if ( CAppSystemGroup::AddSystem(this, i, buf: (char *)a2->m_pInterfaceName) == nullptr )
    {
      _Warning(a1: "Unable to load interface %s from %s\n", a2->m_pInterfaceName, a2->m_pModuleName);
      return 0;
    }
    ++a2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004034E0
// Name: protected: void __near * CAppSystemGroup::FindSystem(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IAppSystem *__thiscall CAppSystemGroup::FindSystem(CAppSystemGroup *this, const char *a2)
{
  int *v2; // eax
  IAppSystem *v4; // [esp+Ch] [ebp-F4h]
  void *System; // [esp+D4h] [ebp-2Ch]
  int v6; // [esp+E0h] [ebp-20h]
  unsigned __int16 i; // [esp+ECh] [ebp-14h]
  unsigned __int16 ia; // [esp+ECh] [ebp-14h]

  i = CUtlDict<int,unsigned short>::Find(this: &this->m_SystemDict, (int)a2);
  if ( i == CUtlDict<int,unsigned short>::InvalidIndex() )
  {
    for ( ia = 0;
          ia < CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: &this->m_Systems.m_Memory.m_pMemory);
          ++ia )
    {
      v4 = *CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::operator[](this: &this->m_Systems, i: ia);
      v6 = (int)v4->QueryInterface(this: v4, a2);
      if ( v6 != 0 )
        return (IAppSystem *)v6;
    }
    if ( this->m_pParentAppSystem != nullptr
      && (System = CAppSystemGroup::FindSystem(this: this->m_pParentAppSystem, a2)) != nullptr )
    {
      return (IAppSystem *)System;
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    v2 = (int *)CUtlDict<int,unsigned short>::operator[](i);
    return *CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::operator[](this: &this->m_Systems, i: *v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403600
// Name: private: class CAppSystemGroup __near * CAppSystemGroup::GetParent(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct CAppSystemGroup *__thiscall CAppSystemGroup::GetParent(CAppSystemGroup *this)
{
  return this->m_pParentAppSystem;
}

//------------------------------------------------------------------------------
// Address: 0x00403630
// Name: private: bool CAppSystemGroup::ConnectSystems(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall CAppSystemGroup::ConnectSystems(CAppSystemGroup *this)
{
  void *(__cdecl *Factory)(const char *, int *); // eax
  IAppSystem *v3; // [esp+D0h] [ebp-20h]
  int i; // [esp+DCh] [ebp-14h]

  for ( i = 0;
        i < CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: &this->m_Systems.m_Memory.m_pMemory);
        ++i )
  {
    v3 = *CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::operator[](this: &this->m_Systems, i);
    Factory = CAppSystemGroup::GetFactory();
    if ( v3->Connect(this: v3, a2: (void *(__cdecl *)(const char *, int *))Factory) == 0 )
    {
      CAppSystemGroup::ReportStartupFailure(this, a2: 1u, a3: i);
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004036E0
// Name: private: void CAppSystemGroup::DisconnectSystems(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CAppSystemGroup::DisconnectSystems(CAppSystemGroup *this)
{
  IAppSystem *v1; // [esp+Ch] [ebp-DCh]
  int i; // [esp+D4h] [ebp-14h]

  i = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: &this->m_Systems.m_Memory.m_pMemory);
  while ( --i >= 0 )
  {
    v1 = *CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::operator[](this: &this->m_Systems, i);
    v1->Disconnect(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403770
// Name: private: enum InitReturnVal_t CAppSystemGroup::InitSystems(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CAppSystemGroup::InitSystems(CAppSystemGroup *this)
{
  IAppSystem *v2; // [esp+Ch] [ebp-E8h]
  int v3; // [esp+D4h] [ebp-20h]
  int i; // [esp+E0h] [ebp-14h]

  for ( i = 0;
        i < CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: &this->m_Systems.m_Memory.m_pMemory);
        ++i )
  {
    v2 = *CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::operator[](this: &this->m_Systems, i);
    v3 = v2->Init(this: v2);
    if ( v3 != 1 )
    {
      CAppSystemGroup::ReportStartupFailure(this, a2: 3u, a3: i);
      return v3;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403820
// Name: private: void CAppSystemGroup::ShutdownSystems(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CAppSystemGroup::ShutdownSystems(CAppSystemGroup *this)
{
  IAppSystem *v1; // [esp+Ch] [ebp-DCh]
  int i; // [esp+D4h] [ebp-14h]

  i = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: &this->m_Systems.m_Memory.m_pMemory);
  while ( --i >= 0 )
  {
    v1 = *CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::operator[](this: &this->m_Systems, i);
    v1->Shutdown(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004038B0
// Name: protected: virtual void __near * CAppSystemGroup::CreateAppWindow(void __near *,char const __near *,bool,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND __thiscall CAppSystemGroup::CreateAppWindow(
        CAppSystemGroup *this,
        HINSTANCE hInstance,
        LPCSTR lpWindowName,
        bool a4,
        LONG a5,
        LONG a6)
{
  int v7; // [esp+Ch] [ebp-150h]
  int v8; // [esp+Ch] [ebp-150h]
  int Y; // [esp+D4h] [ebp-88h]
  int X; // [esp+E0h] [ebp-7Ch]
  int Xa; // [esp+E0h] [ebp-7Ch]
  HWND hWnd; // [esp+ECh] [ebp-70h]
  struct tagRECT Rect; // [esp+F8h] [ebp-64h] BYREF
  DWORD dwStyle; // [esp+110h] [ebp-4Ch]
  WNDCLASSEXA dst; // [esp+11Ch] [ebp-40h] BYREF
  CAppSystemGroup *v16; // [esp+154h] [ebp-8h]

  v16 = this;
  memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
  dst.cbSize = 48;
  dst.style = 40;
  dst.lpfnWndProc = DefWindowProcA;
  dst.hInstance = hInstance;
  dst.lpszClassName = "Valve001";
  dst.hIcon = nullptr;
  dst.hIconSm = nullptr;
  RegisterClassExA(a1: &dst);
  dwStyle = -2080374784;
  if ( a4 )
    dwStyle = dwStyle & 0xFF30FFFF | 0xCB0000;
  dwStyle &= ~0x10000u;
  Rect.top = 0;
  Rect.left = 0;
  Rect.right = a5;
  Rect.bottom = a6;
  AdjustWindowRectEx(lpRect: &Rect, dwStyle, bMenu: false, dwExStyle: 0);
  hWnd = CreateWindowExA(
           dwExStyle: 0,
           lpClassName: dst.lpszClassName,
           lpWindowName,
           dwStyle,
           X: 0,
           Y: 0,
           nWidth: Rect.right - Rect.left,
           nHeight: Rect.bottom - Rect.top,
           hWndParent: nullptr,
           hMenu: nullptr,
           hInstance,
           lpParam: nullptr);
  if ( hWnd == nullptr )
    return nullptr;
  X = (GetSystemMetrics(nIndex: 0) - a5) / 2;
  Y = (GetSystemMetrics(nIndex: 1) - a6) / 2;
  if ( X >= 0 )
    v7 = X;
  else
    v7 = 0;
  Xa = v7;
  if ( Y >= 0 )
    v8 = Y;
  else
    v8 = 0;
  SetWindowPos(hWnd, hWndInsertAfter: nullptr, X: Xa, Y: v8, cx: 0, cy: 0, uFlags: 0x65u);
  return hWnd;
}

//------------------------------------------------------------------------------
// Address: 0x00403AE0
// Name: public: enum CAppSystemGroup::AppSystemGroupStage_t CAppSystemGroup::GetErrorStage(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
enum CAppSystemGroup::AppSystemGroupStage_t __thiscall CAppSystemGroup::GetErrorStage(CAppSystemGroup *this)
{
  return this->m_nErrorStage;
}

//------------------------------------------------------------------------------
// Address: 0x00403B10
// Name: void __near * AppSystemCreateInterfaceFn(char const __near *,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IAppSystem *__cdecl AppSystemCreateInterfaceFn(char *a1, int *a2)
{
  IAppSystem *System; // [esp+D0h] [ebp-8h]

  System = CAppSystemGroup::FindSystem(this: s_pCurrentAppSystem, a2: a1);
  if ( a2 != nullptr )
    *a2 = System == nullptr;
  return System;
}

//------------------------------------------------------------------------------
// Address: 0x00403B70
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static IAppSystem *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(char *a1, int *a2)
{
  return AppSystemCreateInterfaceFn;
}

//------------------------------------------------------------------------------
// Address: 0x00403BA0
// Name: public: int CAppSystemGroup::Run(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CAppSystemGroup::Run(CAppSystemGroup *this)
{
  int v2; // [esp+D0h] [ebp-14h]

  s_pCurrentAppSystem = this;
  v2 = CAppSystemGroup::OnStartup(this);
  if ( this->m_nErrorStage == NONE )
  {
    v2 = this->Main(this);
    CAppSystemGroup::OnShutdown(this);
    s_pCurrentAppSystem = CAppSystemGroup::GetParent(this);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00403C30
// Name: public: virtual int CAppSystemGroup::Startup(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CAppSystemGroup::Startup(CAppSystemGroup *this)
{
  return CAppSystemGroup::OnStartup(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403C70
// Name: public: virtual void CAppSystemGroup::Shutdown(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CAppSystemGroup::Shutdown(CAppSystemGroup *this)
{
  CAppSystemGroup::OnShutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403CB0
// Name: private: int CAppSystemGroup::OnStartup(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CAppSystemGroup::OnStartup(CAppSystemGroup *this)
{
  s_pCurrentAppSystem = this;
  this->m_nErrorStage = NONE;
  if ( this->Create(this) != 0 )
  {
    if ( CAppSystemGroup::ConnectSystems(this) != 0 )
    {
      if ( this->PreInit(this) )
      {
        if ( CAppSystemGroup::InitSystems(this) == 1 )
        {
          return 1;
        }
        else
        {
          this->m_nErrorStage = INITIALIZATION;
          return -1;
        }
      }
      else
      {
        this->m_nErrorStage = PREINITIALIZATION;
        return -1;
      }
    }
    else
    {
      this->m_nErrorStage = CONNECTION;
      return -1;
    }
  }
  else
  {
    this->m_nErrorStage = CREATION;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403DA0
// Name: private: void CAppSystemGroup::OnShutdown(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CAppSystemGroup::OnShutdown(CAppSystemGroup *this)
{
  s_pCurrentAppSystem = this;
  switch ( this->m_nErrorStage )
  {
    case CREATION:
    case CONNECTION:
      break;
    case PREINITIALIZATION:
    case INITIALIZATION:
      goto LABEL_3;
    default:
      CAppSystemGroup::ShutdownSystems(this);
      this->PostShutdown(this);
LABEL_3:
      CAppSystemGroup::DisconnectSystems(this);
      break;
  }
  CAppSystemGroup::RemoveAllSystems(this);
  _SpewOutputFunc(a1: g_DefaultSpewFunc);
  CAppSystemGroup::UnloadAllModules(this);
  this->Destroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403E80
// Name: public: CSteamAppSystemGroup::CSteamAppSystemGroup(class IFileSystem __near *,class CAppSystemGroup __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSteamAppSystemGroup *__thiscall CSteamAppSystemGroup::CSteamAppSystemGroup(
        CSteamAppSystemGroup *this,
        struct IFileSystem *a2,
        struct CAppSystemGroup *a3)
{
  CAppSystemGroup::CAppSystemGroup(this, a2: nullptr);
  this->__vftable = (CSteamAppSystemGroup_vtbl *)&CSteamAppSystemGroup::`vftable';
  this->m_pFileSystem = a2;
  this->m_pGameInfoPath[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403EE0
// Name: public: void CSteamAppSystemGroup::Setup(class IFileSystem __near *,class CAppSystemGroup __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSteamAppSystemGroup::Setup(
        CSteamAppSystemGroup *this,
        struct IFileSystem *a2,
        struct CAppSystemGroup *a3)
{
  this->m_pFileSystem = a2;
  this->m_pParentAppSystem = a3;
}

//------------------------------------------------------------------------------
// Address: 0x00403F20
// Name: private: virtual class CSysModule __near * CSteamAppSystemGroup::LoadModuleDLL(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CSteamAppSystemGroup::LoadModuleDLL(CSteamAppSystemGroup *this, const char *a2)
{
  return this->m_pFileSystem->LoadModule(this: this->m_pFileSystem, a2, a3: nullptr, a4: true);
}

//------------------------------------------------------------------------------
// Address: 0x004044C0
// Name: bool StringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl StringLessThan(const char *const *a1, const char *const *a2)
{
  int v2; // eax

  strcmp(str1: *(unsigned __int8 **)a1, str2: *(unsigned __int8 **)a2);
  return v2 < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404510
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **a1, const char **a2)
{
  return _stricmp(dst: *a1, src: *a2) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404560
// Name: bool CaselessStringLessThanIgnoreSlashes(char const __near * const __near &,char const __near * const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl CaselessStringLessThanIgnoreSlashes(const char *const *a1, const char *const *a2)
{
  char v3; // [esp+D3h] [ebp-29h]
  char v4; // [esp+DFh] [ebp-1Dh]
  char *i; // [esp+E8h] [ebp-14h]
  char *v6; // [esp+F4h] [ebp-8h]

  v6 = (char *)*a1;
  for ( i = (char *)*a2; *v6 != 0 && *i != 0; ++i )
  {
    v4 = *v6;
    v3 = *i;
    if ( *v6 == 47 || v4 == 92 )
    {
      if ( v3 != 47 && v3 != 92 )
        return v3 > 47;
    }
    else
    {
      if ( v4 >= 97 && v4 <= 122 )
        v4 -= 32;
      if ( v3 >= 97 && v3 <= 122 )
        v3 -= 32;
      if ( v4 > v3 )
        return 0;
      if ( v4 < v3 )
        return 1;
    }
    ++v6;
  }
  return *v6 != *i && *v6 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404850
// Name: char __near * MemAlloc_StrDup(char const __near *,char const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl MemAlloc_StrDup(char *buf, const char *a2, unsigned int a3)
{
  int v3; // eax
  unsigned __int8 *dst; // [esp+DCh] [ebp-8h]

  if ( buf != nullptr )
  {
    strlen((unsigned __int8 *)buf);
    dst = (unsigned __int8 *)_g_pMemAlloc->Alloc(this: _g_pMemAlloc, a2: v3 + 1, a3: a2, a4: a3);
    if ( dst != nullptr )
      strcpy(dst, src: (unsigned __int8 *)buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405BB0
// Name: void Construct<struct CAppSystemGroup::Module_t>(struct CAppSystemGroup::Module_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl Construct<CAppSystemGroup::Module_t>(void *a1)
{
  return operator new(a1: 0xCu, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x00405C00
// Name: void __near * operator new(unsigned int,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int a1, void *a2)
{
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x00405E90
// Name: void CopyConstruct<class IAppSystem __near *>(class IAppSystem __near * __near *,class IAppSystem __near * const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl CopyConstruct<IAppSystem *>(void *a1, int *a2)
{
  int *result; // eax
  int *v3; // [esp+14h] [ebp-C8h]

  result = (int *)operator new(a1: 4u, a2: a1);
  v3 = result;
  if ( result != nullptr )
  {
    result = (int *)*a2;
    *v3 = *a2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004064D0
// Name: void CopyConstruct<struct CUtlMap<char const __near *,int,unsigned short>::Node_t>(struct CUtlMap<char const __near *,int,unsigned short>::Node_t __near *,struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl CopyConstruct<CUtlMap<char const *,int,unsigned short>::Node_t>(void *a1, _DWORD *a2)
{
  _DWORD *result; // eax

  result = operator new(a1: 8u, a2: a1);
  if ( result != nullptr )
    return CUtlMap<char const *,int,unsigned short>::Node_t::Node_t(this: result, a2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406B70
// Name: int UtlMemory_CalcNewAllocationCount(int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl UtlMemory_CalcNewAllocationCount(int a1, int a2, int a3, int a4)
{
  if ( a2 != 0 )
    return a2 * ((a3 - 1) / a2 + 1);
  if ( a1 == 0 )
    a1 = (a4 + 31) / a4;
  while ( a1 < a3 )
    a1 *= 2;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00408060
// Name: void Construct<struct CUtlMap<char const __near *,int,unsigned short>::Node_t>(struct CUtlMap<char const __near *,int,unsigned short>::Node_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl Construct<CUtlMap<char const *,int,unsigned short>::Node_t>(void *a1)
{
  void *result; // eax

  result = operator new(a1: 8u, a2: a1);
  if ( result != nullptr )
    return CUtlMap<char const *,int,unsigned short>::Node_t::Node_t(this: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004085A0
// Name: enum SpewRetval_t WinAppDefaultSpewFunc(enum SpewType_t,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl WinAppDefaultSpewFunc(enum SpewType_t a1, const char *a2)
{
  _Plat_DebugString(a1: a2);
  return a1 >= SPEW_MESSAGE && (a1 <= SPEW_WARNING || a1 == SPEW_LOG);
}

//------------------------------------------------------------------------------
// Address: 0x00408620
// Name: void __near * GetAppInstance(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HINSTANCE __cdecl GetAppInstance()
{
  return s_HInstance;
}

//------------------------------------------------------------------------------
// Address: 0x00408650
// Name: int AppMain(void __near *,void __near *,char const __near *,int,class CAppSystemGroup __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AppMain(HINSTANCE a1, void *a2, const char *a3, int a4, CAppSystemGroup *a5)
{
  LPSTR CommandLineA; // eax
  int v7; // [esp+Ch] [ebp-D0h]

  if ( a5 == nullptr )
  {
    __SpewInfo(a1: 2, a2: "u:\\main\\src\\appframework\\winapp.cpp", a3: `AppMain'::`2'::__LINE__Var + 1);
    if ( __SpewMessage(a1: "%s", "Assertion Failed: pAppSystemGroup") == 0
      && ((unsigned __int8)_ShouldUseNewAssertDialog() == 0
       || (unsigned __int8)_DoNewAssertDialog(
                             a1: "u:\\main\\src\\appframework\\winapp.cpp",
                             a2: `AppMain'::`2'::__LINE__Var + 1,
                             a3: "Assertion Failed: pAppSystemGroup") != 0) )
    {
      __debugbreak();
    }
  }
  g_DefaultSpewFunc = (enum SpewRetval_t (__cdecl *)(enum SpewType_t, const char *))WinAppDefaultSpewFunc;
  s_HInstance = a1;
  v7 = _CommandLine();
  CommandLineA = GetCommandLineA();
  (*(void (__thiscall **)(int, LPSTR))(*(_DWORD *)v7 + 4))(a1: v7, a2: CommandLineA);
  return CAppSystemGroup::Run(this: a5);
}

//------------------------------------------------------------------------------
// Address: 0x004087A0
// Name: public: CSteamApplication::CSteamApplication(class CSteamAppSystemGroup __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSteamApplication *__thiscall CSteamApplication::CSteamApplication(
        CSteamApplication *this,
        struct CSteamAppSystemGroup *a2)
{
  CAppSystemGroup::CAppSystemGroup(this, a2: nullptr);
  this->__vftable = (CSteamApplication_vtbl *)&CSteamApplication::`vftable';
  this->m_pChildAppSystemGroup = a2;
  this->m_pFileSystem = nullptr;
  this->m_bSteam = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408810
// Name: public: virtual bool CSteamApplication::Create(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall CSteamApplication::Create(CSteamApplication *this)
{
  void *(__cdecl *ICVarFactory)(const char *, int *); // eax
  struct IAppSystem *v3; // eax
  int Module; // [esp+D0h] [ebp-12Ch]
  int i; // [esp+DCh] [ebp-120h]
  char v6[268]; // [esp+E8h] [ebp-114h] BYREF
  CAppSystemGroup *v7; // [esp+1F4h] [ebp-8h]

  v7 = this;
  FileSystem_SetErrorMode(a1: FS_ERRORMODE_AUTO);
  if ( FileSystem_GetFileSystemDLLName(pDest: v6, maxLen: 260, a3: &v7[1].m_Modules.m_Memory.m_nAllocationCount) != 0 )
    return 0;
  FileSystem_SetupSteamInstallPath();
  ICVarFactory = (void *(__cdecl *)(const char *, int *))_VStdLib_GetICVarFactory();
  i = CAppSystemGroup::LoadModule(this: v7, a2: ICVarFactory);
  CAppSystemGroup::AddSystem(this: v7, i, buf: "VEngineCvar007");
  Module = CAppSystemGroup::LoadModule(this: v7, str: v6);
  v3 = CAppSystemGroup::AddSystem(this: v7, i: Module, buf: "VFileSystem017");
  v7[1].__vftable = (CAppSystemGroup_vtbl *)v3;
  if ( v7[1].__vftable != nullptr )
    return 1;
  _Error(a1: "Unable to load %s", v6);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408A20
// Name: public: virtual int CSteamApplication::Startup(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CSteamApplication::Startup(CSteamApplication *this)
{
  int v2; // [esp+D0h] [ebp-14h]

  v2 = CAppSystemGroup::Startup(this);
  if ( CAppSystemGroup::GetErrorStage(this) != NONE )
    return v2;
  if ( FileSystem_SetBasePaths(a1: this->m_pFileSystem) != 0 )
    return 0;
  CSteamAppSystemGroup::Setup(this: this->m_pChildAppSystemGroup, a2: this->m_pFileSystem, a3: this);
  return this->m_pChildAppSystemGroup->Startup(this: this->m_pChildAppSystemGroup);
}

//------------------------------------------------------------------------------
// Address: 0x00408AC0
// Name: public: virtual void CSteamApplication::Shutdown(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSteamApplication::Shutdown(CSteamApplication *this)
{
  this->m_pChildAppSystemGroup->Shutdown(this: this->m_pChildAppSystemGroup);
  CAppSystemGroup::Shutdown(this);
}

//------------------------------------------------------------------------------
// Address: 0x00408B20
// Name: void Q_getwd(char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl Q_getwd(char *pnbuf, int maxlen)
{
  _getcwd(pnbuf, maxlen);
  V_strncat(pDest: pnbuf, pSrc: "\\", destBufferSize: maxlen, max_chars_to_copy: -1);
  V_FixSlashes(pname: pnbuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x00408B90
// Name: public: CFSSearchPathsInit::CFSSearchPathsInit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFSSearchPathsInit *__thiscall CFSSearchPathsInit::CFSSearchPathsInit(CFSSearchPathsInit *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_BYTE *)this + 12) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408BE0
// Name: public: CFSSteamSetupInfo::CFSSteamSetupInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFSSteamSetupInfo *__thiscall CFSSteamSetupInfo::CFSSteamSetupInfo(CFSSteamSetupInfo *this)
{
  *(_DWORD *)this = 0;
  *((_BYTE *)this + 4) = 0;
  *((_BYTE *)this + 7) = 0;
  *((_BYTE *)this + 5) = 1;
  *((_BYTE *)this + 8) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408C40
// Name: public: CFSMountContentInfo::CFSMountContentInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFSMountContentInfo *__thiscall CFSMountContentInfo::CFSMountContentInfo(CFSMountContentInfo *this)
{
  *(_BYTE *)this = 1;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408C90
// Name: void AddLanguageGameDir(class IFileSystem __near *,char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl AddLanguageGameDir(struct IFileSystem *a1, char *pSrc, const char *a3)
{
  const char *v3; // [esp+D0h] [ebp-22Ch]
  char *v4; // [esp+DCh] [ebp-220h]
  char s1[268]; // [esp+E8h] [ebp-214h] BYREF
  char pDest[264]; // [esp+1F4h] [ebp-108h] BYREF

  V_snprintf(pDest, maxLen: 260, pFormat: "%s_%s", pSrc, a3);
  a1->AddSearchPath(this: a1, a2: pDest, a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( !a1->IsSteam(this: a1) )
  {
    V_strncpy(pDest: s1, pSrc, maxLen: 260);
    v4 = _V_strstr(
           file: "u:\\main\\src\\public\\filesystem_init.cpp",
           line: `AddLanguageGameDir'::`2'::__LINE__Var + 13,
           s1,
           search: "\\game\\");
    if ( v4 != nullptr )
    {
      v3 = &v4[_V_strlen(
                 file: "u:\\main\\src\\public\\filesystem_init.cpp",
                 line: `AddLanguageGameDir'::`2'::__LINE__Var + 17,
                 str: "\\game\\")];
      *v4 = 0;
      V_snprintf(pDest, maxLen: 260, pFormat: "%s%clocalization%c%s_%s", s1, 92, 92, v3, a3);
      a1->AddSearchPath(this: a1, a2: pDest, a3: "GAME", a4: PATH_ADD_TO_TAIL);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408E60
// Name: void AddGameBinDir(class IFileSystem __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl AddGameBinDir(struct IFileSystem *a1, const char *a2)
{
  char pDest[264]; // [esp+D0h] [ebp-108h] BYREF

  V_snprintf(pDest, maxLen: 260, pFormat: "%s%cbin", a2, 92);
  a1->AddSearchPath(this: a1, a2: pDest, a3: "GAMEBIN", a4: PATH_ADD_TO_TAIL);
}

//------------------------------------------------------------------------------
// Address: 0x00408F10
// Name: class KeyValues __near * ReadKeyValuesFile(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct KeyValues *__cdecl ReadKeyValuesFile(char *file)
{
  int v2; // eax
  void *v3; // eax
  int v4; // eax
  const char *v5; // eax
  unsigned int v6; // [esp-8h] [ebp-130h]
  _iobuf *v7; // [esp-4h] [ebp-12Ch]
  KeyValues *v8; // [esp+Ch] [ebp-11Ch]
  KeyValues *v9; // [esp+14h] [ebp-114h]
  _DWORD v10[7]; // [esp+104h] [ebp-24h] BYREF
  _iobuf *stream; // [esp+120h] [ebp-8h]

  stream = fopen(file, mode: "rb");
  if ( stream == nullptr )
    return nullptr;
  CUtlVector<char,CUtlMemory<char,int>>::CUtlVector<char,CUtlMemory<char,int>>(this: v10, a2: 0, a3: 0);
  fseek(stream, offset: 0, whence: 2);
  v2 = ftell(stream);
  CUtlVector<char,CUtlMemory<char,int>>::SetSize(a1: v2 + 1);
  fseek(stream, offset: 0, whence: 0);
  v7 = stream;
  v6 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: v10) - 1;
  v3 = (void *)CUtlVector<char,CUtlMemory<char,int>>::Base(this: v10);
  fread(buffer: v3, elementSize: 1u, count: v6, stream: v7);
  fclose(stream);
  v4 = CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::Count(this: v10);
  *(_BYTE *)CUtlVector<char,CUtlMemory<char,int>>::Element(a1: v4 - 1) = 0;
  v9 = (KeyValues *)KeyValues::operator new(
                      iAllocSize: 0x20u,
                      nBlockUse: 1,
                      pFileName: "u:\\main\\src\\public\\filesystem_init.cpp",
                      nLine: `ReadKeyValuesFile'::`2'::__LINE__Var + 13);
  if ( v9 != nullptr )
    v8 = KeyValues::KeyValues(this: v9, setName: defaultValue);
  else
    v8 = nullptr;
  v5 = (const char *)CUtlVector<char,CUtlMemory<char,int>>::Base(this: v10);
  if ( KeyValues::LoadFromBuffer(this: v8, resourceName: file, pBuffer: v5, pFileSystem: nullptr, pPathID: nullptr) )
  {
    CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: v10);
    return v8;
  }
  else
  {
    KeyValues::deleteThis(this: v8);
    CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: v10);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004090D0
// Name: bool FileSystem_GetExecutableDir(char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl FileSystem_GetExecutableDir(char *pDest, int maxLen)
{
  char pOut; // [esp+D4h] [ebp-114h] BYREF
  char s1[267]; // [esp+D5h] [ebp-113h] BYREF
  char *VProjectCmdLineValue; // [esp+1E0h] [ebp-8h]

  *pDest = 0;
  if ( byte_440818 != 0 )
  {
    VProjectCmdLineValue = (char *)GetVProjectCmdLineValue();
    if ( VProjectCmdLineValue == nullptr )
      VProjectCmdLineValue = getenv(option: "VProject");
    if ( VProjectCmdLineValue != nullptr )
    {
      V_snprintf(pDest, maxLen, pFormat: "%s%c..%cbin", VProjectCmdLineValue, 92, 92);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else if ( (unsigned __int8)sub_4092D0(lpFilename: pDest, nSize: maxLen) != 0 )
  {
    V_StripFilename(path: pDest);
    V_FixSlashes(pname: pDest, separator: 92);
    V_StrRight(pStr: pDest, nChars: 4, &pOut, outSize: 260);
    if ( pOut != 92
      || _V_stricmp(
           file: "u:\\main\\src\\public\\filesystem_init.cpp",
           line: `FileSystem_GetExecutableDir'::`2'::__LINE__Var + 39,
           s1,
           s2: "bin") != 0 )
    {
      V_strncat(pDest, pSrc: "\\bin", destBufferSize: maxLen, max_chars_to_copy: -1);
      V_FixSlashes(pname: pDest, separator: 92);
    }
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004092D0
// Name: sub_4092D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl sub_4092D0(LPSTR lpFilename, DWORD nSize)
{
  HMODULE ModuleHandleA; // eax

  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  return GetModuleFileNameA(hModule: ModuleHandleA, lpFilename, nSize) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409340
// Name: void LaunchVConfig(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl LaunchVConfig()
{
  char *argv[5]; // [esp+D0h] [ebp-11Ch] BYREF
  char pStr[264]; // [esp+E4h] [ebp-108h] BYREF

  FileSystem_GetExecutableDir(pDest: pStr, maxLen: 260);
  V_AppendSlash(pStr, strSize: 260);
  V_strncat(pDest: pStr, pSrc: "vconfig.exe", destBufferSize: 0x104u, max_chars_to_copy: -1);
  argv[0] = pStr;
  argv[1] = "-allowdebug";
  argv[2] = nullptr;
  _spawnv(modeflag: 1, pathname: pStr, (const char *const *)argv);
}

//------------------------------------------------------------------------------
// Address: 0x00409430
// Name: char const __near * GetVProjectCmdLineValue(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl GetVProjectCmdLineValue()
{
  int v0; // eax
  int v2; // [esp+Ch] [ebp-C8h]
  int v3; // [esp+10h] [ebp-C4h]

  v3 = _CommandLine();
  v2 = _CommandLine();
  v0 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 32))(a1: v3, a2: "-game", a3: 0);
  return (*(const char *(__thiscall **)(int, const char *, int))(*(_DWORD *)v2 + 32))(a1: v2, a2: "-vproject", a3: v0);
}

//------------------------------------------------------------------------------
// Address: 0x004094E0
// Name: enum FSReturnCode_t SetupFileSystemError(bool,enum FSReturnCode_t,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int SetupFileSystemError(char a1, int a2, char *pFormat, ...)
{
  int v4; // [esp+Ch] [ebp-D0h]
  va_list va; // [esp+F0h] [ebp+14h] BYREF

  va_start(va, pFormat);
  V_vsnprintf(pDest: pDest, maxLen: 256, pFormat, params: va);
  _Warning(a1: "%s\n", pDest);
  if ( a1 != 0 && dword_43E344 == 1 )
  {
    v4 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-NoVConfig") == 0
      && GetVProjectCmdLineValue() == nullptr )
    {
      LaunchVConfig();
    }
  }
  if ( (unsigned int)dword_43E344 <= 1 )
    _Error(a1: "%s\n", pDest);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x004095E0
// Name: enum FSReturnCode_t LoadGameInfoFile(char const __near *,class KeyValues __near * __near &,class KeyValues __near * __near &,class KeyValues __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl LoadGameInfoFile(char *pSrc, KeyValues **a2, KeyValues **a3, _DWORD *a4)
{
  char pDest[264]; // [esp+D0h] [ebp-108h] BYREF

  V_strncpy(pDest, pSrc, maxLen: 260);
  V_AppendSlash(pStr: pDest, strSize: 260);
  V_strncat(pDest, pSrc: "gameinfo.txt", destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_FixSlashes(pname: pDest, separator: 92);
  *a2 = ReadKeyValuesFile(file: pDest);
  if ( *a2 == nullptr )
    return SetupFileSystemError(a1: 1, a2: 1, pFormat: "%s is missing.", pDest);
  *a3 = KeyValues::FindKey(this: *a2, keyName: "FileSystem", bCreate: false);
  if ( *a3 != nullptr )
  {
    *a4 = KeyValues::FindKey(this: *a3, keyName: "SearchPaths", bCreate: false);
    if ( *a4 != 0 )
      return 0;
  }
  KeyValues::deleteThis(this: *a2);
  return SetupFileSystemError(a1: 1, a2: 2, pFormat: "%s is not a valid format.", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x004097E0
// Name: bool IsLowViolenceBuild(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl IsLowViolenceBuild()
{
  int v1; // [esp+Ch] [ebp-130h]
  bool v2; // [esp+D7h] [ebp-65h]
  unsigned int cbData[3]; // [esp+E0h] [ebp-5Ch] BYREF
  unsigned __int8 Data[72]; // [esp+ECh] [ebp-50h] BYREF
  HKEY__ *phkResult; // [esp+134h] [ebp-8h] BYREF

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-lv") != 0 )
    return 1;
  cbData[0] = 63;
  v2 = false;
  if ( RegOpenKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: "Software\\Valve\\Source\\Settings",
         ulOptions: 0,
         samDesired: 0x20019u,
         &phkResult) == 0 )
  {
    if ( RegQueryValueExA(
           hKey: phkResult,
           lpValueName: "User Token 2",
           lpReserved: nullptr,
           lpType: nullptr,
           lpData: Data,
           lpcbData: cbData) == 0 )
      v2 = _V_strlen(
             file: "u:\\main\\src\\public\\filesystem_init.cpp",
             line: `IsLowViolenceBuild'::`2'::__LINE__Var + 21,
             str: (const char *)Data) > 0;
    if ( !v2 )
    {
      cbData[0] = 63;
      if ( RegQueryValueExA(
             hKey: phkResult,
             lpValueName: "User Token 3",
             lpReserved: nullptr,
             lpType: nullptr,
             lpData: Data,
             lpcbData: cbData) == 0 )
        v2 = _V_strlen(
               file: "u:\\main\\src\\public\\filesystem_init.cpp",
               line: `IsLowViolenceBuild'::`2'::__LINE__Var + 35,
               str: (const char *)Data) > 0;
    }
    RegCloseKey(hKey: phkResult);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004099B0
// Name: bool FileSystem_IsHldsUpdateToolDedicatedServer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl FileSystem_IsHldsUpdateToolDedicatedServer()
{
  char *s1; // [esp+D4h] [ebp-114h]
  char pname[264]; // [esp+E0h] [ebp-108h] BYREF

  if ( (unsigned __int8)sub_409AC0(path: pname, maxLen: 260) == 0 )
    return false;
  V_FixSlashes(pname, separator: 92);
  V_StripTrailingSlash(ppath: pname);
  s1 = (char *)V_UnqualifiedFileName(in: pname);
  return s1 != nullptr
      && _V_stricmp(
           file: "u:\\main\\src\\public\\filesystem_init.cpp",
           line: `FileSystem_IsHldsUpdateToolDedicatedServer'::`2'::__LINE__Var + 10,
           s1,
           s2: "orangebox") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409AC0
// Name: sub_409AC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_409AC0(char *path, int maxLen)
{
  if ( FileSystem_GetExecutableDir(pDest: path, maxLen) == 0 )
    return 0;
  V_StripFilename(path);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409B20
// Name: enum FSReturnCode_t FileSystem_LoadSearchPaths(class CFSSearchPathsInit __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl FileSystem_LoadSearchPaths(int a1)
{
  char *v2; // eax
  int v3; // eax
  char *v4; // eax
  int v5; // eax
  void *v6; // esp
  char *cbSize; // [esp+10h] [ebp-5C0h]
  _BYTE v8[184]; // [esp+20h] [ebp-5B0h] BYREF
  _RTC_ALLOCA_NODE *pAllocaInfoList; // [esp+D8h] [ebp-4F8h]
  char dest[268]; // [esp+E4h] [ebp-4ECh] BYREF
  char pRelativePath[268]; // [esp+1F0h] [ebp-3E0h] BYREF
  char *pFullPath; // [esp+2FCh] [ebp-2D4h]
  char *v13; // [esp+308h] [ebp-2C8h]
  char *ppath; // [esp+314h] [ebp-2BCh]
  char *v15; // [esp+320h] [ebp-2B0h]
  int v16; // [esp+32Ch] [ebp-2A4h]
  char *path; // [esp+338h] [ebp-298h]
  char *pDirectory; // [esp+344h] [ebp-28Ch]
  char pDest[268]; // [esp+350h] [ebp-280h] BYREF
  char *pStr; // [esp+45Ch] [ebp-174h]
  char *s1; // [esp+468h] [ebp-168h]
  KeyValues *i; // [esp+474h] [ebp-15Ch]
  _BYTE v23[12]; // [esp+483h] [ebp-14Dh] BYREF
  char v24; // [esp+48Fh] [ebp-141h]
  char pStartingDir[268]; // [esp+498h] [ebp-138h] BYREF
  int v26; // [esp+5A4h] [ebp-2Ch]
  KeyValues *v27; // [esp+5B0h] [ebp-20h] BYREF
  KeyValues *v28; // [esp+5BCh] [ebp-14h] BYREF
  KeyValues *v29; // [esp+5C8h] [ebp-8h] BYREF

  pAllocaInfoList = nullptr;
  if ( *(_DWORD *)(a1 + 8) == 0 || *(_DWORD *)a1 == 0 )
    return SetupFileSystemError(a1: 0, a2: 3, pFormat: "FileSystem_LoadSearchPaths: Invalid parameters specified.");
  v26 = LoadGameInfoFile(pSrc: *(char **)a1, a2: &v29, a3: &v28, a4: &v27);
  if ( v26 != 0 )
    return v26;
  if ( sub_409AC0(path: pStartingDir, maxLen: 260) == 0 )
    return SetupFileSystemError(a1: 0, a2: 3, pFormat: "FileSystem_GetBaseDir failed.");
  *(_BYTE *)(a1 + 12) = 0;
  v24 = IsLowViolenceBuild();
  v23[0] = 1;
  for ( i = KeyValues::GetFirstValue(this: v27); i != nullptr; i = KeyValues::GetNextValue(this: i) )
  {
    s1 = (char *)KeyValues::GetName(this: i);
    pStr = (char *)KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v2 = (char *)V_stristr(pStr, pSearch: "|gameinfo_path|");
    if ( v2 == pStr )
    {
      strlen(buf: "|gameinfo_path|");
      pStr += v3;
      sub_40A200(a1, s1, a3: (int)v23, pStartingDir: *(char **)a1, pPath: pStr, a6: v24);
    }
    else
    {
      v4 = (char *)V_stristr(pStr, pSearch: "|all_source_engine_paths|");
      if ( v4 == pStr )
      {
        strlen(buf: "|all_source_engine_paths|");
        pStr += v5;
        sub_40A200(a1, s1, a3: (int)v23, pStartingDir, pPath: pStr, a6: v24);
        if ( FileSystem_IsHldsUpdateToolDedicatedServer() )
        {
          V_snprintf(pDest, maxLen: 260, pFormat: "..%c%s", 92, pStr);
          sub_40A200(a1, s1, a3: (int)v23, pStartingDir, pPath: pDest, a6: v24);
        }
      }
      else
      {
        sub_40A200(a1, s1, a3: (int)v23, pStartingDir, pPath: pStr, a6: v24);
      }
    }
  }
  KeyValues::deleteThis(this: v29);
  pDirectory = getenv(option: "VGame");
  path = getenv(option: "VContent");
  if ( pDirectory != nullptr && path != nullptr )
  {
    v16 = (*(int (__thiscall **)(_DWORD, const char *, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(a1 + 8) + 52))(
            a1: *(_DWORD *)(a1 + 8),
            a2: "GAME",
            a3: 0,
            a4: 0,
            a5: 0);
    v6 = alloca(((v16 + 15) & 0xFFFFFFF0) + 36);
    v15 = v8;
    (*(void (__thiscall **)(_DWORD, const char *, _DWORD, _BYTE *, int))(**(_DWORD **)(a1 + 8) + 52))(
      a1: *(_DWORD *)(a1 + 8),
      a2: "GAME",
      a3: 0,
      a4: v8,
      a5: v16);
    ppath = v15;
    while ( ppath != nullptr )
    {
      v13 = strchr(string: ppath, chr: 0x3Bu);
      if ( v13 != nullptr )
        *v13 = 0;
      V_StripTrailingSlash(ppath);
      V_FixSlashes(pname: ppath, separator: 92);
      pFullPath = ppath;
      if ( v13 != nullptr )
        cbSize = v13 + 1;
      else
        cbSize = nullptr;
      ppath = cbSize;
      if ( V_MakeRelativePath(pFullPath, pDirectory, pRelativePath, nBufLen: 260) )
      {
        V_ComposeFileName(path, filename: pRelativePath, dest, destSize: 260);
        (*(void (__thiscall **)(_DWORD, char *, const char *, int))(**(_DWORD **)(a1 + 8) + 28))(
          a1: *(_DWORD *)(a1 + 8),
          a2: dest,
          a3: "CONTENT",
          a4: 1);
      }
    }
  }
  (*(void (__thiscall **)(_DWORD, const char *, int))(**(_DWORD **)(a1 + 8) + 44))(
    a1: *(_DWORD *)(a1 + 8),
    a2: "content",
    a3: 1);
  (*(void (__thiscall **)(_DWORD, const char *, int))(**(_DWORD **)(a1 + 8) + 44))(
    a1: *(_DWORD *)(a1 + 8),
    a2: "executable_path",
    a3: 1);
  (*(void (__thiscall **)(_DWORD, const char *, int))(**(_DWORD **)(a1 + 8) + 44))(
    a1: *(_DWORD *)(a1 + 8),
    a2: "gamebin",
    a3: 1);
  (*(void (__thiscall **)(_DWORD, const char *, int))(**(_DWORD **)(a1 + 8) + 44))(
    a1: *(_DWORD *)(a1 + 8),
    a2: "mod",
    a3: 1);
  if ( *(_BYTE *)(a1 + 12) != 0 )
    (*(void (__thiscall **)(_DWORD, int, const char *, int))(**(_DWORD **)(a1 + 8) + 28))(
      a1: *(_DWORD *)(a1 + 8),
      a2: a1 + 12,
      a3: "DEFAULT_WRITE_PATH",
      a4: 1);
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 8) + 244))(a1: *(_DWORD *)(a1 + 8));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A1B0
// Name: char __near * strchr(char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strchr(char *string, unsigned __int8 chr)
{
  strchr((unsigned __int8 *)string, chr);
}

//------------------------------------------------------------------------------
// Address: 0x0040A200
// Name: sub_40A200
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_40A200(int a1, char *s1, _BYTE *a3, char *pStartingDir, char *pPath, char a6)
{
  int v7; // [esp+Ch] [ebp-3F4h]
  char v8[268]; // [esp+D4h] [ebp-32Ch] BYREF
  char pDest[271]; // [esp+1E0h] [ebp-220h] BYREF
  char v10; // [esp+2EFh] [ebp-111h]
  char pOut[264]; // [esp+2F8h] [ebp-108h] BYREF

  V_MakeAbsolutePath(pOut, outLen: 260, pPath, pStartingDir);
  V_FixSlashes(pname: pOut, separator: 92);
  if ( !V_RemoveDotSlashes(pFilename: pOut, separator: 92) )
    _Error(a1: "FileSystem_AddLoadedSearchPath - Can't resolve pathname for '%s'", pOut);
  if ( _V_stricmp(
         file: "u:\\main\\src\\public\\filesystem_init.cpp",
         line: `FileSystem_AddLoadedSearchPath'::`2'::__LINE__Var + 10,
         s1,
         s2: "game") == 0 )
  {
    v10 = 1;
    if ( a6 != 0 )
    {
      V_snprintf(pDest, maxLen: 260, pFormat: "%s_lv", pOut);
      (*(void (__thiscall **)(_DWORD, char *, char *, int))(**(_DWORD **)(a1 + 8) + 28))(
        a1: *(_DWORD *)(a1 + 8),
        a2: pDest,
        a3: s1,
        a4: 1);
    }
    if ( *(_DWORD *)(a1 + 4) != 0 && v10 != 0 )
      AddLanguageGameDir(a1: *(struct IFileSystem **)(a1 + 8), pSrc: pOut, a3: *(const char **)(a1 + 4));
    v7 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-tempcontent") != 0 && v10 != 0 )
    {
      V_snprintf(pDest: v8, maxLen: 260, pFormat: "%s_tempcontent", pOut);
      (*(void (__thiscall **)(_DWORD, char *, char *, int))(**(_DWORD **)(a1 + 8) + 28))(
        a1: *(_DWORD *)(a1 + 8),
        a2: v8,
        a3: s1,
        a4: 1);
    }
    if ( *a3 != 0 )
    {
      *a3 = 0;
      (*(void (__thiscall **)(_DWORD, char *, const char *, int))(**(_DWORD **)(a1 + 8) + 28))(
        a1: *(_DWORD *)(a1 + 8),
        a2: pOut,
        a3: "MOD",
        a4: 1);
      V_strncpy(pDest: (char *)(a1 + 12), pSrc: pOut, maxLen: 512);
    }
    if ( v10 != 0 )
      AddGameBinDir(a1: *(struct IFileSystem **)(a1 + 8), a2: pOut);
  }
  return (*(int (__thiscall **)(_DWORD, char *, char *, int))(**(_DWORD **)(a1 + 8) + 28))(
           a1: *(_DWORD *)(a1 + 8),
           a2: pOut,
           a3: s1,
           a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0040A4E0
// Name: bool DoesFileExistIn(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl DoesFileExistIn(char *pSrc, char *a2)
{
  char pDest[264]; // [esp+DCh] [ebp-108h] BYREF

  V_strncpy(pDest, pSrc, maxLen: 260);
  V_AppendSlash(pStr: pDest, strSize: 260);
  V_strncat(pDest, pSrc: a2, destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_FixSlashes(pname: pDest, separator: 92);
  return _access(path: pDest, amode: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A5F0
// Name: enum FSReturnCode_t LocateGameInfoFile(class CFSSteamSetupInfo const __near &,char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl LocateGameInfoFile(const char **a1, char *pDest, int maxLen)
{
  _anonymous_namespace_ *v4; // [esp+0h] [ebp-318h]
  unsigned __int8 (__cdecl *v5)(const char **, char *, int, char *); // [esp+D4h] [ebp-244h]
  char v6[9]; // [esp+E3h] [ebp-235h] BYREF
  char *pPath; // [esp+1F8h] [ebp-120h]

  if ( *((_BYTE *)a1 + 4) == 0 )
  {
    pPath = (char *)GetVProjectCmdLineValue();
    if ( pPath != nullptr )
    {
      if ( DoesFileExistIn(pSrc: pPath, a2: "gameinfo.txt") )
      {
        V_MakeAbsolutePath(pOut: pDest, outLen: maxLen, pPath, pStartingDir: nullptr);
        return 0;
      }
      if ( *((_BYTE *)a1 + 8) != 0 )
        goto LABEL_11;
    }
    else
    {
      if ( *((_BYTE *)a1 + 8) != 0 )
      {
LABEL_11:
        V_strncpy(pDest, pSrc: defaultValue, maxLen);
        return 0;
      }
      v6[0] = 1;
      v5 = (unsigned __int8 (__cdecl *)(const char **, char *, int, char *))*`anonymous namespace'::GetSuggestGameInfoDirFn(this: v4);
      if ( v5 != nullptr
        && v5(a1, a2: pDest, a3: maxLen, a4: v6) != 0
        && sub_40AB50(pSrc: pDest, nSize: maxLen, a3: v6[0]) == 0 )
      {
        return 0;
      }
      pPath = getenv(option: "VProject");
      if ( pPath != nullptr )
      {
        V_MakeAbsolutePath(pOut: pDest, outLen: maxLen, pPath, pStartingDir: nullptr);
        if ( sub_40AB50(pSrc: pDest, nSize: maxLen, a3: 0) == 0 )
          return 0;
      }
      _Warning(a1: "Warning: falling back to auto detection of vproject directory.\n");
      if ( *a1 != nullptr )
        V_MakeAbsolutePath(pOut: pDest, outLen: maxLen, pPath: *a1, pStartingDir: nullptr);
      else
        V_MakeAbsolutePath(pOut: pDest, outLen: maxLen, pPath: ".", pStartingDir: nullptr);
      if ( sub_40AB50(pSrc: pDest, nSize: maxLen, a3: 1) == 0 )
        return 0;
      Q_getwd(pnbuf: pDest, maxlen: maxLen);
      if ( sub_40AB50(pSrc: pDest, nSize: maxLen, a3: 1) == 0 )
        return 0;
    }
    return SetupFileSystemError(
             a1: 1,
             a2: 1,
             pFormat: "Unable to find %s. Solutions:\n"
             "\n"
             "1. Read http://www.valve-erc.com/srcsdk/faq.html#NoGameDir\n"
             "2. Run vconfig to specify which game you're working on.\n"
             "3. Add -game <path> on the command line where <path> is the directory that %s is in.\n",
             "gameinfo.txt",
             "gameinfo.txt");
  }
  if ( *a1 == nullptr )
    return SetupFileSystemError(a1: 0, a2: 1, pFormat: "bOnlyUseDirectoryName=1 and pDirectoryName=NULL.");
  if ( !DoesFileExistIn(pSrc: (char *)*a1, a2: "gameinfo.txt") )
    return SetupFileSystemError(
             a1: 1,
             a2: 1,
             pFormat: "Setup file '%s' doesn't exist in subdirectory '%s'.\nCheck your -game parameter or VCONFIG setting.",
             "gameinfo.txt",
             *a1);
  V_strncpy(pDest, pSrc: *a1, maxLen);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040AB50
// Name: sub_40AB50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_40AB50(char *pSrc, unsigned int nSize, char a3)
{
  char *v3; // eax
  const char *v5; // eax
  void *v6; // [esp+10h] [ebp-134h]
  char *string; // [esp+118h] [ebp-2Ch]
  _BYTE *v8; // [esp+124h] [ebp-20h]
  _BYTE *v9; // [esp+130h] [ebp-14h]
  _BYTE v10[8]; // [esp+13Ch] [ebp-8h] BYREF

  v6 = operator new[](
         nSize,
         nBlockUse: 1,
         pFileName: "u:\\main\\src\\public\\filesystem_init.cpp",
         nLine: `TryLocateGameInfoFile'::`2'::__LINE__Var + 2);
  CArrayAutoPtr<char>::CArrayAutoPtr<char>(a1: v6);
  v3 = (char *)CPlainAutoPtr<char>::Get(a1: v10);
  V_strncpy(pDest: v3, pSrc, maxLen: nSize);
  *(_BYTE *)CArrayAutoPtr<char>::operator[](this: v10, a2: nSize - 1) = 0;
  v9 = (_BYTE *)CPlainAutoPtr<char>::Get(a1: v10);
  v8 = &v9[nSize];
  while ( v9 < v8 )
  {
    if ( *v9 == 92 )
      *v9 = 47;
    ++v9;
  }
  do
  {
    if ( DoesFileExistIn(pSrc, a2: "gameinfo.txt") )
      goto LABEL_7;
  }
  while ( a3 != 0 && V_StripLastDir(dirName: pSrc, maxlen: nSize) );
  v5 = (const char *)CPlainAutoPtr<char>::Get(a1: v10);
  V_strncpy(pDest: pSrc, pSrc: v5, maxLen: nSize);
  pSrc[nSize - 1] = 0;
  string = V_stristr(pStr: pSrc, pSearch: "/content/");
  if ( string != nullptr )
  {
    sprintf(string, format: "/game/");
    memmove(dst: (unsigned __int8 *)string + 6, src: (unsigned __int8 *)string + 9, count: &pSrc[nSize] - (string + 9));
    while ( !DoesFileExistIn(pSrc, a2: "gameinfo.txt") )
    {
      if ( a3 == 0 || !V_StripLastDir(dirName: pSrc, maxlen: nSize) )
        goto LABEL_15;
    }
LABEL_7:
    CArrayAutoPtr<char>::~CArrayAutoPtr<char>(a1: v10);
    return 0;
  }
LABEL_15:
  CArrayAutoPtr<char>::~CArrayAutoPtr<char>(a1: v10);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040ADD0
// Name: bool DoesPathExistAlready(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl DoesPathExistAlready(char *pSrc, char *pSearch)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  const char *i; // eax
  int v8; // eax
  const char *v9; // [esp+D0h] [ebp-2128h]
  const char *v10; // [esp+D0h] [ebp-2128h]
  char pname[268]; // [esp+E8h] [ebp-2110h] BYREF
  char pDest[8196]; // [esp+1F4h] [ebp-2004h] BYREF

  V_strncpy(pDest, pSrc, maxLen: 0x2000);
  V_FixSlashes(pname: pDest, separator: 92);
  V_strncpy(pDest: pname, pSrc: pSearch, maxLen: 260);
  V_FixSlashes(pname, separator: 92);
  strlen(buf: (unsigned __int8 *)pname);
  if ( v2 != 0 )
  {
    strlen(buf: (unsigned __int8 *)pname);
    if ( pname[v3 - 1] == 92 || (strlen(buf: (unsigned __int8 *)pname), pname[v4 - 1] == 47) )
    {
      strlen(buf: (unsigned __int8 *)pname);
      pname[v5 - 1] = 0;
    }
  }
  for ( i = V_stristr(pStr: pDest, pSearch: pname); ; i = V_stristr(pStr: v10, pSearch: pname) )
  {
    v9 = i;
    if ( i == nullptr )
      return 0;
    strlen(buf: (unsigned __int8 *)pname);
    v10 = &v9[v8];
    if ( *v10 == 0 || *v10 == 59 )
      break;
    if ( (*v10 == 92 || *v10 == 47) && v10[1] == 59 )
      break;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040AFE0
// Name: enum FSReturnCode_t SetSteamInstallPath(char __near *,int,class CSteamEnvVars __near &,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl SetSteamInstallPath(char *pDest, int maxLen, int a3, char a4)
{
  char Buffer[8200]; // [esp+D0h] [ebp-2110h] BYREF
  char pSrc[264]; // [esp+20D8h] [ebp-108h] BYREF

  if ( FileSystem_GetExecutableDir(pDest: pSrc, maxLen: 260) != 0 )
  {
    V_strncpy(pDest, pSrc, maxLen);
    while ( !DoesFileExistIn(pSrc: pDest, a2: "steam.dll") || DoesFileExistIn(pSrc: pDest, a2: "steamapp.cfg") )
    {
      if ( !V_StripLastDir(dirName: pDest, maxlen: maxLen) )
      {
        if ( a4 == 0 )
          return SetupFileSystemError(
                   a1: 0,
                   a2: 5,
                   pFormat: "Can't find steam.dll relative to executable path: %s.",
                   pSrc);
        _Warning(a1: "Can't find steam.dll relative to executable path: %s.\n", pSrc);
        return 5;
      }
    }
    CTempEnvVar::GetValue(this: (CTempEnvVar *)(a3 + 96), lpBuffer: Buffer, a3: 0x2000);
    if ( DoesPathExistAlready(pSrc: Buffer, pSearch: pDest) == 0 )
      CTempEnvVar::SetValue(this: (const char **)(a3 + 96), pFormat: "%s;%s", Buffer, pDest);
    return 0;
  }
  else if ( a4 != 0 )
  {
    _Warning(a1: "SetSteamInstallPath: FileSystem_GetExecutableDir failed.\n");
    return 3;
  }
  else
  {
    return SetupFileSystemError(a1: 0, a2: 3, pFormat: "FileSystem_GetExecutableDir failed.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B1E0
// Name: public: int CTempEnvVar::GetValue(char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __thiscall CTempEnvVar::GetValue(LPCSTR *this, LPSTR lpBuffer, int nSize)
{
  if ( lpBuffer != nullptr && nSize > 0 )
    return GetEnvironmentVariableA(lpName: *(this + 1), lpBuffer, nSize);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040C4E0
// Name: public: CArrayAutoPtr<char>::CArrayAutoPtr<char>(char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall CArrayAutoPtr<char>::CArrayAutoPtr<char>(_DWORD *this, int a2)
{
  CUtlMap<char const *,int,unsigned short>::CKeyLess::CKeyLess(this, a2: 0);
  CPlainAutoPtr<char>::Attach(a1: a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040C540
// Name: public: CArrayAutoPtr<char>::~CArrayAutoPtr<char>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CArrayAutoPtr<char>::~CArrayAutoPtr<char>(void *this)
{
  CArrayAutoPtr<char>::Delete(a1: this);
  return CPlainAutoPtr<char>::~CPlainAutoPtr<char>(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x0040C6B0
// Name: public: CPlainAutoPtr<char>::~CPlainAutoPtr<char>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPlainAutoPtr<char>::~CPlainAutoPtr<char>(void *this)
{
  return CArrayAutoPtr<char>::Delete(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x0040C6F0
// Name: public: void CPlainAutoPtr<char>::Attach(char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall CPlainAutoPtr<char>::Attach(_DWORD *this, int a2)
{
  *this = a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040C730
// Name: public: char __near * CPlainAutoPtr<char>::Detach(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPlainAutoPtr<char>::Detach(int *this)
{
  int v2; // [esp+D0h] [ebp-14h]

  v2 = *this;
  *this = 0;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0040D340
// Name: void Destruct<char>(char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl Destruct<char>(unsigned __int8 *dst)
{
  memset(dst, value: 0xDDu, count: sizeof(unsigned __int8));
}

//------------------------------------------------------------------------------
// Address: 0x0040D640
// Name: void Construct<char>(char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl Construct<char>(void *a1)
{
  return operator new(a1: 1u, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x004146B0
// Name: public: static void CBaseResourcePrecacher::RegisterAll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __cdecl CBaseResourcePrecacher::RegisterAll()
{
  int i; // [esp+D0h] [ebp-8h]

  for ( i = 0; i < 5; ++i )
    (*(void (__thiscall **)(struct IPrecacheSystem *, struct CBaseResourcePrecacher **, int))(*(_DWORD *)g_pPrecacheSystem
                                                                                            + 28))(
      a1: g_pPrecacheSystem,
      a2: (&CBaseResourcePrecacher::sm_pFirst)[i],
      a3: i);
}

//------------------------------------------------------------------------------
// Address: 0x00414730
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 *value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = (_BYTE)value;
    if ( (_BYTE)value != 0 || count < 0x100 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = (unsigned __int8)value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero((void *)dst, val: (int)value, len: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004147AA
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  if ( format != nullptr )
  {
    if ( count == 0 || string != nullptr )
    {
      str._cnt = 0x7FFFFFFF;
      if ( count <= 0x7FFFFFFF )
        str._cnt = count;
      str._flag = 66;
      str._base = string;
      str._ptr = string;
      result = _output_l(stream: &str, format, plocinfo, argptr: ap);
      v6 = result;
      if ( string != nullptr )
      {
        if ( --str._cnt < 0 )
          _flsbuf(ch: 0, &str);
        else
          *str._ptr = 0;
        return v6;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return -1;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041485B
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x00414880
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:ByteCopyDown+4[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x100
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:CopyUnwindUp+4[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 004148DC case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414BE5
// Name: __initp_misc_winxfltr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winxfltr()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00414C64
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x00414C75
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x00414E01
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414E13
// Name: fast_error_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn fast_error_exit(int rterrnum)
{
  if ( __error_mode == 1 )
    _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  __crtExitProcess(status: 255);
}

//------------------------------------------------------------------------------
// Address: 0x00414E37
// Name: check_managed_app
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl check_managed_app()
{
  return (_WORD)MEMORY[0x400000] == 23117
      && *(_DWORD *)(MEMORY[0x40003C] + 0x400000) == 17744
      && *(_WORD *)(MEMORY[0x40003C] + 4194328) == 267
      && *(_DWORD *)(MEMORY[0x40003C] + 4194420) > 0xEu
      && *(_DWORD *)(MEMORY[0x40003C] + 4194536) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00414E78
// Name: __tmainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tmainCRTStartup()
{
  HANDLE ProcessHeap; // eax
  _OSVERSIONINFOA *v1; // eax
  _OSVERSIONINFOA *v2; // esi
  HANDLE v3; // eax
  int v4; // edi
  HANDLE v5; // eax
  int v6; // eax
  char *v7; // eax
  int wShowWindow; // ecx
  int v9; // eax
  _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-70h] BYREF
  unsigned int winminor; // [esp+58h] [ebp-28h]
  unsigned int winmajor; // [esp+5Ch] [ebp-24h]
  int managedapp; // [esp+60h] [ebp-20h]
  int mainret; // [esp+64h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+68h] [ebp-18h]

  ms_exc.registration.TryLevel = 0;
  GetStartupInfoA(lpStartupInfo: &StartupInfo);
  ms_exc.registration.TryLevel = -2;
  ProcessHeap = GetProcessHeap();
  v1 = (_OSVERSIONINFOA *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 0, dwBytes: 0x94u);
  v2 = v1;
  if ( v1 == nullptr )
    fast_error_exit(rterrnum: 18);
  v1->dwOSVersionInfoSize = 148;
  if ( GetVersionExA(lpVersionInformation: v1) )
  {
    managedapp = v2->dwPlatformId;
    winmajor = v2->dwMajorVersion;
    winminor = v2->dwMinorVersion;
    v4 = v2->dwBuildNumber & 0x7FFF;
    v5 = GetProcessHeap();
    HeapFree(hHeap: v5, dwFlags: 0, lpMem: v2);
    if ( managedapp != 2 )
      v4 |= 0x8000u;
    _osplatform = managedapp;
    _winver = winminor + (winmajor << 8);
    _winmajor = winmajor;
    _winminor = winminor;
    _osver = v4;
    managedapp = check_managed_app();
    if ( _heap_init() == 0 )
      fast_error_exit(rterrnum: 28);
    if ( _mtinit() == 0 )
      fast_error_exit(rterrnum: 16);
    _RTC_Initialize();
    ms_exc.registration.TryLevel = 1;
    if ( _ioinit() < 0 )
      _amsg_exit(rterrnum: 27);
    _acmdln = GetCommandLineA();
    _aenvptr = (char *)__crtGetEnvironmentStringsA();
    if ( _setargv() < 0 )
      _amsg_exit(rterrnum: 8);
    if ( _setenvp() < 0 )
      _amsg_exit(rterrnum: 9);
    v6 = _cinit(initFloatingPrecision: 1);
    if ( v6 != 0 )
      _amsg_exit(rterrnum: v6);
    v7 = (char *)_wincmdln();
    if ( (StartupInfo.dwFlags & 1) != 0 )
      wShowWindow = StartupInfo.wShowWindow;
    else
      wShowWindow = 10;
    v9 = WinMain(hInstance: (HINSTANCE__ *)0x400000, hPrevInstance: nullptr, lpCmdLine: v7, nCmdShow: wShowWindow);
    mainret = v9;
    if ( managedapp == 0 )
      exit(code: v9);
    _cexit();
    return mainret;
  }
  else
  {
    v3 = GetProcessHeap();
    HeapFree(hHeap: v3, dwFlags: 0, lpMem: v2);
    return 255;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415058
// Name: _WinMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl WinMainCRTStartup()
{
  __security_init_cookie();
  return _tmainCRTStartup();
}

//------------------------------------------------------------------------------
// Address: 0x00415062
// Name: __RTC_CheckEsp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_CheckEsp()
{
  char v0; // zf
  void *retaddr; // [esp+0h] [ebp+0h]

  if ( !v0 )
    _RTC_Failure(retaddr, errnum: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00415085
// Name: _RTC_CheckStackVars(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _RTC_CheckStackVars(char *frame, _RTC_framedesc *v)
{
  int v3; // ebx
  bool v4; // cc
  char *v5; // edx
  _RTC_vardesc *v6; // eax
  int i; // [esp+Ch] [ebp-4h]
  void *retaddr; // [esp+14h] [ebp+4h]

  v3 = 0;
  v4 = v->varCount <= 0;
  v5 = frame;
  i = 0;
  if ( !v4 )
  {
    do
    {
      v6 = &v->variables[v3];
      if ( *(_DWORD *)&v5[v6->addr - 4] != -858993460 || *(_DWORD *)&v5[v6->addr + v6->size] != -858993460 )
      {
        _RTC_StackFailure(retaddr, varname: v->variables[v3].name);
        v5 = frame;
      }
      ++i;
      ++v3;
    }
    while ( i < v->varCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004150DF
// Name: _RTC_AllocaHelper(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _RTC_AllocaHelper(
        _RTC_ALLOCA_NODE *pAllocaBase,
        unsigned int cbSize,
        _RTC_ALLOCA_NODE **pAllocaInfoList)
{
  if ( pAllocaBase != nullptr && cbSize != 0 && pAllocaInfoList != nullptr )
  {
    memset(pAllocaBase, 204, cbSize);
    pAllocaBase->next = *pAllocaInfoList;
    pAllocaBase->allocaSize = cbSize;
    *pAllocaInfoList = pAllocaBase;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041510C
// Name: _RTC_CheckStackVars2(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _RTC_CheckStackVars2(char *frame, _RTC_framedesc *v, _RTC_ALLOCA_NODE *allocaList)
{
  int v4; // ebx
  bool v5; // zf
  char *v6; // edx
  _RTC_vardesc *v7; // eax
  _RTC_ALLOCA_NODE *v8; // esi
  int v9; // ebx
  _RTC_ALLOCA_NODE *v10; // eax
  int i; // [esp+10h] [ebp-4h]
  void *retaddr; // [esp+18h] [ebp+4h]

  v4 = 0;
  v5 = v == nullptr;
  v6 = frame;
  if ( !v5 )
  {
    for ( i = 0; i < v->varCount; ++v4 )
    {
      v7 = &v->variables[v4];
      if ( *(_DWORD *)&v6[v7->addr - 4] != -858993460 || *(_DWORD *)&v6[v7->addr + v7->size] != -858993460 )
      {
        _RTC_StackFailure(retaddr, varname: v->variables[v4].name);
        v6 = frame;
      }
      ++i;
    }
  }
  v8 = allocaList;
  v9 = 0;
  v10 = allocaList;
  if ( allocaList != nullptr )
  {
    do
    {
      v10 = v10->next;
      ++v9;
    }
    while ( v10 != nullptr );
    while ( v8 != nullptr )
    {
      if ( v8->guard1 != -858993460
        || v8->guard2[0] != -858993460
        || v8->guard2[1] != -858993460
        || v8->guard2[2] != -858993460 )
      {
        _RTC_AllocaFailure(retaddr, pn: v8, num: v9);
      }
      if ( *(_DWORD *)((char *)v8 + v8->allocaSize - 4) != -858993460 )
        _RTC_AllocaFailure(retaddr, pn: v8, num: v9);
      v8 = v8->next;
      --v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004151C0
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _alloca_probe_16()
{
  return _chkstk();
}

//------------------------------------------------------------------------------
// Address: 0x004151F0
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcmp(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int16 v6; // ax

  v2 = str1;
  v3 = str2;
  if ( ((unsigned __int8)str1 & 3) != 0 )
  {
    if ( ((unsigned __int8)str1 & 1) == 0 )
      goto doword;
    v2 = str1 + 1;
    if ( *str1 != *str2 )
      return;
    v3 = str2 + 1;
    if ( *str1 == 0 )
      return;
    if ( ((unsigned __int8)v2 & 2) != 0 )
    {
doword:
      v6 = *(_WORD *)v2;
      v2 += 2;
      if ( (_BYTE)v6 != *v3 || (_BYTE)v6 == 0 || HIBYTE(v6) != v3[1] || HIBYTE(v6) == 0 )
        return;
      v3 += 2;
    }
  }
  do
  {
    v4 = *(_DWORD *)v2;
    if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
      break;
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) != v3[1] )
      break;
    if ( BYTE1(v4) == 0 )
      break;
    v5 = HIWORD(v4);
    if ( (_BYTE)v5 != v3[2] )
      break;
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) != v3[3] )
      break;
    v3 += 4;
    v2 += 4;
  }
  while ( BYTE1(v5) != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00415280
// Name: _strcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcpy()
{
  JUMPOUT(0x4152F5);
}

//------------------------------------------------------------------------------
// Address: 0x00415290
// Name: _strcat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcat(char *dst, unsigned __int8 *src)
{
  char *v2; // ecx
  char v3; // al
  int v4; // eax
  int v5; // eax
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // ecx
  int v8; // edx
  int v9; // eax

  v2 = dst;
  if ( ((unsigned __int8)dst & 3) == 0 )
    goto find_end_of_dest_string_loop;
  do
  {
    v3 = *v2++;
    if ( v3 == 0 )
    {
start_byte_3:
      v6 = (unsigned __int8 *)(v2 - 1);
      goto copy_start;
    }
  }
  while ( ((unsigned __int8)v2 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_dest_string_loop:
      v4 = (*(_DWORD *)v2 + 2130640639) ^ ~*(_DWORD *)v2;
      v2 += 4;
    }
    while ( (v4 & 0x81010100) == 0 );
    v5 = *((_DWORD *)v2 - 1);
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) == 0 )
    {
      v6 = (unsigned __int8 *)(v2 - 3);
      goto copy_start;
    }
    if ( (v5 & 0xFF0000) == 0 )
    {
      v6 = (unsigned __int8 *)(v2 - 2);
      goto copy_start;
    }
    if ( (v5 & 0xFF000000) == 0 )
      goto start_byte_3;
  }
  v6 = (unsigned __int8 *)(v2 - 4);
copy_start:
  v7 = src;
  if ( ((unsigned __int8)src & 3) == 0 )
    goto main_loop_entrance;
  while ( 1 )
  {
    LOBYTE(v8) = *v7++;
    if ( (_BYTE)v8 == 0 )
      break;
    *v6++ = v8;
    if ( ((unsigned __int8)v7 & 3) == 0 )
    {
      while ( 1 )
      {
main_loop_entrance:
        v9 = (*(_DWORD *)v7 + 2130640639) ^ ~*(_DWORD *)v7;
        v8 = *(_DWORD *)v7;
        v7 += 4;
        if ( (v9 & 0x81010100) != 0 )
        {
          if ( (_BYTE)v8 == 0 )
            goto _byte_0;
          if ( BYTE1(v8) == 0 )
          {
            *(_WORD *)v6 = (unsigned __int8)v8;
            return;
          }
          if ( (v8 & 0xFF0000) == 0 )
          {
            *(_WORD *)v6 = v8;
            v6[2] = 0;
            return;
          }
          if ( (v8 & 0xFF000000) == 0 )
          {
            *(_DWORD *)v6 = v8;
            return;
          }
        }
        *(_DWORD *)v6 = v8;
        v6 += 4;
      }
    }
  }
_byte_0:
  *v6 = v8;
}

//------------------------------------------------------------------------------
// Address: 0x00415380
// Name: _strlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strlen(char *buf)
{
  char *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = buf;
  if ( ((unsigned __int8)buf & 3) != 0 )
  {
    while ( 1 )
    {
      v2 = *v1++;
      if ( v2 == 0 )
        break;
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto main_loop_0;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_0:
        v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
        v1 += 4;
      }
      while ( (v3 & 0x81010100) == 0 );
      v4 = *((_DWORD *)v1 - 1);
    }
    while ( (_BYTE)v4 != 0 && BYTE1(v4) != 0 && (v4 & 0xFF0000) != 0 && (v4 & 0xFF000000) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041540B
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x00415421
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax

  result = true;
  if ( drive != 0 )
  {
    LOBYTE(drive) = drive + 64;
    strcpy((char *)&drive + 1, ":\\");
    if ( GetDriveTypeA(lpRootPathName: (LPCSTR)&drive) <= 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415458
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  int v4; // eax
  char *v5; // edi
  signed int FullPathNameA; // eax
  char *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  char drvstr[4]; // [esp+8h] [ebp-4h] BYREF
  signed int count; // [esp+14h] [ebp+8h]

  if ( drive != 0 )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return nullptr;
    }
    v4 = drive;
  }
  else
  {
    v4 = _getdrive();
  }
  v5 = pnbuf;
  if ( pnbuf != nullptr )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return nullptr;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v4 != 0 )
  {
    drvstr[0] = v4 + 64;
    strcpy(&drvstr[1], ":.");
  }
  else
  {
    strcpy(drvstr, ".");
  }
  FullPathNameA = GetFullPathNameA(lpFileName: drvstr, nBufferLength: count, lpBuffer: pnbuf, lpFilePart: &pname);
  if ( FullPathNameA == 0 )
    goto LABEL_25;
  if ( pnbuf == nullptr )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v7 = (char *)calloc(count: maxlen, size: 1u);
    v5 = v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return nullptr;
    }
    v8 = GetFullPathNameA(lpFileName: drvstr, nBufferLength: maxlen, lpBuffer: v7, lpFilePart: &pname);
    if ( v8 != 0 && v8 < maxlen )
      return v5;
LABEL_25:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return nullptr;
  }
  if ( FullPathNameA < count )
    return v5;
  *_errno() = 34;
  *pnbuf = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041558D
// Name: __getcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getcwd(char *pnbuf, int maxlen)
{
  char *retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = _getdcwd_nolock(drive: 0, pnbuf, maxlen);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004155D6
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // ebx
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415648
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004156C4
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fread_nolock_s(
        char *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  char *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = buffer;
  dataSize = bufferSize;
  if ( elementSize == 0 || num == 0 )
    return 0;
  if ( buffer != nullptr )
  {
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
      goto LABEL_12;
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
    {
LABEL_12:
      v6 = num * elementSize;
      v7 = num * elementSize;
      if ( (stream->_flag & 0x10C) != 0 )
        streambufsize = stream->_bufsiz;
      else
        streambufsize = 4096;
      if ( v6 == 0 )
        return num;
      while ( 1 )
      {
        if ( (stream->_flag & 0x10C) != 0 )
        {
          cnt = stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_46;
            v9 = v7;
            if ( v7 >= cnt )
              v9 = stream->_cnt;
            if ( v9 <= dataSize )
            {
              memcpy_s(dst: data, sizeInBytes: dataSize, src: stream->_ptr, count: v9);
              stream->_cnt -= v9;
              stream->_ptr += v9;
              data += v9;
              v7 -= v9;
              dataSize -= v9;
              v6 = num * elementSize;
              goto LABEL_38;
            }
            if ( bufferSize != -1 )
              memset(dst: (int)buffer, value: nullptr, count: bufferSize);
LABEL_42:
            *_errno() = 34;
            _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
            return 0;
          }
        }
        if ( v7 < streambufsize )
        {
          v15 = _filbuf(str: stream);
          if ( v15 == -1 )
            return (v6 - v7) / elementSize;
          if ( dataSize != 0 )
          {
            v16 = data++;
            *v16 = v15;
            --v7;
            --dataSize;
            streambufsize = stream->_bufsiz;
            goto LABEL_38;
          }
LABEL_43:
          if ( bufferSize != -1 )
            memset(dst: (int)buffer, value: nullptr, count: bufferSize);
          goto LABEL_42;
        }
        if ( streambufsize != 0 )
        {
          if ( v7 <= 0x7FFFFFFF )
          {
            v10 = v7 % streambufsize;
            v11 = v7;
          }
          else
          {
            v10 = 0x7FFFFFFF % streambufsize;
            v11 = 0x7FFFFFFF;
          }
          v12 = v11 - v10;
        }
        else
        {
          v12 = 0x7FFFFFFF;
          if ( v7 <= 0x7FFFFFFF )
            v12 = v7;
        }
        if ( v12 > dataSize )
          goto LABEL_43;
        v17 = v12;
        v13 = _fileno(stream);
        v14 = _read(fh: v13, buf: data, cnt: v17);
        if ( v14 == 0 )
          break;
        if ( v14 == -1 )
        {
LABEL_46:
          stream->_flag |= 0x20u;
          return (v6 - v7) / elementSize;
        }
        data += v14;
        v7 -= v14;
        dataSize -= v14;
LABEL_38:
        if ( v7 == 0 )
          return num;
      }
      stream->_flag |= 0x10u;
      return (v6 - v7) / elementSize;
    }
  }
  *_errno() = 22;
  _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004158CA
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread_s(
        char *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( elementSize == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fread_nolock_s(buffer, bufferSize, elementSize, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00415960
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread(char *buffer, unsigned int elementSize, unsigned int count, _iobuf *stream)
{
  return fread_s(buffer, bufferSize: 0xFFFFFFFF, elementSize, count, stream);
}

//------------------------------------------------------------------------------
// Address: 0x0041597B
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftell_nolock(_iobuf *str)
{
  int v3; // eax
  int v4; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v8; // edx
  int cnt; // edx
  int v10; // esi
  char *v11; // eax
  char *v12; // ecx
  bool v13; // zf
  int bufsiz; // eax
  int v15; // ecx
  char *offset; // [esp+8h] [ebp-Ch]
  int filepos; // [esp+Ch] [ebp-8h]
  int fd; // [esp+10h] [ebp-4h]
  unsigned int rdcnt; // [esp+1Ch] [ebp+8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  v3 = _fileno(stream: str);
  fd = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v4 = _lseek(fh: v3, pos: 0, mthd: 1);
  filepos = v4;
  if ( v4 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v4 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  offset = (char *)(str->_ptr - base);
  if ( (flag & 3) != 0 )
  {
    if ( __pioinfo[fd >> 5][fd & 0x1F].osfile < 0 )
    {
      v8 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v8 == 10 )
            ++offset;
          ++v8;
        }
        while ( v8 < ptr );
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( filepos == 0 )
    return (int)offset;
  if ( (str->_flag & 1) == 0 )
    return (int)&offset[filepos];
  cnt = str->_cnt;
  if ( cnt != 0 )
  {
    v10 = fd & 0x1F;
    rdcnt = cnt + ptr - base;
    if ( __pioinfo[fd >> 5][v10].osfile >= 0 )
    {
LABEL_39:
      filepos -= rdcnt;
      return (int)&offset[filepos];
    }
    if ( _lseek(fh: fd, pos: 0, mthd: 2) == filepos )
    {
      v11 = str->_base;
      v12 = &v11[rdcnt];
      while ( v11 < v12 )
      {
        if ( *v11 == 10 )
          ++rdcnt;
        ++v11;
      }
      v13 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v13 )
        ++rdcnt;
      goto LABEL_39;
    }
    if ( _lseek(fh: fd, pos: filepos, mthd: 0) >= 0 )
    {
      bufsiz = 512;
      if ( rdcnt > 0x200 || ((v15 = str->_flag) & 8) == 0 || (v15 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      rdcnt = bufsiz;
      v13 = (__pioinfo[fd >> 5][v10].osfile & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  offset = nullptr;
  return (int)&offset[filepos];
}

//------------------------------------------------------------------------------
// Address: 0x00415B13
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ftell(_iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ftell_nolock(str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415B81
// Name: __fseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseek_nolock(_iobuf *str, int offset, int whence)
{
  int flag; // eax
  int v5; // eax
  int v6; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock(str);
      whence = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = _fileno(stream: str);
    return (_lseek(fh: v6, pos: offset, mthd: whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415C08
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fseek(_iobuf *stream, int offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseek_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415C8D
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  ms_exc.registration.TryLevel = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: &ms_exc.registration, a3: -2);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00415D51
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x00415D64
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getenv_helper_nolock(char *option)
{
  char **v1; // esi
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax

  v1 = _environ;
  if ( __env_initialized == 0 )
    return nullptr;
  if ( _environ != nullptr || _wenviron != nullptr && __wtomb_environ() == 0 && (v1 = _environ, _environ != nullptr) )
  {
    if ( option != nullptr )
    {
      strlen(buf: option);
      v4 = v3;
      while ( *v1 != nullptr )
      {
        strlen(buf: *v1);
        if ( v5 > v4
          && (*v1)[v4] == 61
          && _mbsnbicoll(s1: (const unsigned __int8 *)*v1, s2: (const unsigned __int8 *)option, n: v4) == 0 )
        {
          return &(*v1)[v4 + 1];
        }
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00415DE5
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv(char *option)
{
  char *retval; // [esp+14h] [ebp-1Ch]

  if ( option != nullptr && strnlen(str: option, maxsize: 0x7FFFu) < 0x7FFF )
  {
    _lock(locknum: 7);
    retval = _getenv_helper_nolock(option);
    _unlock(locknum: 7);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415E68
// Name: __dupenv_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _dupenv_s(char **pBuffer, unsigned int *pBufferSizeInTChars, char *varname)
{
  char *v3; // eax
  int v4; // eax
  unsigned int v5; // edi
  char *v6; // eax
  char *_Src; // [esp+10h] [ebp-20h]
  int retval; // [esp+14h] [ebp-1Ch]

  _lock(locknum: 7);
  if ( pBuffer != nullptr )
  {
    *pBuffer = nullptr;
    if ( pBufferSizeInTChars != nullptr )
      *pBufferSizeInTChars = 0;
    if ( varname != nullptr )
    {
      v3 = _getenv_helper_nolock(option: varname);
      _Src = v3;
      if ( v3 != nullptr )
      {
        strlen(buf: v3);
        v5 = v4 + 1;
        v6 = (char *)calloc(count: v4 + 1, size: 1u);
        *pBuffer = v6;
        if ( v6 == nullptr )
        {
          *_errno() = 12;
          retval = *_errno();
          goto LABEL_14;
        }
        if ( strcpy_s(_Dst: v6, _SizeInBytes: v5, _Src) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        if ( pBufferSizeInTChars != nullptr )
          *pBufferSizeInTChars = v5;
      }
      retval = 0;
      goto LABEL_14;
    }
  }
  *_errno() = 22;
  _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  retval = 22;
LABEL_14:
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00415F4E
// Name: __spawnv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnv(int modeflag, const char *pathname, const char *const *argv)
{
  if ( pathname != nullptr && *pathname != 0 && argv != nullptr && *argv != nullptr && **(_BYTE **)argv != 0 )
    return _spawnve(mode: modeflag, name: pathname, argv, envp: nullptr);
  *_errno() = 22;
  _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00415FB0
// Name: _strchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strchr(char *string, unsigned __int8 chr)
{
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = string;
  if ( ((unsigned __int8)string & 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == chr || v3 == 0 )
        break;
      if ( ((unsigned __int8)v2 & 3) == 0 )
        goto main_loop_1;
    }
  }
  else
  {
    do
    {
main_loop_1:
      while ( 1 )
      {
        v4 = ((chr << 8) | chr | (((chr << 8) | chr) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( (((v4 + 2130640639) ^ ~v4) & 0x81010100) != 0 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 != 0 && ((v7 & 0x1010100) != 0 || (v5 & 0x80000000) == 0) )
          return;
      }
      v8 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v8 == chr )
        break;
      if ( (_BYTE)v8 == 0 )
        break;
      if ( BYTE1(v8) == chr )
        break;
      if ( BYTE1(v8) == 0 )
        break;
      v9 = HIWORD(v8);
      if ( (_BYTE)v9 == chr )
        break;
    }
    while ( (_BYTE)v9 != 0 && BYTE1(v9) != chr && BYTE1(v9) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041606E
// Name: __access_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access_s(const char *path, int amode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  if ( path == nullptr || (amode & 0xFFFFFFF9) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return 22;
  }
  FileAttributesA = GetFileAttributesA(lpFileName: path);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return *_errno();
  }
  if ( (FileAttributesA & 0x10) == 0 && (FileAttributesA & 1) != 0 && (amode & 2) != 0 )
  {
    *__doserrno() = 5;
    *_errno() = 13;
    return *_errno();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004160F5
// Name: __access
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access(const char *path, int amode)
{
  return -(_access_s(path, amode) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x00416110
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:ByteCopyDown_0+4[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x100
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:CopyUnwindUp_0+4[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 0041616C case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416475
// Name: _sprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF
  va_list argptr; // [esp+34h] [ebp+10h] BYREF

  va_start(argptr, format);
  if ( format != nullptr && string != nullptr )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(ch: 0, &str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004164F0
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x0041651B
// Name: _putenv_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl putenv_helper(char *name, const char *value)
{
  const CHAR *v3; // ebx
  const unsigned __int8 *v4; // eax
  int v5; // eax
  unsigned int v6; // edi
  char *v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  char *v11; // eax
  int v12; // ebx
  int v13; // eax
  unsigned __int16 *v14; // eax
  unsigned int v15; // eax
  char *newoption; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 *woption; // [esp+8h] [ebp-4h] BYREF

  newoption = nullptr;
  if ( __env_initialized == 0 )
    return -1;
  v3 = name;
  if ( name == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  if ( value != nullptr )
  {
    v8 = strnlen(str: name, maxsize: 0x7FFFu);
    v9 = strnlen(str: value, maxsize: 0x7FFFu);
    if ( v8 < 0x7FFF && v9 < 0x7FFF )
    {
      v10 = v9 + v8 + 2;
      v11 = (char *)calloc(count: v10, size: 1u);
      newoption = v11;
      if ( v11 != nullptr )
      {
        strcpy_s(_Dst: v11, _SizeInBytes: v10, _Src: name);
        newoption[v8] = 61;
        strcpy_s(_Dst: &newoption[v8 + 1], _SizeInBytes: v10 - (v8 + 1), _Src: value);
        v3 = name;
        goto LABEL_16;
      }
      return -1;
    }
LABEL_13:
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  v4 = _mbschr(string: (const unsigned __int8 *)name, c: 0x3Du);
  if ( v4 != nullptr
    && (v4 - (const unsigned __int8 *)name >= 0x7FFF || strnlen(str: (const char *)v4 + 1, maxsize: 0x7FFFu) >= 0x7FFF) )
  {
    goto LABEL_13;
  }
  strlen(buf: name);
  v6 = v5 + 1;
  v7 = (char *)calloc(count: v5 + 1, size: 1u);
  newoption = v7;
  if ( v7 == nullptr )
    return -1;
  strcpy_s(_Dst: v7, _SizeInBytes: v6, _Src: name);
LABEL_16:
  if ( __crtsetenv(poption: &newoption, primary: 1) != 0 )
  {
    if ( newoption != nullptr )
      free(pMem: newoption);
    return -1;
  }
  if ( _wenviron == nullptr )
    return 0;
  woption = nullptr;
  v12 = MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: v3,
          cbMultiByte: -1,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  if ( v12 == 0 )
    goto LABEL_29;
  if ( value != nullptr )
  {
    v13 = MultiByteToWideChar(
            CodePage: 0,
            dwFlags: 0,
            lpMultiByteStr: value,
            cbMultiByte: -1,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    if ( v13 == 0 )
    {
LABEL_29:
      *_errno() = 42;
      return -1;
    }
    v12 += v13 + 1;
  }
  v14 = (unsigned __int16 *)calloc(count: v12, size: 2u);
  woption = v14;
  if ( v14 == nullptr )
    return -1;
  if ( MultiByteToWideChar(
         CodePage: 0,
         dwFlags: 0,
         lpMultiByteStr: name,
         cbMultiByte: -1,
         lpWideCharStr: v14,
         cchWideChar: v12) == 0
    || value != nullptr
    && (v15 = wcslen(wcs: woption),
        woption[v15] = 61,
        MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: value,
          cbMultiByte: -1,
          lpWideCharStr: &woption[v15 + 1],
          cchWideChar: v12 - (v15 + 1)) == 0) )
  {
    free(pMem: woption);
    goto LABEL_29;
  }
  if ( __crtwsetenv(poption: &woption, primary: 0) != 0 )
  {
    if ( woption != nullptr )
      free(pMem: woption);
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041672A
// Name: __putenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _putenv(char *option)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = putenv_helper(name: option, value: nullptr);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0041676F
// Name: __chdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chdir(const char *path)
{
  char *v1; // esi
  signed int CurrentDirectoryA; // eax
  DWORD v4; // edi
  char *v5; // eax
  char v6; // al
  DWORD LastError; // eax
  int memfree; // [esp+8h] [ebp-80h]
  int retval; // [esp+Ch] [ebp-7Ch]
  char env_var[4]; // [esp+10h] [ebp-78h] BYREF
  char abspath[264]; // [esp+14h] [ebp-74h] BYREF

  retval = -1;
  v1 = abspath;
  memfree = 0;
  if ( path == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  if ( !SetCurrentDirectoryA(lpPathName: path) )
    goto LABEL_14;
  CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x105u, lpBuffer: abspath);
  v4 = CurrentDirectoryA;
  if ( CurrentDirectoryA > 260 )
  {
    v5 = (char *)calloc(count: CurrentDirectoryA + 1, size: 1u);
    v1 = v5;
    if ( v5 == nullptr || (memfree = 1, v4 == 0) )
    {
LABEL_14:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      goto LABEL_15;
    }
    v4 = GetCurrentDirectoryA(nBufferLength: v4 + 1, lpBuffer: v5);
  }
  if ( v4 == 0 )
    goto LABEL_14;
  if ( (v6 = *v1, *v1 != 92) && v6 != 47 || v6 != v1[1] )
  {
    env_var[0] = 61;
    env_var[1] = _mbctoupper(c: (unsigned __int8)*v1);
    strcpy(&env_var[2], ":");
    if ( !SetEnvironmentVariableA(lpName: env_var, lpValue: v1) )
      goto LABEL_14;
  }
  retval = 0;
LABEL_15:
  if ( memfree != 0 )
    free(pMem: v1);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004168A0
// Name: _acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl acos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x41D988);
  }
  JUMPOUT(0x41692F);
}

//------------------------------------------------------------------------------
// Address: 0x004168E0
// Name: __CIacos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIacos(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIacos;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIacos_pentium4(a1);
  else
__CIacos:
    _CIacos_default(a1, a2: HIDWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x0041691B
// Name: __CIacos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004169F0
// Name: _asin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl asin(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x41E2A8);
  }
  JUMPOUT(0x416A7F);
}

//------------------------------------------------------------------------------
// Address: 0x00416A30
// Name: __CIasin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIasin(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIasin;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIasin_pentium4(a1);
  else
__CIasin:
    _CIasin_default(a1, a2: HIDWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x00416A6B
// Name: __CIasin_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00416B40
// Name: _fmod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl fmod(double X, double Y)
{
  double result; // st7

  _ctrandisp2(parm1: *(unsigned __int64 *)&X, parm2: *(unsigned __int64 *)&Y);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416B4A
// Name: __CIfmod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __thiscall _CIfmod(int this)
{
  return _cintrindisp2(a1: this, a2: &_OP_FMODjmptab);
}

//------------------------------------------------------------------------------
// Address: 0x00416B80
// Name: _pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl pow(double X, double Y)
{
  int v2; // eax
  bool v3; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v2 = _mm_getcsr() & 0x1F80;
    v3 = v2 == 8064;
    if ( v2 == 8064 )
      v3 = (v5 & 0x7F) == 127;
    if ( v3 )
      JUMPOUT(0x41F839);
  }
  JUMPOUT(0x416C14);
}

//------------------------------------------------------------------------------
// Address: 0x00416BC0
// Name: __CIpow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIpow(__int64 a1, __int64 a2)
{
  int v4; // eax
  bool v5; // zf
  char v6; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIpow;
  v4 = _mm_getcsr() & 0x1F80;
  v5 = v4 == 8064;
  if ( v4 == 8064 )
    v5 = (v6 & 0x7F) == 127;
  if ( v5 )
    _CIpow_pentium4(a1, a2);
  else
__CIpow:
    _CIpow_default(a1, a2: HIDWORD(a1), a3: a2, a4: HIDWORD(a2));
}

//------------------------------------------------------------------------------
// Address: 0x00416BFB
// Name: __CIpow_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIpow_default()
{
  JUMPOUT(0x416C1D);
}

//------------------------------------------------------------------------------
// Address: 0x00416E10
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x00416E19
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x00416E2C
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp+0h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x00416E46
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416EC0
// Name: _floor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl floor(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _floor_default(x: X);
  v1 = _mm_getcsr() & 0x1F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _floor_pentium4(X);
  else
    return _floor_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x00416F00
// Name: __floor_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _floor_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns, (__m128i)_mm_and_pd(v2, *(__m128d *)&S));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmplt_pd(v9, v8).m128d_f64[0];
    if ( v3 < 3071 )
    {
      a1.m128i_i64[0] = (*(_QWORD *)&_mm_cmplt_pd(v9, *(__m128d *)&NegZero).m128d_f64[0] | NegZero) & NegOne;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 3122 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] - COERCE_DOUBLE(*(_QWORD *)&v10 & One);
      return *(double *)a1.m128i_i64;
    }
  }
  else
  {
    if ( v3 >= 1023 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 1074 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416FE1
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00417063
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(char *nptr, localeinfo_struct *plocinfo)
{
  char *v2; // esi
  long double result; // st7
  int v4; // eax
  int v5; // eax
  _flt fltstruct; // [esp+8h] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+20h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v2 = nptr;
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[(unsigned __int8)*v2] & 8
         : _isctype_l(c: (unsigned __int8)*v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    strlen(buf: v2);
    result = _fltin2(
               flt: &fltstruct,
               str: v2,
               len_ignore: v5,
               scale_ignore: 0,
               radix_ignore: 0,
               _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041710C
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00417120
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x415FB6);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004171A6
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _tolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  unsigned __int16 v8; // ax
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+18h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+1Ch] [ebp-4h] BYREF
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        result = (unsigned __int8)outbuffer[0];
      }
      else
      {
        LOBYTE(v8) = 0;
        HIBYTE(v8) = outbuffer[0];
        result = (unsigned __int8)outbuffer[1] | v8;
      }
      goto LABEL_18;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pclmap[c];
LABEL_18:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x004172BD
// Name: _tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl tolower(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _tolower_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 65 <= 0x19 )
    return c + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004172F0
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  char *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  const char *v9; // esi
  char v10; // bl
  size_t v11; // ecx
  int v12; // edx
  char v13; // dl
  int v15; // eax

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Destination;
  if ( ((unsigned __int8)Destination & 3) == 0 )
    goto find_end_of_front_string_loop;
  do
  {
    v5 = *v4++;
    if ( v5 == 0 )
    {
start_byte_3_0:
      v8 = v4 - 1;
      goto copy_start_0;
    }
  }
  while ( ((unsigned __int8)v4 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_front_string_loop:
      v6 = (*(_DWORD *)v4 + 2130640639) ^ ~*(_DWORD *)v4;
      v4 += 4;
    }
    while ( (v6 & 0x81010100) == 0 );
    v7 = *((_DWORD *)v4 - 1);
    if ( (_BYTE)v7 == 0 )
      break;
    if ( BYTE1(v7) == 0 )
    {
      v8 = v4 - 3;
      goto copy_start_0;
    }
    if ( (v7 & 0xFF0000) == 0 )
    {
      v8 = v4 - 2;
      goto copy_start_0;
    }
    if ( (v7 & 0xFF000000) == 0 )
      goto start_byte_3_0;
  }
  v8 = v4 - 4;
copy_start_0:
  v9 = Source;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v10 = Count;
    v11 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance_0;
tail_loop_start:
    v3 = v10 & 3;
    if ( (v10 & 3) != 0 )
    {
      while ( 1 )
      {
        v13 = *v9++;
        *v8++ = v13;
        if ( v13 == 0 )
          break;
        if ( --v3 == 0 )
          goto empty_counter;
      }
    }
    else
    {
empty_counter:
      *v8 = v3;
    }
    return Destination;
  }
  do
  {
    LOBYTE(v12) = *v9++;
    if ( (_BYTE)v12 == 0 )
    {
LABEL_26:
      *v8 = v12;
      return Destination;
    }
    *v8++ = v12;
    if ( --v3 == 0 )
      goto empty_counter;
  }
  while ( ((unsigned __int8)v9 & 3) != 0 );
  v10 = v3;
  v11 = v3 >> 2;
  if ( v11 == 0 )
    goto tail_loop_start;
  while ( 1 )
  {
main_loop_entrance_0:
    v15 = (*(_DWORD *)v9 + 2130640639) ^ ~*(_DWORD *)v9;
    v12 = *(_DWORD *)v9;
    v9 += 4;
    if ( (v15 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        goto LABEL_26;
      if ( BYTE1(v12) == 0 )
        break;
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_WORD *)v8 = v12;
        v8[2] = 0;
        return Destination;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v8 = v12;
        return Destination;
      }
    }
    *(_DWORD *)v8 = v12;
    v8 += 4;
    if ( --v11 == 0 )
      goto tail_loop_start;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x00417430
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance_1;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start_0:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance_1:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start_0;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x00417560
// Name: __allrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allrem(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  unsigned __int64 result; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // eax
  int v9; // ecx
  bool v10; // cf
  unsigned __int64 v11; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 == 0 )
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    result = v4 % (unsigned int)a2;
    if ( v2 - 1 < 0 )
      return result;
    return -(__int64)result;
  }
  v6 = __PAIR64__(v3, a2);
  v7 = a1;
  do
  {
    v6 >>= 1;
    v7 >>= 1;
  }
  while ( HIDWORD(v6) != 0 );
  v8 = v7 / (unsigned int)v6;
  v9 = HIDWORD(a2) * v8;
  v11 = (unsigned int)a2 * (unsigned __int64)v8;
  v10 = __CFADD__(v9, HIDWORD(v11));
  HIDWORD(v11) += v9;
  if ( v10 || v11 > a1 )
    v11 -= a2;
  result = v11 - a1;
  if ( v2 - 1 < 0 )
    return -(__int64)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417620
// Name: __alldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldiv(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v8 = v7 / (unsigned int)v6;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    v5 = v8;
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    LODWORD(v5) = v4 / (unsigned int)a2;
    HIDWORD(v5) = HIDWORD(a1) / (unsigned int)a2;
  }
  if ( v2 == 1 )
    return -v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004176CA
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, mask: 4, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417719
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 4;
}

//------------------------------------------------------------------------------
// Address: 0x00417742
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isspace_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 8;
  else
    result = _isctype_l(c, mask: 8, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417791
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isspace(int c)
{
  if ( __locale_changed != 0 )
    return _isspace_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 8;
}

//------------------------------------------------------------------------------
// Address: 0x004177BA
// Name: __wtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wtol(const wchar_t *nptr)
{
  return wcstol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x004177CB
// Name: __wtoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl _wtoi(const wchar_t *nptr)
{
  return _wtol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x004177D0
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  char *v3; // esi
  int v5; // eax
  int v6; // eax
  _flt *v7; // eax
  _flt *v8; // ecx
  int flags; // eax
  long double v10; // st7
  _flt answerstruct; // [esp+Ch] [ebp-30h] BYREF
  _LocaleUpdate _loc_update; // [esp+24h] [ebp-18h] BYREF
  long double tmp; // [esp+34h] [ebp-8h]

  v3 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
       ? _loc_update.localeinfo.locinfo->pctype[(unsigned __int8)*v3] & 8
       : _isctype_l(c: (unsigned __int8)*v3, mask: 8, plocinfo: &_loc_update.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  strlen(buf: v3);
  v7 = _fltin2(
         flt: &answerstruct,
         str: v3,
         len_ignore: v6,
         scale_ignore: 0,
         radix_ignore: 0,
         _Locale: &_loc_update.localeinfo);
  v8 = v7;
  if ( endptr != nullptr )
    *endptr = &v3[v7->nbytes];
  flags = v7->flags;
  if ( (v8->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr != nullptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v10 = *(double *)&_HUGE;
    if ( *v3 == 45 )
      v10 = -*(double *)&_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v10 = 0.0, 0.0 != v8->dval) )
  {
    tmp = v8->dval;
    goto LABEL_24;
  }
  tmp = v10;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x004178EB
// Name: _strtod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl strtod(char *nptr, char **endptr)
{
  return _strtod_l(nptr, endptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004178FE
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  char v7; // bl
  const char *i; // edi
  int v9; // eax
  _BYTE *v10; // edi
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // eax
  unsigned __int16 v13; // cx
  unsigned int v14; // ecx
  int v15; // ecx
  const char *v16; // edi
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-14h] BYREF
  unsigned int number; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  number = 0;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[(unsigned __int8)v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: (unsigned __int8)v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v10 = i + 1;
    v7 = *v10;
    i = v10 + 1;
  }
LABEL_32:
  pctype = locinfo->pctype;
  v12 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    v13 = pctype[(unsigned __int8)v7];
    if ( (v13 & 4) != 0 )
    {
      v14 = v7 - 48;
    }
    else
    {
      if ( (v13 & 0x103) == 0 )
        break;
      v15 = v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v15 = v7 - 32;
      v14 = v15 - 55;
    }
    if ( v14 >= ibase )
      break;
    flags |= 8u;
    if ( number < v12 || number == v12 && v14 <= 0xFFFFFFFF % ibase )
    {
      number = v14 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v16 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v16 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v16;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x00417B29
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00417B52
// Name: _strtoul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoul(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 1);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00417B80
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x00417BC0
// Name: _tan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl tan(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x422388);
  }
  JUMPOUT(0x417C4F);
}

//------------------------------------------------------------------------------
// Address: 0x00417C00
// Name: __CItan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CItan(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CItan;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CItan_pentium4(a1);
  else
__CItan:
    _CItan_default(a1);
}

//------------------------------------------------------------------------------
// Address: 0x00417C3B
// Name: __CItan_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00417CED
// Name: fastzero_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fastzero_I(_OWORD *dst, unsigned int len)
{
  unsigned int v3; // ecx

  v3 = len >> 7;
  do
  {
    *dst = 0;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = 0;
    dst[6] = 0;
    dst[7] = 0;
    dst += 8;
    --v3;
  }
  while ( v3 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00417D44
// Name: __VEC_memzero
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _VEC_memzero(int dst, int val, int len)
{
  char *result; // eax
  int v4; // edi
  int v5; // edx
  unsigned int v6; // [esp+4h] [ebp-Ch]

  result = (char *)dst;
  v4 = dst % 16;
  if ( dst % 16 != 0 )
  {
    memset((void *)dst, 0, 16 - v4);
    _VEC_memzero(dst: (void *)(16 - v4 + dst), val: 0, len: len - (16 - v4));
    return (char *)dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastzero_I((_OWORD *)dst, len: len - v5);
      result = (char *)dst;
      v5 = v6;
    }
    if ( v5 != 0 )
    {
      memset(&result[len - v5], 0, v6);
      return (char *)dst;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417DD3
// Name: __sse2_mathfcns_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sse2_mathfcns_init()
{
  __use_sse2_mathfcns = 0;
  __use_sse2_mathfcns = _get_sse2_info();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00417DE7
// Name: __flsbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flsbuf(unsigned __int8 ch, int str)
{
  _iobuf *v2; // esi
  int flag; // eax
  bool v5; // zf
  char *base; // eax
  char *ptr; // edi
  signed int v8; // edi
  ioinfo *v9; // eax
  __int64 v10; // rax
  int written; // [esp+4h] [ebp-4h]

  v2 = (_iobuf *)str;
  str = _fileno(stream: (_iobuf *)str);
  flag = v2->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    v2->_flag |= 0x20u;
    return -1;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    v2->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      v2->_flag = flag | 0x20;
      return -1;
    }
    v2->_ptr = v2->_base;
    v2->_flag = flag & 0xFFFFFFFE;
  }
  v5 = (v2->_flag & 0x10C) == 0;
  v2->_flag = v2->_flag & 0xFFFFFFED | 2;
  v2->_cnt = 0;
  written = 0;
  if ( v5 && (v2 != &__iob_func()[1] && v2 != &__iob_func()[2] || _isatty(fh: str) == 0) )
    _getbuf(str: v2);
  if ( (v2->_flag & 0x108) != 0 )
  {
    base = v2->_base;
    ptr = v2->_ptr;
    v2->_ptr = base + 1;
    v8 = ptr - base;
    v2->_cnt = v2->_bufsiz - 1;
    if ( v8 <= 0 )
    {
      if ( str == -1 || str == -2 )
        v9 = &__badioinfo;
      else
        v9 = &__pioinfo[str >> 5][str & 0x1F];
      if ( (v9->osfile & 0x20) != 0 )
      {
        v10 = _lseeki64(fh: str, pos: 0, mthd: 2);
        if ( (HIDWORD(v10) & (unsigned int)v10) == 0xFFFFFFFF )
          goto LABEL_27;
      }
    }
    else
    {
      written = _write(fh: str, buf: base, cnt: v8);
    }
    *v2->_base = ch;
  }
  else
  {
    v8 = 1;
    written = _write(fh: str, buf: &ch, cnt: 1u);
  }
  if ( written != v8 )
  {
LABEL_27:
    v2->_flag |= 0x20u;
    return -1;
  }
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x00417F47
// Name: write_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char(int ch@<eax>, _iobuf *f@<ecx>, int *pnumwritten@<esi>)
{
  bool v3; // sf

  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr)
    && ((v3 = f->_cnt - 1 < 0, --f->_cnt, v3)
      ? (ch = _flsbuf(ch, str: (int)f))
      : (*f->_ptr = ch, ++f->_ptr, ch = (unsigned __int8)ch),
        ch == -1) )
  {
    *pnumwritten = -1;
  }
  else
  {
    ++*pnumwritten;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417F7A
// Name: write_multi_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_multi_char(int *pnumwritten@<eax>, char ch, int num, _iobuf *f)
{
  int *v4; // esi

  v4 = pnumwritten;
  do
  {
    if ( num <= 0 )
      break;
    LOBYTE(pnumwritten) = ch;
    --num;
    write_char(ch: (int)pnumwritten, f, pnumwritten: v4);
  }
  while ( *v4 != -1 );
}

//------------------------------------------------------------------------------
// Address: 0x00417F9E
// Name: write_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string(char *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  int *v4; // esi
  int *v6; // eax

  v4 = pnumwritten;
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    while ( len > 0 )
    {
      LOBYTE(pnumwritten) = *string;
      --len;
      write_char(ch: (int)pnumwritten, f, pnumwritten: v4);
      ++string;
      if ( *v4 == -1 )
      {
        v6 = _errno();
        if ( *v6 != 42 )
          return;
        LOBYTE(v6) = 63;
        write_char(ch: (int)v6, f, pnumwritten: v4);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417FE8
// Name: __output_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _output_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  const char *v4; // ebx
  int *v5; // edi
  _DWORD *v7; // esi
  ioinfo *v8; // eax
  _DWORD *v9; // esi
  ioinfo *v10; // eax
  char v11; // dl
  STATE v12; // ecx
  bool v13; // zf
  char *v14; // ebx
  int v15; // eax
  char v16; // al
  int v17; // eax
  _output_l::__l2::<unnamed_tag> *p_buffer; // ebx
  int v19; // ecx
  char *v20; // edi
  char *v21; // eax
  char *v22; // edi
  __int16 *v23; // eax
  char *v24; // ecx
  int v25; // eax
  _WORD *v26; // esi
  __int64 v27; // rax
  int *v28; // edi
  int v29; // esi
  char *v30; // eax
  int v31; // eax
  char *v32; // edi
  void (__cdecl *v33)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_tag> *, int, int, int, int, _LocaleUpdate *); // eax
  int v34; // edi
  void (__cdecl *v35)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *); // eax
  void (__cdecl *v36)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *); // eax
  unsigned int v37; // ebx
  unsigned int v38; // edi
  char *j; // esi
  int v40; // eax
  unsigned __int64 v41; // rcx
  int v42; // ecx
  char *v43; // eax
  char *v44; // esi
  char *i; // eax
  int v46; // ebx
  _iobuf *v47; // edi
  char *v48; // esi
  wchar_t v49; // ax
  char v50; // al
  int v51; // [esp-14h] [ebp-A0h]
  int v52; // [esp-10h] [ebp-9Ch]
  unsigned __int64 v53; // [esp-10h] [ebp-9Ch]
  int v54; // [esp-Ch] [ebp-98h]
  int v55; // [esp-8h] [ebp-94h]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-80h] BYREF
  int capexp; // [esp+14h] [ebp-78h]
  STATE state; // [esp+18h] [ebp-74h]
  int retval; // [esp+1Ch] [ebp-70h] BYREF
  int count; // [esp+24h] [ebp-68h]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-64h] BYREF
  char *heapbuf; // [esp+38h] [ebp-54h]
  int no_output; // [esp+3Ch] [ebp-50h]
  int hexadd; // [esp+40h] [ebp-4Ch]
  char *v65; // [esp+44h] [ebp-48h]
  int bufferiswide; // [esp+48h] [ebp-44h]
  int fldwidth; // [esp+4Ch] [ebp-40h]
  int prefixlen; // [esp+50h] [ebp-3Ch]
  char prefix[4]; // [esp+54h] [ebp-38h] BYREF
  int charsout; // [esp+58h] [ebp-34h] BYREF
  _iobuf *f; // [esp+5Ch] [ebp-30h]
  char *v72; // [esp+60h] [ebp-2Ch]
  int radix; // [esp+64h] [ebp-28h] BYREF
  char *string; // [esp+68h] [ebp-24h]
  int precision; // [esp+6Ch] [ebp-20h]
  char v76; // [esp+73h] [ebp-19h]
  int flags; // [esp+74h] [ebp-18h]
  _output_l::__l2::<unnamed_tag> buffer; // [esp+78h] [ebp-14h] BYREF
  char L_buffer[8]; // [esp+278h] [ebp+1ECh] BYREF

  v4 = format;
  v5 = (int *)argptr;
  f = stream;
  v72 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( f == nullptr
    || (f->_flag & 0x40) == 0
    && (_fileno(stream: f) == -1 || _fileno(stream: f) == -2
      ? (v8 = &__badioinfo)
      : (v7 = (_DWORD *)(4 * (_fileno(stream: f) >> 5) + 4534976),
         v8 = (ioinfo *)(*v7 + 56 * (_fileno(stream: f) & 0x1F))),
        (*((_BYTE *)v8 + 36) & 0x7F) != 0
     || (_fileno(stream: f) == -1 || _fileno(stream: f) == -2
       ? (v10 = &__badioinfo)
       : (v9 = (_DWORD *)(4 * (_fileno(stream: f) >> 5) + 4534976),
          v10 = (ioinfo *)(*v9 + 56 * (_fileno(stream: f) & 0x1F))),
         *((char *)v10 + 36) < 0))
    || format == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    goto LABEL_3;
  }
  v11 = *format;
  v12 = ST_NORMAL;
  v13 = *format == 0;
  charsout = 0;
  radix = 0;
  heapbuf = nullptr;
  v76 = v11;
  if ( v13 )
  {
LABEL_222:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  while ( 1 )
  {
    v14 = (char *)(v4 + 1);
    v65 = v14;
    if ( charsout < 0 )
      goto LABEL_222;
    if ( (unsigned __int8)(v11 - 32) > 0x58u )
      v15 = 0;
    else
      v15 = *((_BYTE *)&S + v11 + 8) & 0xF;
    state = __lookuptable[8 * v15 + v12] >> 4;
    switch ( state )
    {
      case ST_NORMAL:
        goto NORMAL_STATE;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_219;
      case ST_FLAG:
        switch ( v11 )
        {
          case ' ':
            flags |= 2u;
            break;
          case '#':
            flags |= 0x80u;
            break;
          case '+':
            flags |= 1u;
            break;
          case '-':
            flags |= 4u;
            break;
          case '0':
            flags |= 8u;
            break;
          default:
            break;
        }
        goto LABEL_219;
      case ST_WIDTH:
        if ( v11 == 42 )
        {
          v72 = (char *)(v5 + 1);
          fldwidth = *v5;
          if ( fldwidth < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + v11 - 48;
        }
        goto LABEL_219;
      case ST_DOT:
        precision = 0;
        goto LABEL_219;
      case ST_PRECIS:
        if ( v11 == 42 )
        {
          v72 = (char *)(v5 + 1);
          precision = *v5;
          if ( precision < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + v11 - 48;
        }
        goto LABEL_219;
      case ST_SIZE:
        if ( v11 != 73 )
        {
          switch ( v11 )
          {
            case 'h':
              flags |= 0x20u;
              break;
            case 'l':
              if ( *v14 == 108 )
              {
                flags |= 0x1000u;
                v65 = v14 + 1;
              }
              else
              {
                flags |= 0x10u;
              }
              break;
            case 'w':
              flags |= 0x800u;
              break;
            default:
              break;
          }
          goto LABEL_219;
        }
        v16 = *v14;
        if ( *v14 == 54 && v14[1] == 52 )
        {
          flags |= 0x8000u;
          v65 = v14 + 2;
          goto LABEL_219;
        }
        if ( v16 == 51 && v14[1] == 50 )
        {
          flags &= ~0x8000u;
          v65 = v14 + 2;
          goto LABEL_219;
        }
        if ( v16 == 100 || v16 == 105 || v16 == 111 || v16 == 117 || v16 == 120 || v16 == 88 )
          goto LABEL_219;
        state = ST_NORMAL;
NORMAL_STATE:
        bufferiswide = 0;
        v17 = _isleadbyte_l(c: (unsigned __int8)v11, plocinfo: &_loc_update.localeinfo);
        v13 = v17 == 0;
        LOBYTE(v17) = v76;
        if ( v13 || (write_char(ch: v17, f, pnumwritten: &charsout), LOBYTE(v17) = *v14, v65 = v14 + 1, (_BYTE)v17 != 0) )
        {
          write_char(ch: v17, f, pnumwritten: &charsout);
          goto LABEL_219;
        }
LABEL_221:
        *_errno() = 22;
        _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
LABEL_3:
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return -1;
      case ST_TYPE:
        if ( v11 <= 100 )
        {
          if ( v11 == 100 )
          {
LABEL_119:
            flags |= 0x40u;
            goto LABEL_120;
          }
          if ( v11 > 83 )
          {
            if ( v11 == 88 )
              goto LABEL_141;
            if ( v11 == 90 )
            {
              v23 = (__int16 *)*v5;
              v72 = (char *)(v5 + 1);
              if ( v23 != nullptr && (v24 = *((char **)v23 + 1)) != nullptr )
              {
                v25 = *v23;
                string = v24;
                if ( (flags & 0x800) != 0 )
                {
                  v25 /= 2;
                  bufferiswide = 1;
                }
                else
                {
                  bufferiswide = 0;
                }
              }
              else
              {
                string = __nullstring;
                strlen(buf: __nullstring);
              }
              goto LABEL_190;
            }
            if ( v11 != 97 )
            {
              if ( v11 != 99 )
                goto LABEL_191;
              goto LABEL_94;
            }
          }
          else
          {
            if ( v11 == 83 )
            {
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
              goto LABEL_84;
            }
            if ( v11 != 65 )
            {
              if ( v11 != 67 )
              {
                if ( v11 != 69 && v11 != 71 )
                  goto LABEL_191;
                goto LABEL_77;
              }
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
LABEL_94:
              v22 = (char *)(v5 + 1);
              v72 = v22;
              if ( (flags & 0x810) != 0 )
              {
                if ( wctomb_s(pRetValue: &radix, dst: buffer.sz, sizeInBytes: 0x200u, wchar: *((_WORD *)v22 - 2)) != 0 )
                  no_output = 1;
              }
              else
              {
                buffer.sz[0] = *(v22 - 4);
                radix = 1;
              }
              string = (char *)&buffer;
              goto LABEL_191;
            }
LABEL_77:
            v11 += 32;
            capexp = 1;
            v76 = v11;
          }
LABEL_78:
          flags |= 0x40u;
          p_buffer = &buffer;
          string = (char *)&buffer;
          count = 512;
          if ( precision >= 0 )
          {
            if ( precision != 0 )
            {
              if ( precision > 512 )
                precision = 512;
              if ( precision > 163 )
              {
                v29 = precision + 349;
                v30 = (char *)operator new(nSize: precision + 349);
                v11 = v76;
                heapbuf = v30;
                if ( v30 != nullptr )
                {
                  string = v30;
                  count = v29;
                  p_buffer = (_output_l::__l2::<unnamed_tag> *)v30;
                }
                else
                {
                  precision = 163;
                }
              }
            }
            else
            {
              precision = v11 == 103;
            }
          }
          else
          {
            precision = 6;
          }
          v31 = *v5;
          v32 = (char *)(v5 + 2);
          LODWORD(tmp.x) = v31;
          HIDWORD(tmp.x) = *((_DWORD *)v32 - 1);
          v55 = capexp;
          v54 = precision;
          v72 = v32;
          v52 = v11;
          v51 = count;
          v33 = (void (__cdecl *)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_tag> *, int, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr: codedptr);
          v33(a1: &tmp, a2: p_buffer, a3: v51, a4: v52, a5: v54, a6: v55, a7: &_loc_update);
          v34 = flags & 0x80;
          if ( (flags & 0x80) != 0 && precision == 0 )
          {
            v35 = (void (__cdecl *)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *))_decode_pointer(codedptr: off_43EF24);
            v35(a1: p_buffer, a2: &_loc_update);
          }
          if ( v76 == 103 && v34 == 0 )
          {
            v36 = (void (__cdecl *)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *))_decode_pointer(codedptr: off_43EF20);
            v36(a1: p_buffer, a2: &_loc_update);
          }
          if ( p_buffer->sz[0] == 45 )
          {
            flags |= 0x100u;
            p_buffer = (_output_l::__l2::<unnamed_tag> *)((char *)p_buffer + 1);
            string = (char *)p_buffer;
          }
          strlen(buf: p_buffer->sz);
          goto LABEL_190;
        }
        if ( v11 > 112 )
        {
          if ( v11 != 115 )
          {
            if ( v11 != 117 )
            {
              if ( v11 != 120 )
                goto LABEL_191;
              hexadd = 39;
              goto COMMON_HEX;
            }
LABEL_120:
            radix = 10;
            goto COMMON_INT;
          }
LABEL_84:
          v19 = precision;
          if ( precision == -1 )
            v19 = 0x7FFFFFFF;
          v72 = (char *)(v5 + 1);
          v20 = (char *)*v5;
          string = v20;
          if ( (flags & 0x810) != 0 )
          {
            if ( v20 == nullptr )
              string = (char *)__wnullstring;
            v21 = string;
            bufferiswide = 1;
            while ( v19 != 0 )
            {
              --v19;
              if ( *(_WORD *)v21 == 0 )
                break;
              v21 += 2;
            }
            v25 = (v21 - string) >> 1;
          }
          else
          {
            if ( v20 == nullptr )
              string = __nullstring;
            for ( i = string; v19 != 0; ++i )
            {
              --v19;
              if ( *i == 0 )
                break;
            }
            v25 = i - string;
          }
LABEL_190:
          radix = v25;
          goto LABEL_191;
        }
        if ( v11 == 112 )
        {
          precision = 8;
LABEL_141:
          hexadd = 7;
COMMON_HEX:
          radix = 16;
          if ( (flags & 0x80u) != 0 )
          {
            prefix[0] = 48;
            prefix[1] = hexadd + 81;
            prefixlen = 2;
          }
          goto COMMON_INT;
        }
        if ( v11 < 101 )
          goto LABEL_191;
        if ( v11 <= 103 )
          goto LABEL_78;
        if ( v11 == 105 )
          goto LABEL_119;
        if ( v11 != 110 )
        {
          if ( v11 != 111 )
            goto LABEL_191;
          radix = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
COMMON_INT:
          if ( (flags & 0x8000u) != 0 || (flags & 0x1000) != 0 )
          {
            v27 = *(_QWORD *)v5;
            v28 = v5 + 2;
          }
          else
          {
            v28 = v5 + 1;
            if ( (flags & 0x20) != 0 )
            {
              v72 = (char *)v28;
              if ( (flags & 0x40) != 0 )
                LODWORD(v27) = *((__int16 *)v28 - 2);
              else
                LODWORD(v27) = *((unsigned __int16 *)v28 - 2);
              v27 = (int)v27;
LABEL_158:
              if ( (flags & 0x40) != 0 && v27 < 0 )
              {
                v27 = -v27;
                flags |= 0x100u;
              }
              v37 = HIDWORD(v27);
              v38 = v27;
              if ( (flags & 0x9000) == 0 )
                v37 = 0;
              if ( precision >= 0 )
              {
                flags &= ~8u;
                if ( precision > 512 )
                  precision = 512;
              }
              else
              {
                precision = 1;
              }
              if ( (v37 | (unsigned int)v27) == 0 )
                prefixlen = 0;
              for ( j = &buffer.sz[511]; ; --j )
              {
                v40 = precision--;
                if ( v40 <= 0 && (v37 | v38) == 0 )
                  break;
                v53 = __PAIR64__(v37, v38);
                v41 = __PAIR64__(v37, v38) % radix;
                v42 = v41 + 48;
                count = HIDWORD(v41);
                v37 = (v53 / radix) >> 32;
                v38 = v53 / radix;
                if ( v42 > 57 )
                  LOBYTE(v42) = hexadd + v42;
                *j = v42;
              }
              v43 = (char *)(&buffer.sz[511] - j);
              v44 = j + 1;
              radix = (int)v43;
              string = v44;
              if ( (flags & 0x200) != 0 && (v43 == nullptr || *v44 != 48) )
              {
                *--string = 48;
                v25 = (int)(v43 + 1);
                goto LABEL_190;
              }
LABEL_191:
              if ( no_output != 0 )
                goto LABEL_217;
              if ( (flags & 0x40) != 0 )
              {
                if ( (flags & 0x100) != 0 )
                {
                  prefix[0] = 45;
                  goto LABEL_199;
                }
                if ( (flags & 1) != 0 )
                {
                  prefix[0] = 43;
                  goto LABEL_199;
                }
                if ( (flags & 2) != 0 )
                {
                  prefix[0] = 32;
LABEL_199:
                  prefixlen = 1;
                }
              }
              v46 = fldwidth - radix - prefixlen;
              if ( (flags & 0xC) == 0 )
                write_multi_char(pnumwritten: &charsout, ch: 32, num: fldwidth - radix - prefixlen, f);
              v47 = f;
              write_string(string: prefix, f, pnumwritten: &charsout, len: prefixlen);
              if ( (flags & 8) != 0 && (flags & 4) == 0 )
                write_multi_char(pnumwritten: &charsout, ch: 48, num: v46, f: v47);
              if ( bufferiswide != 0 && radix > 0 )
              {
                v48 = string;
                count = radix;
                while ( 1 )
                {
                  v49 = *(_WORD *)v48;
                  --count;
                  v48 += 2;
                  if ( wctomb_s(pRetValue: &retval, dst: L_buffer, sizeInBytes: 6u, wchar: v49) != 0 || retval == 0 )
                    break;
                  write_string(string: L_buffer, f: v47, pnumwritten: &charsout, len: retval);
                  if ( count == 0 )
                    goto LABEL_214;
                }
                charsout = -1;
              }
              else
              {
                write_string(string, f: v47, pnumwritten: &charsout, len: radix);
              }
LABEL_214:
              if ( charsout >= 0 && (flags & 4) != 0 )
                write_multi_char(pnumwritten: &charsout, ch: 32, num: v46, f: v47);
              goto LABEL_217;
            }
            LODWORD(v27) = *(v28 - 1);
            if ( (flags & 0x40) != 0 )
              v27 = (int)v27;
            else
              HIDWORD(v27) = 0;
          }
          v72 = (char *)v28;
          goto LABEL_158;
        }
        v26 = (_WORD *)*v5;
        v72 = (char *)(v5 + 1);
        if ( !_get_printf_count_output() )
          goto LABEL_221;
        if ( (flags & 0x20) != 0 )
          *v26 = charsout;
        else
          *(_DWORD *)v26 = charsout;
        no_output = 1;
LABEL_217:
        if ( heapbuf != nullptr )
        {
          free(pMem: heapbuf);
          heapbuf = nullptr;
        }
LABEL_219:
        v4 = v65;
        v50 = *v65;
        v76 = *v65;
        if ( v76 == 0 )
          goto LABEL_222;
        v12 = state;
        v5 = (int *)v72;
        v11 = v50;
        break;
      default:
        goto LABEL_219;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041897C
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg(
        void (__cdecl *enull)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))
{
  __pInvalidArgHandler = enull;
}

//------------------------------------------------------------------------------
// Address: 0x00418986
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(
        unsigned int a1@<eax>,
        unsigned int a2@<edx>,
        unsigned int a3@<ecx>,
        unsigned int a4@<ebx>,
        unsigned int a5@<edi>,
        unsigned int a6@<esi>)
{
  unsigned int v6; // kr00_4
  BOOL v7; // esi
  HANDLE CurrentProcess; // eax
  _EXCEPTION_RECORD ExceptionRecord; // [esp+4h] [ebp-80h] BYREF
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+54h] [ebp-30h] BYREF
  _CONTEXT ContextRecord; // [esp+5Ch] [ebp-28h] BYREF
  unsigned int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  ContextRecord.Eax = a1;
  ContextRecord.Ecx = a3;
  ContextRecord.Edx = a2;
  ContextRecord.Ebx = a4;
  ContextRecord.Esi = a6;
  ContextRecord.Edi = a5;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  ContextRecord.EFlags = v6;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Ebp = savedregs;
  memset(dst: (int)&ExceptionRecord, value: nullptr, count: sizeof(ExceptionRecord));
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionRecord.ExceptionCode = -1073741811;
  ExceptionRecord.ExceptionAddress = retaddr;
  ExceptionPointers.ContextRecord = &ContextRecord;
  v7 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers) == 0 && !v7 )
    _crt_debugger_hook(_Reserved: 2);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC000000D);
}

//------------------------------------------------------------------------------
// Address: 0x00418A82
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int a3@<esi>)
{
  void (*v3)(void); // eax
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // [esp-4h] [ebp-4h]

  v3 = (void (*)(void))_decode_pointer(codedptr: __pInvalidArgHandler);
  if ( v3 == nullptr )
  {
    _crt_debugger_hook(_Reserved: 2);
    _invoke_watson(a1: v4, a2: v5, a3: v6, a4: a1, a5: a2, a6: a3);
  }
  v3();
}

//------------------------------------------------------------------------------
// Address: 0x00418AA6
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x00418AE1
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x00418AF4
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x00418B07
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x00418B25
// Name: fastcopy_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fastcopy_I(__m128i *dst, const __m128i *src, unsigned int len)
{
  unsigned int v5; // ecx
  __m128i si128; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm3
  __m128i v9; // xmm5
  __m128i v10; // xmm6
  __m128i v11; // xmm7

  v5 = len >> 7;
  do
  {
    si128 = _mm_load_si128(src + 1);
    v7 = _mm_load_si128(src + 2);
    v8 = _mm_load_si128(src + 3);
    *dst = _mm_load_si128(src);
    dst[1] = si128;
    dst[2] = v7;
    dst[3] = v8;
    v9 = _mm_load_si128(src + 5);
    v10 = _mm_load_si128(src + 6);
    v11 = _mm_load_si128(src + 7);
    dst[4] = _mm_load_si128(src + 4);
    dst[5] = v9;
    dst[6] = v10;
    dst[7] = v11;
    src += 8;
    dst += 8;
    --v5;
  }
  while ( v5 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00418BAC
// Name: __VEC_memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__m128i *__cdecl _VEC_memcpy(__m128i *dst, const __m128i *src, unsigned int len)
{
  int v3; // ecx
  __m128i *result; // eax
  int v5; // ecx
  unsigned int v6; // [esp+4h] [ebp-18h]

  v3 = (int)src % 16;
  result = dst;
  if ( (((int)dst % 16) | ((int)src % 16)) != 0 )
  {
    if ( v3 == (int)dst % 16 )
    {
      qmemcpy(dst, src, 16 - v3);
      _VEC_memcpy(dst: &dst->m128i_i8[16 - v3], src: &src->m128i_i8[16 - v3], len: len - (16 - v3));
    }
    else
    {
      qmemcpy(dst, src, len);
    }
    return dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastcopy_I(dst, src, len: len - v5);
      result = dst;
      v5 = v6;
    }
    if ( v5 != 0 )
    {
      qmemcpy(&result->m128i_i8[len - v5], &src->m128i_i8[len - v5], v6);
      return dst;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418C8F
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  char *v2; // esi
  bool i; // zf
  char v4; // al
  char *v5; // esi
  char v6; // cl
  char v7; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buffer;
  for ( i = tolower(c: *buffer) == 101; !i; i = isdigit(c: (unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower(c: *v2) == 120 )
    v2 += 2;
  v4 = *v2;
  *v2 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = v4;
    v4 = v6;
    v7 = *v5++;
  }
  while ( v7 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x00418D00
// Name: __cropzeros_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char *v2; // eax
  char i; // cl
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *v7; // edx
  char v8; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buf;
  for ( i = *buf; *v2 != 0; i = *++v2 )
  {
    if ( i == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *v5;
      if ( *v5 == 0 || v6 == 101 || v6 == 69 )
        break;
      ++v5;
    }
    v7 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v8 = *v7;
      ++v5;
      ++v7;
      *v5 = v8;
    }
    while ( v8 != 0 );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x00418D80
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _positive(long double *arg)
{
  return *arg >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00418D96
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign_l(_CRT_FLOAT flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE doubletemp; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) != 0 )
  {
    _atodbl_l(d: &doubletemp, str: number, plocinfo);
    *(_CRT_DOUBLE *)argument = doubletemp;
  }
  else
  {
    _atoflt_l(d: &flag, str: number, plocinfo);
    *(_CRT_FLOAT *)argument = flag;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418DD6
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign(int flag, char *argument, char *number)
{
  _fassign_l((_CRT_FLOAT)flag, argument, number, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00418DED
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(char *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist != 0 )
  {
    strlen(buf: s);
    memmove(dst: (unsigned __int8 *)&s[dist], src: (unsigned __int8 *)s, count: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418E0A
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt(char *buffer)
{
  _forcdecpt_l(buffer, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00418E18
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros(char *buf)
{
  _cropzeros_l(buf, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00418E26
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int *v8; // eax
  int v10; // eax
  char *v11; // esi
  char *v12; // esi
  unsigned int v13; // ebx
  unsigned int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  unsigned __int8 *v17; // ecx
  _BYTE *v18; // esi
  int v19; // eax
  _BYTE *v20; // esi
  _BYTE *v21; // esi
  unsigned int v22; // [esp-4h] [ebp-20h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v22 = 22;
LABEL_3:
    *v8 = v22;
    _invalid_parameter(a1: (unsigned int)buf, a2: v22, a3: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v22;
  }
  if ( ndec <= 0 )
    v10 = 0;
  else
    v10 = ndec;
  if ( sizeInBytes <= v10 + 9 )
  {
    v8 = _errno();
    v22 = 34;
    goto LABEL_3;
  }
  if ( g_fmt != 0 )
    shift(s: &buf[pflt->sign == 45], dist: ndec > 0);
  v11 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v11 = buf + 1;
  }
  if ( ndec > 0 )
  {
    *v11 = v11[1];
    *++v11 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  }
  v12 = &v11[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v13 = -1;
  else
    v13 = sizeInBytes + buf - v12;
  v14 = strcpy_s(_Dst: v12, _SizeInBytes: v13, _Src: "e+000");
  if ( v14 != 0 )
    _invoke_watson(a1: v14, a2: v15, a3: v16, a4: 0, a5: (unsigned int)pflt, a6: (unsigned int)v12);
  v17 = (unsigned __int8 *)(v12 + 2);
  if ( caps != 0 )
    *v12 = 69;
  v18 = v12 + 1;
  if ( *pflt->mantissa != 48 )
  {
    v19 = pflt->decpt - 1;
    if ( v19 < 0 )
    {
      v19 = 1 - pflt->decpt;
      *v18 = 45;
    }
    v20 = v18 + 1;
    if ( v19 >= 100 )
    {
      *v20 += v19 / 100;
      v19 %= 100;
    }
    v21 = v20 + 1;
    if ( v19 >= 10 )
    {
      *v21 += v19 / 10;
      LOBYTE(v19) = v19 % 10;
    }
    v21[1] += v19;
  }
  if ( (_outputformat & 1) != 0 && *v17 == 48 )
    memmove(dst: v17, src: v17 + 1, count: 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418F93
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  unsigned int v7; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( sizeInBytes == -1 )
      v7 = -1;
    else
      v7 = sizeInBytes - (retstrflt.sign == 45) - (ndec > 0);
    result = _fptostr(
               buf: &buf[(retstrflt.sign == 45) + (ndec > 0)],
               sizeInBytes: v7,
               digits: ndec + 1,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)buf, a3: 0x16u);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419061
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _cftoe(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, int caps)
{
  return _cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0041907F
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _cftoa_l@<eax>(
        unsigned int a1@<ebx>,
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v7; // esi
  int *v8; // eax
  unsigned int result; // eax
  unsigned int v10; // eax
  bool v11; // zf
  _BYTE *v12; // esi
  _BYTE *v13; // eax
  _BYTE *v14; // esi
  _BYTE *v15; // esi
  char *v16; // esi
  char *v17; // eax
  char *v18; // esi
  int x_low; // eax
  unsigned __int16 v20; // ax
  unsigned int v21; // ecx
  char *i; // eax
  _BYTE *v23; // esi
  __int64 v24; // rax
  __int64 v25; // rcx
  _BYTE *v26; // esi
  _BYTE *v27; // edi
  __int64 v28; // rax
  __int64 v29; // rcx
  __int64 v30; // rax
  __int64 v31; // rcx
  __int64 v32; // rcx
  __int64 v33; // [esp-Ch] [ebp-38h]
  unsigned int v34; // [esp-4h] [ebp-30h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-24h] BYREF
  __int64 exponent; // [esp+18h] [ebp-14h]
  unsigned __int64 mask; // [esp+20h] [ebp-Ch]
  int maskpos; // [esp+28h] [ebp-4h]
  char *pos; // [esp+38h] [ebp+Ch]

  LODWORD(exponent) = 1023;
  maskpos = 48;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v7 = buf;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v34 = 22;
LABEL_5:
    *v8 = v34;
    _invalid_parameter(a1, a2: 0, a3: v34);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v34;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v8 = _errno();
    v34 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v10 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v10 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf: buf + 2, sizeInBytes: v10, ndec, caps: 0);
    if ( result != 0 )
    {
      v11 = !_loc_update.updated;
      *buf = 0;
      if ( !v11 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v7 = buf + 1;
    }
    *v7 = 48;
    v12 = v7 + 1;
    *v12 = caps == 0 ? 120 : 88;
    strrchr(string: v12 + 1, chr: 0x65u);
    if ( v13 != nullptr )
    {
      *v13 = caps == 0 ? 112 : 80;
      v13[3] = 0;
    }
  }
  else
  {
    if ( (HIDWORD(pvalue->x) & 0x80000000) != 0 )
    {
      *buf = 45;
      v7 = buf + 1;
    }
    *v7 = 48;
    v14 = v7 + 1;
    *v14 = caps == 0 ? 120 : 88;
    v15 = v14 + 1;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      *v15 = 49;
      v16 = v15 + 1;
    }
    else
    {
      *v15 = 48;
      v16 = v15 + 1;
      if ( (HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x)) != 0 )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v17 = v16;
    v18 = v16 + 1;
    pos = v17;
    if ( ndec != 0 )
      *v17 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v17 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(mask) != 0 || x_low != 0 )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        v20 = ((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48;
        if ( v20 > 0x39u )
          LOBYTE(v20) = (caps != 0 ? 7 : 39) + v20;
        v21 = HIDWORD(mask);
        maskpos -= 4;
        *v18++ = v20;
        --ndec;
        mask = __PAIR64__(v21, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0
        && (unsigned __int16)((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) > 8u )
      {
        for ( i = v18 - 1; *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == pos )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = caps != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( ndec > 0 )
    {
      memset(dst: (int)v18, value: (unsigned __int8 *)0x30, count: ndec);
      v18 += ndec;
    }
    if ( *pos == 0 )
      v18 = pos;
    *v18 = caps == 0 ? 112 : 80;
    v23 = v18 + 1;
    HIDWORD(v25) = 0;
    v24 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v24 < 0 )
    {
      *v23 = 45;
      v26 = v23 + 1;
      v24 = -v24;
    }
    else
    {
      *v23 = 43;
      v26 = v23 + 1;
    }
    v27 = v26;
    *v26 = 48;
    if ( v24 >= 0 )
    {
      LODWORD(v25) = 1000;
      if ( v24 >= 1000 )
      {
        v33 = v25;
        v29 = v24 % v25;
        v28 = v24 / v33;
        *v26++ = v28 + 48;
        HIDWORD(exponent) = HIDWORD(v28);
        v24 = v29;
        if ( v26 != v27 )
          goto LABEL_60;
      }
    }
    if ( v24 >= 100 )
    {
LABEL_60:
      v31 = v24 % 100;
      v30 = v24 / 100;
      *v26 = v30 + 48;
      HIDWORD(exponent) = HIDWORD(v30);
      ++v26;
      v24 = v31;
    }
    if ( v26 != v27 || v24 >= 10 )
    {
      v32 = v24 % 10;
      *v26++ = v24 / 10 + 48;
      LOBYTE(v24) = v24 % 10;
      HIDWORD(exponent) = HIDWORD(v32);
    }
    *v26 = v24 + 48;
    v26[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004193F0
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftof2_l@<eax>(
        char *buf@<ecx>,
        _strflt *pflt@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v8; // esi
  char *v10; // eax
  char *v11; // esi
  int decpt; // eax
  char *v13; // esi
  int v14; // ebx
  char *v15; // esi
  int v16; // ebx
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( g_fmt != 0 && v8 == ndec )
    {
      v10 = &buf[v8 + (pflt->sign == 45)];
      *v10 = 48;
      v10[1] = 0;
    }
    v11 = buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v11 = buf + 1;
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = &v11[decpt];
    }
    else
    {
      shift(s: v11, dist: 1);
      *v11 = 48;
      v13 = v11 + 1;
    }
    if ( ndec > 0 )
    {
      shift(s: v13, dist: 1);
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      v14 = pflt->decpt;
      v15 = v13 + 1;
      if ( v14 < 0 )
      {
        v16 = -v14;
        if ( g_fmt != 0 || ndec >= v16 )
          ndec = v16;
        shift(s: v15, dist: ndec);
        memset(dst: (int)v15, value: (unsigned __int8 *)0x30, count: ndec);
      }
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: (unsigned int)pflt, a2: (unsigned int)buf, a3: 0x16u);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004194E5
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v6 = sizeInBytes, sizeInBytes != 0) )
  {
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (retstrflt.sign == 45);
    result = _fptostr(
               buf: &buf[retstrflt.sign == 45],
               sizeInBytes: v6,
               digits: ndec + retstrflt.decpt,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)buf, a3: 0x16u);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041959E
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  unsigned int v7; // ecx
  BOOL v8; // eax
  char *v9; // edi
  _strflt retstrflt; // [esp+Ch] [ebp-30h] BYREF
  int g_magnitude; // [esp+1Ch] [ebp-20h]
  char resstr[24]; // [esp+20h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    g_magnitude = retstrflt.decpt - 1;
    v8 = retstrflt.sign == 45;
    v9 = &buf[v8];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v8;
    result = _fptostr(buf: v9, sizeInBytes: v7, digits: ndec, pflt: &retstrflt);
    if ( result != 0 )
    {
      *buf = 0;
    }
    else if ( retstrflt.decpt - 1 < -4 || retstrflt.decpt - 1 >= ndec )
    {
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 1, plocinfo);
    }
    else
    {
      if ( g_magnitude < retstrflt.decpt - 1 )
        v9[strlen(v9) - 1] = 0;
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: 0x16u, a3: (unsigned int)buf);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041975C
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _setdefaultprecision@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // edx
  unsigned int v4; // ecx

  result = _controlfp_s(_CurrentState: nullptr, newctrl: 0x10000u, mask: 0x30000u);
  if ( result != 0 )
    _invoke_watson(a1: result, a2: v3, a3: v4, a4: a1, a5: a2, a6: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419785
// Name: __ms_p5_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ms_p5_test_fdiv()
{
  return 4195835.0 - 4195835.0 / 3145727.0 * 3145727.0 > 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004197C1
// Name: __ms_p5_mp_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ms_p5_mp_test_fdiv()
{
  HMODULE ModuleHandleA; // eax
  BOOL (__stdcall *IsProcessorFeaturePresent)(DWORD); // eax

  ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32");
  if ( ModuleHandleA != nullptr
    && (IsProcessorFeaturePresent = (BOOL (__stdcall *)(DWORD))GetProcAddress(
                                                                 hModule: ModuleHandleA,
                                                                 lpProcName: "IsProcessorFeaturePresent")) != nullptr )
  {
    return IsProcessorFeaturePresent(ProcessorFeature: 0);
  }
  else
  {
    return _ms_p5_test_fdiv();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041994F
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  unsigned int v0; // esi
  void (__cdecl *sigabrt)(int); // eax
  unsigned int v2; // edx
  unsigned int v3; // ecx
  unsigned int v4; // kr00_4
  unsigned int v5; // [esp-4h] [ebp-88h]
  _EXCEPTION_RECORD ExceptionRecord; // [esp+4h] [ebp-80h] BYREF
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+54h] [ebp-30h] BYREF
  _CONTEXT ContextRecord; // [esp+5Ch] [ebp-28h] BYREF
  unsigned int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  if ( (__abort_behavior & 1) != 0 )
    _NMSG_WRITE(rterrnum: 10);
  sigabrt = __get_sigabrt();
  if ( sigabrt != nullptr )
  {
    sigabrt = (void (__cdecl *)(int))raise(signum: 22);
    v3 = v5;
  }
  if ( (__abort_behavior & 2) != 0 )
  {
    ContextRecord.Eax = (unsigned int)sigabrt;
    ContextRecord.Ecx = v3;
    ContextRecord.Edx = v2;
    ContextRecord.Esi = v0;
    LOWORD(ContextRecord.SegSs) = __SS__;
    LOWORD(ContextRecord.SegCs) = __CS__;
    LOWORD(ContextRecord.SegDs) = __DS__;
    LOWORD(ContextRecord.SegEs) = __ES__;
    LOWORD(ContextRecord.SegFs) = __FS__;
    LOWORD(ContextRecord.SegGs) = __GS__;
    v4 = __readeflags();
    ContextRecord.EFlags = v4;
    ContextRecord.Esp = (unsigned int)&retaddr;
    ContextRecord.ContextFlags = 65537;
    ContextRecord.Eip = (unsigned int)retaddr;
    ContextRecord.Ebp = savedregs;
    memset(dst: (int)&ExceptionRecord, value: nullptr, count: sizeof(ExceptionRecord));
    ExceptionPointers.ExceptionRecord = &ExceptionRecord;
    ExceptionRecord.ExceptionCode = 1073741845;
    ExceptionRecord.ExceptionAddress = retaddr;
    ExceptionPointers.ContextRecord = &ContextRecord;
    SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
    UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers);
  }
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x00419A42
// Name: __set_abort_behavior
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior(unsigned int flags, unsigned int mask)
{
  unsigned int result; // eax

  result = __abort_behavior;
  __abort_behavior = mask & flags | __abort_behavior & ~mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00419A60
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  unsigned int i; // edi
  unsigned int v2; // eax
  unsigned int v3; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // ecx
  HANDLE StdHandle; // eax
  void *v19; // ebp
  DWORD v20; // eax
  unsigned int NumberOfBytesWritten; // [esp+Ch] [ebp-4h] BYREF

  for ( i = 0; i < 0x17; ++i )
  {
    if ( rterrnum == rterrs[i].rterrno )
      break;
  }
  if ( i < 0x17 )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v19 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        strlen(buf: rterrs[i].rterrtxt);
        WriteFile(
          hFile: v19,
          lpBuffer: rterrs[i].rterrtxt,
          nNumberOfBytesToWrite: v20,
          lpNumberOfBytesWritten: &NumberOfBytesWritten,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      v2 = strcpy_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: "Runtime Error!\n\nProgram: ");
      if ( v2 != 0 )
        _invoke_watson(a1: v2, a2: v3, a3: v4, a4: 0x314u, a5: i, a6: 0);
      outmsg[285] = 0;
      if ( GetModuleFileNameA(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0
        && strcpy_s(_Dst: &outmsg[25], _SizeInBytes: 0x2FBu, _Src: "<program name unknown>") != 0 )
      {
        _invoke_watson(a1: 0, a2: v5, a3: v6, a4: 0x314u, a5: i, a6: (unsigned int)&outmsg[25]);
      }
      strlen(buf: &outmsg[25]);
      if ( (unsigned int)(v7 + 1) > 0x3C )
      {
        strlen(buf: &outmsg[25]);
        v9 = strncpy_s(
               _Dst: &outmsg[v8 - 34],
               _SizeInBytes: (char *)&gpFlsAlloc - &outmsg[v8 - 34],
               _Src: "...",
               _Count: 3u);
        if ( v9 != 0 )
          _invoke_watson(a1: v9, a2: v10, a3: v11, a4: 0x314u, a5: i, a6: 0);
      }
      v12 = strcat_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: "\n\n");
      if ( v12 != 0 )
        _invoke_watson(a1: v12, a2: v13, a3: v14, a4: 0x314u, a5: i, a6: 0);
      v15 = strcat_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: rterrs[i].rterrtxt);
      if ( v15 != 0 )
        _invoke_watson(a1: v15, a2: v16, a3: v17, a4: 0x314u, a5: i, a6: 0);
      __crtMessageBoxA(lpText: outmsg, lpCaption: "Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419C00
// Name: __FF_MSGBANNER
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _FF_MSGBANNER()
{
  if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
  {
    _NMSG_WRITE(rterrnum: 252);
    _NMSG_WRITE(rterrnum: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419C39
// Name: _use_encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl use_encode_pointer()
{
  unsigned int v0; // ebx
  HMODULE ModuleHandleA; // eax
  char *v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // eax
  int bEncode; // [esp+8h] [ebp-8h]
  int winmajor; // [esp+Ch] [ebp-4h] BYREF

  v0 = 0;
  bEncode = 1;
  winmajor = 0;
  _get_winmajor(pValue: (unsigned int *)&winmajor);
  if ( winmajor > 5 )
    return 1;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  v3 = (char *)ModuleHandleA + *((_DWORD *)ModuleHandleA + 15);
  v4 = (unsigned __int8 *)&v3[*((unsigned __int16 *)v3 + 10) + 24];
  if ( *((_WORD *)v3 + 3) != 0 )
  {
    while ( 1 )
    {
      strcmp(str1: ".mixcrt", str2: v4);
      if ( v5 == 0 )
        break;
      ++v0;
      v4 += 40;
      if ( v0 >= *((unsigned __int16 *)v3 + 3) )
        return bEncode;
    }
    return 0;
  }
  return bEncode;
}

//------------------------------------------------------------------------------
// Address: 0x00419CA5
// Name: __encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __cdecl _encode_pointer(void *ptr)
{
  int (__stdcall *Value)(unsigned int); // eax
  int v2; // eax
  PVOID (__stdcall *EncodePointer)(PVOID); // eax
  HMODULE ModuleHandleA; // esi
  unsigned int v6; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr
    && __flsindex != -1
    && (v6 = __flsindex,
        Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex),
        (v2 = Value(a1: v6)) != 0) )
  {
    EncodePointer = *(PVOID (__stdcall **)(PVOID))(v2 + 504);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
    if ( ModuleHandleA == nullptr || use_encode_pointer() == 0 )
      return ptr;
    EncodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "EncodePointer");
  }
  if ( EncodePointer != nullptr )
    return EncodePointer(Ptr: ptr);
  return ptr;
}

//------------------------------------------------------------------------------
// Address: 0x00419D13
// Name: __encoded_null
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __cdecl _encoded_null()
{
  return _encode_pointer(ptr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00419D1C
// Name: __decode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __cdecl _decode_pointer(void *codedptr)
{
  int (__stdcall *Value)(unsigned int); // eax
  int v2; // eax
  PVOID (__stdcall *DecodePointer)(PVOID); // eax
  HMODULE ModuleHandleA; // esi
  unsigned int v6; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr
    && __flsindex != -1
    && (v6 = __flsindex,
        Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex),
        (v2 = Value(a1: v6)) != 0) )
  {
    DecodePointer = *(PVOID (__stdcall **)(PVOID))(v2 + 508);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
    if ( ModuleHandleA == nullptr || use_encode_pointer() == 0 )
      return codedptr;
    DecodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "DecodePointer");
  }
  if ( DecodePointer != nullptr )
    return DecodePointer(Ptr: codedptr);
  return codedptr;
}

//------------------------------------------------------------------------------
// Address: 0x00419D8A
// Name: __crtTlsAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall __crtTlsAlloc(void (__stdcall *lpCallBack)(void *))
{
  return TlsAlloc();
}

//------------------------------------------------------------------------------
// Address: 0x00419D93
// Name: ___set_flsgetvalue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *(__stdcall *__cdecl __set_flsgetvalue())(unsigned int)
{
  void *Value; // esi

  Value = TlsGetValue(dwTlsIndex: __getvalueindex);
  if ( Value == nullptr )
  {
    Value = _decode_pointer(codedptr: gpFlsGetValue);
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: Value);
  }
  return (void *(__stdcall *)(unsigned int))Value;
}

//------------------------------------------------------------------------------
// Address: 0x00419DC5
// Name: __mtterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _mtterm()
{
  void (__stdcall *v0)(unsigned int); // eax
  unsigned int v2; // [esp-4h] [ebp-4h]

  if ( __flsindex != -1 )
  {
    v2 = __flsindex;
    v0 = (void (__stdcall *)(unsigned int))_decode_pointer(codedptr: gpFlsFree);
    v0(a1: v2);
    __flsindex = -1;
  }
  if ( __getvalueindex != -1 )
  {
    TlsFree(dwTlsIndex: __getvalueindex);
    __getvalueindex = -1;
  }
  return _mtdeletelocks();
}

//------------------------------------------------------------------------------
// Address: 0x00419E02
// Name: __initptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initptd(_tiddata *ptd, threadlocaleinfostruct *ptloci)
{
  HINSTANCE__ *hKernel32; // [esp+10h] [ebp-1Ch]

  hKernel32 = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
  ptd->_pxcptacttab = _XcptActTab;
  ptd->_holdrand = 1;
  if ( hKernel32 != nullptr && use_encode_pointer() != 0 )
  {
    ptd->_encode_ptr = GetProcAddress(hModule: hKernel32, lpProcName: "EncodePointer");
    ptd->_decode_ptr = GetProcAddress(hModule: hKernel32, lpProcName: "DecodePointer");
  }
  ptd->_ownlocale = 1;
  ptd->_setloc_data._cachein[0] = 67;
  ptd->_setloc_data._cacheout[0] = 67;
  ptd->ptmbcinfo = &__initialmbcinfo;
  InterlockedIncrement(lpAddend: &__initialmbcinfo.refcount);
  _lock(locknum: 12);
  ptd->ptlocinfo = ptloci;
  if ( ptloci == nullptr )
    ptd->ptlocinfo = __ptlocinfo;
  __addlocaleref(ptloci: ptd->ptlocinfo);
  _unlock(locknum: 12);
}

//------------------------------------------------------------------------------
// Address: 0x00419EC1
// Name: __getptd_noexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd_noexit()
{
  DWORD LastError; // eax
  DWORD v1; // edi
  void *(__stdcall *v2)(unsigned int); // eax
  _tiddata *v3; // esi
  _tiddata *v4; // eax
  int (__stdcall *v5)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v8; // [esp-8h] [ebp-10h]
  unsigned int v9; // [esp-4h] [ebp-Ch]
  _tiddata *v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = __flsindex;
  v1 = LastError;
  v2 = __set_flsgetvalue();
  v3 = (_tiddata *)v2(a1: v9);
  if ( v3 == nullptr )
  {
    v4 = (_tiddata *)calloc(count: 1u, size: 0x214u);
    v3 = v4;
    if ( v4 != nullptr )
    {
      v10 = v4;
      v8 = __flsindex;
      v5 = (int (__stdcall *)(unsigned int, _tiddata *))_decode_pointer(codedptr: gpFlsSetValue);
      if ( v5(a1: v8, a2: v10) != 0 )
      {
        _initptd(ptd: v3, ptloci: nullptr);
        CurrentThreadId = GetCurrentThreadId();
        v3->_thandle = -1;
        v3->_tid = CurrentThreadId;
      }
      else
      {
        free(pMem: v3);
        v3 = nullptr;
      }
    }
  }
  SetLastError(dwErrCode: v1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00419F38
// Name: __getptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd()
{
  _tiddata *v0; // esi

  v0 = _getptd_noexit();
  if ( v0 == nullptr )
    _amsg_exit(rterrnum: 16);
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x00419F50
// Name: _freefls(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _freefls(void *data)
{
  threadmbcinfostruct *v1; // edi
  threadlocaleinfostruct *v2; // edi
  int savedregs; // [esp+28h] [ebp+0h]

  if ( data != nullptr )
  {
    if ( *((_DWORD *)data + 9) != 0 )
      free(pMem: *((void **)data + 9));
    if ( *((_DWORD *)data + 11) != 0 )
      free(pMem: *((void **)data + 11));
    if ( *((_DWORD *)data + 13) != 0 )
      free(pMem: *((void **)data + 13));
    if ( *((_DWORD *)data + 15) != 0 )
      free(pMem: *((void **)data + 15));
    if ( *((_DWORD *)data + 17) != 0 )
      free(pMem: *((void **)data + 17));
    if ( *((_DWORD *)data + 18) != 0 )
      free(pMem: *((void **)data + 18));
    if ( *((_XCPT_ACTION **)data + 23) != _XcptActTab )
      free(pMem: *((void **)data + 23));
    _lock(locknum: 13);
    v1 = *((threadmbcinfostruct **)data + 26);
    if ( v1 != nullptr && InterlockedDecrement(lpAddend: *((volatile LONG **)data + 26)) == 0 && v1 != &__initialmbcinfo )
      free(pMem: v1);
    _unlock(locknum: 13);
    _lock(locknum: 12);
    v2 = *((threadlocaleinfostruct **)data + 27);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: *((threadlocaleinfostruct **)data + 27));
      if ( v2 != __ptlocinfo && v2 != &__initiallocinfo && v2->refcount == 0 )
        __freetlocinfo(ptloci: v2);
    }
    savedregs = 4300874;
    _unlock(locknum: 12);
    free(pMem: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A071
// Name: __mtinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinit()
{
  HMODULE ModuleHandleA; // eax
  HMODULE v1; // edi
  BOOL (__stdcall *FlsFree)(DWORD); // eax
  DWORD v4; // eax
  int (__stdcall *v5)(_DWORD); // eax
  _tiddata *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v10; // [esp-Ch] [ebp-10h]
  _tiddata *v11; // [esp-8h] [ebp-Ch]

  ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
  v1 = ModuleHandleA;
  if ( ModuleHandleA == nullptr )
  {
    _mtterm();
    return 0;
  }
  gpFlsAlloc = (unsigned int (__stdcall *)(void (__stdcall *)(void *)))GetProcAddress(
                                                                         hModule: ModuleHandleA,
                                                                         lpProcName: "FlsAlloc");
  gpFlsGetValue = (void *(__stdcall *)(unsigned int))GetProcAddress(hModule: v1, lpProcName: "FlsGetValue");
  gpFlsSetValue = (int (__stdcall *)(unsigned int, void *))GetProcAddress(hModule: v1, lpProcName: "FlsSetValue");
  FlsFree = (BOOL (__stdcall *)(DWORD))GetProcAddress(hModule: v1, lpProcName: "FlsFree");
  gpFlsFree = FlsFree;
  if ( gpFlsAlloc == nullptr || gpFlsGetValue == nullptr || gpFlsSetValue == nullptr || FlsFree == nullptr )
  {
    gpFlsGetValue = TlsGetValue;
    gpFlsAlloc = __crtTlsAlloc;
    gpFlsSetValue = TlsSetValue;
    gpFlsFree = TlsFree;
  }
  v4 = TlsAlloc();
  __getvalueindex = v4;
  if ( v4 != -1 && TlsSetValue(dwTlsIndex: v4, lpTlsValue: gpFlsGetValue) )
  {
    _init_pointers();
    gpFlsAlloc = (unsigned int (__stdcall *)(void (__stdcall *)(void *)))_encode_pointer(ptr: gpFlsAlloc);
    gpFlsGetValue = (void *(__stdcall *)(unsigned int))_encode_pointer(ptr: gpFlsGetValue);
    gpFlsSetValue = (int (__stdcall *)(unsigned int, void *))_encode_pointer(ptr: gpFlsSetValue);
    gpFlsFree = (int (__stdcall *)(unsigned int))_encode_pointer(ptr: gpFlsFree);
    if ( _mtinitlocks() != 0 )
    {
      v5 = (int (__stdcall *)(_DWORD))_decode_pointer(codedptr: gpFlsAlloc);
      __flsindex = v5(a1: _freefls);
      if ( __flsindex != -1 )
      {
        v6 = (_tiddata *)calloc(count: 1u, size: 0x214u);
        v7 = v6;
        if ( v6 != nullptr )
        {
          v11 = v6;
          v10 = __flsindex;
          v8 = (int (__stdcall *)(unsigned int, _tiddata *))_decode_pointer(codedptr: gpFlsSetValue);
          if ( v8(a1: v10, a2: v11) != 0 )
          {
            _initptd(ptd: v7, ptloci: nullptr);
            CurrentThreadId = GetCurrentThreadId();
            v7->_thandle = -1;
            v7->_tid = CurrentThreadId;
            return 1;
          }
        }
      }
    }
    _mtterm();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A1F5
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void (__cdecl *enull)())
{
  __pPurecall = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0041A1FF
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _amsg_exit(int rterrnum)
{
  void (__cdecl *v1)(int); // eax

  _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  v1 = (void (__cdecl *)(int))_decode_pointer(codedptr: _aexit_rtn);
  v1(a1: 255);
}

//------------------------------------------------------------------------------
// Address: 0x0041A223
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleA; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleA = GetModuleHandleA(lpModuleName: "mscoree.dll");
  if ( ModuleHandleA != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleA, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A249
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x0041A25E
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x0041A267
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x0041A270
// Name: _initterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall initterm(void (__cdecl **pfbegin)()@<eax>, void (__cdecl **pfend)())
{
  while ( pfbegin < pfend )
  {
    if ( *pfbegin != nullptr )
      (*pfbegin)();
    ++pfbegin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A288
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && result == 0 )
  {
    if ( *pfbegin != nullptr )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041A2A8
// Name: __get_osplatform
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_osplatform@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int *pValue)
{
  if ( pValue != nullptr && _osplatform != 0 )
  {
    *pValue = _osplatform;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A2DF
// Name: __get_winmajor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_winmajor@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int *pValue)
{
  if ( pValue != nullptr && _osplatform != 0 )
  {
    *pValue = _winmajor;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A31B
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // esi

  if ( _fpmath != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) != 0 )
    _fpmath(initPrecision: initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(pfbegin: __xi_a, pfend: __xi_z);
  if ( result == 0 )
  {
    atexit(func: _RTC_Terminate);
    for ( i = __xc_a; i < __xc_z; ++i )
    {
      if ( *i != nullptr )
        (*i)();
    }
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) != 0 )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041A3AD
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  void **v3; // esi
  PVOID v4; // edi
  void (*v5)(void); // eax
  void (__cdecl **onexitbegin)(); // [esp+14h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      onexitbegin = (void (__cdecl **)())_decode_pointer(codedptr: __onexitbegin);
      v3 = (void **)_decode_pointer(codedptr: __onexitend);
      if ( onexitbegin != nullptr )
      {
        while ( --v3 >= (void **)onexitbegin )
        {
          if ( *v3 != nullptr )
          {
            v4 = *v3;
            if ( v4 != _encoded_null() )
            {
              v5 = (void (*)(void))_decode_pointer(codedptr: v4);
              v5();
            }
          }
        }
      }
      initterm(pfbegin: __xp_a, pfend: __xp_z);
    }
    initterm(pfbegin: __xt_a, pfend: __xt_z);
  }
  if ( retcaller != 0 )
    _unlock(locknum: 8);
  if ( retcaller == 0 )
  {
    _C_Exit_Done = 1;
    _unlock(locknum: 8);
    __crtExitProcess(status: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A48F
// Name: _exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn exit(int code)
{
  doexit(code, quick: 0, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041A4A0
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041A4B1
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041A4C0
// Name: __c_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _c_exit()
{
  doexit(code: 0, quick: 1, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041A4CF
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *_init_pointers())(int)
{
  PVOID v0; // esi
  void (__cdecl *result)(int); // eax

  v0 = _encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_initcrit(enull: v0);
  _initp_misc_invarg(enull: (void (__cdecl *)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))v0);
  _initp_misc_purevirt(enull: (void (__cdecl *)())v0);
  _initp_misc_rand_s(enull: v0);
  _initp_misc_winsig(enull: v0);
  _initp_misc_winxfltr();
  _initp_eh_hooks(enull: v0);
  result = (void (__cdecl *)(int))_encode_pointer(ptr: _exit);
  _aexit_rtn = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041A561
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x0041A716
// Name: long __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS *pPtrs)
{
  _EXCEPTION_RECORD *ExceptionRecord; // eax
  unsigned int v2; // eax

  ExceptionRecord = pPtrs->ExceptionRecord;
  if ( pPtrs->ExceptionRecord->ExceptionCode == -529697949 && ExceptionRecord->NumberParameters == 3 )
  {
    v2 = ExceptionRecord->ExceptionInformation[0];
    if ( v2 == 429065504 || v2 == 429065505 || v2 == 429065506 || v2 == 26820608 )
      terminate();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A753
// Name: ___CxxSetUnhandledExceptionFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __CxxSetUnhandledExceptionFilter()
{
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: __CxxUnhandledExceptionFilter);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A761
// Name: __XcptFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _XcptFilter(unsigned int xcptnum, _EXCEPTION_POINTERS *pxcptinfoptrs)
{
  int result; // eax
  _DWORD *v3; // esi
  int *v4; // edx
  int *v5; // ecx
  int *v6; // eax
  void (__cdecl *v7)(int); // ebx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  void *oldpxcptinfoptrs; // [esp+4h] [ebp-8h]

  result = (int)_getptd_noexit();
  v3 = (_DWORD *)result;
  if ( result != 0 )
  {
    v4 = *(int **)(result + 92);
    v5 = v4;
    do
    {
      if ( *v5 == xcptnum )
        break;
      v5 += 3;
    }
    while ( v5 < &v4[3 * _XcptActTabCount] );
    if ( v5 < &v4[3 * _XcptActTabCount] && *v5 == xcptnum )
      v6 = v5;
    else
      v6 = nullptr;
    if ( v6 != nullptr && (v7 = (void (__cdecl *)(int))v6[2]) != nullptr )
    {
      if ( v7 == (void (__cdecl *)(int))5 )
      {
        v6[2] = 0;
        return 1;
      }
      else
      {
        if ( v7 != (void (__cdecl *)(int))1 )
        {
          oldpxcptinfoptrs = (void *)v3[24];
          v3[24] = pxcptinfoptrs;
          v8 = v6[1];
          if ( v8 == 8 )
          {
            v9 = _First_FPE_Indx;
            if ( _First_FPE_Indx < _First_FPE_Indx + _Num_FPE )
            {
              v10 = 12 * _First_FPE_Indx;
              do
              {
                *(_DWORD *)(v10 + v3[23] + 8) = 0;
                ++v9;
                v10 += 12;
              }
              while ( v9 < _First_FPE_Indx + _Num_FPE );
            }
            v11 = *v6;
            v12 = v3[25];
            switch ( v11 )
            {
              case -1073741682:
                v3[25] = 131;
                break;
              case -1073741680:
                v3[25] = 129;
                break;
              case -1073741679:
                v3[25] = 132;
                break;
              case -1073741677:
                v3[25] = 133;
                break;
              case -1073741683:
                v3[25] = 130;
                break;
              case -1073741681:
                v3[25] = 134;
                break;
              case -1073741678:
                v3[25] = 138;
                break;
              default:
                break;
            }
            v7(a1: 8);
            v3[25] = v12;
          }
          else
          {
            v6[2] = 0;
            v7(a1: v8);
          }
          v3[24] = oldpxcptinfoptrs;
        }
        return -1;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041A8BF
// Name: __wincmdln
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl _wincmdln()
{
  BOOL v0; // edi
  const char *v1; // esi
  unsigned __int8 v2; // al

  v0 = false;
  if ( __mbctype_initialized == 0 )
    __initmbctable();
  v1 = _acmdln;
  if ( _acmdln == nullptr )
    v1 = defaultValue;
  while ( 1 )
  {
    v2 = *v1;
    if ( *v1 <= 0x20u )
    {
      if ( v2 == 0 )
        return v1;
      if ( !v0 )
        break;
    }
    if ( v2 == 34 )
      v0 = !v0;
    if ( _ismbblead(tst: v2) != 0 )
      ++v1;
    ++v1;
  }
  while ( *v1 != 0 && *v1 <= 0x20u )
    ++v1;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A91C
// Name: __setenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setenvp()
{
  char *v0; // esi
  int v1; // edi
  int v3; // eax
  char **v4; // edi
  char *i; // esi
  int v6; // eax
  unsigned int v7; // ebp
  char *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  v0 = _aenvptr;
  v1 = 0;
  if ( _aenvptr != nullptr )
  {
    while ( *v0 != 0 )
    {
      if ( *v0 != 61 )
        ++v1;
      strlen(buf: v0);
      v0 += v3 + 1;
    }
    v4 = (char **)calloc(count: v1 + 1, size: 4u);
    _environ = v4;
    if ( v4 != nullptr )
    {
      for ( i = _aenvptr; ; i += v7 )
      {
        if ( *i == 0 )
        {
          free(pMem: _aenvptr);
          _aenvptr = nullptr;
          *v4 = nullptr;
          __env_initialized = 1;
          return 0;
        }
        strlen(buf: i);
        v7 = v6 + 1;
        if ( *i != 61 )
          break;
LABEL_16:
        ;
      }
      v8 = (char *)calloc(count: v6 + 1, size: 1u);
      *v4 = v8;
      if ( v8 != nullptr )
      {
        v9 = strcpy_s(_Dst: v8, _SizeInBytes: v7, _Src: i);
        if ( v9 != 0 )
          _invoke_watson(a1: v9, a2: v10, a3: v11, a4: 0, a5: (unsigned int)v4, a6: (unsigned int)i);
        ++v4;
        goto LABEL_16;
      }
      free(pMem: _environ);
      _environ = nullptr;
      return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A9F7
// Name: parse_cmdline
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall parse_cmdline(char *cmdstart@<edx>, int *numchars@<edi>, char **argv, char *args, int *numargs)
{
  int *v5; // ecx
  char *v7; // edx
  char **v8; // ebx
  char v9; // bl
  char *v10; // ecx
  char **v11; // eax
  int v12; // ebx
  unsigned int v13; // ecx
  char v14; // al
  char *v15; // ecx
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-10h]
  BOOL inquote; // [esp+8h] [ebp-4h]
  BOOL inquotea; // [esp+8h] [ebp-4h]

  v5 = numargs;
  *numchars = 0;
  v7 = args;
  *numargs = 1;
  if ( argv != nullptr )
  {
    v8 = argv++;
    *v8 = args;
  }
  inquote = false;
  do
  {
    if ( *cmdstart == 34 )
    {
      v9 = 34;
      ++cmdstart;
      inquote = !inquote;
    }
    else
    {
      ++*numchars;
      if ( v7 != nullptr )
      {
        *v7 = *cmdstart;
        args = v7 + 1;
      }
      v9 = *cmdstart;
      v17 = (unsigned __int8)*cmdstart++;
      if ( _ismbblead(tst: v17) != 0 )
      {
        ++*numchars;
        if ( args != nullptr )
        {
          v10 = args++;
          *v10 = *cmdstart;
        }
        ++cmdstart;
      }
      v7 = args;
      v5 = numargs;
      if ( v9 == 0 )
      {
        --cmdstart;
        goto LABEL_18;
      }
    }
  }
  while ( inquote || v9 != 32 && v9 != 9 );
  if ( v7 != nullptr )
    *(v7 - 1) = 0;
LABEL_18:
  inquotea = false;
  while ( *cmdstart != 0 )
  {
    while ( *cmdstart == 32 || *cmdstart == 9 )
      ++cmdstart;
    if ( *cmdstart == 0 )
      break;
    if ( argv != nullptr )
    {
      v11 = argv++;
      *v11 = v7;
    }
    ++*v5;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *cmdstart == 92 )
      {
        ++cmdstart;
        ++v13;
      }
      if ( *cmdstart == 34 )
      {
        if ( (v13 & 1) == 0 )
        {
          if ( inquotea && cmdstart[1] == 34 )
          {
            ++cmdstart;
          }
          else
          {
            v12 = 0;
            inquotea = !inquotea;
          }
        }
        v13 >>= 1;
      }
      if ( v13 != 0 )
      {
        do
        {
          --v13;
          if ( v7 != nullptr )
            *v7++ = 92;
          ++*numchars;
        }
        while ( v13 != 0 );
        args = v7;
      }
      v14 = *cmdstart;
      if ( *cmdstart == 0 || !inquotea && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 != 0 )
      {
        if ( v7 != nullptr )
        {
          if ( _ismbblead(tst: v14) != 0 )
          {
            v15 = args++;
            *v15 = *cmdstart++;
            ++*numchars;
          }
          v16 = args++;
          *v16 = *cmdstart;
        }
        else if ( _ismbblead(tst: v14) != 0 )
        {
          ++cmdstart;
          ++*numchars;
        }
        ++*numchars;
        v7 = args;
      }
      ++cmdstart;
    }
    if ( v7 != nullptr )
    {
      *v7++ = 0;
      args = v7;
    }
    ++*numchars;
    v5 = numargs;
  }
  if ( argv != nullptr )
    *argv = nullptr;
  ++*v5;
}

//------------------------------------------------------------------------------
// Address: 0x0041AB8F
// Name: __setargv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setargv()
{
  bool v0; // zf
  int v1; // edi
  unsigned int v2; // eax
  char **v3; // esi
  int numchars; // [esp+Ch] [ebp-Ch] BYREF
  int numargs; // [esp+10h] [ebp-8h] BYREF
  char *cmdstart; // [esp+14h] [ebp-4h]

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  pgmname[260] = 0;
  GetModuleFileNameA(hModule: nullptr, lpFilename: pgmname, nSize: 0x104u);
  _pgmptr = pgmname;
  if ( _acmdln == nullptr || (v0 = *_acmdln == 0, cmdstart = _acmdln, v0) )
    cmdstart = pgmname;
  parse_cmdline(cmdstart, &numchars, argv: nullptr, args: nullptr, &numargs);
  if ( (unsigned int)numargs >= 0x3FFFFFFF )
    return -1;
  if ( numchars == -1 )
    return -1;
  v1 = numargs;
  v2 = 4 * numargs + numchars;
  if ( v2 < numchars )
    return -1;
  v3 = (char **)operator new(nSize: v2);
  if ( v3 == nullptr )
    return -1;
  parse_cmdline(cmdstart, &numchars, argv: v3, args: (char *)&v3[v1], &numargs);
  __argc = numargs - 1;
  __argv = v3;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041AC48
// Name: ___crtGetEnvironmentStringsA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __crtGetEnvironmentStringsA()
{
  int v0; // eax
  char *v1; // ebx
  WCHAR *EnvironmentStringsW; // esi
  WCHAR *i; // eax
  unsigned int v5; // eax
  int v6; // ebp
  char *v7; // eax
  LPCH EnvironmentStrings; // eax
  char *v9; // esi
  unsigned int v10; // ebp
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // edi
  char *nSizeW; // [esp+10h] [ebp-8h]
  int cchWideChar; // [esp+14h] [ebp-4h]

  v0 = f_use_0;
  v1 = nullptr;
  EnvironmentStringsW = nullptr;
  if ( f_use_0 == 0 )
  {
    EnvironmentStringsW = GetEnvironmentStringsW();
    if ( EnvironmentStringsW != nullptr )
    {
      f_use_0 = 1;
      goto LABEL_8;
    }
    if ( GetLastError() == 120 )
    {
      v0 = 2;
      f_use_0 = 2;
    }
    else
    {
      v0 = f_use_0;
    }
  }
  if ( v0 == 1 )
  {
LABEL_8:
    if ( EnvironmentStringsW == nullptr )
    {
      EnvironmentStringsW = GetEnvironmentStringsW();
      if ( EnvironmentStringsW == nullptr )
        return nullptr;
    }
    for ( i = EnvironmentStringsW; *i != 0; ++i )
    {
      do
        ++i;
      while ( *i != 0 );
    }
    cchWideChar = i - EnvironmentStringsW + 1;
    v5 = WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: EnvironmentStringsW,
           cchWideChar,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    v6 = v5;
    if ( v5 != 0 )
    {
      v7 = (char *)operator new(nSize: v5);
      nSizeW = v7;
      if ( v7 != nullptr )
      {
        if ( WideCharToMultiByte(
               CodePage: 0,
               dwFlags: 0,
               lpWideCharStr: EnvironmentStringsW,
               cchWideChar,
               lpMultiByteStr: v7,
               cbMultiByte: v6,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: nullptr) == 0 )
        {
          free(pMem: nSizeW);
          nSizeW = nullptr;
        }
        v1 = nSizeW;
      }
    }
    FreeEnvironmentStringsW(penv: EnvironmentStringsW);
    return (unsigned __int8 *)v1;
  }
  if ( v0 != 2 && v0 != 0 )
    return nullptr;
  EnvironmentStrings = GetEnvironmentStrings();
  v9 = EnvironmentStrings;
  if ( EnvironmentStrings == nullptr )
    return nullptr;
  for ( ; *EnvironmentStrings != 0; ++EnvironmentStrings )
  {
    do
      ++EnvironmentStrings;
    while ( *EnvironmentStrings != 0 );
  }
  v10 = EnvironmentStrings - v9 + 1;
  v11 = (unsigned __int8 *)operator new(nSize: v10);
  v12 = v11;
  if ( v11 == nullptr )
  {
    FreeEnvironmentStringsA(penv: v9);
    return nullptr;
  }
  memcpy(dst: v11, src: (unsigned __int8 *)v9, count: v10);
  FreeEnvironmentStringsA(penv: v9);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x0041AD7D
// Name: __ioinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ioinit()
{
  ioinfo *v0; // eax
  ioinfo *i; // ecx
  int v2; // edi
  unsigned __int8 *v3; // ebx
  int v4; // esi
  ioinfo *v5; // eax
  ioinfo *j; // edx
  ioinfo *v7; // esi
  int k; // ebx
  ioinfo *v9; // esi
  DWORD v10; // eax
  HANDLE StdHandle; // eax
  int v12; // edi
  DWORD FileType; // eax
  _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-64h] BYREF
  int fh; // [esp+54h] [ebp-20h]
  int *posfhnd; // [esp+58h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+5Ch] [ebp-18h]

  ms_exc.registration.TryLevel = 0;
  GetStartupInfoA(lpStartupInfo: &StartupInfo);
  ms_exc.registration.TryLevel = -2;
  v0 = (ioinfo *)calloc(count: 0x20u, size: 0x38u);
  if ( v0 == nullptr )
    return -1;
  __pioinfo[0] = v0;
  _nhandle = 32;
  for ( i = v0 + 32; v0 < i; i = __pioinfo[0] + 32 )
  {
    v0->osfile = 0;
    v0->osfhnd = -1;
    v0->pipech = 10;
    v0->lockinitflag = 0;
    *((_BYTE *)v0 + 36) = 0;
    v0->pipech2[0] = 10;
    v0->pipech2[1] = 10;
    ++v0;
  }
  if ( StartupInfo.cbReserved2 != 0 && StartupInfo.lpReserved2 != nullptr )
  {
    v2 = *(_DWORD *)StartupInfo.lpReserved2;
    v3 = StartupInfo.lpReserved2 + 4;
    posfhnd = (int *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    if ( v2 >= 2048 )
      v2 = 2048;
    v4 = 1;
    while ( (int)_nhandle < v2 )
    {
      v5 = (ioinfo *)calloc(count: 0x20u, size: 0x38u);
      if ( v5 == nullptr )
      {
        v2 = _nhandle;
        break;
      }
      __pioinfo[v4] = v5;
      _nhandle += 32;
      for ( j = v5 + 32; v5 < j; j = __pioinfo[v4] + 32 )
      {
        v5->osfile = 0;
        v5->osfhnd = -1;
        v5->pipech = 10;
        v5->lockinitflag = 0;
        *((_BYTE *)v5 + 36) &= 0x80u;
        v5->pipech2[0] = 10;
        v5->pipech2[1] = 10;
        ++v5;
      }
      ++v4;
    }
    for ( fh = 0; fh < v2; ++posfhnd )
    {
      if ( *posfhnd != -1
        && *posfhnd != -2
        && (*v3 & 1) != 0
        && ((*v3 & 8) != 0 || GetFileType(hFile: (HANDLE)*posfhnd) != 0) )
      {
        v7 = &__pioinfo[fh >> 5][fh & 0x1F];
        v7->osfhnd = *posfhnd;
        v7->osfile = *v3;
        if ( __crtInitCritSecAndSpinCount(lpCriticalSection: &v7->lock, dwSpinCount: 0xFA0u) == 0 )
          return -1;
        ++v7->lockinitflag;
      }
      ++fh;
      ++v3;
    }
  }
  for ( k = 0; k < 3; ++k )
  {
    v9 = &__pioinfo[0][k];
    if ( v9->osfhnd == -1 || v9->osfhnd == -2 )
    {
      v9->osfile = -127;
      if ( k != 0 )
        v10 = -(k != 1) - 11;
      else
        v10 = -10;
      StdHandle = GetStdHandle(nStdHandle: v10);
      v12 = (int)StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle != nullptr && (FileType = GetFileType(hFile: StdHandle)) != 0 )
      {
        v9->osfhnd = v12;
        if ( (unsigned __int8)FileType == 2 )
        {
          v9->osfile |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          v9->osfile |= 8u;
        }
        if ( __crtInitCritSecAndSpinCount(lpCriticalSection: &v9->lock, dwSpinCount: 0xFA0u) == 0 )
          return -1;
        ++v9->lockinitflag;
      }
      else
      {
        v9->osfile |= 0x40u;
        v9->osfhnd = -2;
      }
    }
    else
    {
      v9->osfile |= 0x80u;
    }
  }
  SetHandleCount(uNumber: _nhandle);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041AFBD
// Name: __RTC_Initialize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Initialize()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0041AFE1
// Name: __RTC_Terminate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Terminate()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0041B005
// Name: ___security_init_cookie
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __security_init_cookie()
{
  unsigned int v0; // esi
  DWORD v1; // esi
  DWORD v2; // esi
  DWORD v3; // esi
  uintptr_t v4; // esi
  _LARGE_INTEGER perfctr; // [esp+8h] [ebp-10h] BYREF
  FT systime; // [esp+10h] [ebp-8h] BYREF

  systime.ft_scalar = 0;
  if ( __security_cookie == -1153374642 || (__security_cookie & 0xFFFF0000) == 0 )
  {
    GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&systime);
    v0 = systime.ft_struct.dwLowDateTime ^ systime.ft_struct.dwHighDateTime;
    v1 = GetCurrentProcessId() ^ v0;
    v2 = GetCurrentThreadId() ^ v1;
    v3 = GetTickCount() ^ v2;
    QueryPerformanceCounter(lpPerformanceCount: &perfctr);
    v4 = perfctr.LowPart ^ perfctr.HighPart ^ v3;
    if ( v4 == -1153374642 )
    {
      v4 = -1153374641;
    }
    else if ( (v4 & 0xFFFF0000) == 0 )
    {
      v4 |= v4 << 16;
    }
    __security_cookie = v4;
    __security_cookie_complement = ~v4;
  }
  else
  {
    __security_cookie_complement = ~__security_cookie;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B099
// Name: DebuggerProbe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall DebuggerProbe(void *dwLevelRequired)
{
  tagEXCEPTION_VISUALCPP_DEBUG_INFO info; // [esp+10h] [ebp-34h] BYREF
  unsigned __int8 bDebuggerListening; // [esp+2Bh] [ebp-19h] BYREF
  CPPEH_RECORD ms_exc; // [esp+2Ch] [ebp-18h]

  bDebuggerListening = 0;
  info.dwType = 4097;
  *(_QWORD *)&info.SetName.szName = __PAIR64__(&bDebuggerListening, (unsigned int)dwLevelRequired);
  ms_exc.registration.TryLevel = 0;
  RaiseException(dwExceptionCode: 0x406D1388u, dwExceptionFlags: 0, nNumberOfArguments: 6u, lpArguments: &info.dwType);
  return bDebuggerListening;
}

//------------------------------------------------------------------------------
// Address: 0x0041B0E9
// Name: DebuggerRuntime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl DebuggerRuntime(unsigned int bRealBug, void *pvReturnAddr, const wchar_t *pwMessage)
{
  const char *dwErrorNumber; // ecx
  tagEXCEPTION_VISUALCPP_DEBUG_INFO info; // [esp+10h] [ebp-34h] BYREF
  unsigned __int8 bDebuggerListening; // [esp+2Bh] [ebp-19h] BYREF
  CPPEH_RECORD ms_exc; // [esp+2Ch] [ebp-18h]

  bDebuggerListening = 0;
  info.dwType = 4098;
  info.SetName.szName = dwErrorNumber;
  *(_QWORD *)&info.RuntimeError[4] = __PAIR64__((unsigned int)pvReturnAddr, bRealBug);
  *(_DWORD *)&info.RuntimeError[12] = &bDebuggerListening;
  *(_DWORD *)&info.RuntimeError[16] = pwMessage;
  ms_exc.registration.TryLevel = 0;
  RaiseException(dwExceptionCode: 0x406D1388u, dwExceptionFlags: 0, nNumberOfArguments: 6u, lpArguments: &info.dwType);
  return bDebuggerListening;
}

//------------------------------------------------------------------------------
// Address: 0x0041B14B
// Name: failwithmessage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall failwithmessage(void *retaddr, const char *msg, int crttype, int errnum)
{
  unsigned int v6; // eax
  wchar_t *v7; // edi
  char v8; // al
  int v9; // eax
  int v10; // eax
  int v11; // eax
  bool v12; // zf
  char *v13; // eax
  int (*fn)(int, const char *, int, const char *, const char *, ...); // [esp+10h] [ebp-7Ch]
  int lineNum; // [esp+14h] [ebp-78h] BYREF
  char *srcName; // [esp+18h] [ebp-74h]
  wchar_t msgB[512]; // [esp+1Ch] [ebp-70h] BYREF
  char srcNameB[1040]; // [esp+41Ch] [ebp+390h] BYREF
  char moduleNameB[520]; // [esp+82Ch] [ebp+7A0h] BYREF
  wchar_t moduleNameW[260]; // [esp+A34h] [ebp+9A8h] BYREF
  wchar_t srcNameW[260]; // [esp+C3Ch] [ebp+BB0h] BYREF

  lineNum = (int)retaddr;
  fn = nullptr;
  srcName = (char *)_RTC_GetErrorFuncW(addr: retaddr);
  if ( srcName == nullptr )
    fn = _RTC_GetErrorFunc(addr: retaddr);
  v6 = MultiByteToWideChar(
         CodePage: 0xFDE9u,
         dwFlags: 0,
         lpMultiByteStr: msg,
         cbMultiByte: -1,
         lpWideCharStr: nullptr,
         cchWideChar: 0);
  if ( v6 >= 0x200
    || (v7 = msgB,
        MultiByteToWideChar(
          CodePage: 0xFDE9u,
          dwFlags: 0,
          lpMultiByteStr: msg,
          cbMultiByte: -1,
          lpWideCharStr: msgB,
          cchWideChar: v6) == 0) )
  {
    v7 = L"Runtime Check Error.\n\r Unable to display RTC Message.";
  }
  if ( DebuggerProbe(dwLevelRequired: (void *)0x1002) != 0 )
  {
    if ( DebuggerRuntime(bRealBug: RTC_NoFalsePositives[errnum], pvReturnAddr: (void *)lineNum, pwMessage: v7) != 0 )
      return;
    v8 = 0;
  }
  else
  {
    v8 = 1;
  }
  if ( fn == nullptr && srcName == nullptr || v8 != 0 && IsDebuggerPresent() )
    goto LABEL_25;
  _RTC_GetSrcLine(
    address: (unsigned __int8 *)(lineNum - 5),
    source: srcNameW,
    sourcelen: 0x104u,
    pline: &lineNum,
    moduleName: moduleNameW,
    modulelen: 0x104u);
  if ( srcName != nullptr )
  {
    v9 = ((int (*)(int, wchar_t *, int, wchar_t *, const wchar_t *, ...))srcName)(
           a1: crttype,
           a2: srcNameW,
           a3: lineNum,
           a4: moduleNameW,
           a5: L"Run-Time Check Failure #%d - %s",
           errnum,
           v7);
  }
  else
  {
    v10 = WideCharToMultiByte(
            CodePage: 0xFDE9u,
            dwFlags: 0,
            lpWideCharStr: srcNameW,
            cchWideChar: -1,
            lpMultiByteStr: nullptr,
            cbMultiByte: 0,
            lpDefaultChar: nullptr,
            lpUsedDefaultChar: nullptr);
    if ( v10 != 0
      && WideCharToMultiByte(
           CodePage: 0xFDE9u,
           dwFlags: 0,
           lpWideCharStr: srcNameW,
           cchWideChar: -1,
           lpMultiByteStr: srcNameB,
           cbMultiByte: v10,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr) != 0 )
    {
      srcName = srcNameB;
    }
    else
    {
      srcName = "Unknown Filename";
    }
    v11 = WideCharToMultiByte(
            CodePage: 0xFDE9u,
            dwFlags: 0,
            lpWideCharStr: moduleNameW,
            cchWideChar: -1,
            lpMultiByteStr: nullptr,
            cbMultiByte: 0,
            lpDefaultChar: nullptr,
            lpUsedDefaultChar: nullptr);
    if ( v11 == 0
      || (v12 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: moduleNameW,
                  cchWideChar: -1,
                  lpMultiByteStr: moduleNameB,
                  cbMultiByte: v11,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr) == 0,
          v13 = moduleNameB,
          v12) )
    {
      v13 = "Unknown Module Name";
    }
    v9 = fn(a1: crttype, a2: srcName, a3: lineNum, a4: v13, a5: "Run-Time Check Failure #%d - %s", errnum, msg);
  }
  if ( v9 == 1 )
LABEL_25:
    DebugBreak();
}

//------------------------------------------------------------------------------
// Address: 0x0041B339
// Name: void _RTC_Failure(void __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Failure(void *retaddr, unsigned int errnum)
{
  int v2; // ecx
  int v3; // eax
  const char *v4; // edx

  v2 = errnum;
  if ( errnum > 4 )
  {
    v4 = RTC_ErrorMessages[5];
    v3 = 1;
    v2 = 5;
  }
  else
  {
    v3 = _RTC_ErrorLevels[errnum];
    v4 = RTC_ErrorMessages[errnum];
  }
  if ( v3 != -1 )
    failwithmessage(retaddr, msg: v4, crttype: v3, errnum: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0041B371
// Name: void _RTC_StackFailure(void __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_StackFailure(void *retaddr, const char *varname)
{
  char *v2; // ebx
  int v3; // ecx
  char v4; // al
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  unsigned int v8; // eax
  char *v9; // edi
  char v10; // cl
  void *v11; // [esp+4h] [ebp-408h] BYREF
  char msgB[1024]; // [esp+8h] [ebp-404h] BYREF

  v11 = retaddr;
  if ( crttype != -1 )
  {
    if ( *varname != 0 && strlen(varname) + 45 <= 0x400 )
    {
      v2 = msgB;
      v3 = 0;
      do
      {
        v4 = stack_premsg[v3];
        msgB[v3++] = v4;
      }
      while ( v4 != 0 );
      v5 = strlen(varname) + 1;
      v6 = (char *)&v11 + 3;
      do
        v7 = *++v6;
      while ( v7 != 0 );
      qmemcpy(v6, varname, v5);
      v8 = strlen("' was corrupted.") + 1;
      v9 = (char *)&v11 + 3;
      do
        v10 = *++v9;
      while ( v10 != 0 );
      qmemcpy(v9, "' was corrupted.", v8);
    }
    else
    {
      v2 = "Stack corrupted near unknown variable";
    }
    failwithmessage(retaddr: v11, msg: v2, crttype: crttype, errnum: 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B462
// Name: _getMemBlockDataString
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl getMemBlockDataString(char *printbuff, char *valbuff, char *data, unsigned int datasize)
{
  char *v4; // edi
  unsigned int v5; // esi
  int v6; // eax
  unsigned int v7; // ecx
  unsigned __int8 v8; // bl
  char *v9; // [esp+10h] [ebp-4h]

  v9 = valbuff;
  v4 = printbuff;
  v5 = 0;
  v6 = data - printbuff;
  while ( 1 )
  {
    v7 = datasize;
    if ( datasize >= 0x10 )
      v7 = 16;
    if ( v5 >= v7 )
      break;
    v8 = v4[v6];
    wsprintffp(a1: v9, a2: "%.2X ", v8);
    v9 += 3;
    v6 = data - printbuff;
    *v4 = v8;
    ++v5;
    ++v4;
  }
  printbuff[v5] = 0;
  valbuff[3 * v5] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B4C7
// Name: void _RTC_AllocaFailure(void __near *,struct _RTC_ALLOCA_NODE __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_AllocaFailure(void *retaddr, _RTC_ALLOCA_NODE *pn, int num)
{
  int v3; // ebx
  HMODULE LibraryA; // eax
  int (*wsprintfA)(LPSTR, LPCSTR, ...); // eax
  int v6; // eax
  char msg[244]; // [esp+10h] [ebp-140h] BYREF
  char valbuff[52]; // [esp+104h] [ebp-4Ch] BYREF
  char printbuff[20]; // [esp+138h] [ebp-18h] BYREF

  v3 = dword_43F0C8;
  if ( dword_43F0C8 != -1 )
  {
    LibraryA = LoadLibraryA(lpLibFileName: "user32.dll");
    if ( LibraryA != nullptr
      && (wsprintfA = (int (*)(LPSTR, LPCSTR, ...))GetProcAddress(hModule: LibraryA, lpProcName: "wsprintfA"),
          wsprintffp = wsprintfA,
          pn != nullptr)
      && wsprintfA != nullptr )
    {
      wsprintfA(
        a1: msg,
        a2: "%s%s%p%s%ld%s%d%s",
        "Stack area around _alloca memory reserved by this function is corrupted",
        "\nAddress: 0x",
        &pn[1],
        "\nSize: ",
        pn->allocaSize - 36,
        "\nAllocation number within this function: ",
        num,
        "\nData: <");
      getMemBlockDataString(printbuff, valbuff, data: (char *)&pn[1], datasize: pn->allocaSize - 36);
      v6 = lstrlenA(lpString: msg);
      wsprintffp(a1: &msg[v6], a2: "%s%s%s%s", printbuff, "> ", valbuff, "\n");
      failwithmessage(retaddr, msg, crttype: v3, errnum: 4);
    }
    else
    {
      failwithmessage(
        retaddr,
        msg: "Stack area around _alloca memory reserved by this function is corrupted\n",
        crttype: v3,
        errnum: 4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B5E4
// Name: int (*_RTC_GetErrorFunc(void const __near *))(int,char const __near *,int,char const __near *,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int (*__cdecl _RTC_GetErrorFunc())(int, const char *, int, const char *, const char *, ...)
{
  return RTC_ErrorReportFunc;
}

//------------------------------------------------------------------------------
// Address: 0x0041B5EA
// Name: int (*_RTC_GetErrorFuncW(void const __near *))(int,wchar_t const __near *,int,wchar_t const __near *,wchar_t const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int (*__cdecl _RTC_GetErrorFuncW())(int, const wchar_t *, int, const wchar_t *, const wchar_t *, ...)
{
  return RTC_ErrorReportFuncW;
}

//------------------------------------------------------------------------------
// Address: 0x0041B5F0
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x0041B5F6
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int osfhnd; // eax

  v0 = _nstream;
  if ( _nstream == 0 )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)calloc(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)calloc(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&__security_cookie )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_43F0F8;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_43F158 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B6A7
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pMem: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x0041B6C7
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_43F348 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(locknum: pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B703
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(locknum: i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B731
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_43F348 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(locknum: pf - _iob + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B767
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(locknum: i + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B791
// Name: __getdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getdrive()
{
  unsigned __int8 *v0; // ebx
  signed int CurrentDirectoryA; // esi
  char *v2; // eax
  int v3; // edi
  int memfree; // [esp+10h] [ebp-7Ch]
  char curdirstr[264]; // [esp+14h] [ebp-78h] BYREF

  memfree = 0;
  v0 = (unsigned __int8 *)curdirstr;
  CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x105u, lpBuffer: curdirstr);
  if ( CurrentDirectoryA > 260 )
  {
    v2 = (char *)calloc(count: CurrentDirectoryA + 1, size: 1u);
    v0 = (unsigned __int8 *)v2;
    if ( v2 != nullptr )
    {
      memfree = 1;
      CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: CurrentDirectoryA + 1, lpBuffer: v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryA = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryA != 0 )
  {
    if ( v0[1] == 58 )
      v3 = toupper(c: *v0) - 64;
  }
  else
  {
    *_errno() = 12;
  }
  if ( memfree != 0 )
    free(pMem: v0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041B857
// Name: __mtinitlocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocks()
{
  int v0; // esi
  _RTL_CRITICAL_SECTION *v1; // edi

  v0 = 0;
  v1 = lclcritsects;
  while ( 1 )
  {
    if ( *(&locktable + 2 * v0 + 1) == (LPCRITICAL_SECTION)1 )
    {
      *(&locktable + 2 * v0) = v1++;
      if ( __crtInitCritSecAndSpinCount(lpCriticalSection: *(&locktable + 2 * v0), dwSpinCount: 0xFA0u) == 0 )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&locktable + 2 * v0) = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B8A0
// Name: __mtdeletelocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _mtdeletelocks()
{
  LPCRITICAL_SECTION *v0; // esi
  LPCRITICAL_SECTION v1; // edi
  LPCRITICAL_SECTION *v2; // esi

  v0 = &locktable;
  do
  {
    v1 = *v0;
    if ( *v0 != nullptr && v0[1] != (LPCRITICAL_SECTION)1 )
    {
      DeleteCriticalSection(lpCriticalSection: *v0);
      free(pMem: v1);
      *v0 = nullptr;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)_lookuptrailbytes );
  v2 = &locktable;
  do
  {
    if ( *v2 != nullptr && v2[1] == (LPCRITICAL_SECTION)1 )
      DeleteCriticalSection(lpCriticalSection: *v2);
    v2 += 2;
  }
  while ( (int)v2 < (int)_lookuptrailbytes );
}

//------------------------------------------------------------------------------
// Address: 0x0041B8F5
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x0041B90A
// Name: __mtinitlocknum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocknum(int locknum)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 1;
  if ( _crtheap == nullptr )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(rterrnum: 30);
    __crtExitProcess(status: 255);
  }
  if ( *(&locktable + 2 * locknum) != nullptr )
    return 1;
  v2 = (_RTL_CRITICAL_SECTION *)operator new(nSize: 0x18u);
  if ( v2 != nullptr )
  {
    _lock(locknum: 10);
    if ( *(&locktable + 2 * locknum) != nullptr )
    {
      free(pMem: v2);
    }
    else if ( __crtInitCritSecAndSpinCount(lpCriticalSection: v2, dwSpinCount: 0xFA0u) != 0 )
    {
      *(&locktable + 2 * locknum) = v2;
    }
    else
    {
      free(pMem: v2);
      *_errno() = 12;
      retval = 0;
    }
    _unlock(locknum: 10);
    return retval;
  }
  else
  {
    *_errno() = 12;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B9CD
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock(int locknum)
{
  if ( *(&locktable + 2 * locknum) == nullptr && _mtinitlocknum(locknum) == 0 )
    _amsg_exit(rterrnum: 17);
  EnterCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x0041B9FE
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_nolock(int fh)
{
  int osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(fh) == -1
    || (fh == 1 && (__pioinfo[0][2].osfile & 1) != 0 || fh == 2 && (__pioinfo[0][1].osfile & 1) != 0)
    && (osfhandle = _get_osfhandle(fh: 2), _get_osfhandle(fh: 1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(fh), CloseHandle(hObject: v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  __pioinfo[fh >> 5][fh & 0x1F].osfile = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041BA92
// Name: __close
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _close@<eax>(unsigned int a1@<ebx>, int a2@<esi>, int fh)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0
    || fh >= _nhandle
    || (a1 = 4 * (fh >> 5) + 4534976, a2 = fh & 0x1F, (__pioinfo[fh >> 5][a2].osfile & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: a2 * 56);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (__pioinfo[fh >> 5][a2].osfile & 1) != 0 )
  {
    r = _close_nolock(fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x0041BB5F
// Name: __fileno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fileno@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_file;
  *_errno() = 22;
  _invalid_parameter(a1, a2, a3: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041BB8C
// Name: __freebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(pMem: stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = nullptr;
    stream->_base = nullptr;
    stream->_cnt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BBB8
// Name: __flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = _fileno(a1: 0, a2: (unsigned int)v4, stream: str);
      if ( (char *)_write(fh: v5, buf: v9, cnt: (unsigned int)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0041BC1A
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fflush_nolock@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *str)
{
  int v4; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v4 = _fileno(a1, a2, stream: str);
  return -(_commit(filedes: v4) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041BC5C
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall flsall@<eax>(unsigned int a1@<ebx>, int flushflag)
{
  int i; // esi
  char **v3; // eax
  char *v4; // eax
  int v5; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v3 = (char **)&__piob[i];
    if ( *v3 != nullptr )
    {
      v4 = *v3;
      if ( (v4[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v4);
        v5 = *((_DWORD *)__piob[i] + 3);
        if ( (v5 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(a1, a2: 0, str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v5 & 2) != 0 && _fflush_nolock(a1, a2: 0, str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BD36
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _flushall@<eax>(unsigned int a1@<ebx>)
{
  return flsall(a1, flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041BD3F
// Name: __filbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _filbuf@<eax>(unsigned int a1@<ebx>, _iobuf *str)
{
  int flag; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  _DWORD *v6; // edi
  ioinfo *v7; // eax
  int v8; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-10h]
  unsigned int bufsiz; // [esp-4h] [ebp-Ch]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2: 0, a3: 0);
    return -1;
  }
  flag = str->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return -1;
  if ( (flag & 2) != 0 )
  {
    str->_flag = flag | 0x20;
    return -1;
  }
  v3 = flag | 1;
  str->_flag = v3;
  if ( (v3 & 0x10C) != 0 )
    str->_ptr = str->_base;
  else
    _getbuf(str);
  bufsiz = str->_bufsiz;
  base = str->_base;
  v4 = _fileno(a1, a2: 0, stream: str);
  v5 = _read(fh: v4, buf: base, cnt: bufsiz);
  str->_cnt = v5;
  if ( v5 == 0 || v5 == -1 )
  {
    str->_flag |= v5 != 0 ? 32 : 16;
    str->_cnt = 0;
    return -1;
  }
  if ( (str->_flag & 0x82) == 0 )
  {
    if ( _fileno(a1, a2: 0, stream: str) == -1 || _fileno(a1, a2: 0, stream: str) == -2 )
    {
      v7 = &__badioinfo;
    }
    else
    {
      v6 = (_DWORD *)(4 * (_fileno(a1, a2: 0, stream: str) >> 5) + 4534976);
      v7 = (ioinfo *)(*v6 + 56 * (_fileno(a1, a2: (unsigned int)v6, stream: str) & 0x1F));
    }
    if ( (v7->osfile & 0x82) == 0x82 )
      str->_flag |= 0x2000u;
  }
  if ( str->_bufsiz == 512 )
  {
    v8 = str->_flag;
    if ( (v8 & 8) != 0 && (v8 & 0x400) == 0 )
      str->_bufsiz = 4096;
  }
  ptr = str->_ptr;
  --str->_cnt;
  result = (unsigned __int8)*ptr;
  str->_ptr = ptr + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BE5F
// Name: __read_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _read_nolock@<eax>(unsigned int a1@<edi>, int fh, _BYTE *inputbuf, unsigned int cnt)
{
  unsigned int v4; // edx
  int result; // eax
  int v6; // esi
  ioinfo *v7; // eax
  char osfile; // cl
  _BYTE *v9; // eax
  __int64 v10; // rax
  ioinfo *v11; // ecx
  ioinfo *v12; // ecx
  char pipech; // cl
  ioinfo *v14; // ecx
  bool v15; // zf
  char v16; // cl
  ioinfo *v17; // ecx
  char v18; // cl
  ioinfo *v19; // ecx
  ioinfo *v20; // eax
  char *p_osfile; // eax
  char *v22; // ebx
  bool v23; // cf
  char v24; // al
  char *v25; // eax
  char *v26; // ebx
  int v27; // ecx
  int v28; // eax
  char v29; // dl
  ioinfo *v30; // ecx
  char *v31; // ebx
  int v32; // ebx
  DWORD LastError; // eax
  ioinfo *v34; // edx
  BOOL v35; // ecx
  char *v36; // ebx
  __int16 v37; // cx
  char *v38; // esi
  unsigned int inputsize; // [esp+4h] [ebp-1Ch]
  int os_read; // [esp+8h] [ebp-18h] BYREF
  int retval; // [esp+Ch] [ebp-14h]
  int bytes_read; // [esp+10h] [ebp-10h]
  void *buf; // [esp+14h] [ebp-Ch]
  wchar_t wpeekchr; // [esp+18h] [ebp-8h] BYREF
  char tmode; // [esp+1Eh] [ebp-2h]
  char peekchr; // [esp+1Fh] [ebp-1h] BYREF
  char *p; // [esp+30h] [ebp+10h]
  char *pa; // [esp+30h] [ebp+10h]

  v4 = cnt;
  retval = -2;
  inputsize = cnt;
  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1: 0, a2: a1, a3: fh);
    return -1;
  }
  v6 = fh & 0x1F;
  v7 = &__pioinfo[fh >> 5][v6];
  osfile = v7->osfile;
  if ( (osfile & 1) == 0 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_19:
    _invalid_parameter(a1: 0, a2: 4 * (fh >> 5) + 4534976, a3: v6 * 56);
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
    goto LABEL_18;
  bytes_read = 0;
  if ( cnt == 0 || (osfile & 2) != 0 )
    return 0;
  if ( inputbuf == nullptr )
    goto LABEL_18;
  tmode = (char)(2 * *((_BYTE *)v7 + 36)) >> 1;
  if ( tmode != 1 )
  {
    if ( tmode != 2 )
    {
LABEL_16:
      v9 = inputbuf;
      buf = inputbuf;
      goto LABEL_26;
    }
    if ( (cnt & 1) == 0 )
    {
      cnt &= ~1u;
      goto LABEL_16;
    }
LABEL_18:
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_19;
  }
  if ( (cnt & 1) != 0 )
    goto LABEL_18;
  cnt = 4;
  if ( v4 >> 1 >= 4 )
    cnt = v4 >> 1;
  buf = operator new(nSize: cnt);
  if ( buf == nullptr )
  {
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  v10 = _lseeki64_nolock(fh, pos: 0, mthd: 1);
  v11 = __pioinfo[fh >> 5];
  LODWORD(v11[v6].startpos) = v10;
  v9 = buf;
  HIDWORD(v11[v6].startpos) = HIDWORD(v10);
LABEL_26:
  v12 = &__pioinfo[fh >> 5][v6];
  if ( (v12->osfile & 0x48) != 0 )
  {
    pipech = v12->pipech;
    if ( pipech != 10 && cnt != 0 )
    {
      *v9 = pipech;
      v14 = __pioinfo[fh >> 5];
      ++v9;
      --cnt;
      v15 = tmode == 0;
      bytes_read = 1;
      v14[v6].pipech = 10;
      if ( !v15 )
      {
        v16 = __pioinfo[fh >> 5][v6].pipech2[0];
        if ( v16 != 10 && cnt != 0 )
        {
          *v9 = v16;
          v17 = __pioinfo[fh >> 5];
          ++v9;
          --cnt;
          v15 = tmode == 1;
          bytes_read = 2;
          v17[v6].pipech2[0] = 10;
          if ( v15 )
          {
            v18 = __pioinfo[fh >> 5][v6].pipech2[1];
            if ( v18 != 10 && cnt != 0 )
            {
              *v9 = v18;
              v19 = __pioinfo[fh >> 5];
              ++v9;
              --cnt;
              bytes_read = 3;
              v19[v6].pipech2[1] = 10;
            }
          }
        }
      }
    }
  }
  if ( !ReadFile(
          hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
          lpBuffer: v9,
          nNumberOfBytesToRead: cnt,
          lpNumberOfBytesRead: (LPDWORD)&os_read,
          lpOverlapped: nullptr)
    || os_read < 0
    || os_read > cnt )
  {
    LastError = GetLastError();
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
      goto LABEL_93;
    }
    if ( LastError == 109 )
    {
      retval = 0;
      goto error_return;
    }
    goto LABEL_92;
  }
  v20 = __pioinfo[fh >> 5];
  bytes_read += os_read;
  p_osfile = &v20[v6].osfile;
  if ( *p_osfile < 0 )
  {
    if ( tmode != 2 )
    {
      if ( os_read != 0 && *(_BYTE *)buf == 10 )
        *p_osfile |= 4u;
      else
        *p_osfile &= ~4u;
      v22 = (char *)buf;
      v23 = buf < (char *)buf + bytes_read;
      p = (char *)buf;
      bytes_read += (int)buf;
      if ( v23 )
      {
        do
        {
          v24 = *p;
          if ( *p == 26 )
          {
            v25 = &__pioinfo[fh >> 5][v6].osfile;
            if ( (*v25 & 0x40) != 0 )
              *v22++ = *p;
            else
              *v25 |= 2u;
            break;
          }
          if ( v24 == 13 )
          {
            if ( (unsigned int)p < bytes_read - 1 )
            {
              if ( p[1] == 10 )
              {
                p += 2;
                goto LABEL_52;
              }
              ++p;
LABEL_63:
              *v22 = 13;
LABEL_64:
              ++v22;
              continue;
            }
            ++p;
            if ( !ReadFile(
                    hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
                    lpBuffer: &peekchr,
                    nNumberOfBytesToRead: 1u,
                    lpNumberOfBytesRead: (LPDWORD)&os_read,
                    lpOverlapped: nullptr)
              && GetLastError() != 0
              || os_read == 0 )
            {
              goto LABEL_63;
            }
            if ( (__pioinfo[fh >> 5][v6].osfile & 0x48) != 0 )
            {
              if ( peekchr != 10 )
              {
                *v22 = 13;
                __pioinfo[fh >> 5][v6].pipech = peekchr;
                goto LABEL_64;
              }
LABEL_52:
              *v22 = 10;
              goto LABEL_64;
            }
            if ( v22 == buf && peekchr == 10 )
              goto LABEL_52;
            _lseeki64_nolock(fh, pos: -1, mthd: 1);
            if ( peekchr != 10 )
              goto LABEL_63;
          }
          else
          {
            *v22++ = v24;
            ++p;
          }
        }
        while ( (unsigned int)p < bytes_read );
      }
      bytes_read = v22 - (_BYTE *)buf;
      if ( tmode != 1 || v22 == buf )
        goto error_return;
      v26 = v22 - 1;
      LOBYTE(v27) = *v26;
      if ( *v26 < 0 )
      {
        v28 = 1;
        v27 = (unsigned __int8)v27;
        while ( _lookuptrailbytes[v27] == 0 && v28 <= 4 && v26 >= buf )
        {
          v27 = (unsigned __int8)*--v26;
          ++v28;
        }
        v29 = *v26;
        if ( _lookuptrailbytes[(unsigned __int8)*v26] == 0 )
        {
          *_errno() = 42;
LABEL_93:
          retval = -1;
          goto error_return;
        }
        if ( _lookuptrailbytes[(unsigned __int8)*v26] + 1 == v28 )
        {
          v26 += v28;
        }
        else
        {
          v30 = &__pioinfo[fh >> 5][v6];
          if ( (v30->osfile & 0x48) != 0 )
          {
            v31 = v26 + 1;
            v30->pipech = v29;
            if ( v28 >= 2 )
              __pioinfo[fh >> 5][v6].pipech2[0] = *v31++;
            if ( v28 == 3 )
              __pioinfo[fh >> 5][v6].pipech2[1] = *v31++;
            v26 = &v31[-v28];
          }
          else
          {
            _lseeki64_nolock(fh, pos: -v28, mthd: 1);
          }
        }
      }
      else
      {
        ++v26;
      }
      v32 = v26 - (_BYTE *)buf;
      bytes_read = MultiByteToWideChar(
                     CodePage: 0xFDE9u,
                     dwFlags: 0,
                     lpMultiByteStr: (LPCCH)buf,
                     cbMultiByte: v32,
                     lpWideCharStr: (LPWSTR)inputbuf,
                     cchWideChar: inputsize >> 1);
      if ( bytes_read != 0 )
      {
        v34 = __pioinfo[fh >> 5];
        v35 = bytes_read != v32;
        bytes_read *= 2;
        v34[v6].utf8translations = v35;
        goto error_return;
      }
      LastError = GetLastError();
LABEL_92:
      _dosmaperr(oserrno: LastError);
      goto LABEL_93;
    }
    if ( os_read != 0 && *(_WORD *)buf == 10 )
      *p_osfile |= 4u;
    else
      *p_osfile &= ~4u;
    v36 = (char *)buf;
    v23 = buf < (char *)buf + bytes_read;
    pa = (char *)buf;
    bytes_read += (int)buf;
    if ( !v23 )
    {
LABEL_128:
      bytes_read = v36 - (_BYTE *)buf;
      goto error_return;
    }
    while ( 1 )
    {
      v37 = *(_WORD *)pa;
      if ( *(_WORD *)pa == 26 )
      {
        v38 = &__pioinfo[fh >> 5][v6].osfile;
        if ( (*v38 & 0x40) != 0 )
        {
          *(_WORD *)v36 = *(_WORD *)pa;
          v36 += 2;
        }
        else
        {
          *v38 |= 2u;
        }
        goto LABEL_128;
      }
      if ( v37 == 13 )
      {
        if ( (unsigned int)pa < bytes_read - 2 )
        {
          if ( *((_WORD *)pa + 1) == 10 )
          {
            pa += 4;
            goto LABEL_110;
          }
          pa += 2;
LABEL_121:
          *(_WORD *)v36 = 13;
LABEL_122:
          v36 += 2;
          goto LABEL_123;
        }
        pa += 2;
        if ( !ReadFile(
                hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
                lpBuffer: &wpeekchr,
                nNumberOfBytesToRead: 2u,
                lpNumberOfBytesRead: (LPDWORD)&os_read,
                lpOverlapped: nullptr)
          && GetLastError() != 0
          || os_read == 0 )
        {
          goto LABEL_121;
        }
        if ( (__pioinfo[fh >> 5][v6].osfile & 0x48) != 0 )
        {
          if ( wpeekchr != 10 )
          {
            *(_WORD *)v36 = 13;
            __pioinfo[fh >> 5][v6].pipech = wpeekchr;
            __pioinfo[fh >> 5][v6].pipech2[0] = HIBYTE(wpeekchr);
            __pioinfo[fh >> 5][v6].pipech2[1] = 10;
            goto LABEL_122;
          }
LABEL_110:
          *(_WORD *)v36 = 10;
          goto LABEL_122;
        }
        if ( v36 == buf && wpeekchr == 10 )
          goto LABEL_110;
        _lseeki64_nolock(fh, pos: -2, mthd: 1);
        if ( wpeekchr != 10 )
          goto LABEL_121;
      }
      else
      {
        *(_WORD *)v36 = v37;
        v36 += 2;
        pa += 2;
      }
LABEL_123:
      if ( (unsigned int)pa >= bytes_read )
        goto LABEL_128;
    }
  }
error_return:
  if ( buf != inputbuf )
    free(pMem: buf);
  result = retval;
  if ( retval == -2 )
    return bytes_read;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041C420
// Name: __read
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _read@<eax>(unsigned int a1@<ebx>, int a2@<esi>, int fh, _BYTE *buf, unsigned int cnt)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0
    || fh >= _nhandle
    || (a1 = 4 * (fh >> 5) + 4534976, a2 = fh & 0x1F, (__pioinfo[fh >> 5][a2].osfile & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_7:
    _invalid_parameter(a1, a2: 0, a3: a2 * 56);
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_7;
  }
  __lock_fhandle(fh);
  if ( (__pioinfo[fh >> 5][a2].osfile & 1) != 0 )
  {
    r = _read_nolock(a1: 0, fh, inputbuf: buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x0041C51D
// Name: _memcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall memcpy_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int8 *dst,
        unsigned int sizeInBytes,
        unsigned __int8 *src,
        unsigned int count)
{
  unsigned int v6; // esi

  if ( count == 0 )
    return 0;
  if ( dst != nullptr )
  {
    if ( src != nullptr && sizeInBytes >= count )
    {
      memcpy(dst, src, count);
      return 0;
    }
    memset((int)dst, value: nullptr, count: sizeInBytes);
    if ( src != nullptr )
    {
      if ( sizeInBytes < count )
      {
        *_errno() = 34;
        v6 = 34;
        goto LABEL_5;
      }
      return 22;
    }
  }
  v6 = 22;
  *_errno() = 22;
LABEL_5:
  _invalid_parameter(a1, a2: 0, a3: v6);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0041C598
// Name: __lseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _lseek_nolock(int fh, LONG pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD v5; // edi
  DWORD LastError; // eax
  char *p_osfile; // eax

  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return -1;
  }
  else
  {
    v5 = SetFilePointer(hFile: osfhandle, lDistanceToMove: pos, lpDistanceToMoveHigh: nullptr, dwMoveMethod: mthd);
    if ( v5 == -1 )
      LastError = GetLastError();
    else
      LastError = 0;
    if ( LastError != 0 )
    {
      _dosmaperr(oserrno: LastError);
      return -1;
    }
    else
    {
      p_osfile = &__pioinfo[fh >> 5][fh & 0x1F].osfile;
      *p_osfile &= ~2u;
      return v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C60A
// Name: __lseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __usercall _lseek@<eax>(unsigned int a1@<ebx>, int a2@<esi>, int fh, LONG pos, DWORD mthd)
{
  DWORD r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0
    || fh >= _nhandle
    || (a1 = 4 * (fh >> 5) + 4534976, a2 = fh & 0x1F, (__pioinfo[fh >> 5][a2].osfile & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: a2 * 56);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (__pioinfo[fh >> 5][a2].osfile & 1) != 0 )
  {
    r = _lseek_nolock(fh, pos, mthd);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x0041C6E6
// Name: __openfile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__usercall _openfile@<eax>(
        unsigned int a1@<edi>,
        const char *filename,
        const char *mode,
        int shflag,
        _iobuf *str)
{
  char v6; // al
  int v8; // ecx
  const unsigned __int8 *v9; // esi
  signed __int8 v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int filedes; // [esp+8h] [ebp-10h] BYREF
  int commodeset; // [esp+Ch] [ebp-Ch]
  int scanset; // [esp+10h] [ebp-8h]
  int streamflag; // [esp+14h] [ebp-4h]
  unsigned int modeflag; // [esp+24h] [ebp+Ch]

  streamflag = _commode;
  commodeset = 0;
  scanset = 0;
  filedes = 0;
  while ( *mode == 32 )
    ++mode;
  v6 = *mode;
  if ( *mode == 97 )
  {
    modeflag = 265;
LABEL_11:
    streamflag |= 2u;
    goto LABEL_12;
  }
  if ( v6 != 114 )
  {
    if ( v6 != 119 )
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: (unsigned int)mode);
      return nullptr;
    }
    modeflag = 769;
    goto LABEL_11;
  }
  streamflag |= 1u;
  modeflag = 0;
LABEL_12:
  v8 = 1;
  v9 = (const unsigned __int8 *)(mode + 1);
  v10 = *v9;
  if ( *v9 == 0 )
    goto LABEL_62;
  a1 = 0x4000;
  while ( v8 != 0 )
  {
    if ( v10 > 83 )
    {
      v16 = v10 - 84;
      if ( v16 == 0 )
      {
        if ( (modeflag & 0x1000) == 0 )
        {
          modeflag |= 0x1000u;
          goto LABEL_49;
        }
        goto LABEL_47;
      }
      v17 = v16 - 14;
      if ( v17 != 0 )
      {
        v18 = v17 - 1;
        if ( v18 != 0 )
        {
          v19 = v18 - 11;
          if ( v19 != 0 )
          {
            if ( v19 != 6 )
              goto LABEL_64;
            if ( (modeflag & 0xC000) != 0 )
              goto LABEL_47;
            modeflag |= 0x4000u;
          }
          else
          {
            if ( commodeset != 0 )
              goto LABEL_47;
            streamflag &= ~0x4000u;
            commodeset = 1;
          }
        }
        else
        {
          if ( commodeset != 0 )
            goto LABEL_47;
          streamflag |= 0x4000u;
          commodeset = 1;
        }
      }
      else
      {
        if ( (modeflag & 0xC000) != 0 )
          goto LABEL_47;
        modeflag |= 0x8000u;
      }
    }
    else if ( v10 == 83 )
    {
      if ( scanset != 0 )
        goto LABEL_47;
      modeflag |= 0x20u;
      scanset = 1;
    }
    else
    {
      v11 = v10 - 32;
      if ( v11 != 0 )
      {
        v12 = v11 - 11;
        if ( v12 != 0 )
        {
          v13 = v12 - 1;
          if ( v13 == 0 )
          {
            filedes = 1;
LABEL_47:
            v8 = 0;
            goto LABEL_49;
          }
          v14 = v13 - 24;
          if ( v14 != 0 )
          {
            v15 = v14 - 10;
            if ( v15 != 0 )
            {
              if ( v15 != 4 )
                goto LABEL_64;
              if ( scanset != 0 )
                goto LABEL_47;
              modeflag |= 0x10u;
              scanset = 1;
            }
            else
            {
              modeflag |= 0x80u;
            }
          }
          else
          {
            if ( (modeflag & 0x40) != 0 )
              goto LABEL_47;
            modeflag |= 0x40u;
          }
        }
        else
        {
          if ( (modeflag & 2) != 0 )
            goto LABEL_47;
          modeflag = modeflag & 0xFFFFFFFC | 2;
          streamflag = streamflag & 0xFFFFFF7C | 0x80;
        }
      }
    }
LABEL_49:
    v10 = *++v9;
    if ( *v9 == 0 )
      break;
  }
  if ( filedes == 0 )
    goto LABEL_62;
  while ( *v9 == 32 )
    ++v9;
  if ( _mbsnbcmp(s1: "ccs=", s2: v9, n: 4u) != 0 )
    goto LABEL_64;
  v9 += 4;
  if ( _mbsicmp(s1: v9, s2: "UTF-8") == 0 )
  {
    v9 += 5;
    modeflag |= 0x40000u;
    goto LABEL_62;
  }
  if ( _mbsicmp(s1: v9, s2: "UTF-16LE") == 0 )
  {
    v9 += 8;
    modeflag |= 0x20000u;
    goto LABEL_62;
  }
  if ( _mbsicmp(s1: v9, s2: "UNICODE") != 0 )
    goto LABEL_64;
  v9 += 7;
  modeflag |= 0x10000u;
LABEL_62:
  while ( *v9 == 32 )
    ++v9;
  if ( *v9 != 0 )
  {
LABEL_64:
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: (unsigned int)v9);
    return nullptr;
  }
  if ( _sopen_s(pfh: &filedes, path: filename, oflag: modeflag, shflag, pmode: 384) != 0 )
    return nullptr;
  ++_cflush;
  str->_flag = streamflag;
  v20 = filedes;
  str->_cnt = 0;
  str->_ptr = nullptr;
  str->_base = nullptr;
  str->_tmpfname = nullptr;
  str->_file = v20;
  return str;
}

//------------------------------------------------------------------------------
// Address: 0x0041C986
// Name: __getstream
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _getstream()
{
  _DWORD *v0; // edi
  int i; // esi
  void **v2; // eax
  int v3; // eax
  int v4; // esi

  v0 = nullptr;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = &__piob[i];
    if ( *v2 == nullptr )
    {
      v4 = i;
      __piob[v4] = operator new(nSize: 0x38u);
      if ( __piob[v4] != nullptr )
      {
        if ( __crtInitCritSecAndSpinCount(
               lpCriticalSection: (_RTL_CRITICAL_SECTION *)((char *)__piob[v4] + 32),
               dwSpinCount: 0xFA0u) != 0 )
        {
          EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[v4] + 32));
          v0 = __piob[v4];
        }
        else
        {
          free(pMem: __piob[v4]);
          __piob[v4] = nullptr;
        }
      }
      break;
    }
    v3 = *((_DWORD *)*v2 + 3);
    if ( (v3 & 0x83) == 0 && (v3 & 0x8000u) == 0 )
    {
      if ( (unsigned int)(i - 3) <= 0x10 && _mtinitlocknum(locknum: i + 16) == 0 )
        break;
      _lock_file2(i, s: (char *)__piob[i]);
      if ( (*((_BYTE *)__piob[i] + 12) & 0x83) == 0 )
      {
        v0 = __piob[i];
        break;
      }
      _unlock_file2(i, s: (char *)__piob[i]);
    }
  }
  if ( v0 != nullptr )
  {
    v0[3] &= 0x8000u;
    v0[1] = 0;
    v0[2] = 0;
    *v0 = 0;
    v0[7] = 0;
    v0[4] = -1;
  }
  _unlock(locknum: 1);
  return (_iobuf *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x0041CAB8
// Name: __local_unwind4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind4(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ebx
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-8h] [ebp-28h]
  int (__cdecl *v8)(int, int, int, int); // [esp-4h] [ebp-24h]

  v8 = unwind_handler4;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a2;
    v4 = *(_DWORD *)(a2 + 12);
    if ( v4 == -2 || a3 != -2 && v4 <= a3 )
      break;
    v5 = 3 * v4;
    v6 = (*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 16;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)((*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 0x10);
    if ( *(_DWORD *)(v6 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: 1, a2: ExceptionList, a3: v8);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041CB48
// Name: _unwind_handler4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unwind_handler4(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind4(a1: *(_DWORD **)(a2 + 20), a2: *(_DWORD *)(a2 + 16), a3: *(_DWORD *)(a2 + 12));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041CB8E
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _seh_longjmp_unwind4(unsigned int Dummy)
{
  _local_unwind4(a1: *(_DWORD **)(Dummy + 40), a2: *(_DWORD *)(Dummy + 24), a3: *(_DWORD *)(Dummy + 28));
}

//------------------------------------------------------------------------------
// Address: 0x0041CBAA
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_CallFilterFunc(int (*this)(void))
{
  return this();
}

//------------------------------------------------------------------------------
// Address: 0x0041CBC1
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_TransferToHandler(int (__fastcall *this)(_DWORD, _DWORD))
{
  _NLG_Notify(a1: 1);
  return this(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041CBDA
// Name: _EH4_GlobalUnwind(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _EH4_GlobalUnwind(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &ReturnPoint, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0041CBF4
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return _local_unwind4(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041CC0B
// Name: __mbsnbicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsnbicoll_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  int v7; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( n == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( s1 != nullptr && s2 != nullptr )
  {
    if ( n > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: 0x7FFFFFFFu);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      v7 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: _loc_update.localeinfo.mbcinfo->mblcid,
             dwCmpFlags: 0x1001u,
             lpString1: (const char *)s1,
             cchCount1: n,
             lpString2: (const char *)s2,
             cchCount2: n,
             code_page: _loc_update.localeinfo.mbcinfo->mbcodepage);
      if ( v7 == 0 )
        goto LABEL_15;
      result = v7 - 2;
    }
    else
    {
      result = _strnicoll_l(_string1: (const char *)s1, _string2: (const char *)s2, count: n, plocinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041CCF7
// Name: __mbsnbicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsnbicoll@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n)
{
  return _mbsnbicoll_l(a1, a2, s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0041CD0E
// Name: ___wtomb_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __wtomb_environ()
{
  LPCWCH *v0; // edi
  const WCHAR *v1; // eax
  unsigned int v2; // eax
  char *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  char *envp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCWCH *)_wenviron;
  envp = nullptr;
  v1 = *_wenviron;
  if ( *_wenviron == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: v1,
           cchWideChar: -1,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    size = v2;
    if ( v2 == 0 )
      break;
    v3 = (char *)calloc(count: v2, size: 1u);
    envp = v3;
    if ( v3 == nullptr )
      break;
    if ( WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: *v0,
           cchWideChar: -1,
           lpMultiByteStr: v3,
           cbMultiByte: size,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr) == 0 )
    {
      free(pMem: envp);
      return -1;
    }
    if ( __crtsetenv(poption: &envp, primary: 0) < 0 && envp != nullptr )
    {
      free(pMem: envp);
      envp = nullptr;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041CDA3
// Name: _strcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strcpy_s@<eax>(unsigned int a1@<edi>, char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // al

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter(a1: 0, a2: a1, a3: v4);
    return v4;
  }
  v7 = _Dst;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( v8 == 0 )
      break;
    --a1;
  }
  while ( a1 != 0 );
  if ( a1 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041CE08
// Name: _strnlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strnlen(const char *str, unsigned int maxsize)
{
  unsigned int result; // eax

  for ( result = 0; result < maxsize; ++str )
  {
    if ( *str == 0 )
      break;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041CE22
// Name: comexecmd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall comexecmd@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        int mode,
        const char *name,
        const char *const *argv,
        const char *const *envp)
{
  int v7; // esi
  char *envblk; // [esp+4h] [ebp-8h] BYREF
  char *argblk; // [esp+8h] [ebp-4h] BYREF

  if ( name == nullptr || argv == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
  if ( _cenvarg(argv, envp, &argblk, &envblk, name) == -1 )
    return -1;
  v7 = _dospawn(mode, name, cmdblk: argblk, envblk);
  free(pMem: argblk);
  free(pMem: envblk);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0041CE9A
// Name: __spawnve
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _spawnve@<eax>(
        unsigned int a1@<esi>,
        int mode,
        char *name,
        const char *const *argv,
        const char *const *envp)
{
  const char *v5; // edi
  const unsigned __int8 *v7; // esi
  const unsigned __int8 *v8; // eax
  int v9; // eax
  unsigned int v10; // esi
  char *v11; // eax
  char *v12; // edi
  unsigned int v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // ecx
  int v19; // eax
  unsigned int v20; // esi
  char *v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // edx
  unsigned int v24; // ecx
  int v25; // eax
  char *v26; // edi
  unsigned int v27; // esi
  unsigned int v28; // eax
  unsigned int v29; // edx
  unsigned int v30; // ecx
  int save_errno; // [esp+8h] [ebp-14h]
  int rc; // [esp+Ch] [ebp-10h]
  const char **v33; // [esp+10h] [ebp-Ch]
  char *p; // [esp+14h] [ebp-8h]
  char *pathname; // [esp+18h] [ebp-4h]

  v5 = name;
  pathname = name;
  if ( name == nullptr || *name == 0 || argv == nullptr || *argv == nullptr || **(_BYTE **)argv == 0 )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)name, a3: a1);
    return -1;
  }
  v7 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x5Cu);
  v8 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x2Fu);
  if ( v8 != nullptr )
  {
    if ( v7 == nullptr || v8 > v7 )
      v7 = v8;
  }
  else if ( v7 == nullptr )
  {
    v7 = _mbschr(string: (const unsigned __int8 *)name, c: 0x3Au);
    if ( v7 == nullptr )
    {
      strlen(buf: name);
      v10 = v9 + 3;
      v11 = (char *)calloc(count: v9 + 3, size: 1u);
      v12 = v11;
      pathname = v11;
      if ( v11 == nullptr )
        return -1;
      v13 = strcpy_s(a1: (unsigned int)v11, _Dst: v11, _SizeInBytes: v10, _Src: ".\\");
      if ( v13 != 0 )
        _invoke_watson(a1: v13, a2: v14, a3: v15, a4: 0, a5: (unsigned int)v12, a6: v10);
      v16 = strcat_s(_Dst: v12, _SizeInBytes: v10, _Src: name);
      if ( v16 != 0 )
        _invoke_watson(a1: v16, a2: v17, a3: v18, a4: 0, a5: (unsigned int)v12, a6: v10);
      v7 = (const unsigned __int8 *)(v12 + 2);
      v5 = name;
    }
  }
  rc = -1;
  if ( _mbsrchr(str: v7, c: 0x2Eu) == nullptr )
  {
    strlen(buf: pathname);
    v20 = v19 + 5;
    v21 = (char *)calloc(count: v19 + 5, size: 1u);
    p = v21;
    if ( v21 != nullptr )
    {
      v22 = strcpy_s(a1: (unsigned int)v5, _Dst: v21, _SizeInBytes: v20, _Src: pathname);
      if ( v22 != 0 )
        _invoke_watson(a1: v22, a2: v23, a3: v24, a4: 0, a5: (unsigned int)v5, a6: v20);
      strlen(buf: pathname);
      v26 = &p[v25];
      save_errno = *_errno();
      v27 = (unsigned int)&p[v20 - (_DWORD)v26];
      v33 = (const char **)(ext_strings + 12);
      while ( 1 )
      {
        v28 = strcpy_s(a1: (unsigned int)v26, _Dst: v26, _SizeInBytes: v27, _Src: *v33);
        if ( v28 != 0 )
          _invoke_watson(a1: v28, a2: v29, a3: v30, a4: 0, a5: (unsigned int)v26, a6: v27);
        if ( _access_s(path: p, amode: 0) == 0 )
          break;
        if ( (int)--v33 < (int)ext_strings )
          goto LABEL_33;
      }
      *_errno() = save_errno;
      rc = comexecmd(a1: 0, a2: (unsigned int)v26, mode, name: p, argv, envp);
LABEL_33:
      free(pMem: p);
      v5 = name;
      goto LABEL_34;
    }
    return -1;
  }
  if ( _access_s(path: pathname, amode: 0) == 0 )
    rc = comexecmd(a1: 0, a2: (unsigned int)v5, mode, name: pathname, argv, envp);
LABEL_34:
  if ( pathname != v5 )
    free(pMem: pathname);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x0041D0B9
// Name: wfindenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall wfindenv@<eax>(unsigned int len@<edi>, const wchar_t *name)
{
  const wchar_t **i; // esi
  wchar_t v3; // ax

  for ( i = (const wchar_t **)_wenviron; ; ++i )
  {
    if ( *i == nullptr )
      return -(((char *)i - (char *)_wenviron) >> 2);
    if ( _wcsnicoll(_string1: name, _string2: *i, count: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_wenviron) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0041D10A
// Name: copy_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 **__usercall copy_environ@<eax>(unsigned __int16 **oldenviron@<edi>)
{
  unsigned __int16 **result; // eax
  unsigned __int16 **v2; // ecx
  unsigned __int16 **v3; // esi
  ConVar *v4; // ecx
  unsigned __int16 *v5; // eax
  unsigned __int16 **v6; // ebx
  ConVar *v7; // [esp-Ch] [ebp-10h]
  ConVar *v8; // [esp-Ch] [ebp-10h]
  ConVar *v9; // [esp-Ch] [ebp-10h]
  unsigned __int16 **newenviron; // [esp+0h] [ebp-4h]

  result = nullptr;
  v2 = oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v2;
        result = (unsigned __int16 **)((char *)result + 1);
      }
      while ( *v2 != nullptr );
    }
    v3 = (unsigned __int16 **)calloc(count: (unsigned int)result + 1, size: 4u);
    v4 = v7;
    newenviron = v3;
    if ( v3 == nullptr )
    {
      _amsg_exit(rterrnum: 9);
      v4 = v8;
    }
    v5 = *oldenviron;
    v6 = oldenviron;
    while ( v5 != nullptr )
    {
      v9 = (ConVar *)v5;
      *v3++ = (unsigned __int16 *)_wcsdup(this: v4);
      v5 = *++v6;
      v4 = v9;
    }
    *v3 = nullptr;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041D167
// Name: ___crtwsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __crtwsetenv@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        unsigned __int16 **poption,
        int primary)
{
  const wchar_t *v5; // edi
  unsigned __int16 *v6; // eax
  unsigned __int16 *v7; // ebx
  unsigned __int16 **v8; // eax
  char **v9; // eax
  unsigned __int16 **v10; // eax
  int v11; // eax
  unsigned int v12; // ebx
  char *v13; // edi
  unsigned __int16 **v14; // eax
  unsigned int v15; // eax
  unsigned __int16 *v16; // edi
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // ecx
  unsigned __int16 *v21; // ebx
  const wchar_t *v22; // ebx
  unsigned int v23; // eax
  char *v24; // eax
  unsigned int v25; // eax
  char *v26; // eax
  char *c_name; // [esp+8h] [ebp-18h]
  char *c_namea; // [esp+8h] [ebp-18h]
  unsigned int c_value; // [esp+Ch] [ebp-14h]
  char *c_valuea; // [esp+Ch] [ebp-14h]
  int size; // [esp+10h] [ebp-10h]
  int sizea; // [esp+10h] [ebp-10h]
  BOOL remove; // [esp+14h] [ebp-Ch]
  unsigned __int16 *option; // [esp+18h] [ebp-8h]
  int retval; // [esp+1Ch] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
  v5 = *poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_13;
  v6 = wcschr(string: v5, ch: 0x3Du);
  v7 = v6;
  if ( v6 == nullptr || v5 == v6 )
    goto LABEL_13;
  remove = v6[1] == 0;
  v8 = _wenviron;
  if ( _wenviron == __winitenv )
  {
    v8 = copy_environ(oldenviron: _wenviron);
    v5 = option;
    _wenviron = v8;
  }
  if ( v8 == nullptr )
  {
    if ( primary != 0 && _environ != nullptr )
    {
      _wenvptr = (wchar_t *)__crtGetEnvironmentStringsW();
      if ( _wsetenvp() < 0 && __mbtow_environ() != 0 )
      {
LABEL_13:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove )
        return 0;
      if ( _environ != nullptr )
        goto LABEL_19;
      v9 = (char **)operator new(nSize: 4u);
      _environ = v9;
      if ( v9 == nullptr )
        return -1;
      *v9 = nullptr;
      if ( _wenviron == nullptr )
      {
LABEL_19:
        v10 = (unsigned __int16 **)operator new(nSize: 4u);
        _wenviron = v10;
        if ( v10 == nullptr )
          return -1;
        *v10 = nullptr;
      }
    }
  }
  c_name = (char *)_wenviron;
  if ( _wenviron == nullptr )
    return -1;
  c_value = v7 - v5;
  v11 = wfindenv(len: c_value, name: v5);
  v12 = v11;
  if ( v11 < 0 || *(_DWORD *)c_name == 0 )
  {
    if ( !remove )
    {
      if ( v11 < 0 )
        v12 = -v11;
      if ( (int)(v12 + 2) <= (int)v12 )
        return -1;
      if ( v12 + 2 >= 0x3FFFFFFF )
        return -1;
      v14 = (unsigned __int16 **)_recalloc_crt(ptr: _wenviron, count: 4u, size: v12 + 2);
      if ( v14 == nullptr )
        return -1;
      v12 = (unsigned int)&v14[v12];
      *(_DWORD *)v12 = option;
      *(_DWORD *)(v12 + 4) = 0;
      *poption = nullptr;
      goto LABEL_38;
    }
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  v13 = &c_name[4 * v11];
  free(pMem: *(void **)v13);
  if ( !remove )
  {
    *(_DWORD *)v13 = option;
    *poption = nullptr;
    goto LABEL_39;
  }
  while ( *(_DWORD *)v13 != 0 )
  {
    *(_DWORD *)v13 = *((_DWORD *)v13 + 1);
    ++v12;
    v13 = &c_name[4 * v12];
  }
  if ( v12 < 0x3FFFFFFF )
  {
    v14 = (unsigned __int16 **)_recalloc_crt(ptr: _wenviron, count: v12, size: 4u);
    if ( v14 != nullptr )
LABEL_38:
      _wenviron = v14;
  }
LABEL_39:
  if ( primary != 0 )
  {
    v15 = wcslen(wcs: option);
    v16 = (unsigned __int16 *)calloc(count: v15 + 2, size: 2u);
    if ( v16 != nullptr )
    {
      v17 = wcslen(wcs: option);
      v18 = wcscpy_s(_Dst: v16, _SizeInWords: v17 + 2, _Src: option);
      if ( v18 != 0 )
        _invoke_watson(a1: v18, a2: v19, a3: v20, a4: v12, a5: (unsigned int)v16, a6: 0);
      v21 = &v16[c_value];
      *v21 = 0;
      v22 = v21 + 1;
      if ( f_use == 1 && !SetEnvironmentVariableW(lpName: v16, lpValue: !remove ? v22 : nullptr) )
      {
        if ( GetLastError() == 120 )
        {
          f_use = 0;
          goto LABEL_49;
        }
        retval = -1;
      }
      if ( f_use != 0 )
      {
LABEL_61:
        if ( retval == -1 )
          *_errno() = 42;
        free(pMem: v16);
        goto LABEL_64;
      }
LABEL_49:
      c_namea = nullptr;
      c_valuea = nullptr;
      v23 = WideCharToMultiByte(
              CodePage: 0,
              dwFlags: 0,
              lpWideCharStr: v16,
              cchWideChar: -1,
              lpMultiByteStr: nullptr,
              cbMultiByte: 0,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: nullptr);
      size = v23;
      if ( v23 != 0 )
      {
        v24 = (char *)calloc(count: v23, size: 1u);
        c_namea = v24;
        if ( v24 != nullptr
          && WideCharToMultiByte(
               CodePage: 0,
               dwFlags: 0,
               lpWideCharStr: v16,
               cchWideChar: -1,
               lpMultiByteStr: v24,
               cbMultiByte: size,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: nullptr) != 0 )
        {
          if ( remove )
            goto LABEL_57;
          v25 = WideCharToMultiByte(
                  CodePage: 0,
                  dwFlags: 0,
                  lpWideCharStr: v22,
                  cchWideChar: -1,
                  lpMultiByteStr: nullptr,
                  cbMultiByte: 0,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          sizea = v25;
          if ( v25 != 0 )
          {
            v26 = (char *)calloc(count: v25, size: 1u);
            c_valuea = v26;
            if ( v26 != nullptr )
            {
              if ( WideCharToMultiByte(
                     CodePage: 0,
                     dwFlags: 0,
                     lpWideCharStr: v22,
                     cchWideChar: -1,
                     lpMultiByteStr: v26,
                     cbMultiByte: sizea,
                     lpDefaultChar: nullptr,
                     lpUsedDefaultChar: nullptr) == 0 )
                retval = -1;
LABEL_57:
              if ( retval == -1 || SetEnvironmentVariableA(lpName: c_namea, lpValue: !remove ? c_valuea : nullptr) )
                goto LABEL_60;
            }
          }
        }
      }
      retval = -1;
LABEL_60:
      free(pMem: c_valuea);
      free(pMem: c_namea);
      goto LABEL_61;
    }
  }
LABEL_64:
  if ( remove )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0041D4CD
// Name: _wcslen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcslen(const wchar_t *wcs)
{
  const wchar_t *v1; // eax
  __int16 v2; // cx

  v1 = wcs;
  do
    v2 = *v1++;
  while ( v2 != 0 );
  return v1 - wcs - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041D4E3
// Name: findenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall findenv@<eax>(unsigned int len@<edi>, const char *name)
{
  const unsigned __int8 **i; // esi
  unsigned __int8 v3; // al

  for ( i = (const unsigned __int8 **)_environ; ; ++i )
  {
    if ( *i == nullptr )
      return -(((char *)i - (char *)_environ) >> 2);
    if ( _mbsnbicoll(a1: len, a2: (unsigned int)i, s1: (const unsigned __int8 *)name, s2: *i, n: len) == 0 )
    {
      v3 = (*i)[len];
      if ( v3 == 61 || v3 == 0 )
        break;
    }
  }
  return ((char *)i - (char *)_environ) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0041D530
// Name: copy_environ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__usercall copy_environ_0@<eax>(const char **oldenviron@<edi>)
{
  char **result; // eax
  char **v2; // ecx
  char **v3; // esi
  const char *v4; // eax
  const char **v5; // ebx
  char **newenviron; // [esp+0h] [ebp-4h]

  result = nullptr;
  v2 = (char **)oldenviron;
  if ( oldenviron != nullptr )
  {
    if ( *oldenviron != nullptr )
    {
      do
      {
        ++v2;
        result = (char **)((char *)result + 1);
      }
      while ( *v2 != nullptr );
    }
    v3 = (char **)calloc(count: (unsigned int)result + 1, size: 4u);
    newenviron = v3;
    if ( v3 == nullptr )
      _amsg_exit(rterrnum: 9);
    v4 = *oldenviron;
    v5 = oldenviron;
    while ( v4 != nullptr )
    {
      *v3++ = _strdup(string: v4);
      v4 = *++v5;
    }
    *v3 = nullptr;
    return newenviron;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041D58D
// Name: ___crtsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __crtsetenv@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, char **poption, int primary)
{
  const unsigned __int8 *v5; // esi
  const unsigned __int8 *v6; // eax
  bool v7; // zf
  char **v8; // eax
  char **v9; // eax
  unsigned __int16 **v10; // eax
  char **v11; // esi
  int v12; // eax
  unsigned int v13; // edi
  char **v14; // esi
  char **v15; // eax
  char **v16; // ecx
  int v17; // eax
  char *v18; // edi
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // edx
  unsigned int v22; // ecx
  const char *v23; // eax
  char **env; // [esp+8h] [ebp-14h]
  int retval; // [esp+Ch] [ebp-10h]
  const char *equal; // [esp+10h] [ebp-Ch]
  int remove; // [esp+14h] [ebp-8h]
  char *option; // [esp+18h] [ebp-4h]

  retval = 0;
  if ( poption == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    return -1;
  }
  v5 = (const unsigned __int8 *)*poption;
  option = *poption;
  if ( *poption == nullptr )
    goto LABEL_12;
  v6 = _mbschr(string: v5, c: 0x3Du);
  equal = (const char *)v6;
  if ( v6 == nullptr || v5 == v6 )
    goto LABEL_12;
  v7 = v6[1] == 0;
  v8 = _environ;
  remove = v7;
  if ( _environ == __initenv )
  {
    v8 = copy_environ_0(oldenviron: (const char **)_environ);
    _environ = v8;
  }
  if ( v8 == nullptr )
  {
    if ( primary != 0 && _wenviron != nullptr )
    {
      if ( __wtomb_environ() != 0 )
      {
LABEL_12:
        *_errno() = 22;
        return -1;
      }
    }
    else
    {
      if ( remove != 0 )
        return 0;
      v9 = (char **)operator new(nSize: 4u);
      _environ = v9;
      if ( v9 == nullptr )
        return -1;
      *v9 = nullptr;
      if ( _wenviron == nullptr )
      {
        v10 = (unsigned __int16 **)operator new(nSize: 4u);
        _wenviron = v10;
        if ( v10 == nullptr )
          return -1;
        *v10 = nullptr;
      }
    }
  }
  v11 = _environ;
  env = _environ;
  if ( _environ == nullptr )
    return -1;
  v12 = findenv(len: equal - option, name: option);
  v13 = v12;
  if ( v12 < 0 || *v11 == nullptr )
  {
    if ( remove == 0 )
    {
      if ( v12 < 0 )
        v13 = -v12;
      if ( (int)(v13 + 2) <= (int)v13 )
        return -1;
      if ( v13 + 2 >= 0x3FFFFFFF )
        return -1;
      v15 = (char **)_recalloc_crt(ptr: _environ, count: 4u, size: v13 + 2);
      if ( v15 == nullptr )
        return -1;
      v16 = &v15[v13];
      *v16 = option;
      v16[1] = nullptr;
      *poption = nullptr;
      goto LABEL_36;
    }
    free(pMem: option);
    *poption = nullptr;
    return 0;
  }
  v14 = &v11[v12];
  free(pMem: *v14);
  if ( remove == 0 )
  {
    *v14 = option;
    *poption = nullptr;
    goto LABEL_37;
  }
  while ( *v14 != nullptr )
  {
    *v14 = v14[1];
    v14 = &env[++v13];
  }
  if ( v13 < 0x3FFFFFFF )
  {
    v15 = (char **)_recalloc_crt(ptr: _environ, count: v13, size: 4u);
    if ( v15 == nullptr )
      goto LABEL_37;
LABEL_36:
    _environ = v15;
  }
LABEL_37:
  if ( primary != 0 )
  {
    strlen(buf: option);
    v18 = (char *)calloc(count: v17 + 2, size: 1u);
    if ( v18 != nullptr )
    {
      strlen(buf: option);
      v20 = strcpy_s(a1: (unsigned int)v18, _Dst: v18, _SizeInBytes: v19 + 2, _Src: option);
      if ( v20 != 0 )
        _invoke_watson(a1: v20, a2: v21, a3: v22, a4: 0, a5: (unsigned int)v18, a6: (unsigned int)option);
      v23 = &equal[v18 - option];
      *v23 = 0;
      if ( !SetEnvironmentVariableA(lpName: v18, lpValue: remove == 0 ? v23 + 1 : nullptr) )
      {
        retval = -1;
        *_errno() = 42;
      }
      free(pMem: v18);
    }
  }
  if ( remove != 0 )
  {
    free(pMem: option);
    *poption = nullptr;
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0041D7D9
// Name: __mbschr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbschr_l(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        char *string,
        unsigned int c,
        localeinfo_struct *plocinfo)
{
  char *v5; // eax
  unsigned __int16 v6; // cx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v5 = string;
  if ( string != nullptr )
  {
    if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
    {
      while ( 1 )
      {
        v6 = (unsigned __int8)*v5;
        if ( *v5 == 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) != 0 )
        {
          if ( *++v5 == 0 )
            goto LABEL_17;
          if ( c == ((unsigned __int8)*v5 | (v6 << 8)) )
            goto LABEL_15;
        }
        else if ( c == (unsigned __int8)*v5 )
        {
          break;
        }
        ++v5;
      }
      if ( c == (unsigned __int8)*v5 )
        goto LABEL_15;
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      strchr(string, chr: c);
LABEL_15:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D893
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbschr(unsigned int a1@<edi>, unsigned int a2@<esi>, char *string, unsigned int c)
{
  _mbschr_l(a1, a2, string, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0041D8A6
// Name: __mbctoupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctoupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 ret[4]; // [esp+14h] [ebp-8h] BYREF
  char val[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c <= 0xFF )
  {
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[c + 1] & 0x20) != 0 )
      result = _loc_update.localeinfo.mbcinfo->mbcasemap[c];
    else
      result = c;
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  val[0] = BYTE1(c);
  val[1] = c;
  if ( (_loc_update.localeinfo.mbcinfo->mbctype[BYTE1(c) + 1] & 4) != 0
    && __crtLCMapStringA(
         plocinfo: &_loc_update.localeinfo,
         Locale: _loc_update.localeinfo.mbcinfo->mblcid,
         dwMapFlags: 0x200u,
         lpSrcStr: val,
         cchSrc: 2,
         lpDestStr: (char *)ret,
         cchDest: 2,
         code_page: _loc_update.localeinfo.mbcinfo->mbcodepage,
         bError: 1) != 0 )
  {
    result = ret[1] + (ret[0] << 8);
    goto LABEL_11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x0041D94A
// Name: __mbctoupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctoupper(unsigned int c)
{
  return _mbctoupper_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0041D958
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(uintptr_t StackCookie)
{
  if ( StackCookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x0041D970
// Name: __CIacos_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIacos_pentium4()
{
  JUMPOUT(0x41D98E);
}

//------------------------------------------------------------------------------
// Address: 0x0041DED0
// Name: __trandisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _trandisp1@<eax>(int a1@<edx>, __int16 a2@<cx>, int a3@<ebp>, __int16 a4@<fpstat>, double _ST7@<st0>)
{
  __int16 v5; // bx

  if ( *(_BYTE *)(a1 + 14) == 5 )
  {
    HIBYTE(v5) = HIBYTE(*(_WORD *)(a3 - 164)) & 0xFC | 2;
    LOBYTE(v5) = 63;
  }
  else
  {
    v5 = 4927;
  }
  *(_WORD *)(a3 - 162) = v5;
  _EBX = &XAMtoTagTab;
  __asm { fxam }
  *(_DWORD *)(a3 - 148) = a1;
  *(_WORD *)(a3 - 160) = a4;
  *(_BYTE *)(a3 - 144) = 0;
  LOBYTE(a2) = __ROL1__((char)(2 * *(_BYTE *)(a3 - 159)) >> 1, 1);
  _AL = a2 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))(_AL + a1 + 16))(a1: a2 & 0x404);
}

//------------------------------------------------------------------------------
// Address: 0x0041DF37
// Name: __trandisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _trandisp2@<eax>(int a1@<edx>, int a2@<ebp>, __int16 a3@<fpstat>, double _ST6@<st1>, double a5@<st0>)
{
  __int16 v5; // bx
  __int16 v7; // fps
  char v9; // cl
  __int16 v10; // cx
  char v13; // ah

  if ( *(_BYTE *)(a1 + 14) == 5 )
  {
    HIBYTE(v5) = HIBYTE(*(_WORD *)(a2 - 164)) & 0xFC | 2;
    LOBYTE(v5) = 63;
  }
  else
  {
    v5 = 4927;
  }
  *(_WORD *)(a2 - 162) = v5;
  _EBX = &XAMtoTagTab;
  __asm { fxam }
  *(_DWORD *)(a2 - 148) = a1;
  *(_WORD *)(a2 - 160) = a3;
  *(_BYTE *)(a2 - 144) = 0;
  _ST6 = a5;
  v9 = *(_BYTE *)(a2 - 159);
  __asm { fxam }
  *(_WORD *)(a2 - 160) = v7;
  HIBYTE(v10) = __ROL1__((char)(2 * *(_BYTE *)(a2 - 159)) >> 1, 1);
  _AL = HIBYTE(v10) & 0xF;
  __asm { xlat }
  v13 = _AL;
  LOBYTE(v10) = __ROL1__((char)(2 * v9) >> 1, 1);
  _AL = v10 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))((char)((4 * v13) | _AL) + a1 + 16))(a1: v10 & 0x404);
}

//------------------------------------------------------------------------------
// Address: 0x0041DFC3
// Name: __rttospopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int _rttospopde()
{
  _rttosnpopde();
  return _rttospop();
}

//------------------------------------------------------------------------------
// Address: 0x0041DFC8
// Name: __rttospop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _rttospop()
{
  return _rtnospop();
}

//------------------------------------------------------------------------------
// Address: 0x0041DFCA
// Name: __rtnospop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _rtnospop()
{
  JUMPOUT(0x41DFCC);
}

//------------------------------------------------------------------------------
// Address: 0x0041DFCD
// Name: __rtnospopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _rtnospopde()
{
  _rttosnpopde();
  _rtnospop();
}

//------------------------------------------------------------------------------
// Address: 0x0041DFD4
// Name: __rtzeropop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtzeropop@<eax>(double a1@<st0>)
{
  return _rtzeronpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0041DFD6
// Name: __rtzeronpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double _rtzeronpop()
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x0041DFDB
// Name: __rtonepop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtonepop@<eax>(double a1@<st0>)
{
  return _rtonenpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0041DFDD
// Name: __rtonenpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double _rtonenpop()
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0041DFE2
// Name: __tosnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _tosnan1@<st0>(int a1@<ebp>, double a2@<st0>)
{
  double result; // st7

  *(double *)(a1 - 158) = a2;
  result = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0 )
  {
    *(_BYTE *)(a1 - 144) = 7;
  }
  else
  {
    *(_BYTE *)(a1 - 144) = 1;
    return result + *(double *)&One_0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041E00D
// Name: __nosnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _nosnan2()
{
  return _tosnan2();
}

//------------------------------------------------------------------------------
// Address: 0x0041E00F
// Name: __tosnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _tosnan2@<st0>(int a1@<ebp>, double a2@<st1>, double a3@<st0>)
{
  double v3; // st6

  *(double *)(a1 - 158) = a2;
  v3 = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0 )
    *(_BYTE *)(a1 - 144) = 7;
  else
    *(_BYTE *)(a1 - 144) = 1;
  return a3 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041E037
// Name: __nan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _nan2@<st0>(int a1@<ebp>, double a2@<st1>, double a3@<st0>)
{
  double v3; // st6
  double v4; // rt0
  double v5; // st6

  *(double *)(a1 - 158) = a2;
  v3 = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0
    && (v4 = v3,
        v5 = a3,
        a3 = v4,
        *(double *)(a1 - 158) = v5,
        v3 = *(double *)(a1 - 158),
        (*(_BYTE *)(a1 - 151) & 0x40) != 0) )
  {
    *(_BYTE *)(a1 - 144) = 7;
  }
  else
  {
    *(_BYTE *)(a1 - 144) = 1;
  }
  return a3 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041E076
// Name: __rtindfpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtindfpop@<eax>(double a1@<st0>)
{
  return _rtindfnpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0041E078
// Name: __rtindfnpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtindfnpop@<eax>(int a1@<ebp>)
{
  if ( *(char *)(a1 - 144) > 0 )
    JUMPOUT(0x41E090);
  return _rttosnpopde();
}

//------------------------------------------------------------------------------
// Address: 0x0041E089
// Name: __rttosnpopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _rttosnpopde(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 144) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041E093
// Name: __rtchsifneg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtchsifneg@<st0>(char a1@<cl>, double result@<st0>)
{
  if ( a1 != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041E0A0
// Name: __startTwoArgErrorHandling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _startTwoArgErrorHandling()
{
  JUMPOUT(0x41E0C0);
}

//------------------------------------------------------------------------------
// Address: 0x0041E0B7
// Name: __startOneArgErrorHandling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _startOneArgErrorHandling(
        int a1@<eax>,
        int a2@<edx>,
        char *a3@<ecx>,
        __int16 savCW,
        unsigned int ret_addr,
        unsigned __int64 param1)
{
  _exception exc; // [esp+0h] [ebp-20h] BYREF

  exc.type = a1;
  __asm { fstp    [ebp+exc.retval] }
  exc.name = a3;
  *(_QWORD *)&exc.arg1 = param1;
  _87except(opcode: a2, &exc, pcw16: (unsigned __int16 *)&savCW);
  __asm { fld     [ebp+exc.retval] }
  if ( savCW != 639 )
    __asm { fldcw   word ptr [ebp+savCW] }
}

//------------------------------------------------------------------------------
// Address: 0x0041E100
// Name: __twoToTOS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _twoToTOS@<st0>(long double a1@<st0>)
{
  long double v1; // rt0

  v1 = rint(a1);
  return __FSCALE__(__F2XM1__(-(v1 - a1)) + 1.0, v1);
}

//------------------------------------------------------------------------------
// Address: 0x0041E115
// Name: __load_CW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _load_CW()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0041E12C
// Name: __convertTOStoQNaN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _convertTOStoQNaN@<st0>(int a1@<eax>, double result@<st0>)
{
  if ( (a1 & 0x80000) == 0 )
    return result + 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041E145
// Name: __fload_withFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __fastcall _fload_withFB(int a1, _DWORD *a2)
{
  double result; // st7

  if ( (a2[1] & 0x7FF00000) != 0x7FF00000 )
    return *(double *)a2;
  *(_QWORD *)&result = *(_QWORD *)a2 << 11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041E188
// Name: __checkTOS_withFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _checkTOS_withFB(int a1, int a2)
{
  int result; // eax

  result = a2 & 0x7FF00000;
  if ( (a2 & 0x7FF00000) == 0x7FF00000 )
    return a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041E19E
// Name: __fast_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _fast_exit()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0041E1AB
// Name: __math_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0041E1D5
// Name: __check_overflow_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _check_overflow_exit()
{
  JUMPOUT(0x41E1FD);
}

//------------------------------------------------------------------------------
// Address: 0x0041E1E9
// Name: __check_range_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0041E290
// Name: __CIasin_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIasin_pentium4()
{
  JUMPOUT(0x41E2AE);
}

//------------------------------------------------------------------------------
// Address: 0x0041E810
// Name: __cintrindisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cintrindisp2@<eax>(int a1@<edx>, __int16 a2@<fpstat>, double a3@<st1>, double a4@<st0>)
{
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _trandisp2(a1, a2: (int)&savedregs, a3: a2, _ST6: a3, a5: a4);
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x0041E84E
// Name: __cintrindisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cintrindisp1@<eax>(int a1@<edx>, __int16 a2@<cx>, __int16 a3@<fpstat>, double a4@<st0>)
{
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _trandisp1(a1, a2, a3: (int)&savedregs, a4: a3, _ST7: a4);
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x0041E88B
// Name: __ctrandisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ctrandisp2(double a1@<st1>, double a2@<st0>, unsigned __int64 parm1, unsigned __int64 parm2)
{
  int v4; // edx
  __int16 v5; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(parm: parm1);
  _fload(parm: parm2);
  _trandisp2(a1: v4, a2: (int)&savedregs, a3: v5, _ST6: a1, a5: a2);
  ctranexit();
}

//------------------------------------------------------------------------------
// Address: 0x0041E8D3
// Name: ctranexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall ctranexit@<eax>(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 712) &= ~1u;
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x0041E8DA
// Name: cintrinexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall cintrinexit@<st0>(long double *a1@<ebp>, long double result@<st0>)
{
  char v2; // fps
  char v3; // al
  __int16 v4; // ax
  int v5; // ebx

  if ( __fastflag != 0 )
    return result;
  *(a1 - 90) = result;
  v3 = *((_BYTE *)a1 - 144);
  switch ( v3 )
  {
    case 0:
      goto checkinexact;
    case -1:
      if ( (*((_WORD *)a1 - 357) & 0x7FF0) != 0x7FF0 )
        goto checkinexact;
      goto haveoverflow_0;
    case -2:
      v4 = *((_WORD *)a1 - 357) & 0x7FF0;
      if ( v4 == 0 )
      {
        *(_DWORD *)((char *)a1 - 142) = 4;
        result = __FSCALE__(result, 1536.0);
        if ( fabs(result) < 2.225073858507201e-308 )
          result = result * 0.0;
        goto haveerror;
      }
      if ( v4 != 32752 )
      {
checkinexact:
        if ( (*((_WORD *)a1 - 82) & 0x20) != 0 || (v2 & 0x20) == 0 )
          return result;
        *(_DWORD *)((char *)a1 - 142) = 8;
        goto haveerror;
      }
haveoverflow_0:
      *(_DWORD *)((char *)a1 - 142) = 3;
      result = __FSCALE__(result, -1536.0);
      if ( fabs(result) > 1.797693134862316e308 )
        result = result * INFINITY;
      goto haveerror;
    default:
      break;
  }
  *(_DWORD *)((char *)a1 - 142) = v3;
haveerror:
  v5 = *((_DWORD *)a1 - 37) + 1;
  *(_DWORD *)((char *)a1 - 138) = v5;
  if ( (*(_BYTE *)(a1 - 89) & 1) == 0 )
  {
    *(_DWORD *)((char *)a1 - 134) = *((_DWORD *)a1 + 2);
    *(_DWORD *)((char *)a1 - 130) = *((_DWORD *)a1 + 3);
    if ( *(_BYTE *)(v5 + 12) != 1 )
    {
      *(_DWORD *)((char *)a1 - 126) = *((_DWORD *)a1 + 4);
      *(_DWORD *)((char *)a1 - 122) = *((_DWORD *)a1 + 5);
    }
  }
  *(long double *)((char *)a1 - 118) = result;
  _87except(
    opcode: *(char *)(*((_DWORD *)a1 - 37) + 14),
    exc: (_exception *)((char *)a1 - 142),
    pcw16: (unsigned __int16 *)a1 - 82);
  return *(long double *)((char *)a1 - 118);
}

//------------------------------------------------------------------------------
// Address: 0x0041EA21
// Name: __ctrandisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ctrandisp1(double a1@<st0>, unsigned __int64 parm1)
{
  int v2; // edx
  __int16 v3; // cx
  __int16 v4; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(parm: parm1);
  _trandisp1(a1: v2, a2: v3, a3: (int)&savedregs, a4: v4, _ST7: a1);
  ctranexit(a1: (int)&savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x0041EA54
// Name: __fload
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _fload(double parm)
{
  double tmp; // [esp+6h] [ebp-Ah]

  if ( (HIWORD(parm) & 0x7FF0) != 0x7FF0 )
    return parm;
  HIDWORD(tmp) = *(_QWORD *)&parm >> 21;
  LODWORD(tmp) = LODWORD(parm);
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x0041EA90
// Name: _fdiv_main_routine
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl fdiv_main_routine(_TBYTE a1, _TBYTE a2)
{
  double v2; // st7
  double v3; // st6
  unsigned int v4; // eax

  v2 = *(double *)&a2;
  v3 = *(double *)&a1;
  while ( !__CFADD__(DWORD1(a1), DWORD1(a1)) )
  {
    if ( *(_QWORD *)&a1 == 0 || (HIWORD(a1) & 0x7FFF) != 0 )
      return v2 / v3;
    if ( (HIWORD(a2) & 0x7FFF) != 0 )
    {
      if ( (HIWORD(a2) & 0x7FFF) == 0x7FFF || !__CFADD__(DWORD1(a2), DWORD1(a2)) )
        return v2 / v3;
    }
    else if ( __CFADD__(DWORD1(a2), DWORD1(a2)) )
    {
      return v2 / v3;
    }
    *(double *)&a1 = v3 * *(float *)&one_shl_63;
    v2 = *(double *)&a2;
  }
  v4 = (2 * DWORD1(a1)) ^ 0xE000000;
  if ( (v4 & 0xE000000) != 0 )
    return v2 / v3;
  if ( fdiv_risc_table[v4 >> 28] == 0 )
    return v2 / v3;
  if ( (HIWORD(a1) & 0x7FFF) == 0 || (HIWORD(a1) & 0x7FFF) == 0x7FFF )
    return v2 / v3;
  if ( (HIWORD(a2) & 0x7FFF) == 1 )
    return v2 * *(float *)&fdiv_scale_2 / (v3 * *(float *)&fdiv_scale_2);
  else
    return v2 * *(float *)&fdiv_scale_1 / (v3 * *(float *)&fdiv_scale_1);
}

//------------------------------------------------------------------------------
// Address: 0x0041EBA7
// Name: __adj_fdiv_r
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _adj_fdiv_r(char a1@<al>)
{
  _TBYTE v1; // [esp-2Ch] [ebp-58h]
  _TBYTE v2; // [esp-20h] [ebp-4Ch]
  _TBYTE v17; // [esp+0h] [ebp-2Ch]
  _TBYTE v18; // [esp+Ch] [ebp-20h]

  switch ( a1 & 0x3F )
  {
    case 0:
      __asm { fdiv    st, st; jumptable 0041EBAD case 0 }
      return;
    case 1:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label2;
    case 2:
label2:
      __asm { fdivr   st, st; jumptable 0041EBAD case 2 }
      return;
    case 3:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label4;
    case 4:
label4:
      __asm { fdiv    st, st; jumptable 0041EBAD case 4 }
      return;
    case 5:
      __asm { fdivp   st, st; jumptable 0041EBAD case 5 }
      return;
    case 6:
      __asm { fdivr   st, st; jumptable 0041EBAD case 6 }
      return;
    case 7:
      __asm { fdivrp  st, st; jumptable 0041EBAD case 7 }
      return;
    case 8:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 8
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fld     [esp+2Ch+var_C]
        fxch    st(1)
      }
      return;
    case 9:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label10;
    case 0xA:
label10:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 0041EBAD case 10
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fld     [esp+arg_8]
        fxch    st(1)
      }
      return;
    case 0xB:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label12;
    case 0xC:
label12:
      __asm
      {
        fxch    st(1); jumptable 0041EBAD case 12
        fstp    [esp+arg_8]; _TBYTE
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm { fld     [esp+arg_1C] }
      return;
    case 0xD:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 0041EBAD case 13
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      return;
    case 0xE:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 14
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fld     [esp+2Ch+var_20] }
      return;
    case 0xF:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 15
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      return;
    case 0x10:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 16
        fxch    st(1)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(1)
        fld     [esp+2Ch+var_C]
        fxch    st(2)
      }
      return;
    case 0x11:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label18;
    case 0x12:
label18:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 0041EBAD case 18
        fxch    st(1)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(1)
        fld     [esp+arg_8]
        fxch    st(2)
      }
      return;
    case 0x13:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label20;
    case 0x14:
label20:
      __asm
      {
        fxch    st(2); jumptable 0041EBAD case 20
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(1)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(1)
        fld     [esp+arg_1C]
      }
      return;
    case 0x15:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 0041EBAD case 21
        fxch    st(1)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(1) }
      return;
    case 0x16:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 22
        fxch    st(1)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(1)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x17:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 23
        fxch    st(1)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(1) }
      return;
    case 0x18:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 24
        fxch    st(2)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(2)
        fld     [esp+2Ch+var_C]
        fxch    st(3)
      }
      return;
    case 0x19:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label26;
    case 0x1A:
label26:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 0041EBAD case 26
        fxch    st(2)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(2)
        fld     [esp+arg_8]
        fxch    st(3)
      }
      return;
    case 0x1B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label28;
    case 0x1C:
label28:
      __asm
      {
        fxch    st(3); jumptable 0041EBAD case 28
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(2)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(2)
        fld     [esp+arg_1C]
      }
      return;
    case 0x1D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 0041EBAD case 29
        fxch    st(2)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(2) }
      return;
    case 0x1E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 30
        fxch    st(2)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(2)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x1F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 31
        fxch    st(2)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(2) }
      return;
    case 0x20:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 32
        fxch    st(3)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(3)
        fld     [esp+2Ch+var_C]
        fxch    st(4)
      }
      return;
    case 0x21:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label34;
    case 0x22:
label34:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 0041EBAD case 34
        fxch    st(3)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(3)
        fld     [esp+arg_8]
        fxch    st(4)
      }
      return;
    case 0x23:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label36;
    case 0x24:
label36:
      __asm
      {
        fxch    st(4); jumptable 0041EBAD case 36
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(3)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(3)
        fld     [esp+arg_1C]
      }
      return;
    case 0x25:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 0041EBAD case 37
        fxch    st(3)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(3) }
      return;
    case 0x26:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 38
        fxch    st(3)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(3)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x27:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 39
        fxch    st(3)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(3) }
      return;
    case 0x28:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 40
        fxch    st(4)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(4)
        fld     [esp+2Ch+var_C]
        fxch    st(5)
      }
      return;
    case 0x29:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label42;
    case 0x2A:
label42:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 0041EBAD case 42
        fxch    st(4)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(4)
        fld     [esp+arg_8]
        fxch    st(5)
      }
      return;
    case 0x2B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label44;
    case 0x2C:
label44:
      __asm
      {
        fxch    st(5); jumptable 0041EBAD case 44
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(4)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(4)
        fld     [esp+arg_1C]
      }
      return;
    case 0x2D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 0041EBAD case 45
        fxch    st(4)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(4) }
      return;
    case 0x2E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 46
        fxch    st(4)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(4)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x2F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 47
        fxch    st(4)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(4) }
      return;
    case 0x30:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 48
        fxch    st(5)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(5)
        fld     [esp+2Ch+var_C]
        fxch    st(6)
      }
      return;
    case 0x31:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label50;
    case 0x32:
label50:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 0041EBAD case 50
        fxch    st(5)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(5)
        fld     [esp+arg_8]
        fxch    st(6)
      }
      return;
    case 0x33:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label52;
    case 0x34:
label52:
      __asm
      {
        fxch    st(6); jumptable 0041EBAD case 52
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(5)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(5)
        fld     [esp+arg_1C]
      }
      return;
    case 0x35:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 0041EBAD case 53
        fxch    st(5)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(5) }
      return;
    case 0x36:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 54
        fxch    st(5)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(5)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x37:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 55
        fxch    st(5)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(5) }
      return;
    case 0x38:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 56
        fxch    st(6)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(6)
        fld     [esp+2Ch+var_C]
        fxch    st(7)
      }
      return;
    case 0x39:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label58;
    case 0x3A:
label58:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 0041EBAD case 58
        fxch    st(6)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(6)
        fld     [esp+arg_8]
        fxch    st(7)
      }
      return;
    case 0x3B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label60;
    case 0x3C:
label60:
      __asm
      {
        fxch    st(7); jumptable 0041EBAD case 60
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(6)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(6)
        fld     [esp+arg_1C]
      }
      break;
    case 0x3D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 0041EBAD case 61
        fxch    st(6)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(6) }
      break;
    case 0x3E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 62
        fxch    st(6)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(6)
        fld     [esp+2Ch+var_20]
      }
      break;
    case 0x3F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 0041EBAD case 63
        fxch    st(6)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(6) }
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F046
// Name: __fdivp_sti_st
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fdivp_sti_st(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-2Ch]
  _TBYTE v3; // [esp+Ch] [ebp-20h]

  *(double *)&v2 = a1;
  *(double *)&v3 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0041F059
// Name: __fdivrp_sti_st
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fdivrp_sti_st(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-2Ch]
  _TBYTE v3; // [esp+Ch] [ebp-20h]

  *(double *)&v3 = a1;
  *(double *)&v2 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0041F06C
// Name: __adj_fdiv_m32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m32(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, float a4)
{
  if ( (LODWORD(a4) & 0x7F800000) != 0x7F800000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivp_sti_st(a1: a2, a2: a3);
    else
      _fdivp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F0B8
// Name: __adj_fdiv_m64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m64(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, double a4)
{
  if ( (HIDWORD(a4) & 0x7FF00000) != 0x7FF00000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivp_sti_st(a1: a2, a2: a3);
    else
      _fdivp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F104
// Name: __adj_fdiv_m16i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m16i(
        __int16 a1@<fpstat>,
        double a2@<st1>,
        double a3@<st0>,
        __int16 a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivp_sti_st(a1: a2, a2: a3);
  else
    _fdivp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041F138
// Name: __adj_fdiv_m32i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m32i(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, int a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivp_sti_st(a1: a2, a2: a3);
  else
    _fdivp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041F16C
// Name: __adj_fdivr_m32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m32(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, float a4)
{
  if ( (LODWORD(a4) & 0x7F800000) != 0x7F800000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivrp_sti_st(a1: a2, a2: a3);
    else
      _fdivrp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F1B8
// Name: __adj_fdivr_m64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m64(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, double a4)
{
  if ( (HIDWORD(a4) & 0x7FF00000) != 0x7FF00000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivrp_sti_st(a1: a2, a2: a3);
    else
      _fdivrp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F204
// Name: __adj_fdivr_m16i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m16i(
        __int16 a1@<fpstat>,
        double a2@<st1>,
        double a3@<st0>,
        __int16 a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivrp_sti_st(a1: a2, a2: a3);
  else
    _fdivrp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041F238
// Name: __adj_fdivr_m32i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m32i(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, int a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivrp_sti_st(a1: a2, a2: a3);
  else
    _fdivrp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041F26C
// Name: __safe_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __spoils<edx,ecx,st0> _safe_fdiv(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-30h]
  _TBYTE v3; // [esp+Ch] [ebp-24h]

  *(double *)&v2 = a1;
  *(double *)&v3 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0041F281
// Name: __safe_fdivr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __spoils<edx,ecx,st0> _safe_fdivr(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-30h]
  _TBYTE v3; // [esp+Ch] [ebp-24h]

  *(double *)&v3 = a1;
  *(double *)&v2 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0041F296
// Name: __fprem_common
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _fprem_common@<eax>(char a1@<dl>, __int128 a2, int a3, int a4, __int128 a5)
{
  unsigned int result; // eax
  int v6; // ecx
  double v7; // st7
  __int16 v8; // fps
  double v9; // st6
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  __int16 v13; // fps

  result = *(_DWORD *)((char *)&a2 + 6) ^ 0x700;
  if ( ((*(_DWORD *)((char *)&a2 + 6) ^ 0x700) & 0x700) == 0 )
  {
    result = (result >> 11) & 0xF;
    if ( fprem_risc_table[result] != 0 )
    {
      result = *(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000;
      if ( (*(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000) != 0x7FFF0000 )
      {
        result = *(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000;
        if ( (*(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000) != 0 && result != 2147418112 )
        {
          result = 2 * DWORD1(a5);
          if ( 2 * DWORD1(a5) == 0 )
          {
            result = 2 * DWORD1(a2);
            if ( 2 * DWORD1(a2) == 0 )
            {
              if ( (WORD4(a5) & 0x7FFFu) > (WORD4(a2) & 0x7FFFu) + 63 )
              {
                v6 = ((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1;
                v7 = fabs(*(long double *)&a2);
                v9 = fabs(*(long double *)&a5);
                do
                {
                  v10 = v9 < v7;
                  v11 = 0;
                  v12 = v9 == v7;
                  result = v8 & 0x100;
                  if ( (v8 & 0x100) == 0 )
                    v9 = v9 - v7;
                  v7 = v7 * *(double *)&half;
                  --v6;
                }
                while ( v6 != 0 );
              }
              else
              {
                while ( 1 )
                {
                  result = (WORD4(a2) & 0x7FFF) + 10;
                  if ( (int)((WORD4(a5) & 0x7FFF) - result) < 0 )
                    break;
                  *(double *)&a5 = __FPREM__(*(long double *)&a5, *(long double *)&a2);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (a1 & 3) != 0 )
  {
    __asm { fnstenv [esp+28h+var_28] }
    __asm { fldenv  [esp+28h+var_28] }
    return v13 & 0x4300;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F49C
// Name: __adj_fprem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __spoils<ecx,st0> _adj_fprem@<eax>(double a1@<st1>, double a2@<st0>)
{
  int result; // eax
  char v3; // dl
  _BYTE v4[20]; // [esp+0h] [ebp-34h]
  int v5; // [esp+14h] [ebp-20h]
  __int128 v6; // [esp+18h] [ebp-1Ch]

  *(double *)&v6 = a1;
  *(double *)v4 = a2;
  if ( (*(_DWORD *)&v4[6] & 0x7FFF0000) != 0 )
    return _fprem_common(a1: 0, a2: *(__int128 *)v4, a3: *(int *)&v4[16], a4: v5, a5: v6);
  result = *(_DWORD *)&v4[4] | *(_DWORD *)v4;
  if ( a2 != 0.0 )
  {
    *(double *)&v4[12] = a2;
    v3 = 2;
    if ( (WORD4(v6) & 0x7FFFu) <= 0x7FBE )
    {
      v3 = 3;
      *(double *)&v6 = a1 * *(double *)&one_shl_64;
    }
    *(double *)v4 = a2 * *(double *)&one_shl_64;
    return _fprem_common(a1: v3, a2: *(__int128 *)v4, a3: HIDWORD(*(unsigned __int64 *)&a2), a4: v5, a5: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F54E
// Name: __fprem1_common
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _fprem1_common@<eax>(char a1@<dl>, __int128 a2, int a3, int a4, __int128 a5)
{
  unsigned int result; // eax
  int v6; // ecx
  double v7; // st7
  __int16 v8; // fps
  double v9; // st6
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  __int16 v13; // fps

  result = *(_DWORD *)((char *)&a2 + 6) ^ 0x700;
  if ( ((*(_DWORD *)((char *)&a2 + 6) ^ 0x700) & 0x700) == 0 )
  {
    result = (result >> 11) & 0xF;
    if ( fprem_risc_table[result] != 0 )
    {
      result = *(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000;
      if ( (*(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000) != 0x7FFF0000 )
      {
        result = *(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000;
        if ( (*(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000) != 0 && result != 2147418112 )
        {
          result = 2 * DWORD1(a5);
          if ( 2 * DWORD1(a5) == 0 )
          {
            result = 2 * DWORD1(a2);
            if ( 2 * DWORD1(a2) == 0 )
            {
              if ( (WORD4(a5) & 0x7FFFu) > (WORD4(a2) & 0x7FFFu) + 63 )
              {
                v6 = ((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1;
                v7 = fabs(*(long double *)&a2);
                v9 = fabs(*(long double *)&a5);
                do
                {
                  v10 = v9 < v7;
                  v11 = 0;
                  v12 = v9 == v7;
                  result = v8 & 0x100;
                  if ( (v8 & 0x100) == 0 )
                    v9 = v9 - v7;
                  v7 = v7 * *(double *)&half;
                  --v6;
                }
                while ( v6 != 0 );
              }
              else
              {
                while ( 1 )
                {
                  result = (WORD4(a2) & 0x7FFF) + 10;
                  if ( (int)((WORD4(a5) & 0x7FFF) - result) < 0 )
                    break;
                  *(double *)&a5 = __FPREM__(*(long double *)&a5, *(long double *)&a2);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (a1 & 3) != 0 )
  {
    __asm { fnstenv [esp+28h+var_28] }
    __asm { fldenv  [esp+28h+var_28] }
    return v13 & 0x4300;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F754
// Name: __adj_fprem1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __spoils<ecx,st0> _adj_fprem1@<eax>(double a1@<st1>, double a2@<st0>)
{
  int result; // eax
  char v3; // dl
  _BYTE v4[20]; // [esp+0h] [ebp-34h]
  int v5; // [esp+14h] [ebp-20h]
  __int128 v6; // [esp+18h] [ebp-1Ch]

  *(double *)&v6 = a1;
  *(double *)v4 = a2;
  if ( (*(_DWORD *)&v4[6] & 0x7FFF0000) != 0 )
    return _fprem1_common(a1: 0, a2: *(__int128 *)v4, a3: *(int *)&v4[16], a4: v5, a5: v6);
  result = *(_DWORD *)&v4[4] | *(_DWORD *)v4;
  if ( a2 != 0.0 )
  {
    *(double *)&v4[12] = a2;
    v3 = 2;
    if ( (WORD4(v6) & 0x7FFFu) <= 0x7FBE )
    {
      v3 = 3;
      *(double *)&v6 = a1 * *(double *)&one_shl_64;
    }
    *(double *)v4 = a2 * *(double *)&one_shl_64;
    return _fprem1_common(a1: v3, a2: *(__int128 *)v4, a3: HIDWORD(*(unsigned __int64 *)&a2), a4: v5, a5: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F809
// Name: __safe_fprem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __usercall _safe_fprem@<eax>(double a1@<st1>, double a2@<st0>)
{
  return _adj_fprem(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041F80F
// Name: __safe_fprem1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __usercall _safe_fprem1@<eax>(double a1@<st1>, double a2@<st0>)
{
  return _adj_fprem1(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041F815
// Name: __adj_fpatan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _adj_fpatan@<st0>(long double a1@<st1>, long double a2@<st0>)
{
  return atan2(a2, a1);
}

//------------------------------------------------------------------------------
// Address: 0x0041F818
// Name: __adj_fptan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _adj_fptan()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0041F820
// Name: __CIpow_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIpow_pentium4()
{
  JUMPOUT(0x41F839);
}

//------------------------------------------------------------------------------
// Address: 0x00420391
// Name: __fFEXP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fFEXP@<eax>(__int16 a1@<cx>, int a2@<ebp>, double a3@<st0>)
{
  double v3; // st7

  *(_BYTE *)(a2 - 144) = -2;
  HIBYTE(a1) = 0;
  v3 = a3 * 1.442695040888963407;
  _ffexpm1(a1);
  if ( (*(_BYTE *)(a2 - 159) & 1) != 0 && _adjust_fdiv == 1 )
    _safe_fdivr(a1: 1.442695040888963407 + 1.0, a2: v3);
  return _rttospop();
}

//------------------------------------------------------------------------------
// Address: 0x004203F8
// Name: __rtinfpopse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtinfpopse@<eax>(double a1@<st0>)
{
  return _rtinfnpopse(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004203FA
// Name: __rtinfnpopse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtinfnpopse@<st0>(int a1@<ebp>)
{
  double result; // st7

  result = *(double *)&_infinity;
  *(_BYTE *)(a1 - 144) = 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042040A
// Name: __fFLN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _fFLN@<st0>(int a1@<ebp>, long double a2@<st0>)
{
  __int16 v2; // fps
  bool v3; // c0
  char v4; // c2
  bool v5; // c3
  long double result; // st7

  v3 = a2 < 0.0;
  v4 = 0;
  v5 = a2 == 0.0;
  *(_WORD *)(a1 - 160) = v2;
  if ( (*(_BYTE *)(a1 - 159) & 0x41) == 0 )
    return __FYL2X__(a2, 0.6931471805599453094);
  _rtindfpop(a1: 0.6931471805599453094);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420467
// Name: zerotoxdone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void zerotoxdone()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004204BF
// Name: __rtinfpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtinfpop@<eax>(double a1@<st0>)
{
  return _rtinfnpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004204C1
// Name: __rtinfnpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtinfnpop@<st0>(int a1@<ebp>)
{
  double result; // st7

  result = *(double *)&_infinity;
  *(_BYTE *)(a1 - 144) = 3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004204DE
// Name: __ffexpm1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __usercall _ffexpm1@<st0>(char a1@<ch>, int _EBP@<ebp>)
{
  double result; // st7

  __asm
  {
    fld     st
    fabs
    fld     _log2max
    fcompp
    fstsw   word ptr [ebp-0A0h]
  }
  if ( (*(_BYTE *)(_EBP - 159) & 0x41) != 0 )
  {
    __asm
    {
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    if ( (*(_BYTE *)(_EBP - 159) & 1) != 0 )
    {
      *(_BYTE *)(_EBP - 144) = 4;
      return _rtzeronpop();
    }
    else
    {
      __asm
      {
        fstp    st
        fld     __infinity
      }
      if ( a1 != 0 )
        __asm { fchs }
    }
  }
  else
  {
    __asm
    {
      fld     st
      frndint
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    __asm
    {
      fxch    st(1)
      fsub    st, st(1)
      ftst
      fstsw   word ptr [ebp-0A0h]
      fabs
      f2xm1
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420521
// Name: _isintTOS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isintTOS@<eax>(long double a1@<st0>)
{
  if ( rint(a1) != a1 )
    return notanint();
  if ( rint(a1 * *(double *)&half) == a1 * *(double *)&half )
    return evenint();
  return isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x00420546
// Name: _isintTOSret
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void isintTOSret()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00420547
// Name: notanint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void notanint()
{
  isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x0042054E
// Name: evenint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void evenint()
{
  isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x00420555
// Name: _usepowhlp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall usepowhlp@<st0>(int a1@<ebp>, long double y@<st1>, long double x@<st0>)
{
  int v4; // eax
  long double result; // st7
  long double *v6; // [esp+10h] [ebp-7Ch]
  long double v7[15]; // [esp+14h] [ebp-78h] BYREF

  _ESI = v7;
  v6 = v7;
  __asm { fsave   byte ptr [esi+8] }
  v4 = _powhlp(x, y, result: v7);
  __asm { frstor  byte ptr [esi+8] }
  result = v7[0];
  if ( v4 != 0 )
    _rttosnpopde(a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420587
// Name: __d_inttype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _d_inttype(long double y)
{
  if ( (_fpclass(x: y) & 0x90) != 0 || _frnd(x: y) != y )
    return 0;
  if ( _frnd(x: y * 0.5) == y * 0.5 )
    return 2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004205EB
// Name: __powhlp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _powhlp(double x, long double y, long double *result)
{
  long double dbl; // st7
  int v4; // esi
  long double v5; // st6
  double *v6; // eax
  int v7; // eax

  dbl = 0.0;
  v4 = 0;
  v5 = x;
  if ( x < 0.0 )
    v5 = -x;
  if ( HIDWORD(y) == 2146435072 )
  {
    if ( LODWORD(y) == 0 )
    {
      if ( v5 <= 1.0 )
      {
        v6 = result;
        if ( v5 >= 1.0 )
          dbl = 1.0;
        goto LABEL_28;
      }
      goto LABEL_6;
    }
  }
  else if ( y == -INFINITY )
  {
    if ( v5 > 1.0 )
      goto LABEL_27;
    v6 = result;
    if ( v5 < 1.0 )
    {
      dbl = _d_inf.dbl;
LABEL_28:
      *v6 = dbl;
      return v4;
    }
    *result = _d_ind.dbl;
    return 1;
  }
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( LODWORD(x) == 0 )
    {
      if ( y <= 0.0 )
      {
        v6 = result;
        if ( y >= 0.0 )
          dbl = 1.0;
        goto LABEL_28;
      }
LABEL_6:
      dbl = _d_inf.dbl;
LABEL_27:
      v6 = result;
      goto LABEL_28;
    }
  }
  else if ( x == -INFINITY )
  {
    v7 = _d_inttype(y);
    dbl = 0.0;
    if ( y <= 0.0 )
    {
      if ( y >= 0.0 )
      {
        dbl = 1.0;
      }
      else if ( v7 == 1 )
      {
        dbl = _d_mzero.dbl;
      }
    }
    else
    {
      dbl = _d_inf.dbl;
      if ( v7 == 1 )
        dbl = -_d_inf.dbl;
    }
    goto LABEL_27;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00420729
// Name: ___libm_error_support
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_error_support(long double *arg1, long double *arg2, long double *retval, error_types input_tag)
{
  int (__cdecl *v4)(_exception *); // eax
  long double v5; // st7
  long double v6; // st7
  long double v7; // st7
  _exception exc; // [esp+Ch] [ebp-28h] BYREF
  char double_zero[8]; // [esp+2Ch] [ebp-8h]

  double_zero[0] = 0;
  double_zero[1] = 0;
  double_zero[2] = 0;
  double_zero[3] = 0;
  double_zero[4] = 0;
  double_zero[5] = 0;
  double_zero[6] = 0;
  double_zero[7] = 0;
  if ( pmatherr_set != 0 )
    v4 = (int (__cdecl *)(_exception *))_decode_pointer(codedptr: _pmatherr);
  else
    v4 = _matherr;
  if ( input_tag > exp10_overflow )
  {
    switch ( input_tag )
    {
      case log_nan:
        exc.name = "log";
        goto LABEL_37;
      case log10_nan:
        exc.name = "log10";
        goto LABEL_37;
      case exp_nan:
        exc.name = "exp";
        goto LABEL_37;
      case atan_nan:
        exc.name = "atan";
        goto LABEL_37;
      case ceil_nan:
        exc.name = "ceil";
        goto LABEL_37;
      case floor_nan:
        exc.name = "floor";
        goto LABEL_37;
      case pow_nan:
        goto $LN36;
      case modf_nan:
        exc.name = "modf";
        goto LABEL_37;
      case acos_nan:
        goto $LN30;
      case asin_nan:
        goto $LN8_10;
      case sin_naninf:
        exc.name = "sin";
        goto LABEL_53;
      case cos_naninf:
        exc.name = "cos";
        goto LABEL_53;
      case tan_naninf:
        exc.name = "tan";
LABEL_53:
        v6 = *arg1 * *(double *)double_zero;
        *retval = v6;
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        goto LABEL_54;
      default:
        return;
    }
  }
  if ( input_tag == exp10_overflow )
  {
    exc.type = 3;
    exc.name = "exp10";
    goto LABEL_17;
  }
  if ( input_tag <= pow_underflow )
  {
    switch ( input_tag )
    {
      case pow_underflow:
        exc.name = "pow";
        goto LABEL_20;
      case log_zero:
        exc.type = 2;
        exc.name = "log";
        goto LABEL_17;
      case log_negative:
        exc.name = "log";
        break;
      case log10_zero:
        exc.type = 2;
        exc.name = "log10";
        goto LABEL_17;
      case log10_negative:
        exc.name = "log10";
        break;
      case exp_overflow:
        exc.type = 3;
        exc.name = "exp";
LABEL_17:
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        exc.retval = *retval;
        if ( v4(pexcept: &exc) == 0 )
          *_errno() = 34;
        goto LABEL_56;
      case exp_underflow:
        exc.name = "exp";
LABEL_20:
        exc.arg1 = *arg1;
        v5 = *arg2;
        exc.type = 4;
        exc.arg2 = v5;
        exc.retval = *retval;
        v4(pexcept: &exc);
LABEL_56:
        v7 = exc.retval;
        goto LABEL_57;
      case pow_overflow:
        exc.type = 3;
        goto LABEL_16;
      default:
        return;
    }
LABEL_23:
    exc.arg1 = *arg1;
    exc.arg2 = *arg2;
    v6 = *retval;
LABEL_54:
    exc.retval = v6;
    exc.type = 1;
    if ( v4(pexcept: &exc) == 0 )
      *_errno() = 33;
    goto LABEL_56;
  }
  if ( input_tag != pow_zero_to_zero )
  {
    switch ( input_tag )
    {
      case pow_zero_to_negative:
        exc.type = 2;
LABEL_16:
        exc.name = "pow";
        goto LABEL_17;
      case pow_neg_to_non_integer:
$LN36:
        exc.name = "pow";
        break;
      case pow_nan_to_zero:
        exc.name = "pow";
LABEL_37:
        *retval = *arg1;
        break;
      case acos_gt_one:
$LN30:
        exc.name = "acos";
        break;
      case asin_gt_one:
$LN8_10:
        exc.name = "asin";
        break;
      default:
        return;
    }
    goto LABEL_23;
  }
  v7 = 1.0;
LABEL_57:
  *retval = v7;
}

//------------------------------------------------------------------------------
// Address: 0x004209D9
// Name: __floor_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _floor_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]

  v1 = _ctrlfp(newctrl: newcw, _mask: 0xFFFFu);
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp(newctrl: v1, _mask: 0xFFFFu);
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xBu, x, savedcw: v1);
    }
    return _except1(flags: 8, opcode: 11, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp(newctrl: v1, _mask: 0xFFFFu);
      return v4;
    }
    else
    {
      return _except1(flags: 16, opcode: 11, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420AAA
// Name: CPtoLCID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CPtoLCID@<eax>(int codepage@<eax>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax

  v1 = codepage - 932;
  if ( v1 == 0 )
    return 1041;
  v2 = v1 - 4;
  if ( v2 == 0 )
    return 2052;
  v3 = v2 - 13;
  if ( v3 == 0 )
    return 1042;
  if ( v3 == 1 )
    return 1028;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00420AD9
// Name: setSBCS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBCS(threadmbcinfostruct *ptmbci@<eax>)
{
  int v1; // ebp
  unsigned __int8 *mbctype; // ebx
  int v4; // eax
  unsigned __int8 *mbcasemap; // ecx
  int i; // esi

  v1 = 257;
  mbctype = ptmbci->mbctype;
  memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
  ptmbci->mbcodepage = 0;
  ptmbci->ismbcodepage = 0;
  ptmbci->mblcid = 0;
  *(_DWORD *)ptmbci->mbulinfo = 0;
  *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
  *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
  v4 = (char *)&__initialmbcinfo - (char *)ptmbci;
  do
  {
    *mbctype = mbctype[v4];
    ++mbctype;
    --v1;
  }
  while ( v1 != 0 );
  mbcasemap = ptmbci->mbcasemap;
  for ( i = 256; i != 0; --i )
  {
    *mbcasemap = mbcasemap[v4];
    ++mbcasemap;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420B2E
// Name: setSBUpLow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBUpLow(threadmbcinfostruct *ptmbci@<esi>)
{
  unsigned int i; // eax
  unsigned __int8 v2; // al
  unsigned __int8 *v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned __int8 *v6; // ebx
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int8 v9; // cl
  unsigned int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 v12; // dl
  int v13; // [esp+8h] [ebp-80h]
  _cpinfo cpinfo; // [esp+Ch] [ebp-7Ch] BYREF
  unsigned __int16 wVector[256]; // [esp+20h] [ebp-68h] BYREF
  unsigned __int8 upVector[256]; // [esp+220h] [ebp+198h] BYREF
  unsigned __int8 lowVector[256]; // [esp+320h] [ebp+298h] BYREF
  unsigned __int8 sbVector[256]; // [esp+420h] [ebp+398h] BYREF

  if ( GetCPInfo(CodePage: ptmbci->mbcodepage, lpCPInfo: &cpinfo) )
  {
    for ( i = 0; i < 0x100; ++i )
      sbVector[i] = i;
    v2 = cpinfo.LeadByte[0];
    sbVector[0] = 32;
    if ( cpinfo.LeadByte[0] != 0 )
    {
      v3 = &cpinfo.LeadByte[1];
      do
      {
        v4 = v2;
        v5 = *v3;
        if ( v4 <= v5 )
          memset(dst: (int)&sbVector[v4], value: (unsigned __int8 *)0x20, count: v5 - v4 + 1);
        v6 = v3 + 1;
        v2 = *v6;
        v3 = v6 + 1;
      }
      while ( v2 != 0 );
    }
    __crtGetStringTypeA(
      plocinfo: nullptr,
      dwInfoType: 1u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpCharType: wVector,
      code_page: ptmbci->mbcodepage,
      lcid: ptmbci->mblcid,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x100u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)lowVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x200u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)upVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    v7 = 0;
    while ( 1 )
    {
      v8 = wVector[v7];
      if ( (v8 & 1) != 0 )
      {
        ptmbci->mbctype[v7 + 1] |= 0x10u;
        v9 = lowVector[v7];
      }
      else
      {
        if ( (v8 & 2) == 0 )
        {
          ptmbci->mbcasemap[v7] = 0;
          goto LABEL_16;
        }
        ptmbci->mbctype[v7 + 1] |= 0x20u;
        v9 = upVector[v7];
      }
      ptmbci->mbcasemap[v7] = v9;
LABEL_16:
      if ( (unsigned int)++v7 >= 0x100 )
        return;
    }
  }
  v10 = 0;
  v13 = -97 - (_DWORD)ptmbci->mbcasemap;
  do
  {
    v11 = &ptmbci->mbcasemap[v10];
    if ( (unsigned int)&v11[v13 + 32] <= 0x19 )
    {
      ptmbci->mbctype[v10 + 1] |= 0x10u;
      v12 = v10 + 32;
LABEL_23:
      *v11 = v12;
      goto LABEL_25;
    }
    if ( (unsigned int)&v11[v13] <= 0x19 )
    {
      ptmbci->mbctype[v10 + 1] |= 0x20u;
      v12 = v10 - 32;
      goto LABEL_23;
    }
    *v11 = 0;
LABEL_25:
    ++v10;
  }
  while ( v10 < 0x100 );
}

//------------------------------------------------------------------------------
// Address: 0x00420CB8
// Name: ___updatetmbcinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadmbcinfostruct *__cdecl __updatetmbcinfo()
{
  _tiddata *v0; // edi
  threadmbcinfostruct *ptmbcinfo; // esi

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptmbcinfo = v0->ptmbcinfo;
  }
  else
  {
    _lock(locknum: 13);
    ptmbcinfo = v0->ptmbcinfo;
    if ( ptmbcinfo != __ptmbcinfo )
    {
      if ( ptmbcinfo != nullptr
        && InterlockedDecrement(lpAddend: &ptmbcinfo->refcount) == 0
        && ptmbcinfo != &__initialmbcinfo )
      {
        free(pMem: ptmbcinfo);
      }
      v0->ptmbcinfo = __ptmbcinfo;
      ptmbcinfo = __ptmbcinfo;
      InterlockedIncrement(lpAddend: &__ptmbcinfo->refcount);
    }
    _unlock(locknum: 13);
  }
  if ( ptmbcinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptmbcinfo;
}

//------------------------------------------------------------------------------
// Address: 0x00420D5C
// Name: getSystemCP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT __usercall getSystemCP@<eax>(int codepage@<esi>)
{
  UINT result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: nullptr);
  fSystemSet = 0;
  switch ( codepage )
  {
    case -2:
      fSystemSet = 1;
      result = GetOEMCP();
      goto LABEL_3;
    case -3:
      fSystemSet = 1;
      result = GetACP();
      goto LABEL_3;
    case -4:
      result = _loc_update.localeinfo.locinfo->lc_codepage;
      fSystemSet = 1;
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    default:
      break;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return codepage;
}

//------------------------------------------------------------------------------
// Address: 0x00420DD6
// Name: __setmbcp_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp_nolock(int codepage, threadmbcinfostruct *ptmbci)
{
  UINT SystemCP; // edi
  unsigned int i; // eax
  bool v5; // cc
  unsigned __int8 *v6; // esi
  unsigned __int8 v7; // cl
  unsigned int k; // eax
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned __int16 *mbulinfo; // eax
  int v13; // ecx
  unsigned __int16 *v14; // ecx
  int j; // edx
  unsigned __int8 *v16; // eax
  int m; // ecx
  int v18; // edx
  unsigned int irg; // [esp+Ch] [ebp-20h]
  unsigned int icp; // [esp+10h] [ebp-1Ch]
  unsigned int icpa; // [esp+10h] [ebp-1Ch]
  _cpinfo cpinfo; // [esp+14h] [ebp-18h] BYREF
  int codepagea; // [esp+34h] [ebp+8h]

  SystemCP = getSystemCP(codepage);
  codepagea = SystemCP;
  if ( SystemCP != 0 )
  {
    icp = 0;
    for ( i = 0; i < 5; ++i )
    {
      if ( _rgcode_page_info[i].code_page == SystemCP )
      {
        memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
        irg = 0;
        v9 = _rgcode_page_info[icp].rgrange[0];
        icpa = (unsigned int)v9;
        do
        {
          while ( *v9 != 0 )
          {
            LOBYTE(v10) = v9[1];
            if ( (_BYTE)v10 == 0 )
              break;
            v11 = *v9;
            v10 = (unsigned __int8)v10;
            while ( v11 <= v10 )
            {
              ptmbci->mbctype[v11 + 1] |= _rgctypeflag[irg];
              v10 = v9[1];
              ++v11;
            }
            SystemCP = codepagea;
            v9 += 2;
          }
          ++irg;
          v9 = (unsigned __int8 *)(icpa + 8);
          icpa += 8;
        }
        while ( irg < 4 );
        ptmbci->mbcodepage = SystemCP;
        ptmbci->ismbcodepage = 1;
        ptmbci->mblcid = CPtoLCID(codepage: SystemCP);
        mbulinfo = ptmbci->mbulinfo;
        v14 = (unsigned __int16 *)((char *)_rgcode_page_info[0].mbulinfo + v13);
        for ( j = 6; j != 0; --j )
          *mbulinfo++ = *v14++;
LABEL_26:
        setSBUpLow(ptmbci);
        return 0;
      }
      ++icp;
    }
    if ( SystemCP == 65000 || SystemCP == 65001 || !IsValidCodePage(CodePage: (unsigned __int16)SystemCP) )
      return -1;
    if ( GetCPInfo(CodePage: SystemCP, lpCPInfo: &cpinfo) )
    {
      memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
      v5 = cpinfo.MaxCharSize <= 1;
      ptmbci->mbcodepage = SystemCP;
      ptmbci->mblcid = 0;
      if ( v5 )
      {
        ptmbci->ismbcodepage = 0;
      }
      else
      {
        if ( cpinfo.LeadByte[0] != 0 )
        {
          v6 = &cpinfo.LeadByte[1];
          do
          {
            v7 = *v6;
            if ( *v6 == 0 )
              break;
            for ( k = *(v6 - 1); k <= v7; ++k )
              ptmbci->mbctype[k + 1] |= 4u;
            v6 += 2;
          }
          while ( *(v6 - 1) != 0 );
        }
        v16 = &ptmbci->mbctype[2];
        for ( m = 254; m != 0; --m )
          *v16++ |= 8u;
        ptmbci->mblcid = CPtoLCID(codepage: ptmbci->mbcodepage);
        ptmbci->ismbcodepage = v18;
      }
      *(_DWORD *)ptmbci->mbulinfo = 0;
      *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
      *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
      goto LABEL_26;
    }
    if ( fSystemSet == 0 )
      return -1;
  }
  setSBCS(ptmbci);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00420FAF
// Name: __setmbcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp(int codepage)
{
  _tiddata *v1; // edi
  threadmbcinfostruct *ptmbcinfo; // ebx
  threadmbcinfostruct *v3; // eax
  threadmbcinfostruct *v4; // ebx
  int v5; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  int retcode; // [esp+14h] [ebp-20h]
  UINT codepagea; // [esp+3Ch] [ebp+8h]

  retcode = -1;
  v1 = _getptd();
  __updatetmbcinfo();
  ptmbcinfo = v1->ptmbcinfo;
  codepagea = getSystemCP(codepage);
  if ( codepagea == ptmbcinfo->mbcodepage )
    return 0;
  v3 = (threadmbcinfostruct *)operator new(nSize: 0x220u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    qmemcpy(v3, v1->ptmbcinfo, sizeof(threadmbcinfostruct));
    v3->refcount = 0;
    v5 = _setmbcp_nolock(codepage: codepagea, ptmbci: v3);
    retcode = v5;
    if ( v5 != 0 )
    {
      if ( v5 == -1 )
      {
        if ( v4 != &__initialmbcinfo )
          free(pMem: v4);
        *_errno() = 22;
      }
    }
    else
    {
      if ( InterlockedDecrement(lpAddend: &v1->ptmbcinfo->refcount) == 0 && v1->ptmbcinfo != &__initialmbcinfo )
        free(pMem: v1->ptmbcinfo);
      v1->ptmbcinfo = v4;
      InterlockedIncrement(lpAddend: &v4->refcount);
      if ( (v1->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
      {
        _lock(locknum: 13);
        __mbcodepage = v4->mbcodepage;
        __ismbcodepage = v4->ismbcodepage;
        __mblcid = v4->mblcid;
        for ( i = 0; i < 5; ++i )
          __mbulinfo[i] = v4->mbulinfo[i];
        for ( j = 0; j < 257; ++j )
          _mbctype[j] = v4->mbctype[j];
        for ( k = 0; k < 256; ++k )
          _mbcasemap[k] = v4->mbcasemap[k];
        if ( InterlockedDecrement(lpAddend: &__ptmbcinfo->refcount) == 0 && __ptmbcinfo != &__initialmbcinfo )
          free(pMem: __ptmbcinfo);
        __ptmbcinfo = v4;
        InterlockedIncrement(lpAddend: &v4->refcount);
        _unlock(locknum: 13);
      }
    }
  }
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x00421149
// Name: ___initmbctable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initmbctable()
{
  if ( __mbctype_initialized == 0 )
  {
    _setmbcp(codepage: -3);
    __mbctype_initialized = 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00421167
// Name: ___freetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __freetlocinfo(threadlocaleinfostruct *ptloci)
{
  lconv *lconv; // eax
  int *lconv_intl_refcount; // eax
  int *lconv_mon_refcount; // eax
  int *lconv_num_refcount; // eax
  int *ctype1_refcount; // eax
  __lc_time_data *lc_time_curr; // eax
  void **p_refcount; // edi
  int i; // ebx
  _DWORD *v9; // eax

  lconv = ptloci->lconv;
  if ( lconv != nullptr && lconv != &__lconv_c )
  {
    lconv_intl_refcount = ptloci->lconv_intl_refcount;
    if ( lconv_intl_refcount != nullptr && *lconv_intl_refcount == 0 )
    {
      lconv_mon_refcount = ptloci->lconv_mon_refcount;
      if ( lconv_mon_refcount != nullptr && *lconv_mon_refcount == 0 )
      {
        free(pMem: ptloci->lconv_mon_refcount);
        __free_lconv_mon(l: ptloci->lconv);
      }
      lconv_num_refcount = ptloci->lconv_num_refcount;
      if ( lconv_num_refcount != nullptr && *lconv_num_refcount == 0 )
      {
        free(pMem: ptloci->lconv_num_refcount);
        __free_lconv_num(l: ptloci->lconv);
      }
      free(pMem: ptloci->lconv_intl_refcount);
      free(pMem: ptloci->lconv);
    }
  }
  ctype1_refcount = ptloci->ctype1_refcount;
  if ( ctype1_refcount != nullptr && *ctype1_refcount == 0 )
  {
    free(pMem: ptloci->ctype1 - 127);
    free(pMem: (void *)(ptloci->pclmap - 128));
    free(pMem: (void *)(ptloci->pcumap - 128));
    free(pMem: ptloci->ctype1_refcount);
  }
  lc_time_curr = ptloci->lc_time_curr;
  if ( lc_time_curr != &__lc_time_c && lc_time_curr->refcount == 0 )
  {
    __free_lc_time(lc_time: ptloci->lc_time_curr);
    free(pMem: ptloci->lc_time_curr);
  }
  p_refcount = (void **)&ptloci->lc_category[0].refcount;
  for ( i = 6; i != 0; --i )
  {
    if ( *(p_refcount - 2) != __clocalestr && *p_refcount != nullptr && *(_DWORD *)*p_refcount == 0 )
      free(pMem: *p_refcount);
    if ( *(p_refcount - 1) != nullptr )
    {
      v9 = p_refcount[1];
      if ( v9 != nullptr && *v9 == 0 )
        free(pMem: p_refcount[1]);
    }
    p_refcount += 4;
  }
  free(pMem: ptloci);
}

//------------------------------------------------------------------------------
// Address: 0x004212A7
// Name: ___addlocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __addlocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int i; // ebp

  InterlockedIncrement(lpAddend: &ptloci->refcount);
  if ( ptloci->lconv_intl_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_intl_refcount);
  if ( ptloci->lconv_mon_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_mon_refcount);
  if ( ptloci->lconv_num_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_num_refcount);
  if ( ptloci->ctype1_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->ctype1_refcount);
  p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
  for ( i = 6; i != 0; --i )
  {
    if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
      InterlockedIncrement(lpAddend: *p_refcount);
    if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
      InterlockedIncrement(lpAddend: p_refcount[1]);
    p_refcount += 4;
  }
  InterlockedIncrement(lpAddend: &ptloci->lc_time_curr->refcount);
}

//------------------------------------------------------------------------------
// Address: 0x0042132D
// Name: ___removelocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __removelocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int i; // ebp

  if ( ptloci != nullptr )
  {
    InterlockedDecrement(lpAddend: &ptloci->refcount);
    if ( ptloci->lconv_intl_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_intl_refcount);
    if ( ptloci->lconv_mon_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_mon_refcount);
    if ( ptloci->lconv_num_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_num_refcount);
    if ( ptloci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->ctype1_refcount);
    p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
    for ( i = 6; i != 0; --i )
    {
      if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
        InterlockedDecrement(lpAddend: *p_refcount);
      if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
        InterlockedDecrement(lpAddend: p_refcount[1]);
      p_refcount += 4;
    }
    InterlockedDecrement(lpAddend: &ptloci->lc_time_curr->refcount);
  }
  return ptloci;
}

//------------------------------------------------------------------------------
// Address: 0x004213B9
// Name: _updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__usercall updatetlocinfoEx_nolock@<eax>(
        threadlocaleinfostruct **pptlocid@<eax>,
        threadlocaleinfostruct *ptlocis@<edi>)
{
  threadlocaleinfostruct *v2; // esi

  if ( ptlocis == nullptr || pptlocid == nullptr )
    return nullptr;
  v2 = *pptlocid;
  if ( *pptlocid != ptlocis )
  {
    *pptlocid = ptlocis;
    __addlocaleref(ptloci: ptlocis);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: v2);
      if ( v2->refcount == 0 && v2 != &__initiallocinfo )
        __freetlocinfo(ptloci: v2);
    }
  }
  return ptlocis;
}

//------------------------------------------------------------------------------
// Address: 0x004213F7
// Name: ___updatetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __updatetlocinfo()
{
  _tiddata *v0; // esi
  threadlocaleinfostruct *ptlocinfo; // esi
  threadlocaleinfostruct *ptloci; // [esp+10h] [ebp-1Ch]

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptlocinfo = _getptd()->ptlocinfo;
  }
  else
  {
    _lock(locknum: 12);
    ptloci = updatetlocinfoEx_nolock(pptlocid: &v0->ptlocinfo, ptlocis: __ptlocinfo);
    _unlock(locknum: 12);
    ptlocinfo = ptloci;
  }
  if ( ptlocinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptlocinfo;
}

//------------------------------------------------------------------------------
// Address: 0x0042146D
// Name: __fltin2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_flt *__cdecl _fltin2(
        _flt *flt,
        const char *str,
        int len_ignore,
        int scale_ignore,
        int radix_ignore,
        localeinfo_struct *_Locale)
{
  int v6; // ebx
  INTRNCVT_STATUS v7; // eax
  const char *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const char *v10; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v10 = str;
  v6 = 0;
  flags = __strgtold12_l(pld12: &ld12, p_end_ptr: &EndPtr, str, mult12: 0, scale: 0, decpt: 0, implicit_E: 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v6 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v7 = _ld12tod(pld12: &ld12, d: &x);
    if ( (flags & 2) != 0 || v7 == INTRNCVT_OVERFLOW )
      v6 = 128;
    if ( (flags & 1) != 0 || v7 == INTRNCVT_UNDERFLOW )
      v6 |= 0x100u;
  }
  flt->nbytes = EndPtr - v10;
  flt->dval = x.x;
  flt->flags = v6;
  return flt;
}

//------------------------------------------------------------------------------
// Address: 0x00421512
// Name: __isctype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isctype_l(int c, int mask, localeinfo_struct *plocinfo)
{
  __int16 v3; // bx
  int v4; // eax
  int v5; // ecx
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char buffer[4]; // [esp+14h] [ebp-8h] BYREF
  unsigned __int16 chartype; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = c;
  if ( (unsigned int)(c + 1) <= 0x100 )
  {
    v4 = _loc_update.localeinfo.locinfo->pctype[c];
    goto LABEL_11;
  }
  ca = c >> 8;
  if ( _isleadbyte_l(c: HIBYTE(v3), plocinfo: &_loc_update.localeinfo) != 0 )
  {
    buffer[0] = ca;
    buffer[1] = v3;
    buffer[2] = 0;
    v5 = 2;
  }
  else
  {
    buffer[0] = v3;
    buffer[1] = 0;
    v5 = 1;
  }
  if ( __crtGetStringTypeA(
         plocinfo: &_loc_update.localeinfo,
         dwInfoType: 1u,
         lpSrcStr: buffer,
         cchSrc: v5,
         lpCharType: &chartype,
         code_page: _loc_update.localeinfo.locinfo->lc_codepage,
         lcid: _loc_update.localeinfo.locinfo->lc_handle[2],
         bError: 1) != 0 )
  {
    v4 = chartype;
LABEL_11:
    result = mask & v4;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004215C8
// Name: ___strgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __strgtold12_l(
        _LDBL12 *pld12,
        const char **p_end_ptr,
        const char *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v8; // ecx
  char *v9; // edi
  const char *v11; // edx
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // eax
  const char *v16; // edx
  int v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  _LDBL12 *v24; // esi
  char v25; // al
  int v26; // eax
  _LDBL12 *v27; // eax
  _LDBL12 *v28; // ebx
  __int16 v29; // dx
  __int16 v30; // ax
  unsigned __int16 v31; // dx
  __int16 v32; // ax
  unsigned __int16 v33; // di
  int v34; // eax
  _WORD *v35; // esi
  unsigned int v36; // ecx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  __int16 v39; // di
  unsigned int v40; // ecx
  int v41; // esi
  int v42; // ecx
  int v43; // esi
  unsigned int v44; // ecx
  int v45; // ebx
  int v46; // ecx
  __int16 v47; // cx
  int v48; // esi
  unsigned int v49; // edx
  __int16 v50; // ax
  int v51; // [esp-4h] [ebp-8Ch]
  int v52; // [esp-4h] [ebp-8Ch]
  int v53; // [esp+10h] [ebp-78h]
  __int16 man_sign; // [esp+14h] [ebp-74h]
  _LDBL12 *v55; // [esp+18h] [ebp-70h]
  unsigned int result_flags; // [esp+1Ch] [ebp-6Ch]
  int exp_sign; // [esp+20h] [ebp-68h]
  int exp_signa; // [esp+20h] [ebp-68h]
  int pow; // [esp+24h] [ebp-64h]
  int powa; // [esp+24h] [ebp-64h]
  int found_exponent; // [esp+28h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+28h] [ebp-60h]
  int found_decpoint; // [esp+2Ch] [ebp-5Ch]
  unsigned __int8 *found_decpointa; // [esp+2Ch] [ebp-5Ch]
  int found_digit; // [esp+30h] [ebp-58h]
  int found_digita; // [esp+30h] [ebp-58h]
  const char *savedp; // [esp+34h] [ebp-54h]
  int savedpa; // [esp+34h] [ebp-54h]
  int exp_adj; // [esp+38h] [ebp-50h]
  int exp_adja; // [esp+38h] [ebp-50h]
  unsigned int manlen; // [esp+3Ch] [ebp-4Ch]
  unsigned int manlena; // [esp+3Ch] [ebp-4Ch]
  __int64 v73; // [esp+40h] [ebp-48h] BYREF
  int v74; // [esp+48h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+4Ch] [ebp-3Ch] BYREF
  _BYTE v76[12]; // [esp+5Ch] [ebp-2Ch] BYREF
  char buf[28]; // [esp+68h] [ebp-20h] BYREF

  v8 = 0;
  v9 = buf;
  man_sign = 0;
  exp_sign = 1;
  manlen = 0;
  found_digit = 0;
  found_decpoint = 0;
  found_exponent = 0;
  pow = 0;
  exp_adj = 0;
  result_flags = 0;
  if ( _Locale == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)buf, a3: 1u);
    return 0;
  }
  v11 = str;
  savedp = str;
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v11;
  }
  while ( 2 )
  {
    v13 = *v11++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v14 = v13 - 43;
        if ( v14 == 0 )
        {
          man_sign = 0;
          v8 = 2;
          continue;
        }
        v15 = v14 - 2;
        if ( v15 == 0 )
        {
          v8 = 2;
          man_sign = 0x8000;
          continue;
        }
        if ( v15 != 3 )
          goto LABEL_75;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_33;
        if ( v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (v13 <= 99 || v13 > 101) )
          goto LABEL_75;
        v52 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
        {
LABEL_11:
          v51 = 3;
LABEL_12:
          v8 = v51;
          --v11;
        }
        else
        {
          if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v52 = 5;
            goto LABEL_15;
          }
          if ( v13 != 48 )
          {
LABEL_37:
            v16 = savedp;
            goto LABEL_82;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        found_digit = 1;
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen >= 0x19 )
          {
            ++exp_adj;
          }
          else
          {
            ++manlen;
            *v9++ = v13 - 48;
          }
          v13 = *v11++;
        }
        if ( v13 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_46;
LABEL_24:
        v52 = 4;
        goto LABEL_15;
      case 4:
        found_digit = 1;
        found_decpoint = 1;
        if ( manlen == 0 )
        {
          while ( v13 == 48 )
          {
            --exp_adj;
            v13 = *v11++;
          }
        }
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            *v9++ = v13 - 48;
            --exp_adj;
          }
          v13 = *v11++;
        }
LABEL_46:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_33:
        --v11;
        v52 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int8)(v13 - 48) > 9u )
          goto LABEL_37;
        v51 = 4;
        goto LABEL_12;
      case 6:
        savedp = v11 - 2;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v17 = v13 - 43;
        if ( v17 == 0 )
          goto LABEL_70;
        v18 = v17 - 2;
        if ( v18 == 0 )
          goto LABEL_69;
        v19 = v18 == 3;
LABEL_67:
        if ( !v19 )
          goto LABEL_37;
        v52 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v19 = v13 == 48;
        goto LABEL_67;
      case 8:
        found_exponent = 1;
        while ( v13 == 48 )
          v13 = *v11++;
        if ( (unsigned __int8)(v13 - 49) > 8u )
          goto LABEL_75;
LABEL_63:
        v51 = 9;
        goto LABEL_12;
      case 9:
        found_exponent = 1;
        v21 = 0;
        while ( 2 )
        {
          if ( v13 >= 48 && v13 <= 57 )
          {
            v21 = 10 * v21 + v13 - 48;
            if ( v21 <= 5200 )
            {
              v13 = *v11++;
              continue;
            }
            v21 = 5201;
          }
          break;
        }
        pow = v21;
        while ( v13 >= 48 && v13 <= 57 )
          v13 = *v11++;
LABEL_75:
        v16 = v11 - 1;
        goto LABEL_82;
      case 11:
        if ( implicit_E != 0 )
        {
          v20 = v13 - 43;
          savedp = v11 - 1;
          if ( v20 != 0 )
          {
            if ( v20 != 2 )
            {
              v16 = v11 - 1;
              goto LABEL_82;
            }
LABEL_69:
            exp_sign = -1;
            v8 = 7;
          }
          else
          {
LABEL_70:
            v52 = 7;
LABEL_15:
            v8 = v52;
          }
          continue;
        }
        v16 = v11 - 1;
LABEL_82:
        *p_end_ptr = v16;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_174:
          v47 = 0;
          v50 = 0;
          v49 = 0;
          v48 = 0;
          goto LABEL_175;
        }
        if ( manlen > 0x18 )
        {
          if ( buf[23] >= 5 )
            ++buf[23];
          --v9;
          ++exp_adj;
          manlen = 24;
        }
        if ( manlen == 0 )
          goto LABEL_174;
        while ( *--v9 == 0 )
        {
          --manlen;
          ++exp_adj;
        }
        __mtold12(manptr: buf, manlen, ld12: &tmpld12);
        v22 = pow;
        if ( exp_sign < 0 )
          v22 = -pow;
        v23 = exp_adj + v22;
        if ( found_exponent == 0 )
          v23 += scale;
        if ( found_decpoint == 0 )
          v23 -= decpt;
        if ( v23 > 5200 )
        {
          v48 = 0;
          v50 = 0x7FFF;
          v49 = 0x80000000;
          v47 = 0;
          result_flags = 2;
          goto LABEL_175;
        }
        if ( v23 < -5200 )
        {
          result_flags = 1;
          goto LABEL_174;
        }
        v24 = &_pow10pos[-8];
        savedpa = v23;
        if ( v23 != 0 )
        {
          if ( v23 < 0 )
          {
            savedpa = -v23;
            v24 = &_pow10neg[-8];
          }
          if ( mult12 == 0 )
            *(_WORD *)tmpld12.ld12 = 0;
          while ( savedpa != 0 )
          {
            v25 = savedpa;
            savedpa >>= 3;
            v24 += 7;
            v26 = v25 & 7;
            manlena = (unsigned int)v24;
            if ( v26 != 0 )
            {
              v27 = &v24[v26];
              v28 = v27;
              v55 = v27;
              if ( *(_WORD *)v27->ld12 >= 0x8000u )
              {
                v73 = *(_QWORD *)v27->ld12;
                v74 = *(_DWORD *)&v27->ld12[8];
                --*(_DWORD *)((char *)&v73 + 2);
                v28 = (_LDBL12 *)&v73;
                v55 = (_LDBL12 *)&v73;
              }
              v29 = *(_WORD *)&v28->ld12[10];
              exp_adja = 0;
              memset(v76, 0, sizeof(v76));
              v30 = *(_WORD *)&tmpld12.ld12[10] ^ v29;
              v31 = v29 & 0x7FFF;
              v32 = v30 & 0x8000;
              v33 = v31 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF || v31 >= 0x7FFFu || v33 > 0xBFFDu )
              {
LABEL_167:
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                v34 = v32 != 0 ? -32768 : 2147450880;
                *(_DWORD *)tmpld12.ld12 = 0;
                goto LABEL_168;
              }
              if ( v33 <= 0x3FBFu )
              {
                v34 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_168:
                *(_DWORD *)&tmpld12.ld12[8] = v34;
                continue;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v33, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v31 != 0
                  || (++v33, (*(_DWORD *)&v28->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v28->ld12[4] != 0
                  || *(_DWORD *)v28->ld12 != 0 )
                {
                  exp_signa = 0;
                  v35 = &v76[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v28->ld12[8];
                    do
                    {
                      v53 = 0;
                      v36 = *(unsigned __int16 *)found_decpointa * *(unsigned __int16 *)found_exponenta;
                      v37 = *((_DWORD *)v35 - 1);
                      v38 = v37 + v36;
                      if ( v37 + v36 < v37 || v38 < v36 )
                        v53 = 1;
                      *((_DWORD *)v35 - 1) = v38;
                      if ( v53 != 0 )
                        ++*v35;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    v28 = v55;
                    ++v35;
                    ++exp_signa;
                  }
                  v39 = v33 - 16382;
                  if ( v39 <= 0 )
                    goto LABEL_178;
                  do
                  {
                    if ( *(int *)&v76[8] < 0 )
                      break;
                    v40 = *(_DWORD *)v76;
                    *(_DWORD *)v76 *= 2;
                    v41 = (v40 >> 31) | (2 * *(_DWORD *)&v76[4]);
                    v42 = *(__int64 *)&v76[4] >> 31;
                    --v39;
                    *(_DWORD *)&v76[4] = v41;
                    *(_DWORD *)&v76[8] = v42;
                  }
                  while ( v39 > 0 );
                  if ( v39 <= 0 )
                  {
LABEL_178:
                    if ( --v39 < 0 )
                    {
                      v43 = (unsigned __int16)-v39;
                      v39 = 0;
                      do
                      {
                        if ( (v76[0] & 1) != 0 )
                          ++exp_adja;
                        v44 = *(_DWORD *)&v76[8];
                        *(_DWORD *)&v76[8] >>= 1;
                        v45 = __SPAIR64__(v44, *(unsigned int *)&v76[4]) >> 1;
                        v46 = *(__int64 *)v76 >> 1;
                        --v43;
                        *(_DWORD *)&v76[4] = v45;
                        *(_DWORD *)v76 = v46;
                      }
                      while ( v43 != 0 );
                      if ( exp_adja != 0 )
                        *(_WORD *)v76 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v76 > 0x8000u || (*(_DWORD *)v76 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v76[2] == -1 )
                    {
                      *(_DWORD *)&v76[2] = 0;
                      if ( *(_DWORD *)&v76[6] == -1 )
                      {
                        *(_DWORD *)&v76[6] = 0;
                        if ( *(_WORD *)&v76[10] == 0xFFFF )
                        {
                          *(_WORD *)&v76[10] = 0x8000;
                          ++v39;
                        }
                        else
                        {
                          ++*(_WORD *)&v76[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v76[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v76[2];
                    }
                  }
                  v24 = (_LDBL12 *)manlena;
                  if ( (unsigned __int16)v39 >= 0x7FFFu )
                    goto LABEL_167;
                  *(_WORD *)tmpld12.ld12 = *(_WORD *)&v76[2];
                  *(_QWORD *)&tmpld12.ld12[2] = *(_QWORD *)&v76[4];
                  *(_WORD *)&tmpld12.ld12[10] = v32 | v39;
                }
                else
                {
                  memset(&tmpld12, 0, sizeof(tmpld12));
                }
              }
              else
              {
                *(_WORD *)&tmpld12.ld12[10] = 0;
              }
            }
          }
        }
        v47 = *(_WORD *)tmpld12.ld12;
        v48 = *(_DWORD *)&tmpld12.ld12[2];
        v49 = *(_DWORD *)&tmpld12.ld12[6];
        v50 = *(_WORD *)&tmpld12.ld12[10];
LABEL_175:
        *(_WORD *)pld12->ld12 = v47;
        *(_WORD *)&pld12->ld12[10] = man_sign | v50;
        *(_DWORD *)&pld12->ld12[2] = v48;
        *(_DWORD *)&pld12->ld12[6] = v49;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421C88
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pMem: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x00421CA3
// Name: __crtLCMapStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtLCMapStringA_stat(
        unsigned int Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        unsigned int code_page,
        int bError)
{
  localeinfo_struct *plocinfo; // ecx
  localeinfo_struct *v9; // esi
  int v10; // ecx
  const char *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned int v15; // eax
  void *v16; // esp
  wchar_t *v17; // eax
  int v18; // eax
  int v19; // ecx
  unsigned int v20; // eax
  void *v21; // esp
  WCHAR *v22; // esi
  WCHAR *v23; // eax
  int v24; // eax
  int v26; // eax
  wchar_t *v27; // eax
  int v28; // eax
  int v29; // esi
  unsigned int v30; // eax
  void *v31; // esp
  char *v32; // edi
  char *v33; // eax
  _DWORD v34[2]; // [esp+0h] [ebp-20h] BYREF
  int v35; // [esp+8h] [ebp-18h] BYREF
  int AnsiCP; // [esp+Ch] [ebp-14h]
  char *cbuffer2; // [esp+10h] [ebp-10h]
  wchar_t *inwbuffer; // [esp+14h] [ebp-Ch]
  int retval; // [esp+18h] [ebp-8h] BYREF

  v9 = plocinfo;
  if ( f_use_1 == 0 )
  {
    if ( LCMapStringW(Locale: 0, dwMapFlags: 0x100u, lpSrcStr: &String2, cchSrc: 1, lpDestStr: nullptr, cchDest: 0) != 0 )
    {
      f_use_1 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_1 = 2;
    }
  }
  if ( cchSrc > 0 )
  {
    v10 = cchSrc;
    v11 = lpSrcStr;
    while ( 1 )
    {
      --v10;
      if ( *v11 == 0 )
        break;
      ++v11;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    v12 = cchSrc - v10 - 1;
    if ( v12 < cchSrc )
      v12 = cchSrc - v10;
    cchSrc = v12;
  }
  if ( f_use_1 != 2 && f_use_1 != 0 )
  {
    if ( f_use_1 == 1 )
    {
      retval = 0;
      if ( code_page == 0 )
        code_page = v9->locinfo->lc_codepage;
      v13 = MultiByteToWideChar(
              CodePage: code_page,
              dwFlags: 8 * (bError != 0) + 1,
              lpMultiByteStr: lpSrcStr,
              cbMultiByte: cchSrc,
              lpWideCharStr: nullptr,
              cchWideChar: 0);
      v14 = v13;
      if ( v13 != 0 )
      {
        if ( v13 <= 0 || 0xFFFFFFE0 / v13 < 2 )
        {
          inwbuffer = nullptr;
LABEL_30:
          if ( inwbuffer != nullptr )
          {
            if ( MultiByteToWideChar(
                   CodePage: code_page,
                   dwFlags: 1u,
                   lpMultiByteStr: lpSrcStr,
                   cbMultiByte: cchSrc,
                   lpWideCharStr: inwbuffer,
                   cchWideChar: v14) != 0 )
            {
              v18 = LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v14, lpDestStr: nullptr, cchDest: 0);
              v19 = v18;
              retval = v18;
              if ( v18 != 0 )
              {
                if ( (dwMapFlags & 0x400) != 0 )
                {
                  if ( cchDest != 0 && v18 <= cchDest )
                    LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v14, (LPWSTR)lpDestStr, cchDest);
                  goto LABEL_53;
                }
                if ( v18 <= 0 || 0xFFFFFFE0 / v18 < 2 )
                {
                  v22 = nullptr;
LABEL_46:
                  if ( v22 != nullptr )
                  {
                    if ( LCMapStringW(
                           Locale,
                           dwMapFlags,
                           lpSrcStr: inwbuffer,
                           cchSrc: v14,
                           lpDestStr: v22,
                           cchDest: retval) != 0 )
                    {
                      if ( cchDest != 0 )
                        v24 = WideCharToMultiByte(
                                CodePage: code_page,
                                dwFlags: 0,
                                lpWideCharStr: v22,
                                cchWideChar: retval,
                                lpMultiByteStr: lpDestStr,
                                cbMultiByte: cchDest,
                                lpDefaultChar: nullptr,
                                lpUsedDefaultChar: nullptr);
                      else
                        v24 = WideCharToMultiByte(
                                CodePage: code_page,
                                dwFlags: 0,
                                lpWideCharStr: v22,
                                cchWideChar: retval,
                                lpMultiByteStr: nullptr,
                                cbMultiByte: 0,
                                lpDefaultChar: nullptr,
                                lpUsedDefaultChar: nullptr);
                      retval = v24;
                    }
                    _freea(_Memory: v22);
                  }
                  goto LABEL_53;
                }
                v20 = 2 * v18 + 8;
                if ( v20 > 0x400 )
                {
                  v23 = (WCHAR *)operator new(nSize: 2 * v19 + 8);
                  if ( v23 != nullptr )
                  {
                    *(_DWORD *)v23 = 56797;
                    v23 += 4;
                  }
                  v22 = v23;
                  goto LABEL_46;
                }
                v21 = alloca(v20);
                if ( v34 != nullptr )
                {
                  v34[0] = 52428;
                  v22 = (WCHAR *)&v35;
                  goto LABEL_46;
                }
              }
            }
LABEL_53:
            _freea(_Memory: inwbuffer);
            return retval;
          }
          return 0;
        }
        v15 = 2 * v13 + 8;
        if ( v15 > 0x400 )
        {
          v17 = (wchar_t *)operator new(nSize: 2 * v14 + 8);
          if ( v17 != nullptr )
          {
            *(_DWORD *)v17 = 56797;
            goto LABEL_27;
          }
        }
        else
        {
          v16 = alloca(v15);
          v17 = (wchar_t *)v34;
          if ( v34 != nullptr )
          {
            v34[0] = 52428;
LABEL_27:
            v17 += 4;
          }
        }
        inwbuffer = v17;
        goto LABEL_30;
      }
    }
    return 0;
  }
  inwbuffer = nullptr;
  cbuffer2 = nullptr;
  if ( Locale == 0 )
    Locale = v9->locinfo->lc_handle[2];
  if ( code_page == 0 )
    code_page = v9->locinfo->lc_codepage;
  v26 = __ansicp(lcid: Locale);
  AnsiCP = v26;
  if ( v26 == -1 )
    return 0;
  if ( v26 == code_page )
  {
    v29 = LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest);
    goto LABEL_78;
  }
  v27 = (wchar_t *)__convertcp(fromCP: code_page, toCP: v26, lpSrcStr, pcchSrc: &cchSrc, lpDestStr: nullptr, cchDest: 0);
  inwbuffer = v27;
  if ( v27 == nullptr )
    return 0;
  v28 = LCMapStringA(Locale, dwMapFlags, lpSrcStr: (LPCSTR)v27, cchSrc, lpDestStr: nullptr, cchDest: 0);
  retval = v28;
  if ( v28 != 0 )
  {
    if ( v28 <= 0 )
    {
      v32 = nullptr;
    }
    else
    {
      v30 = v28 + 8;
      if ( v30 > 0x400 )
      {
        v33 = (char *)operator new(nSize: v30);
        if ( v33 != nullptr )
        {
          *(_DWORD *)v33 = 56797;
          v33 += 8;
        }
        v32 = v33;
      }
      else
      {
        v31 = alloca(v30);
        if ( v34 == nullptr )
          goto LABEL_63;
        v34[0] = 52428;
        v32 = (char *)&v35;
      }
    }
    if ( v32 != nullptr )
    {
      memset(dst: (int)v32, value: nullptr, count: retval);
      retval = LCMapStringA(Locale, dwMapFlags, lpSrcStr: (LPCSTR)inwbuffer, cchSrc, lpDestStr: v32, cchDest: retval);
      if ( retval != 0 )
      {
        cbuffer2 = __convertcp(fromCP: AnsiCP, toCP: code_page, lpSrcStr: v32, pcchSrc: &retval, lpDestStr, cchDest);
        v29 = cbuffer2 != nullptr ? retval : 0;
      }
      else
      {
        v29 = 0;
      }
      _freea(_Memory: v32);
      goto LABEL_78;
    }
  }
LABEL_63:
  v29 = 0;
LABEL_78:
  if ( inwbuffer != nullptr )
    free(pMem: inwbuffer);
  if ( cbuffer2 != nullptr && lpDestStr != cbuffer2 )
    free(pMem: cbuffer2);
  return v29;
}

//------------------------------------------------------------------------------
// Address: 0x00422045
// Name: ___crtLCMapStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtLCMapStringA(
        localeinfo_struct *plocinfo,
        unsigned int Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        unsigned int code_page,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtLCMapStringA_stat(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, code_page, bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00422088
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isleadbyte_l(unsigned __int8 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _loc_update.localeinfo.locinfo->pctype[c] & 0x8000;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004220BE
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isleadbyte(unsigned __int8 c)
{
  return _isleadbyte_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004220CC
// Name: wcstoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall wcstoxl@<eax>(
        unsigned int a1@<esi>,
        localeinfo_struct *plocinfo,
        const wchar_t *nptr,
        const wchar_t **endptr,
        unsigned int ibase,
        int flags)
{
  unsigned __int16 v7; // si
  unsigned __int16 *v8; // edi
  unsigned __int16 *v9; // edi
  unsigned int v10; // ebx
  unsigned int v11; // eax
  int v12; // eax
  const wchar_t *v13; // edi
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)nptr, a3: a1);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  v7 = *nptr;
  number = 0;
  v8 = (unsigned __int16 *)(nptr + 1);
  while ( _iswctype_l(c: v7, mask: 8u, plocinfo: &_loc_update.localeinfo) != 0 )
    v7 = *v8++;
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_17;
  }
  v7 = *v8++;
LABEL_17:
  if ( ibase != 0 )
    goto LABEL_24;
  if ( _wchartodigit(ch: v7) == 0 )
  {
    if ( *v8 != 120 && *v8 != 88 )
    {
      ibase = 8;
      goto LABEL_29;
    }
    ibase = 16;
LABEL_24:
    if ( ibase == 16 && _wchartodigit(ch: v7) == 0 && (*v8 == 120 || *v8 == 88) )
    {
      v9 = v8 + 1;
      v7 = *v9;
      v8 = v9 + 1;
    }
    goto LABEL_29;
  }
  ibase = 10;
LABEL_29:
  v15 = 0xFFFFFFFF % ibase;
  v10 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    v11 = _wchartodigit(ch: v7);
    if ( v11 == -1 )
    {
      if ( (v7 < 0x41u || v7 > 0x5Au) && (unsigned __int16)(v7 - 97) > 0x19u )
        break;
      v12 = v7;
      if ( (unsigned __int16)(v7 - 97) <= 0x19u )
        v12 = v7 - 32;
      v11 = v12 - 55;
    }
    if ( v11 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v11 <= v15 )
    {
      number = v11 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *v8++;
  }
  v13 = v8 - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v13 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v13;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x004222C3
// Name: _wcstol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall wcstol@<eax>(unsigned int a1@<esi>, const wchar_t *nptr, wchar_t **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return wcstoxl(a1, plocinfo: nullptr, nptr, (const wchar_t **)endptr, ibase, flags: 0);
  else
    return wcstoxl(a1, plocinfo: &__initiallocalestructinfo, nptr, (const wchar_t **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004222EC
// Name: __iswctype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _iswctype_l(unsigned __int16 c, unsigned __int16 mask, localeinfo_struct *plocinfo)
{
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  int d; // [esp+10h] [ebp-4h] BYREF

  if ( c == 0xFFFF )
  {
    d = 0;
  }
  else if ( c >= 0x100u )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( __crtGetStringTypeW(
           plocinfo: &_loc_update.localeinfo,
           dwInfoType: 1u,
           lpSrcStr: &c,
           cchSrc: 1,
           lpCharType: (unsigned __int16 *)&d,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           lcid: _loc_update.localeinfo.locinfo->lc_handle[2]) == 0 )
      d = 0;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    d = (unsigned __int16)(mask & _pwctype[c]);
  }
  return mask & (unsigned __int16)d;
}

//------------------------------------------------------------------------------
// Address: 0x00422370
// Name: __CItan_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004225D0
// Name: has_osfxsr_set
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl has_osfxsr_set()
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00422620
// Name: __get_sse2_info
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _get_sse2_info()
{
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4
  int cpu_feature; // [esp+18h] [ebp-4h]

  cpu_feature = 0;
  v0 = __readeflags();
  __writeeflags(v0 ^ 0x200000);
  v1 = __readeflags();
  if ( v1 != v0 )
  {
    __writeeflags(v0);
    _EAX = 0;
    __asm { cpuid }
    _EAX = 1;
    __asm { cpuid }
    cpu_feature = _EDX;
  }
  return (cpu_feature & 0x4000000) != 0 && has_osfxsr_set() != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422680
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __sse2_available_init()
{
  __sse2_available = _get_sse2_info();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042268D
// Name: __lseeki64_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
doubleint __cdecl _lseeki64_nolock(int fh, __int64 pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD LastError; // eax
  char *p_osfile; // eax
  doubleint newpos; // [esp+8h] [ebp-8h] BYREF

  newpos.bigint = pos;
  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return (doubleint)-1LL;
  }
  newpos.twoints.lowerhalf = SetFilePointer(
                               hFile: osfhandle,
                               lDistanceToMove: newpos.twoints.lowerhalf,
                               lpDistanceToMoveHigh: &newpos.twoints.upperhalf,
                               dwMoveMethod: mthd);
  if ( newpos.twoints.lowerhalf == -1 )
  {
    LastError = GetLastError();
    if ( LastError != 0 )
    {
      _dosmaperr(oserrno: LastError);
      return (doubleint)-1LL;
    }
  }
  p_osfile = &__pioinfo[fh >> 5][fh & 0x1F].osfile;
  *p_osfile &= ~2u;
  return newpos;
}

//------------------------------------------------------------------------------
// Address: 0x00422710
// Name: __lseeki64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _lseeki64@<eax>(unsigned int a1@<ebx>, int fh, __int64 pos, DWORD mthd)
{
  int v5; // esi
  unsigned int r; // [esp+10h] [ebp-24h]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: 0xFFFFFFFF);
    return -1;
  }
  v5 = fh & 0x1F;
  if ( (__pioinfo[fh >> 5][v5].osfile & 1) != 0 )
  {
    __lock_fhandle(fh);
    if ( (__pioinfo[fh >> 5][v5].osfile & 1) != 0 )
    {
      r = _lseeki64_nolock(fh, pos, mthd).twoints.lowerhalf;
    }
    else
    {
      *_errno() = 9;
      *__doserrno() = 0;
      r = -1;
    }
    _unlock_fhandle(fh);
    return r;
  }
  else
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1: 4 * (fh >> 5) + 4534976, a2: 0, a3: v5 * 56);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422829
// Name: __write_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _write_nolock@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh, char *buf, DWORD cnt)
{
  int v6; // ebx
  _DWORD *v7; // edi
  ioinfo *v8; // eax
  char v9; // cl
  BOOL v10; // esi
  UINT v11; // eax
  char *v12; // esi
  DWORD v13; // eax
  int v14; // esi
  ioinfo *v15; // eax
  DWORD v16; // ecx
  ioinfo *v17; // eax
  unsigned int v18; // ecx
  char *v19; // eax
  unsigned __int16 *v20; // edx
  char v21; // dl
  int v22; // esi
  unsigned int v23; // esi
  unsigned int v24; // ecx
  char *v25; // eax
  unsigned __int16 *v26; // edx
  unsigned __int16 v27; // dx
  int v28; // esi
  DWORD v29; // ecx
  wchar_t *v30; // eax
  wchar_t v31; // dx
  int v32; // esi
  int v33; // edi
  unsigned int v34; // esi
  unsigned __int8 v35; // [esp-Ch] [ebp-8Ch]
  unsigned int consoleCP; // [esp+4h] [ebp-7Ch] BYREF
  int bCR; // [esp+8h] [ebp-78h]
  char *pch; // [esp+Ch] [ebp-74h]
  _DWORD *v39; // [esp+10h] [ebp-70h]
  int written; // [esp+14h] [ebp-6Ch] BYREF
  int lfcount; // [esp+18h] [ebp-68h]
  char *s; // [esp+1Ch] [ebp-64h]
  int charcount; // [esp+20h] [ebp-60h]
  char *v44; // [esp+24h] [ebp-5Ch]
  char tmode; // [esp+2Bh] [ebp-55h]
  DWORD tmpchar; // [esp+2Ch] [ebp-54h] BYREF
  unsigned __int16 *pu; // [esp+30h] [ebp-50h] BYREF
  char utf8_buf[1028]; // [esp+34h] [ebp-4Ch] BYREF
  wchar_t utf16_buf[170]; // [esp+438h] [ebp+3B8h] BYREF
  char mboutbuf[8]; // [esp+58Ch] [ebp+50Ch] BYREF

  s = buf;
  charcount = 0;
  lfcount = 0;
  if ( cnt == 0 )
    return 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
  v6 = fh & 0x1F;
  v7 = (_DWORD *)(4 * (fh >> 5) + 4534976);
  v8 = &__pioinfo[fh >> 5][v6];
  v9 = (char)(2 * *((_BYTE *)v8 + 36)) >> 1;
  v39 = v7;
  tmode = v9;
  if ( (v9 == 2 || v9 == 1) && (cnt & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(a1: v6 * 56, a2: (unsigned int)v7, a3: 0);
    return -1;
  }
  if ( (v8->osfile & 0x20) != 0 )
    _lseeki64_nolock(fh, pos: 0, mthd: 2u);
  if ( _isatty(fh) != 0 && __pioinfo[fh >> 5][v6].osfile < 0 )
  {
    v10 = _getptd()->ptlocinfo->lc_handle[2] == 0;
    if ( GetConsoleMode(hConsoleHandle: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd, lpMode: &consoleCP)
      && (!v10 || tmode != 0) )
    {
      v11 = GetConsoleCP();
      pu = nullptr;
      v12 = s;
      consoleCP = v11;
      pch = s;
      v44 = nullptr;
      while ( 1 )
      {
        if ( tmode != 0 )
        {
          if ( tmode == 1 || tmode == 2 )
          {
            v16 = *(unsigned __int16 *)v12;
            v44 += 2;
            tmpchar = v16;
            pch = v12 + 2;
            bCR = (_WORD)v16 == 10;
          }
          if ( tmode == 1 || tmode == 2 )
          {
            if ( _putwch_nolock(ch: tmpchar) != (_WORD)tmpchar )
              goto LABEL_82;
            ++charcount;
            if ( bCR != 0 )
            {
              tmpchar = 13;
              if ( _putwch_nolock(ch: 0xDu) != 13 )
                goto LABEL_82;
              ++charcount;
              ++lfcount;
            }
          }
        }
        else
        {
          v35 = *v12;
          bCR = *v12 == 10;
          if ( isleadbyte(c: v35) != 0 )
          {
            if ( cnt + s - v12 <= 1 || mbtowc(pwc: (wchar_t *)&tmpchar, s: v12, n: 2u) == -1 )
              goto LABEL_83;
            ++v12;
            ++v44;
          }
          else if ( mbtowc(pwc: (wchar_t *)&tmpchar, s: v12, n: 1u) == -1 )
          {
            goto LABEL_83;
          }
          ++v44;
          pch = v12 + 1;
          v13 = WideCharToMultiByte(
                  CodePage: consoleCP,
                  dwFlags: 0,
                  lpWideCharStr: (LPCWCH)&tmpchar,
                  cchWideChar: 1,
                  lpMultiByteStr: mboutbuf,
                  cbMultiByte: 5,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          v14 = v13;
          if ( v13 == 0 )
            goto LABEL_83;
          if ( !WriteFile(
                  hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
                  lpBuffer: mboutbuf,
                  nNumberOfBytesToWrite: v13,
                  lpNumberOfBytesWritten: (LPDWORD)&pu,
                  lpOverlapped: nullptr) )
            goto LABEL_82;
          charcount += (int)pu;
          if ( (int)pu < v14 )
            goto LABEL_83;
          if ( bCR != 0 )
          {
            v15 = __pioinfo[fh >> 5];
            mboutbuf[0] = 13;
            if ( !WriteFile(
                    hFile: (HANDLE)v15[v6].osfhnd,
                    lpBuffer: mboutbuf,
                    nNumberOfBytesToWrite: 1u,
                    lpNumberOfBytesWritten: (LPDWORD)&pu,
                    lpOverlapped: nullptr) )
              goto LABEL_82;
            if ( (int)pu < 1 )
              goto LABEL_83;
            ++lfcount;
            ++charcount;
          }
        }
        if ( (unsigned int)v44 >= cnt )
          goto LABEL_83;
        v12 = pch;
      }
    }
  }
  v17 = &__pioinfo[fh >> 5][v6];
  if ( v17->osfile >= 0 )
  {
    if ( WriteFile(
           hFile: (HANDLE)v17->osfhnd,
           lpBuffer: s,
           nNumberOfBytesToWrite: cnt,
           lpNumberOfBytesWritten: (LPDWORD)&written,
           lpOverlapped: nullptr) )
    {
      tmpchar = 0;
      charcount = written;
      goto LABEL_83;
    }
  }
  else
  {
    tmpchar = 0;
    if ( tmode != 0 )
    {
      if ( tmode == 2 )
      {
        pu = (unsigned __int16 *)s;
        while ( 1 )
        {
          v23 = 0;
          v24 = (char *)pu - s;
          v25 = utf8_buf;
          do
          {
            if ( v24 >= cnt )
              break;
            v26 = pu++;
            v27 = *v26;
            v24 += 2;
            if ( v27 == 10 )
            {
              lfcount += 2;
              *(_WORD *)v25 = 13;
              v25 += 2;
              v23 += 2;
            }
            v7 = v39;
            *(_WORD *)v25 = v27;
            v25 += 2;
            v23 += 2;
          }
          while ( v23 < 0x3FF );
          v28 = v25 - utf8_buf;
          if ( !WriteFile(
                  hFile: *(HANDLE *)(v6 * 56 + *v7),
                  lpBuffer: utf8_buf,
                  nNumberOfBytesToWrite: v25 - utf8_buf,
                  lpNumberOfBytesWritten: (LPDWORD)&written,
                  lpOverlapped: nullptr) )
            break;
          charcount += written;
          if ( written < v28 || (char *)pu - s >= cnt )
            goto LABEL_83;
        }
      }
      else
      {
        v44 = s;
        while ( 1 )
        {
          pu = nullptr;
          v29 = v44 - s;
          v30 = utf16_buf;
          do
          {
            if ( v29 >= cnt )
              break;
            v31 = *(_WORD *)v44;
            v44 += 2;
            v29 += 2;
            if ( v31 == 10 )
            {
              *v30++ = 13;
              ++pu;
            }
            ++pu;
            *v30++ = v31;
          }
          while ( (unsigned int)pu < 0x152 );
          v32 = 0;
          v33 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: utf16_buf,
                  cchWideChar: v30 - utf16_buf,
                  lpMultiByteStr: &utf8_buf[340],
                  cbMultiByte: 683,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          if ( v33 == 0 )
            break;
          while ( WriteFile(
                    hFile: *(HANDLE *)(v6 * 56 + *v39),
                    lpBuffer: &utf8_buf[v32 + 340],
                    nNumberOfBytesToWrite: v33 - v32,
                    lpNumberOfBytesWritten: (LPDWORD)&written,
                    lpOverlapped: nullptr) )
          {
            v32 += written;
            if ( v33 <= v32 )
              goto LABEL_77;
          }
          tmpchar = GetLastError();
LABEL_77:
          if ( v33 <= v32 )
          {
            charcount = v44 - s;
            if ( v44 - s < cnt )
              continue;
          }
          goto LABEL_83;
        }
      }
    }
    else
    {
      pu = (unsigned __int16 *)s;
      while ( 1 )
      {
        v44 = nullptr;
        v18 = (char *)pu - s;
        v19 = utf8_buf;
        do
        {
          if ( v18 >= cnt )
            break;
          v20 = pu;
          pu = (unsigned __int16 *)((char *)pu + 1);
          v21 = *(_BYTE *)v20;
          ++v18;
          if ( v21 == 10 )
          {
            ++lfcount;
            *v19++ = 13;
            ++v44;
          }
          *v19++ = v21;
          ++v44;
        }
        while ( (unsigned int)v44 < 0x400 );
        v22 = v19 - utf8_buf;
        if ( !WriteFile(
                hFile: (HANDLE)__pioinfo[fh >> 5][v6].osfhnd,
                lpBuffer: utf8_buf,
                nNumberOfBytesToWrite: v19 - utf8_buf,
                lpNumberOfBytesWritten: (LPDWORD)&written,
                lpOverlapped: nullptr) )
          break;
        charcount += written;
        if ( written < v22 || (char *)pu - s >= cnt )
          goto LABEL_83;
      }
    }
  }
LABEL_82:
  tmpchar = GetLastError();
LABEL_83:
  if ( charcount == 0 )
  {
    v34 = 0;
    if ( tmpchar != 0 )
    {
      v34 = 5;
      if ( tmpchar != 5 )
      {
        _dosmaperr(oserrno: tmpchar);
        return -1;
      }
      *_errno() = 9;
    }
    else
    {
      if ( (*(_BYTE *)(v6 * 56 + *v39 + 4) & 0x40) != 0 && *s == 26 )
        return 0;
      *_errno() = 28;
    }
    *__doserrno() = v34;
    return -1;
  }
  return charcount - lfcount;
}

//------------------------------------------------------------------------------
// Address: 0x00422DEF
// Name: __write
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _write@<eax>(unsigned int a1@<ebx>, int a2@<esi>, int fh, char *buf, DWORD cnt)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0
    || fh >= _nhandle
    || (a1 = 4 * (fh >> 5) + 4534976, a2 = fh & 0x1F, (__pioinfo[fh >> 5][a2].osfile & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: a2 * 56);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (__pioinfo[fh >> 5][a2].osfile & 1) != 0 )
  {
    r = _write_nolock(a1, a2: 0, fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x00422ECB
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _getbuf(_iobuf *str)
{
  char *v1; // eax
  char *base; // eax

  ++_cflush;
  v1 = (char *)operator new(nSize: 0x1000u);
  str->_base = v1;
  if ( v1 != nullptr )
  {
    str->_flag |= 8u;
    str->_bufsiz = 4096;
  }
  else
  {
    str->_flag |= 4u;
    str->_base = (char *)&str->_charbuf;
    str->_bufsiz = 2;
  }
  base = str->_base;
  str->_cnt = 0;
  str->_ptr = base;
}

//------------------------------------------------------------------------------
// Address: 0x00422F0F
// Name: __isatty
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _isatty@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh)
{
  if ( fh == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  else if ( fh >= 0 && fh < _nhandle )
  {
    return __pioinfo[fh >> 5][fh & 0x1F].osfile & 0x40;
  }
  else
  {
    *_errno() = 9;
    _invalid_parameter(a1, a2, a3: 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422F6D
// Name: __wctomb_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wctomb_s_l(
        int *pRetValue,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t wchar,
        localeinfo_struct *plocinfo)
{
  char *v5; // esi
  unsigned int v6; // edi
  int result; // eax
  int v8; // esi
  int v9; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v5 = dst;
  v6 = sizeInBytes;
  if ( dst == nullptr && sizeInBytes != 0 )
  {
    if ( pRetValue != nullptr )
      *pRetValue = 0;
    return 0;
  }
  if ( pRetValue != nullptr )
    *pRetValue = -1;
  if ( v6 > 0x7FFFFFFF )
  {
    v8 = 22;
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: v6, a3: 0x16u);
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( wchar > 0xFFu )
    {
      if ( v5 != nullptr && v6 != 0 )
        memset(dst: (int)v5, value: nullptr, count: v6);
      goto LABEL_16;
    }
    if ( v5 != nullptr )
    {
      if ( v6 == 0 )
      {
LABEL_21:
        v8 = 34;
        *_errno() = 34;
        _invalid_parameter(a1: 0, a2: v6, a3: 0x22u);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return v8;
      }
      *v5 = wchar;
    }
    if ( pRetValue != nullptr )
      *pRetValue = 1;
LABEL_26:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  dst = nullptr;
  v9 = WideCharToMultiByte(
         CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
         dwFlags: 0,
         lpWideCharStr: &wchar,
         cchWideChar: 1,
         lpMultiByteStr: v5,
         cbMultiByte: v6,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: (LPBOOL)&dst);
  if ( v9 != 0 )
  {
    if ( dst == nullptr )
    {
      if ( pRetValue != nullptr )
        *pRetValue = v9;
      goto LABEL_26;
    }
  }
  else if ( GetLastError() == 122 )
  {
    if ( v5 != nullptr && v6 != 0 )
      memset(dst: (int)v5, value: nullptr, count: v6);
    goto LABEL_21;
  }
LABEL_16:
  *_errno() = 42;
  result = *_errno();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004230CC
// Name: _wctomb_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wctomb_s(int *pRetValue, char *dst, unsigned int sizeInBytes, wchar_t wchar)
{
  return _wctomb_s_l(pRetValue, dst, sizeInBytes, wchar, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004230F0
// Name: __aulldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldvrm(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned __int64 v8; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v3 = v6 / v5;
    v8 = v3 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v3, HIDWORD(v8)) || (HIDWORD(v8) = (a2 * (unsigned __int64)v3) >> 32, v8 > a1) )
      --v3;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 / (unsigned int)a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00423185
// Name: __crt_debugger_hook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _crt_debugger_hook()
{
  _debugger_hook_dummy = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00423190
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x004231BD
// Name: __atodbl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atodbl_l(_CRT_DOUBLE *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tod(pld12: &ld12, d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00423263
// Name: __atoflt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atoflt_l(_CRT_FLOAT *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tof(pld12: &ld12, f: d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00423309
// Name: __fptostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fptostr(char *buf, unsigned int sizeInBytes, int digits, _strflt *pflt)
{
  _strflt *v4; // ecx
  char *mantissa; // edi
  unsigned int v6; // esi
  int v8; // edx
  int v9; // eax
  char *v10; // eax
  char v11; // cl
  int v12; // eax

  v4 = pflt;
  mantissa = pflt->mantissa;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v6 = 22;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter(a1: 0, a2: (unsigned int)mantissa, a3: v6);
    return v6;
  }
  v8 = digits;
  *buf = 0;
  if ( digits <= 0 )
    v9 = 0;
  else
    v9 = digits;
  if ( sizeInBytes <= v9 + 1 )
  {
    *_errno() = 34;
    v6 = 34;
    goto LABEL_3;
  }
  *buf = 48;
  v10 = buf + 1;
  if ( digits > 0 )
  {
    do
    {
      v11 = *mantissa;
      if ( *mantissa != 0 )
        ++mantissa;
      else
        v11 = 48;
      *v10++ = v11;
      --v8;
    }
    while ( v8 > 0 );
    v4 = pflt;
  }
  *v10 = 0;
  if ( v8 >= 0 && *mantissa >= 53 )
  {
    while ( *--v10 == 57 )
      *v10 = 48;
    ++*v10;
  }
  if ( *buf == 49 )
  {
    ++v4->decpt;
  }
  else
  {
    strlen(buf: buf + 1);
    memmove(dst: (unsigned __int8 *)buf, src: (unsigned __int8 *)buf + 1, count: v12 + 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004233C6
// Name: ___dtold
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __dtold(_LDOUBLE *pld, long double *px)
{
  int v3; // ecx
  int v4; // eax
  unsigned int v5; // edx
  int v6; // eax
  __int16 v7; // cx
  __int16 v8; // di
  _LDOUBLE *v9; // eax
  __int16 v10; // cx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  unsigned int msb; // [esp+Ch] [ebp-4h]
  __int16 sign; // [esp+1Ch] [ebp+Ch]

  v3 = (*((unsigned __int16 *)px + 3) >> 4) & 0x7FF;
  sign = *((_WORD *)px + 3) & 0x8000;
  v4 = *((_DWORD *)px + 1);
  v5 = *(_DWORD *)px;
  v6 = v4 & 0xFFFFF;
  msb = 0x80000000;
  if ( (_WORD)v3 == 0 )
  {
    if ( v6 == 0 && v5 == 0 )
    {
      v9 = pld;
      v10 = sign;
      *(_DWORD *)&pld->ld[4] = 0;
      *(_DWORD *)pld->ld = 0;
      goto LABEL_13;
    }
    v7 = 15361;
    msb = 0;
    goto LABEL_9;
  }
  if ( (unsigned __int16)v3 != 2047 )
  {
    v7 = v3 + 15360;
LABEL_9:
    v8 = v7;
    goto LABEL_10;
  }
  v8 = 0x7FFF;
LABEL_10:
  v11 = msb | (v6 << 11) | (v5 >> 21);
  v9 = pld;
  *(_DWORD *)&pld->ld[4] = v11;
  *(_DWORD *)pld->ld = v5 << 11;
  if ( (v11 & 0x80000000) == 0 )
  {
    do
    {
      v12 = *(__int64 *)pld->ld >> 31;
      v13 = 2 * *(_DWORD *)pld->ld;
      --v8;
      *(_DWORD *)&pld->ld[4] = v12;
      *(_DWORD *)pld->ld = v13;
    }
    while ( (v12 & 0x80000000) == 0 );
  }
  v10 = v8 | sign;
LABEL_13:
  *(_WORD *)&v9->ld[8] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x00423481
// Name: __fltout2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_strflt *__cdecl _fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned int resultsize)
{
  _strflt *v4; // ebx
  int v5; // eax
  char *v6; // esi
  unsigned int v7; // edx
  unsigned int v8; // ecx
  _BYTE v10[26]; // [esp-Eh] [ebp-4Ah] BYREF
  char *_Dst; // [esp+Ch] [ebp-30h]
  _FloatOutStruct autofos; // [esp+10h] [ebp-2Ch] BYREF
  _LDOUBLE ld; // [esp+2Ch] [ebp-10h] BYREF

  v4 = flt;
  _Dst = resultstr;
  __dtold(pld: &ld, px: &x.x);
  v5 = _I10_OUTPUT(ld, ndigits: 17, output_flags: 0, fos: &autofos);
  v6 = _Dst;
  v4->flag = v5;
  v4->sign = autofos.sign;
  v4->decpt = autofos.exp;
  if ( strcpy_s(a1: (unsigned int)v10, _Dst: v6, _SizeInBytes: resultsize, _Src: autofos.man) != 0 )
  {
    memset(v10, 0, 14);
    _invoke_watson(a1: 0, a2: v7, a3: v8, a4: (unsigned int)v4, a5: (unsigned int)v10, a6: (unsigned int)v6);
  }
  v4->mantissa = v6;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00423510
// Name: __alldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldvrm(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  int v5; // esi
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  int result; // eax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v5 = v7 / (unsigned int)v6;
    v8 = (unsigned int)v5 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v5, HIDWORD(v8))
      || (HIDWORD(v8) = (a2 * (unsigned __int64)(unsigned int)v5) >> 32, v8 > a1) )
    {
      --v5;
    }
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    v5 = v4 / (unsigned int)a2;
  }
  result = v5;
  if ( v2 == 1 )
    return -v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004235F0
// Name: __aullshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __usercall _aullshr@<edx:eax>(unsigned __int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
    return 0;
  else
    return a1 >> a2;
}

//------------------------------------------------------------------------------
// Address: 0x0042360F
// Name: __fptrap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _fptrap()
{
  _amsg_exit(rterrnum: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00423618
// Name: __controlfp_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _controlfp_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned int *_CurrentState,
        unsigned int newctrl,
        unsigned int mask)
{
  unsigned int v5; // [esp-4h] [ebp-8h]

  if ( (mask & 0xFFF7FFFF & newctrl & 0xFCF0FCE0) != 0 )
  {
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl: 0, mask: 0);
    *_errno() = 22;
    _invalid_parameter(a1, a2: 0x16u, a3: 0);
    return 22;
  }
  else
  {
    v5 = mask & 0xFFF7FFFF;
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl, mask: v5);
    else
      _control87(newctrl, mask: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423682
// Name: public: void HeapManager::Destructor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall HeapManager::Destructor(HeapManager *this)
{
  HeapManager::Block *head; // eax
  HeapManager::Block *tail; // [esp-4h] [ebp-8h]

  if ( this->pOpDelete != nullptr )
  {
    while ( 1 )
    {
      head = this->head;
      this->tail = head;
      if ( head == nullptr )
        break;
      tail = this->tail;
      this->head = tail->next;
      this->pOpDelete(a1: tail);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004236A8
// Name: private: static int UnDecorator::getNumberOfDimensions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl UnDecorator::getNumberOfDimensions()
{
  const char *v0; // ecx
  char v1; // dl
  int result; // eax
  char v3; // dl

  v0 = UnDecorator::gName;
  v1 = *UnDecorator::gName;
  if ( *UnDecorator::gName == 0 )
    return 0;
  if ( v1 < 48 || v1 > 57 )
  {
    result = 0;
    while ( v1 != 64 )
    {
      if ( v1 == 0 )
        return 0;
      if ( v1 < 65 || v1 > 80 )
        return -1;
      ++v0;
      result = 16 * result + v1 - 65;
      UnDecorator::gName = v0;
      v1 = *v0;
    }
    v3 = *v0;
    UnDecorator::gName = v0 + 1;
    if ( v3 == 64 )
      return result;
    return -1;
  }
  else
  {
    ++UnDecorator::gName;
    return v1 - 47;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042370B
// Name: private: static int UnDecorator::getTypeEncoding(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl UnDecorator::getTypeEncoding()
{
  const char *v0; // ecx
  int result; // eax
  char v2; // dl
  char v3; // bl
  const char *v4; // ecx
  int v5; // edx
  int v6; // edx
  int v7; // eax
  unsigned int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  char v13; // al
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // eax
  char v18; // dl
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // edx
  int v23; // edx
  char v24; // dl
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax

  v0 = UnDecorator::gName;
  while ( 2 )
  {
    result = 0;
    if ( *v0 == 95 )
    {
      ++v0;
      result = 0x4000;
      UnDecorator::gName = v0;
    }
    v2 = *v0;
    if ( *v0 >= 65 && v2 <= 90 )
    {
      v6 = *v0 - 65;
      v7 = result | 0x8000;
      UnDecorator::gName = v0 + 1;
      if ( (v6 & 1) != 0 )
        result = v7 | 0x2000;
      else
        result = v7 & 0xFFFFDFFF;
      if ( v6 < 24 )
      {
        if ( (result & 0x8000) != 0 )
          v8 = result & 0xFFFFE7FF | 0x800;
        else
          v8 = result & 0xFFFF9FFF;
        v9 = v6 & 0x18;
        if ( (v6 & 0x18) != 0 )
        {
          if ( v9 == 8 )
          {
            if ( (v8 & 0x8000) != 0 )
              result = v8 & 0xFFFFFF3F | 0x80;
            else
              result = v8 & 0xFFFFE7FF | 0x1000;
          }
          else
          {
            if ( v9 != 16 )
              return 0xFFFF;
            if ( (v8 & 0x8000) != 0 )
              result = v8 & 0xFFFFFF3F;
            else
              result = v8 & 0xFFFFE7FF;
          }
        }
        else if ( (v8 & 0x8000) != 0 )
        {
          result = v8 & 0xFFFFFF3F | 0x40;
        }
        else
        {
          result = v8 & 0xFFFFE7FF | 0x800;
        }
        v10 = v6 & 6;
        if ( v10 == 0 )
          return result;
        v11 = v10 - 2;
        if ( v11 != 0 )
        {
          v12 = v11 - 2;
          if ( v12 == 0 )
            return result & 0xFFFFF8FF | 0x100;
          if ( v12 == 2 )
            return result & 0xFFFFF8FF | 0x400;
          return 0xFFFF;
        }
        if ( (result & 0x8000) != 0 )
          return result & 0xFFFFF8FF | 0x200;
        else
          return result & 0xFFFF9FFF;
      }
    }
    else
    {
      if ( v2 == 36 )
      {
        v3 = 0;
        v4 = v0 + 1;
        UnDecorator::gName = v4;
        v5 = *v4;
        if ( v5 > 66 )
        {
          v14 = v5 - 67;
          if ( v14 == 0 )
          {
            result |= 0x7C00u;
            goto LABEL_83;
          }
          v15 = v14 - 1;
          if ( v15 == 0 )
          {
            result = result & 0xFFFF64FF | 0x9100;
            goto LABEL_83;
          }
          v16 = v15 - 1;
          if ( v16 == 0 )
          {
            result = result & 0xFFFF64FF | 0x9200;
            goto LABEL_83;
          }
          if ( v16 != 13 )
            return 0xFFFF;
          UnDecorator::gName = ++v4;
          v3 = 1;
        }
        else
        {
          if ( v5 == 66 )
          {
            result |= 0x9800u;
            goto LABEL_83;
          }
          if ( *v4 == 0 )
          {
            result = 65534;
            goto LABEL_83;
          }
          if ( v5 == 36 )
          {
            if ( v4[1] == 80 )
              ++v4;
            UnDecorator::gName = ++v4;
            switch ( *v4 )
            {
              case 'F':
              case 'H':
              case 'L':
              case 'M':
              case 'Q':
                v0 = v4 + 1;
                UnDecorator::gName = v0;
                continue;
              case 'J':
              case 'N':
              case 'O':
                UnDecorator::gName = ++v4;
                v13 = *v4;
                if ( *v4 >= 48 && v13 <= 57 )
                {
                  UnDecorator::gName = &v4[v13 - 47];
                  return UnDecorator::getTypeEncoding() | 0x10000;
                }
                result = 0xFFFF;
                break;
              default:
                goto LABEL_83;
            }
            goto LABEL_83;
          }
          if ( v5 <= 47 )
            return 0xFFFF;
          if ( v5 > 53 )
          {
            if ( v5 == 65 )
            {
              result = result & 0xFFFF64FF | 0x9000;
LABEL_83:
              UnDecorator::gName = v4 + 1;
              return result;
            }
            return 0xFFFF;
          }
        }
        v17 = result | 0x8000;
        v18 = *v4 - 48;
        if ( (v17 & 0x8000) != 0 )
          v19 = v17 & 0xFFFFE7FF | 0x800;
        else
          v19 = v17 & 0xFFFF9FFF;
        if ( v3 != 0 )
          v20 = v19 & 0xFFFFF8FF | 0x600;
        else
          v20 = v19 & 0xFFFFF8FF | 0x500;
        if ( (v18 & 1) != 0 )
          v21 = v20 | 0x2000;
        else
          v21 = v20 & 0xFFFFDFFF;
        v22 = v18 & 6;
        if ( v22 == 0 )
        {
          if ( (v21 & 0x8000) != 0 )
            result = v21 & 0xFFFFFF3F | 0x40;
          else
            result = v21 & 0xFFFFE7FF | 0x800;
          goto LABEL_83;
        }
        v23 = v22 - 2;
        if ( v23 == 0 )
        {
          if ( (v21 & 0x8000) != 0 )
            result = v21 & 0xFFFFFF3F | 0x80;
          else
            result = v21 & 0xFFFFE7FF | 0x1000;
          goto LABEL_83;
        }
        if ( v23 == 2 )
        {
          if ( (v21 & 0x8000) != 0 )
            result = v21 & 0xFFFFFF3F;
          else
            result = v21 & 0xFFFFE7FF;
          goto LABEL_83;
        }
        return 0xFFFF;
      }
      v24 = *v0;
      if ( *v0 < 48 || v24 > 56 )
      {
        if ( v24 == 57 )
        {
          UnDecorator::gName = v0 + 1;
          return 65533;
        }
        else
        {
          return (v24 != 0) + 65534;
        }
      }
      else
      {
        UnDecorator::gName = v0 + 1;
        v25 = result & 0xFFFF7FFF;
        switch ( v24 )
        {
          case '0':
            if ( (v25 & 0x8000) != 0 )
              v26 = v25 & 0xFFFFF8FF | 0x200;
            else
              v26 = v25 & 0xFFFF9FFF;
            if ( (v26 & 0x8000) != 0 )
              result = v26 & 0xFFFFFF3F | 0x40;
            else
              result = v26 & 0xFFFFE7FF | 0x800;
            break;
          case '1':
            if ( (v25 & 0x8000) != 0 )
              v27 = v25 & 0xFFFFF8FF | 0x200;
            else
              v27 = v25 & 0xFFFF9FFF;
            if ( (v27 & 0x8000) != 0 )
              result = v27 & 0xFFFFFF3F | 0x80;
            else
              result = v27 & 0xFFFFE7FF | 0x1000;
            break;
          case '2':
            if ( (v25 & 0x8000) != 0 )
              v28 = v25 & 0xFFFFF8FF | 0x200;
            else
              v28 = v25 & 0xFFFF9FFF;
            if ( (v28 & 0x8000) != 0 )
              result = v28 & 0xFFFFFF3F;
            else
              result = v28 & 0xFFFFE7FF;
            break;
          case '3':
            result = v25 & 0xFFFF9FFF | 0x4000;
            break;
          case '4':
            result = v25 & 0xFFFF9FFF | 0x2000;
            break;
          case '5':
            result = v25 & 0xFFFF83FF | 0x6000;
            break;
          case '6':
            result = v25 & 0xFFFF83FF | 0x6800;
            break;
          case '7':
            result = v25 & 0xFFFF83FF | 0x7000;
            break;
          case '8':
            result = v25 & 0xFFFF83FF | 0x7800;
            break;
          default:
            return 0xFFFF;
        }
      }
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423B7F
// Name: public: static char const __near * UnDecorator::UScore(enum Tokens)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl UnDecorator::UScore(Tokens tok)
{
  const char *result; // eax

  result = tokenTable[tok];
  if ( (UnDecorator::disableFlags & 1) != 0 )
    result += 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423B98
// Name: public: void __near * HeapManager::getMemory(unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall HeapManager::getMemory(HeapManager *this, unsigned int sz, int noBuffer)
{
  unsigned int v3; // edi
  unsigned int blockLeft; // eax
  HeapManager::Block *Memory; // eax
  HeapManager::Block *tail; // ecx

  v3 = (sz + 7) & 0xFFFFFFF8;
  if ( noBuffer != 0 )
    return (char *)this->pOpNew(a1: (sz + 7) & 0xFFFFFFF8);
  if ( v3 == 0 )
    v3 = 8;
  blockLeft = this->blockLeft;
  if ( blockLeft >= v3 )
  {
    this->blockLeft = blockLeft - v3;
  }
  else
  {
    if ( v3 > 0x1000 )
      return nullptr;
    Memory = (HeapManager::Block *)HeapManager::getMemory(this: &heap, sz: 0x1004u, noBuffer: 1);
    if ( Memory != nullptr )
      Memory->next = nullptr;
    else
      Memory = nullptr;
    if ( Memory == nullptr )
      return nullptr;
    tail = this->tail;
    if ( tail != nullptr )
      tail->next = Memory;
    else
      this->head = Memory;
    this->tail = Memory;
    this->blockLeft = 4096 - v3;
  }
  return &this->tail->memBlock[this->blockLeft];
}

//------------------------------------------------------------------------------
// Address: 0x00423C1C
// Name: public: DName::DName(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, const DName *rd)
{
  DName *result; // eax
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // esi
  int v7; // edx
  int v8; // esi

  result = this;
  *((_DWORD *)this + 1) ^= (*((_DWORD *)this + 1) ^ ((int)(*((_DWORD *)rd + 1) << 28) >> 28)) & 0xF;
  v3 = *((_DWORD *)result + 1)
     ^ ((unsigned __int8)*((_DWORD *)result + 1)
      ^ (unsigned __int8)*((_DWORD *)rd + 1))
     & 0x10;
  *((_DWORD *)this + 1) = v3;
  v4 = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x20;
  *((_DWORD *)this + 1) = v4;
  v5 = v4 ^ ((unsigned __int8)v4 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x40;
  *((_DWORD *)this + 1) = v5;
  v6 = v5 ^ ((unsigned __int8)v5 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x80;
  *((_DWORD *)this + 1) = v6;
  this->node = rd->node;
  *((_DWORD *)this + 1) ^= (*((_DWORD *)rd + 1) ^ v6) & 0x100;
  v7 = *((_DWORD *)result + 1)
     ^ ((unsigned __int16)*((_DWORD *)result + 1)
      ^ (unsigned __int16)*((_DWORD *)rd + 1))
     & 0x200;
  *((_DWORD *)this + 1) = v7;
  v8 = v7 ^ ((unsigned __int16)v7 ^ (unsigned __int16)*((_DWORD *)rd + 1)) & 0x400;
  *((_DWORD *)this + 1) = v8;
  *((_DWORD *)this + 1) = v8 ^ ((unsigned __int16)v8 ^ (unsigned __int16)*((_DWORD *)rd + 1)) & 0x800;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423D58
// Name: public: class DNameNode __near & DNameNode::operator+=(class DNameNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DNameNode *__thiscall DNameNode::operator+=(DNameNode *this, DNameNode *pNode)
{
  DNameNode *result; // eax
  DNameNode *next; // edx

  result = this;
  if ( pNode != nullptr )
  {
    next = this->next;
    if ( next != nullptr )
    {
      while ( next->next != nullptr )
        next = next->next;
      next->next = pNode;
    }
    else
    {
      this->next = pNode;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423D81
// Name: public: virtual int charNode::length(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall charNode::length(charNode *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423D85
// Name: public: virtual char charNode::getLastChar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall charNode::getLastChar(charNode *this)
{
  return this->me;
}

//------------------------------------------------------------------------------
// Address: 0x00423D89
// Name: public: virtual char __near * charNode::getString(char __near *,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall charNode::getString(charNode *this, char *buf, int len)
{
  char *result; // eax

  result = buf;
  if ( buf == nullptr || len == 0 )
    return nullptr;
  *buf = this->me;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423DA4
// Name: public: virtual int DNameStatusNode::length(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall DNameStatusNode::length(DNameStatusNode *this)
{
  return this->myLen;
}

//------------------------------------------------------------------------------
// Address: 0x00423DA8
// Name: public: pDNameNode::pDNameNode(class DName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
pDNameNode *__thiscall pDNameNode::pDNameNode(pDNameNode *this, DName *pName)
{
  DName *v2; // edx
  pDNameNode *result; // eax
  int v4; // ecx

  v2 = pName;
  result = this;
  this->next = nullptr;
  this->__vftable = (pDNameNode_vtbl *)&pDNameNode::`vftable';
  if ( pName != nullptr )
  {
    v4 = (int)(*((_DWORD *)pName + 1) << 28) >> 28;
    if ( v4 == 1 || v4 == 3 )
      v2 = nullptr;
  }
  result->me = v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423DD7
// Name: public: DNameStatusNode::DNameStatusNode(enum DNameStatus)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DNameStatusNode *__thiscall DNameStatusNode::DNameStatusNode(DNameStatusNode *this, DNameStatus stat)
{
  DNameStatusNode *result; // eax
  int v3; // ecx

  result = this;
  this->next = nullptr;
  this->__vftable = (DNameStatusNode_vtbl *)&DNameStatusNode::`vftable';
  this->me = stat;
  if ( stat == DN_truncated )
    v3 = 4;
  else
    v3 = 0;
  result->myLen = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423DFC
// Name: public: virtual char DNameStatusNode::getLastChar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall DNameStatusNode::getLastChar(DNameStatusNode *this)
{
  return this->me != DN_truncated ? 0 : 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x00423E09
// Name: und_strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall und_strncpy@<eax>(char *src@<edx>, char *dst, unsigned int len)
{
  char *i; // ecx
  bool v4; // zf

  for ( i = dst; len != 0; --len )
  {
    v4 = *src == 0;
    *i = *src;
    if ( v4 )
      break;
    ++i;
    ++src;
  }
  return dst;
}

//------------------------------------------------------------------------------
// Address: 0x00423E29
// Name: private: static class DName UnDecorator::getDataIndirectType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getDataIndirectType(DName *result)
{
  DName superType; // [esp+0h] [ebp-10h] BYREF
  DName cvType; // [esp+8h] [ebp-8h] BYREF

  *((_DWORD *)&cvType + 1) &= 0xFFFFF000;
  *((_DWORD *)&superType + 1) &= 0xFFFFF000;
  cvType.node = nullptr;
  superType.node = nullptr;
  UnDecorator::getDataIndirectType(result, &superType, prType: 0, &cvType, thisFlag: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423E5C
// Name: private: static class DName UnDecorator::getThisType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getThisType(DName *result)
{
  DName superType; // [esp+0h] [ebp-10h] BYREF
  DName cvType; // [esp+8h] [ebp-8h] BYREF

  *((_DWORD *)&cvType + 1) &= 0xFFFFF000;
  *((_DWORD *)&superType + 1) &= 0xFFFFF000;
  cvType.node = nullptr;
  superType.node = nullptr;
  UnDecorator::getDataIndirectType(result, &superType, prType: 0, &cvType, thisFlag: 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423E90
// Name: public: DName::DName(class DName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, DName *pd)
{
  char *Memory; // eax
  pDNameNode *v4; // eax

  if ( pd != nullptr )
  {
    Memory = HeapManager::getMemory(this: &heap, sz: 0xCu, noBuffer: 0);
    if ( Memory != nullptr )
      v4 = pDNameNode::pDNameNode(this: (pDNameNode *)Memory, pName: pd);
    else
      v4 = nullptr;
    this->node = v4;
    *((_DWORD *)this + 1) ^= (*((_DWORD *)this + 1) ^ (v4 != nullptr ? 0 : 3)) & 0xF;
  }
  else
  {
    *((_DWORD *)this + 1) &= 0xFFFFFFF0;
    this->node = nullptr;
  }
  *((_DWORD *)this + 1) &= 0xFFFFF00F;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423EE6
// Name: public: DName::DName(enum DNameStatus)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, DNameStatus st)
{
  unsigned __int8 v3; // al
  char *Memory; // eax
  DNameStatusNode *v5; // eax
  int v6; // ecx

  if ( st == DN_invalid || st == DN_error )
    v3 = st;
  else
    v3 = 0;
  *((_DWORD *)this + 1) ^= (v3 ^ (unsigned __int8)*((_DWORD *)this + 1)) & 0xF;
  Memory = HeapManager::getMemory(this: &heap, sz: 0x10u, noBuffer: 0);
  if ( Memory != nullptr )
    v5 = DNameStatusNode::DNameStatusNode(this: (DNameStatusNode *)Memory, stat: st);
  else
    v5 = nullptr;
  *((_DWORD *)this + 1) &= 0xFFFFF00F;
  v6 = *((_DWORD *)this + 1);
  this->node = v5;
  if ( v5 == nullptr )
    *((_DWORD *)this + 1) = v6 & 0xFFFFFFF0 | 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423F47
// Name: public: int DName::isValid(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall DName::isValid(DName *this)
{
  int v1; // eax

  v1 = (int)(*((_DWORD *)this + 1) << 28) >> 28;
  return v1 == 0 || v1 == 2;
}

//------------------------------------------------------------------------------
// Address: 0x00423F5E
// Name: public: int DName::isEmpty(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall DName::isEmpty(DName *this)
{
  return this->node == nullptr || !DName::isValid(this);
}

//------------------------------------------------------------------------------
// Address: 0x00423F73
// Name: public: int DName::isUDC(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall DName::isUDC(DName *this)
{
  int v1; // ecx

  return !DName::isEmpty(this) && (*(_BYTE *)(v1 + 4) & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00423F87
// Name: public: int DName::length(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall DName::length(DName *this)
{
  int v1; // edi
  int *v2; // ecx
  int v3; // esi
  int v4; // eax

  v1 = 0;
  if ( !DName::isEmpty(this) )
  {
    v3 = *v2;
    while ( v3 != 0 )
    {
      v4 = (**(int (__thiscall ***)(int))v3)(a1: v3);
      v3 = *(_DWORD *)(v3 + 4);
      v1 += v4;
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00423FAC
// Name: public: char DName::getLastChar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall DName::getLastChar(DName *this)
{
  int v1; // edi
  int *v2; // ecx
  int v3; // esi

  v1 = 0;
  if ( DName::isEmpty(this) )
    return 0;
  v3 = *v2;
  if ( *v2 == 0 )
    return 0;
  do
  {
    if ( (**(int (__thiscall ***)(int))v3)(a1: v3) != 0 )
      v1 = v3;
    v3 = *(_DWORD *)(v3 + 4);
  }
  while ( v3 != 0 );
  if ( v1 != 0 )
    return (*(char (__thiscall **)(int))(*(_DWORD *)v1 + 4))(a1: v1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00423FE4
// Name: public: char __near * DName::getString(char __near *,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall DName::getString(DName *this, char *buf, char *max)
{
  DName *v4; // ecx
  unsigned int v5; // esi
  int v6; // ebx
  DNameNode *node; // esi
  int v8; // edi
  char *v9; // eax
  char *curBuf; // [esp+14h] [ebp+Ch]

  if ( DName::isEmpty(this) )
  {
    if ( buf != nullptr )
    {
      v9 = buf;
LABEL_18:
      *v9 = 0;
    }
  }
  else
  {
    if ( buf != nullptr )
    {
      v5 = (unsigned int)max;
      goto LABEL_6;
    }
    v5 = DName::length(this: v4) + 1;
    buf = HeapManager::getMemory(this: &heap, sz: v5, noBuffer: 0);
    if ( buf != nullptr )
    {
LABEL_6:
      v6 = v5;
      node = this->node;
      curBuf = buf;
      while ( node != nullptr && v6 > 0 )
      {
        v8 = node->length(this: node);
        if ( v8 != 0 )
        {
          if ( v6 - v8 < 0 )
            v8 = v6;
          if ( node->getString(this: node, a2: curBuf, a3: v8) != nullptr )
          {
            v6 -= v8;
            curBuf += v8;
          }
        }
        node = node->next;
      }
      v9 = curBuf;
      goto LABEL_18;
    }
  }
  return buf;
}

//------------------------------------------------------------------------------
// Address: 0x00424075
// Name: public: class DName __near & DName::operator|=(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::operator|=(DName *this, DName *rd)
{
  DName *v2; // edx
  int v3; // esi
  int v4; // ecx

  v2 = this;
  v3 = *((_DWORD *)this + 1);
  if ( (*((_BYTE *)this + 4) & 0xF) != 3 && !DName::isValid(this: rd) )
    *((_DWORD *)v2 + 1) = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)((int)(*(_DWORD *)(v4 + 4) << 28) >> 28)) & 0xF;
  return v2;
}
