// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxbutton.cpp
// Functions: 2
// ============================================================

#include "utils\mxtk\mxbutton.h"

//------------------------------------------------------------------------------
// Address: 0x004C1DB0
// Name: public: mxButton::mxButton(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxButton *__thiscall mxButton::mxButton(
        mxButton *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        HMENU id)
{
  HWND__ *Handle; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxButton_vtbl *)&mxButton::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "BUTTON",
               lpWindowName: label,
               dwStyle: 0x50000000u,
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
    mxWidget::setType(this, type: 0);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1E80
// Name: public: virtual mxButton::~mxButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxButton::~mxButton(mxButton *this)
{
  this->__vftable = (mxButton_vtbl *)&mxButton::`vftable';
  mxWidget::~mxWidget(this);
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056D510
// Name: public: mxButton::mxButton(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxButton *__thiscall mxButton::mxButton(
        mxButton *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        HMENU id)
{
  HWND__ *Handle; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxButton_vtbl *)&mxButton::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "BUTTON",
               lpWindowName: label,
               dwStyle: 0x50000000u,
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
    mxWidget::setType(this, type: 0);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042AF00
// Name: public: mxButton::mxButton(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxButton *__thiscall mxButton::mxButton(
        mxButton *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        HMENU id)
{
  HWND__ *Handle; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxButton_vtbl *)&mxButton::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "BUTTON",
               lpWindowName: label,
               dwStyle: 0x50000000u,
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
    mxWidget::setType(this, type: 0);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

} // namespace scenemanager
