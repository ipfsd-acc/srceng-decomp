// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: resourcesystem/resourcesystem.cpp
// Functions: 125
// ============================================================

#include "resourcesystem\resourcesystem.h"

//------------------------------------------------------------------------------
// Address: 0x10001100
// Name: public: void CUtlMemory<unsigned int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned int,int>::Grow(CUtlMemory<KeyValues *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  KeyValues **m_pMemory; // edx
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
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001310
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001420
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001530
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001640
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10001730
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10001830
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10001920
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10001A20
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10001B10
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10001C10
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10001D10
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int v1; // ebx
  int result; // eax
  UtlRBTreeLinks_t<unsigned short> *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : &this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( v3->m_Left == 0xFFFF )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    if ( (_WORD)result == 0xFFFF )
      result = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001DC0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // di
  int result; // eax
  int v5; // edx
  UtlRBTreeLinks_t<unsigned short> *v6; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v7; // eax
  int v8; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v9; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v11; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i)->m_Right == 0xFFFF )
  {
    v7 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(this, i);
    v8 = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      result = v7->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v9 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v9 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v9->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v11 = m_Parent == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[m_Parent];
      if ( v11->m_Right != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = &this->m_Elements.m_pMemory[(unsigned __int16)result];
    }
  }
  else
  {
    result = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Right;
    v5 = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( v6->m_Left == 0xFFFF )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( (_WORD)result == 0xFFFF )
        result = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001F70
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10002070
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10002170
// Name: public: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
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
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002230
// Name: public: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
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
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100022F0
// Name: public: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
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
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100023B0
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v10; // ecx
  unsigned __int16 v11; // bp
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v12; // ecx
  unsigned __int16 v13; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v15; // ecx
  unsigned __int16 m_Right; // dx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v17; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v18; // ecx
  unsigned __int16 v19; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v20; // eax
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v22; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v23; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v24; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v25; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v26; // ecx
  unsigned __int16 v27; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v28; // eax
  int v29; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v30; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Parent == 0xFFFF )
        v7 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v13 == 0xFFFF )
        v14 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v17 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v18 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = &this->m_Elements.m_pMemory[elem];
        v19 = v18->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v19 == 0xFFFF )
          v20 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v19];
        if ( v20->m_Right == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v22 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = &this->m_Elements.m_pMemory[v9];
          v9 = v22->m_Parent;
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v23 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v11 = v23->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v24 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = &this->m_Elements.m_pMemory[v11];
        m_Right = v24->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v25 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[m_Right];
        if ( v25->m_Tag == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v26 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[elem];
        v27 = v26->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v27 == 0xFFFF )
          v28 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[v27];
        if ( v28->m_Left == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v30 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[v9];
          v9 = v30->m_Parent;
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v31 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[v9];
          v11 = v31->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x10002990
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v10; // ecx
  unsigned __int16 v11; // bp
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v12; // ecx
  unsigned __int16 v13; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v15; // ecx
  unsigned __int16 m_Right; // dx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v17; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v18; // ecx
  unsigned __int16 v19; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v20; // eax
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v22; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v23; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v24; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v25; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v26; // ecx
  unsigned __int16 v27; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v28; // eax
  int v29; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v30; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Parent == 0xFFFF )
        v7 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v13 == 0xFFFF )
        v14 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v17 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v18 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = &this->m_Elements.m_pMemory[elem];
        v19 = v18->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v19 == 0xFFFF )
          v20 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v19];
        if ( v20->m_Right == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v22 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = &this->m_Elements.m_pMemory[v9];
          v9 = v22->m_Parent;
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v23 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v11 = v23->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v24 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = &this->m_Elements.m_pMemory[v11];
        m_Right = v24->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v25 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[m_Right];
        if ( v25->m_Tag == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v26 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[elem];
        v27 = v26->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v27 == 0xFFFF )
          v28 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[v27];
        if ( v28->m_Left == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v30 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[v9];
          v9 = v30->m_Parent;
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v31 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[v9];
          v11 = v31->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x10002F70
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v10; // ecx
  unsigned __int16 v11; // bp
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v12; // ecx
  unsigned __int16 v13; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v15; // ecx
  unsigned __int16 m_Right; // dx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v17; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v18; // ecx
  unsigned __int16 v19; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v20; // eax
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v22; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v23; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v24; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v25; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v26; // ecx
  unsigned __int16 v27; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v28; // eax
  int v29; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v30; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Parent == 0xFFFF )
        v7 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v13 == 0xFFFF )
        v14 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v17 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v18 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = &this->m_Elements.m_pMemory[elem];
        v19 = v18->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v19 == 0xFFFF )
          v20 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v19];
        if ( v20->m_Right == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v22 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = &this->m_Elements.m_pMemory[v9];
          v9 = v22->m_Parent;
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v23 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v11 = v23->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v24 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = &this->m_Elements.m_pMemory[v11];
        m_Right = v24->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v25 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[m_Right];
        if ( v25->m_Tag == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v26 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[elem];
        v27 = v26->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v27 == 0xFFFF )
          v28 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[v27];
        if ( v28->m_Left == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v30 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[v9];
          v9 = v30->m_Parent;
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v31 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[v9];
          v11 = v31->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x100039E0
// Name: public: CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x10003A40
// Name: public: CUtlRBTree<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x10003AA0
// Name: public: CUtlRBTree<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x10004230
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  TSLNodeBase_t *v5; // [esp-8h] [ebp-18h]
  int value64_high; // [esp-4h] [ebp-14h]
  int v7; // [esp-4h] [ebp-14h]

  Next = this->m_Head.value.Next;
  value64_high = HIDWORD(this->m_Head.value64);
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: value64_high + 65537,
                          a4: Next,
                          a5: value64_high) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v7 = HIDWORD(this->m_Head.value64);
      v5 = this->m_Head.value.Next;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10004290
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int value64_high; // eax

  Next = this->m_Head.value.Next;
  value64_high = HIDWORD(this->m_Head.value64);
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: value64_high - 1,
                             a4: Next,
                             a5: value64_high) == 0 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    value64_high = HIDWORD(this->m_Head.value64);
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100042D0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: HIDWORD(this->m_Head.value64) & 0xFFFF0000,
                            a4: Next,
                            a5: HIDWORD(this->m_Head.value64)) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10004320
// Name: public: virtual struct AppSystemInfo_t const __near * CResourceSystem::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CResourceSystem::GetDependencies(CResourceSystem *this)
{
  return s_Dependencies;
}

