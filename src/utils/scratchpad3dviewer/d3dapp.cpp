// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scratchpad3dviewer/d3dapp.cpp
// Functions: 17
// ============================================================

#include "utils\scratchpad3dviewer\d3dapp.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: void CallAppRender(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CallAppRender(bool bInvalidRect)
{
  DWORD TickCount; // ecx
  double v2; // st7
  int v3; // edi
  int v4; // esi
  tagRECT Rect; // [esp+18h] [ebp-1Ch] BYREF
  tagPOINT curMousePos; // [esp+28h] [ebp-Ch] BYREF
  float frametime; // [esp+30h] [ebp-4h]

  TickCount = GetTickCount();
  v2 = (double)(TickCount - lastTime) * 0.001;
  frametime = v2;
  if ( v2 > 0.1 )
    frametime = 0.1;
  lastTime = TickCount;
  GetCursorPos(lpPoint: &curMousePos);
  if ( lastMousePos.x == 0xFFFF )
  {
    v3 = 0;
    v4 = 0;
  }
  else
  {
    v4 = curMousePos.x - lastMousePos.x;
    v3 = curMousePos.y - lastMousePos.y;
  }
  if ( g_nCapture != 0 )
  {
    GetWindowRect(hWnd: g_hWnd, lpRect: &Rect);
    lastMousePos.x = (Rect.right + Rect.left) / 2;
    lastMousePos.y = (Rect.bottom + Rect.top) / 2;
    SetCursorPos(X: (Rect.right + Rect.left) / 2, Y: lastMousePos.y);
  }
  else
  {
    lastMousePos = curMousePos;
  }
  AppRender(frametime, mouseDeltaX: (float)v4, mouseDeltaY: (float)v3, bInvalidRect);
}

