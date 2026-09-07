// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datamodel/dependencygraph.cpp
// Functions: 10
// ============================================================

#include "datamodel\dependencygraph.h"

//------------------------------------------------------------------------------
// Address: 0x00447620
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00447640
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x00448340
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448540
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004486E0
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x00448770
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  CAttributeNode *src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = &search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: &this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: &this->m_attrNodes,
           src: &pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004488C0
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00448A90
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00448EB0
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00448F50
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00455C40
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00455C60
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x00456790
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456990
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00456A90
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x00456B20
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  CAttributeNode *src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = &search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: &this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: &this->m_attrNodes,
           src: &pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00456C70
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00456E40
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00457260
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00457300
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004160E0
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00416100
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x00416BB0
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416DB0
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416F50
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x00417000
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<vgui::TreeNode *,int> *v9; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  CAttributeNode *src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = &search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: &this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: &this->m_attrNodes,
           src: &pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<vgui::TreeNode *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00417150
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00417320
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00417740
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004177E0
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x101EF420
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x101EF440
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x101EFF70
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0170
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0270
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x101F0300
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<vgui::TreeNode *,int> *v9; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  CAttributeNode *src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = &search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: &this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: &this->m_attrNodes,
           src: &pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<vgui::TreeNode *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101F0450
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101F0620
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CPreviewImagePropertiesCache::PreviewImageLessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&operatorDict,
             a2: (const char *)v7);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101F0A40
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F0AE0
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0047D0A0
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x0047D0C0
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0047DC10
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DE10
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047DF10
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x0047DFA0
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = (DmElementHandle_t)&search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
           src: (const DmElementHandle_t *)&pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0047E0F0
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0047E2C0
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0047E6E0
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047E780
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x0043543C
// Name: public: void SeekList::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SeekList::Cleanup(SeekList *this)
{
  SeekNode *m_pFirst; // eax

  while ( this->m_pFirst != nullptr )
  {
    m_pFirst = this->m_pFirst;
    this->m_pFirst = this->m_pFirst->m_pNext;
    m_pFirst->m_pNext = nullptr;
    free(pMem: m_pFirst);
  }
  this->m_pLast = nullptr;
  this->m_dwCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00435650
// Name: private: void CStreamEncoder::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStreamEncoder::Cleanup(CStreamEncoder *this)
{
  CDmAttributeOp<VMatrix> *v2; // ecx
  tagPERFTIMERINFO *m_pPerfTimerInfo; // esi
  CDmAttributeOp<VMatrix> *v4; // [esp-4h] [ebp-8h]
  CDmAttributeOp<VMatrix> *v5; // [esp-4h] [ebp-8h]

  SeekList::Cleanup(this: &this->m_SeekList);
  if ( this->m_pbSrc != nullptr )
  {
    free(pMem: this->m_pbSrc);
    v2 = v4;
  }
  if ( this->m_pbDst != nullptr )
  {
    free(pMem: this->m_pbDst);
    v2 = v5;
  }
  if ( this->m_pauenc != nullptr )
    auencDelete(pauenc: this->m_pauenc);
  m_pPerfTimerInfo = this->m_pPerfTimerInfo;
  if ( m_pPerfTimerInfo != nullptr )
    PerfTimerFree(this: v2, pInfo: m_pPerfTimerInfo);
}

//------------------------------------------------------------------------------
// Address: 0x00435FBF
// Name: private: void CXMAInterleave::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXMAInterleave::Cleanup(CXMAInterleave *this)
{
  unsigned int v2; // ebx
  void **p_fragmenthdr; // edi
  CXMAStreamCopy *m_pStreamState; // esi

  if ( this->m_pbBuf0 != nullptr )
    free(pMem: this->m_pbBuf0);
  if ( this->m_pbBuf1 != nullptr )
    free(pMem: this->m_pbBuf1);
  v2 = 0;
  if ( this->m_nNumstreams != 0 )
  {
    p_fragmenthdr = (void **)&this->m_aXMAstreams[0].fragmenthdr;
    do
    {
      free(pMem: *(p_fragmenthdr - 1));
      free(pMem: *p_fragmenthdr);
      ++v2;
      p_fragmenthdr += 14;
    }
    while ( v2 < this->m_nNumstreams );
  }
  m_pStreamState = this->m_pStreamState;
  if ( m_pStreamState != nullptr )
    free(pMem: m_pStreamState);
}

//------------------------------------------------------------------------------
// Address: 0x00503D50
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00503D70
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x005048D0
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00504AD0
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00504BD0
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x00504C60
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<S3RGBA,int> *v9; // esi
  int m_nAllocationCount; // eax
  S3RGBA *v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  CAttributeNode *src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = &search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: &this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: &this->m_attrNodes,
           src: &pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<S3RGBA,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00504DB0
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00504F80
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict,
             a2: (const char *)v7);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&v49->m_opNodes, num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x005053A0
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00505440
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004356A2
// Name: public: void CStreamEncoder::GetLoopData(unsigned long __near *,unsigned long __near *,unsigned char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStreamEncoder::GetLoopData(
        CStreamEncoder *this,
        unsigned int *pdwStart,
        unsigned int *pdwStop,
        unsigned __int8 *pbSubFrameData)
{
  *pdwStart = this->m_dwLoopStartOffset;
  *pdwStop = this->m_dwLoopStopOffset;
  *pbSubFrameData = this->m_bLoopSubframeSkip | (16 * this->m_bLoopSubframeEnd);
}

//------------------------------------------------------------------------------
// Address: 0x004356D2
// Name: public: long CStreamEncoder::GetSeekData(unsigned long __near *,unsigned long __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CStreamEncoder::GetSeekData(
        CStreamEncoder *this,
        unsigned int *pdwSeekEntries,
        unsigned int **ppdwSamples)
{
  int v3; // esi
  unsigned int *Samples; // eax

  v3 = 0;
  *pdwSeekEntries = this->m_SeekList.m_dwCount;
  Samples = SeekList::GetSamples(this: &this->m_SeekList);
  *ppdwSamples = Samples;
  if ( Samples == nullptr )
    return -2147024882;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00435701
// Name: public: CStreamEncoder::CStreamEncoder(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStreamEncoder *__thiscall CStreamEncoder::CStreamEncoder(CStreamEncoder *this)
{
  this->m_fInitialized = false;
  this->m_pauenc = nullptr;
  this->m_pPerfTimerInfo = nullptr;
  this->m_cbInputBlock = 0;
  this->m_cbSrcBufLength = 0;
  this->m_cbDstBufLength = 0;
  this->m_pbSrc = nullptr;
  this->m_pbDst = nullptr;
  this->m_cFramesGenerated = 0;
  this->m_cbSourceBytesLeft = 0;
  this->m_dwCurrentSamples = 0;
  this->m_SeekList.m_pFirst = nullptr;
  this->m_SeekList.m_pLast = nullptr;
  this->m_SeekList.m_dwCount = 0;
  this->m_dwLoopStart = 0;
  this->m_dwLoopStop = 0;
  this->m_dwPacket = 0;
  this->m_dwLoopStartOffset = 0;
  this->m_dwLoopStopOffset = 0;
  *(_WORD *)&this->m_bLoopSubframeEnd = 0;
  this->m_fCalcLoops = false;
  memset(&this->m_wfx, 0, sizeof(this->m_wfx));
  memset(dst: (unsigned __int8 *)&this->m_wmaencInfo, value: 0, count: sizeof(this->m_wmaencInfo));
  memset(dst: (unsigned __int8 *)&this->m_Format, value: 0, count: sizeof(this->m_Format));
  memset(dst: this->m_abPrevPacket, value: 0, count: sizeof(this->m_abPrevPacket));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004357C6
// Name: public: CStreamEncoder::~CStreamEncoder(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStreamEncoder::~CStreamEncoder(CStreamEncoder *this)
{
  CStreamEncoder::Cleanup(this);
  SeekList::Cleanup(this: &this->m_SeekList);
}

//------------------------------------------------------------------------------
// Address: 0x0043601F
// Name: private: unsigned int CXMAInterleave::ChopAndCopy(unsigned char __near *,unsigned char __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CXMAInterleave::ChopAndCopy(
        CXMAInterleave *this,
        unsigned __int8 *pbSrc,
        unsigned __int8 *pbDst,
        int nFrames)
{
  unsigned __int8 *v4; // edi
  unsigned int v6; // esi
  signed int v7; // eax
  int v8; // ebx
  int v9; // esi
  int frm_count; // [esp+8h] [ebp-4h] BYREF

  v4 = pbSrc;
  CountFrames(pbPkt: pbSrc, pnFrmCount: &frm_count);
  if ( frm_count <= nFrames )
    return 0;
  v6 = frm_count - nFrames;
  v7 = SeekOffset(pbPkt: v4) + 32;
  v8 = 0;
  pbSrc = (unsigned __int8 *)v7;
  if ( v6 != 0 )
  {
    while ( 1 )
    {
      nFrames = FindNextFrame(pbPkt: v4, pnOffset: (int *)&pbSrc);
      if ( nFrames == 0 )
        return nFrames;
      if ( ++v8 >= v6 )
      {
        v7 = (signed int)pbSrc;
        break;
      }
    }
  }
  if ( nFrames == 0 || v7 >= 0x4000 )
    return nFrames;
  v9 = 0x4000 - v7;
  BitCopy(pbSrc: v4, pbDst, nSrcOff: v7, nDstOff: 0x20u, nLen: 0x4000 - v7);
  BitCopy(pbSrc: this->m_pbZbuf, pbDst: v4, nSrcOff: 0, nDstOff: (unsigned int)--pbSrc, nLen: v9 + 1);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x004360BA
// Name: private: long CXMAInterleave::WriteHeader(class CTargetStream_XMA1 __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CXMAInterleave::WriteHeader(
        CXMAInterleave *this,
        CTargetStream_XMA1 *pXMA1Stream,
        unsigned __int8 version)
{
  unsigned int v4; // edi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // esi
  XMAWAVEFORMAT *pFormat; // eax
  unsigned __int8 v8; // cl
  bool v9; // cf
  int v10; // ecx
  unsigned __int8 LoopCount; // al
  int i; // [esp+Ch] [ebp-Ch]
  HRESULT hr; // [esp+10h] [ebp-8h]
  unsigned __int8 Version; // [esp+17h] [ebp-1h]

  hr = 0;
  v4 = 20 * (this->m_nNumstreams - 1) + 32;
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4);
  v6 = v5;
  if ( v5 == nullptr )
    return -2147024882;
  memset(dst: v5, value: 0, count: v4);
  i = 0;
  if ( (int)this->m_nNumstreams <= 0 )
  {
LABEL_19:
    hr = CTargetStream::SetFormat(this: pXMA1Stream, pbFormat: v6, dwFormatSize: v4);
  }
  else
  {
    while ( hr >= 0 )
    {
      pFormat = this->m_aXMAstreams[i].pFormat;
      if ( pFormat->FormatTag != 357 )
        hr = -2004287486;
      if ( hr >= 0 )
      {
        v8 = version;
        if ( version == 0 )
          v8 = pFormat->Version;
        Version = v8;
        v9 = v8 < 3u;
        v10 = (int)&v6[20 * i + 12];
        *(_DWORD *)v10 = pFormat->XmaStreams[0].PsuedoBytesPerSec;
        *(_BYTE *)(v10 + 17) = pFormat->XmaStreams[0].Channels;
        *(_WORD *)(v10 + 18) = pFormat->XmaStreams[0].ChannelMask;
        *(_DWORD *)(v10 + 4) = pFormat->XmaStreams[0].SampleRate;
        if ( v9 )
        {
          v6[20 * i + 28] = pFormat->XmaStreams[0].SubframeData;
          *(_DWORD *)&v6[20 * i + 24] = pFormat->XmaStreams[0].LoopEnd;
          *(_DWORD *)&v6[20 * i + 20] = pFormat->XmaStreams[0].LoopStart;
        }
        if ( i == 0 )
        {
          *((_WORD *)v6 + 1) = pFormat->BitsPerSample;
          *((_WORD *)v6 + 2) = pFormat->EncodeOptions;
          *(_WORD *)v6 = pFormat->FormatTag;
          *((_WORD *)v6 + 4) = this->m_nNumstreams;
          v6[11] = Version;
        }
        if ( v6[10] == 0 )
        {
          LoopCount = pFormat->LoopCount;
          if ( LoopCount != 0 )
            v6[10] = LoopCount;
        }
      }
      if ( ++i >= (signed int)this->m_nNumstreams )
      {
        if ( hr < 0 )
          break;
        goto LABEL_19;
      }
    }
  }
  free(pMem: v6);
  return hr;
}

