// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/focusnavgroup.cpp
// Functions: 14
// ============================================================

#include "vgui2\vgui_controls\focusnavgroup.h"

//------------------------------------------------------------------------------
// Address: 0x102DB830
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DB890
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x102DB8A0
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x102DB8B0
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DB900
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DB9F0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x102DBA00
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x102DBA10
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x102DBA90
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x102DBAE0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DBBA0
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x102DBC10
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  KeyValues *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int v28; // [esp+10h] [ebp-10h]
  unsigned int v29; // [esp+10h] [ebp-10h]
  vgui::Panel *v30; // [esp+10h] [ebp-10h]
  int v31; // [esp+14h] [ebp-Ch]
  KeyValues *v32; // [esp+18h] [ebp-8h]
  KeyValues *v33; // [esp+18h] [ebp-8h]
  char v34; // [esp+1Fh] [ebp-1h]
  char v35; // [esp+2Bh] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  v35 = 0;
  v34 = 1;
  v32 = nullptr;
  while ( 1 )
  {
    v7 = 0;
    v31 = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      v29 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != v29 )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        v30 = this->_mainPanel;
        v13 = ((int (*)(void))v30->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))v30->GetVParent)(a1: v30, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          v35 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = v32;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return v35;
        }
        v6 = v32;
      }
    }
    v5 = 9999999;
    v34 = 0;
  }
  v28 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != v31 )
  {
    if ( v9 < v31 && v9 > v28 )
    {
      v28 = v9;
      v32 = (KeyValues *)Child;
    }
    goto LABEL_14;
  }
  v32 = (KeyValues *)Child;
LABEL_17:
  v6 = v32;
LABEL_18:
  if ( v34 == 0 )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = (**(int (__thiscall ***)(KeyValues *, int))v6)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  (*(void (__thiscall **)(KeyValues *, int))(*(_DWORD *)v6 + 48))(a1: v6, a2: -1);
  v35 = 1;
  v16 = (**(int (__thiscall ***)(KeyValues *))v6)(a1: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v33 = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: v33)
       && KeyValues::GetInt(this: v33, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: v33);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = (**(int (__thiscall ***)(KeyValues *, int))v6)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return v35;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return v35;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102DBEF0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp-4h] [ebp-24h]
  int v25; // [esp-4h] [ebp-24h]
  BOOL v26; // [esp+0h] [ebp-20h]
  int v27; // [esp+10h] [ebp-10h]
  unsigned int v28; // [esp+10h] [ebp-10h]
  vgui::Panel *v29; // [esp+10h] [ebp-10h]
  KeyValues *v30; // [esp+14h] [ebp-Ch]
  KeyValues *v31; // [esp+14h] [ebp-Ch]
  KeyValues *v32; // [esp+14h] [ebp-Ch]
  vgui::Panel *v33; // [esp+18h] [ebp-8h]
  char v34; // [esp+1Fh] [ebp-1h]
  char v35; // [esp+2Bh] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v30 = nullptr;
  if ( panel != 0 )
    v30 = (KeyValues *)g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v35 = 0;
  v34 = 1;
  v33 = nullptr;
  while ( 2 )
  {
    v31 = (KeyValues *)((char *)v30 + 1);
    v27 = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( (KeyValues *)v7 != v31 )
    {
      if ( v7 > (int)v31 && v7 < v27 )
      {
        v27 = v7;
        v33 = v6;
      }
      goto LABEL_13;
    }
    v33 = v6;
LABEL_16:
    v3 = v33;
LABEL_17:
    if ( v34 == 0 )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      v28 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == v28 || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      v29 = this->_mainPanel;
      v11 = ((int (*)(void))v29->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))v29->GetVParent)(a1: v29, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = v33;
LABEL_25:
        v30 = nullptr;
        v34 = 0;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  v35 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (v32 = nullptr)
      : (v32 = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: v32)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: v32, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: v32),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return v35;
}

//------------------------------------------------------------------------------
// Address: 0x102DC1F0
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10071B70
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10071BD0
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10071BE0
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x10071BF0
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071C40
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071D30
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x10071D40
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x10071D50
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10071DD0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x10071E20
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10071EE0
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10071F50
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10072230
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x10072530
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00459AC0
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00459B20
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00459B30
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x00459B40
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459B90
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459C80
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x00459C90
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x00459CA0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00459D20
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x00459D70
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459E30
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00459EA0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045A180
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x0045A480
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10088230
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10088290
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100882A0
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x100882B0
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088300
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100883F0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x10088400
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x10088410
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10088490
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x100884E0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100885A0
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10088610
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100888F0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x10088BF0
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0063F570
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063F5D0
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0063F5E0
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x0063F5F0
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063F640
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063F730
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x0063F740
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x0063F750
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0063F7D0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x0063F820
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063F8E0
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0063F950
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0063FC30
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x0063FF30
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102DB930
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DB990
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x102DB9A0
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x102DB9B0
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DBAF0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x102DBB00
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x102DBB10
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x102DBB90
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x102DBBE0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DBCA0
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x102DBD10
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  KeyValues *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int v28; // [esp+10h] [ebp-10h]
  unsigned int v29; // [esp+10h] [ebp-10h]
  vgui::Panel *v30; // [esp+10h] [ebp-10h]
  int v31; // [esp+14h] [ebp-Ch]
  KeyValues *v32; // [esp+18h] [ebp-8h]
  KeyValues *v33; // [esp+18h] [ebp-8h]
  char v34; // [esp+1Fh] [ebp-1h]
  char v35; // [esp+2Bh] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  v35 = 0;
  v34 = 1;
  v32 = nullptr;
  while ( 1 )
  {
    v7 = 0;
    v31 = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      v29 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != v29 )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        v30 = this->_mainPanel;
        v13 = ((int (*)(void))v30->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))v30->GetVParent)(a1: v30, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          v35 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = v32;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return v35;
        }
        v6 = v32;
      }
    }
    v5 = 9999999;
    v34 = 0;
  }
  v28 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != v31 )
  {
    if ( v9 < v31 && v9 > v28 )
    {
      v28 = v9;
      v32 = (KeyValues *)Child;
    }
    goto LABEL_14;
  }
  v32 = (KeyValues *)Child;
LABEL_17:
  v6 = v32;
