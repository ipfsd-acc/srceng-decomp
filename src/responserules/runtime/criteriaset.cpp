// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: responserules/runtime/criteriaset.cpp
// Functions: 16
// ============================================================

#include "responserules\runtime\criteriaset.h"

//------------------------------------------------------------------------------
// Address: 0x1035F2F0
// Name: char const __near * SplitContext(char const __near *,char __near *,int,char __near *,int,float __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl SplitContext(
        const char *raw,
        char *key,
        int keylen,
        char *value,
        int valuelen,
        float *duration,
        const char *entireContext)
{
  char *v7; // eax
  char *v8; // edi
  int v10; // esi
  int v11; // eax
  char *v12; // eax
  char *v13; // esi
  int v14; // eax
  int v15; // esi
  int v16; // [esp-8h] [ebp-18h]
  char *end; // [esp+8h] [ebp-8h]
  bool last; // [esp+Fh] [ebp-1h]

  v7 = _V_strstr(s1: raw, search: ":");
  v8 = v7;
  if ( v7 == nullptr )
  {
    DevMsg(a1: "SplitContext:  warning, ignoring context '%s', missing colon separator!\n", raw);
    *value = 0;
    *key = 0;
    return nullptr;
  }
  v10 = v7 - raw;
  v11 = v10 + 1;
  if ( v10 + 1 >= keylen )
    v11 = keylen;
  V_strncpy(pDest: key, pSrc: raw, maxLen: v11);
  if ( v10 >= keylen - 1 )
    v10 = keylen - 1;
  key[v10] = 0;
  last = false;
  end = _V_strstr(s1: v8 + 1, search: ",");
  if ( end == nullptr )
  {
    end = &v8[_V_strlen(str: v8 + 1) + 1];
    last = true;
  }
  v12 = _V_strstr(s1: v8 + 1, search: ":");
  v13 = v12;
  if ( v12 != nullptr && v12 < end )
  {
    if ( duration != nullptr )
      *duration = atof(nptr: v12 + 1);
    if ( (unsigned __int8)(v13[1] - 48) > 9u )
    {
      DevMsg(
        a1: "SplitContext:  warning, ignoring context '%s', missing comma separator!  Entire context was '%s'.\n",
        raw,
        entireContext);
      *value = 0;
      *key = 0;
      return nullptr;
    }
    v14 = v13 - v8 - 1;
    v15 = valuelen - 1;
    if ( v14 < valuelen - 1 )
      v15 = v14;
    v16 = v15 + 1;
  }
  else
  {
    if ( duration != nullptr )
      *duration = 0.0;
    v15 = valuelen - 1;
    if ( end - v8 - 1 < valuelen - 1 )
      v15 = end - v8 - 1;
    v16 = v15 + 1;
  }
  V_strncpy(pDest: value, pSrc: v8 + 1, maxLen: v16);
  value[v15] = 0;
  if ( last )
    return nullptr;
  return end + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035F480
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct ResponseRules::CriteriaSet::CritEntry_t,short>,short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (__int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > -1 )
      {
        if ( (__int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (__int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 80 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: m_pMemory,
                                                                                            a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035F520
// Name: public: int ResponseRules::CriteriaSet::GetCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ResponseRules::CriteriaSet::GetCount(ResponseRules::CriteriaSet *this)
{
  return this->m_Lookup.m_NumElements;
}

//------------------------------------------------------------------------------
// Address: 0x10360500
// Name: public: char const __near * ResponseRules::CriteriaSet::GetValue(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall ResponseRules::CriteriaSet::GetValue(ResponseRules::CriteriaSet *this, int index)
{
  char *result; // eax

  if ( index < 0 )
    return (char *)locale;
  if ( index >= this->m_Lookup.m_NumElements )
    return (char *)locale;
  result = this->m_Lookup.m_Elements.m_pMemory[(__int16)index].m_Data.value;
  if ( &this->m_Lookup.m_Elements.m_pMemory[(__int16)index] == (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)-10 )
    return (char *)locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10360530
// Name: public: float ResponseRules::CriteriaSet::GetWeight(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall ResponseRules::CriteriaSet::GetWeight(ResponseRules::CriteriaSet *this, int index)
{
  if ( index < 0 || index >= this->m_Lookup.m_NumElements )
    return 1.0;
  else
    return this->m_Lookup.m_Elements.m_pMemory[(__int16)index].m_Data.weight;
}

//------------------------------------------------------------------------------
// Address: 0x10361FB0
// Name: public: int ResponseRules::CriteriaSet::FindCriterionIndex(class CUtlSymbol)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ResponseRules::CriteriaSet::FindCriterionIndex(ResponseRules::CriteriaSet *this, CUtlSymbol criteria)
{
  ResponseRules::CriteriaSet::CritEntry_t search; // [esp+0h] [ebp-48h] BYREF

  search.weight = 0.0;
  search.value[0] = 0;
  search.criterianame = criteria;
  return CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::Find(
           this: &this->m_Lookup,
           &search);
}

//------------------------------------------------------------------------------
// Address: 0x10361FF0
// Name: public: int ResponseRules::CriteriaSet::FindCriterionIndex(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ResponseRules::CriteriaSet::FindCriterionIndex(ResponseRules::CriteriaSet *this, const char *name)
{
  ResponseRules::CriteriaSet::CritEntry_t search; // [esp+4h] [ebp-48h] BYREF

  CUtlSymbolTable::AddString(
    this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols,
    result: (CUtlSymbol *)&name,
    pString: name);
  search.weight = 0.0;
  search.value[0] = 0;
  search.criterianame.m_Id = (unsigned __int16)name;
  return CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::Find(
           this: &this->m_Lookup,
           &search);
}

//------------------------------------------------------------------------------
// Address: 0x103622C0
// Name: public: void ResponseRules::CriteriaSet::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CriteriaSet::Reset(ResponseRules::CriteriaSet *this)
{
  CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::RemoveAll(this: &this->m_Lookup);
  this->m_Lookup.m_FirstFree = -1;
  if ( this->m_Lookup.m_Elements.m_nGrowSize < 0 )
  {
    this->m_Lookup.m_LastAlloc.index = -1;
  }
  else
  {
    if ( this->m_Lookup.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Lookup.m_Elements.m_pMemory);
      this->m_Lookup.m_Elements.m_pMemory = nullptr;
    }
    this->m_Lookup.m_Elements.m_nAllocationCount = 0;
    this->m_Lookup.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103623B0
// Name: public: ResponseRules::CriteriaSet::CriteriaSet(void)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::CriteriaSet *__thiscall ResponseRules::CriteriaSet::CriteriaSet(ResponseRules::CriteriaSet *this)
{
  this->m_Lookup.m_LessFunc = (bool (__cdecl *)(const ResponseRules::CriteriaSet::CritEntry_t *, const ResponseRules::CriteriaSet::CritEntry_t *))CDefOps<CUtlSymbol const>::LessFunc;
  this->m_Lookup.m_Elements.m_pMemory = nullptr;
  this->m_Lookup.m_Elements.m_nAllocationCount = 0;
  this->m_Lookup.m_Elements.m_nGrowSize = 0;
  this->m_Lookup.m_Root = -1;
  this->m_Lookup.m_NumElements = 0;
  this->m_Lookup.m_FirstFree = -1;
  this->m_Lookup.m_LastAlloc.index = -1;
  this->m_Lookup.m_pElements = this->m_Lookup.m_Elements.m_pMemory;
  this->m_nNumPrefixedContexts = 0;
  this->m_bOverrideOnAppend = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103623F0
// Name: public: void ResponseRules::CriteriaSet::AppendCriteria(class CUtlSymbol,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CriteriaSet::AppendCriteria(
        ResponseRules::CriteriaSet *this,
        CUtlSymbol criteria,
        const char *value,
        float weight)
{
  __int16 v5; // di
  ResponseRules::CriteriaSet::CritEntry_t *p_m_Data; // esi
  ResponseRules::CriteriaSet::CritEntry_t entry; // [esp+0h] [ebp-90h] BYREF
  ResponseRules::CriteriaSet::CritEntry_t search; // [esp+48h] [ebp-48h] BYREF

  search.weight = 0.0;
  search.value[0] = 0;
  search.criterianame = criteria;
  v5 = CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::Find(
         this: &this->m_Lookup,
         &search);
  if ( v5 == -1 )
  {
    entry.weight = 0.0;
    entry.value[0] = 0;
    entry.criterianame = criteria;
    v5 = CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::Insert(
           this: &this->m_Lookup,
           a2: (const char *)0xFFFFFFFF,
           insert: &entry);
    if ( *CUtlSymbolTable::String(this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols, id: criteria) == 36 )
      ++this->m_nNumPrefixedContexts;
  }
  else if ( !this->m_bOverrideOnAppend )
  {
    return;
  }
  p_m_Data = &this->m_Lookup.m_Elements.m_pMemory[v5].m_Data;
  if ( value != nullptr )
    V_strncpy(pDest: p_m_Data->value, pSrc: value, maxLen: 64);
  else
    p_m_Data->value[0] = 0;
  p_m_Data->weight = weight;
}

//------------------------------------------------------------------------------
// Address: 0x103624C0
// Name: public: void ResponseRules::CriteriaSet::AppendCriteria(char const __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CriteriaSet::AppendCriteria(
        ResponseRules::CriteriaSet *this,
        const char *pCriteriaName,
        const char *value,
        float weight)
{
  CUtlSymbolTable::AddString(
    this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols,
    result: (CUtlSymbol *)&pCriteriaName,
    pString: pCriteriaName);
  ResponseRules::CriteriaSet::AppendCriteria(this, criteria: (CUtlSymbol)pCriteriaName, value, weight);
}

//------------------------------------------------------------------------------
// Address: 0x10362500
// Name: public: void ResponseRules::CriteriaSet::Merge(class ResponseRules::CriteriaSet const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CriteriaSet::Merge(
        ResponseRules::CriteriaSet *this,
        const ResponseRules::CriteriaSet *otherCriteria)
{
  int v3; // eax
  UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *m_pMemory; // edx
  UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *v5; // eax
  int i; // esi
  float v7; // xmm0_4
  char *value; // eax
  unsigned int weight; // [esp+4h] [ebp-14h]
  int count; // [esp+14h] [ebp-4h]

  if ( otherCriteria != nullptr )
  {
    v3 = otherCriteria->m_Lookup.m_NumElements + this->m_Lookup.m_NumElements;
    count = otherCriteria->m_Lookup.m_NumElements;
    if ( this->m_Lookup.m_Elements.m_nAllocationCount < v3 && this->m_Lookup.m_Elements.m_nGrowSize >= 0 )
    {
      m_pMemory = this->m_Lookup.m_Elements.m_pMemory;
      this->m_Lookup.m_Elements.m_nAllocationCount = v3;
      weight = 80 * v3;
      if ( m_pMemory != nullptr )
        v5 = (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)_g_pMemAlloc->Realloc_2(
                                                                                 this: _g_pMemAlloc,
                                                                                 a2: m_pMemory,
                                                                                 a3: weight);
      else
        v5 = (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)_g_pMemAlloc->Alloc_2(
                                                                                 this: _g_pMemAlloc,
                                                                                 a2: weight);
      this->m_Lookup.m_Elements.m_pMemory = v5;
    }
    for ( i = 0; i < count; ++i )
    {
      if ( i < 0 || i >= otherCriteria->m_Lookup.m_NumElements )
        v7 = 1.0;
      else
        v7 = otherCriteria->m_Lookup.m_Elements.m_pMemory[(__int16)i].m_Data.weight;
      if ( i < 0
        || i >= otherCriteria->m_Lookup.m_NumElements
        || (value = otherCriteria->m_Lookup.m_Elements.m_pMemory[(__int16)i].m_Data.value,
            &otherCriteria->m_Lookup.m_Elements.m_pMemory[(__int16)i] == (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)-10) )
      {
        value = (char *)locale;
      }
      if ( i < 0 || i >= otherCriteria->m_Lookup.m_NumElements )
        ResponseRules::CriteriaSet::AppendCriteria(this, criteria: (CUtlSymbol)-1, value, weight: v7);
      else
        ResponseRules::CriteriaSet::AppendCriteria(
          this,
          criteria: otherCriteria->m_Lookup.m_Elements.m_pMemory[(__int16)i].m_Data.criterianame,
          value,
          weight: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10362610
// Name: public: void ResponseRules::CriteriaSet::Merge(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CriteriaSet::Merge(ResponseRules::CriteriaSet *this, const char *modifiers)
{
  const char *v2; // edi
  char *v3; // esi
  char copy_modifiers[256]; // [esp+Ch] [ebp-204h] BYREF
  char value[128]; // [esp+10Ch] [ebp-104h] BYREF
  char key[128]; // [esp+18Ch] [ebp-84h] BYREF
  ResponseRules::CriteriaSet *v7; // [esp+20Ch] [ebp-4h]

  v2 = modifiers;
  v7 = this;
  if ( modifiers != nullptr )
  {
    memset(key, 0, sizeof(key));
    memset(value, 0, sizeof(value));
    V_strncpy(pDest: copy_modifiers, pSrc: modifiers, maxLen: 255);
    v3 = copy_modifiers;
    do
    {
      v3 = SplitContext(raw: v3, key, keylen: 128, value, valuelen: 128, duration: nullptr, entireContext: v2);
      if ( key[0] != 0 && value[0] != 0 )
      {
        CUtlSymbolTable::AddString(
          this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols,
          result: (CUtlSymbol *)&modifiers,
          pString: key);
        ResponseRules::CriteriaSet::AppendCriteria(this: v7, criteria: (CUtlSymbol)modifiers, value, weight: 1.0);
      }
    }
    while ( v3 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103626F0
// Name: public: static int ResponseRules::CriteriaSet::InterceptWorldSetContexts(class ResponseRules::CriteriaSet restrict __near *,class ResponseRules::CriteriaSet restrict __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ResponseRules::CriteriaSet::InterceptWorldSetContexts(
        ResponseRules::CriteriaSet *pFrom,
        ResponseRules::CriteriaSet *pSetOnWorld)
{
  ResponseRules::CriteriaSet *v2; // edi
  int m_nNumPrefixedContexts; // eax
  ResponseRules::CriteriaSet *v5; // esi
  UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *m_pMemory; // edx
  UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *v7; // eax
  int m_NumElements; // eax
  int v9; // eax
  IMemAlloc_vtbl *v10; // edx
  __int16 Inorder; // ax
  int v12; // ebx
  const char *v13; // eax
  int v14; // eax
  int weight_low; // xmm0_4
  int v16; // eax
  int v17; // xmm0_4
  const char *v18; // esi
  int v19; // ecx
  int v20; // xmm0_4
  const char *v21; // eax
  int v22; // esi
  unsigned int weight; // [esp+8h] [ebp-9Ch]
  char buf[80]; // [esp+18h] [ebp-8Ch] BYREF
  char *pString; // [esp+68h] [ebp-3Ch]
  ResponseRules::CriteriaSet rewrite; // [esp+6Ch] [ebp-38h] BYREF
  float v27; // [esp+90h] [ebp-14h]
  float v28; // [esp+94h] [ebp-10h]
  float v29; // [esp+98h] [ebp-Ch]
  char *value; // [esp+9Ch] [ebp-8h]
  CUtlSymbol v31; // [esp+A0h] [ebp-4h] BYREF

  v2 = pFrom;
  m_nNumPrefixedContexts = pFrom->m_nNumPrefixedContexts;
  if ( m_nNumPrefixedContexts == 0 )
    return 0;
  v5 = pSetOnWorld;
  if ( pSetOnWorld->m_Lookup.m_Elements.m_nAllocationCount < m_nNumPrefixedContexts
    && pSetOnWorld->m_Lookup.m_Elements.m_nGrowSize >= 0 )
  {
    m_pMemory = pSetOnWorld->m_Lookup.m_Elements.m_pMemory;
    pSetOnWorld->m_Lookup.m_Elements.m_nAllocationCount = m_nNumPrefixedContexts;
    weight = 80 * m_nNumPrefixedContexts;
    if ( m_pMemory != nullptr )
      v7 = (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: weight);
    else
      v7 = (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: weight);
    v5->m_Lookup.m_Elements.m_pMemory = v7;
  }
  strcpy(buf, "world");
  memset(dst: (int)&buf[6], value: nullptr, count: 0x4Au);
  rewrite.m_Lookup.m_NumElements = 0;
  m_NumElements = v2->m_Lookup.m_NumElements;
  rewrite.m_Lookup.m_Root = -1;
  v9 = m_NumElements + 1;
  rewrite.m_Lookup.m_LessFunc = (bool (__cdecl *)(const ResponseRules::CriteriaSet::CritEntry_t *, const ResponseRules::CriteriaSet::CritEntry_t *))CDefOps<CUtlSymbol const>::LessFunc;
  memset(&rewrite.m_Lookup.m_Elements, 0, sizeof(rewrite.m_Lookup.m_Elements));
  rewrite.m_Lookup.m_FirstFree = -1;
  rewrite.m_Lookup.m_LastAlloc.index = -1;
  rewrite.m_Lookup.m_pElements = nullptr;
  rewrite.m_nNumPrefixedContexts = 0;
  rewrite.m_bOverrideOnAppend = true;
  if ( v9 > 0 )
  {
    v10 = _g_pMemAlloc->__vftable;
    rewrite.m_Lookup.m_Elements.m_nAllocationCount = v9;
    rewrite.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)v10->Alloc_2(this: _g_pMemAlloc, a2: 80 * v9);
  }
  Inorder = CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::FirstInorder(this: &v2->m_Lookup);
  while ( 1 )
  {
    v12 = Inorder;
    if ( Inorder < 0 || Inorder >= v2->m_Lookup.m_NumElements )
      break;
    v13 = CUtlSymbolTable::String(
            this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols,
            id: v2->m_Lookup.m_Elements.m_pMemory[Inorder].m_Data.criterianame);
    if ( v13 != nullptr && *v13 == 36 )
    {
      pString = (char *)(v13 + 1);
      V_strncpy(pDest: &buf[5], pSrc: v13 + 1, maxLen: 75);
      v14 = v2->m_Lookup.m_NumElements;
      if ( v12 >= v14 )
        weight_low = 1065353216;
      else
        weight_low = LODWORD(v2->m_Lookup.m_Elements.m_pMemory[(__int16)v12].m_Data.weight);
      v27 = *(float *)&weight_low;
      if ( v12 >= v14 || (value = v2->m_Lookup.m_Elements.m_pMemory[(__int16)v12].m_Data.value) == nullptr )
        value = (char *)locale;
      CUtlSymbolTable::AddString(
        this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols,
        result: (CUtlSymbol *)&pFrom,
        pString: buf);
      ResponseRules::CriteriaSet::AppendCriteria(this: &rewrite, criteria: (CUtlSymbol)pFrom, value, weight: v27);
      v16 = v2->m_Lookup.m_NumElements;
      if ( v12 >= v16 )
        v17 = 1065353216;
      else
        v17 = LODWORD(v2->m_Lookup.m_Elements.m_pMemory[(__int16)v12].m_Data.weight);
      v29 = *(float *)&v17;
      if ( v12 >= v16
        || (v18 = v2->m_Lookup.m_Elements.m_pMemory[(__int16)v12].m_Data.value,
            &v2->m_Lookup.m_Elements.m_pMemory[(__int16)v12] == (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)-10) )
      {
        v18 = locale;
      }
      CUtlSymbolTable::AddString(this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols, result: &v31, pString);
      ResponseRules::CriteriaSet::AppendCriteria(this: pSetOnWorld, criteria: v31, value: v18, weight: v29);
      buf[5] = 0;
      Inorder = CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::NextInorder(
                  this: &v2->m_Lookup,
                  i: v12);
      v5 = pSetOnWorld;
    }
    else
    {
      v19 = v2->m_Lookup.m_NumElements;
      if ( v12 >= v19 )
        v20 = 1065353216;
      else
        v20 = LODWORD(v2->m_Lookup.m_Elements.m_pMemory[(__int16)v12].m_Data.weight);
      v28 = *(float *)&v20;
      if ( v12 >= v19
        || (v21 = v2->m_Lookup.m_Elements.m_pMemory[(__int16)v12].m_Data.value,
            &v2->m_Lookup.m_Elements.m_pMemory[(__int16)v12] == (UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short> *)-10) )
      {
        v21 = locale;
      }
      if ( v12 >= v19 )
        ResponseRules::CriteriaSet::AppendCriteria(this: &rewrite, criteria: (CUtlSymbol)-1, value: v21, weight: v28);
      else
        ResponseRules::CriteriaSet::AppendCriteria(
          this: &rewrite,
          criteria: v2->m_Lookup.m_Elements.m_pMemory[(__int16)v12].m_Data.criterianame,
          value: v21,
          weight: v28);
      Inorder = CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::NextInorder(
                  this: &v2->m_Lookup,
                  i: v12);
      v5 = pSetOnWorld;
    }
  }
  v2->m_nNumPrefixedContexts = 0;
  CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::Swap(
    this: &v2->m_Lookup,
    that: &rewrite.m_Lookup);
  v22 = v5->m_Lookup.m_NumElements;
  CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::RemoveAll(this: &rewrite.m_Lookup);
  if ( rewrite.m_Lookup.m_Elements.m_nGrowSize >= 0 && rewrite.m_Lookup.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rewrite.m_Lookup.m_Elements.m_pMemory);
  return v22;
}

//------------------------------------------------------------------------------
// Address: 0x103629F0
// Name: public: void ResponseRules::CriteriaSet::RemoveCriteria(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CriteriaSet::RemoveCriteria(ResponseRules::CriteriaSet *this, const char *criteria)
{
  const char *v2; // ebx
  __int16 v4; // di
  int v5; // eax
  ResponseRules::CriteriaSet::CritEntry_t search; // [esp+Ch] [ebp-48h] BYREF

  v2 = criteria;
  CUtlSymbolTable::AddString(
    this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols,
    result: (CUtlSymbol *)&criteria,
    pString: criteria);
  search.criterianame.m_Id = (unsigned __int16)criteria;
  search.weight = 0.0;
  search.value[0] = 0;
  v4 = CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::Find(
         this: &this->m_Lookup,
         &search);
  if ( v4 != -1 )
  {
    if ( *v2 == 36 )
      this->m_nNumPrefixedContexts = this->m_nNumPrefixedContexts - 1 < 0 ? 0 : this->m_nNumPrefixedContexts - 1;
    if ( v4 != -1 )
    {
      CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::Unlink(
        this: &this->m_Lookup,
        elem: v4);
      v5 = v4;
      this->m_Lookup.m_Elements.m_pMemory[v5].m_Left = v4;
      this->m_Lookup.m_Elements.m_pMemory[v5].m_Right = this->m_Lookup.m_FirstFree;
      --this->m_Lookup.m_NumElements;
      this->m_Lookup.m_FirstFree = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10362A90
// Name: public: void ResponseRules::CriteriaSet::Describe(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::CriteriaSet::Describe(ResponseRules::CriteriaSet *this)
{
  ResponseRules::CriteriaSet *v1; // esi
  int m_NumElements; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short> *v3; // ebx
  unsigned __int16 Inorder; // ax
  const char *v5; // edi
  const ResponseRules::CriteriaSet::CritEntry_t *p_m_Data; // esi
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // dx
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v11; // esi
  int v12; // edx
  CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t *v13; // esi
  unsigned __int16 v14; // ax
  unsigned __int16 i; // si
  const ResponseRules::CriteriaSet::CritEntry_t *elem; // ecx
  const char *key; // edx
  float weight; // xmm0_4
  const char *value; // eax
  CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short> m_TempMap; // [esp+18h] [ebp-30h] BYREF
  CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t insert; // [esp+34h] [ebp-14h] BYREF
  CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl*)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short> > *p_m_Lookup; // [esp+3Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+40h] [ebp-8h] BYREF
  bool leftchild; // [esp+47h] [ebp-1h] BYREF

  v1 = this;
  m_NumElements = this->m_Lookup.m_NumElements;
  v3 = nullptr;
  p_m_Lookup = &this->m_Lookup;
  m_TempMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  m_TempMap.m_Tree.m_Elements.m_pMemory = nullptr;
  m_TempMap.m_Tree.m_Elements.m_nAllocationCount = m_NumElements;
  m_TempMap.m_Tree.m_Elements.m_nGrowSize = 0;
  if ( m_NumElements != 0 )
  {
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_NumElements);
    m_TempMap.m_Tree.m_Elements.m_pMemory = v3;
  }
  *(_DWORD *)&m_TempMap.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&m_TempMap.m_Tree.m_FirstFree = -1;
  m_TempMap.m_Tree.m_pElements = v3;
  Inorder = CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::FirstInorder(this: &v1->m_Lookup);
  v5 = (const char *)Inorder;
  if ( Inorder != 0xFFFF )
  {
    do
    {
      p_m_Data = &v1->m_Lookup.m_Elements.m_pMemory[(__int16)v5].m_Data;
      insert.key = CUtlSymbolTable::String(
                     this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols,
                     id: p_m_Data->criterianame);
      insert.elem = p_m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &m_TempMap.m_Tree,
        &insert,
        parent,
        &leftchild);
      v7 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,void (__thiscall ResponseRules::CResponseSystem::*)(char const *,ResponseRules::ResponseGroup &,ResponseRules::ResponseParams &),unsigned short>::Node_t,unsigned short>,unsigned short> > *)&m_TempMap,
             a2: v5);
      v8 = parent[0];
      v9 = v7;
      m_pMemory = m_TempMap.m_Tree.m_Elements.m_pMemory;
      v11 = v9;
      m_TempMap.m_Tree.m_Elements.m_pMemory[v11].m_Right = -1;
      m_pMemory[v11].m_Left = -1;
      m_pMemory[v11].m_Tag = 0;
      m_pMemory[v11].m_Parent = v8;
      if ( v8 == 0xFFFF )
      {
        m_TempMap.m_Tree.m_Root = v9;
      }
      else
      {
        v12 = v8;
        if ( leftchild )
          m_pMemory[v12].m_Left = v9;
        else
          m_pMemory[v12].m_Right = v9;
      }
      CUtlRBTree<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        this: &m_TempMap.m_Tree,
        elem: v9);
      v3 = m_TempMap.m_Tree.m_Elements.m_pMemory;
      ++m_TempMap.m_Tree.m_NumElements;
      v13 = &m_TempMap.m_Tree.m_Elements.m_pMemory[v11].m_Data;
      if ( v13 != nullptr )
        *v13 = insert;
      v1 = (ResponseRules::CriteriaSet *)p_m_Lookup;
      v14 = CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::NextInorder(
              this: p_m_Lookup,
              i: (__int16)v5);
      v5 = (const char *)v14;
    }
    while ( v14 != 0xFFFF );
  }
  for ( i = CUtlRBTree<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &m_TempMap.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &m_TempMap.m_Tree,
              i) )
  {
    elem = v3[i].m_Data.elem;
    key = v3[i].m_Data.key;
    weight = elem->weight;
    value = elem->value;
    if ( weight == 1.0 )
    {
      if ( elem == (const ResponseRules::CriteriaSet::CritEntry_t *)-2 )
        value = locale;
      DevMsg(a1: "  %20s = '%s'\n", key, value);
    }
    else
    {
      if ( elem == (const ResponseRules::CriteriaSet::CritEntry_t *)-2 )
        value = locale;
      DevMsg(a1: "  %20s = '%s' (weight %f)\n", key, value, weight);
    }
  }
  CUtlRBTree<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CriteriaSet::CritEntry_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &m_TempMap.m_Tree);
  if ( m_TempMap.m_Tree.m_Elements.m_nGrowSize >= 0 && m_TempMap.m_Tree.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_TempMap.m_Tree.m_Elements.m_pMemory);
}
