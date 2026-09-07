// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/mission_editor/theme_room_picker.cpp
// Functions: 9
// ============================================================

#include "missionchooser\vgui\mission_editor\theme_room_picker.h"

//------------------------------------------------------------------------------
// Address: 0x10011E20
// Name: public: static char const __near * CThemeRoomPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CThemeRoomPicker::GetPanelClassName()
{
  return "CThemeRoomPicker";
}

//------------------------------------------------------------------------------
// Address: 0x10011E30
// Name: public: virtual void CThemeRoomPicker::PopulateThemeList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeRoomPicker::PopulateThemeList(CThemeRoomPicker *this)
{
  vgui::Label_vtbl *v2; // edx

  CThemesDialog::PopulateThemeList(this);
  v2 = this->m_pCurrentThemeLabel->CThemesDialog::__vftable;
  if ( this->m_pSelectedTheme != nullptr )
    ((void (__stdcall *)(CLevelTheme *))v2->SetText)(a1: this->m_pSelectedTheme);
  else
    ((void (__stdcall *)(const char *))v2->SetText)(a1: "None");
}

//------------------------------------------------------------------------------
// Address: 0x10011E70
// Name: public: virtual void CThemeRoomPicker::ThemeClicked(class CThemeDetails __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeRoomPicker::ThemeClicked(CThemeRoomPicker *this, CThemeDetails *pThemeDetails)
{
  CLevelTheme *m_pTheme; // eax
  vgui::Label *m_pCurrentThemeLabel; // ecx
  vgui::PanelListPanel *m_pThemePanelList; // ecx
  int v6; // edi
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // esi
  int iPanels; // [esp+Ch] [ebp+8h]

  m_pTheme = pThemeDetails->m_pTheme;
  m_pCurrentThemeLabel = this->m_pCurrentThemeLabel;
  this->m_pSelectedTheme = m_pTheme;
  m_pCurrentThemeLabel->SetText(this: m_pCurrentThemeLabel, a2: m_pTheme->m_szName);
  m_pThemePanelList = this->m_pThemePanelList;
  if ( m_pThemePanelList != nullptr )
  {
    v6 = 0;
    iPanels = vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)m_pThemePanelList);
    if ( iPanels > 0 )
    {
      do
      {
        v7 = this->m_pThemePanelList->GetItemPanel(this: this->m_pThemePanelList, a2: v6);
        v8 = v7;
        if ( v7 != nullptr )
        {
          v7->InvalidateLayout(this: v7, a2: false, a3: false);
          v8->OnThink(this: v8);
        }
        ++v6;
      }
      while ( v6 < iPanels );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011EF0
// Name: public: virtual bool CThemeRoomPicker::ShouldHighlight(class CThemeDetails __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThemeRoomPicker::ShouldHighlight(CThemeRoomPicker *this, CThemeDetails *pDetails)
{
  return pDetails != nullptr && pDetails->m_pTheme == this->m_pSelectedTheme;
}

//------------------------------------------------------------------------------
// Address: 0x10011F20
// Name: public: virtual void CThemeRoomPicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeRoomPicker::OnCommand(CThemeRoomPicker *this, const char *command)
{
  KeyValues *m_pKey; // ecx
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( _V_stricmp(s1: command, s2: "Okay") != 0 )
  {
    CThemesDialog::OnCommand(this, command);
  }
  else
  {
    if ( this->m_pSelectedTheme != nullptr )
    {
      m_pKey = this->m_pKey;
      if ( m_pKey != nullptr )
      {
        KeyValues::SetStringValue(this: m_pKey, strValue: this->m_pSelectedTheme->m_szName);
        v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v4 != nullptr )
          v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: "Update");
        else
          v5 = nullptr;
        this->PostActionSignal(this, a2: v5);
      }
    }
    this->OnClose(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011FB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CThemeRoomPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CThemeRoomPicker::GetMessageMap(CThemeRoomPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CThemeRoomPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CThemeRoomPicker::GetMessageMap'::`2'::s_pMap;
  `CThemeRoomPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CThemeRoomPicker");
  `CThemeRoomPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011FE0
// Name: public: virtual struct PanelAnimationMap __near * CThemeRoomPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CThemeRoomPicker::GetAnimMap(CThemeRoomPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CThemeRoomPicker");
}

//------------------------------------------------------------------------------
// Address: 0x10012000
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CThemeRoomPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CThemeRoomPicker::GetKBMap(CThemeRoomPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CThemeRoomPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CThemeRoomPicker::GetKBMap'::`2'::s_pMap;
  `CThemeRoomPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CThemeRoomPicker");
  `CThemeRoomPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012030
// Name: public: CThemeRoomPicker::CThemeRoomPicker(class vgui::Panel __near *,char const __near *,class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CThemeRoomPicker *__thiscall CThemeRoomPicker::CThemeRoomPicker(
        CThemeRoomPicker *this,
        vgui::Panel *parent,
        const char *name,
        KeyValues *pKey,
        bool bPickRooms)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  const char *v9; // eax
  CLevelTheme *Theme; // eax
  const char *String; // eax
  vgui::Label *m_pCurrentThemeLabel; // ecx
  char szStartRoom[260]; // [esp+8h] [ebp-184h] BYREF
  char szStartRoomTheme[128]; // [esp+10Ch] [ebp-80h] BYREF

  CThemesDialog::CThemesDialog(this, parent, name, bGlobal: false);
  this->__vftable = (CThemeRoomPicker_vtbl *)&CThemeRoomPicker::`vftable';
  if ( `CThemeRoomPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CThemeRoomPicker::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CThemeRoomPicker");
    v6->pfnClassName = CThemeRoomPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "CThemesDialog");
  }
  if ( `CThemeRoomPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CThemeRoomPicker::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CThemeRoomPicker");
    v7->pfnClassName = CThemeRoomPicker::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "CThemesDialog");
  }
  if ( `CThemeRoomPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CThemeRoomPicker::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CThemeRoomPicker");
    v8->pfnClassName = CThemeRoomPicker::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CThemesDialog");
  }
  this->m_pKey = pKey;
  this->m_bPickRooms = bPickRooms;
  if ( bPickRooms )
  {
    String = KeyValues::GetString(this: pKey, keyName: nullptr, defaultValue: szDescription);
    if ( CLevelTheme::SplitThemeAndRoom(
           pszFullName: String,
           szThemeOut: szStartRoomTheme,
           nThemeOutSize: 128,
           szRoomOut: szStartRoom,
           nRoomOutSize: 260) != 0 )
    {
      vgui::Frame::LoadControlSettings(
        this,
        dialogResourceName: "RoomPicker.res",
        pathID: nullptr,
        pPreloadedKeyValues: nullptr,
        pConditions: nullptr);
    }
    else
    {
      m_pCurrentThemeLabel = this->m_pCurrentThemeLabel;
      this->m_pSelectedTheme = nullptr;
      m_pCurrentThemeLabel->SetText(this: m_pCurrentThemeLabel, a2: "Unknown theme");
    }
    return this;
  }
  else
  {
    v9 = KeyValues::GetString(this: pKey, keyName: nullptr, defaultValue: szDescription);
    Theme = CLevelTheme::FindTheme(szThemeName: v9);
    this->m_pSelectedTheme = Theme;
    if ( Theme == nullptr )
      Theme = (CLevelTheme *)"Unknown theme";
    this->m_pCurrentThemeLabel->SetText(this: this->m_pCurrentThemeLabel, a2: (const char *)Theme);
    vgui::Frame::LoadControlSettings(
      this,
      dialogResourceName: "ThemePicker.res",
      pathID: nullptr,
      pPreloadedKeyValues: nullptr,
      pConditions: nullptr);
    return this;
  }
}
