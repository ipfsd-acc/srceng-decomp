// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/keyvalues_editor/kv_leaf_panel.cpp
// Functions: 12
// ============================================================

#include "missionchooser\keyvalues_editor\kv_leaf_panel.h"

//------------------------------------------------------------------------------
// Address: 0x1000EF90
// Name: public: static char const __near * CKV_Leaf_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Leaf_Panel::GetPanelClassName()
{
  return "CKV_Leaf_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x1000EFA0
// Name: public: virtual void CKV_Leaf_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Leaf_Panel::PerformLayout(CKV_Combo_Leaf_Panel *this)
{
  int v2; // eax
  KeyValues *m_pFileSpecNode; // ecx
  int Tall; // ebx
  int v5; // edi
  KeyValues *v6; // ecx
  int v7; // eax
  int Wide; // eax
  int Int; // [esp-4h] [ebp-10h]

  CKV_Editor_Base_Panel::PerformLayout(this);
  vgui::Panel::SetBounds(this: this->m_pLabel, x: 0, y: 0, wide: 100, tall: 20);
  this->m_pLabel->SizeToContents(this: this->m_pLabel);
  this->m_pLabel->InvalidateLayout(this: this->m_pLabel, a2: true, a3: false);
  if ( vgui::Panel::GetWide(this: this->m_pLabel) + 5 <= 100 )
    v2 = 100;
  else
    v2 = vgui::Panel::GetWide(this: this->m_pLabel) + 5;
  m_pFileSpecNode = this->m_pFileSpecNode;
  Tall = 0;
  v5 = v2;
  if ( m_pFileSpecNode != nullptr
    && KeyValues::FindKey(this: m_pFileSpecNode, keyName: "TextEntryNewLine", bCreate: false) != nullptr )
  {
    Tall = vgui::Panel::GetTall(this: this->m_pLabel);
    v5 = 0;
  }
  v6 = this->m_pFileSpecNode;
  if ( v6 != nullptr && KeyValues::FindKey(this: v6, keyName: "Tall", bCreate: false) != nullptr )
  {
    Int = KeyValues::GetInt(this: this->m_pFileSpecNode, keyName: "Tall", defaultValue: 0);
    vgui::Panel::SetBounds(this: this->m_pCombo, x: v5, y: Tall, wide: 390 - v5, tall: Int);
  }
  else
  {
    vgui::Panel::SetBounds(this: this->m_pCombo, x: v5, y: Tall, wide: 390 - v5, tall: 20);
  }
  v7 = vgui::Panel::GetTall(this: this->m_pCombo);
  vgui::Panel::SetSize(this, wide: 420, tall: Tall + v7);
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pDeleteButton, x: Wide - 25, y: 2, wide: 20, tall: 16);
}

//------------------------------------------------------------------------------
// Address: 0x1000F0C0
// Name: public: virtual void CKV_Leaf_Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Leaf_Panel::ApplySchemeSettings(CKV_Leaf_Panel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
  this->SetPaintBackgroundEnabled(this, a2: false);
  this->m_pDeleteButton->SetVisible(this: this->m_pDeleteButton, a2: this->m_bAllowDeletion);
}

