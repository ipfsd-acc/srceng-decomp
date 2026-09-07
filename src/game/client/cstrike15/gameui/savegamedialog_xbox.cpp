// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/savegamedialog_xbox.cpp
// Functions: 13
// ============================================================

#include "game\client\cstrike15\gameui\savegamedialog_xbox.h"

//------------------------------------------------------------------------------
// Address: 0x101F4D70
// Name: public: static char const __near * CSaveGameDialogXbox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSaveGameDialogXbox::GetPanelClassName()
{
  return "CSaveGameDialogXbox";
}

//------------------------------------------------------------------------------
// Address: 0x101F4DB0
// Name: public: virtual void CAsyncCtxSaveGame::ExecuteAsync(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncCtxSaveGame::ExecuteAsync(CAsyncCtxSaveGame *this)
{
  while ( engine->IsSaveInProgress(this: engine) )
    _ThreadSleep(a1: 50);
}

//------------------------------------------------------------------------------
// Address: 0x101F4DF0
// Name: private: void CSaveGameDialogXbox::SaveCompleted(class CAsyncCtxSaveGame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameDialogXbox::SaveCompleted(CSaveGameDialogXbox *this, CAsyncCtxSaveGame *pCtx)
{
  char *ModDirectory; // eax
  CCStrike15BasePanel *v4; // eax
  char szDirectory[260]; // [esp+Ch] [ebp-104h] BYREF

  ModDirectory = COM_GetModDirectory();
  V_snprintf(pDest: szDirectory, maxLen: 0x104u, pFormat: "%s:/%s", ModDirectory, pCtx->m_szFilename);
  CSaveGameBrowserDialog::ParseSaveData(
    this,
    pszFileName: szDirectory,
    pszShortName: pCtx->m_szFilename,
    save: &this->m_NewSaveDesc);
  v4 = BasePanel();
  CBaseModPanel::CloseMessageDialog(this: v4, nType: 1u);
  if ( this->m_iSelectedSave != 0 || !this->m_bNewSaveAvailable )
  {
    CSaveGameBrowserDialog::AnimateOverwriteActivePanel(this, pNewDesc: &this->m_NewSaveDesc);
    this->m_bGameSaving = false;
  }
  else
  {
    CSaveGameBrowserDialog::AnimateInsertNewPanel(this, pDesc: &this->m_NewSaveDesc);
    this->m_bGameSaving = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4E90
// Name: public: virtual void CSaveGameDialogXbox::OnDoneScanningSaveGames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameDialogXbox::OnDoneScanningSaveGames(CSaveGameDialogXbox *this)
{
  ConVarRef save_history_count; // [esp+4h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &save_history_count, pName: "save_history_count");
  this->m_bNewSaveAvailable = false;
}

//------------------------------------------------------------------------------
// Address: 0x101F4EC0
// Name: public: CSaveGameDialogXbox::CSaveGameDialogXbox(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveGameDialogXbox *__thiscall CSaveGameDialogXbox::CSaveGameDialogXbox(
        CSaveGameDialogXbox *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi

  CSaveGameBrowserDialog::CSaveGameBrowserDialog(this, parent);
  this->__vftable = (CSaveGameDialogXbox_vtbl *)&CSaveGameDialogXbox::`vftable';
  if ( `CSaveGameDialogXbox::ChainToMap'::`2'::chained == 0 )
  {
    `CSaveGameDialogXbox::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CSaveGameDialogXbox");
    v3->pfnClassName = CSaveGameDialogXbox::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CSaveGameBrowserDialog");
  }
  if ( `CSaveGameDialogXbox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSaveGameDialogXbox::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CSaveGameDialogXbox");
    v4->pfnClassName = CSaveGameDialogXbox::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CSaveGameBrowserDialog");
  }
  if ( `CSaveGameDialogXbox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSaveGameDialogXbox::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveGameDialogXbox");
    v5->pfnClassName = CSaveGameDialogXbox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveGameBrowserDialog");
  }
  this->m_bFilterAutosaves = true;
  *(_WORD *)&this->m_bGameSaving = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F4F90
// Name: public: virtual struct vgui::PanelMessageMap __near * CSaveGameDialogXbox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSaveGameDialogXbox::GetMessageMap(CSaveGameDialogXbox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSaveGameDialogXbox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveGameDialogXbox::GetMessageMap'::`2'::s_pMap;
  `CSaveGameDialogXbox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSaveGameDialogXbox");
  `CSaveGameDialogXbox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F4FC0
// Name: public: virtual struct PanelAnimationMap __near * CSaveGameDialogXbox::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSaveGameDialogXbox::GetAnimMap(CSaveGameDialogXbox *this)
{
  return FindOrAddPanelAnimationMap(className: "CSaveGameDialogXbox");
}

//------------------------------------------------------------------------------
// Address: 0x101F4FD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSaveGameDialogXbox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSaveGameDialogXbox::GetKBMap(CSaveGameDialogXbox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSaveGameDialogXbox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveGameDialogXbox::GetKBMap'::`2'::s_pMap;
  `CSaveGameDialogXbox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveGameDialogXbox");
  `CSaveGameDialogXbox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F5000
// Name: public: virtual void CSaveGameDialogXbox::PerformSelectedAction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameDialogXbox::PerformSelectedAction(CSaveGameDialogXbox *this)
{
  CCStrike15BasePanel *v2; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  if ( this->m_SavePanels.m_Size != 0 )
  {
    *((_BYTE *)&this->CSaveGameBrowserDialog + 1132) |= 4u;
    if ( this->m_iSelectedSave != 0 || !this->m_bNewSaveAvailable )
    {
      v2 = BasePanel();
      CBaseModPanel::ShowMessageDialog(this: v2, nType: 0x1Fu, pOwner: this);
    }
    else
    {
      this->OnCommand(this, a2: "SaveGame");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5050
// Name: public: virtual void CSaveGameDialogXbox::UpdateFooterOptions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameDialogXbox::UpdateFooterOptions(CSaveGameDialogXbox *this)
{
  vgui::CFooterPanel *m_pFooter; // edi

  m_pFooter = this->m_pFooter;
  vgui::CFooterPanel::ClearButtons(this: m_pFooter);
  if ( this->m_SavePanels.m_Size != 0 )
  {
    if ( this->m_iSelectedSave != 0 || !this->m_bNewSaveAvailable )
      vgui::CFooterPanel::AddNewButtonLabel(
        this: m_pFooter,
        text: "#GameUI_SaveGame_Overwrite",
        icon: "#GameUI_Icons_A_BUTTON");
    else
      vgui::CFooterPanel::AddNewButtonLabel(
        this: m_pFooter,
        text: "#GameUI_SaveGame_NewSave",
        icon: "#GameUI_Icons_A_BUTTON");
  }
  vgui::CFooterPanel::AddNewButtonLabel(this: m_pFooter, text: "#GameUI_Close", icon: "#GameUI_Icons_B_BUTTON");
  vgui::CFooterPanel::AddNewButtonLabel(
    this: m_pFooter,
    text: "#GameUI_Console_StorageChange",
    icon: "#GameUI_Icons_Y_BUTTON");
}

//------------------------------------------------------------------------------
// Address: 0x101F50C0
// Name: public: virtual void CAsyncCtxSaveGame::Completed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncCtxSaveGame::Completed(CAsyncCtxSaveGame *this)
{
  CSaveGameDialogXbox::SaveCompleted(this: this->m_pSaveGameDlg, pCtx: this);
}

//------------------------------------------------------------------------------
// Address: 0x101F50D0
// Name: private: void CSaveGameDialogXbox::InitiateSaving(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameDialogXbox::InitiateSaving(CSaveGameDialogXbox *this)
{
  bool v2; // bl
  CAsyncCtxSaveGame *v3; // eax
  CCStrike15BasePanel *v4; // eax
  CCStrike15BasePanel *v5; // eax
  char *m_szFilename; // esi
  char *ModDirectory; // eax
  int m_iSelectedSave; // ebx
  SaveGameDescription_t *p_m_SaveInfo; // eax
  CCStrike15BasePanel *v10; // eax
  unsigned int dwLowDateTime; // [esp-8h] [ebp-124h]
  CAsyncCtxSaveGame *v12; // [esp-4h] [ebp-120h]
  char szCmd[260]; // [esp+Ch] [ebp-110h] BYREF
  _FILETIME currentTime; // [esp+110h] [ebp-Ch] BYREF
  CAsyncCtxSaveGame *pAsyncCtx; // [esp+118h] [ebp-4h]

  v2 = this->m_iSelectedSave == 0 && this->m_bNewSaveAvailable;
  v3 = (CAsyncCtxSaveGame *)MemAlloc_Alloc(nSize: 0x114u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (CAsyncCtxSaveGame_vtbl *)&CBaseModPanel::CAsyncJobContext::`vftable';
    v3->m_hThreadHandle = nullptr;
    v3->m_flLeastExecuteTime = 3.0;
    v3->__vftable = (CAsyncCtxSaveGame_vtbl *)&CAsyncCtxSaveGame::`vftable';
    v3->m_pSaveGameDlg = this;
    pAsyncCtx = v3;
  }
  else
  {
    pAsyncCtx = nullptr;
  }
  if ( !v2 )
  {
    v4 = BasePanel();
    CBaseModPanel::CloseMessageDialog(this: v4, nType: 1u);
  }
  v5 = BasePanel();
  CBaseModPanel::ShowMessageDialog(this: v5, nType: 0x20u, pOwner: this);
  m_szFilename = pAsyncCtx->m_szFilename;
  if ( v2 )
  {
    GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: &currentTime);
    dwLowDateTime = currentTime.dwLowDateTime;
    ModDirectory = COM_GetModDirectory();
    V_snprintf(pDest: m_szFilename, maxLen: 0x104u, pFormat: "%s_%u", ModDirectory, dwLowDateTime);
    V_snprintf(pDest: szCmd, maxLen: 0x104u, pFormat: "xsave %s", m_szFilename);
    engine->ExecuteClientCmd(this: engine, a2: szCmd);
    V_strncat(pDest: m_szFilename, pSrc: ".360.sav", destBufferSize: 0x104u, max_chars_to_copy: -1);
  }
  else
  {
    m_iSelectedSave = this->m_iSelectedSave;
    if ( CSaveGameBrowserDialog::IsValidPanel(this, idx: m_iSelectedSave) )
      p_m_SaveInfo = &this->m_SavePanels.m_Memory.m_pMemory[m_iSelectedSave]->m_SaveInfo;
    else
      p_m_SaveInfo = nullptr;
    V_strncpy(pDest: m_szFilename, pSrc: p_m_SaveInfo->szShortName, maxLen: 260);
    V_snprintf(pDest: szCmd, maxLen: 0x104u, pFormat: "xsave %s", m_szFilename);
    engine->ExecuteClientCmd(this: engine, a2: szCmd);
  }
  v12 = pAsyncCtx;
  v10 = BasePanel();
  CBaseModPanel::ExecuteAsync(this: v10, pAsync: v12);
}

//------------------------------------------------------------------------------
// Address: 0x101F5250
// Name: public: virtual void CSaveGameDialogXbox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameDialogXbox::OnCommand(CSaveGameDialogXbox *this, const char *command)
{
  CGameUI *v3; // eax
  CCStrike15BasePanel *v4; // eax

  if ( _V_stricmp(s1: command, s2: "SaveGame") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "SaveSuccess") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "CloseAndSelectResume") != 0 )
      {
        if ( _V_stricmp(s1: command, s2: "OverwriteGameCancelled") != 0 )
        {
          if ( _V_stricmp(s1: command, s2: "RefreshSaveGames") != 0 )
          {
            if ( _V_stricmp(s1: command, s2: "ReleaseModalWindow") != 0 )
            {
              if ( !this->m_bGameSaving )
                vgui::Frame::OnCommand(this, command);
            }
            else
            {
              g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
            }
          }
          else
          {
            this->RefreshSaveGames(this);
          }
        }
        else
        {
          *((_BYTE *)&this->CSaveGameBrowserDialog + 1132) &= ~4u;
        }
      }
      else
      {
        v4 = BasePanel();
        CBaseModPanel::ArmFirstMenuItem(this: v4);
        this->OnCommand(this, a2: "Close");
      }
    }
    else
    {
      g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "UI/buttonclick.wav");
      v3 = GameUI();
      CGameUI::SetSavedThisMenuSession(this: v3, bState: true);
    }
  }
  else if ( !this->m_bGameSaving )
  {
    *((_BYTE *)&this->CSaveGameBrowserDialog + 1132) |= 4u;
    this->m_bGameSaving = true;
    CSaveGameDialogXbox::InitiateSaving(this);
  }
}
