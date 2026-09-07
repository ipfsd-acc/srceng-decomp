// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/bancontextmenu.cpp
// Functions: 10
// ============================================================

#include "tracker\adminserver\bancontextmenu.h"

//------------------------------------------------------------------------------
// Address: 0x100013E0
// Name: public: CBanContextMenu::CBanContextMenu(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBanContextMenu *__thiscall CBanContextMenu::CBanContextMenu(CBanContextMenu *this, vgui::Panel *parent)
{
  vgui::Menu::Menu(this, parent, panelName: "BanContextMenu");
  this->parent = parent;
  this->__vftable = (CBanContextMenu_vtbl *)&CBanContextMenu::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001420
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        vgui::Panel *this,
        const char *elementName,
        const char *x,
        int *y,
        int *wide,
        int *tall)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001430
// Name: public: virtual unsigned long vgui::Panel::GetDragFailCursor(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Panel::GetDragFailCursor(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10001450
// Name: public: static char const __near * vgui::Menu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Menu::GetPanelClassName()
{
  return "Menu";
}

//------------------------------------------------------------------------------
// Address: 0x10001460
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001470
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Menu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Menu::GetMessageMap(vgui::Menu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Menu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Menu::GetMessageMap'::`2'::s_pMap;
  `vgui::Menu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Menu");
  `vgui::Menu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100014A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Menu::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Menu::GetAnimMap(vgui::Menu *this)
{
  return FindOrAddPanelAnimationMap(className: "Menu");
}

//------------------------------------------------------------------------------
// Address: 0x100014B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Menu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Menu::GetKBMap(vgui::Menu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Menu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Menu::GetKBMap'::`2'::s_pMap;
  `vgui::Menu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Menu");
  `vgui::Menu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016660
// Name: private: class vgui::MenuItem __near * vgui::Menu::GetParentMenuItem(void)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall vgui::Menu::GetParentMenuItem(vgui::Menu *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  return (vgui::MenuItem *)__RTDynamicCast(
                             inptr: v1,
                             VfDelta: 0,
                             SrcType: &vgui::Panel `RTTI Type Descriptor',
                             TargetType: &vgui::MenuItem `RTTI Type Descriptor',
                             isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10017090
// Name: public: class vgui::MenuItem __near * vgui::Menu::GetMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuItem *__thiscall vgui::Menu::GetMenuItem(vgui::Menu *this, int itemID)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_MenuItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_MenuItems.m_LastAlloc.index
    && ((m_pMemory = this->m_MenuItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element;
  }
  else
  {
    return nullptr;
  }
}
