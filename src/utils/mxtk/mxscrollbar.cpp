// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxscrollbar.cpp
// Functions: 8
// ============================================================

#include "utils\mxtk\mxscrollbar.h"

//------------------------------------------------------------------------------
// Address: 0x004C17F0
// Name: public: mxScrollbar::mxScrollbar(class mxWindow __near *,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxScrollbar *__thiscall mxScrollbar::mxScrollbar(
        mxScrollbar *this,
        HWND__ *parent,
        int x,
        int y,
        int w,
        int h,
        HMENU id,
        int style)
{
  DWORD v10; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax
  HWND hwndParent; // [esp+10h] [ebp+8h]

  mxWidget::mxWidget(this, (mxWindow *)parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxScrollbar_vtbl *)&mxScrollbar::`vftable';
  if ( parent != nullptr )
  {
    v10 = 1342177280;
    hwndParent = mxWidget::getHandle(this: (mxWidget *)parent);
    if ( style != 0 )
    {
      if ( style == 1 )
        v10 = 1342177285;
    }
    else
    {
      v10 = 1342177284;
    }
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "SCROLLBAR",
               lpWindowName: defaultValue,
               dwStyle: v10,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: hwndParent,
               hMenu: id,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 15);
    mxWidget::setParent(this, parentWindow: (mxWindow *)parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C18D0
// Name: public: void mxScrollbar::setValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxScrollbar::setValue(mxScrollbar *this, int ivalue)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SetScrollPos(hWnd: Handle, nBar: 2, nPos: ivalue, bRedraw: false);
}

//------------------------------------------------------------------------------
// Address: 0x004C18F0
// Name: public: void mxScrollbar::setRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxScrollbar::setRange(mxScrollbar *this, int min, int max)
{
  HWND__ *Handle; // eax
  tagSCROLLINFO v4; // [esp+0h] [ebp-1Ch] BYREF

  v4.nMin = min;
  memset(&v4.nPage, 0, 12);
  v4.cbSize = 28;
  v4.fMask = 1;
  v4.nMax = max;
  Handle = mxWidget::getHandle(this);
  SetScrollInfo(hwnd: Handle, nBar: 2, lpsi: &v4, redraw: true);
}

//------------------------------------------------------------------------------
// Address: 0x004C1940
// Name: public: void mxScrollbar::setPagesize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxScrollbar::setPagesize(mxScrollbar *this, unsigned int size)
{
  HWND__ *Handle; // eax
  tagSCROLLINFO v3; // [esp+0h] [ebp-1Ch] BYREF

  v3.nMin = 0;
  v3.nMax = 0;
  v3.nPos = 0;
  v3.nTrackPos = 0;
  v3.cbSize = 28;
  v3.fMask = 2;
  v3.nPage = size;
  Handle = mxWidget::getHandle(this);
  SetScrollInfo(hwnd: Handle, nBar: 2, lpsi: &v3, redraw: true);
}

//------------------------------------------------------------------------------
// Address: 0x004C1990
// Name: public: int mxScrollbar::getValue(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxScrollbar::getValue(mxScrollbar *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return GetScrollPos(hWnd: Handle, nBar: 2);
}

//------------------------------------------------------------------------------
// Address: 0x004C19A0
// Name: public: int mxScrollbar::getMinValue(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxScrollbar::getMinValue(mxScrollbar *this)
{
  HWND__ *Handle; // eax
  tagSCROLLINFO v3; // [esp+0h] [ebp-1Ch] BYREF

  memset(&v3.nMin, 0, 20);
  v3.cbSize = 28;
  v3.fMask = 1;
  Handle = mxWidget::getHandle(this);
  GetScrollInfo(hwnd: Handle, nBar: 2, lpsi: &v3);
  return v3.nMin;
}

//------------------------------------------------------------------------------
// Address: 0x004C19E0
// Name: public: int mxScrollbar::getMaxValue(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxScrollbar::getMaxValue(mxScrollbar *this)
{
  HWND__ *Handle; // eax
  tagSCROLLINFO v3; // [esp+0h] [ebp-1Ch] BYREF

  memset(&v3.nMin, 0, 20);
  v3.cbSize = 28;
  v3.fMask = 1;
  Handle = mxWidget::getHandle(this);
  GetScrollInfo(hwnd: Handle, nBar: 2, lpsi: &v3);
  return v3.nMax;
}

//------------------------------------------------------------------------------
// Address: 0x004C1A20
// Name: public: int mxScrollbar::getPagesize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall mxScrollbar::getPagesize(mxScrollbar *this)
{
  HWND__ *Handle; // eax
  tagSCROLLINFO v3; // [esp+0h] [ebp-1Ch] BYREF

  memset(&v3.nMin, 0, 20);
  v3.cbSize = 28;
  v3.fMask = 2;
  Handle = mxWidget::getHandle(this);
  GetScrollInfo(hwnd: Handle, nBar: 2, lpsi: &v3);
  return v3.nPage;
}

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042B420
// Name: public: mxScrollbar::mxScrollbar(class mxWindow __near *,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxScrollbar *__thiscall mxScrollbar::mxScrollbar(
        mxScrollbar *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        HMENU id,
        int style)
{
  DWORD v10; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax
  HWND hwndParent; // [esp+10h] [ebp+8h]

  mxWidget::mxWidget(this, parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxScrollbar_vtbl *)&mxScrollbar::`vftable';
  if ( parent != nullptr )
  {
    v10 = 1342177280;
    hwndParent = mxWidget::getHandle(this: parent);
    if ( style != 0 )
    {
      if ( style == 1 )
        v10 = 1342177285;
    }
    else
    {
      v10 = 1342177284;
    }
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "SCROLLBAR",
               lpWindowName: &WindowName,
               dwStyle: v10,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: hwndParent,
               hMenu: id,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 15);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B500
// Name: public: void mxScrollbar::setValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxScrollbar::setValue(mxScrollbar *this, int ivalue)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SetScrollPos(hWnd: Handle, nBar: 2, nPos: ivalue, bRedraw: false);
}

