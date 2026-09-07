// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxcheckbox.cpp
// Functions: 3
// ============================================================

#include "utils\mxtk\mxcheckbox.h"

//------------------------------------------------------------------------------
// Address: 0x004C23A0
// Name: public: void mxCheckBox::setChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxCheckBox::setChecked(mxCheckBox *this, bool b)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0xF1u, wParam: b, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C23D0
// Name: public: bool mxCheckBox::isChecked(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall mxCheckBox::isChecked(mxCheckBox *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return SendMessageA(hWnd: Handle, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C23F0
// Name: public: mxCheckBox::mxCheckBox(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxCheckBox *__thiscall mxCheckBox::mxCheckBox(
        mxCheckBox *this,
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
  HWND__ *v13; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxCheckBox_vtbl *)&mxCheckBox::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "BUTTON",
               lpWindowName: label,
               dwStyle: 0x50000003u,
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
    mxWidget::setType(this, type: 1);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
    v13 = mxWidget::getHandle(this);
    SendMessageA(hWnd: v13, Msg: 0xF1u, wParam: 0, lParam: 0);
  }
  return this;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056D400
// Name: public: mxCheckBox::mxCheckBox(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxCheckBox *__thiscall mxCheckBox::mxCheckBox(
        mxCheckBox *this,
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
  HWND__ *v13; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxCheckBox_vtbl *)&mxCheckBox::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "BUTTON",
               lpWindowName: label,
               dwStyle: 0x50000003u,
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
    mxWidget::setType(this, type: 1);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
    v13 = mxWidget::getHandle(this);
    SendMessageA(hWnd: v13, Msg: 0xF1u, wParam: 0, lParam: 0);
  }
  return this;
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042B000
// Name: public: void mxCheckBox::setChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxCheckBox::setChecked(mxCheckBox *this, bool b)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0xF1u, wParam: b, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0042B030
// Name: public: bool mxCheckBox::isChecked(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall mxCheckBox::isChecked(mxCheckBox *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return SendMessageA(hWnd: Handle, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042B050
// Name: public: mxCheckBox::mxCheckBox(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxCheckBox *__thiscall mxCheckBox::mxCheckBox(
        mxCheckBox *this,
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
  HWND__ *v13; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxCheckBox_vtbl *)&mxCheckBox::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "BUTTON",
               lpWindowName: label,
               dwStyle: 0x50000003u,
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
    mxWidget::setType(this, type: 1);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
    v13 = mxWidget::getHandle(this);
    SendMessageA(hWnd: v13, Msg: 0xF1u, wParam: 0, lParam: 0);
  }
  return this;
}

} // namespace scenemanager