LABEL_18:
  if ( v34 == 0 )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = (**(int (__thiscall ***)(KeyValues *, int))v6)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  (*(void (__thiscall **)(KeyValues *, int))(*(_DWORD *)v6 + 48))(a1: v6, a2: -1);
  v35 = 1;
  v16 = (**(int (__thiscall ***)(KeyValues *))v6)(a1: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v33 = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: v33)
       && KeyValues::GetInt(this: v33, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: v33);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = (**(int (__thiscall ***)(KeyValues *, int))v6)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return v35;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return v35;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102DBFF0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp-4h] [ebp-24h]
  int v25; // [esp-4h] [ebp-24h]
  BOOL v26; // [esp+0h] [ebp-20h]
  int v27; // [esp+10h] [ebp-10h]
  unsigned int v28; // [esp+10h] [ebp-10h]
  vgui::Panel *v29; // [esp+10h] [ebp-10h]
  KeyValues *v30; // [esp+14h] [ebp-Ch]
  KeyValues *v31; // [esp+14h] [ebp-Ch]
  KeyValues *v32; // [esp+14h] [ebp-Ch]
  vgui::Panel *v33; // [esp+18h] [ebp-8h]
  char v34; // [esp+1Fh] [ebp-1h]
  char v35; // [esp+2Bh] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v30 = nullptr;
  if ( panel != 0 )
    v30 = (KeyValues *)g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v35 = 0;
  v34 = 1;
  v33 = nullptr;
  while ( 2 )
  {
    v31 = (KeyValues *)((char *)v30 + 1);
    v27 = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( (KeyValues *)v7 != v31 )
    {
      if ( v7 > (int)v31 && v7 < v27 )
      {
        v27 = v7;
        v33 = v6;
      }
      goto LABEL_13;
    }
    v33 = v6;
LABEL_16:
    v3 = v33;
LABEL_17:
    if ( v34 == 0 )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      v28 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == v28 || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      v29 = this->_mainPanel;
      v11 = ((int (*)(void))v29->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))v29->GetVParent)(a1: v29, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = v33;
LABEL_25:
        v30 = nullptr;
        v34 = 0;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  v35 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (v32 = nullptr)
      : (v32 = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: v32)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: v32, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: v32),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return v35;
}

//------------------------------------------------------------------------------
// Address: 0x102DC2F0
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1032DDC0
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1032DE20
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1032DE30
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x1032DE40
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032DE90
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032DF80
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x1032DF90
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x1032DFA0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1032E020
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x1032E070
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1032E130
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1032E1A0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  KeyValues *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int v28; // [esp+10h] [ebp-10h]
  unsigned int v29; // [esp+10h] [ebp-10h]
  vgui::Panel *v30; // [esp+10h] [ebp-10h]
  int v31; // [esp+14h] [ebp-Ch]
  KeyValues *v32; // [esp+18h] [ebp-8h]
  KeyValues *v33; // [esp+18h] [ebp-8h]
  char v34; // [esp+1Fh] [ebp-1h]
  char v35; // [esp+2Bh] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  v35 = 0;
  v34 = 1;
  v32 = nullptr;
  while ( 1 )
  {
    v7 = 0;
    v31 = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      v29 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != v29 )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        v30 = this->_mainPanel;
        v13 = ((int (*)(void))v30->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))v30->GetVParent)(a1: v30, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          v35 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = v32;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return v35;
        }
        v6 = v32;
      }
    }
    v5 = 9999999;
    v34 = 0;
  }
  v28 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != v31 )
  {
    if ( v9 < v31 && v9 > v28 )
    {
      v28 = v9;
      v32 = (KeyValues *)Child;
    }
    goto LABEL_14;
  }
  v32 = (KeyValues *)Child;
LABEL_17:
  v6 = v32;
LABEL_18:
  if ( v34 == 0 )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = (**(int (__thiscall ***)(KeyValues *, int))v6)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  (*(void (__thiscall **)(KeyValues *, int))(*(_DWORD *)v6 + 48))(a1: v6, a2: -1);
  v35 = 1;
  v16 = (**(int (__thiscall ***)(KeyValues *))v6)(a1: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v33 = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: v33)
       && KeyValues::GetInt(this: v33, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: v33);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = (**(int (__thiscall ***)(KeyValues *, int))v6)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return v35;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return v35;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032E480
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp-4h] [ebp-24h]
  int v25; // [esp-4h] [ebp-24h]
  BOOL v26; // [esp+0h] [ebp-20h]
  int v27; // [esp+10h] [ebp-10h]
  unsigned int v28; // [esp+10h] [ebp-10h]
  vgui::Panel *v29; // [esp+10h] [ebp-10h]
  KeyValues *v30; // [esp+14h] [ebp-Ch]
  KeyValues *v31; // [esp+14h] [ebp-Ch]
  KeyValues *v32; // [esp+14h] [ebp-Ch]
  vgui::Panel *v33; // [esp+18h] [ebp-8h]
  char v34; // [esp+1Fh] [ebp-1h]
  char v35; // [esp+2Bh] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v30 = nullptr;
  if ( panel != 0 )
    v30 = (KeyValues *)g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v35 = 0;
  v34 = 1;
  v33 = nullptr;
  while ( 2 )
  {
    v31 = (KeyValues *)((char *)v30 + 1);
    v27 = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( (KeyValues *)v7 != v31 )
    {
      if ( v7 > (int)v31 && v7 < v27 )
      {
        v27 = v7;
        v33 = v6;
      }
      goto LABEL_13;
    }
    v33 = v6;
LABEL_16:
    v3 = v33;
LABEL_17:
    if ( v34 == 0 )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      v28 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == v28 || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      v29 = this->_mainPanel;
      v11 = ((int (*)(void))v29->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))v29->GetVParent)(a1: v29, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = v33;
LABEL_25:
        v30 = nullptr;
        v34 = 0;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  v35 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (v32 = nullptr)
      : (v32 = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: v32)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: v32, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: v32),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return v35;
}

//------------------------------------------------------------------------------
// Address: 0x1032E780
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100D70A0
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D7100
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100D7110
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x100D7120
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7170
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7260
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x100D7270
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x100D7280
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x100D7300
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x100D7350
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D7410
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100D7480
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  KeyValues *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int v28; // [esp+10h] [ebp-10h]
  unsigned int v29; // [esp+10h] [ebp-10h]
  vgui::Panel *v30; // [esp+10h] [ebp-10h]
  int v31; // [esp+14h] [ebp-Ch]
  KeyValues *v32; // [esp+18h] [ebp-8h]
  KeyValues *v33; // [esp+18h] [ebp-8h]
  char v34; // [esp+1Fh] [ebp-1h]
  char v35; // [esp+2Bh] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  v35 = 0;
  v34 = 1;
  v32 = nullptr;
  while ( 1 )
  {
    v7 = 0;
    v31 = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      v29 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != v29 )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        v30 = this->_mainPanel;
        v13 = ((int (*)(void))v30->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))v30->GetVParent)(a1: v30, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          v35 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = v32;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return v35;
        }
        v6 = v32;
      }
    }
    v5 = 9999999;
    v34 = 0;
  }
  v28 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != v31 )
  {
    if ( v9 < v31 && v9 > v28 )
    {
      v28 = v9;
      v32 = (KeyValues *)Child;
    }
    goto LABEL_14;
  }
  v32 = (KeyValues *)Child;
LABEL_17:
  v6 = v32;
