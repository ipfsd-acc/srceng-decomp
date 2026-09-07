// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxlistbox.cpp
// Functions: 9
// ============================================================

#include "utils\mxtk\mxlistbox.h"

//------------------------------------------------------------------------------
// Address: 0x0056CF00
// Name: public: mxListBox::mxListBox(class mxWindow __near *,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxListBox *__thiscall mxListBox::mxListBox(
        mxListBox *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        HMENU id,
        int style)
{
  HWND__ *Handle; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxListBox_vtbl *)&mxListBox::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0x200u,
               lpClassName: "LISTBOX",
               lpWindowName: WindowName,
               dwStyle: 0x50200001u,
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
    mxWidget::setType(this, type: 8);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056CFD0
// Name: public: void mxListBox::add(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListBox::add(mxListBox *this, const char *item)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x180u, wParam: 0, lParam: (LPARAM)item);
}

//------------------------------------------------------------------------------
// Address: 0x0056CFF0
// Name: public: void mxListBox::select(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListBox::select(mxListBox *this, WPARAM index)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x186u, wParam: index, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056D010
// Name: public: void mxListBox::deselect(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListBox::deselect(mxListBox *this, LPARAM index)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x185u, wParam: 0, lParam: index);
}

//------------------------------------------------------------------------------
// Address: 0x0056D030
// Name: public: void mxListBox::remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListBox::remove(mxListBox *this, WPARAM index)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x182u, wParam: index, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056D050
// Name: public: void mxListBox::removeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListBox::removeAll(mxListBox *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x184u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056D070
// Name: public: int mxListBox::getItemCount(void)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall mxListBox::getItemCount(mxListBox *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return SendMessageA(hWnd: Handle, Msg: 0x18Bu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056D090
// Name: public: int mxListBox::getSelectedIndex(void)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall mxListBox::getSelectedIndex(mxListBox *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return SendMessageA(hWnd: Handle, Msg: 0x188u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056D0B0
// Name: public: char const __near * mxListBox::getItemText(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall mxListBox::getItemText(mxListBox *this, WPARAM index)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x189u, wParam: index, lParam: (LPARAM)text);
  return text;
}
