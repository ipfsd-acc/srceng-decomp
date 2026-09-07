// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxmenu.cpp
// Functions: 6
// ============================================================

#include "utils\mxtk\mxmenu.h"

//------------------------------------------------------------------------------
// Address: 0x004C1B50
// Name: public: void mxMenu::addMenu(char const __near *,class mxMenu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::addMenu(mxPopupMenu *this, const char *item, mxPopupMenu *menu)
{
  HWND__ *v4; // eax
  HWND__ *Handle; // [esp-8h] [ebp-Ch]

  Handle = mxWidget::getHandle(this: menu);
  v4 = mxWidget::getHandle(this);
  AppendMenuA(hMenu: (HMENU)v4, uFlags: 0x10u, uIDNewItem: (UINT_PTR)Handle, lpNewItem: item);
}

//------------------------------------------------------------------------------
// Address: 0x004C1B80
// Name: public: void mxMenu::addSeparator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::addSeparator(mxPopupMenu *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  AppendMenuA(hMenu: (HMENU)Handle, uFlags: 0x800u, uIDNewItem: 0, lpNewItem: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C1BA0
// Name: public: void mxMenu::setChecked(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::setChecked(mxPopupMenu *this, UINT id, bool b)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  CheckMenuItem(hMenu: (HMENU)Handle, uIDCheckItem: id, uCheck: b ? 8 : 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C4330
// Name: public: void mxMenu::setEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::setEnabled(mxMenuBar *this, UINT id, bool b)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  EnableMenuItem(hMenu: (HMENU)Handle, uIDEnableItem: id, uEnable: !b);
}

//------------------------------------------------------------------------------
// Address: 0x004C43B0
// Name: public: mxMenu::mxMenu(void)
// Source: json
//------------------------------------------------------------------------------
mxMenu *__thiscall mxMenu::mxMenu(mxMenu *this)
{
  HMENU Menu; // eax

  mxWidget::mxWidget(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: nullptr);
  this->__vftable = (mxMenu_vtbl *)&mxMenu::`vftable';
  Menu = CreateMenu();
  mxWidget::setHandle(this, handle: (HWND__ *)Menu);
  mxWidget::setType(this, type: 9);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C43F0
// Name: public: bool mxMenu::isChecked(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall mxMenu::isChecked(mxMenu *this, UINT id)
{
  HWND__ *Handle; // eax
  tagMENUITEMINFOA mii; // [esp+4h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)&mii, value: 0, count: sizeof(mii));
  mii.cbSize = 48;
  mii.fMask = 1;
  Handle = mxWidget::getHandle(this);
  GetMenuItemInfoA(hmenu: (HMENU)Handle, item: id, fByPosition: false, lpmii: &mii);
  return (mii.fState & 8) != 0;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056F5D0
// Name: public: void mxMenu::addMenu(char const __near *,class mxMenu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::addMenu(mxMenuBar *this, const char *item, mxMenu *menu)
{
  HWND__ *v4; // eax
  HWND__ *Handle; // [esp-8h] [ebp-Ch]

  Handle = mxWidget::getHandle(this: menu);
  v4 = mxWidget::getHandle(this);
  AppendMenuA(hMenu: (HMENU)v4, uFlags: 0x10u, uIDNewItem: (UINT_PTR)Handle, lpNewItem: item);
}

//------------------------------------------------------------------------------
// Address: 0x0056FA70
// Name: public: mxMenu::mxMenu(void)
// Source: json
//------------------------------------------------------------------------------
mxMenu *__thiscall mxMenu::mxMenu(mxMenu *this)
{
  HMENU Menu; // eax

  mxWidget::mxWidget(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: nullptr);
  this->__vftable = (mxMenu_vtbl *)&mxMenu::`vftable';
  Menu = CreateMenu();
  mxWidget::setHandle(this, handle: (HWND__ *)Menu);
  mxWidget::setType(this, type: 9);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056FAB0
// Name: public: void mxMenu::add(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::add(mxMenu *this, const char *item, UINT_PTR id)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  AppendMenuA(hMenu: (HMENU)Handle, uFlags: 0, uIDNewItem: id, lpNewItem: item);
}

//------------------------------------------------------------------------------
// Address: 0x0056FAD0
// Name: public: void mxMenu::addSeparator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::addSeparator(mxMenu *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  AppendMenuA(hMenu: (HMENU)Handle, uFlags: 0x800u, uIDNewItem: 0, lpNewItem: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0056FAF0
// Name: public: void mxMenu::setEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::setEnabled(mxMenuBar *this, UINT id, bool b)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  EnableMenuItem(hMenu: (HMENU)Handle, uIDEnableItem: id, uEnable: !b);
}

//------------------------------------------------------------------------------
// Address: 0x0056FB10
// Name: public: void mxMenu::setChecked(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::setChecked(mxMenu *this, UINT id, bool b)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  CheckMenuItem(hMenu: (HMENU)Handle, uIDCheckItem: id, uCheck: b ? 8 : 0);
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042B720
// Name: public: mxMenu::mxMenu(void)
// Source: json
//------------------------------------------------------------------------------
mxMenu *__thiscall mxMenu::mxMenu(mxMenu *this)
{
  HMENU Menu; // eax

  mxWidget::mxWidget(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: nullptr);
  this->__vftable = (mxMenu_vtbl *)&mxMenu::`vftable';
  Menu = CreateMenu();
  mxWidget::setHandle(this, handle: (HWND__ *)Menu);
  mxWidget::setType(this, type: 9);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B760
// Name: public: void mxMenu::addMenu(char const __near *,class mxMenu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::addMenu(mxMenuBar *this, const char *item, mxMenu *menu)
{
  HWND__ *v4; // eax
  HWND__ *Handle; // [esp-8h] [ebp-Ch]

  Handle = mxWidget::getHandle(this: menu);
  v4 = mxWidget::getHandle(this);
  AppendMenuA(hMenu: (HMENU)v4, uFlags: 0x10u, uIDNewItem: (UINT_PTR)Handle, lpNewItem: item);
}

//------------------------------------------------------------------------------
// Address: 0x0042B790
// Name: public: void mxMenu::addSeparator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::addSeparator(mxPopupMenu *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  AppendMenuA(hMenu: (HMENU)Handle, uFlags: 0x800u, uIDNewItem: 0, lpNewItem: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042B7B0
// Name: public: void mxMenu::setChecked(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenu::setChecked(mxMenu *this, UINT id, bool b)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  CheckMenuItem(hMenu: (HMENU)Handle, uIDCheckItem: id, uCheck: b ? 8 : 0);
}

} // namespace scenemanager
