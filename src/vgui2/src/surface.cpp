// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/surface.cpp
// Functions: 242
// ============================================================

#include "vgui2\src\surface.h"

//------------------------------------------------------------------------------
// Address: 0x10007720
// Name: protected: enum CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::NodeColor_t CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::Color(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Color(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( i == -1 )
    return dword_10051544;
  else
    return this->m_Elements.m_pMemory[i].m_Tag;
}

//------------------------------------------------------------------------------
// Address: 0x10008290
// Name: public: int CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::LeftChild(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x100082F0
// Name: public: int CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RightChild(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( i == -1 )
    return dword_1005153C;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10008350
// Name: protected: void CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::FindInsertionPosition(struct CSchemeManager::CachedBitmapHandle_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        const CSchemeManager::CachedBitmapHandle_t *insert,
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
      if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008440
// Name: public: int CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( i == -1 )
    return dword_10051540;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x100084A0
// Name: public: bool CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x10008550
// Name: public: int CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::NewNode(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v11; // edx

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
      CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>::Grow(this: &this->m_Elements, num: 1);
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
// Address: 0x10008610
// Name: protected: void CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateLeft(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v8; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v9; // eax

  v2 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_1005153C = -1;
      dword_10051540 = -1;
      dword_10051544 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100087C0
// Name: public: bool CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsRightChild(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( m_Parent == -1 )
    return dword_1005153C == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x10008980
// Name: public: int CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::Find(struct CSchemeManager::CachedBitmapHandle_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Find(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        const CSchemeManager::CachedBitmapHandle_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10008A70
// Name: public: void CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RemoveAll(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this)
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
          if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
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
// Address: 0x10008BA0
// Name: protected: void CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateRight(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v6; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v7; // eax

  v2 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1005153C = -1;
    dword_10051540 = -1;
    dword_10051544 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10008D10
// Name: protected: void CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v7; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v18; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v19; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v20; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v23; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
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
        if ( CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateLeft(
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
// Address: 0x100092C0
// Name: protected: void CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::LinkToParent(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v4; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::InsertRebalance(
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
    CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009330
// Name: protected: void CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::RemoveRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RemoveRebalance(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v5; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v6; // ecx
  int m_Parent; // edi
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v8; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v9; // ecx
  int m_Right; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v11; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v12; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v13; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v14; // edx
  int m_Left; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v16; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v17; // edx
  int v18; // edx
  int *v19; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v20; // edx
  int v21; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v22; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v23; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v24; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v25; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v26; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v27; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v28; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v29; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v30; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v31; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v32; // edx
  int v33; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v34; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v35; // edx
  int v36; // edx
  int *v37; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v38; // edx
  int v39; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v40; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v41; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v42; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v43; // ecx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v44; // edx
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v45; // ecx

  v2 = elem;
  if ( elem != this->m_Root )
  {
    v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
    do
    {
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      if ( v5->m_Tag != 1 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      if ( v2 == -1 )
        v6 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v6 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v6->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1005153C = -1;
        dword_10051540 = -1;
        dword_10051544 = 1;
      }
      if ( m_Parent == -1 )
      {
        v8 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
      }
      else
      {
        v8 = &this->m_Elements.m_pMemory[m_Parent];
        v2 = elem;
      }
      if ( v2 == v8->m_Left )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Parent == -1 )
          v9 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v9 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v9->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Right == -1 )
          v11 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v11 = &this->m_Elements.m_pMemory[m_Right];
        if ( v11->m_Tag == 0 )
        {
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateLeft(
            this,
            elem: m_Parent);
          v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( elem == -1 )
            v12 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v12 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v12->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( m_Parent == -1 )
            v13 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v13 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v13->m_Right;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Right == -1 )
          v14 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[m_Right];
        m_Left = v14->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Left == -1 )
          v16 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Left];
        if ( v16->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( m_Right == -1 )
            v17 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v17 = &this->m_Elements.m_pMemory[m_Right];
          v18 = v17->m_Right;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          v19 = v18 == -1
              ? &`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v18];
          if ( v19[3] == 1 )
            goto LABEL_146;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Right == -1 )
          v20 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[m_Right];
        v21 = v20->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( v21 == -1 )
          v22 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v22 = &this->m_Elements.m_pMemory[v21];
        if ( v22->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( m_Right == -1 )
            v23 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[m_Right];
          this->m_Elements.m_pMemory[v23->m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateRight(
            this,
            elem: m_Right);
          v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( elem == -1 )
            v24 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( m_Parent == -1 )
            v25 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v25 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v25->m_Right;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Parent == -1 )
          v26 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[m_Parent];
        this->m_Elements.m_pMemory[m_Right].m_Tag = v26->m_Tag;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
        if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Right == -1 )
          v27 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v27 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v27->m_Right].m_Tag = 1;
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateLeft(
          this,
          elem: m_Parent);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Parent == -1 )
          v28 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[m_Parent];
        m_Right = v28->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Right == -1 )
          v29 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v29 = &this->m_Elements.m_pMemory[m_Right];
        if ( v29->m_Tag == 0 )
        {
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Parent].m_Tag = 0;
          CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateRight(
            this,
            elem: m_Parent);
          v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( elem == -1 )
            v30 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v30->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( m_Parent == -1 )
            v31 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v31->m_Left;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Right == -1 )
          v32 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v32 = &this->m_Elements.m_pMemory[m_Right];
        v33 = v32->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( v33 == -1 )
          v34 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v34 = &this->m_Elements.m_pMemory[v33];
        if ( v34->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( m_Right == -1 )
            v35 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v35 = &this->m_Elements.m_pMemory[m_Right];
          v36 = v35->m_Left;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          v37 = v36 == -1
              ? &`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel
              : (int *)&this->m_Elements.m_pMemory[v36];
          if ( v37[3] == 1 )
          {
LABEL_146:
            if ( m_Right != -1 )
            {
              this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
              v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
            }
            elem = m_Parent;
            goto LABEL_188;
          }
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Right == -1 )
          v38 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v38 = &this->m_Elements.m_pMemory[m_Right];
        v39 = v38->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( v39 == -1 )
          v40 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v40 = &this->m_Elements.m_pMemory[v39];
        if ( v40->m_Tag == 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( m_Right == -1 )
            v41 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v41 = &this->m_Elements.m_pMemory[m_Right];
          this->m_Elements.m_pMemory[v41->m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 0;
          CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateLeft(
            this,
            elem: m_Right);
          v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( elem == -1 )
            v42 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v42 = &this->m_Elements.m_pMemory[elem];
          m_Parent = v42->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( m_Parent == -1 )
            v43 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v43 = &this->m_Elements.m_pMemory[m_Parent];
          m_Right = v43->m_Left;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Parent == -1 )
          v44 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v44 = &this->m_Elements.m_pMemory[m_Parent];
        this->m_Elements.m_pMemory[m_Right].m_Tag = v44->m_Tag;
        this->m_Elements.m_pMemory[m_Parent].m_Tag = 1;
        if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1005153C = -1;
          dword_10051540 = -1;
          dword_10051544 = 1;
        }
        if ( m_Right == -1 )
          v45 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v45 = &this->m_Elements.m_pMemory[m_Right];
        this->m_Elements.m_pMemory[v45->m_Left].m_Tag = 1;
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RotateRight(
          this,
          elem: m_Parent);
      }
      v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
      elem = this->m_Root;
LABEL_188:
      v2 = elem;
    }
    while ( elem != this->m_Root );
  }
  this->m_Elements.m_pMemory[v2].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A3B0
// Name: protected: void CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Unlink(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        int elem)
{
  int m_Left; // edi
  int v4; // ecx
  int v5; // eax
  int *v6; // eax
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *v7; // eax
  int v8; // ebx
  int v9; // ebx
  CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> >::NodeColor_t ycolor; // [esp+Ch] [ebp-8h]
  int x; // [esp+10h] [ebp-4h]

  m_Left = elem;
  if ( elem != -1 )
  {
    v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_1005153C = -1;
      dword_10051540 = -1;
      dword_10051544 = 1;
    }
    if ( this->m_Elements.m_pMemory[elem].m_Left != -1 )
    {
      if ( CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RightChild(
             this,
             i: elem) == -1 )
      {
        v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
      }
      else
      {
        v5 = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RightChild(
               this,
               i: elem);
        v4 = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard';
        m_Left = v5;
        while ( 1 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          v6 = m_Left == -1
             ? &`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel
             : (int *)&this->m_Elements.m_pMemory[m_Left];
          if ( *v6 == -1 )
            break;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1005153C = -1;
            dword_10051540 = -1;
            dword_10051544 = 1;
          }
          if ( m_Left == -1 )
            m_Left = `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            m_Left = this->m_Elements.m_pMemory[m_Left].m_Left;
        }
      }
    }
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
      `CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_1005153C = -1;
      dword_10051540 = -1;
      dword_10051544 = 1;
    }
    if ( m_Left == -1 )
      v7 = (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)&`CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v7 = &this->m_Elements.m_pMemory[m_Left];
    if ( v7->m_Left == -1 )
    {
      x = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RightChild(
            this,
            i: m_Left);
      v8 = x;
    }
    else
    {
      v8 = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::LeftChild(
             this,
             i: m_Left);
      x = v8;
    }
    if ( v8 != -1 )
      this->m_Elements.m_pMemory[v8].m_Parent = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                                  this,
                                                  i: m_Left);
    if ( m_Left == this->m_Root )
    {
      this->m_Root = v8;
    }
    else if ( CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsLeftChild(
                this,
                i: m_Left) )
    {
      this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                   this,
                                   i: m_Left)].m_Left = v8;
    }
    else
    {
      this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                   this,
                                   i: m_Left)].m_Right = v8;
    }
    ycolor = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Color(
               this,
               i: m_Left);
    if ( m_Left != elem )
    {
      v9 = m_Left;
      this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                                      this,
                                                      i: elem);
      this->m_Elements.m_pMemory[v9].m_Right = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RightChild(
                                                 this,
                                                 i: elem);
      this->m_Elements.m_pMemory[v9].m_Left = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::LeftChild(
                                                this,
                                                i: elem);
      if ( elem == this->m_Root )
      {
        this->m_Root = m_Left;
      }
      else if ( CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::IsLeftChild(
                  this,
                  i: elem) )
      {
        this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                     this,
                                     i: elem)].m_Left = m_Left;
      }
      else
      {
        this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Parent(
                                     this,
                                     i: elem)].m_Right = m_Left;
      }
      if ( CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::LeftChild(
             this,
             i: m_Left) != -1 )
        this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::LeftChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      if ( CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RightChild(
             this,
             i: m_Left) != -1 )
        this->m_Elements.m_pMemory[CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RightChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      this->m_Elements.m_pMemory[v9].m_Tag = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Color(
                                               this,
                                               i: elem);
      v8 = x;
    }
    if ( v8 != -1 && ycolor == BLACK )
      CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::RemoveRebalance(
        this,
        elem: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A850
// Name: public: int CUtlRBTree<struct CSchemeManager::CachedBitmapHandle_t,int,bool (*)(struct CSchemeManager::CachedBitmapHandle_t const __near &,struct CSchemeManager::CachedBitmapHandle_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CSchemeManager::CachedBitmapHandle_t,int>,int>>::Insert(struct CSchemeManager::CachedBitmapHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::Insert(
        CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl*)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> > *this,
        const CSchemeManager::CachedBitmapHandle_t *insert)
{
  int v3; // edi
  UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::NewNode(this);
  CUtlRBTree<CSchemeManager::CachedBitmapHandle_t,int,bool (__cdecl *)(CSchemeManager::CachedBitmapHandle_t const &,CSchemeManager::CachedBitmapHandle_t const &),CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int> *)-16 )
    m_pMemory[v3].m_Data = (CSchemeManager::CachedBitmapHandle_t)insert->pBitmap;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000B4F0
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
// Address: 0x1000B540
// Name: public: static bool CWin32Surface::ContextAbsPos_t::Less(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CWin32Surface::ContextAbsPos_t::Less(const vgui::Texture *lhs, const vgui::Texture *rhs)
{
  return lhs->_id < rhs->_id;
}

