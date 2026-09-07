// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/overwatch/overwatch_service/filechangewatcher.cpp
// Functions: 27
// ============================================================

#include "utils\overwatch\overwatch_service\filechangewatcher.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  return _stricmp(dst: *lhs, src: *rhs) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401020
// Name: public: void CFileChangeWatcher::CFileChange::GetFullFilename(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileChangeWatcher::CFileChange::GetFullFilename(
        CFileChangeWatcher::CFileChange *this,
        char *pOut,
        int nMaxBytes)
{
  V_ComposeFileName(path: this->m_pBaseDirName, filename: this->m_RelativeFilename, dest: pOut, destSize: nMaxBytes);
}

//------------------------------------------------------------------------------
// Address: 0x00401040
// Name: public: void CUtlMemory<class CFileChangeWatcher::CDirWatch __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFileChangeWatcher::CDirWatch *,int>::Grow(
        CUtlMemory<CFileChangeWatcher::CDirWatch *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CFileChangeWatcher::CDirWatch **m_pMemory; // edx
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
      this->m_pMemory = (CFileChangeWatcher::CDirWatch **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CFileChangeWatcher::CDirWatch **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004010D0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: m_pMemory,
                                                                                        a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401170
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4122A4 = -1;
    dword_4122A8 = -1;
    dword_4122AC = 1;
  }
  if ( i == -1 )
    return dword_4122A8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x004011C0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4122A4 = -1;
    dword_4122A8 = -1;
    dword_4122AC = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00401210
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4122A4 = -1;
    dword_4122A8 = -1;
    dword_4122AC = 1;
  }
  if ( i == -1 )
    return dword_4122A4;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00401260
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,int,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,int,int>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401350
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v11; // edx

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
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>::Grow(this: &this->m_Elements, num: 1);
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
// Address: 0x00401420
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  int v3; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
         this,
         i);
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4122A4 = -1;
    dword_4122A8 = -1;
    dword_4122AC = 1;
  }
  if ( v3 == -1 )
    return `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v3].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00401490
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v5; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
         this,
         i: elem);
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4122A4 = -1;
    dword_4122A8 = -1;
    dword_4122AC = 1;
  }
  if ( v3 == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[v3];
  this->m_Elements.m_pMemory[elem].m_Right = v4->m_Left;
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4122A4 = -1;
    dword_4122A8 = -1;
    dword_4122AC = 1;
  }
  if ( v3 == -1 )
    v5 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v5 = &this->m_Elements.m_pMemory[v3];
  if ( v5->m_Left != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LeftChild(
                                 this,
                                 i: v3)].m_Parent = elem;
  if ( v3 != -1 )
    this->m_Elements.m_pMemory[v3].m_Parent = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v3;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = v3;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = v3;
  }
  this->m_Elements.m_pMemory[v3].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = v3;
}

//------------------------------------------------------------------------------
// Address: 0x004015C0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // eax
  int m_Left; // edi
  int v5; // eax

  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4122A4 = -1;
    dword_4122A8 = -1;
    dword_4122AC = 1;
  }
  if ( elem == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[elem];
  m_Left = v3->m_Left;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
                                              this,
                                              i: v3->m_Left);
  if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
         this,
         i: m_Left) != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
           this,
           i: v5) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004016C0
// Name: public: CUtlVector<class CFileChangeWatcher::CDirWatch __near *,class CUtlMemory<class CFileChangeWatcher::CDirWatch __near *,int>>::~CUtlVector<class CFileChangeWatcher::CDirWatch __near *,class CUtlMemory<class CFileChangeWatcher::CDirWatch __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int>>::~CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int>>(
        CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int> > *this)
{
  bool v2; // sf
  CFileChangeWatcher::CDirWatch **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401730
// Name: public: void CUtlVector<class CFileChangeWatcher::CDirWatch __near *,class CUtlMemory<class CFileChangeWatcher::CDirWatch __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int>>::PurgeAndDeleteElements(
        CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CFileChangeWatcher::CDirWatch **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004017A0
// Name: public: int CUtlVector<class CFileChangeWatcher::CDirWatch __near *,class CUtlMemory<class CFileChangeWatcher::CDirWatch __near *,int>>::InsertBefore(int,class CFileChangeWatcher::CDirWatch __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int>>::InsertBefore(
        CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int> > *this,
        int elem,
        CFileChangeWatcher::CDirWatch **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFileChangeWatcher::CDirWatch **m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CFileChangeWatcher::CDirWatch **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CFileChangeWatcher::CDirWatch *,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00401810
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,int,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,int,int>::Node_t *search)
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
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00401900
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4122A4 = -1;
      dword_4122A8 = -1;
      dword_4122AC = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4122A4 = -1;
      dword_4122A8 = -1;
      dword_4122AC = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004019A0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // esi
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int v7; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v8; // ecx
  int m_Parent; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
         this,
         i) == -1 )
  {
    result = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
               this,
               i);
    v7 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v8->m_Parent;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      v10 = m_Parent == -1
          ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v10[1] != v2 )
        break;
      v2 = result;
      if ( result == -1 )
        break;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      result = this->m_Elements.m_pMemory[result].m_Parent;
    }
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401B30
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401BC0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  int *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v10; // ecx
  int v11; // ebp
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v15; // ecx
  int m_Right; // ecx
  int *v17; // edx
  int v18; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v19; // ecx
  int v20; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v21; // eax
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v24; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v25; // ecx
  int m_Left; // ecx
  int *v27; // eax
  int v28; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v29; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v30; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7[3] != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      if ( v9 == -1 )
        v12 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4122A4 = -1;
        dword_4122A8 = -1;
        dword_4122AC = 1;
      }
      v14 = v13 == -1
          ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v13];
      if ( *v14 == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4122A4 = -1;
          dword_4122A8 = -1;
          dword_4122AC = 1;
        }
        if ( v11 == -1 )
          v15 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4122A4 = -1;
          dword_4122A8 = -1;
          dword_4122AC = 1;
        }
        v17 = m_Right == -1
            ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Right];
        if ( v17[3] != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4122A4 = -1;
            dword_4122A8 = -1;
            dword_4122AC = 1;
          }
          v18 = elem;
          if ( elem == -1 )
          {
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          }
          else
          {
            v19 = &this->m_Elements.m_pMemory[elem];
            v18 = elem;
          }
          v20 = v19->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4122A4 = -1;
            dword_4122A8 = -1;
            dword_4122AC = 1;
          }
          if ( v20 == -1 )
            v21 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v21 = &this->m_Elements.m_pMemory[v20];
          if ( v21->m_Right == v18 )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
              this,
              elem: v9);
            v22 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v22 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4122A4 = -1;
              dword_4122A8 = -1;
              dword_4122AC = 1;
            }
            if ( v9 == -1 )
              v23 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v23 = &this->m_Elements.m_pMemory[v9];
            v9 = v23->m_Parent;
            if ( (v22 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
              `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4122A4 = -1;
              dword_4122A8 = -1;
              dword_4122AC = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v11 = v24->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4122A4 = -1;
          dword_4122A8 = -1;
          dword_4122AC = 1;
        }
        if ( v11 == -1 )
          v25 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[v11];
        m_Left = v25->m_Left;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4122A4 = -1;
          dword_4122A8 = -1;
          dword_4122AC = 1;
        }
        v27 = m_Left == -1
            ? &`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( v27[3] != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v28 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v28 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4122A4 = -1;
              dword_4122A8 = -1;
              dword_4122AC = 1;
            }
            if ( v9 == -1 )
              v29 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v29 = &this->m_Elements.m_pMemory[v9];
            v9 = v29->m_Parent;
            if ( (v28 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v28 | 1;
              `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_4122A4 = -1;
              dword_4122A8 = -1;
              dword_4122AC = 1;
            }
            if ( v9 == -1 )
              v30 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v30 = &this->m_Elements.m_pMemory[v9];
            v11 = v30->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402100
// Name: public: CFileChangeWatcher::CFileChangeWatcher(void)
// Source: json
//------------------------------------------------------------------------------
CFileChangeWatcher *__thiscall CFileChangeWatcher::CFileChangeWatcher(CFileChangeWatcher *this)
{
  this->m_DirWatches.m_Memory.m_pMemory = nullptr;
  this->m_DirWatches.m_Memory.m_nAllocationCount = 0;
  this->m_DirWatches.m_Memory.m_nGrowSize = 0;
  this->m_DirWatches.m_Size = 0;
  this->m_DirWatches.m_pElements = nullptr;
  this->m_pFileChangeFreeList = nullptr;
  this->m_pFileChangeAllocatedList = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402120
// Name: public: void CFileChangeWatcher::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileChangeWatcher::Term(CFileChangeWatcher *this)
{
  int i; // esi

  for ( i = 0; i < this->m_DirWatches.m_Size; ++i )
  {
    CloseHandle(hObject: this->m_DirWatches.m_Memory.m_pMemory[i]->m_hDir);
    CloseHandle(hObject: this->m_DirWatches.m_Memory.m_pMemory[i]->m_hEvent);
  }
  CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int>>::PurgeAndDeleteElements(this: &this->m_DirWatches);
}

//------------------------------------------------------------------------------
// Address: 0x00402160
// Name: public: CFileChangeWatcher::~CFileChangeWatcher(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileChangeWatcher::~CFileChangeWatcher(CFileChangeWatcher *this)
{
  CFileChangeWatcher::Term(this);
  CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int>>::~CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int>>(this: &this->m_DirWatches);
}

//------------------------------------------------------------------------------
// Address: 0x00402170
// Name: public: bool CFileChangeWatcher::AddDirectory(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileChangeWatcher::AddDirectory(
        CFileChangeWatcher *this,
        CFileChangeWatcher::CDirWatch *pFullDirName,
        bool bRecursive)
{
  const char *v3; // ebx
  HANDLE FileA; // edi
  char *v7; // esi

  v3 = (const char *)pFullDirName;
  FileA = CreateFileA(
            lpFileName: pFullDirName->m_FullDirName,
            dwDesiredAccess: 0x80000000,
            dwShareMode: 7u,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 3u,
            dwFlagsAndAttributes: 0x42000000u,
            hTemplateFile: nullptr);
  if ( FileA == (HANDLE)-1 )
  {
    _Warning(a1: "CFileChangeWatcher::AddDirectory - can't get a handle to directory %s.\n", v3);
    return 0;
  }
  else
  {
    v7 = (char *)operator new(nSize: 0x4120u);
    pFullDirName = (CFileChangeWatcher::CDirWatch *)v7;
    V_strncpy(pDest: v7, pSrc: v3, maxLen: 260);
    *((_DWORD *)v7 + 71) = FileA;
    *((_DWORD *)v7 + 70) = CreateEventA(
                             lpEventAttributes: nullptr,
                             bManualReset: false,
                             bInitialState: false,
                             lpName: nullptr);
    *(_QWORD *)(v7 + 260) = 0;
    *(_QWORD *)(v7 + 268) = 0;
    *((_DWORD *)v7 + 69) = 0;
    *((_DWORD *)v7 + 69) = *((_DWORD *)v7 + 70);
    if ( ReadDirectoryChangesW(
           hDirectory: *((HANDLE *)v7 + 71),
           lpBuffer: v7 + 288,
           nBufferLength: 0x4000u,
           bWatchSubtree: true,
           dwNotifyFilter: 0x19u,
           lpBytesReturned: nullptr,
           lpOverlapped: (LPOVERLAPPED)v7 + 13,
           lpCompletionRoutine: nullptr) )
    {
      CUtlVector<CFileChangeWatcher::CDirWatch *,CUtlMemory<CFileChangeWatcher::CDirWatch *,int>>::InsertBefore(
        this: &this->m_DirWatches,
        elem: this->m_DirWatches.m_Size,
        src: &pFullDirName);
      return 1;
    }
    else
    {
      CloseHandle(hObject: *((HANDLE *)v7 + 70));
      CloseHandle(hObject: *((HANDLE *)v7 + 71));
      free(pMem: v7);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402280
// Name: public: void CUtlDict<int,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,int>::RemoveAll(CUtlDict<int,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004022D0
// Name: public: class CFileChangeWatcher::CFileChange __near * CFileChangeWatcher::Update(void)
// Source: json
//------------------------------------------------------------------------------
CFileChangeWatcher::CFileChange *__thiscall CFileChangeWatcher::Update(CFileChangeWatcher *this)
{
  CFileChangeWatcher *v1; // esi
  CFileChangeWatcher::CFileChange *m_pFileChangeAllocatedList; // eax
  CFileChangeWatcher::CFileChange *m_pNext; // ecx
  bool v4; // zf
  CFileChangeWatcher::CFileChange *v5; // edi
  bool v6; // cc
  _OVERLAPPED *v7; // edi
  $A5A483E05FC9B52B872A8DCFA58CFF52 *v8; // edi
  unsigned int v9; // ebx
  unsigned int Offset; // esi
  char *v11; // eax
  int v12; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ecx
  int v14; // edx
  unsigned int v15; // esi
  int v16; // edx
  CUtlMap<char const *,int,int>::Node_t *p_m_Data; // esi
  int i; // ebx
  char *v19; // edi
  int v20; // ebp
  CFileChangeWatcher::CFileChange **p_m_pFileChangeFreeList; // ecx
  CFileChangeWatcher::CFileChange *m_pFileChangeFreeList; // eax
  CFileChangeWatcher::CFileChange *v23; // esi
  CFileChangeWatcher::CFileChange *v24; // edx
  int j; // esi
  void *InternalHigh; // [esp-10h] [ebp-1478h]
  bool leftchild[4]; // [esp+14h] [ebp-1454h] BYREF
  CFileChangeWatcher *v29; // [esp+18h] [ebp-1450h]
  int v30; // [esp+1Ch] [ebp-144Ch]
  CFileChangeWatcher::CFileChange *v31; // [esp+20h] [ebp-1448h]
  _OVERLAPPED *v32; // [esp+24h] [ebp-1444h]
  char *pSrc; // [esp+28h] [ebp-1440h]
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > v34; // [esp+2Ch] [ebp-143Ch] BYREF
  unsigned int NumberOfBytesTransferred; // [esp+50h] [ebp-1418h] BYREF
  CUtlMap<char const *,int,int>::Node_t insert; // [esp+54h] [ebp-1414h] BYREF
  int parent; // [esp+5Ch] [ebp-140Ch] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+60h] [ebp-1408h] BYREF
  char pUTF8[1024]; // [esp+68h] [ebp-1400h] BYREF
  wchar_t dst[2048]; // [esp+468h] [ebp-1000h] BYREF

  v1 = this;
  m_pFileChangeAllocatedList = this->m_pFileChangeAllocatedList;
  v29 = this;
  if ( m_pFileChangeAllocatedList != nullptr )
  {
    do
    {
      m_pNext = m_pFileChangeAllocatedList->m_pNext;
      v4 = m_pFileChangeAllocatedList->m_pNext == nullptr;
      m_pFileChangeAllocatedList->m_pNext = v1->m_pFileChangeFreeList;
      v1->m_pFileChangeFreeList = m_pFileChangeAllocatedList;
      m_pFileChangeAllocatedList = m_pNext;
    }
    while ( !v4 );
  }
  v5 = nullptr;
  v6 = v1->m_DirWatches.m_Size <= 0;
  v1->m_pFileChangeAllocatedList = nullptr;
  memset(&v34.m_Elements, 0, sizeof(v34.m_Elements));
  v34.m_Root = -1;
  v34.m_NumElements = 0;
  v34.m_FirstFree = -1;
  v34.m_LastAlloc.index = -1;
  v34.m_pElements = nullptr;
  v34.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  v31 = nullptr;
  v30 = 0;
  if ( !v6 )
  {
    do
    {
      v7 = (_OVERLAPPED *)v1->m_DirWatches.m_Memory.m_pMemory[v30];
      NumberOfBytesTransferred = 0;
      InternalHigh = (void *)v7[14].InternalHigh;
      v32 = v7;
      if ( GetOverlappedResult(
             hFile: InternalHigh,
             lpOverlapped: v7 + 13,
             lpNumberOfBytesTransferred: &NumberOfBytesTransferred,
             bWait: false) )
      {
        v8 = &v7[14].___u2;
        v9 = NumberOfBytesTransferred;
        if ( NumberOfBytesTransferred >= 0x10 )
        {
          do
          {
            Offset = v8[2].Offset;
            pSrc = (char *)v8;
            if ( Offset >= 0x7FF )
              Offset = 2047;
            memcpy((unsigned __int8 *)dst, src: (unsigned __int8 *)&v8[3], count: Offset);
            dst[(int)Offset / 2] = 0;
            V_UnicodeToUTF8(pUnicode: dst, pUTF8, cubDestSizeInBytes: 1024);
            search.key = pUTF8;
            if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                   this: &v34,
                   &search) == -1 )
            {
              v11 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pUTF8) + 1);
              if ( v11 != nullptr )
                strcpy(v11, pUTF8);
              else
                v11 = nullptr;
              insert.key = v11;
              insert.elem = 0;
              CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
                this: &v34,
                &insert,
                &parent,
                leftchild: &leftchild[3]);
              v12 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NewNode(this: &v34);
              m_pMemory = v34.m_Elements.m_pMemory;
              v14 = parent;
              v15 = v12;
              v4 = parent == -1;
              v34.m_Elements.m_pMemory[v15].m_Parent = parent;
              m_pMemory[v15].m_Right = -1;
              m_pMemory[v15].m_Left = -1;
              m_pMemory[v15].m_Tag = 0;
              if ( v4 )
              {
                v34.m_Root = v12;
              }
              else
              {
                v16 = v14;
                if ( leftchild[3] )
                  m_pMemory[v16].m_Left = v12;
                else
                  m_pMemory[v16].m_Right = v12;
              }
              CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
                this: &v34,
                elem: v12);
              ++v34.m_NumElements;
              p_m_Data = &v34.m_Elements.m_pMemory[v15].m_Data;
              if ( p_m_Data != nullptr )
                *p_m_Data = insert;
            }
            if ( v8->Offset == 0 )
              break;
            v8 = ($A5A483E05FC9B52B872A8DCFA58CFF52 *)((char *)v8 + v8->Offset);
            v9 -= *(_DWORD *)pSrc;
          }
          while ( v9 >= 0x10 );
          v1 = v29;
        }
        ReadDirectoryChangesW(
          hDirectory: (HANDLE)v32[14].InternalHigh,
          lpBuffer: &v32[14].___u2,
          nBufferLength: 0x4000u,
          bWatchSubtree: true,
          dwNotifyFilter: 0x19u,
          lpBytesReturned: nullptr,
          lpOverlapped: v32 + 13,
          lpCompletionRoutine: nullptr);
      }
      else
      {
        for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v34);
              i != -1;
              i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                    this: &v34,
                    i) )
        {
          pSrc = (char *)v34.m_Elements.m_pMemory[i].m_Data.key;
          v19 = pSrc;
          v20 = strlen(pSrc) + 1;
          p_m_pFileChangeFreeList = &v29->m_pFileChangeFreeList;
          m_pFileChangeFreeList = v29->m_pFileChangeFreeList;
          if ( m_pFileChangeFreeList != nullptr )
          {
            while ( m_pFileChangeFreeList->m_nBytesAvailableForFilename < v20 )
            {
              p_m_pFileChangeFreeList = &m_pFileChangeFreeList->m_pNext;
              m_pFileChangeFreeList = m_pFileChangeFreeList->m_pNext;
              if ( m_pFileChangeFreeList == nullptr )
                goto LABEL_27;
            }
            *p_m_pFileChangeFreeList = m_pFileChangeFreeList->m_pNext;
          }
          else
          {
LABEL_27:
            m_pFileChangeFreeList = (CFileChangeWatcher::CFileChange *)operator new(nSize: 8 * ((v20 + 34) / 8));
            m_pFileChangeFreeList->m_nBytesAvailableForFilename = 8 * ((v20 + 34) / 8) - 12;
            v19 = pSrc;
          }
          v23 = m_pFileChangeFreeList;
          V_strncpy(pDest: m_pFileChangeFreeList->m_RelativeFilename, pSrc: v19, maxLen: v20);
          v24 = v31;
          v23->m_pBaseDirName = (char *)v32;
          v23->m_pNext = v24;
          v31 = v23;
        }
        for ( j = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v34);
              j != -1;
              j = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                    this: &v34,
                    i: j) )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v34.m_Elements.m_pMemory[j].m_Data.key);
        }
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v34);
        ++v30;
        v1 = v29;
      }
    }
    while ( v30 < v1->m_DirWatches.m_Size );
    v5 = v31;
  }
  v1->m_pFileChangeAllocatedList = v5;
  CUtlDict<int,int>::RemoveAll(this: (CUtlDict<int,int> *)&v34);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v34);
  if ( v34.m_Elements.m_nGrowSize >= 0 && v34.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34.m_Elements.m_pMemory);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004026A0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
