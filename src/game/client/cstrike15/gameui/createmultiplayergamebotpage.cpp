// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/createmultiplayergamebotpage.cpp
// Functions: 8
// ============================================================

#include "game\client\cstrike15\gameui\createmultiplayergamebotpage.h"

//------------------------------------------------------------------------------
// Address: 0x101D1910
// Name: public: static char const __near * CCreateMultiplayerGameBotPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCreateMultiplayerGameBotPage::GetPanelClassName()
{
  return "CCreateMultiplayerGameBotPage";
}

//------------------------------------------------------------------------------
// Address: 0x101D1920
// Name: private: void CCreateMultiplayerGameBotPage::SetJoinTeamCombo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameBotPage::SetJoinTeamCombo(CCreateMultiplayerGameBotPage *this, const char *team)
{
  int v3; // esi
  const char **v4; // eax

  if ( team != nullptr )
  {
    v3 = 0;
    if ( joinTeamArg[0] != nullptr )
    {
      v4 = joinTeamArg;
      while ( _V_stricmp(s1: team, s2: *v4) != 0 )
      {
        v4 = &joinTeamArg[++v3];
        if ( *v4 == nullptr )
          return;
      }
      vgui::ComboBox::ActivateItemByRow(this: this->m_joinTeamCombo, row: v3);
    }
  }
  else
  {
    vgui::ComboBox::ActivateItemByRow(this: this->m_joinTeamCombo, row: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1990
// Name: private: void CCreateMultiplayerGameBotPage::SetChatterCombo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameBotPage::SetChatterCombo(
        CCreateMultiplayerGameBotPage *this,
        const char *chatter)
{
  int v3; // esi
  const char **v4; // eax

  if ( chatter != nullptr )
  {
    v3 = 0;
    if ( chatterArg[0] != nullptr )
    {
      v4 = chatterArg;
      while ( _V_stricmp(s1: chatter, s2: *v4) != 0 )
      {
        v4 = &chatterArg[++v3];
        if ( *v4 == nullptr )
          return;
      }
      vgui::ComboBox::ActivateItemByRow(this: this->m_chatterCombo, row: v3);
    }
  }
  else
  {
    vgui::ComboBox::ActivateItemByRow(this: this->m_joinTeamCombo, row: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1A00
// Name: protected: virtual void CCreateMultiplayerGameBotPage::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameBotPage::OnApplyChanges(CCreateMultiplayerGameBotPage *this)
{
  int v2; // edi
  int v3; // edi
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  char *v12; // edi
  char *v13; // edi
  char entryBuffer[256]; // [esp+8h] [ebp-108h] BYREF
  ConVarRef v15; // [esp+108h] [ebp-8h] BYREF

  v2 = this->m_joinAfterPlayer->IsSelected(this: this->m_joinAfterPlayer);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_join_after_player", value: v2);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_join_after_player");
  v15.m_pConVar->SetValue_2(this: v15.m_pConVar, a2: v2);
  v3 = this->m_allowRogues->IsSelected(this: this->m_allowRogues);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_allow_rogues", value: v3);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_allow_rogues");
  v15.m_pConVar->SetValue_2(this: v15.m_pConVar, a2: v3);
  v4 = this->m_allowPistols->IsSelected(this: this->m_allowPistols);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_allow_pistols", value: v4);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_allow_pistols");
  v15.m_pConVar->SetValue_2(this: v15.m_pConVar, a2: v4);
  v5 = this->m_allowShotguns->IsSelected(this: this->m_allowShotguns);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_allow_shotguns", value: v5);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_allow_shotguns");
  v15.m_pConVar->SetValue_2(this: v15.m_pConVar, a2: v5);
  v6 = this->m_allowSubmachineGuns->IsSelected(this: this->m_allowSubmachineGuns);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_allow_sub_machine_guns", value: v6);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_allow_sub_machine_guns");
  v15.m_pConVar->SetValue_2(this: v15.m_pConVar, a2: v6);
  v7 = this->m_allowMachineGuns->IsSelected(this: this->m_allowMachineGuns);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_allow_machine_guns", value: v7);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_allow_machine_guns");
  v15.m_pConVar->SetValue_2(this: v15.m_pConVar, a2: v7);
  v8 = this->m_allowRifles->IsSelected(this: this->m_allowRifles);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_allow_rifles", value: v8);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_allow_rifles");
  v15.m_pConVar->SetValue_2(this: v15.m_pConVar, a2: v8);
  v9 = this->m_allowSnipers->IsSelected(this: this->m_allowSnipers);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_allow_snipers", value: v9);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_allow_snipers");
  v15.m_pConVar->SetValue_2(this: v15.m_pConVar, a2: v9);
  v10 = this->m_allowGrenades->IsSelected(this: this->m_allowGrenades);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_allow_grenades", value: v10);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_allow_grenades");
  v15.m_pConVar->SetValue_2(this: v15.m_pConVar, a2: v10);
  v11 = this->m_deferToHuman->IsSelected(this: this->m_deferToHuman);
  KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_defer_to_human", value: v11);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_defer_to_human");
  v15.m_pConVar->SetValue_2(this: v15.m_pConVar, a2: v11);
  v12 = (char *)joinTeamArg[vgui::ComboBox::GetActiveItem(this: this->m_joinTeamCombo)];
  KeyValues::SetString(this: this->m_pSavedData, keyName: "bot_join_team", value: v12);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_join_team");
  v15.m_pConVar->SetValue_4(this: v15.m_pConVar, a2: v12);
  v13 = (char *)chatterArg[vgui::ComboBox::GetActiveItem(this: this->m_chatterCombo)];
  KeyValues::SetString(this: this->m_pSavedData, keyName: "bot_chatter", value: v13);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_chatter");
  v15.m_pConVar->SetValue_4(this: v15.m_pConVar, a2: v13);
  this->m_prefixEntry->GetText_2(this: this->m_prefixEntry, a2: entryBuffer, a3: 256);
  KeyValues::SetString(this: this->m_pSavedData, keyName: "bot_prefix", value: entryBuffer);
  ConVarRef::ConVarRef(this: &v15, pName: "bot_prefix");
  v15.m_pConVar->SetValue_4(this: v15.m_pConVar, a2: entryBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x101D1D40
// Name: public: virtual struct vgui::PanelMessageMap __near * CCreateMultiplayerGameBotPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCreateMultiplayerGameBotPage::GetMessageMap(CCreateMultiplayerGameBotPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCreateMultiplayerGameBotPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCreateMultiplayerGameBotPage::GetMessageMap'::`2'::s_pMap;
  `CCreateMultiplayerGameBotPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCreateMultiplayerGameBotPage");
  `CCreateMultiplayerGameBotPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D1D70
// Name: public: virtual struct PanelAnimationMap __near * CCreateMultiplayerGameBotPage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCreateMultiplayerGameBotPage::GetAnimMap(CCreateMultiplayerGameBotPage *this)
{
  return FindOrAddPanelAnimationMap(className: "CCreateMultiplayerGameBotPage");
}

//------------------------------------------------------------------------------
// Address: 0x101D1D80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCreateMultiplayerGameBotPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCreateMultiplayerGameBotPage::GetKBMap(CCreateMultiplayerGameBotPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCreateMultiplayerGameBotPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCreateMultiplayerGameBotPage::GetKBMap'::`2'::s_pMap;
  `CCreateMultiplayerGameBotPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCreateMultiplayerGameBotPage");
  `CCreateMultiplayerGameBotPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D1DB0
// Name: public: CCreateMultiplayerGameBotPage::CCreateMultiplayerGameBotPage(class vgui::Panel __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CCreateMultiplayerGameBotPage *__thiscall CCreateMultiplayerGameBotPage::CCreateMultiplayerGameBotPage(
        CCreateMultiplayerGameBotPage *this,
        vgui::Panel *parent,
        const char *name,
        KeyValues *botKeys)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CCvarToggleCheckButton *v8; // eax
  CCvarToggleCheckButton *v9; // eax
  CCvarToggleCheckButton *v10; // eax
  CCvarToggleCheckButton *v11; // eax
  CCvarToggleCheckButton *v12; // eax
  CCvarToggleCheckButton *v13; // eax
  CCvarToggleCheckButton *v14; // eax
  CCvarToggleCheckButton *v15; // eax
  CCvarToggleCheckButton *v16; // eax
  CCvarToggleCheckButton *v17; // eax
  CCvarToggleCheckButton *v18; // eax
  CCvarToggleCheckButton *v19; // eax
  CCvarToggleCheckButton *v20; // eax
  CCvarToggleCheckButton *v21; // eax
  CCvarToggleCheckButton *v22; // eax
  CCvarToggleCheckButton *v23; // eax
  CCvarToggleCheckButton *v24; // eax
  CCvarToggleCheckButton *v25; // eax
  CCvarToggleCheckButton *v26; // eax
  CCvarToggleCheckButton *v27; // eax
  vgui::ComboBox *v28; // eax
  vgui::ComboBox *v29; // eax
  vgui::ComboBox *v30; // eax
  vgui::ComboBox *v31; // eax
  vgui::TextEntry *v32; // eax
  vgui::TextEntry *v33; // eax
  char *String; // eax
  char *v35; // eax
  char *v36; // eax

  vgui::PropertyPage::PropertyPage(this, parent, panelName: name);
  this->__vftable = (CCreateMultiplayerGameBotPage_vtbl *)&CCreateMultiplayerGameBotPage::`vftable';
  if ( `CCreateMultiplayerGameBotPage::ChainToMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameBotPage::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CCreateMultiplayerGameBotPage");
    v5->pfnClassName = CCreateMultiplayerGameBotPage::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `CCreateMultiplayerGameBotPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameBotPage::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CCreateMultiplayerGameBotPage");
    v6->pfnClassName = CCreateMultiplayerGameBotPage::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `CCreateMultiplayerGameBotPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameBotPage::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CCreateMultiplayerGameBotPage");
    v7->pfnClassName = CCreateMultiplayerGameBotPage::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  this->m_pSavedData = botKeys;
  v8 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v8 != nullptr )
    v9 = CCvarToggleCheckButton::CCvarToggleCheckButton(
           this: v8,
           parent: this,
           panelName: "BotAllowRogueCheck",
           text: prType,
           cvarname: "bot_allow_rogues");
  else
    v9 = nullptr;
  this->m_allowRogues = v9;
  v10 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v10 != nullptr )
    v11 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v10,
            parent: this,
            panelName: "BotAllowPistolsCheck",
            text: prType,
            cvarname: "bot_allow_pistols");
  else
    v11 = nullptr;
  this->m_allowPistols = v11;
  v12 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v12 != nullptr )
    v13 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v12,
            parent: this,
            panelName: "BotAllowShotgunsCheck",
            text: prType,
            cvarname: "bot_allow_shotguns");
  else
    v13 = nullptr;
  this->m_allowShotguns = v13;
  v14 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v14 != nullptr )
    v15 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v14,
            parent: this,
            panelName: "BotAllowSubmachineGunsCheck",
            text: prType,
            cvarname: "bot_allow_sub_machine_guns");
  else
    v15 = nullptr;
  this->m_allowSubmachineGuns = v15;
  v16 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v16 != nullptr )
    v17 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v16,
            parent: this,
            panelName: "BotAllowRiflesCheck",
            text: prType,
            cvarname: "bot_allow_rifles");
  else
    v17 = nullptr;
  this->m_allowRifles = v17;
  v18 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v18 != nullptr )
    v19 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v18,
            parent: this,
            panelName: "BotAllowMachineGunsCheck",
            text: prType,
            cvarname: "bot_allow_machine_guns");
  else
    v19 = nullptr;
  this->m_allowMachineGuns = v19;
  v20 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v20 != nullptr )
    v21 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v20,
            parent: this,
            panelName: "BotAllowGrenadesCheck",
            text: prType,
            cvarname: "bot_allow_grenades");
  else
    v21 = nullptr;
  this->m_allowGrenades = v21;
  v22 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v22 != nullptr )
    v23 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v22,
            parent: this,
            panelName: "BotAllowSnipersCheck",
            text: prType,
            cvarname: "bot_allow_snipers");
  else
    v23 = nullptr;
  this->m_allowSnipers = v23;
  v24 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v24 != nullptr )
    v25 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v24,
            parent: this,
            panelName: "BotJoinAfterPlayerCheck",
            text: prType,
            cvarname: "bot_join_after_player");
  else
    v25 = nullptr;
  this->m_joinAfterPlayer = v25;
  v26 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v26 != nullptr )
    v27 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v26,
            parent: this,
            panelName: "BotDeferToHumanCheck",
            text: prType,
            cvarname: "bot_defer_to_human");
  else
    v27 = nullptr;
  this->m_deferToHuman = v27;
  v28 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v28 != nullptr )
    v29 = vgui::ComboBox::ComboBox(
            this: v28,
            parent: this,
            panelName: "BotJoinTeamCombo",
            numLines: 3,
            allowEdit: false);
  else
    v29 = nullptr;
  this->m_joinTeamCombo = v29;
  v29->AddItem_2(this: v29, a2: "#Cstrike_Random", a3: nullptr);
  this->m_joinTeamCombo->AddItem_2(this: this->m_joinTeamCombo, a2: "#Cstrike_ScoreBoard_CT", a3: nullptr);
  this->m_joinTeamCombo->AddItem_2(this: this->m_joinTeamCombo, a2: "#Cstrike_ScoreBoard_Ter", a3: nullptr);
  v30 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v30 != nullptr )
    v31 = vgui::ComboBox::ComboBox(this: v30, parent: this, panelName: "BotChatterCombo", numLines: 4, allowEdit: false);
  else
    v31 = nullptr;
  this->m_chatterCombo = v31;
  v31->AddItem_2(this: v31, a2: "#Cstrike_Bot_Chatter_Normal", a3: nullptr);
  this->m_chatterCombo->AddItem_2(this: this->m_chatterCombo, a2: "#Cstrike_Bot_Chatter_Minimal", a3: nullptr);
  this->m_chatterCombo->AddItem_2(this: this->m_chatterCombo, a2: "#Cstrike_Bot_Chatter_Radio", a3: nullptr);
  this->m_chatterCombo->AddItem_2(this: this->m_chatterCombo, a2: "#Cstrike_Bot_Chatter_Off", a3: nullptr);
  v32 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v32 != nullptr )
    v33 = vgui::TextEntry::TextEntry(this: v32, parent: this, panelName: "BotPrefixEntry");
  else
    v33 = nullptr;
  this->m_prefixEntry = v33;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource/CreateMultiplayerGameBotPage.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  LOBYTE(name) = KeyValues::GetInt(this: botKeys, keyName: "bot_join_after_player", defaultValue: 1) != 0;
  this->m_joinAfterPlayer->SetSelected(this: this->m_joinAfterPlayer, a2: (bool)name);
  LOBYTE(name) = KeyValues::GetInt(this: botKeys, keyName: "bot_allow_rogues", defaultValue: 1) != 0;
  this->m_allowRogues->SetSelected(this: this->m_allowRogues, a2: (bool)name);
  LOBYTE(name) = KeyValues::GetInt(this: botKeys, keyName: "bot_allow_pistols", defaultValue: 1) != 0;
  this->m_allowPistols->SetSelected(this: this->m_allowPistols, a2: (bool)name);
  LOBYTE(name) = KeyValues::GetInt(this: botKeys, keyName: "bot_allow_shotguns", defaultValue: 1) != 0;
  this->m_allowShotguns->SetSelected(this: this->m_allowShotguns, a2: (bool)name);
  LOBYTE(name) = KeyValues::GetInt(this: botKeys, keyName: "bot_allow_sub_machine_guns", defaultValue: 1) != 0;
  this->m_allowSubmachineGuns->SetSelected(this: this->m_allowSubmachineGuns, a2: (bool)name);
  LOBYTE(name) = KeyValues::GetInt(this: botKeys, keyName: "bot_allow_machine_guns", defaultValue: 1) != 0;
  this->m_allowMachineGuns->SetSelected(this: this->m_allowMachineGuns, a2: (bool)name);
  LOBYTE(name) = KeyValues::GetInt(this: botKeys, keyName: "bot_allow_rifles", defaultValue: 1) != 0;
  this->m_allowRifles->SetSelected(this: this->m_allowRifles, a2: (bool)name);
  LOBYTE(name) = KeyValues::GetInt(this: botKeys, keyName: "bot_allow_snipers", defaultValue: 1) != 0;
  this->m_allowSnipers->SetSelected(this: this->m_allowSnipers, a2: (bool)name);
  LOBYTE(name) = KeyValues::GetInt(this: botKeys, keyName: "bot_allow_grenades", defaultValue: 1) != 0;
  this->m_allowGrenades->SetSelected(this: this->m_allowGrenades, a2: (bool)name);
  LOBYTE(name) = KeyValues::GetInt(this: botKeys, keyName: "bot_defer_to_human", defaultValue: 1) != 0;
  this->m_deferToHuman->SetSelected(this: this->m_deferToHuman, a2: (bool)name);
  String = KeyValues::GetString(this: botKeys, keyName: "bot_join_team", defaultValue: "any");
  CCreateMultiplayerGameBotPage::SetJoinTeamCombo(this, team: String);
  v35 = KeyValues::GetString(this: botKeys, keyName: "bot_chatter", defaultValue: "normal");
  CCreateMultiplayerGameBotPage::SetChatterCombo(this, chatter: v35);
  v36 = KeyValues::GetString(this: botKeys, keyName: "bot_prefix", defaultValue: prType);
  if ( v36 != nullptr )
    vgui::EditablePanel::SetControlString(this, controlName: "BotPrefixEntry", string: v36);
  return this;
}