//------------------------------------------------------------------------------
// Address: 0x1000B560
// Name: staticGenerateIconForTexture
// Source: json
//------------------------------------------------------------------------------
void __usercall staticGenerateIconForTexture(vgui::Texture *texture@<esi>)
{
  HICON__ *ImageA; // eax
  int wide; // ebx
  int tall; // edi
  HBITMAP__ *Bitmap; // eax
  HBITMAP__ *v5; // edx
  HBITMAP__ *v6; // edi
  char buf[256]; // [esp+0h] [ebp-194h] BYREF
  unsigned __int8 planeAND[128]; // [esp+100h] [ebp-94h] BYREF
  _ICONINFO iconInfo; // [esp+180h] [ebp-14h] BYREF

  V_snprintf(pDest: buf, maxLen: 256, pFormat: "%s.ico", texture->_filename);
  ImageA = (HICON__ *)LoadImageA(hInst: nullptr, name: buf, type: 1u, cx: 16, cy: 16, fuLoad: 0x50u);
  texture->_icon = ImageA;
  if ( ImageA == nullptr )
  {
    wide = texture->_wide;
    if ( wide <= 32 )
    {
      tall = texture->_tall;
      if ( tall <= 32 )
      {
        memset(dst: planeAND, value: 0, count: sizeof(planeAND));
        Bitmap = CreateBitmap(nWidth: wide, nHeight: tall, nPlanes: 1u, nBitCount: 1u, lpBits: planeAND);
        v5 = texture->_bitmap;
        v6 = Bitmap;
        iconInfo.xHotspot = 8;
        iconInfo.yHotspot = 8;
        iconInfo.fIcon = 1;
        iconInfo.hbmMask = Bitmap;
        iconInfo.hbmColor = v5;
        texture->_icon = CreateIconIndirect(piconinfo: &iconInfo);
        DeleteObject(ho: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B620
// Name: public: virtual unsigned int CWin32Surface::GetEmbeddedPanel(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWin32Surface::GetEmbeddedPanel(CWin32Surface *this)
{
  return this->_embeddedPanel;
}

//------------------------------------------------------------------------------
// Address: 0x1000B630
// Name: public: virtual void CWin32Surface::DrawTexturedSubRect(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawTexturedSubRect(
        CWin32Surface *this,
        int x0,
        int y0,
        int x1,
        int y1,
        float texs0,
        float text0,
        float texs1,
        float text1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000B640
// Name: public: virtual void CWin32Surface::DrawTexturedPolygon(int,struct FontVertex_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawTexturedPolygon(CWin32Surface *this, int n, HBRUSH__ *pVertices, bool bClipVertices)
{
  HDC v4; // edi
  POINT *v5; // esi
  int i; // eax
  COLORREF BkColor; // ebx
  HBRUSH SolidBrush; // ebx
  COLORREF pencolor; // [esp+Ch] [ebp-8h]
  HBRUSH__ *oldBrush; // [esp+20h] [ebp+Ch]

  v4 = *(HDC *)((*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel)
              + 4);
  v5 = (POINT *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * n);
  if ( v5 != nullptr )
  {
    for ( i = 0; i < n; pVertices += 4 )
    {
      v5[i].x = (int)*(float *)pVertices;
      v5[i++].y = (int)*((float *)pVertices + 1);
    }
    pencolor = GetTextColor(hdc: v4);
    BkColor = GetBkColor(hdc: v4);
    this->DrawSetTextColor_2(this, a2: (unsigned __int8)BkColor, a3: BYTE1(BkColor), a4: BYTE2(BkColor), a5: 255);
    SolidBrush = CreateSolidBrush(color: BkColor);
    oldBrush = (HBRUSH__ *)SelectObject(hdc: v4, h: SolidBrush);
    Polygon(hdc: v4, apt: v5, cpt: n);
    SelectObject(hdc: v4, h: oldBrush);
    DeleteObject(ho: SolidBrush);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    this->DrawSetTextColor_2(this, a2: (unsigned __int8)pencolor, a3: BYTE1(pencolor), a4: BYTE2(pencolor), a5: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B760
// Name: public: virtual wchar_t const __near * CWin32Surface::GetTitle(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall CWin32Surface::GetTitle(CWin32Surface *this, unsigned int panel)
{
  return &word_1003DE18;
}

//------------------------------------------------------------------------------
// Address: 0x1000B770
// Name: public: virtual void CWin32Surface::DrawOutlinedCircle(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawOutlinedCircle(CWin32Surface *this, int left, int top, int right, int bottom)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000B780
// Name: public: virtual void CWin32Surface::DrawWordBubble(int,int,int,int,int,class Color,class Color,bool,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawWordBubble(
        CWin32Surface *this,
        int x0,
        int y0,
        int x1,
        int y1,
        int nBorderThickness,
        Color rgbaBackground,
        Color rgbaBorder,
        bool bPointer,
        int nPointerX,
        int nPointerY,
        int nPointerBaseThickness)
{
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  CWin32Surface_vtbl *v16; // edx
  CWin32Surface_vtbl *v17; // edx
  void (__thiscall *DrawFilledRect)(vgui::ISurface *, int, int, int, int); // edx
  FontVertex_t *v19; // edi
  FontVertex_t *v20; // edi
  int j; // ebx
  void (__thiscall *DrawTexturedPolygon)(vgui::ISurface *, int, FontVertex_t *, bool); // edx
  FontVertex_t *v23; // edi
  int i; // ebx
  FontVertex_t cornerVerts[12]; // [esp+Ch] [ebp-1D4h] BYREF
  int nOldClipX1; // [esp+CCh] [ebp-114h] BYREF
  float v27; // [esp+D0h] [ebp-110h]
  int nOldClipY0; // [esp+D4h] [ebp-10Ch] BYREF
  int v29; // [esp+D8h] [ebp-108h]
  int v30; // [esp+DCh] [ebp-104h]
  int nOldClipX0; // [esp+E0h] [ebp-100h] BYREF
  int nOldClipY1; // [esp+E4h] [ebp-FCh] BYREF
  float v33; // [esp+E8h] [ebp-F8h] BYREF
  float v34; // [esp+ECh] [ebp-F4h]
  int v35; // [esp+F0h] [ebp-F0h]
  int v36; // [esp+F4h] [ebp-ECh]
  float v37; // [esp+F8h] [ebp-E8h]
  float v38; // [esp+FCh] [ebp-E4h]
  int v39; // [esp+100h] [ebp-E0h]
  int v40; // [esp+104h] [ebp-DCh]
  float v41; // [esp+108h] [ebp-D8h]
  float v42; // [esp+10Ch] [ebp-D4h]
  int v43; // [esp+110h] [ebp-D0h]
  int v44; // [esp+114h] [ebp-CCh]
  float v45; // [esp+118h] [ebp-C8h]
  float v46; // [esp+11Ch] [ebp-C4h]
  int v47; // [esp+120h] [ebp-C0h]
  int v48; // [esp+124h] [ebp-BCh]
  float v49; // [esp+128h] [ebp-B8h]
  float v50; // [esp+12Ch] [ebp-B4h]
  int v51; // [esp+130h] [ebp-B0h]
  int v52; // [esp+134h] [ebp-ACh]
  float v53; // [esp+138h] [ebp-A8h]
  float v54; // [esp+13Ch] [ebp-A4h]
  int v55; // [esp+140h] [ebp-A0h]
  int v56; // [esp+144h] [ebp-9Ch]
  float v57; // [esp+148h] [ebp-98h]
  float v58; // [esp+14Ch] [ebp-94h]
  int v59; // [esp+150h] [ebp-90h]
  int v60; // [esp+154h] [ebp-8Ch]
  float v61; // [esp+158h] [ebp-88h]
  float v62; // [esp+15Ch] [ebp-84h]
  int v63; // [esp+160h] [ebp-80h]
  int v64; // [esp+164h] [ebp-7Ch]
  float v65; // [esp+168h] [ebp-78h]
  float v66; // [esp+16Ch] [ebp-74h]
  int v67; // [esp+170h] [ebp-70h]
  int v68; // [esp+174h] [ebp-6Ch]
  float v69; // [esp+178h] [ebp-68h]
  float v70; // [esp+17Ch] [ebp-64h]
  int v71; // [esp+180h] [ebp-60h]
  int v72; // [esp+184h] [ebp-5Ch]
  float v73; // [esp+188h] [ebp-58h]
  float v74; // [esp+18Ch] [ebp-54h]
  int v75; // [esp+190h] [ebp-50h]
  int v76; // [esp+194h] [ebp-4Ch]
  float v77; // [esp+198h] [ebp-48h]
  float v78; // [esp+19Ch] [ebp-44h]
  int v79; // [esp+1A0h] [ebp-40h]
  int v80; // [esp+1A4h] [ebp-3Ch]
  FontVertex_t pointerVerts[3]; // [esp+1A8h] [ebp-38h] BYREF
  int v82; // [esp+1D8h] [ebp-8h]
  int nBackgroundWide; // [esp+1DCh] [ebp-4h]
  int nBackgroundTall; // [esp+1E8h] [ebp+8h]
  float nBackgroundTalla; // [esp+1E8h] [ebp+8h]
  int y0a; // [esp+1ECh] [ebp+Ch]
  int nHalfPointerBaseBottomWide; // [esp+1F0h] [ebp+10h]
  int nHalfPointerBaseBottomWidea; // [esp+1F0h] [ebp+10h]
  int nHalfPointerBaseTopWide; // [esp+1F4h] [ebp+14h]
  int nHalfPointerBaseTopWideb; // [esp+1F4h] [ebp+14h]
  float nHalfPointerBaseTopWidea; // [esp+1F4h] [ebp+14h]
  int nPointerBaseThicknessb; // [esp+210h] [ebp+30h]
  int nPointerBaseThicknessa; // [esp+210h] [ebp+30h]

  this->GetClipRect(this, a2: &nOldClipX0, a3: &nOldClipY0, a4: &nOldClipX1, a5: &nOldClipY1);
  this->SetClipRect(this, a2: -32768, a3: -32768, a4: 0x7FFF, a5: 0x7FFF);
  DrawSetColor = this->DrawSetColor;
  nBackgroundWide = x1 - x0;
  nBackgroundTall = y1 - y0;
  ((void (__thiscall *)(_DWORD, _DWORD))DrawSetColor)(a1: this, a2: rgbaBackground);
  this->DrawFilledRect(this, a2: x0, a3: y0, a4: x1, a5: y1);
  this->DrawSetTexture(this, a2: -1);
  if ( nPointerY < y0 || nPointerY >= y1 )
  {
    if ( bPointer )
    {
      pointerVerts[0].m_TexCoord.x = 0.0;
      pointerVerts[0].m_TexCoord.y = 0.0;
      pointerVerts[1].m_TexCoord.x = 0.0;
      pointerVerts[1].m_TexCoord.y = 0.0;
      pointerVerts[1].m_Position.y = (float)nPointerY;
      pointerVerts[2].m_TexCoord.x = 0.0;
      pointerVerts[2].m_TexCoord.y = 0.0;
      if ( nPointerY >= y0 )
      {
        nHalfPointerBaseTopWide = nPointerBaseThickness;
        pointerVerts[0].m_Position.x = (float)(x0 + nPointerBaseThickness);
        nHalfPointerBaseBottomWide = nPointerBaseThickness / 2;
        pointerVerts[1].m_Position.x = (float)nPointerX;
        DrawTexturedPolygon = this->DrawTexturedPolygon;
        pointerVerts[0].m_Position.y = (float)(y0 + nBackgroundTall);
        pointerVerts[2].m_Position.x = (float)(x0 + nPointerBaseThickness / 2);
        pointerVerts[2].m_Position.y = pointerVerts[0].m_Position.y;
      }
      else
      {
        nHalfPointerBaseTopWide = nPointerBaseThickness / 2;
        pointerVerts[0].m_Position.x = (float)(x0 + nPointerBaseThickness / 2);
        pointerVerts[1].m_Position.x = (float)nPointerX;
        nHalfPointerBaseBottomWide = nPointerBaseThickness;
        DrawTexturedPolygon = this->DrawTexturedPolygon;
        pointerVerts[0].m_Position.y = (float)y0;
        pointerVerts[2].m_Position.x = (float)(x0 + nPointerBaseThickness);
        pointerVerts[2].m_Position.y = (float)y0;
      }
      DrawTexturedPolygon(this, a2: 3, a3: pointerVerts, a4: true);
      goto LABEL_5;
    }
  }
  else
  {
    bPointer = false;
  }
  nHalfPointerBaseTopWide = nPointerBaseThickness;
  nHalfPointerBaseBottomWide = nPointerBaseThickness;
LABEL_5:
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor)(a1: this, a2: rgbaBorder);
  v16 = this->CBaseAppSystem<vgui::ISurface>::vgui::ISurface::IAppSystem::__vftable;
  v29 = x0 + nHalfPointerBaseTopWide;
  v82 = y0 - nBorderThickness;
  v16->DrawFilledRect(this, a2: x0, a3: y0 - nBorderThickness, a4: x0 + nHalfPointerBaseTopWide, a5: y0);
  nHalfPointerBaseTopWideb = x0 + nBackgroundWide;
  y0a = x0 + nPointerBaseThickness;
  this->DrawFilledRect(this, a2: x0 + nPointerBaseThickness, a3: v82, a4: x0 + nBackgroundWide, a5: y0);
  v17 = this->CBaseAppSystem<vgui::ISurface>::vgui::ISurface::IAppSystem::__vftable;
  nPointerBaseThicknessb = y0 + nBackgroundTall;
  v30 = x0 - nBorderThickness;
  v17->DrawFilledRect(this, a2: x0 - nBorderThickness, a3: y0, a4: x0, a5: y0 + nBackgroundTall);
  this->DrawFilledRect(
    this,
    a2: nHalfPointerBaseTopWideb,
    a3: y0,
    a4: nHalfPointerBaseTopWideb + nBorderThickness,
    a5: y0 + nBackgroundTall);
  nHalfPointerBaseBottomWidea = x0 + nHalfPointerBaseBottomWide;
  DrawFilledRect = this->DrawFilledRect;
  nBackgroundWide = y0 + nBackgroundTall + nBorderThickness;
  DrawFilledRect(
    this,
    a2: x0,
    a3: nPointerBaseThicknessb,
    a4: nHalfPointerBaseBottomWidea,
    a5: nPointerBaseThicknessb + nBorderThickness);
  this->DrawFilledRect(this, a2: y0a, a3: y0 + nBackgroundTall, a4: nHalfPointerBaseTopWideb, a5: nBackgroundWide);
  v27 = (float)v82;
  cornerVerts[0].m_Position.y = (float)v82;
  *(float *)&v82 = (float)y0;
  cornerVerts[1].m_Position.y = (float)y0;
  cornerVerts[2].m_Position.x = (float)v30;
  cornerVerts[2].m_Position.y = (float)y0;
  cornerVerts[3].m_Position.y = v27;
  cornerVerts[4].m_Position.y = (float)y0;
  cornerVerts[5].m_Position.y = (float)y0;
  cornerVerts[6].m_Position.x = (float)v30;
  cornerVerts[0].m_Position.x = (float)x0;
  cornerVerts[0].m_TexCoord.x = 0.0;
  cornerVerts[0].m_TexCoord.y = 0.0;
  cornerVerts[1].m_Position.x = (float)x0;
  cornerVerts[1].m_TexCoord.x = 0.0;
  cornerVerts[1].m_TexCoord.y = 0.0;
  cornerVerts[2].m_TexCoord.x = 0.0;
  cornerVerts[2].m_TexCoord.y = 0.0;
  cornerVerts[3].m_Position.x = (float)nHalfPointerBaseTopWideb;
  cornerVerts[3].m_TexCoord.x = 0.0;
  cornerVerts[3].m_TexCoord.y = 0.0;
  cornerVerts[4].m_Position.x = (float)(nHalfPointerBaseTopWideb + nBorderThickness);
  cornerVerts[4].m_TexCoord.x = 0.0;
  cornerVerts[4].m_TexCoord.y = 0.0;
  cornerVerts[5].m_Position.x = (float)nHalfPointerBaseTopWideb;
  cornerVerts[5].m_TexCoord.x = 0.0;
  cornerVerts[5].m_TexCoord.y = 0.0;
  nBackgroundTalla = (float)(y0 + nBackgroundTall);
  cornerVerts[6].m_Position.y = (float)nPointerBaseThicknessb;
  cornerVerts[6].m_TexCoord.x = 0.0;
  cornerVerts[6].m_TexCoord.y = 0.0;
  cornerVerts[7].m_Position.x = (float)x0;
  cornerVerts[7].m_Position.y = (float)nPointerBaseThicknessb;
  cornerVerts[7].m_TexCoord.x = 0.0;
  cornerVerts[7].m_TexCoord.y = 0.0;
  nHalfPointerBaseTopWidea = (float)nBackgroundWide;
  cornerVerts[8].m_Position.x = (float)x0;
  cornerVerts[8].m_Position.y = (float)nBackgroundWide;
  cornerVerts[8].m_TexCoord.x = 0.0;
  cornerVerts[8].m_TexCoord.y = 0.0;
  cornerVerts[9].m_Position.x = cornerVerts[3].m_Position.x;
  cornerVerts[9].m_Position.y = (float)nPointerBaseThicknessb;
  cornerVerts[9].m_TexCoord.x = 0.0;
  cornerVerts[9].m_TexCoord.y = 0.0;
  cornerVerts[10].m_Position.x = cornerVerts[4].m_Position.x;
  cornerVerts[10].m_Position.y = (float)nPointerBaseThicknessb;
  cornerVerts[10].m_TexCoord.x = 0.0;
  cornerVerts[10].m_TexCoord.y = 0.0;
  cornerVerts[11].m_Position.x = cornerVerts[3].m_Position.x;
  cornerVerts[11].m_Position.y = (float)nBackgroundWide;
  cornerVerts[11].m_TexCoord.x = 0.0;
  cornerVerts[11].m_TexCoord.y = 0.0;
  v19 = cornerVerts;
  for ( nPointerBaseThicknessa = 4; nPointerBaseThicknessa != 0; --nPointerBaseThicknessa )
  {
    this->DrawTexturedPolygon(this, a2: 3, a3: v19, a4: true);
    v19 += 3;
  }
  if ( bPointer )
  {
    v49 = (float)y0a;
    v53 = (float)y0a;
    v35 = 0;
    v36 = 0;
    v39 = 0;
    v40 = 0;
    v43 = 0;
    v44 = 0;
    v47 = 0;
    v48 = 0;
    v51 = 0;
    v52 = 0;
    v55 = 0;
    v56 = 0;
    v59 = 0;
    v60 = 0;
    v63 = 0;
    v64 = 0;
    if ( nPointerY >= y0 )
    {
      v33 = (float)nHalfPointerBaseBottomWidea;
      v37 = (float)nHalfPointerBaseBottomWidea;
      v42 = (float)nPointerY;
      v62 = (float)nPointerY;
      v66 = (float)nPointerY;
      v34 = nHalfPointerBaseTopWidea;
      v38 = nBackgroundTalla;
      v41 = (float)nPointerX;
      v45 = (float)(nPointerX - nBorderThickness);
      v46 = (float)(nBorderThickness + nPointerY);
      v50 = nHalfPointerBaseTopWidea;
      v54 = nBackgroundTalla;
      v57 = (float)(nBorderThickness + nPointerX);
      v58 = v46;
      v61 = (float)nPointerX;
      v65 = (float)nPointerX;
      v67 = 0;
      v68 = 0;
      v69 = v57;
      v70 = v46;
      v71 = 0;
      v72 = 0;
      v73 = (float)nPointerX;
      v74 = (float)(nPointerY + 2 * nBorderThickness);
      v75 = 0;
      v76 = 0;
      v77 = v45;
      v78 = v46;
      v79 = 0;
      v80 = 0;
      v23 = (FontVertex_t *)&v33;
      for ( i = 3; i != 0; --i )
      {
        this->DrawTexturedPolygon(this, a2: 4, a3: v23, a4: true);
        v23 += 4;
      }
    }
    else
    {
      v33 = (float)v29;
      v37 = (float)v29;
      v38 = v27;
      v50 = v27;
      v34 = *(float *)&v82;
      v41 = (float)(nPointerX - nBorderThickness);
      v42 = (float)(nPointerY - nBorderThickness);
      v45 = (float)nPointerX;
      v46 = (float)nPointerY;
      v54 = *(float *)&v82;
      v57 = (float)nPointerX;
      v58 = (float)nPointerY;
      v61 = (float)(nBorderThickness + nPointerX);
      v62 = v42;
      v65 = (float)nPointerX;
      v66 = (float)(nPointerY - 2 * nBorderThickness);
      v67 = 0;
      v68 = 0;
      v69 = v61;
      v70 = v42;
      v71 = 0;
      v72 = 0;
      v73 = (float)nPointerX;
      v74 = (float)nPointerY;
      v75 = 0;
      v76 = 0;
      v77 = v41;
      v78 = v42;
      v79 = 0;
      v80 = 0;
      v20 = (FontVertex_t *)&v33;
      for ( j = 3; j != 0; --j )
      {
        this->DrawTexturedPolygon(this, a2: 4, a3: v20, a4: true);
        v20 += 4;
      }
    }
  }
  this->SetClipRect(this, a2: nOldClipX0, a3: nOldClipY0, a4: nOldClipX1, a5: nOldClipY1);
}

//------------------------------------------------------------------------------
// Address: 0x1000BF40
// Name: public: virtual bool CWin32Surface::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32Surface::Connect(CWin32Surface *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000BF50
// Name: public: virtual void __near * CWin32Surface::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ISchemeSurface *__thiscall CWin32Surface::QueryInterface(CWin32Surface *this, const char *pInterfaceName)
{
  int v3; // eax
  int v5; // eax

  v3 = _V_strlen(str: "VGUI_Surface031");
  if ( V_strncmp(s1: pInterfaceName, s2: "VGUI_Surface031", count: v3 + 1) == 0 )
    return (ISchemeSurface *)this;
  v5 = _V_strlen(str: "SchemeSurface001");
  if ( V_strncmp(s1: pInterfaceName, s2: "SchemeSurface001", count: v5 + 1) != 0 || this == nullptr )
    return nullptr;
  else
    return &this->ISchemeSurface;
}

//------------------------------------------------------------------------------
// Address: 0x1000BFC0
// Name: public: virtual void CWin32Surface::SetEmbeddedPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetEmbeddedPanel(CWin32Surface *this, unsigned int panel)
{
  void (__thiscall *SetCurrentContextPanel)(CWin32Surface *, unsigned int); // edx
  void (__thiscall *CreatePopup)(vgui::ISurface *, unsigned int, bool, bool, bool, bool, bool); // edx
  HWND *v5; // eax
  CFontManager *v6; // eax
  CFontManager *v7; // eax
  int v8; // [esp+0h] [ebp-48h]
  int v9; // [esp+4h] [ebp-44h]
  char language[64]; // [esp+8h] [ebp-40h] BYREF

  SetCurrentContextPanel = this->SetCurrentContextPanel;
  this->_embeddedPanel = panel;
  staticSurfaceAvailable = true;
  ((void (__stdcall *)(unsigned int, int, int, _DWORD, _DWORD))SetCurrentContextPanel)(
    a1: panel,
    a2: v8,
    a3: v9,
    a4: *(_DWORD *)language,
    a5: *(_DWORD *)&language[4]);
  CreatePopup = this->CreatePopup;
  *(_DWORD *)&language[4] = 1;
  *(_DWORD *)language = 1;
  ((void (__thiscall *)(CWin32Surface *))CreatePopup)(a1: this);
  v5 = (HWND *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
  SetTimer(hWnd: *v5, nIDEvent: 0, uElapse: 0x32u, lpTimerFunc: nullptr);
  if ( vgui::g_pSystem->GetRegistryString(
         this: vgui::g_pSystem,
         a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language",
         a3: language,
         a4: 63) )
  {
    v6 = FontManager();
    CFontManager::SetLanguage(this: v6, pLanguage: language);
  }
  else
  {
    v7 = FontManager();
    CFontManager::SetLanguage(this: v7, pLanguage: "english");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C060
// Name: public: virtual bool CWin32Surface::DrawGetUnicodeCharRenderInfo(wchar_t,struct FontCharRenderInfo __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::DrawGetUnicodeCharRenderInfo(CWin32Surface *this, wchar_t ch, FontCharRenderInfo *info)
{
  info->valid = false;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1000C070
// Name: public: virtual void CWin32Surface::PushMakeCurrent(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::PushMakeCurrent(CWin32Surface *this, int *panel, bool useInsets)
{
  unsigned int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  unsigned int currentContextPanel; // ecx
  int v9; // eax
  unsigned int v10; // edi
  int v11; // eax
  HDC v12; // [esp-10h] [ebp-5Ch]
  int v13; // [esp-10h] [ebp-5Ch]
  int v14; // [esp-Ch] [ebp-58h]
  int v15; // [esp-Ch] [ebp-58h]
  int v16; // [esp-8h] [ebp-54h]
  int v17; // [esp-8h] [ebp-54h]
  int v18; // [esp-4h] [ebp-50h]
  void *v19; // [esp-4h] [ebp-50h]
  int clipRect[4]; // [esp+Ch] [ebp-40h] BYREF
  int absPanel[4]; // [esp+1Ch] [ebp-30h] BYREF
  int inset[4]; // [esp+2Ch] [ebp-20h] BYREF
  int absThis[4]; // [esp+3Ch] [ebp-10h] BYREF

  v4 = (unsigned int)panel;
  if ( panel != nullptr )
  {
    do
    {
      if ( (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v4 + 12))(a1: v4) != 0 )
        break;
      v4 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v4 + 124))(a1: v4);
    }
    while ( v4 != 0 );
  }
  this->SetCurrentContextPanel(this, a2: v4);
  this->m_pActiveFont = nullptr;
  if ( v4 == 0 )
    _Msg(a1: "Warning: VPanel with no drawing context\n");
  v5 = (*(int (__thiscall **)(int *))(*panel + 156))(a1: panel);
  (*(void (__thiscall **)(int, int *, int *, int *, int *))(*(_DWORD *)v5 + 24))(
    a1: v5,
    a2: inset,
    a3: &inset[1],
    a4: &inset[2],
    a5: &inset[3]);
  if ( !useInsets )
    memset(inset, 0, sizeof(inset));
  (*(void (__thiscall **)(unsigned int, int *, int *))(*(_DWORD *)this->_currentContextPanel + 72))(
    a1: this->_currentContextPanel,
    a2: absThis,
    a3: &absThis[1]);
  (*(void (__thiscall **)(unsigned int, int *, int *))(*(_DWORD *)this->_currentContextPanel + 52))(
    a1: this->_currentContextPanel,
    a2: &absThis[2],
    a3: &absThis[3]);
  absThis[2] += absThis[0];
  absThis[3] += absThis[1];
  (*(void (__thiscall **)(int *, int *, int *))(*panel + 72))(a1: panel, a2: absPanel, a3: &absPanel[1]);
  (*(void (__thiscall **)(int *, int *, int *))(*panel + 52))(a1: panel, a2: &absPanel[2], a3: &absPanel[3]);
  v6 = *panel;
  absPanel[2] += absPanel[0];
  absPanel[3] += absPanel[1];
  v7 = (*(int (__thiscall **)(int *))(v6 + 156))(a1: panel);
  (*(void (__thiscall **)(int, int *, int *, int *, int *))(*(_DWORD *)v7 + 28))(
    a1: v7,
    a2: clipRect,
    a3: &clipRect[1],
    a4: &clipRect[2],
    a5: &clipRect[3]);
  currentContextPanel = this->_currentContextPanel;
  if ( (int *)currentContextPanel == panel )
  {
    v16 = inset[1];
    v14 = inset[0];
  }
  else
  {
    v16 = inset[1] + absPanel[1] - absThis[1];
    v14 = inset[0] + absPanel[0] - absThis[0];
  }
  v12 = *(HDC *)((*(int (__thiscall **)(unsigned int))(*(_DWORD *)currentContextPanel + 12))(a1: currentContextPanel) + 4);
  SetViewportOrgEx(hdc: v12, x: v14, y: v16, lppt: nullptr);
  v18 = clipRect[3] - absThis[1] - inset[3];
  v17 = clipRect[2] - absThis[0] - inset[2];
  v15 = clipRect[1] - absThis[1];
  v13 = clipRect[0] - absThis[0];
  v9 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
  SetRectRgn(hrgn: *(HRGN *)(v9 + 20), left: v13, top: v15, right: v17, bottom: v18);
  v10 = this->_currentContextPanel;
  v19 = *(void **)((*(int (__thiscall **)(unsigned int))(*(_DWORD *)v10 + 12))(a1: v10) + 20);
  v11 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v10 + 12))(a1: v10);
  SelectObject(hdc: *(HDC *)(v11 + 4), h: v19);
}

//------------------------------------------------------------------------------
// Address: 0x1000C230
// Name: public: virtual void CWin32Surface::PopMakeCurrent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::PopMakeCurrent(CWin32Surface *this, unsigned int panel)
{
  if ( panel == this->_currentContextPanel )
    this->SetCurrentContextPanel(this, a2: this->_embeddedPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1000C250
// Name: public: virtual void CWin32Surface::GetScreenSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::GetScreenSize(CWin32Surface *this, int *wide, int *tall)
{
  unsigned int embeddedPanel; // esi
  int v4; // eax
  int v5; // eax

  if ( this->m_ScreenSizeOverride.m_bActive )
  {
    *(_QWORD *)wide = *(_QWORD *)this->m_ScreenSizeOverride.m_nValue;
  }
  else
  {
    embeddedPanel = this->_embeddedPanel;
    if ( embeddedPanel != 0 )
    {
      v4 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)embeddedPanel + 12))(a1: embeddedPanel);
      *wide = GetDeviceCaps(hdc: *(HDC *)(v4 + 4), index: 8);
      v5 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)embeddedPanel + 12))(a1: embeddedPanel);
      *tall = GetDeviceCaps(hdc: *(HDC *)(v5 + 4), index: 10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C2C0
// Name: public: virtual bool CWin32Surface::ForceScreenSizeOverride(bool,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::ForceScreenSizeOverride(CWin32Surface *this, bool bState, int wide, int tall)
{
  bool result; // al

  result = this->m_ScreenSizeOverride.m_bActive;
  this->m_ScreenSizeOverride.m_bActive = bState;
  this->m_ScreenSizeOverride.m_nValue[0] = wide;
  this->m_ScreenSizeOverride.m_nValue[1] = tall;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C2F0
// Name: public: virtual bool CWin32Surface::ForceScreenPosOffset(bool,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::ForceScreenPosOffset(CWin32Surface *this, bool bState, int x, int y)
{
  bool result; // al

  result = this->m_ScreenPosOverride.m_bActive;
  this->m_ScreenPosOverride.m_bActive = bState;
  this->m_ScreenPosOverride.m_nValue[0] = x;
  this->m_ScreenPosOverride.m_nValue[1] = y;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C320
// Name: public: virtual void CWin32Surface::OffsetAbsPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::OffsetAbsPos(CWin32Surface *this, int *x, int *y)
{
  if ( this->m_ScreenPosOverride.m_bActive )
  {
    *x += this->m_ScreenPosOverride.m_nValue[0];
    *y += this->m_ScreenPosOverride.m_nValue[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C350
// Name: public: virtual bool CWin32Surface::IsScreenSizeOverrideActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::IsScreenSizeOverrideActive(CWin32Surface *this)
{
  return this->m_ScreenSizeOverride.m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x1000C360
// Name: public: virtual bool CWin32Surface::IsScreenPosOverrideActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::IsScreenPosOverrideActive(CWin32Surface *this)
{
  return this->m_ScreenPosOverride.m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x1000C370
// Name: private: virtual long CSurfaceDragDropTarget::DragLeave(void)
// Source: json
//------------------------------------------------------------------------------
IVguiMatInfo *__thiscall CSurfaceDragDropTarget::DragLeave(CWin32Surface *this, CSurfaceDragDropTarget *id)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000C380
// Name: public: virtual void CWin32Surface::DrawSetTextureFrame(int,int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetTextureFrame(CWin32Surface *this, int id, int nFrame, unsigned int *pFrameCache)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000C390
// Name: public: virtual void CWin32Surface::GetClipRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::GetClipRect(CWin32Surface *this, int *x0, int *y0, int *x1, int *y1)
{
  int v5; // eax

  v5 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 156))(a1: this->_currentContextPanel);
  (*(void (__thiscall **)(int, int *, int *, int *, int *))(*(_DWORD *)v5 + 28))(a1: v5, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x1000C3B0
// Name: public: virtual void CWin32Surface::SetClipRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetClipRect(CWin32Surface *this, int x0, int y0, int x1, int y1)
{
  int v5; // eax

  v5 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
  SetRectRgn(hrgn: *(HRGN *)(v5 + 20), left: x0, top: y0, right: x1, bottom: y1);
}

//------------------------------------------------------------------------------
// Address: 0x1000C3E0
// Name: public: virtual unsigned int CWin32Surface::GetNotifyPanel(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWin32Surface::GetNotifyPanel(CWin32Surface *this)
{
  return this->_notifyPanel;
}

//------------------------------------------------------------------------------
// Address: 0x1000C3F0
// Name: public: virtual void CWin32Surface::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetColor(
        CWin32Surface *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        int a)
{
  int v5; // eax

  v5 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
  SetBkColor(hdc: *(HDC *)(v5 + 4), color: r | ((g | (b << 8)) << 8));
}

//------------------------------------------------------------------------------
// Address: 0x1000C430
// Name: public: virtual void CWin32Surface::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetColor(CWin32Surface *this, Color col)
{
  this->DrawSetColor_2(this, a2: col._color[0], a3: col._color[1], a4: col._color[2], a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x1000C470
// Name: public: virtual void CWin32Surface::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetTextPos(CWin32Surface *this, int x, int y)
{
  int v4; // eax

  v4 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
  MoveToEx(hdc: *(HDC *)(v4 + 4), x, y, lppt: nullptr);
  this->m_TextPos[1] = y;
  this->m_TextPos[0] = x;
}

//------------------------------------------------------------------------------
// Address: 0x1000C4B0
// Name: public: virtual void CWin32Surface::DrawGetTextPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawGetTextPos(CWin32Surface *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->m_TextPos;
}

//------------------------------------------------------------------------------
// Address: 0x1000C4D0
// Name: public: virtual void CWin32Surface::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetTextFont(CWin32Surface *this, unsigned int font)
{
  this->m_hCurrentFont = font;
}

//------------------------------------------------------------------------------
// Address: 0x1000C4E0
// Name: public: virtual void CWin32Surface::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawFilledRect(CWin32Surface *this, int x0, int y0, int x1, int y1)
{
  unsigned int currentContextPanel; // ecx
  int v6; // eax
  tagRECT rect; // [esp+0h] [ebp-10h] BYREF

  currentContextPanel = this->_currentContextPanel;
  rect.left = x0;
  rect.right = x1;
  rect.top = y0;
  rect.bottom = y1;
  v6 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)currentContextPanel + 12))(a1: currentContextPanel);
  ExtTextOutA(hdc: *(HDC *)(v6 + 4), x: 0, y: 0, options: 2u, lprect: &rect, lpString: nullptr, c: 0, lpDx: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000C530
// Name: public: virtual void CWin32Surface::DrawFilledRectArray(struct vgui::IntRect __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawFilledRectArray(CWin32Surface *this, vgui::IntRect *pRects, int numRects)
{
  int v3; // ebx
  int *p_x1; // esi

  v3 = numRects;
  if ( numRects > 0 )
  {
    p_x1 = &pRects->x1;
    do
    {
      this->DrawFilledRect(this, a2: *(p_x1 - 2), a3: *(p_x1 - 1), a4: *p_x1, a5: p_x1[1]);
      p_x1 += 4;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C570
// Name: public: virtual void CWin32Surface::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawOutlinedRect(CWin32Surface *this, int x0, int y0, int x1, int y1)
{
  this->DrawFilledRect(this, a2: x0, a3: y0, a4: x1, a5: y0 + 1);
  this->DrawFilledRect(this, a2: x0, a3: y1 - 1, a4: x1, a5: y1);
  this->DrawFilledRect(this, a2: x0, a3: y0 + 1, a4: x0 + 1, a5: y1 - 1);
  this->DrawFilledRect(this, a2: x1 - 1, a3: y0 + 1, a4: x1, a5: y1 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000C5E0
// Name: public: virtual void CWin32Surface::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawLine(CWin32Surface *this, int x0, int y0, int x1, int y1)
{
  unsigned int currentContextPanel; // ecx
  int v6; // eax
  tagPOINT pt[2]; // [esp+0h] [ebp-10h] BYREF

  currentContextPanel = this->_currentContextPanel;
  pt[0].x = x0;
  pt[0].y = y0;
  pt[1].x = x1;
  pt[1].y = y1;
  v6 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)currentContextPanel + 12))(a1: currentContextPanel);
  Polyline(hdc: *(HDC *)(v6 + 4), apt: pt, cpt: 2);
}

//------------------------------------------------------------------------------
// Address: 0x1000C620
// Name: public: virtual void CWin32Surface::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawPolyLine(CWin32Surface *this, int *px, int *py, int numPoints)
{
  _DWORD *v4; // esi
  int v5; // eax
  int *v6; // ecx
  int v7; // eax
  int v8; // [esp+0h] [ebp-Ch]

  v4 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * numPoints);
  if ( v4 != nullptr )
  {
    v5 = 0;
    if ( numPoints > 0 )
    {
      v6 = py;
      do
      {
        v4[2 * v5] = *(int *)((char *)v6 + (char *)px - (char *)py);
        v4[2 * v5++ + 1] = *v6++;
      }
      while ( v5 < numPoints );
    }
    v7 = (*(int (__thiscall **)(unsigned int, _DWORD *))(*(_DWORD *)this->_currentContextPanel + 12))(
           a1: this->_currentContextPanel,
           a2: v4);
    Polyline(hdc: *(HDC *)(v7 + 4), apt: (const POINT *)numPoints, cpt: v8);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C6A0
// Name: private: void CWin32Surface::SetLineColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetLineColor(CWin32Surface *this, Color col)
{
  HPEN__ *pen; // edi
  HPEN__ *v4; // eax
  int v5; // eax
  HPEN__ *v6; // [esp-4h] [ebp-Ch]

  pen = this->pen;
  v4 = CreatePen(iStyle: 0, cWidth: 0, color: col._color[0] | (*(unsigned __int16 *)&col._color[1] << 8));
  this->pen = v4;
  if ( v4 != nullptr )
  {
    v6 = v4;
    v5 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
    SelectObject(hdc: *(HDC *)(v5 + 4), h: v6);
  }
  if ( pen != nullptr )
    DeleteObject(ho: pen);
}

//------------------------------------------------------------------------------
// Address: 0x1000C710
// Name: public: virtual void CWin32Surface::DrawPrintText(wchar_t const __near *,int,enum FontDrawType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawPrintText(
        CWin32Surface *this,
        const wchar_t *text,
        int textLen,
        FontDrawType_t drawType)
{
  int i; // esi

  if ( text != nullptr && textLen >= 1 )
  {
    for ( i = 0; i < textLen; ++i )
      this->DrawUnicodeChar(this, a2: text[i], a3: FONT_DRAW_DEFAULT);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C750
// Name: public: virtual void CWin32Surface::DrawUnicodeString(wchar_t const __near *,enum FontDrawType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawUnicodeString(CWin32Surface *this, const wchar_t *pwString, FontDrawType_t drawType)
{
  int v4; // eax
  const wchar_t *i; // esi

  if ( pwString != nullptr )
  {
    v4 = *pwString;
    for ( i = pwString + 1; (_WORD)v4 != 0; ++i )
    {
      this->DrawUnicodeChar(this, a2: v4, a3: FONT_DRAW_DEFAULT);
      v4 = *i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C790
// Name: public: virtual void CWin32Surface::DrawUnicodeChar(wchar_t,enum FontDrawType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawUnicodeChar(CWin32Surface *this, wchar_t wch, FontDrawType_t drawType)
{
  CFontManager *v4; // eax
  CWin32Font *FontForChar; // eax
  CWin32Font *v6; // edi
  CWin32Font_vtbl *v7; // ebx
  int v8; // eax
  int v9; // eax
  UINT v10; // kr00_4
  int v11; // eax
  unsigned int m_hCurrentFont; // [esp-8h] [ebp-18h]
  wchar_t v13; // [esp-4h] [ebp-14h]
  char mbcs[8]; // [esp+8h] [ebp-8h] BYREF

  v13 = wch;
  m_hCurrentFont = this->m_hCurrentFont;
  v4 = FontManager();
  FontForChar = CFontManager::GetFontForChar(this: v4, font: m_hCurrentFont, wch: v13);
  v6 = FontForChar;
  if ( FontForChar != nullptr )
  {
    if ( this->m_pActiveFont != FontForChar )
    {
      v7 = FontForChar->__vftable;
      v8 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
      v7->SetAsActiveFont(this: v6, a2: *(HDC__ **)(v8 + 4));
      this->m_pActiveFont = v6;
    }
    if ( this->m_bSupportsUnicode )
    {
      v9 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
      ExtTextOutW(hdc: *(HDC *)(v9 + 4), x: 0, y: 0, options: 0, lprect: nullptr, lpString: &wch, c: 1u, lpDx: nullptr);
    }
    else
    {
      memset(mbcs, 0, 6);
      WideCharToMultiByte(
        CodePage: 0,
        dwFlags: 0,
        lpWideCharStr: &wch,
        cchWideChar: 1,
        lpMultiByteStr: mbcs,
        cbMultiByte: 6,
        lpDefaultChar: nullptr,
        lpUsedDefaultChar: nullptr);
      v10 = strlen(mbcs);
      v11 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
      ExtTextOutA(
        hdc: *(HDC *)(v11 + 4),
        x: 0,
        y: 0,
        options: 0,
        lprect: nullptr,
        lpString: mbcs,
        c: v10,
        lpDx: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C880
// Name: public: virtual int CWin32Surface::CreateNewTextureID(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Surface::CreateNewTextureID(CWin32Surface *this, bool procedural)
{
  return staticBindIndex++;
}

//------------------------------------------------------------------------------
// Address: 0x1000C8A0
// Name: public: virtual class vgui::IHTML __near * CWin32Surface::CreateHTMLWindow(class vgui::IHTMLEvents __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
vgui::IHTML *__thiscall CWin32Surface::CreateHTMLWindow(
        CWin32Surface *this,
        vgui::IHTMLEvents *events,
        unsigned int context)
{
  int i; // esi

  for ( i = context; i != 0; i = (*(int (__thiscall **)(int))(*(_DWORD *)i + 124))(a1: i) )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)i + 12))(a1: i) != 0 )
      break;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000C8E0
// Name: public: virtual void CWin32Surface::DrawSetTextureRGBALinear(int,unsigned char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetTextureRGBALinear(
        CWin32Surface *this,
        int id,
        const unsigned __int8 *rgba,
        int wide,
        int tall)
{
  this->DrawSetTextureRGBAEx(this, a2: id, a3: rgba, a4: wide, a5: tall, a6: IMAGE_FORMAT_RGBA8888);
}

//------------------------------------------------------------------------------
// Address: 0x1000C910
// Name: public: virtual void CWin32Surface::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawTexturedRect(CWin32Surface *this, int x0, int y0, int x1, int y1)
{
  vgui::Texture *m_pCurrentTexture; // eax
  int wide; // ebx
  unsigned int currentContextPanel; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  HGDIOBJ v15; // eax
  unsigned int v16; // edi
  int v17; // eax
  int v18; // eax
  int v19; // [esp-2Ch] [ebp-40h]
  int v20; // [esp-28h] [ebp-3Ch]
  int v21; // [esp-24h] [ebp-38h]
  HDC v22; // [esp-20h] [ebp-34h]
  HDC v23; // [esp-20h] [ebp-34h]
  int v24; // [esp-14h] [ebp-28h]
  int v25; // [esp-10h] [ebp-24h]
  HBITMAP__ *maskBitmap; // [esp-Ch] [ebp-20h]
  DWORD v27; // [esp-Ch] [ebp-20h]
  HBITMAP__ *v28; // [esp-Ch] [ebp-20h]
  HBITMAP__ *bitmap; // [esp+4h] [ebp-10h]
  HGDIOBJ oldObject; // [esp+8h] [ebp-Ch]
  int tall; // [esp+10h] [ebp-4h]
  unsigned int y1a; // [esp+28h] [ebp+14h]
  unsigned int y1b; // [esp+28h] [ebp+14h]

  if ( this->m_pCurrentTexture != nullptr
    && *(_DWORD *)((*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel)
                 + 12) != 0 )
  {
    m_pCurrentTexture = this->m_pCurrentTexture;
    wide = m_pCurrentTexture->_wide;
    tall = m_pCurrentTexture->_tall;
    currentContextPanel = this->_currentContextPanel;
    bitmap = m_pCurrentTexture->_bitmap;
    if ( m_pCurrentTexture->_bMask )
    {
      maskBitmap = m_pCurrentTexture->_maskBitmap;
      v9 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)currentContextPanel + 12))(a1: currentContextPanel);
      v10 = y1 - y0;
      oldObject = SelectObject(hdc: *(HDC *)(v9 + 12), h: maskBitmap);
      y1a = this->_currentContextPanel;
      v22 = *(HDC *)((*(int (**)(void))(*(_DWORD *)y1a + 12))() + 12);
      v11 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)y1a + 12))(a1: y1a);
      StretchBlt(
        hdcDest: *(HDC *)(v11 + 4),
        xDest: x0,
        yDest: y0,
        wDest: x1 - x0,
        hDest: v10,
        hdcSrc: v22,
        xSrc: 0,
        ySrc: 0,
        wSrc: wide,
        hSrc: tall,
        rop: 0x8800C6u);
      v12 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
      SelectObject(hdc: *(HDC *)(v12 + 12), h: bitmap);
      v27 = 15597702;
      v25 = tall;
      v24 = wide;
      y1b = this->_currentContextPanel;
      v23 = *(HDC *)((*(int (**)(void))(*(_DWORD *)y1b + 12))() + 12);
      v21 = v10;
      v20 = x1 - x0;
      v19 = y0;
      v13 = *(_DWORD *)y1b;
    }
    else
    {
      v28 = m_pCurrentTexture->_bitmap;
      v14 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)currentContextPanel + 12))(a1: currentContextPanel);
      v15 = SelectObject(hdc: *(HDC *)(v14 + 12), h: v28);
      v27 = 13369376;
      v25 = tall;
      v24 = wide;
      oldObject = v15;
      v16 = this->_currentContextPanel;
      v23 = *(HDC *)((*(int (**)(void))(*(_DWORD *)v16 + 12))() + 12);
      v21 = y1 - y0;
      v20 = x1 - x0;
      v19 = y0;
      v13 = *(_DWORD *)v16;
    }
    v17 = (*(int (**)(void))(v13 + 12))();
    StretchBlt(
      hdcDest: *(HDC *)(v17 + 4),
      xDest: x0,
      yDest: v19,
      wDest: v20,
      hDest: v21,
      hdcSrc: v23,
      xSrc: 0,
      ySrc: 0,
      wSrc: v24,
      hSrc: v25,
      rop: v27);
    v18 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
    SelectObject(hdc: *(HDC *)(v18 + 12), h: oldObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CA90
// Name: struct HBITMAP__ __near * staticCreateBitmapHandle(int,int,struct HDC__ __near *,int,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HBITMAP __cdecl staticCreateBitmapHandle(int wide, int tall, HDC__ *hdc, unsigned __int16 bpp, void **dib)
{
  HBITMAP result; // eax
  tagBITMAPINFOHEADER bitmapInfoHeader; // [esp+4h] [ebp-28h] BYREF

  bitmapInfoHeader.biHeight = -tall;
  bitmapInfoHeader.biWidth = wide;
  bitmapInfoHeader.biPlanes = 1;
  bitmapInfoHeader.biBitCount = bpp;
  bitmapInfoHeader.biSize = 40;
  memset(&bitmapInfoHeader.biCompression, 0, 24);
  result = CreateDIBSection(
             hdc,
             pbmi: (const BITMAPINFO *)&bitmapInfoHeader,
             usage: 0,
             ppvBits: dib,
             hSection: nullptr,
             offset: 0);
  if ( result == nullptr )
  {
    _Error(a1: "staticCreateBitmapHandle: can't create DIB");
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000CB20
// Name: private: bool CWin32Surface::LoadBMP(class vgui::Texture __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CWin32Surface::LoadBMP@<al>(
        CWin32Surface *this@<ecx>,
        int a2@<esi>,
        vgui::Texture *texture,
        const char *filename)
{
  void *v4; // ebx
  int v6; // esi
  SIZE_T v7; // esi
  int *v8; // edi
  CWin32Surface *v9; // ecx
  int v10; // eax
  HBITMAP__ *BitmapHandle; // eax
  bool v12; // cc
  int v13; // edx
  int wide; // ecx
  unsigned __int8 *v15; // eax
  char *v16; // ecx
  void *v17; // esi
  char buf[1024]; // [esp+4h] [ebp-41Ch] BYREF
  tagBITMAPFILEHEADER bmfHeader; // [esp+404h] [ebp-1Ch] BYREF
  CWin32Surface *v20; // [esp+414h] [ebp-Ch]
  void *hDIB; // [esp+418h] [ebp-8h]
  void *file; // [esp+41Ch] [ebp-4h]
  int j; // [esp+42Ch] [ebp+Ch]
  char j_3; // [esp+42Fh] [ebp+Fh]

  v20 = this;
  _snprintf(string: buf, count: 0x400u, format: "%s.bmp", filename);
  v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: buf, a3: "rb", a4: "SKIN");
  file = v4;
  if ( v4 == nullptr )
  {
    v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: buf, a3: "rb", a4: 0);
    file = v4;
    if ( v4 == nullptr )
      return 0;
  }
  j_3 = 0;
  v6 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFullFileSystem->Size_2)(
         a1: &g_pFullFileSystem->IBaseFileSystem,
         a2: v4,
         a3: a2);
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &bmfHeader, a3: 14, a4: v4);
  if ( bmfHeader.bfType == 19778 )
  {
    v7 = v6 - 14;
    hDIB = GlobalAlloc(uFlags: 0x42u, dwBytes: v7);
    v8 = (int *)GlobalLock(hMem: hDIB);
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8, a3: v7, a4: v4);
    texture->_wide = v8[1];
    v9 = v20;
    texture->_tall = v8[2];
    texture->_icon = nullptr;
    texture->_bMask = false;
    v10 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v9->_currentContextPanel + 12))(a1: v9->_currentContextPanel);
    BitmapHandle = staticCreateBitmapHandle(
                     wide: texture->_wide,
                     tall: texture->_tall,
                     hdc: *(HDC__ **)(v10 + 4),
                     bpp: 0x20u,
                     dib: &texture->_dib);
    v12 = texture->_tall <= 0;
    texture->_bitmap = BitmapHandle;
    j = 0;
    if ( !v12 )
    {
      do
      {
        v13 = 0;
        if ( texture->_wide > 0 )
        {
          do
          {
            wide = texture->_wide;
            v15 = (unsigned __int8 *)v8 + v13 + wide * (texture->_tall - j - 1) + 1064;
            v16 = (char *)texture->_dib + 4 * v13 + 4 * j * wide;
            *v16 = BYTE2(v8[*v15 + 10]);
            v16[1] = BYTE1(v8[*v15 + 10]);
            ++v13;
            v16[2] = v8[*v15 + 10];
            v16[3] = -1;
          }
          while ( v13 < texture->_wide );
          v4 = file;
        }
        ++j;
      }
      while ( j < texture->_tall );
    }
    v17 = hDIB;
    j_3 = 1;
    GlobalUnlock(hMem: hDIB);
    GlobalFree(hMem: v17);
  }
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
  return j_3;
}

//------------------------------------------------------------------------------
// Address: 0x1000CD00
// Name: private: bool CWin32Surface::LoadTGA(class vgui::Texture __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32Surface::LoadTGA(CWin32Surface *this, vgui::Texture *texture, const char *filename)
{
  void *v4; // esi
  int v6; // ecx
  unsigned __int8 *v7; // edi
  char *v8; // ebx
  bool v9; // zf
  int v10; // ecx
  int v11; // ebx
  unsigned __int8 *v12; // edi
  unsigned __int8 v13; // dl
  unsigned __int8 i; // cl
  int v15; // eax
  int v16; // eax
  int height; // ecx
  tagRGBQUAD v19; // ebx
  HDC v20; // eax
  HBITMAP__ *v21; // edi
  bool v22; // al
  int v23; // eax
  int k; // ebx
  int v25; // eax
  char *v26; // ecx
  unsigned __int8 *v27; // edi
  _DWORD *v28; // edx
  char buf[1024]; // [esp+Ch] [ebp-45Ch] BYREF
  BITMAPINFO pbmi; // [esp+40Ch] [ebp-5Ch] BYREF
  int column; // [esp+438h] [ebp-30h]
  tga_header_t tgaHeader; // [esp+43Ch] [ebp-2Ch] BYREF
  unsigned __int8 packetHeader; // [esp+453h] [ebp-15h] BYREF
  int row; // [esp+454h] [ebp-14h]
  unsigned __int8 j; // [esp+45Bh] [ebp-Dh]
  unsigned __int8 *rgba; // [esp+45Ch] [ebp-Ch]
  unsigned __int8 color[4]; // [esp+460h] [ebp-8h] BYREF
  bool bMask; // [esp+467h] [ebp-1h]
  int texturea; // [esp+470h] [ebp+8h]
  char *packetSize; // [esp+474h] [ebp+Ch]
  unsigned __int8 packetSize_3; // [esp+477h] [ebp+Fh]

  pbmi.bmiColors[0] = (tagRGBQUAD)this;
  _snprintf(string: buf, count: 0x400u, format: "%s.tga", filename);
  v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: buf, a3: "rb", a4: "SKIN");
  if ( v4 == nullptr )
  {
    v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: buf, a3: "rb", a4: 0);
    if ( v4 == nullptr )
      return CWin32Surface::LoadBMP(this, a2: 0, texture, filename);
  }
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &tgaHeader, a3: 18, a4: v4);
  if ( tgaHeader.image_type != 2 && tgaHeader.image_type != 10 )
  {
    vgui::g_pIVgui->DPrintf2(
      this: vgui::g_pIVgui,
      a2: "Error: texture file '%s' has invalid image_type %d\n",
      filename,
      tgaHeader.image_type);
    return 0;
  }
  if ( tgaHeader.colormap_type != 0 || tgaHeader.pixel_size != 24 && tgaHeader.pixel_size != 32 )
    return 0;
  if ( tgaHeader.id_length != 0 )
    g_pFullFileSystem->Seek(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: v4,
      a3: tgaHeader.id_length,
      a4: FILESYSTEM_SEEK_CURRENT);
  rgba = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * tgaHeader.width * tgaHeader.height);
  bMask = false;
  if ( tgaHeader.image_type == 2 )
  {
    v6 = tgaHeader.height - 1;
    for ( row = v6; v6 >= 0; row = v6 )
    {
      v7 = &rgba[4 * v6 * tgaHeader.width];
      column = 0;
      if ( tgaHeader.width != 0 )
      {
        v8 = (char *)(v7 + 2);
        packetSize = (char *)(v7 + 1);
        *(_DWORD *)color = v7 + 2;
        do
        {
          if ( tgaHeader.pixel_size == 24 )
          {
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8, a3: 1, a4: v4);
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: packetSize, a3: 1, a4: v4);
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v7, a3: 1, a4: v4);
            v8 += 4;
            v7[3] = -1;
            v7 += 4;
            packetSize += 4;
            *(_DWORD *)color = v8;
          }
          else if ( tgaHeader.pixel_size == 32 )
          {
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8, a3: 1, a4: v4);
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: packetSize, a3: 1, a4: v4);
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v7, a3: 1, a4: v4);
            g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v7 + 3, a3: 1, a4: v4);
            v9 = v7[3] == 0;
            bMask = true;
            v7[3] = !v9 - 1;
            *(_DWORD *)color += 4;
            v8 = *(char **)color;
            v7 += 4;
            packetSize += 4;
          }
          ++column;
        }
        while ( column < tgaHeader.width );
        v6 = row;
      }
      --v6;
    }
    goto breakOut;
  }
  v10 = tgaHeader.height - 1;
  row = v10;
  if ( v10 >= 0 )
  {
    while ( 1 )
    {
      v11 = 0;
      v12 = &rgba[4 * v10 * tgaHeader.width];
      if ( tgaHeader.width != 0 )
        break;
LABEL_51:
      row = --v10;
      if ( v10 < 0 )
        goto breakOut;
    }
    while ( 1 )
    {
      g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &packetHeader, a3: 1, a4: v4);
      v13 = (packetHeader & 0x7F) + 1;
      packetSize_3 = v13;
      if ( (packetHeader & 0x80u) != 0 )
      {
        if ( tgaHeader.pixel_size == 24 )
        {
          g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &color[2], a3: 1, a4: v4);
          g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &color[1], a3: 1, a4: v4);
          g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: color, a3: 1, a4: v4);
          color[3] = -1;
        }
        else
        {
          if ( tgaHeader.pixel_size != 32 )
            goto LABEL_33;
          g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &color[2], a3: 1, a4: v4);
          g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &color[1], a3: 1, a4: v4);
          g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: color, a3: 1, a4: v4);
          g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &color[3], a3: 1, a4: v4);
          bMask = true;
        }
        v13 = packetSize_3;
