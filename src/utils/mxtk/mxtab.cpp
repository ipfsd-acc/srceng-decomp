// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxtab.cpp
// Functions: 4
// ============================================================

#include "utils\mxtk\mxtab.h"

//------------------------------------------------------------------------------
// Address: 0x004C27D0
// Name: void mxTab_resizeChild(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mxTab_resizeChild(HWND__ *hwnd)
{
  LRESULT v1; // eax
  HWND Parent; // eax
  HWND v3; // eax
  int SystemMetrics; // ebx
  int v5; // eax
  HDWP v6; // edi
  HWND__ *Handle; // eax
  int left; // [esp-18h] [ebp-64h]
  int top; // [esp-14h] [ebp-60h]
  int v10; // [esp-10h] [ebp-5Ch]
  int v11; // [esp-Ch] [ebp-58h]
  tagTCITEMA ti; // [esp+8h] [ebp-44h] BYREF
  tagRECT rc2; // [esp+24h] [ebp-28h] BYREF
  tagRECT rc; // [esp+34h] [ebp-18h] BYREF
  mxWidget *widget; // [esp+44h] [ebp-8h]
  int index; // [esp+48h] [ebp-4h]

  v1 = SendMessageA(hWnd: hwnd, Msg: 0x130Bu, wParam: 0, lParam: 0);
  index = v1;
  if ( v1 >= 0 )
  {
    ti.mask = 8;
    SendMessageA(hWnd: hwnd, Msg: 0x1305u, wParam: v1, lParam: (LPARAM)&ti);
    widget = (mxWidget *)ti.lParam;
    if ( ti.lParam != 0 )
    {
      GetWindowRect(hWnd: hwnd, lpRect: &rc);
      Parent = GetParent(hWnd: hwnd);
      ScreenToClient(hWnd: Parent, lpPoint: (LPPOINT)&rc);
      v3 = GetParent(hWnd: hwnd);
      ScreenToClient(hWnd: v3, lpPoint: (LPPOINT)&rc.right);
      SendMessageA(hWnd: hwnd, Msg: 0x130Au, wParam: index, lParam: (LPARAM)&rc2);
      SystemMetrics = GetSystemMetrics(nIndex: 45);
      v5 = GetSystemMetrics(nIndex: 46);
      rc.top += rc2.bottom + 3 * v5 - rc2.top;
      rc.left += 2 * SystemMetrics;
      rc.right -= 2 * SystemMetrics;
      rc.bottom -= 2 * v5;
      v6 = BeginDeferWindowPos(nNumWindows: 2);
      DeferWindowPos(hWinPosInfo: v6, hWnd: hwnd, hWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, uFlags: 7u);
      v11 = rc.bottom - rc.top;
      v10 = rc.right - rc.left;
      top = rc.top;
      left = rc.left;
      Handle = mxWidget::getHandle(this: widget);
      DeferWindowPos(
        hWinPosInfo: v6,
        hWnd: Handle,
        hWndInsertAfter: nullptr,
        x: left,
        y: top,
        cx: v10,
        cy: v11,
        uFlags: 0x40u);
      EndDeferWindowPos(hWinPosInfo: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C28E0
// Name: public: mxTab::mxTab(class mxWindow __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxTab *__thiscall mxTab::mxTab(mxTab *this, mxWindow *parent, int x, int y, int w, int h, HMENU id)
{
  HWND__ *Handle; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxTab_vtbl *)&mxTab::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "SysTabControl32",
               lpWindowName: defaultValue,
               dwStyle: 0x54000000u,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: Handle,
               hMenu: id,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 16);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C29A0
// Name: public: void mxTab::add(class mxWidget __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTab::add(mxTab *this, mxWidget *widget, char *text)
{
  HWND__ *Handle; // eax
  HWND__ *v5; // eax
  HWND__ *v6; // eax
  WPARAM v7; // [esp-8h] [ebp-2Ch]
  tagTCITEMA ti; // [esp+8h] [ebp-1Ch] BYREF

  ti.lParam = (int)widget;
  ti.mask = 9;
  ti.pszText = text;
  Handle = mxWidget::getHandle(this);
  v7 = SendMessageA(hWnd: Handle, Msg: 0x1304u, wParam: 0, lParam: 0);
  v5 = mxWidget::getHandle(this);
  SendMessageA(hWnd: v5, Msg: 0x1307u, wParam: v7, lParam: (LPARAM)&ti);
  v6 = mxWidget::getHandle(this);
  mxTab_resizeChild(hwnd: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004C2A10
// Name: public: int mxTab::getSelectedIndex(void)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall mxTab::getSelectedIndex(mxTab *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return SendMessageA(hWnd: Handle, Msg: 0x130Bu, wParam: 0, lParam: 0);
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056DC40
// Name: void mxTab_resizeChild(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mxTab_resizeChild(HWND__ *hwnd)
{
  LRESULT v1; // eax
  HWND Parent; // eax
  HWND v3; // eax
  int SystemMetrics; // ebx
  int v5; // eax
  HDWP v6; // edi
  HWND__ *Handle; // eax
  int left; // [esp-18h] [ebp-64h]
  int top; // [esp-14h] [ebp-60h]
  int v10; // [esp-10h] [ebp-5Ch]
  int v11; // [esp-Ch] [ebp-58h]
  tagTCITEMA ti; // [esp+8h] [ebp-44h] BYREF
  tagRECT rc2; // [esp+24h] [ebp-28h] BYREF
  tagRECT rc; // [esp+34h] [ebp-18h] BYREF
  mxWidget *widget; // [esp+44h] [ebp-8h]
  int index; // [esp+48h] [ebp-4h]

  v1 = SendMessageA(hWnd: hwnd, Msg: 0x130Bu, wParam: 0, lParam: 0);
  index = v1;
  if ( v1 >= 0 )
  {
    ti.mask = 8;
    SendMessageA(hWnd: hwnd, Msg: 0x1305u, wParam: v1, lParam: (LPARAM)&ti);
    widget = (mxWidget *)ti.lParam;
    if ( ti.lParam != 0 )
    {
      GetWindowRect(hWnd: hwnd, lpRect: &rc);
      Parent = GetParent(hWnd: hwnd);
      ScreenToClient(hWnd: Parent, lpPoint: (LPPOINT)&rc);
      v3 = GetParent(hWnd: hwnd);
      ScreenToClient(hWnd: v3, lpPoint: (LPPOINT)&rc.right);
      SendMessageA(hWnd: hwnd, Msg: 0x130Au, wParam: index, lParam: (LPARAM)&rc2);
      SystemMetrics = GetSystemMetrics(nIndex: 45);
      v5 = GetSystemMetrics(nIndex: 46);
      rc.top += rc2.bottom + 3 * v5 - rc2.top;
      rc.left += 2 * SystemMetrics;
      rc.right -= 2 * SystemMetrics;
      rc.bottom -= 2 * v5;
      v6 = BeginDeferWindowPos(nNumWindows: 2);
      DeferWindowPos(hWinPosInfo: v6, hWnd: hwnd, hWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, uFlags: 7u);
      v11 = rc.bottom - rc.top;
      v10 = rc.right - rc.left;
      top = rc.top;
      left = rc.left;
      Handle = mxWidget::getHandle(this: widget);
      DeferWindowPos(
        hWinPosInfo: v6,
        hWnd: Handle,
        hWndInsertAfter: nullptr,
        x: left,
        y: top,
        cx: v10,
        cy: v11,
        uFlags: 0x40u);
      EndDeferWindowPos(hWinPosInfo: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056DD50
// Name: public: mxTab::mxTab(class mxWindow __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxTab *__thiscall mxTab::mxTab(mxTab *this, mxWindow *parent, int x, int y, int w, int h, HMENU id)
{
  HWND__ *Handle; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxTab_vtbl *)&mxTab::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "SysTabControl32",
               lpWindowName: WindowName,
               dwStyle: 0x54000000u,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: Handle,
               hMenu: id,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 16);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056DE10
// Name: public: void mxTab::add(class mxWidget __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTab::add(mxTab *this, mxWidget *widget, char *text)
{
  HWND__ *Handle; // eax
  HWND__ *v5; // eax
  HWND__ *v6; // eax
  WPARAM v7; // [esp-8h] [ebp-2Ch]
  tagTCITEMA ti; // [esp+8h] [ebp-1Ch] BYREF

  ti.lParam = (int)widget;
  ti.mask = 9;
  ti.pszText = text;
  Handle = mxWidget::getHandle(this);
  v7 = SendMessageA(hWnd: Handle, Msg: 0x1304u, wParam: 0, lParam: 0);
  v5 = mxWidget::getHandle(this);
  SendMessageA(hWnd: v5, Msg: 0x1307u, wParam: v7, lParam: (LPARAM)&ti);
  v6 = mxWidget::getHandle(this);
  mxTab_resizeChild(hwnd: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0056DE80
// Name: public: int mxTab::getSelectedIndex(void)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall mxTab::getSelectedIndex(mxTab *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return SendMessageA(hWnd: Handle, Msg: 0x130Bu, wParam: 0, lParam: 0);
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042BB50
// Name: void mxTab_resizeChild(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mxTab_resizeChild(HWND__ *hwnd)
{
  LRESULT v1; // eax
  HWND Parent; // eax
  HWND v3; // eax
  int SystemMetrics; // ebx
  int v5; // eax
  HDWP v6; // edi
  HWND__ *Handle; // eax
  int left; // [esp-18h] [ebp-64h]
  int top; // [esp-14h] [ebp-60h]
  int v10; // [esp-10h] [ebp-5Ch]
  int v11; // [esp-Ch] [ebp-58h]
  tagTCITEMA ti; // [esp+8h] [ebp-44h] BYREF
  tagRECT rc2; // [esp+24h] [ebp-28h] BYREF
  tagRECT rc; // [esp+34h] [ebp-18h] BYREF
  mxWidget *widget; // [esp+44h] [ebp-8h]
  int index; // [esp+48h] [ebp-4h]

  v1 = SendMessageA(hWnd: hwnd, Msg: 0x130Bu, wParam: 0, lParam: 0);
  index = v1;
  if ( v1 >= 0 )
  {
    ti.mask = 8;
    SendMessageA(hWnd: hwnd, Msg: 0x1305u, wParam: v1, lParam: (LPARAM)&ti);
    widget = (mxWidget *)ti.lParam;
    if ( ti.lParam != 0 )
    {
      GetWindowRect(hWnd: hwnd, lpRect: &rc);
      Parent = GetParent(hWnd: hwnd);
      ScreenToClient(hWnd: Parent, lpPoint: (LPPOINT)&rc);
      v3 = GetParent(hWnd: hwnd);
      ScreenToClient(hWnd: v3, lpPoint: (LPPOINT)&rc.right);
      SendMessageA(hWnd: hwnd, Msg: 0x130Au, wParam: index, lParam: (LPARAM)&rc2);
      SystemMetrics = GetSystemMetrics(nIndex: 45);
      v5 = GetSystemMetrics(nIndex: 46);
      rc.top += rc2.bottom + 3 * v5 - rc2.top;
      rc.left += 2 * SystemMetrics;
      rc.right -= 2 * SystemMetrics;
      rc.bottom -= 2 * v5;
      v6 = BeginDeferWindowPos(nNumWindows: 2);
      DeferWindowPos(hWinPosInfo: v6, hWnd: hwnd, hWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, uFlags: 7u);
      v11 = rc.bottom - rc.top;
      v10 = rc.right - rc.left;
      top = rc.top;
      left = rc.left;
      Handle = mxWidget::getHandle(this: widget);
      DeferWindowPos(
        hWinPosInfo: v6,
        hWnd: Handle,
        hWndInsertAfter: nullptr,
        x: left,
        y: top,
        cx: v10,
        cy: v11,
        uFlags: 0x40u);
      EndDeferWindowPos(hWinPosInfo: v6);
    }
  }
}

} // namespace scenemanager