//------------------------------------------------------------------------------
// Address: 0x00401110
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401160
// Name: bool Sys_Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __noreturn Sys_Error(char *pMsg, ...)
{
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  _vsnprintf(string, count: 0x1000u, format: pMsg, ap);
  MessageBoxA(hWnd: nullptr, lpText: string, lpCaption: "Error!", uType: 0);
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004011B0
// Name: void Sys_Quit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_Quit()
{
  PostQuitMessage(nExitCode: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004011C0
// Name: void Sys_SetWindowText(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_SetWindowText(char *pMsg, ...)
{
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(ap, pMsg);
  _vsnprintf(string, count: 0x1000u, format: pMsg, ap);
  SetWindowTextA(hWnd: g_hWnd, lpString: string);
}

//------------------------------------------------------------------------------
// Address: 0x00401210
// Name: bool Sys_GetKeyState(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Sys_GetKeyState(int key)
{
  int v1; // eax
  int keyTranslations[3][2]; // [esp+0h] [ebp-18h]

  *(_QWORD *)&keyTranslations[0][0] = 0x1FFFFFFFFLL;
  *(_QWORD *)&keyTranslations[1][0] = 0x2FFFFFFFELL;
  *(_QWORD *)&keyTranslations[2][0] = 0x20FFFFFFFDLL;
  v1 = 0;
  while ( key != keyTranslations[v1][0] )
  {
    if ( ++v1 >= 3 )
      return GetAsyncKeyState(vKey: key) < 0;
  }
  return GetAsyncKeyState(vKey: keyTranslations[v1][1]) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401280
// Name: void Sys_Sleep(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_Sleep(DWORD ms)
{
  Sleep(dwMilliseconds: ms);
}

//------------------------------------------------------------------------------
// Address: 0x00401290
// Name: bool Sys_HasFocus(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Sys_HasFocus()
{
  return g_bFocus;
}

//------------------------------------------------------------------------------
// Address: 0x004012A0
// Name: char const __near * Sys_FindArg(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Sys_FindArg(const char *pArg, const char *pDefault)
{
  int v2; // esi

  v2 = 0;
  if ( __argc <= 0 )
    return (char *)pDefault;
  while ( _V_stricmp(s1: __argv[v2], s2: pArg) != 0 )
  {
    if ( ++v2 >= __argc )
      return (char *)pDefault;
  }
  if ( v2 + 1 >= __argc )
    return (char *)&unk_41A27F;
  else
    return __argv[v2 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x00401300
// Name: int Sys_ScreenWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_ScreenWidth()
{
  return g_ScreenWidth;
}

//------------------------------------------------------------------------------
// Address: 0x00401310
// Name: int Sys_ScreenHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_ScreenHeight()
{
  return g_ScreenHeight;
}

//------------------------------------------------------------------------------
// Address: 0x00401320
// Name: void InitD3D(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitD3D()
{
  int v0; // eax
  const char *v1; // eax
  _D3DDISPLAYMODE d3ddm; // [esp+0h] [ebp-20h] BYREF
  tagRECT rcClient; // [esp+10h] [ebp-10h] BYREF

  if ( g_pDevice != nullptr )
  {
    g_pDevice->Release(this: g_pDevice);
    g_pDevice = nullptr;
  }
  if ( g_pDirect3D != nullptr )
  {
    g_pDirect3D->Release(this: g_pDirect3D);
    g_pDirect3D = nullptr;
  }
  GetClientRect(hWnd: g_hWnd, lpRect: &rcClient);
  g_ScreenWidth = rcClient.right - rcClient.left;
  g_ScreenHeight = rcClient.bottom - rcClient.top;
  g_pDirect3D = (IDirect3D8 *)Direct3DCreate8(a1: 220);
  g_pDirect3D->GetAdapterDisplayMode(this: g_pDirect3D, a2: 0, a3: &d3ddm);
  memset(dst: (unsigned __int8 *)&d3dpp, value: 0, count: sizeof(d3dpp));
  d3dpp.BackBufferFormat = d3ddm.Format;
  d3dpp.Windowed = 1;
  d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
  d3dpp.EnableAutoDepthStencil = 1;
  d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
  d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
  v0 = g_pDirect3D->CreateDevice(
         this: g_pDirect3D,
         a2: 0,
         a3: D3DDEVTYPE_HAL,
         a4: g_hWnd,
         a5: 32u,
         a6: &d3dpp,
         a7: &g_pDevice);
  if ( v0 < 0 )
  {
    v1 = (const char *)DXGetErrorString8A(a1: v0);
    Sys_Error(pMsg: "CreateDevice failed (%s)", v1);
  }
  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_CULLMODE, a3: 1u);
  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_LIGHTING, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00401460
// Name: void DoResize(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00401480
// Name: int InitInstance(struct HINSTANCE__ __near *,int)
// Source: json
//------------------------------------------------------------------------------
HWND __cdecl InitInstance(HINSTANCE__ *hInstance, int nCmdShow)
{
  char *Arg; // eax
  char *v3; // eax
  int v4; // ebx
  char *v5; // eax
  int v6; // edi
  char *v7; // eax
  int v8; // esi
  int top; // ebx
  int left; // ecx
  DWORD v11; // eax
  HWND result; // eax
  tagRECT rcWorkArea; // [esp+0h] [ebp-18h] BYREF
  unsigned int dwFlags; // [esp+10h] [ebp-8h]
  int x; // [esp+14h] [ebp-4h]

  hInst = hInstance;
  Arg = Sys_FindArg(pArg: "-x", pDefault: nullptr);
  if ( Arg != nullptr )
    x = atoi(nptr: Arg);
  else
    x = 0;
  v3 = Sys_FindArg(pArg: "-y", pDefault: nullptr);
  if ( v3 != nullptr )
    v4 = atoi(nptr: v3);
  else
    v4 = 0;
  v5 = Sys_FindArg(pArg: "-width", pDefault: nullptr);
  if ( v5 != nullptr )
    v6 = atoi(nptr: v5);
  else
    v6 = 0x80000000;
  v7 = Sys_FindArg(pArg: "-height", pDefault: nullptr);
  if ( v7 != nullptr )
    v8 = atoi(nptr: v7);
  else
    v8 = 0x80000000;
  dwFlags = 13565952;
  SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: (PVOID)&rcWorkArea, fWinIni: 0);
  if ( x != 0 || v4 != 0 || v6 != 0x80000000 || v8 != v6 )
  {
    left = rcWorkArea.left + x;
    top = rcWorkArea.top + v4;
    v11 = dwFlags;
  }
  else
  {
    top = rcWorkArea.top;
    x = rcWorkArea.left;
    left = rcWorkArea.left;
    v6 = rcWorkArea.right - rcWorkArea.left;
    v8 = rcWorkArea.bottom - rcWorkArea.top;
    v11 = 30343168;
  }
  result = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: szWindowClass,
             lpWindowName: szTitle,
             dwStyle: v11,
             X: left,
             Y: top,
             nWidth: v6,
             nHeight: v8,
             hWndParent: nullptr,
             hMenu: nullptr,
             hInstance,
             lpParam: nullptr);
  g_hWnd = result;
  if ( result != nullptr )
  {
    ShowWindow(hWnd: result, nCmdShow);
    UpdateWindow(hWnd: g_hWnd);
    InitD3D();
    AppInit();
    AppPreResize();
    InitD3D();
    AppChar(key: rcWorkArea.left);
    CallAppRender(bInvalidRect: true);
    return (HWND)1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004015F0
// Name: long WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WndProc(HWND__ *hWnd, UINT message, unsigned int wParam, LPARAM lParam)
{
  int result; // eax
  tagPAINTSTRUCT ps; // [esp+0h] [ebp-40h] BYREF

  if ( message > 0x100 )
  {
    if ( message <= 0x201 )
    {
      if ( message != 513 )
      {
        if ( message == 257 )
        {
          AppKey(key: wParam, down: 0);
          return 0;
        }
        if ( message == 258 )
        {
          AppChar(key: wParam);
          return 0;
        }
        return DefWindowProcA(hWnd, Msg: message, wParam, lParam);
      }
LABEL_18:
      ShowCursor(bShow: false);
      SetCapture(hWnd: g_hWnd);
      ++g_nCapture;
      return 0;
    }
    if ( message != 514 )
    {
      if ( message == 516 )
        goto LABEL_18;
      if ( message != 517 )
        return DefWindowProcA(hWnd, Msg: message, wParam, lParam);
    }
    ShowCursor(bShow: true);
    ReleaseCapture();
    --g_nCapture;
    return 0;
  }
  if ( message == 256 )
  {
    AppKey(key: wParam, down: (unsigned __int16)lParam);
    return 0;
  }
  else
  {
    switch ( message )
    {
      case 2u:
        PostQuitMessage(nExitCode: 0);
        result = 0;
        break;
      case 5u:
        if ( g_pDevice == nullptr )
          return 0;
        DoResize();
        result = 0;
        break;
      case 7u:
        g_bFocus = true;
        result = 0;
        break;
      case 8u:
        g_bFocus = false;
        result = 0;
        break;
      case 0xFu:
        BeginPaint(hWnd, lpPaint: &ps);
        EndPaint(hWnd, lpPaint: &ps);
        if ( g_pDevice == nullptr )
          return 0;
        CallAppRender(bInvalidRect: true);
        result = 0;
        break;
      default:
        return DefWindowProcA(hWnd, Msg: message, wParam, lParam);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004017C0
// Name: unsigned short MyRegisterClass(struct HINSTANCE__ __near *)
// Source: json
//------------------------------------------------------------------------------
ATOM __cdecl MyRegisterClass(HINSTANCE__ *hInstance)
{
  tagWNDCLASSEXA wcex; // [esp+4h] [ebp-30h] BYREF

  wcex.cbSize = 48;
  wcex.style = 3;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = LoadIconA(hInstance, lpIconName: (LPCSTR)0x6B);
  wcex.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wcex.hbrBackground = (HBRUSH__ *)6;
  wcex.lpszMenuName = nullptr;
  wcex.lpszClassName = szWindowClass;
  wcex.hIconSm = LoadIconA(hInstance, lpIconName: (LPCSTR)0x6C);
  return RegisterClassExA(a1: &wcex);
}

//------------------------------------------------------------------------------
// Address: 0x00401840
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
HWND __userpurge WinMain@<eax>(
        int a1@<ebx>,
        HINSTANCE__ *hInstance,
        HINSTANCE__ *hPrevInstance,
        char *lpCmdLine,
        int nCmdShow)
{
  int *v5; // edi
  int v6; // esi
  int CommandLine; // eax
  HWND result; // eax
  HACCEL AcceleratorsA; // edi
  tagMSG msg; // [esp+2Ch] [ebp-20h] BYREF
  CSimpleWindowsLoggingListener simpleWindowsLoggingListener; // [esp+48h] [ebp-4h] BYREF

  v5 = (int *)_CommandLine();
  v6 = *v5;
  CommandLine = _Plat_GetCommandLine();
  (*(void (__thiscall **)(int *, int))(v6 + 4))(a1: v5, a2: CommandLine);
  simpleWindowsLoggingListener.__vftable = (CSimpleWindowsLoggingListener_vtbl *)&CSimpleWindowsLoggingListener::`vftable';
  _LoggingSystem_ResetCurrentLoggingState();
  _LoggingSystem_RegisterLoggingListener(a1: &simpleWindowsLoggingListener);
  MathLib_Init(
    gamma: 1.0,
    texGamma: 1.0,
    brightness: 1.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: false,
    bAllowSSE2: true,
    bAllowMMX: true);
  LoadStringA(hInstance, uID: 0x67u, lpBuffer: szTitle, cchBufferMax: 100);
  strcpy(szWindowClass, "d3dapp");
  MyRegisterClass(hInstance);
  result = InitInstance(hInstance, nCmdShow);
  if ( result != nullptr )
  {
    AcceleratorsA = LoadAcceleratorsA(hInstance, lpTableName: (LPCSTR)0x6D);
    InvalidateRect(hWnd: g_hWnd, lpRect: nullptr, bErase: false);
    while ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
    {
LABEL_8:
      if ( msg.message == 18 )
        goto LABEL_10;
      CallAppRender(bInvalidRect: false);
    }
    while ( msg.message != 18 )
    {
      if ( TranslateAcceleratorA(hWnd: msg.hwnd, hAccTable: AcceleratorsA, lpMsg: &msg) == 0 )
      {
        TranslateMessage(lpMsg: &msg);
        DispatchMessageA(lpMsg: &msg);
      }
      if ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
        goto LABEL_8;
    }
LABEL_10:
    AppChar(key: a1);
    return (HWND)msg.wParam;
  }
  return result;
}