//------------------------------------------------------------------------------
// Address: 0x004361EA
// Name: public: GrowArray<unsigned int>::~GrowArray<unsigned int>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GrowArray<unsigned int>::~GrowArray<unsigned int>(GrowArray<unsigned int> *this)
{
  if ( this->m_array != nullptr )
    free(pMem: this->m_array);
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004C1850
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x004C1870
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x004C24C0
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C26C0
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C27C0
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x004C2850
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  CAttributeNode *src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = &search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: &this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: &this->m_attrNodes,
           src: &pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004C29A0
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x004C2B70
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x004C2F90
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVectorAuto<s_animation_t *>,CUtlMemory<CUtlVectorAuto<s_animation_t *>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C3030
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_opNodes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00449340
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00449360
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0044A040
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A240
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A340
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x0044A3D0
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  CAttributeNode *src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = &search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( !CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
          this: &this->m_attrNodes,
          &src,
          &pBucket,
          pIndex: (int *)&pAttr)
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( !CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
            this: &this->m_attrNodes,
            src: &pAttrNode,
            pBucket: (unsigned int *)&pAttr,
            pIndex: (int *)&pBucket) )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0044A520
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0044A6F0
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0044AB10
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044ABB0
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00447F10
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00447F30
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x00448B30
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448D30
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448E30
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x00448EC0
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = (DmElementHandle_t)&search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
           src: (const DmElementHandle_t *)&pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00449010
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00449240
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDmxSerializationDictionary::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00449660
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00449700
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x0043FD00
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x0043FD20
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x00440A60
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  unsigned int m_Size; // edi
  unsigned int v3; // ebx
  COperatorNode *v4; // ebp
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  bool v10; // zf
  COperatorNode **v11; // eax
  int v12; // edx
  int v13; // eax
  int *p_m_Size; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  CAttributeNode *v17; // ebp
  unsigned int v18; // edx
  unsigned int v19; // eax
  COperatorNode *v20; // ebx
  int v21; // edi
  int v22; // eax
  COperatorNode **v23; // ecx
  int v24; // eax
  COperatorNode **v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // ecx
  int *i; // edi
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int ha; // [esp+10h] [ebp-Ch]
  unsigned int oi; // [esp+14h] [ebp-8h]
  unsigned int v33; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  for ( h = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      v10 = this->m_opRoots.m_Size - v6 == 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 >= 0 && !v10 )
        memmove(dst: (unsigned __int8 *)&m_pMemory[v6 + 1], src: (unsigned __int8 *)&m_pMemory[v6], count: 4 * v9);
      v11 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v11 != nullptr )
        *v11 = v4;
      m_Size = h;
      v4->m_bInList = true;
    }
  }
  v12 = this->m_attrNodes.m_Buckets.m_Size;
  v13 = 0;
  if ( v12 <= 0 )
  {
LABEL_15:
    v15 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v13;
      p_m_Size += 5;
      if ( v13 >= v12 )
        goto LABEL_15;
    }
    v15 = v13 << 16;
  }
  for ( oi = v15; oi != -1; oi = v28 | (v27 << 16) )
  {
    v16 = oi;
    v17 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(oi)].m_Memory.m_pMemory[(unsigned __int16)oi];
    if ( !v17->m_bIsOutputToOperator && (v17->m_attribute->m_nFlags & 0x40000) != 0 )
    {
      v18 = v17->m_InputDependentOperators.m_Size;
      v19 = 0;
      ha = v18;
      v33 = 0;
      if ( v18 != 0 )
      {
        do
        {
          v20 = v17->m_InputDependentOperators.m_Memory.m_pMemory[v19];
          if ( !v20->m_bInList )
          {
            v21 = this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v21 + 1 > v22 )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v21 - v22 + 1);
            ++this->m_opRoots.m_Size;
            v23 = this->m_opRoots.m_Memory.m_pMemory;
            v24 = this->m_opRoots.m_Size - v21 - 1;
            v10 = this->m_opRoots.m_Size - v21 == 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v24 >= 0 && !v10 )
              memmove(dst: (unsigned __int8 *)&v23[v21 + 1], src: (unsigned __int8 *)&v23[v21], count: 4 * v24);
            v25 = &this->m_opRoots.m_Memory.m_pMemory[v21];
            if ( v25 != nullptr )
              *v25 = v20;
            v18 = ha;
            v19 = v33;
            v20->m_bInList = true;
          }
          v33 = ++v19;
        }
        while ( v19 < v18 );
        v16 = oi;
      }
    }
    v17->m_attribute->m_nFlags &= ~0x40000u;
    v26 = this->m_attrNodes.m_Buckets.m_Size;
    v28 = v16 + 1;
    v27 = HIWORD(v28);
    v28 = (unsigned __int16)v28;
    if ( v27 >= v26 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v27].m_Size; v28 >= *i; i += 5 )
    {
      ++v27;
      v28 = 0;
      if ( v27 >= v26 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440C60
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  char result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebp
  unsigned int v6; // ebx
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  bool v12; // zf
  IDmeOperator **v13; // eax
  char oi_3; // [esp+5h] [ebp-9h]
  unsigned int on; // [esp+6h] [ebp-8h]
  unsigned int v16; // [esp+Ah] [ebp-4h]

  m_Size = pOpNodes->m_Size;
  result = 0;
  v4 = 0;
  oi_3 = 0;
  v16 = m_Size;
  on = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          oi_3 = 1;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        for ( v5->m_state = TS_VISITING; v7 < v6; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            oi_3 = 1;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        v12 = operators->m_Size - v8 == 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 >= 0 && !v12 )
          memmove(dst: (unsigned __int8 *)&m_pMemory[v8 + 1], src: (unsigned __int8 *)&m_pMemory[v8], count: 4 * v11);
        v13 = &operators->m_Memory.m_pMemory[v8];
        if ( v13 != nullptr )
          *v13 = v5->m_operator;
        v4 = on;
        m_Size = v16;
        v5->m_state = TS_VISITED;
      }
      on = ++v4;
    }
    while ( v4 < m_Size );
    return oi_3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00440DD0
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  char OperatorOrdering; // al
  int m_Size; // esi
  char v5; // cl
  int v6; // eax
  int v7; // edx
  int v8; // esi
  IDmeOperator **m_pMemory; // ecx
  IDmeOperator *v10; // ebp
  char v12; // [esp+Bh] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  v5 = OperatorOrdering;
  v6 = m_Size / 2;
  v7 = 0;
  v12 = v5;
  if ( m_Size / 2 <= 0 )
    return v5;
  v8 = m_Size;
  do
  {
    m_pMemory = p_m_operators->m_Memory.m_pMemory;
    v10 = p_m_operators->m_Memory.m_pMemory[v7];
    m_pMemory[v7] = p_m_operators->m_Memory.m_pMemory[v8 - 1];
    m_pMemory[v8 - 1] = v10;
    ++v7;
    --v8;
  }
  while ( v7 < v6 );
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x00440E40
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, COperatorNode **pAttr)
{
  COperatorNode **v3; // edi
  CUtlHash<CAttributeNode *,bool (__cdecl*)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl*)(CAttributeNode * const &)> *p_m_attrNodes; // esi
  unsigned int v5; // eax
  CAttributeNode *v6; // esi
  CAttributeNode *v7; // eax
  CAttributeNode *src; // [esp+3Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+40h] [ebp-24h] BYREF
  CAttributeNode search; // [esp+44h] [ebp-20h] BYREF
  char v12; // [esp+60h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  pAttr = (COperatorNode **)&search.m_InputDependentOperators;
  p_m_attrNodes = &this->m_attrNodes;
  search.m_InputDependentOperators.m_Memory.m_pMemory = v3;
  memset(&search.m_InputDependentOperators.m_Memory.m_nAllocationCount, 0, 20);
  v12 = 0;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: p_m_attrNodes,
         src: (CAttributeNode *const *)&pAttr,
         &pBucket,
         pIndex: (int *)&search) == 0
    || (v5 = (int)search.m_attribute | (pBucket << 16)) == -1 )
  {
    src = nullptr;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CDependencyGraph::FindAttrNode_Alloc",
      a3: 1,
      a4: "Unaccounted",
      a5: false,
      a6: 0);
    v7 = (CAttributeNode *)CMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v7 != nullptr )
    {
      v7->m_attribute = nullptr;
      v7->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v7->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v7->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v7->m_InputDependentOperators.m_Size = 0;
      v7->m_InputDependentOperators.m_pElements = nullptr;
      v7->m_bIsOutputToOperator = false;
    }
    src = v7;
    v7->m_attribute = (CDmAttribute *)v3;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CDependencyGraph::FindAttrNode_Alloc2",
      a3: 1,
      a4: "Unaccounted",
      a5: false,
      a6: 0);
    CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::Insert(
      this: p_m_attrNodes,
      (unsigned int)&src);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    v6 = src;
  }
  else
  {
    v6 = p_m_attrNodes->m_Buckets.m_Memory.m_pMemory[HIWORD(v5)].m_Memory.m_pMemory[LOWORD(search.m_attribute)];
  }
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&search.m_InputDependentOperators.m_Memory.m_nAllocationCount);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00440F80
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  int m_Size; // ebp
  int i; // esi
  COperatorNode *v4; // edi
  int v5; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int j; // edi
  CAttributeNode *v10; // esi
  bool v11; // sf
  COperatorNode **m_pMemory; // eax
  int v13; // edx
  signed int v14; // eax
  int v15; // ecx
  int *v16; // esi
  int v17; // edx
  int v18; // ecx
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *v19; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  m_Size = this->m_opNodes.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[i];
    if ( v4 != nullptr )
    {
      CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v4->m_OutputAttributes);
      free(pMem: v4);
    }
  }
  v5 = this->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( v5 <= 0 )
  {
LABEL_9:
    v8 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= v5 )
        goto LABEL_9;
    }
    v8 = v6 << 16;
  }
  for ( j = v8; j != -1; j = v15 | (v14 << 16) )
  {
    v10 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(j)].m_Memory.m_pMemory[(unsigned __int16)j];
    if ( v10 != nullptr )
    {
      v11 = v10->m_InputDependentOperators.m_Memory.m_nGrowSize < 0;
      v10->m_InputDependentOperators.m_Size = 0;
      if ( !v11 )
      {
        if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
          v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
        }
        v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      }
      v11 = v10->m_InputDependentOperators.m_Memory.m_nGrowSize < 0;
      m_pMemory = v10->m_InputDependentOperators.m_Memory.m_pMemory;
      v10->m_InputDependentOperators.m_pElements = m_pMemory;
      if ( !v11 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
        }
        v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      }
    }
    CMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
    v13 = this->m_attrNodes.m_Buckets.m_Size;
    v14 = (j + 1) >> 16;
    v15 = (unsigned __int16)(j + 1);
    if ( v14 >= v13 )
      break;
    v16 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v14].m_Size;
    while ( v15 >= *v16 )
    {
      ++v14;
      v15 = 0;
      v16 += 5;
      if ( v14 >= v13 )
        goto LABEL_27;
    }
  }
