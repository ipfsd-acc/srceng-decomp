// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system_editor/layout_system_kv_editor.cpp
// Functions: 10
// ============================================================

#include "missionchooser\layout_system_editor\layout_system_kv_editor.h"

//------------------------------------------------------------------------------
// Address: 0x1001F900
// Name: public: static char const __near * CLayoutSystemKVEditor::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLayoutSystemKVEditor::GetPanelClassName()
{
  return "CLayoutSystemKVEditor";
}

//------------------------------------------------------------------------------
// Address: 0x1001F910
// Name: public: virtual void CLayoutSystemKVEditor::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLayoutSystemKVEditor::PerformLayout(CLayoutSystemKVEditor *this)
{
  int Wide; // eax
  int Tall; // [esp-4h] [ebp-8h]

  vgui::EditablePanel::PerformLayout(this);
  Tall = vgui::Panel::GetTall(this);
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pScrollingWindow, x: 0, y: 0, wide: Wide, tall: Tall);
  if ( this->m_pMissionPanel != nullptr )
    this->m_pMissionPanel->PerformLayout(this: this->m_pMissionPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1001F960
// Name: public: void CLayoutSystemKVEditor::RecreateMissionPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLayoutSystemKVEditor::RecreateMissionPanel(CLayoutSystemKVEditor *this)
{
  CMissionPanel *m_pMissionPanel; // ecx
  CMissionPanel *v3; // eax
  CMissionPanel *v4; // eax

  m_pMissionPanel = this->m_pMissionPanel;
  if ( m_pMissionPanel != nullptr )
    ((void (__thiscall *)(CMissionPanel *, int))m_pMissionPanel->dtr_Panel)(a1: m_pMissionPanel, a2: 1);
  v3 = (CMissionPanel *)operator new(nSize: 0x290u);
  if ( v3 != nullptr )
    v4 = CMissionPanel::CMissionPanel(this: v3, pParent: this, pName: "Mission");
  else
    v4 = nullptr;
  this->m_pMissionPanel = v4;
  v4->m_pEditor = this;
  CScrollingWindow::SetChildPanel(this: this->m_pScrollingWindow, pPanel: this->m_pMissionPanel);
  this->m_pScrollingWindow->InvalidateLayout(this: this->m_pScrollingWindow, a2: true, a3: false);
  CNodePanel::SetData(this: this->m_pMissionPanel, pNodeKV: this->m_pMissionFileKV);
  this->m_pMissionPanel->InvalidateLayout(this: this->m_pMissionPanel, a2: true, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001FA00
// Name: public: void CLayoutSystemKVEditor::ShowOptionalValues(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLayoutSystemKVEditor::ShowOptionalValues(CLayoutSystemKVEditor *this, bool bVisible)
{
  CMissionPanel *m_pMissionPanel; // ecx

  if ( bVisible != this->m_bShowOptionalValues )
  {
    m_pMissionPanel = this->m_pMissionPanel;
    this->m_bShowOptionalValues = bVisible;
    if ( m_pMissionPanel != nullptr )
      m_pMissionPanel->UpdateState(this: m_pMissionPanel);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FA40
// Name: public: void CLayoutSystemKVEditor::ShowAddButtons(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLayoutSystemKVEditor::ShowAddButtons(CLayoutSystemKVEditor *this, bool bVisible)
{
  CMissionPanel *m_pMissionPanel; // ecx

  if ( bVisible != this->m_bShowAddButtons )
  {
    m_pMissionPanel = this->m_pMissionPanel;
    this->m_bShowAddButtons = bVisible;
    if ( m_pMissionPanel != nullptr )
      m_pMissionPanel->UpdateState(this: m_pMissionPanel);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FA80
// Name: public: virtual struct vgui::PanelMessageMap __near * CLayoutSystemKVEditor::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLayoutSystemKVEditor::GetMessageMap(CLayoutSystemKVEditor *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLayoutSystemKVEditor::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLayoutSystemKVEditor::GetMessageMap'::`2'::s_pMap;
  `CLayoutSystemKVEditor::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLayoutSystemKVEditor");
  `CLayoutSystemKVEditor::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001FAB0
// Name: public: virtual struct PanelAnimationMap __near * CLayoutSystemKVEditor::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLayoutSystemKVEditor::GetAnimMap(CLayoutSystemKVEditor *this)
{
  return FindOrAddPanelAnimationMap(className: "CLayoutSystemKVEditor");
}

//------------------------------------------------------------------------------
// Address: 0x1001FAC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLayoutSystemKVEditor::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLayoutSystemKVEditor::GetKBMap(CLayoutSystemKVEditor *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLayoutSystemKVEditor::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLayoutSystemKVEditor::GetKBMap'::`2'::s_pMap;
  `CLayoutSystemKVEditor::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLayoutSystemKVEditor");
  `CLayoutSystemKVEditor::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001FAF0
// Name: public: CLayoutSystemKVEditor::CLayoutSystemKVEditor(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLayoutSystemKVEditor *__thiscall CLayoutSystemKVEditor::CLayoutSystemKVEditor(
        CLayoutSystemKVEditor *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CScrollingWindow *v7; // eax

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CLayoutSystemKVEditor_vtbl *)&CLayoutSystemKVEditor::`vftable';
  if ( `CLayoutSystemKVEditor::ChainToMap'::`2'::chained == 0 )
  {
    `CLayoutSystemKVEditor::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CLayoutSystemKVEditor");
    v4->pfnClassName = CLayoutSystemKVEditor::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CLayoutSystemKVEditor::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLayoutSystemKVEditor::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CLayoutSystemKVEditor");
    v5->pfnClassName = CLayoutSystemKVEditor::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CLayoutSystemKVEditor::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLayoutSystemKVEditor::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CLayoutSystemKVEditor");
    v6->pfnClassName = CLayoutSystemKVEditor::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_pMissionFileKV = nullptr;
  this->m_pMissionPanel = nullptr;
  *(_WORD *)&this->m_bShowOptionalValues = 0;
  v7 = (CScrollingWindow *)operator new(nSize: 0x168u);
  if ( v7 != nullptr )
    this->m_pScrollingWindow = CScrollingWindow::CScrollingWindow(this: v7, parent: this, name: "ScrollingWindow");
  else
    this->m_pScrollingWindow = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001FC30
// Name: public: void CLayoutSystemKVEditor::SetMissionData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLayoutSystemKVEditor::SetMissionData(CLayoutSystemKVEditor *this, KeyValues *pMissionFileKV)
{
  this->m_pMissionFileKV = pMissionFileKV;
  CLayoutSystemKVEditor::RecreateMissionPanel(this);
}
