// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/commentaryexplanationdialog.cpp
// Functions: 7
// ============================================================

#include "game\client\cstrike15\gameui\commentaryexplanationdialog.h"

//------------------------------------------------------------------------------
// Address: 0x101D3CB0
// Name: public: virtual void CCommentaryExplanationDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryExplanationDialog::OnClose(CCustomTabExplanationDialog *this)
{
  CGameUI *v1; // eax

  vgui::Frame::OnClose(this);
  v1 = GameUI();
  CGameUI::AllowEngineHideGameUI(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101EFB70
// Name: public: static char const __near * CCommentaryExplanationDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCommentaryExplanationDialog::GetPanelClassName()
{
  return "CCommentaryExplanationDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101EFBB0
// Name: public: virtual void CCommentaryExplanationDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryExplanationDialog::OnCommand(CCommentaryExplanationDialog *this, const char *command)
{
  CCStrike15BasePanel *v3; // eax

  if ( _V_stricmp(s1: command, s2: "ok") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "cancel") != 0 && _V_stricmp(s1: command, s2: "close") != 0 )
      vgui::Frame::OnCommand(this, command);
    else
      this->Close(this);
  }
  else
  {
    this->Close(this);
    v3 = BasePanel();
    CBaseModPanel::FadeToBlackAndRunEngineCommand(this: v3, engineCommand: this->m_pszFinishCommand);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EFC40
// Name: public: virtual struct vgui::PanelMessageMap __near * CCommentaryExplanationDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCommentaryExplanationDialog::GetMessageMap(CCommentaryExplanationDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCommentaryExplanationDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCommentaryExplanationDialog::GetMessageMap'::`2'::s_pMap;
  `CCommentaryExplanationDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCommentaryExplanationDialog");
  `CCommentaryExplanationDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EFC70
// Name: public: virtual struct PanelAnimationMap __near * CCommentaryExplanationDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCommentaryExplanationDialog::GetAnimMap(CCommentaryExplanationDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CCommentaryExplanationDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101EFC80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCommentaryExplanationDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCommentaryExplanationDialog::GetKBMap(CCommentaryExplanationDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCommentaryExplanationDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCommentaryExplanationDialog::GetKBMap'::`2'::s_pMap;
  `CCommentaryExplanationDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCommentaryExplanationDialog");
  `CCommentaryExplanationDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EFCB0
// Name: public: CCommentaryExplanationDialog::CCommentaryExplanationDialog(class vgui::Panel __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
CCommentaryExplanationDialog *__thiscall CCommentaryExplanationDialog::CCommentaryExplanationDialog(
        CCommentaryExplanationDialog *this,
        vgui::Panel *parent,
        char *pszFinishCommand)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CGameUI *v7; // eax

  vgui::Frame::Frame(this, parent, panelName: "CommentaryExplanationDialog", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CCommentaryExplanationDialog_vtbl *)&CCommentaryExplanationDialog::`vftable';
  if ( `CCommentaryExplanationDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CCommentaryExplanationDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CCommentaryExplanationDialog");
    v4->pfnClassName = CCommentaryExplanationDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CCommentaryExplanationDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCommentaryExplanationDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CCommentaryExplanationDialog");
    v5->pfnClassName = CCommentaryExplanationDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CCommentaryExplanationDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCommentaryExplanationDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CCommentaryExplanationDialog");
    v6->pfnClassName = CCommentaryExplanationDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  g_pVGuiInput->SetAppModalSurface(this: g_pVGuiInput, a2: this->_vpanel);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/CommentaryExplanationDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::MoveToCenterOfScreen(this);
  v7 = GameUI();
  CGameUI::PreventEngineHideGameUI(this: v7);
  V_snprintf(pDest: this->m_pszFinishCommand, maxLen: 0x200u, pFormat: pszFinishCommand);
  return this;
}
