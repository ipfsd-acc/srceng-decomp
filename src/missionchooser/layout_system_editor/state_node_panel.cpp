// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system_editor/state_node_panel.cpp
// Functions: 7
// ============================================================

#include "missionchooser\layout_system_editor\state_node_panel.h"

//------------------------------------------------------------------------------
// Address: 0x10024160
// Name: public: static char const __near * CStateNodePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CStateNodePanel::GetPanelClassName()
{
  return "CStateNodePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10024170
// Name: protected: virtual void CStateNodePanel::CreatePanelContents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStateNodePanel::CreatePanelContents(CStateNodePanel *this)
{
  int v2; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  bool v7; // al
  CRuleInstanceNodePanel *Child; // edi
  void (__thiscall *UpdateState)(CNodePanel *); // edx
  int nIndex; // [esp+Ch] [ebp-8h]
  bool bIsState; // [esp+12h] [ebp-2h]
  bool bIsRuleInstance; // [esp+13h] [ebp-1h]

  v2 = 0;
  nIndex = 0;
  for ( i = KeyValues::GetFirstSubKey(this: this->m_pNodeKV); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    bIsState = _V_stricmp(s1: Name, s2: "state") == 0;
    v5 = KeyValues::GetName(this: i);
    bIsRuleInstance = _V_stricmp(s1: v5, s2: "rule_instance") == 0;
    v6 = KeyValues::GetName(this: i);
    v7 = _V_stricmp(s1: v6, s2: "action") == 0;
    if ( bIsState || bIsRuleInstance || v7 )
    {
      CNodePanel::AddNewElementPanel(this, nIndex: v2, bAllowRules: true, bAllowStates: false);
      Child = CNodePanel::CreateChild(this, pKey: i);
      UpdateState = Child->UpdateState;
      Child->m_bShowDeleteButton = true;
      UpdateState(this: Child);
      CNodePanel::AddChild(this, pPanel: Child, nPadding: 0);
      if ( bIsRuleInstance )
      {
        CRuleInstanceNodePanel::AddAllowableRuleType(this: Child, pType: "state");
        CRuleInstanceNodePanel::AddAllowableRuleType(this: Child, pType: "action");
      }
    }
    v2 = ++nIndex;
  }
  CNodePanel::AddNewElementPanel(this, nIndex: v2, bAllowRules: true, bAllowStates: false);
}

//------------------------------------------------------------------------------
// Address: 0x10024280
// Name: protected: virtual void CStateNodePanel::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStateNodePanel::UpdateState(CStateNodePanel *this)
{
  KeyValues *m_pNodeKV; // edi
  const char *String; // eax

  m_pNodeKV = this->m_pNodeKV;
  if ( m_pNodeKV != nullptr )
  {
    V_strncpy(pDest: this->m_NodeLabel, pSrc: "State", maxLen: 100);
    String = KeyValues::GetString(this: m_pNodeKV, keyName: "name", defaultValue: "<unnamed>");
    V_strncpy(pDest: this->m_NodeName, pSrc: String, maxLen: 100);
  }
  ((void (__thiscall *)(CStateNodePanel *, int))this->SetBgColor)(a1: this, a2: -12829636);
  CNodePanel::UpdateState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100242F0
// Name: public: CStateNodePanel::CStateNodePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CStateNodePanel *__thiscall CStateNodePanel::CStateNodePanel(
        CStateNodePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *UpdateState)(CNodePanel *); // eax

  CNodePanel::CNodePanel(this, pParent, pName);
  this->__vftable = (CStateNodePanel_vtbl *)&CStateNodePanel::`vftable';
  if ( `CStateNodePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CStateNodePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CStateNodePanel");
    v4->pfnClassName = CStateNodePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
  }
  if ( `CStateNodePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CStateNodePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CStateNodePanel");
    v5->pfnClassName = CStateNodePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CNodePanel");
  }
  if ( `CStateNodePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CStateNodePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CStateNodePanel");
    v6->pfnClassName = CStateNodePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CNodePanel");
  }
  UpdateState = this->UpdateState;
  this->m_bShowNameEditBox = true;
  UpdateState(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100243C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CStateNodePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CStateNodePanel::GetMessageMap(CStateNodePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CStateNodePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CStateNodePanel::GetMessageMap'::`2'::s_pMap;
  `CStateNodePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CStateNodePanel");
  `CStateNodePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100243F0
// Name: public: virtual struct PanelAnimationMap __near * CStateNodePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CStateNodePanel::GetAnimMap(CStateNodePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CStateNodePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10024400
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CStateNodePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CStateNodePanel::GetKBMap(CStateNodePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CStateNodePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CStateNodePanel::GetKBMap'::`2'::s_pMap;
  `CStateNodePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CStateNodePanel");
  `CStateNodePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}