//------------------------------------------------------------------------------
// Address: 0x10004330
// Name: public: virtual void CResourceSystem::InstallResourceConstructor(int,char const __near *,class IResourceTypeConstructor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::InstallResourceConstructor(
        CResourceSystem *this,
        int nType,
        const char *pResourceManagerType,
        IResourceTypeConstructor *pConstructor)
{
  CResourceTypeManagerBase *ResourceTypeManager; // eax

  if ( this->m_ppTypeManagers[nType] != nullptr )
  {
    _Warning(a1: "Tried to install the two resource constructors for the same resource type \"%d\"!\n", nType);
  }
  else
  {
    ResourceTypeManager = CResourceTypeManagerFactoryBase::CreateResourceTypeManager(pTypeManagerName: pResourceManagerType);
    this->m_ppTypeManagers[nType] = ResourceTypeManager;
    if ( ResourceTypeManager != nullptr )
      ResourceTypeManager->Init(this: ResourceTypeManager, a2: nType, a3: pConstructor);
    else
      _Warning(a1: "Tried to use an unknown resource manager type \"%s\"!\n", pResourceManagerType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100043A0
// Name: public: virtual void CResourceSystem::RemoveResourceConstructor(class IResourceTypeConstructor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::RemoveResourceConstructor(
        CResourceSystem *this,
        IResourceTypeConstructor *pConstructor)
{
  CResourceTypeManagerBase **m_ppTypeManagers; // esi
  int i; // edi
  CResourceTypeManagerBase *v4; // ecx

  m_ppTypeManagers = this->m_ppTypeManagers;
  for ( i = 7; i != 0; --i )
  {
    v4 = *m_ppTypeManagers;
    if ( *m_ppTypeManagers != nullptr && v4->m_pConstructor == pConstructor )
    {
      v4->Shutdown(this: v4);
      CResourceTypeManagerBase::Release(this: *m_ppTypeManagers);
      *m_ppTypeManagers = nullptr;
    }
    ++m_ppTypeManagers;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100043E0
// Name: public: virtual int CResourceSystem::GetFieldSize(enum ResourceFieldType_t)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CResourceSystem::GetFieldSize(CResourceSystem *this, ResourceFieldType_t nType)
{
  return ResourceFieldProperties_t::GetFieldProperties(nFieldType: nType)->m_nMemorySize;
}

//------------------------------------------------------------------------------
// Address: 0x10004400
// Name: public: virtual int CResourceSystem::GetFieldAlignment(enum ResourceFieldType_t)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CResourceSystem::GetFieldAlignment(CResourceSystem *this, ResourceFieldType_t nType)
{
  return ResourceFieldProperties_t::GetFieldProperties(nFieldType: nType)->m_nAlignment;
}

//------------------------------------------------------------------------------
// Address: 0x10004420
// Name: public: virtual char const __near * CResourceSystem::GetFieldName(enum ResourceFieldType_t)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CResourceSystem::GetFieldName(CResourceSystem *this, ResourceFieldType_t nType)
{
  return ResourceFieldProperties_t::GetFieldProperties(nFieldType: nType)->m_pTypeName;
}

//------------------------------------------------------------------------------
// Address: 0x10004440
// Name: public: virtual class IResourceTypeManager __near * CResourceSystem::GetResourceManager(int)
// Source: json
//------------------------------------------------------------------------------
CResourceTypeManagerBase *__thiscall CResourceSystem::GetResourceManager(CResourceSystem *this, int nType)
{
  return this->m_ppTypeManagers[nType];
}

//------------------------------------------------------------------------------
// Address: 0x10004450
// Name: public: static bool CDefOps<void const __near *>::LessFunc(void const __near * const __near &,void const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<void const *>::LessFunc(const unsigned int *lhs, const unsigned int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x10004530
// Name: void std::_Push_heap<int __near *,int,int,bool (*)(int const __near &,int const __near &)>(int __near *,int,int,int,bool (*)(int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        int *_First,
        int _Hole,
        int _Top,
        int _Val,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int v5; // edi
  int v6; // esi
  bool v7; // cc

  v5 = _Hole;
  v6 = (_Hole - 1) / 2;
  if ( _Top >= _Hole )
  {
    _First[_Hole] = _Val;
  }
  else
  {
    do
    {
      if ( !_Pred(a1: &_First[v6], a2: &_Val) )
        break;
      _First[v5] = _First[v6];
      v5 = v6;
      v7 = _Top < v6;
      v6 = (v6 - 1) / 2;
    }
    while ( v7 );
    _First[v5] = _Val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100045A0
// Name: public: void __near * CMemoryPoolMT::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMemoryPoolMT::Alloc(CMemoryPoolMT *this)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  void *result; // eax

  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  result = CUtlMemoryPool::Alloc(this);
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100045F0
// Name: public: virtual void CResourceSystem::GetResourceMapping(char const __near *,int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::GetResourceMapping(
        CResourceSystem *this,
        const char *pDmeElementType,
        int *pType,
        unsigned int *pId)
{
  const CResourceStructIntrospection *StructIntrospectionByDmElement; // eax

  *pType = -1;
  *pId = 0;
  StructIntrospectionByDmElement = CResourceIntrospectionDictionary::FindStructIntrospectionByDmElement(
                                     this: &this->m_IntrospectionDict,
                                     pDmeElement: pDmeElementType);
  if ( StructIntrospectionByDmElement != nullptr )
  {
    *pId = StructIntrospectionByDmElement->m_nId;
    this->FindEnumeratedValue(
      this,
      a2: pType,
      a3: "ResourceTypeEngine_t",
      a4: (char *)&StructIntrospectionByDmElement->m_pResourceType
    + StructIntrospectionByDmElement->m_pResourceType.m_nOffset,
      a5: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004640
// Name: private: static bool CResourceSystem::SortLessFunc(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CResourceSystem::SortLessFunc(const int *left, const int *right)
{
  return *(_DWORD *)(*left + 8) != 0 && *(_DWORD *)(*right + 8) == 0
      || (*(_BYTE *)(*left + 16) & 4) != 0 && (*(_BYTE *)(*right + 16) & 4) == 0
      || *(_DWORD *)(*left + 20) < *(_DWORD *)(*right + 20);
}

//------------------------------------------------------------------------------
// Address: 0x10004680
// Name: public: virtual void CResourceSystem::BlockUntilAllVTDsLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::BlockUntilAllVTDsLoaded(CResourceSystem *this)
{
  while ( this->m_nPendingVTDRequests.m_value > 0 )
    _ThreadSleep(a1: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100046B0
// Name: protected: void __near * CResourceScatterer::ScatterAlloc(int,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CResourceScatterer::ScatterAlloc(CResourceScatterer *this, int nSize, int nAlignment)
{
  int m_nMaxAlignment; // eax
  char *result; // eax

  if ( this->m_bCalculatingSize )
  {
    m_nMaxAlignment = nAlignment;
    this->m_nCalculatedRequiredSize = nSize + (~(nAlignment - 1) & (nAlignment + this->m_nCalculatedRequiredSize - 1));
    if ( this->m_nMaxAlignment > nAlignment )
      m_nMaxAlignment = this->m_nMaxAlignment;
    this->m_nMaxAlignment = m_nMaxAlignment;
    return nullptr;
  }
  else
  {
    result = (char *)(~(nAlignment - 1) & ((int)this->m_pAllocChunkNextAlloc + nAlignment - 1));
    this->m_pAllocChunkNextAlloc = &result[nSize];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004700
// Name: protected: void CResourceScatterer::ScatterRootField(void const __near *,void __near *,class CResourceFieldIntrospection const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceScatterer::ScatterRootField(
        CResourceScatterer *this,
        _DWORD *pSrcField,
        _DWORD *pDstField,
        CResourceFieldIntrospection *pFieldIntro)
{
  ResourceFieldType_t RootType; // ebx
  unsigned int RootTypeData; // eax
  int ElementMemorySize; // eax
  int v8; // ebx
  char *v9; // eax
  const CResourceStructIntrospection *v10; // eax

  RootType = CResourceFieldIntrospection::GetRootType(this: pFieldIntro);
  RootTypeData = CResourceFieldIntrospection::GetRootTypeData(this: pFieldIntro);
  if ( RootType == RESOURCE_FIELD_TYPE_STRUCT )
  {
    v10 = this->m_pResourceSystem->FindStructIntrospection_2(this: this->m_pResourceSystem, a2: RootTypeData);
    CResourceScatterer::ScatterStruct(this, pSrcStruct: pSrcField, pDstStruct: pDstField, pStructIntro: v10);
  }
  else if ( RootType == RESOURCE_FIELD_TYPE_STRING )
  {
    v8 = _V_strlen(str: (const char *)pSrcField + *pSrcField) + 1;
    v9 = CResourceScatterer::ScatterAlloc(this, nSize: v8, nAlignment: 1);
    if ( !this->m_bCalculatingSize )
    {
      *pDstField = v9 - (char *)pDstField;
      _V_memcpy(dest: v9, src: pSrcField, count: v8);
    }
  }
  else if ( !this->m_bCalculatingSize )
  {
    ElementMemorySize = CResourceFieldIntrospection::GetElementMemorySize(
                          this: pFieldIntro,
                          nTypeChainIndex: pFieldIntro->m_nTypeChainCount - 1,
                          pIntroDct: nullptr);
    _V_memcpy(dest: pDstField, src: pSrcField, count: ElementMemorySize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004860
// Name: public: CTSQueue<struct CResourceSystem::PendingResourceIdResolution_t,0>::CTSQueue<struct CResourceSystem::PendingResourceIdResolution_t,0>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *__thiscall CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>(
        CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CInterlockedIntT<int> *p_m_Count; // edi
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *v4; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  p_m_Count = &this->m_Count;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  HIDWORD(p_m_FreeNodes->m_Head.value64) = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&p_m_Count->m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v4 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)operator new(nSize: 0x10u);
  this->m_Tail.value.pNode = v4;
  this->m_Head.value.pNode = v4;
  v4->pNext = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004960
// Name: public: class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Next(class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *__thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Next(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *result,
        const CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *it)
{
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v3; // eax

  v3 = result;
  if ( (unsigned __int16)(it->index + 1) >= this->m_nAllocationCount )
    result->index = -1;
  else
    result->index = it->index + 1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10004AB0
// Name: void std::_Adjust_heap<int __near *,int,int,bool (*)(int const __near &,int const __near &)>(int __near *,int,int,int,bool (*)(int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        int *_First,
        int _Hole,
        int _Bottom,
        int _Val,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int v5; // edi
  int v6; // esi
  bool i; // zf

  v5 = _Hole;
  v6 = 2 * _Hole + 2;
  for ( i = v6 == _Bottom; v6 < _Bottom; i = v6 == _Bottom )
  {
    if ( _Pred(a1: &_First[v6], a2: &_First[v6 - 1]) )
      --v6;
    _First[v5] = _First[v6];
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    _First[v5] = _First[_Bottom - 1];
    v5 = _Bottom - 1;
  }
  std::_Push_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(_First, _Hole: v5, _Top: _Hole, _Val, _Pred);
}

//------------------------------------------------------------------------------
// Address: 0x10004B80
// Name: public: void CUtlMemory<struct CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Grow(
        CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CCountedStringPoolBase<unsigned short>::hash_item_t *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CCountedStringPoolBase<unsigned short>::hash_item_t *)_g_pMemAlloc->Realloc_2(
                                                                                 this: _g_pMemAlloc,
                                                                                 a2: m_pMemory,
                                                                                 a3: v7);
    else
      this->m_pMemory = (CCountedStringPoolBase<unsigned short>::hash_item_t *)_g_pMemAlloc->Alloc_2(
                                                                                 this: _g_pMemAlloc,
                                                                                 a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004C10
// Name: public: void CUtlMemory<struct CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
        CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CResourceSystem::PendingResourceIdResolution_t *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CResourceSystem::PendingResourceIdResolution_t *)_g_pMemAlloc->Realloc_2(
                                                                            this: _g_pMemAlloc,
                                                                            a2: m_pMemory,
                                                                            a3: v7);
    else
      this->m_pMemory = (CResourceSystem::PendingResourceIdResolution_t *)_g_pMemAlloc->Alloc_2(
                                                                            this: _g_pMemAlloc,
                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004CB0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004D50
// Name: public: void CUtlMemory<unsigned short,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned short,int>::Grow(CUtlMemory<unsigned short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int16 *m_pMemory; // edx
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
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004DF0
// Name: public: virtual void CBaseAppSystem<class IResourceSystem>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IResourceSystem>::Reconnect(
        CBaseAppSystem<IResourceSystem> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10004E10
// Name: private: unsigned int CResourceSystem::ComputeFinishedFrameCount(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CResourceSystem::ComputeFinishedFrameCount(CResourceSystem *this)
{
  int m_Size; // edi
  __int64 m_nFrameCount; // rax
  unsigned int **m_pMemory; // ecx

  m_Size = this->m_FinishedFrameCounters.m_Size;
  m_nFrameCount = (unsigned int)this->m_nFrameCount;
  if ( m_Size < 0 )
  {
    m_pMemory = this->m_FinishedFrameCounters.m_Memory.m_pMemory;
    do
    {
      if ( (unsigned int)m_nFrameCount >= **m_pMemory )
        LODWORD(m_nFrameCount) = **m_pMemory;
      ++HIDWORD(m_nFrameCount);
      ++m_pMemory;
    }
    while ( SHIDWORD(m_nFrameCount) > m_Size );
  }
  return m_nFrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x10004F40
// Name: public: struct CTSQueue<struct CResourceSystem::PendingResourceIdResolution_t,0>::Node_t __near * CTSQueue<struct CResourceSystem::PendingResourceIdResolution_t,0>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *__thiscall CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Pop(
        CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *this)
{
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *v1; // esi
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *pNext; // eax
  unsigned int m_nId; // edi
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::NodeLink_t *p_m_Tail; // [esp+C0h] [ebp-2Ch]
  int *p_sequence; // [esp+C4h] [ebp-28h]
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::NodeLink_t *v8; // [esp+CCh] [ebp-20h]
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *pNode; // [esp+D4h] [ebp-18h]
  __int64 v11; // [esp+E0h] [ebp-Ch]

  v1 = this;
  p_m_Tail = &this->m_Tail;
  p_sequence = &this->m_Head.value.sequence;
  v8 = &this->m_Tail;
  while ( 1 )
  {
    do
    {
      while ( 1 )
      {
        do
        {
          pNode = v1->m_Head.value.pNode;
          pNext = v1->m_Head.value.pNode->pNext;
        }
        while ( pNext == nullptr );
        if ( pNode != v8->value.pNode )
          break;
        if ( pNext == (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)v1 )
          return nullptr;
        _ThreadInterlockedAssignIf64(
          a1: &v1->m_Tail,
          a2: pNext,
          a3: p_m_Tail->value.sequence + 1,
          a4: pNode,
          a5: p_m_Tail->value.sequence);
      }
    }
    while ( pNext == (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)v1 );
    m_nId = pNext->elem.m_nId;
    v11 = *(_QWORD *)&pNext->elem.m_hFile;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: pNext,
                            a3: *p_sequence + 1,
                            a4: pNode,
                            a5: *p_sequence) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  *(_QWORD *)&pNode->elem.m_hFile = v11;
  pNode->elem.m_nId = m_nId;
  return pNode;
}

//------------------------------------------------------------------------------
// Address: 0x10005250
// Name: public: virtual void CMemberFunctor2<class CResourceSystem __near *,void (CResourceSystem::*)(class IAsyncFileRequest __near *,void __near *),class IAsyncFileRequest __near *,void __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor2<CResourceSystem *,void (__thiscall CResourceSystem::*)(IAsyncFileRequest *,void *),IAsyncFileRequest *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor2<CResourceSystem *,void (__thiscall CResourceSystem::*)(IAsyncFileRequest *,void *),IAsyncFileRequest *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1, a3: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x10005270
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005380
// Name: void std::_Make_heap<int __near *,int,int,bool (*)(int const __near &,int const __near &)>(int __near *,int __near *,bool (*)(int const __near &,int const __near &),int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
        int *_First,
        int *_Last,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int i; // esi
  int v4; // eax

  for ( i = (_Last - _First) / 2;
        i > 0;
        std::_Adjust_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
          _First,
          _Hole: i,
          _Bottom: _Last - _First,
          _Val: v4,
          _Pred) )
  {
    v4 = _First[--i];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100053C0
// Name: protected: void CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<void const *,void *,unsigned short>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100054D0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebp
  int m_nAllocationCount; // eax
  unsigned __int16 v5; // cx
  unsigned __int16 index; // di
  int v7; // ebx
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v8; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v11; // edx
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t v12; // [esp+6h] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == 0xFFFF )
  {
    p_m_LastAlloc = &this->m_LastAlloc;
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
    {
      v5 = -1;
    }
    else
    {
      v5 = p_m_LastAlloc->index + 1;
    }
    v12.index = v5;
    index = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( p_m_LastAlloc->index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v12.index = (v7 > 0) - 1;
        v8 = &v12;
      }
      else
      {
        v8 = CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Next(
               this: &this->m_Elements,
               result: &v12,
               it: &this->m_LastAlloc);
      }
      index = v8->index;
      if ( v8->index >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    p_m_LastAlloc->index = index;
    this->m_pElements = m_pMemory;
    return index;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[m_FirstFree].m_Right;
    this->m_pElements = v11;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100055E0
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100056D0
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x100057D0
// Name: protected: void CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100058C0
// Name: protected: void CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x100059C0
// Name: public: virtual enum InitReturnVal_t CResourceSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CResourceSystem::Init(CResourceSystem *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  this->m_hProceduralFileHandle = CUtlFilenameSymbolTable::FindOrAddFileName(
                                    this: &this->m_FileSymbols,
                                    pFileName: ";procedural;");
  CResourceIntrospectionDictionary::Init(this: &this->m_IntrospectionDict, pOwner: this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005A00
// Name: public: virtual void CResourceSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::Shutdown(CResourceSystem *this)
{
  int v2; // edi
  CResourceTypeManagerBase **m_ppTypeManagers; // esi
  int m_BlocksAllocated; // esi
  void *v5; // esp
  int Elements; // ebx
  int i; // esi
  int v8[3]; // [esp+0h] [ebp-10h] BYREF
  CResourceSystem *v9; // [esp+Ch] [ebp-4h]

  v9 = this;
  v2 = 0;
  m_ppTypeManagers = this->m_ppTypeManagers;
  do
  {
    if ( *m_ppTypeManagers != nullptr )
    {
      _Warning(a1: "Forgot to remove resource type manager for type %d!\n", v2);
      (*m_ppTypeManagers)->Shutdown(this: *m_ppTypeManagers);
      CResourceTypeManagerBase::Release(this: *m_ppTypeManagers);
    }
    ++v2;
    ++m_ppTypeManagers;
  }
  while ( v2 < 7 );
  m_BlocksAllocated = this->m_FileData.m_EntryMemory.m_BlocksAllocated;
  v5 = alloca(4 * m_BlocksAllocated);
  Elements = CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::GetElements(
               this: &this->m_FileData,
               nFirstElement: 0,
               nCount: m_BlocksAllocated,
               pHandles: v8);
  for ( i = 0; i < Elements; ++i )
  {
    if ( *(_DWORD *)(v8[i] + 8) != 0 )
      free(pMem: *(void **)(v8[i] + 8));
  }
  CResourceIntrospectionDictionary::Shutdown(this: &v9->m_IntrospectionDict);
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10005AB0
// Name: private: void CResourceSystem::OnResourceIdFileLoaded(class IAsyncFileRequest __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CResourceSystem::OnResourceIdFileLoaded(
        CResourceSystem *this@<ecx>,
        CResourceSystem_vtbl *a2@<ebx>,
        IAsyncFileRequest *pRequest,
        void *hFile,
        int a5)
{
  CResourceSystem *v5; // edi
  int v6; // ebp
  bool v7; // zf
  IAsyncFileRequest_vtbl *v8; // eax
  const char *v9; // eax
  const ResourceIdList_t *Block; // eax
  signed int v11; // ebx
  int v12; // ebp
  _DWORD *v13; // esi
  CResourceTypeManagerBase *v14; // edi
  int v16; // [esp+10h] [ebp-Ch]
  const ResourceFileHeader_t *v18; // [esp+18h] [ebp-4h]
  void *retaddr; // [esp+1Ch] [ebp+0h]
  const ResourceIdList_t *pIdList; // [esp+20h] [ebp+4h]

  v5 = this;
  _InterlockedExchangeAdd(&this->m_nPendingFileIdRequests.m_value, 0xFFFFFFFF);
  v6 = CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::Find(
         this: &this->m_FileData,
         uiKey: hFile);
  *(_DWORD *)(v6 + 16) &= ~8u;
  v16 = v6;
  v7 = pRequest->GetRequestStatus(this: pRequest) == ASYNC_REQUEST_OK;
  v8 = pRequest->__vftable;
  if ( v7 )
  {
    v18 = (const ResourceFileHeader_t *)v8->GetResultBuffer(this: pRequest);
    Block = (const ResourceIdList_t *)Resource_GetBlock(pHeader: v18, id: 0x4C444952u);
    pIdList = Block;
    if ( Block != nullptr )
    {
      v11 = 0;
      if ( (int)Block->m_ResourceTypeList.m_nCount > 0 )
      {
        v12 = 0;
        while ( 1 )
        {
          v13 = (int *)((char *)&Block[v12].m_ResourceTypeList.m_nOffset + Block->m_ResourceTypeList.m_nOffset);
          v14 = v5->m_ppTypeManagers[*v13];
          if ( ((unsigned __int8 (__thiscall *)(CResourceTypeManagerBase *, CResourceSystem_vtbl *))v14->SupportsFileAtomicCaching)(
                 a1: v14,
                 a2) == 0 )
            a5 &= ~4u;
          a2 = this->__vftable;
          ((void (__thiscall *)(CResourceTypeManagerBase *, _DWORD, int, void *))v14->RegisterResources)(
            a1: v14,
            a2: v13[2],
            a3: (int)v13 + v13[1] + 4,
            a4: retaddr);
          Block = pIdList;
          ++v11;
          ++v12;
          if ( v11 >= (signed int)pIdList->m_ResourceTypeList.m_nCount )
            break;
          v5 = this;
        }
        v6 = v16;
      }
      *(_DWORD *)(v6 + 16) |= 5u;
    }
    else
    {
      *(_DWORD *)(v6 + 16) |= 1u;
    }
  }
  else
  {
    v9 = v8->GetFileName(this: pRequest);
    _Warning(a1: "Error loading resource file \"%s\"\n", v9);
    *(_DWORD *)(v6 + 16) |= 3u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005BD0
// Name: public: virtual void CResourceSystem::UnregisterFrameCounter(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::UnregisterFrameCounter(CResourceSystem *this, unsigned int *pFrameCounter)
{
  CUtlVector<unsigned int *,CUtlMemory<unsigned int *,int>>::FindAndRemove(
    this: &this->m_FrameCounters,
    src: &pFrameCounter);
}

//------------------------------------------------------------------------------
// Address: 0x10005BF0
// Name: public: virtual void CResourceSystem::UnregisterFinishedFrameCounter(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::UnregisterFinishedFrameCounter(CResourceSystem *this, unsigned int *pFrameCounter)
{
  CUtlVector<unsigned int *,CUtlMemory<unsigned int *,int>>::FindAndRemove(
    this: &this->m_FinishedFrameCounters,
    src: &pFrameCounter);
}

//------------------------------------------------------------------------------
// Address: 0x10005C10
// Name: public: void CTSQueue<struct CResourceSystem::PendingResourceIdResolution_t,0>::PushItem(struct CResourceSystem::PendingResourceIdResolution_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::PushItem(
        CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *this,
        const CResourceSystem::PendingResourceIdResolution_t *init)
{
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *v3; // eax

  v3 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)CTSListBase::Pop(this: &this->m_FreeNodes);
  if ( v3 != nullptr
    || (v3 = (CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *)operator new(nSize: 0x10u)) != nullptr )
  {
    v3->elem = *init;
    CTSQueue<ResourceBindingBase_t const *,0>::Push(this, pNode: v3);
  }
  else
  {
    CTSQueue<ResourceBindingBase_t const *,0>::Push(this, pNode: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005D00
// Name: public: void CTSQueue<struct CResourceSystem::PendingResourceIdResolution_t,0>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Purge(
        CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0> *this)
{
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int value64_high; // eax

  for ( i = CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Pop(this);
        i != nullptr;
        i = CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Pop(this) )
  {
    free(pMem: i);
  }
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    value64_high = HIDWORD(this->m_FreeNodes.m_Head.value64);
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &this->m_FreeNodes,
                               a2: Next->Next,
                               a3: value64_high - 1,
                               a4: Next,
                               a5: value64_high) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      value64_high = HIDWORD(this->m_FreeNodes.m_Head.value64);
      if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    free(pMem: Next);
  }
LABEL_7:
  this->m_Head.value.sequence = 0;
  this->m_Tail.value.sequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10005D80
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10005E80
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<void const *,void *,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10005F80
// Name: public: void CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
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
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006260
// Name: public: void CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
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
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006320
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v10; // ecx
  unsigned __int16 v11; // bp
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v12; // ecx
  unsigned __int16 v13; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v15; // ecx
  unsigned __int16 m_Right; // dx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v17; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v18; // ecx
  unsigned __int16 v19; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v20; // eax
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v22; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v23; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v24; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v25; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v26; // ecx
  unsigned __int16 v27; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v28; // eax
  int v29; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v30; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Parent == 0xFFFF )
        v7 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v13 == 0xFFFF )
        v14 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v17 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v18 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = &this->m_Elements.m_pMemory[elem];
        v19 = v18->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v19 == 0xFFFF )
          v20 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v19];
        if ( v20->m_Right == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v22 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = &this->m_Elements.m_pMemory[v9];
          v9 = v22->m_Parent;
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v23 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v11 = v23->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v24 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = &this->m_Elements.m_pMemory[v11];
        m_Right = v24->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v25 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[m_Right];
        if ( v25->m_Tag == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v26 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[elem];
        v27 = v26->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v27 == 0xFFFF )
          v28 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[v27];
        if ( v28->m_Left == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v30 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[v9];
          v9 = v30->m_Parent;
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v31 = (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[v9];
          v11 = v31->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x10006900
// Name: protected: void CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v10; // ecx
  unsigned __int16 v11; // bp
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v12; // ecx
  unsigned __int16 v13; // cx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v15; // ecx
  unsigned __int16 m_Right; // dx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v17; // ecx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v18; // ecx
  unsigned __int16 v19; // cx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v20; // eax
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v22; // eax
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v23; // eax
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v24; // ecx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v25; // ecx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v26; // ecx
  unsigned __int16 v27; // cx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v28; // eax
  int v29; // ecx
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v30; // eax
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Parent == 0xFFFF )
        v7 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v13 == 0xFFFF )
        v14 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v17 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v18 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = &this->m_Elements.m_pMemory[elem];
        v19 = v18->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v19 == 0xFFFF )
          v20 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v19];
        if ( v20->m_Right == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v22 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = &this->m_Elements.m_pMemory[v9];
          v9 = v22->m_Parent;
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v23 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v11 = v23->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v24 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = &this->m_Elements.m_pMemory[v11];
        m_Right = v24->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v25 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[m_Right];
        if ( v25->m_Tag == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v26 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[elem];
        v27 = v26->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v27 == 0xFFFF )
          v28 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[v27];
        if ( v28->m_Left == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v30 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[v9];
          v9 = v30->m_Parent;
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v31 = (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[v9];
          v11 = v31->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x10006EE0
// Name: public: void CIOCompletionQueue::ProcessAllResultCallbacks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIOCompletionQueue::ProcessAllResultCallbacks(CIOCompletionQueue *this)
{
  CTSQueue<CAsyncIOResult_t,0>::Node_t *v2; // eax
  IAsyncRequestBase *m_pRequest; // esi

  while ( 1 )
  {
    v2 = CTSQueue<CAsyncIOResult_t,0>::Pop(this: &this->m_TSIOResultQueue);
    if ( v2 == nullptr )
      break;
    m_pRequest = v2->elem.m_pRequest;
    CTSListBase::Push(this: &this->m_TSIOResultQueue.m_FreeNodes, pNode: (TSLNodeBase_t *)v2);
    if ( m_pRequest != nullptr )
      m_pRequest->ProcessCallback(this: m_pRequest, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006F20
// Name: public: void CResourceSystem::SubmitFileIdResolutionRequest(char const __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::SubmitFileIdResolutionRequest(
        CResourceSystem *this,
        const char *pFileName,
        unsigned int nType,
        unsigned int nId)
{
  void *v5; // edi
  CResourceSystem::PendingResourceIdResolution_t insert; // [esp+8h] [ebp-114h] BYREF
  char pResourceFileName[260]; // [esp+14h] [ebp-108h] BYREF

  GenerateResourceFileName(pFileName, pResourceFileName: &pResourceFileName[4], nBufLen: 0x104u);
  v5 = CUtlFilenameSymbolTable::FindOrAddFileName(this: &this->m_FileSymbols, pFileName: &pResourceFileName[4]);
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::Insert(
    this: &this->m_FileData,
    uiKey: v5,
    data: &s_DefaultResourceFileData,
    pDidInsert: (bool *)&insert.m_hFile + 3);
  if ( HIBYTE(insert.m_hFile) != 0 )
  {
    insert.m_nId = nType;
    insert.m_nType = (int)v5;
    *(_DWORD *)pResourceFileName = nId;
    CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::PushItem(
      this: &this->m_PendingResourceIdResolutions,
      init: (const CResourceSystem::PendingResourceIdResolution_t *)&insert.m_nType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006FB0
// Name: private: void CResourceSystem::StreamFileIdResolutionFile(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CResourceSystem::StreamFileIdResolutionFile(CResourceSystem *this@<ecx>, int a2@<esi>, void *hFile)
{
  int v4; // eax
  IAsyncFileRequest *v5; // esi
  _DWORD *v6; // eax
  char pIdPath[260]; // [esp+8h] [ebp-20Ch] BYREF
  char pFullPath[264]; // [esp+10Ch] [ebp-108h] BYREF

  v4 = CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::Find(
         this: &this->m_FileData,
         uiKey: hFile);
  if ( (*(_BYTE *)(v4 + 16) & 8) == 0 )
  {
    *(_DWORD *)(v4 + 16) |= 8u;
    _InterlockedExchangeAdd(&this->m_nPendingFileIdRequests.m_value, 1u);
    *(_DWORD *)pIdPath = hFile;
    CUtlFilenameSymbolTable::String(
      this: &this->m_FileSymbols,
      handle: (void *const *)pIdPath,
      buf: &pIdPath[4],
      buflen: 260);
    V_SetExtension(path: &pIdPath[4], extension: "ids", pathStringLength: 260);
    ((void (__thiscall *)(IFileSystem *, char *, const char *, char *, int, _DWORD, _DWORD, int))g_pFullFileSystem->RelativePathToFullPath)(
      a1: g_pFullFileSystem,
      a2: &pIdPath[4],
      a3: "GAME",
      a4: &pFullPath[4],
      a5: 260,
      a6: 0,
      a7: 0,
      a8: a2);
    v5 = g_pAsyncFileSystem->CreateNewFileRequest(this: g_pAsyncFileSystem);
    v5->LoadFile(this: v5, a2: &pFullPath[8]);
    v5->ProvideDataBuffer(this: v5);
    v6 = operator new(nSize: 0x20u);
    if ( v6 != nullptr )
    {
      v6[3] = 1;
      *v6 = &CMemberFunctor2<CResourceSystem *,void (__thiscall CResourceSystem::*)(IAsyncFileRequest *,void *),IAsyncFileRequest *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v6[2] = &CMemberFunctor2<CResourceSystem *,void (__thiscall CResourceSystem::*)(IAsyncFileRequest *,void *),IAsyncFileRequest *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v6[4] = CResourceSystem::OnResourceIdFileLoaded;
      v6[5] = this;
      v6[6] = v5;
      v6[7] = hFile;
    }
    ((void (__thiscall *)(IAsyncFileRequest *, CIOCompletionQueue *))v5->AssignCallbackAndQueue)(
      a1: v5,
      a2: &this->m_IOCompletionQueue);
    g_pAsyncFileSystem->SubmitAsyncFileRequest(this: g_pAsyncFileSystem, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100070E0
// Name: public: CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x10007140
// Name: void std::_Sort_heap<int __near *,bool (*)(int const __near &,int const __near &)>(int __near *,int __near *,bool (*)(int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<int *,bool (__cdecl *)(int const &,int const &)>(
        char *_First,
        int *_Last,
        bool (__cdecl *_Pred)(const int *, const int *))
{
  int i; // esi
  int v4; // [esp-Ch] [ebp-14h]

  for ( i = (char *)_Last - _First; i >> 2 > 1; i -= 4 )
  {
    v4 = *(_DWORD *)&_First[i - 4];
    *(_DWORD *)&_First[i - 4] = *(_DWORD *)_First;
    std::_Adjust_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
      (int *)_First,
      _Hole: 0,
      _Bottom: (i - 4) >> 2,
      _Val: v4,
      _Pred);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007190
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007200
// Name: protected: void CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007270
// Name: public: virtual enum AppSystemTier_t CTier2AppSystem<class IResourceSystem,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IResourceSystem,0>::GetTier(CTier2AppSystem<IResourceSystem,0> *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10007280
// Name: public: virtual bool CTier2AppSystem<class IResourceSystem,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier2AppSystem<IResourceSystem,0>::Connect(
        CTier2AppSystem<IResourceSystem,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  pFactoryList = factory;
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100072B0
// Name: public: virtual void CTier2AppSystem<class IResourceSystem,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IResourceSystem,0>::Disconnect(CTier2AppSystem<IResourceSystem,0> *this)
{
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x100072C0
// Name: public: virtual class CSchemaClassBindingBase __near * CResourceSystem::FindClassBinding(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
CSchemaClassBindingBase *__thiscall CResourceSystem::FindClassBinding(CResourceSystem *this, unsigned int id)
{
  unsigned __int16 v3; // ax
  CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = id;
  v3 = CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_ClassBindings.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_ClassBindings.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10007310
// Name: private: void CResourceSystem::ExecuteFileIdResolutionRequests(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::ExecuteFileIdResolutionRequests(CResourceSystem *this)
{
  int v2; // ebx
  CResourceSystem::PendingResourceIdResolution_t *m_pMemory; // esi
  CResourceTypeManagerBase *v4; // ecx
  unsigned int m_nId; // edx
  CResourceSystem::PendingResourceIdResolution_t *v6; // esi
  CResourceTypeManagerBase *v7; // ecx
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Node_t *v8; // eax
  unsigned int v9; // esi
  int m_Size; // [esp+8h] [ebp-118h]
  CResourceSystem::PendingResourceIdResolution_t item; // [esp+Ch] [ebp-114h] BYREF
  char pFileName[260]; // [esp+18h] [ebp-108h] BYREF

  if ( this->m_nPendingVTDRequests.m_value <= 0 && this->m_nPendingFileIdRequests.m_value <= 0 )
  {
    if ( this->m_ActiveIdResolutions.m_Size > 0 )
    {
      v2 = 0;
      m_Size = this->m_ActiveIdResolutions.m_Size;
      do
      {
        m_pMemory = this->m_ActiveIdResolutions.m_Memory.m_pMemory;
        v4 = this->m_ppTypeManagers[m_pMemory[v2].m_nType];
        m_nId = m_pMemory[v2].m_nId;
        v6 = &m_pMemory[v2];
        if ( !v4->IsFileHandleDefined(this: v4, a2: m_nId) )
        {
          v7 = this->m_ppTypeManagers[v6->m_nType];
          v7->MarkResourceIdNotResolveable(this: v7, a2: v6->m_nId);
          item.m_hFile = v6->m_hFile;
          CUtlFilenameSymbolTable::String(
            this: &this->m_FileSymbols,
            handle: &item.m_hFile,
            buf: &pFileName[4],
            buflen: 260);
          V_SetExtension(path: &pFileName[4], extension: "ids", pathStringLength: 260);
          _Warning(
            a1: "Encountered unresolveable resource %X type %d (file \"%s\")\n",
            v6->m_nId,
            v6->m_nType,
            &pFileName[4]);
        }
        ++v2;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
    this->m_ActiveIdResolutions.m_Size = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Pop(this: &this->m_PendingResourceIdResolutions);
        if ( v8 == nullptr )
          return;
        v9 = v8->elem.m_nId;
        *(_QWORD *)&item.m_nType = *(_QWORD *)&v8->elem.m_hFile;
        *(_DWORD *)pFileName = v9;
        CTSListBase::Push(this: &this->m_PendingResourceIdResolutions.m_FreeNodes, pNode: (TSLNodeBase_t *)v8);
        if ( item.m_nId != -1 )
          break;
LABEL_13:
        CResourceSystem::StreamFileIdResolutionFile(this, a2: v9, hFile: (void *)item.m_nType);
      }
      if ( !this->m_ppTypeManagers[item.m_nId]->IsFileHandleDefined(this: this->m_ppTypeManagers[item.m_nId], a2: v9) )
      {
        CUtlVector<CResourceTypeManagerFileAtomic::ToCacheHandle_t,CUtlMemory<CResourceTypeManagerFileAtomic::ToCacheHandle_t,int>>::InsertBefore(
          this: &this->m_ActiveIdResolutions,
          elem: this->m_ActiveIdResolutions.m_Size,
          src: (const CResourceSystem::PendingResourceIdResolution_t *)&item.m_nType);
        goto LABEL_13;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007460
// Name: public: virtual void CResourceSystem::LoadResourceManifest(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::LoadResourceManifest(CResourceSystem *this, const char *pFileName)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebp
  IBaseFileSystem *v4; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v7; // eax
  const char *String; // eax
  CUtlBuffer buf; // [esp+8h] [ebp-34h] BYREF

  buf.m_Memory.m_pMemory = (unsigned __int8 *)this;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: pFileName);
  else
    v3 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v3,
         filesystem: v4,
         resourceName: pFileName,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0, nFlags: 0);
    for ( i = KeyValues::GetFirstSubKey(this: v3); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: Name, s2: "file") != 0 )
      {
        v7 = KeyValues::GetName(this: i);
        _Warning(a1: "ResourceSystem: Manifest '%s' with bogus file type '%s', expecting 'file'\n", pFileName, v7);
      }
      else
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &setName);
        CResourceSystem::SubmitFileIdResolutionRequest(
          this: (CResourceSystem *)buf.m_Memory.m_pMemory,
          pFileName: String,
          nType: 0xFFFFFFFF,
          nId: 0);
      }
    }
    KeyValues::deleteThis(this: v3);
    CResourceSystem::ExecuteFileIdResolutionRequests(this: (CResourceSystem *)buf.m_Memory.m_pMemory);
    if ( buf.m_Get >= 0 && buf.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
  }
  else
  {
    _Warning(a1: "ResourceSystem: Unable to load manifest file '%s'\n", pFileName);
    KeyValues::deleteThis(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007580
// Name: public: virtual void CResourceSystem::RegisterFrameCounter(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::RegisterFrameCounter(CResourceSystem *this, unsigned int *pFrameCounter)
{
  CUtlVector<unsigned int *,CUtlMemory<unsigned int *,int>>::InsertBefore(
    this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&this->m_FrameCounters,
    elem: this->m_FrameCounters.m_Size,
    src: (KeyValues *const *)&pFrameCounter);
}

//------------------------------------------------------------------------------
// Address: 0x100075A0
// Name: public: virtual void CResourceSystem::RegisterFinishedFrameCounter(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::RegisterFinishedFrameCounter(CResourceSystem *this, unsigned int *pFrameCounter)
{
  CUtlVector<unsigned int *,CUtlMemory<unsigned int *,int>>::InsertBefore(
    this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&this->m_FinishedFrameCounters,
    elem: this->m_FinishedFrameCounters.m_Size,
    src: (KeyValues *const *)&pFrameCounter);
  *pFrameCounter = this->m_nFrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x100075D0
// Name: protected: void CResourceScatterer::ScatterField(void const __near *,void __near *,class CResourceFieldIntrospection const __near *,enum ResourceFieldType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceScatterer::ScatterField(
        CResourceScatterer *this,
        _DWORD *pSrcField,
        char *pDstField,
        CResourceFieldIntrospection *pFieldIntro,
        int nFieldType,
        ResourceFieldType_t nTypeChainIndex)
{
  CResourceScatterer *v7; // ebx
  int v8; // edi
  __int16 m_nCount; // ax
  int i; // ebx
  _DWORD *v11; // edi
  int ElementMemorySize; // eax
  int v13; // ebp
  int v14; // eax
  char *v15; // edi
  unsigned __int16 v16; // ax
  char *elem; // eax
  int ElementAlignment; // eax
  int v19; // eax
  int v20; // edi
  char *v21; // eax
  char *v22; // edi
  char *v23; // ebx
  int v24; // [esp+10h] [ebp-18h]
  int v25; // [esp+10h] [ebp-18h]
  int nSrcStride; // [esp+18h] [ebp-10h]
  int ElementDiskSize; // [esp+1Ch] [ebp-Ch]
  CUtlMap<void const *,void *,unsigned short>::Node_t search; // [esp+20h] [ebp-8h] BYREF
  int nDstStridea; // [esp+34h] [ebp+Ch]
  int nDstStride; // [esp+34h] [ebp+Ch]
  int nArrayCount; // [esp+38h] [ebp+10h]
  ResourceFieldType_t subFieldType; // [esp+3Ch] [ebp+14h]

  v7 = this;
  v8 = 1;
  v24 = 1;
  if ( nTypeChainIndex == RESOURCE_FIELD_TYPE_UNKNOWN )
  {
    m_nCount = pFieldIntro->m_nCount;
    if ( m_nCount <= 0 )
    {
      v24 = 1;
    }
    else
    {
      v24 = m_nCount;
      v8 = m_nCount;
    }
  }
  if ( nTypeChainIndex == pFieldIntro->m_nTypeChainCount - 1 )
  {
    for ( i = 0; i < v24; ++i )
    {
      v11 = (_DWORD *)((char *)pSrcField
                     + i
                     * CResourceFieldIntrospection::GetElementDiskSize(
                         this: pFieldIntro,
                         nTypeChainIndex,
                         pIntroDct: nullptr));
      ElementMemorySize = CResourceFieldIntrospection::GetElementMemorySize(
                            this: pFieldIntro,
                            nTypeChainIndex,
                            pIntroDct: nullptr);
      CResourceScatterer::ScatterRootField(
        this,
        pSrcField: v11,
        pDstField: &pDstField[i * ElementMemorySize],
        pFieldIntro);
    }
  }
  else
  {
    v13 = nTypeChainIndex + 1;
    subFieldType = CResourceFieldIntrospection::ReadTypeChain(this: pFieldIntro, nChainIndex: nTypeChainIndex + 1);
    v14 = nFieldType - 1;
    nSrcStride = nFieldType - 1;
    v25 = v8;
    while ( 1 )
    {
      switch ( v14 )
      {
        case 0:
          v15 = (char *)pSrcField + *pSrcField;
          search.key = v15;
          v16 = CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                  this: &v7->m_ScatterDict.m_Tree,
                  &search);
          if ( v16 == 0xFFFF )
          {
            nDstStridea = CResourceFieldIntrospection::GetElementMemorySize(
                            this: pFieldIntro,
                            nTypeChainIndex: v13,
                            pIntroDct: nullptr);
            ElementAlignment = CResourceFieldIntrospection::GetElementAlignment(
                                 this: pFieldIntro,
                                 nTypeChainIndex: v13,
                                 pIntroDct: nullptr);
            elem = CResourceScatterer::ScatterAlloc(this: v7, nSize: nDstStridea, nAlignment: ElementAlignment);
          }
          else
          {
            elem = (char *)v7->m_ScatterDict.m_Tree.m_Elements.m_pMemory[v16].m_Data.elem;
          }
          if ( !v7->m_bCalculatingSize )
            *(_DWORD *)pDstField = elem - pDstField;
          CResourceScatterer::ScatterField(
            this: v7,
            pSrcField: v15,
            pDstField: elem,
            pFieldIntro,
            nFieldType: subFieldType,
            nTypeChainIndex: v13);
          break;
        case 1:
          ElementDiskSize = CResourceFieldIntrospection::GetElementDiskSize(
                              this: pFieldIntro,
                              nTypeChainIndex: v13,
                              pIntroDct: nullptr);
          nDstStride = CResourceFieldIntrospection::GetElementMemorySize(
                         this: pFieldIntro,
                         nTypeChainIndex: v13,
                         pIntroDct: nullptr);
          v19 = CResourceFieldIntrospection::GetElementAlignment(
                  this: pFieldIntro,
                  nTypeChainIndex: v13,
                  pIntroDct: nullptr);
          v20 = pSrcField[1];
          nArrayCount = v20;
          if ( v20 != 0 )
            v21 = CResourceScatterer::ScatterAlloc(this: v7, nSize: nDstStride * v20, nAlignment: v19);
          else
            v21 = nullptr;
          if ( !v7->m_bCalculatingSize )
          {
            *(_DWORD *)pDstField = v21 - pDstField;
            *((_DWORD *)pDstField + 1) = v20;
          }
          if ( v20 > 0 )
          {
            v22 = v21;
            v23 = (char *)pSrcField + *pSrcField;
            do
            {
              CResourceScatterer::ScatterField(
                this,
                pSrcField: v23,
                pDstField: v22,
                pFieldIntro,
                nFieldType: subFieldType,
                nTypeChainIndex: v13);
              v22 += nDstStride;
              v23 += ElementDiskSize;
              --nArrayCount;
            }
            while ( nArrayCount != 0 );
            v7 = this;
          }
          break;
        case 4:
          _V_memcpy(dest: pDstField, src: pSrcField, count: 8);
          break;
        case 6:
          if ( !v7->m_bCalculatingSize )
            _V_memset(dest: pDstField, fill: 0, count: 4);
          break;
        default:
          break;
      }
      if ( --v25 == 0 )
        break;
      v14 = nSrcStride;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007820
// Name: public: CCountedStringPoolBase<unsigned short>::CCountedStringPoolBase<unsigned short>(enum StringPoolCase_t)
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned short> *__thiscall CCountedStringPoolBase<unsigned short>::CCountedStringPoolBase<unsigned short>(
        CCountedStringPoolBase<unsigned short> *this,
        StringPoolCase_t caseSensitivity)
{
  CUtlVector<CCountedStringPoolBase<unsigned short>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int> > *p_m_Elements; // esi
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_HashTable; // edi
  int i; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CCountedStringPoolBase<unsigned short>::hash_item_t *m_pMemory; // ecx
  int v9; // eax

  this->__vftable = (CCountedStringPoolBase<unsigned short>_vtbl *)&CCountedStringPoolBase<unsigned short>::`vftable';
  this->m_HashTable.m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Size = 0;
  this->m_HashTable.m_pElements = nullptr;
  p_m_Elements = &this->m_Elements;
  p_m_HashTable = &this->m_HashTable;
  this->m_Elements.m_Memory.m_pMemory = nullptr;
  this->m_Elements.m_Memory.m_nAllocationCount = 0;
  this->m_Elements.m_Memory.m_nGrowSize = 0;
  this->m_Elements.m_Size = 0;
  this->m_Elements.m_pElements = nullptr;
  if ( this->m_HashTable.m_Size < 1024 )
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
      this: &this->m_HashTable,
      elem: this->m_HashTable.m_Size,
      num: 1024 - this->m_HashTable.m_Size);
  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    p_m_HashTable->m_Memory.m_pMemory[i] = 0;
  this->m_FreeListStart = 0;
  m_Size = p_m_Elements->m_Size;
  m_nAllocationCount = p_m_Elements->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Grow(
      this: &p_m_Elements->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_Elements->m_Size;
  m_pMemory = p_m_Elements->m_Memory.m_pMemory;
  v9 = p_m_Elements->m_Size - m_Size - 1;
  p_m_Elements->m_pElements = p_m_Elements->m_Memory.m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v9);
  p_m_Elements->m_Memory.m_pMemory->pString = nullptr;
  p_m_Elements->m_Memory.m_pMemory->nReferenceCount = 0;
  p_m_Elements->m_Memory.m_pMemory->nNextElement = 0;
  this->m_caseSensitivity = caseSensitivity;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100078F0
// Name: public: void CCountedStringPoolBase<unsigned short>::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCountedStringPoolBase<unsigned short>::FreeAll(CCountedStringPoolBase<unsigned short> *this)
{
  int i; // eax
  int v3; // edi
  bool v4; // cc
  CCountedStringPoolBase<unsigned short>::hash_item_t *m_pMemory; // edx
  CUtlVector<CCountedStringPoolBase<unsigned short>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int> > *p_m_Elements; // esi
  int m_nAllocationCount; // eax
  CCountedStringPoolBase<unsigned short>::hash_item_t *v8; // ecx
  int v9; // eax

  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    this->m_HashTable.m_Memory.m_pMemory[i] = 0;
  v3 = 0;
  v4 = this->m_Elements.m_Size <= 0;
  this->m_FreeListStart = 0;
  if ( !v4 )
  {
    do
    {
      m_pMemory = this->m_Elements.m_Memory.m_pMemory;
      if ( m_pMemory[v3].pString != nullptr )
      {
        free(pMem: m_pMemory[v3].pString);
        this->m_Elements.m_Memory.m_pMemory[v3].pString = nullptr;
        this->m_Elements.m_Memory.m_pMemory[v3].nReferenceCount = 0;
        this->m_Elements.m_Memory.m_pMemory[v3].nNextElement = 0;
      }
      ++v3;
    }
    while ( v3 < this->m_Elements.m_Size );
  }
  p_m_Elements = &this->m_Elements;
  p_m_Elements->m_Size = 0;
  m_nAllocationCount = p_m_Elements->m_Memory.m_nAllocationCount;
  if ( m_nAllocationCount < 1 )
    CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Grow(
      this: &p_m_Elements->m_Memory,
      num: 1 - m_nAllocationCount);
  ++p_m_Elements->m_Size;
  v8 = p_m_Elements->m_Memory.m_pMemory;
  v9 = p_m_Elements->m_Size - 1;
  p_m_Elements->m_pElements = p_m_Elements->m_Memory.m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[1], src: v8, count: 8 * v9);
  p_m_Elements->m_Memory.m_pMemory->pString = nullptr;
  p_m_Elements->m_Memory.m_pMemory->nReferenceCount = 0;
  p_m_Elements->m_Memory.m_pMemory->nNextElement = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100079B0
// Name: public: CCountedStringPoolBase<unsigned int>::CCountedStringPoolBase<unsigned int>(enum StringPoolCase_t)
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned int> *__thiscall CCountedStringPoolBase<unsigned int>::CCountedStringPoolBase<unsigned int>(
        CCountedStringPoolBase<unsigned int> *this,
        StringPoolCase_t caseSensitivity)
{
  CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> *p_m_Elements; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *p_m_HashTable; // edi
  int i; // eax
  CResourceSystem::PendingResourceIdResolution_t *m_pMemory; // edi
  int m_nAllocationCount; // eax
  CResourceSystem::PendingResourceIdResolution_t *v8; // ecx
  int v9; // eax

  this->__vftable = (CCountedStringPoolBase<unsigned int>_vtbl *)&CCountedStringPoolBase<unsigned int>::`vftable';
  this->m_HashTable.m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Size = 0;
  this->m_HashTable.m_pElements = nullptr;
  p_m_Elements = (CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> *)&this->m_Elements;
  p_m_HashTable = &this->m_HashTable;
  this->m_Elements.m_Memory.m_pMemory = nullptr;
  this->m_Elements.m_Memory.m_nAllocationCount = 0;
  this->m_Elements.m_Memory.m_nGrowSize = 0;
  this->m_Elements.m_Size = 0;
  this->m_Elements.m_pElements = nullptr;
  if ( this->m_HashTable.m_Size < 1024 )
    CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(
      this: &this->m_HashTable,
      elem: this->m_HashTable.m_Size,
      num: 1024 - this->m_HashTable.m_Size);
  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    p_m_HashTable->m_Memory.m_pMemory[i] = 0;
  this->m_FreeListStart = 0;
  m_pMemory = p_m_Elements[1].m_pMemory;
  m_nAllocationCount = p_m_Elements->m_nAllocationCount;
  if ( (int)&m_pMemory->m_hFile + 1 > m_nAllocationCount )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      this: p_m_Elements,
      num: (int)&m_pMemory->m_hFile - m_nAllocationCount + 1);
  ++p_m_Elements[1].m_pMemory;
  v8 = p_m_Elements->m_pMemory;
  v9 = (char *)p_m_Elements[1].m_pMemory - (char *)m_pMemory - 1;
  p_m_Elements[1].m_nAllocationCount = (int)p_m_Elements->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[(int)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 12 * v9);
  p_m_Elements->m_pMemory->m_hFile = nullptr;
  LOBYTE(p_m_Elements->m_pMemory->m_nId) = 0;
  p_m_Elements->m_pMemory->m_nType = 0;
  this->m_caseSensitivity = caseSensitivity;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007A80
// Name: public: void CCountedStringPoolBase<unsigned int>::FreeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCountedStringPoolBase<unsigned int>::FreeAll(CCountedStringPoolBase<unsigned int> *this)
{
  int i; // eax
  int v3; // ebp
  bool v4; // cc
  int v5; // edi
  CCountedStringPoolBase<unsigned int>::hash_item_t *m_pMemory; // edx
  CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> *p_m_Elements; // esi
  int m_nAllocationCount; // eax
  CResourceSystem::PendingResourceIdResolution_t *v9; // ecx
  int v10; // eax

  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
    this->m_HashTable.m_Memory.m_pMemory[i] = 0;
  v3 = 0;
  v4 = this->m_Elements.m_Size <= 0;
  this->m_FreeListStart = 0;
  if ( !v4 )
  {
    v5 = 0;
    do
    {
      m_pMemory = this->m_Elements.m_Memory.m_pMemory;
      if ( m_pMemory[v5].pString != nullptr )
      {
        free(pMem: m_pMemory[v5].pString);
        this->m_Elements.m_Memory.m_pMemory[v5].pString = nullptr;
        this->m_Elements.m_Memory.m_pMemory[v5].nReferenceCount = 0;
        this->m_Elements.m_Memory.m_pMemory[v5].nNextElement = 0;
      }
      ++v3;
      ++v5;
    }
    while ( v3 < this->m_Elements.m_Size );
  }
  p_m_Elements = (CUtlMemory<CResourceSystem::PendingResourceIdResolution_t,int> *)&this->m_Elements;
  p_m_Elements[1].m_pMemory = nullptr;
  m_nAllocationCount = p_m_Elements->m_nAllocationCount;
  if ( m_nAllocationCount < 1 )
    CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int>::Grow(
      this: p_m_Elements,
      num: 1 - m_nAllocationCount);
  ++p_m_Elements[1].m_pMemory;
  v9 = p_m_Elements->m_pMemory;
  v10 = (int)&p_m_Elements[1].m_pMemory[-1].m_nId + 3;
  p_m_Elements[1].m_nAllocationCount = (int)p_m_Elements->m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &v9[1], src: v9, count: 12 * v10);
  p_m_Elements->m_pMemory->m_hFile = nullptr;
  LOBYTE(p_m_Elements->m_pMemory->m_nId) = 0;
  p_m_Elements->m_pMemory->m_nType = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007B50
// Name: public: CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x10007BB0
// Name: private: void CResourceSystem::PurgeOvercommittedDcts(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::PurgeOvercommittedDcts(CResourceSystem *this, unsigned int nFinishedFrameCount)
{
  bool v2; // cf
  int m_BlocksAllocated; // esi
  void *v4; // esp
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0> *p_m_FileData; // ebx
  int Elements; // ecx
  int v7; // esi
  int v8; // ebx
  int v9; // ecx
  int v10; // ebx
  unsigned int m_nDctMemoryUsed; // eax
  int v12; // esi
  int v13; // ecx
  void **v14; // esi
  bool v15; // cc
  int v16[3]; // [esp+0h] [ebp-14h] BYREF
  CResourceSystem *v17; // [esp+Ch] [ebp-8h]
  int nCount; // [esp+10h] [ebp-4h]

  v2 = this->m_nDctMemoryUsed < this->m_nDctMemoryLimit;
  v17 = this;
  if ( !v2 )
  {
    m_BlocksAllocated = this->m_FileData.m_EntryMemory.m_BlocksAllocated;
    v4 = alloca(4 * m_BlocksAllocated);
    p_m_FileData = &this->m_FileData;
    Elements = CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::GetElements(
                 this: &this->m_FileData,
                 nFirstElement: 0,
                 nCount: m_BlocksAllocated,
                 pHandles: v16);
    v7 = (4 * Elements) >> 2;
    nCount = Elements;
    CResourceSystem::s_pFileHashTable = p_m_FileData;
    if ( v7 > 1 )
    {
      v8 = v7 / 2;
      if ( v7 / 2 > 0 )
      {
        do
        {
          v9 = v16[--v8];
          std::_Adjust_heap<int *,int,int,bool (__cdecl *)(int const &,int const &)>(
            _First: v16,
            _Hole: v8,
            _Bottom: v7,
            _Val: v9,
            _Pred: CResourceSystem::SortLessFunc);
        }
        while ( v8 > 0 );
        Elements = nCount;
      }
    }
    std::_Sort_heap<int *,bool (__cdecl *)(int const &,int const &)>(
      _First: (char *)v16,
      _Last: &v16[Elements],
      _Pred: CResourceSystem::SortLessFunc);
    v10 = 0;
    CResourceSystem::s_pFileHashTable = nullptr;
    if ( nCount > 0 )
    {
      do
      {
        m_nDctMemoryUsed = v17->m_nDctMemoryUsed;
        if ( m_nDctMemoryUsed <= v17->m_nDctMemoryLimit )
          break;
        v12 = v16[v10];
        v13 = *(_DWORD *)(v12 + 8);
        v14 = (void **)(v12 + 8);
        if ( v13 == 0 )
          break;
        v17->m_nDctMemoryUsed = m_nDctMemoryUsed - *(_DWORD *)(v13 + 4);
        free(pMem: *v14);
        v15 = ++v10 < nCount;
        *v14 = nullptr;
      }
      while ( v15 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007CB0
// Name: public: CResourceScatterer::CResourceScatterer(class CResourceSystem const __near *)
// Source: json
//------------------------------------------------------------------------------
CResourceScatterer *__thiscall CResourceScatterer::CResourceScatterer(
        CResourceScatterer *this,
        const CResourceSystem *pResourceSystem)
{
  this->m_ScatterDict.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const void *const *, const void *const *))CDefOps<void const *>::LessFunc;
  this->m_ScatterDict.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_ScatterDict.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_ScatterDict.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_ScatterDict.m_Tree.m_Root = -1;
  this->m_ScatterDict.m_Tree.m_NumElements = 0;
  this->m_ScatterDict.m_Tree.m_FirstFree = -1;
  this->m_ScatterDict.m_Tree.m_LastAlloc.index = -1;
  this->m_ScatterDict.m_Tree.m_pElements = this->m_ScatterDict.m_Tree.m_Elements.m_pMemory;
  this->m_pResourceSystem = pResourceSystem;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007CF0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t *insert)
{
  const CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t *v2; // ebx
  unsigned __int16 v4; // di
  UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // ecx
  unsigned __int16 v8[2]; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    parent: v8,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode((CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)this);
  CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent: v8[0],
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  v6 = v4;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)-8 )
  {
    m_pMemory[v6].m_Data.key = v2->key;
    m_pMemory[v6].m_Data.elem = v2->elem;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10007D60
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<void const *,void *,unsigned short>::Node_t *insert)
{
  const CUtlMap<void const *,void *,unsigned short>::Node_t *v2; // ebx
  unsigned __int16 v4; // di
  UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // ecx
  unsigned __int16 v8[2]; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    parent: v8,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode((CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)this);
  CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent: v8[0],
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  v6 = v4;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)-8 )
  {
    m_pMemory[v6].m_Data.key = v2->key;
    m_pMemory[v6].m_Data.elem = v2->elem;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10007E50
// Name: public: virtual CResourceSystem::~CResourceSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::~CResourceSystem(CResourceSystem *this)
{
  this->__vftable = (CResourceSystem_vtbl *)&CResourceSystem::`vftable';
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ActiveIdResolutions);
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::Purge(this: &this->m_PendingResourceIdResolutions);
  free(pMem: this->m_PendingResourceIdResolutions.m_Head.value.pNode);
  CTSListBase::Detach(this: &this->m_PendingResourceIdResolutions.m_FreeNodes);
  CTSQueue<CAsyncIOResult_t,0>::Purge(this: &this->m_IOCompletionQueue.m_TSIOResultQueue);
  free(pMem: this->m_IOCompletionQueue.m_TSIOResultQueue.m_Head.value.pNode);
  CTSListBase::Detach(this: &this->m_IOCompletionQueue.m_TSIOResultQueue.m_FreeNodes);
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::RemoveAll(this: &this->m_FileData);
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_FileData.m_EntryMemory);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_FinishedFrameCounters);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_FrameCounters);
  this->m_FileSymbols.m_FileStringPool.__vftable = (CCountedStringPoolBase<unsigned int>_vtbl *)&CCountedStringPoolBase<unsigned int>::`vftable';
  CCountedStringPoolBase<unsigned int>::FreeAll(this: &this->m_FileSymbols.m_FileStringPool);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_FileSymbols.m_FileStringPool.m_Elements);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_FileSymbols.m_FileStringPool.m_HashTable);
  this->m_FileSymbols.m_PathStringPool.__vftable = (CCountedStringPoolBase<unsigned short>_vtbl *)&CCountedStringPoolBase<unsigned short>::`vftable';
  CCountedStringPoolBase<unsigned short>::FreeAll(this: &this->m_FileSymbols.m_PathStringPool);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_FileSymbols.m_PathStringPool.m_Elements);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_FileSymbols.m_PathStringPool.m_HashTable);
  CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_ClassBindings.m_Tree);
  CResourceIntrospectionDictionary::~CResourceIntrospectionDictionary(this: &this->m_IntrospectionDict);
}

//------------------------------------------------------------------------------
// Address: 0x10007F30
// Name: public: virtual class CResourceStructIntrospection const __near * CResourceSystem::FindStructIntrospectionByBlockType(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceSystem::FindStructIntrospectionByBlockType(
        CResourceSystem *this,
        unsigned int a1)
{
  return CResourceIntrospectionDictionary::FindStructIntrospectionByBlockType(
           this: &this->m_IntrospectionDict,
           nBlockType: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10007F40
// Name: public: virtual class CResourceStructIntrospection const __near * CResourceSystem::FindStructIntrospection(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceSystem::FindStructIntrospection(
        CResourceSystem *this,
        unsigned int a1)
{
  return CResourceIntrospectionDictionary::FindStructIntrospection(this: &this->m_IntrospectionDict, id: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10007F50
// Name: public: virtual class CResourceStructIntrospection const __near * CResourceSystem::FindStructIntrospection(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceSystem::FindStructIntrospection(
        CResourceSystem *this,
        const char *a1)
{
  return CResourceIntrospectionDictionary::FindStructIntrospection(this: &this->m_IntrospectionDict, pStructName: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10007F60
// Name: public: virtual class CResourceEnumIntrospection const __near * CResourceSystem::FindEnumIntrospection(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceEnumIntrospection *__thiscall CResourceSystem::FindEnumIntrospection(
        CResourceSystem *this,
        unsigned int a1)
{
  return CResourceIntrospectionDictionary::FindEnumIntrospection(this: &this->m_IntrospectionDict, id: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10007F70
// Name: public: virtual class CResourceEnumIntrospection const __near * CResourceSystem::FindEnumIntrospection(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CResourceEnumIntrospection *__thiscall CResourceSystem::FindEnumIntrospection(
        CResourceSystem *this,
        const char *a1)
{
  return CResourceIntrospectionDictionary::FindEnumIntrospection(this: &this->m_IntrospectionDict, pEnumName: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10007F80
// Name: public: virtual class CResourceTypedefIntrospection const __near * CResourceSystem::FindTypedefIntrospection(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceTypedefIntrospection *__thiscall CResourceSystem::FindTypedefIntrospection(
        CResourceSystem *this,
        unsigned int a1)
{
  return CResourceIntrospectionDictionary::FindTypedefIntrospection(this: &this->m_IntrospectionDict, id: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10007F90
// Name: public: virtual class CResourceTypedefIntrospection const __near * CResourceSystem::FindTypedefIntrospection(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CResourceTypedefIntrospection *__thiscall CResourceSystem::FindTypedefIntrospection(
        CResourceSystem *this,
        const char *a1)
{
  return CResourceIntrospectionDictionary::FindTypedefIntrospection(this: &this->m_IntrospectionDict, pTypedefName: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10007FA0
// Name: public: virtual bool CResourceSystem::FindEnumeratedValue(void __near *,char const __near *,char const __near *,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CResourceSystem::FindEnumeratedValue(
        CResourceSystem *this,
        void *a1,
        const char *a2,
        const char *a3,
        int a4)
{
  return CResourceIntrospectionDictionary::FindEnumeratedValue(
           this: &this->m_IntrospectionDict,
           pValue: a1,
           pEnumName: a2,
           pEnumValueName: a3,
           nDefaultValue: a4);
}

//------------------------------------------------------------------------------
// Address: 0x10007FB0
// Name: public: virtual char const __near * CResourceSystem::FindEnumerationName(char const __near *,int,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CResourceSystem::FindEnumerationName(
        CResourceSystem *this,
        const char *a1,
        int a2,
        const char *a3)
{
  return CResourceIntrospectionDictionary::FindEnumerationName(
           this: &this->m_IntrospectionDict,
           pEnumName: a1,
           nValue: a2,
           pDefaultName: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10007FC0
// Name: public: virtual class CResourceStructIntrospection const __near * CResourceSystem::FindStructIntrospectionForResourceType(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceSystem::FindStructIntrospectionForResourceType(
        CResourceSystem *this,
        int a1)
{
  return CResourceIntrospectionDictionary::FindStructIntrospectionForResourceType(
           this: &this->m_IntrospectionDict,
           nType: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10007FD0
// Name: public: virtual class CResourceStructIntrospection const __near * CResourceSystem::FindPermanentStructIntrospectionForResourceType(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceSystem::FindPermanentStructIntrospectionForResourceType(
        CResourceSystem *this,
        int a1)
{
  return CResourceIntrospectionDictionary::FindPermanentStructIntrospectionForResourceType(
           this: &this->m_IntrospectionDict,
           nType: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10007FE0
// Name: public: virtual void CResourceSystem::FrameUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::FrameUpdate(CResourceSystem *this)
{
  unsigned int v2; // ebp
  CResourceTypeManagerBase **m_ppTypeManagers; // edi
  int i; // ebx
  int m_Size; // ecx
  int j; // eax
  unsigned int *v7; // edx

  this->m_bInFrameUpdate = true;
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::Commit(this: &this->m_FileData);
  CIOCompletionQueue::ProcessAllResultCallbacks(this: &this->m_IOCompletionQueue);
  CResourceSystem::ExecuteFileIdResolutionRequests(this);
  v2 = CResourceSystem::ComputeFinishedFrameCount(this);
  CResourceSystem::PurgeOvercommittedDcts(this, nFinishedFrameCount: v2);
  m_ppTypeManagers = this->m_ppTypeManagers;
  for ( i = 7; i != 0; --i )
  {
    if ( *m_ppTypeManagers != nullptr )
      (*m_ppTypeManagers)->FrameUpdate(this: *m_ppTypeManagers, a2: v2);
    ++m_ppTypeManagers;
  }
  m_Size = this->m_FrameCounters.m_Size;
  ++this->m_nFrameCount;
  for ( j = 0; j < m_Size; *v7 = this->m_nFrameCount )
    v7 = this->m_FrameCounters.m_Memory.m_pMemory[j++];
  this->m_bInFrameUpdate = false;
}

//------------------------------------------------------------------------------
// Address: 0x10008080
// Name: public: CResourceSystem::CResourceSystem(void)
// Source: json
//------------------------------------------------------------------------------
CResourceSystem *__thiscall CResourceSystem::CResourceSystem(CResourceSystem *this)
{
  this->__vftable = (CResourceSystem_vtbl *)&CResourceSystem::`vftable';
  CResourceIntrospectionDictionary::CResourceIntrospectionDictionary(this: &this->m_IntrospectionDict);
  this->m_ClassBindings.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<void const *>::LessFunc;
  this->m_ClassBindings.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_ClassBindings.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_ClassBindings.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_ClassBindings.m_Tree.m_Root = -1;
  this->m_ClassBindings.m_Tree.m_FirstFree = -1;
  this->m_ClassBindings.m_Tree.m_NumElements = 0;
  this->m_ClassBindings.m_Tree.m_LastAlloc.index = -1;
  this->m_ClassBindings.m_Tree.m_pElements = this->m_ClassBindings.m_Tree.m_Elements.m_pMemory;
  CCountedStringPoolBase<unsigned short>::CCountedStringPoolBase<unsigned short>(
    this: &this->m_FileSymbols.m_PathStringPool,
    caseSensitivity: StringPoolCaseInsensitive);
  CCountedStringPoolBase<unsigned int>::CCountedStringPoolBase<unsigned int>(
    this: &this->m_FileSymbols.m_FileStringPool,
    caseSensitivity: StringPoolCaseInsensitive);
  CThreadSpinRWLock::CThreadSpinRWLock(this: &this->m_FileSymbols.m_lock);
  this->m_FrameCounters.m_Memory.m_pMemory = nullptr;
  this->m_FrameCounters.m_Memory.m_nAllocationCount = 0;
  this->m_FrameCounters.m_Memory.m_nGrowSize = 0;
  this->m_FrameCounters.m_Size = 0;
  this->m_FrameCounters.m_pElements = nullptr;
  this->m_FinishedFrameCounters.m_Memory.m_pMemory = nullptr;
  this->m_FinishedFrameCounters.m_Memory.m_nAllocationCount = 0;
  this->m_FinishedFrameCounters.m_Memory.m_nGrowSize = 0;
  this->m_FinishedFrameCounters.m_Size = 0;
  this->m_FinishedFrameCounters.m_pElements = nullptr;
  CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>::CUtlTSHash<ResourceFileData_t,251,void *,CUtlTSHashGenericHash<251,void *>,0>(
    this: &this->m_FileData,
    nAllocationCount: 256);
  this->m_nPendingFileIdRequests.m_value = 0;
  this->m_nPendingVTDRequests.m_value = 0;
  CTSQueue<CAsyncIOResult_t,0>::CTSQueue<CAsyncIOResult_t,0>(this: &this->m_IOCompletionQueue.m_TSIOResultQueue);
  CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>::CTSQueue<CResourceSystem::PendingResourceIdResolution_t,0>(this: &this->m_PendingResourceIdResolutions);
  this->m_ActiveIdResolutions.m_Memory.m_pMemory = nullptr;
  this->m_ActiveIdResolutions.m_Memory.m_nAllocationCount = 0;
  this->m_ActiveIdResolutions.m_Memory.m_nGrowSize = 0;
  this->m_ActiveIdResolutions.m_Size = 0;
  this->m_ActiveIdResolutions.m_pElements = nullptr;
  this->m_nFrameCount = 0;
  *(_QWORD *)this->m_ppTypeManagers = 0;
  *(_QWORD *)&this->m_ppTypeManagers[2] = 0;
  *(_QWORD *)&this->m_ppTypeManagers[4] = 0;
  this->m_ppTypeManagers[6] = nullptr;
  this->m_nDctMemoryLimit = 0x20000;
  this->m_nDctMemoryUsed = 0;
  _InterlockedExchange(&this->m_nPendingFileIdRequests.m_value, 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100081F0
// Name: public: virtual void CResourceSystem::InstallSchemaClassBinding(class CSchemaClassBindingBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceSystem::InstallSchemaClassBinding(CResourceSystem *this, CSchemaClassBindingBase *pBinding)
{
  unsigned int v3; // ebx
  CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short> *p_m_ClassBindings; // ebp
  unsigned __int16 v5; // ax
  CSchemaClassBindingBase *elem; // esi
  CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t search; // [esp+10h] [ebp-8h] BYREF

  v3 = ComputeStructureNameHash(pStructName: pBinding->m_pClassName);
  p_m_ClassBindings = &this->m_ClassBindings;
  search.key = v3;
  v5 = CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_ClassBindings.m_Tree,
         &search);
  if ( v5 != 0xFFFF )
  {
    elem = this->m_ClassBindings.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
    if ( _V_strcmp(s1: elem->m_pClassName, s2: pBinding->m_pClassName) != 0 )
      _Error(a1: "Structure name collision: '%s' and '%s' (%d)\n", pBinding->m_pClassName, elem->m_pClassName, v3);
  }
  search.key = v3;
  search.elem = pBinding;
  CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &p_m_ClassBindings->m_Tree,
    insert: &search);
}

//------------------------------------------------------------------------------
// Address: 0x10008290
// Name: protected: void CResourceScatterer::ScatterStruct(void const __near *,void __near *,class CResourceStructIntrospection const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceScatterer::ScatterStruct(
        CResourceScatterer *this,
        char *pSrcStruct,
        char *pDstStruct,
        const CResourceStructIntrospection *pStructIntro)
{
  const CResourceStructIntrospection *v5; // edi
  int v6; // ebx
  CResourceFieldIntrospection *Field; // esi
  __int16 m_nOnDiskOffset; // ax
  char *v9; // ebx
  char *v10; // edi
  ResourceFieldType_t TypeChain; // eax
  char *v12; // edi
  int ElementMemorySize; // eax
  CSchemaClassBindingBase *v14; // eax
  int nFields; // [esp+Ch] [ebp-Ch]
  CUtlMap<void const *,void *,unsigned short>::Node_t insert; // [esp+10h] [ebp-8h] BYREF

  insert.elem = pDstStruct;
  insert.key = pSrcStruct;
  CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &this->m_ScatterDict.m_Tree,
    &insert);
  v5 = pStructIntro;
  v6 = 0;
  insert.key = (const void *)CResourceStructIntrospection::GetFieldCount(this: pStructIntro);
  nFields = 0;
  if ( (int)insert.key > 0 )
  {
    while ( 1 )
    {
      Field = (CResourceFieldIntrospection *)CResourceStructIntrospection::GetField(this: v5, nIndex: v6);
      m_nOnDiskOffset = Field->m_nOnDiskOffset;
      if ( m_nOnDiskOffset >= 0 )
        break;
      if ( !this->m_bCalculatingSize )
      {
        v12 = &pDstStruct[Field->m_nInMemoryOffset];
        ElementMemorySize = CResourceFieldIntrospection::GetElementMemorySize(
                              this: Field,
                              nTypeChainIndex: 0,
                              pIntroDct: nullptr);
        _V_memset(dest: v12, fill: 0, count: Field->m_nCount * ElementMemorySize);
        goto LABEL_6;
      }
LABEL_7:
      nFields = ++v6;
      if ( v6 >= (int)insert.key )
        goto LABEL_8;
    }
    v9 = &pDstStruct[Field->m_nInMemoryOffset];
    v10 = &pSrcStruct[m_nOnDiskOffset];
    TypeChain = CResourceFieldIntrospection::ReadTypeChain(this: Field, nChainIndex: 0);
    CResourceScatterer::ScatterField(
      this,
      pSrcField: v10,
      pDstField: v9,
      pFieldIntro: Field,
      nFieldType: TypeChain,
      nTypeChainIndex: RESOURCE_FIELD_TYPE_UNKNOWN);
    v6 = nFields;
LABEL_6:
    v5 = pStructIntro;
    goto LABEL_7;
  }
LABEL_8:
  if ( CResourceStructIntrospection::HasVTable(this: v5) )
  {
    v14 = this->m_pResourceSystem->FindClassBinding(this: this->m_pResourceSystem, a2: v5->m_nId);
    if ( v14 != nullptr )
      v14->ConstructInPlace(this: v14, a2: pDstStruct);
    else
      _Error(a1: "Failed to find runtime class binding for %s\n", (const char *)&v5->m_pName + v5->m_pName.m_nOffset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100083B0
// Name: public: void __near * CResourceScatterer::DoScatter(void const __near *,class CResourceStructIntrospection const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CResourceScatterer::DoScatter(
        CResourceScatterer *this,
        char *pSrcStruct,
        const CResourceStructIntrospection *pStructIntro,
        int *pOutResultSize)
{
  int m_nAlignment; // eax
  void *v6; // eax
  int m_nCalculatedRequiredSize; // ecx
  int m_nMaxAlignment; // eax
  int m_nMemorySize; // edx
  char *v11; // ebx

  this->m_nCalculatedRequiredSize = 0;
  this->m_nMaxAlignment = 1;
  this->m_bCalculatingSize = true;
  m_nAlignment = pStructIntro->m_nAlignment;
  this->m_nCalculatedRequiredSize = pStructIntro->m_nMemorySize + ((m_nAlignment - 1) & ~(m_nAlignment - 1));
  if ( m_nAlignment == 0 )
    m_nAlignment = 1;
  this->m_nMaxAlignment = m_nAlignment;
  CResourceScatterer::ScatterStruct(this, pSrcStruct, pDstStruct: nullptr, pStructIntro);
  this->m_bCalculatingSize = false;
  CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_ScatterDict.m_Tree);
  v6 = g_pAsyncFileSystem->AllocateBuffer(
         this: g_pAsyncFileSystem,
         a2: this->m_nCalculatedRequiredSize,
         a3: this->m_nMaxAlignment);
  m_nCalculatedRequiredSize = this->m_nCalculatedRequiredSize;
  this->m_pAllocChunkBase = v6;
  this->m_pAllocChunkNextAlloc = v6;
  *pOutResultSize = m_nCalculatedRequiredSize;
  m_nMaxAlignment = pStructIntro->m_nAlignment;
  m_nMemorySize = pStructIntro->m_nMemorySize;
  if ( this->m_bCalculatingSize )
  {
    this->m_nCalculatedRequiredSize = m_nMemorySize
                                    + (~(m_nMaxAlignment - 1) & (this->m_nCalculatedRequiredSize + m_nMaxAlignment - 1));
    if ( this->m_nMaxAlignment > m_nMaxAlignment )
      m_nMaxAlignment = this->m_nMaxAlignment;
    this->m_nMaxAlignment = m_nMaxAlignment;
    CResourceScatterer::ScatterStruct(this, pSrcStruct, pDstStruct: nullptr, pStructIntro);
    return nullptr;
  }
  else
  {
    v11 = (char *)(~(m_nMaxAlignment - 1) & ((int)this->m_pAllocChunkNextAlloc + m_nMaxAlignment - 1));
    this->m_pAllocChunkNextAlloc = &v11[m_nMemorySize];
    CResourceScatterer::ScatterStruct(this, pSrcStruct, pDstStruct: v11, pStructIntro);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100084A0
// Name: public: virtual bool CResourceSystem::UnpackIntrospectedBlock(void const __near *,unsigned int,class CResourceIntrospection const __near *,class CResourceStructIntrospection const __near *,class CResourceStructIntrospection const __near *,void const __near * __near *,int __near *,enum IntrospectionCompatibilityType_t __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourceSystem::UnpackIntrospectedBlock(
        CResourceSystem *this,
        char *pResourceData,
        unsigned int nSrcDataSize,
        const CResourceIntrospection *pSrcIntro,
        const CResourceStructIntrospection *pSrcStructIntro,
        const CResourceStructIntrospection *pDstStructIntro,
        char **pOutResult,
        int *pOutResultSize,
        IntrospectionCompatibilityType_t *pOutCompat)
{
  IntrospectionCompatibilityType_t v10; // eax
  CResourceScatterer s; // [esp+10h] [ebp-38h] BYREF

  *pOutResult = nullptr;
  *pOutResultSize = 0;
  s.m_ScatterDict.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const void *const *, const void *const *))this;
  *pOutCompat = INTROSPECTION_COMPAT_UNKNOWN;
  if ( pSrcIntro != nullptr )
  {
    if ( pSrcStructIntro != nullptr )
    {
      if ( pDstStructIntro != nullptr )
      {
        if ( CResourceIntrospection::GetVersion(this: pSrcIntro) == 2 )
        {
          v10 = CResourceIntrospection::CalculateCompatibility(this: pSrcIntro);
          *pOutCompat = v10;
          if ( v10 == INTROSPECTION_COMPAT_REQUIRES_CONVERSION )
          {
            _Warning(a1: "ERROR: Unpack upconversion not supported yet.\n");
            return 0;
          }
          else
          {
            if ( v10 == INTROSPECTION_COMPAT_REQUIRES_SCATTER )
            {
              CResourceScatterer::CResourceScatterer(
                this: (CResourceScatterer *)&s.m_ScatterDict.m_Tree.m_Elements,
                pResourceSystem: (const CResourceSystem *)s.m_ScatterDict.m_Tree.m_LessFunc.m_LessFunc);
              *pOutResult = CResourceScatterer::DoScatter(
                              this: (CResourceScatterer *)&s.m_ScatterDict.m_Tree.m_Elements,
                              pSrcStruct: pResourceData,
                              pStructIntro: pSrcStructIntro,
                              pOutResultSize);
              CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: (CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&s.m_ScatterDict.m_Tree.m_Elements);
            }
            else
            {
              *pOutResult = pResourceData;
              *pOutResultSize = nSrcDataSize;
            }
            return 1;
          }
        }
        else
        {
          _Warning(a1: "ERROR: Out-of-date source introspection dictionary\n");
          return 0;
        }
      }
      else
      {
        _Warning(a1: "ERROR: Invalid destination introspection struct.\n");
        return 0;
      }
    }
    else
    {
      _Warning(a1: "ERROR: Invalid source introspection struct.\n");
      return 0;
    }
  }
  else
  {
    _Warning(a1: "ERROR: Invalid source introspection data.\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C050
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
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
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C190
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
// Address: 0x10001190
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceStructIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x100011F0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceEnumIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x10001250
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CResourceTypedefIntrospection const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x10004310
// Name: __CreateCResourceSystemIResourceSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CResourceSystem *__cdecl _CreateCResourceSystemIResourceSystem_interface()
{
  return &s_ResourceSystem;
}

//------------------------------------------------------------------------------
// Address: 0x100049A0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,class CSchemaClassBindingBase __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CSchemaClassBindingBase *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x10004B20
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<void const __near *,void __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<void const __near *,void __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short,CUtlMap<void const *,void *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void const *,void *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}
