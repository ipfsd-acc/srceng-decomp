// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/editablepanel.cpp
// Functions: 43
// ============================================================

#include "vgui2\vgui_controls\editablepanel.h"

//------------------------------------------------------------------------------
// Address: 0x102A4330
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, const char *child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  CBaseServer::RemoveClientFromGame(this, panelName: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: (unsigned int)child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A43A0
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4460
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  vgui::Panel::AutoResize_e AutoResize; // eax
  vgui::Panel::AutoResize_e v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != AUTORESIZE_NO )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == AUTORESIZE_RIGHT || v6 == AUTORESIZE_DOWNANDRIGHT;
        v8 = v6 == AUTORESIZE_DOWN || v6 == AUTORESIZE_DOWNANDRIGHT;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A45E0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != AUTORESIZE_NO )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4640
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A46E0
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102A4720
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A47C0
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x102A47D0
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x102A47E0
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (const char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x102A4850
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4890
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x102A48D0
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4950
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A49D0
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A49E0
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  const char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)MemAlloc_Alloc(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x102A4AC0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102A4B10
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102A4B60
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4BA0
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4C10
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplySettings(vgui::EditablePanel *this, KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102A4C40
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102A4C90
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A4D90
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x102A4DC0
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x102A4DF0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, char *controlName, const char *string)
{
  vgui::Panel *ChildByName; // ebx
  const wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4E90
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4EF0
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: (int)state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4F50
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x102A4FC0
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_3, a4: 511, a5: defaultString);
  return buf_3;
}

//------------------------------------------------------------------------------
// Address: 0x102A4FF0
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        const char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  const char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x102A5080
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A51E0
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5240
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102A5280
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(
        vgui::EditablePanel *this,
        const char *varName,
        const char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A52D0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(
        vgui::EditablePanel *this,
        const char *varName,
        const wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5320
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, const char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5370
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, const char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A53D0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5470
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CurrentDefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5510
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FindDefaultButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A55A0
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar();
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar();
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar();
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)MemAlloc_Alloc(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: (CDragDropHelperPanel *)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102A56C0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10032670
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10032680
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  CBanPanel::OnOpenContextMenu((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100326F0
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100327B0
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032930
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032990
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032A30
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10032A70
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032B00
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10032B10
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10032B20
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x10032B90
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032BD0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x10032C10
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032C90
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032D10
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x10032D20
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x10032E00
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x10032E10
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10032E60
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10032EB0
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032EF0
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032F60
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10032F90
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10032FE0
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return BlankImage::GetNumFrames((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033040
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x100330E0
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x10033110
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x10033140
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, const char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100331E0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033240
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100332A0
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::EditablePanel::GetControlInt(
        vgui::EditablePanel *this,
        const char *controlName,
        int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  unsigned int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x10033310
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x10033340
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100333D0
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100334E0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x10033530
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10033590
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100335C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x100335D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033600
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10033640
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10033690
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x100336E0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10033730
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x100337C0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033860
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CurrentDefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033900
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "FindDefaultButton";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033990
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10033AB0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00410BA0
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00410BB0
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410C20
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410CE0
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410E60
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410EC0
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410F60
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00410FA0
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411030
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00411040
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x00411050
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x004110C0
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411100
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x00411140
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004111C0
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411240
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x00411250
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x00411320
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x00411330
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00411380
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004113D0
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411410
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411480
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x004114B0
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00411500
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return _wcsdup((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411560
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00411600
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x00411630
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x00411660
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, const char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411700
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411760
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004117C0
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x00411830
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x00411860
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x004118F0
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411A00
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x00411A50
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00411AC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411AF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00411B00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411B30
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00411B70
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00411BC0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00411C10
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00411C60
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00411CF0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411D90
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CurrentDefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411E30
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "FindDefaultButton";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411EC0
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: (CDragDropHelperPanel *)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00411FE0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10050A90
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10050AA0
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050B10
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050BD0
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050D50
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050DB0
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050E50
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10050E90
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050F20
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10050F30
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10050F40
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x10050FB0
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050FF0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x10051030
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100510B0
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051130
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x10051140
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x10051220
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x10051230
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10051280
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100512D0
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051310
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051380
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x100513B0
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10051400
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return CBaseAppSystem<IFileSystem>::GetDependencies((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051460
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10051500
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x10051530
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x10051560
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, const char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051600
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051660
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100516C0
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x10051730
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x10051760
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100517F0
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051900
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x10051950
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100519B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100519E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x100519F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051A20
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10051A60
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10051AB0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10051B00
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10051B50
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10051BE0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051C80
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CurrentDefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051D20
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "FindDefaultButton";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051DB0
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10051ED0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005FEF80
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x005FEF90
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, const char *child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed(this, panelName: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: (unsigned int)child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF000
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF0C0
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF240
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF2A0
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF340
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x005FF380
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF420
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x005FF430
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x005FF440
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x005FF4B0
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF4F0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x005FF530
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF5B0
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF630
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x005FF640
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)MemAlloc_Alloc(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x005FF720
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x005FF730
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005FF780
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005FF7D0
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF810
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FF880
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x005FF8B0
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x005FF900
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return CChildOperatorDefinition::GetName((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005FF960
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x005FFA00
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x005FFA30
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x005FFA60
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, const char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FFB00
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FFB60
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FFBC0
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x005FFC30
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x005FFC60
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x005FFCF0
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FFE00
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x005FFE50
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x005FFEB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005FFEE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x005FFEF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005FFF20
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x005FFF60
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x005FFFB0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00600000
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00600050
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x006000E0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00600180
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CurrentDefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00600220
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FindDefaultButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006002B0
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)MemAlloc_Alloc(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006003D0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102A4400
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, const char *child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  CBaseServer::RemoveClientFromGame(this, panelName: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: (unsigned int)child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4470
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4530
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  vgui::Panel::AutoResize_e AutoResize; // eax
  vgui::Panel::AutoResize_e v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != AUTORESIZE_NO )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == AUTORESIZE_RIGHT || v6 == AUTORESIZE_DOWNANDRIGHT;
        v8 = v6 == AUTORESIZE_DOWN || v6 == AUTORESIZE_DOWNANDRIGHT;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A46B0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != AUTORESIZE_NO )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4710
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A47B0
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102A47F0
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A48A0
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x102A48B0
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (const char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x102A4920
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4960
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x102A49A0
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4A20
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4AA0
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A4AB0
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)MemAlloc_Alloc(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x102A4BF0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102A4C80
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4CF0
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102A4D20
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102A4D70
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A4E70
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x102A4EA0
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x102A4ED0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, char *controlName, const char *string)
{
  vgui::Panel *ChildByName; // ebx
  const wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4F70
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4FD0
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: (int)state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5030
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x102A50A0
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_3, a4: 511, a5: defaultString);
  return buf_3;
}

//------------------------------------------------------------------------------
// Address: 0x102A50D0
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x102A5160
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A52C0
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5360
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, const char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A53B0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, const wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5400
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5450
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A54E0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5580
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CurrentDefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5620
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FindDefaultButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A56B0
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        __m128i *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)MemAlloc_Alloc(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: (CDragDropHelperPanel *)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102A57D0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102DCEF0
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DCF60
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD020
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD1A0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD200
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD2A0
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102DD2E0
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD380
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x102DD390
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x102DD3A0
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  operator delete(p: this->m_pszConfigName);
  v5 = std::char_traits<char>::length(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x102DD410
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD450
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x102DD490
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD510
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD590
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DD5A0
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: &var);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x102DD680
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102DD6D0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102DD720
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD760
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD7D0
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x102DD800
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x102DD850
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return C_OP_SetControlPointRotation::GetReadAttributes((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DD950
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x102DD980
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x102DD9B0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DDA50
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DDAB0
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: (int)state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DDB10
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x102DDB80
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_3, a4: 511, a5: defaultString);
  return buf_3;
}

//------------------------------------------------------------------------------
// Address: 0x102DDBB0
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x102DDC40
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DDDA0
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  operator delete(p: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    operator delete(p: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DDE00
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102DDE40
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DDE90
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DDEE0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DDF30
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DDF90
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE030
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CurrentDefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE0D0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FindDefaultButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE160
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: (CDragDropHelperPanel *)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DE280
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        unsigned int hScheme)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::BuildGroup *v8; // eax
  vgui::BuildGroup *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName, scheme: hScheme);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v7->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v8 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v8 != nullptr )
    v9 = vgui::BuildGroup::BuildGroup(this: v8, parentPanel: this, contextPanel: this);
  else
    v9 = nullptr;
  this->_buildGroup = v9;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v9, panel: (CDragDropHelperPanel *)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DE3A0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x1008FFF0
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10090000
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090070
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090130
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100902B0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090310
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100903B0
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100903F0
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090490
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100904A0
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x100904B0
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x10090520
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090560
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x100905A0
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090620
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100906A0
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x100906B0
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: szDescription);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x10090780
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x10090790
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100907E0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10090830
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090870
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100908E0
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10090910
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10090960
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return BlankImage::GetNumFrames((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100909C0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10090A60
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x10090A90
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x10090AC0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090B60
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090BC0
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: (int)state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090C20
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x10090C90
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x10090CC0
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10090D50
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090E60
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x10090EB0
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10090F10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10090F40
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10090F50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10090F80
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10090FC0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10091010
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10091060
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x100910B0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10091110
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100911B0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CurrentDefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091250
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "FindDefaultButton";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100912E0
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10091400
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00440AE0
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00440AF0
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440B60
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440C20
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440DA0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440E00
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440EA0
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00440EE0
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440F70
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00440F80
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x00440F90
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x00441000
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441040
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x00441080
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441100
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441180
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441190
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x00441260
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x00441270
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004412C0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00441310
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441350
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004413C0
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x004413F0
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00441440
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return BlankImage::GetNumFrames((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004414A0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00441540
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x00441570
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x004415A0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, const char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441640
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004416A0
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441700
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x00441770
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x004417A0
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00441830
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441940
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x00441990
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004419F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00441A20
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00441A30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00441A60
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00441AA0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441AF0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441B40
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441B90
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441C20
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441CC0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CurrentDefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441D60
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FindDefaultButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441DF0
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: (CDragDropHelperPanel *)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00441F10
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x004259F0
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00425A00
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebp
  const char *v5; // eax
  int v6; // edi

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: child);
  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)v4->GetPanel(this: v3, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425A60
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0.0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425B10
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *Child; // eax
  vgui::Panel *v4; // ebp
  int PinCorner; // edi
  int AutoResize; // eax
  int v7; // esi
  bool v8; // al
  bool v9; // bl
  int v10; // esi
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int y; // [esp+8h] [ebp-30h] BYREF
  int wide; // [esp+Ch] [ebp-2Ch] BYREF
  int px; // [esp+10h] [ebp-28h] BYREF
  int ox; // [esp+14h] [ebp-24h] BYREF
  int w; // [esp+18h] [ebp-20h] BYREF
  int tall; // [esp+1Ch] [ebp-1Ch] BYREF
  int py; // [esp+20h] [ebp-18h] BYREF
  int oy; // [esp+24h] [ebp-14h] BYREF
  int h; // [esp+28h] [ebp-10h] BYREF
  int i; // [esp+2Ch] [ebp-Ch] BYREF
  int j; // [esp+30h] [ebp-8h]
  vgui::EditablePanel *v25; // [esp+34h] [ebp-4h]

  v1 = this;
  v25 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, wide: &px, tall: &py);
  v2 = 0;
  for ( j = 0; v2 < vgui::Panel::GetChildCount(this: v1); v2 = j )
  {
    Child = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = Child;
    if ( Child != nullptr )
    {
      PinCorner = vgui::Panel::GetPinCorner(this: Child);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v7 = AutoResize;
      if ( PinCorner != 4 || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, x: &y, y: &wide, wide: &tall, tall: &i);
        vgui::Panel::GetPinOffset(this: v4, dx: &ox, dy: &oy);
        vgui::Panel::GetResizeOffset(this: v4, dx: &w, dy: &h);
        v8 = v7 == 1 || v7 == 3;
        v9 = v7 == 2 || v7 == 3;
        if ( PinCorner == 1 || PinCorner == 3 )
        {
          v11 = px + ox;
          if ( v8 )
            v10 = w;
          else
            v10 = v11 - tall;
          y = v10;
        }
        else
        {
          v10 = ox;
          y = ox;
          if ( v8 )
            v11 = px + w;
          else
            v11 = ox + tall;
        }
        if ( PinCorner == 2 || PinCorner == 3 )
        {
          v13 = py + oy;
          if ( v9 )
            v12 = h;
          else
            v12 = v13 - i;
          wide = v12;
        }
        else
        {
          v12 = oy;
          wide = oy;
          if ( v9 )
            v13 = h + py;
          else
            v13 = oy + i;
        }
        if ( v11 < v10 )
          v11 = v10;
        if ( v13 < v12 )
          v13 = v12;
        vgui::Panel::SetBounds(this: v4, x: v10, y: v12, wide: v11 - v10, tall: v13 - v12);
        v1 = v25;
      }
    }
    ++j;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425CB0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425D10
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0.0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425DA0
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00425DE0
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0.0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425E60
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00425E70
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x00425E80
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, char *configName, int dialogID)
{
  KeyValues *v4; // ebp
  unsigned int v5; // esi
  char *v6; // eax

  v4 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( v4 != nullptr )
    this->ApplyUserConfigSettings(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00425EF0
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425F30
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x00425F60
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  int i; // ebx
  vgui::Panel *Child; // esi
  const char *v5; // eax
  void (__thiscall **p_ApplyUserConfigSettings)(vgui::Panel *, KeyValues *); // edi
  KeyValues *Key; // eax

  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        p_ApplyUserConfigSettings = &Child->ApplyUserConfigSettings;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        (*p_ApplyUserConfigSettings)(this: Child, a2: Key);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425FD0
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  int i; // ebx
  vgui::Panel *Child; // esi
  const char *v5; // eax
  void (__thiscall **p_GetUserConfigSettings)(vgui::Panel *, KeyValues *); // edi
  KeyValues *Key; // eax

  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        p_GetUserConfigSettings = &Child->GetUserConfigSettings;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        (*p_GetUserConfigSettings)(this: Child, a2: Key);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426040
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x00426050
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  const char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x00426120
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x00426130
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00426170
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004261B0
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004261E0
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // esi
  vgui::EditablePanel *v3; // eax
  int v4; // eax
  int v5; // esi

  p_m_NavGroup = &this->m_NavGroup;
  v3 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v3 == nullptr || v3 == this )
  {
    v4 = p_m_NavGroup->GetDefaultPanel(this: p_m_NavGroup);
    v5 = v4;
    if ( v4 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 48))(a1: v4, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 392))(a1: v5);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v3->RequestFocus(this: v3, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426250
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplySettings(vgui::EditablePanel *this, KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00426280
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004262D0
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return BlankImage::GetNumFrames((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426330
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // eax
  int v6; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    v6 = v5;
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 224))(a1: v6) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x004263D0
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x00426400
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x00426430
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, const char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0.0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004264D0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426530
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426590
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x00426600
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x00426630
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = (char *)KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x004266C0
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this, int a2)
{
  vgui::IPanel *v3; // ebx
  void (__thiscall **p_SendMessage)(vgui::IPanel *, unsigned int, KeyValues *, unsigned int); // edi
  int v5; // eax
  int v6; // eax
  vgui::IPanel *v7; // ebx
  int v8; // ebp
  int (__thiscall **p_GetChildCount)(vgui::IPanel *, unsigned int); // edi
  int v10; // eax
  void (__thiscall **v11)(vgui::IPanel *, unsigned int, KeyValues *, unsigned int); // edi
  unsigned int (__thiscall **p_GetChild)(vgui::IPanel *, unsigned int, int); // ebx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  vgui::IPanel *v16; // ebx
  int (__thiscall **v17)(vgui::IPanel *, unsigned int); // edi
  int v18; // eax

  if ( this->m_pDialogVariables != nullptr )
  {
    v3 = g_pVGuiPanel;
    p_SendMessage = &g_pVGuiPanel->SendMessage;
    v5 = this->GetVPanel(this);
    v6 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v5);
    ((void (__thiscall *)(vgui::IPanel *, int))*p_SendMessage)(a1: v3, a2: v6);
    v7 = g_pVGuiPanel;
    v8 = 0;
    p_GetChildCount = &g_pVGuiPanel->GetChildCount;
    v10 = this->GetVPanel(this);
    if ( (*p_GetChildCount)(this: v7, a2: v10) > 0 )
    {
      do
      {
        v11 = &g_pVGuiPanel->SendMessage;
        p_GetChild = &g_pVGuiPanel->GetChild;
        v13 = this->GetVPanel(this);
        v14 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: v8,
                a3: this->m_pDialogVariables,
                a4: v13);
        v15 = ((int (__thiscall *)(int, int))*p_GetChild)(a1: a2, a2: v14);
        ((void (__thiscall *)(int, int))*v11)(a1: a2, a2: v15);
        v16 = g_pVGuiPanel;
        ++v8;
        v17 = &g_pVGuiPanel->GetChildCount;
        v18 = this->GetVPanel(this);
      }
      while ( v8 < (*v17)(this: v16, a2: v18) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004267E0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x00426820
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this@<ecx>, int a2@<ebp>)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00426880
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004268B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004268C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004268F0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  int v6; // [esp+0h] [ebp-4h]

  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this, a2: v6);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00426930
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, const char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax
  int v6; // [esp+0h] [ebp-4h]

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00426980
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, const char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax
  int v6; // [esp+0h] [ebp-4h]

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004269D0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, const char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax
  int v6; // [esp+0h] [ebp-4h]

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00426A20
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, const char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax
  int v6; // [esp+4h] [ebp-4h]

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00426A90
// Name: public: static void vgui::EditablePanel::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::EditablePanel::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x00426B10
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    vgui::EditablePanel::AddToMap(
      scriptname: "DefaultButtonSet",
      function: (unsigned int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)9,
      p1name: "button",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426B70
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    vgui::EditablePanel::AddToMap(
      scriptname: "CurrentDefaultButtonSet",
      function: (unsigned int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)9,
      p1name: "button",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426BD0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    vgui::EditablePanel::AddToMap(
      scriptname: "FindDefaultButton",
      function: (unsigned int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426C30
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar();
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar();
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar();
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00426D50
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0061EC10
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0061EC20
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, const char *child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed(this, panelName: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: (unsigned int)child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061EC90
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061ED50
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061EED0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061EF30
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061EFD0
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0061F010
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061F0B0
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x0061F0C0
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x0061F0D0
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x0061F140
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061F180
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x0061F1C0
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061F240
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061F2C0
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x0061F2D0
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)MemAlloc_Alloc(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x0061F3A0
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x0061F3B0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0061F400
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0061F450
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061F490
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061F500
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0061F530
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0061F580
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return CChildOperatorDefinition::GetName((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0061F5E0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0061F680
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x0061F6B0
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x0061F6E0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *string)
{
  vgui::Panel *ChildByName; // ebx
  const wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061F780
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061F7E0
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061F840
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x0061F8B0
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x0061F8E0
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x0061F970
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061FA80
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x0061FAD0
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0061FB30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0061FB60
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0061FB70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0061FBA0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0061FBE0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, const char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x0061FC30
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, const wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x0061FC80
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x0061FCD0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x0061FD60
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061FE00
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CurrentDefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061FEA0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FindDefaultButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061FF30
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)MemAlloc_Alloc(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00620050
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10040490
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x100404A0
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040510
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100405D0
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040750
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100407B0
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040850
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10040890
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040920
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10040930
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10040940
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x100409B0
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100409F0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x10040A30
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040AB0
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040B30
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x10040B40
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x10040C20
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x10040C30
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10040C80
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10040CD0
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040D10
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040D80
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10040DB0
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10040E00
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return BlankImage::GetNumFrames((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10040E60
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10040F00
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x10040F30
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x10040F60
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *string)
{
  vgui::Panel *ChildByName; // ebx
  const wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041000
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041060
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100410C0
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x10041130
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x10041160
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100411F0
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041300
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x10041350
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100413B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100413E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x100413F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10041420
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10041460
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, const char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x100414B0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, const wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10041500
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10041550
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x100415B0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041650
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CurrentDefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100416F0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "FindDefaultButton";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041780
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100418A0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10060C30
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10060C40
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060CB0
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060D70
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060EF0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060F50
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061000
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10061040
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100610D0
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100610E0
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x100610F0
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x10061160
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100611A0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x100611E0
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061260
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100612E0
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x100612F0
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x100613C0
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x100613D0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10061420
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10061470
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100614B0
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061520
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10061550
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100615A0
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return CMatSystemSurface::GetNotifyPanel((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061600
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x100616A0
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x100616D0
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x10061700
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, const char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100617A0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061800
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061860
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x100618D0
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x10061900
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10061990
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061AA0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x10061AF0
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10061B50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061B80
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10061B90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061BC0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10061C00
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10061C50
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10061CA0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10061CF0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10061D80
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061E20
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CurrentDefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061EC0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "FindDefaultButton";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061F50
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062070
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00432780
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00432790
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432800
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004328C0
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432A40
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432AA0
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432B40
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00432B80
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432C20
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00432C30
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x00432C40
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x00432CB0
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432CF0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x00432D30
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432DB0
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432E30
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x00432E40
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: &defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x00432F10
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x00432F20
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00432F70
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00432FC0
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433000
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433070
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x004330A0
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004330F0
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return _wcsdup((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00433150
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004331F0
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x00433220
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x00433250
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, const char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004332F0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433350
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004333B0
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x00433420
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_2, a4: 511, a5: defaultString);
  return buf_2;
}

//------------------------------------------------------------------------------
// Address: 0x00433450
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x004334E0
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004335F0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x00433640
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004336A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004336D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004336E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00433710
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00433750
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x004337A0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x004337F0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00433840
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x004338D0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433970
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CurrentDefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433A10
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "FindDefaultButton";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433AA0
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00433BC0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0046B730
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046B740
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebp
  const char *v5; // eax
  int v6; // edi

  CFunctorCallbackBase::ValidateFunctorData((vgui::TreeView *)this, itemIndex: child);
  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)v4->GetPanel(this: v3, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B7A0
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0.0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B850
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *Child; // eax
  vgui::Panel *v4; // ebp
  int PinCorner; // edi
  int AutoResize; // eax
  int v7; // esi
  bool v8; // al
  bool v9; // bl
  int v10; // esi
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int y; // [esp+8h] [ebp-30h] BYREF
  int wide; // [esp+Ch] [ebp-2Ch] BYREF
  int px; // [esp+10h] [ebp-28h] BYREF
  int ox; // [esp+14h] [ebp-24h] BYREF
  int w; // [esp+18h] [ebp-20h] BYREF
  int tall; // [esp+1Ch] [ebp-1Ch] BYREF
  int py; // [esp+20h] [ebp-18h] BYREF
  int oy; // [esp+24h] [ebp-14h] BYREF
  int h; // [esp+28h] [ebp-10h] BYREF
  int i; // [esp+2Ch] [ebp-Ch] BYREF
  int j; // [esp+30h] [ebp-8h]
  vgui::EditablePanel *v25; // [esp+34h] [ebp-4h]

  v1 = this;
  v25 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, wide: &px, tall: &py);
  v2 = 0;
  for ( j = 0; v2 < vgui::Panel::GetChildCount(this: v1); v2 = j )
  {
    Child = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = Child;
    if ( Child != nullptr )
    {
      PinCorner = vgui::Panel::GetPinCorner(this: Child);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v7 = AutoResize;
      if ( PinCorner != 4 || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, x: &y, y: &wide, wide: &tall, tall: &i);
        vgui::Panel::GetPinOffset(this: v4, dx: &ox, dy: &oy);
        vgui::Panel::GetResizeOffset(this: v4, dx: &w, dy: &h);
        v8 = v7 == 1 || v7 == 3;
        v9 = v7 == 2 || v7 == 3;
        if ( PinCorner == 1 || PinCorner == 3 )
        {
          v11 = px + ox;
          if ( v8 )
            v10 = w;
          else
            v10 = v11 - tall;
          y = v10;
        }
        else
        {
          v10 = ox;
          y = ox;
          if ( v8 )
            v11 = px + w;
          else
            v11 = ox + tall;
        }
        if ( PinCorner == 2 || PinCorner == 3 )
        {
          v13 = py + oy;
          if ( v9 )
            v12 = h;
          else
            v12 = v13 - i;
          wide = v12;
        }
        else
        {
          v12 = oy;
          wide = oy;
          if ( v9 )
            v13 = h + py;
          else
            v13 = oy + i;
        }
        if ( v11 < v10 )
          v11 = v10;
        if ( v13 < v12 )
          v13 = v12;
        vgui::Panel::SetBounds(this: v4, x: v10, y: v12, wide: v11 - v10, tall: v13 - v12);
        v1 = v25;
      }
    }
    ++j;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B9F0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BA50
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0.0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BAE0
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0046BB20
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0.0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BBA0
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x0046BBB0
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x0046BBC0
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, char *configName, int dialogID)
{
  KeyValues *v4; // ebp
  unsigned int v5; // esi
  char *v6; // eax

  v4 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: configName) + 1;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( v4 != nullptr )
    this->ApplyUserConfigSettings(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0046BC30
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BC70
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x0046BCA0
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  void (__thiscall **p_ApplyUserConfigSettings)(vgui::Panel *, KeyValues *); // edi
  KeyValues *Key; // eax

  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        p_ApplyUserConfigSettings = &Child->ApplyUserConfigSettings;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        (*p_ApplyUserConfigSettings)(this: Child, a2: Key);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BD10
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  void (__thiscall **p_GetUserConfigSettings)(vgui::Panel *, KeyValues *); // edi
  KeyValues *Key; // eax

  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        p_GetUserConfigSettings = &Child->GetUserConfigSettings;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        (*p_GetUserConfigSettings)(this: Child, a2: Key);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BD80
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046BD90
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  const char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)MemAlloc_Alloc(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x0046BE60
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x0046BE70
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0046BEB0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0046BEF0
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BF20
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // esi
  vgui::EditablePanel *v3; // eax
  int v4; // eax
  int v5; // esi

  p_m_NavGroup = &this->m_NavGroup;
  v3 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v3 == nullptr || v3 == this )
  {
    v4 = p_m_NavGroup->GetDefaultPanel(this: p_m_NavGroup);
    v5 = v4;
    if ( v4 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 48))(a1: v4, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 392))(a1: v5);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v3->RequestFocus(this: v3, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BF90
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplySettings(vgui::EditablePanel *this, KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x0046BFC0
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0046C010
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return CBaseAppSystem<IDataModel>::GetDependencies((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046C070
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // eax
  int v6; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    v6 = v5;
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 224))(a1: v6) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x0046C110
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x0046C140
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x0046C170
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, const char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  const wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0.0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C210
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C270
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C2D0
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x0046C340
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x0046C370
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = (char *)KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x0046C400
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this, int a2)
{
  vgui::IPanel *v3; // ebx
  void (__thiscall **p_SendMessage)(vgui::IPanel *, unsigned int, KeyValues *, unsigned int); // edi
  int v5; // eax
  int v6; // eax
  vgui::IPanel *v7; // ebx
  int v8; // ebp
  int (__thiscall **p_GetChildCount)(vgui::IPanel *, unsigned int); // edi
  int v10; // eax
  void (__thiscall **v11)(vgui::IPanel *, unsigned int, KeyValues *, unsigned int); // edi
  unsigned int (__thiscall **p_GetChild)(vgui::IPanel *, unsigned int, int); // ebx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  vgui::IPanel *v16; // ebx
  int (__thiscall **v17)(vgui::IPanel *, unsigned int); // edi
  int v18; // eax

  if ( this->m_pDialogVariables != nullptr )
  {
    v3 = g_pVGuiPanel;
    p_SendMessage = &g_pVGuiPanel->SendMessage;
    v5 = this->GetVPanel(this);
    v6 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v5);
    ((void (__thiscall *)(vgui::IPanel *, int))*p_SendMessage)(a1: v3, a2: v6);
    v7 = g_pVGuiPanel;
    v8 = 0;
    p_GetChildCount = &g_pVGuiPanel->GetChildCount;
    v10 = this->GetVPanel(this);
    if ( (*p_GetChildCount)(this: v7, a2: v10) > 0 )
    {
      do
      {
        v11 = &g_pVGuiPanel->SendMessage;
        p_GetChild = &g_pVGuiPanel->GetChild;
        v13 = this->GetVPanel(this);
        v14 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: v8,
                a3: this->m_pDialogVariables,
                a4: v13);
        v15 = ((int (__thiscall *)(int, int))*p_GetChild)(a1: a2, a2: v14);
        ((void (__thiscall *)(int, int))*v11)(a1: a2, a2: v15);
        v16 = g_pVGuiPanel;
        ++v8;
        v17 = &g_pVGuiPanel->GetChildCount;
        v18 = this->GetVPanel(this);
      }
      while ( v8 < (*v17)(this: v16, a2: v18) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C520
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x0046C560
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046C5D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046C600
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046C610
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046C640
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  int v6; // [esp+0h] [ebp-4h]

  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this, a2: v6);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0046C680
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax
  int v6; // [esp+0h] [ebp-4h]

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0046C6D0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax
  int v6; // [esp+0h] [ebp-4h]

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0046C720
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax
  int v6; // [esp+0h] [ebp-4h]

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0046C770
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax
  int v6; // [esp+4h] [ebp-4h]

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0046C7E0
// Name: public: static void vgui::EditablePanel::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::EditablePanel::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x0046C860
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    vgui::EditablePanel::AddToMap(
      scriptname: "DefaultButtonSet",
      function: (unsigned int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)9,
      p1name: "button",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C8C0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    vgui::EditablePanel::AddToMap(
      scriptname: "CurrentDefaultButtonSet",
      function: (unsigned int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)9,
      p1name: "button",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C920
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    vgui::EditablePanel::AddToMap(
      scriptname: "FindDefaultButton",
      function: (unsigned int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C980
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar();
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar();
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar();
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)MemAlloc_Alloc(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046CAA0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00421030
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00421040
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004210B0
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421170
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004212F0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421350
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004213F0
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00421430
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004214D0
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x004214E0
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x004214F0
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x00421560
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004215A0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x004215E0
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421660
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004216E0
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x004216F0
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x004217C0
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x004217D0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00421820
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00421870
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004218B0
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421920
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x00421950
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004219A0
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return BlankImage::GetNumFrames((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421A00
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00421AA0
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x00421AD0
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x00421B00
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *string)
{
  vgui::Panel *ChildByName; // ebx
  const wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421BA0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421C00
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421C60
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x00421CD0
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x00421D00
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00421D90
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421EA0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x00421EF0
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00421F50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421F80
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00421F90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421FC0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00422000
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(
        vgui::EditablePanel *this,
        const char *varName,
        const char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00422050
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(
        vgui::EditablePanel *this,
        const char *varName,
        const wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x004220A0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, const char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x004220F0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00422180
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422220
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CurrentDefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004222C0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "FindDefaultButton";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422350
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00422470
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00424A80
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00424A90
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424B00
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424BC0
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424D40
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424DA0
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424E40
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00424E80
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424F20
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00424F30
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x00424F40
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x00424FB0
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424FF0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x00425030
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004250B0
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425130
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x00425140
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  const char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: defaultValue);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x00425210
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x00425220
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00425270
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004252C0
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425300
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425370
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x004253A0
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004253F0
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return BlankImage::GetNumFrames((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425450
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004254F0
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x00425520
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x00425550
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *string)
{
  vgui::Panel *ChildByName; // ebx
  const wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004255F0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425650
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004256B0
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x00425720
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_1, a4: 511, a5: defaultString);
  return buf_1;
}

//------------------------------------------------------------------------------
// Address: 0x00425750
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = (char *)KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x004257E0
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004258F0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x00425940
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004259A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004259D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004259E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425A10
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00425A50
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, const char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00425AA0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(
        vgui::EditablePanel *this,
        const char *varName,
        const wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00425AF0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00425B40
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x00425BD0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425C70
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CurrentDefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425EC0
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10389160
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103891D0
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10389290
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10389410
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10389470
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10389510
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10389550
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103895F0
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10389600
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10389610
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  C_BaseEntity::operator delete(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)MemAlloc_Alloc(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x10389680
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103896C0
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x10389700
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  const char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10389780
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  const char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10389800
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x10389810
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  const char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)MemAlloc_Alloc(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: prType);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x103898F0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10389940
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10389990
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103899D0
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    CHudScope::LevelInit((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    CHudScope::LevelInit((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10389A40
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10389A70
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10389AC0
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10389BC0
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x10389BF0
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x10389C20
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *string)
{
  vgui::Panel *ChildByName; // ebx
  const wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10389CC0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10389D20
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10389D80
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x10389DF0
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_2, a4: 511, a5: defaultString);
  return buf_2;
}

//------------------------------------------------------------------------------
// Address: 0x10389E20
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = (char *)KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10389EB0
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038A010
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  C_BaseEntity::operator delete(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    C_BaseEntity::operator delete(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1038A070
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1038A0B0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(
        vgui::EditablePanel *this,
        const char *varName,
        const char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x1038A100
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(
        vgui::EditablePanel *this,
        const char *varName,
        const wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x1038A150
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, const char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x1038A1A0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, const char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x1038A200
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038A2A0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CurrentDefaultButtonSet";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x900000001LL;
    LODWORD(v4.m[2][2]) = "button";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038A340
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FindDefaultButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038A3D0
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar();
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar();
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar();
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)MemAlloc_Alloc(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1038A4F0
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        unsigned int hScheme)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::BuildGroup *v8; // eax
  vgui::BuildGroup *v9; // eax

  vgui::Panel::Panel(this, parent, panelName, scheme: hScheme);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v7->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar();
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar();
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar();
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v8 = (vgui::BuildGroup *)MemAlloc_Alloc(nSize: 0xD8u);
  if ( v8 != nullptr )
    v9 = vgui::BuildGroup::BuildGroup(this: v8, parentPanel: this, contextPanel: this);
  else
    v9 = nullptr;
  this->_buildGroup = v9;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v9, panel: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1038A610
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10381400
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10381410
// Name: protected: virtual void vgui::EditablePanel::OnChildAdded(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnChildAdded(vgui::EditablePanel *this, unsigned int child)
{
  vgui::IPanel *v4; // edi
  const char *v5; // eax
  int v6; // edi
  vgui::IPanel_vtbl *childa; // [esp+14h] [ebp+8h]

  CNavMesh::SaveCustomData((vgui::TreeView *)this, itemIndex: child);
  v4 = g_pVGuiPanel;
  childa = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = (int)childa->GetPanel(this: v4, a2: child, a3: v5);
  if ( v6 != 0 )
  {
    (*(void (__thiscall **)(int, vgui::BuildGroup *))(*(_DWORD *)v6 + 304))(a1: v6, a2: this->_buildGroup);
    (*(void (__thiscall **)(int, vgui::EditablePanel *))(*(_DWORD *)v6 + 188))(a1: v6, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381480
// Name: public: virtual void vgui::EditablePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnKeyCodeTyped(vgui::EditablePanel *this, ButtonCode_t code)
{
  vgui::FocusNavGroup *v3; // eax
  unsigned int v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->GetFocusNavGroup(this);
    v4 = v3->GetCurrentDefaultButton(this: v3);
    if ( v4 != 0
      && g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v4)
      && g_pVGuiPanel->IsEnabled(this: g_pVGuiPanel, a2: v4)
      && !vgui::Panel::IsConsoleStylePanel(this) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Hotkey");
      else
        v6 = nullptr;
      ((void (__thiscall *)(vgui::EditablePanel *, unsigned int, KeyValues *, _DWORD))this->PostMessage_2)(
        a1: this,
        a2: v4,
        a3: v6,
        a4: 0);
    }
    else
    {
      vgui::Panel::OnKeyCodeTyped(this, keycode: KEY_ENTER);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodeTyped(this, keycode: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381540
// Name: public: virtual void vgui::EditablePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::PerformLayout(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v1; // ebx
  int v2; // esi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // edi
  int AutoResize; // eax
  int v6; // esi
  bool v7; // al
  bool v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int i; // [esp+Ch] [ebp-34h]
  int h; // [esp+10h] [ebp-30h] BYREF
  int oy; // [esp+14h] [ebp-2Ch] BYREF
  int py; // [esp+18h] [ebp-28h] BYREF
  int tall; // [esp+1Ch] [ebp-24h] BYREF
  vgui::Panel *child; // [esp+20h] [ebp-20h]
  int w; // [esp+24h] [ebp-1Ch] BYREF
  int ox; // [esp+28h] [ebp-18h] BYREF
  int px; // [esp+2Ch] [ebp-14h] BYREF
  int wide; // [esp+30h] [ebp-10h] BYREF
  vgui::Panel::PinCorner_e pinCorner; // [esp+34h] [ebp-Ch]
  int y; // [esp+38h] [ebp-8h] BYREF
  int x; // [esp+3Ch] [ebp-4h] BYREF

  v1 = this;
  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this: v1, &wide, &tall);
  v2 = 0;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v1); v2 = i )
  {
    v3 = vgui::Panel::GetChild(this: v1, index: v2);
    v4 = v3;
    child = v3;
    if ( v3 != nullptr )
    {
      pinCorner = vgui::Panel::GetPinCorner(this: v3);
      AutoResize = vgui::Panel::GetAutoResize(this: v4);
      v6 = AutoResize;
      if ( pinCorner != PIN_NO || AutoResize != 0 )
      {
        vgui::Panel::GetBounds(this: v4, &x, &y, wide: &w, tall: &h);
        vgui::Panel::GetPinOffset(this: v4, dx: &px, dy: &py);
        vgui::Panel::GetResizeOffset(this: v4, dx: &ox, dy: &oy);
        v7 = v6 == 1 || v6 == 3;
        v8 = v6 == 2 || v6 == 3;
        if ( pinCorner == PIN_TOPRIGHT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v10 = px + wide;
          if ( v7 )
            v9 = ox;
          else
            v9 = v10 - w;
          x = v9;
        }
        else
        {
          v9 = px;
          x = px;
          if ( v7 )
            v10 = ox + wide;
          else
            v10 = px + w;
        }
        if ( pinCorner == PIN_BOTTOMLEFT || pinCorner == PIN_BOTTOMRIGHT )
        {
          v12 = tall + py;
          if ( v8 )
            v11 = oy;
          else
            v11 = v12 - h;
          y = v11;
        }
        else
        {
          v11 = py;
          y = py;
          if ( v8 )
            v12 = oy + tall;
          else
            v12 = py + h;
          v4 = child;
        }
        if ( v10 < v9 )
          v10 = v9;
        if ( v12 < v11 )
          v12 = v11;
        vgui::Panel::SetBounds(this: v4, x: v9, y: v11, wide: v10 - v9, tall: v12 - v11);
        v1 = this;
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103816C0
// Name: protected: virtual void vgui::EditablePanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSizeChanged(vgui::EditablePanel *this, int wide, int tall)
{
  int i; // edi
  vgui::Panel *Child; // eax
  vgui::Panel *v6; // esi

  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    v6 = Child;
    if ( Child != nullptr && vgui::Panel::GetAutoResize(this: Child) != 0 )
      v6->InvalidateLayout(this: v6, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381720
// Name: protected: virtual void vgui::EditablePanel::OnCurrentDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnCurrentDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int v5; // eax
  vgui::EditablePanel_vtbl *v6; // edi
  int v7; // eax

  this->m_NavGroup.SetCurrentDefaultButton(this: &this->m_NavGroup, a2: defaultButton, a3: false);
  if ( this->GetVParent(this) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CurrentDefaultButtonSet");
    else
      v4 = nullptr;
    v5 = g_pVGui->PanelToHandle(this: g_pVGui, a2: defaultButton);
    KeyValues::SetInt(this: v4, keyName: "button", value: v5);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v4, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103817C0
// Name: protected: virtual void vgui::EditablePanel::OnDefaultButtonSet(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnDefaultButtonSet(vgui::EditablePanel *this, unsigned int defaultButton)
{
  vgui::IPanel *v3; // edi
  vgui::IPanel_vtbl *v4; // ebx
  const char *v5; // eax
  vgui::Panel *v6; // eax

  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  v5 = this->GetModuleName(this);
  v6 = v4->GetPanel(this: v3, a2: defaultButton, a3: v5);
  this->m_NavGroup.SetDefaultButton(this: &this->m_NavGroup, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10381800
// Name: protected: virtual void vgui::EditablePanel::OnFindDefaultButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnFindDefaultButton(vgui::EditablePanel *this)
{
  vgui::FocusNavGroup *p_m_NavGroup; // edi
  vgui::FocusNavGroup_vtbl *v3; // esi
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  vgui::EditablePanel_vtbl *v7; // edi
  int v8; // eax

  p_m_NavGroup = &this->m_NavGroup;
  if ( this->m_NavGroup.GetDefaultButton(this: &this->m_NavGroup) != 0 )
  {
    v3 = p_m_NavGroup->__vftable;
    v4 = ((int (__thiscall *)(vgui::FocusNavGroup *, int))p_m_NavGroup->GetDefaultButton)(a1: p_m_NavGroup, a2: 1);
    ((void (__thiscall *)(vgui::FocusNavGroup *, int))v3->SetCurrentDefaultButton)(a1: p_m_NavGroup, a2: v4);
  }
  else if ( this->GetVParent(this) != 0 )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "FindDefaultButton");
    else
      v6 = nullptr;
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, _DWORD))this->GetVParent)(a1: this, a2: v6, a3: 0);
    ((void (__thiscall *)(vgui::EditablePanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381890
// Name: public: virtual void vgui::EditablePanel::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ActivateBuildMode(vgui::EditablePanel *this)
{
  this->_buildGroup->SetEnabled(this: this->_buildGroup, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x103818A0
// Name: public: virtual void vgui::EditablePanel::RegisterControlSettingsFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RegisterControlSettingsFile(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID)
{
  vgui::BuildGroup::RegisterControlSettingsFile(this: this->_buildGroup, controlResourceName: resourceName, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x103818B0
// Name: public: virtual void vgui::EditablePanel::LoadUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadUserConfig(vgui::EditablePanel *this, KeyValues *configName, int dialogID)
{
  unsigned int v5; // esi
  char *v6; // eax
  KeyValues *data; // [esp+14h] [ebp+8h]

  data = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: configName, a3: dialogID);
  free(pMem: this->m_pszConfigName);
  v5 = _V_strlen(str: (const char *)configName) + 1;
  v6 = (char *)operator new(nSize: v5);
  this->m_pszConfigName = v6;
  V_strncpy(pDest: v6, pSrc: (char *)configName, maxLen: v5);
  this->m_iConfigID = dialogID;
  if ( data != nullptr )
    this->ApplyUserConfigSettings(this, a2: data);
}

//------------------------------------------------------------------------------
// Address: 0x10381920
// Name: public: virtual void vgui::EditablePanel::SaveUserConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SaveUserConfig(vgui::EditablePanel *this)
{
  char *m_pszConfigName; // eax
  KeyValues *v3; // eax

  m_pszConfigName = this->m_pszConfigName;
  if ( m_pszConfigName != nullptr )
  {
    v3 = g_pVGuiSystem->GetUserConfigFileData(this: g_pVGuiSystem, a2: m_pszConfigName, a3: this->m_iConfigID);
    if ( v3 != nullptr )
      this->GetUserConfigSettings(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381960
// Name: public: virtual void vgui::EditablePanel::LoadControlSettingsAndUserConfig(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettingsAndUserConfig(
        vgui::EditablePanel *this,
        const char *dialogResourceName,
        int dialogID)
{
  this->LoadControlSettings(this, a2: dialogResourceName, a3: nullptr, a4: nullptr, a5: nullptr);
  this->LoadUserConfig(this, a2: dialogResourceName, a3: dialogID);
}

//------------------------------------------------------------------------------
// Address: 0x103819A0
// Name: protected: virtual void vgui::EditablePanel::ApplyUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ApplyUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->ApplyUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381A20
// Name: protected: virtual void vgui::EditablePanel::GetUserConfigSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetUserConfigSettings(vgui::EditablePanel *this, KeyValues *userConfig)
{
  vgui::EditablePanel *v2; // edi
  int i; // ebx
  vgui::Panel *Child; // esi
  char *v5; // eax
  vgui::Panel_vtbl *v6; // edi
  KeyValues *Key; // eax

  v2 = this;
  for ( i = 0; i < vgui::Panel::GetChildCount(this: v2); ++i )
  {
    Child = vgui::Panel::GetChild(this: v2, index: i);
    if ( Child->HasUserConfigSettings(this: Child) )
    {
      v5 = (char *)Child->GetName(this: Child);
      if ( v5 != nullptr && *v5 != 0 )
      {
        v6 = Child->__vftable;
        Key = KeyValues::FindKey(this: userConfig, keyName: v5, bCreate: true);
        v6->GetUserConfigSettings(this: Child, a2: Key);
        v2 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381AA0
// Name: protected: virtual void vgui::EditablePanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnClose(vgui::EditablePanel *this)
{
  this->SaveUserConfig(this);
}

//------------------------------------------------------------------------------
// Address: 0x10381AB0
// Name: public: virtual bool vgui::EditablePanel::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestInfo(vgui::EditablePanel *this, KeyValues *data)
{
  const char *Name; // eax
  vgui::BuildModeDialog *v4; // edi
  vgui::BuildGroup *Ptr; // eax
  vgui::BuildModeDialog *v6; // eax
  vgui::Panel *v8; // eax
  const char *v9; // eax
  vgui::EditablePanel_vtbl *v10; // ebx
  char *String; // eax

  Name = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: Name, s2: "BuildDialog") == 0 )
  {
    v4 = (vgui::BuildModeDialog *)operator new(nSize: 0x384u);
    if ( v4 != nullptr )
    {
      Ptr = (vgui::BuildGroup *)KeyValues::GetPtr(this: data, keyName: "BuildGroupPtr", defaultValue: nullptr);
      v6 = vgui::BuildModeDialog::BuildModeDialog(this: v4, buildGroup: Ptr);
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v6);
      return true;
    }
    v8 = nullptr;
    goto LABEL_5;
  }
  v9 = KeyValues::GetName(this: data);
  if ( _V_stricmp(s1: v9, s2: "ControlFactory") == 0 )
  {
    v10 = this->__vftable;
    String = KeyValues::GetString(this: data, keyName: "ControlName", defaultValue: locale);
    v8 = v10->CreateControlByName(this, a2: String);
    if ( v8 != nullptr )
    {
LABEL_5:
      KeyValues::SetPtr(this: data, keyName: "PanelPtr", value: v8);
      return true;
    }
  }
  return vgui::Panel::RequestInfo(this, outputData: data);
}

//------------------------------------------------------------------------------
// Address: 0x10381B80
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x10381B90
// Name: public: virtual bool vgui::EditablePanel::RequestFocusNext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusNext(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusNext(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateDown(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10381BE0
// Name: public: virtual bool vgui::EditablePanel::RequestFocusPrev(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::EditablePanel::RequestFocusPrev(vgui::EditablePanel *this, unsigned int panel)
{
  bool v3; // bl

  v3 = this->m_NavGroup.RequestFocusPrev(this: &this->m_NavGroup, a2: panel);
  if ( !v3 && vgui::Panel::IsConsoleStylePanel(this) )
    this->NavigateUp(this);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10381C30
// Name: public: virtual void vgui::EditablePanel::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::RequestFocus(vgui::EditablePanel *this, int direction)
{
  if ( direction == 1 )
  {
    this->RequestFocusNext(this, a2: 0);
  }
  else if ( direction == -1 )
  {
    this->RequestFocusPrev(this, a2: 0);
  }
  else
  {
    vgui::Panel::RequestFocus(this, direction: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381C70
// Name: public: virtual void vgui::EditablePanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnSetFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  int v3; // eax
  int v4; // esi

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  if ( v2 == nullptr || v2 == this )
  {
    v3 = this->m_NavGroup.GetDefaultPanel(this: &this->m_NavGroup);
    v4 = v3;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 392))(a1: v4);
    }
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
  else
  {
    v2->RequestFocus(this: v2, a2: 0);
    vgui::Panel::OnKillFocus((vgui::TextEntry *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381CE0
// Name: public: virtual void vgui::EditablePanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::EditablePanel::ApplySettings(
        vgui::EditablePanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *inResourceData)
{
  vgui::Panel::ApplySettings(this, a2, a3: (int)inResourceData, inResourceData);
  this->_buildGroup->ApplySettings(this: this->_buildGroup, a2: inResourceData);
}

//------------------------------------------------------------------------------
// Address: 0x10381D10
// Name: public: virtual void vgui::EditablePanel::OnRequestFocus(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::OnRequestFocus(
        vgui::EditablePanel *this,
        unsigned int subFocus,
        unsigned int defaultPanel)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-4h] [ebp-Ch]

  if ( g_pVGuiPanel->IsPopup(this: g_pVGuiPanel, a2: subFocus) )
    v4 = defaultPanel;
  else
    v4 = this->m_NavGroup.SetCurrentFocus(this: &this->m_NavGroup, a2: subFocus, a3: defaultPanel);
  v6 = v4;
  v5 = this->GetVPanel(this);
  vgui::Panel::OnRequestFocus(this, subFocus: v5, defaultPanel: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10381D60
// Name: public: virtual unsigned int vgui::EditablePanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetCurrentKeyFocus(vgui::EditablePanel *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // esi
  int result; // eax

  v2 = (vgui::EditablePanel *)this->m_NavGroup.GetCurrentFocus(this: &this->m_NavGroup);
  v3 = v2;
  if ( v2 == this )
    return 0;
  if ( v2 == nullptr || v2->IsPopup(this: v2) )
    return CHEGrenade::YouForgotToImplementOrDeclareServerClass((vgui::CTreeViewListControl *)this);
  result = v3->GetCurrentKeyFocus(this: v3);
  if ( result == 0 )
    return v3->GetVPanel(this: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10381DC0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10381E60
// Name: public: virtual void vgui::EditablePanel::SetControlEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlEnabled(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL enabled)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetEnabled(this: ChildByName, a2: enabled);
}

//------------------------------------------------------------------------------
// Address: 0x10381E90
// Name: public: virtual void vgui::EditablePanel::SetControlVisible(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlVisible(
        vgui::EditablePanel *this,
        const char *controlName,
        BOOL visible)
{
  vgui::Panel *ChildByName; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
    ChildByName->SetVisible(this: ChildByName, a2: visible);
}

//------------------------------------------------------------------------------
// Address: 0x10381EC0
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(vgui::EditablePanel *this, const char *controlName, char *string)
{
  vgui::Panel *ChildByName; // ebx
  wchar_t *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    if ( *string == 35 )
    {
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: string);
      if ( v5 == nullptr )
        return;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: v5);
LABEL_9:
        ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
          a1: this,
          a2: ChildByName,
          a3: v7,
          a4: 0);
        return;
      }
    }
    else
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v8, setName: "SetText", firstKey: "text", firstValue: string);
        goto LABEL_9;
      }
    }
    v7 = nullptr;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381F60
// Name: public: virtual void vgui::EditablePanel::SetControlString(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        wchar_t *string)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetText", firstKey: "text", firstValue: string);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10381FC0
// Name: public: virtual void vgui::EditablePanel::SetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetControlInt(vgui::EditablePanel *this, const char *controlName, int state)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "SetState", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::EditablePanel *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: ChildByName,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10382020
// Name: public: virtual int vgui::EditablePanel::GetControlInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::EditablePanel::GetControlInt(vgui::EditablePanel *this, const char *controlName, int defaultState)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int Int; // edi

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  if ( ChildByName == nullptr )
    return defaultState;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GetState") : nullptr;
  if ( !ChildByName->RequestInfo(this: ChildByName, a2: v5) )
    return defaultState;
  Int = KeyValues::GetInt(this: v5, keyName: "state", defaultValue: defaultState);
  KeyValues::deleteThis(this: v5);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x10382090
// Name: public: virtual char const __near * vgui::EditablePanel::GetControlString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        const char *defaultString)
{
  this->GetControlString(this, a2: controlName, a3: buf_2, a4: 511, a5: defaultString);
  return buf_2;
}

//------------------------------------------------------------------------------
// Address: 0x103820C0
// Name: public: virtual void vgui::EditablePanel::GetControlString(char const __near *,char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::GetControlString(
        vgui::EditablePanel *this,
        const char *controlName,
        char *buf,
        int bufSize,
        char *defaultString)
{
  vgui::Panel *ChildByName; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  int v8; // edi
  char *String; // [esp-8h] [ebp-14h]
  int v10; // [esp-4h] [ebp-10h]

  ChildByName = vgui::Panel::FindChildByName(this, childName: controlName, recurseDown: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "GetText");
  else
    v7 = nullptr;
  if ( ChildByName != nullptr && ChildByName->RequestInfo(this: ChildByName, a2: v7) )
  {
    v8 = bufSize;
    v10 = bufSize;
    String = KeyValues::GetString(this: v7, keyName: "text", defaultValue: defaultString);
  }
  else
  {
    v8 = bufSize;
    v10 = bufSize;
    String = defaultString;
  }
  V_strncpy(pDest: buf, pSrc: String, maxLen: v10);
  buf[v8 - 1] = 0;
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10382150
// Name: private: void vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(vgui::EditablePanel *this)
{
  vgui::IPanel *v2; // ebx
  vgui::IPanel_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  vgui::IPanel *v6; // ebx
  vgui::IPanel_vtbl *v7; // edi
  int v8; // eax
  vgui::IPanel_vtbl *v9; // edi
  vgui::IPanel_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vgui::IPanel *v14; // ebx
  vgui::IPanel_vtbl *v15; // edi
  int v16; // eax
  vgui::IPanel *v17; // [esp+4h] [ebp-Ch]
  vgui::IPanel *v18; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_pDialogVariables != nullptr )
  {
    v2 = g_pVGuiPanel;
    v3 = g_pVGuiPanel->__vftable;
    v4 = this->GetVPanel(this);
    v5 = ((int (__thiscall *)(vgui::EditablePanel *, KeyValues *, int))this->GetVPanel)(
           a1: this,
           a2: this->m_pDialogVariables,
           a3: v4);
    ((void (__thiscall *)(vgui::IPanel *, int))v3->SendMessage)(a1: v2, a2: v5);
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    i = 0;
    v8 = this->GetVPanel(this);
    if ( v7->GetChildCount(this: v6, a2: v8) > 0 )
    {
      do
      {
        v9 = g_pVGuiPanel->__vftable;
        v10 = g_pVGuiPanel->__vftable;
        v18 = g_pVGuiPanel;
        v17 = g_pVGuiPanel;
        v11 = this->GetVPanel(this);
        v12 = ((int (__thiscall *)(vgui::EditablePanel *, int, KeyValues *, int))this->GetVPanel)(
                a1: this,
                a2: i,
                a3: this->m_pDialogVariables,
                a4: v11);
        v13 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v18, a2: v12);
        ((void (__thiscall *)(vgui::IPanel *, int))v9->SendMessage)(a1: v17, a2: v13);
        v14 = g_pVGuiPanel;
        ++i;
        v15 = g_pVGuiPanel->__vftable;
        v16 = this->GetVPanel(this);
      }
      while ( i < v15->GetChildCount(this: v14, a2: v16) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10382260
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x103822A0
// Name: public: virtual vgui::EditablePanel::~EditablePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::~EditablePanel(vgui::EditablePanel *this)
{
  vgui::BuildGroup *buildGroup; // edi
  KeyValues *m_pDialogVariables; // ecx

  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  vgui::Panel::SetBuildGroup(this, buildGroup: nullptr);
  free(pMem: this->m_pszConfigName);
  buildGroup = this->_buildGroup;
  if ( buildGroup != nullptr )
  {
    vgui::BuildGroup::~BuildGroup(this: this->_buildGroup);
    free(pMem: buildGroup);
  }
  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables != nullptr )
    KeyValues::deleteThis(this: m_pDialogVariables);
  vgui::FocusNavGroup::~FocusNavGroup(this: &this->m_NavGroup);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10382310
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10382340
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10382350
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
  `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10382380
// Name: public: virtual void vgui::EditablePanel::LoadControlSettings(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::LoadControlSettings(
        vgui::EditablePanel *this,
        const char *resourceName,
        const char *pathID,
        KeyValues *pKeyValues,
        KeyValues *pConditions)
{
  this->_buildGroup->LoadControlSettings(
    this: this->_buildGroup,
    a2: resourceName,
    a3: pathID,
    a4: pKeyValues,
    a5: pConditions);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103823C0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, char *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10382410
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, wchar_t *value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetWString(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10382460
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, int value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetInt(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x103824B0
// Name: public: virtual void vgui::EditablePanel::SetDialogVariable(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::EditablePanel::SetDialogVariable(vgui::EditablePanel *this, char *varName, float value)
{
  KeyValues *m_pDialogVariables; // eax
  KeyValues *v5; // eax

  m_pDialogVariables = this->m_pDialogVariables;
  if ( m_pDialogVariables == nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      m_pDialogVariables = KeyValues::KeyValues(this: v5, setName: "DialogVariables");
    else
      m_pDialogVariables = nullptr;
    this->m_pDialogVariables = m_pDialogVariables;
  }
  KeyValues::SetFloat(this: m_pDialogVariables, keyName: varName, value);
  vgui::EditablePanel::ForceSubPanelsToUpdateWithNewDialogVariables(this);
}

//------------------------------------------------------------------------------
// Address: 0x10382540
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{928,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103825E0
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::EditablePanel::`vcall'{932,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CurrentDefaultButtonSet";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_HANDLE;
    v4.firstParamName = "button";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10382680
// Name: public: static void vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded )
  {
    `vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSceneEntity::`vcall'{936,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "FindDefaultButton";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10382710
// Name: public: vgui::EditablePanel::EditablePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall vgui::EditablePanel::EditablePanel(
        vgui::EditablePanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::BuildGroup *v7; // eax
  vgui::BuildGroup *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::EditablePanel_vtbl *)&vgui::EditablePanel::`vftable';
  if ( `vgui::EditablePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
    v4->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "EditablePanel");
    v5->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::EditablePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::EditablePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
    v6->pfnClassName = vgui::EditablePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::EditablePanel::PanelMessageFunc_OnDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnCurrentDefaultButtonSet::InitVar(a1: (int)&savedregs);
  vgui::EditablePanel::PanelMessageFunc_OnFindDefaultButton::InitVar(a1: (int)&savedregs);
  vgui::FocusNavGroup::FocusNavGroup(this: &this->m_NavGroup, panel: this);
  v7 = (vgui::BuildGroup *)operator new(nSize: 0xD8u);
  if ( v7 != nullptr )
    v8 = vgui::BuildGroup::BuildGroup(this: v7, parentPanel: this, contextPanel: this);
  else
    v8 = nullptr;
  this->_buildGroup = v8;
  this->m_pszConfigName = nullptr;
  this->m_iConfigID = 0;
  this->m_pDialogVariables = nullptr;
  vgui::BuildGroup::PanelAdded(this: v8, panel: (CDragDropHelperPanel *)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10382830
// Name: Create_EditablePanel
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__cdecl Create_EditablePanel()
{
  vgui::EditablePanel *v0; // eax

  v0 = (vgui::EditablePanel *)operator new(nSize: 0x17Cu);
  if ( v0 != nullptr )
    return vgui::EditablePanel::EditablePanel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace server
