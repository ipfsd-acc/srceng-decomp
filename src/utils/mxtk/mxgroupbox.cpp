// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxgroupbox.cpp
// Functions: 1
// ============================================================

#include "utils\mxtk\mxgroupbox.h"

//------------------------------------------------------------------------------
// Address: 0x0056F670
// Name: public: mxGroupBox::mxGroupBox(class mxWindow __near *,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxGroupBox *__thiscall mxGroupBox::mxGroupBox(
        mxGroupBox *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label)
{
  HWND__ *Handle; // ebx
  HMODULE ModuleHandleA; // eax
  HWND Window; // ebx
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxGroupBox_vtbl *)&mxGroupBox::`vftable';
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "BUTTON",
               lpWindowName: label,
               dwStyle: 0x50000007u,
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
    mxWidget::setType(this, type: 5);
    mxWidget::setParent(this, parentWindow: parent);
  }
  return this;
}
