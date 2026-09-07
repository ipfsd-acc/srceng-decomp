// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxtooltip.cpp
// Functions: 1
// ============================================================

#include "utils\mxtk\mxtooltip.h"

//------------------------------------------------------------------------------
// Address: 0x004C25E0
// Name: public: static void mxToolTip::add(class mxWidget __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mxToolTip::add(mxWidget *widget, char *text)
{
  HWND ToolTipControl; // eax
  tagTOOLINFOA ti; // [esp+4h] [ebp-30h] BYREF

  if ( widget != nullptr )
  {
    memset(dst: (unsigned __int8 *)&ti, value: 0, count: sizeof(ti));
    ti.cbSize = 48;
    ti.uFlags = 17;
    ti.uId = (unsigned int)mxWidget::getHandle(this: widget);
    ti.lpszText = text;
    ToolTipControl = mx_CreateToolTipControl();
    SendMessageA(hWnd: ToolTipControl, Msg: 0x404u, wParam: 0, lParam: (LPARAM)&ti);
  }
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056CEA0
// Name: public: static void mxToolTip::add(class mxWidget __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl mxToolTip::add(mxWidget *widget, char *text)
{
  HWND ToolTipControl; // eax
  tagTOOLINFOA ti; // [esp+4h] [ebp-30h] BYREF

  if ( widget != nullptr )
  {
    memset(dst: (unsigned __int8 *)&ti, value: 0, count: sizeof(ti));
    ti.cbSize = 48;
    ti.uFlags = 17;
    ti.uId = (unsigned int)mxWidget::getHandle(this: widget);
    ti.lpszText = text;
    ToolTipControl = mx_CreateToolTipControl();
    SendMessageA(hWnd: ToolTipControl, Msg: 0x404u, wParam: 0, lParam: (LPARAM)&ti);
  }
}

} // namespace hlmv