LABEL_33:
        for ( i = 0; i < v13; ++i )
        {
          *(_DWORD *)v12 = *(_DWORD *)color;
          ++v11;
          v12 += 4;
          if ( v11 == tgaHeader.width )
          {
            v11 = 0;
            if ( row <= 0 )
              goto breakOut;
            v15 = --row * tgaHeader.width;
            v12 = &rgba[4 * v15];
          }
        }
        goto LABEL_49;
      }
      j = 0;
      if ( (packetHeader & 0x7F) != 0xFF )
        break;
LABEL_49:
      if ( v11 >= tgaHeader.width )
      {
        v10 = row;
        goto LABEL_51;
      }
    }
    while ( tgaHeader.pixel_size != 24 )
    {
      if ( tgaHeader.pixel_size == 32 )
      {
        g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12 + 2, a3: 1, a4: v4);
        g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12 + 1, a3: 1, a4: v4);
        g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12, a3: 1, a4: v4);
        g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12 + 3, a3: 1, a4: v4);
LABEL_44:
        v13 = packetSize_3;
        v12 += 4;
      }
      if ( ++v11 == tgaHeader.width )
      {
        v11 = 0;
        if ( row <= 0 )
          goto breakOut;
        v16 = --row * tgaHeader.width;
        v12 = &rgba[4 * v16];
      }
      if ( ++j >= v13 )
        goto LABEL_49;
    }
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12 + 2, a3: 1, a4: v4);
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12 + 1, a3: 1, a4: v4);
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12, a3: 1, a4: v4);
    v12[3] = -1;
    goto LABEL_44;
  }
