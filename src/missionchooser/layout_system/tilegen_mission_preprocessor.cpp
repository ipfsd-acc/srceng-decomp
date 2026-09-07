// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system/tilegen_mission_preprocessor.cpp
// Functions: 7
// ============================================================

#include "missionchooser\layout_system\tilegen_mission_preprocessor.h"

//------------------------------------------------------------------------------
// Address: 0x1001E2F0
// Name: private: void CTilegenMissionPreprocessor::EvaluateMetaVariables(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenMissionPreprocessor::EvaluateMetaVariables(
        CTilegenMissionPreprocessor *this,
        KeyValues *pKeyValues)
{
  const char *String; // esi
  char outputString[64]; // [esp+Ch] [ebp-50h] BYREF
  char uniqueNumber[16]; // [esp+4Ch] [ebp-10h] BYREF

  String = KeyValues::GetString(this: pKeyValues, keyName: nullptr, defaultValue: szDescription);
  if ( V_stristr(pStr: String, pSearch: "%Unique") != nullptr )
  {
    V_snprintf(pDest: uniqueNumber, maxLen: 15, pFormat: "%02d", this->m_nUniqueIndex);
    V_StrSubst(
      pIn: String,
      pMatch: "%Unique",
      pReplaceWith: uniqueNumber,
      pOut: outputString,
      outLen: 64,
      bCaseSensitive: false);
    KeyValues::SetString(this: pKeyValues, keyName: nullptr, value: outputString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E370
// Name: public: class CTilegenRule const __near * CTilegenMissionPreprocessor::FindRule(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CTilegenRule *__thiscall CTilegenMissionPreprocessor::FindRule(
        CTilegenMissionPreprocessor *this,
        const char *pRuleName)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_Rules.m_Size <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: this->m_Rules.m_Memory.m_pMemory[v3]->m_pName, s2: pRuleName) != 0 )
  {
    if ( ++v3 >= this->m_Rules.m_Size )
      return nullptr;
  }
  return this->m_Rules.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x1001E3C0
// Name: public: class CTilegenEnum const __near * CTilegenMissionPreprocessor::FindEnum(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CTilegenEnum *__thiscall CTilegenMissionPreprocessor::FindEnum(
        CTilegenMissionPreprocessor *this,
        const char *pEnumName)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_Enums.m_Size <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: this->m_Enums.m_Memory.m_pMemory[v3]->m_pEnumName, s2: pEnumName) != 0 )
  {
    if ( ++v3 >= this->m_Enums.m_Size )
      return nullptr;
  }
  return this->m_Enums.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x1001E410
// Name: private: bool CTilegenMissionPreprocessor::SubstituteRules_Recursive(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenMissionPreprocessor::SubstituteRules_Recursive(
        CTilegenMissionPreprocessor *this,
        KeyValues *pParent,
        KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // eax
  CTilegenRule *Rule; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  KeyValues *FirstSubKey; // ebx
  KeyValues *pNextSubKey; // [esp+14h] [ebp+8h]

  Name = KeyValues::GetName(this: pKeyValues);
  if ( _V_stricmp(s1: Name, s2: "rule_instance") != 0 )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
    if ( FirstSubKey == nullptr )
      return 1;
    while ( 1 )
    {
      pNextSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( !CTilegenMissionPreprocessor::SubstituteRules_Recursive(this, pParent: pKeyValues, pKeyValues: FirstSubKey) )
        break;
      FirstSubKey = pNextSubKey;
      if ( pNextSubKey == nullptr )
        return 1;
    }
    return 0;
  }
  if ( KeyValues::GetInt(this: pKeyValues, keyName: "disabled", defaultValue: 0) != 0 )
  {
    KeyValues::RemoveSubKey(this: pParent, subKey: pKeyValues);
    KeyValues::deleteThis(this: pKeyValues);
    return 1;
  }
  String = KeyValues::GetString(this: pKeyValues, keyName: "name", defaultValue: szDescription);
  if ( *String == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Rule instance must have a valid 'name' key.\n");
    return 0;
  }
  Rule = (CTilegenRule *)CTilegenMissionPreprocessor::FindRule(this, pRuleName: String);
  if ( Rule == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Rule %s not found in rule list.\n");
    return 0;
  }
  ++this->m_nUniqueIndex;
  v8 = CTilegenRule::InstantiateRule(this: Rule, pRuleInstanceKV: pKeyValues, pPreprocessor: this);
  v9 = v8;
  if ( v8 == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Error instantiating rule %s.\n");
    return 0;
  }
  KeyValues::SwapSubKey(this: pParent, pExistingSubkey: pKeyValues, pNewSubKey: v8);
  if ( !CTilegenMissionPreprocessor::SubstituteRules_Recursive(this, pParent, pKeyValues: v9) )
    return 0;
  KeyValues::ElideSubKey(this: pParent, pSubKey: v9);
  KeyValues::deleteThis(this: pKeyValues);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001E5A0
