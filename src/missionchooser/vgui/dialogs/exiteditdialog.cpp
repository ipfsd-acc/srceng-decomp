// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/dialogs/exiteditdialog.cpp
// Functions: 6
// ============================================================

#include "missionchooser\vgui\dialogs\exiteditdialog.h"

//------------------------------------------------------------------------------
// Address: 0x1002E460
// Name: public: static char const __near * CExitEditDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CExitEditDialog::GetPanelClassName()
{
  return "CExitEditDialog";
}

//------------------------------------------------------------------------------
// Address: 0x1002E470
// Name: public: virtual void CExitEditDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExitEditDialog::OnCommand(CExitEditDialog *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "Okay") != 0 )
  {
    _V_stricmp(s1: command, s2: "Close");
  }
  else
  {
    this->m_pExitTagEdit->GetText_2(this: this->m_pExitTagEdit, a2: this->m_pExit->m_szExitTag, a3: 64);
    this->m_pExit->m_bChokepointGrowSource = this->m_pChokeGrowCheck->IsSelected(this: this->m_pChokeGrowCheck);
    this->OnClose(this);
  }
  vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x1002E500
// Name: public: virtual struct vgui::PanelMessageMap __near * CExitEditDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CExitEditDialog::GetMessageMap(CExitEditDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CExitEditDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CExitEditDialog::GetMessageMap'::`2'::s_pMap;
  `CExitEditDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CExitEditDialog");
  `CExitEditDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E530
// Name: public: virtual struct PanelAnimationMap __near * CExitEditDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CExitEditDialog::GetAnimMap(CExitEditDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CExitEditDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1002E540
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CExitEditDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CExitEditDialog::GetKBMap(CExitEditDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CExitEditDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CExitEditDialog::GetKBMap'::`2'::s_pMap;
  `CExitEditDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CExitEditDialog");
  `CExitEditDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E570
// Name: public: CExitEditDialog::CExitEditDialog(class vgui::Panel __near *,char const __near *,class CRoomTemplate __near *,class CRoomTemplateExit __near *)
// Source: json
//------------------------------------------------------------------------------
CExitEditDialog *__thiscall CExitEditDialog::CExitEditDialog(
        CExitEditDialog *this,
        vgui::Panel *parent,
        const char *name,
        CRoomTemplate *pRoomTemplate,
        CRoomTemplateExit *pExit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  CRoomTemplateExit *m_pExit; // ecx
  vgui::CheckButton *v12; // eax
  vgui::CheckButton *v13; // eax
  CRoomTemplateExit *v14; // ecx

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CExitEditDialog_vtbl *)&CExitEditDialog::`vftable';
  if ( `CExitEditDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CExitEditDialog::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CExitEditDialog");
    v6->pfnClassName = CExitEditDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CExitEditDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CExitEditDialog::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CExitEditDialog");
    v7->pfnClassName = CExitEditDialog::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CExitEditDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CExitEditDialog::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CExitEditDialog");
    v8->pfnClassName = CExitEditDialog::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  g_pExitEditDialog = this;
  this->m_pExit = pExit;
  this->m_pRoomTemplate = pRoomTemplate;
  v9 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "ExitTagEdit");
  else
    v10 = nullptr;
  m_pExit = this->m_pExit;
  this->m_pExitTagEdit = v10;
  v10->SetText(this: v10, a2: m_pExit->m_szExitTag);
  v12 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v12 != nullptr )
    v13 = vgui::CheckButton::CheckButton(
            this: v12,
            parent: this,
            panelName: "ChokeGrow",
            text: "Chokepoing Grow Source");
  else
    v13 = nullptr;
  v14 = this->m_pExit;
  this->m_pChokeGrowCheck = v13;
  v13->SetSelected(this: v13, a2: v14->m_bChokepointGrowSource);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "ExitEditDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}