breakOut:
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
  height = tgaHeader.height;
  v19 = pbmi.bmiColors[0];
  texture->_wide = tgaHeader.width;
  texture->_tall = height;
  texture->_icon = nullptr;
  v20 = *(HDC *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&v19 + 48) + 12))(a1: *(_DWORD *)(*(_DWORD *)&v19 + 48))
               + 4);
  pbmi.bmiHeader.biWidth = tgaHeader.width;
  pbmi.bmiHeader.biSize = 40;
  pbmi.bmiHeader.biHeight = -tgaHeader.height;
  *(_DWORD *)&pbmi.bmiHeader.biPlanes = 2097153;
  memset(&pbmi.bmiHeader.biCompression, 0, 24);
  v21 = CreateDIBSection(hdc: v20, &pbmi, usage: 0, ppvBits: &texture->_dib, hSection: nullptr, offset: 0);
  if ( v21 == nullptr )
    _Error(a1: "staticCreateBitmapHandle: can't create DIB");
  v22 = bMask;
  texture->_bitmap = v21;
  texture->_bMask = v22;
  if ( v22 )
  {
    v23 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&v19 + 48) + 12))(a1: *(_DWORD *)(*(_DWORD *)&v19 + 48));
    texture->_maskBitmap = staticCreateBitmapHandle(
                             wide: tgaHeader.width,
                             tall: tgaHeader.height,
                             hdc: *(HDC__ **)(v23 + 4),
                             bpp: 0x20u,
                             dib: &texture->_maskDib);
  }
  else
  {
    texture->_maskBitmap = nullptr;
  }
  for ( texturea = 0; texturea < texture->_tall; ++texturea )
  {
    for ( k = 0; k < texture->_wide; ++k )
    {
      v25 = 4 * (k + texturea * texture->_wide);
      v26 = (char *)texture->_dib + v25;
      if ( bMask )
      {
        v27 = &rgba[v25 + 3];
        v28 = (char *)texture->_maskDib + v25;
        if ( *v27 != 0 )
        {
          *v28 = -1;
          *(_DWORD *)v26 = 0;
        }
        else
        {
          *v28 = 0;
          *v26 = rgba[v25 + 2];
          v26[1] = rgba[v25 + 1];
          v26[2] = rgba[v25];
          v26[3] = *v27;
        }
      }
      else
      {
        *v26 = rgba[v25 + 2];
        v26[1] = rgba[v25 + 1];
        v26[2] = rgba[v25];
        v26[3] = rgba[v25 + 3];
      }
    }
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rgba);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D3B0
// Name: public: virtual void CWin32Surface::BringToFront(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::BringToFront(CWin32Surface *this, unsigned int panel)
{
  int v2; // esi
  HWND *v3; // eax

  v2 = panel;
  if ( panel != 0 )
  {
    while ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2) == 0 )
    {
      v2 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 124))(a1: v2);
      if ( v2 == 0 )
        return;
    }
    if ( v2 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2) != 0 )
    {
      v3 = (HWND *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2);
      SetActiveWindow(hWnd: *v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D410
// Name: public: virtual void CWin32Surface::SetForegroundWindow(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetForegroundWindow(CWin32Surface *this, unsigned int panel)
{
  HWND *v2; // eax

  if ( panel != 0 && (*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 12))(a1: panel) != 0 )
  {
    v2 = (HWND *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 12))(a1: panel);
    SetForegroundWindow(hWnd: *v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D440
// Name: public: virtual void CWin32Surface::SetAsTopMost(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetAsTopMost(CWin32Surface *this, unsigned int panel, bool state)
{
  int i; // esi
  UINT v4; // edi
  HWND *v5; // eax
  HWND *v6; // eax

  for ( i = panel; i != 0; i = (*(int (__thiscall **)(int))(*(_DWORD *)i + 124))(a1: i) )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)i + 12))(a1: i) != 0 )
      break;
  }
  v4 = 3;
  if ( *(_BYTE *)((*(int (__thiscall **)(int))(*(_DWORD *)i + 12))(a1: i) + 53) != 0 )
    v4 = 19;
  v5 = (HWND *)(*(int (__thiscall **)(int))(*(_DWORD *)i + 12))(a1: i);
  if ( state )
  {
    SetFocus(hWnd: *v5);
    v6 = (HWND *)(*(int (__thiscall **)(int))(*(_DWORD *)i + 12))(a1: i);
    SetWindowPos(hWnd: *v6, hWndInsertAfter: HWND_MESSAGE|0x2, X: 0, Y: 0, cx: 0, cy: 0, uFlags: v4);
  }
  else
  {
    SetWindowPos(hWnd: *v5, hWndInsertAfter: (HWND)0xFFFFFFFE, X: 0, Y: 0, cx: 0, cy: 0, uFlags: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D4F0
// Name: public: virtual void CWin32Surface::SetPanelVisible(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetPanelVisible(CWin32Surface *this, unsigned int panel, bool visible)
{
  HWND *v3; // eax

  if ( (*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 12))(a1: panel) != 0 )
  {
    v3 = (HWND *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 12))(a1: panel);
    if ( visible )
      ShowWindow(hWnd: *v3, nCmdShow: 8);
    else
      ShowWindow(hWnd: *v3, nCmdShow: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D540
// Name: public: virtual void CWin32Surface::FlashWindow(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::FlashWindow(CWin32Surface *this, unsigned int panel, bool state)
{
  HWND *v3; // eax

  if ( (*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 12))(a1: panel) != 0 )
  {
    v3 = (HWND *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 12))(a1: panel);
    FlashWindow(hWnd: *v3, bInvert: state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D570
// Name: public: virtual void CWin32Surface::SetMinimized(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetMinimized(CWin32Surface *this, unsigned int panel, bool state)
{
  HWND *v3; // eax

  if ( (*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 12))(a1: panel) != 0 )
  {
    v3 = (HWND *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 12))(a1: panel);
    if ( state )
      ShowWindow(hWnd: *v3, nCmdShow: 6);
    else
      ShowWindow(hWnd: *v3, nCmdShow: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D5C0
// Name: public: virtual bool CWin32Surface::IsMinimized(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::IsMinimized(CWin32Surface *this, unsigned int panel)
{
  HWND *v2; // eax

  if ( *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 12))(a1: panel) == 0 )
    return false;
  v2 = (HWND *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 12))(a1: panel);
  return IsIconic(hWnd: *v2);
}

//------------------------------------------------------------------------------
// Address: 0x1000D600
// Name: public: virtual void CWin32Surface::SetTitle(unsigned int,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetTitle(CWin32Surface *this, unsigned int panel, const wchar_t *title)
{
  int v3; // esi
  HWND *v5; // eax
  HWND *v6; // eax
  char mbcs[512]; // [esp+8h] [ebp-200h] BYREF

  v3 = panel;
  if ( panel != 0 )
  {
    while ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3) == 0 )
    {
      v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
      if ( v3 == 0 )
        return;
    }
    if ( v3 != 0 )
    {
      if ( this->m_bSupportsUnicode )
      {
        v5 = (HWND *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
        SetWindowTextW(hWnd: *v5, lpString: title);
      }
      else
      {
        WideCharToMultiByte(
          CodePage: 0,
          dwFlags: 0,
          lpWideCharStr: title,
          cchWideChar: -1,
          lpMultiByteStr: mbcs,
          cbMultiByte: 512,
          lpDefaultChar: nullptr,
          lpUsedDefaultChar: nullptr);
        v6 = (HWND *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
        SetWindowTextA(hWnd: *v6, lpString: mbcs);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D6B0
// Name: public: virtual void CWin32Surface::SetAsToolBar(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetAsToolBar(CWin32Surface *this, unsigned int panel, bool state)
{
  int v3; // esi
  HWND *v4; // edi
  HWND *v5; // esi
  LONG WindowLongA; // eax

  v3 = panel;
  if ( panel != 0 )
  {
    while ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3) == 0 )
    {
      v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
      if ( v3 == 0 )
        return;
    }
    if ( v3 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3) != 0 )
    {
      v4 = (HWND *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
      v5 = (HWND *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
      WindowLongA = GetWindowLongA(hWnd: *v4, nIndex: -20);
      if ( state )
        SetWindowLongA(hWnd: *v5, nIndex: -20, dwNewLong: WindowLongA | 0x80);
      else
        SetWindowLongA(hWnd: *v5, nIndex: -20, dwNewLong: WindowLongA & 0xFFFFFF7F);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D770
// Name: public: virtual bool CWin32Surface::RecreateContext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32Surface::RecreateContext(CWin32Surface *this, int panel)
{
  unsigned int v2; // edi
  int v3; // esi
  signed int v4; // eax
  int v5; // ecx
  HDC DC; // eax
  HDC CompatibleDC; // eax
  HWND v9; // [esp-Ch] [ebp-14h]
  HDC v10; // [esp-8h] [ebp-10h]
  int tall; // [esp+4h] [ebp-4h] BYREF

  v2 = panel;
  if ( panel == 0 || (*(int (__thiscall **)(int))(*(_DWORD *)panel + 12))(a1: panel) == 0 )
    return 1;
  v3 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 12))(a1: v2);
  (*(void (__thiscall **)(unsigned int, int *, int *))(*(_DWORD *)v2 + 52))(a1: v2, a2: &panel, a3: &tall);
  v4 = *(_DWORD *)(v3 + 28);
  if ( panel > v4 || (v5 = *(_DWORD *)(v3 + 32), tall > v5) || panel < v4 - 200 || tall < v5 - 200 )
  {
    if ( *(_DWORD *)(v3 + 24) != 0 )
      DeleteObject(ho: *(HGDIOBJ *)(v3 + 24));
    DC = GetDC(hWnd: *(HWND *)v3);
    *(_DWORD *)(v3 + 8) = DC;
    *(_DWORD *)(v3 + 24) = CreateCompatibleBitmap(hdc: DC, cx: panel + 100, cy: tall + 100);
    *(_DWORD *)(v3 + 28) = panel + 100;
    *(_DWORD *)(v3 + 32) = tall + 100;
    if ( *(_DWORD *)(v3 + 12) != 0 )
      DeleteDC(hdc: *(HDC *)(v3 + 12));
    SelectObject(hdc: *(HDC *)(v3 + 4), h: *(HGDIOBJ *)(v3 + 24));
    CompatibleDC = CreateCompatibleDC(hdc: *(HDC *)(v3 + 4));
    v10 = *(HDC *)(v3 + 8);
    v9 = *(HWND *)v3;
    *(_DWORD *)(v3 + 12) = CompatibleDC;
    ReleaseDC(hWnd: v9, hDC: v10);
    *(_DWORD *)(v3 + 8) = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D870
// Name: public: virtual void CWin32Surface::EnableMouseCapture(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::EnableMouseCapture(CWin32Surface *this, unsigned int panel, bool state)
{
  int i; // esi
  HWND *v4; // eax

  for ( i = panel; i != 0; i = (*(int (__thiscall **)(int))(*(_DWORD *)i + 124))(a1: i) )
  {
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)i + 12))(a1: i) != 0 )
      break;
  }
  if ( state )
  {
    v4 = (HWND *)(*(int (__thiscall **)(int))(*(_DWORD *)i + 12))(a1: i);
    SetCapture(hWnd: *v4);
  }
  else
  {
    ReleaseCapture();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D8D0
// Name: public: virtual bool CWin32Surface::ShouldPaintChildPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::ShouldPaintChildPanel(CWin32Surface *this, unsigned int childPanel)
{
  return (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)childPanel + 28))(a1: childPanel) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D8F0
// Name: public: virtual void CWin32Surface::SwapBuffers(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SwapBuffers(CWin32Surface *this, int panel)
{
  int v2; // edi
  int v3; // esi
  HDC DC; // eax
  HRGN v5; // ecx
  int wide; // [esp+4h] [ebp-4h] BYREF

  v2 = panel;
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)panel + 12))(a1: panel) != 0 )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2);
    (*(void (__thiscall **)(int, int *, int *))(*(_DWORD *)v2 + 52))(a1: v2, a2: &wide, a3: &panel);
    DC = GetDC(hWnd: *(HWND *)v3);
    v5 = *(HRGN *)(v3 + 20);
    *(_DWORD *)(v3 + 8) = DC;
    SetRectRgn(hrgn: v5, left: 0, top: 0, right: wide, bottom: panel);
    SelectObject(hdc: *(HDC *)(v3 + 4), h: *(HGDIOBJ *)(v3 + 20));
    SetViewportOrgEx(hdc: *(HDC *)(v3 + 4), x: 0, y: 0, lppt: nullptr);
    BitBlt(
      hdc: *(HDC *)(v3 + 8),
      x: 0,
      y: 0,
      cx: wide,
      cy: panel,
      hdcSrc: *(HDC *)(v3 + 4),
      x1: 0,
      y1: 0,
      rop: 0xCC0020u);
    ReleaseDC(hWnd: *(HWND *)v3, hDC: *(HDC *)(v3 + 8));
    *(_DWORD *)(v3 + 8) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D9B0
// Name: public: virtual void CWin32Surface::ApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::ApplyChanges(CWin32Surface *this)
{
  CWin32Surface *v1; // edi
  int (__thiscall *GetPopupCount)(vgui::ISurface *); // edx
  int v3; // esi
  int v4; // esi
  HWND *v5; // ebx
  int left; // edi
  void (__thiscall *v7)(int, int *, int *); // edx
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  bool v10; // zf
  unsigned __int8 (__thiscall *v11)(int); // eax
  int (__thiscall *v12)(vgui::ISurface *); // eax
  tagRECT rect; // [esp+24h] [ebp-34h] BYREF
  int y; // [esp+34h] [ebp-24h] BYREF
  int x; // [esp+38h] [ebp-20h] BYREF
  int i; // [esp+3Ch] [ebp-1Ch]
  int stall; // [esp+40h] [ebp-18h]
  int swide; // [esp+44h] [ebp-14h]
  int sy; // [esp+48h] [ebp-10h]
  CWin32Surface *v20; // [esp+4Ch] [ebp-Ch]
  int tall; // [esp+50h] [ebp-8h] BYREF
  int wide; // [esp+54h] [ebp-4h] BYREF

  v1 = this;
  GetPopupCount = this->GetPopupCount;
  v3 = 0;
  v20 = this;
  i = 0;
  if ( ((int (__fastcall *)(CWin32Surface *))GetPopupCount)(a1: this) > 0 )
  {
    do
    {
      v4 = v1->GetPopup(this: v1, a2: v3);
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4) != 0 )
      {
        v5 = (HWND *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
        if ( v4 == v1->GetEmbeddedPanel(this: v1)
          || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 100))(a1: v4) == 0 )
        {
          ShowWindow(hWnd: *v5, nCmdShow: 0);
        }
        else
        {
          GetWindowRect(hWnd: *v5, lpRect: &rect);
          left = rect.left;
          v7 = *(void (__thiscall **)(int, int *, int *))(*(_DWORD *)v4 + 44);
          swide = rect.right - rect.left;
          stall = rect.bottom - rect.top;
          sy = rect.top;
          v7(a1: v4, a2: &x, a3: &y);
          (*(void (__thiscall **)(int, int *, int *))(*(_DWORD *)v4 + 52))(a1: v4, a2: &wide, a3: &tall);
          if ( x != left || y != sy || wide != swide || tall != stall )
          {
            SetWindowPos(hWnd: *v5, hWndInsertAfter: nullptr, X: x, Y: y, cx: wide, cy: tall, uFlags: 0x114u);
            if ( left > 0 || sy > 0 )
            {
              v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v8 != nullptr )
                v9 = KeyValues::KeyValues(this: v8, setName: "Move");
              else
                v9 = nullptr;
              ((void (__thiscall *)(vgui::IVGui *, int, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
                a1: vgui::g_pIVgui,
                a2: v4,
                a3: v9,
                a4: 0,
                a5: 0);
            }
          }
          v10 = (GetWindowLongA(hWnd: *v5, nIndex: -16) & 0x10000000) == 0;
          v11 = *(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 100);
          if ( v10 )
          {
            if ( v11(a1: v4) != 0 )
              ShowWindow(hWnd: *v5, nCmdShow: 8);
          }
          else if ( v11(a1: v4) == 0 )
          {
            ShowWindow(hWnd: *v5, nCmdShow: 0);
          }
          if ( (wide != swide || tall != stall)
            && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 100))(a1: v4) != 0 )
          {
            v20->RecreateContext(this: v20, a2: v4);
          }
          v1 = v20;
        }
      }
      v12 = v1->GetPopupCount;
      v3 = ++i;
    }
    while ( v3 < v12(this: v1) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DB90
// Name: private: void CWin32Surface::InternalSolveTraverse(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::InternalSolveTraverse(CWin32Surface *this, unsigned int panel)
{
  int i; // ebx
  unsigned int v3; // edi

  (*(void (__thiscall **)(unsigned int))(*(_DWORD *)panel + 88))(a1: panel);
  for ( i = 0; i < (*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 112))(a1: panel); ++i )
  {
    v3 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)panel + 116))(a1: panel, a2: i);
    if ( (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v3 + 100))(a1: v3) != 0 )
      CWin32Surface::InternalSolveTraverse(this, panel: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DBF0
// Name: private: void CWin32Surface::InternalThinkTraverse(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::InternalThinkTraverse(CWin32Surface *this, unsigned int panel)
{
  int v2; // eax
  int i; // ebx
  unsigned int v4; // edi

  v2 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 156))(a1: panel);
  (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 4))(a1: v2);
  for ( i = 0; i < (*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 112))(a1: panel); ++i )
  {
    v4 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)panel + 116))(a1: panel, a2: i);
    if ( (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v4 + 100))(a1: v4) != 0 )
      CWin32Surface::InternalThinkTraverse(this, panel: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DC60
// Name: private: void CWin32Surface::InternalSchemeSettingsTraverse(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::InternalSchemeSettingsTraverse(
        CWin32Surface *this,
        unsigned int panel,
        bool forceApplySchemeSettings)
{
  int i; // edi
  unsigned int v4; // ebx
  int v5; // eax

  for ( i = 0; i < (*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 112))(a1: panel); ++i )
  {
    v4 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)panel + 116))(a1: panel, a2: i);
    if ( forceApplySchemeSettings
      || (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v4 + 100))(a1: v4) != 0 )
    {
      CWin32Surface::InternalSchemeSettingsTraverse(this, panel: v4, forceApplySchemeSettings);
    }
  }
  v5 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 156))(a1: panel);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1000DCE0
// Name: public: virtual void CWin32Surface::SolveTraverse(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SolveTraverse(CWin32Surface *this, unsigned int panel, bool forceApplySchemeSettings)
{
  CWin32Surface::InternalSchemeSettingsTraverse(this, panel, forceApplySchemeSettings);
  if ( (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)panel + 100))(a1: panel) != 0 )
  {
    CWin32Surface::InternalThinkTraverse(this, panel);
    CWin32Surface::InternalSolveTraverse(this, panel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DD20
// Name: public: virtual void CWin32Surface::PaintTraverse(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::PaintTraverse(CWin32Surface *this, unsigned int panel)
{
  int v2; // eax

  v2 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 156))(a1: panel);
  (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v2 + 12))(a1: v2, a2: 0, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000DD50
// Name: public: virtual void CWin32Surface::SetBitmapFontName(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetBitmapFontName(CWin32Surface *this, int nOldWidth, int nOldHeight)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD60
// Name: public: virtual void CWin32Surface::DrawFlushText(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CWin32Surface::DrawFlushText()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD70
// Name: public: virtual void CWin32Surface::CalculateMouseVisible(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::CalculateMouseVisible(CWin32Surface *this)
{
  CWin32Surface *v1; // esi
  unsigned int v2; // esi
  char v3; // bl
  int v4; // edi
  int i; // [esp+8h] [ebp-4h]

  v1 = this;
  *(_WORD *)&this->_needKB = 0;
  i = 0;
  if ( vgui::g_pSurface->GetPopupCount(this: vgui::g_pSurface) > 0 )
  {
    do
    {
      v2 = vgui::g_pSurface->GetPopup(this: vgui::g_pSurface, a2: i);
      v3 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 100))(a1: v2);
      v4 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 124))(a1: v2);
      if ( v4 != 0 )
      {
        while ( v3 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 100))(a1: v4) != 0 )
        {
          v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 124))(a1: v4);
          if ( v4 == 0 )
            goto LABEL_6;
        }
      }
      else
      {
LABEL_6:
        if ( v3 != 0 )
        {
          this->_needMouse |= (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 172))(a1: v2);
          this->_needKB |= (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 168))(a1: v2);
        }
      }
      ++i;
    }
    while ( i < vgui::g_pSurface->GetPopupCount(this: vgui::g_pSurface) );
    v1 = this;
  }
  if ( v1->_needMouse )
  {
    v1->SetCursor(this: v1, a2: 2u);
    v1->UnlockCursor(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DE80
// Name: public: virtual bool CWin32Surface::NeedKBInput(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::NeedKBInput(CWin32Surface *this)
{
  return this->_needKB;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE90
// Name: public: virtual void CWin32Surface::SetCursor(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetCursor(CWin32Surface *this, unsigned int cursor)
{
  if ( cursor == 0 )
    goto LABEL_6;
  if ( cursor <= 0xE )
  {
    this->_currentCursor = staticDefaultCursor[cursor];
    goto LABEL_6;
  }
  if ( cursor != 15 )
LABEL_6:
    SetCursor(hCursor: this->_currentCursor);
}

//------------------------------------------------------------------------------
// Address: 0x1000DEC0
// Name: public: virtual void CWin32Surface::Invalidate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::Invalidate(CWin32Surface *this, unsigned int panel)
{
  int v2; // esi
  HWND *v3; // eax

  v2 = panel;
  if ( panel != 0 )
  {
    while ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2) == 0 )
    {
      v2 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 124))(a1: v2);
      if ( v2 == 0 )
        return;
    }
    if ( v2 != 0
      && (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v2 + 100))(a1: v2) != 0 )
    {
      v3 = (HWND *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2);
      InvalidateRect(hWnd: *v3, lpRect: nullptr, bErase: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DF30
// Name: public: virtual bool CWin32Surface::HasFocus(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32Surface::HasFocus(CWin32Surface *this)
{
  HWND Focus; // ebx
  int v4; // edi
  unsigned int v5; // eax

  Focus = GetFocus();
  if ( Focus == nullptr )
    return 0;
  v4 = 0;
  if ( this->GetPopupCount(this) <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = this->GetPopup(this, a2: v4);
    if ( Focus == *(HWND *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v5 + 12))(a1: v5) )
      break;
    if ( ++v4 >= this->GetPopupCount(this) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DFA0
// Name: public: virtual bool CWin32Surface::IsWithin(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32Surface::IsWithin(CWin32Surface *this, unsigned int x, unsigned int y)
{
  HWND v4; // ebx
  int v5; // edi
  unsigned int v6; // eax

  v4 = WindowFromPoint(Point: (POINT)__PAIR64__(y, x));
  v5 = 0;
  if ( this->GetPopupCount(this) <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = this->GetPopup(this, a2: v5);
    if ( *(HWND *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v6 + 12))(a1: v6) == v4 )
      break;
    if ( ++v5 >= this->GetPopupCount(this) )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E010
// Name: public: void CWin32Surface::setFocus(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::setFocus(CWin32Surface *this, unsigned int panel)
{
  int v2; // esi
  int v4; // edi
  unsigned int v5; // eax
  CWin32Surface_vtbl *v6; // edi
  unsigned int v7; // eax
  int v8; // eax

  v2 = panel;
  if ( panel != 0 )
  {
    while ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2) == 0 )
    {
      v2 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 124))(a1: v2);
      if ( v2 == 0 )
        return;
    }
    if ( v2 != 0 )
    {
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2) != 0
        && (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v2 + 136))(a1: v2, a2: v2) != 0 )
      {
        if ( vgui::g_pInput->GetAppModalSurface(this: vgui::g_pInput) == 0
          || (v4 = *(_DWORD *)v2,
              v5 = vgui::g_pInput->GetAppModalSurface(this: vgui::g_pInput),
              (*(unsigned __int8 (__thiscall **)(int, unsigned int))(v4 + 136))(a1: v2, a2: v5) != 0) )
        {
          (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 128))(a1: v2);
          return;
        }
        v6 = this->CBaseAppSystem<vgui::ISurface>::vgui::ISurface::IAppSystem::__vftable;
        v7 = vgui::g_pInput->GetAppModalSurface(this: vgui::g_pInput);
        v6->SetForegroundWindow(this, a2: v7);
      }
      v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 156))(a1: v2);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 48))(a1: v8, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E0F0
// Name: public: virtual unsigned long CWin32Surface::CreateFont(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWin32Surface::CreateFont(CWin32Surface *this)
{
  CFontManager *v1; // eax

  v1 = FontManager();
  return CFontManager::CreateFont(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1000E100
// Name: public: virtual bool CWin32Surface::SetFontGlyphSet(unsigned long,char const __near *,int,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::SetFontGlyphSet(
        CWin32Surface *this,
        unsigned int font,
        const char *windowsFontName,
        int tall,
        int weight,
        int blur,
        int scanlines,
        int flags,
        int nRangeMin,
        int nRangeMax)
{
  CFontManager *v10; // eax

  v10 = FontManager();
  return CFontManager::SetFontGlyphSet(
           this: v10,
           font,
           windowsFontName,
           tall,
           weight,
           blur,
           scanlines,
           flags,
           nRangeMin,
           nRangeMax);
}

//------------------------------------------------------------------------------
// Address: 0x1000E140
// Name: public: virtual int CWin32Surface::GetFontTall(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Surface::GetFontTall(CWin32Surface *this, unsigned int font)
{
  CFontManager *v2; // eax

  v2 = FontManager();
  return CFontManager::GetFontTall(this: v2, font);
}

//------------------------------------------------------------------------------
// Address: 0x1000E160
// Name: public: virtual int CWin32Surface::GetFontAscent(unsigned long,wchar_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Surface::GetFontAscent(CWin32Surface *this, unsigned int font, wchar_t wch)
{
  CFontManager *v3; // eax

  v3 = FontManager();
  return CFontManager::GetFontAscent(this: v3, font, wch);
}

//------------------------------------------------------------------------------
// Address: 0x1000E180
// Name: public: virtual bool CWin32Surface::IsFontAdditive(unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::IsFontAdditive(CWin32Surface *this, unsigned int font)
{
  CFontManager *v2; // eax

  v2 = FontManager();
  return CFontManager::IsFontAdditive(this: v2, font);
}

//------------------------------------------------------------------------------
// Address: 0x1000E1A0
// Name: public: virtual void CWin32Surface::GetCharABCwide(unsigned long,int,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::GetCharABCwide(CWin32Surface *this, unsigned int font, int ch, int *a, int *b, int *c)
{
  CFontManager *v6; // eax

  v6 = FontManager();
  CFontManager::GetCharABCwide(this: v6, font, ch, a, b, c);
}

//------------------------------------------------------------------------------
// Address: 0x1000E1D0
// Name: public: virtual int CWin32Surface::GetCharacterWidth(unsigned long,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Surface::GetCharacterWidth(CWin32Surface *this, unsigned int font, int ch)
{
  CFontManager *v3; // eax

  v3 = FontManager();
  return CFontManager::GetCharacterWidth(this: v3, font, ch);
}

//------------------------------------------------------------------------------
// Address: 0x1000E1F0
// Name: public: virtual void CWin32Surface::GetTextSize(unsigned long,wchar_t const __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::GetTextSize(
        CWin32Surface *this,
        unsigned int font,
        const wchar_t *text,
        int *wide,
        int *tall)
{
  CFontManager *v5; // eax

  v5 = FontManager();
  CFontManager::GetTextSize(this: v5, font, text, wide, tall);
}

//------------------------------------------------------------------------------
// Address: 0x1000E220
// Name: public: virtual int CWin32Surface::ComputeTextWidth(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall CWin32Surface::ComputeTextWidth(CWin32Surface *this, const wchar_t *pString)
{
  int nTall; // [esp+0h] [ebp-4h] BYREF

  nTall = (int)this;
  (*(void (__thiscall **)(char *, int, const wchar_t *, const wchar_t **, int *))(*((_DWORD *)this - 2) + 308))(
    a1: (char *)this - 8,
    a2: 1,
    a3: pString,
    a4: &pString,
    a5: &nTall);
  return pString;
}

//------------------------------------------------------------------------------
// Address: 0x1000E260
// Name: public: virtual bool CWin32Surface::SetBitmapFontGlyphSet(unsigned long,char const __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::SetBitmapFontGlyphSet(
        CWin32Surface *this,
        unsigned int font,
        const char *windowsFontName,
        float scalex,
        float scaley,
        int flags)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1000E270
