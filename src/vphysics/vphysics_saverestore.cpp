// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/vphysics_saverestore.cpp
// Functions: 119
// ============================================================

#include "vphysics\vphysics_saverestore.h"

//------------------------------------------------------------------------------
// Address: 0x100033A0
// Name: public: void CUtlMemory<class CPhysicsCollisionSet,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPhysicsCollisionSet,int>::Grow(CUtlMemory<CPhysicsCollisionSet,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CPhysicsCollisionSet *m_pMemory; // edx
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
    v7 = 132 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CPhysicsCollisionSet *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CPhysicsCollisionSet *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007F80
// Name: public: void CUtlMemory<struct bboxcache_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bboxcache_t,int>::Grow(CUtlMemory<bboxcache_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  bboxcache_t *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (bboxcache_t *)_g_pMemAlloc->Realloc_2(
                                         this: _g_pMemAlloc,
                                         a2: m_pMemory,
                                         a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (bboxcache_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100104A0
// Name: protected: enum CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::NodeColor_t CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Color(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> >::NodeColor_t __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Color(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100FC8CC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(dword_100FC8CC);
  else
    return this->m_Elements.m_pMemory[i].m_Tag;
}

//------------------------------------------------------------------------------
// Address: 0x10010510
// Name: protected: bool CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::IsBlack(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::IsBlack(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100FC8CC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(dword_100FC8CC) == 1;
  else
    return this->m_Elements.m_pMemory[i].m_Tag == 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010BC0
