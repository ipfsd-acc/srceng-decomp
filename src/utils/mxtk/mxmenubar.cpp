// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxmenubar.cpp
// Functions: 2
// ============================================================

#include "utils\mxtk\mxmenubar.h"

//------------------------------------------------------------------------------
// Address: 0x004C42D0
// Name: public: mxMenuBar::mxMenuBar(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
mxMenuBar *__thiscall mxMenuBar::mxMenuBar(mxMenuBar *this, mxWindow *parent)
{
  HMENU Menu; // edi
  HWND__ *Handle; // eax

  mxWidget::mxWidget(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: nullptr);
  this->__vftable = (mxMenuBar_vtbl *)&mxMenuBar::`vftable';
  Menu = CreateMenu();
  mxWidget::setHandle(this, handle: (HWND__ *)Menu);
  mxWidget::setType(this, type: 10);
  mxWidget::setParent(this, parentWindow: parent);
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    SetMenu(hWnd: Handle, hMenu: Menu);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C4350
// Name: public: void mxMenuBar::modify(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenuBar::modify(mxMenuBar *this, UINT id, UINT_PTR newId, const char *newItem)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  ModifyMenuA(hMnu: (HMENU)Handle, uPosition: id, uFlags: 0, uIDNewItem: newId, lpNewItem: newItem);
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056F570
// Name: public: mxMenuBar::mxMenuBar(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
mxMenuBar *__thiscall mxMenuBar::mxMenuBar(mxMenuBar *this, mxWindow *parent)
{
  HMENU Menu; // edi
  HWND__ *Handle; // eax

  mxWidget::mxWidget(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: nullptr);
  this->__vftable = (mxMenuBar_vtbl *)&mxMenuBar::`vftable';
  Menu = CreateMenu();
  mxWidget::setHandle(this, handle: (HWND__ *)Menu);
  mxWidget::setType(this, type: 10);
  mxWidget::setParent(this, parentWindow: parent);
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    SetMenu(hWnd: Handle, hMenu: Menu);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056F600
// Name: public: void mxMenuBar::modify(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenuBar::modify(mxMenuBar *this, UINT id, UINT_PTR newId, const char *newItem)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  ModifyMenuA(hMnu: (HMENU)Handle, uPosition: id, uFlags: 0, uIDNewItem: newId, lpNewItem: newItem);
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042B810
// Name: public: mxMenuBar::mxMenuBar(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
mxMenuBar *__thiscall mxMenuBar::mxMenuBar(mxMenuBar *this, mxWindow *parent)
{
  HMENU Menu; // edi
  HWND__ *Handle; // eax

  mxWidget::mxWidget(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: nullptr);
  this->__vftable = (mxMenuBar_vtbl *)&mxMenuBar::`vftable';
  Menu = CreateMenu();
  mxWidget::setHandle(this, handle: (HWND__ *)Menu);
  mxWidget::setType(this, type: 10);
  mxWidget::setParent(this, parentWindow: parent);
  if ( parent != nullptr )
  {
    Handle = mxWidget::getHandle(this: parent);
    SetMenu(hWnd: Handle, hMenu: Menu);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B870
// Name: public: void mxMenuBar::setEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenuBar::setEnabled(mxMenuBar *this, UINT id, bool b)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  EnableMenuItem(hMenu: (HMENU)Handle, uIDEnableItem: id, uEnable: !b);
}

//------------------------------------------------------------------------------
// Address: 0x0042B890
// Name: public: void mxMenuBar::modify(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMenuBar::modify(mxMenuBar *this, UINT id, UINT_PTR newId, const char *newItem)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  ModifyMenuA(hMnu: (HMENU)Handle, uPosition: id, uFlags: 0, uIDNewItem: newId, lpNewItem: newItem);
}

} // namespace scenemanager