LABEL_18:
  if ( v34 == 0 )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = (**(int (__thiscall ***)(KeyValues *, int))v6)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  (*(void (__thiscall **)(KeyValues *, int))(*(_DWORD *)v6 + 48))(a1: v6, a2: -1);
  v35 = 1;
  v16 = (**(int (__thiscall ***)(KeyValues *))v6)(a1: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v33 = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: v33)
       && KeyValues::GetInt(this: v33, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: v33);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = (**(int (__thiscall ***)(KeyValues *, int))v6)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return v35;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return v35;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D7760
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp-4h] [ebp-24h]
  int v25; // [esp-4h] [ebp-24h]
  BOOL v26; // [esp+0h] [ebp-20h]
  int v27; // [esp+10h] [ebp-10h]
  unsigned int v28; // [esp+10h] [ebp-10h]
  vgui::Panel *v29; // [esp+10h] [ebp-10h]
  KeyValues *v30; // [esp+14h] [ebp-Ch]
  KeyValues *v31; // [esp+14h] [ebp-Ch]
  KeyValues *v32; // [esp+14h] [ebp-Ch]
  vgui::Panel *v33; // [esp+18h] [ebp-8h]
  char v34; // [esp+1Fh] [ebp-1h]
  char v35; // [esp+2Bh] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v30 = nullptr;
  if ( panel != 0 )
    v30 = (KeyValues *)g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v35 = 0;
  v34 = 1;
  v33 = nullptr;
  while ( 2 )
  {
    v31 = (KeyValues *)((char *)v30 + 1);
    v27 = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( (KeyValues *)v7 != v31 )
    {
      if ( v7 > (int)v31 && v7 < v27 )
      {
        v27 = v7;
        v33 = v6;
      }
      goto LABEL_13;
    }
    v33 = v6;
LABEL_16:
    v3 = v33;
LABEL_17:
    if ( v34 == 0 )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      v28 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == v28 || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      v29 = this->_mainPanel;
      v11 = ((int (*)(void))v29->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))v29->GetVParent)(a1: v29, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = v33;
LABEL_25:
        v30 = nullptr;
        v34 = 0;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  v35 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (v32 = nullptr)
      : (v32 = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: v32)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: v32, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: v32),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return v35;
}

//------------------------------------------------------------------------------
// Address: 0x100D7A60
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0047EA30
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047EA90
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0047EAA0
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x0047EAB0
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EB00
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EBF0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x0047EC00
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x0047EC10
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0047EC90
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x0047ECE0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047EDA0
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0047EE10
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F0F0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x0047F3F0
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00462BA0
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_defaultButton; // edi
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  p_defaultButton = &this->_defaultButton;
  p_currentDefaultButton = &this->_currentDefaultButton;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: p_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00462C00
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00462C10
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x00462C20
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462C70
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebp
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0.0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462D50
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x00462D60
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x00462D70
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // eax
  int v6; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      v6 = v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 224))(a1: v6) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x00462E00
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x00462E50
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // eax
  vgui::IPanel_vtbl *v4; // ebp
  unsigned int v5; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v8; // edi
  vgui::IPanel *v9; // edi
  unsigned int v10; // eax
  vgui::IPanel_vtbl *v11; // ebx
  unsigned int v12; // esi
  char *v13; // eax

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v4 = v2->__vftable;
  v5 = v3;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v4->GetPanel(this: v2, a2: v5, a3: ControlsModuleName);
  v8 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v8;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v9 = g_pVGuiPanel;
        v10 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v11 = v9->__vftable;
        v12 = v10;
        v13 = vgui::GetControlsModuleName();
        return v11->GetPanel(this: v9, a2: v12, a3: v13);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00462F00
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00462F70
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        unsigned int panel)
{
  int v6; // ebx
  int v7; // ebx
  int v8; // ebp
  vgui::Panel *Child; // esi
  int v10; // eax
  int v11; // esi
  vgui::ISurface *v12; // esi
  unsigned int v13; // ebx
  vgui::IPanel *v14; // ebp
  bool (__thiscall **p_RequestFocusPrev)(vgui::IPanel *, unsigned int, unsigned int); // esi
  vgui::Panel *mainPanel; // ebx
  int v17; // eax
  int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  vgui::IVGui *v24; // ebx
  void (__thiscall **p_PostMessage)(vgui::IVGui *, unsigned int, KeyValues *, unsigned int, float); // esi
  int v26; // eax
  void (__thiscall **p_SetCurrentDefaultButton)(vgui::FocusNavGroup *, unsigned int, bool); // esi
  int v28; // eax
  char best_3; // [esp+37h] [ebp-9h]
  int bestPosition; // [esp+38h] [ebp-8h]
  int v33; // [esp+3Ch] [ebp-4h]
  int (__thiscall ***retaddr)(_DWORD, int); // [esp+40h] [ebp+0h]
  char bFound; // [esp+44h] [ebp+4h]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v6 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound = 0;
  best_3 = 1;
  bestPosition = 0;
  while ( 1 )
  {
    v7 = v6 - 1;
    v8 = 0;
    if ( v7 > 0 )
      break;
LABEL_19:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v12 = g_pVGuiSurface;
      v13 = this->_mainPanel->GetVParent(this: this->_mainPanel);
      if ( v13 != v12->GetEmbeddedPanel(this: v12) )
      {
        v14 = g_pVGuiPanel;
        p_RequestFocusPrev = &g_pVGuiPanel->RequestFocusPrev;
        mainPanel = this->_mainPanel;
        v17 = ((int (*)(void))mainPanel->GetVPanel)();
        v18 = ((int (__thiscall *)(vgui::Panel *, int))mainPanel->GetVParent)(a1: mainPanel, a2: v17);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))*p_RequestFocusPrev)(a1: v14, a2: v18) != 0 )
        {
          bFound = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
LABEL_25:
          v11 = bestPosition;
          if ( bestPosition != 0 )
            goto LABEL_26;
          return bFound;
        }
      }
    }
    v6 = 9999999;
    best_3 = 0;
  }
  v33 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_17;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v8);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v8 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v10 = Child->GetTabPosition(this: Child);
  if ( v10 != v7 )
  {
    if ( v10 < v7 && v10 > v33 )
    {
      v33 = v10;
      bestPosition = (int)Child;
    }
    goto LABEL_14;
  }
  bestPosition = (int)Child;
LABEL_17:
  if ( best_3 == 0 )
    goto LABEL_25;
  v11 = bestPosition;
  if ( bestPosition == 0 )
    goto LABEL_19;
