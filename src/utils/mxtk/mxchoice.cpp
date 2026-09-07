// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxchoice.cpp
// Functions: 5
// ============================================================

#include "utils\mxtk\mxchoice.h"

//------------------------------------------------------------------------------
// Address: 0x004C2640
// Name: public: mxChoice::mxChoice(class mxWindow __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxChoice *__thiscall mxChoice::mxChoice(mxChoice *this, mxWindow *parent, int x, int y, int w, int h, HMENU id)
{
  HWND__ *Handle; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxChoice_vtbl *)&mxChoice::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "COMBOBOX",
               lpWindowName: defaultValue,
               dwStyle: 0x50200003u,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h + 500,
               hWndParent: Handle,
               hMenu: id,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 2);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C2710
// Name: public: void mxChoice::add(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxChoice::add(mxChoice *this, const char *item)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x143u, wParam: 0, lParam: (LPARAM)item);
}

//------------------------------------------------------------------------------
// Address: 0x004C2730
// Name: public: void mxChoice::select(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxChoice::select(mxChoice *this, WPARAM index)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x14Eu, wParam: index, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C2750
// Name: public: void mxChoice::removeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxChoice::removeAll(mxChoice *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x14Bu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C2770
// Name: public: int mxChoice::getSelectedIndex(void)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall mxChoice::getSelectedIndex(mxChoice *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return SendMessageA(hWnd: Handle, Msg: 0x147u, wParam: 0, lParam: 0);
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056D200
// Name: public: mxChoice::mxChoice(class mxWindow __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxChoice *__thiscall mxChoice::mxChoice(mxChoice *this, mxWindow *parent, int x, int y, int w, int h, HMENU id)
{
  HWND__ *Handle; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxChoice_vtbl *)&mxChoice::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "COMBOBOX",
               lpWindowName: WindowName,
               dwStyle: 0x50200003u,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h + 500,
               hWndParent: Handle,
               hMenu: id,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 2);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056D2D0
// Name: public: void mxChoice::add(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxChoice::add(mxChoice *this, const char *item)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x143u, wParam: 0, lParam: (LPARAM)item);
}

//------------------------------------------------------------------------------
// Address: 0x0056D2F0
// Name: public: void mxChoice::select(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxChoice::select(mxChoice *this, WPARAM index)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x14Eu, wParam: index, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056D310
// Name: public: void mxChoice::removeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxChoice::removeAll(mxChoice *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x14Bu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056D330
// Name: public: int mxChoice::getItemCount(void)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall mxChoice::getItemCount(mxChoice *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return SendMessageA(hWnd: Handle, Msg: 0x146u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056D350
// Name: public: int mxChoice::getSelectedIndex(void)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall mxChoice::getSelectedIndex(mxChoice *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return SendMessageA(hWnd: Handle, Msg: 0x147u, wParam: 0, lParam: 0);
}

} // namespace hlmv