// Name: public: bool CTilegenMissionPreprocessor::SubstituteRules(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenMissionPreprocessor::SubstituteRules(CTilegenMissionPreprocessor *this, KeyValues *pKeyValues)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  const char *String; // eax
  int v6; // ebx
  CTilegenRule *v7; // ebx
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  KeyValues *v10; // ebx
  KeyValues *pNextSubKey; // [esp+Ch] [ebp-8h]
  const char *v13; // [esp+10h] [ebp-4h]
  KeyValues *NextKey; // [esp+10h] [ebp-4h]

  this->m_nUniqueIndex = 0;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeyValues);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    pNextSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "rule_instance") == 0 )
      break;
    v10 = KeyValues::GetFirstSubKey(this: FirstSubKey);
    if ( v10 != nullptr )
    {
      do
      {
        NextKey = KeyValues::GetNextKey(this: v10);
        if ( CTilegenMissionPreprocessor::SubstituteRules_Recursive(this, pParent: FirstSubKey, pKeyValues: v10) == 0 )
          return 0;
        v10 = NextKey;
      }
      while ( NextKey != nullptr );
    }
LABEL_17:
    FirstSubKey = pNextSubKey;
    if ( pNextSubKey == nullptr )
      return 1;
  }
  if ( KeyValues::GetInt(this: FirstSubKey, keyName: "disabled", defaultValue: 0) != 0 )
  {
    KeyValues::RemoveSubKey(this: pKeyValues, subKey: FirstSubKey);
    KeyValues::deleteThis(this: FirstSubKey);
    goto LABEL_17;
  }
  String = KeyValues::GetString(this: FirstSubKey, keyName: "name", defaultValue: szDescription);
  v13 = String;
  if ( *String != 0 )
  {
    v6 = 0;
    if ( this->m_Rules.m_Size <= 0 )
      goto LABEL_21;
    while ( _V_stricmp(s1: this->m_Rules.m_Memory.m_pMemory[v6]->m_pName, s2: String) != 0 )
    {
      if ( ++v6 >= this->m_Rules.m_Size )
        goto LABEL_21;
      String = v13;
    }
    v7 = this->m_Rules.m_Memory.m_pMemory[v6];
    if ( v7 == nullptr )
    {
LABEL_21:
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Rule %s not found in rule list.\n");
      return 0;
    }
    ++this->m_nUniqueIndex;
    v8 = CTilegenRule::InstantiateRule(this: v7, pRuleInstanceKV: FirstSubKey, pPreprocessor: this);
    v9 = v8;
    if ( v8 == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Error instantiating rule %s.\n");
      return 0;
    }
    KeyValues::SwapSubKey(this: pKeyValues, pExistingSubkey: FirstSubKey, pNewSubKey: v8);
    if ( CTilegenMissionPreprocessor::SubstituteRules_Recursive(this, pParent: pKeyValues, pKeyValues: v9) == 0 )
      return 0;
    KeyValues::ElideSubKey(this: pKeyValues, pSubKey: v9);
    KeyValues::deleteThis(this: FirstSubKey);
    goto LABEL_17;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Rule instance must have a valid 'name' key.\n");
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E800
// Name: public: CTilegenMissionPreprocessor::~CTilegenMissionPreprocessor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenMissionPreprocessor::~CTilegenMissionPreprocessor(CTilegenMissionPreprocessor *this)
{
  CUtlVector<CTilegenRule *,CUtlMemory<CTilegenRule *,int>>::PurgeAndDeleteElements(this: &this->m_Rules);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Rules);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1001E820
// Name: public: bool CTilegenMissionPreprocessor::ParseAndStripRules(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenMissionPreprocessor::ParseAndStripRules(CTilegenMissionPreprocessor *this, KeyValues *pRulesKV)
{
  KeyValues *v2; // edi
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  CTilegenRule *v7; // eax
  CTilegenRule *v8; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CTilegenRule **m_pMemory; // ecx
  int v12; // eax
  CTilegenRule **v13; // edi
  const char *v14; // eax
  CTilegenEnum *v15; // eax
  CTilegenEnum *v16; // edi
  int v17; // esi
  int v18; // eax
  CTilegenEnum **v19; // ecx
  int v20; // eax
  CTilegenEnum **v21; // eax
  CTilegenRule *pNewRule; // [esp+Ch] [ebp-8h]
  KeyValues *pSubKey; // [esp+10h] [ebp-4h]

  v2 = pRulesKV;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pRulesKV);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "rule") == 0 )
    {
      pSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      KeyValues::RemoveSubKey(this: v2, subKey: FirstSubKey);
      v7 = (CTilegenRule *)operator new(nSize: 0x40u);
      if ( v7 != nullptr )
      {
        v8 = CTilegenRule::CTilegenRule(this: v7);
        pNewRule = v8;
      }
      else
      {
        pNewRule = nullptr;
        v8 = nullptr;
      }
      if ( CTilegenRule::LoadFromKeyValues(this: v8, pRuleKeyValues: FirstSubKey) )
      {
        m_Size = this->m_Rules.m_Size;
        m_nAllocationCount = this->m_Rules.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Rules,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_Rules.m_Size;
        m_pMemory = this->m_Rules.m_Memory.m_pMemory;
        v12 = this->m_Rules.m_Size - m_Size - 1;
        this->m_Rules.m_pElements = m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
        v13 = &this->m_Rules.m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
          *v13 = pNewRule;
        goto LABEL_27;
      }
      if ( v8 != nullptr )
      {
        CTilegenRule::~CTilegenRule(this: v8);
        free(pMem: v8);
      }
      return 0;
    }
    v14 = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: v14, s2: "enum") != 0 )
    {
      pSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      goto LABEL_27;
    }
    pSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    KeyValues::RemoveSubKey(this: v2, subKey: FirstSubKey);
    v15 = (CTilegenEnum *)operator new(nSize: 0x1Cu);
    v16 = v15 != nullptr ? CTilegenEnum::CTilegenEnum(this: v15) : nullptr;
    if ( CTilegenEnum::LoadFromKeyValues(this: v16, pEnumKeyValues: FirstSubKey) == 0 )
      break;
    v17 = this->m_Enums.m_Size;
    v18 = this->m_Enums.m_Memory.m_nAllocationCount;
    if ( v17 + 1 > v18 )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        (CUtlMemory<vgui::TreeNode *,int> *)this,
        num: v17 - v18 + 1);
    ++this->m_Enums.m_Size;
    v19 = this->m_Enums.m_Memory.m_pMemory;
    v20 = this->m_Enums.m_Size - v17 - 1;
    this->m_Enums.m_pElements = this->m_Enums.m_Memory.m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &v19[v17 + 1], src: &v19[v17], count: 4 * v20);
    v21 = &this->m_Enums.m_Memory.m_pMemory[v17];
    if ( v21 != nullptr )
      *v21 = v16;
LABEL_27:
    if ( pSubKey == nullptr )
      return 1;
    FirstSubKey = pSubKey;
    v2 = pRulesKV;
  }
  if ( v16 == nullptr )
    return 0;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v16->m_Entries);
  free(pMem: v16);
  return 0;
}