LABEL_26:
  v19 = (**(int (__thiscall ***)(int, int, int))v11)(a1: v11, a2: a3, a3: a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v19);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 48))(a1: v11, a2: -1);
  v20 = (**(int (__thiscall ***)(int))v11)(a1: v11);
  if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: v20) )
  {
    p_SetCurrentDefaultButton = &this->SetCurrentDefaultButton;
    v28 = (**retaddr)(a1: retaddr, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))*p_SetCurrentDefaultButton)(a1: this, a2: v28);
    return bFound;
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v21 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v21, a3: true);
    return bFound;
  }
  this->SetCurrentDefaultButton(this, a2: 0, a3: true);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound;
  v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v22 != nullptr )
    v23 = KeyValues::KeyValues(this: v22, setName: "FindDefaultButton");
  else
    v23 = nullptr;
  v24 = g_pVGui;
  p_PostMessage = &g_pVGui->PostMessage;
  v26 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v23,
          a3: 0,
          a4: 0.0);
  ((void (__thiscall *)(vgui::IVGui *, int))*p_PostMessage)(a1: v24, a2: v26);
  return bFound;
}

//------------------------------------------------------------------------------
// Address: 0x00463200
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  int v3; // ebx
  vgui::Panel *v4; // esi
  int v5; // ebx
  int v6; // ebp
  vgui::Panel *Child; // eax
  vgui::Panel *v8; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // esi
  unsigned int v11; // ebx
  vgui::IPanel *v12; // ebp
  bool (__thiscall **p_RequestFocusNext)(vgui::IPanel *, unsigned int, unsigned int); // esi
  vgui::Panel *v14; // ebx
  int v15; // eax
  int v16; // eax
  unsigned int v18; // eax
  unsigned int v19; // esi
  KeyValues *v20; // eax
  KeyValues *v21; // ebp
  bool v22; // bl
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  vgui::IVGui *v25; // ebx
  void (__thiscall **p_PostMessage)(vgui::IVGui *, unsigned int, KeyValues *, unsigned int, float); // esi
  int v27; // eax
  void (__thiscall **p_SetCurrentDefaultButton)(vgui::FocusNavGroup *, unsigned int, bool); // esi
  unsigned int v29; // [esp+14h] [ebp-24h]
  int v30; // [esp+14h] [ebp-24h]
  BOOL v31; // [esp+18h] [ebp-20h]
  char best_3; // [esp+2Fh] [ebp-9h]
  vgui::Panel *bestPosition; // [esp+30h] [ebp-8h]
  int v34; // [esp+34h] [ebp-4h]
  char bFound; // [esp+3Ch] [ebp+4h]

  ++stack_depth;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v3 = 0;
  if ( panel != 0 )
    v3 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v4 = nullptr;
  bFound = 0;
  best_3 = 1;
  bestPosition = nullptr;
  while ( 2 )
  {
    v5 = v3 + 1;
    v34 = 999999;
    v6 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v6);
      v8 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v8->IsEnabled(this: v8)
        && v8->GetTabPosition(this: v8) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v6 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v9 = v8->GetTabPosition(this: v8);
    if ( v9 != v5 )
    {
      if ( v9 > v5 && v9 < v34 )
      {
        v34 = v9;
        bestPosition = v8;
      }
      goto LABEL_13;
    }
    bestPosition = v8;
LABEL_16:
    v4 = bestPosition;
LABEL_17:
    if ( best_3 == 0 )
    {
      if ( v4 == nullptr )
        goto LABEL_43;
    }
    else if ( v4 == nullptr )
    {
      if ( this->_topLevelFocus || this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      v11 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == v11
        || stack_depth >= 15
        || (v12 = g_pVGuiPanel,
            p_RequestFocusNext = &g_pVGuiPanel->RequestFocusNext,
            v14 = this->_mainPanel,
            v15 = ((int (*)(void))v14->GetVPanel)(),
            v16 = ((int (__thiscall *)(vgui::Panel *, int))v14->GetVParent)(a1: v14, a2: v15),
            ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))*p_RequestFocusNext)(a1: v12, a2: v16) == 0) )
      {
        v4 = bestPosition;
LABEL_25:
        v3 = 0;
        best_3 = 0;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v18 = v4->GetVPanel(this: v4);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v18);
  v4->RequestFocus(this: v4, a2: 1);
  bFound = 1;
  v19 = v4->GetVPanel(this: v4);
  if ( v19 == 0 )
    goto LABEL_35;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "CanBeDefaultButton");
  else
    v21 = nullptr;
  v22 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v19, a3: v21) )
    v22 = KeyValues::GetInt(this: v21, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v21);
  if ( v22 )
  {
    p_SetCurrentDefaultButton = &this->SetCurrentDefaultButton;
    v30 = ((int (__thiscall *)(vgui::Panel *, int))bestPosition->GetVPanel)(a1: bestPosition, a2: 1);
    (*p_SetCurrentDefaultButton)(this, a2: v30, a3: v31);
  }
  else
  {
LABEL_35:
    if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v29 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
      this->SetCurrentDefaultButton(this, a2: v29, a3: true);
    }
    else
    {
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
      {
        v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v23 != nullptr )
          v24 = KeyValues::KeyValues(this: v23, setName: "FindDefaultButton");
        else
          v24 = nullptr;
        v25 = g_pVGui;
        p_PostMessage = &g_pVGui->PostMessage;
        v27 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
                a1: this->_mainPanel,
                a2: v24,
                a3: 0,
                a4: 0.0);
        ((void (__thiscall *)(vgui::IVGui *, int))*p_PostMessage)(a1: v25, a2: v27);
        --stack_depth;
        return 1;
      }
    }
  }
LABEL_43:
  --stack_depth;
  return bFound;
}

