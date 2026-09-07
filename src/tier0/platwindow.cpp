// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/platwindow.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000AB70
// Name: _Plat_CreateWindow
// Source: json
//------------------------------------------------------------------------------
PlatWindow_t__ *__cdecl Plat_CreateWindow(
        HINSTANCE__ *hInstance,
        const char *pTitle,
        int nWidth,
        int nHeight,
        char nFlags)
{
  DWORD v5; // esi
  tagWNDCLASSEXA wc; // [esp+Ch] [ebp-40h] BYREF
  tagRECT windowRect; // [esp+3Ch] [ebp-10h] BYREF

  memset(dst: (unsigned __int8 *)&wc, value: 0, count: sizeof(wc));
  wc.cbSize = 48;
  wc.style = 40;
  wc.lpfnWndProc = DefWindowProcA;
  wc.hInstance = hInstance;
  wc.lpszClassName = "Valve001";
  wc.hIcon = nullptr;
  wc.hIconSm = nullptr;
  RegisterClassExA(a1: &wc);
  v5 = -2080374784;
  if ( (nFlags & 1) == 0 )
    v5 = ((nFlags & 2) << 17) | 0x84CB0000;
  windowRect.top = 0;
  windowRect.left = 0;
  windowRect.right = nWidth;
  windowRect.bottom = nHeight;
  AdjustWindowRectEx(lpRect: &windowRect, dwStyle: v5, bMenu: false, dwExStyle: 0);
  return (PlatWindow_t__ *)CreateWindowExA(
                             dwExStyle: 0,
                             lpClassName: wc.lpszClassName,
                             lpWindowName: pTitle,
                             dwStyle: v5,
                             X: 0,
                             Y: 0,
                             nWidth: windowRect.right - windowRect.left,
                             nHeight: windowRect.bottom - windowRect.top,
                             hWndParent: nullptr,
                             hMenu: nullptr,
                             hInstance,
                             lpParam: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000AC30
// Name: _Plat_SetWindowTitle
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_SetWindowTitle(PlatWindow_t__ *hWindow, const char *pTitle)
{
  SetWindowTextA(hWnd: (HWND)hWindow, lpString: pTitle);
}

//------------------------------------------------------------------------------
// Address: 0x1000AC50
// Name: _Plat_SetWindowPos
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_SetWindowPos(PlatWindow_t__ *hWindow, int x, int y)
{
  SetWindowPos(hWnd: (HWND)hWindow, hWndInsertAfter: nullptr, X: x, Y: y, cx: 0, cy: 0, uFlags: 0x65u);
}

//------------------------------------------------------------------------------
// Address: 0x1000AC70
// Name: _Plat_GetDesktopResolution
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_GetDesktopResolution(int *pWidth, int *pHeight)
{
  *pWidth = GetSystemMetrics(nIndex: 0);
  *pHeight = GetSystemMetrics(nIndex: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000AC90
// Name: _Plat_GetWindowClientSize
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_GetWindowClientSize(PlatWindow_t__ *hWindow, int *pWidth, int *pHeight)
{
  int v3; // ecx
  tagRECT rect; // [esp+0h] [ebp-10h] BYREF

  GetClientRect(hWnd: (HWND)hWindow, lpRect: &rect);
  v3 = rect.bottom - rect.top;
  *pWidth = rect.right - rect.left;
  *pHeight = v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000ACC0
// Name: _Plat_IsWindowMinimized
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Plat_IsWindowMinimized(PlatWindow_t__ *hWindow)
{
  return IsIconic(hWnd: (HWND)hWindow);
}

//------------------------------------------------------------------------------
// Address: 0x1000ACE0
// Name: _Plat_GetShellWindow
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
HWND __stdcall Plat_GetShellWindow()
{
  return GetShellWindow();
}

//------------------------------------------------------------------------------
// Address: 0x1000ACF0
// Name: _Plat_WindowToScreenCoords
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_WindowToScreenCoords(PlatWindow_t__ *hWnd, int *x, int *y)
{
  int v3; // ecx
  tagPOINT pt; // [esp+8h] [ebp-8h] BYREF

  v3 = *y;
  pt.x = *x;
  pt.y = v3;
  ClientToScreen((HWND)hWnd, lpPoint: &pt);
  *(tagPOINT *)x = pt;
}

//------------------------------------------------------------------------------
// Address: 0x1000AD30
// Name: _Plat_ScreenToWindowCoords
// Source: json
//------------------------------------------------------------------------------
void __cdecl Plat_ScreenToWindowCoords(PlatWindow_t__ *hWnd, int *x, int *y)
{
  int v3; // ecx
  tagPOINT pt; // [esp+8h] [ebp-8h] BYREF

  v3 = *y;
  pt.x = *x;
  pt.y = v3;
  ScreenToClient((HWND)hWnd, lpPoint: &pt);
  *(tagPOINT *)x = pt;
}
