// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxpopupmenu.cpp
// Functions: 3
// ============================================================

#include "utils\mxtk\mxpopupmenu.h"

//------------------------------------------------------------------------------
// Address: 0x004C1A90
// Name: public: mxPopupMenu::mxPopupMenu(void)
// Source: json
//------------------------------------------------------------------------------
mxPopupMenu *__thiscall mxPopupMenu::mxPopupMenu(mxPopupMenu *this)
{
  HMENU PopupMenu; // eax

  mxWidget::mxWidget(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: nullptr);
  this->__vftable = (mxPopupMenu_vtbl *)&mxPopupMenu::`vftable';
  PopupMenu = CreatePopupMenu();
  mxWidget::setHandle(this, handle: (HWND__ *)PopupMenu);
  mxWidget::setType(this, type: 11);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1AD0
// Name: public: int mxPopupMenu::popup(class mxWidget __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall mxPopupMenu::popup(mxPopupMenu *this, mxWidget *widget, int x, int y)
{
  HWND__ *Handle; // eax
  HWND__ *v6; // eax
  HWND__ *v8; // [esp-8h] [ebp-18h]
  tagPOINT pt; // [esp+8h] [ebp-8h] BYREF
  tagPOINT v10; // 0:^8.8

  pt.y = y;
  pt.x = x;
  Handle = mxWidget::getHandle(this: widget);
  ClientToScreen(hWnd: Handle, lpPoint: &pt);
  v8 = mxWidget::getHandle(this: widget);
  v10 = pt;
  v6 = mxWidget::getHandle(this);
  return TrackPopupMenu(hMenu: (HMENU)v6, uFlags: 0, x: v10.x, y: v10.y, nReserved: 0, hWnd: v8, prcRect: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C1B30
// Name: public: void mxPopupMenu::add(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxPopupMenu::add(mxPopupMenu *this, const char *item, UINT_PTR id)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  AppendMenuA(hMenu: (HMENU)Handle, uFlags: 0, uIDNewItem: id, lpNewItem: item);
}

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042B330
// Name: public: mxPopupMenu::mxPopupMenu(void)
// Source: json
//------------------------------------------------------------------------------
mxPopupMenu *__thiscall mxPopupMenu::mxPopupMenu(mxPopupMenu *this)
{
  HMENU PopupMenu; // eax

  mxWidget::mxWidget(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: nullptr);
  this->__vftable = (mxPopupMenu_vtbl *)&mxPopupMenu::`vftable';
  PopupMenu = CreatePopupMenu();
  mxWidget::setHandle(this, handle: (HWND__ *)PopupMenu);
  mxWidget::setType(this, type: 11);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B370
// Name: public: int mxPopupMenu::popup(class mxWidget __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall mxPopupMenu::popup(mxPopupMenu *this, mxWidget *widget, int x, int y)
{
  HWND__ *Handle; // eax
  HWND__ *v6; // eax
  HWND__ *v8; // [esp-8h] [ebp-18h]
  tagPOINT pt; // [esp+8h] [ebp-8h] BYREF
  tagPOINT v10; // 0:^8.8

  pt.y = y;
  pt.x = x;
  Handle = mxWidget::getHandle(this: widget);
  ClientToScreen(hWnd: Handle, lpPoint: &pt);
  v8 = mxWidget::getHandle(this: widget);
  v10 = pt;
  v6 = mxWidget::getHandle(this);
  return TrackPopupMenu(hMenu: (HMENU)v6, uFlags: 0, x: v10.x, y: v10.y, nReserved: 0, hWnd: v8, prcRect: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042B3D0
// Name: public: void mxPopupMenu::add(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxPopupMenu::add(mxPopupMenu *this, const char *item, UINT_PTR id)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  AppendMenuA(hMenu: (HMENU)Handle, uFlags: 0, uIDNewItem: id, lpNewItem: item);
}

} // namespace scenemanager