//------------------------------------------------------------------------------
// Address: 0x00463500
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      this->SetCurrentDefaultButton(this, a2: focus, a3: true);
      return focus;
    }
    if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0066F020
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0066F080
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0066F090
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x0066F0A0
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0066F0F0
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0066F1E0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x0066F1F0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x0066F200
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0066F280
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x0066F2D0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0066F390
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0066F400
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0066F6E0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x0066F9E0
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1007CAC0
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007CB20
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1007CB30
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x1007CB40
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CB90
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CC80
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x1007CC90
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x1007CCA0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1007CD20
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x1007CD70
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007CE30
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1007CEA0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007D180
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x1007D480
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10095EE0
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10095F40
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10095F50
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x10095F60
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095FB0
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100960A0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x100960B0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x100960C0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10096140
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x10096190
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10096250
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100962C0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100965A0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x100968A0
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004704C0
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00470520
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00470530
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x00470540
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470590
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470680
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x00470690
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x004706A0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00470720
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x00470770
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470830
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004708A0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00470B80
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x00470E80
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004B15C0
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_defaultButton; // edi
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  p_defaultButton = &this->_defaultButton;
  p_currentDefaultButton = &this->_currentDefaultButton;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: p_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B1620
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x004B1630
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x004B1640
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B1690
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebp
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0.0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B1770
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x004B1780
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x004B1790
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // eax
  int v6; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      v6 = v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 224))(a1: v6) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x004B1820
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x004B1870
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // eax
  vgui::IPanel_vtbl *v4; // ebp
  unsigned int v5; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v8; // edi
  vgui::IPanel *v9; // edi
  unsigned int v10; // eax
  vgui::IPanel_vtbl *v11; // ebx
  unsigned int v12; // esi
  char *v13; // eax

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v4 = v2->__vftable;
  v5 = v3;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v4->GetPanel(this: v2, a2: v5, a3: ControlsModuleName);
  v8 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v8;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v9 = g_pVGuiPanel;
        v10 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v11 = v9->__vftable;
        v12 = v10;
        v13 = vgui::GetControlsModuleName();
        return v11->GetPanel(this: v9, a2: v12, a3: v13);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B1920
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004B1990
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        unsigned int panel)
{
  int v6; // ebx
  int v7; // ebx
  int v8; // ebp
  vgui::Panel *Child; // esi
  int v10; // eax
  int v11; // esi
  vgui::ISurface *v12; // esi
  unsigned int v13; // ebx
  vgui::IPanel *v14; // ebp
  bool (__thiscall **p_RequestFocusPrev)(vgui::IPanel *, unsigned int, unsigned int); // esi
  vgui::Panel *mainPanel; // ebx
  int v17; // eax
  int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  vgui::IVGui *v24; // ebx
  void (__thiscall **p_PostMessage)(vgui::IVGui *, unsigned int, KeyValues *, unsigned int, float); // esi
  int v26; // eax
  void (__thiscall **p_SetCurrentDefaultButton)(vgui::FocusNavGroup *, unsigned int, bool); // esi
  int v28; // eax
  char best_3; // [esp+37h] [ebp-9h]
  int bestPosition; // [esp+38h] [ebp-8h]
  int v33; // [esp+3Ch] [ebp-4h]
  int (__thiscall ***retaddr)(_DWORD, int); // [esp+40h] [ebp+0h]
  char bFound; // [esp+44h] [ebp+4h]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v6 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound = 0;
  best_3 = 1;
  bestPosition = 0;
  while ( 1 )
  {
    v7 = v6 - 1;
    v8 = 0;
    if ( v7 > 0 )
      break;
LABEL_19:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v12 = g_pVGuiSurface;
      v13 = this->_mainPanel->GetVParent(this: this->_mainPanel);
      if ( v13 != v12->GetEmbeddedPanel(this: v12) )
      {
        v14 = g_pVGuiPanel;
        p_RequestFocusPrev = &g_pVGuiPanel->RequestFocusPrev;
        mainPanel = this->_mainPanel;
        v17 = ((int (*)(void))mainPanel->GetVPanel)();
        v18 = ((int (__thiscall *)(vgui::Panel *, int))mainPanel->GetVParent)(a1: mainPanel, a2: v17);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))*p_RequestFocusPrev)(a1: v14, a2: v18) != 0 )
        {
          bFound = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
LABEL_25:
          v11 = bestPosition;
          if ( bestPosition != 0 )
            goto LABEL_26;
          return bFound;
        }
      }
    }
    v6 = 9999999;
    best_3 = 0;
  }
  v33 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_17;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v8);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v8 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v10 = Child->GetTabPosition(this: Child);
  if ( v10 != v7 )
  {
    if ( v10 < v7 && v10 > v33 )
    {
      v33 = v10;
      bestPosition = (int)Child;
    }
    goto LABEL_14;
  }
  bestPosition = (int)Child;
LABEL_17:
  if ( best_3 == 0 )
    goto LABEL_25;
  v11 = bestPosition;
  if ( bestPosition == 0 )
    goto LABEL_19;
LABEL_26:
  v19 = (**(int (__thiscall ***)(int, int, int))v11)(a1: v11, a2: a3, a3: a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v19);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 48))(a1: v11, a2: -1);
  v20 = (**(int (__thiscall ***)(int))v11)(a1: v11);
  if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: v20) )
  {
    p_SetCurrentDefaultButton = &this->SetCurrentDefaultButton;
    v28 = (**retaddr)(a1: retaddr, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))*p_SetCurrentDefaultButton)(a1: this, a2: v28);
    return bFound;
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v21 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v21, a3: true);
    return bFound;
  }
  this->SetCurrentDefaultButton(this, a2: 0, a3: true);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound;
  v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v22 != nullptr )
    v23 = KeyValues::KeyValues(this: v22, setName: "FindDefaultButton");
  else
    v23 = nullptr;
  v24 = g_pVGui;
  p_PostMessage = &g_pVGui->PostMessage;
  v26 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v23,
          a3: 0,
          a4: 0.0);
  ((void (__thiscall *)(vgui::IVGui *, int))*p_PostMessage)(a1: v24, a2: v26);
  return bFound;
}

//------------------------------------------------------------------------------
// Address: 0x004B1C20
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  int v3; // ebx
  vgui::Panel *v4; // esi
  int v5; // ebx
  int v6; // ebp
  vgui::Panel *Child; // eax
  vgui::Panel *v8; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // esi
  unsigned int v11; // ebx
  vgui::IPanel *v12; // ebp
  bool (__thiscall **p_RequestFocusNext)(vgui::IPanel *, unsigned int, unsigned int); // esi
  vgui::Panel *v14; // ebx
  int v15; // eax
  int v16; // eax
  unsigned int v18; // eax
  unsigned int v19; // esi
  KeyValues *v20; // eax
  KeyValues *v21; // ebp
  bool v22; // bl
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  vgui::IVGui *v25; // ebx
  void (__thiscall **p_PostMessage)(vgui::IVGui *, unsigned int, KeyValues *, unsigned int, float); // esi
  int v27; // eax
  void (__thiscall **p_SetCurrentDefaultButton)(vgui::FocusNavGroup *, unsigned int, bool); // esi
  unsigned int v29; // [esp+14h] [ebp-24h]
  int v30; // [esp+14h] [ebp-24h]
  BOOL v31; // [esp+18h] [ebp-20h]
  char best_3; // [esp+2Fh] [ebp-9h]
  vgui::Panel *bestPosition; // [esp+30h] [ebp-8h]
  int v34; // [esp+34h] [ebp-4h]
  char bFound; // [esp+3Ch] [ebp+4h]

  ++stack_depth;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v3 = 0;
  if ( panel != 0 )
    v3 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v4 = nullptr;
  bFound = 0;
  best_3 = 1;
  bestPosition = nullptr;
  while ( 2 )
  {
    v5 = v3 + 1;
    v34 = 999999;
    v6 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v6);
      v8 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v8->IsEnabled(this: v8)
        && v8->GetTabPosition(this: v8) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v6 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v9 = v8->GetTabPosition(this: v8);
    if ( v9 != v5 )
    {
      if ( v9 > v5 && v9 < v34 )
      {
        v34 = v9;
        bestPosition = v8;
      }
      goto LABEL_13;
    }
    bestPosition = v8;