// Name: public: virtual char const __near * CWin32Surface::GetFontName(unsigned long)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CWin32Surface::GetFontName(CWin32Surface *this, unsigned int font)
{
  CFontManager *v2; // eax

  v2 = FontManager();
  return CFontManager::GetFontName(this: v2, font);
}

//------------------------------------------------------------------------------
// Address: 0x1000E290
// Name: public: virtual void CWin32Surface::DrawFilledRectFastFade(int,int,int,int,int,int,unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawFilledRectFastFade(
        CWin32Surface *this,
        int x0,
        int y0,
        int x1,
        int y1,
        int fadeStartPt,
        int fadeEndPt,
        int alpha0,
        unsigned int alpha1,
        bool bHorizontal)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000E2A0
// Name: public: virtual void CWin32Surface::GetWorkspaceBounds(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::GetWorkspaceBounds(CWin32Surface *this, int *x, int *y, int *wide, int *tall)
{
  int top; // edx
  tagRECT rcScreen; // [esp+0h] [ebp-10h] BYREF

  SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: &rcScreen, fWinIni: 0);
  top = rcScreen.top;
  *x = rcScreen.left;
  *y = top;
  *wide = rcScreen.right - *x;
  *tall = rcScreen.bottom - *y;
}

//------------------------------------------------------------------------------
// Address: 0x1000E2E0
// Name: public: virtual void CWin32Surface::GetAbsoluteWindowBounds(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::GetAbsoluteWindowBounds(CWin32Surface *this, int *x, int *y, int *wide, int *tall)
{
  *x = 0;
  *y = 0;
  this->GetScreenSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1000E310
// Name: public: virtual void CWin32Surface::PlaySound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::PlaySound(CWin32Surface *this, const char *fileName)
{
  char localPath[260]; // [esp+0h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->GetLocalPath(this: g_pFullFileSystem, a2: fileName, a3: localPath, a4: 260) != nullptr )
  {
    g_pFullFileSystem->GetLocalCopy(this: g_pFullFileSystem, a2: localPath);
    PlaySoundA(pszSound: localPath, hmod: nullptr, fdwSound: 0x22013u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E370
// Name: public: virtual void CWin32Surface::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::RunFrame(CWin32Surface *this)
{
  int MessageA; // eax
  tagMSG msg; // [esp+4h] [ebp-1Ch] BYREF

  if ( vgui::g_pIVgui->GetShouldVGuiControlSleep(this: vgui::g_pIVgui)
    || PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
  {
    do
    {
      MessageA = GetMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0);
      if ( MessageA == 0 )
        break;
      if ( MessageA == -1 )
      {
        vgui::g_pIVgui->Stop(this: vgui::g_pIVgui);
        return;
      }
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    while ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E410
// Name: public: virtual bool CWin32Surface::SupportsFontFeature(enum FontFeature_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::SupportsFontFeature(CWin32Surface *this, FontFeature_t feature)
{
  return feature == FONT_FEATURE_ANTIALIASED_FONTS;
}

//------------------------------------------------------------------------------
// Address: 0x1000E430
// Name: public: virtual bool CWin32Surface::SupportsFeature(enum vgui::ISurface::SurfaceFeature_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::SupportsFeature(CWin32Surface *this, vgui::ISurface::SurfaceFeature_t feature)
{
  bool result; // al

  switch ( feature )
  {
    case ANTIALIASED_FONTS:
    case DROPSHADOW_FONTS:
    case OUTLINE_FONTS:
      result = this->SupportsFontFeature(this: &this->ISchemeSurface, a2: (FontFeature_t)feature);
      break;
    case ESCAPE_KEY:
    case OPENING_NEW_HTML_WINDOWS:
    case FRAME_MINIMIZE_MAXIMIZE:
    case DIRECT_HWND_RENDER:
      result = true;
      break;
    default:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E480
// Name: public: virtual void CWin32Surface::SetLanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetLanguage(CWin32Surface *this, const char *pLanguage)
{
  CFontManager *v2; // eax

  v2 = FontManager();
  CFontManager::SetLanguage(this: v2, pLanguage);
}

//------------------------------------------------------------------------------
// Address: 0x1000E4A0
// Name: public: virtual char const __near * CWin32Surface::GetLanguage(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CWin32Surface::GetLanguage(CWin32Surface *this)
{
  CFontManager *v1; // eax

  v1 = FontManager();
  return CFontManager::GetLanguage(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1000E4B0
// Name: staticNotifyIconProc
// Source: json
//------------------------------------------------------------------------------
void __usercall staticNotifyIconProc(int lparam@<eax>, HWND__ *hwnd)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  vgui::IVGui_vtbl *v6; // esi
  int v7; // eax

  if ( lparam > 515 )
  {
    if ( lparam != 517 )
      return;
    goto LABEL_12;
  }
  if ( lparam == 515 )
  {
    SetForegroundWindow(hWnd: hwnd);
    if ( vgui::g_pSurface->GetNotifyPanel(this: vgui::g_pSurface) == 0 )
      return;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v4, setName: "NotifyIconMsg", firstKey: "msg", firstValue: "LBUTTONDBLCLK");
      goto LABEL_17;
    }
LABEL_16:
    v3 = nullptr;
    goto LABEL_17;
  }
  if ( lparam == 123 )
  {
LABEL_12:
    if ( vgui::g_pSurface->GetNotifyPanel(this: vgui::g_pSurface) == 0 )
      return;
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v5, setName: "NotifyIconMsg", firstKey: "msg", firstValue: "CONTEXTMENU");
      goto LABEL_17;
    }
    goto LABEL_16;
  }
  if ( lparam == 513 && g_Surface._notifyPanel != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "NotifyIconMsg", firstKey: "msg", firstValue: "WM_LBUTTONDOWN");
LABEL_17:
      v6 = vgui::g_pIVgui->__vftable;
      v7 = ((int (__thiscall *)(vgui::ISurface *, KeyValues *, _DWORD, _DWORD))vgui::g_pSurface->GetNotifyPanel)(
             a1: vgui::g_pSurface,
             a2: v3,
             a3: 0,
             a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessageA)(a1: vgui::g_pIVgui, a2: v7);
      return;
    }
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E5A0
// Name: PostCursorMoved
// Source: json
//------------------------------------------------------------------------------
void __usercall PostCursorMoved(int lparam@<eax>, HWND__ *hwnd)
{
  tagPOINT pt; // [esp+0h] [ebp-8h] BYREF

  pt.x = (__int16)lparam;
  pt.y = SHIWORD(lparam);
  ClientToScreen(hWnd: hwnd, lpPoint: &pt);
  vgui::g_pInput->InternalCursorMoved(this: vgui::g_pInput, a2: pt.x, a3: pt.y);
}

//------------------------------------------------------------------------------
// Address: 0x1000E5E0
// Name: staticProc
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall staticProc(HWND hwnd, UINT msg, unsigned int wparam, unsigned int lparam)
{
  unsigned int v5; // esi
  vgui::IVGui_vtbl *v6; // edi
  LONG WindowLongA; // eax
  unsigned int v8; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  vgui::IPanel_vtbl *v12; // esi
  int v13; // eax
  bool v15; // zf
  unsigned int v16; // esi
  unsigned int v17; // esi
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  ButtonCode_t v20; // eax
  ButtonCode_t v21; // esi
  void (__thiscall *SetKeyCodeState)(vgui::IInputInternal *, ButtonCode_t, bool); // eax
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  tagPAINTSTRUCT ps; // [esp+14h] [ebp-50h] BYREF
  tagPOINT Point; // [esp+54h] [ebp-10h] BYREF
  unsigned int panel; // [esp+5Ch] [ebp-8h]
  bool bMMButtonDown; // [esp+63h] [ebp-1h]
  bool sendToDefWindowProc_3; // [esp+6Fh] [ebp+Bh]
  bool bRMButtonDown_3; // [esp+7Bh] [ebp+17h]
  bool bRMButtonDown_3a; // [esp+7Bh] [ebp+17h]

  v5 = 0;
  panel = 0;
  Point.y = 0;
  if ( staticSurfaceAvailable )
  {
    v6 = vgui::g_pIVgui->__vftable;
    WindowLongA = GetWindowLongA(hWnd: hwnd, nIndex: -21);
    v8 = v6->HandleToPanel(this: vgui::g_pIVgui, a2: WindowLongA);
    panel = v8;
    if ( v8 != 0 )
    {
      v5 = panel;
      Point.y = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v8 + 156))(a1: v8);
    }
    else
    {
      v5 = 0;
    }
  }
  if ( msg == staticShutdownMsg )
  {
    vgui::g_pIVgui->ShutdownMessage(this: vgui::g_pIVgui, a2: lparam);
    return DefWindowProcA(hWnd: hwnd, Msg: msg, wParam: wparam, lParam: lparam);
  }
  if ( msg != 22 || wparam != 1 )
  {
    if ( v5 == 0 )
      return DefWindowProcA(hWnd: hwnd, Msg: msg, wParam: wparam, lParam: lparam);
    sendToDefWindowProc_3 = !ImmIsUIMessageA(a1: nullptr, a2: msg, a3: wparam, a4: lparam);
    if ( msg <= 0x200 )
    {
      if ( msg == 512 )
      {
        Point.x = (__int16)lparam;
        Point.y = SHIWORD(lparam);
        bMMButtonDown = (wparam & 0x10) != 0;
        if ( (wparam & 1) == 0 && vgui::g_pInput->IsMouseDown(this: vgui::g_pInput, a2: KEY_COUNT) )
        {
          vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: KEY_COUNT, a3: BUTTON_RELEASED);
          vgui::g_pInput->InternalMouseReleased(this: vgui::g_pInput, a2: KEY_COUNT);
        }
        if ( (wparam & 2) == 0 && vgui::g_pInput->IsMouseDown(this: vgui::g_pInput, a2: MOUSE_RIGHT) )
        {
          vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: KEY_COUNT, a3: BUTTON_RELEASED);
          vgui::g_pInput->InternalMouseReleased(this: vgui::g_pInput, a2: KEY_COUNT);
        }
        if ( !bMMButtonDown && vgui::g_pInput->IsMouseDown(this: vgui::g_pInput, a2: MOUSE_MIDDLE) )
        {
          vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: MOUSE_MIDDLE, a3: BUTTON_RELEASED);
          vgui::g_pInput->InternalMouseReleased(this: vgui::g_pInput, a2: MOUSE_MIDDLE);
        }
        ClientToScreen(hWnd: hwnd, lpPoint: &Point);
        vgui::g_pInput->InternalCursorMoved(this: vgui::g_pInput, a2: Point.x, a3: Point.y);
      }
      else if ( msg > 0xF )
      {
        switch ( msg )
        {
          case 0x10u:
            v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v18 != nullptr )
              v19 = KeyValues::KeyValues(this: v18, setName: "Close");
            else
              v19 = nullptr;
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
              a1: vgui::g_pIVgui,
              a2: v5,
              a3: v19,
              a4: 0,
              a5: 0);
            return 0;
          case 0x14u:
            (*(void (__thiscall **)(int))(*(_DWORD *)Point.y + 16))(a1: Point.y);
            break;
          case 0x20u:
            break;
          case 0x100u:
          case 0x104u:
            v20 = KeyCode_VirtualKeyToVGUI(key: wparam);
            g_iPreviousKeyCode = v20;
            bRMButtonDown_3a = (lparam & 0x40000000) != 0;
            if ( (lparam & 0x40000000) == 0 )
            {
              vgui::g_pInput->SetKeyCodeState(this: vgui::g_pInput, a2: v20, a3: true);
              vgui::g_pInput->InternalKeyCodePressed(this: vgui::g_pInput, a2: g_iPreviousKeyCode);
              v20 = g_iPreviousKeyCode;
            }
            vgui::g_pInput->InternalKeyCodeTyped(this: vgui::g_pInput, a2: v20);
            if ( bRMButtonDown_3a || wparam != 20 && wparam != 145 && wparam != 144 )
              break;
            if ( wparam == 144 )
            {
              v21 = KEY_NUMLOCKTOGGLE;
            }
            else if ( wparam == 145 )
            {
              v21 = KEY_SCROLLLOCKTOGGLE;
            }
            else
            {
              v21 = KEY_CAPSLOCKTOGGLE;
            }
            v15 = (GetKeyState(nVirtKey: wparam) & 1) == 0;
            SetKeyCodeState = vgui::g_pInput->SetKeyCodeState;
            if ( v15 )
              goto LABEL_53;
            ((void (__stdcall *)(ButtonCode_t, int))SetKeyCodeState)(a1: v21, a2: 1);
            vgui::g_pInput->InternalKeyCodePressed(this: vgui::g_pInput, a2: v21);
            break;
          case 0x101u:
          case 0x105u:
            v21 = KeyCode_VirtualKeyToVGUI(key: wparam);
            SetKeyCodeState = vgui::g_pInput->SetKeyCodeState;
LABEL_53:
            ((void (__stdcall *)(ButtonCode_t, _DWORD))SetKeyCodeState)(a1: v21, a2: 0);
            vgui::g_pInput->InternalKeyCodeReleased(this: vgui::g_pInput, a2: v21);
            break;
          case 0x102u:
          case 0x106u:
            vgui::g_pInput->InternalKeyTyped(this: vgui::g_pInput, a2: wparam);
            break;
          default:
            goto LABEL_84;
        }
      }
      else
      {
        switch ( msg )
        {
          case 0xFu:
            bRMButtonDown_3 = vgui::g_pIPanel->IsVisible(this: vgui::g_pIPanel, a2: v5);
            v16 = vgui::g_pIPanel->GetParent(this: vgui::g_pIPanel, a2: v5);
            if ( v16 != 0 )
            {
              while ( bRMButtonDown_3 && vgui::g_pIPanel->IsVisible(this: vgui::g_pIPanel, a2: v16) )
              {
                v16 = vgui::g_pIPanel->GetParent(this: vgui::g_pIPanel, a2: v16);
                if ( v16 == 0 )
                  goto LABEL_30;
              }
            }
            else
            {
LABEL_30:
              if ( bRMButtonDown_3 )
              {
                BeginPaint(hWnd: hwnd, lpPaint: &ps);
                v17 = panel;
                CWin32Surface::SolveTraverse(this: &g_Surface, panel, forceApplySchemeSettings: false);
                CWin32Surface::PaintTraverse(this: &g_Surface, panel: v17);
                EndPaint(hWnd: hwnd, lpPaint: &ps);
              }
            }
            ValidateRect(hWnd: hwnd, lpRect: nullptr);
            break;
          case 1u:
            s_uTaskbarRestart = RegisterWindowMessageA(lpString: "TaskbarCreated");
            break;
          case 7u:
            CWin32Surface::setFocus(this: &g_Surface, panel: v5);
            break;
          default:
            v15 = msg == 8;
LABEL_83:
            if ( !v15 )
            {
LABEL_84:
              if ( msg == s_uTaskbarRestart )
              {
                v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                if ( v23 != nullptr )
                  v24 = KeyValues::KeyValues(this: v23, setName: "TaskbarRestart");
                else
                  v24 = nullptr;
                ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
                  a1: vgui::g_pIVgui,
                  a2: v5,
                  a3: v24,
                  a4: 0,
                  a5: 0);
              }
            }
            break;
        }
      }
$LN105:
      if ( sendToDefWindowProc_3 )
        return DefWindowProcA(hWnd: hwnd, Msg: msg, wParam: wparam, lParam: lparam);
      else
        return 1;
    }
    if ( msg <= 0x401 )
    {
      if ( msg == 1025 )
      {
        staticNotifyIconProc(lparam, hwnd);
      }
      else
      {
        switch ( msg )
        {
          case 0x201u:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: KEY_COUNT, a3: BUTTON_PRESSED);
            vgui::g_pInput->InternalMousePressed(this: vgui::g_pInput, a2: KEY_COUNT);
            break;
          case 0x202u:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: KEY_COUNT, a3: BUTTON_RELEASED);
            vgui::g_pInput->InternalMouseReleased(this: vgui::g_pInput, a2: KEY_COUNT);
            break;
          case 0x203u:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: KEY_COUNT, a3: BUTTON_DOUBLECLICKED);
            vgui::g_pInput->InternalMouseDoublePressed(this: vgui::g_pInput, a2: KEY_COUNT);
            break;
          case 0x204u:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: MOUSE_RIGHT, a3: BUTTON_PRESSED);
            vgui::g_pInput->InternalMousePressed(this: vgui::g_pInput, a2: MOUSE_RIGHT);
            break;
          case 0x205u:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: MOUSE_RIGHT, a3: BUTTON_RELEASED);
            vgui::g_pInput->InternalMouseReleased(this: vgui::g_pInput, a2: MOUSE_RIGHT);
            break;
          case 0x206u:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: MOUSE_RIGHT, a3: BUTTON_DOUBLECLICKED);
            vgui::g_pInput->InternalMouseDoublePressed(this: vgui::g_pInput, a2: MOUSE_RIGHT);
            break;
          case 0x207u:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: MOUSE_MIDDLE, a3: BUTTON_PRESSED);
            vgui::g_pInput->InternalMousePressed(this: vgui::g_pInput, a2: MOUSE_MIDDLE);
            break;
          case 0x208u:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: MOUSE_MIDDLE, a3: BUTTON_RELEASED);
            vgui::g_pInput->InternalMouseReleased(this: vgui::g_pInput, a2: MOUSE_MIDDLE);
            break;
          case 0x209u:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(this: vgui::g_pInput, a2: MOUSE_MIDDLE, a3: BUTTON_DOUBLECLICKED);
            vgui::g_pInput->InternalMouseDoublePressed(this: vgui::g_pInput, a2: MOUSE_MIDDLE);
            break;
          case 0x20Au:
            vgui::g_pInput->InternalMouseWheeled(this: vgui::g_pInput, a2: SHIWORD(wparam) / 120);
            break;
          case 0x20Bu:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(
              this: vgui::g_pInput,
              a2: (ButtonCode_t)((HIWORD(wparam) != 1) + 110),
              a3: BUTTON_PRESSED);
            vgui::g_pInput->InternalMousePressed(this: vgui::g_pInput, a2: (ButtonCode_t)((HIWORD(wparam) != 1) + 110));
            break;
          case 0x20Cu:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(
              this: vgui::g_pInput,
              a2: (ButtonCode_t)((HIWORD(wparam) != 1) + 110),
              a3: BUTTON_RELEASED);
            vgui::g_pInput->InternalMouseReleased(this: vgui::g_pInput, a2: (ButtonCode_t)((HIWORD(wparam) != 1) + 110));
            break;
          case 0x20Du:
            PostCursorMoved(lparam, hwnd);
            vgui::g_pInput->SetMouseCodeState(
              this: vgui::g_pInput,
              a2: (ButtonCode_t)((HIWORD(wparam) != 1) + 110),
              a3: BUTTON_DOUBLECLICKED);
            vgui::g_pInput->InternalMouseDoublePressed(
              this: vgui::g_pInput,
              a2: (ButtonCode_t)((HIWORD(wparam) != 1) + 110));
            break;
          default:
            goto LABEL_84;
        }
      }
      goto $LN105;
    }
    v15 = msg == 0x8000;
    goto LABEL_83;
  }
  if ( vgui::g_pSurface->GetEmbeddedPanel(this: vgui::g_pSurface) != 0 )
  {
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "WindowsEndSession");
    else
      v11 = nullptr;
    v12 = vgui::g_pIPanel->__vftable;
    v13 = ((int (__thiscall *)(vgui::ISurface *, KeyValues *, _DWORD))vgui::g_pSurface->GetEmbeddedPanel)(
            a1: vgui::g_pSurface,
            a2: v11,
            a3: 0);
    ((void (__thiscall *)(vgui::IPanel *, int))v12->SendMessage)(a1: vgui::g_pIPanel, a2: v13);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000EF80
// Name: bool ValveFont::DecodeFont(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ValveFont::DecodeFont(CUtlBuffer *buffer)
{
  int m_Put; // edi
  unsigned __int8 *m_pMemory; // eax
  unsigned int v4; // ecx
  const char *v5; // edx
  unsigned __int8 *v6; // esi
  unsigned __int8 v7; // cl
  int v8; // edi
  char v9; // cl
  char v10; // bl
  unsigned __int8 *i; // esi
  int j; // esi
  unsigned __int8 v13; // dl

  m_Put = buffer->m_Put;
  if ( m_Put <= 6 )
    return 0;
  m_pMemory = buffer->m_Memory.m_pMemory;
  v4 = 6;
  v5 = "VFONT1";
  v6 = &buffer->m_Memory.m_pMemory[m_Put - 6];
  do
  {
    if ( *(_DWORD *)v6 != *(_DWORD *)v5 )
      return 0;
    v4 -= 4;
    v5 += 4;
    v6 += 4;
  }
  while ( v4 >= 4 );
  if ( v4 != 0 && (*v5 != *v6 || v4 > 1 && (v5[1] != v6[1] || v4 > 2 && v5[2] != v6[2])) )
    return 0;
  v7 = m_pMemory[m_Put - 7];
  v8 = m_Put - 6 - v7;
  v9 = v7 - 1;
  v10 = -89;
  for ( i = &m_pMemory[v8]; v9 != 0; ++i )
  {
    --v9;
    v10 ^= *i - 89;
  }
  for ( j = v8; j > 0; ++m_pMemory )
  {
    v13 = v10 ^ *m_pMemory;
    --j;
    v10 = *m_pMemory - 89;
    *m_pMemory = v13;
  }
  CUtlBuffer::SeekPut(this: buffer, type: SEEK_HEAD, offset: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F070
// Name: public: virtual class IMaterial __near * ISchemeSurface::GetTextureForChar(struct FontCharRenderInfo __near &,float __near * __near *)
// Source: json
//------------------------------------------------------------------------------
struct IMaterial *__thiscall ISchemeSurface::GetTextureForChar(
        ISchemeSurface *this,
        FontCharRenderInfo *info,
        FontCharRenderInfo *texCoords)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000F080
// Name: public: virtual bool ISchemeSurface::GetUnicodeCharRenderPositions(struct FontCharRenderInfo __near &,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ISchemeSurface::GetUnicodeCharRenderPositions(
        ISchemeSurface *this,
        FontCharRenderInfo *info,
        FontCharRenderInfo *pPositions)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1000F090
// Name: public: virtual void CWin32Surface::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetTextColor(
        CWin32Surface *this,
        int r,
        unsigned __int8 g,
        unsigned __int8 b,
        char a)
{
  int v6; // eax

  BYTE2(r) = b;
  BYTE1(r) = g;
  HIBYTE(r) = a;
  CWin32Surface::SetLineColor(this, col: (Color)r);
  v6 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
  SetTextColor(hdc: *(HDC *)(v6 + 4), color: (unsigned __int8)r | ((g | (b << 8)) << 8));
}

