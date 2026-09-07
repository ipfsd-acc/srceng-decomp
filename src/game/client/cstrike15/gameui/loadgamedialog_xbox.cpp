// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/loadgamedialog_xbox.cpp
// Functions: 11
// ============================================================

#include "game\client\cstrike15\gameui\loadgamedialog_xbox.h"

//------------------------------------------------------------------------------
// Address: 0x101F1120
// Name: public: static char const __near * CLoadGameDialogXbox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLoadGameDialogXbox::GetPanelClassName()
{
  return "CLoadGameDialogXbox";
}

//------------------------------------------------------------------------------
// Address: 0x101F1130
// Name: public: virtual void CLoadGameDialogXbox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadGameDialogXbox::ApplySchemeSettings(CLoadGameDialogXbox *this, vgui::IScheme *pScheme)
{
  vgui::Panel *ChildByName; // eax

  CSaveGameBrowserDialog::ApplySchemeSettings(this, pScheme);
  ChildByName = vgui::Panel::FindChildByName(this, childName: "TitleLabel", recurseDown: false);
  if ( ChildByName != nullptr )
    ((void (__thiscall *)(vgui::Panel *, const char *))ChildByName->__vftable[1].Think)(
      a1: ChildByName,
      a2: "#GameUI_LoadGame");
}

