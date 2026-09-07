// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/servercontextmenu.cpp
// Functions: 8
// ============================================================

#include "serverbrowser\servercontextmenu.h"

//------------------------------------------------------------------------------
// Address: 0x10016C60
// Name: public: CServerContextMenu::CServerContextMenu(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CServerContextMenu *__thiscall CServerContextMenu::CServerContextMenu(CServerContextMenu *this, vgui::Panel *parent)
{
  vgui::Menu::Menu(this, parent, panelName: "ServerContextMenu");
  this->__vftable = (CServerContextMenu_vtbl *)&CServerContextMenu::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016C90
// Name: public: static char const __near * vgui::Menu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Menu::GetPanelClassName()
{
  return "Menu";
}

//------------------------------------------------------------------------------
// Address: 0x10016CA0
// Name: public: void CServerContextMenu::ShowMenu(class vgui::Panel __near *,unsigned int,bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerContextMenu::ShowMenu(
        CServerContextMenu *this,
        vgui::Panel *target,
        int serverID,
        int showConnect,
        bool showViewGameInfo,
        bool showRefresh,
        bool showAddToFavorites)
{
  int v7; // ebx
  vgui::Panel *v8; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IPanel *v20; // edi
  vgui::IPanel_vtbl *v21; // ebx
  int v22; // eax
  int gx; // [esp+Ch] [ebp-4h] BYREF

  v7 = serverID;
  v8 = target;
  if ( (_BYTE)showConnect != 0 )
  {
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "ConnectToServer", firstKey: "serverID", firstValue: v7);
    else
      v11 = nullptr;
    this->AddMenuItem(this, a2: "ConnectToServer", a3: "#ServerBrowser_ConnectToServer", a4: v11, a5: v8, a6: nullptr);
  }
  if ( showViewGameInfo )
  {
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
      v13 = KeyValues::KeyValues(this: v12, setName: "ViewGameInfo", firstKey: "serverID", firstValue: v7);
    else
      v13 = nullptr;
    this->AddMenuItem(this, a2: "ViewGameInfo", a3: "#ServerBrowser_ViewServerInfo", a4: v13, a5: v8, a6: nullptr);
  }
  if ( showRefresh )
  {
    v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v14 != nullptr )
      v15 = KeyValues::KeyValues(this: v14, setName: "RefreshServer", firstKey: "serverID", firstValue: v7);
    else
      v15 = nullptr;
    this->AddMenuItem(this, a2: "RefreshServer", a3: "#ServerBrowser_RefreshServer", a4: v15, a5: v8, a6: nullptr);
  }
  if ( showAddToFavorites )
  {
    v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v16 != nullptr )
      v17 = KeyValues::KeyValues(this: v16, setName: "AddToFavorites", firstKey: "serverID", firstValue: v7);
    else
      v17 = nullptr;
    this->AddMenuItem(
      this,
      a2: "AddToFavorites",
      a3: "#ServerBrowser_AddServerToFavorites",
      a4: v17,
      a5: v8,
      a6: nullptr);
    v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v18 != nullptr )
      v19 = KeyValues::KeyValues(this: v18, setName: "AddToBlacklist", firstKey: "serverID", firstValue: v7);
    else
      v19 = nullptr;
    this->AddMenuItem(
      this,
      a2: "AddToBlacklist",
      a3: "#ServerBrowser_AddServerToBlacklist",
      a4: v19,
      a5: v8,
      a6: nullptr);
  }
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: (int *)&target, a3: &showConnect);
  v20 = g_pVGuiPanel;
  v21 = g_pVGuiPanel->__vftable;
  v22 = ((int (__thiscall *)(vgui::ISurface *, int *, int *))g_pVGuiSurface->GetEmbeddedPanel)(
          a1: g_pVGuiSurface,
          a2: &gx,
          a3: &serverID);
  ((void (__thiscall *)(vgui::IPanel *, int))v21->GetPos)(a1: v20, a2: v22);
  vgui::Panel::SetPos(this, x: (int)target - gx, y: showConnect - serverID);
  this->SetVisible(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10016E70
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
// Address: 0x10016EA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Menu::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Menu::GetAnimMap(vgui::Menu *this)
{
  return FindOrAddPanelAnimationMap(className: "Menu");
}

//------------------------------------------------------------------------------
// Address: 0x10016EB0
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
// Address: 0x10058E30
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
// Address: 0x10059770
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