LABEL_16:
    v4 = bestPosition;
LABEL_17:
    if ( best_3 == 0 )
    {
      if ( v4 == nullptr )
        goto LABEL_43;
    }
    else if ( v4 == nullptr )
    {
      if ( this->_topLevelFocus || this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      v11 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == v11
        || stack_depth >= 15
        || (v12 = g_pVGuiPanel,
            p_RequestFocusNext = &g_pVGuiPanel->RequestFocusNext,
            v14 = this->_mainPanel,
            v15 = ((int (*)(void))v14->GetVPanel)(),
            v16 = ((int (__thiscall *)(vgui::Panel *, int))v14->GetVParent)(a1: v14, a2: v15),
            ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))*p_RequestFocusNext)(a1: v12, a2: v16) == 0) )
      {
        v4 = bestPosition;
LABEL_25:
        v3 = 0;
        best_3 = 0;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v18 = v4->GetVPanel(this: v4);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v18);
  v4->RequestFocus(this: v4, a2: 1);
  bFound = 1;
  v19 = v4->GetVPanel(this: v4);
  if ( v19 == 0 )
    goto LABEL_35;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "CanBeDefaultButton");
  else
    v21 = nullptr;
  v22 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v19, a3: v21) )
    v22 = KeyValues::GetInt(this: v21, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v21);
  if ( v22 )
  {
    p_SetCurrentDefaultButton = &this->SetCurrentDefaultButton;
    v30 = ((int (__thiscall *)(vgui::Panel *, int))bestPosition->GetVPanel)(a1: bestPosition, a2: 1);
    (*p_SetCurrentDefaultButton)(this, a2: v30, a3: v31);
  }
  else
  {
LABEL_35:
    if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v29 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
      this->SetCurrentDefaultButton(this, a2: v29, a3: true);
    }
    else
    {
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
      {
        v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v23 != nullptr )
          v24 = KeyValues::KeyValues(this: v23, setName: "FindDefaultButton");
        else
          v24 = nullptr;
        v25 = g_pVGui;
        p_PostMessage = &g_pVGui->PostMessage;
        v27 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
                a1: this->_mainPanel,
                a2: v24,
                a3: 0,
                a4: 0.0);
        ((void (__thiscall *)(vgui::IVGui *, int))*p_PostMessage)(a1: v25, a2: v27);
        --stack_depth;
        return 1;
      }
    }
  }
LABEL_43:
  --stack_depth;
  return bFound;
}

