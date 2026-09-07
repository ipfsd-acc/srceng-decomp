// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system_editor/rule_instance_node_panel.cpp
// Functions: 26
// ============================================================

#include "missionchooser\layout_system_editor\rule_instance_node_panel.h"

//------------------------------------------------------------------------------
// Address: 0x100210D0
// Name: public: static char const __near * CRuleInstanceNodePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRuleInstanceNodePanel::GetPanelClassName()
{
  return "CRuleInstanceNodePanel";
}

//------------------------------------------------------------------------------
// Address: 0x100210E0
// Name: public: static char const __near * CRulePickerDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRulePickerDialog::GetPanelClassName()
{
  return "CRulePickerDialog";
}

//------------------------------------------------------------------------------
// Address: 0x100210F0
// Name: public: static char const __near * CRuleDetailsPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRuleDetailsPanel::GetPanelClassName()
{
  return "CRuleDetailsPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10021100
// Name: public: virtual void CRuleDetailsPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRuleDetailsPanel::OnMouseReleased(CRuleDetailsPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "RuleDetailsClicked");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021150
// Name: bool RuleMatchExists(struct RuleType_t const __near *,int,struct RuleType_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RuleMatchExists(
        const RuleType_t *pTypes,
        int nNumTypes,
        const RuleType_t *pValidTypeList,
        int nNumValidTypes)
{
  int v4; // esi
  const RuleType_t *v5; // edi
  int i; // [esp+Ch] [ebp-8h]

  i = 0;
  if ( nNumTypes <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = 0;
    if ( nNumValidTypes > 0 )
      break;
LABEL_6:
    ++pTypes;
    if ( ++i >= nNumTypes )
      return 0;
  }
  v5 = pValidTypeList;
  while ( _V_stricmp(s1: v5->m_Name, s2: pTypes->m_Name) != 0 )
  {
    ++v4;
    ++v5;
    if ( v4 >= nNumValidTypes )
      goto LABEL_6;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100211D0
// Name: public: virtual void CRuleInstanceNodePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRuleInstanceNodePanel::ApplySchemeSettings(CRuleInstanceNodePanel *this, vgui::IScheme *pScheme)
{
  CNodePanel::ApplySchemeSettings(this, pScheme);
  ((void (__thiscall *)(CRuleInstanceNodePanel *, int))this->SetBgColor)(a1: this, a2: -12040120);
}

//------------------------------------------------------------------------------
// Address: 0x10021200
// Name: public: virtual void CRuleInstanceNodePanel::OnRuleChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRuleInstanceNodePanel::OnRuleChanged(CRuleInstanceNodePanel *this, KeyValues *pKeyValues)
{
  KeyValues *FirstSubKey; // eax
  KeyValues *v4; // esi
  KeyValues *m_pNodeKV; // edi
  const char *Name; // eax
  KeyValues *v7; // eax

  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  v4 = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    KeyValues::RemoveSubKey(this: pKeyValues, subKey: FirstSubKey);
    m_pNodeKV = this->m_pNodeKV;
    Name = KeyValues::GetName(this: m_pNodeKV);
    if ( _V_stricmp(s1: Name, s2: "rule_instance") != 0 )
    {
      v7 = KeyValues::GetFirstSubKey(this: m_pNodeKV);
      KeyValues::SwapSubKey(this: m_pNodeKV, pExistingSubkey: v7, pNewSubKey: v4);
      CNodePanel::RecreateControls(this);
    }
    else
    {
      CNodePanel::SetData(this, pNodeKV: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021270
// Name: public: CRuleDetailsPanel::CRuleDetailsPanel(class vgui::Panel __near *,char const __near *,class CTilegenRule const __near *)
// Source: json
//------------------------------------------------------------------------------
CRuleDetailsPanel *__thiscall CRuleDetailsPanel::CRuleDetailsPanel(
        CRuleDetailsPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        const CTilegenRule *pRule)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  vgui::Tooltip *Tooltip; // eax
  const char *m_pDescription; // [esp-4h] [ebp-Ch]

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CRuleDetailsPanel_vtbl *)&CRuleDetailsPanel::`vftable';
  if ( `CRuleDetailsPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CRuleDetailsPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CRuleDetailsPanel");
    v5->pfnClassName = CRuleDetailsPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CRuleDetailsPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRuleDetailsPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CRuleDetailsPanel");
    v6->pfnClassName = CRuleDetailsPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CRuleDetailsPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRuleDetailsPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CRuleDetailsPanel");
    v7->pfnClassName = CRuleDetailsPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_pRule = pRule;
  v8 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v8 != nullptr )
    v9 = vgui::Label::Label(this: v8, parent: this, panelName: "RuleName", text: this->m_pRule->m_pFriendlyName);
  else
    v9 = nullptr;
  this->m_pRuleNameLabel = v9;
  v9->SetMouseInputEnabled(this: v9, a2: false);
  this->m_pRuleNameLabel->SetPaintBackgroundEnabled(this: this->m_pRuleNameLabel, a2: false);
  this->m_pRuleNameLabel->SizeToContents(this: this->m_pRuleNameLabel);
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  m_pDescription = pRule->m_pDescription;
  Tooltip = vgui::Panel::GetTooltip(this);
  vgui::Tooltip::SetText(this: Tooltip, text: m_pDescription);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100213C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CRuleDetailsPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRuleDetailsPanel::GetMessageMap(CRuleDetailsPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRuleDetailsPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRuleDetailsPanel::GetMessageMap'::`2'::s_pMap;
  `CRuleDetailsPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRuleDetailsPanel");
  `CRuleDetailsPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100213F0
// Name: public: virtual struct PanelAnimationMap __near * CRuleDetailsPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRuleDetailsPanel::GetAnimMap(CRuleDetailsPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CRuleDetailsPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10021400
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRuleDetailsPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRuleDetailsPanel::GetKBMap(CRuleDetailsPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRuleDetailsPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRuleDetailsPanel::GetKBMap'::`2'::s_pMap;
  `CRuleDetailsPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRuleDetailsPanel");
  `CRuleDetailsPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021430
// Name: protected: virtual void CRuleInstanceNodePanel::CreatePanelContents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRuleInstanceNodePanel::CreatePanelContents(CRuleInstanceNodePanel *this)
{
  KeyValues *m_pNodeKV; // edi
  const char *Name; // eax
  vgui::Button *v4; // eax
  vgui::Button *v5; // eax
  vgui::Button *v6; // eax
  const char *v7; // ecx
  vgui::Button *v8; // eax
  const char *String; // eax
  const char *v10; // edi
  const CTilegenRule *Rule; // ebx
  vgui::Tooltip *Tooltip; // eax
  CRuleInstanceParameterPanel *v13; // eax
  CRuleInstanceParameterPanel *v14; // edi
  const char *m_pDescription; // [esp+0h] [ebp-20h]
  KeyValues *Key; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  KeyValues *pInstanceParameterKV; // [esp+18h] [ebp-8h]
  KeyValues *FirstSubKey; // [esp+1Ch] [ebp-4h]

  m_pNodeKV = this->m_pNodeKV;
  FirstSubKey = m_pNodeKV;
  Name = KeyValues::GetName(this: m_pNodeKV);
  if ( _V_stricmp(s1: Name, s2: "rule_instance") != 0 )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: m_pNodeKV);
    m_pNodeKV = FirstSubKey;
  }
  this->m_bDisabled = KeyValues::GetInt(this: m_pNodeKV, keyName: "disabled", defaultValue: 0) != 0;
  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
    v5 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: "ChangeRule",
           text: "Change",
           pActionSignalTarget: this,
           pCmd: "ChangeRule");
  else
    v5 = nullptr;
  this->m_pChangeRuleButton = v5;
  CNodePanel::AddHeadingElement(this, pPanel: v5, flExpandFactor: 0, nPadding: 0);
  v6 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v6 != nullptr )
  {
    v7 = "Enable";
    if ( !this->m_bDisabled )
      v7 = "Disable";
    v8 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "DisableRule",
           text: v7,
           pActionSignalTarget: this,
           pCmd: "DisableRule");
  }
  else
  {
    v8 = nullptr;
  }
  this->m_pDisableRuleButton = v8;
  CNodePanel::AddHeadingElement(this, pPanel: v8, flExpandFactor: 0, nPadding: 0);
  String = KeyValues::GetString(this: m_pNodeKV, keyName: "name", defaultValue: nullptr);
  v10 = String;
  if ( String != nullptr )
  {
    Rule = CTilegenMissionPreprocessor::FindRule(
             this: (CTilegenMissionPreprocessor *)this->m_pEditor->m_pPreprocessor,
             pRuleName: String);
    if ( Rule != nullptr )
    {
      m_pDescription = Rule->m_pDescription;
      Tooltip = vgui::Panel::GetTooltip(this);
      vgui::Tooltip::SetText(this: Tooltip, text: m_pDescription);
      if ( !this->m_bDisabled )
      {
        pInstanceParameterKV = nullptr;
        if ( Rule->m_SubstitutionVariables.m_Size > 0 )
        {
          v17 = 0;
          do
          {
            Key = KeyValues::FindKey(
                    this: FirstSubKey,
                    keyName: Rule->m_SubstitutionVariables.m_Memory.m_pMemory[v17].m_pName,
                    bCreate: false);
            v13 = (CRuleInstanceParameterPanel *)operator new(nSize: 0x2A0u);
            if ( v13 != nullptr )
              v14 = CRuleInstanceParameterPanel::CRuleInstanceParameterPanel(
                      this: v13,
                      pParent: this,
                      pName: "text_entry",
                      pRule: Rule,
                      nRuleParameterIndex: (int)pInstanceParameterKV);
            else
              v14 = nullptr;
            v14->m_pEditor = this->m_pEditor;
            CNodePanel::SetData(this: v14, pNodeKV: Key);
            CNodePanel::AddChild(this, pPanel: v14, nPadding: 0);
            ++v17;
            pInstanceParameterKV = (KeyValues *)((char *)pInstanceParameterKV + 1);
          }
          while ( (int)pInstanceParameterKV < Rule->m_SubstitutionVariables.m_Size );
        }
      }
      V_snprintf(pDest: this->m_NodeLabel, maxLen: 100, pFormat: "%s", Rule->m_pFriendlyName);
    }
    else
    {
      V_snprintf(pDest: this->m_NodeLabel, maxLen: 100, pFormat: "Rule '%s' not found!", v10);
    }
  }
  else
  {
    V_snprintf(pDest: this->m_NodeLabel, maxLen: 100, pFormat: "No Rule specified");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021630
// Name: class KeyValues __near * InstantiateRule(class CTilegenMissionPreprocessor const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl InstantiateRule(CTilegenMissionPreprocessor *pPreprocessor, const char *pRuleName)
{
  const CTilegenRule *Rule; // edi
  int v3; // ebx
  KeyValues *v4; // eax
  CTilegenRule::SubstitutionVariable_t *m_pMemory; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  KeyValues *Copy; // eax
  KeyValues *pDefaultValue; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  KeyValues *pNewKV; // [esp+14h] [ebp-4h]

  Rule = CTilegenMissionPreprocessor::FindRule(this: pPreprocessor, pRuleName);
  v3 = 0;
  if ( Rule == nullptr )
    return nullptr;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    pNewKV = KeyValues::KeyValues(this: v4, setName: "rule_instance", firstKey: "name", firstValue: pRuleName);
  else
    pNewKV = nullptr;
  for ( i = 0; i < Rule->m_SubstitutionVariables.m_Size; ++i )
  {
    m_pMemory = Rule->m_SubstitutionVariables.m_Memory.m_pMemory;
    if ( m_pMemory[v3].m_pDefault == nullptr && !m_pMemory[v3].m_bCanOmit )
    {
      pDefaultValue = m_pMemory[v3].m_pDefault;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: Rule->m_SubstitutionVariables.m_Memory.m_pMemory[v3].m_pName);
      else
        v7 = nullptr;
      if ( pDefaultValue != nullptr )
      {
        Copy = KeyValues::MakeCopy(this: pDefaultValue);
        KeyValues::AddSubKey(this: v7, pSubkey: Copy);
      }
      else
      {
        KeyValues::SetString(this: v7, keyName: nullptr, value: "<Enter Value>");
      }
      KeyValues::AddSubKey(this: pNewKV, pSubkey: v7);
    }
    ++v3;
  }
  return pNewKV;
}

//------------------------------------------------------------------------------
// Address: 0x10021710
// Name: public: virtual void CRulePickerDialog::OnRuleDetailsClicked(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRulePickerDialog::OnRuleDetailsClicked(CRulePickerDialog *this, vgui::Panel *pPanel)
{
  _DWORD *v3; // eax
  KeyValues *v4; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // edi

  v3 = __RTDynamicCast(
         inptr: pPanel,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CRuleDetailsPanel `RTTI Type Descriptor',
         isReference: 0);
  v4 = InstantiateRule(
         pPreprocessor: (CTilegenMissionPreprocessor *)this->m_pRulePreprocessor,
         pRuleName: *(const char **)(v3[85] + 8));
  if ( v4 != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "RuleChanged");
    else
      v6 = nullptr;
    KeyValues::AddSubKey(this: v6, pSubkey: v4);
    this->PostActionSignal(this, a2: v6);
  }
  this->OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x100217A0
// Name: public: static void CRuleInstanceNodePanel::PanelMessageFunc_OnRuleChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRuleInstanceNodePanel::PanelMessageFunc_OnRuleChanged::InitVar(int a1@<ebp>)
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
  if ( !`CRuleInstanceNodePanel::PanelMessageFunc_OnRuleChanged::InitVar'::`2'::bAdded )
  {
    `CRuleInstanceNodePanel::PanelMessageFunc_OnRuleChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRuleInstanceNodePanel::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRuleInstanceNodePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "RuleChanged";
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
// Address: 0x10021830
// Name: public: static void CRulePickerDialog::PanelMessageFunc_OnRuleDetailsClicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRulePickerDialog::PanelMessageFunc_OnRuleDetailsClicked::InitVar(int a1@<ebp>)
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
  if ( !`CRulePickerDialog::PanelMessageFunc_OnRuleDetailsClicked::InitVar'::`2'::bAdded )
  {
    `CRulePickerDialog::PanelMessageFunc_OnRuleDetailsClicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRulePickerDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RuleDetailsClicked";
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
// Address: 0x100218D0
// Name: public: void CRuleInstanceNodePanel::AddAllowableRuleType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRuleInstanceNodePanel::AddAllowableRuleType(CRuleInstanceNodePanel *this, const char *pType)
{
  int m_Size; // edi
  RuleType_t *m_pMemory; // ebx
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *p_m_AllowableRuleTypes; // ecx
  int v6; // esi
  RuleType_t allowedRuleType; // [esp+Ch] [ebp-40h] BYREF
  const char *pTypea; // [esp+54h] [ebp+8h]

  V_strncpy(pDest: allowedRuleType.m_Name, pSrc: pType, maxLen: 64);
  m_Size = this->m_AllowableRuleTypes.m_Size;
  m_pMemory = this->m_AllowableRuleTypes.m_Memory.m_pMemory;
  p_m_AllowableRuleTypes = (CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *)&this->m_AllowableRuleTypes;
  v6 = 0;
  pTypea = (const char *)p_m_AllowableRuleTypes;
  if ( m_Size <= 0 )
  {
LABEL_5:
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: p_m_AllowableRuleTypes,
      elem: p_m_AllowableRuleTypes->m_Size,
      src: (const vgui::MessageMapItem_t *)&allowedRuleType);
  }
  else
  {
    while ( _V_stricmp(s1: m_pMemory->m_Name, s2: allowedRuleType.m_Name) != 0 )
    {
      ++v6;
      ++m_pMemory;
      if ( v6 >= m_Size )
      {
        p_m_AllowableRuleTypes = (CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *)pTypea;
        goto LABEL_5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021940
// Name: public: CRulePickerDialog::CRulePickerDialog(class vgui::Panel __near *,char const __near *,class CTilegenMissionPreprocessor const __near *,struct RuleType_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
CRulePickerDialog *__thiscall CRulePickerDialog::CRulePickerDialog(
        CRulePickerDialog *this,
        vgui::Panel *pParent,
        const char *pName,
        const CTilegenMissionPreprocessor *pRulePreprocessor,
        RuleType_t *pAllowableRuleTypes,
        int nNumAllowableRuleTypes)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi
  vgui::PanelListPanel *v10; // eax
  vgui::PanelListPanel *v11; // eax
  int i; // ebx
  CTilegenRule *v13; // edi
  CRuleDetailsPanel *v14; // eax
  CRuleDetailsPanel *v15; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: pName, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CRulePickerDialog_vtbl *)&CRulePickerDialog::`vftable';
  if ( `CRulePickerDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CRulePickerDialog::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "CRulePickerDialog");
    v7->pfnClassName = CRulePickerDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CRulePickerDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRulePickerDialog::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "CRulePickerDialog");
    v8->pfnClassName = CRulePickerDialog::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CRulePickerDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRulePickerDialog::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "CRulePickerDialog");
    v9->pfnClassName = CRulePickerDialog::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CRulePickerDialog::PanelMessageFunc_OnRuleDetailsClicked::InitVar(a1: (int)&savedregs);
  this->m_pRulePreprocessor = pRulePreprocessor;
  v10 = (vgui::PanelListPanel *)operator new(nSize: 0x1ACu);
  if ( v10 != nullptr )
    v11 = vgui::PanelListPanel::PanelListPanel(this: v10, parent: this, panelName: "RulePanelListPanel");
  else
    v11 = nullptr;
  this->m_pRulePanelList = v11;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "RulePicker.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::MoveToCenterOfScreen(this);
  for ( i = 0; i < this->m_pRulePreprocessor->m_Rules.m_Size; ++i )
  {
    v13 = this->m_pRulePreprocessor->m_Rules.m_Memory.m_pMemory[i];
    if ( !v13->m_bHidden
      && RuleMatchExists(
           pTypes: v13->m_Types.m_Memory.m_pMemory,
           nNumTypes: v13->m_Types.m_Size,
           pValidTypeList: pAllowableRuleTypes,
           nNumValidTypes: nNumAllowableRuleTypes) != 0 )
    {
      v14 = (CRuleDetailsPanel *)operator new(nSize: 0x158u);
      if ( v14 != nullptr )
        v15 = CRuleDetailsPanel::CRuleDetailsPanel(this: v14, pParent: this, pName: "RuleDetails", pRule: v13);
      else
        v15 = nullptr;
      this->m_pRulePanelList->AddItem(this: this->m_pRulePanelList, a2: nullptr, a3: v15);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10021AE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CRulePickerDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRulePickerDialog::GetMessageMap(CRulePickerDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRulePickerDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRulePickerDialog::GetMessageMap'::`2'::s_pMap;
  `CRulePickerDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRulePickerDialog");
  `CRulePickerDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021B10
// Name: public: virtual struct PanelAnimationMap __near * CRulePickerDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRulePickerDialog::GetAnimMap(CRulePickerDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CRulePickerDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10021B20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRulePickerDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRulePickerDialog::GetKBMap(CRulePickerDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRulePickerDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRulePickerDialog::GetKBMap'::`2'::s_pMap;
  `CRulePickerDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRulePickerDialog");
  `CRulePickerDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021B80
// Name: public: CRuleInstanceNodePanel::CRuleInstanceNodePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRuleInstanceNodePanel *__thiscall CRuleInstanceNodePanel::CRuleInstanceNodePanel(
        CRuleInstanceNodePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CNodePanel::CNodePanel(this, pParent, pName);
  this->__vftable = (CRuleInstanceNodePanel_vtbl *)&CRuleInstanceNodePanel::`vftable';
  if ( `CRuleInstanceNodePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CRuleInstanceNodePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRuleInstanceNodePanel");
    v4->pfnClassName = CRuleInstanceNodePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
  }
  if ( `CRuleInstanceNodePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRuleInstanceNodePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRuleInstanceNodePanel");
    v5->pfnClassName = CRuleInstanceNodePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CNodePanel");
  }
  if ( `CRuleInstanceNodePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRuleInstanceNodePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRuleInstanceNodePanel");
    v6->pfnClassName = CRuleInstanceNodePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CNodePanel");
  }
  CRuleInstanceNodePanel::PanelMessageFunc_OnRuleChanged::InitVar(a1: (int)&savedregs);
  this->m_pChangeRuleButton = nullptr;
  this->m_pDisableRuleButton = nullptr;
  this->m_bDisabled = false;
  this->m_AllowableRuleTypes.m_Memory.m_pMemory = nullptr;
  this->m_AllowableRuleTypes.m_Memory.m_nAllocationCount = 0;
  this->m_AllowableRuleTypes.m_Memory.m_nGrowSize = 0;
  this->m_AllowableRuleTypes.m_Size = 0;
  this->m_AllowableRuleTypes.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10021C80
// Name: public: virtual struct vgui::PanelMessageMap __near * CRuleInstanceNodePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRuleInstanceNodePanel::GetMessageMap(CRuleInstanceNodePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRuleInstanceNodePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRuleInstanceNodePanel::GetMessageMap'::`2'::s_pMap;
  `CRuleInstanceNodePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRuleInstanceNodePanel");
  `CRuleInstanceNodePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021CB0
// Name: public: virtual struct PanelAnimationMap __near * CRuleInstanceNodePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRuleInstanceNodePanel::GetAnimMap(CRuleInstanceNodePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CRuleInstanceNodePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10021CC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRuleInstanceNodePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRuleInstanceNodePanel::GetKBMap(CRuleInstanceNodePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRuleInstanceNodePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRuleInstanceNodePanel::GetKBMap'::`2'::s_pMap;
  `CRuleInstanceNodePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRuleInstanceNodePanel");
  `CRuleInstanceNodePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021D30
// Name: public: virtual void CRuleInstanceNodePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRuleInstanceNodePanel::OnCommand(CRuleInstanceNodePanel *this, const char *pCommand)
{
  CRulePickerDialog *v3; // eax
  CRulePickerDialog *v4; // edi
  bool v5; // al
  bool v6; // zf
  const char *v7; // eax
  KeyValues *m_pNodeKV; // edi
  KeyValues *Key; // eax

  if ( _V_stricmp(s1: pCommand, s2: "ChangeRule") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "DisableRule") == 0 )
    {
      v5 = !this->m_bDisabled;
      this->m_bDisabled = v5;
      v6 = !v5;
      v7 = "Enable";
      if ( v6 )
        v7 = "Disable";
      this->m_pDisableRuleButton->SetText(this: this->m_pDisableRuleButton, a2: v7);
      if ( this->m_bDisabled )
      {
        KeyValues::SetInt(this: this->m_pNodeKV, keyName: "disabled", value: 1);
      }
      else
      {
        m_pNodeKV = this->m_pNodeKV;
        Key = KeyValues::FindKey(this: m_pNodeKV, keyName: "disabled", bCreate: false);
        KeyValues::RemoveSubKey(this: m_pNodeKV, subKey: Key);
      }
      CNodePanel::RecreateControls(this);
    }
    CNodePanel::OnCommand(this, pCommand);
  }
  else
  {
    v3 = (CRulePickerDialog *)operator new(nSize: 0x21Cu);
    if ( v3 != nullptr )
      v4 = CRulePickerDialog::CRulePickerDialog(
             this: v3,
             pParent: this,
             pName: "RulePicker",
             pRulePreprocessor: this->m_pEditor->m_pPreprocessor,
             pAllowableRuleTypes: this->m_AllowableRuleTypes.m_Memory.m_pMemory,
             nNumAllowableRuleTypes: this->m_AllowableRuleTypes.m_Size);
    else
      v4 = nullptr;
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    v4->DoModal(this: v4);
  }
}