//------------------------------------------------------------------------------
// Address: 0x1000F0F0
// Name: public: virtual void CWin32Surface::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetTextColor(CWin32Surface *this, Color col)
{
  CWin32Surface::SetLineColor(this, col);
  this->DrawSetTextColor_2(this, a2: col._color[0], a3: col._color[1], a4: col._color[2], a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x1000F130
// Name: public: CIconImage::CIconImage(struct HICON__ __near *)
// Source: json
//------------------------------------------------------------------------------
CIconImage *__thiscall CIconImage::CIconImage(CIconImage *this, HICON__ *hIcon)
{
  HICON__ *v3; // eax
  int v4; // edi
  int v5; // ebx
  _BYTE pv[4]; // [esp+8h] [ebp-2Ch] BYREF
  int v8; // [esp+Ch] [ebp-28h]
  int v9; // [esp+10h] [ebp-24h]
  _ICONINFO iconInfo; // [esp+20h] [ebp-14h] BYREF

  this->__vftable = (CIconImage_vtbl *)&CIconImage::`vftable';
  v3 = CopyIcon(hIcon);
  v4 = 0;
  this->m_hIcon = v3;
  this->m_Pos.y = 0;
  this->m_Pos.x = 0;
  if ( GetIconInfo(hIcon: v3, piconinfo: &iconInfo) )
  {
    v5 = 0;
    if ( GetObjectA(h: iconInfo.hbmColor, c: 24, pv) != 0 )
    {
      v4 = v8;
      v5 = v9;
    }
    this->m_Size.cy = v5;
    this->m_Size.cx = v4;
    return this;
  }
  else
  {
    this->m_Size.cy = 0;
    this->m_Size.cx = 0;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F1B0
// Name: public: virtual void CIconImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconImage::Paint(CIconImage *this)
{
  int v2; // eax

  if ( this->m_hIcon != nullptr && this->m_Size.cx != 0 && this->m_Size.cy != 0 )
  {
    v2 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)g_Surface._currentContextPanel + 12))(a1: g_Surface._currentContextPanel);
    DrawIconEx(
      hdc: *(HDC *)(v2 + 4),
      xLeft: this->m_Pos.x,
      yTop: this->m_Pos.y,
      hIcon: this->m_hIcon,
      cxWidth: this->m_Size.cx,
      cyWidth: this->m_Size.cy,
      istepIfAniCur: 0,
      hbrFlickerFreeDraw: nullptr,
      diFlags: 3u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F200
// Name: public: virtual void CIconImage::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconImage::SetPos(CIconImage *this, int x, int y)
{
  this->m_Pos.x = x;
  this->m_Pos.y = y;
}

//------------------------------------------------------------------------------
// Address: 0x1000F220
// Name: public: virtual void CIconImage::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconImage::GetContentSize(CIconImage *this, tagSIZE *wide, int *tall)
{
  *wide = this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1000F240
// Name: public: virtual void CIconImage::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconImage::GetSize(CIconImage *this, int *wide, int *tall)
{
  this->GetContentSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1000F250
// Name: public: virtual void CIconImage::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIconImage::SetColor(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000F2A0
// Name: private: void CWin32Surface::initStaticData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::initStaticData(CWin32Surface *this)
{
  unsigned __int16 v1; // si
  const char *v2; // eax
  unsigned int wTmpIconID; // [esp+4h] [ebp-4h] BYREF

  staticDefaultCursor[1] = nullptr;
  staticDefaultCursor[2] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  staticDefaultCursor[3] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F01);
  staticDefaultCursor[4] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F02);
  staticDefaultCursor[5] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F8A);
  staticDefaultCursor[6] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F03);
  staticDefaultCursor[7] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F04);
  staticDefaultCursor[8] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F82);
  staticDefaultCursor[9] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F83);
  staticDefaultCursor[10] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
  staticDefaultCursor[11] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F85);
  staticDefaultCursor[12] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
  staticDefaultCursor[13] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F88);
  staticDefaultCursor[14] = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F89);
  *(_QWORD *)&staticWndclass.cbClsExtra = 0;
  *(_QWORD *)&staticWndclass.hInstance = 0;
  *(_QWORD *)&staticWndclass.hCursor = 0;
  *(_QWORD *)&staticWndclass.lpszMenuName = 0;
  staticWndclass.style = 11;
  staticWndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))staticProc;
  staticWndclass.hInstance = GetModuleHandleA(lpModuleName: nullptr);
  v1 = 101;
  v2 = getenv(option: "__STEAM_BOOTSTRAPPER_ICON_ID__");
  if ( v2 != nullptr )
  {
    wTmpIconID = 0;
    if ( sscanf(string: v2, format: "%u", &wTmpIconID) == 1 && wTmpIconID > 0x65 )
      v1 = wTmpIconID;
  }
  staticWndclass.hIcon = LoadIconA(hInstance: staticWndclass.hInstance, lpIconName: (LPCSTR)v1);
  staticWndclass.lpszClassName = "Surface";
  staticWndclassAtom = RegisterClassA(lpWndClass: &staticWndclass);
  staticShutdownMsg = RegisterWindowMessageA(lpString: "ShutdownValvePlatform");
}

//------------------------------------------------------------------------------
// Address: 0x1000F440
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<vgui::Texture,int> *m_pMemory; // edx

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
      this->m_pMemory = (UtlRBTreeNode_t<vgui::Texture,int> *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<vgui::Texture,int> *)_g_pMemAlloc->Alloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F500
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short> *m_pMemory; // edx
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: m_pMemory,
                                                                                            a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F5B0
// Name: public: unsigned short CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100517B8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_100517B8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x1000F620
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F6D0
// Name: private: virtual long CSurfaceDragDropTarget::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CSurfaceDragDropTarget::QueryInterface(
        CSurfaceDragDropTarget *this,
        const _GUID *riid,
        void **ppvObject)
{
  if ( IsEqualGUID(rguid1: riid, rguid2: &IID_IDropTarget) == 0 )
    return -2147467262;
  *ppvObject = this;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F700
// Name: private: virtual unsigned long CSurfaceDragDropTarget::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CSurfaceDragDropTarget::AddRef(CSurfaceDragDropTarget *this)
{
  unsigned int result; // eax

  result = this->_refCount + 1;
  this->_refCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F720
// Name: private: virtual unsigned long CSurfaceDragDropTarget::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CSurfaceDragDropTarget::Release(CSurfaceDragDropTarget *this)
{
  unsigned int result; // eax

  result = this->_refCount - 1;
  this->_refCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F740
// Name: private: virtual long CSurfaceDragDropTarget::DragEnter(struct IDataObject __near *,unsigned long,struct _POINTL,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CSurfaceDragDropTarget::DragEnter(
        CSurfaceDragDropTarget *this,
        IDataObject *pDataObject,
        unsigned int grfKeyState,
        _POINTL pt,
        unsigned int *pdwEffect)
{
  KeyValues *dragData; // ecx

  dragData = this->_dragData;
  if ( dragData != nullptr )
    KeyValues::deleteThis(this: dragData);
  this->_dragData = this->calculateData(this, a2: pDataObject);
  return ((HRESULT (__stdcall *)(CSurfaceDragDropTarget *, unsigned int, int, int, unsigned int *))this->DragOver)(
           a1: this,
           a2: grfKeyState,
           a3: pt.x,
           a4: pt.y,
           a5: pdwEffect);
}

//------------------------------------------------------------------------------
// Address: 0x1000F780
// Name: private: virtual long CSurfaceDragDropTarget::DragOver(unsigned long,struct _POINTL,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CSurfaceDragDropTarget::DragOver(
        CSurfaceDragDropTarget *this,
        unsigned int grfKeyState,
        _POINTL pt,
        unsigned int *pdwEffect)
{
  unsigned int v4; // eax
  int v5; // eax

  *pdwEffect = 0;
  if ( this->_dragData != nullptr && vgui::g_pIVgui->IsRunning(this: vgui::g_pIVgui) )
  {
    v4 = vgui::g_pInput->GetMouseOver(this: vgui::g_pInput);
    if ( v4 != 0 )
    {
      v5 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v4 + 156))(a1: v4);
      if ( (*(unsigned __int8 (__thiscall **)(int, KeyValues *))(*(_DWORD *)v5 + 44))(a1: v5, a2: this->_dragData) != 0 )
        *pdwEffect = 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F7F0
// Name: private: virtual long CSurfaceDragDropTarget::Drop(struct IDataObject __near *,unsigned long,struct _POINTL,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CSurfaceDragDropTarget::Drop(
        CSurfaceDragDropTarget *this,
        IDataObject *pDataObject,
        unsigned int grfKeyState,
        _POINTL pt,
        unsigned int *pdwEffect)
{
  void *Ptr; // eax
  KeyValues *dragData; // edx
  KeyValues *v7; // ecx

  *pdwEffect = 0;
  if ( this->_dragData != nullptr && vgui::g_pIVgui->IsRunning(this: vgui::g_pIVgui) )
  {
    Ptr = KeyValues::GetPtr(this: this->_dragData, keyName: "AcceptPanel", defaultValue: nullptr);
    if ( Ptr != nullptr )
    {
      dragData = this->_dragData;
      if ( dragData != nullptr )
      {
        ((void (__thiscall *)(vgui::IVGui *, void *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
          a1: vgui::g_pIVgui,
          a2: Ptr,
          a3: dragData,
          a4: 0,
          a5: 0);
        this->_dragData = nullptr;
      }
    }
    v7 = this->_dragData;
    if ( v7 != nullptr )
      KeyValues::deleteThis(this: v7);
    this->_dragData = nullptr;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F870
// Name: private: virtual class KeyValues __near * CSurfaceDragDropTarget::calculateData(struct IDataObject __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CSurfaceDragDropTarget::calculateData(CSurfaceDragDropTarget *this, KeyValues *pDataObject)
{
  HRESULT (__stdcall *v2)(IDataObject *, tagFORMATETC *, tagSTGMEDIUM *); // ecx
  KeyValues *v3; // esi
  const char *v4; // edi
  KeyValues *v5; // eax
  HRESULT (__stdcall *v7)(IDataObject *, tagFORMATETC *, tagSTGMEDIUM *); // eax
  KeyValues *v8; // eax
  signed int v9; // esi
  HDROP v10; // edi
  signed int FileA; // ebx
  char buf[512]; // [esp+Ch] [ebp-244h] BYREF
  char namebuf[32]; // [esp+20Ch] [ebp-44h] BYREF
  tagFORMATETC format; // [esp+22Ch] [ebp-24h] BYREF
  KeyValues *fileList; // [esp+240h] [ebp-10h]
  tagSTGMEDIUM storage; // [esp+244h] [ebp-Ch] BYREF
  KeyValues *dragData; // [esp+258h] [ebp+8h]

  v2 = *(HRESULT (__stdcall **)(IDataObject *, tagFORMATETC *, tagSTGMEDIUM *))(*(_DWORD *)pDataObject + 12);
  format.cfFormat = 1;
  v3 = nullptr;
  format.ptd = nullptr;
  format.dwAspect = 1;
  format.lindex = -1;
  format.tymed = 1;
  if ( v2(this: (IDataObject *)pDataObject, a2: &format, a3: &storage) == 0 )
  {
    if ( storage.tymed == 1 )
    {
      v4 = (const char *)GlobalLock(hMem: storage.hBitmap);
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v3 = KeyValues::KeyValues(
               this: v5,
               setName: "DragDrop",
               firstKey: "type",
               firstValue: "text",
               secondKey: "text",
               secondValue: v4);
      else
        v3 = nullptr;
      GlobalUnlock(hMem: storage.hBitmap);
    }
    ReleaseStgMedium(a1: &storage);
    return v3;
  }
  v7 = *(HRESULT (__stdcall **)(IDataObject *, tagFORMATETC *, tagSTGMEDIUM *))(*(_DWORD *)pDataObject + 12);
  format.cfFormat = 15;
  if ( v7(this: (IDataObject *)pDataObject, a2: &format, a3: &storage) != 0 || storage.tymed != 1 )
    return v3;
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v9 = 0;
  if ( v8 != nullptr )
    dragData = KeyValues::KeyValues(this: v8, setName: "DragDrop", firstKey: "type", firstValue: "files");
  else
    dragData = nullptr;
  fileList = KeyValues::FindKey(this: dragData, keyName: "list", bCreate: true);
  v10 = (HDROP)GlobalLock(hMem: storage.hBitmap);
  FileA = DragQueryFileA(hDrop: v10, iFile: 0xFFFFFFFF, lpszFile: buf, cch: 0x1FFu);
  if ( FileA > 0 )
  {
    do
    {
      V_snprintf(pDest: namebuf, maxLen: 32, pFormat: "%d", v9);
      DragQueryFileA(hDrop: v10, iFile: v9, lpszFile: buf, cch: 0x1FFu);
      KeyValues::SetString(this: fileList, keyName: namebuf, value: buf);
      ++v9;
    }
    while ( v9 < FileA );
  }
  GlobalUnlock(hMem: storage.hBitmap);
  return dragData;
}

//------------------------------------------------------------------------------
// Address: 0x1000FA00
// Name: public: virtual int CWin32Surface::GetPopupCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Surface::GetPopupCount(CWin32Surface *this)
{
  return this->_popupList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1000FA10
// Name: public: virtual unsigned int CWin32Surface::GetPopup(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWin32Surface::GetPopup(CWin32Surface *this, int index)
{
  return this->_popupList.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x1000FA90
// Name: public: int CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Parent(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( i == -1 )
    return dword_100517A8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x1000FAF0
// Name: public: int CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::LeftChild(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1000FB50
// Name: public: int CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RightChild(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( i == -1 )
    return dword_100517A4;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1000FBB0
// Name: public: bool CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::IsRightChild(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<vgui::Texture,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( m_Parent == -1 )
    return dword_100517A4 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC70
// Name: protected: void CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::FindInsertionPosition(class vgui::Texture const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::FindInsertionPosition(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        const vgui::Texture *insert,
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
      if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FD70
// Name: public: unsigned short CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100517B8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1000FDD0
// Name: public: unsigned short CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100517B8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1000FE40
// Name: protected: void CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CWin32Surface::ContextAbsPos_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this,
        const CWin32Surface::ContextAbsPos_t *insert,
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
      if ( (`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517B8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517B8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FF30
// Name: public: int CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::NewNode(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<vgui::Texture,int> *m_pMemory; // edx
  UtlRBTreeNode_t<vgui::Texture,int> *v11; // edx

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
      CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>::Grow(this: &this->m_Elements, num: 1);
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
// Address: 0x10010000
// Name: public: unsigned short CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  int result; // eax
  CWin32Surface::ContextAbsPos_t *p_m_Data; // ecx

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
      CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>::Grow(
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
        v9 = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    this->m_LastAlloc.index = v6;
    result = v6;
  }
  else
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Elements.m_pMemory[m_FirstFree].m_Right;
  }
  p_m_Data = &this->m_Elements.m_pMemory[(unsigned __int16)result].m_Data;
  if ( &this->m_Elements.m_pMemory[(unsigned __int16)result] != (UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short> *)-8 )
  {
    p_m_Data->id = -1;
    p_m_Data->m_nPos[1] = 0;
    p_m_Data->m_nPos[0] = 0;
  }
  this->m_pElements = this->m_Elements.m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010120
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100517C4 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_100517C4;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x10010180
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100517C4 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x100101E0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_100517C4 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10010240
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010330
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short> *v12; // edx

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
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
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
// Address: 0x10010430
// Name: public: bool CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::IsLeftChild(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<vgui::Texture,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x100104F0
// Name: protected: void CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RotateLeft(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<vgui::Texture,int> *v6; // ecx
  int v7; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *v8; // ecx
  int v9; // ecx
  int v10; // ecx

  v2 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::LeftChild(
                                 this,
                                 i: m_Right)].m_Parent = elem;
    v7 = elem;
  }
  if ( m_Right != -1 )
  {
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v9 = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Parent(
           this,
           i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v9].m_Left = m_Right;
  }
  else
  {
    v10 = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v10].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100106A0
// Name: protected: void CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RotateRight(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<vgui::Texture,int> *v6; // ecx
  int v7; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *v8; // ecx
  int v9; // ecx
  int v10; // ecx

  v2 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( m_Left == -1 )
    v8 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Left];
  if ( v8->m_Right != -1 )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
    v7 = elem;
  }
  if ( m_Left != -1 )
  {
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    v9 = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Parent(
           this,
           i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v9].m_Right = m_Left;
  }
  else
  {
    v10 = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v10].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10010850
// Name: protected: void CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10010950
// Name: protected: void CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10010A50
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10010B40
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10010C30
// Name: public: int CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::Find(class vgui::Texture const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Find(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        const vgui::Texture *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10010D30
// Name: public: int CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::FirstInorder(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_100517A4 = -1;
      dword_100517A8 = -1;
      dword_100517AC = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_100517A4 = -1;
      dword_100517A8 = -1;
      dword_100517AC = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010DE0
// Name: public: int CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::NextInorder(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<vgui::Texture,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_100517A4 = -1;
    dword_100517A8 = -1;
    dword_100517AC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_100517A4 = -1;
          dword_100517A8 = -1;
          dword_100517AC = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010F70
// Name: public: unsigned short CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Find(struct CWin32Surface::ContextAbsPos_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this,
        const CWin32Surface::ContextAbsPos_t *search)
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
      if ( (`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517B8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517B8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10011070
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t *search)
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
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10011170
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x10011220
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100517C4 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100517C4 = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100112F0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
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
  if ( CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i) == 0xFFFF )
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                       this,
                       i);
    v7 = `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    for ( result = (unsigned __int16)result; ; result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Parent )
    {
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      v10 = (_WORD)v9 == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v9];
      if ( *((_WORD *)v10 + 1) != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
    }
  }
  else
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                       this,
                       i);
    v4 = `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    result = (unsigned __int16)result;
    while ( 1 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( *(_WORD *)v6 == 0xFFFF )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)result == 0xFFFF )
        result = (unsigned __int16)`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100114E0
