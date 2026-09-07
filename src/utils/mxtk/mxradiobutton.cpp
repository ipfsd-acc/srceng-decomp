// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxradiobutton.cpp
// Functions: 3
// ============================================================

#include "utils\mxtk\mxradiobutton.h"

//------------------------------------------------------------------------------
// Address: 0x0056D3B0
// Name: public: void mxRadioButton::setChecked(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxRadioButton::setChecked(mxRadioButton *this, bool b)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0xF1u, wParam: b, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056D3E0
// Name: public: bool mxRadioButton::isChecked(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall mxRadioButton::isChecked(mxRadioButton *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return SendMessageA(hWnd: Handle, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x0056D900
// Name: public: mxRadioButton::mxRadioButton(class mxWindow __near *,int,int,int,int,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
mxRadioButton *__thiscall mxRadioButton::mxRadioButton(
        mxRadioButton *this,
        HWND__ *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        HMENU id,
        bool newGroup)
{
  DWORD v11; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax
  HWND__ *Handle; // eax
  HWND hwndParent; // [esp+10h] [ebp+8h]

  mxWidget::mxWidget(this, (mxWindow *)parent, x, y, w, h, label);
  this->__vftable = (mxRadioButton_vtbl *)&mxRadioButton::`vftable';
  if ( parent != nullptr )
  {
    v11 = 1342177289;
    hwndParent = mxWidget::getHandle(this: (mxWidget *)parent);
    if ( newGroup )
      v11 = 1342308361;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "BUTTON",
               lpWindowName: label,
               dwStyle: v11,
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
    mxWidget::setType(this, type: 13);
    mxWidget::setParent(this, parentWindow: (mxWindow *)parent);
    mxWidget::setId(this, (LONG)id);
    Handle = mxWidget::getHandle(this);
    SendMessageA(hWnd: Handle, Msg: 0xF1u, wParam: newGroup, lParam: 0);
  }
  return this;
}