// Name: public: unsigned short CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100FC8CC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_100FC8CC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x10010C30
// Name: public: unsigned short CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100FC8CC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10010C90
// Name: public: unsigned short CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100FC8CC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10010D00
// Name: protected: void CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CPhysicsListenerCollision::corepair_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        const CPhysicsListenerCollision::corepair_t *insert,
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
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010E80
// Name: public: unsigned short CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *v12; // edx

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
      CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>::Grow(
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
// Address: 0x10010F80
// Name: protected: void CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10011080
// Name: protected: void CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10011180
// Name: protected: void CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
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
    v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateRight(
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
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x10011990
// Name: public: unsigned short CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Find(struct CPhysicsListenerCollision::corepair_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        const CPhysicsListenerCollision::corepair_t *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10011A90
// Name: public: unsigned short CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011B60
// Name: public: unsigned short CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // si
  int v4; // edx
  int result; // eax
  int *v6; // ecx
  int v7; // edx
  int *v8; // ecx
  int v9; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i) == 0xFFFF )
  {
    LOWORD(result) = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                       this,
                       i);
    v7 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    for ( result = (unsigned __int16)result; ; result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Parent )
    {
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      v10 = (_WORD)v9 == 0xFFFF
          ? &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v9];
      if ( *((_WORD *)v10 + 1) != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
    }
  }
  else
  {
    LOWORD(result) = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
                       this,
                       i);
    v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    result = (unsigned __int16)result;
    while ( 1 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( *(_WORD *)v6 == 0xFFFF )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)result == 0xFFFF )
        result = (unsigned __int16)`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011EB0
// Name: public: void CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x10011F70
// Name: protected: void CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011FF0
// Name: protected: void CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RemoveRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RemoveRebalance(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int *v6; // ecx
  unsigned __int16 v7; // bx
  int *v8; // ecx
  int *v9; // ecx
  int v10; // edi
  int *v11; // ecx
  int *v12; // ecx
  int *v13; // ecx
  int *v14; // ecx
  int v15; // ecx
  int *v16; // ecx
  int *v17; // eax
  int *v18; // ecx
  int v19; // ecx
  int *v20; // ecx
  int *v21; // eax
  int *v22; // ecx
  int *v23; // ecx
  int *v24; // ecx
  int v25; // eax
  int *v26; // ecx
  int *v27; // ecx
  int v28; // edi
  int *v29; // ecx
  int *v30; // ecx
  int *v31; // ecx
  int *v32; // ecx
  int v33; // ecx
  int *v34; // ecx
  UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *v35; // eax
  int *v36; // ecx
  int v37; // ecx
  int *v38; // ecx
  int *v39; // eax
  int *v40; // ecx
  int *v41; // ecx
  int *v42; // ecx
  int v43; // eax
  int *v44; // ecx
  unsigned __int16 parent; // [esp+4h] [ebp-4h]

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      if ( *((_WORD *)v5 + 3) != 1 )
        goto LABEL_182;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v6 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v6 = (int *)&this->m_Elements.m_pMemory[v2];
      v7 = *((_WORD *)v6 + 2);
      parent = v7;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v8 = v7 == 0xFFFF
         ? &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[v7];
      if ( v2 != *(_WORD *)v8 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      if ( v7 == 0xFFFF )
        v9 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v9 = (int *)&this->m_Elements.m_pMemory[v7];
      v10 = *((unsigned __int16 *)v9 + 1);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      if ( (_WORD)v10 == 0xFFFF )
        v11 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v11 = (int *)&this->m_Elements.m_pMemory[v10];
      if ( *((_WORD *)v11 + 3) == 0 )
      {
        this->m_Elements.m_pMemory[v10].m_Tag = 1;
        this->m_Elements.m_pMemory[v7].m_Tag = 0;
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v7);
        v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
        if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
             | 1;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v12 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v12 = (int *)&this->m_Elements.m_pMemory[elem];
        v7 = *((_WORD *)v12 + 2);
        parent = v7;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        if ( v7 == 0xFFFF )
          v13 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v13 = (int *)&this->m_Elements.m_pMemory[v7];
        LOWORD(v10) = *((_WORD *)v13 + 1);
      }
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      if ( (_WORD)v10 == 0xFFFF )
        v14 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
      v15 = *(unsigned __int16 *)v14;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v15 == 0xFFFF )
        v16 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v16 = (int *)&this->m_Elements.m_pMemory[v15];
      if ( *((_WORD *)v16 + 3) != 1 )
        goto LABEL_61;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      if ( (_WORD)v10 == 0xFFFF )
        v17 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
      if ( !CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::IsBlack(
              this,
              i: *((_WORD *)v17 + 1)) )
      {
        v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
LABEL_61:
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v18 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
        v19 = *((unsigned __int16 *)v18 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 3) == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100FC8CC = 0x1FFFF;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v21 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v21 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
          this->m_Elements.m_pMemory[*(unsigned __int16 *)v21].m_Tag = 1;
          this->m_Elements.m_pMemory[(unsigned __int16)v10].m_Tag = 0;
          CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v10);
          v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100FC8CC = 0x1FFFF;
          }
          if ( elem == 0xFFFF )
            v22 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[elem];
          v7 = *((_WORD *)v22 + 2);
          parent = v7;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100FC8CC = 0x1FFFF;
          }
          if ( v7 == 0xFFFF )
            v23 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v7];
          LOWORD(v10) = *((_WORD *)v23 + 1);
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        if ( v7 == 0xFFFF )
          v24 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v7];
        v25 = (unsigned __int16)v10;
        this->m_Elements.m_pMemory[v25].m_Tag = *((_WORD *)v24 + 3);
        this->m_Elements.m_pMemory[v7].m_Tag = 1;
        if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v26 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[v25];
        this->m_Elements.m_pMemory[*((unsigned __int16 *)v26 + 1)].m_Tag = 1;
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: parent);
        goto LABEL_180;
      }
      if ( (_WORD)v10 == 0xFFFF )
        goto LABEL_140;
      this->m_Elements.m_pMemory[(unsigned __int16)v10].m_Tag = 0;
      elem = v7;
LABEL_181:
      v2 = elem;
      if ( elem == this->m_Root )
        goto LABEL_182;
    }
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
    }
    if ( v7 == 0xFFFF )
      v27 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v27 = (int *)&this->m_Elements.m_pMemory[v7];
    v28 = *(unsigned __int16 *)v27;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
    }
    if ( (_WORD)v28 == 0xFFFF )
      v29 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v29 = (int *)&this->m_Elements.m_pMemory[v28];
    if ( *((_WORD *)v29 + 3) == 0 )
    {
      this->m_Elements.m_pMemory[v28].m_Tag = 1;
      this->m_Elements.m_pMemory[v7].m_Tag = 0;
      CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateRight(
        this,
        elem: v7);
      v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      if ( elem == 0xFFFF )
        v30 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v30 = (int *)&this->m_Elements.m_pMemory[elem];
      v7 = *((_WORD *)v30 + 2);
      parent = v7;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      if ( v7 == 0xFFFF )
        v31 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v31 = (int *)&this->m_Elements.m_pMemory[v7];
      LOWORD(v28) = *(_WORD *)v31;
    }
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
    }
    if ( (_WORD)v28 == 0xFFFF )
      v32 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v32 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v28];
    v33 = *((unsigned __int16 *)v32 + 1);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v33 == 0xFFFF )
      v34 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v34 = (int *)&this->m_Elements.m_pMemory[v33];
    if ( *((_WORD *)v34 + 3) != 1 )
      goto LABEL_142;
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
    }
    if ( (_WORD)v28 == 0xFFFF )
      v35 = (UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *)&`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v35 = &this->m_Elements.m_pMemory[(unsigned __int16)v28];
    if ( !CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::IsBlack(
            this,
            i: v35->m_Left) )
    {
      v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
LABEL_142:
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      if ( (_WORD)v28 == 0xFFFF )
        v36 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v36 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v28];
      v37 = *(unsigned __int16 *)v36;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v37 == 0xFFFF )
        v38 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v38 = (int *)&this->m_Elements.m_pMemory[v37];
      if ( *((_WORD *)v38 + 3) == 1 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        if ( (_WORD)v28 == 0xFFFF )
          v39 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v39 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v28];
        this->m_Elements.m_pMemory[*((unsigned __int16 *)v39 + 1)].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v28].m_Tag = 0;
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v28);
        v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
        if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v4 = `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
             | 1;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v40 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v40 = (int *)&this->m_Elements.m_pMemory[elem];
        v7 = *((_WORD *)v40 + 2);
        parent = v7;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        if ( v7 == 0xFFFF )
          v41 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v41 = (int *)&this->m_Elements.m_pMemory[v7];
        LOWORD(v28) = *(_WORD *)v41;
      }
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      if ( v7 == 0xFFFF )
        v42 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v42 = (int *)&this->m_Elements.m_pMemory[v7];
      v43 = (unsigned __int16)v28;
      this->m_Elements.m_pMemory[v43].m_Tag = *((_WORD *)v42 + 3);
      this->m_Elements.m_pMemory[v7].m_Tag = 1;
      if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FC8CC = 0x1FFFF;
      }
      if ( (_WORD)v28 == 0xFFFF )
        v44 = &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v44 = (int *)&this->m_Elements.m_pMemory[v43];
      this->m_Elements.m_pMemory[*(unsigned __int16 *)v44].m_Tag = 1;
      CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RotateRight(
        this,
        elem: parent);
LABEL_180:
      elem = this->m_Root;
      goto LABEL_181;
    }
    if ( (_WORD)v28 != 0xFFFF )
      this->m_Elements.m_pMemory[(unsigned __int16)v28].m_Tag = 0;
LABEL_140:
    elem = v7;
    goto LABEL_181;
  }
LABEL_182:
  this->m_Elements.m_pMemory[v2].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013430
// Name: protected: void CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Unlink(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 i; // ax
  unsigned __int16 v4; // di
  int *v5; // eax
  unsigned __int16 v6; // bx
  unsigned __int16 v7; // ax
  int v8; // ebx
  unsigned __int16 v9; // ax
  CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> >::NodeColor_t ycolor; // [esp+8h] [ebp-8h]
  unsigned __int16 x; // [esp+Ch] [ebp-4h]

  if ( elem != 0xFFFF )
  {
    if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: elem) == 0xFFFF
      || CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: elem) == 0xFFFF )
    {
      v4 = elem;
    }
    else
    {
      for ( i = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
                  this,
                  i: elem);
            ;
            i = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
                  this,
                  i: v4) )
      {
        v4 = i;
        if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FC8CC = 0x1FFFF;
        }
        v5 = i == 0xFFFF
           ? &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
           : (int *)&this->m_Elements.m_pMemory[i];
        if ( *(_WORD *)v5 == 0xFFFF )
          break;
      }
    }
    if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v4) == 0xFFFF )
    {
      x = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
            this,
            i: v4);
      v6 = x;
    }
    else
    {
      v6 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
             this,
             i: v4);
      x = v6;
    }
    if ( v6 != 0xFFFF )
      this->m_Elements.m_pMemory[v6].m_Parent = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                                  this,
                                                  i: v4);
    if ( v4 == this->m_Root )
    {
      this->m_Root = v6;
    }
    else
    {
      v7 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
             this,
             i: v4);
      if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
             this,
             i: v7) == v4 )
        this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                     this,
                                     i: v4)].m_Left = v6;
      else
        this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                     this,
                                     i: v4)].m_Right = v6;
    }
    ycolor = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Color(
               this,
               i: v4);
    if ( v4 != elem )
    {
      v8 = v4;
      this->m_Elements.m_pMemory[v8].m_Parent = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                                  this,
                                                  i: elem);
      this->m_Elements.m_pMemory[v8].m_Right = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
                                                 this,
                                                 i: elem);
      this->m_Elements.m_pMemory[v8].m_Left = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
                                                this,
                                                i: elem);
      if ( elem == this->m_Root )
      {
        this->m_Root = v4;
      }
      else
      {
        v9 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
               this,
               i: elem);
        if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: v9) == elem )
          this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                       this,
                                       i: elem)].m_Left = v4;
        else
          this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Parent(
                                       this,
                                       i: elem)].m_Right = v4;
      }
      if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
             this,
             i: v4) != 0xFFFF )
        this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
                                     this,
                                     i: v4)].m_Parent = v4;
      if ( CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
             this,
             i: v4) != 0xFFFF )
        this->m_Elements.m_pMemory[CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RightChild(
                                     this,
                                     i: v4)].m_Parent = v4;
      this->m_Elements.m_pMemory[v8].m_Tag = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Color(
                                               this,
                                               i: elem);
      v6 = x;
    }
    if ( v6 != 0xFFFF && ycolor == BLACK )
      CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RemoveRebalance(
        this,
        elem: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100144C0
// Name: public: CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::~CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x10014530
// Name: public: unsigned short CUtlRBTree<struct CPhysicsListenerCollision::corepair_t,unsigned short,bool (*)(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Insert(struct CPhysicsListenerCollision::corepair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *this,
        const CPhysicsListenerCollision::corepair_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100171E0
// Name: public: void CUtlMemory<class CSurface,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSurface,int>::Grow(CUtlMemory<CSurface,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSurface *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSurface *)_g_pMemAlloc->Realloc_2(
                                      this: _g_pMemAlloc,
                                      a2: m_pMemory,
                                      a3: 120 * m_nAllocationCount);
    else
      this->m_pMemory = (CSurface *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 120 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017290
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbol *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033660
// Name: public: virtual bool CPhysicsEnvironment::Save(struct physsaveparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsEnvironment::Save(CPhysicsEnvironment *this, const physsaveparams_t *params)
{
  PhysInterfaceId_t type; // ebx

  type = params->type;
  if ( (unsigned int)type > PIID_IPHYSICSGAMETRACE )
    return false;
  ((void (__stdcall *)(void **, int))params->pSave->WriteInt_2)(a1: &params->pObject, a2: 1);
  return saveFuncs[type](a1: params, a2: params->pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100336A0
// Name: public: virtual void CVPhysPtrSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysPtrSaveRestoreOps::Save(
        CVPhysPtrSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  const int *pField; // esi
  typedescription_t *pTypeDesc; // eax
  int fieldSize; // ebx

  pField = (const int *)fieldInfo->pField;
  pTypeDesc = fieldInfo->pTypeDesc;
  fieldSize = pTypeDesc->fieldSize;
  if ( pTypeDesc->fieldSize != 0 )
  {
    do
    {
      pSave->WriteInt_2(this: pSave, a2: pField++, a3: 1);
      --fieldSize;
    }
    while ( fieldSize != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100336E0
// Name: public: static bool CDefOps<void __near *>::LessFunc(void __near * const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<void *>::LessFunc(void *const *lhs, void *const *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x10033700
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100337B0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100FCD9C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_100FCD9C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x10033810
// Name: public: virtual void CVPhysPtrUtlVectorSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysPtrUtlVectorSaveRestoreOps::Save(
        CVPhysPtrUtlVectorSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  _DWORD *pField; // ebx
  ISave *v4; // edi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  int i; // esi

  pField = fieldInfo->pField;
  v4 = pSave;
  WriteInt_2 = pSave->WriteInt_2;
  fieldInfo = *((const SaveRestoreFieldInfo_t **)fieldInfo->pField + 3);
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  for ( i = 0; i < (int)fieldInfo; ++i )
    v4->WriteInt_2(this: v4, a2: (const int *)(*pField + 4 * i), a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10033860
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100FCD9C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x100338C0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100FCD9C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10033920
// Name: protected: void CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<void *,void *,unsigned short>::Node_t *insert,
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
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FCD9C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FCD9C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033A10
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short> *v12; // edx

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
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
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
// Address: 0x10033B10
// Name: protected: void CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10033C00
// Name: protected: void CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10033CF0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<void *,void *,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FCD9C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FCD9C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10033DF0
// Name: public: void CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x10033EA0
// Name: protected: void CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // ecx
  int v11; // ebx
  int *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  int *v15; // ecx
  int v16; // edx
  int *v17; // ecx
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int *v30; // eax
  int *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FCD9C = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FCD9C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FCD9C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FCD9C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FCD9C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100FCD9C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FCD9C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FCD9C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FCD9C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FCD9C = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100FCD9C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100FCD9C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FCD9C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FCD9C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v25 + 3) == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v16].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FCD9C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100FCD9C = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100FCD9C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100FCD9C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034490
// Name: public: CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x10034500
// Name: public: virtual void CVPhysPtrSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysPtrSaveRestoreOps::Restore(
        CVPhysPtrSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  int *pField; // esi
  int fieldSize; // ebx
  unsigned __int16 v5; // ax
  CUtlMap<void *,void *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  pField = (int *)fieldInfo->pField;
  if ( fieldInfo->pTypeDesc->fieldSize != 0 )
  {
    fieldSize = fieldInfo->pTypeDesc->fieldSize;
    do
    {
      pRestore->ReadInt_2(this: pRestore, a2: pField, a3: 1, a4: 0);
      search.key = (void *)*pField;
      v5 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &s_VPhysPtrMap.m_Tree,
             &search);
      if ( v5 == 0xFFFF )
        *pField = 0;
      else
        *pField = (int)s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
      ++pField;
      --fieldSize;
    }
    while ( fieldSize != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034570
// Name: public: virtual void CPhysicsEnvironment::PostRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::PostRestore(CPhysicsEnvironment *this)
{
  CPhysicsEnvironment::UpdateDeleteHighMark(this);
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &s_VPhysPtrMap.m_Tree);
  PostRestorePhysicsObject();
  PostRestorePhysicsConstraintGroup();
}

//------------------------------------------------------------------------------
// Address: 0x10034590
// Name: public: virtual void CVPhysPtrUtlVectorSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysPtrUtlVectorSaveRestoreOps::Restore(
        CVPhysPtrUtlVectorSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  CUtlVector<int,CUtlMemory<int,int> > *v3; // esi
  IRestore *v4; // edi
  int (__thiscall *ReadInt_2)(IRestore *, int *, int, int); // edx
  int v6; // ebx
  void **v7; // esi
  unsigned __int16 v8; // ax
  CUtlMap<void *,void *,unsigned short>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  CUtlVector<int,CUtlMemory<int,int> > *pUtlVector; // [esp+14h] [ebp-4h]

  v4 = pRestore;
  ReadInt_2 = pRestore->ReadInt_2;
  pUtlVector = (CUtlVector<int,CUtlMemory<int,int> > *)fieldInfo->pField;
  v3 = pUtlVector;
  ReadInt_2(this: pRestore, a2: (int *)&fieldInfo, a3: 1, a4: 0);
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::InsertMultipleBefore(
    this: v3,
    elem: v3->m_Size,
    num: (int)fieldInfo);
  v6 = 0;
  if ( (int)fieldInfo > 0 )
  {
    while ( 1 )
    {
      v7 = (void **)&v3->m_Memory.m_pMemory[v6];
      v4->ReadInt_2(this: v4, a2: (int *)v7, a3: 1, a4: 0);
      search.key = *v7;
      v8 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &s_VPhysPtrMap.m_Tree,
             &search);
      *v7 = v8 == 0xFFFF ? nullptr : s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
      if ( ++v6 >= (int)fieldInfo )
        break;
      v3 = pUtlVector;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034630
// Name: AddPtrAssociation
// Source: json
//------------------------------------------------------------------------------
void __usercall AddPtrAssociation(void *pOldValue@<eax>, void *pNewValue@<ecx>)
{
  unsigned __int16 v2; // cx
  int v3; // esi
  UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short> *v4; // eax
  unsigned __int16 v5; // dx
  int v6; // edx
  CUtlMap<void *,void *,unsigned short>::Node_t insert; // [esp+8h] [ebp-10h] BYREF
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  insert.key = pOldValue;
  insert.elem = pNewValue;
  *(_DWORD *)parent = 0xFFFF;
  leftchild = false;
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: &s_VPhysPtrMap.m_Tree,
    &insert,
    parent,
    &leftchild);
  v2 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &s_VPhysPtrMap.m_Tree);
  v3 = v2;
  v4 = &s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v2];
  v5 = parent[0];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = v5;
  v4->m_Tag = 0;
  if ( v5 == 0xFFFF )
  {
    s_VPhysPtrMap.m_Tree.m_Root = v2;
  }
  else
  {
    v6 = v5;
    if ( leftchild )
      s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v6].m_Left = v2;
    else
      s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v6].m_Right = v2;
  }
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
    this: &s_VPhysPtrMap.m_Tree,
    elem: v2);
  ++s_VPhysPtrMap.m_Tree.m_NumElements;
  if ( &s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v3] != (UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short> *)-8 )
    s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v3].m_Data = insert;
}

//------------------------------------------------------------------------------
// Address: 0x10034700
// Name: public: virtual void CPhysicsEnvironment::PreRestore(struct physprerestoreparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::PreRestore(CPhysicsEnvironment *this, const physprerestoreparams_t *params)
{
  bool v2; // cc
  void **p_pNewObject; // edi
  void *v4; // ecx
  unsigned __int16 v5; // cx
  int v6; // esi
  UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short> *v7; // eax
  unsigned __int16 v8; // dx
  int v9; // edx
  CUtlMap<void *,void *,unsigned short>::Node_t insert; // [esp+4h] [ebp-14h] BYREF
  int i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = params->recreatedObjectCount <= 0;
  i = 0;
  if ( !v2 )
  {
    p_pNewObject = &params->recreatedObjectList[0].pNewObject;
    do
    {
      v4 = *p_pNewObject;
      insert.key = *(p_pNewObject - 1);
      insert.elem = v4;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &s_VPhysPtrMap.m_Tree,
        &insert,
        parent,
        &leftchild);
      v5 = CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &s_VPhysPtrMap.m_Tree);
      v6 = v5;
      v7 = &s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v5];
      v8 = parent[0];
      v7->m_Right = -1;
      v7->m_Left = -1;
      v7->m_Parent = v8;
      v7->m_Tag = 0;
      if ( v8 == 0xFFFF )
      {
        s_VPhysPtrMap.m_Tree.m_Root = v5;
      }
      else
      {
        v9 = v8;
        if ( leftchild )
          s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v9].m_Left = v5;
        else
          s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v9].m_Right = v5;
      }
      CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        this: &s_VPhysPtrMap.m_Tree,
        elem: v5);
      ++s_VPhysPtrMap.m_Tree.m_NumElements;
      if ( &s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short> *)-8 )
        s_VPhysPtrMap.m_Tree.m_Elements.m_pMemory[v6].m_Data = insert;
      p_pNewObject += 2;
      ++i;
    }
    while ( i < params->recreatedObjectCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034800
// Name: public: virtual bool CPhysicsEnvironment::Restore(struct physrestoreparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsEnvironment::Restore(CPhysicsEnvironment *this, const physrestoreparams_t *params)
{
  const physrestoreparams_t *v2; // esi
  PhysInterfaceId_t type; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IPhysicsObject **m_pMemory; // ecx
  int v8; // eax
  IPhysicsObject **v9; // eax
  IPhysicsObject *v11; // [esp+Ch] [ebp-4h]

  v2 = params;
  type = params->type;
  if ( (unsigned int)type > PIID_IPHYSICSGAMETRACE )
    return 0;
  params->pRestore->ReadInt_2(this: params->pRestore, a2: (int *)&params, a3: 1, a4: 0);
  if ( !restoreFuncs[type](a1: v2, a2: v2->ppObject) )
    return 0;
  AddPtrAssociation(pOldValue: (void *)params, pNewValue: *v2->ppObject);
  if ( type == PIID_IPHYSICSOBJECT )
  {
    m_Size = this->m_objects.m_Size;
    m_nAllocationCount = this->m_objects.m_Memory.m_nAllocationCount;
    v11 = (IPhysicsObject *)*v2->ppObject;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_objects,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_objects.m_Size;
    m_pMemory = this->m_objects.m_Memory.m_pMemory;
    v8 = this->m_objects.m_Size - m_Size - 1;
    this->m_objects.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_objects.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = v11;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ACD40
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD900
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
// Address: 0x100ADA00
// Name: public: void CUtlMemory<class CPredictedPhysicsObject __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this,
        int num)
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
// Address: 0x100ADA90
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
    dword_1010F764 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_1010F764;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x100ADC10
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
    dword_1010F764 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x100ADC70
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
    dword_1010F764 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100ADCE0
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
        dword_1010F764 = 0x1FFFF;
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
        dword_1010F764 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADDD0
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
// Address: 0x100ADED0
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
// Address: 0x100AE010
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
        dword_1010F764 = 0x1FFFF;
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
        dword_1010F764 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x100AE110
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
// Address: 0x100AE1D0
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
      dword_1010F764 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1010F764 = 0x1FFFF;
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
      dword_1010F764 = 0x1FFFF;
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
      dword_1010F764 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1010F764 = 0x1FFFF;
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
      dword_1010F764 = 0x1FFFF;
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
        dword_1010F764 = 0x1FFFF;
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
        dword_1010F764 = 0x1FFFF;
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
          dword_1010F764 = 0x1FFFF;
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
          dword_1010F764 = 0x1FFFF;
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
        dword_1010F764 = 0x1FFFF;
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
        dword_1010F764 = 0x1FFFF;
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
          dword_1010F764 = 0x1FFFF;
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
          dword_1010F764 = 0x1FFFF;
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
// Address: 0x100AE7E0
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
// Address: 0x100AE8E0
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
// Address: 0x100AE970
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

//------------------------------------------------------------------------------
// Address: 0x100C6780
// Name: _dynamic_initializer_for__vphys_sleep_timeout_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vphys_sleep_timeout_command__()
{
  ConCommand::ConCommand(
    this: &vphys_sleep_timeout_command,
    pName: "vphys_sleep_timeout",
    callback: vphys_sleep_timeout,
    pHelpString: "set sleep timeout: large values mean stuff won't ever sleep",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vphys_sleep_timeout_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6920
// Name: _dynamic_initializer_for__vphysics_threadmode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vphysics_threadmode__()
{
  ConVar::ConVar(this: &vphysics_threadmode, pName: "vphysics_threadmode", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vphysics_threadmode__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6EC0
// Name: _dynamic_atexit_destructor_for__vphys_sleep_timeout_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vphys_sleep_timeout_command__()
{
  ConCommand::~ConCommand(this: &vphys_sleep_timeout_command);
}

//------------------------------------------------------------------------------
// Address: 0x100C7030
// Name: _dynamic_atexit_destructor_for__vphysics_threadmode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vphysics_threadmode__()
{
  ConVar::~ConVar(this: &vphysics_threadmode);
}

//------------------------------------------------------------------------------
// Address: 0x100C67B0
// Name: _dynamic_initializer_for__g_PhysicsCollision__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PhysicsCollision__()
{
  CPhysicsTrace::CPhysicsTrace(this: &g_PhysicsCollision.m_traceapi);
  g_PhysicsCollision.m_bboxCache.m_Memory.m_pMemory = nullptr;
  g_PhysicsCollision.m_bboxCache.m_Memory.m_nAllocationCount = 0;
  g_PhysicsCollision.m_bboxCache.m_Memory.m_nGrowSize = 0;
  g_PhysicsCollision.m_bboxCache.m_Size = 0;
  g_PhysicsCollision.m_bboxCache.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_PhysicsCollision__);
}

//------------------------------------------------------------------------------
// Address: 0x100C67F0
// Name: _dynamic_initializer_for____g_CreateCPhysicsCollisionIPhysicsCollision_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCPhysicsCollisionIPhysicsCollision_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCPhysicsCollisionIPhysicsCollision_reg,
           fn: _CreateCPhysicsCollisionIPhysicsCollision_interface,
           pName: "VPhysicsCollision007");
}

//------------------------------------------------------------------------------
// Address: 0x100C6950
// Name: _dynamic_initializer_for__g_PhysicsMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PhysicsMutex__()
{
  g_PhysicsMutex.m_ownerID = 0;
  g_PhysicsMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C6960
// Name: _dynamic_initializer_for__g_cv_phys_enable_query_cache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_phys_enable_query_cache__()
{
  ConVar::ConVar(this: &g_cv_phys_enable_query_cache, pName: "phys_enable_query_cache", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_phys_enable_query_cache__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6990
// Name: _dynamic_initializer_for__cv_phys_enable_simd_optimizations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_phys_enable_simd_optimizations__()
{
  ConVar::ConVar(
    this: &cv_phys_enable_simd_optimizations,
    pName: "phys_enable_simd_optimizations",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "enable some additional SIMD/VMX128 optimizations in physics and collision");
  return atexit(func: dynamic_atexit_destructor_for__cv_phys_enable_simd_optimizations__);
}

//------------------------------------------------------------------------------
// Address: 0x100C69C0
// Name: _dynamic_initializer_for__cv_phys_enable_experimental_optimizations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_phys_enable_experimental_optimizations__()
{
  ConVar::ConVar(
    this: &cv_phys_enable_experimental_optimizations,
    pName: "phys_enable_experimental_optimizations",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "enable some experimental SIMD/VMX128 optimizations in physics and collision");
  return atexit(func: dynamic_atexit_destructor_for__cv_phys_enable_experimental_optimizations__);
}

//------------------------------------------------------------------------------
// Address: 0x100C69F0
// Name: _dynamic_initializer_for__cv_phys_enable_PIX_counters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cv_phys_enable_PIX_counters__()
{
  ConVar::ConVar(
    this: &cv_phys_enable_PIX_counters,
    pName: "phys_enable_PIX_counters",
    pDefaultValue: "1",
    flags: 16386,
    pHelpString: "enable PIX counters");
  return atexit(func: dynamic_atexit_destructor_for__cv_phys_enable_PIX_counters__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6A20
// Name: _dynamic_initializer_for__s_StubPredictableController__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StubPredictableController__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_StubPredictableController__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6A30
// Name: _dynamic_initializer_for__g_cvPhysPMC__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cvPhysPMC__()
{
  ConVar::ConVar(this: &g_cvPhysPMC, pName: "PhysPMC", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_cvPhysPMC__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6A60
// Name: _dynamic_initializer_for__g_SurfaceDatabase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SurfaceDatabase__()
{
  CPhysicsSurfaceProps::CPhysicsSurfaceProps(this: &g_SurfaceDatabase);
  return atexit(func: dynamic_atexit_destructor_for__g_SurfaceDatabase__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6A80
// Name: _dynamic_initializer_for____g_CreateCPhysicsSurfacePropsIPhysicsSurfaceProps_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCPhysicsSurfacePropsIPhysicsSurfaceProps_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCPhysicsSurfacePropsIPhysicsSurfaceProps_reg,
           fn: _CreateCPhysicsSurfacePropsIPhysicsSurfaceProps_interface,
           pName: "VPhysicsSurfaceProps001");
}

//------------------------------------------------------------------------------
// Address: 0x100C6ED0
// Name: _dynamic_atexit_destructor_for__g_MainDLLInterface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MainDLLInterface__()
{
  CUtlVector<CPhysicsCollisionSet,CUtlMemory<CPhysicsCollisionSet,int>>::Purge(this: &g_MainDLLInterface.m_collisionSets);
  if ( g_MainDLLInterface.m_collisionSets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_MainDLLInterface.m_collisionSets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_MainDLLInterface.m_collisionSets.m_Memory.m_pMemory);
      g_MainDLLInterface.m_collisionSets.m_Memory.m_pMemory = nullptr;
    }
    g_MainDLLInterface.m_collisionSets.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MainDLLInterface.m_envList);
}

//------------------------------------------------------------------------------
// Address: 0x100C6F20
// Name: _dynamic_atexit_destructor_for__fast_poly_convert__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fast_poly_convert__()
{
  ConVar::~ConVar(this: &fast_poly_convert);
}

//------------------------------------------------------------------------------
// Address: 0x100C6F30
// Name: _dynamic_atexit_destructor_for__g_PhysicsCollision__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PhysicsCollision__()
{
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_PhysicsCollision.m_bboxCache);
  CEmptyCollisionListener::PostSimulationFrame(this: (CDataManagerBase *)&g_PhysicsCollision.m_traceapi);
  g_PhysicsCollision.__vftable = (CPhysicsCollision_vtbl *)&IPhysicsCollision::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100C6F50
// Name: _DataMapInit_physcollideheader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_physcollideheader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x100C6F60
// Name: _DataMapInit_compactsurfaceheader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_compactsurfaceheader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x100C6F70
// Name: _DataMapInit_vphysics_save_cphysicsconstraintgroup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_cphysicsconstraintgroup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

//------------------------------------------------------------------------------
// Address: 0x100C6F80
// Name: _dynamic_atexit_destructor_for__g_ConstraintGroupActivateList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ConstraintGroupActivateList__()
{
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_ConstraintGroupActivateList);
}

//------------------------------------------------------------------------------
// Address: 0x100C6F90
// Name: _DataMapInit_vphysics_save_cphysicsconstraint_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_cphysicsconstraint_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

//------------------------------------------------------------------------------
// Address: 0x100C6FA0
// Name: _DataMapInit_vphysics_save_constraintbreakable_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_constraintbreakable_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x100C6FB0
// Name: _DataMapInit_vphysics_save_constraintaxislimit_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_constraintaxislimit_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_4);
}

//------------------------------------------------------------------------------
// Address: 0x100C6FC0
// Name: _DataMapInit_vphysics_save_constraintfixed_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_constraintfixed_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_5);
}

//------------------------------------------------------------------------------
// Address: 0x100C6FD0
// Name: _DataMapInit_vphysics_save_constrainthinge_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_constrainthinge_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_6);
}

//------------------------------------------------------------------------------
// Address: 0x100C6FE0
// Name: _DataMapInit_vphysics_save_constraintsliding_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_constraintsliding_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_7);
}

//------------------------------------------------------------------------------
// Address: 0x100C6FF0
// Name: _DataMapInit_vphysics_save_constraintpulley_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_constraintpulley_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_8);
}

//------------------------------------------------------------------------------
// Address: 0x100C7000
// Name: _DataMapInit_vphysics_save_constraintlength_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_constraintlength_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_9);
}

//------------------------------------------------------------------------------
// Address: 0x100C7010
// Name: _DataMapInit_vphysics_save_constraintballsocket_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_constraintballsocket_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_10);
}

//------------------------------------------------------------------------------
// Address: 0x100C7020
// Name: _DataMapInit_vphysics_save_constraintragdoll_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_constraintragdoll_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_11);
}

//------------------------------------------------------------------------------
// Address: 0x100C7040
// Name: _dynamic_atexit_destructor_for__g_cv_phys_enable_query_cache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_phys_enable_query_cache__()
{
  ConVar::~ConVar(this: &g_cv_phys_enable_query_cache);
}

//------------------------------------------------------------------------------
// Address: 0x100C7050
// Name: _dynamic_atexit_destructor_for__cv_phys_enable_simd_optimizations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_phys_enable_simd_optimizations__()
{
  ConVar::~ConVar(this: &cv_phys_enable_simd_optimizations);
}

//------------------------------------------------------------------------------
// Address: 0x100C7060
// Name: _dynamic_atexit_destructor_for__cv_phys_enable_experimental_optimizations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_phys_enable_experimental_optimizations__()
{
  ConVar::~ConVar(this: &cv_phys_enable_experimental_optimizations);
}

//------------------------------------------------------------------------------
// Address: 0x100C7070
// Name: _dynamic_atexit_destructor_for__cv_phys_enable_PIX_counters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_phys_enable_PIX_counters__()
{
  ConVar::~ConVar(this: &cv_phys_enable_PIX_counters);
}

//------------------------------------------------------------------------------
// Address: 0x100C7080
// Name: _dynamic_atexit_destructor_for__g_cvPhysPMC__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cvPhysPMC__()
{
  ConVar::~ConVar(this: &g_cvPhysPMC);
}

//------------------------------------------------------------------------------
// Address: 0x100C7090
// Name: _dynamic_atexit_destructor_for__s_StubPredictableController__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_StubPredictableController__()
{
  s_StubPredictableController.__vftable = (CPredictable_Controller_Independant_Stub_vtbl *)&IVP_Controller_Dependent::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100C70A0
// Name: _dynamic_atexit_destructor_for__g_SurfaceDatabase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SurfaceDatabase__()
{
  CPhysicsSurfaceProps::~CPhysicsSurfaceProps(this: &g_SurfaceDatabase);
}

//------------------------------------------------------------------------------
// Address: 0x100C70B0
// Name: _DataMapInit_vphysics_save_motioncontroller_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_motioncontroller_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_12);
}

//------------------------------------------------------------------------------
// Address: 0x100C70C0
// Name: _dynamic_atexit_destructor_for__g_PostRestoreObjectList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PostRestoreObjectList__()
{
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_PostRestoreObjectList);
}

//------------------------------------------------------------------------------
// Address: 0x100C70D0
// Name: _DataMapInit_vphysics_save_cphysicsobject_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_cphysicsobject_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_13);
}

//------------------------------------------------------------------------------
// Address: 0x100C70E0
// Name: _DataMapInit_vphysics_save_shadowcontrolparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_shadowcontrolparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_14);
}

//------------------------------------------------------------------------------
// Address: 0x100C70F0
// Name: _DataMapInit_vphysics_save_cshadowcontroller_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_cshadowcontroller_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_15);
}

//------------------------------------------------------------------------------
// Address: 0x100C7100
// Name: _DataMapInit_vphysics_save_cphysicsspring_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_cphysicsspring_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_16);
}

//------------------------------------------------------------------------------
// Address: 0x100C7110
// Name: _DataMapInit_vphysics_save_cvehiclecontroller_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vphysics_save_cvehiclecontroller_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_17);
}

//------------------------------------------------------------------------------
// Address: 0x100C7120
// Name: _DataMapInit_vehicle_operatingparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehicle_operatingparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_18);
}

//------------------------------------------------------------------------------
// Address: 0x100C7130
// Name: _DataMapInit_vehicle_bodyparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehicle_bodyparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_19);
}

//------------------------------------------------------------------------------
// Address: 0x100C7140
// Name: _DataMapInit_vehicle_wheelparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehicle_wheelparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_20);
}

//------------------------------------------------------------------------------
// Address: 0x100C7150
// Name: _DataMapInit_vehicle_suspensionparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehicle_suspensionparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_21);
}

//------------------------------------------------------------------------------
// Address: 0x100C7160
// Name: _DataMapInit_vehicle_axleparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehicle_axleparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_22);
}

//------------------------------------------------------------------------------
// Address: 0x100C7170
// Name: _DataMapInit_vehicle_steeringparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehicle_steeringparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_23);
}

//------------------------------------------------------------------------------
// Address: 0x100C7180
// Name: _DataMapInit_vehicle_engineparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehicle_engineparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_24);
}

//------------------------------------------------------------------------------
// Address: 0x100C7190
// Name: _DataMapInit_vehicleparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_vehicleparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_25);
}

//------------------------------------------------------------------------------
// Address: 0x100C71A0
// Name: _dynamic_atexit_destructor_for__g_pMeshFrameLocks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_pMeshFrameLocks__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_pMeshFrameLocks);
}

//------------------------------------------------------------------------------
// Address: 0x100C71B0
// Name: _dynamic_atexit_destructor_for__g_MeshManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MeshManager__()
{
  g_MeshManager.__vftable = (CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>_vtbl *)&CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_MeshManager.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_MeshManager);
    *((_WORD *)&g_MeshManager.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_MeshManager);
}

//------------------------------------------------------------------------------
// Address: 0x100C71E0
// Name: _dynamic_atexit_destructor_for__g_MeshFrameLocksPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MeshFrameLocksPool__()
{
  CTSPool<CUtlVector<CPhysCollideVirtualMesh *,CUtlMemory<CPhysCollideVirtualMesh *,int>>>::~CTSPool<CUtlVector<CPhysCollideVirtualMesh *,CUtlMemory<CPhysCollideVirtualMesh *,int>>>(this: &g_MeshFrameLocksPool);
}

//------------------------------------------------------------------------------
// Address: 0x100C71F0
// Name: _dynamic_atexit_destructor_for__g_VisitHashPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VisitHashPool__()
{
  CTSPool<CVisitHash>::~CTSPool<CVisitHash>(this: &g_VisitHashPool);
}

//------------------------------------------------------------------------------
// Address: 0x100C7200
// Name: _dynamic_atexit_destructor_for__s_VPhysPtrMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_VPhysPtrMap__()
{
  CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &s_VPhysPtrMap.m_Tree);
}