//------------------------------------------------------------------------------
// Address: 0x1000F110
// Name: public: virtual void CKV_Leaf_Panel::UpdatePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Leaf_Panel::UpdatePanel(CKV_Leaf_Panel *this)
{
  KeyValues *m_pFileSpecNode; // ecx
  vgui::Button_vtbl *v3; // edi
  KeyValues *Key; // eax
  KeyValues *v5; // ecx
  vgui::Label_vtbl *v6; // edi
  const char *String; // eax
  vgui::TextEntry_vtbl *v8; // edi
  const char *v9; // eax

  m_pFileSpecNode = this->m_pFileSpecNode;
  if ( m_pFileSpecNode != nullptr )
  {
    v3 = this->m_pDeleteButton->__vftable;
    Key = KeyValues::FindKey(this: m_pFileSpecNode, keyName: "Deletable", bCreate: false);
    v3->SetVisible(this: this->m_pDeleteButton, a2: Key != nullptr);
  }
  if ( this->m_pKey != nullptr )
  {
    v5 = this->m_pFileSpecNode;
    if ( v5 != nullptr && KeyValues::FindKey(this: v5, keyName: "FriendlyName", bCreate: false) != nullptr )
    {
      v6 = this->m_pLabel->__vftable;
      String = KeyValues::GetString(this: this->m_pFileSpecNode, keyName: "FriendlyName", defaultValue: szDescription);
    }
    else
    {
      v6 = this->m_pLabel->__vftable;
      String = KeyValues::GetName(this: this->m_pKey);
    }
    v6->SetText(this: this->m_pLabel, a2: String);
    v8 = this->m_pTextEntry->__vftable;
    v9 = KeyValues::GetString(this: this->m_pKey, keyName: nullptr, defaultValue: szDescription);
    v8->SetText(this: this->m_pTextEntry, a2: v9);
    if ( KeyValues::GetInt(this: this->m_pFileSpecNode, keyName: "ReadOnly", defaultValue: 0) == 1 )
    {
      this->m_pTextEntry->SetEditable(this: this->m_pTextEntry, a2: false);
      this->m_pTextEntry->SetEnabled(this: this->m_pTextEntry, a2: false);
    }
  }
  else
  {
    this->m_pLabel->SetText(this: this->m_pLabel, a2: "INVALID KEY");
    this->m_pTextEntry->SetText(this: this->m_pTextEntry, a2: "INVALID KEY");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F250
// Name: public: virtual void CKV_Leaf_Panel::TextEntryChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Leaf_Panel::TextEntryChanged(CKV_Leaf_Panel *this, vgui::TextEntry *pTextEntry)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char buf[2048]; // [esp+4h] [ebp-800h] BYREF

  if ( pTextEntry == this->m_pTextEntry && this->m_pKey != nullptr )
  {
    this->m_pTextEntry->GetText_2(this: this->m_pTextEntry, a2: buf, a3: 2048);
    KeyValues::SetStringValue(this: this->m_pKey, strValue: buf);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "command", firstKey: "command", firstValue: "KeyValuesChanged");
      this->PostActionSignal(this, a2: v4);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F2F0
// Name: public: virtual void CKV_Leaf_Panel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Leaf_Panel::OnCommand(CKV_Leaf_Panel *this, const char *command)
{
  KeyValues *m_pKeyParent; // ecx

  if ( _V_stricmp(s1: command, s2: "Delete") == 0
    && (m_pKeyParent = this->m_pKeyParent) != nullptr
    && this->m_bAllowDeletion )
  {
    KeyValues::RemoveSubKey(this: m_pKeyParent, subKey: this->m_pKey);
    KeyValues::deleteThis(this: this->m_pKey);
    this->m_pEditor->OnKeyDeleted(this: this->m_pEditor);
  }
  else
  {
    vgui::Panel::OnCommand(this, command);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F360
// Name: public: static void CKV_Leaf_Panel::PanelMessageFunc_TextEntryChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CKV_Leaf_Panel::PanelMessageFunc_TextEntryChanged::InitVar(int a1@<ebp>)
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
  if ( !`CKV_Leaf_Panel::PanelMessageFunc_TextEntryChanged::InitVar'::`2'::bAdded )
  {
    `CKV_Leaf_Panel::PanelMessageFunc_TextEntryChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CKV_Node_Panel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CKV_Leaf_Panel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "TextChanged";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F400
// Name: public: CKV_Leaf_Panel::CKV_Leaf_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Leaf_Panel *__thiscall CKV_Leaf_Panel::CKV_Leaf_Panel(CKV_Leaf_Panel *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Button *v11; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CKV_Editor_Base_Panel::CKV_Editor_Base_Panel(this, parent, name);
  this->__vftable = (CKV_Leaf_Panel_vtbl *)&CKV_Leaf_Panel::`vftable';
  if ( `CKV_Leaf_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Leaf_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Leaf_Panel");
    v4->pfnClassName = CKV_Leaf_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Leaf_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Leaf_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Leaf_Panel");
    v5->pfnClassName = CKV_Leaf_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Leaf_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Leaf_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Leaf_Panel");
    v6->pfnClassName = CKV_Leaf_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Base_Panel");
  }
  CKV_Leaf_Panel::PanelMessageFunc_TextEntryChanged::InitVar(a1: (int)&savedregs);
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "Label", text: szDescription);
  else
    v8 = nullptr;
  this->m_pLabel = v8;
  v8->SetMouseInputEnabled(this: v8, a2: false);
  v9 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "TextEntry");
  else
    v10 = nullptr;
  this->m_pTextEntry = v10;
  v10->SetAutoLocalize(this: v10, a2: false);
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    this->m_pDeleteButton = vgui::Button::Button(
                              this: v11,
                              parent: this,
                              panelName: "DeleteButton",
                              text: "X",
                              pActionSignalTarget: this,
                              pCmd: "Delete");
  else
    this->m_pDeleteButton = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F580
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Leaf_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Leaf_Panel::GetMessageMap(CKV_Leaf_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Leaf_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Leaf_Panel::GetMessageMap'::`2'::s_pMap;
  `CKV_Leaf_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Leaf_Panel");
  `CKV_Leaf_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F5B0
// Name: public: virtual struct PanelAnimationMap __near * CKV_Leaf_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Leaf_Panel::GetAnimMap(CKV_Leaf_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Leaf_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x1000F5C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Leaf_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Leaf_Panel::GetKBMap(CKV_Leaf_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Leaf_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Leaf_Panel::GetKBMap'::`2'::s_pMap;
  `CKV_Leaf_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Leaf_Panel");
  `CKV_Leaf_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F5F0
// Name: Create_CKV_Leaf_Panel
// Source: json
//------------------------------------------------------------------------------
CKV_Leaf_Panel *__cdecl Create_CKV_Leaf_Panel()
{
  CKV_Leaf_Panel *v0; // eax

  v0 = (CKV_Leaf_Panel *)operator new(nSize: 0x1A8u);
  if ( v0 != nullptr )
    return CKV_Leaf_Panel::CKV_Leaf_Panel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004065F0
// Name: public: virtual void CKV_Leaf_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Leaf_Panel::PerformLayout(CKV_Combo_Leaf_Panel *this)
{
  int v2; // eax
  KeyValues *m_pFileSpecNode; // ecx
  int Tall; // ebx
  int v5; // edi
  KeyValues *v6; // ecx
  int v7; // eax
  int Wide; // eax
  int Int; // [esp-4h] [ebp-10h]

  CKV_Editor_Base_Panel::PerformLayout(this);
  vgui::Panel::SetBounds(this: this->m_pLabel, x: 0, y: 0, wide: 100, tall: 20);
  this->m_pLabel->SizeToContents(this: this->m_pLabel);
  this->m_pLabel->InvalidateLayout(this: this->m_pLabel, a2: true, a3: false);
  if ( vgui::Panel::GetWide(this: this->m_pLabel) + 5 <= 100 )
    v2 = 100;
  else
    v2 = vgui::Panel::GetWide(this: this->m_pLabel) + 5;
  m_pFileSpecNode = this->m_pFileSpecNode;
  Tall = 0;
  v5 = v2;
  if ( m_pFileSpecNode != nullptr
    && KeyValues::FindKey(this: m_pFileSpecNode, keyName: "TextEntryNewLine", bCreate: false) != nullptr )
  {
    Tall = vgui::Panel::GetTall(this: this->m_pLabel);
    v5 = 0;
  }
  v6 = this->m_pFileSpecNode;
  if ( v6 != nullptr && KeyValues::FindKey(this: v6, keyName: "Tall", bCreate: false) != nullptr )
  {
    Int = KeyValues::GetInt(this: this->m_pFileSpecNode, keyName: "Tall", defaultValue: 0);
    vgui::Panel::SetBounds(this: this->m_pCombo, x: v5, y: Tall, wide: 390 - v5, tall: Int);
  }
  else
  {
    vgui::Panel::SetBounds(this: this->m_pCombo, x: v5, y: Tall, wide: 390 - v5, tall: 20);
  }
  v7 = vgui::Panel::GetTall(this: this->m_pCombo);
  vgui::Panel::SetSize(this, wide: 420, tall: Tall + v7);
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pDeleteButton, x: Wide - 25, y: 2, wide: 20, tall: 16);
}

//------------------------------------------------------------------------------
// Address: 0x004087E0
// Name: public: static char const __near * CKV_Leaf_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Leaf_Panel::GetPanelClassName()
{
  return "CKV_Leaf_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x004087F0
// Name: public: virtual void CKV_Leaf_Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Leaf_Panel::ApplySchemeSettings(CKV_Leaf_Panel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
  this->SetPaintBackgroundEnabled(this, a2: false);
  this->m_pDeleteButton->SetVisible(this: this->m_pDeleteButton, a2: this->m_bAllowDeletion);
}

//------------------------------------------------------------------------------
// Address: 0x00408840
// Name: public: virtual void CKV_Leaf_Panel::UpdatePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Leaf_Panel::UpdatePanel(CKV_Leaf_Panel *this)
{
  KeyValues *m_pFileSpecNode; // ecx
  vgui::Button_vtbl *v3; // edi
  KeyValues *Key; // eax
  KeyValues *v5; // ecx
  vgui::Label_vtbl *v6; // edi
  const char *String; // eax
  vgui::TextEntry_vtbl *v8; // edi
  const char *v9; // eax

  m_pFileSpecNode = this->m_pFileSpecNode;
  if ( m_pFileSpecNode != nullptr )
  {
    v3 = this->m_pDeleteButton->__vftable;
    Key = KeyValues::FindKey(this: m_pFileSpecNode, keyName: "Deletable", bCreate: false);
    v3->SetVisible(this: this->m_pDeleteButton, a2: Key != nullptr);
  }
  if ( this->m_pKey != nullptr )
  {
    v5 = this->m_pFileSpecNode;
    if ( v5 != nullptr && KeyValues::FindKey(this: v5, keyName: "FriendlyName", bCreate: false) != nullptr )
    {
      v6 = this->m_pLabel->__vftable;
      String = KeyValues::GetString(this: this->m_pFileSpecNode, keyName: "FriendlyName", defaultValue: &defaultValue);
    }
    else
    {
      v6 = this->m_pLabel->__vftable;
      String = KeyValues::GetName(this: this->m_pKey);
    }
    v6->SetText(this: this->m_pLabel, a2: String);
    v8 = this->m_pTextEntry->__vftable;
    v9 = KeyValues::GetString(this: this->m_pKey, keyName: nullptr, defaultValue: &defaultValue);
    v8->SetText(this: this->m_pTextEntry, a2: v9);
    if ( KeyValues::GetInt(this: this->m_pFileSpecNode, keyName: "ReadOnly", defaultValue: 0) == 1 )
    {
      this->m_pTextEntry->SetEditable(this: this->m_pTextEntry, a2: false);
      this->m_pTextEntry->SetEnabled(this: this->m_pTextEntry, a2: false);
    }
  }
  else
  {
    this->m_pLabel->SetText(this: this->m_pLabel, a2: "INVALID KEY");
    this->m_pTextEntry->SetText(this: this->m_pTextEntry, a2: "INVALID KEY");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408980
// Name: public: virtual void CKV_Leaf_Panel::TextEntryChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Leaf_Panel::TextEntryChanged(CKV_Leaf_Panel *this, vgui::TextEntry *pTextEntry)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char buf[2048]; // [esp+4h] [ebp-800h] BYREF

  if ( pTextEntry == this->m_pTextEntry && this->m_pKey != nullptr )
  {
    this->m_pTextEntry->GetText_2(this: this->m_pTextEntry, a2: buf, a3: 2048);
    KeyValues::SetStringValue(this: this->m_pKey, strValue: buf);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "command", firstKey: "command", firstValue: "KeyValuesChanged");
      this->PostActionSignal(this, a2: v4);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408A20
// Name: public: virtual void CKV_Leaf_Panel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Leaf_Panel::OnCommand(CKV_Leaf_Panel *this, const char *command)
{
  KeyValues *m_pKeyParent; // ecx

  if ( _V_stricmp(s1: command, s2: "Delete") == 0
    && (m_pKeyParent = this->m_pKeyParent) != nullptr
    && this->m_bAllowDeletion )
  {
    KeyValues::RemoveSubKey(this: m_pKeyParent, subKey: this->m_pKey);
    KeyValues::deleteThis(this: this->m_pKey);
    this->m_pEditor->OnKeyDeleted(this: this->m_pEditor);
  }
  else
  {
    vgui::Panel::OnCommand(this, command);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408AA0
// Name: public: static void CKV_Leaf_Panel::PanelMessageFunc_TextEntryChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CKV_Leaf_Panel::PanelMessageFunc_TextEntryChanged::InitVar(int a1@<ebp>)
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
  if ( !`CKV_Leaf_Panel::PanelMessageFunc_TextEntryChanged::InitVar'::`2'::bAdded )
  {
    `CKV_Leaf_Panel::PanelMessageFunc_TextEntryChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CKV_Node_Panel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CKV_Leaf_Panel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "TextChanged";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408B40
// Name: public: CKV_Leaf_Panel::CKV_Leaf_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Leaf_Panel *__thiscall CKV_Leaf_Panel::CKV_Leaf_Panel(CKV_Leaf_Panel *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Button *v11; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CKV_Editor_Base_Panel::CKV_Editor_Base_Panel(this, parent, name);
  this->__vftable = (CKV_Leaf_Panel_vtbl *)&CKV_Leaf_Panel::`vftable';
  if ( `CKV_Leaf_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Leaf_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Leaf_Panel");
    v4->pfnClassName = CKV_Leaf_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Leaf_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Leaf_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Leaf_Panel");
    v5->pfnClassName = CKV_Leaf_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Leaf_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Leaf_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Leaf_Panel");
    v6->pfnClassName = CKV_Leaf_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Base_Panel");
  }
  CKV_Leaf_Panel::PanelMessageFunc_TextEntryChanged::InitVar(a1: (int)&savedregs);
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "Label", text: &defaultValue);
  else
    v8 = nullptr;
  this->m_pLabel = v8;
  v8->SetMouseInputEnabled(this: v8, a2: false);
  v9 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "TextEntry");
  else
    v10 = nullptr;
  this->m_pTextEntry = v10;
  v10->SetAutoLocalize(this: v10, a2: false);
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    this->m_pDeleteButton = vgui::Button::Button(
                              this: v11,
                              parent: this,
                              panelName: "DeleteButton",
                              text: "X",
                              pActionSignalTarget: this,
                              pCmd: "Delete");
  else
    this->m_pDeleteButton = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408CC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Leaf_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Leaf_Panel::GetMessageMap(CKV_Leaf_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Leaf_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Leaf_Panel::GetMessageMap'::`2'::s_pMap;
  `CKV_Leaf_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Leaf_Panel");
  `CKV_Leaf_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408CF0
// Name: public: virtual struct PanelAnimationMap __near * CKV_Leaf_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Leaf_Panel::GetAnimMap(CKV_Leaf_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Leaf_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x00408D00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Leaf_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Leaf_Panel::GetKBMap(CKV_Leaf_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Leaf_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Leaf_Panel::GetKBMap'::`2'::s_pMap;
  `CKV_Leaf_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Leaf_Panel");
  `CKV_Leaf_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408D30
// Name: Create_CKV_Leaf_Panel
// Source: json
//------------------------------------------------------------------------------
CKV_Leaf_Panel *__cdecl Create_CKV_Leaf_Panel()
{
  CKV_Leaf_Panel *v0; // eax

  v0 = (CKV_Leaf_Panel *)operator new(nSize: 0x1A8u);
  if ( v0 != nullptr )
    return CKV_Leaf_Panel::CKV_Leaf_Panel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor
