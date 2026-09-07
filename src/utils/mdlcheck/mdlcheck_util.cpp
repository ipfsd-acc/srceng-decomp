// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mdlcheck/mdlcheck_util.cpp
// Functions: 80
// ============================================================

#include "utils\mdlcheck\mdlcheck_util.h"

//------------------------------------------------------------------------------
// Address: 0x00403690
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 280 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: m_pMemory,
                                                                                           a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403730
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00403790
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 292 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                              this: _g_pMemAlloc,
                                                                                              a2: m_pMemory,
                                                                                              a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                              this: _g_pMemAlloc,
                                                                                              a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403830
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *__thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory;
  else
    return (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00403890
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,ModelFile,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // edi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403980
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (dword_82C084 & 1) == 0 )
  {
    dword_82C084 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004039E0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this)
{
  int m_FirstFree; // ecx
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403AB0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = dword_82C084;
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      dword_82C084 = v1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      dword_82C084 = v1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403B50
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this)
{
  int m_FirstFree; // ecx
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403C20
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
bool (__cdecl *__thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this))(const char *const *, const char *const *)
{
  int m_Root; // ebx
  bool (__cdecl *result)(const char *const *, const char *const *); // eax
  CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *v3; // edx

  m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  result = (bool (__cdecl *)(const char *const *, const char *const *))this->m_Root;
  while ( 1 )
  {
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    v3 = result == (bool (__cdecl *)(const char *const *, const char *const *))-1
       ? &`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
    if ( v3->m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
      break;
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( result == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
      result = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc;
    else
      result = (bool (__cdecl *)(const char *const *, const char *const *))this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403CC0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (dword_82C084 & 1) == 0 )
  {
    dword_82C084 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00403D20
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *p_m_NumElements; // eax
  int m_Parent; // eax

  v2 = dword_82C084;
  if ( (dword_82C084 & 1) == 0 )
  {
    v2 = dword_82C084 | 1;
    dword_82C084 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( i == -1 )
    p_m_NumElements = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    p_m_NumElements = &this->m_Elements.m_pMemory[i];
  m_Parent = p_m_NumElements->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    dword_82C084 = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00403DD0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory == (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00403E80
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *p_m_NumElements; // eax
  int m_Parent; // eax

  v2 = dword_82C084;
  if ( (dword_82C084 & 1) == 0 )
  {
    v2 = dword_82C084 | 1;
    dword_82C084 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( i == -1 )
    p_m_NumElements = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    p_m_NumElements = &this->m_Elements.m_pMemory[i];
  m_Parent = p_m_NumElements->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    dword_82C084 = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00403F40
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v3; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *p_m_NumElements; // eax
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v6; // eax
  int v7; // edx
  int v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v9; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v10; // eax
  int v11; // eax

  v3 = dword_82C084;
  if ( (dword_82C084 & 1) == 0 )
  {
    v3 = dword_82C084 | 1;
    dword_82C084 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( elem == -1 )
    p_m_NumElements = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    p_m_NumElements = &this->m_Elements.m_pMemory[elem];
  m_Right = p_m_NumElements->m_Right;
  if ( (v3 & 1) == 0 )
  {
    dword_82C084 = v3 | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v8 = dword_82C084;
  if ( (dword_82C084 & 1) == 0 )
  {
    v8 = dword_82C084 | 1;
    dword_82C084 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( m_Right == -1 )
    v9 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    v9 = &this->m_Elements.m_pMemory[m_Right];
  if ( v9->m_Left != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      dword_82C084 = v8 | 1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
    }
    if ( m_Right == -1 )
      v10 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
    else
      v10 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v10->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
  {
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v11 = CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v11].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
    v7 = elem;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00404120
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v3; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *p_m_NumElements; // eax
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v7; // eax

  v3 = dword_82C084;
  if ( (dword_82C084 & 1) == 0 )
  {
    v3 = dword_82C084 | 1;
    dword_82C084 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( elem == -1 )
    p_m_NumElements = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    p_m_NumElements = &this->m_Elements.m_pMemory[elem];
  m_Left = p_m_NumElements->m_Left;
  if ( (v3 & 1) == 0 )
  {
    dword_82C084 = v3 | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (dword_82C084 & 1) == 0 )
  {
    dword_82C084 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004042B0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00404360
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v4; // eax
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v6; // eax
  int v7; // edx
  int v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v9; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v10; // eax
  int v11; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v8 = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    v8 = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
       | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v9 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v9 = &this->m_Elements.m_pMemory[m_Right];
  if ( v9->m_Left != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v8 | 1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( m_Right == -1 )
      v10 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v10 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v10->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
  {
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v11 = CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v11].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
    v7 = elem;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00404540
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v4; // eax
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v7; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[(_DWORD)CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RightChild(
                                         this,
                                         i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004046D0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,ModelFile,int>::Node_t *search)
{
  int m_Root; // ebx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x004047C0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct QCFile,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,QCFile,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // edi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (dword_82C084 & 1) == 0 )
      {
        dword_82C084 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (dword_82C084 & 1) == 0 )
      {
        dword_82C084 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004048B0
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (dword_82C084 & 1) == 0 )
          {
            dword_82C084 |= 1u;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404970
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *p_m_NumElements; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // [esp-4h] [ebp-10h]

  if ( (dword_82C084 & 1) == 0 )
  {
    dword_82C084 |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
  }
  if ( i == -1 )
    p_m_NumElements = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    p_m_NumElements = &this->m_Elements.m_pMemory[i];
  if ( p_m_NumElements->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        if ( m_Parent == -1 )
          break;
        if ( (dword_82C084 & 1) == 0 )
        {
          dword_82C084 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
        }
        v8 = m_Parent;
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = dword_82C084;
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        dword_82C084 = v5;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        dword_82C084 = v5;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404AE0
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404BA0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *__thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v3; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *result; // eax
  int m_Root; // edx
  CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *v6; // ecx
  int m_Parent; // esi
  int v8; // [esp-4h] [ebp-10h]

  if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v8 = m_Parent;
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
    while ( 1 )
    {
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v6 = result == (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1
         ? &`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
      if ( v6->m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( result == (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1 )
        result = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc;
      else
        result = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404D10
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  int v4; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *p_m_NumElements; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v8; // eax
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v10; // eax
  int v11; // ebx
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v18; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v23; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = dword_82C084;
      if ( (dword_82C084 & 1) == 0 )
      {
        v4 = dword_82C084 | 1;
        dword_82C084 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
      }
      if ( v2 == -1 )
        p_m_NumElements = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
      else
        p_m_NumElements = &this->m_Elements.m_pMemory[v2];
      m_Parent = p_m_NumElements->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        dword_82C084 = v4;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        dword_82C084 = v4;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        dword_82C084 = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = dword_82C084;
      if ( IsLeftChild )
      {
        if ( (dword_82C084 & 1) == 0 )
        {
          v13 = dword_82C084 | 1;
          dword_82C084 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          dword_82C084 = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = dword_82C084;
          if ( (dword_82C084 & 1) == 0 )
          {
            v17 = dword_82C084 | 1;
            dword_82C084 |= 1u;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            dword_82C084 = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (dword_82C084 & 1) == 0 )
        {
          v13 = dword_82C084 | 1;
          dword_82C084 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          dword_82C084 = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = dword_82C084;
          if ( (dword_82C084 & 1) == 0 )
          {
            v22 = dword_82C084 | 1;
            dword_82C084 |= 1u;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            dword_82C084 = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004051A0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  int m_Root; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v8; // eax
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v10; // eax
  int v11; // ebx
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v18; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v23; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        m_Root = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
               | 1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
          if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                | 1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
          if ( (`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                | 1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405730
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *m_pMemory; // eax
  int v6; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    v6 = parent;
    if ( isLeft )
      m_pMemory[v6].m_Left = i;
    else
      m_pMemory[v6].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004057A0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *m_pMemory; // eax
  int v6; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    v6 = parent;
    if ( isLeft )
      m_pMemory[v6].m_Left = i;
    else
      m_pMemory[v6].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004059D0
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A30
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A90
// Name: public: void CUtlDict<struct QCFile,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<QCFile,int>::RemoveAll(CUtlDict<QCFile,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00405AE0
// Name: public: void CUtlDict<struct ModelFile,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<ModelFile,int>::RemoveAll(CUtlDict<ModelFile,int> *this)
{
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *i; // esi

  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00405DE0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int,class CUtlMap<char const __near *,struct QCFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct QCFile,int>::Node_t,int>,int>>::Insert(struct CUtlMap<char const __near *,struct QCFile,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::Insert(
        CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,QCFile,int>::Node_t *insert)
{
  int v3; // ebx
  UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::NewNode(this);
  CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00405E60
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int,class CUtlMap<char const __near *,struct ModelFile,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t,int>,int>>::Insert(struct CUtlMap<char const __near *,struct ModelFile,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Insert(
        CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,ModelFile,int>::Node_t *insert)
{
  int v3; // ebx
  UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::NewNode(this);
  CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00405EE0
// Name: public: int CUtlDict<struct QCFile,int>::Insert(char const __near *,struct QCFile const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<QCFile,int>::Insert(CUtlDict<QCFile,int> *this, const char *pName, const QCFile *element)
{
  char *v4; // eax
  CUtlMap<char const *,QCFile,int>::Node_t insert; // [esp+Ch] [ebp-108h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  insert.key = v4;
  insert.elem = *element;
  return CUtlRBTree<CUtlMap<char const *,QCFile,int>::Node_t,int,CUtlMap<char const *,QCFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,QCFile,int>::Node_t,int>,int>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x00405F60
// Name: public: int CUtlDict<struct ModelFile,int>::Insert(char const __near *,struct ModelFile const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<ModelFile,int>::Insert(
        CUtlDict<ModelFile,int> *this,
        const char *pName,
        const ModelFile *element)
{
  char *v4; // eax
  CUtlMap<char const *,ModelFile,int>::Node_t insert; // [esp+Ch] [ebp-114h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  insert.key = v4;
  insert.elem = *element;
  return CUtlRBTree<CUtlMap<char const *,ModelFile,int>::Node_t,int,CUtlMap<char const *,ModelFile,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ModelFile,int>::Node_t,int>,int>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x00406400
// Name: void vprint(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void vprint(int depth, char *fmt, ...)
{
  _iobuf *v2; // edi
  int v3; // esi
  char *i; // esi
  char string[8192]; // [esp+Ch] [ebp-2000h] BYREF
  va_list ap; // [esp+201Ch] [ebp+10h] BYREF

  va_start(ap, fmt);
  vsprintf(string, format: fmt, ap);
  v2 = nullptr;
  if ( uselogfile )
    v2 = fopen(file: "log.txt", mode: "ab");
  v3 = depth;
  while ( v3 > 0 )
  {
    --v3;
    printf(format: "  ");
    OutputDebugStringA(lpOutputString: "  ");
    if ( v2 != nullptr )
      fprintf(str: v2, format: "  ");
  }
  printf(format: string);
  OutputDebugStringA(lpOutputString: string);
  if ( v2 != nullptr )
  {
    for ( i = string; *i != 0; fputc(ch: *i++, str: v2) )
    {
      if ( *i == 10 )
        fputc(ch: 13, str: v2);
    }
    fclose(stream: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004064F0
// Name: void dump(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void dump(char *fmt, ...)
{
  _iobuf *v1; // edi
  char *i; // esi
  char string[8192]; // [esp+4h] [ebp-2000h] BYREF
  va_list ap; // [esp+2010h] [ebp+Ch] BYREF

  va_start(ap, fmt);
  vsprintf(string, format: fmt, ap);
  v1 = nullptr;
  if ( uselogfile )
    v1 = fopen(file: "log.txt", mode: "ab");
  printf(format: "%s", string);
  OutputDebugStringA(lpOutputString: string);
  if ( v1 != nullptr )
  {
    for ( i = string; *i != 0; fputc(ch: *i++, str: v1) )
    {
      if ( *i == 10 )
        fputc(ch: 13, str: v1);
    }
    fclose(stream: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004065B0
// Name: bool CC_IsBreakChar(char)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CC_IsBreakChar(char ch)
{
  bool result; // al

  result = false;
  switch ( ch )
  {
    case '(':
    case ')':
    case ',':
    case ';':
    case '<':
    case '>':
    case '[':
    case ']':
    case '{':
    case '}':
      goto $LN4_0;
    case ':':
      if ( !com_ignorecolons )
$LN4_0:
        result = true;
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406640
// Name: char __near * CC_ParseToken(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CC_ParseToken(char *data)
{
  char *result; // eax
  char *v2; // edx
  unsigned int v3; // esi
  int v4; // ebx
  char i; // al
  char j; // al
  char v7; // bl
  char *v8; // edx
  bool v9; // cl
  int v10; // eax
  bool v11; // cl

  if ( s_com_token_unget )
  {
    s_com_token_unget = false;
    return data;
  }
  v2 = data;
  v3 = 0;
  unk_82C088[0] = 0;
  if ( data == nullptr )
    return nullptr;
  while ( 1 )
  {
    while ( 1 )
    {
      v4 = *v2;
      if ( v4 <= 32 )
      {
        while ( v4 != 0 )
        {
          if ( v4 == 10 )
            ++linesprocessed;
          v4 = *++v2;
          if ( v4 > 32 )
            goto LABEL_10;
        }
        return nullptr;
      }
LABEL_10:
      if ( com_ignoreinlinecomment )
        break;
      if ( v4 != 47 )
        goto LABEL_30;
      if ( v2[1] != 47 )
        goto LABEL_18;
      for ( i = *v2; i != 0; i = *++v2 )
      {
        if ( i == 10 )
          break;
      }
    }
    if ( v4 != 47 )
      break;
LABEL_18:
    if ( v2[1] != 42 )
      break;
    for ( j = *v2; j != 0; j = *++v2 )
    {
      v7 = v2[1];
      if ( v7 == 0 || j == 42 && v7 == 47 )
        break;
      if ( j == 10 )
        ++linesprocessed;
    }
    if ( *v2 == 42 && v2[1] == 47 )
      v2 += 2;
  }
LABEL_30:
  if ( *v2 == 76 )
  {
    result = v2 + 1;
    if ( v2[1] == 34 )
    {
      unk_82C088[0] = v4;
      return result;
    }
  }
  if ( v4 == 34 )
  {
    v8 = v2 + 1;
    v9 = false;
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = *v8++;
        if ( v10 != 34 )
          break;
        if ( !v9 )
          goto $LN3_0;
        v9 = false;
        unk_82C088[v3++] = 34;
      }
      if ( v10 == 0 && v3 < 0x3FF )
        break;
      v9 = v10 == 92;
      unk_82C088[v3++] = v10;
    }
  }
  else
  {
    if ( CC_IsBreakChar(ch: v4) )
    {
      unk_82C088[0] = v4;
      unk_82C089 = 0;
      return v8 + 1;
    }
    v11 = com_ignorecolons;
    while ( 2 )
    {
      ++v8;
      unk_82C088[v3] = v4;
      v4 = *v8;
      ++v3;
      switch ( (char)v4 )
      {
        case '(':
        case ')':
        case ',':
        case ';':
        case '<':
        case '>':
        case '[':
        case ']':
        case '{':
        case '}':
          break;
        case ':':
          if ( v11 )
            goto LABEL_46;
          break;
        default:
LABEL_46:
          if ( v4 > 32 && v3 < 0x3FF )
            continue;
          break;
      }
      break;
    }
  }
$LN3_0:
  unk_82C088[v3] = 0;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00406860
// Name: unsigned char __near * COM_LoadFile(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl COM_LoadFile(const char *name, int *len)
{
  _iobuf *result; // eax
  _iobuf *v3; // esi
  void *v4; // ebx

  result = fopen(file: name, mode: "rb");
  v3 = result;
  if ( result != nullptr )
  {
    fseek(stream: result, offset: 0, whence: 2);
    *len = ftell(stream: v3);
    fseek(stream: v3, offset: 0, whence: 0);
    v4 = operator new(size: *len + 1);
    fread(buffer: v4, elementSize: *len, count: 1u, stream: v3);
    fclose(stream: v3);
    *((_BYTE *)v4 + *len) = 0;
    return (_iobuf *)v4;
  }
  else
  {
    *len = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004068E0
// Name: void COM_FreeFile(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_FreeFile(unsigned __int8 *buffer)
{
  operator delete(p: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x004068F0
// Name: public: void CUtlMemory<char __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char *,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406980
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( i == -1 )
    return dword_82C4B8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00406A80
// Name: void dump_queue(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl dump_queue(CUtlVector<char *,CUtlMemory<char *,int> > *printQueue)
{
  _iobuf *v1; // edi
  CUtlVector<char *,CUtlMemory<char *,int> > *v2; // esi
  int i; // ebx
  const char *v4; // esi
  char j; // al

  v1 = nullptr;
  if ( uselogfile )
    v1 = fopen(file: "log.txt", mode: "ab");
  v2 = printQueue;
  for ( i = 0; i < printQueue->m_Size; v2 = printQueue )
  {
    v4 = v2->m_Memory.m_pMemory[i];
    printf(format: "%s", v4);
    OutputDebugStringA(lpOutputString: v4);
    if ( v1 != nullptr )
    {
      for ( j = *v4; j != 0; ++v4 )
      {
        if ( j == 10 )
          fputc(ch: 13, str: v1);
        fputc(ch: *v4, str: v1);
        j = v4[1];
      }
    }
    ++i;
  }
  if ( v1 != nullptr )
    fclose(stream: v1);
  v2->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406B20
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( i == -1 )
    return dword_82C4B4;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00406B80
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_82C4B4 = -1;
        dword_82C4B8 = -1;
        dword_82C4BC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_82C4B4 = -1;
        dword_82C4B8 = -1;
        dword_82C4BC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406C70
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<fileList_t,int>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406D30
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_82C4B4 = -1;
      dword_82C4B8 = -1;
      dword_82C4BC = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_82C4B4 = -1;
      dword_82C4B8 = -1;
      dword_82C4BC = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406DD0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( m_Parent == -1 )
    return dword_82C4B4 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00406E80
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00406F30
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_82C4B4 = -1;
      dword_82C4B8 = -1;
      dword_82C4BC = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004070E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00407250
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_82C4B4 = -1;
        dword_82C4B8 = -1;
        dword_82C4BC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_82C4B4 = -1;
        dword_82C4B8 = -1;
        dword_82C4BC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00407340
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_82C4B4 = -1;
            dword_82C4B8 = -1;
            dword_82C4BC = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407400
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_82C4B4 = -1;
    dword_82C4B8 = -1;
    dword_82C4BC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_82C4B4 = -1;
          dword_82C4B8 = -1;
          dword_82C4BC = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_82C4B4 = -1;
        dword_82C4B8 = -1;
        dword_82C4BC = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_82C4B4 = -1;
        dword_82C4B8 = -1;
        dword_82C4BC = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407570
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_82C4B4 = -1;
        dword_82C4B8 = -1;
        dword_82C4BC = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_82C4B4 = -1;
        dword_82C4B8 = -1;
        dword_82C4BC = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_82C4B4 = -1;
        dword_82C4B8 = -1;
        dword_82C4BC = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_82C4B4 = -1;
        dword_82C4B8 = -1;
        dword_82C4BC = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_82C4B4 = -1;
          dword_82C4B8 = -1;
          dword_82C4BC = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_82C4B4 = -1;
          dword_82C4B8 = -1;
          dword_82C4BC = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_82C4B4 = -1;
            dword_82C4B8 = -1;
            dword_82C4BC = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_82C4B4 = -1;
            dword_82C4B8 = -1;
            dword_82C4BC = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_82C4B4 = -1;
          dword_82C4B8 = -1;
          dword_82C4BC = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_82C4B4 = -1;
          dword_82C4B8 = -1;
          dword_82C4BC = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_82C4B4 = -1;
            dword_82C4B8 = -1;
            dword_82C4BC = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_82C4B4 = -1;
            dword_82C4B8 = -1;
            dword_82C4BC = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004079D0
// Name: void dump_print_queue(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl dump_print_queue()
{
  int v0; // edi
  int v1; // esi

  v0 = 0;
  if ( g_PerforceUser.m_Elements.m_Tree.m_NumElements > 0 )
  {
    v1 = 0;
    do
    {
      if ( v0 != 0 )
        dump(fmt: "\n\n%s :\n", g_PerforceUser.m_Elements.m_Tree.m_Elements.m_pMemory[v1].m_Data.key);
      dump_queue(printQueue: g_PerforceUser.m_Elements.m_Tree.m_Elements.m_pMemory[v1].m_Data.elem);
      ++v0;
      ++v1;
    }
    while ( v0 < g_PerforceUser.m_Elements.m_Tree.m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407A20
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407A90
// Name: void vprint_queued(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __usercall vprint_queued(int a1@<ebx>, int a2@<esi>, int owner, char *fmt, ...)
{
  char *v4; // eax
  char *v5; // ebx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *elem; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  CUtlSymbolTable::StringPool_t **v9; // ecx
  int v10; // eax
  CUtlSymbolTable::StringPool_t **v11; // eax
  unsigned __int8 string[8192]; // [esp+0h] [ebp-2000h] BYREF
  va_list ap; // [esp+2010h] [ebp+10h] BYREF

  va_start(ap, fmt);
  _strnset(string, val: 0x20u, count: 0);
  vsprintf((char *)string, format: fmt, ap);
  v4 = (char *)((int (__thiscall *)(IMemAlloc *, unsigned int, int, int))_g_pMemAlloc->Alloc_2)(
                 a1: _g_pMemAlloc,
                 a2: strlen((const char *)string) + 1,
                 a3: a2,
                 a4: a1);
  if ( v4 != nullptr )
  {
    strcpy(v4, (const char *)string);
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  elem = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)g_PerforceUser.m_Elements.m_Tree.m_Elements.m_pMemory[owner].m_Data.elem;
  m_nAllocationCount = elem->m_nAllocationCount;
  m_pMemory = elem[1].m_pMemory;
  if ( (int)m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<char *,int>::Grow(this: elem, num: (int)m_pMemory - m_nAllocationCount + 1);
  ++elem[1].m_pMemory;
  v9 = elem->m_pMemory;
  v10 = (char *)elem[1].m_pMemory - (char *)m_pMemory - 1;
  elem[1].m_nAllocationCount = (int)elem->m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &v9[(_DWORD)m_pMemory + 1], src: &v9[(_DWORD)m_pMemory], count: 4 * v10);
  v11 = &elem->m_pMemory[(_DWORD)m_pMemory];
  if ( v11 != nullptr )
    *v11 = (CUtlSymbolTable::StringPool_t *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00407B80
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407BE0
// Name: public: void CUtlDict<class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlVector<char *,CUtlMemory<char *,int>> *,int>::RemoveAll(
        CUtlDict<CUtlVector<char *,CUtlMemory<char *,int> > *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00407C30
// Name: public: int CUtlMap<char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Insert(char const __near * const __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Insert(
        CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int> *this,
        const char **key,
        int insert)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CUtlVector<char *,CUtlMemory<char *,int> > **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::NewNode(this: &this->m_Tree);
  CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00407CB0
// Name: public: int CUtlDict<class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near *,int>::Insert(char const __near *,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Insert(
        CUtlDict<CUtlVector<char *,CUtlMemory<char *,int> > *,int> *this,
        char *pName,
        CUtlVector<char *,CUtlMemory<char *,int> > *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x00407D10
// Name: void vprint_init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vprint_init(CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v1; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *userQueue; // [esp+0h] [ebp-4h] BYREF

  userQueue = this;
  v1 = (CUtlVector<char *,CUtlMemory<char *,int> > *)operator new(size: 0x14u);
  if ( v1 != nullptr )
  {
    v1->m_Memory.m_pMemory = nullptr;
    v1->m_Memory.m_nAllocationCount = 0;
    v1->m_Memory.m_nGrowSize = 0;
    v1->m_Size = 0;
    v1->m_pElements = nullptr;
    userQueue = v1;
  }
  else
  {
    userQueue = nullptr;
  }
  CUtlDict<CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Insert(
    this: &g_PerforceUser,
    pName: "unknown",
    element: &userQueue);
}

//------------------------------------------------------------------------------
// Address: 0x00407D60
// Name: int vprint_owner(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl vprint_owner(const char *path, const char *filename)
{
  IP4 *v2; // esi
  const char *v3; // eax
  char v4; // cl
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int *v10; // eax
  __int16 v11; // ecx^2
  int *v12; // esi
  const char *v13; // eax
  int result; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v15; // eax
  __int16 v16; // ecx^2
  char *v17; // eax
  int v18; // [esp-8h] [ebp-120h]
  int v19; // [esp-4h] [ebp-11Ch]
  char v20; // [esp+Bh] [ebp-10Dh] BYREF
  char fullname[260]; // [esp+Ch] [ebp-10Ch] BYREF
  CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t search; // [esp+110h] [ebp-8h] BYREF

  v2 = p4;
  if ( p4 == nullptr )
    return 0;
  v3 = path;
  if ( path != nullptr )
  {
    do
    {
      v4 = *v3;
      v3[fullname - path] = *v3;
      ++v3;
    }
    while ( v4 != 0 );
    v5 = &v20;
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, "\\");
    v7 = strlen(filename) + 1;
    v8 = &v20;
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, filename, v7);
    v2 = p4;
  }
  else
  {
    strcpy(fullname, filename);
  }
  v10 = (int *)v2->GetRevisionList(this: v2, a2: fullname, a3: false);
  v12 = v10;
  if ( v10[3] <= 0 )
    return 0;
  HIWORD(v19) = v11;
  LOWORD(v19) = *(_WORD *)(*v10 + 28);
  v13 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v19);
  if ( v13 == nullptr
    || (search.key = v13,
        (result = CUtlRBTree<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Node_t,int>,int>>::Find(
                    this: &g_PerforceUser.m_Elements.m_Tree,
                    &search)) == -1) )
  {
    v15 = (CUtlVector<char *,CUtlMemory<char *,int> > *)operator new(size: 0x14u);
    if ( v15 != nullptr )
    {
      v15->m_Memory.m_pMemory = nullptr;
      v15->m_Memory.m_nAllocationCount = 0;
      v15->m_Memory.m_nGrowSize = 0;
      v15->m_Size = 0;
      v15->m_pElements = nullptr;
      search.elem = v15;
    }
    else
    {
      search.elem = nullptr;
    }
    HIWORD(v18) = v16;
    LOWORD(v18) = *(_WORD *)(*v12 + 28);
    v17 = (char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v18);
    return CUtlDict<CUtlVector<char *,CUtlMemory<char *,int>> *,int>::Insert(
             this: &g_PerforceUser,
             pName: v17,
             element: &search.elem);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C6D0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C7D0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_8432CC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_8432CC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0040C950
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_8432CC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0040C9B0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_8432CC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040CA20
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_8432CC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_8432CC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CB10
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040CC10
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040CD50
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_8432CC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_8432CC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0040CEC0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CF80
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_8432CC = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_8432CC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_8432CC = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_8432CC = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_8432CC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_8432CC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_8432CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_8432CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_8432CC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_8432CC = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_8432CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_8432CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_8432CC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_8432CC = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040D530
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D630
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D6C0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}