// Name: public: void CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RemoveAll(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this)
{
  int index; // eax
  BOOL v3; // ecx
  int v4; // esi
  int v5; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = this->m_Elements.m_nAllocationCount > 0;
    v4 = v3 - 1;
    if ( v3 )
    {
      do
      {
        if ( v4 >= 0
          && v4 < this->m_Elements.m_nAllocationCount
          && v4 <= index
          && CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::LeftChild(
               this,
               i: v4) != v4 )
        {
          v5 = v4;
          this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v5].m_Left = v4;
          this->m_FirstFree = v4;
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
// Address: 0x10011570
// Name: public: void CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x10011630
// Name: protected: void CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::InsertRebalance(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<vgui::Texture,int> *v7; // ecx
  UtlRBTreeNode_t<vgui::Texture,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<vgui::Texture,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<vgui::Texture,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *v18; // ecx
  UtlRBTreeNode_t<vgui::Texture,int> *v19; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *v20; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *v23; // ecx
  UtlRBTreeNode_t<vgui::Texture,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_100517A4 = -1;
          dword_100517A8 = -1;
          dword_100517AC = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_100517A4 = -1;
          dword_100517A8 = -1;
          dword_100517AC = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_100517A4 = -1;
            dword_100517A8 = -1;
            dword_100517AC = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_100517A4 = -1;
            dword_100517A8 = -1;
            dword_100517AC = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_100517A4 = -1;
          dword_100517A8 = -1;
          dword_100517AC = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_100517A4 = -1;
          dword_100517A8 = -1;
          dword_100517AC = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
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
        if ( CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_100517A4 = -1;
            dword_100517A8 = -1;
            dword_100517AC = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_100517A4 = -1;
            dword_100517A8 = -1;
            dword_100517AC = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<vgui::Texture,int> *)&`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RotateLeft(
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
// Address: 0x10011B00
// Name: protected: void CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this,
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
    v4 = `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100517B8 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100517B8 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100517B8 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100517B8 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100517B8 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100517B8 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517B8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517B8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517B8 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517B8 = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RotateRight(
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
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517B8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517B8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517B8 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517B8 = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x100120B0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
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
      v4 = `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_100517C4 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517C4 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517C4 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517C4 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517C4 = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100517C4 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100517C4 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517C4 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517C4 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
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
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517C4 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_100517C4 = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100517C4 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_100517C4 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x100126A0
// Name: private: class vgui::Texture __near * CWin32Surface::GetTextureById(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Texture *__thiscall CWin32Surface::GetTextureById(CWin32Surface *this, int id)
{
  int v3; // eax
  int v4; // esi
  vgui::Texture findTex; // [esp+Ch] [ebp-28h] BYREF

  findTex._id = id;
  memset(&findTex._bitmap, 0, 36);
  v3 = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Find(
         this: &this->m_VGuiSurfaceTextures,
         search: &findTex);
  v4 = v3;
  if ( v3 < 0
    || v3 >= this->m_VGuiSurfaceTextures.m_Elements.m_nAllocationCount
    || v3 > this->m_VGuiSurfaceTextures.m_LastAlloc.index
    || CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::LeftChild(
         this: &this->m_VGuiSurfaceTextures,
         i: v3) == v3 )
  {
    return nullptr;
  }
  else
  {
    return &this->m_VGuiSurfaceTextures.m_Elements.m_pMemory[v4].m_Data;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012740
// Name: public: virtual void CWin32Surface::SetNotifyIcon(unsigned int,unsigned long,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetNotifyIcon(
        CWin32Surface *this,
        unsigned int context,
        unsigned int iconID,
        vgui::Texture *panelToReceiveMessages,
        char *text)
{
  int v5; // edi
  int (__thiscall *v7)(int); // eax
  HWND__ *v8; // ecx
  int (__thiscall *v9)(int); // eax
  int (__thiscall *v10)(int); // eax
  DWORD v11; // esi
  BOOL v12; // eax
  _NOTIFYICONDATAA iconData; // [esp+8h] [ebp-3D0h] BYREF
  _NOTIFYICONDATAA Data; // [esp+1F0h] [ebp-1E8h] BYREF
  unsigned int dwMessage; // [esp+3E0h] [ebp+8h]
  vgui::Texture *texture; // [esp+3E8h] [ebp+10h]

  v5 = context;
  if ( context != 0 )
  {
    while ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5) == 0 )
    {
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 124))(a1: v5);
      if ( v5 == 0 )
        return;
    }
    if ( v5 != 0 )
    {
      if ( text == nullptr )
        text = (char *)pHelpString;
      if ( this->_notifyIcon == iconID
        && (vgui::Texture *)this->_notifyPanel == panelToReceiveMessages
        && *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5) + 76) != 0 )
      {
        v7 = *(int (__thiscall **)(int))(*(_DWORD *)v5 + 12);
        Data.cbSize = 488;
        v8 = *(HWND__ **)v7(a1: v5);
        v9 = *(int (__thiscall **)(int))(*(_DWORD *)v5 + 12);
        Data.hWnd = v8;
        Data.uID = 1;
        Data.uFlags = 4;
        Data.uCallbackMessage = 1025;
        Data.hIcon = *(HICON__ **)(v9(a1: v5) + 76);
        memset(Data.szTip, 0, 464);
        strncpy(dest: (unsigned __int8 *)Data.szTip, source: (unsigned __int8 *)text, count: 0x3Fu);
        Data.szTip[63] = 0;
        Shell_NotifyIconA(dwMessage: 1u, lpData: &Data);
      }
      else
      {
        this->_notifyPanel = (unsigned int)panelToReceiveMessages;
        this->_notifyIcon = iconID;
        v10 = *(int (__thiscall **)(int))(*(_DWORD *)v5 + 12);
        if ( iconID != 0 )
        {
          dwMessage = *(_DWORD *)(v10(a1: v5) + 76) != 0;
          texture = CWin32Surface::GetTextureById(this, id: iconID);
          if ( texture->_icon == nullptr )
          {
            (*(void (__thiscall **)(unsigned int))(*(_DWORD *)this->_currentContextPanel + 12))(a1: this->_currentContextPanel);
            staticGenerateIconForTexture(texture);
          }
          v11 = dwMessage;
          *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5) + 76) = texture->_icon;
        }
        else
        {
          v11 = 2;
          *(_DWORD *)(v10(a1: v5) + 76) = 0;
        }
        iconData.cbSize = 488;
        iconData.hWnd = *(HWND__ **)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
        iconData.uID = 1;
        iconData.uFlags = 7;
        iconData.uCallbackMessage = 1025;
        iconData.hIcon = *(HICON__ **)((*(int (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5) + 76);
        memset(iconData.szTip, 0, 464);
        strncpy(dest: (unsigned __int8 *)iconData.szTip, source: (unsigned __int8 *)text, count: 0x3Fu);
        iconData.szTip[63] = 0;
        v12 = Shell_NotifyIconA(dwMessage: v11, lpData: &iconData);
        if ( iconID != 0 && !v12 )
        {
          GetLastError();
          _Msg(a1: "error: SetNotifyIcon(%d) failed\n");
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100129A0
// Name: public: virtual bool CWin32Surface::IsTextureIDValid(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWin32Surface::IsTextureIDValid(CWin32Surface *this, int id)
{
  return CWin32Surface::GetTextureById(this, id) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100129C0
// Name: public: virtual void CWin32Surface::DeleteHTMLWindow(class vgui::IHTML __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DeleteHTMLWindow(CWin32Surface *this, CChromeHTMLWindow *htmlwin)
{
  vgui::IHTML *v3; // esi

  v3 = (vgui::IHTML *)__RTDynamicCast(
                        inptr: htmlwin,
                        VfDelta: 0,
                        SrcType: &vgui::IHTML `RTTI Type Descriptor',
                        TargetType: &CChromeHTMLWindow `RTTI Type Descriptor',
                        isReference: 0);
  htmlwin = (CChromeHTMLWindow *)v3;
  if ( v3 != nullptr )
  {
    CUtlVector<CChromeHTMLWindow *,CUtlMemory<CChromeHTMLWindow *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::VPanel *,CUtlMemory<vgui::VPanel *,int> > *)&this->m_HtmlWindows,
      src: (vgui::VPanel *const *)&htmlwin);
    v3->__vftable[1].OpenURL(this: v3, a2: (const char *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012A10
// Name: public: virtual void CWin32Surface::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetTexture(CWin32Surface *this, int id)
{
  this->m_pCurrentTexture = CWin32Surface::GetTextureById(this, id);
}

//------------------------------------------------------------------------------
// Address: 0x10012A30
// Name: public: virtual bool CWin32Surface::DrawGetTextureFile(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32Surface::DrawGetTextureFile(CWin32Surface *this, int id, char *filename, int maxlen)
{
  vgui::Texture *TextureById; // eax

  TextureById = CWin32Surface::GetTextureById(this, id);
  if ( TextureById == nullptr )
    return 0;
  V_strncpy(pDest: filename, pSrc: TextureById->_filename, maxLen: maxlen);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012A60
// Name: public: virtual int CWin32Surface::DrawGetTextureId(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Surface::DrawGetTextureId(CWin32Surface *this, const char *filename)
{
  int Inorder; // esi
  UtlRBTreeNode_t<vgui::Texture,int> *m_pMemory; // ecx
  int p_m_Data; // edi

  Inorder = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::FirstInorder(this: &this->m_VGuiSurfaceTextures);
  if ( Inorder == -1 )
    return -1;
  while ( 1 )
  {
    m_pMemory = this->m_VGuiSurfaceTextures.m_Elements.m_pMemory;
    p_m_Data = (int)&m_pMemory[Inorder].m_Data;
    if ( _V_stricmp(s1: filename, s2: m_pMemory[Inorder].m_Data._filename) == 0 )
      break;
    Inorder = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::NextInorder(
                this: &this->m_VGuiSurfaceTextures,
                i: Inorder);
    if ( Inorder == -1 )
      return -1;
  }
  return *(_DWORD *)p_m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x10012AD0
// Name: public: virtual void CWin32Surface::DrawGetTextureSize(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawGetTextureSize(CWin32Surface *this, int id, int *wide, int *tall)
{
  vgui::Texture *TextureById; // eax

  TextureById = CWin32Surface::GetTextureById(this, id);
  if ( TextureById != nullptr )
  {
    *wide = TextureById->_wide;
    *tall = TextureById->_tall;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012B00
// Name: public: virtual void CWin32Surface::ReleasePanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWin32Surface::ReleasePanel(CWin32Surface *this@<ecx>, int a2@<esi>, unsigned int panel)
{
  unsigned int v3; // ebx
  int v5; // esi

  v3 = panel;
  CUtlVector<CChromeHTMLWindow *,CUtlMemory<CChromeHTMLWindow *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::VPanel *,CUtlMemory<vgui::VPanel *,int> > *)&this->_popupList,
    src: (vgui::VPanel *const *)&panel);
  if ( v3 == this->_currentContextPanel )
    this->_currentContextPanel = this->_embeddedPanel;
  if ( (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v3 + 12))(a1: v3) != 0 )
  {
    v5 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)v3 + 12))(a1: v3, a2);
    RevokeDragDrop(hwnd: *(HWND *)v5);
    if ( *(_DWORD *)(v5 + 76) != 0 )
      this->SetNotifyIcon(this, a2: v3, a3: 0, a4: 0, a5: nullptr);
    this->SetPanelVisible(this, a2: v3, a3: false);
    SetWindowLongA(hWnd: *(HWND *)v5, nIndex: -21, dwNewLong: -1);
    SetWindowPos(hWnd: *(HWND *)v5, hWndInsertAfter: (HWND)1, X: 0, Y: 0, cx: 1, cy: 1, uFlags: 0x88u);
    if ( *(_DWORD *)(v5 + 24) != 0 )
      DeleteObject(ho: *(HGDIOBJ *)(v5 + 24));
    if ( *(_DWORD *)(v5 + 12) != 0 )
      DeleteDC(hdc: *(HDC *)(v5 + 12));
    if ( *(_DWORD *)(v5 + 8) != 0 )
      ReleaseDC(hWnd: *(HWND *)v5, hDC: *(HDC *)(v5 + 8));
    DeleteDC(hdc: *(HDC *)(v5 + 4));
    DestroyWindow(hWnd: *(HWND *)v5);
    DeleteObject(ho: *(HGDIOBJ *)(v5 + 20));
    free(pMem: (void *)v5);
    (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)v3 + 16))(a1: v3, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012C00
// Name: public: virtual bool CWin32Surface::AddCustomFontFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::AddCustomFontFile(CWin32Surface *this, const char *fontFileName)
{
  bool v3; // bl
  CUtlBuffer buf; // [esp+0h] [ebp-34h] BYREF
  unsigned int dwNumFontsRegistered; // [esp+30h] [ebp-4h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: fontFileName,
         a3: nullptr,
         a4: &buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( ValveFont::DecodeFont(buffer: &buf) != 0 )
    {
      dwNumFontsRegistered = 0;
      v3 = AddFontMemResourceEx(
             pFileView: buf.m_Memory.m_pMemory,
             cjSize: buf.m_Put,
             pvResrved: nullptr,
             pNumFonts: &dwNumFontsRegistered) != nullptr;
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return v3;
    }
    else
    {
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return false;
    }
  }
  else
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012CE0
// Name: public: virtual void CWin32Surface::GetAbsPosForContext(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::GetAbsPosForContext(CWin32Surface *this, int id, int *x, int *y)
{
  unsigned __int16 v5; // ax
  CWin32Surface::ContextAbsPos_t *p_m_Data; // eax
  CWin32Surface::ContextAbsPos_t search; // [esp+4h] [ebp-Ch] BYREF

  search.m_nPos[1] = 0;
  search.m_nPos[0] = 0;
  search.id = id;
  v5 = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_ContextAbsPos,
         &search);
  if ( v5 == 0xFFFF )
  {
    *y = 0;
    *x = 0;
  }
  else
  {
    p_m_Data = &this->m_ContextAbsPos.m_Elements.m_pMemory[v5].m_Data;
    *x = p_m_Data->m_nPos[0];
    *y = p_m_Data->m_nPos[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012D60
// Name: protected: void CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::LinkToParent(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<vgui::Texture,int> *v4; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::InsertRebalance(
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
    CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012DE0
// Name: protected: void CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012E60
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012EE0
// Name: public: int vgui::Dar<unsigned int>::AddElement(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Dar<unsigned int>::AddElement(vgui::Dar<unsigned int> *this, unsigned int elem)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  unsigned int *m_pMemory; // ecx
  int v6; // eax
  unsigned int *v7; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow((CUtlMemory<CWin32Font *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = elem;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10012F40
// Name: public: void CUtlDict<class vgui::IImage __near *,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<vgui::IImage *,unsigned short>::RemoveAll(CUtlDict<vgui::IImage *,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10012FA0
// Name: public: virtual void CWin32Surface::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::Shutdown(CWin32Surface *this)
{
  int i; // edi
  vgui::IImage *elem; // ecx
  CFontManager *v4; // eax
  int j; // edi
  const char *v6; // eax
  int (__thiscall *GetPopupCount)(vgui::ISurface *); // eax
  CWin32Surface_vtbl *v8; // edi
  unsigned int v9; // eax
  HMODULE ModuleHandleA; // eax

  for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_FileTypeImages.m_Elements.m_Tree);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_FileTypeImages.m_Elements.m_Tree,
                                i) )
  {
    elem = this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem;
    if ( elem != nullptr )
      ((void (__thiscall *)(vgui::IImage *, int))elem->dtr_IImage)(a1: elem, a2: 1);
  }
  CUtlDict<vgui::IImage *,unsigned short>::RemoveAll(this: &this->m_FileTypeImages);
  v4 = FontManager();
  CFontManager::ClearAllFonts(this: v4);
  for ( j = 0; j < this->m_CustomFontFileNames.m_Size; ++j )
  {
    v6 = CUtlSymbol::String(this: &this->m_CustomFontFileNames.m_Memory.m_pMemory[j]);
    RemoveFontResourceA(lpFileName: v6);
  }
  this->m_CustomFontFileNames.m_Size = 0;
  GetPopupCount = this->GetPopupCount;
  staticSurfaceAvailable = false;
  if ( GetPopupCount(this) != 0 )
  {
    do
    {
      v8 = this->CBaseAppSystem<vgui::ISurface>::vgui::ISurface::IAppSystem::__vftable;
      v9 = this->GetPopup(this, a2: 0);
      v8->ReleasePanel(this, a2: v9);
    }
    while ( this->GetPopupCount(this) != 0 );
  }
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  UnregisterClassA(lpClassName: "Surface", hInstance: ModuleHandleA);
  staticWndclassAtom = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100130A0
// Name: public: virtual void CWin32Surface::MovePopupToFront(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::MovePopupToFront(CWin32Surface *this, unsigned int panel)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  vgui::Dar<unsigned int>::MoveElementToEnd(this: &this->_popupList, elem: panel);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "OnMovedPopupToFront");
  else
    v3 = nullptr;
  ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
    a1: vgui::g_pIVgui,
    a2: panel,
    a3: v3,
    a4: 0,
    a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100130F0
// Name: public: virtual void CWin32Surface::CreatePopup(unsigned int,bool,bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWin32Surface::CreatePopup(
        CWin32Surface *this@<ecx>,
        int a2@<ebx>,
        HWND__ *panel,
        bool minimised,
        bool showTaskbarIcon,
        bool disabled,
        int mouseInput,
        unsigned int kbInput)
{
  unsigned __int8 (__thiscall *v9)(HWND__ *); // edx
  HWND__ *v11; // esi
  void *v12; // esi
  HMODULE ModuleHandleA; // eax
  HDC CompatibleDC; // eax
  LONG v15; // eax
  char v16; // al
  CWin32Surface *v17; // ecx
  _DWORD *v18; // esi
  int m_Size; // edx
  int v20; // eax
  unsigned int *m_pMemory; // ecx
  int wide; // [esp+8h] [ebp-14h] BYREF
  int tall; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int y; // [esp+14h] [ebp-8h] BYREF
  CWin32Surface *v26; // [esp+18h] [ebp-4h]
  HWND__ *hwndParent; // [esp+24h] [ebp+8h]
  DWORD style; // [esp+2Ch] [ebp+10h]
  DWORD style_ex; // [esp+38h] [ebp+1Ch]

  v9 = *(unsigned __int8 (__thiscall **)(HWND__ *))(*(_DWORD *)panel + 28);
  v26 = this;
  if ( v9(a1: panel) == 0 || (*(int (__thiscall **)(HWND__ *))(*(_DWORD *)panel + 12))(a1: panel) == 0 )
  {
    if ( (*(int (__thiscall **)(HWND__ *))(*(_DWORD *)panel + 124))(a1: panel) == 0
      && panel != (HWND__ *)this->_embeddedPanel )
    {
      (*(void (__thiscall **)(HWND__ *, unsigned int))(*(_DWORD *)panel + 108))(a1: panel, a2: this->_embeddedPanel);
    }
    (*(void (__thiscall **)(HWND__ *, int *, int *, int))(*(_DWORD *)panel + 44))(a1: panel, a2: &x, a3: &y, a4: a2);
    (*(void (__thiscall **)(HWND__ *, int *, int *))(*(_DWORD *)panel + 52))(a1: panel, a2: &wide, a3: &tall);
    (*(void (__thiscall **)(HWND__ *, int))(*(_DWORD *)panel + 32))(a1: panel, a2: 1);
    (*(void (__thiscall **)(HWND__ *, unsigned int))(*(_DWORD *)panel + 160))(a1: panel, a2: kbInput);
    (*(void (__thiscall **)(HWND__ *, int))(*(_DWORD *)panel + 164))(a1: panel, a2: mouseInput);
    hwndParent = nullptr;
    v11 = panel;
    while ( (*(int (__thiscall **)(HWND__ *))(*(_DWORD *)v11 + 12))(a1: v11) == 0 )
    {
      v11 = (HWND__ *)(*(int (__thiscall **)(HWND__ *))(*(_DWORD *)v11 + 124))(a1: v11);
      if ( v11 == nullptr )
        goto LABEL_13;
    }
    if ( v11 != nullptr && v11 != (HWND__ *)v26->_embeddedPanel )
      hwndParent = *(HWND__ **)(*(int (__thiscall **)(HWND__ *))(*(_DWORD *)v11 + 12))(a1: v11);
LABEL_13:
    v12 = operator new(nSize: 0x58u);
    (*(void (__thiscall **)(HWND__ *, void *))(*(_DWORD *)panel + 16))(a1: panel, a2: v12);
    style_ex = 0;
    if ( showTaskbarIcon )
    {
      style = -2113273856;
    }
    else
    {
      style = -2113929216;
      style_ex = 128;
      if ( hwndParent == nullptr )
        hwndParent = *(HWND__ **)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v26->_embeddedPanel + 12))(a1: v26->_embeddedPanel);
    }
    if ( panel != (HWND__ *)v26->_embeddedPanel
      && (*(unsigned __int8 (__thiscall **)(HWND__ *))(*(_DWORD *)panel + 100))(a1: panel) != 0 )
    {
      style |= 0x10000000u;
    }
    if ( disabled )
      style |= 0x8000000u;
    if ( minimised )
      style |= 0x20000000u;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    *(_DWORD *)v12 = CreateWindowExA(
                       dwExStyle: style_ex,
                       lpClassName: "Surface",
                       lpWindowName: pHelpString,
                       dwStyle: style,
                       X: x,
                       Y: y,
                       nWidth: wide,
                       nHeight: tall,
                       hWndParent: hwndParent,
                       hMenu: nullptr,
                       hInstance: ModuleHandleA,
                       lpParam: nullptr);
    *((_DWORD *)v12 + 5) = CreateRectRgn(x1: 0, y1: 0, x2: 64, y2: 64);
    CompatibleDC = CreateCompatibleDC(hdc: nullptr);
    *((_DWORD *)v12 + 1) = CompatibleDC;
    *((_DWORD *)v12 + 2) = 0;
    *((_DWORD *)v12 + 6) = 0;
    *((_DWORD *)v12 + 7) = 0;
    *((_DWORD *)v12 + 8) = 0;
    *((_BYTE *)v12 + 52) = 0;
    *((_DWORD *)v12 + 17) = panel;
    *((_BYTE *)v12 + 53) = disabled;
    *((_DWORD *)v12 + 19) = 0;
    *((_DWORD *)v12 + 3) = 0;
    SetBkMode(hdc: CompatibleDC, mode: 1);
    v15 = vgui::g_pIVgui->PanelToHandle(this: vgui::g_pIVgui, a2: (unsigned int)panel);
    SetWindowLongA(hWnd: *(HWND *)v12, nIndex: -21, dwNewLong: v15);
    SetTextAlign(hdc: *((HDC *)v12 + 1), align: 1u);
    v16 = (*(int (__thiscall **)(HWND__ *))(*(_DWORD *)panel + 100))(a1: panel);
    v17 = v26;
    if ( v16 == 0 || panel == (HWND__ *)v26->_embeddedPanel )
    {
      ((void (__stdcall *)(HWND__ *, _DWORD))v26->SetPanelVisible)(a1: panel, a2: 0);
      v17 = v26;
    }
    v17->RecreateContext(this: v17, a2: (unsigned int)panel);
    RegisterDragDrop(hwnd: *(HWND *)v12, pDropTarget: &staticDragDropTarget);
    v18 = &v26->CBaseAppSystem<vgui::ISurface>::vgui::ISurface::IAppSystem::__vftable;
    m_Size = v26->_popupList.m_Size;
    v20 = 0;
    if ( m_Size <= 0 )
      goto LABEL_31;
    m_pMemory = v26->_popupList.m_Memory.m_pMemory;
    while ( (HWND__ *)*m_pMemory != panel )
    {
      ++v20;
      ++m_pMemory;
      if ( v20 >= m_Size )
        goto LABEL_31;
    }
    if ( v20 == -1 )
LABEL_31:
      vgui::Dar<unsigned int>::AddElement(this: &v26->_popupList, elem: (unsigned int)panel);
    else
      __debugbreak();
    if ( first )
    {
      PlaySoundA(pszSound: pHelpString, hmod: nullptr, fdwSound: 0x22013u);
      first = false;
    }
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*v18 + 604))(a1: v18, a2: v18[10]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100133A0
// Name: public: int CUtlRBTree<class vgui::Texture,int,bool (*)(class vgui::Texture const __near &,class vgui::Texture const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class vgui::Texture,int>,int>>::Insert(class vgui::Texture const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Insert(
        CUtlRBTree<vgui::Texture,int,bool (__cdecl*)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int> > *this,
        const vgui::Texture *insert)
{
  int v3; // edi
  UtlRBTreeNode_t<vgui::Texture,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::NewNode(this);
  CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<vgui::Texture,int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10013440
// Name: public: unsigned short CUtlRBTree<struct CWin32Surface::ContextAbsPos_t,unsigned short,bool (*)(struct CWin32Surface::ContextAbsPos_t const __near &,struct CWin32Surface::ContextAbsPos_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Insert(struct CWin32Surface::ContextAbsPos_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl*)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short> > *this,
        const CWin32Surface::ContextAbsPos_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100134C0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<char const __near *,class vgui::IImage __near *,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10013530
// Name: public: CWin32Surface::CWin32Surface(void)
// Source: json
//------------------------------------------------------------------------------
CWin32Surface *__thiscall CWin32Surface::CWin32Surface(CWin32Surface *this)
{
  UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short> *v3; // edx
  bool v4; // cf

  this->ISchemeSurface::IAppSystem::__vftable = (ISchemeSurface_vtbl *)&ISchemeSurface::`vftable';
  this->ILocalizeTextQuery::__vftable = (ILocalizeTextQuery_vtbl *)&ILocalizeTextQuery::`vftable';
  this->CBaseAppSystem<vgui::ISurface>::vgui::ISurface::IAppSystem::__vftable = (CWin32Surface_vtbl *)&CWin32Surface::`vftable'{for `CBaseAppSystem<vgui::ISurface>'};
  this->ISchemeSurface::IAppSystem::__vftable = (ISchemeSurface_vtbl *)&CWin32Surface::`vftable'{for `ISchemeSurface'};
  this->ILocalizeTextQuery::__vftable = (ILocalizeTextQuery_vtbl *)&CWin32Surface::`vftable'{for `ILocalizeTextQuery'};
  this->m_FileTypeImages.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_FileTypeImages.m_Elements.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_FileTypeImages.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_FileTypeImages.m_Elements.m_Tree.m_pElements = m_pMemory;
  if ( this->m_FileTypeImages.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_FileTypeImages.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->_popupList.m_Memory.m_pMemory = nullptr;
  this->_popupList.m_Memory.m_nAllocationCount = 0;
  this->_popupList.m_Memory.m_nGrowSize = 0;
  this->_popupList.m_Size = 0;
  this->_popupList.m_pElements = nullptr;
  this->m_HtmlWindows.m_Memory.m_pMemory = nullptr;
  this->m_HtmlWindows.m_Memory.m_nAllocationCount = 0;
  this->m_HtmlWindows.m_Memory.m_nGrowSize = 0;
  this->m_HtmlWindows.m_Size = 0;
  this->m_HtmlWindows.m_pElements = nullptr;
  this->m_CustomFontFileNames.m_Memory.m_pMemory = nullptr;
  this->m_CustomFontFileNames.m_Memory.m_nAllocationCount = 0;
  this->m_CustomFontFileNames.m_Memory.m_nGrowSize = 0;
  this->m_CustomFontFileNames.m_Size = 0;
  this->m_CustomFontFileNames.m_pElements = nullptr;
  this->m_VGuiSurfaceTextures.m_LessFunc = (bool (__cdecl *)(const vgui::Texture *, const vgui::Texture *))CWin32Surface::ContextAbsPos_t::Less;
  this->m_VGuiSurfaceTextures.m_Elements.m_pMemory = nullptr;
  this->m_VGuiSurfaceTextures.m_Elements.m_nAllocationCount = 128;
  this->m_VGuiSurfaceTextures.m_Elements.m_nGrowSize = 0;
  this->m_VGuiSurfaceTextures.m_Elements.m_pMemory = (UtlRBTreeNode_t<vgui::Texture,int> *)_g_pMemAlloc->Alloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: 7168);
  this->m_VGuiSurfaceTextures.m_NumElements = 0;
  this->m_VGuiSurfaceTextures.m_Root = -1;
  this->m_VGuiSurfaceTextures.m_FirstFree = -1;
  this->m_VGuiSurfaceTextures.m_LastAlloc.index = -1;
  this->m_VGuiSurfaceTextures.m_pElements = this->m_VGuiSurfaceTextures.m_Elements.m_pMemory;
  this->m_ScreenSizeOverride.m_bActive = false;
  this->m_ScreenSizeOverride.m_nValue[1] = 0;
  this->m_ScreenSizeOverride.m_nValue[0] = 0;
  this->m_ScreenPosOverride.m_bActive = false;
  this->m_ScreenPosOverride.m_nValue[1] = 0;
  this->m_ScreenPosOverride.m_nValue[0] = 0;
  this->m_ContextAbsPos.m_LessFunc = (bool (__cdecl *)(const CWin32Surface::ContextAbsPos_t *, const CWin32Surface::ContextAbsPos_t *))CWin32Surface::ContextAbsPos_t::Less;
  this->m_ContextAbsPos.m_Elements.m_pMemory = nullptr;
  this->m_ContextAbsPos.m_Elements.m_nAllocationCount = 0;
  this->m_ContextAbsPos.m_Elements.m_nGrowSize = 0;
  v3 = this->m_ContextAbsPos.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_ContextAbsPos.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_ContextAbsPos.m_FirstFree = -1;
  this->m_ContextAbsPos.m_pElements = v3;
  this->_currentCursor = nullptr;
  this->m_pCurrentTexture = nullptr;
  CWin32Surface::initStaticData(this);
  staticSurfaceAvailable = false;
  this->m_bAllowJavaScript = false;
  this->m_hCurrentFont = 0;
  this->pen = nullptr;
  *(_WORD *)&this->_needKB = 257;
  CoInitialize(pvReserved: nullptr);
  this->m_WindowsVersion.dwOSVersionInfoSize = 148;
  GetVersionExA(lpVersionInformation: &this->m_WindowsVersion);
  v4 = this->m_WindowsVersion.dwMajorVersion < 5;
  this->m_TextPos[1] = 0;
  this->m_bSupportsUnicode = !v4;
  this->m_TextPos[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100136F0
// Name: public: virtual bool CWin32Surface::IsCursorVisible(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32Surface::IsCursorVisible(ConCommand *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013700
// Name: public: virtual void CWin32Surface::GetProportionalBase(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::GetProportionalBase(CWin32Surface *this, int *width, int *height)
{
  *width = 640;
  *height = 480;
}

//------------------------------------------------------------------------------
// Address: 0x10013720
// Name: public: virtual void CWin32Surface::SetAllowHTMLJavaScript(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetAllowHTMLJavaScript(CWin32Surface *this, bool state)
{
  this->m_bAllowJavaScript = state;
}

//------------------------------------------------------------------------------
// Address: 0x10013730
// Name: public: virtual float CWin32Surface::DrawGetAlphaMultiplier(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWin32Surface::DrawGetAlphaMultiplier(CWin32Surface *this)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10013740
// Name: public: virtual unsigned long CWin32Surface::CreateCursorFromFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWin32Surface::CreateCursorFromFile(
        CWin32Surface *this,
        const char *curOrAniFile,
        const char *pPathID)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10013750
// Name: public: virtual void CWin32Surface::PaintTraverseEx(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::PaintTraverseEx(CWin32Surface *this, unsigned int panel, bool paintPopups)
{
  this->PaintTraverse(this, a2: panel);
}

//------------------------------------------------------------------------------
// Address: 0x10013770
// Name: public: virtual float CWin32Surface::GetZPos(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWin32Surface::GetZPos(CWin32Surface *this)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10013780
// Name: public: virtual void CWin32Surface::GetKernedCharWidth(unsigned long,wchar_t,wchar_t,wchar_t,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::GetKernedCharWidth(
        CWin32Surface *this,
        unsigned int font,
        wchar_t ch,
        wchar_t chBefore,
        wchar_t chAfter,
        float *wide,
        float *flabcA,
        float *flabcC)
{
  *wide = 0.0;
  *flabcA = 0.0;
  *flabcC = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100137A0
// Name: public: virtual void CWin32Surface::DrawUpdateRegionTextureRGBA(int,int,int,unsigned char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawUpdateRegionTextureRGBA(
        CWin32Surface *this,
        int nTextureID,
        int x,
        int y,
        const unsigned __int8 *pchData,
        const unsigned __int8 *wide,
        int tall,
        int imageFormat)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100138A0
// Name: public: virtual enum AppSystemTier_t CWin32Surface::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Surface::GetTier(CWin32Surface *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10013900
// Name: public: CWin32Surface::~CWin32Surface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::~CWin32Surface(CWin32Surface *this)
{
  int v2; // edi
  vgui::Texture *p_m_Data; // ebx
  HICON icon; // ebx
  CUtlSymbol *m_pMemory; // eax
  CChromeHTMLWindow **v6; // eax
  unsigned int *v7; // eax

  v2 = 0;
  this->CBaseAppSystem<vgui::ISurface>::vgui::ISurface::IAppSystem::__vftable = (CWin32Surface_vtbl *)&CWin32Surface::`vftable'{for `CBaseAppSystem<vgui::ISurface>'};
  this->ISchemeSurface::IAppSystem::__vftable = (ISchemeSurface_vtbl *)&CWin32Surface::`vftable'{for `ISchemeSurface'};
  this->ILocalizeTextQuery::__vftable = (ILocalizeTextQuery_vtbl *)&CWin32Surface::`vftable'{for `ILocalizeTextQuery'};
  for ( staticSurfaceAvailable = false; v2 < this->m_VGuiSurfaceTextures.m_Elements.m_nAllocationCount; ++v2 )
  {
    if ( v2 >= 0
      && v2 < this->m_VGuiSurfaceTextures.m_Elements.m_nAllocationCount
      && v2 <= this->m_VGuiSurfaceTextures.m_LastAlloc.index )
    {
      if ( (`CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100517A4 = -1;
        dword_100517A8 = -1;
        dword_100517AC = 1;
      }
      if ( this->m_VGuiSurfaceTextures.m_Elements.m_pMemory[v2].m_Left != v2 )
      {
        p_m_Data = &this->m_VGuiSurfaceTextures.m_Elements.m_pMemory[v2].m_Data;
        if ( this->m_VGuiSurfaceTextures.m_Elements.m_pMemory[v2].m_Data._bitmap != nullptr )
          DeleteObject(ho: this->m_VGuiSurfaceTextures.m_Elements.m_pMemory[v2].m_Data._bitmap);
        if ( p_m_Data->_maskBitmap != nullptr )
          DeleteObject(ho: p_m_Data->_maskBitmap);
        icon = p_m_Data->_icon;
        if ( icon != nullptr )
          DestroyIcon(hIcon: icon);
      }
    }
  }
  CoUninitialize();
  CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_ContextAbsPos);
  this->m_ContextAbsPos.m_FirstFree = -1;
  if ( this->m_ContextAbsPos.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_ContextAbsPos.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ContextAbsPos.m_Elements.m_pMemory);
      this->m_ContextAbsPos.m_Elements.m_pMemory = nullptr;
    }
    this->m_ContextAbsPos.m_Elements.m_nAllocationCount = 0;
  }
  this->m_ContextAbsPos.m_LastAlloc.index = -1;
  if ( this->m_ContextAbsPos.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_ContextAbsPos.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ContextAbsPos.m_Elements.m_pMemory);
      this->m_ContextAbsPos.m_Elements.m_pMemory = nullptr;
    }
    this->m_ContextAbsPos.m_Elements.m_nAllocationCount = 0;
  }
  CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::RemoveAll(this: &this->m_VGuiSurfaceTextures);
  this->m_VGuiSurfaceTextures.m_FirstFree = -1;
  if ( this->m_VGuiSurfaceTextures.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_VGuiSurfaceTextures.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VGuiSurfaceTextures.m_Elements.m_pMemory);
      this->m_VGuiSurfaceTextures.m_Elements.m_pMemory = nullptr;
    }
    this->m_VGuiSurfaceTextures.m_Elements.m_nAllocationCount = 0;
  }
  this->m_VGuiSurfaceTextures.m_LastAlloc.index = -1;
  if ( this->m_VGuiSurfaceTextures.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_VGuiSurfaceTextures.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VGuiSurfaceTextures.m_Elements.m_pMemory);
      this->m_VGuiSurfaceTextures.m_Elements.m_pMemory = nullptr;
    }
    this->m_VGuiSurfaceTextures.m_Elements.m_nAllocationCount = 0;
  }
  this->m_CustomFontFileNames.m_Size = 0;
  if ( this->m_CustomFontFileNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CustomFontFileNames.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CustomFontFileNames.m_Memory.m_pMemory);
      this->m_CustomFontFileNames.m_Memory.m_pMemory = nullptr;
    }
    this->m_CustomFontFileNames.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_CustomFontFileNames.m_Memory.m_pMemory;
  this->m_CustomFontFileNames.m_pElements = m_pMemory;
  if ( this->m_CustomFontFileNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_CustomFontFileNames.m_Memory.m_pMemory = nullptr;
    }
    this->m_CustomFontFileNames.m_Memory.m_nAllocationCount = 0;
  }
  this->m_HtmlWindows.m_Size = 0;
  if ( this->m_HtmlWindows.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_HtmlWindows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_HtmlWindows.m_Memory.m_pMemory);
      this->m_HtmlWindows.m_Memory.m_pMemory = nullptr;
    }
    this->m_HtmlWindows.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_HtmlWindows.m_Memory.m_pMemory;
  this->m_HtmlWindows.m_pElements = v6;
  if ( this->m_HtmlWindows.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_HtmlWindows.m_Memory.m_pMemory = nullptr;
    }
    this->m_HtmlWindows.m_Memory.m_nAllocationCount = 0;
  }
  this->_popupList.m_Size = 0;
  if ( this->_popupList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->_popupList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->_popupList.m_Memory.m_pMemory);
      this->_popupList.m_Memory.m_pMemory = nullptr;
    }
    this->_popupList.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->_popupList.m_Memory.m_pMemory;
  this->_popupList.m_pElements = v7;
  if ( this->_popupList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->_popupList.m_Memory.m_pMemory = nullptr;
    }
    this->_popupList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlDict<vgui::IImage *,unsigned short>::RemoveAll(this: &this->m_FileTypeImages);
  CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_FileTypeImages.m_Elements.m_Tree);
  this->m_FileTypeImages.m_Elements.m_Tree.m_FirstFree = -1;
  if ( this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_pMemory);
      this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_FileTypeImages.m_Elements.m_Tree.m_LastAlloc.index = -1;
  if ( this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_pMemory);
      this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013C60
// Name: public: virtual void CWin32Surface::DrawSetTextureRGBAEx(int,unsigned char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetTextureRGBAEx(
        CWin32Surface *this,
        int id,
        unsigned __int8 *rgba,
        int wide,
        int tall,
        ImageFormat imageFormat)
{
  vgui::Texture *TextureById; // eax
  vgui::Texture *p_m_Data; // esi
  CWin32Surface *v9; // edx
  int v10; // eax
  HBITMAP BitmapHandle; // eax
  unsigned __int8 *dib; // ecx
  vgui::Texture insert; // [esp+Ch] [ebp-2Ch] BYREF
  CWin32Surface *v14; // [esp+34h] [ebp-4h]

  v14 = this;
  TextureById = CWin32Surface::GetTextureById(this, id);
  p_m_Data = TextureById;
  if ( TextureById != nullptr )
  {
    if ( TextureById->_bitmap != nullptr )
      DeleteObject(ho: TextureById->_bitmap);
    if ( p_m_Data->_maskBitmap != nullptr )
      DeleteObject(ho: p_m_Data->_maskBitmap);
  }
  else
  {
    insert._id = id;
    memset(&insert._bitmap, 0, 36);
    p_m_Data = &this->m_VGuiSurfaceTextures.m_Elements.m_pMemory[CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Insert(
                                                                   this: &this->m_VGuiSurfaceTextures,
                                                                   &insert)].m_Data;
    *(_QWORD *)&p_m_Data->_id = 0;
    *(_QWORD *)&p_m_Data->_maskBitmap = 0;
    *(_QWORD *)&p_m_Data->_icon = 0;
    *(_QWORD *)&p_m_Data->_tall = 0;
    *(_QWORD *)&p_m_Data->_maskDib = 0;
  }
  v9 = v14;
  p_m_Data->_id = id;
  p_m_Data->_filename = nullptr;
  p_m_Data->_wide = wide;
  p_m_Data->_tall = tall;
  p_m_Data->_icon = nullptr;
  p_m_Data->_dib = nullptr;
  v10 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v9->_currentContextPanel + 12))(a1: v9->_currentContextPanel);
  BitmapHandle = staticCreateBitmapHandle(
                   wide: p_m_Data->_wide,
                   tall: p_m_Data->_tall,
                   hdc: *(HDC__ **)(v10 + 4),
                   bpp: 0x20u,
                   dib: &p_m_Data->_dib);
  dib = (unsigned __int8 *)p_m_Data->_dib;
  p_m_Data->_bitmap = BitmapHandle;
  memcpy(dst: dib, src: rgba, count: 4 * tall * wide);
  v14->m_pCurrentTexture = p_m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x10013D70
// Name: public: virtual void CWin32Surface::DrawSetTextureFile(int,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::DrawSetTextureFile(
        CWin32Surface *this,
        int id,
        const char *filename,
        int hardwareFilter,
        bool forceReload)
{
  vgui::Texture *TextureById; // eax
  int p_m_Data; // esi
  int v8; // eax
  UtlRBTreeNode_t<vgui::Texture,int> *m_pMemory; // edx
  vgui::Texture insert; // [esp+Ch] [ebp-28h] BYREF

  TextureById = CWin32Surface::GetTextureById(this, id);
  p_m_Data = (int)TextureById;
  if ( TextureById != nullptr )
  {
    if ( _V_stricmp(s1: filename, s2: TextureById->_filename) == 0 && !forceReload )
      goto LABEL_4;
  }
  else
  {
    insert._id = id;
    memset(&insert._bitmap, 0, 36);
    v8 = CUtlRBTree<vgui::Texture,int,bool (__cdecl *)(vgui::Texture const &,vgui::Texture const &),CUtlMemory<UtlRBTreeNode_t<vgui::Texture,int>,int>>::Insert(
           this: &this->m_VGuiSurfaceTextures,
           &insert);
    m_pMemory = this->m_VGuiSurfaceTextures.m_Elements.m_pMemory;
    p_m_Data = (int)&m_pMemory[v8].m_Data;
    *(_QWORD *)p_m_Data = 0;
    *(_QWORD *)(p_m_Data + 8) = 0;
    *(_QWORD *)(p_m_Data + 16) = 0;
    *(_QWORD *)(p_m_Data + 24) = 0;
    *(_QWORD *)(p_m_Data + 32) = 0;
    if ( &m_pMemory[v8] == (UtlRBTreeNode_t<vgui::Texture,int> *)-16 )
      goto LABEL_10;
  }
  if ( *(_DWORD *)(p_m_Data + 4) != 0 )
    DeleteObject(ho: *(HGDIOBJ *)(p_m_Data + 4));
  if ( *(_DWORD *)(p_m_Data + 8) != 0 )
    DeleteObject(ho: *(HGDIOBJ *)(p_m_Data + 8));
LABEL_10:
  *(_DWORD *)p_m_Data = id;
  *(_DWORD *)(p_m_Data + 36) = filename;
  if ( CWin32Surface::LoadTGA(this, texture: (vgui::Texture *)p_m_Data, filename) != 0
    || V_stristr(pStr: filename, pSearch: "vgui/") != nullptr
    && CWin32Surface::LoadTGA(this, texture: (vgui::Texture *)p_m_Data, filename: filename + 5) != 0 )
  {
LABEL_4:
    this->m_pCurrentTexture = (vgui::Texture *)p_m_Data;
    return;
  }
  _Msg(a1: "Error: texture file '%s' does not exist or is invalid\n");
}

//------------------------------------------------------------------------------
// Address: 0x10013E90
// Name: public: virtual void CWin32Surface::SetAbsPosForContext(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32Surface::SetAbsPosForContext(CWin32Surface *this, int id, int x, int y)
{
  unsigned __int16 v5; // ax
  CWin32Surface::ContextAbsPos_t *p_m_Data; // eax
  CWin32Surface::ContextAbsPos_t search; // [esp+8h] [ebp-Ch] BYREF

  search.m_nPos[1] = 0;
  search.m_nPos[0] = 0;
  search.id = id;
  v5 = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_ContextAbsPos,
         &search);
  if ( v5 == 0xFFFF )
    v5 = CUtlRBTree<CWin32Surface::ContextAbsPos_t,unsigned short,bool (__cdecl *)(CWin32Surface::ContextAbsPos_t const &,CWin32Surface::ContextAbsPos_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Surface::ContextAbsPos_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_ContextAbsPos,
           insert: &search);
  p_m_Data = &this->m_ContextAbsPos.m_Elements.m_pMemory[v5].m_Data;
  p_m_Data->m_nPos[0] = x;
  p_m_Data->m_nPos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x10013F00
// Name: public: unsigned short CUtlDict<class vgui::IImage __near *,unsigned short>::Insert(char const __near *,class vgui::IImage __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<vgui::IImage *,unsigned short>::Insert(
        CUtlDict<vgui::IImage *,unsigned short> *this,
        const char *pName,
        vgui::IImage **element)
{
  char *v4; // eax
  vgui::IImage *v5; // edx
  CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x10013F70
// Name: public: virtual class vgui::IImage __near * CWin32Surface::GetIconImageForFullPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall CWin32Surface::GetIconImageForFullPath(CWin32Surface *this, CIconImage *pFullPath)
{
  vgui::IImage *elem; // esi
  const char *v4; // edi
  char *szTypeName; // eax
  unsigned __int16 v6; // ax
  CIconImage *v7; // eax
  char lookup[512]; // [esp+Ch] [ebp-388h] BYREF
  _SHFILEINFOA info; // [esp+20Ch] [ebp-188h] BYREF
  char ext[32]; // [esp+36Ch] [ebp-28h] BYREF
  CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t search; // [esp+38Ch] [ebp-8h] BYREF

  elem = nullptr;
  memset(&info, 0, sizeof(info));
  v4 = (const char *)pFullPath;
  if ( SHGetFileInfoA(pszPath: (LPCSTR)pFullPath, dwFileAttributes: 0, psfi: &info, cbFileInfo: 0x160u, uFlags: 0x505u) != 0 )
  {
    if ( info.szTypeName[0] != 0 )
    {
      V_ExtractFileExtension(path: v4, dest: ext, destSize: 32);
      while ( _V_stricmp(s1: ext, s2: *(const char **)((char *)g_pUniqueExtensions + (_DWORD)elem)) != 0 )
      {
        if ( (unsigned int)++elem >= 0xC )
        {
          szTypeName = info.szTypeName;
          goto LABEL_7;
        }
      }
      szTypeName = (char *)v4;
LABEL_7:
      V_snprintf(pDest: lookup, maxLen: 512, pFormat: "%s", szTypeName);
      search.key = lookup;
      v6 = CUtlRBTree<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,vgui::IImage *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IImage *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_FileTypeImages.m_Elements.m_Tree,
             &search);
      if ( v6 == 0xFFFF )
      {
        v7 = (CIconImage *)operator new(nSize: 0x18u);
        if ( v7 != nullptr )
          pFullPath = CIconImage::CIconImage(this: v7, hIcon: info.hIcon);
        else
          pFullPath = nullptr;
        v6 = CUtlDict<vgui::IImage *,unsigned short>::Insert(
               this: &this->m_FileTypeImages,
               pName: lookup,
               element: &pFullPath);
      }
      elem = this->m_FileTypeImages.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
    }
    DestroyIcon(hIcon: info.hIcon);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100186D0
// Name: public: void vgui::Dar<unsigned int>::MoveElementToEnd(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Dar<unsigned int>::MoveElementToEnd(vgui::Dar<unsigned int> *this, unsigned int elem)
{
  int m_Size; // ecx
  int v4; // eax
  unsigned int *i; // edx
  int v6; // ecx
  int v7; // edi
  int m_nAllocationCount; // eax
  unsigned int *m_pMemory; // ecx
  int v10; // eax
  unsigned int *v11; // eax

  m_Size = this->m_Size;
  if ( m_Size != 0 && this->m_Memory.m_pMemory[m_Size - 1] != elem )
  {
    v4 = 0;
    if ( m_Size > 0 )
    {
      for ( i = this->m_Memory.m_pMemory; *i != elem; ++i )
      {
        if ( ++v4 >= m_Size )
          return;
      }
      if ( v4 != -1 )
      {
        v6 = m_Size - v4 - 1;
        if ( v6 > 0 )
          _V_memmove(dest: &this->m_Memory.m_pMemory[v4], src: &this->m_Memory.m_pMemory[v4 + 1], count: 4 * v6);
        v7 = --this->m_Size;
        m_nAllocationCount = this->m_Memory.m_nAllocationCount;
        if ( v7 + 1 > m_nAllocationCount )
          CUtlMemory<int,int>::Grow((CUtlMemory<CWin32Font *,int> *)this, num: v7 - m_nAllocationCount + 1);
        ++this->m_Size;
        m_pMemory = this->m_Memory.m_pMemory;
        v10 = this->m_Size - v7 - 1;
        this->m_pElements = this->m_Memory.m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * v10);
        v11 = &this->m_Memory.m_pMemory[v7];
        if ( v11 != nullptr )
          *v11 = elem;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C910
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
// Address: 0x1001CA10
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
    dword_10052614 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_10052614;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x1001CB90
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
    dword_10052614 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1001CBF0
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
    dword_10052614 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1001CC60
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
        dword_10052614 = 0x1FFFF;
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
        dword_10052614 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CD50
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
// Address: 0x1001CE50
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
// Address: 0x1001CF70
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
        dword_10052614 = 0x1FFFF;
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
        dword_10052614 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x1001D070
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
// Address: 0x1001D130
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
      dword_10052614 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_10052614 = 0x1FFFF;
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
      dword_10052614 = 0x1FFFF;
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
      dword_10052614 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_10052614 = 0x1FFFF;
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
      dword_10052614 = 0x1FFFF;
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
        dword_10052614 = 0x1FFFF;
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
        dword_10052614 = 0x1FFFF;
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
          dword_10052614 = 0x1FFFF;
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
          dword_10052614 = 0x1FFFF;
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
        dword_10052614 = 0x1FFFF;
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
        dword_10052614 = 0x1FFFF;
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
          dword_10052614 = 0x1FFFF;
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
          dword_10052614 = 0x1FFFF;
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
// Address: 0x1001D760
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
// Address: 0x1001D860
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
// Address: 0x1001D8D0
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
// Address: 0x1001E060
// Name: public: virtual unsigned int CWin32Surface::GetModalPanel(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWin32Surface::GetModalPanel(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E070
// Name: public: virtual bool CWin32Surface::IsCursorLocked(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32Surface::IsCursorLocked(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10021720
// Name: public: unsigned short CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // ecx
  int result; // eax
  int v12; // edx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v13; // ecx

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
      CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Grow(
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
    v12 = m_FirstFree;
    result = m_FirstFree;
    v13 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v13[v12].m_Right;
    this->m_pElements = v13;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021890
// Name: protected: void CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CWin32Font::abc_cache_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this,
        const CWin32Font::abc_cache_t *insert,
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
      if ( (`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021990
// Name: protected: void CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  const UtlRBTreeLinks_t<unsigned short> *v4; // eax
  int m_Right; // ebx
  const UtlRBTreeLinks_t<unsigned short> *v6; // eax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
         this,
         i: elem);
  m_Right = v4->m_Right;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                                               this,
                                               i: v4->m_Right)->m_Left;
  elema = elem;
  if ( CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( (_WORD)m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v6 = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v6->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10021AB0
// Name: protected: void CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  const UtlRBTreeLinks_t<unsigned short> *v4; // eax
  int m_Left; // edi
  const UtlRBTreeLinks_t<unsigned short> *v6; // eax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
         this,
         i: elem);
  m_Left = v4->m_Left;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                                              this,
                                              i: v4->m_Left)->m_Right;
  elema = elem;
  if ( CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( (_WORD)m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v6 = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v6->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10021BD0
// Name: public: unsigned short CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Find(struct CWin32Font::abc_cache_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this,
        const CWin32Font::abc_cache_t *search)
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
      if ( (`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10021CD0
// Name: public: void CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
               this,
               i: it)->m_Left != v3 )
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
// Address: 0x10021D90
// Name: protected: void CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v10; // ecx
  int v11; // ecx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v12; // edx
  int v13; // edx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v14; // edx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v15; // edx
  unsigned __int16 m_Right; // dx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v17; // ebx
  int v18; // eax
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v19; // edx
  int v20; // edx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v21; // eax
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v22; // edx
  int m_Left; // edx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v24; // ebx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v25; // edx
  int v26; // edx
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = &this->m_Elements.m_pMemory[v2];
    m_Parent = v5->m_Parent;
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      v4 |= 1u;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    if ( (_WORD)m_Parent == 0xFFFF )
      v7 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = &this->m_Elements.m_pMemory[m_Parent];
    if ( v7->m_Tag != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = &this->m_Elements.m_pMemory[v2];
    v9 = v8->m_Parent;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      *(_DWORD *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = &this->m_Elements.m_pMemory[v9];
    v11 = v10->m_Parent;
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      v4 |= 1u;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    if ( v9 == 0xFFFF )
      v12 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = &this->m_Elements.m_pMemory[v9];
    v13 = v12->m_Parent;
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      v4 |= 1u;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = &this->m_Elements.m_pMemory[v13];
    if ( v14->m_Left == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        v4 |= 1u;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = &this->m_Elements.m_pMemory[v11];
      m_Right = v15->m_Right;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        v4 |= 1u;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Right == 0xFFFF )
        v17 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = &this->m_Elements.m_pMemory[m_Right];
      if ( v17->m_Tag != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          v4 |= 1u;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = &this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = v19->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[v20];
        if ( v21->m_Right == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                 this,
                 i: v9)->m_Parent;
          LOWORD(v11) = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                          this,
                          i: v9)->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = m_Right;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        v4 |= 1u;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = &this->m_Elements.m_pMemory[v11];
      m_Left = v22->m_Left;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        v4 |= 1u;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( (_WORD)m_Left == 0xFFFF )
        v24 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = &this->m_Elements.m_pMemory[m_Left];
      if ( v24->m_Tag != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          v4 |= 1u;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = &this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = v25->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)&`CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = &this->m_Elements.m_pMemory[v26];
        if ( v27->m_Left == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                 this,
                 i: v9)->m_Parent;
          LOWORD(v11) = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Links(
                          this,
                          i: v9)->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = m_Left;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100223D0
// Name: protected: void CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022460
// Name: public: CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::~CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x100225D0
// Name: public: unsigned short CUtlRBTree<struct CWin32Font::abc_cache_t,unsigned short,bool (*)(struct CWin32Font::abc_cache_t const __near &,struct CWin32Font::abc_cache_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Insert(struct CWin32Font::abc_cache_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl*)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> > *this,
        const CWin32Font::abc_cache_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CWin32Font::abc_cache_t,unsigned short,bool (__cdecl *)(CWin32Font::abc_cache_t const &,CWin32Font::abc_cache_t const &),CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1000B520
// Name: __CreateCWin32SurfaceISurface_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWin32Surface *__cdecl _CreateCWin32SurfaceISurface_interface()
{
  return &g_Surface;
}

//------------------------------------------------------------------------------
// Address: 0x1000B530
// Name: __CreateCWin32SurfaceISchemeSurface_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ISchemeSurface *__cdecl _CreateCWin32SurfaceISchemeSurface_interface()
{
  return &g_Surface.ISchemeSurface;
}