//------------------------------------------------------------------------------
// Address: 0x004B1F20
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      this->SetCurrentDefaultButton(this, a2: focus, a3: true);
      return focus;
    }
    if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00465A40
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00465AA0
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00465AB0
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x00465AC0
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465B10
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465C00
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x00465C10
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x00465C20
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00465CA0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x00465CF0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00465DB0
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00465E20
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00466100
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x00466400
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x004664C0
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00466520
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00466530
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x00466540
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466590
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466680
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x00466690
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x004666A0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00466720
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x00466770
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00466830
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004668A0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00466B80
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x00466E80
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103D4140
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103D41A0
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x103D41B0
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D4200
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D42F0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x103D4300
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x103D4310
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x103D4390
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x103D43E0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D44A0
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x103D4510
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D47F0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x103D4AF0
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103C9B20
// Name: public: vgui::FocusNavGroup::FocusNavGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::FocusNavGroup::FocusNavGroup(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  vgui::VPanelHandle *p_currentFocus; // ecx

  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
  this->_defaultButton.m_iPanelID = -1;
  this->_currentDefaultButton.m_iPanelID = -1;
  p_currentFocus = &this->_currentFocus;
  p_currentFocus->m_iPanelID = -1;
  this->_mainPanel = panel;
  vgui::VPanelHandle::Set(this: p_currentFocus, pent: 0);
  this->_topLevelFocus = false;
  vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: 0);
  vgui::VPanelHandle::Set(this: &this->_currentDefaultButton, pent: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C9B80
// Name: public: vgui::FocusNavGroup::~FocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::~FocusNavGroup(vgui::FocusNavGroup *this)
{
  this->__vftable = (vgui::FocusNavGroup_vtbl *)&vgui::FocusNavGroup::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x103C9B90
// Name: public: virtual void vgui::FocusNavGroup::SetFocusTopLevel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetFocusTopLevel(vgui::FocusNavGroup *this, bool state)
{
  this->_topLevelFocus = state;
}

//------------------------------------------------------------------------------
// Address: 0x103C9BA0
// Name: public: virtual void vgui::FocusNavGroup::SetDefaultButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetDefaultButton(vgui::FocusNavGroup *this, vgui::Panel *panel)
{
  unsigned int v3; // ebx
  unsigned int v4; // eax

  if ( panel != nullptr )
    v3 = panel->GetVPanel(this: panel);
  else
    v3 = 0;
  if ( v3 != vgui::VPanelHandle::Get(this: &this->_defaultButton) )
  {
    vgui::VPanelHandle::Set(this: &this->_defaultButton, pent: v3);
    v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C9BF0
// Name: public: virtual void vgui::FocusNavGroup::SetCurrentDefaultButton(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FocusNavGroup::SetCurrentDefaultButton(
        vgui::FocusNavGroup *this,
        unsigned int panel,
        bool sendCurrentDefaultButtonMessage)
{
  vgui::VPanelHandle *p_currentDefaultButton; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::IVGui *v6; // esi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  vgui::IVGui *v10; // esi
  unsigned int v11; // eax

  p_currentDefaultButton = &this->_currentDefaultButton;
  if ( panel != vgui::VPanelHandle::Get(this: &this->_currentDefaultButton) )
  {
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 0);
      else
        v5 = nullptr;
      v6 = g_pVGui;
      v7 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v6->PostMessage)(
        a1: v6,
        a2: v7,
        a3: v5,
        a4: 0,
        a5: 0);
    }
    vgui::VPanelHandle::Set(this: p_currentDefaultButton, pent: panel);
    if ( sendCurrentDefaultButtonMessage && vgui::VPanelHandle::Get(this: p_currentDefaultButton) != 0 )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetAsCurrentDefaultButton", firstKey: "state", firstValue: 1);
      else
        v9 = nullptr;
      v10 = g_pVGui;
      v11 = vgui::VPanelHandle::Get(this: p_currentDefaultButton);
      ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))v10->PostMessage)(
        a1: v10,
        a2: v11,
        a3: v9,
        a4: 0,
        a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C9CE0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetCurrentDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetCurrentDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_currentDefaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x103C9CF0
// Name: public: virtual unsigned int vgui::FocusNavGroup::GetDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::GetDefaultButton(vgui::FocusNavGroup *this)
{
  return vgui::VPanelHandle::Get(this: &this->_defaultButton);
}

//------------------------------------------------------------------------------
// Address: 0x103C9D00
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::FindPanelByHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::FindPanelByHotkey(vgui::FocusNavGroup *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  v3 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v3);
    if ( Child != nullptr )
    {
      v5 = (int)Child->HasHotkey(this: Child, a2: key);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
      {
        break;
      }
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x103C9D80
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetDefaultPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetDefaultPanel(vgui::FocusNavGroup *this)
{
  int v2; // edi
  vgui::Panel *Child; // esi

  v2 = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v2);
    if ( Child != nullptr && Child->GetTabPosition(this: Child) == 1 )
      break;
    if ( ++v2 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      return nullptr;
  }
  return Child;
}

//------------------------------------------------------------------------------
// Address: 0x103C9DD0
// Name: public: virtual class vgui::Panel __near * vgui::FocusNavGroup::GetCurrentFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::FocusNavGroup::GetCurrentFocus(vgui::FocusNavGroup *this)
{
  vgui::VPanelHandle *p_currentFocus; // esi
  vgui::IPanel *v2; // edi
  unsigned int v3; // ebx
  char *ControlsModuleName; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v6; // edi
  vgui::IPanel *v7; // edi
  unsigned int v8; // eax
  vgui::IPanel_vtbl *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  vgui::IPanel_vtbl *v13; // [esp+8h] [ebp-4h]

  p_currentFocus = &this->_currentFocus;
  if ( vgui::VPanelHandle::Get(this: &this->_currentFocus) == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = vgui::VPanelHandle::Get(this: p_currentFocus);
  v13 = v2->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  result = v13->GetPanel(this: v2, a2: v3, a3: ControlsModuleName);
  v6 = result;
  if ( result != nullptr )
  {
    if ( result->IsFullyVisible(this: result) )
    {
      return v6;
    }
    else
    {
      this->RequestFocusNext(this, a2: 0);
      if ( vgui::VPanelHandle::Get(this: p_currentFocus) != 0 )
      {
        v7 = g_pVGuiPanel;
        v8 = vgui::VPanelHandle::Get(this: p_currentFocus);
        v9 = v7->__vftable;
        v10 = v8;
        v11 = vgui::GetControlsModuleName();
        return v9->GetPanel(this: v7, a2: v10, a3: v11);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C9E90
// Name: private: bool vgui::FocusNavGroup::CanButtonBeDefault(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::FocusNavGroup::CanButtonBeDefault(vgui::FocusNavGroup *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  bool v5; // bl

  if ( panel == 0 )
    return false;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "CanBeDefaultButton");
  else
    v4 = nullptr;
  v5 = false;
  if ( g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: panel, a3: v4) )
    v5 = KeyValues::GetInt(this: v4, keyName: "result", defaultValue: 0) == 1;
  KeyValues::deleteThis(this: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x103C9F00
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge vgui::FocusNavGroup::RequestFocusPrev@<al>(
        vgui::FocusNavGroup *this@<ecx>,
        int a2@<ebx>,
        unsigned int panel)
{
  int v5; // eax
  vgui::Panel *v6; // esi
  int v7; // ebx
  vgui::Panel *Child; // esi
  int v9; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ebx
  KeyValues *v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  vgui::IVGui *v22; // ebx
  vgui::IVGui_vtbl *v23; // esi
  int v24; // eax
  vgui::FocusNavGroup_vtbl *v25; // ebx
  int v26; // eax
  int bestPosition; // [esp+38h] [ebp-10h]
  int bestPositiona; // [esp+38h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+38h] [ebp-10h]
  int newPosition; // [esp+3Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+40h] [ebp-8h]
  KeyValues *besta; // [esp+40h] [ebp-8h]
  bool bRepeat; // [esp+47h] [ebp-1h]
  char bFound_3; // [esp+53h] [ebp+Bh]

  if ( panel == 0 )
    return 0;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  v5 = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  v6 = nullptr;
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 1 )
  {
    v7 = 0;
    newPosition = v5 - 1;
    if ( v5 - 1 > 0 )
      break;
LABEL_20:
    if ( !this->_topLevelFocus && this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) != bestPositiona )
      {
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        bestPositionb = this->_mainPanel;
        v13 = ((int (*)(void))bestPositionb->GetVPanel)();
        v14 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v13);
        if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v12->RequestFocusPrev)(a1: v11, a2: v14) != 0 )
        {
          bFound_3 = 1;
          this->SetCurrentDefaultButton(this, a2: 0, a3: true);
          v6 = best;
LABEL_27:
          if ( v6 != nullptr )
            goto LABEL_28;
          return bFound_3;
        }
        v6 = best;
      }
    }
    v5 = 9999999;
    bRepeat = false;
  }
  bestPosition = 0;
  if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v7);
    if ( Child != nullptr
      && Child->IsVisible(this: Child)
      && Child->IsEnabled(this: Child)
      && Child->GetTabPosition(this: Child) != 0 )
    {
      break;
    }
LABEL_14:
    if ( ++v7 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
      goto LABEL_17;
  }
  v9 = Child->GetTabPosition(this: Child);
  if ( v9 != newPosition )
  {
    if ( v9 < newPosition && v9 > bestPosition )
    {
      bestPosition = v9;
      best = Child;
    }
    goto LABEL_14;
  }
  best = Child;
LABEL_17:
  v6 = best;
LABEL_18:
  if ( !bRepeat )
    goto LABEL_27;
  if ( v6 == nullptr )
    goto LABEL_20;
