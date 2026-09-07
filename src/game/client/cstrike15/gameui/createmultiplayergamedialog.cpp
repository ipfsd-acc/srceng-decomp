// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/createmultiplayergamedialog.cpp
// Functions: 6
// ============================================================

#include "game\client\cstrike15\gameui\createmultiplayergamedialog.h"

//------------------------------------------------------------------------------
// Address: 0x101D23C0
// Name: public: static char const __near * CCreateMultiplayerGameDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCreateMultiplayerGameDialog::GetPanelClassName()
{
  return "CCreateMultiplayerGameDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101D23D0
// Name: protected: virtual bool CCreateMultiplayerGameDialog::OnOK(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCreateMultiplayerGameDialog::OnOK(CCreateMultiplayerGameDialog *this, bool applyOnly)
{
  char *MapName; // eax
  char *HostName; // eax
  char *Password; // eax
  IBaseFileSystem *v6; // eax
  int MaxPlayers; // eax
  char szMapCommand[1024]; // [esp+4h] [ebp-4C0h] BYREF
  char szPassword[64]; // [esp+404h] [ebp-C0h] BYREF
  char szHostName[64]; // [esp+444h] [ebp-80h] BYREF
  char szMapName[64]; // [esp+484h] [ebp-40h] BYREF

  g_pCVar->RevertFlaggedConVars(this: g_pCVar, a2: 0x2000);
  g_pCVar->RevertFlaggedConVars(this: g_pCVar, a2: 0x4000);
  DevMsg(a1: "FCVAR_CHEAT cvars reverted to defaults.\n");
  vgui::PropertyDialog::OnOK(this, applyOnly);
  MapName = (char *)CCreateMultiplayerGameServerPage::GetMapName(this: this->m_pServerPage);
  V_strncpy(pDest: szMapName, pSrc: MapName, maxLen: 64);
  HostName = (char *)CCreateMultiplayerGameGameplayPage::GetHostName(this: this->m_pGameplayPage);
  V_strncpy(pDest: szHostName, pSrc: HostName, maxLen: 64);
  Password = (char *)CCreateMultiplayerGameGameplayPage::GetPassword(this: this->m_pGameplayPage);
  V_strncpy(pDest: szPassword, pSrc: Password, maxLen: 64);
  if ( this->m_pSavedData != nullptr )
  {
    if ( CCreateMultiplayerGameServerPage::IsRandomMapSelected(this: this->m_pServerPage) )
      KeyValues::SetString(this: this->m_pSavedData, keyName: "map", value: (char *)prType);
    else
      KeyValues::SetString(this: this->m_pSavedData, keyName: "map", value: szMapName);
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    KeyValues::SaveToFile(this: this->m_pSavedData, filesystem: v6, resourceName: "ServerConfig.vdf", pathID: "GAME");
  }
  MaxPlayers = CCreateMultiplayerGameGameplayPage::GetMaxPlayers(this: this->m_pGameplayPage);
  V_snprintf(
    pDest: szMapCommand,
    maxLen: 0x400u,
    pFormat: "disconnect\n"
    "wait\n"
    "wait\n"
    "sv_lan 1\n"
    "setmaster enable\n"
    "maxplayers %i\n"
    "sv_password \"%s\"\n"
    "hostname \"%s\"\n"
    "progress_enable\n"
    "map %s\n",
    MaxPlayers,
    szPassword,
    szHostName,
    szMapName);
  engine->ClientCmd_Unrestricted(this: engine, a2: szMapCommand);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D2520
// Name: public: virtual struct vgui::PanelMessageMap __near * CCreateMultiplayerGameDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCreateMultiplayerGameDialog::GetMessageMap(CCreateMultiplayerGameDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCreateMultiplayerGameDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCreateMultiplayerGameDialog::GetMessageMap'::`2'::s_pMap;
  `CCreateMultiplayerGameDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCreateMultiplayerGameDialog");
  `CCreateMultiplayerGameDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D2550
// Name: public: virtual struct PanelAnimationMap __near * CCreateMultiplayerGameDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCreateMultiplayerGameDialog::GetAnimMap(CCreateMultiplayerGameDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CCreateMultiplayerGameDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101D2560
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCreateMultiplayerGameDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCreateMultiplayerGameDialog::GetKBMap(CCreateMultiplayerGameDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCreateMultiplayerGameDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCreateMultiplayerGameDialog::GetKBMap'::`2'::s_pMap;
  `CCreateMultiplayerGameDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCreateMultiplayerGameDialog");
  `CCreateMultiplayerGameDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D2590
// Name: public: CCreateMultiplayerGameDialog::CCreateMultiplayerGameDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CCreateMultiplayerGameDialog *__thiscall CCreateMultiplayerGameDialog::CCreateMultiplayerGameDialog(
        CCreateMultiplayerGameDialog *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CModInfo *v6; // eax
  const char *GameName; // eax
  CCreateMultiplayerGameServerPage *v8; // eax
  CCreateMultiplayerGameServerPage *v9; // eax
  CCreateMultiplayerGameGameplayPage *v10; // eax
  CCreateMultiplayerGameGameplayPage *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  IBaseFileSystem *v14; // ecx
  char *String; // eax
  CCreateMultiplayerGameBotPage *v16; // eax
  CCreateMultiplayerGameBotPage *v17; // eax
  CCreateMultiplayerGameServerPage *m_pServerPage; // [esp-8h] [ebp-14h]

  vgui::PropertyDialog::PropertyDialog(this, parent, panelName: "CreateMultiplayerGameDialog");
  this->__vftable = (CCreateMultiplayerGameDialog_vtbl *)&CCreateMultiplayerGameDialog::`vftable';
  if ( `CCreateMultiplayerGameDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CCreateMultiplayerGameDialog");
    v3->pfnClassName = CCreateMultiplayerGameDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyDialog");
  }
  if ( `CCreateMultiplayerGameDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CCreateMultiplayerGameDialog");
    v4->pfnClassName = CCreateMultiplayerGameDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyDialog");
  }
  if ( `CCreateMultiplayerGameDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CCreateMultiplayerGameDialog");
    v5->pfnClassName = CCreateMultiplayerGameDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyDialog");
  }
  this->m_bBotsEnabled = false;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Panel::SetSize(this, wide: 348, tall: 460);
  vgui::Frame::SetTitle(this, title: "#GameUI_CreateServer", surfaceTitle: true);
  vgui::PropertyDialog::SetOKButtonText(this, text: "#GameUI_Start");
  v6 = ModInfo();
  GameName = CModInfo::GetGameName(this: v6);
  if ( _V_stricmp(s1: GameName, s2: "Counter-Strike Source") == 0 )
    this->m_bBotsEnabled = true;
  v8 = (CCreateMultiplayerGameServerPage *)MemAlloc_Alloc(nSize: 0x1DCu);
  if ( v8 != nullptr )
    v9 = CCreateMultiplayerGameServerPage::CCreateMultiplayerGameServerPage(this: v8, parent: this, name: "ServerPage");
  else
    v9 = nullptr;
  this->m_pServerPage = v9;
  v10 = (CCreateMultiplayerGameGameplayPage *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v10 != nullptr )
    v11 = CCreateMultiplayerGameGameplayPage::CCreateMultiplayerGameGameplayPage(
            this: v10,
            parent: this,
            name: "GameplayPage");
  else
    v11 = nullptr;
  m_pServerPage = this->m_pServerPage;
  this->m_pGameplayPage = v11;
  this->m_pBotPage = nullptr;
  vgui::PropertyDialog::AddPage(this, page: m_pServerPage, title: "#GameUI_Server");
  vgui::PropertyDialog::AddPage(this, page: this->m_pGameplayPage, title: "#GameUI_Game");
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: "ServerConfig");
  else
    v13 = nullptr;
  this->m_pSavedData = v13;
  if ( v13 != nullptr )
  {
    v14 = g_pFullFileSystem != nullptr ? &g_pFullFileSystem->IBaseFileSystem : nullptr;
    KeyValues::LoadFromFile(
      this: v13,
      filesystem: v14,
      resourceName: "ServerConfig.vdf",
      pathID: "GAME",
      pfnEvaluateSymbolProc: nullptr);
    String = KeyValues::GetString(this: this->m_pSavedData, keyName: "map", defaultValue: prType);
    if ( *String != 0 )
      CCreateMultiplayerGameServerPage::SetMap(this: this->m_pServerPage, mapName: String);
  }
  if ( this->m_bBotsEnabled )
  {
    v16 = (CCreateMultiplayerGameBotPage *)MemAlloc_Alloc(nSize: 0x1C4u);
    if ( v16 != nullptr )
      v17 = CCreateMultiplayerGameBotPage::CCreateMultiplayerGameBotPage(
              this: v16,
              parent: this,
              name: "BotPage",
              botKeys: this->m_pSavedData);
    else
      v17 = nullptr;
    this->m_pBotPage = v17;
    vgui::PropertyDialog::AddPage(this, page: v17, title: "#GameUI_CPUPlayerOptions");
    CCreateMultiplayerGameServerPage::EnableBots(this: this->m_pServerPage, data: this->m_pSavedData);
  }
  return this;
}
