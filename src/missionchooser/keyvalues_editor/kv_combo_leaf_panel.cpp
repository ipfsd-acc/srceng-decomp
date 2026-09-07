// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/keyvalues_editor/kv_combo_leaf_panel.cpp
// Functions: 12
// ============================================================

#include "missionchooser\keyvalues_editor\kv_combo_leaf_panel.h"

//------------------------------------------------------------------------------
// Address: 0x1000C8F0
// Name: public: static char const __near * CKV_Combo_Leaf_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Combo_Leaf_Panel::GetPanelClassName()
{
  return "CKV_Combo_Leaf_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x1000C900
// Name: public: virtual void CKV_Combo_Leaf_Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Combo_Leaf_Panel::ApplySchemeSettings(CKV_Combo_Leaf_Panel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000C940
// Name: public: virtual void CKV_Combo_Leaf_Panel::UpdatePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Combo_Leaf_Panel::UpdatePanel(CKV_Combo_Leaf_Panel *this)
{
  KeyValues *m_pFileSpecNode; // ecx
  vgui::Button_vtbl *v3; // edi
  KeyValues *Key; // eax
  KeyValues *m_pKey; // ecx
  const char *v6; // eax
  KeyValues *i; // edi
  const char *Name; // eax
  const char *String; // ebx
  int v10; // eax
  const char *v11; // eax
  KeyValues *v12; // ecx
  vgui::Label_vtbl *v13; // edi
  const char *v14; // eax
  KeyValues *v15; // ecx
  int iIndex; // [esp+8h] [ebp-Ch]
  int iCurrentChoice; // [esp+Ch] [ebp-8h]
  int iChoices; // [esp+10h] [ebp-4h]

  m_pFileSpecNode = this->m_pFileSpecNode;
  if ( m_pFileSpecNode != nullptr )
  {
    v3 = this->m_pDeleteButton->__vftable;
    Key = KeyValues::FindKey(this: m_pFileSpecNode, keyName: "Deletable", bCreate: false);
    v3->SetVisible(this: this->m_pDeleteButton, a2: Key != nullptr);
    this->m_bIntegerChoice = KeyValues::GetInt(this: this->m_pFileSpecNode, keyName: "IntegerChoice", defaultValue: 0) != 0;
    vgui::ComboBox::RemoveAll(this: this->m_pCombo);
    m_pKey = this->m_pKey;
    iChoices = 0;
    v6 = m_pKey != nullptr ? KeyValues::GetString(this: m_pKey, keyName: nullptr, defaultValue: szDescription) : "0";
    iCurrentChoice = atoi(nptr: v6);
    for ( i = KeyValues::GetFirstSubKey(this: this->m_pFileSpecNode); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: Name, s2: "Choice") == 0 )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: szDescription);
        v10 = this->m_pCombo->AddItem_2(this: this->m_pCombo, a2: String, a3: nullptr);
        iIndex = v10;
        if ( this->m_bIntegerChoice )
        {
          if ( iCurrentChoice == iChoices )
            this->m_pCombo->ActivateItem(this: this->m_pCombo, a2: v10);
        }
        else
        {
          v11 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: szDescription);
          if ( _V_stricmp(s1: String, s2: v11) == 0 )
            this->m_pCombo->ActivateItem(this: this->m_pCombo, a2: iIndex);
        }
        ++iChoices;
      }
    }
  }
  if ( this->m_pKey != nullptr )
  {
    v12 = this->m_pFileSpecNode;
    if ( v12 != nullptr && KeyValues::FindKey(this: v12, keyName: "FriendlyName", bCreate: false) != nullptr )
    {
      v13 = this->m_pLabel->__vftable;
      v14 = KeyValues::GetString(this: this->m_pFileSpecNode, keyName: "FriendlyName", defaultValue: szDescription);
    }
    else
    {
      v13 = this->m_pLabel->__vftable;
      v14 = KeyValues::GetName(this: this->m_pKey);
    }
    v13->SetText(this: this->m_pLabel, a2: v14);
    v15 = this->m_pFileSpecNode;
    if ( v15 != nullptr && KeyValues::GetInt(this: v15, keyName: "ReadOnly", defaultValue: 0) == 1 )
    {
      this->m_pCombo->SetEditable(this: this->m_pCombo, a2: false);
      this->m_pCombo->SetEnabled(this: this->m_pCombo, a2: false);
    }
  }
  else
  {
    this->m_pLabel->SetText(this: this->m_pLabel, a2: "INVALID KEY");
    this->m_pCombo->SetText(this: this->m_pCombo, a2: "INVALID KEY");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CB80
// Name: public: virtual void CKV_Combo_Leaf_Panel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Combo_Leaf_Panel::OnTextChanged(CKV_Combo_Leaf_Panel *this, vgui::ComboBox *pTextEntry)
{
  vgui::ComboBox *m_pCombo; // ecx
  int ActiveItem; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  char buf[2048]; // [esp+4h] [ebp-800h] BYREF

  m_pCombo = this->m_pCombo;
  if ( pTextEntry == m_pCombo && this->m_pKey != nullptr )
  {
    if ( this->m_bIntegerChoice )
    {
      ActiveItem = vgui::ComboBox::GetActiveItem(this: m_pCombo);
      KeyValues::SetInt(this: this->m_pKey, keyName: nullptr, value: ActiveItem);
    }
    else
    {
      m_pCombo->GetText_2(this: m_pCombo, a2: buf, a3: 2048);
      KeyValues::SetStringValue(this: this->m_pKey, strValue: buf);
    }
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v5, setName: "command", firstKey: "command", firstValue: "KeyValuesChanged");
      this->PostActionSignal(this, a2: v6);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CC40
// Name: public: virtual void CKV_Combo_Leaf_Panel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Combo_Leaf_Panel::OnCommand(CKV_Combo_Leaf_Panel *this, const char *command)
{
  KeyValues *m_pKeyParent; // ecx

  if ( _V_stricmp(s1: command, s2: "Delete") != 0 || (m_pKeyParent = this->m_pKeyParent) == nullptr )
  {
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    KeyValues::RemoveSubKey(this: m_pKeyParent, subKey: this->m_pKey);
    KeyValues::deleteThis(this: this->m_pKey);
    this->m_pEditor->OnKeyDeleted(this: this->m_pEditor);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CD30
// Name: public: static void CKV_Combo_Leaf_Panel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CKV_Combo_Leaf_Panel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CKV_Combo_Leaf_Panel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CKV_Combo_Leaf_Panel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CKV_Node_Panel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CKV_Combo_Leaf_Panel");
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
// Address: 0x1000CDD0
// Name: public: CKV_Combo_Leaf_Panel::CKV_Combo_Leaf_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Combo_Leaf_Panel *__thiscall CKV_Combo_Leaf_Panel::CKV_Combo_Leaf_Panel(
        CKV_Combo_Leaf_Panel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::ComboBox *v10; // eax
  vgui::Button *v11; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CKV_Editor_Base_Panel::CKV_Editor_Base_Panel(this, parent, name);
  this->__vftable = (CKV_Combo_Leaf_Panel_vtbl *)&CKV_Combo_Leaf_Panel::`vftable';
  if ( `CKV_Combo_Leaf_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Combo_Leaf_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Combo_Leaf_Panel");
    v4->pfnClassName = CKV_Combo_Leaf_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Combo_Leaf_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Combo_Leaf_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Combo_Leaf_Panel");
    v5->pfnClassName = CKV_Combo_Leaf_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Combo_Leaf_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Combo_Leaf_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Combo_Leaf_Panel");
    v6->pfnClassName = CKV_Combo_Leaf_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Base_Panel");
  }
  CKV_Combo_Leaf_Panel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_bIntegerChoice = false;
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "Label", text: szDescription);
  else
    v8 = nullptr;
  this->m_pLabel = v8;
  v8->SetMouseInputEnabled(this: v8, a2: false);
  v9 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v9 != nullptr )
    v10 = vgui::ComboBox::ComboBox(this: v9, parent: this, panelName: "Combo", numLines: 8, allowEdit: false);
  else
    v10 = nullptr;
  this->m_pCombo = v10;
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
// Address: 0x1000CF50
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Combo_Leaf_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Combo_Leaf_Panel::GetMessageMap(CKV_Combo_Leaf_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Combo_Leaf_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Combo_Leaf_Panel::GetMessageMap'::`2'::s_pMap;
  `CKV_Combo_Leaf_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Combo_Leaf_Panel");
  `CKV_Combo_Leaf_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF80
// Name: public: virtual struct PanelAnimationMap __near * CKV_Combo_Leaf_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Combo_Leaf_Panel::GetAnimMap(CKV_Combo_Leaf_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Combo_Leaf_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x1000CF90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Combo_Leaf_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Combo_Leaf_Panel::GetKBMap(CKV_Combo_Leaf_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Combo_Leaf_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Combo_Leaf_Panel::GetKBMap'::`2'::s_pMap;
  `CKV_Combo_Leaf_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Combo_Leaf_Panel");
  `CKV_Combo_Leaf_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000CFC0
// Name: Create_CKV_Combo_Leaf_Panel
// Source: json
//------------------------------------------------------------------------------
CKV_Combo_Leaf_Panel *__cdecl Create_CKV_Combo_Leaf_Panel()
{
  CKV_Combo_Leaf_Panel *v0; // eax

  v0 = (CKV_Combo_Leaf_Panel *)operator new(nSize: 0x1ACu);
  if ( v0 != nullptr )
    return CKV_Combo_Leaf_Panel::CKV_Combo_Leaf_Panel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001F130
// Name: public: void CUtlMemory<struct vgui::MessageMapItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::MessageMapItem_t,int>::Grow(CUtlMemory<vgui::MessageMapItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::MessageMapItem_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004065E0
// Name: public: static char const __near * CKV_Combo_Leaf_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Combo_Leaf_Panel::GetPanelClassName()
{
  return "CKV_Combo_Leaf_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x00406710
// Name: public: virtual void CKV_Combo_Leaf_Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Combo_Leaf_Panel::ApplySchemeSettings(CKV_Combo_Leaf_Panel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00406750
// Name: public: virtual void CKV_Combo_Leaf_Panel::UpdatePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Combo_Leaf_Panel::UpdatePanel(CKV_Combo_Leaf_Panel *this)
{
  KeyValues *m_pFileSpecNode; // ecx
  vgui::Button_vtbl *v3; // edi
  KeyValues *Key; // eax
  KeyValues *m_pKey; // ecx
  const char *v6; // eax
  KeyValues *i; // edi
  const char *Name; // eax
  const char *String; // ebx
  int v10; // eax
  const char *v11; // eax
  KeyValues *v12; // ecx
  vgui::Label_vtbl *v13; // edi
  const char *v14; // eax
  KeyValues *v15; // ecx
  int iIndex; // [esp+8h] [ebp-Ch]
  int iCurrentChoice; // [esp+Ch] [ebp-8h]
  int iChoices; // [esp+10h] [ebp-4h]

  m_pFileSpecNode = this->m_pFileSpecNode;
  if ( m_pFileSpecNode != nullptr )
  {
    v3 = this->m_pDeleteButton->__vftable;
    Key = KeyValues::FindKey(this: m_pFileSpecNode, keyName: "Deletable", bCreate: false);
    v3->SetVisible(this: this->m_pDeleteButton, a2: Key != nullptr);
    this->m_bIntegerChoice = KeyValues::GetInt(this: this->m_pFileSpecNode, keyName: "IntegerChoice", defaultValue: 0) != 0;
    vgui::ComboBox::RemoveAll(this: this->m_pCombo);
    m_pKey = this->m_pKey;
    iChoices = 0;
    v6 = m_pKey != nullptr ? KeyValues::GetString(this: m_pKey, keyName: nullptr, defaultValue: &defaultValue) : "0";
    iCurrentChoice = atoi(nptr: v6);
    for ( i = KeyValues::GetFirstSubKey(this: this->m_pFileSpecNode); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: Name, s2: "Choice") == 0 )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &defaultValue);
        v10 = this->m_pCombo->AddItem_2(this: this->m_pCombo, a2: String, a3: nullptr);
        iIndex = v10;
        if ( this->m_bIntegerChoice )
        {
          if ( iCurrentChoice == iChoices )
            this->m_pCombo->ActivateItem(this: this->m_pCombo, a2: v10);
        }
        else
        {
          v11 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &defaultValue);
          if ( _V_stricmp(s1: String, s2: v11) == 0 )
            this->m_pCombo->ActivateItem(this: this->m_pCombo, a2: iIndex);
        }
        ++iChoices;
      }
    }
  }
  if ( this->m_pKey != nullptr )
  {
    v12 = this->m_pFileSpecNode;
    if ( v12 != nullptr && KeyValues::FindKey(this: v12, keyName: "FriendlyName", bCreate: false) != nullptr )
    {
      v13 = this->m_pLabel->__vftable;
      v14 = KeyValues::GetString(this: this->m_pFileSpecNode, keyName: "FriendlyName", defaultValue: &defaultValue);
    }
    else
    {
      v13 = this->m_pLabel->__vftable;
      v14 = KeyValues::GetName(this: this->m_pKey);
    }
    v13->SetText(this: this->m_pLabel, a2: v14);
    v15 = this->m_pFileSpecNode;
    if ( v15 != nullptr && KeyValues::GetInt(this: v15, keyName: "ReadOnly", defaultValue: 0) == 1 )
    {
      this->m_pCombo->SetEditable(this: this->m_pCombo, a2: false);
      this->m_pCombo->SetEnabled(this: this->m_pCombo, a2: false);
    }
  }
  else
  {
    this->m_pLabel->SetText(this: this->m_pLabel, a2: "INVALID KEY");
    this->m_pCombo->SetText(this: this->m_pCombo, a2: "INVALID KEY");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406990
// Name: public: virtual void CKV_Combo_Leaf_Panel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Combo_Leaf_Panel::OnTextChanged(CKV_Combo_Leaf_Panel *this, vgui::ComboBox *pTextEntry)
{
  vgui::ComboBox *m_pCombo; // ecx
  int ActiveItem; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  char buf[2048]; // [esp+4h] [ebp-800h] BYREF

  m_pCombo = this->m_pCombo;
  if ( pTextEntry == m_pCombo && this->m_pKey != nullptr )
  {
    if ( this->m_bIntegerChoice )
    {
      ActiveItem = vgui::ComboBox::GetActiveItem(this: m_pCombo);
      KeyValues::SetInt(this: this->m_pKey, keyName: nullptr, value: ActiveItem);
    }
    else
    {
      m_pCombo->GetText_2(this: m_pCombo, a2: buf, a3: 2048);
      KeyValues::SetStringValue(this: this->m_pKey, strValue: buf);
    }
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v5, setName: "command", firstKey: "command", firstValue: "KeyValuesChanged");
      this->PostActionSignal(this, a2: v6);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406A50
// Name: public: virtual void CKV_Combo_Leaf_Panel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Combo_Leaf_Panel::OnCommand(CKV_Combo_Leaf_Panel *this, const char *command)
{
  KeyValues *m_pKeyParent; // ecx

  if ( _V_stricmp(s1: command, s2: "Delete") != 0 || (m_pKeyParent = this->m_pKeyParent) == nullptr )
  {
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    KeyValues::RemoveSubKey(this: m_pKeyParent, subKey: this->m_pKey);
    KeyValues::deleteThis(this: this->m_pKey);
    this->m_pEditor->OnKeyDeleted(this: this->m_pEditor);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406AC0
// Name: public: void CUtlMemory<struct vgui::MessageMapItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::MessageMapItem_t,int>::Grow(CUtlMemory<vgui::MessageMapItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::MessageMapItem_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406BC0
// Name: public: static void CKV_Combo_Leaf_Panel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CKV_Combo_Leaf_Panel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CKV_Combo_Leaf_Panel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CKV_Combo_Leaf_Panel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CKV_Node_Panel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CKV_Combo_Leaf_Panel");
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
// Address: 0x00406C60
// Name: public: CKV_Combo_Leaf_Panel::CKV_Combo_Leaf_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Combo_Leaf_Panel *__thiscall CKV_Combo_Leaf_Panel::CKV_Combo_Leaf_Panel(
        CKV_Combo_Leaf_Panel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::ComboBox *v10; // eax
  vgui::Button *v11; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CKV_Editor_Base_Panel::CKV_Editor_Base_Panel(this, parent, name);
  this->__vftable = (CKV_Combo_Leaf_Panel_vtbl *)&CKV_Combo_Leaf_Panel::`vftable';
  if ( `CKV_Combo_Leaf_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Combo_Leaf_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Combo_Leaf_Panel");
    v4->pfnClassName = CKV_Combo_Leaf_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Combo_Leaf_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Combo_Leaf_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Combo_Leaf_Panel");
    v5->pfnClassName = CKV_Combo_Leaf_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Combo_Leaf_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Combo_Leaf_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Combo_Leaf_Panel");
    v6->pfnClassName = CKV_Combo_Leaf_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Base_Panel");
  }
  CKV_Combo_Leaf_Panel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_bIntegerChoice = false;
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "Label", text: &defaultValue);
  else
    v8 = nullptr;
  this->m_pLabel = v8;
  v8->SetMouseInputEnabled(this: v8, a2: false);
  v9 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v9 != nullptr )
    v10 = vgui::ComboBox::ComboBox(this: v9, parent: this, panelName: "Combo", numLines: 8, allowEdit: false);
  else
    v10 = nullptr;
  this->m_pCombo = v10;
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
// Address: 0x00406E00
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        vgui::Panel *this,
        const char *elementName,
        const char *x,
        int *y,
        int *wide,
        int *tall)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00406E10
