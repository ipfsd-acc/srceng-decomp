// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/classcheck/processmodule.cpp
// Functions: 87
// ============================================================

#include "utils\classcheck\processmodule.h"

//------------------------------------------------------------------------------
// Address: 0x00402920
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_423FE4 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00402980
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_423FE4 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004029F0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_423FE4 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_423FE4 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402AC0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,MissingType,unsigned short>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402BB0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_423FE4 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_423FE4;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00402C20
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short> *v12; // edx

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
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
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
// Address: 0x00402D20
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00402E20
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00402F20
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,MissingType,unsigned short>::Node_t *search)
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
      if ( (`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00403020
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x004030E0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
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
  if ( CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i) == 0xFFFF )
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                       this,
                       i);
    v7 = `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    for ( result = (unsigned __int16)result; ; result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Parent )
    {
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      v10 = (_WORD)v9 == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v9];
      if ( *((_WORD *)v10 + 1) != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
    }
  }
  else
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                       this,
                       i);
    v4 = `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    result = (unsigned __int16)result;
    while ( 1 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( *(_WORD *)v6 == 0xFFFF )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)result == 0xFFFF )
        result = (unsigned __int16)`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004032E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
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
    v4 = `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_423FE4 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_423FE4 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_423FE4 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_423FE4 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_423FE4 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_423FE4 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_423FE4 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_423FE4 = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
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
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_423FE4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_423FE4 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_423FE4 = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x00403890
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x00403900
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004039E0
// Name: public: void CUtlDict<class MissingType,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<MissingType,unsigned short>::RemoveAll(CUtlDict<MissingType,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00403A40
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MissingType,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,MissingType,unsigned short>::Node_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00403AD0
// Name: public: unsigned short CUtlDict<class MissingType,unsigned short>::Insert(char const __near *,class MissingType const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<MissingType,unsigned short>::Insert(
        CUtlDict<MissingType,unsigned short> *this,
        const char *pName,
        const MissingType *element)
{
  char *v4; // eax
  CClassVariable *var; // edx
  CUtlMap<char const *,MissingType,unsigned short>::Node_t insert; // [esp+8h] [ebp-Ch] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  insert.key = v4;
  var = element->var;
  insert.elem.owning_class = element->owning_class;
  insert.elem.var = var;
  return CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x00406870
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::SetSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::SetSize(CUtlVector<char,CUtlMemory<char,int> > *this, int size)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v5; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004069C0
// Name: public: virtual class CClass __near * CCodeProcessor::FindClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CClass *__thiscall CCodeProcessor::FindClass(CCodeProcessor *this, const char *name)
{
  CClass *m_pClassList; // esi

  m_pClassList = this->m_pClassList;
  if ( m_pClassList == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: m_pClassList->m_szName, s2: name) != 0 )
  {
    m_pClassList = m_pClassList->m_pNext;
    if ( m_pClassList == nullptr )
      return nullptr;
  }
  return m_pClassList;
}

//------------------------------------------------------------------------------
// Address: 0x00406A00
// Name: int FnClassSortCompare(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FnClassSortCompare(const char **elem1, const char **elem2)
{
  return _V_stricmp(s1: *elem1, s2: *elem2);
}

//------------------------------------------------------------------------------
// Address: 0x00406A20
// Name: public: void CCodeProcessor::SortClassList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SortClassList(CCodeProcessor *this)
{
  CClass *m_pClassList; // eax
  signed int v3; // edi
  _DWORD *v4; // esi
  CClass *v5; // ecx
  signed int i; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // edi

  m_pClassList = this->m_pClassList;
  v3 = 0;
  if ( m_pClassList != nullptr )
  {
    do
    {
      m_pClassList = m_pClassList->m_pNext;
      ++v3;
    }
    while ( m_pClassList != nullptr );
    if ( v3 > 1 )
    {
      v4 = operator new(nSize: 4 * v3);
      if ( v4 != nullptr )
      {
        v5 = this->m_pClassList;
        for ( i = 0; i < v3; ++i )
        {
          v4[i] = v5;
          v5 = v5->m_pNext;
        }
        qsort(base: v4, num: v3, width: 4u, comp: (int (__cdecl *)(const void *, const void *))FnClassSortCompare);
        v7 = v3 - 1;
        v8 = 0;
        do
        {
          v9 = v4[v8];
          v10 = v4[++v8];
          *(_DWORD *)(v9 + 16788) = v10;
        }
        while ( v8 < v7 );
        *(_DWORD *)(v4[v8] + 16788) = 0;
        this->m_pClassList = (CClass *)*v4;
      }
      free(pMem: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406AD0
// Name: public: void CCodeProcessor::ResolveBaseClasses(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::ResolveBaseClasses(CCodeProcessor *this, const char *baseentityclass)
{
  CClass *i; // esi
  CClass *j; // esi

  CCodeProcessor::SortClassList(this);
  for ( i = this->m_pClassList; i != nullptr; i = i->m_pNext )
  {
    if ( i->m_szBaseClass[0] != 0 )
      i->m_pBaseClass = this->FindClass(this, a2: i->m_szBaseClass);
  }
  for ( j = this->m_pClassList; j != nullptr; j = j->m_pNext )
    CClass::CheckChildOfBaseEntity(this: j, baseentityclass);
}

//------------------------------------------------------------------------------
// Address: 0x00406B40
// Name: public: void CCodeProcessor::PrintMissingTDFields(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::PrintMissingTDFields(CCodeProcessor *this)
{
  CCodeProcessor *v1; // esi
  CClass *m_pClassList; // esi
  int v3; // ebx
  int v4; // edi
  CClass *v5; // esi
  int v6; // ebx
  int v7; // edi
  CClass *v8; // esi
  int v9; // ebx
  int v10; // edi
  CClass *v11; // esi
  int v12; // ebx
  int v13; // edi
  CClass *i; // esi
  CClass *j; // esi
  int c; // [esp+10h] [ebp-4h] BYREF

  v1 = this;
  if ( ((unsigned __int8 (__fastcall *)(CCodeProcessor *))this->GetPrintTDs)(a1: this) != 0 )
  {
    m_pClassList = v1->m_pClassList;
    v3 = 0;
    v4 = 0;
    if ( m_pClassList != nullptr )
    {
      do
      {
        if ( (m_pClassList->m_bDerivedFromCBaseEntity || m_pClassList->m_bHasSaveRestoreData)
          && CClass::CheckForMissingTypeDescriptionFields(this: m_pClassList, missingcount: &c, createtds: false) )
        {
          ++v3;
          v4 += c;
        }
        m_pClassList = m_pClassList->m_pNext;
      }
      while ( m_pClassList != nullptr );
      if ( v4 != 0 )
      {
        vprint(depth: 0, fmt: "\nSummary:  %i fields missing from %i classes\n", v4, v3);
LABEL_13:
        vprint(depth: 0, fmt: "\n");
        v1 = this;
        goto LABEL_14;
      }
      if ( v3 != 0 )
      {
        vprint(depth: 0, fmt: "\nSummary:  no errors for %i classes\n", v3);
        goto LABEL_13;
      }
    }
    vprint(depth: 0, fmt: "\nSummary:  no saverestore info present\n");
    goto LABEL_13;
  }
LABEL_14:
  if ( !v1->GetPrintPredTDs(this: v1) )
    goto LABEL_27;
  v5 = this->m_pClassList;
  v6 = 0;
  v7 = 0;
  if ( v5 == nullptr )
  {
LABEL_24:
    vprint(depth: 0, fmt: "\nSummary:  no prediction info present\n");
    goto LABEL_26;
  }
  do
  {
    if ( (v5->m_bDerivedFromCBaseEntity || v5->m_bHasPredictionData)
      && CClass::CheckForMissingPredictionFields(this: v5, missingcount: &c, createtds: false) )
    {
      ++v6;
      v7 += c;
    }
    v5 = v5->m_pNext;
  }
  while ( v5 != nullptr );
  if ( v7 == 0 )
  {
    if ( v6 != 0 )
    {
      vprint(depth: 0, fmt: "\nSummary:  no errors for %i predictable classes\n", v6);
      goto LABEL_26;
    }
    goto LABEL_24;
  }
  vprint(depth: 0, fmt: "\nSummary:  %i prediction fields missing from %i classes\n", v7, v6);
LABEL_26:
  vprint(depth: 0, fmt: "\n");
  v1 = this;
LABEL_27:
  if ( !v1->GetPrintCreateMissingTDs(this: v1) )
    goto LABEL_40;
  v8 = this->m_pClassList;
  v9 = 0;
  v10 = 0;
  if ( v8 == nullptr )
  {
LABEL_37:
    vprint(depth: 0, fmt: "\nSummary:  no saverestore info present\n");
    goto LABEL_39;
  }
  do
  {
    if ( (v8->m_bDerivedFromCBaseEntity || v8->m_bHasSaveRestoreData)
      && CClass::CheckForMissingTypeDescriptionFields(this: v8, missingcount: &c, createtds: true) )
    {
      ++v9;
      v10 += c;
    }
    v8 = v8->m_pNext;
  }
  while ( v8 != nullptr );
  if ( v10 == 0 )
  {
    if ( v9 != 0 )
    {
      vprint(depth: 0, fmt: "\nSummary:  no errors for %i classes\n", v9);
      goto LABEL_39;
    }
    goto LABEL_37;
  }
  vprint(depth: 0, fmt: "\nSummary:  %i saverestore fields missing from %i classes\n", v10, v9);
LABEL_39:
  vprint(depth: 0, fmt: "\n");
  v1 = this;
LABEL_40:
  if ( !v1->GetPrintCreateMissingPredTDs(this: v1) )
    goto LABEL_53;
  v11 = this->m_pClassList;
  v12 = 0;
  v13 = 0;
  if ( v11 == nullptr )
  {
LABEL_50:
    vprint(depth: 0, fmt: "\nSummary:  no prediction info present\n");
    goto LABEL_52;
  }
  do
  {
    if ( (v11->m_bDerivedFromCBaseEntity || v11->m_bHasPredictionData)
      && CClass::CheckForMissingPredictionFields(this: v11, missingcount: &c, createtds: true) )
    {
      ++v12;
      v13 += c;
    }
    v11 = v11->m_pNext;
  }
  while ( v11 != nullptr );
  if ( v13 == 0 )
  {
    if ( v12 != 0 )
    {
      vprint(depth: 0, fmt: "\nSummary:  no errors for %i predictable classes\n", v12);
      goto LABEL_52;
    }
    goto LABEL_50;
  }
  vprint(depth: 0, fmt: "\nSummary:  %i prediction fields missing from %i classes\n", v13, v12);
LABEL_52:
  vprint(depth: 0, fmt: "\n");
  v1 = this;
LABEL_53:
  for ( i = v1->m_pClassList; i != nullptr; i = i->m_pNext )
  {
    if ( i->m_bDerivedFromCBaseEntity || i->m_bHasPredictionData )
      CClass::CheckForPredictionFieldsInRecvTableNotMarkedAsSuchCorrectly(this: i, missingcount: &c);
  }
  vprint(depth: 0, fmt: "\n");
  vprint(depth: 0, fmt: "\nMissing DATADESC tables:\n\n");
  for ( j = this->m_pClassList; j != nullptr; j = j->m_pNext )
  {
    if ( j->m_bDerivedFromCBaseEntity && !j->m_bHasSaveRestoreData && j->m_nVarCount != 0 )
      vprint(depth: 0, fmt: "\t%s\n", j->m_szName);
  }
  vprint(depth: 0, fmt: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x00406E70
// Name: public: void CCodeProcessor::ReportHungarianNotationErrors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::ReportHungarianNotationErrors(CCodeProcessor *this)
{
  CClass *m_pClassList; // esi
  int v3; // ebx
  int i; // edi
  int c; // [esp+4h] [ebp-4h] BYREF

  if ( this->GetCheckHungarian(this) )
  {
    vprint(depth: 0, fmt: "\tChecking for hungarian notation issues\n");
    m_pClassList = this->m_pClassList;
    v3 = 0;
    for ( i = 0; m_pClassList != nullptr; ++v3 )
    {
      c = 0;
      CClass::CheckForHungarianErrors(this: m_pClassList, warnings: &c);
      m_pClassList = m_pClassList->m_pNext;
      i += c;
    }
    vprint(depth: 0, fmt: "\tFound %i notation errors across %i classes\n", v3, i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406EE0
// Name: public: void CCodeProcessor::PrintClassList(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::PrintClassList(CCodeProcessor *this)
{
  bool (__thiscall *GetPrintHierarchy)(struct CCodeProcessor *); // edx
  CClass *m_pClassList; // esi
  char v4; // bl
  char *v5; // eax
  CClass *m_pBaseClass; // edi
  int j; // ebx
  CCodeProcessor *v8; // edi
  bool v9; // cc
  const char **m_Members; // ebx
  const char *v11; // edi
  const char *v12; // eax
  int v13; // edi
  CClassVariable **m_Variables; // ebx
  const char *v15; // eax
  int v16; // ebx
  const char *v17; // edi
  int v18; // ebx
  const char *v19; // edi
  char missingwarning[128]; // [esp+4h] [ebp-88h] BYREF
  CCodeProcessor *v21; // [esp+84h] [ebp-8h]
  int i; // [esp+88h] [ebp-4h]

  GetPrintHierarchy = this->GetPrintHierarchy;
  v21 = this;
  if ( ((unsigned __int8 (__fastcall *)(CCodeProcessor *))GetPrintHierarchy)(a1: this) != 0 )
    vprint(depth: 0, fmt: "\nClass Summary\n\n");
  m_pClassList = this->m_pClassList;
  if ( m_pClassList != nullptr )
  {
    while ( !m_pClassList->m_bDerivedFromCBaseEntity )
    {
LABEL_64:
      m_pClassList = m_pClassList->m_pNext;
      if ( m_pClassList == nullptr )
        return;
    }
    v4 = 0;
    missingwarning[0] = 0;
    if ( m_pClassList->m_szTypedefBaseClass[0] != 0 )
    {
      if ( _V_stricmp(s1: m_pClassList->m_szBaseClass, s2: m_pClassList->m_szTypedefBaseClass) != 0 )
        _Warning(
          a1: "class %s has incorrect typedef %s BaseClass\n",
          m_pClassList->m_szName,
          m_pClassList->m_szTypedefBaseClass);
    }
    else if ( m_pClassList->m_szBaseClass[0] != 0 )
    {
      v4 = 1;
      sprintf(string: missingwarning, format: ", missing typedef %s BaseClass", m_pClassList->m_szBaseClass);
    }
    if ( v21->GetPrintHierarchy(this: v21) )
    {
      if ( v4 != 0 )
        v5 = missingwarning;
      else
        v5 = (char *)definetype;
    }
    else
    {
      if ( v4 == 0 )
      {
LABEL_17:
        m_pBaseClass = m_pClassList->m_pBaseClass;
        for ( j = 1; m_pBaseClass != nullptr; m_pBaseClass = m_pBaseClass->m_pBaseClass )
        {
          if ( v21->GetPrintHierarchy(this: v21) )
            vprint(depth: j++, fmt: "public %s\n", m_pBaseClass->m_szName);
        }
        v8 = v21;
        if ( v21->GetPrintHierarchy(this: v21) && v8->GetPrintMembers(this: v8) )
        {
          if ( m_pClassList->m_nMemberCount != 0 )
            vprint(depth: 1, fmt: "\nMember functions:\n\n");
          v9 = m_pClassList->m_nMemberCount <= 0;
          i = 0;
          if ( !v9 )
          {
            m_Members = (const char **)m_pClassList->m_Members;
            do
            {
              v11 = *m_Members;
              if ( (*m_Members)[128] != 0 )
              {
                vprint(depth: 1, fmt: "%s %s();\n", *m_Members + 128, *m_Members);
              }
              else
              {
                v12 = *m_Members;
                if ( *v11 == 126 )
                  v12 = v11 + 1;
                if ( _V_stricmp(s1: v12, s2: m_pClassList->m_szName) != 0 )
                  _Warning(a1: "class %s has member function %s with no return type!!!\n", m_pClassList->m_szName, v11);
                vprint(depth: 1, fmt: "%s();\n", v11);
              }
              ++m_Members;
              ++i;
            }
            while ( i < m_pClassList->m_nMemberCount );
          }
          if ( m_pClassList->m_nVarCount != 0 )
            vprint(depth: 1, fmt: "\nMember Variables\n\n");
          v13 = 0;
          if ( m_pClassList->m_nVarCount > 0 )
          {
            m_Variables = m_pClassList->m_Variables;
            do
            {
              v15 = (const char *)*m_Variables;
              if ( (*m_Variables)->m_bIsArray )
              {
                if ( v15[269] != 0 )
                  vprint(depth: 1, fmt: "%s %s[ %s ];\n", v15 + 128, v15, v15 + 269);
                else
                  vprint(depth: 1, fmt: "%s %s[];\n", v15 + 128, *m_Variables);
              }
              else
              {
                vprint(depth: 1, fmt: "%s %s;\n", v15 + 128, *m_Variables);
              }
              ++v13;
              ++m_Variables;
            }
            while ( v13 < m_pClassList->m_nVarCount );
          }
          if ( m_pClassList->m_nTDCount != 0 )
            vprint(depth: 1, fmt: "\nSave/Restore TYPEDESCRIPTION\n\n");
          v16 = 0;
          if ( m_pClassList->m_nTDCount > 0 )
          {
            i = (int)m_pClassList->m_TDFields;
            do
            {
              v17 = *(const char **)i;
              if ( *(_BYTE *)(*(_DWORD *)i + 384) != 0 )
                vprint(depth: 1, fmt: "// ");
              else
                vprint(depth: 1, fmt: definetype);
              vprint(depth: 0, fmt: "%s( %s, %s, %s, ... )\n", v17 + 256, m_pClassList->m_szName, v17, v17 + 128);
              i += 4;
              ++v16;
            }
            while ( v16 < m_pClassList->m_nTDCount );
          }
          if ( m_pClassList->m_nPredTDCount != 0 )
            vprint(depth: 1, fmt: "\nPrediction TYPEDESCRIPTION\n\n");
          v18 = 0;
          if ( m_pClassList->m_nPredTDCount > 0 )
          {
            i = (int)m_pClassList->m_PredTDFields;
            do
            {
              v19 = *(const char **)i;
              if ( *(_BYTE *)(*(_DWORD *)i + 384) != 0 )
                vprint(depth: 1, fmt: "// ");
              else
                vprint(depth: 1, fmt: definetype);
              vprint(depth: 0, fmt: "%s( %s, %s, %s, ... )\n", v19 + 256, m_pClassList->m_szName, v19, v19 + 128);
              i += 4;
              ++v18;
            }
            while ( v18 < m_pClassList->m_nPredTDCount );
          }
          v8 = v21;
        }
        if ( v8->GetPrintHierarchy(this: v8) )
          vprint(depth: 0, fmt: "\n");
        goto LABEL_64;
      }
      v5 = missingwarning;
    }
    vprint(depth: 0, fmt: "class %s%s\n", m_pClassList->m_szName, v5);
    goto LABEL_17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407290
// Name: public: virtual class CClass __near * CCodeProcessor::AddClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CClass *__thiscall CCodeProcessor::AddClass(CCodeProcessor *this, const char *classname)
{
  CClass *result; // eax
  CClass *v4; // eax
  CClass *m_pClassList; // ecx

  result = this->FindClass(this, a2: classname);
  if ( result == nullptr )
  {
    v4 = (CClass *)operator new(nSize: 0x41A4u);
    if ( v4 != nullptr )
      result = CClass::CClass(this: v4, name: classname);
    else
      result = nullptr;
    m_pClassList = this->m_pClassList;
    ++this->m_nClassesParsed;
    result->m_pNext = m_pClassList;
    this->m_pClassList = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004072E0
// Name: private: char __near * CCodeProcessor::ParseTypeDescription(char __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCodeProcessor::ParseTypeDescription(
        CCodeProcessor *this,
        char *current,
        bool fIsMacroized,
        const char *pModule)
{
  CCodeProcessor *v4; // ebx
  char *result; // eax
  int v6; // ecx
  char v7; // dl
  char *v8; // esi
  char *v9; // eax
  int v10; // ecx
  char v11; // dl
  int v12; // eax
  int v13; // ecx
  char v14; // dl
  char *v15; // edi
  int v16; // eax
  char v17; // cl
  CClass *v18; // esi
  int v19; // eax
  char v20; // cl
  char *v21; // esi
  int v22; // eax
  char v23; // cl
  char *v24; // esi
  char *v25; // eax
  char *v26; // edi
  char v27; // cl
  unsigned int v28; // edx
  char *v29; // edi
  char v30; // cl
  char *i; // ebx
  unsigned int v32; // eax
  char *v33; // edi
  char v34; // cl
  char *v35; // edi
  char v36; // al
  int v37; // eax
  char v38; // cl
  int v39; // ebx
  CClass *v40; // edi
  CTypeDescriptionField *TD; // eax
  CTypeDescriptionField *v42; // esi
  bool v43; // bl
  char commentedvarname[256]; // [esp+8h] [ebp-610h] BYREF
  char variablename[256]; // [esp+108h] [ebp-510h] BYREF
  char vartype[256]; // [esp+208h] [ebp-410h] BYREF
  char classname[256]; // [esp+308h] [ebp-310h] BYREF
  char varname[256]; // [esp+408h] [ebp-210h] BYREF
  char definetype[256]; // [esp+508h] [ebp-110h] BYREF
  CCodeProcessor *v50; // [esp+608h] [ebp-10h]
  char breakchar; // [esp+60Fh] [ebp-9h] BYREF
  BOOL insidecomment; // [esp+610h] [ebp-8h]
  char *currenta; // [esp+620h] [ebp+8h]

  v4 = this;
  v50 = this;
  if ( fIsMacroized )
  {
    v8 = CC_ParseToken(data: current);
    if ( _V_stricmp(s1: com_token, s2: "(") != 0 )
      return v8;
    result = CC_ParseToken(data: v8);
    if ( strlen(com_token) != 0 )
    {
      v13 = 0;
      do
      {
        v14 = com_token[v13];
        classname[v13++] = v14;
      }
      while ( v14 != 0 );
      if ( classname[0] != 42 )
      {
        v8 = CC_ParseToken(data: result);
        if ( _V_stricmp(s1: com_token, s2: ")") != 0 )
          return v8;
        strcpy(variablename, "m_DataDesc");
        goto LABEL_12;
      }
    }
  }
  else
  {
    result = CC_ParseToken(data: current);
    if ( strlen(com_token) != 0 )
    {
      v6 = 0;
      do
      {
        v7 = com_token[v6];
        classname[v6++] = v7;
      }
      while ( v7 != 0 );
      if ( classname[0] != 42 )
      {
        v8 = CC_ParseToken(data: result);
        if ( _V_stricmp(s1: com_token, s2: ":") != 0 )
          return v8;
        v9 = CC_ParseToken(data: v8);
        result = CC_ParseToken(data: v9);
        if ( strlen(com_token) != 0 )
        {
          v10 = 0;
          do
          {
            v11 = com_token[v10];
            variablename[v10++] = v11;
          }
          while ( v11 != 0 );
          v8 = CC_RawParseChar(input: result, ch: "{", &breakchar);
          if ( strlen(com_token) == 0 )
            return v8;
LABEL_12:
          com_ignoreinlinecomment = true;
          LOBYTE(insidecomment) = 0;
          currenta = CC_ParseToken(data: v8);
          while ( strlen(com_token) != 0 )
          {
            if ( _V_stricmp(s1: com_token, s2: ",") != 0 )
            {
              if ( fIsMacroized )
              {
                if ( _V_stricmp(s1: com_token, s2: "END_DATADESC") == 0 )
                  break;
                v12 = _V_stricmp(s1: com_token, s2: "END_BYTESWAP_DATADESC");
              }
              else
              {
                v12 = _V_stricmp(s1: com_token, s2: "}");
              }
              if ( v12 == 0 )
                break;
              if ( com_token[0] == 35 )
              {
                currenta = CC_ParseUntilEndOfLine(input: currenta);
              }
              else if ( _V_stricmp(s1: com_token, s2: "/") != 0
                     || (currenta = CC_ParseToken(data: currenta), _V_stricmp(s1: com_token, s2: "/") != 0) )
              {
                com_ignoreinlinecomment = false;
                v19 = 0;
                do
                {
                  v20 = com_token[v19];
                  definetype[v19++] = v20;
                }
                while ( v20 != 0 );
                currenta = CC_ParseToken(data: currenta);
                if ( _V_stricmp(s1: com_token, s2: "(") != 0 )
                  break;
                v21 = CC_ParseToken(data: currenta);
                v22 = 0;
                do
                {
                  v23 = com_token[v22];
                  varname[v22++] = v23;
                }
                while ( v23 != 0 );
                vartype[0] = 0;
                if ( _V_stricmp(s1: definetype, s2: "DEFINE_FUNCTION") != 0
                  && _V_stricmp(s1: definetype, s2: "DEFINE_THINKFUNC") != 0
                  && _V_stricmp(s1: definetype, s2: "DEFINE_ENTITYFUNC") != 0
                  && _V_stricmp(s1: definetype, s2: "DEFINE_USEFUNC") != 0
                  && _V_stricmp(s1: definetype, s2: "DEFINE_OUTPUT") != 0
                  && _V_stricmp(s1: definetype, s2: "DEFINE_INPUTFUNC") != 0 )
                {
                  if ( _V_stricmp(s1: definetype, s2: "DEFINE_FIELD") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_INDEX") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_KEYFIELD") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_KEYFIELD_NOT_SAVED") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_UTLVECTOR") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_GLOBAL_FIELD") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_GLOBAL_KEYFIELD") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_CUSTOM_FIELD") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_INPUT") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_AUTO_ARRAY") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_AUTO_ARRAY_KEYFIELD") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_AUTO_ARRAY2D") == 0
                    || _V_stricmp(s1: definetype, s2: "DEFINE_ARRAY") == 0 )
                  {
                    v24 = CC_ParseToken(data: v21);
                    if ( strcmp(com_token, "[") == 0 )
                    {
                      v25 = CC_ParseToken(data: v24);
                      v26 = &classname[255];
                      do
                        v27 = *++v26;
                      while ( v27 != 0 );
                      strcpy(v26, "[");
                      v28 = strlen(com_token) + 1;
                      v29 = &classname[255];
                      do
                        v30 = *++v29;
                      while ( v30 != 0 );
                      qmemcpy(v29, com_token, v28);
                      for ( i = CC_ParseToken(data: v25); strcmp(com_token, "]") != 0; i = CC_ParseToken(data: i) )
                      {
                        v32 = strlen(com_token) + 1;
                        v33 = &classname[255];
                        do
                          v34 = *++v33;
                        while ( v34 != 0 );
                        qmemcpy(v33, com_token, v32);
                      }
                      v35 = &classname[255];
                      do
                        v36 = *++v35;
                      while ( v36 != 0 );
                      strcpy(v35, "]");
                      v24 = CC_ParseToken(data: i);
                    }
                    v21 = CC_ParseToken(data: v24);
                    v37 = 0;
                    do
                    {
                      v38 = com_token[v37];
                      vartype[v37++] = v38;
                    }
                    while ( v38 != 0 );
                  }
                }
                else
                {
                  strcpy(vartype, "funcptr");
                }
                v39 = 1;
                for ( currenta = CC_ParseToken(data: v21); strlen(com_token) != 0; currenta = CC_ParseToken(data: currenta) )
                {
                  if ( _V_stricmp(s1: com_token, s2: "(") != 0 )
                  {
                    if ( _V_stricmp(s1: com_token, s2: ")") == 0 && --v39 == 0 )
                      break;
                  }
                  else
                  {
                    ++v39;
                  }
                }
                v40 = v50->FindClass(this: v50, a2: classname);
                if ( v40 != nullptr )
                {
                  if ( strcmp(vartype, aFunc) != 0
                    && (TD = CClass::FindTD(this: v40, name: varname), v42 = TD, TD != nullptr)
                    && _V_stricmp(s1: TD->m_szType, s2: "FIELD_CLASSCHECK_IGNORE") != 0
                    && (v43 = _V_stricmp(s1: definetype, s2: "DEFINE_INPUT") == 0) == (_V_stricmp(
                                                                                         s1: v42->m_szDefineType,
                                                                                         s2: "DEFINE_INPUT") == 0) )
                  {
                    _Warning(
                      a1: "Warning [%s]: class %s::%s already has typedescription entry for field %s\n",
                      pModule,
                      classname,
                      variablename,
                      varname);
                  }
                  else
                  {
                    CClass::AddTD(this: v40, name: varname, type: vartype, definetype, incomments: insidecomment);
                  }
                  v40->m_bHasSaveRestoreData = true;
                }
                v4 = v50;
                LOBYTE(insidecomment) = 0;
                com_ignoreinlinecomment = true;
              }
              else
              {
                v15 = CC_ParseToken(data: currenta);
                currenta = v15;
                if ( V_strncasecmp(s1: com_token, s2: "DEFINE_", n: 7) != 0 )
                {
                  v16 = 0;
                  do
                  {
                    v17 = com_token[v16];
                    commentedvarname[v16++] = v17;
                  }
                  while ( v17 != 0 );
                  v18 = v4->FindClass(this: v4, a2: classname);
                  if ( v18 != nullptr )
                  {
                    if ( CClass::FindTD(this: v18, name: commentedvarname) == nullptr )
                      CClass::AddTD(
                        this: v18,
                        name: commentedvarname,
                        type: ::definetype,
                        definetype: ::definetype,
                        incomments: true);
                    v18->m_bHasSaveRestoreData = true;
                  }
                  currenta = CC_ParseUntilEndOfLine(input: v15);
                }
                else
                {
                  CC_UngetToken();
                  LOBYTE(insidecomment) = 1;
                }
              }
            }
            currenta = CC_ParseToken(data: currenta);
          }
          com_ignoreinlinecomment = false;
          return currenta;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407C40
// Name: private: char __near * CCodeProcessor::ParseReceiveTable(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCodeProcessor::ParseReceiveTable(CCodeProcessor *this, char *current)
{
  char *i; // esi
  int v4; // eax
  char v5; // cl
  CClass *v6; // eax
  CClass *v7; // edi
  char *v8; // eax
  int v9; // eax
  char v10; // cl
  char *v11; // eax
  int v12; // ecx
  char v13; // dl
  CClassVariable *Var; // eax
  int v15; // eax
  char v16; // cl
  int v17; // eax
  int v18; // ecx
  char v19; // dl
  int v20; // ecx
  char *v21; // eax
  char *v22; // edx
  char v23; // cl
  char root[256]; // [esp+8h] [ebp-504h] BYREF
  char recvproptype[256]; // [esp+108h] [ebp-404h] BYREF
  char varname[256]; // [esp+208h] [ebp-304h] BYREF
  char cropped[256]; // [esp+308h] [ebp-204h] BYREF
  char classname[256]; // [esp+408h] [ebp-104h] BYREF
  CClass *leafClass; // [esp+508h] [ebp-4h]

  i = CC_ParseToken(data: current);
  if ( _V_stricmp(s1: com_token, s2: "(") == 0 )
  {
    i = CC_ParseToken(data: i);
    if ( strlen(com_token) != 0 )
    {
      v4 = 0;
      do
      {
        v5 = com_token[v4];
        classname[v4++] = v5;
      }
      while ( v5 != 0 );
      if ( classname[0] != 42 && strcmp(classname, "className") != 0 && strcmp(classname, "clientClassName") != 0 )
      {
        v6 = this->FindClass(this, a2: classname);
        v7 = v6;
        if ( v6 != nullptr )
          v6->m_bHasRecvTableData = true;
        leafClass = v6;
        v8 = CC_ParseUntilEndOfLine(input: i);
        for ( i = CC_ParseToken(data: v8); strlen(com_token) != 0; i = CC_ParseToken(data: i) )
        {
          if ( _V_stricmp(s1: com_token, s2: ",") != 0 )
          {
            if ( _V_stricmp(s1: com_token, s2: "END_RECV_TABLE") == 0 )
              return i;
            if ( com_token[0] == 35 )
              goto LABEL_40;
            v9 = 0;
            do
            {
              v10 = com_token[v9];
              recvproptype[v9++] = v10;
            }
            while ( v10 != 0 );
            if ( V_strncasecmp(s1: recvproptype, s2: "RecvProp", n: 8) != 0 )
              goto LABEL_40;
            if ( strcmp(recvproptype, "RecvPropArray") == 0 )
            {
              i = CC_ParseToken(data: i);
              if ( _V_stricmp(s1: com_token, s2: "(") != 0 )
                return i;
              i = CC_ParseToken(data: i);
              if ( V_strncasecmp(s1: recvproptype, s2: "RecvProp", n: 8) != 0 )
                goto LABEL_40;
            }
            i = CC_ParseToken(data: i);
            if ( _V_stricmp(s1: com_token, s2: "(") != 0 )
              return i;
            i = CC_ParseToken(data: i);
            if ( V_strncasecmp(s1: com_token, s2: "RECVINFO", n: 8) != 0 )
            {
LABEL_40:
              i = CC_ParseUntilEndOfLine(input: i);
              goto LABEL_41;
            }
            i = CC_ParseToken(data: i);
            if ( _V_stricmp(s1: com_token, s2: "(") != 0 )
              return i;
            v11 = CC_ParseToken(data: i);
            v12 = 0;
            do
            {
              v13 = com_token[v12];
              varname[v12++] = v13;
            }
            while ( v13 != 0 );
            i = CC_ParseUntilEndOfLine(input: v11);
            if ( v7 == nullptr )
            {
              vprint(
                depth: 0,
                fmt: "class %s::%s found in RecvTable, but no such class is known!!!\n",
                classname,
                varname);
              goto LABEL_41;
            }
            Var = CClass::FindVar(this: v7, name: varname, checkbaseclasses: true);
            if ( Var == nullptr )
            {
              v15 = 0;
              do
              {
                v16 = varname[v15];
                cropped[v15++] = v16;
              }
              while ( v16 != 0 );
              strstr(str1: (unsigned __int8 *)cropped, str2: ".");
              if ( v17 != 0 )
              {
                while ( 1 )
                {
                  v18 = 0;
                  do
                  {
                    v19 = cropped[v18];
                    root[v18++] = v19;
                  }
                  while ( v19 != 0 );
                  v20 = v17 - (_DWORD)cropped;
                  v21 = (char *)(v17 + 1);
                  root[v20] = 0;
                  v22 = (char *)(cropped - v21);
                  do
                  {
                    v23 = *v21;
                    v21[(_DWORD)v22] = *v21;
                    ++v21;
                  }
                  while ( v23 != 0 );
                  Var = CClass::FindVar(this: v7, name: root, checkbaseclasses: true);
                  if ( Var != nullptr )
                    break;
                  strstr(str1: (unsigned __int8 *)cropped, str2: ".");
                  if ( v17 == 0 )
                    goto LABEL_37;
                }
              }
              else
              {
LABEL_37:
                Var = CClass::FindVar(this: v7, name: cropped, checkbaseclasses: true);
                if ( Var == nullptr )
                {
                  vprint(depth: 0, fmt: "class %s::%s missing, but referenced by RecvTable!!!\n", classname, varname);
                  goto LABEL_41;
                }
              }
            }
            Var->m_bInRecvTable = true;
          }
LABEL_41:
          v7 = leafClass;
        }
      }
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x00408080
// Name: private: char __near * CCodeProcessor::ParsePredictionTypeDescription(char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCodeProcessor::ParsePredictionTypeDescription(
        CCodeProcessor *this,
        char *current,
        const char *pModule)
{
  char *i; // esi
  int v5; // eax
  char v6; // cl
  CClass *v7; // eax
  int v8; // eax
  char v9; // cl
  char *v10; // esi
  int v11; // eax
  char v12; // cl
  char *v13; // eax
  int v14; // eax
  char v15; // cl
  int v16; // edi
  CClass *v17; // edi
  char definetype[256]; // [esp+8h] [ebp-50Ch] BYREF
  char variablename[256]; // [esp+108h] [ebp-40Ch] BYREF
  char varname[256]; // [esp+208h] [ebp-30Ch] BYREF
  char classname[256]; // [esp+308h] [ebp-20Ch] BYREF
  char vartype[256]; // [esp+408h] [ebp-10Ch] BYREF
  CClass *v24; // [esp+508h] [ebp-Ch]
  BOOL inrecvtable; // [esp+50Ch] [ebp-8h]
  BOOL insidecomment; // [esp+510h] [ebp-4h]

  i = CC_ParseToken(data: current);
  if ( _V_stricmp(s1: com_token, s2: "(") == 0 )
  {
    i = CC_ParseToken(data: i);
    if ( strlen(com_token) != 0 )
    {
      v5 = 0;
      do
      {
        v6 = com_token[v5];
        classname[v5++] = v6;
      }
      while ( v6 != 0 );
      if ( classname[0] != 42 )
      {
        v7 = this->FindClass(this, a2: classname);
        v24 = v7;
        if ( v7 != nullptr )
          v7->m_bHasPredictionData = true;
        i = CC_ParseToken(data: i);
        if ( _V_stricmp(s1: com_token, s2: ")") == 0 )
        {
          strcpy(variablename, "m_PredDesc");
          com_ignoreinlinecomment = true;
          LOBYTE(insidecomment) = 0;
          for ( i = CC_ParseToken(data: i); strlen(com_token) != 0; i = CC_ParseToken(data: i) )
          {
            if ( _V_stricmp(s1: com_token, s2: ",") != 0 )
            {
              if ( _V_stricmp(s1: com_token, s2: "END_PREDICTION_DATA") == 0 )
                break;
              if ( com_token[0] == 35 )
                goto LABEL_13;
              if ( _V_stricmp(s1: com_token, s2: "/") == 0 )
              {
                i = CC_ParseToken(data: i);
                if ( _V_stricmp(s1: com_token, s2: "/") == 0 )
                {
                  i = CC_ParseToken(data: i);
                  if ( V_strncasecmp(s1: com_token, s2: "DEFINE_", n: 7) == 0 )
                  {
                    CC_UngetToken();
                    LOBYTE(insidecomment) = 1;
                    continue;
                  }
LABEL_13:
                  i = CC_ParseUntilEndOfLine(input: i);
                  continue;
                }
              }
              com_ignoreinlinecomment = false;
              v8 = 0;
              do
              {
                v9 = com_token[v8];
                definetype[v8++] = v9;
              }
              while ( v9 != 0 );
              i = CC_ParseToken(data: i);
              if ( _V_stricmp(s1: com_token, s2: "(") != 0 )
                break;
              v10 = CC_ParseToken(data: i);
              v11 = 0;
              do
              {
                v12 = com_token[v11];
                varname[v11++] = v12;
              }
              while ( v12 != 0 );
              vartype[0] = 0;
              if ( _V_stricmp(s1: definetype, s2: "DEFINE_FUNCTION") != 0 )
              {
                v13 = CC_ParseToken(data: v10);
                v10 = CC_ParseToken(data: v13);
                v14 = 0;
                do
                {
                  v15 = com_token[v14];
                  vartype[v14++] = v15;
                }
                while ( v15 != 0 );
              }
              else
              {
                strcpy(vartype, "funcptr");
              }
              LOBYTE(inrecvtable) = 0;
              v16 = 1;
              for ( i = CC_ParseToken(data: v10); strlen(com_token) != 0; i = CC_ParseToken(data: i) )
              {
                if ( _V_stricmp(s1: com_token, s2: "(") != 0 )
                {
                  if ( _V_stricmp(s1: com_token, s2: ")") == 0 && --v16 == 0 )
                    break;
                }
                else
                {
                  ++v16;
                }
                if ( _V_stricmp(s1: com_token, s2: "FTYPEDESC_INSENDTABLE") == 0 )
                  LOBYTE(inrecvtable) = 1;
              }
              v17 = v24;
              if ( v24 != nullptr )
              {
                if ( CClass::FindPredTD(this: v24, name: varname) != nullptr )
                  _Warning(
                    a1: "Warning [%s]: class %s::%s already has prediction typedescription entry for field %s\n",
                    pModule,
                    classname,
                    variablename,
                    varname);
                else
                  CClass::AddPredTD(
                    this: v17,
                    name: varname,
                    type: vartype,
                    definetype,
                    incomments: insidecomment,
                    inrecvtable);
              }
              LOBYTE(insidecomment) = 0;
              com_ignoreinlinecomment = true;
            }
          }
          com_ignoreinlinecomment = false;
        }
      }
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x00408450
// Name: SkipFile
// Source: json
//------------------------------------------------------------------------------
bool __usercall SkipFile@<al>(const char *module@<esi>)
{
  return _V_stricmp(s1: module, s2: "predictable_entity.h") == 0
      || _V_stricmp(s1: module, s2: "baseentity_shared.h") == 0
      || _V_stricmp(s1: module, s2: "baseplayer_shared.h") == 0
      || _V_stricmp(s1: module, s2: "tf_tacticalmap.cpp") == 0
      || _V_stricmp(s1: module, s2: "techtree.cpp") == 0
      || _V_stricmp(s1: module, s2: "techtree_parse.cpp") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004084D0
// Name: public: virtual void CCodeProcessor::SetQuiet(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SetQuiet(CCodeProcessor *this, bool quiet)
{
  this->m_bQuiet = quiet;
}

//------------------------------------------------------------------------------
// Address: 0x004084E0
// Name: public: virtual bool CCodeProcessor::GetQuiet(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCodeProcessor::GetQuiet(CCodeProcessor *this)
{
  return this->m_bQuiet;
}

//------------------------------------------------------------------------------
// Address: 0x004084F0
// Name: public: virtual void CCodeProcessor::SetPrintHierarchy(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SetPrintHierarchy(CCodeProcessor *this, bool print)
{
  this->m_bPrintHierarchy = print;
}

//------------------------------------------------------------------------------
// Address: 0x00408500
// Name: public: virtual bool CCodeProcessor::GetPrintHierarchy(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCodeProcessor::GetPrintHierarchy(CCodeProcessor *this)
{
  return this->m_bPrintHierarchy;
}

//------------------------------------------------------------------------------
// Address: 0x00408510
// Name: public: virtual void CCodeProcessor::SetPrintMembers(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SetPrintMembers(CCodeProcessor *this, bool print)
{
  this->m_bPrintMembers = print;
}

//------------------------------------------------------------------------------
// Address: 0x00408520
// Name: public: virtual bool CCodeProcessor::GetPrintMembers(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCodeProcessor::GetPrintMembers(CCodeProcessor *this)
{
  return this->m_bPrintMembers;
}

//------------------------------------------------------------------------------
// Address: 0x00408530
// Name: public: virtual void CCodeProcessor::SetPrintTDs(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SetPrintTDs(CCodeProcessor *this, bool print)
{
  this->m_bPrintTypedescriptionErrors = print;
}

//------------------------------------------------------------------------------
// Address: 0x00408540
// Name: public: virtual bool CCodeProcessor::GetPrintTDs(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCodeProcessor::GetPrintTDs(CCodeProcessor *this)
{
  return this->m_bPrintTypedescriptionErrors;
}

//------------------------------------------------------------------------------
// Address: 0x00408550
// Name: public: virtual void CCodeProcessor::SetLogFile(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SetLogFile(CCodeProcessor *this, bool log)
{
  this->m_bLogToFile = log;
}

//------------------------------------------------------------------------------
// Address: 0x00408560
// Name: public: virtual bool CCodeProcessor::GetLogFile(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCodeProcessor::GetLogFile(CCodeProcessor *this)
{
  return this->m_bLogToFile;
}

//------------------------------------------------------------------------------
// Address: 0x00408570
// Name: public: virtual void CCodeProcessor::SetPrintPredTDs(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SetPrintPredTDs(CCodeProcessor *this, bool print)
{
  this->m_bPrintPredictionDescErrors = print;
}

//------------------------------------------------------------------------------
// Address: 0x00408580
// Name: public: virtual bool CCodeProcessor::GetPrintPredTDs(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCodeProcessor::GetPrintPredTDs(CCodeProcessor *this)
{
  return this->m_bPrintPredictionDescErrors;
}

//------------------------------------------------------------------------------
// Address: 0x00408590
// Name: public: virtual void CCodeProcessor::SetPrintCreateMissingTDs(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SetPrintCreateMissingTDs(CCodeProcessor *this, bool print)
{
  this->m_bCreateMissingTDs = print;
}

//------------------------------------------------------------------------------
// Address: 0x004085A0
// Name: public: virtual bool CCodeProcessor::GetPrintCreateMissingTDs(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCodeProcessor::GetPrintCreateMissingTDs(CCodeProcessor *this)
{
  return this->m_bCreateMissingTDs;
}

//------------------------------------------------------------------------------
// Address: 0x004085B0
// Name: public: virtual void CCodeProcessor::SetPrintCreateMissingPredTDs(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SetPrintCreateMissingPredTDs(CCodeProcessor *this, bool print)
{
  this->m_bCreateMissingPredTDs = print;
}

//------------------------------------------------------------------------------
// Address: 0x004085C0
// Name: public: virtual bool CCodeProcessor::GetPrintCreateMissingPredTDs(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCodeProcessor::GetPrintCreateMissingPredTDs(CCodeProcessor *this)
{
  return this->m_bCreateMissingPredTDs;
}

//------------------------------------------------------------------------------
// Address: 0x004085D0
// Name: public: virtual void CCodeProcessor::SetCheckHungarian(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SetCheckHungarian(CCodeProcessor *this, bool check)
{
  this->m_bCheckHungarian = check;
}

//------------------------------------------------------------------------------
// Address: 0x004085E0
// Name: public: virtual bool CCodeProcessor::GetCheckHungarian(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCodeProcessor::GetCheckHungarian(CCodeProcessor *this)
{
  return this->m_bCheckHungarian;
}

//------------------------------------------------------------------------------
// Address: 0x004085F0
// Name: private: void CCodeProcessor::PrintResults(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::PrintResults(CCodeProcessor *this, const char *baseentityclass)
{
  double v3; // xmm1_8
  CClass *m_pClassList; // esi
  CClass *m_pNext; // ebx

  vprint(depth: 0, fmt: "\nChecking for errors and totaling...\n\n");
  CCodeProcessor::ResolveBaseClasses(this, baseentityclass);
  CCodeProcessor::PrintClassList(this);
  CCodeProcessor::PrintMissingTDFields(this);
  ReportMissingTypes();
  CCodeProcessor::ReportHungarianNotationErrors(this);
  vprint(
    depth: 0,
    fmt: "%i total classes parsed from %i files ( %i headers parsed )\n",
    this->m_nClassesParsed,
    this->m_nFilesProcessed,
    this->m_nHeadersProcessed);
  vprint(depth: 0, fmt: "%.3f K lines of code processed\n", (double)this->m_nLinesOfCode * 0.0009765625);
  v3 = this->m_flEnd - this->m_flStart;
  if ( v3 > 0.0 )
    vprint(
      depth: 0,
      fmt: "%.2f K processed in %.3f seconds, throughput %.2f KB/sec\n\n",
      (double)this->m_nBytesProcessed * 0.0009765625,
      v3,
      (double)this->m_nBytesProcessed / (v3 * 1024.0));
  ClearMissingTypes();
  m_pClassList = this->m_pClassList;
  if ( m_pClassList != nullptr )
  {
    do
    {
      m_pNext = m_pClassList->m_pNext;
      CClass::~CClass(this: m_pClassList);
      free(pMem: m_pClassList);
      m_pClassList = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  this->m_pClassList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00408710
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004087B0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( i == -1 )
    return dword_4277F8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00408810
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( i == -1 )
    return dword_4277F4;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00408870
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( m_Parent == -1 )
    return dword_4277F4 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00408920
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4277F4 = -1;
        dword_4277F8 = -1;
        dword_4277FC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4277F4 = -1;
        dword_4277F8 = -1;
        dword_4277FC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408A10
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v11; // edx

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
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>::Grow(
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
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408AD0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00408B80
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4277F4 = -1;
      dword_4277F8 = -1;
      dword_4277FC = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00408D30
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00408EA0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t *search)
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
      if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4277F4 = -1;
        dword_4277F8 = -1;
        dword_4277FC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4277F4 = -1;
        dword_4277F8 = -1;
        dword_4277FC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00408F90
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this)
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
          if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4277F4 = -1;
            dword_4277F8 = -1;
            dword_4277FC = 1;
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
// Address: 0x00409050
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4277F4 = -1;
      dword_4277F8 = -1;
      dword_4277FC = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_4277F4 = -1;
      dword_4277F8 = -1;
      dword_4277FC = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004090F0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_4277F4 = -1;
    dword_4277F8 = -1;
    dword_4277FC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4277F4 = -1;
          dword_4277F8 = -1;
          dword_4277FC = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4277F4 = -1;
        dword_4277F8 = -1;
        dword_4277FC = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4277F4 = -1;
        dword_4277F8 = -1;
        dword_4277FC = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409260
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4277F4 = -1;
        dword_4277F8 = -1;
        dword_4277FC = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4277F4 = -1;
        dword_4277F8 = -1;
        dword_4277FC = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4277F4 = -1;
        dword_4277F8 = -1;
        dword_4277FC = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_4277F4 = -1;
        dword_4277F8 = -1;
        dword_4277FC = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4277F4 = -1;
          dword_4277F8 = -1;
          dword_4277FC = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4277F4 = -1;
          dword_4277F8 = -1;
          dword_4277FC = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4277F4 = -1;
            dword_4277F8 = -1;
            dword_4277FC = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4277F4 = -1;
            dword_4277F8 = -1;
            dword_4277FC = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4277F4 = -1;
          dword_4277F8 = -1;
          dword_4277FC = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_4277F4 = -1;
          dword_4277F8 = -1;
          dword_4277FC = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
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
        if ( CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4277F4 = -1;
            dword_4277F8 = -1;
            dword_4277FC = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_4277F4 = -1;
            dword_4277F8 = -1;
            dword_4277FC = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RotateLeft(
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
// Address: 0x004096C0
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RemoveAll(this);
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
// Address: 0x00409720
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int,class CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409790
// Name: private: void CCodeProcessor::AddIncludePath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::AddIncludePath(CCodeProcessor *this, char *pPath)
{
  int m_nAllocationCount; // eax
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *p_m_IncludePath; // esi
  int m_Size; // edi
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // ecx
  int v6; // eax
  unsigned int v7; // kr00_4

  m_nAllocationCount = this->m_IncludePath.m_Memory.m_nAllocationCount;
  p_m_IncludePath = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&this->m_IncludePath;
  m_Size = this->m_IncludePath.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<char *,int>::Grow(this: p_m_IncludePath, num: m_Size - m_nAllocationCount + 1);
  ++p_m_IncludePath[1].m_pMemory;
  m_pMemory = p_m_IncludePath->m_pMemory;
  v6 = (int)p_m_IncludePath[1].m_pMemory - m_Size - 1;
  p_m_IncludePath[1].m_nAllocationCount = (int)p_m_IncludePath->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = strlen(pPath);
  p_m_IncludePath->m_pMemory[m_Size] = (void (__cdecl *)(IConVar *, const char *, float))operator new(nSize: v7 + 1);
  memcpy(dst: (unsigned __int8 *)p_m_IncludePath->m_pMemory[m_Size], src: (unsigned __int8 *)pPath, count: v7 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x00409820
// Name: private: void CCodeProcessor::SetupIncludePath(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::SetupIncludePath(
        CCodeProcessor *this,
        const char *sourcetreebase,
        const char *subdir,
        const char *gamespecific)
{
  int i; // edi
  const char *v6; // ebx
  const char *v7; // [esp-Ch] [ebp-19Ch]
  const char *v8; // [esp-8h] [ebp-198h]
  char modsubdir[128]; // [esp+Ch] [ebp-184h] BYREF
  char path[260]; // [esp+8Ch] [ebp-104h] BYREF

  for ( i = this->m_IncludePath.m_Size - 1; i >= 0; --i )
    free(pMem: this->m_IncludePath.m_Memory.m_pMemory[i]);
  this->m_IncludePath.m_Size = 0;
  sprintf(string: path, format: "%s\\%s", sourcetreebase, subdir);
  strlwr(string: path);
  CCodeProcessor::AddIncludePath(this, pPath: path);
  if ( _V_stricmp(s1: subdir, s2: "dlls") != 0 )
  {
    v6 = gamespecific;
    if ( _V_stricmp(s1: subdir, s2: "cl_dll") != 0 )
    {
      v8 = subdir;
      v7 = "%s\\%s";
    }
    else
    {
      v8 = subdir;
      v7 = "%s\\%s_hud";
    }
    sprintf(string: modsubdir, format: v7, v8, gamespecific);
  }
  else
  {
    v6 = gamespecific;
    sprintf(string: modsubdir, format: "%s\\%s_dll", subdir, gamespecific);
  }
  sprintf(string: path, format: "%s\\%s", sourcetreebase, modsubdir);
  strlwr(string: path);
  CCodeProcessor::AddIncludePath(this, pPath: path);
  sprintf(string: path, format: "%s\\game\\server", sourcetreebase);
  strlwr(string: path);
  CCodeProcessor::AddIncludePath(this, pPath: path);
  sprintf(string: path, format: "%s\\game\\server\\%s", sourcetreebase, v6);
  strlwr(string: path);
  CCodeProcessor::AddIncludePath(this, pPath: path);
  sprintf(string: path, format: "%s\\game\\client", sourcetreebase);
  strlwr(string: path);
  CCodeProcessor::AddIncludePath(this, pPath: path);
  sprintf(string: path, format: "%s\\game\\client\\%s", sourcetreebase, v6);
  strlwr(string: path);
  CCodeProcessor::AddIncludePath(this, pPath: path);
  sprintf(string: path, format: "%s\\game\\client\\%s\\vgui", sourcetreebase, v6);
  strlwr(string: path);
  CCodeProcessor::AddIncludePath(this, pPath: path);
  sprintf(string: path, format: "%s\\game\\shared", sourcetreebase);
  strlwr(string: path);
  CCodeProcessor::AddIncludePath(this, pPath: path);
  sprintf(string: path, format: "%s\\game\\shared\\%s", sourcetreebase, v6);
  strlwr(string: path);
  CCodeProcessor::AddIncludePath(this, pPath: path);
  sprintf(string: path, format: "%s\\public", sourcetreebase);
  strlwr(string: path);
  CCodeProcessor::AddIncludePath(this, pPath: path);
}

//------------------------------------------------------------------------------
// Address: 0x00409AB0
// Name: public: void CUtlDict<struct CCodeProcessor::CODE_MODULE,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CCodeProcessor::CODE_MODULE,int>::RemoveAll(CUtlDict<CCodeProcessor::CODE_MODULE,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00409B00
// Name: char const __near * GetQuotedString(char const __near *,char const __near *,class CUtlVector<char,class CUtlMemory<char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetQuotedString(
        const char *pSearchBase,
        const char *pPrefix,
        CUtlVector<char,CUtlMemory<char,int> > *out)
{
  const char *v3; // esi
  int v5; // eax
  unsigned __int8 *v6; // edi
  const char *v7; // ebx
  signed int v8; // esi

  v3 = V_stristr(pStr: pSearchBase, pSearch: pPrefix);
  if ( v3 == nullptr )
    return nullptr;
  v5 = _V_strlen(str: pPrefix);
  v6 = (unsigned __int8 *)&v3[v5 + 1];
  if ( v3[v5] != 34 )
    return nullptr;
  v7 = V_stristr(pStr: &v3[v5 + 1], pSearch: "\"");
  v8 = v7 - (const char *)v6;
  if ( v7 == nullptr || v8 < 1 )
    return nullptr;
  CUtlVector<char,CUtlMemory<char,int>>::SetSize(this: out, size: v8 + 1);
  memcpy(dst: (unsigned __int8 *)out->m_Memory.m_pMemory, src: v6, count: v8);
  out->m_Memory.m_pMemory[v8] = 0;
  return v7 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409B90
// Name: public: CCodeProcessor::CCodeProcessor(void)
// Source: json
//------------------------------------------------------------------------------
CCodeProcessor *__thiscall CCodeProcessor::CCodeProcessor(CCodeProcessor *this)
{
  CUtlDict<CCodeProcessor::CODE_MODULE,int> *p_m_Modules; // ecx

  p_m_Modules = &this->m_Modules;
  this->__vftable = (CCodeProcessor_vtbl *)&CCodeProcessor::`vftable';
  p_m_Modules->m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  p_m_Modules->m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  p_m_Modules->m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  p_m_Modules->m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  p_m_Modules->m_Elements.m_Tree.m_Root = -1;
  p_m_Modules->m_Elements.m_Tree.m_NumElements = 0;
  p_m_Modules->m_Elements.m_Tree.m_FirstFree = -1;
  p_m_Modules->m_Elements.m_Tree.m_LastAlloc.index = -1;
  p_m_Modules->m_Elements.m_Tree.m_pElements = p_m_Modules->m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( p_m_Modules->m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    p_m_Modules->m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_Headers.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Headers.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Headers.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Headers.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Headers.m_Elements.m_Tree.m_Root = -1;
  this->m_Headers.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Headers.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Headers.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Headers.m_Elements.m_Tree.m_pElements = this->m_Headers.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Headers.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Headers.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_IncludePath.m_Memory.m_pMemory = nullptr;
  this->m_IncludePath.m_Memory.m_nAllocationCount = 0;
  this->m_IncludePath.m_Memory.m_nGrowSize = 0;
  this->m_IncludePath.m_Size = 0;
  this->m_IncludePath.m_pElements = nullptr;
  this->m_pClassList = nullptr;
  CUtlDict<CCodeProcessor::CODE_MODULE,int>::RemoveAll(this: p_m_Modules);
  *(_WORD *)&this->m_bLogToFile = 0;
  this->m_nFilesProcessed = 0;
  this->m_nHeadersProcessed = 0;
  this->m_nClassesParsed = 0;
  this->m_nOffset = 0;
  this->m_nBytesProcessed = 0;
  this->m_nLinesOfCode = 0;
  this->m_szCurrentCPP[0] = 0;
  this->m_szBaseEntityClass[0] = 0;
  *(_DWORD *)&this->m_bQuiet = 16842752;
  *(_WORD *)&this->m_bPrintPredictionDescErrors = 1;
  this->m_flStart = 0.0;
  this->m_flEnd = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00409C60
// Name: public: int CUtlMap<char const __near *,struct CCodeProcessor::CODE_MODULE,int>::Insert(char const __near * const __near &,struct CCodeProcessor::CODE_MODULE const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Insert(
        CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int> *this,
        const char **key,
        int insert)
{
  bool v4; // al
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(_BYTE *)insert;
  node.key = *key;
  node.elem.skipped = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::NewNode(this: &this->m_Tree);
  CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00409CE0
// Name: public: int CUtlDict<struct CCodeProcessor::CODE_MODULE,int>::Insert(char const __near *,struct CCodeProcessor::CODE_MODULE const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CCodeProcessor::CODE_MODULE,int>::Insert(
        CUtlDict<CCodeProcessor::CODE_MODULE,int> *this,
        char *pName,
        const CCodeProcessor::CODE_MODULE *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x00409D40
// Name: private: void CCodeProcessor::AddHeader(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::AddHeader(CCodeProcessor *this, int depth, char *filename, const char *rootmodule)
{
  char *v5; // esi
  CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( depth == 1 )
  {
    v5 = filename;
    if ( filename == nullptr
      || (search.key = filename,
          CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Find(
            this: &this->m_Headers.m_Elements.m_Tree,
            &search) == -1)
      || V_stristr(pStr: v5, pSearch: "memdbgon.h") != nullptr
      || V_stristr(pStr: v5, pSearch: "memdbgoff.h") != nullptr )
    {
      HIBYTE(depth) = 0;
      CUtlDict<CCodeProcessor::CODE_MODULE,int>::Insert(
        this: &this->m_Headers,
        pName: v5,
        element: (const CCodeProcessor::CODE_MODULE *)&depth + 3);
    }
    else
    {
      _Warning(a1: "Warning [%s]: %s included twice\n", rootmodule, v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409DD0
// Name: private: bool CCodeProcessor::LoadFile(char __near * __near *,char __near *,char const __near *,bool,int,int __near &,int __near &,int __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCodeProcessor::LoadFile(
        CCodeProcessor *this,
        char **buffer,
        char *filename,
        const char *module,
        bool forcequiet,
        int depth,
        int *filelength,
        int *numheaders,
        int *skippedfiles,
        const char *root,
        const char *baseroot)
{
  int v12; // ebx
  int v13; // eax
  char *File; // eax
  CCodeProcessor::CODE_MODULE *p_elem; // ecx
  CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  v12 = 0;
  if ( this->m_IncludePath.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    sprintf(string: filename, format: "%s\\%s", this->m_IncludePath.m_Memory.m_pMemory[v12], module);
    strlwr(string: filename);
    V_FixSlashes(pname: filename, separator: 92);
    V_RemoveDotSlashes(pFilename: filename, separator: 92);
    if ( filename != nullptr )
    {
      search.key = filename;
      v13 = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::Find(
              this: &this->m_Modules.m_Elements.m_Tree,
              &search);
      if ( v13 != -1 )
        break;
    }
    File = (char *)COM_LoadFile(name: filename, len: filelength);
    *buffer = File;
    if ( File != nullptr )
      return 1;
    if ( ++v12 >= this->m_IncludePath.m_Size )
      return 0;
  }
  p_elem = &this->m_Modules.m_Elements.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem;
  if ( forcequiet )
  {
    ++this->m_nHeadersProcessed;
    ++*numheaders;
    if ( p_elem->skipped )
      ++*skippedfiles;
  }
  CCodeProcessor::AddHeader(this, depth, filename, rootmodule: this->m_szCurrentCPP);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409EA0
// Name: private: void CCodeProcessor::ProcessModule(bool,int,int __near &,int __near &,int __near &,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::ProcessModule(
        CCodeProcessor *this,
        bool forcequiet,
        int depth,
        int *maxdepth,
        int *numheaders,
        int *skippedfiles,
        const char *baseroot,
        const char *root,
        const char *module)
{
  int v9; // edi
  const char *v11; // esi
  int *v12; // ebx
  const char *v13; // ecx
  CCodeProcessor *v14; // esi
  const char *v15; // esi
  CCodeProcessor *v16; // ecx
  int v17; // esi
  int v18; // ebx
  char *v19; // edi
  CClass *v20; // edi
  char *v21; // esi
  char *v22; // eax
  char v23; // cl
  char *v24; // eax
  char *v25; // esi
  CClass *v26; // eax
  CClass *v27; // edi
  char *v28; // edi
  CClass *v29; // esi
  char *v30; // edi
  char *v31; // edi
  CCodeProcessor *v32; // esi
  char basename[256]; // [esp+Ch] [ebp-238h] BYREF
  char filename[256]; // [esp+10Ch] [ebp-138h] BYREF
  char prefix[32]; // [esp+20Ch] [ebp-38h] BYREF
  int filelength; // [esp+22Ch] [ebp-18h] BYREF
  char *buffer; // [esp+230h] [ebp-14h] BYREF
  CCodeProcessor *v38; // [esp+238h] [ebp-Ch]
  bool onclient; // [esp+23Fh] [ebp-5h] BYREF
  char *current; // [esp+240h] [ebp-4h]

  v9 = depth;
  v38 = this;
  if ( depth > *maxdepth )
    *maxdepth = depth;
  v11 = module;
  buffer = nullptr;
  if ( SkipFile(module) )
  {
    HIBYTE(module) = 1;
    CUtlDict<CCodeProcessor::CODE_MODULE,int>::Insert(
      this: &this->m_Modules,
      pName: filename,
      element: (const CCodeProcessor::CODE_MODULE *)&module + 3);
    ++*skippedfiles;
    return;
  }
  v12 = numheaders;
  v13 = v11;
  v14 = v38;
  if ( CCodeProcessor::LoadFile(
         this: v38,
         &buffer,
         filename,
         module: v13,
         forcequiet,
         depth,
         &filelength,
         numheaders,
         skippedfiles,
         root,
         baseroot) == 0 )
  {
    HIBYTE(module) = 1;
    CUtlDict<CCodeProcessor::CODE_MODULE,int>::Insert(
      this: &v14->m_Modules,
      pName: filename,
      element: (const CCodeProcessor::CODE_MODULE *)&module + 3);
    ++*skippedfiles;
    return;
  }
  v14->m_nBytesProcessed += filelength;
  onclient = false;
  CUtlDict<CCodeProcessor::CODE_MODULE,int>::Insert(
    this: &v14->m_Modules,
    pName: filename,
    element: (const CCodeProcessor::CODE_MODULE *)&onclient);
  if ( !forcequiet )
    strcpy(v14->m_szCurrentCPP, filename);
  CCodeProcessor::AddHeader(this: v14, depth, filename, rootmodule: v14->m_szCurrentCPP);
  onclient = V_strncasecmp(s1: v14->m_szBaseEntityClass, s2: aC_0, n: 2) == 0;
  current = CC_ParseToken(data: buffer);
  if ( current != nullptr )
  {
    while ( 1 )
    {
      v15 = module;
      if ( _V_stricmp(s1: com_token, s2: "#include") == 0 )
      {
        current = CC_ParseToken(data: current);
        if ( strlen(com_token) != 0 && com_token[0] != 60 )
        {
          v16 = v38;
          ++v38->m_nHeadersProcessed;
          ++*v12;
          CCodeProcessor::ProcessModule(
            this: v16,
            forcequiet: true,
            depth: v9 + 1,
            maxdepth,
            numheaders: v12,
            skippedfiles,
            baseroot,
            root,
            module: com_token);
        }
        goto LABEL_82;
      }
      if ( _V_stricmp(s1: com_token, s2: "class") != 0 && _V_stricmp(s1: com_token, s2: "struct") != 0 )
        break;
      v28 = CC_ParseToken(data: current);
      current = v28;
      if ( strlen(com_token) == 0 )
        goto LABEL_82;
      v29 = v38->AddClass(this: v38, a2: com_token);
      v30 = CC_ParseToken(data: v28);
      current = v30;
      if ( _V_stricmp(s1: com_token, s2: ":") != 0 )
        goto LABEL_79;
      v31 = CC_ParseToken(data: v30);
      current = v31;
      if ( _V_stricmp(s1: com_token, s2: "public") == 0 )
      {
        v30 = CC_ParseToken(data: v31);
        current = v30;
        if ( strlen(com_token) != 0 )
        {
          CClass::SetBaseClass(this: v29, name: com_token);
          do
            v30 = CC_ParseToken(data: v30);
          while ( strlen(com_token) != 0 && _V_stricmp(s1: com_token, s2: "{") != 0 );
          current = v30;
LABEL_79:
          if ( _V_stricmp(s1: com_token, s2: "{") != 0 )
            goto LABEL_82;
          v24 = CClass::ParseClassDeclaration(this: v29, input: v30);
LABEL_81:
          current = v24;
        }
      }
LABEL_82:
      v12 = numheaders;
      current = CC_ParseToken(data: current);
      if ( current == nullptr )
        goto LABEL_83;
      v9 = depth;
    }
    if ( V_strncasecmp(s1: com_token, s2: "PREDICTABLE_CLASS", n: 17) != 0 )
    {
      if ( strcmp(com_token, "TYPEDESCRIPTION") == 0 || strcmp(com_token, "typedescription_t") == 0 )
      {
        v24 = CCodeProcessor::ParseTypeDescription(this: v38, current, fIsMacroized: false, pModule: v15);
        goto LABEL_81;
      }
      if ( strcmp(com_token, "BEGIN_DATADESC") == 0
        || strcmp(com_token, "BEGIN_DATADESC_NO_BASE") == 0
        || strcmp(com_token, "BEGIN_SIMPLE_DATADESC") == 0
        || strcmp(com_token, "BEGIN_BYTESWAP_DATADESC") == 0 )
      {
        v24 = CCodeProcessor::ParseTypeDescription(this: v38, current, fIsMacroized: true, pModule: v15);
        goto LABEL_81;
      }
      if ( strcmp(com_token, "BEGIN_PREDICTION_DATA") == 0 || strcmp(com_token, "BEGIN_EMBEDDED_PREDDESC") == 0 )
      {
        v24 = CCodeProcessor::ParsePredictionTypeDescription(this: v38, current, pModule: v15);
        goto LABEL_81;
      }
      if ( strcmp(com_token, "BEGIN_RECV_TABLE") == 0
        || strcmp(com_token, "BEGIN_RECV_TABLE_NOBASE") == 0
        || strcmp(com_token, "IMPLEMENT_CLIENTCLASS_DT") == 0
        || strcmp(com_token, "IMPLEMENT_CLIENTCLASS_DT_NOBASE") == 0 )
      {
        v24 = CCodeProcessor::ParseReceiveTable(this: v38, current);
        goto LABEL_81;
      }
      if ( strcmp(com_token, "IMPLEMENT_PREDICTABLE_NODATA") == 0 )
      {
        current = CC_ParseToken(data: current);
        if ( strcmp(com_token, "(") == 0 )
        {
          v25 = CC_ParseToken(data: current);
          v26 = v38->FindClass(this: v38, a2: com_token);
          v27 = v26;
          if ( v26 != nullptr && v26->m_bHasPredictionData )
          {
            if ( !forcequiet )
              _Warning(
                a1: "Class %s declared predictable and implemented with IMPLEMENT_PREDICTABLE_NODATA in typedescription\n",
                v26->m_szName);
            v27->m_bHasPredictionData = false;
          }
          v24 = CC_ParseToken(data: v25);
          goto LABEL_81;
        }
      }
      goto LABEL_82;
    }
    prefix[0] = 0;
    v17 = 1;
    v18 = 0;
    if ( _V_stricmp(s1: com_token, s2: "PREDICTABLE_CLASS_ALIASED") != 0 )
    {
      if ( _V_stricmp(s1: com_token, s2: "PREDICTABLE_CLASS_SHARED") == 0 )
        goto LABEL_29;
      if ( _V_stricmp(s1: com_token, s2: "PREDICTABLE_CLASS") != 0 )
      {
        if ( _V_stricmp(s1: com_token, s2: "PREDICTABLE_CLASS_ALIASED_PREFIXED") != 0 )
          _Warning(a1: "PREDICTABLE_CLASS of unknown type!!! %s\n", com_token);
LABEL_29:
        v19 = CC_ParseToken(data: current);
        current = v19;
        if ( strcmp(com_token, "(") != 0 )
          goto LABEL_82;
        current = CC_ParseToken(data: v19);
        if ( strlen(com_token) == 0 )
          goto LABEL_82;
        v20 = v38->AddClass(this: v38, a2: com_token);
        current = CC_ParseToken(data: current);
        if ( _V_stricmp(s1: com_token, s2: ",") != 0 )
        {
          if ( _V_stricmp(s1: com_token, s2: ")") != 0 )
            goto LABEL_82;
          v24 = CClass::ParseClassDeclaration(this: v20, input: current);
          goto LABEL_81;
        }
        current = CC_ParseToken(data: current);
        if ( strlen(com_token) == 0 )
          goto LABEL_82;
        sprintf(string: basename, format: "%s%s", prefix, com_token);
        if ( v17 == 2 )
        {
          v21 = CC_ParseToken(data: current);
          if ( _V_stricmp(s1: com_token, s2: ",") != 0 || (v21 = CC_ParseToken(data: v21), strlen(com_token) == 0) )
          {
            do
LABEL_41:
              v21 = CC_ParseToken(data: v21);
            while ( strlen(com_token) != 0 && _V_stricmp(s1: com_token, s2: ")") != 0 );
            current = v21;
            if ( _V_stricmp(s1: com_token, s2: ")") == 0 )
            {
              v24 = CClass::ParseClassDeclaration(this: v20, input: v21);
              goto LABEL_81;
            }
            goto LABEL_82;
          }
          if ( v18 == 1 )
            sprintf(string: basename, format: "%s%s", prefix, com_token);
        }
        else
        {
          v21 = current;
        }
        CClass::SetBaseClass(this: v20, name: basename);
        v22 = basename;
        do
        {
          v23 = *v22;
          v22[(char *)v20 - basename + 256] = *v22;
          ++v22;
        }
        while ( v23 != 0 );
        goto LABEL_41;
      }
      if ( !onclient )
      {
        strcpy(prefix, "C");
        goto LABEL_29;
      }
    }
    else
    {
      v17 = 2;
      if ( !onclient )
      {
        strcpy(prefix, "C");
        v18 = 1;
        goto LABEL_29;
      }
    }
    strcpy(prefix, "C_");
    goto LABEL_29;
  }
LABEL_83:
  COM_FreeFile((unsigned __int8 *)buffer);
  v32 = v38;
  if ( !forcequiet && !v38->GetQuiet(this: v38) )
  {
    vprint(depth: 0, fmt: " %s: headers (%i game / %i total)", &filename[v32->m_nOffset], *v12 - *skippedfiles, *v12);
    if ( *maxdepth > 1 )
      vprint(depth: 0, fmt: ", depth %i", *maxdepth);
    vprint(depth: 0, fmt: "\n");
  }
  v32->m_nLinesOfCode += linesprocessed;
  linesprocessed = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A8D0
// Name: private: void CCodeProcessor::ConstructModuleList_R(int,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::ConstructModuleList_R(
        CCodeProcessor *this,
        int level,
        const char *baseentityclass,
        char *gamespecific,
        const char *root)
{
  const char *v5; // edi
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  char filename[256]; // [esp+8h] [ebp-348h] BYREF
  char directory[256]; // [esp+108h] [ebp-248h] BYREF
  _WIN32_FIND_DATAA wfd; // [esp+208h] [ebp-148h] BYREF
  int maxdepth; // [esp+348h] [ebp-8h] BYREF
  void *ff; // [esp+34Ch] [ebp-4h]

  v5 = root;
  sprintf(string: directory, format: "%s\\*.*", root);
  ff = FindFirstFileA(lpFileName: directory, lpFindFileData: &wfd);
  if ( ff != (void *)-1 )
  {
    v7 = level;
    do
    {
      if ( (wfd.dwFileAttributes & 0x10) != 0 )
      {
        if ( wfd.cFileName[0] != 46 )
        {
          if ( v7 != 0
            || (strstr(str1: (unsigned __int8 *)wfd.cFileName, str2: (unsigned __int8 *)gamespecific), v8 != 0) )
          {
            sprintf(string: filename, format: "%s\\%s", v5, wfd.cFileName);
            CCodeProcessor::ConstructModuleList_R(this, level: v7 + 1, baseentityclass, gamespecific, root: filename);
          }
        }
      }
      else
      {
        strstr(str1: (unsigned __int8 *)wfd.cFileName, str2: ".cpp");
        if ( v9 != 0 )
        {
          ++this->m_nFilesProcessed;
          CUtlDict<CCodeProcessor::CODE_MODULE,int>::RemoveAll(this: &this->m_Headers);
          level = 0;
          maxdepth = 0;
          root = nullptr;
          CCodeProcessor::ProcessModule(
            this,
            forcequiet: false,
            depth: 0,
            &maxdepth,
            numheaders: &level,
            skippedfiles: (int *)&root,
            baseroot: v5,
            root: v5,
            module: wfd.cFileName);
        }
      }
    }
    while ( FindNextFileA(hFindFile: ff, lpFindFileData: &wfd) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AA00
// Name: public: virtual void CCodeProcessor::Process(char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::Process(
        CCodeProcessor *this,
        const char *baseentityclass,
        char *gamespecific,
        const char *sourcetreebase,
        const char *subdir)
{
  int v6; // eax
  int v7; // eax
  char rootdirectory[256]; // [esp+Ch] [ebp-100h] BYREF

  CCodeProcessor::SetupIncludePath(this, sourcetreebase, subdir, gamespecific);
  strcpy(this->m_szBaseEntityClass, baseentityclass);
  this->m_nBytesProcessed = 0;
  this->m_nFilesProcessed = 0;
  this->m_nHeadersProcessed = 0;
  this->m_nClassesParsed = 0;
  this->m_nLinesOfCode = 0;
  linesprocessed = 0;
  CUtlDict<CCodeProcessor::CODE_MODULE,int>::RemoveAll(this: &this->m_Modules);
  CUtlDict<CCodeProcessor::CODE_MODULE,int>::RemoveAll(this: &this->m_Headers);
  v6 = clock();
  if ( byte_422230 != 0 )
  {
    byte_422230 = 0;
    dword_4277EC = v6;
  }
  this->m_flStart = (double)(v6 - dword_4277EC) * 0.001;
  sprintf(string: rootdirectory, format: "%s\\%s", sourcetreebase, subdir);
  vprint(depth: 0, fmt: "--- Processing %s\n\n", rootdirectory);
  this->m_nOffset = strlen(rootdirectory) + 1;
  CCodeProcessor::ConstructModuleList_R(this, level: 0, baseentityclass, gamespecific, root: rootdirectory);
  sprintf(string: rootdirectory, format: "%s\\%s", sourcetreebase, "game_shared");
  vprint(depth: 0, fmt: "--- Processing %s\n\n", rootdirectory);
  this->m_nOffset = strlen(rootdirectory) + 1;
  CCodeProcessor::ConstructModuleList_R(this, level: 0, baseentityclass, gamespecific, root: rootdirectory);
  v7 = clock();
  if ( byte_422230 != 0 )
  {
    byte_422230 = 0;
    dword_4277EC = v7;
  }
  this->m_flEnd = (double)(v7 - dword_4277EC) * 0.001;
  CCodeProcessor::PrintResults(this, baseentityclass);
}

//------------------------------------------------------------------------------
// Address: 0x0040ABA0
// Name: public: virtual void CCodeProcessor::Process(char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::Process(
        CCodeProcessor *this,
        const char *baseentityclass,
        const char *gamespecific,
        const char *sourcetreebase,
        const char *subdir,
        const char *pFileName)
{
  const char *v6; // edi
  int v8; // eax
  int v9; // eax
  const char *v10; // [esp-8h] [ebp-114h]
  char rootdirectory[256]; // [esp+Ch] [ebp-100h] BYREF

  v6 = subdir;
  CCodeProcessor::SetupIncludePath(this, sourcetreebase, subdir, gamespecific);
  strcpy(this->m_szBaseEntityClass, baseentityclass);
  this->m_nBytesProcessed = 0;
  this->m_nFilesProcessed = 0;
  this->m_nHeadersProcessed = 0;
  this->m_nClassesParsed = 0;
  this->m_nLinesOfCode = 0;
  linesprocessed = 0;
  CUtlDict<CCodeProcessor::CODE_MODULE,int>::RemoveAll(this: &this->m_Modules);
  CUtlDict<CCodeProcessor::CODE_MODULE,int>::RemoveAll(this: &this->m_Headers);
  v8 = clock();
  if ( byte_422230 != 0 )
  {
    byte_422230 = 0;
    dword_4277EC = v8;
  }
  v10 = sourcetreebase;
  this->m_flStart = (double)(v8 - dword_4277EC) * 0.001;
  sprintf(string: rootdirectory, format: "%s\\%s", v10, v6);
  vprint(depth: 0, fmt: "--- Processing %s\n\n", rootdirectory);
  ++this->m_nFilesProcessed;
  this->m_nOffset = strlen(rootdirectory) + 1;
  CUtlDict<CCodeProcessor::CODE_MODULE,int>::RemoveAll(this: &this->m_Headers);
  gamespecific = nullptr;
  subdir = nullptr;
  sourcetreebase = nullptr;
  CCodeProcessor::ProcessModule(
    this,
    forcequiet: false,
    depth: 0,
    maxdepth: (int *)&subdir,
    numheaders: (int *)&gamespecific,
    skippedfiles: (int *)&sourcetreebase,
    baseroot: rootdirectory,
    root: rootdirectory,
    module: pFileName);
  v9 = clock();
  if ( byte_422230 != 0 )
  {
    byte_422230 = 0;
    dword_4277EC = v9;
  }
  this->m_flEnd = (double)(v9 - dword_4277EC) * 0.001;
  CCodeProcessor::PrintResults(this, baseentityclass);
}

//------------------------------------------------------------------------------
// Address: 0x0040AD00
// Name: public: virtual void CCodeProcessor::ProcessVCProj(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCodeProcessor::ProcessVCProj(CCodeProcessor *this, const char *pFilename)
{
  int v3; // eax
  char *v4; // esi
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *p_m_IncludePath; // esi
  char *v6; // eax
  char *v7; // ebx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // edi
  int m_nAllocationCount; // eax
  void (__cdecl **v10)(IConVar *, const char *, float); // ecx
  int v11; // eax
  void (__cdecl **v12)(IConVar *, const char *, float); // edi
  char *v13; // ebx
  const char *v14; // esi
  const char *v15; // esi
  const char *v16; // eax
  signed int v17; // edi
  int v18; // esi
  int m_Size; // eax
  bool v20; // zf
  const char *v21; // eax
  const char *v22; // eax
  CCodeProcessor *v23; // edi
  CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int> > *p_m_Tree; // edi
  int Inorder; // esi
  char tmpFilename[260]; // [esp+Ch] [ebp-368h] BYREF
  char baseDirName[260]; // [esp+110h] [ebp-264h] BYREF
  char includePath[260]; // [esp+214h] [ebp-160h] BYREF
  CSplitString outStrings; // [esp+318h] [ebp-5Ch] BYREF
  int fileLen; // [esp+330h] [ebp-44h] BYREF
  CUtlVector<char,CUtlMemory<char,int> > includePathsStr; // [esp+334h] [ebp-40h] BYREF
  int numheaders; // [esp+348h] [ebp-2Ch] BYREF
  const char *v33; // [esp+34Ch] [ebp-28h]
  int maxdepth; // [esp+350h] [ebp-24h] BYREF
  int skippedfiles; // [esp+354h] [ebp-20h] BYREF
  CUtlVector<char,CUtlMemory<char,int> > relativeFilename; // [esp+358h] [ebp-1Ch] BYREF
  char *pFileText; // [esp+36Ch] [ebp-8h]
  CCodeProcessor *v38; // [esp+370h] [ebp-4h]
  int i; // [esp+37Ch] [ebp+8h]
  const char *ia; // [esp+37Ch] [ebp+8h]
  unsigned __int8 *ib; // [esp+37Ch] [ebp+8h]

  v38 = this;
  V_strncpy(pDest: tmpFilename, pSrc: pFilename, maxLen: 260);
  V_FixSlashes(pname: tmpFilename, separator: 92);
  strcpy(baseDirName, ".");
  memset(dst: (unsigned __int8 *)&baseDirName[2], value: 0, count: 0x102u);
  strrchr(string: (unsigned __int8 *)tmpFilename, chr: 0x5Cu);
  if ( v3 != 0 )
    V_strncpy(pDest: baseDirName, pSrc: tmpFilename, maxLen: v3 - (_DWORD)tmpFilename + 1);
  v4 = (char *)COM_LoadFile(name: pFilename, len: &fileLen);
  pFileText = v4;
  memset(&includePathsStr, 0, sizeof(includePathsStr));
  if ( GetQuotedString(pSearchBase: v4, pPrefix: "AdditionalIncludeDirectories=", out: &includePathsStr) == nullptr )
    _Error(a1: "Can't find AdditionalIncludeDirectories");
  CSplitString::CSplitString(this: &outStrings, pString: includePathsStr.m_Memory.m_pMemory, pSeparator: ";");
  i = 0;
  if ( outStrings.m_Size > 0 )
  {
    p_m_IncludePath = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&this->m_IncludePath;
    do
    {
      V_ComposeFileName(path: baseDirName, filename: outStrings.m_Memory.m_pMemory[i], dest: includePath, destSize: 260);
      V_FixSlashes(pname: includePath, separator: 92);
      V_StripTrailingSlash(ppath: includePath);
      V_RemoveDotSlashes(pFilename: includePath, separator: 92);
      v6 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(includePath) + 1);
      if ( v6 != nullptr )
      {
        strcpy(v6, includePath);
        v7 = v6;
      }
      else
      {
        v7 = nullptr;
      }
      m_pMemory = p_m_IncludePath[1].m_pMemory;
      m_nAllocationCount = p_m_IncludePath->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<char *,int>::Grow(this: p_m_IncludePath, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_IncludePath[1].m_pMemory;
      v10 = p_m_IncludePath->m_pMemory;
      v11 = (char *)p_m_IncludePath[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_IncludePath[1].m_nAllocationCount = (int)p_m_IncludePath->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[(_DWORD)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 4 * v11);
      v12 = &p_m_IncludePath->m_pMemory[(_DWORD)m_pMemory];
      if ( v12 != nullptr )
        *v12 = (void (__cdecl *)(IConVar *, const char *, float))v7;
      ++i;
    }
    while ( i < outStrings.m_Size );
    v4 = pFileText;
  }
  ia = v4;
  while ( 1 )
  {
    v13 = nullptr;
    memset(&relativeFilename, 0, sizeof(relativeFilename));
    v14 = V_stristr(pStr: ia, pSearch: "RelativePath=");
    if ( v14 == nullptr )
      break;
    v15 = &v14[_V_strlen(str: "RelativePath=") + 1];
    ib = (unsigned __int8 *)v15;
    if ( *(v15 - 1) != 34 )
      break;
    v16 = V_stristr(pStr: v15, pSearch: "\"");
    v17 = v16 - v15;
    v33 = v16;
    if ( v16 == nullptr || v17 < 1 )
      break;
    v18 = v17 + 1;
    m_Size = 0;
    relativeFilename.m_Size = 0;
    if ( v17 + 1 > 0 )
    {
      CUtlMemory<char,int>::Grow(this: &relativeFilename.m_Memory, num: v17 + 1);
      m_Size = relativeFilename.m_Size;
      v13 = relativeFilename.m_Memory.m_pMemory;
    }
    if ( m_Size > 0 && v18 > 0 )
      _V_memmove(dest: &v13[v18], src: v13, count: m_Size);
    memcpy(dst: (unsigned __int8 *)v13, src: ib, count: v17);
    v21 = v33 + 1;
    v20 = v33 + 1 == nullptr;
    v13[v17] = 0;
    ia = v21;
    if ( v20 )
      break;
    strrchr(string: (unsigned __int8 *)v13, chr: 0x2Eu);
    if ( v22 != nullptr && _V_stricmp(s1: v22, s2: ".cpp") == 0 )
    {
      v23 = v38;
      ++v38->m_nFilesProcessed;
      p_m_Tree = &v23->m_Headers.m_Elements.m_Tree;
      Inorder = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::FirstInorder(this: p_m_Tree);
      if ( Inorder != -1 )
      {
        do
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_Tree->m_Elements.m_pMemory[Inorder].m_Data.key);
          Inorder = CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::NextInorder(
                      this: p_m_Tree,
                      i: Inorder);
        }
        while ( Inorder != -1 );
        v13 = relativeFilename.m_Memory.m_pMemory;
      }
      CUtlRBTree<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int,CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CCodeProcessor::CODE_MODULE,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
      numheaders = 0;
      maxdepth = 0;
      skippedfiles = 0;
      CCodeProcessor::ProcessModule(
        this: v38,
        forcequiet: false,
        depth: 0,
        &maxdepth,
        &numheaders,
        &skippedfiles,
        baseroot: baseDirName,
        root: baseDirName,
        module: v13);
    }
    if ( relativeFilename.m_Memory.m_nGrowSize >= 0 && v13 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
  }
  if ( relativeFilename.m_Memory.m_nGrowSize >= 0 && v13 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
  free(pMem: pFileText);
  CCodeProcessor::PrintResults(this: v38, baseentityclass: "CBaseEntity");
  CSplitString::~CSplitString(this: &outStrings);
  if ( includePathsStr.m_Memory.m_nGrowSize >= 0 && includePathsStr.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: includePathsStr.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040C160
// Name: public: void CUtlMemory<char __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char *,int>::Grow(
        CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // edx
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
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Realloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: m_pMemory,
                                                                             a3: v7);
    else
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Alloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C2B0
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this)
{
  bool v2; // sf
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // eax

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
// Address: 0x004068C0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x004068E0
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _calloc_crt(unsigned int count, unsigned int size)
{
  unsigned __int8 *v2; // edi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * count);
  memset(dst: v2, value: 0, count: size * count);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00406910
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x00406930
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: v3, value: 0, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00406970
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x00406990
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}