//------------------------------------------------------------------------------
// Address: 0x0042B520
// Name: public: void mxScrollbar::setRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxScrollbar::setRange(mxScrollbar *this, int min, int max)
{
  HWND__ *Handle; // eax
  tagSCROLLINFO v4; // [esp+0h] [ebp-1Ch] BYREF

  v4.nMin = min;
  memset(&v4.nPage, 0, 12);
  v4.cbSize = 28;
  v4.fMask = 1;
  v4.nMax = max;
  Handle = mxWidget::getHandle(this);
  SetScrollInfo(hwnd: Handle, nBar: 2, lpsi: &v4, redraw: true);
}

//------------------------------------------------------------------------------
// Address: 0x0042B570
// Name: public: void mxScrollbar::setPagesize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxScrollbar::setPagesize(mxScrollbar *this, unsigned int size)
{
  HWND__ *Handle; // eax
  tagSCROLLINFO v3; // [esp+0h] [ebp-1Ch] BYREF

  v3.nMin = 0;
  v3.nMax = 0;
  v3.nPos = 0;
  v3.nTrackPos = 0;
  v3.cbSize = 28;
  v3.fMask = 2;
  v3.nPage = size;
  Handle = mxWidget::getHandle(this);
  SetScrollInfo(hwnd: Handle, nBar: 2, lpsi: &v3, redraw: true);
}

//------------------------------------------------------------------------------
// Address: 0x0042B5C0
// Name: public: int mxScrollbar::getValue(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxScrollbar::getValue(mxScrollbar *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return GetScrollPos(hWnd: Handle, nBar: 2);
}

//------------------------------------------------------------------------------
// Address: 0x0042B5D0
// Name: public: int mxScrollbar::getMaxValue(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxScrollbar::getMaxValue(mxScrollbar *this)
{
  HWND__ *Handle; // eax
  tagSCROLLINFO v3; // [esp+0h] [ebp-1Ch] BYREF

  memset(&v3.nMin, 0, 20);
  v3.cbSize = 28;
  v3.fMask = 1;
  Handle = mxWidget::getHandle(this);
  GetScrollInfo(hwnd: Handle, nBar: 2, lpsi: &v3);
  return v3.nMax;
}

//------------------------------------------------------------------------------
// Address: 0x0042B610
// Name: public: int mxScrollbar::getPagesize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall mxScrollbar::getPagesize(mxScrollbar *this)
{
  HWND__ *Handle; // eax
  tagSCROLLINFO v3; // [esp+0h] [ebp-1Ch] BYREF

  memset(&v3.nMin, 0, 20);
  v3.cbSize = 28;
  v3.fMask = 2;
  Handle = mxWidget::getHandle(this);
  GetScrollInfo(hwnd: Handle, nBar: 2, lpsi: &v3);
  return v3.nPage;
}

} // namespace scenemanager