// Name: public: virtual unsigned long vgui::Panel::GetDragFailCursor(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Panel::GetDragFailCursor(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x00406E20
// Name: private: virtual class vgui::Panel __near * vgui::Panel::GetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetPanel(vgui::Panel *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00406E30
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406E40
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Combo_Leaf_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Combo_Leaf_Panel::GetMessageMap(CKV_Combo_Leaf_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Combo_Leaf_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Combo_Leaf_Panel::GetMessageMap'::`2'::s_pMap;
  `CKV_Combo_Leaf_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Combo_Leaf_Panel");
  `CKV_Combo_Leaf_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406E70
// Name: public: virtual struct PanelAnimationMap __near * CKV_Combo_Leaf_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Combo_Leaf_Panel::GetAnimMap(CKV_Combo_Leaf_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Combo_Leaf_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x00406E80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Combo_Leaf_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Combo_Leaf_Panel::GetKBMap(CKV_Combo_Leaf_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Combo_Leaf_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Combo_Leaf_Panel::GetKBMap'::`2'::s_pMap;
  `CKV_Combo_Leaf_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Combo_Leaf_Panel");
  `CKV_Combo_Leaf_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406EB0
// Name: Create_CKV_Combo_Leaf_Panel
// Source: json
//------------------------------------------------------------------------------
CKV_Combo_Leaf_Panel *__cdecl Create_CKV_Combo_Leaf_Panel()
{
  CKV_Combo_Leaf_Panel *v0; // eax

  v0 = (CKV_Combo_Leaf_Panel *)operator new(nSize: 0x1ACu);
  if ( v0 != nullptr )
    return CKV_Combo_Leaf_Panel::CKV_Combo_Leaf_Panel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041A210
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetParent(vgui::Panel *this)
{
  vgui::IPanel *v1; // esi
  vgui::IPanel_vtbl *v2; // edi
  int v3; // eax
  int v4; // esi
  vgui::IPanel *v5; // edi
  vgui::IPanel_vtbl *v6; // ebx
  const char *ControlsModuleName; // eax

  v1 = g_pVGuiPanel;
  if ( g_pVGuiPanel == nullptr )
    return nullptr;
  v2 = g_pVGuiPanel->__vftable;
  v3 = this->GetVPanel(this);
  v4 = v2->GetParent(this: v1, a2: v3);
  if ( v4 == 0 )
    return nullptr;
  v5 = g_pVGuiPanel;
  v6 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v6->GetPanel(this: v5, a2: v4, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x0041A5D0
// Name: public: class vgui::Panel __near * vgui::Panel::FindSiblingByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindSiblingByName(vgui::Panel *this, const char *siblingName)
{
  vgui::Panel *result; // eax
  vgui::IPanel *v4; // edi
  vgui::IPanel_vtbl *v5; // esi
  unsigned int v6; // eax
  vgui::IPanel *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  int v9; // eax
  int v10; // eax
  vgui::IPanel *v11; // edi
  vgui::IPanel_vtbl *v12; // esi
  const char *ControlsModuleName; // eax
  int v14; // esi
  const char *v15; // eax
  int siblingCount; // [esp+4h] [ebp-Ch]
  unsigned int sibling; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = (vgui::Panel *)this->GetVParent(this);
  if ( result != nullptr )
  {
    v4 = g_pVGuiPanel;
    v5 = g_pVGuiPanel->__vftable;
    v6 = this->GetVParent(this);
    siblingCount = v5->GetChildCount(this: v4, a2: v6);
    i = 0;
    if ( siblingCount <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = ((int (__thiscall *)(vgui::Panel *, int))this->GetVParent)(a1: this, a2: i);
        v10 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetChild)(a1: v7, a2: v9);
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        sibling = v10;
        ControlsModuleName = vgui::GetControlsModuleName();
        v14 = (int)v12->GetPanel(this: v11, a2: sibling, a3: ControlsModuleName);
        v15 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(a1: v14);
        if ( _V_stricmp(s1: v15, s2: siblingName) == 0 )
          break;
        if ( ++i >= siblingCount )
          return nullptr;
      }
      return (vgui::Panel *)v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041A7C0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::HasHotkey(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041AA40
// Name: public: virtual enum vgui::KeyBindingContextHandle_t vgui::Panel::GetKeyBindingsContext(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall vgui::Panel::GetKeyBindingsContext(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x0041B020
// Name: public: class vgui::Panel __near * vgui::Panel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetChild(vgui::Panel *this, int index)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel *v4; // ebx
  const char *ControlsModuleName; // eax
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v9; // [esp+Ch] [ebp-8h]
  vgui::IPanel_vtbl *v10; // [esp+10h] [ebp-4h]

  v2 = g_pVGuiPanel;
  v4 = g_pVGuiPanel;
  v9 = g_pVGuiPanel->__vftable;
  v10 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  v6 = ((int (__thiscall *)(vgui::Panel *, int, const char *))this->GetVPanel)(
         a1: this,
         a2: index,
         a3: ControlsModuleName);
  v7 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v2, a2: v6);
  return ((vgui::Panel *(__thiscall *)(vgui::IPanel *, int))v9->GetPanel)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x0041B2E0
// Name: public: virtual class vgui::IBorder __near * vgui::Panel::GetBorder(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Panel::GetBorder(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x0041B620
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x0041B650
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x0041BAE0
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x0041D3D0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDropTarget(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDropTarget(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  vgui::Panel *v4; // eax

  if ( this->m_pDragDrop->m_bDropEnabled && this->IsDroppable(this, a2: msglist) )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDropTarget(this: v4, a2: msglist);
}

//------------------------------------------------------------------------------
// Address: 0x0041D440
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDragPanel(vgui::Panel *this)
{
  vgui::DragDrop_t *m_pDragDrop; // eax
  vgui::Panel *v4; // eax

  m_pDragDrop = this->m_pDragDrop;
  if ( m_pDragDrop->m_bPreventChaining )
    return nullptr;
  if ( m_pDragDrop->m_bDragEnabled )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDragPanel(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0041D490
// Name: public: virtual struct vgui::DragDrop_t __near * vgui::Panel::GetDragDropInfo(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall vgui::Panel::GetDragDropInfo(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x0041E160
// Name: public: class vgui::Panel __near * vgui::Panel::FindChildByName(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindChildByName(vgui::Panel *this, const char *childName, bool recurseDown)
{
  vgui::IPanel *v3; // ebx
  vgui::IPanel_vtbl *v4; // esi
  int v5; // eax
  int v6; // eax
  vgui::IPanel_vtbl *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  const char *ControlsModuleName; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vgui::Panel *v13; // esi
  const char *v14; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v16; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v16 = this;
  for ( i = 0; ; ++i )
  {
    v3 = g_pVGuiPanel;
    if ( g_pVGuiPanel != nullptr )
    {
      v4 = g_pVGuiPanel->__vftable;
      v5 = this->GetVPanel(this);
      v6 = v4->GetChildCount(this: v3, a2: v5);
      v3 = g_pVGuiPanel;
    }
    else
    {
      v6 = 0;
    }
    if ( i >= v6 )
      break;
    v7 = v3->__vftable;
    v8 = v3->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = ((int (__thiscall *)(vgui::Panel *, int, const char *))v16->GetVPanel)(a1: v16, a2: i, a3: ControlsModuleName);
    v11 = ((int (__thiscall *)(vgui::IPanel *, int))v7->GetChild)(a1: v3, a2: v10);
    v12 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetPanel)(a1: v3, a2: v11);
    v13 = (vgui::Panel *)v12;
    if ( v12 != 0 )
    {
      v14 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 72))(a1: v12);
      if ( _V_stricmp(s1: v14, s2: childName) == 0 )
        return v13;
      if ( recurseDown )
      {
        result = vgui::Panel::FindChildByName(this: v13, childName, recurseDown);
        if ( result != nullptr )
          return result;
      }
    }
    this = v16;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041F2B0
// Name: public: class vgui::Tooltip __near * vgui::Panel::GetTooltip(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Panel::GetTooltip(vgui::Panel *this)
{
  vgui::Tooltip *v2; // eax
  vgui::Tooltip *result; // eax
  bool v4; // zf

  if ( this->m_pTooltips != nullptr )
    return this->m_pTooltips;
  v2 = (vgui::Tooltip *)operator new(nSize: 0x28u);
  if ( v2 != nullptr )
    result = vgui::Tooltip::Tooltip(this: v2, parent: this, text: nullptr);
  else
    result = nullptr;
  v4 = (*((_BYTE *)this + 172) & 8) == 0;
  this->m_pTooltips = result;
  if ( !v4 )
  {
    vgui::Tooltip::SetEnabled(this: result, bState: false);
    return this->m_pTooltips;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041FA90
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavUp; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  unsigned int v11; // edi
  vgui::IPanel *v12; // esi
  vgui::IPanel_vtbl *v13; // ebx
  const char *v14; // eax
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // edi
  vgui::IPanel *v18; // esi
  vgui::IPanel_vtbl *v19; // ebx
  const char *v20; // eax
  unsigned int v21; // eax
  vgui::PHandle *v22; // ebx
  unsigned int v23; // edi
  vgui::IPanel *v24; // esi
  vgui::IPanel_vtbl *v25; // ebx
  const char *v26; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  const char *v31; // [esp-8h] [ebp-20h]
  vgui::PHandle *v33; // [esp+10h] [ebp-8h]
  vgui::Panel *v34; // [esp+14h] [ebp-4h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavUp.m_iPanelID;
  p_m_NavUp = &this->m_NavUp;
  v33 = &this->m_NavUp;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v34 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v34->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavUp = v33,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavUpName) > 0 )
    {
      v31 = CUtlString::operator char const *(this: &this->m_sNavUpName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v31, recurseDown: true);
      if ( ChildByName != nullptr )
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavUp, pPanel: ChildByName);
    }
  }
  if ( p_m_NavUp->m_iPanelID == -1 || (v11 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v35 = nullptr;
    v16 = 0;
  }
  else
  {
    v12 = g_pVGuiPanel;
    v13 = g_pVGuiPanel->__vftable;
    v14 = vgui::GetControlsModuleName();
    v15 = (int)v13->GetPanel(this: v12, a2: v11, a3: v14);
    p_m_NavUp = v33;
    v16 = v15;
    v35 = (vgui::Panel *)v15;
  }
  if ( p_m_NavUp->m_iPanelID == -1 )
    return (vgui::Panel *)v16;
  v17 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID);
  if ( v17 == 0 )
    return (vgui::Panel *)v16;
  v18 = g_pVGuiPanel;
  v19 = g_pVGuiPanel->__vftable;
  v20 = vgui::GetControlsModuleName();
  if ( v19->GetPanel(this: v18, a2: v17, a3: v20) == nullptr )
    return v35;
  v21 = this->m_NavUp.m_iPanelID;
  v22 = &this->m_NavUp;
  if ( v21 == -1 || (v23 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v21)) == 0 )
  {
    v27 = nullptr;
  }
  else
  {
    v24 = g_pVGuiPanel;
    v25 = g_pVGuiPanel->__vftable;
    v26 = vgui::GetControlsModuleName();
    v27 = v25->GetPanel(this: v24, a2: v23, a3: v26);
    v22 = &this->m_NavUp;
  }
  if ( v27 == first )
    return v35;
  v28 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v22);
  if ( v28->IsVisible(this: v28) )
    return v35;
  v29 = this;
  if ( first != nullptr )
    v29 = first;
  return vgui::Panel::GetNavUp(this: v35, first: v29);
}

//------------------------------------------------------------------------------
// Address: 0x0041FC50
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavDown; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavDown.m_iPanelID;
  p_m_NavDown = &this->m_NavDown;
  v34 = &this->m_NavDown;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavDown = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavDownName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavDownName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavDown, pPanel: v11);
      }
    }
  }
  if ( p_m_NavDown->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavDown = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavDown->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavDown.m_iPanelID;
  v23 = &this->m_NavDown;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavDown;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavDown(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x0041FE20
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavLeft; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavLeft.m_iPanelID;
  p_m_NavLeft = &this->m_NavLeft;
  v34 = &this->m_NavLeft;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavLeft = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavLeftName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavLeftName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavLeft, pPanel: v11);
      }
    }
  }
  if ( p_m_NavLeft->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavLeft = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavLeft->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavLeft.m_iPanelID;
  v23 = &this->m_NavLeft;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavLeft;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavLeft(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x0041FFF0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavRight; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavRight.m_iPanelID;
  p_m_NavRight = &this->m_NavRight;
  v34 = &this->m_NavRight;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavRight = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavRightName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavRightName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavRight, pPanel: v11);
      }
    }
  }
  if ( p_m_NavRight->m_iPanelID == -1
    || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavRight = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavRight->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavRight.m_iPanelID;
  v23 = &this->m_NavRight;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavRight;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavRight(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x004208A0
// Name: public: struct vgui::PanelKeyBindingMap __near * vgui::Panel::LookupMapForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupMapForBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebx
  int v3; // edi
  int v4; // esi
  int c; // [esp+Ch] [ebp-4h]

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v3 = 0;
    c = v2->entries.m_Size;
    if ( c > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v4 = 0;
  while ( _V_stricmp(s1: v2->entries.m_Memory.m_pMemory[v4].bindingname, s2: bindingName) != 0 )
  {
    ++v3;
    ++v4;
    if ( v3 >= c )
      goto LABEL_6;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00420900
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBindingByKeyCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBindingByKeyCode(
        vgui::Panel *this,
        ButtonCode_t code,
        int modifiers)
{
  vgui::Panel *v3; // esi
  vgui::PanelKeyBindingMap *v4; // ebx
  int m_Size; // edi
  vgui::BoundKey_t *v6; // eax
  vgui::PanelKeyBindingMap *v7; // eax
  int v8; // ebx
  int v9; // edi
  const char **p_bindingname; // esi
  int c; // [esp+Ch] [ebp-20h]
  int v14; // [esp+14h] [ebp-18h]
  char *s2; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  vgui::PanelKeyBindingMap *map; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  vgui::PanelKeyBindingMap *baseMap; // [esp+28h] [ebp-4h]

  v3 = this;
  map = (vgui::PanelKeyBindingMap *)((int (__fastcall *)(vgui::Panel *))this->GetKBMap)(a1: this);
  if ( map == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = map;
    m_Size = map->boundkeys.m_Size;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
      break;
LABEL_17:
    map = v4->baseMap;
    if ( map == nullptr )
      return nullptr;
  }
  v18 = 0;
  while ( 1 )
  {
    v6 = &v4->boundkeys.m_Memory.m_pMemory[v18];
    if ( v6->keycode == code && v6->modifiers == modifiers )
    {
      s2 = (char *)v6->bindingname;
      v7 = v3->GetKBMap(this: v3);
      baseMap = v7;
      if ( v7 != nullptr )
        break;
    }
LABEL_16:
    ++v18;
    if ( ++i >= m_Size )
      goto LABEL_17;
  }
  while ( 1 )
  {
    v8 = 0;
    v14 = v7->entries.m_Size;
    if ( v14 > 0 )
      break;
LABEL_14:
    baseMap = v7->baseMap;
    if ( baseMap == nullptr )
    {
      m_Size = c;
      v4 = map;
      goto LABEL_16;
    }
    v7 = v7->baseMap;
  }
  v9 = 0;
  while ( 1 )
  {
    p_bindingname = &v7->entries.m_Memory.m_pMemory[v9].bindingname;
    if ( _V_stricmp(s1: *p_bindingname, s2) == 0 )
      return (vgui::KeyBindingMap_t *)p_bindingname;
    v7 = baseMap;
    ++v8;
    ++v9;
    if ( v8 >= v14 )
    {
      v3 = this;
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421D00
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateUp(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateUp(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavUp(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_UP;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421D40
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateDown(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateDown(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavDown(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_DOWN;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421D80
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateLeft(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateLeft(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavLeft(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_LEFT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421DC0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateRight(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateRight(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavRight(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_RIGHT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427100
// Name: private: class vgui::Panel __near * vgui::Panel::FindDropTargetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindDropTargetPanel(vgui::Panel *this)
{
  unsigned int v1; // ebx
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // esi
  const char *ControlsModuleName; // eax
  unsigned int v5; // ebx
  vgui::IPanel *v6; // edi
  vgui::IPanel_vtbl *v7; // esi
  const char *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // ebx
  int v11; // edi
  int m_Size; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  vgui::IPanel *v17; // edi
  vgui::IPanel_vtbl *v18; // esi
  unsigned int *v19; // ebx
  const char *v20; // eax
  int v21; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hits; // [esp+Ch] [ebp-24h] BYREF
  int nCount; // [esp+20h] [ebp-10h]
  vgui::Panel *v24; // [esp+24h] [ebp-Ch]
  int x; // [esp+28h] [ebp-8h] BYREF
  int y; // [esp+2Ch] [ebp-4h] BYREF

  v24 = this;
  if ( s_DragDropHelper.m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  if ( v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName) == nullptr )
    return nullptr;
  memset(&hits, 0, sizeof(hits));
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  nCount = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( s_DragDropHelper.m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID)) == 0 )
  {
    v9 = nullptr;
  }
  else
  {
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = vgui::GetControlsModuleName();
    v9 = v7->GetPanel(this: v6, a2: v5, a3: v8);
  }
  v10 = v9->GetVPanel(this: v9);
  if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
    && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
  {
    v11 = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1;
    if ( v11 >= 0 )
    {
      do
      {
        m_Size = hits.m_Size;
        if ( hits.m_Size != 0 )
          goto LABEL_20;
        v13 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v11);
        v14 = v13;
        if ( v13 != nCount && v13 != v10 && g_pVGuiPanel->IsFullyVisible(this: g_pVGuiPanel, a2: v13) )
          vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: v14);
      }
      while ( --v11 >= 0 );
    }
    m_Size = hits.m_Size;
    if ( hits.m_Size != 0 )
      goto LABEL_20;
    vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: nCount);
  }
  m_Size = hits.m_Size;
  if ( hits.m_Size == 0 )
  {
LABEL_21:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
    return nullptr;
  }
LABEL_20:
  v15 = m_Size - 1;
  nCount = v15;
  if ( v15 < 0 )
    goto LABEL_21;
  while ( 1 )
  {
    v17 = g_pVGuiPanel;
    v18 = g_pVGuiPanel->__vftable;
    v19 = &hits.m_Memory.m_pMemory[v15];
    v20 = v24->GetModuleName(this: v24);
    v21 = (int)v18->GetPanel(this: v17, a2: *v19, a3: v20);
    if ( v21 != 0 )
      break;
    if ( --nCount < 0 )
    {
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
      return nullptr;
    }
    v15 = nCount;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
  return (vgui::Panel *)v21;
}

//------------------------------------------------------------------------------
// Address: 0x00428610
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Panel::GetMessageMap(vgui::Panel *this)
{
  CPanelMessageMapDictionary *PanelMessageMapDictionary; // eax
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetMessageMap'::`2'::s_pMap;
  `vgui::Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  PanelMessageMapDictionary = GetPanelMessageMapDictionary();
  result = CPanelMessageMapDictionary::FindOrAddPanelMessageMap(this: PanelMessageMapDictionary, className: "Panel");
  `vgui::Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428640
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::GetKBMap(vgui::Panel *this)
{
  CPanelKeyBindingMapDictionary *PanelKeyBindingMapDictionary; // eax
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetKBMap'::`2'::s_pMap;
  `vgui::Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  PanelKeyBindingMapDictionary = vgui::GetPanelKeyBindingMapDictionary();
  result = CPanelKeyBindingMapDictionary::FindOrAddPanelKeyBindingMap(
             this: PanelKeyBindingMapDictionary,
             className: "Panel");
  `vgui::Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00493450
// Name: _dynamic_initializer_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__panel_test_title_safe__()
{
  ConVar::ConVar(
    this: &panel_test_title_safe,
    pName: "panel_test_title_safe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Test vgui panel positioning with title safe indentation");
  return atexit(func: dynamic_atexit_destructor_for__panel_test_title_safe__);
}

//------------------------------------------------------------------------------
// Address: 0x00493C50
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}

} // namespace vgui_editor
