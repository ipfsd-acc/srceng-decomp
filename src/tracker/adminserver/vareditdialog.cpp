// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/vareditdialog.cpp
// Functions: 6
// ============================================================

#include "tracker\adminserver\vareditdialog.h"

//------------------------------------------------------------------------------
// Address: 0x10004090
// Name: public: CVarEditDialog::CVarEditDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVarEditDialog *__thiscall CVarEditDialog::CVarEditDialog(CVarEditDialog *this, vgui::Panel *parent, const char *name)
{
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::ComboBox *v10; // eax
  vgui::ComboBox *v11; // eax

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CVarEditDialog_vtbl *)&CVarEditDialog::`vftable';
  vgui::Panel::SetSize(this, wide: 280, tall: 180);
  vgui::Frame::SetSizeable(this, state: false);
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: "OKButton",
           text: "OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v5 = nullptr;
  this->m_pOKButton = v5;
  v6 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "CancelButton",
           text: "Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  this->m_pCancelButton = v7;
  v8 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextEntry::TextEntry(this: v8, parent: this, panelName: "StringEdit");
  else
    v9 = nullptr;
  this->m_pStringEdit = v9;
  v10 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v10 != nullptr )
    v11 = vgui::ComboBox::ComboBox(this: v10, parent: this, panelName: "ComboEdit", numLines: 12, allowEdit: false);
  else
    v11 = nullptr;
  this->m_pComboEdit = v11;
  this->m_pRules = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004190
// Name: public: static char const __near * vgui::Frame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Frame::GetPanelClassName()
{
  return "Frame";
}

//------------------------------------------------------------------------------
// Address: 0x100041A0
// Name: public: void CVarEditDialog::Activate(class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarEditDialog::Activate(CVarEditDialog *this, vgui::Panel *actionSignalTarget, KeyValues *rules)
{
  KeyValues *Copy; // eax
  const char *String; // edi
  KeyValues *Key; // eax
  KeyValues *i; // edi
  vgui::ComboBox_vtbl *v8; // ebx
  const char *v9; // eax
  int Int; // eax
  unsigned __int8 *v11; // ebx
  const char *v12; // eax
  unsigned int v13; // edi
  vgui::ComboBox *m_pComboEdit; // ecx
  int v15; // edi
  vgui::TextEntry_vtbl *v16; // edi
  const char *v17; // eax
  const char *v18; // eax
  char title[256]; // [esp+Ch] [ebp-140h] BYREF
  char customString[64]; // [esp+10Ch] [ebp-40h] BYREF
  const char *end; // [esp+154h] [ebp+8h]
  const char *currentValue; // [esp+158h] [ebp+Ch]

  this->AddActionSignalTarget_2(this, a2: actionSignalTarget);
  Copy = KeyValues::MakeCopy(this: rules);
  this->m_pRules = Copy;
  String = KeyValues::GetString(this: Copy, keyName: "type", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "enumeration") != 0 )
  {
    if ( _V_stricmp(s1: String, s2: "customlist") != 0 )
    {
      this->LoadControlSettings(this, a2: "Admin/VarEditDialog_String.res", a3: "PLATFORM", a4: nullptr, a5: nullptr);
      this->m_pComboEdit->SetVisible(this: this->m_pComboEdit, a2: false);
      vgui::TextEntry::SelectAllOnFirstFocus(this: this->m_pStringEdit, status: true);
      v16 = this->m_pStringEdit->__vftable;
      v17 = KeyValues::GetString(this: this->m_pRules, keyName: "value", defaultValue: defaultValue);
      v16->SetText(this: this->m_pStringEdit, a2: v17);
    }
    else
    {
      this->LoadControlSettings(this, a2: "Admin/VarEditDialog_ComboBox.res", a3: "PLATFORM", a4: nullptr, a5: nullptr);
      this->m_pStringEdit->SetVisible(this: this->m_pStringEdit, a2: false);
      currentValue = KeyValues::GetString(this: this->m_pRules, keyName: "value", defaultValue: defaultValue);
      v11 = (unsigned __int8 *)KeyValues::GetString(
                                 this: this->m_pRules,
                                 keyName: "stringlist",
                                 defaultValue: defaultValue);
      while ( *v11 != 0 )
      {
        if ( *v11 == 10 )
        {
          ++v11;
        }
        else
        {
          strstr(str1: v11, str2: "\n");
          end = v12;
          if ( v12 == nullptr )
            break;
          v13 = v12 - (const char *)v11;
          if ( (unsigned int)(v12 - (const char *)v11) >= 0x40 )
            v13 = 63;
          strncpy(dest: (unsigned __int8 *)customString, source: v11, count: v13);
          m_pComboEdit = this->m_pComboEdit;
          v11 = (unsigned __int8 *)end;
          customString[v13] = 0;
          v15 = m_pComboEdit->AddItem_2(this: m_pComboEdit, a2: customString, a3: nullptr);
          if ( _V_stricmp(s1: customString, s2: currentValue) == 0 )
            this->m_pComboEdit->ActivateItem(this: this->m_pComboEdit, a2: v15);
        }
      }
    }
  }
  else
  {
    this->LoadControlSettings(this, a2: "Admin/VarEditDialog_ComboBox.res", a3: "PLATFORM", a4: nullptr, a5: nullptr);
    this->m_pStringEdit->SetVisible(this: this->m_pStringEdit, a2: false);
    Key = KeyValues::FindKey(this: this->m_pRules, keyName: "list", bCreate: true);
    for ( i = KeyValues::GetFirstSubKey(this: Key); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      v8 = this->m_pComboEdit->__vftable;
      v9 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
      v8->AddItem_2(this: this->m_pComboEdit, a2: v9, a3: nullptr);
    }
    Int = KeyValues::GetInt(this: this->m_pRules, keyName: "enum", defaultValue: 0);
    vgui::ComboBox::ActivateItemByRow(this: this->m_pComboEdit, row: Int);
  }
  v18 = KeyValues::GetString(this: this->m_pRules, keyName: "name", defaultValue: defaultValue);
  _snprintf(string: title, count: 0xFFu, format: "Change %s", v18);
  this->SetTitle_2(this, a2: title, a3: false);
  this->MoveToCenterOfScreen(this);
  vgui::Frame::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10004460
// Name: protected: void CVarEditDialog::ApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarEditDialog::ApplyChanges(CVarEditDialog *this)
{
  const char *String; // edi
  int ActiveItem; // eax
  vgui::ComboBox *m_pStringEdit; // ecx
  CRemoteServer *v5; // eax
  KeyValues *v6; // edi
  const char *v7; // eax
  KeyValues *v8; // eax
  const char *Name; // [esp-8h] [ebp-230h]
  char *v10; // [esp-4h] [ebp-22Ch]
  char v11[512]; // [esp+8h] [ebp-220h] BYREF
  char value[32]; // [esp+208h] [ebp-20h] BYREF

  String = KeyValues::GetString(this: this->m_pRules, keyName: "type", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "enumeration") != 0 )
  {
    if ( _V_stricmp(s1: String, s2: "customlist") != 0 )
      m_pStringEdit = (vgui::ComboBox *)this->m_pStringEdit;
    else
      m_pStringEdit = this->m_pComboEdit;
    m_pStringEdit->GetText_2(this: m_pStringEdit, a2: v11, a3: 512);
    v10 = v11;
  }
  else
  {
    ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pComboEdit);
    _snprintf(string: value, count: 0x1Fu, format: "%d", ActiveItem);
    v10 = value;
  }
  Name = KeyValues::GetName(this: this->m_pRules);
  v5 = RemoteServer();
  CRemoteServer::SetValue(this: v5, variable: Name, value: v10);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
  {
    v7 = KeyValues::GetName(this: this->m_pRules);
    v8 = KeyValues::KeyValues(this: v6, setName: "VarChanged", firstKey: "var", firstValue: v7);
    this->PostActionSignal(this, a2: v8);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004620
// Name: protected: virtual void CVarEditDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarEditDialog::OnCommand(CVarEditDialog *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command);
    else
      this->Close(this);
  }
  else
  {
    CVarEditDialog::ApplyChanges(this);
    this->Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008100
// Name: protected: virtual void CVarEditDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarEditDialog::OnClose(CVarEditDialog *this)
{
  vgui::Frame::OnClose(this);
  this->MarkForDeletion(this);
}
