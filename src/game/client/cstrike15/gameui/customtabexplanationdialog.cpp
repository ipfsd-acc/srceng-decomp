// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/customtabexplanationdialog.cpp
// Functions: 7
// ============================================================

#include "game\client\cstrike15\gameui\customtabexplanationdialog.h"

//------------------------------------------------------------------------------
// Address: 0x101D3C00
// Name: public: static char const __near * CCustomTabExplanationDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCustomTabExplanationDialog::GetPanelClassName()
{
  return "CCustomTabExplanationDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101D3C10
// Name: public: virtual void CCustomTabExplanationDialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomTabExplanationDialog::ApplySchemeSettings(
        CCustomTabExplanationDialog *this,
        vgui::IScheme *pScheme)
{
  CCustomTabExplanationDialog_vtbl *v3; // edi
  CModInfo *v4; // eax
  const char *GameName; // eax

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = ModInfo();
  GameName = CModInfo::GetGameName(this: v4);
  v3->SetDialogVariable_4(this, a2: "game", a3: GameName);
}

//------------------------------------------------------------------------------
// Address: 0x101D3C50
// Name: public: virtual void CCustomTabExplanationDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomTabExplanationDialog::OnCommand(CCustomTabExplanationDialog *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ok") != 0
    && _V_stricmp(s1: command, s2: "cancel") != 0
    && _V_stricmp(s1: command, s2: "close") != 0 )
  {
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    this->Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3CD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CCustomTabExplanationDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCustomTabExplanationDialog::GetMessageMap(CCustomTabExplanationDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCustomTabExplanationDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCustomTabExplanationDialog::GetMessageMap'::`2'::s_pMap;
  `CCustomTabExplanationDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCustomTabExplanationDialog");
  `CCustomTabExplanationDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D3D00
// Name: public: virtual struct PanelAnimationMap __near * CCustomTabExplanationDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCustomTabExplanationDialog::GetAnimMap(CCustomTabExplanationDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CCustomTabExplanationDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101D3D10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCustomTabExplanationDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCustomTabExplanationDialog::GetKBMap(CCustomTabExplanationDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCustomTabExplanationDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCustomTabExplanationDialog::GetKBMap'::`2'::s_pMap;
  `CCustomTabExplanationDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCustomTabExplanationDialog");
  `CCustomTabExplanationDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D3D40
// Name: public: CCustomTabExplanationDialog::CCustomTabExplanationDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CCustomTabExplanationDialog *__thiscall CCustomTabExplanationDialog::CCustomTabExplanationDialog(
        CCustomTabExplanationDialog *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CGameUI *v6; // eax

  vgui::Frame::Frame(this, parent, panelName: "CustomTabExplanationDialog", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CCustomTabExplanationDialog_vtbl *)&CCustomTabExplanationDialog::`vftable';
  if ( `CCustomTabExplanationDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CCustomTabExplanationDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CCustomTabExplanationDialog");
    v3->pfnClassName = CCustomTabExplanationDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CCustomTabExplanationDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCustomTabExplanationDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CCustomTabExplanationDialog");
    v4->pfnClassName = CCustomTabExplanationDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CCustomTabExplanationDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCustomTabExplanationDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CCustomTabExplanationDialog");
    v5->pfnClassName = CCustomTabExplanationDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  g_pVGuiInput->SetAppModalSurface(this: g_pVGuiInput, a2: this->_vpanel);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/CustomTabExplanationDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::MoveToCenterOfScreen(this);
  v6 = GameUI();
  CGameUI::PreventEngineHideGameUI(this: v6);
  return this;
}