LABEL_28:
  v15 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v15);
  v6->RequestFocus(this: v6, a2: -1);
  bFound_3 = 1;
  v16 = v6->GetVPanel(this: v6);
  if ( v16 != 0 )
  {
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    besta = v17 != nullptr ? KeyValues::KeyValues(this: v17, setName: "CanBeDefaultButton") : nullptr;
    v18 = g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v16, a3: besta)
       && KeyValues::GetInt(this: besta, keyName: "result", defaultValue: 0) == 1;
    KeyValues::deleteThis(this: besta);
    if ( v18 )
    {
      v25 = this->__vftable;
      v26 = ((int (__thiscall *)(vgui::Panel *, int))v6->GetVPanel)(a1: v6, a2: 1);
      ((void (__thiscall *)(vgui::FocusNavGroup *, int))v25->SetCurrentDefaultButton)(a1: this, a2: v26);
      return bFound_3;
    }
  }
  if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v19 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    ((void (__thiscall *)(vgui::FocusNavGroup *, unsigned int))this->SetCurrentDefaultButton)(a1: this, a2: v19);
    return 1;
  }
  ((void (__thiscall *)(vgui::FocusNavGroup *, _DWORD))this->SetCurrentDefaultButton)(a1: this, a2: 0);
  if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
    return bFound_3;
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "FindDefaultButton");
  else
    v21 = nullptr;
  v22 = g_pVGui;
  v23 = g_pVGui->__vftable;
  v24 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
          a1: this->_mainPanel,
          a2: v21,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v23->PostMessage)(a1: v22, a2: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103CA1E0
// Name: public: virtual bool vgui::FocusNavGroup::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::FocusNavGroup::RequestFocusNext(vgui::FocusNavGroup *this, unsigned int panel)
{
  vgui::Panel *v3; // esi
  int v4; // ebx
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi
  int v7; // eax
  vgui::Panel *mainPanel; // ebx
  vgui::IPanel *v9; // ebx
  vgui::IPanel_vtbl *v10; // esi
  int v11; // eax
  int v12; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  KeyValues *v16; // eax
  bool v17; // bl
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  vgui::IVGui *v20; // ebx
  vgui::IVGui_vtbl *v21; // esi
  int v22; // eax
  vgui::FocusNavGroup_vtbl *v23; // ebx
  unsigned int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+14h] [ebp-24h]
  BOOL v26; // [esp+18h] [ebp-20h]
  int bestPosition; // [esp+28h] [ebp-10h]
  int bestPositiona; // [esp+28h] [ebp-10h]
  vgui::Panel *bestPositionb; // [esp+28h] [ebp-10h]
  int newPosition; // [esp+2Ch] [ebp-Ch]
  int newPositiona; // [esp+2Ch] [ebp-Ch]
  KeyValues *newPositionb; // [esp+2Ch] [ebp-Ch]
  vgui::Panel *best; // [esp+30h] [ebp-8h]
  bool bRepeat; // [esp+37h] [ebp-1h]
  char bFound_3; // [esp+43h] [ebp+Bh]

  ++stack_depth;
  v3 = nullptr;
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: 0);
  newPosition = 0;
  if ( panel != 0 )
    newPosition = g_pVGuiPanel->GetTabPosition(this: g_pVGuiPanel, a2: panel);
  bFound_3 = 0;
  bRepeat = true;
  best = nullptr;
  while ( 2 )
  {
    newPositiona = newPosition + 1;
    bestPosition = 999999;
    v4 = 0;
    if ( vgui::Panel::GetChildCount(this: this->_mainPanel) <= 0 )
      goto LABEL_17;
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: this->_mainPanel, index: v4);
      v6 = Child;
      if ( Child != nullptr
        && Child->IsVisible(this: Child)
        && v6->IsEnabled(this: v6)
        && v6->GetTabPosition(this: v6) != 0 )
      {
        break;
      }
LABEL_13:
      if ( ++v4 >= vgui::Panel::GetChildCount(this: this->_mainPanel) )
        goto LABEL_16;
    }
    v7 = v6->GetTabPosition(this: v6);
    if ( v7 != newPositiona )
    {
      if ( v7 > newPositiona && v7 < bestPosition )
      {
        bestPosition = v7;
        best = v6;
      }
      goto LABEL_13;
    }
    best = v6;
LABEL_16:
    v3 = best;
LABEL_17:
    if ( !bRepeat )
    {
      if ( v3 == nullptr )
        goto LABEL_44;
    }
    else if ( v3 == nullptr )
    {
      if ( this->_topLevelFocus )
        goto LABEL_25;
      if ( this->_mainPanel->GetVParent(this: this->_mainPanel) == 0 )
        goto LABEL_25;
      mainPanel = this->_mainPanel;
      bestPositiona = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
      if ( mainPanel->GetVParent(this: mainPanel) == bestPositiona || stack_depth >= 15 )
        goto LABEL_25;
      v9 = g_pVGuiPanel;
      v10 = g_pVGuiPanel->__vftable;
      bestPositionb = this->_mainPanel;
      v11 = ((int (*)(void))bestPositionb->GetVPanel)();
      v12 = ((int (__thiscall *)(vgui::Panel *, int))bestPositionb->GetVParent)(a1: bestPositionb, a2: v11);
      if ( ((unsigned __int8 (__thiscall *)(vgui::IPanel *, int))v10->RequestFocusNext)(a1: v9, a2: v12) == 0 )
      {
        v3 = best;
LABEL_25:
        newPosition = 0;
        bRepeat = false;
        continue;
      }
      this->SetCurrentDefaultButton(this, a2: 0, a3: true);
      --stack_depth;
      return 1;
    }
    break;
  }
  v14 = v3->GetVPanel(this: v3);
  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: v14);
  v3->RequestFocus(this: v3, a2: 1);
  bFound_3 = 1;
  v15 = v3->GetVPanel(this: v3);
  if ( v15 != 0
    && ((v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u)) == nullptr
      ? (newPositionb = nullptr)
      : (newPositionb = KeyValues::KeyValues(this: v16, setName: "CanBeDefaultButton")),
        !g_pVGuiPanel->RequestInfo(this: g_pVGuiPanel, a2: v15, a3: newPositionb)
      ? (v17 = false)
      : (v17 = KeyValues::GetInt(this: newPositionb, keyName: "result", defaultValue: 0) == 1),
        KeyValues::deleteThis(this: newPositionb),
        v17) )
  {
    v23 = this->__vftable;
    v25 = ((int (__thiscall *)(vgui::Panel *, int))v3->GetVPanel)(a1: v3, a2: 1);
    v23->SetCurrentDefaultButton(this, a2: v25, a3: v26);
  }
  else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
  {
    v24 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    this->SetCurrentDefaultButton(this, a2: v24, a3: true);
  }
  else
  {
    this->SetCurrentDefaultButton(this, a2: 0, a3: true);
    if ( this->_mainPanel->GetVParent(this: this->_mainPanel) != 0 )
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "FindDefaultButton");
      else
        v19 = nullptr;
      v20 = g_pVGui;
      v21 = g_pVGui->__vftable;
      v22 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->_mainPanel->GetVParent)(
              a1: this->_mainPanel,
              a2: v19,
              a3: 0,
              a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v21->PostMessage)(a1: v20, a2: v22);
      --stack_depth;
      return 1;
    }
  }
LABEL_44:
  --stack_depth;
  return bFound_3;
}

//------------------------------------------------------------------------------
// Address: 0x103CA4E0
// Name: public: virtual unsigned int vgui::FocusNavGroup::SetCurrentFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::FocusNavGroup::SetCurrentFocus(
        vgui::FocusNavGroup *this,
        unsigned int focus,
        unsigned int defaultPanel)
{
  unsigned int v4; // edi

  vgui::VPanelHandle::Set(this: &this->_currentFocus, pent: focus);
  v4 = defaultPanel;
  if ( defaultPanel == 0 )
  {
    if ( vgui::FocusNavGroup::CanButtonBeDefault(this, panel: focus) )
    {
      v4 = focus;
    }
    else if ( vgui::VPanelHandle::Get(this: &this->_defaultButton) != 0 )
    {
      v4 = vgui::VPanelHandle::Get(this: &this->_defaultButton);
    }
  }
  this->SetCurrentDefaultButton(this, a2: v4, a3: true);
  return v4;
}

} // namespace server
