// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: unittests/shaderapitest/shaderapitest.cpp
// Functions: 79
// ============================================================

#include "unittests\shaderapitest\shaderapitest.h"

//------------------------------------------------------------------------------
// Address: 0x00401150
// Name: public: void CVertexBuilder::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::Reset(CVertexBuilder *this)
{
  float *m_pNormal; // edx
  float *v2; // edx
  float *v3; // eax
  float *v4; // edx
  float *v5; // eax
  float *v6; // edx
  float *v7; // eax
  float *v8; // edx

  m_pNormal = this->m_pNormal;
  this->m_pCurrPosition = this->m_pPosition;
  this->m_nCurrentVertex = 0;
  this->m_pCurrNormal = m_pNormal;
  v2 = this->m_pTexCoord[1];
  this->m_pCurrTexCoord[0] = this->m_pTexCoord[0];
  v3 = this->m_pTexCoord[2];
  this->m_pCurrTexCoord[1] = v2;
  v4 = this->m_pTexCoord[3];
  this->m_pCurrTexCoord[2] = v3;
  v5 = this->m_pTexCoord[4];
  this->m_pCurrTexCoord[3] = v4;
  v6 = this->m_pTexCoord[5];
  this->m_pCurrTexCoord[4] = v5;
  v7 = this->m_pTexCoord[6];
  this->m_pCurrTexCoord[5] = v6;
  v8 = this->m_pTexCoord[7];
  this->m_pCurrTexCoord[6] = v7;
  this->m_pCurrTexCoord[7] = v8;
  this->m_pCurrColor = this->m_pColor;
}

//------------------------------------------------------------------------------
// Address: 0x004011E0
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  return AppMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow, pAppSystemGroup: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x00401210
// Name: public: virtual bool CShaderAPITestApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderAPITestApp::Create(CShaderAPITestApp *this)
{
  bool v2; // bl
  int v3; // eax
  const char *v4; // edi
  int Module; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax
  int v8; // eax
  _OSVERSIONINFOA info; // [esp+Ch] [ebp-94h] BYREF

  _LoggingSystem_SetLoggingResponsePolicy(a1: &s_NonFatalLoggingResponsePolicy);
  v2 = false;
  info.dwOSVersionInfoSize = 148;
  if ( GetVersionExA(lpVersionInformation: &info) )
    v2 = info.dwMajorVersion >= 6;
  v3 = _CommandLine();
  v4 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 32))(
                       a1: v3,
                       a2: "-shaderdll",
                       a3: 0);
  if ( v4 == nullptr )
  {
    v4 = "shaderapidx10.dll";
    this->m_bUseDX10 = true;
  }
  if ( !v2 && _V_stricmp(s1: v4, s2: "shaderapidx10.dll") == 0 )
  {
    v4 = "shaderapidx9.dll";
    this->m_bUseDX10 = false;
  }
  Module = CAppSystemGroup::LoadModule(this, pDLLName: v4);
  if ( Module == -1 )
  {
    this->m_bUseDX10 = false;
    Module = CAppSystemGroup::LoadModule(this, pDLLName: "shaderapidx9.dll");
    if ( Module == -1 )
    {
      Module = CAppSystemGroup::LoadModule(this, pDLLName: "shaderapiempty.dll");
      if ( Module == -1 )
        return false;
    }
  }
  g_pShaderDeviceMgr = (IShaderDeviceMgr *)CAppSystemGroup::AddSystem(
                                             this,
                                             module: Module,
                                             pInterfaceName: "ShaderDeviceMgr001");
  FactoryThis = Sys_GetFactoryThis();
  v8 = CAppSystemGroup::LoadModule(this, factory: FactoryThis);
  CAppSystemGroup::AddSystem(this, module: v8, pInterfaceName: "VShaderUtil001");
  return g_pShaderDeviceMgr != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401320
