// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/wavebrowser.cpp
// Functions: 170
// ============================================================

#include "utils\scenemanager\wavebrowser.h"

//------------------------------------------------------------------------------
// Address: 0x0040A010
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_474D10 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_474D10;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0040A070
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_474D10 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0040A0D0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_474D10 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040A130
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x0040A1E0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_474D10 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_474D10 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A2B0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
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
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i) == 0xFFFF )
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                       this,
                       i);
    v7 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    for ( result = (unsigned __int16)result; ; result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Parent )
    {
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      v10 = (_WORD)v9 == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v9];
      if ( *((_WORD *)v10 + 1) != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
    }
  }
  else
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                       this,
                       i);
    v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    result = (unsigned __int16)result;
    while ( 1 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( *(_WORD *)v6 == 0xFFFF )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)result == 0xFFFF )
        result = (unsigned __int16)`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A4A0
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x0040D200
// Name: NameLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NameLessFunc(CSoundEntry *const *name1, CSoundEntry *const *name2)
{
  int (__thiscall ***v2)(_DWORD); // esi
  const char *v3; // eax
  const char *v5; // [esp-4h] [ebp-8h]

  v2 = (int (__thiscall ***)(_DWORD))*name1;
  v5 = (const char *)(***(int (__thiscall ****)(_DWORD))name2)(a1: *name2);
  v3 = (const char *)(**v2)(a1: v2);
  return _V_stricmp(s1: v3, s2: v5) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040D3D0
// Name: public: int CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Parent(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( i == -1 )
    return dword_48CB9C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x0040D430
// Name: public: int CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RightChild(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( i == -1 )
    return dword_48CB98;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040D490
// Name: public: bool CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::IsRightChild(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CSoundEntry *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( m_Parent == -1 )
    return dword_48CB98 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x0040D540
// Name: protected: void CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::FindInsertionPosition(class CSoundEntry __near * const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this,
        CSoundEntry *const *insert,
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
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CB98 = -1;
        dword_48CB9C = -1;
        dword_48CBA0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CB98 = -1;
        dword_48CB9C = -1;
        dword_48CBA0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D630
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode@<eax>(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this@<ecx>,
        const char *a2@<edi>)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  UtlRBTreeNode_t<CSoundEntry *,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CSoundEntry *,int> *v12; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v6 = index + 1;
      if ( v6 < 0 || v6 >= m_nAllocationCount )
        v6 = -1;
    }
    v7 = v6;
    if ( v6 < 0 || v6 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(this: &this->m_Elements, num: 1);
      v8 = this->m_LastAlloc.index;
      if ( v8 < 0 || (v9 = this->m_Elements.m_nAllocationCount, v8 >= v9) )
      {
        v9 = this->m_Elements.m_nAllocationCount;
        v10 = (v9 > 0) - 1;
      }
      else
      {
        v10 = v8 + 1;
        if ( v10 < 0 || v10 >= v9 )
          v10 = -1;
      }
      v7 = v10;
      if ( v10 < 0 || v10 >= v9 )
        _Error(this: (ISceneTokenProcessor *)&stru_44E324, a2);
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v7;
    this->m_pElements = m_pMemory;
    return v7;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[result].m_Right;
    this->m_pElements = v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D6F0
// Name: public: bool CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::IsLeftChild(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CSoundEntry *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x0040D7A0
// Name: protected: void CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RotateLeft(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CSoundEntry *,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *v8; // ecx
  UtlRBTreeNode_t<CSoundEntry *,int> *v9; // eax

  v2 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_48CB98 = -1;
      dword_48CB9C = -1;
      dword_48CBA0 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0040D950
// Name: protected: void CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RotateRight(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CSoundEntry *,int> *v6; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *v7; // eax

  v2 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0040DB10
// Name: public: int CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::FirstInorder(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_48CB98 = -1;
      dword_48CB9C = -1;
      dword_48CBA0 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_48CB98 = -1;
      dword_48CB9C = -1;
      dword_48CBA0 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040DBB0
// Name: public: int CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::NextInorder(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CSoundEntry *,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CB98 = -1;
    dword_48CB9C = -1;
    dword_48CBA0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48CB98 = -1;
          dword_48CB9C = -1;
          dword_48CBA0 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CB98 = -1;
        dword_48CB9C = -1;
        dword_48CBA0 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CB98 = -1;
        dword_48CB9C = -1;
        dword_48CBA0 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040DD20
// Name: public: void CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RemoveAll(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this)
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
          if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48CB98 = -1;
            dword_48CB9C = -1;
            dword_48CBA0 = 1;
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
// Address: 0x0040DDE0
// Name: protected: void CUtlRBTree<class CSoundEntry __near *,int,bool (*)(class CSoundEntry __near * const __near &,class CSoundEntry __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CSoundEntry __near *,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::InsertRebalance(
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CSoundEntry *,int> *v7; // ecx
  UtlRBTreeNode_t<CSoundEntry *,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CSoundEntry *,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CSoundEntry *,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *v18; // ecx
  UtlRBTreeNode_t<CSoundEntry *,int> *v19; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *v20; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CSoundEntry *,int> *v23; // ecx
  UtlRBTreeNode_t<CSoundEntry *,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CB98 = -1;
        dword_48CB9C = -1;
        dword_48CBA0 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CB98 = -1;
        dword_48CB9C = -1;
        dword_48CBA0 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CB98 = -1;
        dword_48CB9C = -1;
        dword_48CBA0 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CB98 = -1;
        dword_48CB9C = -1;
        dword_48CBA0 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48CB98 = -1;
          dword_48CB9C = -1;
          dword_48CBA0 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48CB98 = -1;
          dword_48CB9C = -1;
          dword_48CBA0 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48CB98 = -1;
            dword_48CB9C = -1;
            dword_48CBA0 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48CB98 = -1;
            dword_48CB9C = -1;
            dword_48CBA0 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48CB98 = -1;
          dword_48CB9C = -1;
          dword_48CBA0 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48CB98 = -1;
          dword_48CB9C = -1;
          dword_48CBA0 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
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
        if ( CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48CB98 = -1;
            dword_48CB9C = -1;
            dword_48CBA0 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48CB98 = -1;
            dword_48CB9C = -1;
            dword_48CBA0 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CSoundEntry *,int> *)&`CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CSoundEntry *,int,bool (__cdecl *)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int>>::RotateLeft(
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
// Address: 0x00410CA0
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( i == -1 )
    return dword_48CDF8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00410D00
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( i == -1 )
    return dword_48CDF4;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00410D60
// Name: public: bool CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<char const *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( m_Parent == -1 )
    return dword_48CDF4 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00410E10
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::FindInsertionPosition(char const __near * const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FindInsertionPosition(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        const char *const *insert,
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
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CDF4 = -1;
        dword_48CDF8 = -1;
        dword_48CDFC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CDF4 = -1;
        dword_48CDF8 = -1;
        dword_48CDFC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410F00
// Name: public: bool CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<char const *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00410FB0
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<char const *,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<char const *,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<char const *,int> *v8; // ecx
  UtlRBTreeNode_t<char const *,int> *v9; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_48CDF4 = -1;
      dword_48CDF8 = -1;
      dword_48CDFC = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00411160
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<char const *,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<char const *,int> *v6; // eax
  UtlRBTreeNode_t<char const *,int> *v7; // eax

  v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004112D0
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::FirstInorder(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_48CDF4 = -1;
      dword_48CDF8 = -1;
      dword_48CDFC = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_48CDF4 = -1;
      dword_48CDF8 = -1;
      dword_48CDFC = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411370
// Name: public: int CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NextInorder(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<char const *,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48CDF4 = -1;
    dword_48CDF8 = -1;
    dword_48CDFC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48CDF4 = -1;
          dword_48CDF8 = -1;
          dword_48CDFC = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CDF4 = -1;
        dword_48CDF8 = -1;
        dword_48CDFC = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CDF4 = -1;
        dword_48CDF8 = -1;
        dword_48CDFC = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004114E0
// Name: public: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RemoveAll(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this)
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
          if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48CDF4 = -1;
            dword_48CDF8 = -1;
            dword_48CDFC = 1;
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
// Address: 0x004115A0
// Name: protected: void CUtlRBTree<char const __near *,int,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::InsertRebalance(
        CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<char const *,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<char const *,int> *v7; // ecx
  UtlRBTreeNode_t<char const *,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<char const *,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<char const *,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<char const *,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<char const *,int> *v18; // ecx
  UtlRBTreeNode_t<char const *,int> *v19; // eax
  UtlRBTreeNode_t<char const *,int> *v20; // eax
  UtlRBTreeNode_t<char const *,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<char const *,int> *v23; // ecx
  UtlRBTreeNode_t<char const *,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CDF4 = -1;
        dword_48CDF8 = -1;
        dword_48CDFC = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CDF4 = -1;
        dword_48CDF8 = -1;
        dword_48CDFC = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CDF4 = -1;
        dword_48CDF8 = -1;
        dword_48CDFC = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48CDF4 = -1;
        dword_48CDF8 = -1;
        dword_48CDFC = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48CDF4 = -1;
          dword_48CDF8 = -1;
          dword_48CDFC = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48CDF4 = -1;
          dword_48CDF8 = -1;
          dword_48CDFC = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48CDF4 = -1;
            dword_48CDF8 = -1;
            dword_48CDFC = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48CDF4 = -1;
            dword_48CDF8 = -1;
            dword_48CDFC = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48CDF4 = -1;
          dword_48CDF8 = -1;
          dword_48CDFC = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48CDF4 = -1;
          dword_48CDF8 = -1;
          dword_48CDFC = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
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
        if ( CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48CDF4 = -1;
            dword_48CDF8 = -1;
            dword_48CDFC = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48CDF4 = -1;
            dword_48CDF8 = -1;
            dword_48CDFC = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<char const *,int> *)&`CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::RotateLeft(
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
// Address: 0x00412FC0
// Name: public: virtual bool CWaveOptionsWindow::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaveOptionsWindow::PaintBackground(COptionsWindow *this)
{
  this->redraw(this);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00414410
// Name: bool StringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StringLessThan(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00414470
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x004144A0
// Name: char __near * PSkipSoundChars(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl PSkipSoundChars(char *pch)
{
  char *result; // eax
  char v2; // cl

  for ( result = pch; ; ++result )
  {
    v2 = *result;
    if ( *result != 42
      && v2 != 63
      && v2 != 33
      && v2 != 35
      && v2 != 64
      && v2 != 40
      && v2 != 62
      && v2 != 60
      && v2 != 94
      && v2 != 41
      && v2 != 125
      && v2 != 36 )
    {
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004144F0
// Name: public: void CWaveFileTree::_PopulateTree(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFileTree::_PopulateTree(CWaveFileTree *this, void *pathId, void **path)
{
  char *v4; // ebx
  char *v5; // eax
  void **FirstChild; // esi
  const char *Label; // eax
  char *v8; // [esp-4h] [ebp-214h]
  char sz[512]; // [esp+Ch] [ebp-204h] BYREF
  char *check; // [esp+20Ch] [ebp-4h]
  void **cur; // [esp+21Ch] [ebp+Ch]

  _V_strcpy(dest: sz, src: (const char *)path);
  v4 = sz;
  cur = nullptr;
  do
  {
    if ( *v4 == 0 )
      break;
    v5 = _V_strstr(s1: v4, search: "/");
    if ( v5 == nullptr )
      v5 = _V_strstr(s1: v4, search: "\\");
    check = v4;
    if ( v5 != nullptr )
    {
      *v5 = 0;
      v4 = v5 + 1;
    }
    else
    {
      v4 = nullptr;
    }
    FirstChild = mxTreeView::getFirstChild(this, item: cur);
    if ( FirstChild != nullptr )
    {
      while ( 1 )
      {
        v8 = check;
        Label = mxTreeView::getLabel(this, item: FirstChild);
        if ( _V_stricmp(s1: Label, s2: v8) == 0 )
          break;
        FirstChild = mxTreeView::getNextChild(this, item: FirstChild);
        if ( FirstChild == nullptr )
          goto LABEL_11;
      }
      cur = FirstChild;
    }
    else
    {
LABEL_11:
      cur = mxTreeView::add(this, parent: cur, item: check);
    }
  }
  while ( v4 != nullptr );
  mxTreeView::setUserData(this, item: cur, userData: pathId);
}

//------------------------------------------------------------------------------
// Address: 0x004145D0
// Name: public: static bool CWaveFileTree::FileTreeLessFunc(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CWaveFileTree::FileTreeLessFunc(
        const CWaveFileTree::FileTreePath *lhs,
        const CWaveFileTree::FileTreePath *rhs)
{
  return _V_stricmp(s1: lhs->path, s2: rhs->path) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x004145F0
// Name: public: CWaveOptionsWindow::CWaveOptionsWindow(class CWaveBrowser __near *)
// Source: json
//------------------------------------------------------------------------------
CWaveOptionsWindow *__thiscall CWaveOptionsWindow::CWaveOptionsWindow(CWaveOptionsWindow *this, CWaveBrowser *browser)
{
  mxButton *v3; // eax
  mxButton *v4; // eax
  mxButton *v5; // eax
  mxButton *v6; // eax
  mxButton *v7; // eax
  mxButton *v8; // eax
  mxLabel *v9; // eax

  mxWindow::mxWindow(this, parent: browser, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  this->__vftable = (CWaveOptionsWindow_vtbl *)&CWaveOptionsWindow::`vftable';
  this->m_pBrowser = browser;
  SceneManager_AddWindowStyle(w: this, addbits: 100663296);
  this->m_szSearchString[0] = 0;
  v3 = (mxButton *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxButton::mxButton(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Play", id: 1000);
  else
    v4 = nullptr;
  this->m_pPlay = v4;
  v5 = (mxButton *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = mxButton::mxButton(this: v5, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Stop Sounds", id: 1001);
  else
    v6 = nullptr;
  this->m_pStopSounds = v6;
  v7 = (mxButton *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
    v8 = mxButton::mxButton(this: v7, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Search...", id: 1002);
  else
    v8 = nullptr;
  this->m_pSearch = v8;
  v9 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    this->m_pSearchString = mxLabel::mxLabel(this: v9, parent: this, x: 0, y: 0, w: 0, h: 0, label: &WindowName);
  else
    this->m_pSearchString = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004146F0
// Name: public: virtual void CWaveOptionsWindow::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveOptionsWindow::redraw(COptionsWindow *this)
{
  DWORD SysColor; // eax
  CDrawHelper drawHelper; // [esp+4h] [ebp-54h] BYREF

  SysColor = GetSysColor(nIndex: 15);
  CDrawHelper::CDrawHelper(this: &drawHelper, widget: this, bgColor: SysColor);
  CDrawHelper::~CDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x00414780
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *m_pMemory; // edx
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
    v7 = 276 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)_g_pMemAlloc->Realloc_2(
                                                                              this: _g_pMemAlloc,
                                                                              a2: m_pMemory,
                                                                              a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)_g_pMemAlloc->Alloc_2(
                                                                              this: _g_pMemAlloc,
                                                                              a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004148C0
// Name: public: int CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Parent(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00414920
// Name: public: int CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *__thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RightChild(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory;
  else
    return (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00414980
// Name: public: bool CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::IsRightChild(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory == (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00414A30
// Name: protected: void CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::FindInsertionPosition(struct CWaveFileTree::FileTreePath const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        const CWaveFileTree::FileTreePath *insert,
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
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414B20
// Name: public: int CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Parent(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00414B80
// Name: public: int CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RightChild(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00414BE0
// Name: public: bool CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::IsRightChild(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CWaveFile *,int> *p_m_NumElements; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( i == -1 )
    p_m_NumElements = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    p_m_NumElements = &this->m_Elements.m_pMemory[i];
  m_Parent = p_m_NumElements->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00414C90
// Name: protected: void CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::FindInsertionPosition(class CWaveFile __near * const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this,
        CWaveFile *const *insert,
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
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414D80
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( i == -1 )
    return dword_48D214;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00414DE0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( i == -1 )
    return dword_48D210;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00414E40
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( m_Parent == -1 )
    return dword_48D210 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00414EF0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CWaveFile *,int>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D210 = -1;
        dword_48D214 = -1;
        dword_48D218 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D210 = -1;
        dword_48D214 = -1;
        dword_48D218 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414FE0
// Name: public: int CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::NewNode@<eax>(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this@<ecx>,
        const char *a2@<edi>)
{
  int m_FirstFree; // ecx
  int index; // ecx
  int m_nAllocationCount; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v13; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v6 = index + 1;
      if ( v6 < 0 || v6 >= m_nAllocationCount )
        v6 = -1;
    }
    v7 = v6;
    if ( v6 < 0 || v6 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>::Grow(this: &this->m_Elements, num: 1);
      v8 = this->m_LastAlloc.index;
      if ( v8 < 0 || (v9 = this->m_Elements.m_nAllocationCount, v8 >= v9) )
      {
        v9 = this->m_Elements.m_nAllocationCount;
        v10 = (v9 > 0) - 1;
      }
      else
      {
        v10 = v8 + 1;
        if ( v10 < 0 || v10 >= v9 )
          v10 = -1;
      }
      v7 = v10;
      if ( v10 < 0 || v10 >= v9 )
        _Error(this: (ISceneTokenProcessor *)&stru_44E324, a2);
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v7;
    this->m_pElements = m_pMemory;
    return v7;
  }
  else
  {
    v13 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v13[m_FirstFree].m_Right;
    this->m_pElements = v13;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004150B0
// Name: public: bool CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::IsLeftChild(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc == (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00415160
// Name: protected: void CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RotateLeft(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v4; // eax
  int m_Right; // edi
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v6; // eax
  int v7; // edx
  int v8; // ecx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v9; // eax
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v10; // eax
  int v11; // eax

  m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v8 = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    v8 = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
       | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v9 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v9 = &this->m_Elements.m_pMemory[m_Right];
  if ( v9->m_Left != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v8 | 1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( m_Right == -1 )
      v10 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v10 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v10->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
  {
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v11 = CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v11].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
    v7 = elem;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00415340
// Name: protected: void CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RotateRight(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v4; // eax
  int m_Left; // edi
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v6; // eax
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v7; // eax

  m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[(_DWORD)CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RightChild(
                                         this,
                                         i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004154D0
// Name: public: bool CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::IsLeftChild(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CWaveFile *,int> *p_m_NumElements; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( i == -1 )
    p_m_NumElements = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    p_m_NumElements = &this->m_Elements.m_pMemory[i];
  m_Parent = p_m_NumElements->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00415580
// Name: protected: void CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RotateLeft(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *p_m_NumElements; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CWaveFile *,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *v8; // ecx
  UtlRBTreeNode_t<CWaveFile *,int> *v9; // eax

  v2 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( elem == -1 )
    p_m_NumElements = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    p_m_NumElements = &this->m_Elements.m_pMemory[elem];
  m_Right = p_m_NumElements->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00415730
// Name: protected: void CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RotateRight(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *p_m_NumElements; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CWaveFile *,int> *v6; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *v7; // eax

  v2 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( elem == -1 )
    p_m_NumElements = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    p_m_NumElements = &this->m_Elements.m_pMemory[elem];
  m_Left = p_m_NumElements->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004158A0
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00415950
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_48D210 = -1;
      dword_48D214 = -1;
      dword_48D218 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00415B00
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00415C70
// Name: public: char const __near * CWaveFileTree::GetSelectedPath(void)
// Source: json
//------------------------------------------------------------------------------
CWaveFileTree::FileTreePath *__thiscall CWaveFileTree::GetSelectedPath(CWaveFileTree *this)
{
  void **SelectedItem; // eax
  int UserData; // eax

  SelectedItem = mxTreeView::getSelectedItem(this);
  UserData = (int)mxTreeView::getUserData(this, item: SelectedItem);
  if ( UserData < 0 || (unsigned int)UserData >= this->m_Paths.m_NumElements )
    return (CWaveFileTree::FileTreePath *)&WindowName;
  else
    return &this->m_Paths.m_Elements.m_pMemory[UserData].m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x00415CA0
// Name: public: int CWaveBrowser::GetSoundCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveBrowser::GetSoundCount(CWaveBrowser *this)
{
  return this->m_AllSounds.m_Elements.m_Tree.m_NumElements;
}

//------------------------------------------------------------------------------
// Address: 0x00415CB0
// Name: public: int CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::Find(struct CWaveFileTree::FileTreePath const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Find(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        const CWaveFileTree::FileTreePath *search)
{
  int m_Root; // ebx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00415DA0
// Name: public: void CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RemoveAll(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this)
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
          if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              & 1) == 0 )
          {
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
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
// Address: 0x00415E60
// Name: public: int CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
bool (__cdecl *__thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::FirstInorder(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this))(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *)
{
  int m_Root; // ebx
  bool (__cdecl *result)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *); // eax
  CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *v3; // edx

  m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  result = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))this->m_Root;
  while ( 1 )
  {
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    v3 = result == (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1
       ? &`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel
       : (CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
    if ( v3->m_LessFunc == (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1 )
      break;
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( result == (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1 )
      result = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc;
    else
      result = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415F00
// Name: public: int CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *__thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::NextInorder(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v3; // eax
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *result; // eax
  int m_Root; // edx
  CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *v6; // ecx
  int m_Parent; // esi
  int v8; // [esp-4h] [ebp-10h]

  if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v8 = m_Parent;
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)m_Parent;
  }
  else
  {
    result = CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RightChild(
               this,
               i);
    m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
    while ( 1 )
    {
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v6 = result == (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1
         ? &`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel
         : (CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
      if ( v6->m_LessFunc == (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( result == (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1 )
        result = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc;
      else
        result = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416070
// Name: public: int CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::FirstInorder(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
      `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416110
// Name: public: int CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::NextInorder(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CWaveFile *,int> *p_m_NumElements; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
    `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
  }
  if ( i == -1 )
    p_m_NumElements = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
  else
    p_m_NumElements = &this->m_Elements.m_pMemory[i];
  if ( p_m_NumElements->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416280
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,CWaveFile *,int>::Node_t *search)
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
      if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D210 = -1;
        dword_48D214 = -1;
        dword_48D218 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D210 = -1;
        dword_48D214 = -1;
        dword_48D218 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00416370
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this)
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
          if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48D210 = -1;
            dword_48D214 = -1;
            dword_48D218 = 1;
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
// Address: 0x00416430
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_48D210 = -1;
      dword_48D214 = -1;
      dword_48D218 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_48D210 = -1;
      dword_48D214 = -1;
      dword_48D218 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004164D0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D210 = -1;
    dword_48D214 = -1;
    dword_48D218 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48D210 = -1;
          dword_48D214 = -1;
          dword_48D218 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D210 = -1;
        dword_48D214 = -1;
        dword_48D218 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D210 = -1;
        dword_48D214 = -1;
        dword_48D218 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416640
// Name: public: void CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RemoveAll(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this)
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
          if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
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
// Address: 0x00416700
// Name: protected: void CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::InsertRebalance(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        int elem)
{
  int v2; // eax
  int m_Root; // edx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v7; // ecx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v8; // eax
  int v9; // esi
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v10; // eax
  int v11; // ebx
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v18; // esi
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v19; // eax
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v20; // eax
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v23; // esi
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        m_Root = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
               | 1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
          if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                | 1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v17 | 1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
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
        if ( CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
          if ( (`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                | 1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v22 | 1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))-1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RotateLeft(
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
// Address: 0x00416B90
// Name: protected: void CUtlRBTree<class CWaveFile __near *,int,bool (*)(class CWaveFile __near * const __near &,class CWaveFile __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CWaveFile __near *,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::InsertRebalance(
        CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *p_m_NumElements; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CWaveFile *,int> *v7; // ecx
  UtlRBTreeNode_t<CWaveFile *,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CWaveFile *,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CWaveFile *,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *v18; // ecx
  UtlRBTreeNode_t<CWaveFile *,int> *v19; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *v20; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *v23; // ecx
  UtlRBTreeNode_t<CWaveFile *,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
      }
      if ( v2 == -1 )
        p_m_NumElements = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
      else
        p_m_NumElements = &this->m_Elements.m_pMemory[v2];
      m_Parent = p_m_NumElements->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
        `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
          `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
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
        if ( CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_FirstFree = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc.index = -1;
            `CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_pElements = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CWaveFile *,int> *)&`CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RotateLeft(
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
// Address: 0x00416FF0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D210 = -1;
        dword_48D214 = -1;
        dword_48D218 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D210 = -1;
        dword_48D214 = -1;
        dword_48D218 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D210 = -1;
        dword_48D214 = -1;
        dword_48D218 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D210 = -1;
        dword_48D214 = -1;
        dword_48D218 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48D210 = -1;
          dword_48D214 = -1;
          dword_48D218 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48D210 = -1;
          dword_48D214 = -1;
          dword_48D218 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48D210 = -1;
            dword_48D214 = -1;
            dword_48D218 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48D210 = -1;
            dword_48D214 = -1;
            dword_48D218 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48D210 = -1;
          dword_48D214 = -1;
          dword_48D218 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48D210 = -1;
          dword_48D214 = -1;
          dword_48D218 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
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
        if ( CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48D210 = -1;
            dword_48D214 = -1;
            dword_48D218 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48D210 = -1;
            dword_48D214 = -1;
            dword_48D218 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RotateLeft(
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
// Address: 0x00417450
// Name: public: class CWaveFile __near * CWaveBrowser::GetSound(int)
// Source: json
//------------------------------------------------------------------------------
CWaveFile *__thiscall CWaveBrowser::GetSound(CWaveBrowser *this, int index)
{
  if ( index < 0 || (unsigned int)index >= this->m_AllSounds.m_Elements.m_Tree.m_NumElements )
    return nullptr;
  else
    return this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory[index].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417480
// Name: public: CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::~CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::~CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this)
{
  CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RemoveAll(this);
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
// Address: 0x004174E0
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RemoveAll(this);
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
// Address: 0x00417540
// Name: protected: void CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::LinkToParent(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *v4; // eax
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *m_pMemory; // eax
  int v6; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::InsertRebalance(
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
    CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417650
// Name: private: void CWaveBrowser::ShowContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::ShowContextMenu(CWaveBrowser *this)
{
  HWND Handle; // eax
  mxPopupMenu *v3; // eax
  mxPopupMenu *v4; // esi
  tagPOINT pt; // [esp+4h] [ebp-8h] BYREF

  CSoundBrowser::BuildSelectionList(
    (CSoundBrowser *)this,
    selected: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&this->m_CurrentSelection);
  if ( this->m_CurrentSelection.m_Size > 0 )
  {
    GetCursorPos(lpPoint: &pt);
    Handle = (HWND)mxWidget::getHandle(this);
    ScreenToClient(hWnd: Handle, lpPoint: &pt);
    v3 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v3 != nullptr )
      v4 = mxPopupMenu::mxPopupMenu(this: v3);
    else
      v4 = nullptr;
    if ( this->m_CurrentSelection.m_Size == 1 )
    {
      mxPopupMenu::add(this: v4, item: "&Play", id: 1000);
      mxPopupMenu::add(this: v4, item: "Properties...", id: 1003);
    }
    else
    {
      mxPopupMenu::add(this: v4, item: "Enable Voice Ducking", id: 1004);
      mxPopupMenu::add(this: v4, item: "Disable Voice Ducking", id: 1005);
    }
    mxMenu::addSeparator(this: v4);
    mxPopupMenu::add(this: v4, item: "Refresh sentence data", id: 1008);
    mxPopupMenu::add(this: v4, item: "Import Sentence Data", id: 1007);
    mxPopupMenu::add(this: v4, item: "Export Sentence Data", id: 1006);
    mxMenu::addSeparator(this: v4);
    mxPopupMenu::add(this: v4, item: "Check out", id: 1001);
    mxPopupMenu::add(this: v4, item: "Check in", id: 1002);
    mxPopupMenu::popup(this: v4, widget: this, x: pt.x, y: pt.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417770
// Name: public: void CWaveBrowser::OnPlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnPlay(CWaveBrowser *this)
{
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *p_m_CurrentSelection; // edi
  CWaveFile *v3; // ecx

  p_m_CurrentSelection = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(
    (CSoundBrowser *)this,
    selected: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&this->m_CurrentSelection);
  if ( this->m_CurrentSelection.m_Size == 1 )
  {
    v3 = *p_m_CurrentSelection->m_Memory.m_pMemory;
    if ( v3 != nullptr )
      CWaveFile::Play(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004177A0
// Name: private: void CWaveBrowser::OnCheckout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnCheckout(CWaveBrowser *this)
{
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *p_m_CurrentSelection; // edi
  int m_Size; // ebx
  int i; // esi
  CWorkspaceManager *WorkspaceManager; // eax

  p_m_CurrentSelection = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(
    (CSoundBrowser *)this,
    selected: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&this->m_CurrentSelection);
  m_Size = this->m_CurrentSelection.m_Size;
  for ( i = 0; i < m_Size; ++i )
    p_m_CurrentSelection->m_Memory.m_pMemory[i]->Checkout(this: p_m_CurrentSelection->m_Memory.m_pMemory[i], a2: false);
  WorkspaceManager = GetWorkspaceManager();
  CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
}

//------------------------------------------------------------------------------
// Address: 0x004177F0
// Name: private: void CWaveBrowser::OnCheckin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnCheckin(CWaveBrowser *this)
{
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *p_m_CurrentSelection; // edi
  int m_Size; // ebx
  int i; // esi
  CWorkspaceManager *WorkspaceManager; // eax

  p_m_CurrentSelection = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(
    (CSoundBrowser *)this,
    selected: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&this->m_CurrentSelection);
  m_Size = this->m_CurrentSelection.m_Size;
  for ( i = 0; i < m_Size; ++i )
    p_m_CurrentSelection->m_Memory.m_pMemory[i]->Checkin(this: p_m_CurrentSelection->m_Memory.m_pMemory[i], a2: false);
  WorkspaceManager = GetWorkspaceManager();
  CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
}

//------------------------------------------------------------------------------
// Address: 0x00417840
// Name: private: void CWaveBrowser::OnWaveProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnWaveProperties(CWaveBrowser *this)
{
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *p_m_CurrentSelection; // edi
  CWaveFile *v3; // edi
  int m_Size; // eax
  int v5; // esi
  CWaveFile **m_pMemory; // ecx
  int v7; // eax
  CWaveFile **v8; // eax
  CWaveParams params; // [esp+8h] [ebp-A0h] BYREF

  p_m_CurrentSelection = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(
    (CSoundBrowser *)this,
    selected: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&this->m_CurrentSelection);
  if ( this->m_CurrentSelection.m_Size == 1 )
  {
    v3 = *p_m_CurrentSelection->m_Memory.m_pMemory;
    if ( v3 != nullptr )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Wave Properties");
      m_Size = params.items.m_Size;
      v5 = params.items.m_Size;
      if ( params.items.m_Size + 1 > params.items.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&params.items,
          num: params.items.m_Size - params.items.m_Memory.m_nAllocationCount + 1);
        m_Size = params.items.m_Size;
      }
      m_pMemory = params.items.m_Memory.m_pMemory;
      params.items.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      params.items.m_pElements = params.items.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &params.items.m_Memory.m_pMemory[v5 + 1],
          src: &params.items.m_Memory.m_pMemory[v5],
          count: 4 * v7);
        m_pMemory = params.items.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        *v8 = v3;
      WaveProperties(&params);
      CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&params.items);
    }
  }
  else
  {
    Con_Printf(fmt: "Can only apply properties to one item at a time (FOR NOW)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417920
// Name: private: void CWaveBrowser::OnEnableVoiceDucking(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnEnableVoiceDucking(CWaveBrowser *this)
{
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *p_m_CurrentSelection; // edi
  int m_Size; // ebx
  int v4; // esi
  CWaveFile *v5; // edi
  CWorkspaceManager *WorkspaceManager; // eax
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *v7; // [esp+Ch] [ebp-4h]

  p_m_CurrentSelection = &this->m_CurrentSelection;
  v7 = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(
    (CSoundBrowser *)this,
    selected: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&this->m_CurrentSelection);
  m_Size = this->m_CurrentSelection.m_Size;
  if ( m_Size >= 1 )
  {
    MultipleRequestChangeContext();
    v4 = 0;
    while ( 1 )
    {
      v5 = p_m_CurrentSelection->m_Memory.m_pMemory[v4];
      if ( !CWaveFile::GetVoiceDuck(this: v5) )
        CWaveFile::SetVoiceDuck(this: v5, duck: true);
      if ( ++v4 >= m_Size )
        break;
      p_m_CurrentSelection = v7;
    }
    WorkspaceManager = GetWorkspaceManager();
    CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417990
// Name: private: void CWaveBrowser::OnDisableVoiceDucking(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnDisableVoiceDucking(CWaveBrowser *this)
{
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *p_m_CurrentSelection; // edi
  int m_Size; // ebx
  int v4; // esi
  CWaveFile *v5; // edi
  CWorkspaceManager *WorkspaceManager; // eax
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *v7; // [esp+Ch] [ebp-4h]

  p_m_CurrentSelection = &this->m_CurrentSelection;
  v7 = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(
    (CSoundBrowser *)this,
    selected: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&this->m_CurrentSelection);
  m_Size = this->m_CurrentSelection.m_Size;
  if ( m_Size >= 1 )
  {
    MultipleRequestChangeContext();
    v4 = 0;
    while ( 1 )
    {
      v5 = p_m_CurrentSelection->m_Memory.m_pMemory[v4];
      if ( CWaveFile::GetVoiceDuck(this: v5) )
        CWaveFile::SetVoiceDuck(this: v5, duck: false);
      if ( ++v4 >= m_Size )
        break;
      p_m_CurrentSelection = v7;
    }
    WorkspaceManager = GetWorkspaceManager();
    CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417A00
// Name: private: void CWaveBrowser::OnImportSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnImportSentence(CWaveBrowser *this)
{
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *p_m_CurrentSelection; // ebx
  int i; // edi
  CWaveFile *v4; // esi
  CWorkspaceManager *WorkspaceManager; // eax
  char relative[512]; // [esp+8h] [ebp-204h] BYREF
  int count; // [esp+208h] [ebp-4h]

  p_m_CurrentSelection = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(
    (CSoundBrowser *)this,
    selected: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&this->m_CurrentSelection);
  count = this->m_CurrentSelection.m_Size;
  if ( count >= 1 )
  {
    MultipleRequestChangeContext();
    for ( i = 0; i < count; ++i )
    {
      v4 = p_m_CurrentSelection->m_Memory.m_pMemory[i];
      CWaveFile::GetPhonemeExportFile(this: v4, path: relative, maxlen: 512);
      if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: relative, a3: nullptr) )
        CWaveFile::ImportValveDataChunk(this: v4, tempfile: relative);
    }
    WorkspaceManager = GetWorkspaceManager();
    CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417A90
// Name: private: void CWaveBrowser::OnExportSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnExportSentence(CWaveBrowser *this)
{
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *p_m_CurrentSelection; // ebx
  int i; // edi
  CWaveFile *v4; // esi
  char relative[512]; // [esp+8h] [ebp-204h] BYREF
  int count; // [esp+208h] [ebp-4h]

  p_m_CurrentSelection = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(
    (CSoundBrowser *)this,
    selected: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&this->m_CurrentSelection);
  count = this->m_CurrentSelection.m_Size;
  if ( count >= 1 )
  {
    for ( i = 0; i < count; ++i )
    {
      v4 = p_m_CurrentSelection->m_Memory.m_pMemory[i];
      CWaveFile::GetPhonemeExportFile(this: v4, path: relative, maxlen: 512);
      if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: relative, a3: nullptr) )
        filesystem->RemoveFile(this: filesystem, a2: relative, a3: nullptr);
      CWaveFile::ExportValveDataChunk(this: v4, tempfile: relative);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417B30
// Name: private: void CWaveBrowser::OnGetSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnGetSentence(CWaveBrowser *this)
{
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > *p_m_CurrentSelection; // ebx
  int m_Size; // esi
  int v4; // edi
  CWaveFile *v5; // esi
  CWorkspaceManager *WorkspaceManager; // eax

  p_m_CurrentSelection = &this->m_CurrentSelection;
  CSoundBrowser::BuildSelectionList(
    (CSoundBrowser *)this,
    selected: (CUtlVector<CSoundEntry *,CUtlMemory<CSoundEntry *,int> > *)&this->m_CurrentSelection);
  m_Size = this->m_CurrentSelection.m_Size;
  if ( m_Size >= 1 )
  {
    v4 = m_Size - 1;
    do
    {
      v5 = p_m_CurrentSelection->m_Memory.m_pMemory[v4];
      if ( !CWaveFile::HasLoadedSentenceInfo(this: v5) )
        CWaveFile::EnsureSentence(this: v5);
      --v4;
    }
    while ( v4 >= 0 );
    WorkspaceManager = GetWorkspaceManager();
    CWorkspaceManager::RefreshBrowsers(this: WorkspaceManager);
  }
  else
  {
    Con_Printf(fmt: "No selection\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417B90
// Name: public: void CUtlDict<class CWaveFile __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CWaveFile *,int>::RemoveAll(CUtlDict<CWaveFile *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00417C10
// Name: private: void CWaveBrowser::RemoveAllSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::RemoveAllSounds(CWaveBrowser *this)
{
  CWaveBrowser *v1; // ebx
  int v2; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *m_pMemory; // eax
  CWaveFile *elem; // esi
  CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *p_m_Tree; // edi
  int Inorder; // esi
  CWaveFileTree *m_pFileTree; // ebx
  int m_NumElements; // [esp+10h] [ebp-4h]

  v1 = this;
  if ( this->m_AllSounds.m_Elements.m_Tree.m_NumElements > 0 )
  {
    v2 = 0;
    m_NumElements = this->m_AllSounds.m_Elements.m_Tree.m_NumElements;
    do
    {
      m_pMemory = v1->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory;
      elem = m_pMemory[v2].m_Data.elem;
      if ( elem != nullptr )
      {
        CWaveFile::~CWaveFile(this: m_pMemory[v2].m_Data.elem);
        free(pMem: elem);
      }
      ++v2;
      --m_NumElements;
    }
    while ( m_NumElements != 0 );
  }
  p_m_Tree = &v1->m_AllSounds.m_Elements.m_Tree;
  Inorder = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::FirstInorder(this: &v1->m_AllSounds.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    do
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)v1->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key);
      Inorder = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::NextInorder(
                  this: p_m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
    v1 = this;
  }
  CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
  v1->m_Scripts.m_Size = 0;
  v1->m_CurrentSelection.m_Size = 0;
  m_pFileTree = v1->m_pFileTree;
  mxTreeView::removeAll(this: m_pFileTree);
  CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RemoveAll(this: &m_pFileTree->m_Paths);
}

//------------------------------------------------------------------------------
// Address: 0x00417CC0
// Name: public: int CUtlRBTree<struct CWaveFileTree::FileTreePath,int,bool (*)(struct CWaveFileTree::FileTreePath const __near &,struct CWaveFileTree::FileTreePath const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWaveFileTree::FileTreePath,int>,int>>::Insert(struct CWaveFileTree::FileTreePath const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Insert(
        CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl*)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int> > *this,
        const CWaveFileTree::FileTreePath *insert)
{
  int v3; // ebx
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *m_pMemory; // edx
  int result; // eax
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::NewNode(
         this,
         a2: (const char *)this);
  CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  ++this->m_NumElements;
  m_pMemory = this->m_Elements.m_pMemory;
  result = v3;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-16 )
    qmemcpy((void *)&m_pMemory[v3].m_Data, insert, sizeof(m_pMemory[v3].m_Data));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417D30
// Name: public: virtual void CWaveBrowser::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CWaveBrowser::OnDelete(CWaveBrowser *this)
{
  CWaveBrowser::RemoveAllSounds(this);
}

//------------------------------------------------------------------------------
// Address: 0x00417D40
// Name: private: void CWaveBrowser::PopulateTree(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::PopulateTree(CWaveBrowser *this, const char *subdirectory, bool textsearch)
{
  int v3; // ebx
  const char *v5; // esi
  const char *v6; // esi
  const char *v7; // eax
  int v8; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *m_pMemory; // ecx
  int v10; // edx
  unsigned int v11; // esi
  int v12; // edx
  CWaveFile **p_m_Data; // esi
  CWaveList *m_pListView; // ecx
  int NextSelectedItem; // eax
  const char *Label; // eax
  int v17; // esi
  int v18; // eax
  CWaveFile *m_Data; // esi
  const char *v20; // eax
  CWaveList *v21; // ecx
  int v22; // ebx
  int v23; // eax
  bool v24; // zf
  const char *v25; // eax
  int v26; // [esp-4h] [ebp-24Ch]
  const char *SentenceText; // [esp-4h] [ebp-24Ch]
  char prevSelectedName[512]; // [esp+Ch] [ebp-23Ch] BYREF
  CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > m_Sorted; // [esp+20Ch] [ebp-3Ch] BYREF
  int parent; // [esp+230h] [ebp-18h] BYREF
  int len; // [esp+234h] [ebp-14h]
  const char *texttofind; // [esp+238h] [ebp-10h]
  CWaveFile *wav; // [esp+23Ch] [ebp-Ch] BYREF
  const char *name; // [esp+240h] [ebp-8h]
  bool leftchild; // [esp+247h] [ebp-1h] BYREF
  int selectedSlot; // [esp+250h] [ebp+8h]
  int i; // [esp+254h] [ebp+Ch]

  v3 = 0;
  m_Sorted.m_LessFunc = (bool (__cdecl *)(CWaveFile *const *, CWaveFile *const *))NameLessFunc;
  memset(&m_Sorted.m_Elements, 0, sizeof(m_Sorted.m_Elements));
  m_Sorted.m_Root = -1;
  m_Sorted.m_NumElements = 0;
  m_Sorted.m_FirstFree = -1;
  m_Sorted.m_LastAlloc.index = -1;
  m_Sorted.m_pElements = nullptr;
  texttofind = nullptr;
  if ( textsearch )
  {
    v5 = nullptr;
    subdirectory = nullptr;
    texttofind = this->m_pOptions->m_szSearchString;
  }
  else
  {
    v5 = subdirectory;
  }
  len = 0;
  if ( v5 != nullptr )
  {
    len = _V_strlen(str: v5);
    _V_strstr(s1: v5, search: "/");
  }
  if ( this->m_AllSounds.m_Elements.m_Tree.m_NumElements > 0 )
  {
    name = (const char *)this->m_AllSounds.m_Elements.m_Tree.m_NumElements;
    do
    {
      wav = this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
      v6 = (const char *)wav->GetName(this: wav);
      if ( subdirectory == nullptr
        || (v26 = len, v7 = (const char *)wav->GetName(this: wav), V_strnicmp(s1: subdirectory, s2: v7, n: v26) == 0) )
      {
        if ( !textsearch || texttofind == nullptr || V_stristr(pStr: v6, pSearch: texttofind) != nullptr )
        {
          parent = -1;
          leftchild = false;
          CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::FindInsertionPosition(
            this: &m_Sorted,
            insert: &wav,
            &parent,
            &leftchild);
          v8 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
                 this: (CUtlRBTree<CSoundEntry *,int,bool (__cdecl*)(CSoundEntry * const &,CSoundEntry * const &),CUtlMemory<UtlRBTreeNode_t<CSoundEntry *,int>,int> > *)&m_Sorted,
                 a2: (const char *)this);
          m_pMemory = m_Sorted.m_Elements.m_pMemory;
          v10 = parent;
          v11 = v8;
          m_Sorted.m_Elements.m_pMemory[v11].m_Parent = parent;
          m_pMemory[v11].m_Right = -1;
          m_pMemory[v11].m_Left = -1;
          m_pMemory[v11].m_Tag = 0;
          if ( v10 == -1 )
          {
            m_Sorted.m_Root = v8;
          }
          else
          {
            v12 = v10;
            if ( leftchild )
              m_pMemory[v12].m_Left = v8;
            else
              m_pMemory[v12].m_Right = v8;
          }
          CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::InsertRebalance(
            this: &m_Sorted,
            elem: v8);
          ++m_Sorted.m_NumElements;
          p_m_Data = &m_Sorted.m_Elements.m_pMemory[v11].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = wav;
        }
      }
      ++v3;
      --name;
    }
    while ( name != nullptr );
  }
  m_pListView = this->m_pListView;
  prevSelectedName[0] = 0;
  if ( mxListView::getNumSelected(this: m_pListView) == 1 )
  {
    NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: 0);
    if ( NextSelectedItem >= 0 )
    {
      Label = mxListView::getLabel(this: this->m_pListView, item: NextSelectedItem, column: 0);
      _V_strcpy(dest: prevSelectedName, src: Label);
    }
  }
  mxListView::removeAll(this: this->m_pListView);
  mxListView::setDrawingEnabled(this: this->m_pListView, draw: false);
  v17 = -1;
  selectedSlot = -1;
  v18 = CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::FirstInorder(this: &m_Sorted);
  i = v18;
  if ( v18 != -1 )
  {
    while ( 1 )
    {
      m_Data = m_Sorted.m_Elements.m_pMemory[v18].m_Data;
      v20 = (const char *)m_Data->GetName(this: m_Data);
      v21 = this->m_pListView;
      name = v20;
      v22 = mxListView::add(this: v21, item: v20);
      if ( _V_stricmp(s1: prevSelectedName, s2: name) == 0 )
        selectedSlot = v22;
      v23 = m_Data->GetIconIndex(this: m_Data);
      mxListView::setImage(this: this->m_pListView, item: v22, column: 0, imagenormal: v23);
      mxListView::setUserData(this: this->m_pListView, item: v22, column: 0, userData: m_Data);
      if ( CWaveFile::HasLoadedSentenceInfo(this: m_Data) )
      {
        v24 = !CWaveFile::GetVoiceDuck(this: m_Data);
        v25 = "yes";
        if ( v24 )
          v25 = "no";
        mxListView::setLabel(this: this->m_pListView, item: v22, column: 1, label: v25);
        SentenceText = CWaveFile::GetSentenceText(this: m_Data);
        mxListView::setLabel(this: this->m_pListView, item: v22, column: 2, label: SentenceText);
      }
      else
      {
        mxListView::setLabel(this: this->m_pListView, item: v22, column: 2, label: "(loading...)");
      }
      i = CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::NextInorder(
            this: &m_Sorted,
            i);
      if ( i == -1 )
        break;
      v18 = i;
    }
    v17 = selectedSlot;
  }
  mxListView::setDrawingEnabled(this: this->m_pListView, draw: true);
  if ( v17 != -1 )
  {
    mxListView::setSelected(this: this->m_pListView, item: v17, b: true);
    mxListView::scrollToItem(this: this->m_pListView, item: v17);
  }
  CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RemoveAll(this: &m_Sorted);
  if ( m_Sorted.m_Elements.m_nGrowSize >= 0 && m_Sorted.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Sorted.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00418040
// Name: public: void CWaveBrowser::RepopulateTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::RepopulateTree(CWaveBrowser *this)
{
  CWaveFileTree *m_pFileTree; // esi
  void **SelectedItem; // eax
  int UserData; // eax

  m_pFileTree = this->m_pFileTree;
  SelectedItem = mxTreeView::getSelectedItem(this: m_pFileTree);
  UserData = (int)mxTreeView::getUserData(this: m_pFileTree, item: SelectedItem);
  if ( UserData < 0 || (unsigned int)UserData >= m_pFileTree->m_Paths.m_NumElements )
    CWaveBrowser::PopulateTree(this, subdirectory: &WindowName, textsearch: false);
  else
    CWaveBrowser::PopulateTree(
      this,
      subdirectory: m_pFileTree->m_Paths.m_Elements.m_pMemory[UserData].m_Data.path,
      textsearch: false);
}

//------------------------------------------------------------------------------
// Address: 0x00418090
// Name: public: void CWaveBrowser::JumpToItem(class CWaveFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::JumpToItem(CWaveBrowser *this, CWaveFile *wav)
{
  const char *v3; // eax
  int v4; // eax
  int v5; // esi
  CWaveFile *UserData; // ebx
  const char *v7; // eax
  const char *v8; // [esp-8h] [ebp-214h]
  char filename[256]; // [esp+8h] [ebp-204h] BYREF
  char path[256]; // [esp+108h] [ebp-104h] BYREF
  int c; // [esp+208h] [ebp-4h]

  v3 = CWaveFile::GetFileName(this: wav);
  SplitFileName(in: v3, path, maxpath: 256, filename, maxfilename: 256);
  v4 = _V_strlen(str: "/sound/");
  CWaveBrowser::PopulateTree(this, subdirectory: &path[v4], textsearch: false);
  v5 = 0;
  c = mxListView::getItemCount(this: this->m_pListView);
  if ( c > 0 )
  {
    while ( 1 )
    {
      UserData = (CWaveFile *)mxListView::getUserData(this: this->m_pListView, item: v5, column: 0);
      v8 = CWaveFile::GetFileName(this: wav);
      v7 = CWaveFile::GetFileName(this: UserData);
      if ( _V_stricmp(s1: v7, s2: v8) == 0 )
        break;
      if ( ++v5 >= c )
        return;
    }
    if ( v5 < c )
      mxListView::scrollToItem(this: this->m_pListView, item: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418150
// Name: public: class CWaveFile __near * CWaveBrowser::FindEntry(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CWaveFile *__thiscall CWaveBrowser::FindEntry(CWaveBrowser *this, char *wavname, bool jump)
{
  char *v4; // eax
  int v5; // eax
  int v6; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *m_pMemory; // eax
  CWaveFile *elem; // edi
  CUtlMap<char const *,CWaveFile *,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  v4 = PSkipSoundChars(pch: wavname);
  if ( v4 == nullptr )
    return nullptr;
  search.key = v4;
  v5 = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::Find(
         this: &this->m_AllSounds.m_Elements.m_Tree,
         &search);
  if ( v5 == -1 )
    return nullptr;
  v6 = v5;
  m_pMemory = this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory;
  elem = m_pMemory[v6].m_Data.elem;
  if ( jump )
    CWaveBrowser::JumpToItem(this, wav: m_pMemory[v6].m_Data.elem);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004181B0
// Name: public: void CWaveOptionsWindow::OnSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveOptionsWindow::OnSearch(CWaveOptionsWindow *this)
{
  const char *v2; // eax
  CInputParams params; // [esp+8h] [ebp-58Ch] BYREF

  memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
  V_snprintf(pDest: params.m_szDialogTitle, maxLen: 128, pFormat: "Search");
  _V_strcpy(dest: params.m_szPrompt, src: "Find:");
  _V_strcpy(dest: params.m_szInputText, src: this->m_szSearchString);
  if ( InputProperties(&params) != 0 )
  {
    _V_strcpy(dest: this->m_szSearchString, src: params.m_szInputText);
    v2 = va(fmt: "Search:  '%s'", this->m_szSearchString);
    mxWidget::setLabel(this: this->m_pSearchString, format: v2);
    CWaveBrowser::PopulateTree(
      this: this->m_pBrowser,
      subdirectory: this->m_pBrowser->m_pOptions->m_szSearchString,
      textsearch: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418260
// Name: public: virtual int CWaveBrowser::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveBrowser::handleEvent(CWaveBrowser *this, mxEvent *event)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int result; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  CWorkspaceManager *WorkspaceManager; // eax
  int action; // eax
  int v12; // eax
  CWaveFileTree::FileTreePath *SelectedPath; // eax
  int flags; // eax
  int NextSelectedItem; // eax
  CWaveFile *UserData; // eax
  int v17; // [esp-4h] [ebp-Ch]

  v3 = event->event;
  v4 = 0;
  if ( v3 != 0 )
  {
    v5 = v3 - 1;
    if ( v5 == 0 )
    {
      v7 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pOptions, x: 0, y: 0, w: v7, h: 20);
      v8 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pFileTree, x: 0, y: 20, w: 175, h: v8 - 20);
      v17 = mxWidget::h2(this) - 20;
      v9 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pListView, x: 175, y: 20, w: v9 - 175, h: v17);
      WorkspaceManager = GetWorkspaceManager();
      CWorkspaceManager::SetWorkspaceDirty(this: WorkspaceManager);
      return 1;
    }
    if ( v5 == 18 )
      return 1;
    return v4;
  }
  action = event->action;
  v4 = 1;
  if ( action <= 1000 )
  {
    if ( action == 1000 )
    {
      CWaveBrowser::OnPlay(this);
      return 1;
    }
    v12 = action - 101;
    if ( v12 != 0 )
    {
      if ( v12 == 1 )
      {
        SelectedPath = CWaveFileTree::GetSelectedPath(this: this->m_pFileTree);
        CWaveBrowser::PopulateTree(this, subdirectory: SelectedPath->path, textsearch: false);
        return 1;
      }
      return 0;
    }
    else
    {
      flags = event->flags;
      if ( flags == 1 )
      {
        CWaveBrowser::ShowContextMenu(this);
        return 1;
      }
      if ( flags == 2 && mxListView::getNumSelected(this: this->m_pListView) == 1 )
      {
        NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: -1);
        if ( NextSelectedItem >= 0 )
        {
          UserData = (CWaveFile *)mxListView::getUserData(this: this->m_pListView, item: NextSelectedItem, column: 0);
          if ( UserData != nullptr )
          {
            CWaveFile::Play(this: UserData);
            return 1;
          }
        }
      }
    }
    return v4;
  }
  switch ( action )
  {
    case 1001:
      CWaveBrowser::OnCheckout(this);
      result = 1;
      break;
    case 1002:
      CWaveBrowser::OnCheckin(this);
      result = 1;
      break;
    case 1003:
      CWaveBrowser::OnWaveProperties(this);
      result = 1;
      break;
    case 1004:
      CWaveBrowser::OnEnableVoiceDucking(this);
      result = 1;
      break;
    case 1005:
      CWaveBrowser::OnDisableVoiceDucking(this);
      result = 1;
      break;
    case 1006:
      CWaveBrowser::OnExportSentence(this);
      result = 1;
      break;
    case 1007:
      CWaveBrowser::OnImportSentence(this);
      result = 1;
      break;
    case 1008:
      CWaveBrowser::OnGetSentence(this);
      result = 1;
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418480
// Name: public: virtual int CWaveOptionsWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveOptionsWindow::handleEvent(CWaveOptionsWindow *this, mxEvent *event)
{
  int v3; // ecx
  int result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax

  v3 = event->event;
  result = 0;
  if ( v3 != 0 )
  {
    if ( v3 == 1 )
    {
      v5 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pPlay, x: 1, y: 1, w: 120, h: v5 - 2);
      v6 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pStopSounds, x: 131, y: 1, w: 120, h: v6 - 2);
      v7 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pSearch, x: 261, y: 1, w: 120, h: v7 - 2);
      v8 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pSearchString, x: 391, y: 2, w: 240, h: v8 - 4);
      return 1;
    }
  }
  else
  {
    switch ( event->action )
    {
      case 0x3E8:
        CWaveBrowser::OnPlay(this: this->m_pBrowser);
        return 1;
      case 0x3E9:
        sound->StopAll(this: sound);
        return 1;
      case 0x3EA:
        CWaveOptionsWindow::OnSearch(this);
        return 1;
      default:
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418570
// Name: private: bool CWaveBrowser::LoadWaveFilesInDirectory(class CUtlDict<class CWaveFile __near *,int> __near &,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWaveBrowser::LoadWaveFilesInDirectory(
        CWaveBrowser *this,
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *soundlist,
        const char *pDirectoryName,
        int nDirectoryNameLen)
{
  int v4; // edi
  void *v5; // esp
  const char *v7; // ebx
  int v8; // esi
  void *v9; // esp
  CWaveFile *v10; // eax
  CWaveFile *v11; // ebx
  char *v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v16; // ecx
  int v17; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v19; // eax
  CUtlMap<char const *,CWaveFile *,int>::Node_t *p_m_Data; // esi
  CWaveFileTree *m_pFileTree; // esi
  char v22; // [esp+0h] [ebp-128h] BYREF
  _BYTE v23[3]; // [esp+1h] [ebp-127h] BYREF
  CWaveFileTree::FileTreePath dest; // [esp+Ch] [ebp-11Ch] BYREF
  CWaveBrowser *v25; // [esp+110h] [ebp-18h]
  CUtlMap<char const *,CWaveFile *,int>::Node_t insert; // [esp+114h] [ebp-14h] BYREF
  int parent; // [esp+11Ch] [ebp-Ch] BYREF
  int v28; // [esp+120h] [ebp-8h] BYREF
  bool leftchild; // [esp+127h] [ebp-1h] BYREF

  v4 = nDirectoryNameLen;
  v25 = this;
  v5 = alloca(nDirectoryNameLen + 7);
  V_snprintf(pDest: &v22, maxLen: nDirectoryNameLen + 7, pFormat: "%s/*.wav", pDirectoryName);
  if ( filesystem == nullptr )
    return 0;
  v7 = filesystem->FindFirst(this: filesystem, a2: &v22, a3: &v28);
  if ( v7 != nullptr )
  {
    while ( 1 )
    {
      if ( !filesystem->FindIsDirectory(this: filesystem, a2: v28) )
      {
        v8 = _V_strlen(str: v7) + v4 + 2;
        v9 = alloca(v8);
        V_snprintf(pDest: &v22, maxLen: v8, pFormat: "%s/%s", pDirectoryName + 6, v7);
        V_strnlwr(s: &v22, count: v8);
        v10 = (CWaveFile *)operator new(nSize: 0x168u);
        v11 = v10 != nullptr ? CWaveFile::CWaveFile(this: v10, vcd: nullptr, se: nullptr, filename: &v22) : nullptr;
        if ( &v22 != nullptr
          && (v12 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: &v23[strlen(&v22)] - v23 + 1)) != nullptr )
        {
          strcpy(v12, &v22);
        }
        else
        {
          v12 = nullptr;
        }
        insert.key = v12;
        insert.elem = v11;
        parent = -1;
        leftchild = false;
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::FindInsertionPosition(
          this: (CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *)soundlist,
          &insert,
          &parent,
          &leftchild);
        v13 = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::NewNode(this: soundlist);
        v14 = parent;
        v15 = v13;
        v16 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)&soundlist->m_Elements.m_pMemory[v13];
        v16->m_Parent = parent;
        v16->m_Right = -1;
        v16->m_Left = -1;
        v16->m_Tag = 0;
        if ( v14 == -1 )
        {
          soundlist->m_Root = v13;
        }
        else
        {
          v17 = v14;
          m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)soundlist->m_Elements.m_pMemory;
          if ( leftchild )
            m_pMemory[v17].m_Left = v13;
          else
            m_pMemory[v17].m_Right = v13;
        }
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::InsertRebalance(
          this: (CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *)soundlist,
          elem: v13);
        v19 = (UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *)soundlist->m_Elements.m_pMemory;
        ++soundlist->m_NumElements;
        p_m_Data = &v19[v15].m_Data;
        if ( p_m_Data != nullptr )
          *p_m_Data = insert;
      }
      v7 = filesystem->FindNext(this: filesystem, a2: v28);
      if ( v7 == nullptr )
        break;
      v4 = nDirectoryNameLen;
    }
  }
  m_pFileTree = v25->m_pFileTree;
  _V_strcpy(dest: dest.path, src: pDirectoryName + 6);
  if ( CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Find(
         this: &m_pFileTree->m_Paths,
         search: &dest) == -1 )
    CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Insert(
      this: &m_pFileTree->m_Paths,
      insert: &dest);
  filesystem->FindClose(this: filesystem, a2: v28);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004187A0
// Name: private: bool CWaveBrowser::InitDirectoryRecursive(class CUtlDict<class CWaveFile __near *,int> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWaveBrowser::InitDirectoryRecursive(
        CWaveBrowser *this,
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *soundlist,
        const char *pDirectoryName)
{
  const char *v3; // esi
  int v5; // edi
  void *v7; // esp
  char *v8; // edi
  char v9; // al
  const char *(__thiscall *FindFirst)(IFileSystem *, const char *, int *); // edx
  unsigned int v11; // edi
  const char *i; // esi
  char v13; // al
  void *v14; // esp
  unsigned int v15; // eax
  char *v16; // edi
  char v17; // cl
  char v18; // [esp-1h] [ebp-19h] BYREF
  char v19[12]; // [esp+0h] [ebp-18h] BYREF
  CWaveBrowser *v20; // [esp+Ch] [ebp-Ch]
  char *pWildCard; // [esp+10h] [ebp-8h]
  int nDirectoryNameLen; // [esp+14h] [ebp-4h]

  v3 = pDirectoryName;
  v20 = this;
  v5 = _V_strlen(str: pDirectoryName);
  nDirectoryNameLen = v5;
  if ( CWaveBrowser::LoadWaveFilesInDirectory(this, soundlist, pDirectoryName: v3, nDirectoryNameLen: v5) == 0 )
    return 0;
  v7 = alloca(v5 + 4);
  pWildCard = v19;
  strcpy(v19, v3);
  v8 = &v18;
  do
    v9 = *++v8;
  while ( v9 != 0 );
  strcpy(v8, "/*.");
  FindFirst = filesystem->FindFirst;
  v11 = ++nDirectoryNameLen;
  for ( i = FindFirst(this: filesystem, a2: v19, a3: (int *)&pDirectoryName);
        i != nullptr;
        i = filesystem->FindNext(this: filesystem, a2: pDirectoryName) )
  {
    if ( *i == 46 )
    {
      v13 = i[1];
      if ( v13 == 46 || v13 == 0 )
        continue;
    }
    if ( filesystem->FindIsDirectory(this: filesystem, a2: (int)pDirectoryName) )
    {
      v14 = alloca(_V_strlen(str: i) + v11 + 1);
      memcpy(dst: (unsigned __int8 *)v19, src: (unsigned __int8 *)pWildCard, count: v11);
      v19[v11] = 0;
      v15 = strlen(i) + 1;
      v16 = &v18;
      do
        v17 = *++v16;
      while ( v17 != 0 );
      qmemcpy(v16, i, v15);
      if ( !CWaveBrowser::InitDirectoryRecursive(this: v20, (CUtlDict<CWaveFile *,int> *)soundlist, pDirectoryName: v19) )
        return 0;
      v11 = nDirectoryNameLen;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00418900
// Name: private: void CWaveBrowser::LoadAllSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::LoadAllSounds(CWaveBrowser *this)
{
  int m_NumElements; // eax
  int m_Size; // ecx
  CWaveFile *elem; // ebx
  int v5; // esi
  CWaveFile **v6; // eax
  CWaveFileTree *m_pFileTree; // edi
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *j; // esi
  void **FirstChild; // eax
  CWaveFile **m_pMemory; // eax
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > list; // [esp+Ch] [ebp-1Ch] BYREF
  int i; // [esp+20h] [ebp-8h]
  unsigned int v13; // [esp+24h] [ebp-4h]

  CWaveBrowser::RemoveAllSounds(this);
  CWaveBrowser::InitDirectoryRecursive(
    this,
    soundlist: (CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *)&this->m_AllSounds,
    pDirectoryName: "sound");
  m_NumElements = this->m_AllSounds.m_Elements.m_Tree.m_NumElements;
  m_Size = 0;
  memset(&list, 0, sizeof(list));
  if ( m_NumElements > 0 )
  {
    v13 = 0;
    for ( i = m_NumElements; i != 0; --i )
    {
      elem = this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory[v13 / 0x18].m_Data.elem;
      v5 = m_Size;
      if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&list,
          num: m_Size - list.m_Memory.m_nAllocationCount + 1);
        m_Size = list.m_Size;
      }
      list.m_Size = ++m_Size;
      list.m_pElements = list.m_Memory.m_pMemory;
      if ( m_Size - v5 - 1 > 0 )
      {
        _V_memmove(
          dest: &list.m_Memory.m_pMemory[v5 + 1],
          src: &list.m_Memory.m_pMemory[v5],
          count: 4 * (m_Size - v5 - 1));
        m_Size = list.m_Size;
      }
      v6 = &list.m_Memory.m_pMemory[v5];
      if ( v6 != nullptr )
      {
        *v6 = elem;
        m_Size = list.m_Size;
      }
      v13 += 24;
    }
  }
  fileloader->AddWaveFilesToThread(this: fileloader, a2: &list);
  m_pFileTree = this->m_pFileTree;
  for ( j = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::FirstInorder(this: &m_pFileTree->m_Paths);
        j != (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        j = CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::NextInorder(
              this: &m_pFileTree->m_Paths,
              i: (int)j) )
  {
    CWaveFileTree::_PopulateTree(
      this: m_pFileTree,
      pathId: j,
      path: (void **)&m_pFileTree->m_Paths.m_Elements.m_pMemory[(_DWORD)j].m_Data);
  }
  FirstChild = mxTreeView::getFirstChild(this: m_pFileTree, item: nullptr);
  mxTreeView::setOpen(this: m_pFileTree, item: FirstChild, b: true);
  m_pMemory = list.m_Memory.m_pMemory;
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = m_pMemory;
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00418A60
// Name: public: CWaveBrowser::CWaveBrowser(class mxWindow __near *,class CWorkspaceManager __near *,int)
// Source: json
//------------------------------------------------------------------------------
CWaveBrowser *__thiscall CWaveBrowser::CWaveBrowser(
        CWaveBrowser *this,
        mxWindow *parent,
        CWorkspaceManager *manager,
        int id)
{
  mxListView *v5; // eax
  CWaveList *v6; // edi
  CWaveOptionsWindow *v7; // eax
  CWaveOptionsWindow *v8; // eax
  mxTreeView *v9; // eax
  CWaveFileTree *v10; // edi
  CWorkspaceManager *WorkspaceManager; // eax
  _IMAGELIST *ImageList; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: "Wave Browser", style: id);
  this->__vftable = (CWaveBrowser_vtbl *)&CWaveBrowser::`vftable';
  this->m_AllSounds.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_AllSounds.m_Elements.m_Tree.m_Root = -1;
  this->m_AllSounds.m_Elements.m_Tree.m_NumElements = 0;
  this->m_AllSounds.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_AllSounds.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_AllSounds.m_Elements.m_Tree.m_pElements = this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_AllSounds.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_AllSounds.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_ScriptTable, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_Scripts.m_Memory.m_pMemory = nullptr;
  this->m_Scripts.m_Memory.m_nAllocationCount = 0;
  this->m_Scripts.m_Memory.m_nGrowSize = 0;
  this->m_Scripts.m_Size = 0;
  this->m_Scripts.m_pElements = nullptr;
  this->m_CurrentSelection.m_Memory.m_pMemory = nullptr;
  this->m_CurrentSelection.m_Memory.m_nAllocationCount = 0;
  this->m_CurrentSelection.m_Memory.m_nGrowSize = 0;
  this->m_CurrentSelection.m_Size = 0;
  this->m_CurrentSelection.m_pElements = nullptr;
  this->m_pManager = manager;
  SceneManager_MakeToolWindow(w: this, smallcaption: false);
  v5 = (mxListView *)operator new(nSize: 0xCu);
  v6 = (CWaveList *)v5;
  if ( v5 != nullptr )
  {
    mxListView::mxListView(this: v5, parent: this, x: 0, y: 0, w: 0, h: 0, id: 101);
    v6->__vftable = (CWaveList_vtbl *)&CWaveList::`vftable';
    mxListView::insertTextColumn(this: v6, column: 0, width: 300, label: "WAV");
    mxListView::insertTextColumn(this: v6, column: 1, width: 50, label: "Ducked");
    mxListView::insertTextColumn(this: v6, column: 2, width: 300, label: "Sentence Text");
  }
  else
  {
    v6 = nullptr;
  }
  this->m_pListView = v6;
  v7 = (CWaveOptionsWindow *)operator new(nSize: 0x120u);
  if ( v7 != nullptr )
    v8 = CWaveOptionsWindow::CWaveOptionsWindow(this: v7, browser: this);
  else
    v8 = nullptr;
  this->m_pOptions = v8;
  v9 = (mxTreeView *)operator new(nSize: 0x30u);
  v10 = (CWaveFileTree *)v9;
  if ( v9 != nullptr )
  {
    mxTreeView::mxTreeView(this: v9, parent: this, x: 0, y: 0, w: 0, h: 0, id: 102);
    v10->__vftable = (CWaveFileTree_vtbl *)&CWaveFileTree::`vftable';
    v10->m_Paths.m_LessFunc = CWaveFileTree::FileTreeLessFunc;
    v10->m_Paths.m_Elements.m_pMemory = nullptr;
    v10->m_Paths.m_Elements.m_nAllocationCount = 0;
    v10->m_Paths.m_Elements.m_nGrowSize = 0;
    v10->m_Paths.m_Root = -1;
    v10->m_Paths.m_NumElements = 0;
    v10->m_Paths.m_FirstFree = -1;
    v10->m_Paths.m_LastAlloc.index = -1;
    v10->m_Paths.m_pElements = v10->m_Paths.m_Elements.m_pMemory;
  }
  else
  {
    v10 = nullptr;
  }
  this->m_pFileTree = v10;
  WorkspaceManager = GetWorkspaceManager();
  ImageList = CWorkspaceManager::CreateImageList(this: WorkspaceManager);
  mxListView::setImageList(this: this->m_pListView, himagelist: ImageList);
  CWaveBrowser::LoadAllSounds(this);
  CWaveBrowser::PopulateTree(this, subdirectory: nullptr, textsearch: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041E1F0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E2E0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode@<eax>(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        const char *a2@<edi>)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v6; // cx
  unsigned __int16 v7; // di
  int v8; // eax
  unsigned __int16 v9; // cx
  unsigned __int16 v10; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v13; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v6 = -1;
      else
        v6 = index + 1;
    }
    v7 = v6;
    if ( v6 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v8 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v8 )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v10 = (v8 > 0) - 1;
      }
      else
      {
        v9 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v9 + 1) >= v8 )
          v10 = -1;
        else
          v10 = v9 + 1;
      }
      v7 = v10;
      if ( v10 >= v8 )
        _Error(this: (ISceneTokenProcessor *)&stru_44E324, a2);
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v7;
    this->m_pElements = m_pMemory;
    return v7;
  }
  else
  {
    v13 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v13[m_FirstFree].m_Right;
    this->m_pElements = v13;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E3E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x0041E4D0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x0041E820
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *search)
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
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0041E9E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
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
      v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_474D10 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_474D10 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_474D10 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_474D10 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_474D10 = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_474D10 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_474D10 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_474D10 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_474D10 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
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
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_474D10 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_474D10 = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_474D10 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_474D10 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x0041F020
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F520
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __userpurge CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert@<ax>(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        const char *a2@<edi>,
        const CUtlMap<char const *,int,unsigned short>::Node_t *insert)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
         this,
         a2);
  v5 = v4;
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)-8 )
    m_pMemory[v5].m_Data = *insert;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00420770
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
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( i == -1 )
    return dword_48D318;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x004207D0
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
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( i == -1 )
    return dword_48D314;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00420830
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( m_Parent == -1 )
    return dword_48D314 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x004208E0
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
        dword_48D314 = -1;
        dword_48D318 = -1;
        dword_48D31C = 1;
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
        dword_48D314 = -1;
        dword_48D318 = -1;
        dword_48D31C = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004209D0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int,class CUtlMap<char const __near *,class CWaveFile __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CWaveFile __near *,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::NewNode@<eax>(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this@<ecx>,
        const char *a2@<edi>)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v12; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v6 = index + 1;
      if ( v6 < 0 || v6 >= m_nAllocationCount )
        v6 = -1;
    }
    v7 = v6;
    if ( v6 < 0 || v6 >= m_nAllocationCount )
    {
      CUtlMemory<fileList_t,int>::Grow(this: &this->m_Elements, num: 1);
      v8 = this->m_LastAlloc.index;
      if ( v8 < 0 || (v9 = this->m_Elements.m_nAllocationCount, v8 >= v9) )
      {
        v9 = this->m_Elements.m_nAllocationCount;
        v10 = (v9 > 0) - 1;
      }
      else
      {
        v10 = v8 + 1;
        if ( v10 < 0 || v10 >= v9 )
          v10 = -1;
      }
      v7 = v10;
      if ( v10 < 0 || v10 >= v9 )
        _Error(this: (ISceneTokenProcessor *)&stru_44E324, a2);
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v7;
    this->m_pElements = m_pMemory;
    return v7;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[result].m_Right;
    this->m_pElements = v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420A90
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00420B40
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_48D314 = -1;
      dword_48D318 = -1;
      dword_48D31C = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00420CF0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_48D314 = -1;
    dword_48D318 = -1;
    dword_48D31C = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
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
  else if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00421040
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
        dword_48D314 = -1;
        dword_48D318 = -1;
        dword_48D31C = 1;
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
        dword_48D314 = -1;
        dword_48D318 = -1;
        dword_48D31C = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00421130
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,int>::Node_t,int,class CUtlMap<char const __near *,int,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v24; // eax

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
        dword_48D314 = -1;
        dword_48D318 = -1;
        dword_48D31C = 1;
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
        dword_48D314 = -1;
        dword_48D318 = -1;
        dword_48D31C = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D314 = -1;
        dword_48D318 = -1;
        dword_48D31C = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_48D314 = -1;
        dword_48D318 = -1;
        dword_48D31C = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48D314 = -1;
          dword_48D318 = -1;
          dword_48D31C = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48D314 = -1;
          dword_48D318 = -1;
          dword_48D31C = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48D314 = -1;
            dword_48D318 = -1;
            dword_48D31C = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_48D314 = -1;
            dword_48D318 = -1;
            dword_48D31C = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48D314 = -1;
          dword_48D318 = -1;
          dword_48D31C = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_48D314 = -1;
          dword_48D318 = -1;
          dword_48D31C = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
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
        if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateRight(
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
            dword_48D314 = -1;
            dword_48D318 = -1;
            dword_48D31C = 1;
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
            dword_48D314 = -1;
            dword_48D318 = -1;
            dword_48D31C = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RotateLeft(
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
// Address: 0x00425730
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00425790
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425860
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_48D338 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_48D338;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x004258D0
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_48D338 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00425930
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_48D338 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004259A0
// Name: protected: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::FindInsertionPosition(class CChoreoEvent __near * const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        CChoreoEvent *const *insert,
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
      if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425A90
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode@<eax>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this@<ecx>,
        const char *a2@<edi>)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v6; // cx
  unsigned __int16 v7; // di
  int v8; // eax
  unsigned __int16 v9; // cx
  unsigned __int16 v10; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v13; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v6 = -1;
      else
        v6 = index + 1;
    }
    v7 = v6;
    if ( v6 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>::Grow(this: &this->m_Elements, num: 1);
      v8 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v8 )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v10 = (v8 > 0) - 1;
      }
      else
      {
        v9 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v9 + 1) >= v8 )
          v10 = -1;
        else
          v10 = v9 + 1;
      }
      v7 = v10;
      if ( v10 >= v8 )
        _Error(this: (ISceneTokenProcessor *)&stru_44E324, a2);
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v7;
    this->m_pElements = m_pMemory;
    return v7;
  }
  else
  {
    v13 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v13[m_FirstFree].m_Right;
    this->m_pElements = v13;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425B90
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *__thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory;
  else
    return (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00425BF0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,EventGroup,int>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425CE0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
bool (__cdecl *__thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this))(const char *const *, const char *const *)
{
  int m_Root; // ebx
  bool (__cdecl *result)(const char *const *, const char *const *); // eax
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v3; // edx

  m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  result = (bool (__cdecl *)(const char *const *, const char *const *))this->m_Root;
  while ( 1 )
  {
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    v3 = result == (bool (__cdecl *)(const char *const *, const char *const *))-1
       ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
    if ( v3->m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
      break;
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( result == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
      result = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc;
    else
      result = (bool (__cdecl *)(const char *const *, const char *const *))this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425D80
// Name: protected: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00425E80
// Name: protected: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00425F80
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory == (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00426030
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x004260E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v4; // eax
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v6; // eax
  int v7; // edx
  int v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v9; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v10; // eax
  int v11; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v8 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    v8 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
       | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v9 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v9 = &this->m_Elements.m_pMemory[m_Right];
  if ( v9->m_Left != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v8 | 1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( m_Right == -1 )
      v10 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v10 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v10->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
  {
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v11 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v11].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
    v7 = elem;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004262B0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v4; // eax
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v6; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v7; // eax

  m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[(_DWORD)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RightChild(
                                         this,
                                         i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00426430
// Name: public: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x004264F0
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_48D338 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_48D338 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004265C0
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
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
  if ( CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
         this,
         i) == 0xFFFF )
  {
    LOWORD(result) = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                       this,
                       i);
    v7 = `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    for ( result = (unsigned __int16)result; ; result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Parent )
    {
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      v10 = (_WORD)v9 == 0xFFFF
          ? &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v9];
      if ( *((_WORD *)v10 + 1) != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
    }
  }
  else
  {
    LOWORD(result) = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RightChild(
                       this,
                       i);
    v4 = `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    result = (unsigned __int16)result;
    while ( 1 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( *(_WORD *)v6 == 0xFFFF )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)result == 0xFFFF )
        result = (unsigned __int16)`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004267C0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,EventGroup,int>::Node_t *search)
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
      if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x004268B0
// Name: protected: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
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
    v4 = `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_48D338 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_48D338 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_48D338 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_48D338 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_48D338 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_48D338 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48D338 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48D338 = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateRight(
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
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48D338 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48D338 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48D338 = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x00426E60
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *__thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v3; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *result; // eax
  int m_Root; // edx
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v6; // ecx
  int m_Parent; // esi
  int v8; // [esp-4h] [ebp-10h]

  if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v8 = m_Parent;
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)m_Parent;
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
    while ( 1 )
    {
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v6 = result == (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1
         ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
      if ( v6->m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))-1 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( result == (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1 )
        result = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc;
      else
        result = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426FD0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int m_Root; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v5; // eax
  int m_Parent; // eax
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v7; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v8; // eax
  int v9; // esi
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v10; // eax
  int m_nAllocationCount; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v18; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v20; // eax
  int m_Left; // eax
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *v22; // ecx
  int v23; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v24; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v25; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        m_Root = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
               | 1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Elements.m_nGrowSize != 0 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v10 = v9 == -1
          ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[v9];
      m_nAllocationCount = v10->m_Elements.m_nAllocationCount;
      IsLeftChild = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_nAllocationCount == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[m_nAllocationCount];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v16 = m_Right == -1
            ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Elements.m_nGrowSize != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsRightChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateLeft(
              this,
              elem: v9);
            v17 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
            if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                & 1) == 0 )
            {
              v17 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v18 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v18 = &this->m_Elements.m_pMemory[v9];
            v9 = v18->m_Parent;
            if ( (v17 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v17 | 1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v19 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v19 = &this->m_Elements.m_pMemory[v9];
            m_nAllocationCount = v19->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: m_nAllocationCount);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          elem = m_nAllocationCount;
        }
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_nAllocationCount == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[m_nAllocationCount];
        m_Left = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v22 = m_Left == -1
            ? &`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Left];
        if ( v22->m_Elements.m_nGrowSize != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v23 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
            if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                & 1) == 0 )
            {
              v23 = `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v9 = v24->m_Parent;
            if ( (v23 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v23 | 1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v25 = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v25 = &this->m_Elements.m_pMemory[v9];
            m_nAllocationCount = v25->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: m_nAllocationCount);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          elem = m_nAllocationCount;
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
// Address: 0x004274A0
// Name: public: CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::~CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x00427510
// Name: protected: void CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427590
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427670
// Name: public: unsigned short CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::Insert(class CChoreoEvent __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __userpurge CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert@<ax>(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this@<ecx>,
        const char *a2@<edi>,
        CChoreoEvent *const *insert)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
         (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
         a2);
  v5 = v4;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)-8 )
    m_pMemory[v5].m_Data = *insert;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004276E0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NewNode@<eax>(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this@<ecx>,
        const char *a2@<edi>)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlMap<char const *,EventGroup,int>::Node_t *p_m_Data; // ecx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v6 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v6 = index + 1;
      if ( v6 < 0 || v6 >= m_nAllocationCount )
        v6 = -1;
    }
    v7 = v6;
    if ( v6 < 0 || v6 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v8 = this->m_LastAlloc.index;
      if ( v8 < 0 || (v9 = this->m_Elements.m_nAllocationCount, v8 >= v9) )
      {
        v9 = this->m_Elements.m_nAllocationCount;
        v10 = (v9 > 0) - 1;
      }
      else
      {
        v10 = v8 + 1;
        if ( v10 < 0 || v10 >= v9 )
          v10 = -1;
      }
      v7 = v10;
      if ( v10 < 0 || v10 >= v9 )
        _Error(this: (ISceneTokenProcessor *)&stru_44E324, a2);
    }
    this->m_LastAlloc.index = v7;
    result = v7;
  }
  else
  {
    this->m_FirstFree = this->m_Elements.m_pMemory[result].m_Right;
  }
  p_m_Data = &this->m_Elements.m_pMemory[result].m_Data;
  if ( &this->m_Elements.m_pMemory[result] != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-16 )
  {
    this->m_Elements.m_pMemory[result].m_Data.elem.timeSortedEvents.m_LessFunc = ChoreEventStartTimeLessFunc;
    p_m_Data->elem.timeSortedEvents.m_Elements.m_pMemory = nullptr;
    p_m_Data->elem.timeSortedEvents.m_Elements.m_nAllocationCount = 0;
    p_m_Data->elem.timeSortedEvents.m_Elements.m_nGrowSize = 0;
    p_m_Data->elem.timeSortedEvents.m_Root = -1;
    p_m_Data->elem.timeSortedEvents.m_NumElements = 0;
    p_m_Data->elem.timeSortedEvents.m_FirstFree = -1;
    p_m_Data->elem.timeSortedEvents.m_LastAlloc.index = -1;
    p_m_Data->elem.timeSortedEvents.m_pElements = p_m_Data->elem.timeSortedEvents.m_Elements.m_pMemory;
  }
  this->m_pElements = this->m_Elements.m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427CC0
// Name: public: int CUtlDict<struct EventGroup,int>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Find(CUtlDict<EventGroup,int> *this, const char *pName)
{
  int v2; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t search; // [esp+0h] [ebp-20h] BYREF

  if ( pName == nullptr )
    return -1;
  search.elem.timeSortedEvents.m_Root = -1;
  memset(&search.elem.timeSortedEvents.m_Elements, 0, sizeof(search.elem.timeSortedEvents.m_Elements));
  search.elem.timeSortedEvents.m_pElements = nullptr;
  search.elem.timeSortedEvents.m_NumElements = 0;
  search.elem.timeSortedEvents.m_LessFunc = ChoreEventStartTimeLessFunc;
  search.elem.timeSortedEvents.m_FirstFree = -1;
  search.elem.timeSortedEvents.m_LastAlloc.index = -1;
  search.key = pName;
  v2 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &search.elem.timeSortedEvents);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00427D30
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this)
{
  int index; // eax
  BOOL v3; // ecx
  int v4; // esi

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = this->m_Elements.m_nAllocationCount > 0;
    v4 = v3 - 1;
    if ( v3 )
    {
      do
      {
        if ( v4 >= 0 && v4 < this->m_Elements.m_nAllocationCount && v4 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
            `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
            `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
            `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
            `CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
          }
          if ( this->m_Elements.m_pMemory[v4].m_Left != v4 )
          {
            CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &this->m_Elements.m_pMemory[v4].m_Data.elem.timeSortedEvents);
            this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v4].m_Left = v4;
            this->m_FirstFree = v4;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        if ( ++v4 < 0 || v4 >= this->m_Elements.m_nAllocationCount )
          v4 = -1;
      }
      while ( v4 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427E00
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int,class CUtlMap<char const __near *,struct EventGroup,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>>::Insert(struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Insert@<eax>(
        CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *this@<ecx>,
        const char *a2@<edi>,
        const CUtlMap<char const *,EventGroup,int>::Node_t *insert)
{
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v4 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NewNode(
         this,
         a2);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v4,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-16 )
  {
    m_pMemory[v4].m_Data.key = insert->key;
    EventGroup::EventGroup(this: &m_pMemory[v4].m_Data.elem, src: &insert->elem);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00427E70
// Name: public: void CUtlDict<struct EventGroup,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<EventGroup,int>::RemoveAll(CUtlDict<EventGroup,int> *this)
{
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi

  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00427EC0
// Name: public: int CUtlDict<struct EventGroup,int>::Insert(char const __near *,struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Insert(
        CUtlDict<EventGroup,int> *this,
        const char *pName,
        const EventGroup *element)
{
  char *v3; // eax
  int v4; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t insert; // [esp+Ch] [ebp-24h] BYREF
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *p_m_Tree; // [esp+2Ch] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  insert.key = v3;
  insert.elem.timeSortedEvents.m_LessFunc = ChoreEventStartTimeLessFunc;
  memset(&insert.elem.timeSortedEvents.m_Elements, 0, sizeof(insert.elem.timeSortedEvents.m_Elements));
  *(_DWORD *)&insert.elem.timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&insert.elem.timeSortedEvents.m_FirstFree = -1;
  insert.elem.timeSortedEvents.m_pElements = nullptr;
  EventGroup::operator=(this: &insert.elem, src: element);
  v4 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         a2: pName,
         &insert);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &insert.elem.timeSortedEvents);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00430830
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
    dword_49E9E8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_49E9E8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x004309B0
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
    dword_49E9E8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00430A10
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
    dword_49E9E8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00430A80
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
        dword_49E9E8 = 0x1FFFF;
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
        dword_49E9E8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430B70
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
// Address: 0x00430C70
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
// Address: 0x00430DB0
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
        dword_49E9E8 = 0x1FFFF;
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
        dword_49E9E8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00430EB0
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
// Address: 0x00430F70
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
      dword_49E9E8 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_49E9E8 = 0x1FFFF;
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
      dword_49E9E8 = 0x1FFFF;
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
      dword_49E9E8 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_49E9E8 = 0x1FFFF;
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
      dword_49E9E8 = 0x1FFFF;
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
        dword_49E9E8 = 0x1FFFF;
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
        dword_49E9E8 = 0x1FFFF;
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
          dword_49E9E8 = 0x1FFFF;
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
          dword_49E9E8 = 0x1FFFF;
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
        dword_49E9E8 = 0x1FFFF;
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
        dword_49E9E8 = 0x1FFFF;
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
          dword_49E9E8 = 0x1FFFF;
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
          dword_49E9E8 = 0x1FFFF;
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
// Address: 0x00431580
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
// Address: 0x00431680
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
// Address: 0x00431710
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __userpurge CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert@<ax>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this@<ecx>,
        const char *a2@<edi>,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v4; // ax
  int v5; // edi
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
  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
         this,
         a2);
  v5 = v4;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v5].m_Data = *insert;
  return v5;
}
