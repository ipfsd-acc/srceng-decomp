// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/mxexpressiontab.cpp
// Functions: 1
// ============================================================

#include "utils\hlfaceposer\mxexpressiontab.h"

//------------------------------------------------------------------------------
// Address: 0x004662B0
// Name: public: virtual void mxExpressionTab::ShowRightClickMenu(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionTab::ShowRightClickMenu(mxExpressionTab *this, int mx, int my)
{
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // esi
  HWND Handle; // eax
  HWND v7; // eax
  tagPOINT pt; // [esp+4h] [ebp-8h] BYREF

  if ( g_MDLViewer != nullptr )
  {
    v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v4 != nullptr )
      v5 = mxPopupMenu::mxPopupMenu(this: v4);
    else
      v5 = nullptr;
    mxPopupMenu::add(this: v5, item: "New...", id: 1026);
    mxMenu::addSeparator(this: v5);
    mxPopupMenu::add(this: v5, item: "Load...", id: 1021);
    mxPopupMenu::add(this: v5, item: "Save", id: 1020);
    mxMenu::addSeparator(this: v5);
    mxPopupMenu::add(this: v5, item: "Export to VFE", id: 1023);
    mxMenu::addSeparator(this: v5);
    if ( this->m_nSelected != -1 )
      mxPopupMenu::add(this: v5, item: "Close class", id: 1024);
    mxPopupMenu::add(this: v5, item: "Close all classes", id: 1025);
    mxMenu::addSeparator(this: v5);
    mxPopupMenu::add(this: v5, item: "Recreate all bitmaps", id: 1027);
    pt.y = my;
    pt.x = mx;
    Handle = (HWND)mxWidget::getHandle(this);
    ClientToScreen(hWnd: Handle, lpPoint: &pt);
    v7 = (HWND)mxWidget::getHandle(this: g_MDLViewer);
    ScreenToClient(hWnd: v7, lpPoint: &pt);
    mxPopupMenu::popup(this: v5, widget: g_MDLViewer, x: pt.x, y: pt.y);
  }
}
