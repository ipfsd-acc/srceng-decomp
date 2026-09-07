// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system_editor/mission_panel.cpp
// Functions: 8
// ============================================================

#include "missionchooser\layout_system_editor\mission_panel.h"

//------------------------------------------------------------------------------
// Address: 0x1001FC50
// Name: public: static char const __near * CMissionPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMissionPanel::GetPanelClassName()
{
  return "CMissionPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1001FC60
// Name: protected: virtual void CMissionPanel::CreatePanelContents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMissionPanel::CreatePanelContents(CMissionPanel *this)
{
  KeyValues *m_pNodeKV; // ecx
  int v3; // esi
  KeyValues *i; // edi
  const char *Name; // eax
  const char *v6; // eax
  bool v7; // al
  CRuleInstanceNodePanel *Child; // esi
  void (__thiscall *UpdateState)(CNodePanel *); // edx
  int nIndex; // [esp+4h] [ebp-8h]
  bool bIsRuleInstance; // [esp+Ah] [ebp-2h]
  bool bIsState; // [esp+Bh] [ebp-1h]

  m_pNodeKV = this->m_pNodeKV;
  if ( m_pNodeKV != nullptr )
  {
    v3 = 0;
    nIndex = 0;
    for ( i = KeyValues::GetFirstSubKey(this: m_pNodeKV); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      bIsState = _V_stricmp(s1: Name, s2: "state") == 0;
      v6 = KeyValues::GetName(this: i);
      v7 = _V_stricmp(s1: v6, s2: "rule_instance") == 0;
      bIsRuleInstance = v7;
      if ( bIsState || v7 )
      {
        CNodePanel::AddNewElementPanel(this, nIndex: v3, bAllowRules: true, bAllowStates: false);
        Child = (CRuleInstanceNodePanel *)CNodePanel::CreateChild(this, pKey: i);
        UpdateState = Child->UpdateState;
        Child->m_bShowDeleteButton = true;
        UpdateState(this: Child);
        CNodePanel::AddChild(this, pPanel: Child, nPadding: 10);
        if ( bIsRuleInstance )
        {
          CRuleInstanceNodePanel::AddAllowableRuleType(this: Child, pType: "state");
          CRuleInstanceNodePanel::AddAllowableRuleType(this: Child, pType: "global_action");
          CRuleInstanceNodePanel::AddAllowableRuleType(this: Child, pType: "option_block");
        }
      }
      v3 = ++nIndex;
    }
    CNodePanel::AddNewElementPanel(this, nIndex: v3, bAllowRules: true, bAllowStates: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FD60
// Name: public: virtual void CMissionPanel::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMissionPanel::UpdateState(CMissionPanel *this)
{
  KeyValues *m_pNodeKV; // edi
  const char *String; // eax

  m_pNodeKV = this->m_pNodeKV;
  if ( m_pNodeKV != nullptr )
  {
    V_strncpy(pDest: this->m_NodeLabel, pSrc: "Mission", maxLen: 100);
    String = KeyValues::GetString(this: m_pNodeKV, keyName: "name", defaultValue: "<unnamed>");
    V_strncpy(pDest: this->m_NodeName, pSrc: String, maxLen: 100);
  }
  CNodePanel::UpdateState(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001FDB0
// Name: public: virtual void CMissionPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMissionPanel::PerformLayout(CMissionPanel *this)
{
  vgui::CSizerBase *Sizer; // eax
  int v3; // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  int y; // [esp+4h] [ebp-Ch] BYREF
  int x; // [esp+8h] [ebp-8h] BYREF
  int v7; // [esp+Ch] [ebp-4h]

  vgui::EditablePanel::PerformLayout(this);
  Sizer = vgui::Panel::GetSizer(this);
  vgui::CSizerBase::GetMinSize(this: Sizer, OutX: &x, OutY: &y);
  v3 = x;
  if ( x <= 450 )
    v3 = 450;
  vgui::Panel::SetSize(this, wide: v3, tall: y);
  SetBgColor = this->SetBgColor;
  v7 = -13619152;
  ((void (__thiscall *)(CMissionPanel *, int))SetBgColor)(a1: this, a2: -13619152);
}

//------------------------------------------------------------------------------
// Address: 0x1001FE10
// Name: public: CMissionPanel::CMissionPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMissionPanel *__thiscall CMissionPanel::CMissionPanel(CMissionPanel *this, vgui::Panel *pParent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  void (__thiscall *UpdateState)(CNodePanel *); // eax

  CNodePanel::CNodePanel(this, pParent, pName);
  this->__vftable = (CMissionPanel_vtbl *)&CMissionPanel::`vftable';
  if ( `CMissionPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CMissionPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMissionPanel");
    v4->pfnClassName = CMissionPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
  }
  if ( `CMissionPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMissionPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMissionPanel");
    v5->pfnClassName = CMissionPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CNodePanel");
  }
  if ( `CMissionPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMissionPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMissionPanel");
    v6->pfnClassName = CMissionPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CNodePanel");
  }
  UpdateState = this->UpdateState;
  this->m_bShowNameEditBox = true;
  UpdateState(this);
  CNodePanel::SetChildIndent(this, nIndent: 10);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001FEF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CMissionPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMissionPanel::GetMessageMap(CMissionPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMissionPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMissionPanel::GetMessageMap'::`2'::s_pMap;
  `CMissionPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMissionPanel");
  `CMissionPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001FF20
// Name: public: virtual struct PanelAnimationMap __near * CMissionPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMissionPanel::GetAnimMap(CMissionPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CMissionPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1001FF30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMissionPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMissionPanel::GetKBMap(CMissionPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMissionPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMissionPanel::GetKBMap'::`2'::s_pMap;
  `CMissionPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMissionPanel");
  `CMissionPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}
