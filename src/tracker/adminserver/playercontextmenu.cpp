// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/playercontextmenu.cpp
// Functions: 1
// ============================================================

#include "tracker\adminserver\playercontextmenu.h"

//------------------------------------------------------------------------------
// Address: 0x10003130
// Name: public: CPlayerContextMenu::CPlayerContextMenu(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CPlayerContextMenu *__thiscall CPlayerContextMenu::CPlayerContextMenu(CPlayerContextMenu *this, vgui::Panel *parent)
{
  vgui::Menu::Menu(this, parent, panelName: "ServerContextMenu");
  this->parent = parent;
  this->__vftable = (CPlayerContextMenu_vtbl *)&CPlayerContextMenu::`vftable';
  return this;
}