//------------------------------------------------------------------------------
// Address: 0x101F1170
// Name: public: virtual void CLoadGameDialogXbox::PerformDeletion(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLoadGameDialogXbox::PerformDeletion(CLoadGameDialogXbox *this@<ecx>, const char *a2@<ebx>)
{
  CGameSavePanel *ActivePanel; // eax
  const char *v4; // ecx
  CCStrike15BasePanel *v5; // eax

  ActivePanel = CSaveGameBrowserDialog::GetActivePanel(this);
  if ( ActivePanel != nullptr
    && V_stristr(a1: v4, a2, pStr: ActivePanel->m_SaveInfo.szType, pSearch: "autosave") == nullptr )
  {
    C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
    *((_BYTE *)&this->CSaveGameBrowserDialog + 1132) |= 4u;
    g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "UI/buttonclickrelease.wav");
    v5 = BasePanel();
    CBaseModPanel::ShowMessageDialog(this: v5, nType: 0x1Eu, pOwner: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F11D0
// Name: public: CLoadGameDialogXbox::CLoadGameDialogXbox(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CLoadGameDialogXbox *__thiscall CLoadGameDialogXbox::CLoadGameDialogXbox(
        CLoadGameDialogXbox *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi

  CSaveGameBrowserDialog::CSaveGameBrowserDialog(this, parent);
  this->__vftable = (CLoadGameDialogXbox_vtbl *)&CLoadGameDialogXbox::`vftable';
  if ( `CLoadGameDialogXbox::ChainToMap'::`2'::chained == 0 )
  {
    `CLoadGameDialogXbox::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CLoadGameDialogXbox");
    v3->pfnClassName = CLoadGameDialogXbox::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CSaveGameBrowserDialog");
  }
  if ( `CLoadGameDialogXbox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLoadGameDialogXbox::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CLoadGameDialogXbox");
    v4->pfnClassName = CLoadGameDialogXbox::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CSaveGameBrowserDialog");
  }
  if ( `CLoadGameDialogXbox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLoadGameDialogXbox::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CLoadGameDialogXbox");
    v5->pfnClassName = CLoadGameDialogXbox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveGameBrowserDialog");
  }
  this->m_bFilterAutosaves = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F1290
// Name: public: virtual struct vgui::PanelMessageMap __near * CLoadGameDialogXbox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLoadGameDialogXbox::GetMessageMap(CLoadGameDialogXbox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLoadGameDialogXbox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLoadGameDialogXbox::GetMessageMap'::`2'::s_pMap;
  `CLoadGameDialogXbox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLoadGameDialogXbox");
  `CLoadGameDialogXbox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F12C0
// Name: public: virtual struct PanelAnimationMap __near * CLoadGameDialogXbox::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLoadGameDialogXbox::GetAnimMap(CLoadGameDialogXbox *this)
{
  return FindOrAddPanelAnimationMap(className: "CLoadGameDialogXbox");
}

//------------------------------------------------------------------------------
// Address: 0x101F12D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLoadGameDialogXbox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLoadGameDialogXbox::GetKBMap(CLoadGameDialogXbox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLoadGameDialogXbox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLoadGameDialogXbox::GetKBMap'::`2'::s_pMap;
  `CLoadGameDialogXbox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLoadGameDialogXbox");
  `CLoadGameDialogXbox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F1330
// Name: public: virtual void CLoadGameDialogXbox::PerformSelectedAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadGameDialogXbox::PerformSelectedAction(CLoadGameDialogXbox *this)
{
  CGameUI *v2; // eax
  CGameUI *v3; // eax
  CCStrike15BasePanel *v4; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  if ( this->m_SavePanels.m_Size != 0 )
  {
    *((_BYTE *)&this->CSaveGameBrowserDialog + 1132) |= 4u;
    v2 = GameUI();
    if ( !CGameUI::HasSavedThisMenuSession(this: v2)
      && (v3 = GameUI(), v3->IsInLevel(this: v3))
      && engine->GetMaxClients(this: engine) == 1 )
    {
      v4 = BasePanel();
      CBaseModPanel::ShowMessageDialog(this: v4, nType: 0x1Du, pOwner: this);
    }
    else
    {
      this->OnCommand(this, a2: "LoadGame");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F13A0
// Name: public: virtual void CLoadGameDialogXbox::UpdateFooterOptions(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLoadGameDialogXbox::UpdateFooterOptions(CLoadGameDialogXbox *this@<ecx>, const char *a2@<ebx>)
{
  vgui::CFooterPanel *m_pFooter; // edi
  CGameSavePanel *ActivePanel; // eax
  const char *v5; // ecx

  m_pFooter = this->m_pFooter;
  vgui::CFooterPanel::ClearButtons(this: m_pFooter);
  if ( this->m_SavePanels.m_Size != 0 )
  {
    vgui::CFooterPanel::AddNewButtonLabel(this: m_pFooter, text: "#GameUI_Load", icon: "#GameUI_Icons_A_BUTTON");
    ActivePanel = CSaveGameBrowserDialog::GetActivePanel(this);
    if ( ActivePanel != nullptr
      && V_stristr(a1: v5, a2, pStr: ActivePanel->m_SaveInfo.szType, pSearch: "autosave") == nullptr )
    {
      vgui::CFooterPanel::AddNewButtonLabel(this: m_pFooter, text: "#GameUI_Delete", icon: "#GameUI_Icons_X_BUTTON");
    }
  }
  vgui::CFooterPanel::AddNewButtonLabel(this: m_pFooter, text: "#GameUI_Close", icon: "#GameUI_Icons_B_BUTTON");
  vgui::CFooterPanel::AddNewButtonLabel(
    this: m_pFooter,
    text: "#GameUI_Console_StorageChange",
    icon: "#GameUI_Icons_Y_BUTTON");
}

//------------------------------------------------------------------------------
// Address: 0x101F1430
// Name: private: void CLoadGameDialogXbox::DeleteSaveGame(struct SaveGameDescription_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CLoadGameDialogXbox::DeleteSaveGame(
        CLoadGameDialogXbox *this@<ecx>,
        const char *a2@<ebx>,
        const SaveGameDescription_t *pSaveDesc)
{
  const char *v4; // eax
  const char *v5; // ecx
  SaveGameDescription_t *p_m_SaveInfo; // eax

  if ( pSaveDesc != nullptr )
  {
    v4 = engine->GetMostRecentSaveGame(this: engine, a2: 0);
    if ( V_stristr(a1: v5, a2, pStr: v4, pSearch: pSaveDesc->szShortName) != nullptr && this->m_SavePanels.m_Size > 1u )
    {
      if ( CSaveGameBrowserDialog::IsValidPanel(this, idx: 0) )
        p_m_SaveInfo = &(*this->m_SavePanels.m_Memory.m_pMemory)->m_SaveInfo;
      else
        p_m_SaveInfo = nullptr;
      if ( p_m_SaveInfo != pSaveDesc )
        goto LABEL_10;
      if ( CSaveGameBrowserDialog::IsValidPanel(this, idx: 1) )
      {
        p_m_SaveInfo = (SaveGameDescription_t *)(*((_DWORD *)this->m_SavePanels.m_Memory.m_pMemory + 1) + 384);
LABEL_10:
        if ( p_m_SaveInfo != nullptr )
          engine->SetMostRecentSaveGame(this: engine, a2: (const char *)p_m_SaveInfo);
      }
    }
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: pSaveDesc->szFileName, a3: "MOD");
    g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "UI/buttonclick.wav");
  }
  *((_BYTE *)&this->CSaveGameBrowserDialog + 1132) &= ~4u;
}

//------------------------------------------------------------------------------
// Address: 0x101F1500
// Name: public: virtual void CLoadGameDialogXbox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CLoadGameDialogXbox::OnCommand(
        CLoadGameDialogXbox *this@<ecx>,
        const char *a2@<ebx>,
        const char *command)
{
  int m_iSelectedSave; // edi
  SaveGameDescription_t *p_m_SaveInfo; // eax
  int v6; // edi
  char szCmd[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "LoadGame") == 0 )
  {
    if ( this->m_SavePanels.m_Size != 0 )
    {
      m_iSelectedSave = this->m_iSelectedSave;
      if ( CSaveGameBrowserDialog::IsValidPanel(this, idx: m_iSelectedSave) )
        p_m_SaveInfo = &this->m_SavePanels.m_Memory.m_pMemory[m_iSelectedSave]->m_SaveInfo;
      else
        p_m_SaveInfo = nullptr;
      V_snprintf(pDest: szCmd, maxLen: 0x100u, pFormat: "xload %s", p_m_SaveInfo->szShortName);
      engine->ClientCmd_Unrestricted(this: engine, a2: szCmd);
      this->OnClose(this);
      return;
    }
LABEL_19:
    *((_BYTE *)&this->CSaveGameBrowserDialog + 1132) &= ~4u;
    return;
  }
  if ( _V_stricmp(s1: command, s2: "DeleteGame") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "RefreshSaveGames") == 0 )
    {
      this->RefreshSaveGames(this);
      return;
    }
    if ( _V_stricmp(s1: command, s2: "LoadGameCancelled") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "ReleaseModalWindow") == 0 )
      {
        g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
        return;
      }
      if ( _V_stricmp(s1: command, s2: "DeleteGameCancelled") != 0 )
      {
        vgui::Frame::OnCommand(this, command);
        return;
      }
    }
    goto LABEL_19;
  }
  if ( this->m_SavePanels.m_Size == 0 )
    goto LABEL_19;
  v6 = this->m_iSelectedSave;
  if ( CSaveGameBrowserDialog::IsValidPanel(this, idx: v6) )
    CLoadGameDialogXbox::DeleteSaveGame(this, a2, pSaveDesc: &this->m_SavePanels.m_Memory.m_pMemory[v6]->m_SaveInfo);
  else
    CLoadGameDialogXbox::DeleteSaveGame(this, a2, pSaveDesc: nullptr);
  CSaveGameBrowserDialog::RemoveActivePanel(this);
}
