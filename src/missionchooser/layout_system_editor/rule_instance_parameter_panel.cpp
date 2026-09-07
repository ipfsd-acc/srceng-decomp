// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system_editor/rule_instance_parameter_panel.cpp
// Functions: 65
// ============================================================

#include "missionchooser\layout_system_editor\rule_instance_parameter_panel.h"

//------------------------------------------------------------------------------
// Address: 0x10021E40
// Name: public: static char const __near * CRuleInstanceParameterPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRuleInstanceParameterPanel::GetPanelClassName()
{
  return "CRuleInstanceParameterPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10021E50
// Name: public: static char const __near * CEditableValuePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CEditableValuePanel::GetPanelClassName()
{
  return "CEditableValuePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10021E60
// Name: public: static char const __near * CArrayValuePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CArrayValuePanel::GetPanelClassName()
{
  return "CArrayValuePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10021E70
// Name: public: static char const __near * CBoolValuePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBoolValuePanel::GetPanelClassName()
{
  return "CBoolValuePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10021E80
// Name: public: static char const __near * CStringValuePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CStringValuePanel::GetPanelClassName()
{
  return "CStringValuePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10021E90
// Name: public: static char const __near * CEnumValuePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CEnumValuePanel::GetPanelClassName()
{
  return "CEnumValuePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10021EA0
// Name: public: static char const __near * CThemeValuePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CThemeValuePanel::GetPanelClassName()
{
  return "CThemeValuePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10021EB0
// Name: public: static char const __near * CFileValuePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFileValuePanel::GetPanelClassName()
{
  return "CFileValuePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10021EC0
// Name: public: virtual void CBoolValuePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoolValuePanel::ApplySchemeSettings(CBoolValuePanel *this, vgui::IScheme *pScheme)
{
  CNodePanel::ApplySchemeSettings(this, pScheme);
  this->SetBorder(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10021EF0
// Name: public: virtual void CBoolValuePanel::OnButtonChecked(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoolValuePanel::OnButtonChecked(CBoolValuePanel *this, vgui::Panel *pCheckButton)
{
  KeyValues *m_pNodeKV; // esi
  bool v3; // al

  m_pNodeKV = this->m_pNodeKV;
  v3 = this->m_pCheckButton->IsSelected(this: this->m_pCheckButton);
  KeyValues::SetInt(this: m_pNodeKV, keyName: nullptr, value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10021F20
// Name: public: virtual void CBoolValuePanel::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoolValuePanel::UpdateState(CBoolValuePanel *this)
{
  bool v2; // [esp+4h] [ebp-4h]

  v2 = KeyValues::GetInt(this: this->m_pNodeKV, keyName: nullptr, defaultValue: 0) != 0;
  this->m_pCheckButton->SetSelected(this: this->m_pCheckButton, a2: v2);
  CNodePanel::UpdateState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10021F60
// Name: public: virtual void CStringValuePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringValuePanel::OnTextChanged(CStringValuePanel *this, vgui::Panel *pTextEntry)
{
  KeyValues *m_pNodeKV; // ecx
  char buf[2048]; // [esp+4h] [ebp-800h] BYREF

  this->m_pTextEntry->GetText_2(this: this->m_pTextEntry, a2: buf, a3: 2048);
  m_pNodeKV = this->m_pNodeKV;
  buf[2047] = 0;
  KeyValues::SetString(this: m_pNodeKV, keyName: nullptr, value: buf);
}

//------------------------------------------------------------------------------
// Address: 0x10021FB0
// Name: public: virtual void CStringValuePanel::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringValuePanel::UpdateState(CStringValuePanel *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  const char *String; // eax

  v2 = this->m_pTextEntry->__vftable;
  String = KeyValues::GetString(this: this->m_pNodeKV, keyName: nullptr, defaultValue: szDescription);
  v2->SetText(this: this->m_pTextEntry, a2: String);
  CNodePanel::UpdateState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10021FF0
// Name: public: virtual void CEnumValuePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnumValuePanel::OnTextChanged(CEnumValuePanel *this, vgui::Panel *pComboBox)
{
  KeyValues *ActiveItemUserData; // eax
  KeyValues *m_pNodeKV; // esi
  int Int; // eax

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pComboBox);
  if ( ActiveItemUserData != nullptr )
  {
    m_pNodeKV = this->m_pNodeKV;
    Int = KeyValues::GetInt(this: ActiveItemUserData, keyName: nullptr, defaultValue: 0);
    KeyValues::SetInt(this: m_pNodeKV, keyName: nullptr, value: Int);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022030
// Name: public: virtual void CEnumValuePanel::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnumValuePanel::UpdateState(CEnumValuePanel *this)
{
  int Int; // eax
  int Entry; // eax
  vgui::ComboBox *m_pComboBox; // ecx

  Int = KeyValues::GetInt(this: this->m_pNodeKV, keyName: nullptr, defaultValue: 0);
  Entry = CTilegenEnum::FindEntry(this: (CTilegenEnum *)this->m_pTilegenEnum, nValue: Int);
  m_pComboBox = this->m_pComboBox;
  if ( Entry == -1 )
    m_pComboBox->SetText(this: m_pComboBox, a2: "INVALID ENTRY");
  else
    m_pComboBox->ActivateItem(this: m_pComboBox, a2: Entry);
  CNodePanel::UpdateState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10022090
// Name: public: virtual void CThemeValuePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeValuePanel::OnCommand(CThemeValuePanel *this, const char *pCommand)
{
  CThemeRoomPicker *v3; // edi
  vgui::Panel *v4; // eax
  CThemeRoomPicker *v5; // edi
  const char *String; // eax
  CLevelTheme *Theme; // eax
  KeyValues *m_pNodeKV; // [esp-8h] [ebp-10h]

  if ( _V_stricmp(s1: pCommand, s2: "ChangeTheme") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "Update") != 0 )
    {
      CNodePanel::OnCommand(this, pCommand);
    }
    else
    {
      String = KeyValues::GetString(this: this->m_pNodeKV, keyName: nullptr, defaultValue: szDescription);
      Theme = CLevelTheme::FindTheme(szThemeName: String);
      CThemeDetails::SetTheme(this: this->m_pThemeDetails, pTheme: Theme);
      this->m_pThemeDetails->InvalidateLayout(this: this->m_pThemeDetails, a2: false, a3: false);
    }
  }
  else
  {
    v3 = (CThemeRoomPicker *)operator new(nSize: 0x230u);
    if ( v3 != nullptr )
    {
      m_pNodeKV = this->m_pNodeKV;
      v4 = this->GetParent(this);
      v5 = CThemeRoomPicker::CThemeRoomPicker(
             this: v3,
             parent: v4,
             name: "ThemeRoomPicker",
             pKey: m_pNodeKV,
             bPickRooms: false);
    }
    else
    {
      v5 = nullptr;
    }
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    v5->DoModal(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022170
// Name: public: virtual void CThemeValuePanel::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeValuePanel::UpdateState(CThemeValuePanel *this)
{
  const char *String; // eax
  CLevelTheme *Theme; // eax

  String = KeyValues::GetString(this: this->m_pNodeKV, keyName: nullptr, defaultValue: szDescription);
  Theme = CLevelTheme::FindTheme(szThemeName: String);
  CThemeDetails::SetTheme(this: this->m_pThemeDetails, pTheme: Theme);
  CNodePanel::UpdateState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100221B0
// Name: public: virtual void CFileValuePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileValuePanel::OnCommand(CFileValuePanel *this, const char *pCommand)
{
  vgui::FileOpenDialog *v3; // eax
  vgui::FileOpenDialog *v4; // esi
  char templateDirectory[260]; // [esp+8h] [ebp-208h] BYREF
  char buf[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( _V_stricmp(s1: pCommand, s2: "ChangeFile") != 0 )
  {
    CNodePanel::OnCommand(this, pCommand);
  }
  else
  {
    V_snprintf(pDest: buf, maxLen: 260, pFormat: "Pick %s", this->m_FileTypeName);
    v3 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
    if ( v3 != nullptr )
      v4 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: this,
             title: buf,
             bOpenOnly: true,
             pContextKeyValues: nullptr);
    else
      v4 = nullptr;
    V_snprintf(pDest: templateDirectory, maxLen: 260, pFormat: "%s\\%s", g_gamedir, this->m_BaseDirectory);
    vgui::FileOpenDialog::SetStartDirectory(this: v4, dir: templateDirectory);
    V_snprintf(pDest: buf, maxLen: 260, pFormat: "%s (%s)", this->m_FileTypeName, this->m_FileExtension);
    vgui::FileOpenDialog::AddFilter(
      this: v4,
      filter: this->m_FileExtension,
      filterName: buf,
      bActive: true,
      pFilterInfo: nullptr);
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    vgui::FileOpenDialog::DoModal(this: v4, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100222C0
// Name: public: virtual void CFileValuePanel::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileValuePanel::OnFileSelected(CFileValuePanel *this, KeyValues *pKeyValues)
{
  const char *String; // esi
  char *v4; // esi
  char buffer[260]; // [esp+8h] [ebp-108h] BYREF
  const char *pFullPath; // [esp+10Ch] [ebp-4h]
  const char *pFileStart; // [esp+118h] [ebp+8h]

  String = KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: nullptr);
  pFullPath = String;
  if ( String != nullptr )
  {
    if ( !g_pFullFileSystem->FullPathToRelativePath(this: g_pFullFileSystem, a2: String, a3: buffer, a4: 260) )
      goto LABEL_9;
    v4 = buffer;
    V_FixSlashes(pname: buffer, separator: 92);
    if ( this->m_bStripExtension )
      V_StripExtension(in: buffer, out: buffer, outSize: 260);
    if ( this->m_bStripPath
      && (pFileStart = V_stristr(pStr: buffer, pSearch: this->m_BaseDirectory)) != nullptr
      && (v4 = (char *)&pFileStart[_V_strlen(str: this->m_BaseDirectory)]) == nullptr )
    {
LABEL_9:
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Could not set file to %s (is it underneath the /tilegen/roomtemplates directory?)");
    }
    else
    {
      this->m_pTextEntry->SetText(this: this->m_pTextEntry, a2: v4);
      KeyValues::SetString(this: this->m_pNodeKV, keyName: nullptr, value: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100223E0
// Name: public: virtual void CFileValuePanel::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileValuePanel::UpdateState(CFileValuePanel *this)
{
  vgui::TextEntry_vtbl *v2; // edi
  const char *String; // eax

  v2 = this->m_pTextEntry->__vftable;
  String = KeyValues::GetString(this: this->m_pNodeKV, keyName: nullptr, defaultValue: szDescription);
  v2->SetText(this: this->m_pTextEntry, a2: String);
  CNodePanel::UpdateState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10022420
// Name: public: virtual void CRuleInstanceParameterPanel::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRuleInstanceParameterPanel::UpdateState(CRuleInstanceParameterPanel *this)
{
  CTilegenRule::SubstitutionVariable_t *m_pMemory; // ecx
  bool bShouldShowOptionalValues; // [esp+4h] [ebp-4h]

  bShouldShowOptionalValues = this->m_pEditor->m_bShowOptionalValues;
  if ( this->m_pNodeKV == nullptr
    && ((m_pMemory = this->m_pRule->m_SubstitutionVariables.m_Memory.m_pMemory)[this->m_nRuleParameterIndex].m_pDefault != nullptr
     || m_pMemory[this->m_nRuleParameterIndex].m_bCanOmit) )
  {
    this->SetVisible(this, a2: bShouldShowOptionalValues);
    CNodePanel::UpdateState(this);
  }
  else
  {
    this->SetVisible(this, a2: true);
    CNodePanel::UpdateState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100224A0
// Name: class KeyValues __near * CreateNewValue(class CTilegenRule const __near *,int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl CreateNewValue(const CTilegenRule *pRule, int nRuleParameterIndex)
{
  const char *m_pElementContainer; // esi
  KeyValues *v3; // eax

  m_pElementContainer = pRule->m_SubstitutionVariables.m_Memory.m_pMemory[nRuleParameterIndex].m_pElementContainer;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( m_pElementContainer != nullptr )
  {
    if ( v3 != nullptr )
      return KeyValues::KeyValues(
               this: v3,
               setName: m_pElementContainer,
               firstKey: "rule_instance",
               firstValue: "<null>");
  }
  else if ( v3 != nullptr )
  {
    return KeyValues::KeyValues(this: v3, setName: "rule_instance", firstKey: nullptr, firstValue: "<null>");
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10022500
// Name: public: void CArrayValuePanel::AddNewParameterElementPanel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArrayValuePanel::AddNewParameterElementPanel(CArrayValuePanel *this, int nIndex)
{
  bool m_bAllowExpression; // bl
  CNewElementPanel *v4; // eax
  CNewElementPanel *v5; // edi

  m_bAllowExpression = this->m_pRule->m_SubstitutionVariables.m_Memory.m_pMemory[this->m_nRuleParameterIndex].m_bAllowExpression;
  v4 = (CNewElementPanel *)operator new(nSize: 0x188u);
  if ( v4 != nullptr )
    v5 = CNewElementPanel::CNewElementPanel(this: v4, pParent: this, pName: "NewElement", nIndex);
  else
    v5 = nullptr;
  if ( m_bAllowExpression )
    CNewElementPanel::AddButton(this: v5, pButtonText: "Add Rule", pActionName: (KeyValues *)"AddRule");
  CNodePanel::AddChild(this, pPanel: v5, nPadding: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10022570
// Name: public: virtual void CArrayValuePanel::OnAddRule(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArrayValuePanel::OnAddRule(CArrayValuePanel *this, KeyValues *pKV)
{
  int Int; // ebx
  const char *m_pElementContainer; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  Int = KeyValues::GetInt(this: pKV, keyName: "index", defaultValue: -1);
  m_pElementContainer = this->m_pRule->m_SubstitutionVariables.m_Memory.m_pMemory[this->m_nRuleParameterIndex].m_pElementContainer;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( m_pElementContainer != nullptr )
  {
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v5, setName: m_pElementContainer, firstKey: "rule_instance", firstValue: "<null>");
      CNodePanel::InsertChildData(this, nIndex: Int, pKeyValues: v6);
      return;
    }
  }
  else if ( v5 != nullptr )
  {
    v7 = KeyValues::KeyValues(this: v5, setName: "rule_instance", firstKey: nullptr, firstValue: "<null>");
    CNodePanel::InsertChildData(this, nIndex: Int, pKeyValues: v7);
    return;
  }
  CNodePanel::InsertChildData(this, nIndex: Int, pKeyValues: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10022610
// Name: public: virtual void CRuleInstanceParameterPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRuleInstanceParameterPanel::OnCommand(CRuleInstanceParameterPanel *this, KeyValues *pCommand)
{
  vgui::Panel *v3; // eax
  KeyValues *Key; // ebx
  const char *Name; // eax
  CTilegenRule::SubstitutionVariable_t *m_pMemory; // eax
  const char *m_pName; // edi
  KeyValues *m_pDefault; // eax
  KeyValues *Copy; // edi
  KeyValues *v10; // eax
  const CTilegenRule *m_pRule; // ecx
  int m_nRuleParameterIndex; // eax
  KeyValues *NewValue; // eax
  KeyValues *pParentKV; // [esp+10h] [ebp+8h]

  if ( _V_stricmp(s1: (const char *)pCommand, s2: "AddParam") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)pCommand, s2: "DeleteParam") == 0 )
      CNodePanel::SetData(this, pNodeKV: nullptr);
    CNodePanel::OnCommand(this, (const char *)pCommand);
  }
  else
  {
    v3 = this->GetParent(this);
    Key = *((KeyValues **)__RTDynamicCast(
                            inptr: v3,
                            VfDelta: 0,
                            SrcType: &vgui::Panel `RTTI Type Descriptor',
                            TargetType: &CRuleInstanceNodePanel `RTTI Type Descriptor',
                            isReference: 0)
          + 147);
    pParentKV = Key;
    Name = KeyValues::GetName(this: Key);
    if ( _V_stricmp(s1: Name, s2: "rule_instance") == 0
      || (Key = KeyValues::FindKey(this: Key, keyName: "rule_instance", bCreate: false), pParentKV = Key, Key != nullptr) )
    {
      m_pMemory = this->m_pRule->m_SubstitutionVariables.m_Memory.m_pMemory;
      m_pName = m_pMemory[this->m_nRuleParameterIndex].m_pName;
      m_pDefault = m_pMemory[this->m_nRuleParameterIndex].m_pDefault;
      if ( m_pDefault != nullptr )
      {
        Copy = KeyValues::MakeCopy(this: m_pDefault);
      }
      else
      {
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          Copy = KeyValues::KeyValues(this: v10, setName: m_pName);
        else
          Copy = nullptr;
        m_pRule = this->m_pRule;
        m_nRuleParameterIndex = this->m_nRuleParameterIndex;
        if ( m_pRule->m_SubstitutionVariables.m_Memory.m_pMemory[m_nRuleParameterIndex].m_bAllowExpression )
        {
          NewValue = CreateNewValue(pRule: m_pRule, nRuleParameterIndex: m_nRuleParameterIndex);
          KeyValues::AddSubKey(this: Copy, pSubkey: NewValue);
        }
        else
        {
          KeyValues::SetStringValue(this: Copy, strValue: szDescription);
        }
        Key = pParentKV;
      }
      KeyValues::AddSubKey(this: Key, pSubkey: Copy);
      CNodePanel::SetData(this, pNodeKV: Copy);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022750
// Name: public: static void CArrayValuePanel::PanelMessageFunc_OnAddRule::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CArrayValuePanel::PanelMessageFunc_OnAddRule::InitVar(int a1@<ebp>)
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
  if ( !`CArrayValuePanel::PanelMessageFunc_OnAddRule::InitVar'::`2'::bAdded )
  {
    `CArrayValuePanel::PanelMessageFunc_OnAddRule::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TextEntry::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CArrayValuePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "AddRule";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100227E0
// Name: public: static void CBoolValuePanel::PanelMessageFunc_OnButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBoolValuePanel::PanelMessageFunc_OnButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CBoolValuePanel::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded )
  {
    `CBoolValuePanel::PanelMessageFunc_OnButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRuleInstanceNodePanel::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBoolValuePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x10022880
// Name: public: static void CStringValuePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CStringValuePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CStringValuePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CStringValuePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CTilegenKVEditorPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CStringValuePanel");
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
// Address: 0x10022920
// Name: public: static void CEnumValuePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CEnumValuePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CEnumValuePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CEnumValuePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CTilegenKVEditorPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CEnumValuePanel");
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
// Address: 0x100229C0
// Name: public: static void CFileValuePanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileValuePanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CFileValuePanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CFileValuePanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRuleInstanceNodePanel::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CFileValuePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "FileSelected";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022A50
// Name: public: CEditableValuePanel::CEditableValuePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CEditableValuePanel *__thiscall CEditableValuePanel::CEditableValuePanel(
        CEditableValuePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  CNodePanel::CNodePanel(this, pParent, pName);
  this->__vftable = (CEditableValuePanel_vtbl *)&CEditableValuePanel::`vftable';
  if ( `CEditableValuePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CEditableValuePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CEditableValuePanel");
    v4->pfnClassName = CEditableValuePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
  }
  if ( `CEditableValuePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CEditableValuePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CEditableValuePanel");
    v5->pfnClassName = CEditableValuePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CNodePanel");
  }
  if ( `CEditableValuePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CEditableValuePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CEditableValuePanel");
    v6->pfnClassName = CEditableValuePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CNodePanel");
  }
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10022B20
// Name: public: virtual struct vgui::PanelMessageMap __near * CEditableValuePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CEditableValuePanel::GetMessageMap(CEditableValuePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CEditableValuePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CEditableValuePanel::GetMessageMap'::`2'::s_pMap;
  `CEditableValuePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CEditableValuePanel");
  `CEditableValuePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022B50
// Name: public: virtual struct PanelAnimationMap __near * CEditableValuePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CEditableValuePanel::GetAnimMap(CEditableValuePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CEditableValuePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10022B60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CEditableValuePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CEditableValuePanel::GetKBMap(CEditableValuePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CEditableValuePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CEditableValuePanel::GetKBMap'::`2'::s_pMap;
  `CEditableValuePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CEditableValuePanel");
  `CEditableValuePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022B90
// Name: public: CArrayValuePanel::CArrayValuePanel(class vgui::Panel __near *,char const __near *,class CTilegenRule const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CArrayValuePanel *__thiscall CArrayValuePanel::CArrayValuePanel(
        CArrayValuePanel *this,
        vgui::Panel *pParent,
        const char *pName,
        const CTilegenRule *pRule,
        int nRuleParameterIndex)
{
  vgui::PanelMessageMap *v6; // esi
  PanelAnimationMap *v7; // esi
  vgui::PanelKeyBindingMap *v8; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CNodePanel::CNodePanel(this, pParent, pName);
  this->__vftable = (CArrayValuePanel_vtbl *)&CArrayValuePanel::`vftable';
  if ( `CArrayValuePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CArrayValuePanel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CArrayValuePanel");
    v6->pfnClassName = CArrayValuePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
  }
  if ( `CArrayValuePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CArrayValuePanel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CArrayValuePanel");
    v7->pfnClassName = CArrayValuePanel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "CNodePanel");
  }
  if ( `CArrayValuePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CArrayValuePanel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CArrayValuePanel");
    v8->pfnClassName = CArrayValuePanel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CNodePanel");
  }
  CArrayValuePanel::PanelMessageFunc_OnAddRule::InitVar(a1: (int)&savedregs);
  this->m_nRuleParameterIndex = nRuleParameterIndex;
  this->m_pRule = pRule;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10022C70
// Name: public: virtual struct vgui::PanelMessageMap __near * CArrayValuePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CArrayValuePanel::GetMessageMap(CArrayValuePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CArrayValuePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CArrayValuePanel::GetMessageMap'::`2'::s_pMap;
  `CArrayValuePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CArrayValuePanel");
  `CArrayValuePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022CA0
// Name: public: virtual struct PanelAnimationMap __near * CArrayValuePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CArrayValuePanel::GetAnimMap(CArrayValuePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CArrayValuePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10022CB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CArrayValuePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CArrayValuePanel::GetKBMap(CArrayValuePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CArrayValuePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CArrayValuePanel::GetKBMap'::`2'::s_pMap;
  `CArrayValuePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CArrayValuePanel");
  `CArrayValuePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022CE0
// Name: public: CBoolValuePanel::CBoolValuePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBoolValuePanel *__thiscall CBoolValuePanel::CBoolValuePanel(
        CBoolValuePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CheckButton *v7; // eax
  vgui::CheckButton *v8; // eax
  vgui::CBoxSizer *v9; // eax
  vgui::CBoxSizer *v10; // edi
  int m_Size; // ecx
  vgui::CheckButton *m_pCheckButton; // [esp-8h] [ebp-28h]
  vgui::SizerAddArgs_t args; // [esp+8h] [ebp-18h] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  CEditableValuePanel::CEditableValuePanel(this, pParent, pName);
  this->__vftable = (CBoolValuePanel_vtbl *)&CBoolValuePanel::`vftable';
  if ( `CBoolValuePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBoolValuePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CBoolValuePanel");
    v4->pfnClassName = CBoolValuePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CEditableValuePanel");
  }
  if ( `CBoolValuePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBoolValuePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CBoolValuePanel");
    v5->pfnClassName = CBoolValuePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CEditableValuePanel");
  }
  if ( `CBoolValuePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBoolValuePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CBoolValuePanel");
    v6->pfnClassName = CBoolValuePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CEditableValuePanel");
  }
  CBoolValuePanel::PanelMessageFunc_OnButtonChecked::InitVar(a1: (int)&savedregs);
  v7 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v7 != nullptr )
    v8 = vgui::CheckButton::CheckButton(this: v7, parent: this, panelName: "CheckBox", text: nullptr);
  else
    v8 = nullptr;
  this->m_pCheckButton = v8;
  v9 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v9 != nullptr )
    v10 = vgui::CBoxSizer::CBoxSizer(this: v9, LayoutDirection: ESLD_HORIZONTAL);
  else
    v10 = nullptr;
  m_Size = v10->m_Members.m_Size;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  m_pCheckButton = this->m_pCheckButton;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 0;
  args.m_flExpandFactor = 0.0;
  vgui::CSizerBase::InsertPanel(this: v10, nIndex: m_Size, pPanel: m_pCheckButton, &args);
  vgui::Panel::SetSizer(this, pSizer: v10);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10022E30
// Name: public: virtual struct vgui::PanelMessageMap __near * CBoolValuePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBoolValuePanel::GetMessageMap(CBoolValuePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBoolValuePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBoolValuePanel::GetMessageMap'::`2'::s_pMap;
  `CBoolValuePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBoolValuePanel");
  `CBoolValuePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022E60
// Name: public: virtual struct PanelAnimationMap __near * CBoolValuePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBoolValuePanel::GetAnimMap(CBoolValuePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBoolValuePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10022E70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBoolValuePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBoolValuePanel::GetKBMap(CBoolValuePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBoolValuePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBoolValuePanel::GetKBMap'::`2'::s_pMap;
  `CBoolValuePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBoolValuePanel");
  `CBoolValuePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022EA0
// Name: public: CStringValuePanel::CStringValuePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CStringValuePanel *__thiscall CStringValuePanel::CStringValuePanel(
        CStringValuePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::CBoxSizer *v9; // eax
  vgui::CBoxSizer *v10; // edi
  vgui::TextEntry *m_pTextEntry; // edx
  int m_Size; // [esp-Ch] [ebp-2Ch]
  vgui::SizerAddArgs_t args; // [esp+8h] [ebp-18h] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  CEditableValuePanel::CEditableValuePanel(this, pParent, pName);
  this->__vftable = (CStringValuePanel_vtbl *)&CStringValuePanel::`vftable';
  if ( `CStringValuePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CStringValuePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CStringValuePanel");
    v4->pfnClassName = CStringValuePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CEditableValuePanel");
  }
  if ( `CStringValuePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CStringValuePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CStringValuePanel");
    v5->pfnClassName = CStringValuePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CEditableValuePanel");
  }
  if ( `CStringValuePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CStringValuePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CStringValuePanel");
    v6->pfnClassName = CStringValuePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CEditableValuePanel");
  }
  CStringValuePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  v7 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "TextEntry");
  else
    v8 = nullptr;
  this->m_pTextEntry = v8;
  v8->SetAutoLocalize(this: v8, a2: false);
  v9 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v9 != nullptr )
    v10 = vgui::CBoxSizer::CBoxSizer(this: v9, LayoutDirection: ESLD_HORIZONTAL);
  else
    v10 = nullptr;
  m_pTextEntry = this->m_pTextEntry;
  args.m_nMinX = 20;
  args.m_nMinY = 20;
  m_Size = v10->m_Members.m_Size;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 2;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertPanel(this: v10, nIndex: m_Size, pPanel: m_pTextEntry, &args);
  vgui::Panel::SetSizer(this, pSizer: v10);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10023000
// Name: public: virtual struct vgui::PanelMessageMap __near * CStringValuePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CStringValuePanel::GetMessageMap(CStringValuePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CStringValuePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CStringValuePanel::GetMessageMap'::`2'::s_pMap;
  `CStringValuePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CStringValuePanel");
  `CStringValuePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023030
// Name: public: virtual struct PanelAnimationMap __near * CStringValuePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CStringValuePanel::GetAnimMap(CStringValuePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CStringValuePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10023040
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CStringValuePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CStringValuePanel::GetKBMap(CStringValuePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CStringValuePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CStringValuePanel::GetKBMap'::`2'::s_pMap;
  `CStringValuePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CStringValuePanel");
  `CStringValuePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023070
// Name: public: CEnumValuePanel::CEnumValuePanel(class vgui::Panel __near *,char const __near *,class CTilegenEnum const __near *)
// Source: json
//------------------------------------------------------------------------------
CEnumValuePanel *__thiscall CEnumValuePanel::CEnumValuePanel(
        CEnumValuePanel *this,
        vgui::Panel *pParent,
        KeyValues *pName,
        const CTilegenEnum *pTilegenEnum)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi
  vgui::ComboBox *v8; // eax
  vgui::ComboBox *v9; // eax
  int i; // esi
  KeyValues *v11; // eax
  vgui::CBoxSizer *v12; // eax
  vgui::CBoxSizer *v13; // esi
  vgui::ComboBox *m_pComboBox; // edx
  int m_Size; // [esp-Ch] [ebp-30h]
  vgui::SizerAddArgs_t args; // [esp+Ch] [ebp-18h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF
  KeyValues *pItemKV; // [esp+30h] [ebp+Ch]

  CEditableValuePanel::CEditableValuePanel(this, pParent, (const char *)pName);
  this->__vftable = (CEnumValuePanel_vtbl *)&CEnumValuePanel::`vftable';
  if ( `CEnumValuePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CEnumValuePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CEnumValuePanel");
    v5->pfnClassName = CEnumValuePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CEditableValuePanel");
  }
  if ( `CEnumValuePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CEnumValuePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CEnumValuePanel");
    v6->pfnClassName = CEnumValuePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CEditableValuePanel");
  }
  if ( `CEnumValuePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CEnumValuePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CEnumValuePanel");
    v7->pfnClassName = CEnumValuePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CEditableValuePanel");
  }
  CEnumValuePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_pTilegenEnum = pTilegenEnum;
  v8 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v8 != nullptr )
    v9 = vgui::ComboBox::ComboBox(this: v8, parent: this, panelName: "ComboBox", numLines: 6, allowEdit: false);
  else
    v9 = nullptr;
  this->m_pComboBox = v9;
  v9->SetAutoLocalize(this: v9, a2: false);
  for ( i = 0; i < pTilegenEnum->m_Entries.m_Size; ++i )
  {
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      pItemKV = KeyValues::KeyValues(this: v11, setName: "EnumValue");
    else
      pItemKV = nullptr;
    KeyValues::SetInt(this: pItemKV, keyName: nullptr, value: pTilegenEnum->m_Entries.m_Memory.m_pMemory[i].m_nValue);
    this->m_pComboBox->AddItem_2(
      this: this->m_pComboBox,
      a2: pTilegenEnum->m_Entries.m_Memory.m_pMemory[i].m_pString,
      a3: pItemKV);
  }
  v12 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v12 != nullptr )
    v13 = vgui::CBoxSizer::CBoxSizer(this: v12, LayoutDirection: ESLD_HORIZONTAL);
  else
    v13 = nullptr;
  m_pComboBox = this->m_pComboBox;
  args.m_nMinX = 20;
  args.m_nMinY = 20;
  m_Size = v13->m_Members.m_Size;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 2;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertPanel(this: v13, nIndex: m_Size, pPanel: m_pComboBox, &args);
  vgui::Panel::SetSizer(this, pSizer: v13);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10023240
// Name: public: virtual struct vgui::PanelMessageMap __near * CEnumValuePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CEnumValuePanel::GetMessageMap(CEnumValuePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CEnumValuePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CEnumValuePanel::GetMessageMap'::`2'::s_pMap;
  `CEnumValuePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CEnumValuePanel");
  `CEnumValuePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023270
// Name: public: virtual struct PanelAnimationMap __near * CEnumValuePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CEnumValuePanel::GetAnimMap(CEnumValuePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CEnumValuePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10023280
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CEnumValuePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CEnumValuePanel::GetKBMap(CEnumValuePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CEnumValuePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CEnumValuePanel::GetKBMap'::`2'::s_pMap;
  `CEnumValuePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CEnumValuePanel");
  `CEnumValuePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100232B0
// Name: public: CThemeValuePanel::CThemeValuePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CThemeValuePanel *__thiscall CThemeValuePanel::CThemeValuePanel(
        CThemeValuePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  CThemeDetails *v9; // eax
  CThemeDetails *v10; // eax
  vgui::CBoxSizer *v11; // eax
  vgui::CBoxSizer *v12; // edi
  int m_Size; // [esp-Ch] [ebp-30h]
  int v15; // [esp-Ch] [ebp-30h]
  CThemeDetails *m_pThemeDetails; // [esp-8h] [ebp-2Ch]
  vgui::Button *m_pChangeThemeButton; // [esp-8h] [ebp-2Ch]
  vgui::SizerAddArgs_t args; // [esp+Ch] [ebp-18h] BYREF

  CEditableValuePanel::CEditableValuePanel(this, pParent, pName);
  this->__vftable = (CThemeValuePanel_vtbl *)&CThemeValuePanel::`vftable';
  if ( `CThemeValuePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CThemeValuePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CThemeValuePanel");
    v4->pfnClassName = CThemeValuePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CEditableValuePanel");
  }
  if ( `CThemeValuePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CThemeValuePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CThemeValuePanel");
    v5->pfnClassName = CThemeValuePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CEditableValuePanel");
  }
  if ( `CThemeValuePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CThemeValuePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CThemeValuePanel");
    v6->pfnClassName = CThemeValuePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CEditableValuePanel");
  }
  v7 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: this,
           panelName: "ChangeThemeButton",
           text: "Change Theme",
           pActionSignalTarget: this,
           pCmd: "ChangeTheme");
  else
    v8 = nullptr;
  this->m_pChangeThemeButton = v8;
  v9 = (CThemeDetails *)operator new(nSize: 0x170u);
  if ( v9 != nullptr )
    v10 = CThemeDetails::CThemeDetails(this: v9, parent: this, name: "ThemeDetails", pThemesDialog: nullptr);
  else
    v10 = nullptr;
  this->m_pThemeDetails = v10;
  v10->m_iDesiredWidth = 350;
  this->m_pThemeDetails->m_iDesiredHeight = 100;
  this->m_pThemeDetails->InvalidateLayout(this: this->m_pThemeDetails, a2: false, a3: false);
  vgui::Panel::SetSize(this: this->m_pChangeThemeButton, wide: 120, tall: 20);
  this->m_pThemeDetails->SetPaintBackgroundEnabled(this: this->m_pThemeDetails, a2: false);
  this->m_pChangeThemeButton->SetPaintBackgroundEnabled(this: this->m_pChangeThemeButton, a2: false);
  v11 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v11 != nullptr )
    v12 = vgui::CBoxSizer::CBoxSizer(this: v11, LayoutDirection: ESLD_HORIZONTAL);
  else
    v12 = nullptr;
  m_pThemeDetails = this->m_pThemeDetails;
  m_Size = v12->m_Members.m_Size;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 0;
  args.m_nMinX = 350;
  args.m_nMinY = 100;
  vgui::CSizerBase::InsertPanel(this: v12, nIndex: m_Size, pPanel: m_pThemeDetails, &args);
  m_pChangeThemeButton = this->m_pChangeThemeButton;
  v15 = v12->m_Members.m_Size;
  memset(&args, 0, 9);
  args.m_bIgnoreMemberMin = false;
  args.m_nMinX = 120;
  args.m_nMinY = 20;
  vgui::CSizerBase::InsertPanel(this: v12, nIndex: v15, pPanel: m_pChangeThemeButton, &args);
  vgui::Panel::SetSizer(this, pSizer: v12);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100234C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CThemeValuePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CThemeValuePanel::GetMessageMap(CThemeValuePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CThemeValuePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CThemeValuePanel::GetMessageMap'::`2'::s_pMap;
  `CThemeValuePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CThemeValuePanel");
  `CThemeValuePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100234F0
// Name: public: virtual struct PanelAnimationMap __near * CThemeValuePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CThemeValuePanel::GetAnimMap(CThemeValuePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CThemeValuePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10023500
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CThemeValuePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CThemeValuePanel::GetKBMap(CThemeValuePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CThemeValuePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CThemeValuePanel::GetKBMap'::`2'::s_pMap;
  `CThemeValuePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CThemeValuePanel");
  `CThemeValuePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023530
// Name: public: CFileValuePanel::CFileValuePanel(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CFileValuePanel *__thiscall CFileValuePanel::CFileValuePanel(
        CFileValuePanel *this,
        vgui::Panel *pParent,
        const char *pName,
        const char *pFileTypeName,
        const char *pFileExtension,
        const char *pBaseDirectory,
        bool bStripPath,
        bool bStripExtension)
{
  vgui::PanelMessageMap *v9; // edi
  PanelAnimationMap *v10; // edi
  vgui::PanelKeyBindingMap *v11; // edi
  vgui::TextEntry *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::CBoxSizer *v16; // eax
  vgui::CBoxSizer *v17; // edi
  int m_Size; // [esp-Ch] [ebp-30h]
  int v20; // [esp-Ch] [ebp-30h]
  vgui::TextEntry *m_pTextEntry; // [esp-8h] [ebp-2Ch]
  vgui::Button *m_pChangeFileButton; // [esp-8h] [ebp-2Ch]
  vgui::SizerAddArgs_t args; // [esp+Ch] [ebp-18h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  CEditableValuePanel::CEditableValuePanel(this, pParent, pName);
  this->__vftable = (CFileValuePanel_vtbl *)&CFileValuePanel::`vftable';
  if ( `CFileValuePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CFileValuePanel::ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelMessageMap(className: "CFileValuePanel");
    v9->pfnClassName = CFileValuePanel::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelMessageMap(className: "CEditableValuePanel");
  }
  if ( `CFileValuePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFileValuePanel::ChainToAnimationMap'::`2'::chained = 1;
    v10 = FindOrAddPanelAnimationMap(className: "CFileValuePanel");
    v10->pfnClassName = CFileValuePanel::GetPanelClassName;
    v10->baseMap = FindOrAddPanelAnimationMap(className: "CEditableValuePanel");
  }
  if ( `CFileValuePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFileValuePanel::KB_ChainToMap'::`2'::chained = 1;
    v11 = vgui::FindOrAddPanelKeyBindingMap(className: "CFileValuePanel");
    v11->pfnClassName = CFileValuePanel::GetPanelClassName;
    v11->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CEditableValuePanel");
  }
  CFileValuePanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  this->m_bStripPath = bStripPath;
  this->m_bStripExtension = bStripExtension;
  v12 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v12 != nullptr )
    v13 = vgui::TextEntry::TextEntry(this: v12, parent: this, panelName: "TextEntry");
  else
    v13 = nullptr;
  this->m_pTextEntry = v13;
  v13->SetAutoLocalize(this: v13, a2: false);
  this->m_pTextEntry->SetEditable(this: this->m_pTextEntry, a2: false);
  v14 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "ChangeFileButton",
            text: "...",
            pActionSignalTarget: this,
            pCmd: "ChangeFile");
  else
    v15 = nullptr;
  this->m_pChangeFileButton = v15;
  v16 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v16 != nullptr )
    v17 = vgui::CBoxSizer::CBoxSizer(this: v16, LayoutDirection: ESLD_HORIZONTAL);
  else
    v17 = nullptr;
  m_pTextEntry = this->m_pTextEntry;
  m_Size = v17->m_Members.m_Size;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 2;
  args.m_nMinX = 20;
  args.m_nMinY = 20;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertPanel(this: v17, nIndex: m_Size, pPanel: m_pTextEntry, &args);
  m_pChangeFileButton = this->m_pChangeFileButton;
  v20 = v17->m_Members.m_Size;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 2;
  args.m_nMinX = 20;
  args.m_nMinY = 20;
  vgui::CSizerBase::InsertPanel(this: v17, nIndex: v20, pPanel: m_pChangeFileButton, &args);
  vgui::Panel::SetSizer(this, pSizer: v17);
  V_strncpy(pDest: this->m_FileTypeName, pSrc: pFileTypeName, maxLen: 32);
  V_strncpy(pDest: this->m_FileExtension, pSrc: pFileExtension, maxLen: 32);
  V_strncpy(pDest: this->m_BaseDirectory, pSrc: pBaseDirectory, maxLen: 260);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10023750
// Name: public: virtual struct vgui::PanelMessageMap __near * CFileValuePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFileValuePanel::GetMessageMap(CFileValuePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFileValuePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFileValuePanel::GetMessageMap'::`2'::s_pMap;
  `CFileValuePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFileValuePanel");
  `CFileValuePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023780
// Name: public: virtual struct PanelAnimationMap __near * CFileValuePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFileValuePanel::GetAnimMap(CFileValuePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CFileValuePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10023790
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFileValuePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFileValuePanel::GetKBMap(CFileValuePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFileValuePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFileValuePanel::GetKBMap'::`2'::s_pMap;
  `CFileValuePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFileValuePanel");
  `CFileValuePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100237C0
// Name: public: CRuleInstanceParameterPanel::CRuleInstanceParameterPanel(class vgui::Panel __near *,char const __near *,class CTilegenRule const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CRuleInstanceParameterPanel *__thiscall CRuleInstanceParameterPanel::CRuleInstanceParameterPanel(
        CRuleInstanceParameterPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        const CTilegenRule *pRule,
        int nRuleParameterIndex)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Tooltip *Tooltip; // eax
  const char *m_pDescription; // [esp-4h] [ebp-Ch]

  CNodePanel::CNodePanel(this, pParent, pName);
  this->__vftable = (CRuleInstanceParameterPanel_vtbl *)&CRuleInstanceParameterPanel::`vftable';
  if ( `CRuleInstanceParameterPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CRuleInstanceParameterPanel::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CRuleInstanceParameterPanel");
    v6->pfnClassName = CRuleInstanceParameterPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
  }
  if ( `CRuleInstanceParameterPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRuleInstanceParameterPanel::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CRuleInstanceParameterPanel");
    v7->pfnClassName = CRuleInstanceParameterPanel::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "CNodePanel");
  }
  if ( `CRuleInstanceParameterPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRuleInstanceParameterPanel::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CRuleInstanceParameterPanel");
    v8->pfnClassName = CRuleInstanceParameterPanel::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CNodePanel");
  }
  this->m_nRuleParameterIndex = nRuleParameterIndex;
  this->m_pAddButton = nullptr;
  this->m_pDeleteButton = nullptr;
  this->m_pRule = pRule;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  m_pDescription = this->m_pRule->m_SubstitutionVariables.m_Memory.m_pMemory[this->m_nRuleParameterIndex].m_pDescription;
  Tooltip = vgui::Panel::GetTooltip(this);
  vgui::Tooltip::SetText(this: Tooltip, text: m_pDescription);
  CNodePanel::SetChildIndent(this, nIndent: 25);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100238E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CRuleInstanceParameterPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRuleInstanceParameterPanel::GetMessageMap(CRuleInstanceParameterPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRuleInstanceParameterPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRuleInstanceParameterPanel::GetMessageMap'::`2'::s_pMap;
  `CRuleInstanceParameterPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRuleInstanceParameterPanel");
  `CRuleInstanceParameterPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023910
// Name: public: virtual struct PanelAnimationMap __near * CRuleInstanceParameterPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRuleInstanceParameterPanel::GetAnimMap(CRuleInstanceParameterPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CRuleInstanceParameterPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10023920
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRuleInstanceParameterPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRuleInstanceParameterPanel::GetKBMap(CRuleInstanceParameterPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRuleInstanceParameterPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRuleInstanceParameterPanel::GetKBMap'::`2'::s_pMap;
  `CRuleInstanceParameterPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRuleInstanceParameterPanel");
  `CRuleInstanceParameterPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023950
// Name: class CNodePanel __near * CreateValuePanel(class CTilegenRule const __near *,int,class CNodePanel __near *,class KeyValues __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CFileValuePanel *__cdecl CreateValuePanel(
        CRuleInstanceNodePanel *pRule,
        int nRuleParameterIndex,
        CNodePanel *pParent,
        KeyValues *pData,
        bool *pIsChildPanel)
{
  int v6; // esi
  CTilegenRule::SubstitutionVariable_t *v7; // eax
  const char *m_pTypeName; // edi
  const char *Name; // eax
  CBoolValuePanel *v11; // eax
  CNodePanel *v12; // edi
  CFileValuePanel *v13; // esi
  CStringValuePanel *v14; // eax
  const CTilegenEnum *Enum; // ebx
  CEnumValuePanel *v16; // eax
  CFileValuePanel *v17; // eax
  CFileValuePanel *v18; // eax
  CFileValuePanel *v19; // eax
  CThemeValuePanel *v20; // eax
  CStringValuePanel *v21; // eax
  KeyValues *FirstSubKey; // eax
  KeyValues *v23; // eax
  const char *v24; // eax
  CRuleInstanceNodePanel *v25; // eax
  bool bAllowExpressions; // [esp+Fh] [ebp-1h]
  CRuleInstanceNodePanel *pRuleInstancePanel; // [esp+18h] [ebp+8h]
  bool pRuleInstancePanel_3; // [esp+1Bh] [ebp+Bh]
  bool bAllowLiterals_3; // [esp+1Fh] [ebp+Fh]

  *pIsChildPanel = false;
  v6 = 36 * nRuleParameterIndex;
  v7 = (CTilegenRule::SubstitutionVariable_t *)(36 * nRuleParameterIndex + *(_DWORD *)&pRule->m_clrDragFrame);
  m_pTypeName = v7->m_pTypeName;
  bAllowLiterals_3 = v7->m_bAllowLiteral;
  bAllowExpressions = v7->m_bAllowExpression;
  Name = KeyValues::GetName(this: pData);
  pRuleInstancePanel_3 = _V_stricmp(s1: Name, s2: "rule_instance") == 0;
  if ( KeyValues::GetFirstSubKey(this: pData) == nullptr && !pRuleInstancePanel_3 )
  {
    if ( !bAllowLiterals_3 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      {
        KeyValues::GetString(this: pData, keyName: nullptr, defaultValue: szDescription);
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Literal value (%s) is specified in key values file but not allowed for this rule instance parameter (%s).\n");
      }
      return nullptr;
    }
    if ( _V_stricmp(s1: m_pTypeName, s2: "bool") == 0 )
    {
      v11 = (CBoolValuePanel *)operator new(nSize: 0x298u);
      v12 = pParent;
      if ( v11 != nullptr )
      {
        v13 = (CFileValuePanel *)CBoolValuePanel::CBoolValuePanel(this: v11, pParent, pName: "BoolParameter");
        *pIsChildPanel = false;
LABEL_58:
        v13->m_pEditor = v12->m_pEditor;
        CNodePanel::SetData(this: v13, pNodeKV: pData);
        return v13;
      }
LABEL_38:
      v13 = nullptr;
      *pIsChildPanel = false;
      goto LABEL_58;
    }
    if ( _V_stricmp(s1: m_pTypeName, s2: "string") == 0 )
    {
      v14 = (CStringValuePanel *)operator new(nSize: 0x298u);
      v12 = pParent;
      if ( v14 != nullptr )
      {
        v13 = (CFileValuePanel *)CStringValuePanel::CStringValuePanel(this: v14, pParent, pName: "StringParameter");
        *pIsChildPanel = false;
        goto LABEL_58;
      }
LABEL_29:
      v13 = nullptr;
      *pIsChildPanel = false;
      goto LABEL_58;
    }
    if ( _V_stricmp(s1: m_pTypeName, s2: "enum") == 0 )
    {
      v12 = pParent;
      Enum = CTilegenMissionPreprocessor::FindEnum(
               this: (CTilegenMissionPreprocessor *)pParent->m_pEditor->m_pPreprocessor,
               pEnumName: *(const char **)(v6 + *(_DWORD *)&pRule->m_clrDragFrame + 16));
      if ( Enum != nullptr )
      {
        v16 = (CEnumValuePanel *)operator new(nSize: 0x29Cu);
        if ( v16 != nullptr )
        {
          v13 = (CFileValuePanel *)CEnumValuePanel::CEnumValuePanel(
                                     this: v16,
                                     pParent,
                                     pName: (KeyValues *)"EnumParameter",
                                     pTilegenEnum: Enum);
          *pIsChildPanel = false;
          goto LABEL_58;
        }
        goto LABEL_38;
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      {
        _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Enum %s not found.\n");
        return nullptr;
      }
      return nullptr;
    }
    if ( _V_stricmp(s1: m_pTypeName, s2: "int") == 0
      || _V_stricmp(s1: m_pTypeName, s2: "bool") == 0
      || _V_stricmp(s1: m_pTypeName, s2: "float") == 0 )
    {
      v21 = (CStringValuePanel *)operator new(nSize: 0x298u);
      v12 = pParent;
      if ( v21 != nullptr )
        v13 = (CFileValuePanel *)CStringValuePanel::CStringValuePanel(this: v21, pParent, pName: "StringParameter");
      else
        v13 = nullptr;
      vgui::TextEntry::SetAllowNumericInputOnly(this: *(vgui::TextEntry **)v13->m_FileTypeName, state: true);
      *pIsChildPanel = false;
      goto LABEL_58;
    }
    if ( _V_stricmp(s1: m_pTypeName, s2: "room_name") == 0 )
    {
      v17 = (CFileValuePanel *)operator new(nSize: 0x3E4u);
      v12 = pParent;
      if ( v17 != nullptr )
      {
        v13 = CFileValuePanel::CFileValuePanel(
                this: v17,
                pParent,
                pName: "RoomParameter",
                pFileTypeName: "Room Template",
                pFileExtension: "*.roomtemplate",
                pBaseDirectory: "tilegen\\roomtemplates\\",
                bStripPath: true,
                bStripExtension: true);
        *pIsChildPanel = false;
        goto LABEL_58;
      }
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: m_pTypeName, s2: "layout_name") == 0 )
    {
      v18 = (CFileValuePanel *)operator new(nSize: 0x3E4u);
      v12 = pParent;
      if ( v18 != nullptr )
        v13 = CFileValuePanel::CFileValuePanel(
                this: v18,
                pParent,
                pName: "LayoutParameter",
                pFileTypeName: "Layout",
                pFileExtension: "*.layout",
                pBaseDirectory: "tilegen\\layouts\\",
                bStripPath: false,
                bStripExtension: false);
      else
        v13 = nullptr;
      *pIsChildPanel = false;
      goto LABEL_58;
    }
    if ( _V_stricmp(s1: m_pTypeName, s2: "instance_name") == 0 )
    {
      v19 = (CFileValuePanel *)operator new(nSize: 0x3E4u);
      v12 = pParent;
      if ( v19 != nullptr )
      {
        v13 = CFileValuePanel::CFileValuePanel(
                this: v19,
                pParent,
                pName: "InstanceParameter",
                pFileTypeName: "Instance",
                pFileExtension: "*.vmf",
                pBaseDirectory: "tilegen\\instances\\",
                bStripPath: true,
                bStripExtension: false);
        *pIsChildPanel = false;
        goto LABEL_58;
      }
      goto LABEL_38;
    }
    if ( _V_stricmp(s1: m_pTypeName, s2: "theme_name") != 0 )
      return nullptr;
    v20 = (CThemeValuePanel *)operator new(nSize: 0x29Cu);
    v12 = pParent;
    if ( v20 != nullptr )
      v13 = (CFileValuePanel *)CThemeValuePanel::CThemeValuePanel(this: v20, pParent, pName: "ThemeParameter");
    else
      v13 = nullptr;
LABEL_57:
    *pIsChildPanel = true;
    goto LABEL_58;
  }
  if ( !bAllowExpressions )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Non-literal value is specified in key values file but expressions are not allowed for this rule instance parameter (%s).\n");
    return nullptr;
  }
  if ( pRuleInstancePanel_3
    || (FirstSubKey = KeyValues::GetFirstSubKey(this: pData), KeyValues::GetNextKey(this: FirstSubKey) == nullptr)
    && (v23 = KeyValues::GetFirstSubKey(this: pData),
        v24 = KeyValues::GetName(this: v23),
        _V_stricmp(s1: v24, s2: "rule_instance") == 0) )
  {
    v25 = (CRuleInstanceNodePanel *)operator new(nSize: 0x2B0u);
    v12 = pParent;
    if ( v25 != nullptr )
      pRuleInstancePanel = CRuleInstanceNodePanel::CRuleInstanceNodePanel(this: v25, pParent, pName: "RuleInstance");
    else
      pRuleInstancePanel = nullptr;
    CRuleInstanceNodePanel::AddAllowableRuleType(
      this: pRuleInstancePanel,
      pType: *(const char **)(v6 + *(_DWORD *)&pRule->m_clrDragFrame + 12));
    v13 = (CFileValuePanel *)pRuleInstancePanel;
    goto LABEL_57;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "No rule_instance found where one was expected.\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10023E60
// Name: public: virtual void CArrayValuePanel::CreatePanelContents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArrayValuePanel::CreatePanelContents(CArrayValuePanel *this)
{
  int m_nRuleParameterIndex; // eax
  CTilegenRule::SubstitutionVariable_t *m_pMemory; // edx
  KeyValues *m_pNodeKV; // ecx
  KeyValues *i; // ebx
  CFileValuePanel *v6; // edi
  void (__thiscall *UpdateState)(CNodePanel *); // eax
  bool m_bAllowExpression; // bl
  CNewElementPanel *v9; // eax
  CNewElementPanel *v10; // edi
  int nIndex; // [esp+Ch] [ebp-8h]
  bool bIgnored; // [esp+12h] [ebp-2h] BYREF
  bool bOrderedArray; // [esp+13h] [ebp-1h]

  m_nRuleParameterIndex = this->m_nRuleParameterIndex;
  m_pMemory = this->m_pRule->m_SubstitutionVariables.m_Memory.m_pMemory;
  m_pNodeKV = this->m_pNodeKV;
  bOrderedArray = m_pMemory[m_nRuleParameterIndex].m_bOrderedArray;
  nIndex = 0;
  for ( i = KeyValues::GetFirstSubKey(this: m_pNodeKV); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v6 = CreateValuePanel(
           pRule: (CRuleInstanceNodePanel *)this->m_pRule,
           nRuleParameterIndex: this->m_nRuleParameterIndex,
           pParent: this,
           pData: i,
           pIsChildPanel: &bIgnored);
    if ( v6 != nullptr )
    {
      if ( bOrderedArray )
        CArrayValuePanel::AddNewParameterElementPanel(this, nIndex);
      UpdateState = v6->UpdateState;
      v6->m_bShowDeleteButton = true;
      UpdateState(this: v6);
      CNodePanel::AddChild(this, pPanel: v6, nPadding: 0);
    }
    ++nIndex;
  }
  m_bAllowExpression = this->m_pRule->m_SubstitutionVariables.m_Memory.m_pMemory[this->m_nRuleParameterIndex].m_bAllowExpression;
  v9 = (CNewElementPanel *)operator new(nSize: 0x188u);
  if ( v9 != nullptr )
    v10 = CNewElementPanel::CNewElementPanel(this: v9, pParent: this, pName: "NewElement", nIndex);
  else
    v10 = nullptr;
  if ( m_bAllowExpression )
    CNewElementPanel::AddButton(this: v10, pButtonText: "Add Rule", pActionName: (KeyValues *)"AddRule");
  CNodePanel::AddChild(this, pPanel: v10, nPadding: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10023F70
// Name: protected: virtual void CRuleInstanceParameterPanel::CreatePanelContents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRuleInstanceParameterPanel::CreatePanelContents(CRuleInstanceParameterPanel *this)
{
  const CTilegenRule *m_pRule; // ecx
  KeyValues *m_pNodeKV; // edi
  CRuleInstanceNodePanel *v4; // ecx
  int m_nRuleParameterIndex; // eax
  CArrayValuePanel *v6; // eax
  CArrayValuePanel *v7; // edi
  CFileValuePanel *v8; // eax
  CTilegenRule::SubstitutionVariable_t *m_pMemory; // ecx
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  bool pIsChildPanel; // [esp+17h] [ebp-1h] BYREF

  m_pRule = this->m_pRule;
  this->m_pAddButton = nullptr;
  this->m_pDeleteButton = nullptr;
  m_pNodeKV = this->m_pNodeKV;
  V_strncpy(
    pDest: this->m_NodeLabel,
    pSrc: m_pRule->m_SubstitutionVariables.m_Memory.m_pMemory[this->m_nRuleParameterIndex].m_pFriendlyName,
    maxLen: 100);
  if ( m_pNodeKV != nullptr )
  {
    v4 = (CRuleInstanceNodePanel *)this->m_pRule;
    m_nRuleParameterIndex = this->m_nRuleParameterIndex;
    if ( *(_BYTE *)(*(_DWORD *)&v4->m_clrDragFrame + 36 * m_nRuleParameterIndex + 25) != 0 )
    {
      v6 = (CArrayValuePanel *)operator new(nSize: 0x298u);
      if ( v6 != nullptr )
        v7 = CArrayValuePanel::CArrayValuePanel(
               this: v6,
               pParent: this,
               pName: "ArrayParameter",
               pRule: this->m_pRule,
               nRuleParameterIndex: this->m_nRuleParameterIndex);
      else
        v7 = nullptr;
      CNodePanel::AddChild(this, pPanel: v7, nPadding: 0);
      v7->m_pEditor = this->m_pEditor;
      CNodePanel::SetData(this: v7, pNodeKV: this->m_pNodeKV);
    }
    else
    {
      v8 = CreateValuePanel(
             pRule: v4,
             nRuleParameterIndex: m_nRuleParameterIndex,
             pParent: this,
             pData: this->m_pNodeKV,
             &pIsChildPanel);
      if ( v8 != nullptr )
      {
        if ( pIsChildPanel )
          CNodePanel::AddChild(this, pPanel: v8, nPadding: 0);
        else
          CNodePanel::AddHeadingElement(this, pPanel: v8, flExpandFactor: 0x3F800000u, nPadding: 2u);
      }
      else
      {
        V_strncat(pDest: this->m_NodeLabel, pSrc: " - NOT FOUND", destBufferSize: 0x64u, max_chars_to_copy: -1);
      }
    }
    m_pMemory = this->m_pRule->m_SubstitutionVariables.m_Memory.m_pMemory;
    if ( m_pMemory[this->m_nRuleParameterIndex].m_pDefault != nullptr
      || m_pMemory[this->m_nRuleParameterIndex].m_bCanOmit )
    {
      v10 = (vgui::Button *)operator new(nSize: 0x1F4u);
      if ( v10 != nullptr )
        v11 = vgui::Button::Button(
                this: v10,
                parent: this,
                panelName: "DeleteButton",
                text: "X",
                pActionSignalTarget: this,
                pCmd: "DeleteParam");
      else
        v11 = nullptr;
      this->m_pDeleteButton = v11;
      CNodePanel::AddHeadingSpacer(this);
      CNodePanel::AddHeadingElement(this, pPanel: this->m_pDeleteButton, flExpandFactor: 0, nPadding: 2u);
    }
  }
  else
  {
    v12 = (vgui::Button *)operator new(nSize: 0x1F4u);
    if ( v12 != nullptr )
      v13 = vgui::Button::Button(
              this: v12,
              parent: this,
              panelName: "AddButton",
              text: "Add",
              pActionSignalTarget: this,
              pCmd: "AddParam");
    else
      v13 = nullptr;
    this->m_pAddButton = v13;
    CNodePanel::AddHeadingSpacer(this);
    CNodePanel::AddHeadingElement(this, pPanel: this->m_pAddButton, flExpandFactor: 0, nPadding: 2u);
  }
}
