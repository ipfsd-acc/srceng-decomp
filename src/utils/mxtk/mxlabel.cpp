// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxlabel.cpp
// Functions: 1
// ============================================================

#include "utils\mxtk\mxlabel.h"

//------------------------------------------------------------------------------
// Address: 0x004C2500
// Name: public: mxLabel::mxLabel(class mxWindow __near *,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxLabel *__thiscall mxLabel::mxLabel(mxLabel *this, mxWindow *parent, int x, int y, int w, int h, const char *label)
{
  HWND__ *Handle; // ebx
  HMODULE ModuleHandleA; // eax
  HWND Window; // ebx
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxLabel_vtbl *)&mxLabel::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "STATIC",
               lpWindowName: label,
               dwStyle: 0x50000000u,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: Handle,
               hMenu: nullptr,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 6);
    mxWidget::setParent(this, parentWindow: parent);
  }
  return this;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056D120
// Name: public: mxLabel::mxLabel(class mxWindow __near *,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxLabel *__thiscall mxLabel::mxLabel(mxLabel *this, mxWindow *parent, int x, int y, int w, int h, const char *label)
{
  HWND__ *Handle; // ebx
  HMODULE ModuleHandleA; // eax
  HWND Window; // ebx
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxLabel_vtbl *)&mxLabel::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "STATIC",
               lpWindowName: label,
               dwStyle: 0x50000000u,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: Handle,
               hMenu: nullptr,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 6);
    mxWidget::setParent(this, parentWindow: parent);
  }
  return this;
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042AE20
// Name: public: mxLabel::mxLabel(class mxWindow __near *,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxLabel *__thiscall mxLabel::mxLabel(mxLabel *this, mxWindow *parent, int x, int y, int w, int h, const char *label)
{
  HWND__ *Handle; // ebx
  HMODULE ModuleHandleA; // eax
  HWND Window; // ebx
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxLabel_vtbl *)&mxLabel::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "STATIC",
               lpWindowName: label,
               dwStyle: 0x50000000u,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: Handle,
               hMenu: nullptr,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 6);
    mxWidget::setParent(this, parentWindow: parent);
  }
  return this;
}

} // namespace scenemanager