LABEL_27:
  this->m_opRoots.m_Size = 0;
  this->m_opNodes.m_Size = 0;
  v17 = this->m_attrNodes.m_Buckets.m_Size;
  if ( v17 > 0 )
  {
    v18 = 0;
    do
    {
      v19 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v18++];
      --v17;
      v19->m_Size = 0;
    }
    while ( v17 != 0 );
  }
  this->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00441160
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebp
  CDependencyGraph *v3; // esi
  int m_pElements; // ebx
  IDmeOperator *const *m_nAllocationCount; // edi
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  int v9; // esi
  int v10; // eax
  int v11; // esi
  bool v12; // zf
  int v13; // edx
  int *p_m_opNodes; // esi
  int v15; // eax
  IMemAlloc_vtbl *v16; // edx
  int v17; // eax
  CDmAttribute **v18; // eax
  int v19; // ebx
  _DWORD *v20; // eax
  CAttributeNode *AttrNode; // esi
  int m_Size; // edi
  int v23; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_InputDependentOperators; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v26; // eax
  int *v27; // eax
  int v28; // ebx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v29; // edi
  CAttributeNode *v30; // ebp
  CUtlSymbolTable::StringPool_t **v31; // esi
  int v32; // eax
  CUtlSymbolTable::StringPool_t **v33; // ecx
  int v34; // eax
  CAttributeNode **v35; // eax
  IDmeOperator **v36; // eax
  IDmeOperator **v37; // esi
  int v38; // ebp
  int v39; // eax
  IDmeOperator **v40; // eax
  unsigned __int16 v41; // ax
  unsigned __int16 v42; // dx
  unsigned __int16 v43; // cx
  int v44; // esi
  int v45; // eax
  int v46; // esi
  int v47; // edx
  TraversalState_t m_state; // esi
  CAttributeNode **v49; // eax
  int *p_m_Size; // edi
  int v51; // ecx
  int v52; // eax
  int *v53; // eax
  IDmeOperator **v54; // eax
  IDmeOperator *pOperator; // [esp+20h] [ebp-60h] BYREF
  IDmeOperator *search; // [esp+24h] [ebp-5Ch] BYREF
  COperatorNode *pOpNode; // [esp+28h] [ebp-58h]
  int an; // [esp+2Ch] [ebp-54h]
  int on; // [esp+30h] [ebp-50h]
  int oi; // [esp+34h] [ebp-4Ch]
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+38h] [ebp-48h] BYREF
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > actualOperators; // [esp+4Ch] [ebp-34h] BYREF
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+60h] [ebp-20h] BYREF

  v2 = 0;
  v3 = this;
  pOpNode = (COperatorNode *)this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  memset(&attrs.m_Memory.m_nAllocationCount, 0, 16);
  memset((void *)&actualOperators, 0, sizeof(actualOperators));
  operatorDict.m_LessFunc = nullptr;
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int>>::operator=(
    this: (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)&actualOperators.m_Memory.m_nAllocationCount,
    other: operators);
  m_pElements = (int)actualOperators.m_pElements;
  oi = (int)actualOperators.m_pElements;
  operators = (const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)CDefOps<CDmAttribute *>::LessFunc;
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>(
    this: (CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *)&operatorDict.m_Elements,
    growSize: 0,
    initSize: 2 * (int)actualOperators.m_pElements,
    lessfunc: (bool (__cdecl **)(CDmAttribute *const *, CDmAttribute *const *))&operators);
  if ( m_pElements > 0 )
  {
    m_nAllocationCount = (IDmeOperator *const *)actualOperators.m_Memory.m_nAllocationCount;
    for ( on = m_pElements; on != 0; --on )
    {
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: (CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *)&operatorDict.m_Elements,
        insert: m_nAllocationCount,
        parent: (unsigned __int16 *)&pOperator,
        leftchild: (bool *)&operators);
      v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict.m_Elements);
      v7 = (unsigned __int16)pOperator;
      v8 = v6;
      v9 = 3 * v6;
      v10 = operatorDict.m_Elements.m_nAllocationCount;
      v11 = 4 * v9;
      v12 = (_WORD)pOperator == 0xFFFF;
      *(_WORD *)(v11 + operatorDict.m_Elements.m_nAllocationCount + 4) = (_WORD)pOperator;
      *(_WORD *)(v11 + v10 + 2) = -1;
      *(_WORD *)(v11 + v10) = -1;
      *(_WORD *)(v11 + v10 + 6) = 0;
      if ( v12 )
      {
        operatorDict.m_FirstFree = v8;
      }
      else
      {
        v13 = 3 * v7;
        if ( (_BYTE)operators != 0 )
          *(_WORD *)(v10 + 4 * v13) = v8;
        else
          *(_WORD *)(v10 + 4 * v13 + 2) = v8;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: (CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *)&operatorDict.m_Elements,
        elem: v8);
      ++operatorDict.m_LastAlloc.index;
      if ( v11 + operatorDict.m_Elements.m_nAllocationCount != -8 )
        *(IDmeOperator **)(v11 + operatorDict.m_Elements.m_nAllocationCount + 8) = *m_nAllocationCount;
      ++m_nAllocationCount;
    }
    v3 = (CDependencyGraph *)pOpNode;
  }
  p_m_opNodes = (int *)&v3->m_opNodes;
  if ( p_m_opNodes[1] < m_pElements && p_m_opNodes[2] >= 0 )
  {
    v15 = *p_m_opNodes;
    v12 = *p_m_opNodes == 0;
    p_m_opNodes[1] = m_pElements;
    v16 = _g_pMemAlloc->__vftable;
    if ( v12 )
      v17 = ((int (__stdcall *)(int))v16->Alloc_2)(a1: 4 * m_pElements);
    else
      v17 = ((int (__stdcall *)(int, int))v16->Realloc_2)(a1: v15, a2: 4 * m_pElements);
    *p_m_opNodes = v17;
  }
  p_m_opNodes[4] = *p_m_opNodes;
  v18 = nullptr;
  attrs.m_Memory.m_pMemory = nullptr;
  if ( m_pElements > 0 )
  {
    do
    {
      v19 = *(_DWORD *)(actualOperators.m_Memory.m_nAllocationCount + 4 * (_DWORD)v18);
      if ( v19 != 0 )
      {
        v20 = operator new(nSize: 0x20u);
        if ( v20 != nullptr )
        {
          *v20 = 0;
          v20[1] = v19;
          v20[2] = 0;
          v20[3] = 0;
          v20[4] = 0;
          v20[5] = 0;
          v20[6] = 0;
          *((_BYTE *)v20 + 28) = 0;
          an = (int)v20;
        }
        else
        {
          an = 0;
        }
        attrs.m_pElements = nullptr;
        (*(void (__thiscall **)(int, int *))(*(_DWORD *)v19 + 8))(a1: v19, a2: &attrs.m_Memory.m_nAllocationCount);
        on = (int)attrs.m_pElements;
        if ( (int)attrs.m_pElements > 0 )
        {
          do
          {
            AttrNode = CDependencyGraph::FindAttrNode(
                         this: (CDependencyGraph *)pOpNode,
                         pAttr: *(COperatorNode ***)(attrs.m_Memory.m_nAllocationCount + 4 * v2));
            m_Size = AttrNode->m_InputDependentOperators.m_Size;
            v23 = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
            p_m_InputDependentOperators = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators;
            if ( m_Size + 1 > v23 )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_InputDependentOperators, num: m_Size - v23 + 1);
            ++p_m_InputDependentOperators[1].m_pMemory;
            m_pMemory = p_m_InputDependentOperators->m_pMemory;
            v26 = (int)p_m_InputDependentOperators[1].m_pMemory - m_Size - 1;
            v12 = (CUtlSymbolTable::StringPool_t **)((char *)p_m_InputDependentOperators[1].m_pMemory - m_Size) == (CUtlSymbolTable::StringPool_t **)1;
            p_m_InputDependentOperators[1].m_nAllocationCount = (int)p_m_InputDependentOperators->m_pMemory;
            if ( v26 >= 0 && !v12 )
              memmove(
                dst: (unsigned __int8 *)&m_pMemory[m_Size + 1],
                src: (unsigned __int8 *)&m_pMemory[m_Size],
                count: 4 * v26);
            v27 = (int *)&p_m_InputDependentOperators->m_pMemory[m_Size];
            if ( v27 != nullptr )
              *v27 = an;
            ++v2;
          }
          while ( v2 < on );
        }
        attrs.m_pElements = nullptr;
        (*(void (__thiscall **)(int, int *))(*(_DWORD *)v19 + 12))(a1: v19, a2: &attrs.m_Memory.m_nAllocationCount);
        v28 = 0;
        on = (int)attrs.m_pElements;
        if ( (int)attrs.m_pElements > 0 )
        {
          v29 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(an + 8);
          do
          {
            v30 = CDependencyGraph::FindAttrNode(
                    this: (CDependencyGraph *)pOpNode,
                    pAttr: *(COperatorNode ***)(attrs.m_Memory.m_nAllocationCount + 4 * v28));
            v30->m_bIsOutputToOperator = true;
            v31 = v29[1].m_pMemory;
            v32 = v29->m_nAllocationCount;
            if ( (int)v31 + 1 > v32 )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v29, num: (int)v31 - v32 + 1);
            ++v29[1].m_pMemory;
            v33 = v29->m_pMemory;
            v34 = (char *)v29[1].m_pMemory - (char *)v31 - 1;
            v12 = (char *)v29[1].m_pMemory - (char *)v31 == 1;
            v29[1].m_nAllocationCount = (int)v29->m_pMemory;
            if ( v34 >= 0 && !v12 )
              memmove(
                dst: (unsigned __int8 *)&v33[(_DWORD)v31 + 1],
                src: (unsigned __int8 *)&v33[(_DWORD)v31],
                count: 4 * v34);
            v35 = (CAttributeNode **)&v29->m_pMemory[(_DWORD)v31];
            if ( v35 != nullptr )
              *v35 = v30;
            search = (IDmeOperator *)__RTDynamicCast(
                                       inptr: v30->m_attribute->m_pOwner,
                                       VfDelta: 0,
                                       SrcType: &CDmElement `RTTI Type Descriptor',
                                       TargetType: &IDmeOperator `RTTI Type Descriptor',
                                       isReference: 0);
            if ( search != nullptr
              && CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Find(
                   this: (CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *)&operatorDict.m_Elements,
                   &search) == 0xFFFF )
            {
              v36 = actualOperators.m_pElements;
              v37 = actualOperators.m_pElements;
              if ( (int)actualOperators.m_pElements + 1 > actualOperators.m_Memory.m_nGrowSize )
              {
                CUtlMemory<IDmFormatUpdater *,int>::Grow(
                  this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&actualOperators.m_Memory.m_nAllocationCount,
                  num: (int)actualOperators.m_pElements - actualOperators.m_Memory.m_nGrowSize + 1);
                v36 = actualOperators.m_pElements;
              }
              v38 = actualOperators.m_Memory.m_nAllocationCount;
              actualOperators.m_pElements = (IDmeOperator **)((char *)v36 + 1);
              v39 = (char *)v36 - (char *)v37;
              operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))actualOperators.m_Memory.m_nAllocationCount;
              if ( v39 > 0 )
                memmove(
                  dst: (unsigned __int8 *)(actualOperators.m_Memory.m_nAllocationCount + 4 * (_DWORD)v37 + 4),
                  src: (unsigned __int8 *)(actualOperators.m_Memory.m_nAllocationCount + 4 * (_DWORD)v37),
                  count: 4 * v39);
              v40 = (IDmeOperator **)(v38 + 4 * (_DWORD)v37);
              if ( v40 != nullptr )
                *v40 = search;
              CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
                this: (CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *)&operatorDict.m_Elements,
                insert: &search,
                parent: (unsigned __int16 *)&pOperator,
                leftchild: (bool *)&operators);
              v41 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict.m_Elements);
              v42 = (unsigned __int16)pOperator;
              v43 = v41;
              v44 = 3 * v41;
              v45 = operatorDict.m_Elements.m_nAllocationCount;
              v46 = 4 * v44;
              v12 = (_WORD)pOperator == 0xFFFF;
              *(_WORD *)(operatorDict.m_Elements.m_nAllocationCount + v46 + 4) = (_WORD)pOperator;
              *(_WORD *)(v45 + v46 + 2) = -1;
              *(_WORD *)(v45 + v46) = -1;
              *(_WORD *)(v45 + v46 + 6) = 0;
              if ( v12 )
              {
                operatorDict.m_FirstFree = v43;
              }
              else
              {
                v47 = 3 * v42;
                if ( (_BYTE)operators != 0 )
                  *(_WORD *)(v45 + 4 * v47) = v43;
                else
                  *(_WORD *)(v45 + 4 * v47 + 2) = v43;
              }
              CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
                this: (CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *)&operatorDict.m_Elements,
                elem: v43);
              ++operatorDict.m_LastAlloc.index;
              if ( operatorDict.m_Elements.m_nAllocationCount + v46 != -8 )
                *(_DWORD *)(operatorDict.m_Elements.m_nAllocationCount + v46 + 8) = search;
              ++oi;
            }
            ++v28;
          }
          while ( v28 < on );
        }
        m_state = pOpNode[1].m_state;
        v49 = pOpNode->m_OutputAttributes.m_pElements;
        p_m_Size = &pOpNode->m_OutputAttributes.m_Size;
        if ( m_state + 1 > (int)v49 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&pOpNode->m_OutputAttributes.m_Size,
            num: m_state - (_DWORD)v49 + 1);
        ++p_m_Size[3];
        v51 = *p_m_Size;
        v52 = p_m_Size[3] - m_state - 1;
        v12 = p_m_Size[3] - m_state == 1;
        p_m_Size[4] = *p_m_Size;
        if ( v52 >= 0 && !v12 )
          memmove(
            dst: (unsigned __int8 *)(v51 + 4 * m_state + 4),
            src: (unsigned __int8 *)(v51 + 4 * m_state),
            count: 4 * v52);
        v53 = (int *)(*p_m_Size + 4 * m_state);
        v2 = 0;
        if ( v53 != nullptr )
          *v53 = an;
      }
      v18 = ++attrs.m_Memory.m_pMemory;
    }
    while ( (int)attrs.m_Memory.m_pMemory < oi );
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *)&operatorDict.m_Elements);
  if ( *(int *)&operatorDict.m_Root >= 0 && operatorDict.m_Elements.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)operatorDict.m_Elements.m_nAllocationCount);
  if ( actualOperators.m_Size >= 0 && actualOperators.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)actualOperators.m_Memory.m_nAllocationCount);
  v54 = (IDmeOperator **)attrs.m_Memory.m_nAllocationCount;
  attrs.m_pElements = nullptr;
  if ( attrs.m_Size >= 0 )
  {
    if ( attrs.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)attrs.m_Memory.m_nAllocationCount);
      v54 = nullptr;
      attrs.m_Memory.m_nAllocationCount = 0;
    }
    attrs.m_Memory.m_nGrowSize = 0;
  }
  actualOperators.m_Memory.m_pMemory = v54;
  if ( attrs.m_Size >= 0 )
  {
    if ( v54 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54);
      attrs.m_Memory.m_nAllocationCount = 0;
    }
    attrs.m_Memory.m_nGrowSize = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x004416F0
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_opNodes);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00441730
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlHash<CAttributeNode *,bool (__cdecl*)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl*)(CAttributeNode * const &)> *p_m_attrNodes; // esi
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  p_m_attrNodes = &this->m_attrNodes;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::InsertMultipleBefore(
    this: &p_m_attrNodes->m_Buckets,
    elem: p_m_attrNodes->m_Buckets.m_Size,
    num: 4096,
    pToInsert: nullptr);
  for ( i = 0; i < 4096; ++i )
  {
    p_m_attrNodes->m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    p_m_attrNodes->m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  p_m_attrNodes->m_bPowerOfTwo = true;
  p_m_attrNodes->m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043FD30
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<class IDmeOperator __near *,unsigned short,bool (*)(class IDmeOperator __near * const __near &,class IDmeOperator __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<IDmeOperator *,unsigned short> *__thiscall CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)&`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00446280
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x004462A0
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x00446D50
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00446F50
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447050
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x004470E0
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = (DmElementHandle_t)&search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( !CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
          this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
          &src,
          &pBucket,
          pIndex: (int *)&pAttr)
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( !CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
            this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
            src: (const DmElementHandle_t *)&pAttrNode,
            pBucket: (unsigned int *)&pAttr,
            pIndex: (int *)&pBucket) )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00447230
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00447400
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00447820
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004478C0
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0044B240
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x0044B260
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0044BD90
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044BF90
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044C090
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x0044C120
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = (DmElementHandle_t)&search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( !CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
          this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
          &src,
          &pBucket,
          pIndex: (int *)&pAttr)
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( !CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
            this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
            src: (const DmElementHandle_t *)&pAttrNode,
            pBucket: (unsigned int *)&pAttr,
            pIndex: (int *)&pBucket) )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0044C270
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0044C440
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0044C860
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044C900
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004502D0
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x004502F0
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x00450EA0
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004510A0
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004511A0
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x00451230
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<vgui::TreeNode *,int> *v9; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  CAttributeNode *src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = &search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: &this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: &this->m_attrNodes,
           src: &pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<vgui::TreeNode *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00451380
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x004515B0
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x004519D0
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00451A70
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0044BF50
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x0044BF70
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0044CAA0
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CCA0
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044CDA0
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x0044CE30
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = (DmElementHandle_t)&search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
           src: (const DmElementHandle_t *)&pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0044CF80
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0044D1B0
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0044D5D0
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044D670
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004BAB80
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x004BABA0
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x004BB650
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB850
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BB950
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x004BB9E0
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  CAttributeNode *src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = &search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: &this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: &this->m_attrNodes,
           src: &pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004BBB30
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x004BBD00
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x004BC120
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVectorAuto<s_animation_t *>,CUtlMemory<CUtlVectorAuto<s_animation_t *>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BC1C0
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_opNodes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x004567E0
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00456800
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x004572B0
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
                num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004574B0
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004575B0
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x00457640
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = (DmElementHandle_t)&search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
           src: (const DmElementHandle_t *)&pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00457790
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00457960
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v49->m_opNodes,
          num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00457D80
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00457E20
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0052A4C0
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x0052A4E0
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0052AFA0
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  unsigned int m_Size; // edi
  unsigned int v3; // ebx
  COperatorNode *v4; // ebp
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  bool v10; // zf
  COperatorNode **v11; // eax
  int v12; // edx
  int v13; // eax
  int *p_m_Size; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  CAttributeNode *v17; // ebp
  unsigned int v18; // edx
  unsigned int v19; // eax
  COperatorNode *v20; // ebx
  int v21; // edi
  int v22; // eax
  COperatorNode **v23; // ecx
  int v24; // eax
  COperatorNode **v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // ecx
  int *i; // edi
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int ha; // [esp+10h] [ebp-Ch]
  unsigned int oi; // [esp+14h] [ebp-8h]
  unsigned int v33; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  for ( h = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      v10 = this->m_opRoots.m_Size - v6 == 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 >= 0 && !v10 )
        _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v6 + 1], src: (unsigned __int8 *)&m_pMemory[v6], count: 4 * v9);
      v11 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v11 != nullptr )
        *v11 = v4;
      m_Size = h;
      v4->m_bInList = true;
    }
  }
  v12 = this->m_attrNodes.m_Buckets.m_Size;
  v13 = 0;
  if ( v12 <= 0 )
  {
LABEL_15:
    v15 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v13;
      p_m_Size += 5;
      if ( v13 >= v12 )
        goto LABEL_15;
    }
    v15 = v13 << 16;
  }
  for ( oi = v15; oi != -1; oi = v28 | (v27 << 16) )
  {
    v16 = oi;
    v17 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(oi)].m_Memory.m_pMemory[(unsigned __int16)oi];
    if ( !v17->m_bIsOutputToOperator && (v17->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v18 = v17->m_InputDependentOperators.m_Size;
      v19 = 0;
      ha = v18;
      v33 = 0;
      if ( v18 != 0 )
      {
        do
        {
          v20 = v17->m_InputDependentOperators.m_Memory.m_pMemory[v19];
          if ( !v20->m_bInList )
          {
            v21 = this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v21 + 1 > v22 )
              CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v21 - v22 + 1);
            ++this->m_opRoots.m_Size;
            v23 = this->m_opRoots.m_Memory.m_pMemory;
            v24 = this->m_opRoots.m_Size - v21 - 1;
            v10 = this->m_opRoots.m_Size - v21 == 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v24 >= 0 && !v10 )
              _V_memmove(dest: (unsigned __int8 *)&v23[v21 + 1], src: (unsigned __int8 *)&v23[v21], count: 4 * v24);
            v25 = &this->m_opRoots.m_Memory.m_pMemory[v21];
            if ( v25 != nullptr )
              *v25 = v20;
            v18 = ha;
            v19 = v33;
            v20->m_bInList = true;
          }
          v33 = ++v19;
        }
        while ( v19 < v18 );
        v16 = oi;
      }
    }
    v17->m_attribute->m_nFlags &= ~0x4000u;
    v26 = this->m_attrNodes.m_Buckets.m_Size;
    v28 = v16 + 1;
    v27 = HIWORD(v28);
    v28 = (unsigned __int16)v28;
    if ( v27 >= v26 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v27].m_Size; v28 >= *i; i += 5 )
    {
      ++v27;
      v28 = 0;
      if ( v27 >= v26 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052B1A0
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  char result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebp
  unsigned int v6; // ebx
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  bool v12; // zf
  IDmeOperator **v13; // eax
  char oi_3; // [esp+5h] [ebp-9h]
  unsigned int on; // [esp+6h] [ebp-8h]
  unsigned int v16; // [esp+Ah] [ebp-4h]

  m_Size = pOpNodes->m_Size;
  result = 0;
  v4 = 0;
  oi_3 = 0;
  v16 = m_Size;
  on = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          oi_3 = 1;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        for ( v5->m_state = TS_VISITING; v7 < v6; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            oi_3 = 1;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        v12 = operators->m_Size - v8 == 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 >= 0 && !v12 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[v8 + 1],
            src: (unsigned __int8 *)&m_pMemory[v8],
            count: 4 * v11);
        v13 = &operators->m_Memory.m_pMemory[v8];
        if ( v13 != nullptr )
          *v13 = v5->m_operator;
        v4 = on;
        m_Size = v16;
        v5->m_state = TS_VISITED;
      }
      on = ++v4;
    }
    while ( v4 < m_Size );
    return oi_3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052B2B0
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  char OperatorOrdering; // al
  int m_Size; // ebp
  char v5; // bl
  int v6; // eax
  int v7; // edx
  int v8; // esi
  IDmeOperator **m_pMemory; // ecx
  IDmeOperator *v10; // ebp
  int i; // esi
  int v13; // [esp+14h] [ebp-4h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  v5 = OperatorOrdering;
  v6 = m_Size / 2;
  v7 = 0;
  v13 = m_Size;
  if ( m_Size / 2 > 0 )
  {
    v8 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v7];
      m_pMemory[v7] = p_m_operators->m_Memory.m_pMemory[v8 - 1];
      m_pMemory[v8 - 1] = v10;
      ++v7;
      --v8;
    }
    while ( v7 < v6 );
    m_Size = v13;
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0052B340
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, COperatorNode **pAttr)
{
  COperatorNode **v3; // edi
  CUtlHash<CAttributeNode *,bool (__cdecl*)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl*)(CAttributeNode * const &)> *p_m_attrNodes; // esi
  unsigned int v5; // eax
  CAttributeNode *v6; // esi
  CAttributeNode *v7; // eax
  CAttributeNode *v9; // [esp+14h] [ebp-28h] BYREF
  CAttributeNode *src; // [esp+18h] [ebp-24h] BYREF
  CAttributeNode search; // [esp+1Ch] [ebp-20h] BYREF
  char v12; // [esp+38h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = (CAttributeNode *)&search.m_InputDependentOperators;
  p_m_attrNodes = &this->m_attrNodes;
  search.m_InputDependentOperators.m_Memory.m_pMemory = pAttr;
  memset(&search.m_InputDependentOperators.m_Memory.m_nAllocationCount, 0, 20);
  v12 = 0;
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: p_m_attrNodes,
         &src,
         pBucket: (unsigned int *)&search,
         pIndex: (int *)&pAttr) == 0
    || (v5 = (unsigned int)pAttr | ((int)search.m_attribute << 16)) == -1 )
  {
    v9 = nullptr;
    v7 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v7 != nullptr )
    {
      v7->m_attribute = nullptr;
      v7->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v7->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v7->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v7->m_InputDependentOperators.m_Size = 0;
      v7->m_InputDependentOperators.m_pElements = nullptr;
      v7->m_bIsOutputToOperator = false;
    }
    v9 = v7;
    v7->m_attribute = (CDmAttribute *)v3;
    CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::Insert(
      this: p_m_attrNodes,
      src: (unsigned int)&v9);
    v6 = v9;
  }
  else
  {
    v6 = p_m_attrNodes->m_Buckets.m_Memory.m_pMemory[HIWORD(v5)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&search.m_InputDependentOperators.m_Memory.m_nAllocationCount);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0052B4A0
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  int m_Size; // ebp
  int i; // esi
  COperatorNode *v4; // edi
  int v5; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int j; // edi
  CAttributeNode *v10; // esi
  bool v11; // sf
  COperatorNode **m_pMemory; // eax
  int v13; // edx
  signed int v14; // eax
  int v15; // ecx
  int *v16; // esi
  int v17; // edx
  int v18; // ecx
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *v19; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  m_Size = this->m_opNodes.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[i];
    if ( v4 != nullptr )
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v4->m_OutputAttributes);
    CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v4);
  }
  v5 = this->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( v5 <= 0 )
  {
LABEL_9:
    v8 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= v5 )
        goto LABEL_9;
    }
    v8 = v6 << 16;
  }
  for ( j = v8; j != -1; j = v15 | (v14 << 16) )
  {
    v10 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(j)].m_Memory.m_pMemory[(unsigned __int16)j];
    if ( v10 != nullptr )
    {
      v11 = v10->m_InputDependentOperators.m_Memory.m_nGrowSize < 0;
      v10->m_InputDependentOperators.m_Size = 0;
      if ( !v11 )
      {
        if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
          v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
        }
        v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      }
      v11 = v10->m_InputDependentOperators.m_Memory.m_nGrowSize < 0;
      m_pMemory = v10->m_InputDependentOperators.m_Memory.m_pMemory;
      v10->m_InputDependentOperators.m_pElements = m_pMemory;
      if ( !v11 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
        }
        v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      }
    }
    CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
    v13 = this->m_attrNodes.m_Buckets.m_Size;
    v14 = (j + 1) >> 16;
    v15 = (unsigned __int16)(j + 1);
    if ( v14 >= v13 )
      break;
    v16 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v14].m_Size;
    while ( v15 >= *v16 )
    {
      ++v14;
      v15 = 0;
      v16 += 5;
      if ( v14 >= v13 )
        goto LABEL_27;
    }
  }
LABEL_27:
  this->m_opRoots.m_Size = 0;
  this->m_opNodes.m_Size = 0;
  v17 = this->m_attrNodes.m_Buckets.m_Size;
  if ( v17 > 0 )
  {
    v18 = 0;
    do
    {
      v19 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v18++];
      --v17;
      v19->m_Size = 0;
    }
    while ( v17 != 0 );
  }
  this->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0052B620
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  int m_Size; // edi
  int i; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // esi
  COperatorNode **m_pMemory; // eax
  bool v8; // zf
  IMemAlloc_vtbl *v9; // edx
  int v10; // eax
  CDmAttribute **v11; // eax
  IDmeOperator *v12; // ebp
  void **v13; // eax
  void **v14; // esi
  CAttributeNode *AttrNode; // esi
  int v16; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_InputDependentOperators; // esi
  S3RGBA *v19; // ecx
  int v20; // eax
  int *v21; // eax
  CUtlMemory<S3RGBA,int> *v22; // esi
  CAttributeNode *v23; // ebp
  S3RGBA *v24; // edi
  int v25; // eax
  S3RGBA *v26; // ecx
  int v27; // eax
  CAttributeNode **v28; // eax
  int v29; // esi
  int v30; // eax
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *v31; // edi
  COperatorNode **v32; // ecx
  int v33; // eax
  COperatorNode **v34; // ecx
  int *v35; // esi
  bool (__cdecl *v36)(IDmeOperator *const *, IDmeOperator *const *); // eax
  CDmAttribute **m_pElements; // [esp+20h] [ebp-44h]
  CDmAttribute **v38; // [esp+20h] [ebp-44h]
  int on; // [esp+28h] [ebp-3Ch]
  int oi; // [esp+2Ch] [ebp-38h]
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+30h] [ebp-34h] BYREF
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+44h] [ebp-20h] BYREF

  v2 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this);
  m_Size = operators->m_Size;
  memset(&attrs.m_Memory.m_nAllocationCount, 0, 16);
  operatorDict.m_LessFunc = nullptr;
  oi = m_Size;
  attrs.m_Memory.m_pMemory = (CDmAttribute **)CDefOps<CDmAttribute *>::LessFunc;
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>(
    this: (CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *)&operatorDict.m_Elements,
    growSize: 0,
    initSize: 2 * m_Size,
    lessfunc: (bool (__cdecl **)(CDmAttribute *const *, CDmAttribute *const *))&attrs);
  for ( i = 0; i < m_Size; ++i )
    CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Insert(
      this: (CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *)&operatorDict.m_Elements,
      insert: &operators->m_Memory.m_pMemory[i]);
  p_m_opNodes = &this->m_opNodes;
  if ( this->m_opNodes.m_Memory.m_nAllocationCount < m_Size && this->m_opNodes.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_opNodes->m_Memory.m_pMemory;
    v8 = p_m_opNodes->m_Memory.m_pMemory == nullptr;
    this->m_opNodes.m_Memory.m_nAllocationCount = m_Size;
    v9 = _g_pMemAlloc->__vftable;
    if ( v8 )
      v10 = ((int (__stdcall *)(int))v9->Alloc_2)(a1: 4 * m_Size);
    else
      v10 = ((int (__stdcall *)(COperatorNode **, int))v9->Realloc_2)(a1: m_pMemory, a2: 4 * m_Size);
    p_m_opNodes->m_Memory.m_pMemory = (COperatorNode **)v10;
  }
  v11 = nullptr;
  this->m_opNodes.m_pElements = this->m_opNodes.m_Memory.m_pMemory;
  for ( attrs.m_Memory.m_pMemory = nullptr; (int)attrs.m_Memory.m_pMemory < m_Size; v11 = ++attrs.m_Memory.m_pMemory )
  {
    v12 = operators->m_Memory.m_pMemory[(_DWORD)v11];
    if ( v12 != nullptr )
    {
      v13 = CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v14 = v13;
      on = (int)v13;
      if ( v13 != nullptr )
      {
        *v13 = nullptr;
        v13[1] = nullptr;
        v13[2] = nullptr;
        v13[3] = nullptr;
        v13[4] = nullptr;
        v13[5] = nullptr;
        v13[6] = nullptr;
        *((_BYTE *)v13 + 28) = 0;
      }
      v13[1] = v12;
      attrs.m_pElements = nullptr;
      v12->GetInputAttributes(
        this: v12,
        a2: (CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *)&attrs.m_Memory.m_nAllocationCount);
      m_pElements = attrs.m_pElements;
      if ( (int)attrs.m_pElements > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(
                       this,
                       pAttr: *(COperatorNode ***)(attrs.m_Memory.m_nAllocationCount + 4 * v2));
          v16 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          p_m_InputDependentOperators = (CUtlMemory<S3RGBA,int> *)&AttrNode->m_InputDependentOperators;
          if ( v16 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: p_m_InputDependentOperators,
              num: v16 - m_nAllocationCount + 1);
          ++p_m_InputDependentOperators[1].m_pMemory;
          v19 = p_m_InputDependentOperators->m_pMemory;
          v20 = (int)p_m_InputDependentOperators[1].m_pMemory - v16 - 1;
          v8 = (S3RGBA *)((char *)p_m_InputDependentOperators[1].m_pMemory - v16) == (S3RGBA *)1;
          p_m_InputDependentOperators[1].m_nAllocationCount = (int)p_m_InputDependentOperators->m_pMemory;
          if ( v20 >= 0 && !v8 )
            _V_memmove(dest: (unsigned __int8 *)&v19[v16 + 1], src: (unsigned __int8 *)&v19[v16], count: 4 * v20);
          v21 = (int *)&p_m_InputDependentOperators->m_pMemory[v16];
          if ( v21 != nullptr )
            *v21 = on;
          ++v2;
        }
        while ( v2 < (int)m_pElements );
        v14 = (void **)on;
        v2 = 0;
      }
      attrs.m_pElements = nullptr;
      v12->GetOutputAttributes(
        this: v12,
        a2: (CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *)&attrs.m_Memory.m_nAllocationCount);
      v38 = attrs.m_pElements;
      if ( (int)attrs.m_pElements > 0 )
      {
        v22 = (CUtlMemory<S3RGBA,int> *)(v14 + 2);
        do
        {
          v23 = CDependencyGraph::FindAttrNode(
                  this,
                  pAttr: *(COperatorNode ***)(attrs.m_Memory.m_nAllocationCount + 4 * v2));
          v23->m_bIsOutputToOperator = true;
          v24 = v22[1].m_pMemory;
          v25 = v22->m_nAllocationCount;
          if ( (int)&v24->g > v25 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v22, num: (int)(&v24->g - v25));
          ++v22[1].m_pMemory;
          v26 = v22->m_pMemory;
          v27 = (char *)v22[1].m_pMemory - (char *)v24 - 1;
          v8 = (char *)v22[1].m_pMemory - (char *)v24 == 1;
          v22[1].m_nAllocationCount = (int)v22->m_pMemory;
          if ( v27 >= 0 && !v8 )
            _V_memmove(
              dest: (unsigned __int8 *)&v26[(_DWORD)v24 + 1],
              src: (unsigned __int8 *)&v26[(_DWORD)v24],
              count: 4 * v27);
          v28 = (CAttributeNode **)&v22->m_pMemory[(_DWORD)v24];
          if ( v28 != nullptr )
            *v28 = v23;
          ++v2;
        }
        while ( v2 < (int)v38 );
      }
      v29 = this->m_opNodes.m_Size;
      v30 = this->m_opNodes.m_Memory.m_nAllocationCount;
      v31 = &this->m_opNodes;
      if ( v29 + 1 > v30 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_opNodes, num: v29 - v30 + 1);
      ++this->m_opNodes.m_Size;
      v32 = v31->m_Memory.m_pMemory;
      v33 = this->m_opNodes.m_Size - v29 - 1;
      v8 = this->m_opNodes.m_Size - v29 == 1;
      this->m_opNodes.m_pElements = this->m_opNodes.m_Memory.m_pMemory;
      if ( v33 >= 0 && !v8 )
        _V_memmove(dest: (unsigned __int8 *)&v32[v29 + 1], src: (unsigned __int8 *)&v32[v29], count: 4 * v33);
      v34 = v31->m_Memory.m_pMemory;
      m_Size = oi;
      v35 = (int *)&v34[v29];
      v2 = 0;
      if ( v35 != nullptr )
        *v35 = on;
    }
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *)&operatorDict.m_Elements);
  if ( *(int *)&operatorDict.m_Root >= 0 && operatorDict.m_Elements.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)operatorDict.m_Elements.m_nAllocationCount);
  v36 = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))attrs.m_Memory.m_nAllocationCount;
  attrs.m_pElements = nullptr;
  if ( attrs.m_Size >= 0 )
  {
    if ( attrs.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)attrs.m_Memory.m_nAllocationCount);
      v36 = nullptr;
      attrs.m_Memory.m_nAllocationCount = 0;
    }
    attrs.m_Memory.m_nGrowSize = 0;
  }
  operatorDict.m_LessFunc = v36;
  if ( attrs.m_Size >= 0 )
  {
    if ( v36 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v36);
      attrs.m_Memory.m_nAllocationCount = 0;
    }
    attrs.m_Memory.m_nGrowSize = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0052B9A0
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlHash<CAttributeNode *,bool (__cdecl*)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl*)(CAttributeNode * const &)> *p_m_attrNodes; // esi
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  p_m_attrNodes = &this->m_attrNodes;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)p_m_attrNodes,
    elem: p_m_attrNodes->m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    p_m_attrNodes->m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    p_m_attrNodes->m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  p_m_attrNodes->m_bPowerOfTwo = true;
  p_m_attrNodes->m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052BA40
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0054DB50
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x0054DB70
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x0054E6E0
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054E8E0
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0054E9E0
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x0054EA70
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<S3RGBA,int> *v9; // esi
  int m_nAllocationCount; // eax
  S3RGBA *v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  CAttributeNode *src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = &search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: &this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: &this->m_attrNodes,
           src: &pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<S3RGBA,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<HemiLightData_t *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0054EBC0
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0054EDF0
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  void **v21; // eax
  void **v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  void *v30; // edi
  _BYTE *v31; // eax
  char *v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        *v21 = nullptr;
        v21[1] = nullptr;
        v21[2] = nullptr;
        v21[3] = nullptr;
        v21[4] = nullptr;
        v21[5] = nullptr;
        v21[6] = nullptr;
        *((_BYTE *)v21 + 28) = 0;
      }
      v21[1] = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(void ***)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22[5];
        v31 = v22[3];
        if ( (int)((char *)v30 + 1) > (int)v31 )
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)(v22 + 2),
            num: (_BYTE *)v30 - v31 + 1);
        v22[5] = (char *)v22[5] + 1;
        v32 = (char *)v22[2];
        v33 = (_BYTE *)v22[5] - (_BYTE *)v30 - 1;
        v22[6] = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[4 * (_DWORD)v30 + 4], src: &v32[4 * (_DWORD)v30], count: 4 * v33);
        v34 = (CAttributeNode **)((char *)v22[2] + 4 * (_DWORD)v30);
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&v49->m_opNodes, num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x0054F210
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CVertVisit,CUtlMemory<CVertVisit,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0054F2B0
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&this->m_attrNodes);
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::~CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_opNodes);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10078C30
// Name: bool HashEntryCompareFunc(class CAttributeNode __near * const __near &,class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HashEntryCompareFunc(CAttributeNode *const *lhs, CAttributeNode *const *rhs)
{
  return **(_DWORD **)lhs == **(_DWORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x10078C50
// Name: unsigned int HashEntryKeyFunc(class CAttributeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl HashEntryKeyFunc(CAttributeNode *const *keyinfo)
{
  return **(_DWORD **)keyinfo >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x100798F0
// Name: private: void CDependencyGraph::FindRoots(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::FindRoots(CDependencyGraph *this)
{
  int m_Size; // eax
  unsigned int v3; // edi
  COperatorNode *v4; // ebx
  IDmeOperator *m_operator; // ecx
  int v6; // edi
  int m_nAllocationCount; // eax
  COperatorNode **m_pMemory; // ecx
  int v9; // eax
  COperatorNode **v10; // edi
  int v11; // edx
  int v12; // eax
  int *p_m_Size; // ecx
  int v14; // eax
  unsigned int v15; // edx
  CAttributeNode *v16; // ebx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  COperatorNode *v19; // edx
  int v20; // edi
  int v21; // eax
  COperatorNode **v22; // ecx
  int v23; // eax
  COperatorNode **v24; // edi
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int *i; // edi
  COperatorNode *pOpNode; // [esp+Ch] [ebp-10h]
  unsigned int h; // [esp+10h] [ebp-Ch]
  unsigned int on; // [esp+14h] [ebp-8h]
  unsigned int ona; // [esp+14h] [ebp-8h]
  unsigned int oi; // [esp+18h] [ebp-4h]
  unsigned int oia; // [esp+18h] [ebp-4h]

  m_Size = this->m_opNodes.m_Size;
  v3 = 0;
  this->m_opRoots.m_Size = 0;
  on = m_Size;
  for ( oi = 0; v3 < on; oi = v3 )
  {
    v4 = this->m_opNodes.m_Memory.m_pMemory[v3];
    m_operator = v4->m_operator;
    v4->m_bInList = false;
    v4->m_state = TS_NOT_VISITED;
    if ( m_operator->IsDirty(this: m_operator) != 0 )
    {
      v6 = this->m_opRoots.m_Size;
      m_nAllocationCount = this->m_opRoots.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v6 - m_nAllocationCount + 1);
      ++this->m_opRoots.m_Size;
      m_pMemory = this->m_opRoots.m_Memory.m_pMemory;
      v9 = this->m_opRoots.m_Size - v6 - 1;
      this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &this->m_opRoots.m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = v4;
      v3 = oi;
      v4->m_bInList = true;
    }
    ++v3;
  }
  v11 = this->m_attrNodes.m_Buckets.m_Size;
  v12 = 0;
  if ( v11 <= 0 )
  {
LABEL_15:
    v14 = -1;
  }
  else
  {
    p_m_Size = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v12;
      p_m_Size += 5;
      if ( v12 >= v11 )
        goto LABEL_15;
    }
    v14 = v12 << 16;
  }
  for ( h = v14; h != -1; h = v27 | (v26 << 16) )
  {
    v15 = h;
    v16 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
    if ( !v16->m_bIsOutputToOperator && (v16->m_attribute->m_nFlags & 0x4000) != 0 )
    {
      v17 = v16->m_InputDependentOperators.m_Size;
      v18 = 0;
      ona = v17;
      oia = 0;
      if ( v17 != 0 )
      {
        do
        {
          v19 = v16->m_InputDependentOperators.m_Memory.m_pMemory[v18];
          pOpNode = v19;
          if ( !v19->m_bInList )
          {
            v20 = this->m_opRoots.m_Size;
            v21 = this->m_opRoots.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v20 - v21 + 1);
              v19 = pOpNode;
            }
            ++this->m_opRoots.m_Size;
            v22 = this->m_opRoots.m_Memory.m_pMemory;
            v23 = this->m_opRoots.m_Size - v20 - 1;
            this->m_opRoots.m_pElements = this->m_opRoots.m_Memory.m_pMemory;
            if ( v23 > 0 )
            {
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
              v19 = pOpNode;
            }
            v24 = &this->m_opRoots.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = v19;
            v18 = oia;
            v17 = ona;
            v19->m_bInList = true;
          }
          oia = ++v18;
        }
        while ( v18 < v17 );
        v15 = h;
      }
    }
    v16->m_attribute->m_nFlags &= ~0x4000u;
    v27 = v15 + 1;
    v25 = this->m_attrNodes.m_Buckets.m_Size;
    v26 = HIWORD(v27);
    v27 = (unsigned __int16)v27;
    if ( v26 >= v25 )
      break;
    for ( i = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v26].m_Size; v27 >= *i; i += 5 )
    {
      ++v26;
      v27 = 0;
      if ( v26 >= v25 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079AF0
// Name: private: static bool CDependencyGraph::GetOperatorOrdering(class CUtlVector<struct COperatorNode __near *,class CUtlMemory<struct COperatorNode __near *,int>> __near &,class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDependencyGraph::GetOperatorOrdering(
        CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *pOpNodes,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  unsigned int m_Size; // edx
  bool result; // al
  unsigned int v4; // ecx
  COperatorNode *v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // edi
  int v8; // edi
  int m_nAllocationCount; // eax
  IDmeOperator **m_pMemory; // ecx
  int v11; // eax
  IDmeOperator **v12; // edi
  unsigned int on; // [esp+0h] [ebp-10h]
  unsigned int an; // [esp+4h] [ebp-Ch]
  unsigned int oi; // [esp+8h] [ebp-8h]
  bool cycle; // [esp+Fh] [ebp-1h]

  m_Size = pOpNodes->m_Size;
  result = false;
  v4 = 0;
  cycle = false;
  on = m_Size;
  oi = 0;
  if ( m_Size != 0 )
  {
    do
    {
      v5 = pOpNodes->m_Memory.m_pMemory[v4];
      if ( v5->m_state != TS_NOT_VISITED )
      {
        if ( v5->m_state == TS_VISITING )
          cycle = true;
      }
      else
      {
        v6 = v5->m_OutputAttributes.m_Size;
        v7 = 0;
        v5->m_state = TS_VISITING;
        for ( an = v6; v7 < an; ++v7 )
        {
          if ( CDependencyGraph::GetOperatorOrdering(
                 pOpNodes: &v5->m_OutputAttributes.m_Memory.m_pMemory[v7]->m_InputDependentOperators,
                 operators) )
          {
            cycle = true;
          }
        }
        v8 = operators->m_Size;
        m_nAllocationCount = operators->m_Memory.m_nAllocationCount;
        if ( v8 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)operators,
            num: v8 - m_nAllocationCount + 1);
        ++operators->m_Size;
        m_pMemory = operators->m_Memory.m_pMemory;
        v11 = operators->m_Size - v8 - 1;
        operators->m_pElements = operators->m_Memory.m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v11);
        v12 = &operators->m_Memory.m_pMemory[v8];
        if ( v12 != nullptr )
          *v12 = v5->m_operator;
        v4 = oi;
        m_Size = on;
        v5->m_state = TS_VISITED;
      }
      oi = ++v4;
    }
    while ( v4 < m_Size );
    return cycle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079BF0
// Name: public: bool CDependencyGraph::CullAndSortOperators(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDependencyGraph::CullAndSortOperators(CDependencyGraph *this)
{
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *p_m_operators; // edi
  bool OperatorOrdering; // al
  int m_Size; // ebx
  int v5; // edx
  int v6; // esi
  IDmeOperator **m_pMemory; // ecx
  int i; // esi
  IDmeOperator *v10; // [esp+10h] [ebp-8h]
  bool cycle; // [esp+17h] [ebp-1h]

  CDependencyGraph::FindRoots(this);
  p_m_operators = &this->m_operators;
  this->m_operators.m_Size = 0;
  OperatorOrdering = CDependencyGraph::GetOperatorOrdering(pOpNodes: &this->m_opRoots, operators: &this->m_operators);
  m_Size = this->m_operators.m_Size;
  cycle = OperatorOrdering;
  v5 = 0;
  if ( m_Size / 2 > 0 )
  {
    v6 = m_Size;
    do
    {
      m_pMemory = p_m_operators->m_Memory.m_pMemory;
      v10 = p_m_operators->m_Memory.m_pMemory[v5];
      m_pMemory[v5] = m_pMemory[v6 - 1];
      m_pMemory[v6 - 1] = v10;
      ++v5;
      --v6;
    }
    while ( v5 < m_Size / 2 );
  }
  for ( i = 0; i < m_Size; ++i )
    p_m_operators->m_Memory.m_pMemory[i]->SetSortKey(this: p_m_operators->m_Memory.m_pMemory[i], a2: i);
  return cycle;
}

//------------------------------------------------------------------------------
// Address: 0x10079C80
// Name: private: class CAttributeNode __near * CDependencyGraph::FindAttrNode(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeNode *__thiscall CDependencyGraph::FindAttrNode(CDependencyGraph *this, CDmAttribute *pAttr)
{
  CDmAttribute *v3; // edi
  unsigned int v4; // eax
  CAttributeNode *v5; // esi
  CAttributeNode *v6; // eax
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // eax
  int m_Size; // edi
  CUtlMemory<S3RGBA,int> *v9; // esi
  int m_nAllocationCount; // eax
  S3RGBA *v11; // ecx
  int v12; // eax
  CAttributeNode **v13; // eax
  CAttributeNode search; // [esp+Ch] [ebp-28h] BYREF
  unsigned int pBucket; // [esp+28h] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+2Ch] [ebp-8h] BYREF
  CAttributeNode *pAttrNode; // [esp+30h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::FindAttrNode",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v3 = pAttr;
  src = (DmElementHandle_t)&search;
  search.m_attribute = pAttr;
  memset(&search.m_InputDependentOperators, 0, 21);
  pAttr = nullptr;
  if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
         this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
         &src,
         &pBucket,
         pIndex: (int *)&pAttr) == 0
    || (v4 = (unsigned int)pAttr | (pBucket << 16)) == -1 )
  {
    pAttrNode = nullptr;
    v6 = (CAttributeNode *)CUtlMemoryPool::Alloc(this: &g_AttrNodePool);
    if ( v6 != nullptr )
    {
      v6->m_attribute = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
      v6->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
      v6->m_InputDependentOperators.m_Memory.m_nGrowSize = 0;
      v6->m_InputDependentOperators.m_Size = 0;
      v6->m_InputDependentOperators.m_pElements = nullptr;
      v6->m_bIsOutputToOperator = false;
    }
    pAttrNode = v6;
    v6->m_attribute = v3;
    if ( CUtlHash<CAttributeNode *,bool (__cdecl *)(CAttributeNode * const &,CAttributeNode * const &),unsigned int (__cdecl *)(CAttributeNode * const &)>::DoFind(
           this: (CUtlHash<enum DmElementHandle_t,bool (__cdecl*)(enum DmElementHandle_t const &,enum DmElementHandle_t const &),unsigned int (__cdecl*)(enum DmElementHandle_t const &)> *)&this->m_attrNodes,
           src: (const DmElementHandle_t *)&pAttrNode,
           pBucket: (unsigned int *)&pAttr,
           pIndex: (int *)&pBucket) == 0 )
    {
      m_pMemory = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory;
      m_Size = m_pMemory[(_DWORD)pAttr].m_Size;
      v9 = (CUtlMemory<S3RGBA,int> *)&m_pMemory[(_DWORD)pAttr];
      m_nAllocationCount = v9->m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v9, num: m_Size - m_nAllocationCount + 1);
      ++v9[1].m_pMemory;
      v11 = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - m_Size - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
      v13 = (CAttributeNode **)&v9->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = pAttrNode;
    }
    v5 = pAttrNode;
  }
  else
  {
    v5 = this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pAttr];
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&search.m_InputDependentOperators);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10079DD0
// Name: private: void CDependencyGraph::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Cleanup(CDependencyGraph *this)
{
  CDependencyGraph *v1; // esi
  int v2; // edi
  COperatorNode *v3; // esi
  CAttributeNode **m_pMemory; // eax
  int m_Size; // edx
  int v6; // eax
  int *p_m_Size; // ecx
  int v8; // eax
  unsigned int v9; // edi
  CAttributeNode *v10; // esi
  COperatorNode **v11; // eax
  int v12; // edx
  signed int v13; // eax
  int v14; // ecx
  int *v15; // esi
  int v16; // edx
  int v17; // ecx
  int on; // [esp+Ch] [ebp-8h]

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Cleanup",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  v2 = 0;
  on = v1->m_opNodes.m_Size;
  if ( on > 0 )
  {
    do
    {
      v3 = v1->m_opNodes.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v3->m_OutputAttributes.m_Size = 0;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v3->m_OutputAttributes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_OutputAttributes.m_Memory.m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v3->m_OutputAttributes.m_Memory.m_pMemory;
        v3->m_OutputAttributes.m_pElements = m_pMemory;
        if ( v3->m_OutputAttributes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v3->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
          }
          v3->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_OperatorNodePool, memBlock: v3);
      v1 = this;
      ++v2;
    }
    while ( v2 < on );
  }
  m_Size = v1->m_attrNodes.m_Buckets.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_16:
    v8 = -1;
  }
  else
  {
    p_m_Size = &v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v6;
      p_m_Size += 5;
      if ( v6 >= m_Size )
        goto LABEL_16;
    }
    v8 = v6 << 16;
  }
  v9 = v8;
  if ( v8 != -1 )
  {
    while ( 1 )
    {
      v10 = v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[HIWORD(v9)].m_Memory.m_pMemory[(unsigned __int16)v9];
      if ( v10 != nullptr )
      {
        v10->m_InputDependentOperators.m_Size = 0;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v10->m_InputDependentOperators.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10->m_InputDependentOperators.m_Memory.m_pMemory);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
        v11 = v10->m_InputDependentOperators.m_Memory.m_pMemory;
        v10->m_InputDependentOperators.m_pElements = v11;
        if ( v10->m_InputDependentOperators.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v10->m_InputDependentOperators.m_Memory.m_pMemory = nullptr;
          }
          v10->m_InputDependentOperators.m_Memory.m_nAllocationCount = 0;
        }
      }
      CUtlMemoryPool::Free(this: &g_AttrNodePool, memBlock: v10);
      v12 = this->m_attrNodes.m_Buckets.m_Size;
      v13 = (v9 + 1) >> 16;
      v14 = (unsigned __int16)(v9 + 1);
      if ( v13 >= v12 )
        break;
      v15 = &this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v13].m_Size;
      while ( v14 >= *v15 )
      {
        ++v13;
        v14 = 0;
        v15 += 5;
        if ( v13 >= v12 )
          goto LABEL_36;
      }
      v9 = v14 | (v13 << 16);
      if ( v9 == -1 )
        break;
      v1 = this;
    }
LABEL_36:
    v1 = this;
  }
  v1->m_opRoots.m_Size = 0;
  v1->m_opNodes.m_Size = 0;
  v16 = v1->m_attrNodes.m_Buckets.m_Size;
  if ( v16 > 0 )
  {
    v17 = 0;
    do
    {
      v1->m_attrNodes.m_Buckets.m_Memory.m_pMemory[v17++].m_Size = 0;
      --v16;
    }
    while ( v16 != 0 );
  }
  v1->m_operators.m_Size = 0;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10079FA0
// Name: public: void CDependencyGraph::Reset(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::Reset(
        CDependencyGraph *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  int v2; // ebx
  CDependencyGraph *v3; // edi
  int m_Size; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // eax
  int v6; // eax
  IDmeOperator *const *v7; // edi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  int v11; // esi
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *m_pMemory; // eax
  unsigned int v13; // esi
  int v14; // edx
  IDmeOperator **v15; // esi
  CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *p_m_opNodes; // edi
  COperatorNode **v17; // eax
  COperatorNode **v18; // eax
  int v19; // eax
  IDmeOperator *v20; // edi
  COperatorNode *v21; // eax
  COperatorNode *v22; // esi
  CAttributeNode *AttrNode; // esi
  int v24; // edi
  int m_nAllocationCount; // eax
  COperatorNode **v26; // ecx
  int v27; // eax
  COperatorNode **v28; // eax
  CAttributeNode *v29; // ebx
  int v30; // edi
  int v31; // eax
  CAttributeNode **v32; // ecx
  int v33; // eax
  CAttributeNode **v34; // eax
  CDependencyGraph *v35; // edi
  int v36; // esi
  int v37; // eax
  COperatorNode **v38; // ecx
  int v39; // eax
  COperatorNode **v40; // esi
  CDmAttribute **v41; // eax
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > operatorDict; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > attrs; // [esp+28h] [ebp-30h] BYREF
  int oi; // [esp+3Ch] [ebp-1Ch]
  unsigned __int16 parent[2]; // [esp+40h] [ebp-18h] BYREF
  int an; // [esp+44h] [ebp-14h]
  int ai; // [esp+48h] [ebp-10h]
  int on; // [esp+4Ch] [ebp-Ch]
  CDependencyGraph *v49; // [esp+50h] [ebp-8h]
  bool leftchild; // [esp+57h] [ebp-1h] BYREF

  v2 = 0;
  v3 = this;
  v49 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CDependencyGraph::Reset",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  CDependencyGraph::Cleanup(this: v3);
  m_Size = operators->m_Size;
  v5 = nullptr;
  memset(&attrs, 0, sizeof(attrs));
  on = m_Size;
  operatorDict.m_LessFunc = (bool (__cdecl *)(IDmeOperator *const *, IDmeOperator *const *))CDefOps<CDmAttribute *>::LessFunc;
  operatorDict.m_Elements.m_pMemory = nullptr;
  operatorDict.m_Elements.m_nAllocationCount = 2 * m_Size;
  operatorDict.m_Elements.m_nGrowSize = 0;
  if ( 2 * m_Size != 0 )
  {
    v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * m_Size);
    operatorDict.m_Elements.m_pMemory = v5;
  }
  operatorDict.m_pElements = v5;
  v6 = 0;
  *(_DWORD *)&operatorDict.m_Root = 0xFFFF;
  *(_DWORD *)&operatorDict.m_FirstFree = -1;
  an = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = &operators->m_Memory.m_pMemory[v6];
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &operatorDict,
        insert: v7,
        parent,
        &leftchild);
      v8 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&operatorDict);
      v9 = parent[0];
      v10 = v8;
      v11 = 3 * v8;
      m_pMemory = operatorDict.m_Elements.m_pMemory;
      v13 = 4 * v11;
      *(unsigned __int16 *)((char *)&operatorDict.m_Elements.m_pMemory->m_Right + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v13) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v13) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v13) = v9;
      if ( v9 == 0xFFFF )
      {
        operatorDict.m_Root = v10;
      }
      else
      {
        v14 = v9;
        if ( leftchild )
          m_pMemory[v14].m_Left = v10;
        else
          m_pMemory[v14].m_Right = v10;
      }
      CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &operatorDict,
        elem: v10);
      ++operatorDict.m_NumElements;
      v15 = &(&operatorDict.m_Elements.m_pMemory->m_Data)[v13 / 4];
      if ( v15 != nullptr )
        *v15 = *v7;
      v6 = an + 1;
      an = v6;
    }
    while ( v6 < on );
    m_Size = on;
    v3 = v49;
    v2 = 0;
  }
  p_m_opNodes = &v3->m_opNodes;
  oi = (int)p_m_opNodes;
  if ( p_m_opNodes->m_Memory.m_nAllocationCount < m_Size && p_m_opNodes->m_Memory.m_nGrowSize >= 0 )
  {
    v17 = p_m_opNodes->m_Memory.m_pMemory;
    p_m_opNodes->m_Memory.m_nAllocationCount = m_Size;
    if ( v17 != nullptr )
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: 4 * m_Size);
      p_m_opNodes = (CUtlVector<COperatorNode *,CUtlMemory<COperatorNode *,int> > *)oi;
    }
    else
    {
      v18 = (COperatorNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_Size);
    }
    p_m_opNodes->m_Memory.m_pMemory = v18;
  }
  v19 = 0;
  p_m_opNodes->m_pElements = p_m_opNodes->m_Memory.m_pMemory;
  for ( oi = 0; v19 < m_Size; oi = v19 )
  {
    v20 = operators->m_Memory.m_pMemory[v19];
    ai = (int)v20;
    if ( v20 != nullptr )
    {
      v21 = (COperatorNode *)CUtlMemoryPool::Alloc(this: &g_OperatorNodePool);
      v22 = v21;
      *(_DWORD *)parent = v21;
      if ( v21 != nullptr )
      {
        v21->m_state = TS_NOT_VISITED;
        v21->m_operator = nullptr;
        v21->m_OutputAttributes.m_Memory.m_pMemory = nullptr;
        v21->m_OutputAttributes.m_Memory.m_nAllocationCount = 0;
        v21->m_OutputAttributes.m_Memory.m_nGrowSize = 0;
        v21->m_OutputAttributes.m_Size = 0;
        v21->m_OutputAttributes.m_pElements = nullptr;
        v21->m_bInList = false;
      }
      v21->m_operator = v20;
      attrs.m_Size = 0;
      v20->GetInputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      if ( attrs.m_Size > 0 )
      {
        do
        {
          AttrNode = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[v2]);
          v24 = AttrNode->m_InputDependentOperators.m_Size;
          m_nAllocationCount = AttrNode->m_InputDependentOperators.m_Memory.m_nAllocationCount;
          if ( v24 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&AttrNode->m_InputDependentOperators,
              num: v24 - m_nAllocationCount + 1);
          ++AttrNode->m_InputDependentOperators.m_Size;
          v26 = AttrNode->m_InputDependentOperators.m_Memory.m_pMemory;
          v27 = AttrNode->m_InputDependentOperators.m_Size - v24 - 1;
          AttrNode->m_InputDependentOperators.m_pElements = v26;
          if ( v27 > 0 )
            _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
          v28 = &AttrNode->m_InputDependentOperators.m_Memory.m_pMemory[v24];
          if ( v28 != nullptr )
            *v28 = *(COperatorNode **)parent;
          ++v2;
        }
        while ( v2 < an );
        v22 = *(COperatorNode **)parent;
        v20 = (IDmeOperator *)ai;
      }
      attrs.m_Size = 0;
      v20->GetOutputAttributes(this: v20, a2: &attrs);
      an = attrs.m_Size;
      for ( ai = 0; ai < an; ++ai )
      {
        v29 = CDependencyGraph::FindAttrNode(this: v49, pAttr: attrs.m_Memory.m_pMemory[ai]);
        v29->m_bIsOutputToOperator = true;
        v30 = v22->m_OutputAttributes.m_Size;
        v31 = v22->m_OutputAttributes.m_Memory.m_nAllocationCount;
        if ( v30 + 1 > v31 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&v22->m_OutputAttributes,
            num: v30 - v31 + 1);
        ++v22->m_OutputAttributes.m_Size;
        v32 = v22->m_OutputAttributes.m_Memory.m_pMemory;
        v33 = v22->m_OutputAttributes.m_Size - v30 - 1;
        v22->m_OutputAttributes.m_pElements = v32;
        if ( v33 > 0 )
          _V_memmove(dest: &v32[v30 + 1], src: &v32[v30], count: 4 * v33);
        v34 = &v22->m_OutputAttributes.m_Memory.m_pMemory[v30];
        if ( v34 != nullptr )
          *v34 = v29;
      }
      v35 = v49;
      v36 = v49->m_opNodes.m_Size;
      v37 = v49->m_opNodes.m_Memory.m_nAllocationCount;
      if ( v36 + 1 > v37 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&v49->m_opNodes, num: v36 - v37 + 1);
      ++v35->m_opNodes.m_Size;
      v38 = v35->m_opNodes.m_Memory.m_pMemory;
      v39 = v35->m_opNodes.m_Size - v36 - 1;
      v35->m_opNodes.m_pElements = v38;
      if ( v39 > 0 )
        _V_memmove(dest: &v38[v36 + 1], src: &v38[v36], count: 4 * v39);
      v40 = &v35->m_opNodes.m_Memory.m_pMemory[v36];
      v2 = 0;
      if ( v40 != nullptr )
        *v40 = *(COperatorNode **)parent;
      m_Size = on;
    }
    v19 = oi + 1;
  }
  CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(this: &operatorDict);
  if ( operatorDict.m_Elements.m_nGrowSize >= 0 && operatorDict.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: operatorDict.m_Elements.m_pMemory);
  v41 = attrs.m_Memory.m_pMemory;
  attrs.m_Size = 0;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( attrs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: attrs.m_Memory.m_pMemory);
      v41 = nullptr;
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  attrs.m_pElements = v41;
  if ( attrs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v41 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
      attrs.m_Memory.m_pMemory = nullptr;
    }
    attrs.m_Memory.m_nAllocationCount = 0;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1007A3C0
// Name: public: CDependencyGraph::CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
CDependencyGraph *__thiscall CDependencyGraph::CDependencyGraph(CDependencyGraph *this)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *p_m_attrNodes; // ecx
  int i; // eax

  this->m_opRoots.m_Memory.m_pMemory = nullptr;
  this->m_opRoots.m_Memory.m_nAllocationCount = 0;
  this->m_opRoots.m_Memory.m_nGrowSize = 0;
  this->m_opRoots.m_Size = 0;
  this->m_opRoots.m_pElements = nullptr;
  this->m_opNodes.m_Memory.m_pMemory = nullptr;
  this->m_opNodes.m_Memory.m_nAllocationCount = 0;
  this->m_opNodes.m_Memory.m_nGrowSize = 0;
  this->m_opNodes.m_Size = 0;
  this->m_opNodes.m_pElements = nullptr;
  p_m_attrNodes = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes;
  p_m_attrNodes->m_Memory.m_pMemory = nullptr;
  this->m_attrNodes.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_attrNodes.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_attrNodes.m_Buckets.m_Size = 0;
  this->m_attrNodes.m_Buckets.m_pElements = nullptr;
  this->m_attrNodes.m_CompareFunc = HashEntryCompareFunc;
  this->m_attrNodes.m_KeyFunc = HashEntryKeyFunc;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this: p_m_attrNodes);
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes,
    elem: this->m_attrNodes.m_Buckets.m_Size,
    num: 4096);
  for ( i = 0; i < 4096; ++i )
  {
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_attrNodes.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_attrNodes.m_bPowerOfTwo = true;
  this->m_attrNodes.m_ModMask = 4095;
  this->m_operators.m_Memory.m_pMemory = nullptr;
  this->m_operators.m_Memory.m_nAllocationCount = 0;
  this->m_operators.m_Memory.m_nGrowSize = 0;
  this->m_operators.m_Size = 0;
  this->m_operators.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007A460
// Name: public: CDependencyGraph::~CDependencyGraph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDependencyGraph::~CDependencyGraph(CDependencyGraph *this)
{
  CDependencyGraph::Cleanup(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_operators);
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&this->m_attrNodes);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&this->m_attrNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_opNodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

} // namespace vtex_dll
