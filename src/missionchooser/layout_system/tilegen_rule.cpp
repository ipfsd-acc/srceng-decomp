// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system/tilegen_rule.cpp
// Functions: 9
// ============================================================

#include "missionchooser\layout_system\tilegen_rule.h"

//------------------------------------------------------------------------------
// Address: 0x1001EFD0
// Name: bool ParseSourceTag(char const __near *,bool __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseSourceTag(const char *pSourceTag, bool *pAllowLiterals, bool *pAllowExpressions)
{
  if ( _V_stricmp(s1: pSourceTag, s2: "literal") != 0 )
  {
    if ( _V_stricmp(s1: pSourceTag, s2: "expression") != 0 )
    {
      if ( _V_stricmp(s1: pSourceTag, s2: "expression|literal") != 0
        && _V_stricmp(s1: pSourceTag, s2: "literal|expression") != 0 )
      {
        *pAllowLiterals = false;
        *pAllowExpressions = false;
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
          _LoggingSystem_Log(
            a1: LOG_TilegenLayoutSystem,
            a2: 1,
            a3: "Unrecognized 'source' tag in rule parameter: %s.\n");
        return 0;
      }
      else
      {
        *pAllowLiterals = true;
        *pAllowExpressions = true;
        return 1;
      }
    }
    else
    {
      *pAllowLiterals = false;
      *pAllowExpressions = true;
      return 1;
    }
  }
  else
  {
    *pAllowLiterals = true;
    *pAllowExpressions = false;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F090
// Name: bool ParseArrayTag(char const __near *,bool __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseArrayTag(const char *pArrayTag, bool *pArray, bool *pIsOrdered)
{
  if ( pArrayTag != nullptr )
  {
    if ( _V_stricmp(s1: pArrayTag, s2: "ordered") != 0 )
    {
      if ( _V_stricmp(s1: pArrayTag, s2: "unordered") != 0 )
      {
        *pArray = false;
        *pIsOrdered = false;
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
          _LoggingSystem_Log(
            a1: LOG_TilegenLayoutSystem,
            a2: 1,
            a3: "Unrecognized 'array' tag in rule parameter: %s.\n");
        return 0;
      }
      else
      {
        *pArray = true;
        *pIsOrdered = false;
        return 1;
      }
    }
    else
    {
      *pArray = true;
      *pIsOrdered = true;
      return 1;
    }
  }
  else
  {
    *pArray = false;
    *pIsOrdered = false;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F1C0
// Name: private: void CTilegenRule::RecursiveFixup(class KeyValues __near *,class KeyValues __near *,class CTilegenMissionPreprocessor __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenRule::RecursiveFixup(
        CTilegenRule *this,
        KeyValues *pNewInstanceKV,
        KeyValues *pRuleInstanceKV,
        CTilegenMissionPreprocessor *pPreprocessor)
{
  KeyValues *FirstSubKey; // esi
  int v6; // ebx
  const char *String; // eax
  int v8; // ebx
  KeyValues *Key; // eax
  KeyValues *Copy; // ebx
  const char *Name; // eax
  const char *v12; // eax
  const char *m_pName; // [esp-8h] [ebp-18h]
  KeyValues *pNextKey; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  int ia; // [esp+Ch] [ebp-4h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pNewInstanceKV);
  while ( FirstSubKey != nullptr )
  {
    pNextKey = KeyValues::GetNextKey(this: FirstSubKey);
    CTilegenMissionPreprocessor::EvaluateMetaVariables(this: pPreprocessor, pKeyValues: FirstSubKey);
    v6 = 0;
    if ( this->m_SubstitutionVariables.m_Size > 0 )
    {
      i = 0;
      while ( 1 )
      {
        m_pName = this->m_SubstitutionVariables.m_Memory.m_pMemory[i].m_pName;
        String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: szDescription);
        if ( _V_stricmp(s1: String, s2: m_pName) == 0 )
          break;
        ++i;
        if ( ++v6 >= this->m_SubstitutionVariables.m_Size )
          goto LABEL_13;
      }
      ia = v6;
      v8 = v6;
      Key = KeyValues::FindKey(
              this: pRuleInstanceKV,
              keyName: this->m_SubstitutionVariables.m_Memory.m_pMemory[v8].m_pName,
              bCreate: false);
      if ( Key != nullptr || (Key = this->m_SubstitutionVariables.m_Memory.m_pMemory[v8].m_pDefault) != nullptr )
      {
        Copy = KeyValues::MakeCopy(this: Key);
        KeyValues::SwapSubKey(this: pNewInstanceKV, pExistingSubkey: FirstSubKey, pNewSubKey: Copy);
        Name = KeyValues::GetName(this: FirstSubKey);
        KeyValues::SetName(this: Copy, setName: Name);
        v12 = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: v12, s2: "_elide") == 0 )
          KeyValues::ElideSubKey(this: pNewInstanceKV, pSubKey: Copy);
      }
      else
      {
        KeyValues::RemoveSubKey(this: pNewInstanceKV, subKey: FirstSubKey);
      }
      KeyValues::deleteThis(this: FirstSubKey);
      FirstSubKey = pNextKey;
      v6 = ia;
LABEL_13:
      if ( v6 < this->m_SubstitutionVariables.m_Size )
        continue;
    }
    CTilegenRule::RecursiveFixup(this, pNewInstanceKV: FirstSubKey, pRuleInstanceKV, pPreprocessor);
    FirstSubKey = pNextKey;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F2F0
// Name: public: class KeyValues __near * CTilegenRule::InstantiateRule(class KeyValues __near *,class CTilegenMissionPreprocessor __near *)const
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CTilegenRule::InstantiateRule(
        CTilegenRule *this,
        KeyValues *pRuleInstanceKV,
        CTilegenMissionPreprocessor *pPreprocessor)
{
  int v4; // edi
  int v5; // ebx
  CTilegenRule::SubstitutionVariable_t *m_pMemory; // eax
  KeyValues *Copy; // edi

  v4 = 0;
  if ( this->m_SubstitutionVariables.m_Size <= 0 )
  {
LABEL_7:
    Copy = KeyValues::MakeCopy(this: this->m_pSubstitutionKV);
    CTilegenRule::RecursiveFixup(this, pNewInstanceKV: Copy, pRuleInstanceKV, pPreprocessor);
    return Copy;
  }
  else
  {
    v5 = 0;
    while ( 1 )
    {
      m_pMemory = this->m_SubstitutionVariables.m_Memory.m_pMemory;
      if ( m_pMemory[v5].m_pDefault == nullptr
        && !m_pMemory[v5].m_bCanOmit
        && KeyValues::FindKey(this: pRuleInstanceKV, keyName: m_pMemory[v5].m_pName, bCreate: false) == nullptr )
      {
        break;
      }
      ++v4;
      ++v5;
      if ( v4 >= this->m_SubstitutionVariables.m_Size )
        goto LABEL_7;
    }
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Non-optional substitution variable '%s' not found in rule_instance.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F430
// Name: public: CTilegenRule::CTilegenRule(void)
// Source: json
//------------------------------------------------------------------------------
CTilegenRule *__thiscall CTilegenRule::CTilegenRule(CTilegenRule *this)
{
  this->m_pRuleKV = nullptr;
  this->m_pSubstitutionKV = nullptr;
  this->m_pName = nullptr;
  this->m_pFriendlyName = nullptr;
  this->m_pDescription = nullptr;
  this->m_Types.m_Memory.m_pMemory = nullptr;
  this->m_Types.m_Memory.m_nAllocationCount = 0;
  this->m_Types.m_Memory.m_nGrowSize = 0;
  this->m_Types.m_Size = 0;
  this->m_Types.m_pElements = nullptr;
  this->m_SubstitutionVariables.m_Memory.m_pMemory = nullptr;
  this->m_SubstitutionVariables.m_Memory.m_nAllocationCount = 0;
  this->m_SubstitutionVariables.m_Memory.m_nGrowSize = 0;
  this->m_SubstitutionVariables.m_Size = 0;
  this->m_SubstitutionVariables.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001F470
// Name: public: CTilegenRule::~CTilegenRule(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTilegenRule::~CTilegenRule(CTilegenRule *this)
{
  KeyValues::deleteThis(this: this->m_pRuleKV);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SubstitutionVariables);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Types);
}

//------------------------------------------------------------------------------
// Address: 0x1001F490
// Name: bool ParseTypeTag(char const __near *,class CUtlVector<struct RuleType_t,class CUtlMemory<struct RuleType_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseTypeTag(const char *pTypeTag, CUtlMemory<vgui::MessageMapItem_t,int> *pTypeList)
{
  const char *v2; // esi
  int v3; // ebx
  char v4; // al
  const char *v5; // ecx
  int v6; // ebx
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  RuleType_t *v9; // ecx
  int v10; // eax
  RuleType_t *v11; // esi
  const char *v13; // [esp+Ch] [ebp-Ch]
  int nCurrentIndex; // [esp+10h] [ebp-8h]
  const char *pCurrentTypeName; // [esp+14h] [ebp-4h]

  v2 = pTypeTag;
  v3 = 0;
  nCurrentIndex = 0;
  pCurrentTypeName = pTypeTag;
  while ( 1 )
  {
    v4 = v2[v3];
    v5 = &v2[v3];
    v13 = &v2[v3];
    if ( v4 == 124 || v4 == 0 )
      break;
LABEL_11:
    nCurrentIndex = ++v3;
    if ( *v5 == 0 )
      return 1;
  }
  v6 = (int)&v2[v3 - (_DWORD)pCurrentTypeName];
  if ( v6 > 0 && v6 <= 63 )
  {
    m_pMemory = (int)pTypeList[1].m_pMemory;
    m_nAllocationCount = pTypeList->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: pTypeList, num: m_pMemory - m_nAllocationCount + 1);
    ++pTypeList[1].m_pMemory;
    v9 = (RuleType_t *)pTypeList->m_pMemory;
    v10 = (int)pTypeList[1].m_pMemory - m_pMemory - 1;
    pTypeList[1].m_nAllocationCount = (int)pTypeList->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: v10 << 6);
    v11 = (RuleType_t *)&pTypeList->m_pMemory[m_pMemory];
    _V_memcpy(dest: v11, src: pCurrentTypeName, count: v6);
    v11->m_Name[v6] = 0;
    v3 = nCurrentIndex;
    v5 = v13;
    pCurrentTypeName = &pTypeTag[nCurrentIndex + 1];
    v2 = pTypeTag;
    goto LABEL_11;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Malformed 'type' tag in rule parameter: %s.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001F590
// Name: public: bool CTilegenRule::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenRule::LoadFromKeyValues(CTilegenRule *this, KeyValues *pRuleKeyValues)
{
  const char *String; // eax
  const char *v5; // eax
  KeyValues *m_pRuleKV; // ecx
  const char *v7; // eax
  KeyValues *v8; // ecx
  int Int; // eax
  KeyValues *v10; // ecx
  const char *v11; // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *v15; // eax
  const char *v16; // eax
  int v17; // eax
  const char *v18; // eax
  CTilegenRule::SubstitutionVariable_t variable; // [esp+8h] [ebp-24h] BYREF

  this->m_pRuleKV = pRuleKeyValues;
  String = KeyValues::GetString(this: pRuleKeyValues, keyName: "name", defaultValue: szDescription);
  this->m_pName = String;
  if ( *String == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Rule must have a valid 'name' key.\n");
      return 0;
    }
    return 0;
  }
  v5 = KeyValues::GetString(this: this->m_pRuleKV, keyName: "friendly_name", defaultValue: String);
  m_pRuleKV = this->m_pRuleKV;
  this->m_pFriendlyName = v5;
  v7 = KeyValues::GetString(this: m_pRuleKV, keyName: "description", defaultValue: "No description.");
  v8 = this->m_pRuleKV;
  this->m_pDescription = v7;
  Int = KeyValues::GetInt(this: v8, keyName: "hidden", defaultValue: 1);
  v10 = this->m_pRuleKV;
  this->m_bHidden = Int != 0;
  v11 = KeyValues::GetString(this: v10, keyName: "type", defaultValue: nullptr);
  if ( v11 == nullptr
    || ParseTypeTag(pTypeTag: v11, pTypeList: (CUtlMemory<vgui::MessageMapItem_t,int> *)&this->m_Types) == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Rule '%s' must have a valid 'type' key.\n");
    return 0;
  }
  Key = KeyValues::FindKey(this: this->m_pRuleKV, keyName: "substitute", bCreate: false);
  this->m_pSubstitutionKV = Key;
  if ( Key == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "No 'substitute' blocks found in rule.\n");
      return 0;
    }
    return 0;
  }
  KeyValues::SetName(this: Key, setName: "node");
  FirstSubKey = KeyValues::GetFirstSubKey(this: pRuleKeyValues);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "param") != 0 )
      goto LABEL_20;
    v15 = KeyValues::GetString(this: FirstSubKey, keyName: "name", defaultValue: nullptr);
    variable.m_pName = v15;
    if ( v15 == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
        return 0;
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "No 'name' specified for parameter in rule '%s'.\n");
      return 0;
    }
    if ( *v15 != 36 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
        return 0;
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "First letter of parameter name ('%s') must start with '$'.\n");
      return 0;
    }
    variable.m_pFriendlyName = KeyValues::GetString(this: FirstSubKey, keyName: "friendly_name", defaultValue: v15);
    variable.m_pDescription = KeyValues::GetString(
                                this: FirstSubKey,
                                keyName: "description",
                                defaultValue: "No description.");
    variable.m_pTypeName = KeyValues::GetString(this: FirstSubKey, keyName: "type", defaultValue: "string");
    variable.m_pEnumName = KeyValues::GetString(this: FirstSubKey, keyName: "enum", defaultValue: nullptr);
    if ( _V_stricmp(s1: variable.m_pTypeName, s2: "enum") == 0 && variable.m_pEnumName == nullptr )
      break;
    variable.m_pDefault = KeyValues::FindKey(this: FirstSubKey, keyName: "default", bCreate: false);
    v16 = KeyValues::GetString(this: FirstSubKey, keyName: "array", defaultValue: nullptr);
    ParseArrayTag(pArrayTag: v16, pArray: &variable.m_bArray, pIsOrdered: &variable.m_bOrderedArray);
    variable.m_pElementContainer = KeyValues::GetString(
                                     this: FirstSubKey,
                                     keyName: "element_container",
                                     defaultValue: nullptr);
    if ( variable.m_pDefault != nullptr )
      KeyValues::SetName(this: variable.m_pDefault, setName: variable.m_pName);
    v17 = KeyValues::GetInt(this: FirstSubKey, keyName: "can_omit", defaultValue: 0);
    variable.m_bCanOmit = variable.m_bArray || v17 != 0;
    v18 = KeyValues::GetString(this: FirstSubKey, keyName: "source", defaultValue: "literal|expression");
    if ( ParseSourceTag(
           pSourceTag: v18,
           pAllowLiterals: &variable.m_bAllowLiteral,
           pAllowExpressions: &variable.m_bAllowExpression) == 0 )
      return 0;
    CUtlVector<CTilegenRule::SubstitutionVariable_t,CUtlMemory<CTilegenRule::SubstitutionVariable_t,int>>::InsertBefore(
      this: &this->m_SubstitutionVariables,
      elem: this->m_SubstitutionVariables.m_Size,
      src: &variable);
LABEL_20:
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return 1;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return 0;
  _LoggingSystem_Log(
    a1: LOG_TilegenLayoutSystem,
    a2: 1,
    a3: "Parameter 'type' is 'enum' but no 'enum' key is specified.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005C900
// Name: public: void CUtlMemory<struct CTilegenRule::SubstitutionVariable_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CTilegenRule::SubstitutionVariable_t,int>::Grow(CUtlMemory<MapBrush_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MapBrush_t *m_pMemory; // edx
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
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MapBrush_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MapBrush_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