// Name: ShaderAPITestWndProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall ShaderAPITestWndProc(HWND__ *hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  if ( message != 2 )
    return DefWindowProcA(hWnd, Msg: message, wParam, lParam);
  PostQuitMessage(nExitCode: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401360
// Name: private: bool CShaderAPITestApp::CreateAppWindow(char const __near *,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderAPITestApp::CreateAppWindow(
        CShaderAPITestApp *this,
        const char *pTitle,
        bool bWindowed,
        int w,
        int h)
{
  int v6; // esi
  DWORD v7; // esi
  HINSTANCE AppInstance; // eax
  HWND__ *Window; // eax
  int v11; // kr04_4
  int SystemMetrics; // eax
  tagWNDCLASSEXA wc; // [esp+Ch] [ebp-40h] BYREF
  tagRECT windowRect; // [esp+3Ch] [ebp-10h] BYREF

  memset(dst: (unsigned __int8 *)&wc, value: 0, count: sizeof(wc));
  wc.cbSize = 48;
  wc.style = 40;
  wc.lpfnWndProc = ShaderAPITestWndProc;
  wc.hInstance = (HINSTANCE__ *)GetAppInstance();
  wc.lpszClassName = "Valve001";
  wc.hIcon = nullptr;
  wc.hIconSm = nullptr;
  RegisterClassExA(a1: &wc);
  v6 = -2080374784;
  if ( bWindowed )
    v6 = -2067070976;
  v7 = v6 & 0xFFFEFFFF;
  windowRect.top = 0;
  windowRect.left = 0;
  windowRect.right = w;
  windowRect.bottom = h;
  AdjustWindowRectEx(lpRect: &windowRect, dwStyle: v7, bMenu: false, dwExStyle: 0);
  AppInstance = (HINSTANCE)GetAppInstance();
  Window = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: wc.lpszClassName,
             lpWindowName: pTitle,
             dwStyle: v7,
             X: 0,
             Y: 0,
             nWidth: windowRect.right - windowRect.left,
             nHeight: windowRect.bottom - windowRect.top,
             hWndParent: nullptr,
             hMenu: nullptr,
             hInstance: AppInstance,
             lpParam: nullptr);
  this->m_HWnd = Window;
  if ( Window == nullptr )
    return 0;
  v11 = GetSystemMetrics(nIndex: 0) - w;
  SystemMetrics = GetSystemMetrics(nIndex: 1);
  SetWindowPos(
    hWnd: this->m_HWnd,
    hWndInsertAfter: nullptr,
    X: v11 / 2 < 0 ? 0 : v11 / 2,
    Y: (SystemMetrics - h) / 2 < 0 ? 0 : (SystemMetrics - h) / 2,
    cx: 0,
    cy: 0,
    uFlags: 0x65u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401480
// Name: private: bool CShaderAPITestApp::SetupSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderAPITestApp::SetupSearchPaths(CShaderAPITestApp *this)
{
  bool result; // al
  IFileSystem_vtbl *v3; // edi
  const char *GameInfoPath; // eax

  result = CSteamAppSystemGroup::SetupSearchPaths(
             this,
             pStartingDir: nullptr,
             bOnlyUseStartingDir: false,
             bIsTool: true);
  if ( result )
  {
    v3 = g_pFullFileSystem->IAppSystem::__vftable;
    GameInfoPath = CSteamAppSystemGroup::GetGameInfoPath(this);
    v3->AddSearchPath(this: g_pFullFileSystem, a2: GameInfoPath, a3: "SKIN", a4: PATH_ADD_TO_HEAD);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004014C0
// Name: public: virtual bool CShaderAPITestApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderAPITestApp::PreInit(CShaderAPITestApp *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  void *(__cdecl *bWindowed)(const char *, int *); // [esp+8h] [ebp-8h] BYREF
  const char *pArg; // [esp+Ch] [ebp-4h] BYREF

  this->m_bUseDX10 = false;
  bWindowed = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(pFactoryList: &bWindowed, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(pFactoryList: &bWindowed, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || g_pShaderDeviceMgr == nullptr || !CShaderAPITestApp::SetupSearchPaths(this) )
    return false;
  v2 = 1024;
  v3 = 768;
  v4 = _CommandLine();
  LOBYTE(bWindowed) = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(
                        a1: v4,
                        a2: "-fullscreen",
                        a3: 0) == 0;
  v5 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-width", a3: &pArg) != 0 )
    v2 = atoi(nptr: pArg);
  v6 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-height", a3: &pArg) != 0 )
    v3 = atoi(nptr: pArg);
  return CShaderAPITestApp::CreateAppWindow(this, pTitle: "Press a Key To Continue", (bool)bWindowed, w: v2, h: v3) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004015D0
// Name: public: virtual void CShaderAPITestApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPITestApp::PostShutdown(CShaderAPITestApp *this)
{
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x004015E0
// Name: private: bool CShaderAPITestApp::WaitForKeypress(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderAPITestApp::WaitForKeypress(CShaderAPITestApp *this)
{
  tagMSG msg; // [esp+8h] [ebp-1Ch] BYREF

  memset(&msg, 0, sizeof(msg));
  while ( 1 )
  {
    if ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    if ( msg.message == 256 )
      break;
    if ( msg.message == 18 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401660
// Name: private: bool CShaderAPITestApp::SetMode(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderAPITestApp::SetMode(CShaderAPITestApp *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // edi
  HWND__ *m_HWnd; // eax
  void *(__cdecl *v8)(const char *, int *); // eax
  void *(__cdecl *v9)(const char *, int *); // edi
  IShaderDevice *v10; // eax
  bool v11; // zf
  ShaderDeviceInfo_t mode; // [esp+Ch] [ebp-38h] BYREF

  v2 = g_pShaderDeviceMgr->GetAdapterCount(this: g_pShaderDeviceMgr);
  v3 = _CommandLine();
  v4 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 28))(a1: v3, a2: "-adapter", a3: 0);
  v5 = v4;
  if ( v4 < v2 )
  {
    memset(dst: (unsigned __int8 *)&mode, value: 0, count: sizeof(mode));
    *((_BYTE *)&mode + 52) |= 1u;
    m_HWnd = this->m_HWnd;
    mode.m_nVersion = 1;
    mode.m_DisplayMode.m_nVersion = 1;
    mode.m_DisplayMode.m_nWidth = 1024;
    mode.m_DisplayMode.m_nHeight = 768;
    mode.m_DisplayMode.m_Format = IMAGE_FORMAT_BGRA8888;
    mode.m_DisplayMode.m_nRefreshRateNumerator = 60;
    mode.m_DisplayMode.m_nRefreshRateDenominator = 1;
    mode.m_nBackBufferCount = 1;
    v8 = g_pShaderDeviceMgr->SetMode(this: g_pShaderDeviceMgr, a2: m_HWnd, a3: v5, a4: &mode);
    v9 = v8;
    if ( v8 != nullptr )
    {
      this->m_pShaderAPI = (IShaderAPI *)v8(a1: "ShaderApi029", a2: nullptr);
      v10 = (IShaderDevice *)v9(a1: "ShaderDevice001", a2: nullptr);
      v11 = this->m_pShaderAPI == nullptr;
      this->m_pShaderDevice = v10;
      if ( v11 || v10 == nullptr )
      {
        _Warning(a1: "Unable to get IShaderAPI or IShaderDevice interface!\n");
        return 0;
      }
      else
      {
        return 1;
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
// Address: 0x00401780
// Name: private: void CShaderAPITestApp::CreateShaders(char const __near *,int,char const __near *,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPITestApp::CreateShaders(
        CShaderAPITestApp *this,
        const char *pVShader,
        unsigned int nVBufLen,
        const char *pGShader,
        int nGBufLen,
        const char *pPShader,
        unsigned int nPBufLen)
{
  bool m_bUseDX10; // al
  const char *v9; // ecx
  IShaderDevice *m_pShaderDevice; // edi
  int v11; // ebx
  VertexShaderHandle_t__ *v12; // edi
  IShaderDevice *v13; // edi
  int v14; // ebx
  PixelShaderHandle_t__ *v15; // edi
  IShaderAPI *m_pShaderAPI; // ecx
  VertexShaderHandle_t__ *m_hVertexShader; // edx
  const char *pPixelShaderVersion; // [esp+10h] [ebp-4h]

  m_bUseDX10 = this->m_bUseDX10;
  v9 = "vs_4_0";
  if ( m_bUseDX10 )
  {
    pPixelShaderVersion = "ps_4_0";
  }
  else
  {
    v9 = "vs_2_0";
    pPixelShaderVersion = "ps_2_0";
  }
  m_pShaderDevice = this->m_pShaderDevice;
  v11 = (int)m_pShaderDevice->CompileShader(this: m_pShaderDevice, a2: pVShader, a3: nVBufLen, a4: v9);
  if ( v11 != 0 )
  {
    v12 = m_pShaderDevice->CreateVertexShader(this: m_pShaderDevice, a2: (IShaderBuffer *)v11);
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 8))(a1: v11);
  }
  else
  {
    v12 = nullptr;
  }
  this->m_hGeometryShader = nullptr;
  this->m_hVertexShader = v12;
  v13 = this->m_pShaderDevice;
  v14 = (int)v13->CompileShader(this: v13, a2: pPShader, a3: nPBufLen, a4: pPixelShaderVersion);
  if ( v14 != 0 )
  {
    v15 = v13->CreatePixelShader(this: v13, a2: (IShaderBuffer *)v14);
    (*(void (__thiscall **)(int))(*(_DWORD *)v14 + 8))(a1: v14);
  }
  else
  {
    v15 = nullptr;
  }
  m_pShaderAPI = this->m_pShaderAPI;
  m_hVertexShader = this->m_hVertexShader;
  this->m_hPixelShader = v15;
  m_pShaderAPI->BindVertexShader(this: m_pShaderAPI, a2: m_hVertexShader);
  this->m_pShaderAPI->BindGeometryShader(this: this->m_pShaderAPI, a2: this->m_hGeometryShader);
  this->m_pShaderAPI->BindPixelShader(this: this->m_pShaderAPI, a2: this->m_hPixelShader);
}

//------------------------------------------------------------------------------
// Address: 0x00401890
// Name: public: bool CVertexBuilder::Lock(int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVertexBuilder::Lock(CVertexBuilder *this, int nMaxVertexCount, BOOL bAppend)
{
  bool v4; // zf
  bool v5; // bl
  bool result; // al
  unsigned int m_nFirstVertex; // edx

  v4 = this->m_nBufferOffset == -1;
  this->m_bModify = false;
  v5 = v4;
  this->m_nMaxVertexCount = nMaxVertexCount;
  if ( v4 )
  {
    LOBYTE(bAppend) = 0;
  }
  else if ( bAppend )
  {
    goto LABEL_5;
  }
  this->m_nTotalVertexCount = 0;
LABEL_5:
  result = this->m_pVertexBuffer->Lock(this: this->m_pVertexBuffer, a2: nMaxVertexCount, a3: bAppend, a4: this);
  if ( result )
  {
    CVertexBuilder::Reset(this);
    if ( v5 )
    {
      m_nFirstVertex = this->m_nFirstVertex;
      this->m_nBufferOffset = this->m_nOffset;
      this->m_nBufferFirstVertex = m_nFirstVertex;
    }
    return true;
  }
  else
  {
    this->m_nMaxVertexCount = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401920
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x004019A0
// Name: public: virtual enum LoggingResponse_t CNonFatalLoggingResponsePolicy::OnLog(struct LoggingContext_t const __near *)
// Source: json
//------------------------------------------------------------------------------
LoggingResponse_t __thiscall CNonFatalLoggingResponsePolicy::OnLog(
        CNonFatalLoggingResponsePolicy *this,
        const LoggingContext_t *pContext)
{
  int v2; // eax
  LoggingResponse_t result; // eax

  result = pContext->m_Severity == LS_ASSERT
        && (v2 = _CommandLine(),
            (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-noassert") == 0)
        || pContext->m_Severity == LS_ERROR;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004019E0
// Name: private: void CShaderAPITestApp::CreateSimpleBuffers(enum ShaderBufferType_t,enum ShaderBufferType_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShaderAPITestApp::CreateSimpleBuffers(
        CShaderAPITestApp *this@<ecx>,
        int a2@<esi>,
        ShaderBufferType_t nVBType,
        ShaderBufferType_t nIBType,
        bool bBuffered)
{
  IVertexBuffer *v6; // eax
  float *m_pCurrPosition; // eax
  int v8; // esi
  float *m_pCurrNormal; // eax
  float *v10; // eax
  float *v11; // eax
  int v12; // edx
  float *v13; // eax
  float *v14; // eax
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int v18; // eax
  IIndexBuffer *v19; // eax
  IShaderAPI *m_pShaderAPI; // ecx
  IVertexBuffer *m_pVertexBuffer; // eax
  CVertexBuilder vb; // [esp+8h] [ebp-128h] BYREF
  CIndexBuilder ib; // [esp+FCh] [ebp-34h] BYREF
  bool nVBType_3; // [esp+13Bh] [ebp+Bh]

  if ( nVBType == SHADER_BUFFER_TYPE_DYNAMIC || nVBType == SHADER_BUFFER_TYPE_DYNAMIC_TEMP )
    v6 = (IVertexBuffer *)((int (__thiscall *)(IShaderDevice *, ShaderBufferType_t, _DWORD, _DWORD, int, const char *))this->m_pShaderDevice->CreateVertexBuffer)(
                            a1: this->m_pShaderDevice,
                            a2: nVBType,
                            a3: 0,
                            a4: 0,
                            a5: 1024,
                            a6: "test");
  else
    v6 = (IVertexBuffer *)((int (__thiscall *)(IShaderDevice *, ShaderBufferType_t, int, _DWORD, int, const char *))this->m_pShaderDevice->CreateVertexBuffer)(
                            a1: this->m_pShaderDevice,
                            a2: nVBType,
                            a3: 7,
                            a4: 0,
                            a5: 4,
                            a6: "test");
  this->m_pVertexBuffer = v6;
  vb.m_nBufferOffset = -1;
  vb.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  vb.m_pVertexBuffer = v6;
  vb.m_nBufferFirstVertex = 0;
  memset(&vb.m_nMaxVertexCount, 0, 12);
  vb.m_nTotalVertexCount = 0;
  if ( v6->IsDynamic(this: v6) )
    ((void (__thiscall *)(IVertexBuffer *, int, _DWORD))vb.m_pVertexBuffer->BeginCastBuffer)(
      a1: vb.m_pVertexBuffer,
      a2: 7,
      a3: 0);
  CVertexBuilder::Lock(this: &vb, nMaxVertexCount: 4, bAppend: false);
  m_pCurrPosition = vb.m_pCurrPosition;
  v8 = nCount;
  *vb.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = -1.0;
  m_pCurrPosition[2] = 0.5;
  m_pCurrNormal = vb.m_pCurrNormal;
  *vb.m_pCurrNormal = 0.0;
  m_pCurrNormal[1] = 0.0;
  m_pCurrNormal[2] = 1.0;
  *(_DWORD *)vb.m_pCurrColor = s_pColors[v8 % 4][2]
                             | ((s_pColors[v8 % 4][1]
                               | ((s_pColors[v8 % 4][0] | ((unsigned __int8)byte_4260DB[4 * (v8 % 4)] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &vb);
  v10 = vb.m_pCurrPosition;
  *vb.m_pCurrPosition = 1.0;
  v10[1] = -1.0;
  v10[2] = 0.5;
  v11 = vb.m_pCurrNormal;
  *vb.m_pCurrNormal = 0.0;
  v11[1] = 0.0;
  v11[2] = 1.0;
  v12 = (v8 + 1) % 4;
  *(_DWORD *)vb.m_pCurrColor = s_pColors[v12][2]
                             | ((s_pColors[v12][1]
                               | ((s_pColors[v12][0] | ((unsigned __int8)byte_4260DB[4 * v12] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &vb);
  v13 = vb.m_pCurrPosition;
  *vb.m_pCurrPosition = 1.0;
  v13[1] = 1.0;
  v13[2] = 0.5;
  v14 = vb.m_pCurrNormal;
  *vb.m_pCurrNormal = 0.0;
  v14[1] = 0.0;
  v14[2] = 1.0;
  v15 = (v8 + 2) % 4;
  *(_DWORD *)vb.m_pCurrColor = s_pColors[v15][2]
                             | ((s_pColors[v15][1]
                               | ((s_pColors[v15][0] | ((unsigned __int8)byte_4260DB[4 * v15] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &vb);
  v16 = vb.m_pCurrPosition;
  *vb.m_pCurrPosition = -1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = vb.m_pCurrNormal;
  *vb.m_pCurrNormal = 0.0;
  v17[1] = 0.0;
  v17[2] = 1.0;
  v18 = (v8 + 3) % 4;
  *(_DWORD *)vb.m_pCurrColor = s_pColors[v18][2]
                             | ((s_pColors[v18][1]
                               | ((s_pColors[v18][0] | ((unsigned __int8)byte_4260DB[4 * v18] << 8)) << 8)) << 8);
  nCount = v8 + 4;
  CVertexBuilder::AdvanceVertex(this: &vb);
  ((void (__thiscall *)(IVertexBuffer *, int, CVertexBuilder *, int))vb.m_pVertexBuffer->Spew)(
    a1: vb.m_pVertexBuffer,
    a2: vb.m_nVertexCount,
    a3: &vb,
    a4: a2);
  vb.m_pVertexBuffer->Unlock(this: vb.m_pVertexBuffer, a2: vb.m_nVertexCount, a3: &vb);
  vb.m_nTotalVertexCount += vb.m_nVertexCount;
  ++nCount;
  vb.m_nMaxVertexCount = 0;
  if ( nIBType == SHADER_BUFFER_TYPE_DYNAMIC || nIBType == SHADER_BUFFER_TYPE_DYNAMIC_TEMP )
    v19 = this->m_pShaderDevice->CreateIndexBuffer(this: this->m_pShaderDevice, a2: nIBType, a3: -1, a4: 64, a5: "test");
  else
    v19 = this->m_pShaderDevice->CreateIndexBuffer(this: this->m_pShaderDevice, a2: nIBType, a3: 0, a4: 6, a5: "test");
  this->m_pIndexBuffer = v19;
  ib.m_pIndexBuffer = v19;
  ib.m_nBufferOffset = -1;
  ib.m_nBufferFirstIndex = 0;
  ib.m_nIndexCount = 0;
  ib.m_nCurrentIndex = 0;
  ib.m_nMaxIndexCount = 0;
  ib.m_nTotalIndexCount = 0;
  if ( v19->IsDynamic(this: v19) )
    ib.m_pIndexBuffer->BeginCastBuffer(this: ib.m_pIndexBuffer, a2: MATERIAL_INDEX_FORMAT_16BIT);
  ib.m_bModify = false;
  ib.m_nMaxIndexCount = 6;
  memset(&ib.m_nIndexCount, 0, 16);
  nVBType_3 = ib.m_nBufferOffset == -1;
  if ( ib.m_pIndexBuffer->Lock(this: ib.m_pIndexBuffer, a2: 6, a3: false, a4: &ib) )
  {
    if ( nVBType_3 )
    {
      ib.m_nBufferOffset = ib.m_nOffset;
      ib.m_nBufferFirstIndex = ib.m_nFirstIndex;
    }
  }
  else
  {
    ib.m_nMaxIndexCount = 0;
  }
  ib.m_pIndices[ib.m_nCurrentIndex] = ib.m_nIndexOffset;
  ib.m_nCurrentIndex += ib.m_nIndexSize;
  ib.m_pIndices[ib.m_nCurrentIndex] = LOWORD(ib.m_nIndexOffset) + 2;
  ib.m_nCurrentIndex += ib.m_nIndexSize;
  ib.m_pIndices[ib.m_nCurrentIndex] = LOWORD(ib.m_nIndexOffset) + 1;
  ib.m_nCurrentIndex += ib.m_nIndexSize;
  ib.m_pIndices[ib.m_nCurrentIndex] = ib.m_nIndexOffset;
  ib.m_nCurrentIndex += ib.m_nIndexSize;
  ib.m_pIndices[ib.m_nCurrentIndex] = LOWORD(ib.m_nIndexOffset) + 3;
  ib.m_nCurrentIndex += ib.m_nIndexSize;
  ib.m_pIndices[ib.m_nCurrentIndex] = LOWORD(ib.m_nIndexOffset) + 2;
  ib.m_nCurrentIndex += ib.m_nIndexSize;
  ib.m_nIndexCount = ib.m_nCurrentIndex;
  ((void (__thiscall *)(IIndexBuffer *, int))ib.m_pIndexBuffer->Spew)(a1: ib.m_pIndexBuffer, a2: ib.m_nCurrentIndex);
  ib.m_pIndexBuffer->Unlock(this: ib.m_pIndexBuffer, a2: ib.m_nIndexCount, a3: &ib);
  ib.m_nTotalIndexCount += ib.m_nIndexCount;
  m_pShaderAPI = this->m_pShaderAPI;
  m_pVertexBuffer = this->m_pVertexBuffer;
  ib.m_nMaxIndexCount = 0;
  ((void (__thiscall *)(IShaderAPI *, _DWORD, IVertexBuffer *, unsigned int, _DWORD, int, int, _DWORD, int))m_pShaderAPI->BindVertexBuffer)(
    a1: m_pShaderAPI,
    a2: 0,
    a3: m_pVertexBuffer,
    a4: vb.m_nBufferOffset,
    a5: 0,
    a6: vb.m_nTotalVertexCount,
    a7: 7,
    a8: 0,
    a9: 1);
  this->m_pShaderAPI->BindIndexBuffer(this: this->m_pShaderAPI, a2: this->m_pIndexBuffer, a3: ib.m_nBufferOffset);
  if ( ib.m_pIndexBuffer != nullptr && ib.m_pIndexBuffer->IsDynamic(this: ib.m_pIndexBuffer) )
    ib.m_pIndexBuffer->EndCastBuffer(this: ib.m_pIndexBuffer);
  if ( vb.m_pVertexBuffer != nullptr && vb.m_pVertexBuffer->IsDynamic(this: vb.m_pVertexBuffer) )
    vb.m_pVertexBuffer->EndCastBuffer(this: vb.m_pVertexBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x00401EC0
// Name: private: void CShaderAPITestApp::TestColoredQuad(enum ShaderBufferType_t,enum ShaderBufferType_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPITestApp::TestColoredQuad(
        CShaderAPITestApp *this,
        ShaderBufferType_t nVBType,
        ShaderBufferType_t nIBType,
        bool bBuffered)
{
  IShaderAPI_vtbl *v5; // ebx
  int v6; // eax
  IVertexBuffer *m_pVertexBuffer; // eax
  int v8; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]

  v5 = this->m_pShaderAPI->__vftable;
  v9 = _RandomInt(a1: 190, a2: 255);
  v8 = _RandomInt(a1: 0, a2: 100);
  v6 = _RandomInt(a1: 0, a2: 100);
  v5->ClearColor3ub(this: this->m_pShaderAPI, a2: v6, a3: v8, a4: v9);
  this->m_pShaderAPI->ClearBuffers(this: this->m_pShaderAPI, a2: true, a3: false, a4: false, a5: -1, a6: -1);
  CShaderAPITestApp::CreateSimpleBuffers(this, a2: (int)this, nVBType, nIBType, bBuffered);
  CShaderAPITestApp::CreateShaders(
    this,
    pVShader: "struct VS_INPUT\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tfloat3 vPos\t\t\t\t\t\t: POSIT"
    "ION0;\t\t\t\t\t\t\t\tfloat4 vColor\t\t\t\t\t: COLOR0;\t\t\t\t\t\t\t\t};\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tstruct VS_OUTPUT\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "float4 projPos\t\t\t\t\t: POSITION0;\t\t\t\t\t\t\t\tfloat4 vertexColor\t\t\t\t: COLOR0;\t\t\t\t\t\t\t\t};\t\t\t\t\t\t"
    "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tVS_OUTPUT main( const VS_INPUT v )\t\t\t\t\t\t\t\t\t"
    "\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tVS_OUTPUT o = ( VS_OUTPUT )0;\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "\t\t\t\t\t\t\t\t\t\to.projPos.xyz = v.vPos;\t\t\t\t\t\t\t\t\t\t\t\t\t\to.projPos.w = 1.0f;\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "\t\to.vertexColor = v.vColor;\t\t\t\t\t\t\t\t\t\t\t\t\treturn o;\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t}\t\t\t\t\t\t\t\t\t\t"
    "\t\t\t\t\t\t\t\t\t",
    nVBufLen: 0x266u,
    pGShader: nullptr,
    nGBufLen: 0,
    pPShader: "struct PS_INPUT\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tfloat4 projPos\t\t\t\t\t: POSI"
    "TION0;\t\t\t\t\t\t\t\tfloat4 vColor\t\t\t\t\t: COLOR0;\t\t\t\t\t\t\t\t};\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tfloat4 main( const PS_INPUT i ) : COLOR\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "\t\t\t\t\t\t\treturn i.vColor;\t\t\t\t\t\t\t\t\t\t\t\t\t\t}\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t",
    nPBufLen: 0x11Du);
  this->m_pShaderAPI->Draw(this: this->m_pShaderAPI, a2: MATERIAL_TRIANGLES, a3: 0, a4: 6);
  this->m_pShaderDevice->Present(this: this->m_pShaderDevice);
  this->m_pShaderDevice->DestroyVertexShader(this: this->m_pShaderDevice, a2: this->m_hVertexShader);
  this->m_pShaderDevice->DestroyGeometryShader(this: this->m_pShaderDevice, a2: this->m_hGeometryShader);
  this->m_pShaderDevice->DestroyPixelShader(this: this->m_pShaderDevice, a2: this->m_hPixelShader);
  this->m_hVertexShader = nullptr;
  m_pVertexBuffer = this->m_pVertexBuffer;
  this->m_hGeometryShader = nullptr;
  this->m_hPixelShader = nullptr;
  if ( m_pVertexBuffer != nullptr )
  {
    this->m_pShaderDevice->DestroyVertexBuffer(this: this->m_pShaderDevice, a2: m_pVertexBuffer);
    this->m_pVertexBuffer = nullptr;
  }
  if ( this->m_pIndexBuffer != nullptr )
  {
    this->m_pShaderDevice->DestroyIndexBuffer(this: this->m_pShaderDevice, a2: this->m_pIndexBuffer);
    this->m_pIndexBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402010
// Name: private: void CShaderAPITestApp::TestDynamicBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderAPITestApp::TestDynamicBuffers(CShaderAPITestApp *this)
{
  IVertexBuffer *v2; // eax
  IShaderDevice *m_pShaderDevice; // ecx
  IShaderAPI_vtbl *v4; // esi
  int v5; // eax
  float *m_pCurrPosition; // eax
  int v7; // esi
  float v8; // xmm0_4
  float *m_pCurrNormal; // eax
  float *v10; // eax
  float v11; // xmm0_4
  float *v12; // eax
  int v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float *v18; // eax
  int v19; // eax
  IIndexBuffer *m_pIndexBuffer; // ecx
  bool (__thiscall *Lock)(IIndexBuffer *, int, bool, IndexDesc_t *); // edx
  IShaderAPI *m_pShaderAPI; // ecx
  IVertexBuffer *m_pVertexBuffer; // eax
  IShaderDevice *v24; // ecx
  VertexShaderHandle_t__ *m_hVertexShader; // edx
  void (__thiscall *DestroyVertexShader)(IShaderDevice *, VertexShaderHandle_t__ *); // eax
  IVertexBuffer *v27; // eax
  int v28; // [esp-8h] [ebp-14Ch]
  int v29; // [esp-4h] [ebp-148h]
  CVertexBuilder vb; // [esp+Ch] [ebp-138h] BYREF
  float v31; // [esp+100h] [ebp-44h]
  float v32; // [esp+104h] [ebp-40h]
  int i; // [esp+108h] [ebp-3Ch]
  CIndexBuilder ib; // [esp+10Ch] [ebp-38h] BYREF
  bool v35; // [esp+143h] [ebp-1h]

  v2 = (IVertexBuffer *)((int (__thiscall *)(IShaderDevice *, int, _DWORD, _DWORD, int, const char *))this->m_pShaderDevice->CreateVertexBuffer)(
                          a1: this->m_pShaderDevice,
                          a2: 1,
                          a3: 0,
                          a4: 0,
                          a5: 256,
                          a6: "test");
  m_pShaderDevice = this->m_pShaderDevice;
  this->m_pVertexBuffer = v2;
  this->m_pIndexBuffer = m_pShaderDevice->CreateIndexBuffer(
                           this: m_pShaderDevice,
                           a2: SHADER_BUFFER_TYPE_DYNAMIC,
                           a3: MATERIAL_INDEX_FORMAT_UNKNOWN,
                           a4: 30,
                           a5: "test");
  CShaderAPITestApp::CreateShaders(
    this,
    pVShader: "struct VS_INPUT\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tfloat3 vPos\t\t\t\t\t\t: POSIT"
    "ION0;\t\t\t\t\t\t\t\tfloat4 vColor\t\t\t\t\t: COLOR0;\t\t\t\t\t\t\t\t};\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tstruct VS_OUTPUT\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "float4 projPos\t\t\t\t\t: POSITION0;\t\t\t\t\t\t\t\tfloat4 vertexColor\t\t\t\t: COLOR0;\t\t\t\t\t\t\t\t};\t\t\t\t\t\t"
    "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tVS_OUTPUT main( const VS_INPUT v )\t\t\t\t\t\t\t\t\t"
    "\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tVS_OUTPUT o = ( VS_OUTPUT )0;\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "\t\t\t\t\t\t\t\t\t\to.projPos.xyz = v.vPos;\t\t\t\t\t\t\t\t\t\t\t\t\t\to.projPos.w = 1.0f;\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "\t\to.vertexColor = v.vColor;\t\t\t\t\t\t\t\t\t\t\t\t\treturn o;\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t}\t\t\t\t\t\t\t\t\t\t"
    "\t\t\t\t\t\t\t\t\t",
    nVBufLen: 0x266u,
    pGShader: nullptr,
    nGBufLen: 0,
    pPShader: "struct PS_INPUT\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tfloat4 projPos\t\t\t\t\t: POSI"
    "TION0;\t\t\t\t\t\t\t\tfloat4 vColor\t\t\t\t\t: COLOR0;\t\t\t\t\t\t\t\t};\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tfloat4 main( const PS_INPUT i ) : COLOR\t\t\t\t\t\t\t\t\t{\t\t\t\t\t\t\t\t\t\t\t\t\t"
    "\t\t\t\t\t\t\treturn i.vColor;\t\t\t\t\t\t\t\t\t\t\t\t\t\t}\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t",
    nPBufLen: 0x11Du);
  v4 = this->m_pShaderAPI->__vftable;
  v29 = _RandomInt(a1: 190, a2: 255);
  v28 = _RandomInt(a1: 0, a2: 100);
  v5 = _RandomInt(a1: 0, a2: 100);
  v4->ClearColor3ub(this: this->m_pShaderAPI, a2: v5, a3: v28, a4: v29);
  this->m_pShaderAPI->ClearBuffers(this: this->m_pShaderAPI, a2: true, a3: false, a4: false, a5: -1, a6: -1);
  for ( i = 0; i < 8; ++i )
  {
    vb.m_pVertexBuffer = this->m_pVertexBuffer;
    vb.m_nBufferOffset = -1;
    vb.m_nBufferFirstVertex = 0;
    memset(&vb.m_nMaxVertexCount, 0, 12);
    vb.m_nTotalVertexCount = 0;
    vb.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    if ( vb.m_pVertexBuffer->IsDynamic(this: vb.m_pVertexBuffer) )
      ((void (__thiscall *)(IVertexBuffer *, int, _DWORD))vb.m_pVertexBuffer->BeginCastBuffer)(
        a1: vb.m_pVertexBuffer,
        a2: 7,
        a3: 0);
    CVertexBuilder::Lock(this: &vb, nMaxVertexCount: 4, bAppend: false);
    m_pCurrPosition = vb.m_pCurrPosition;
    v7 = nCount_0;
    v8 = (float)((float)i * 0.25) - 1.0;
    *vb.m_pCurrPosition = v8;
    v32 = v8;
    m_pCurrPosition[1] = -1.0;
    m_pCurrPosition[2] = 0.5;
    m_pCurrNormal = vb.m_pCurrNormal;
    *vb.m_pCurrNormal = 0.0;
    m_pCurrNormal[1] = 0.0;
    m_pCurrNormal[2] = 1.0;
    *(_DWORD *)vb.m_pCurrColor = s_pColors_0[v7 % 4][2]
                               | ((s_pColors_0[v7 % 4][1]
                                 | ((s_pColors_0[v7 % 4][0] | ((unsigned __int8)byte_4260EB[4 * (v7 % 4)] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &vb);
    v10 = vb.m_pCurrPosition;
    v11 = v32 + 0.25;
    *vb.m_pCurrPosition = v32 + 0.25;
    v31 = v11;
    v10[1] = -1.0;
    v10[2] = 0.5;
    v12 = vb.m_pCurrNormal;
    *vb.m_pCurrNormal = 0.0;
    v12[1] = 0.0;
    v12[2] = 1.0;
    v13 = (v7 + 1) % 4;
    *(_DWORD *)vb.m_pCurrColor = s_pColors_0[v13][2]
                               | ((s_pColors_0[v13][1]
                                 | ((s_pColors_0[v13][0] | ((unsigned __int8)byte_4260EB[4 * v13] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &vb);
    v14 = vb.m_pCurrPosition;
    *vb.m_pCurrPosition = v31;
    v14[1] = 1.0;
    v14[2] = 0.5;
    v15 = vb.m_pCurrNormal;
    *vb.m_pCurrNormal = 0.0;
    v15[1] = 0.0;
    v15[2] = 1.0;
    v16 = (v7 + 2) % 4;
    *(_DWORD *)vb.m_pCurrColor = s_pColors_0[v16][2]
                               | ((s_pColors_0[v16][1]
                                 | ((s_pColors_0[v16][0] | ((unsigned __int8)byte_4260EB[4 * v16] << 8)) << 8)) << 8);
    CVertexBuilder::AdvanceVertex(this: &vb);
    v17 = vb.m_pCurrPosition;
    *vb.m_pCurrPosition = v32;
    v17[1] = 1.0;
    v17[2] = 0.5;
    v18 = vb.m_pCurrNormal;
    *vb.m_pCurrNormal = 0.0;
    v18[1] = 0.0;
    v18[2] = 1.0;
    v19 = (v7 + 3) % 4;
    *(_DWORD *)vb.m_pCurrColor = s_pColors_0[v19][2]
                               | ((s_pColors_0[v19][1]
                                 | ((s_pColors_0[v19][0] | ((unsigned __int8)byte_4260EB[4 * v19] << 8)) << 8)) << 8);
    nCount_0 = v7 + 4;
    CVertexBuilder::AdvanceVertex(this: &vb);
    vb.m_pVertexBuffer->Spew(this: vb.m_pVertexBuffer, a2: vb.m_nVertexCount, a3: &vb);
    vb.m_pVertexBuffer->Unlock(this: vb.m_pVertexBuffer, a2: vb.m_nVertexCount, a3: &vb);
    m_pIndexBuffer = this->m_pIndexBuffer;
    vb.m_nTotalVertexCount += vb.m_nVertexCount;
    ++nCount_0;
    vb.m_nMaxVertexCount = 0;
    ib.m_pIndexBuffer = m_pIndexBuffer;
    ib.m_nBufferOffset = -1;
    ib.m_nBufferFirstIndex = 0;
    ib.m_nIndexCount = 0;
    ib.m_nCurrentIndex = 0;
    ib.m_nMaxIndexCount = 0;
    ib.m_nTotalIndexCount = 0;
    if ( m_pIndexBuffer->IsDynamic(this: m_pIndexBuffer) )
      ib.m_pIndexBuffer->BeginCastBuffer(this: ib.m_pIndexBuffer, a2: MATERIAL_INDEX_FORMAT_16BIT);
    ib.m_nIndexOffset = vb.m_nBufferFirstVertex;
    ib.m_bModify = false;
    ib.m_nMaxIndexCount = 6;
    ib.m_nIndexCount = 0;
    ib.m_nTotalIndexCount = 0;
    ib.m_nCurrentIndex = 0;
    Lock = ib.m_pIndexBuffer->Lock;
    v35 = ib.m_nBufferOffset == -1;
    if ( Lock(this: ib.m_pIndexBuffer, a2: 6, a3: false, a4: &ib) )
    {
      if ( v35 )
      {
        ib.m_nBufferOffset = ib.m_nOffset;
        ib.m_nBufferFirstIndex = ib.m_nFirstIndex;
      }
    }
    else
    {
      ib.m_nMaxIndexCount = 0;
    }
    ib.m_pIndices[ib.m_nCurrentIndex] = ib.m_nIndexOffset;
    ib.m_nCurrentIndex += ib.m_nIndexSize;
    ib.m_pIndices[ib.m_nCurrentIndex] = LOWORD(ib.m_nIndexOffset) + 2;
    ib.m_nCurrentIndex += ib.m_nIndexSize;
    ib.m_pIndices[ib.m_nCurrentIndex] = LOWORD(ib.m_nIndexOffset) + 1;
    ib.m_nCurrentIndex += ib.m_nIndexSize;
    ib.m_pIndices[ib.m_nCurrentIndex] = ib.m_nIndexOffset;
    ib.m_nCurrentIndex += ib.m_nIndexSize;
    ib.m_pIndices[ib.m_nCurrentIndex] = LOWORD(ib.m_nIndexOffset) + 3;
    ib.m_nCurrentIndex += ib.m_nIndexSize;
    ib.m_pIndices[ib.m_nCurrentIndex] = LOWORD(ib.m_nIndexOffset) + 2;
    ib.m_nCurrentIndex += ib.m_nIndexSize;
    ib.m_nIndexCount = ib.m_nCurrentIndex;
    ib.m_pIndexBuffer->Spew(this: ib.m_pIndexBuffer, a2: ib.m_nCurrentIndex, a3: &ib);
    ib.m_pIndexBuffer->Unlock(this: ib.m_pIndexBuffer, a2: ib.m_nIndexCount, a3: &ib);
    ib.m_nTotalIndexCount += ib.m_nIndexCount;
    m_pShaderAPI = this->m_pShaderAPI;
    m_pVertexBuffer = this->m_pVertexBuffer;
    ib.m_nMaxIndexCount = 0;
    ((void (__thiscall *)(IShaderAPI *, _DWORD, IVertexBuffer *, unsigned int, unsigned int, int, int, _DWORD, int))m_pShaderAPI->BindVertexBuffer)(
      a1: m_pShaderAPI,
      a2: 0,
      a3: m_pVertexBuffer,
      a4: vb.m_nBufferOffset,
      a5: vb.m_nBufferFirstVertex,
      a6: vb.m_nTotalVertexCount,
      a7: 7,
      a8: 0,
      a9: 1);
    this->m_pShaderAPI->BindIndexBuffer(this: this->m_pShaderAPI, a2: this->m_pIndexBuffer, a3: ib.m_nBufferOffset);
    this->m_pShaderAPI->Draw(
      this: this->m_pShaderAPI,
      a2: MATERIAL_TRIANGLES,
      a3: ib.m_nBufferFirstIndex,
      a4: ib.m_nTotalIndexCount);
    if ( ib.m_pIndexBuffer != nullptr && ib.m_pIndexBuffer->IsDynamic(this: ib.m_pIndexBuffer) )
      ib.m_pIndexBuffer->EndCastBuffer(this: ib.m_pIndexBuffer);
    if ( vb.m_pVertexBuffer != nullptr && vb.m_pVertexBuffer->IsDynamic(this: vb.m_pVertexBuffer) )
      vb.m_pVertexBuffer->EndCastBuffer(this: vb.m_pVertexBuffer);
  }
  this->m_pShaderDevice->Present(this: this->m_pShaderDevice);
  v24 = this->m_pShaderDevice;
  m_hVertexShader = this->m_hVertexShader;
  DestroyVertexShader = v24->DestroyVertexShader;
  ++nCount_0;
  DestroyVertexShader(this: v24, a2: m_hVertexShader);
  this->m_pShaderDevice->DestroyGeometryShader(this: this->m_pShaderDevice, a2: this->m_hGeometryShader);
  this->m_pShaderDevice->DestroyPixelShader(this: this->m_pShaderDevice, a2: this->m_hPixelShader);
  v27 = this->m_pVertexBuffer;
  this->m_hVertexShader = nullptr;
  this->m_hGeometryShader = nullptr;
  this->m_hPixelShader = nullptr;
  if ( v27 != nullptr )
  {
    this->m_pShaderDevice->DestroyVertexBuffer(this: this->m_pShaderDevice, a2: v27);
    this->m_pVertexBuffer = nullptr;
  }
  if ( this->m_pIndexBuffer != nullptr )
  {
    this->m_pShaderDevice->DestroyIndexBuffer(this: this->m_pShaderDevice, a2: this->m_pIndexBuffer);
    this->m_pIndexBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402660
// Name: public: virtual bool CBaseAppSystem<class IShaderUtil>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAppSystem<IShaderUtil>::Connect(
        CBaseAppSystem<IShaderUtil> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402680
// Name: public: virtual enum InitReturnVal_t CBaseAppSystem<class IShaderUtil>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IShaderUtil>::Init(CBaseAppSystem<IShaderUtil> *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402690
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<class IShaderUtil>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IShaderUtil>::GetTier(CBaseAppSystem<IShaderUtil> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x004026A0
// Name: public: virtual void CBaseAppSystem<class IShaderUtil>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IShaderUtil>::Reconnect(
        CBaseAppSystem<IShaderUtil> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x004026C0
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
    dword_428DC8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_428DC8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00402720
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
    dword_428DC8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00402780
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
    dword_428DC8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004027E0
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
// Address: 0x004028A0
// Name: public: virtual struct MaterialSystem_Config_t __near & CShaderUtilTemp::GetConfig(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall CShaderUtilTemp::GetConfig(CShaderUtilTemp *this)
{
  if ( (`CShaderUtilTemp::GetConfig'::`2'::`local static guard' & 1) == 0 )
  {
    `CShaderUtilTemp::GetConfig'::`2'::`local static guard' |= 1u;
    MaterialSystem_Config_t::MaterialSystem_Config_t(this: &`CShaderUtilTemp::GetConfig'::`2'::config);
  }
  return &`CShaderUtilTemp::GetConfig'::`2'::config;
}

//------------------------------------------------------------------------------
// Address: 0x004028D0
// Name: public: virtual bool CShaderUtilTemp::ConvertImageFormat(unsigned char __near *,enum ImageFormat,unsigned char __near *,enum ImageFormat,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderUtilTemp::ConvertImageFormat(
        CShaderUtilTemp *this,
        unsigned __int8 *src,
        unsigned __int8 *srcImageFormat,
        unsigned __int8 *dst,
        unsigned __int8 *dstImageFormat,
        ImageFormat width,
        int height,
        int srcStride,
        int dstStride)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004028E0
// Name: public: virtual int CShaderUtilTemp::GetMemRequired(int,int,int,enum ImageFormat,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderUtilTemp::GetMemRequired(
        CShaderUtilTemp *this,
        int width,
        int height,
        int depth,
        int format,
        bool mipmap)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004028F0
// Name: public: virtual struct ImageFormatInfo_t const __near & CShaderUtilTemp::ImageFormatInfo(enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__thiscall CShaderUtilTemp::ImageFormatInfo(CShaderUtilTemp *this, ImageFormat fmt)
{
  return &`CShaderUtilTemp::ImageFormatInfo'::`2'::info;
}

//------------------------------------------------------------------------------
// Address: 0x00402900
// Name: public: virtual void CShaderUtilTemp::BindStandardTexture(enum Sampler_t,enum TextureBindFlags_t,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderUtilTemp::BindStandardTexture(
        CShaderUtilTemp *this,
        Sampler_t stage,
        Sampler_t nBindFlags,
        TextureBindFlags_t id)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00402910
// Name: public: virtual void CShaderUtilTemp::GetStandardTextureDimensions(int __near *,int __near *,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderUtilTemp::GetStandardTextureDimensions(
        CShaderUtilTemp *this,
        int *pWidth,
        int *pHeight,
        StandardTextureId_t id)
{
  *pHeight = 0;
  *pWidth = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402930
// Name: public: virtual void CShaderUtilTemp::GetLightmapDimensions(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderUtilTemp::GetLightmapDimensions(CShaderUtilTemp *this, int *w, int *h)
{
  *h = 0;
  *w = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402950
// Name: public: virtual void CShaderUtilTemp::BindStandardVertexTexture(enum VertexTextureSampler_t,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderUtilTemp::BindStandardVertexTexture(
        CShaderUtilTemp *this,
        void *(__cdecl *shaderFactory)(const char *, int *),
        void *(__cdecl *nChangeFlags)(const char *, int *))
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00402960
// Name: public: virtual void CShaderUtilTemp::DrawClearBufferQuad(unsigned char,unsigned char,unsigned char,unsigned char,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderUtilTemp::DrawClearBufferQuad(
        CShaderUtilTemp *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a,
        unsigned __int8 bClearColor,
        bool bClearAlpha,
        bool bClearDepth)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00402970
// Name: public: virtual bool CShaderUtilTemp::OnDrawMesh(class IMesh __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderUtilTemp::OnDrawMesh(
        CShaderUtilTemp *this,
        IMesh *pStaticMesh,
        IMesh *pMesh,
        IMesh *nVertexOffsetInBytes)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00402980
// Name: public: virtual bool CShaderUtilTemp::OnSetPrimitiveType(class IMesh __near *,enum MaterialPrimitiveType_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderUtilTemp::OnSetPrimitiveType(CShaderUtilTemp *this, IMesh *pMesh, IMesh *type)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00402990
// Name: public: virtual unsigned int CShaderUtilTemp::GetBoundMorphFormat(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderUtilTemp::GetBoundMorphFormat(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004029A0
// Name: public: virtual void CShaderUtilTemp::GetCurrentColorCorrection(struct ShaderColorCorrectionInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderUtilTemp::GetCurrentColorCorrection(CShaderUtilTemp *this, ShaderColorCorrectionInfo_t *pInfo)
{
  pInfo->m_bIsEnabled = false;
  pInfo->m_nLookupCount = 0;
  pInfo->m_flDefaultWeight = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004029C0
// Name: public: virtual int CShaderUtilTemp::GetShaderAPITextureBindHandle(class ITexture __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderUtilTemp::GetShaderAPITextureBindHandle(
        CShaderUtilTemp *this,
        struct ITexture *pTexture,
        struct ITexture *nFrame,
        int nTextureChannel)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004029D0
// Name: public: virtual float CShaderUtilTemp::GetSubDHeight(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShaderUtilTemp::GetSubDHeight(CShaderUtilTemp *this)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004029E0
// Name: public: virtual bool CShaderUtilTemp::OnDrawMeshModulated(class IMesh __near *,class Vector4D const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderUtilTemp::OnDrawMeshModulated(
        CShaderUtilTemp *this,
        IMesh *pMesh,
        IMesh *diffuseModulation,
        const Vector4D *firstIndex,
        int numIndices)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004029F0
// Name: public: virtual void CShaderUtilTemp::SyncMatrix(enum MaterialMatrixMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderUtilTemp::SyncMatrix(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00402A00
// Name: public: virtual bool CShaderUtilTemp::InFlashlightMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderUtilTemp::InFlashlightMode(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00402A10
// Name: public: virtual class ITexture __near * CShaderUtilTemp::GetRenderTargetEx(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderUtilTemp::GetRenderTargetEx(CShaderUtilTemp *this, int nLightmapPage)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402A20
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
// Address: 0x00402AD0
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
      dword_428DC8 = 0x1FFFF;
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
      dword_428DC8 = 0x1FFFF;
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
// Address: 0x00402BA0
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
        dword_428DC8 = 0x1FFFF;
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
        dword_428DC8 = 0x1FFFF;
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
        dword_428DC8 = 0x1FFFF;
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
        dword_428DC8 = 0x1FFFF;
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
        dword_428DC8 = 0x1FFFF;
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
// Address: 0x00402D90
// Name: private: void CShaderAPITestApp::DisplayAdapterInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CShaderAPITestApp::DisplayAdapterInfo(
        CShaderAPITestApp *this@<ecx>,
        KeyValues *a2@<ebx>,
        int m_nDXSupportLevel@<esi>)
{
  int v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  int i; // ebx
  MaterialAdapterInfo_t info; // [esp+4h] [ebp-274h] BYREF
  CUtlBuffer buf; // [esp+228h] [ebp-50h] BYREF
  ShaderDisplayMode_t mode; // [esp+258h] [ebp-20h] BYREF
  int nAdapterCount; // [esp+270h] [ebp-8h]
  int nModeCount; // [esp+274h] [ebp-4h]

  v3 = 0;
  nAdapterCount = g_pShaderDeviceMgr->GetAdapterCount(this: g_pShaderDeviceMgr);
  if ( nAdapterCount > 0 )
  {
    do
    {
      ((void (__thiscall *)(IShaderDeviceMgr *, int, MaterialAdapterInfo_t *, int, KeyValues *))g_pShaderDeviceMgr->GetAdapterInfo)(
        a1: g_pShaderDeviceMgr,
        a2: v3,
        a3: &info,
        a4: m_nDXSupportLevel,
        a5: a2);
      _Msg(a1: "Adapter %d\n", v3);
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
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "Config");
      else
        v5 = nullptr;
      a2 = v5;
      m_nDXSupportLevel = info.m_nDXSupportLevel;
      ((void (__thiscall *)(IShaderDeviceMgr *, int))g_pShaderDeviceMgr->GetRecommendedConfigurationInfo)(
        a1: g_pShaderDeviceMgr,
        a2: v3);
      KeyValues::RecursiveSaveToFile(this: v5, &buf, indentLevel: 1);
      _Msg(a1: "\tConfiguration:\n%s", (const char *)buf.m_Memory.m_pMemory);
      _Msg(a1: "\n");
      nModeCount = g_pShaderDeviceMgr->GetModeCount(this: g_pShaderDeviceMgr, a2: v3);
      _Msg(a1: "\tMode Count : %d\n", nModeCount);
      for ( i = 0; i < nModeCount; ++i )
      {
        memset(&mode.m_nWidth, 0, 20);
        mode.m_nVersion = 1;
        g_pShaderDeviceMgr->GetModeInfo(this: g_pShaderDeviceMgr, a2: &mode, a3: v3, a4: i);
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
      ++v3;
    }
    while ( v3 < nAdapterCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402F10
// Name: public: virtual int CShaderAPITestApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CShaderAPITestApp::Main@<eax>(CShaderAPITestApp *this@<ecx>, KeyValues *a2@<ebx>, int a3@<esi>)
{
  IShaderAPI_vtbl *v5; // esi
  int v6; // eax
  void *v7; // esp
  int *v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  ShaderViewport_t *v13; // edx
  ShaderBufferType_t v14; // esi
  IShaderAPI *m_pShaderAPI; // ecx
  ShaderBufferType_t v16; // ebx
  int v17; // [esp-8h] [ebp-450h]
  int v18; // [esp-4h] [ebp-44Ch]
  int v19; // [esp+0h] [ebp-448h] BYREF
  int v20; // [esp+8h] [ebp-440h] BYREF
  char buf[1024]; // [esp+Ch] [ebp-43Ch] BYREF
  ShaderViewport_t viewport; // [esp+40Ch] [ebp-3Ch] BYREF
  int x; // [esp+428h] [ebp-20h]
  int y; // [esp+42Ch] [ebp-1Ch]
  int h; // [esp+430h] [ebp-18h] BYREF
  int v26; // [esp+434h] [ebp-14h]
  int w; // [esp+438h] [ebp-10h] BYREF
  int nMaxViewports; // [esp+43Ch] [ebp-Ch]
  ShaderViewport_t *pViewports; // [esp+440h] [ebp-8h]
  int i; // [esp+444h] [ebp-4h]

  CShaderAPITestApp::DisplayAdapterInfo(this, a2, m_nDXSupportLevel: a3);
  if ( CShaderAPITestApp::SetMode(this) == 0 )
    return 0;
  v5 = this->m_pShaderAPI->__vftable;
  v18 = _RandomInt(a1: 190, a2: 255);
  v17 = _RandomInt(a1: 0, a2: 100);
  v6 = _RandomInt(a1: 0, a2: 100);
  v5->ClearColor3ub(this: this->m_pShaderAPI, a2: v6, a3: v17, a4: v18);
  this->m_pShaderAPI->ClearBuffers(this: this->m_pShaderAPI, a2: true, a3: false, a4: false, a5: -1, a6: -1);
  this->m_pShaderDevice->Present(this: this->m_pShaderDevice);
  SetWindowTextA(hWnd: this->m_HWnd, lpString: "ClearBuffers test results . . hit a key");
  if ( CShaderAPITestApp::WaitForKeypress(this) != 0 )
  {
    nMaxViewports = g_pMaterialSystemHardwareConfig->MaxViewports(this: g_pMaterialSystemHardwareConfig);
    v7 = alloca(28 * nMaxViewports);
    pViewports = (ShaderViewport_t *)&v19;
    i = 0;
    if ( nMaxViewports > 0 )
    {
      v8 = &v20;
      do
      {
        x = _RandomInt(a1: 0, a2: 100);
        y = _RandomInt(a1: 0, a2: 100);
        v26 = _RandomInt(a1: 100, a2: 200);
        v9 = _RandomInt(a1: 100, a2: 200);
        v10 = x;
        *v8 = y;
        v11 = i;
        *(v8 - 1) = v10;
        v12 = v26;
        v8[3] = 0;
        v8[2] = v9;
        i = v11 + 1;
        v13 = pViewports;
        *(v8 - 2) = 1;
        v8[1] = v12;
        v8[4] = 1065353216;
        this->m_pShaderAPI->SetViewports(this: this->m_pShaderAPI, a2: i, a3: v13);
        v8 += 7;
      }
      while ( i < nMaxViewports );
    }
    SetWindowTextA(hWnd: this->m_HWnd, lpString: "SetViewports test results . . hit a key");
    if ( CShaderAPITestApp::WaitForKeypress(this) != 0 )
    {
      this->m_pShaderDevice->GetWindowSize(this: this->m_pShaderDevice, a2: &w, a3: &h);
      v14 = SHADER_BUFFER_TYPE_STATIC;
      viewport.m_nWidth = w;
      viewport.m_nHeight = h;
      m_pShaderAPI = this->m_pShaderAPI;
      viewport.m_flMinZ = 0.0;
      viewport.m_nVersion = 1;
      viewport.m_nTopLeftX = 0;
      viewport.m_nTopLeftY = 0;
      viewport.m_flMaxZ = 1.0;
      m_pShaderAPI->SetViewports(this: m_pShaderAPI, a2: 1, a3: &viewport);
      while ( v14 > SHADER_BUFFER_TYPE_DYNAMIC )
      {
LABEL_14:
        if ( ++v14 >= SHADER_BUFFER_TYPE_COUNT )
        {
          SetWindowTextA(hWnd: this->m_HWnd, lpString: "Dynamic Buffer Test: HIT A KEY!");
          CShaderAPITestApp::TestDynamicBuffers(this);
          if ( CShaderAPITestApp::WaitForKeypress(this) != 0 )
          {
            g_pMaterialSystemHardwareConfig->OverrideStreamOffsetSupport(
              this: g_pMaterialSystemHardwareConfig,
              a2: true,
              a3: false);
            SetWindowTextA(hWnd: this->m_HWnd, lpString: "Dynamic Buffer Test (no stream offset): HIT A KEY!");
            CShaderAPITestApp::TestDynamicBuffers(this);
            if ( CShaderAPITestApp::WaitForKeypress(this) != 0 )
              g_pMaterialSystemHardwareConfig->OverrideStreamOffsetSupport(
                this: g_pMaterialSystemHardwareConfig,
                a2: false,
                a3: false);
          }
          return 1;
        }
      }
      v16 = SHADER_BUFFER_TYPE_STATIC;
      while ( 1 )
      {
        if ( v16 <= SHADER_BUFFER_TYPE_DYNAMIC )
        {
          CShaderAPITestApp::TestColoredQuad(this, nVBType: v14, nIBType: v16, bBuffered: false);
          sprintf(string: buf, format: "TestColoredQuad results VB: %d IB: %d Buffered: %d HIT A KEY!", v14, v16, 0);
          SetWindowTextA(hWnd: this->m_HWnd, lpString: buf);
          if ( CShaderAPITestApp::WaitForKeypress(this) == 0 )
            break;
        }
        if ( ++v16 >= SHADER_BUFFER_TYPE_COUNT )
          goto LABEL_14;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004031F0
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

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
// Address: 0x00403260
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
// Address: 0x004032D0
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
// Address: 0x00403330
// Name: public: virtual char const __near * CShaderAPITestApp::GetAppName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CShaderAPITestApp::GetAppName(CShaderAPITestApp *this)
{
  return "InputTest";
}

//------------------------------------------------------------------------------
// Address: 0x004037D0
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
        dword_428DC8 = 0x1FFFF;
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
        dword_428DC8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004038C0
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
// Address: 0x004039C0
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
// Address: 0x00403AB0
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
// Address: 0x00403D90
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::Purge(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CUtlSymbolTable *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
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
// Address: 0x00403E00
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
        dword_428DC8 = 0x1FFFF;
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
        dword_428DC8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00403F00
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
  int v8; // edx
  CUtlSymbolTable *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlSymbolTable *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 56 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlSymbolTable::CUtlSymbolTable(this: v12, growSize: 0, initSize: 16, caseInsensitive: false);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00403FC0
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
        dword_428DC8 = 0x1FFFF;
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
        dword_428DC8 = 0x1FFFF;
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
        dword_428DC8 = 0x1FFFF;
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
        dword_428DC8 = 0x1FFFF;
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
        dword_428DC8 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_428DC8 = 0x1FFFF;
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
          dword_428DC8 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_428DC8 = 0x1FFFF;
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
          dword_428DC8 = 0x1FFFF;
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
          dword_428DC8 = 0x1FFFF;
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
            dword_428DC8 = 0x1FFFF;
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
            dword_428DC8 = 0x1FFFF;
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
          dword_428DC8 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_428DC8 = 0x1FFFF;
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
          dword_428DC8 = 0x1FFFF;
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
          dword_428DC8 = 0x1FFFF;
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
            dword_428DC8 = 0x1FFFF;
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
            dword_428DC8 = 0x1FFFF;
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
// Address: 0x004045B0
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAppSystemGroup::Module_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00404600
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
// Address: 0x00404A20
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}

//------------------------------------------------------------------------------
// Address: 0x00404B00
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
// Address: 0x0040C410
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx

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
// Address: 0x0040C510
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
    dword_42AFC8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_42AFC8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0040C690
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
    dword_42AFC8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0040C6F0
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
    dword_42AFC8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040C760
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
        dword_42AFC8 = 0x1FFFF;
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
        dword_42AFC8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C850
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
// Address: 0x0040C950
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
// Address: 0x0040CA90
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
        dword_42AFC8 = 0x1FFFF;
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
        dword_42AFC8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0040CB90
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
// Address: 0x0040CC50
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
      dword_42AFC8 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_42AFC8 = 0x1FFFF;
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
      dword_42AFC8 = 0x1FFFF;
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
      dword_42AFC8 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_42AFC8 = 0x1FFFF;
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
      dword_42AFC8 = 0x1FFFF;
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
        dword_42AFC8 = 0x1FFFF;
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
        dword_42AFC8 = 0x1FFFF;
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
          dword_42AFC8 = 0x1FFFF;
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
          dword_42AFC8 = 0x1FFFF;
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
        dword_42AFC8 = 0x1FFFF;
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
        dword_42AFC8 = 0x1FFFF;
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
          dword_42AFC8 = 0x1FFFF;
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
          dword_42AFC8 = 0x1FFFF;
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
// Address: 0x0040D260
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
// Address: 0x0040D360
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
// Address: 0x0040D3F0
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
  v3 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
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
// Address: 0x004011D0
// Name: __CreateCShaderUtilTempIShaderUtil_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CShaderUtilTemp *__cdecl _CreateCShaderUtilTempIShaderUtil_interface()
{
  return &g_pTemp;
}
