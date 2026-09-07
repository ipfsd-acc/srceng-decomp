// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/vcover.cpp
// Functions: 49
// ============================================================

#include "vstdlib\vcover.h"

//------------------------------------------------------------------------------
// Address: 0x10002300
// Name: protected: enum CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NodeColor_t CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> >::NodeColor_t __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1003466C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(dword_1003466C);
  else
    return this->m_Elements.m_pMemory[i].m_Tag;
}

//------------------------------------------------------------------------------
// Address: 0x10002AF0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1003466C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_1003466C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x10002B50
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1003466C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10002BB0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1003466C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10002C10
// Name: protected: void CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D00
// Name: public: int CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Parent(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( i == -1 )
    return dword_1003467C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x10002D60
// Name: public: int CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RightChild(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( i == -1 )
    return dword_10034678;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10002DC0
// Name: public: bool CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::IsRightChild(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<ConCommandBase *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( m_Parent == -1 )
    return dword_10034678 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x10002E70
// Name: protected: void CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::FindInsertionPosition(class ConCommandBase __near * const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::FindInsertionPosition(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this,
        ConCommandBase *const *insert,
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
      if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10034678 = -1;
        dword_1003467C = -1;
        dword_10034680 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10034678 = -1;
        dword_1003467C = -1;
        dword_10034680 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F60
// Name: public: int CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::NewNode(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<ConCommandBase *,int> *m_pMemory; // edx
  UtlRBTreeNode_t<ConCommandBase *,int> *v11; // edx

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
      CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>::Grow(this: &this->m_Elements, num: 1);
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
// Address: 0x10003020
// Name: protected: void CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10003110
// Name: protected: void CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10003200
// Name: public: bool CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::IsLeftChild(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<ConCommandBase *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x100032B0
// Name: protected: void CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RotateLeft(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<ConCommandBase *,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v8; // ecx
  UtlRBTreeNode_t<ConCommandBase *,int> *v9; // eax

  v2 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10034678 = -1;
      dword_1003467C = -1;
      dword_10034680 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10003460
// Name: protected: void CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RotateRight(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<ConCommandBase *,int> *v6; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v7; // eax

  v2 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10003BE0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t *search)
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
      if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10003CE0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1003466C = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1003466C = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003DB0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
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
  if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i) == 0xFFFF )
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                       this,
                       i);
    v7 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    for ( result = (unsigned __int16)result; ; result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Parent )
    {
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      v10 = (_WORD)v9 == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v9];
      if ( *((_WORD *)v10 + 1) != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
    }
  }
  else
  {
    LOWORD(result) = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                       this,
                       i);
    v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    result = (unsigned __int16)result;
    while ( 1 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( *(_WORD *)v6 == 0xFFFF )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)result == 0xFFFF )
        result = (unsigned __int16)`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003FC0
// Name: public: int CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::FirstInorder(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10034678 = -1;
      dword_1003467C = -1;
      dword_10034680 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10034678 = -1;
      dword_1003467C = -1;
      dword_10034680 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004060
// Name: public: int CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::NextInorder(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<ConCommandBase *,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10034678 = -1;
    dword_1003467C = -1;
    dword_10034680 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10034678 = -1;
          dword_1003467C = -1;
          dword_10034680 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10034678 = -1;
        dword_1003467C = -1;
        dword_10034680 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10034678 = -1;
        dword_1003467C = -1;
        dword_10034680 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004240
// Name: public: void CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RemoveAll(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this)
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
          if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10034678 = -1;
            dword_1003467C = -1;
            dword_10034680 = 1;
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
// Address: 0x10004300
// Name: protected: void CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
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
      v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
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
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x100048F0
// Name: protected: void CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveRebalance(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Root; // bx
  int v4; // eax
  int *v5; // ecx
  int *v6; // ecx
  unsigned __int16 v7; // di
  int *v8; // ecx
  int *v9; // ecx
  int v10; // edx
  int *v11; // ecx
  int *v12; // ecx
  int *v13; // ecx
  int *v14; // ecx
  int v15; // ecx
  int *v16; // ecx
  int *v17; // ecx
  int v18; // ecx
  int *v19; // ecx
  int *v20; // ecx
  int v21; // ecx
  int *v22; // ecx
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // eax
  int *v28; // ecx
  int *v29; // ecx
  int v30; // edx
  int *v31; // ecx
  int *v32; // ecx
  int *v33; // ecx
  int *v34; // ecx
  int v35; // ecx
  int *v36; // ecx
  int *v37; // ecx
  int v38; // ecx
  int *v39; // ecx
  int *v40; // ecx
  int v41; // ecx
  int *v42; // ecx
  int *v43; // eax
  int *v44; // ecx
  int *v45; // ecx
  int *v46; // ecx
  int v47; // eax
  int *v48; // ecx
  unsigned __int16 parent; // [esp+8h] [ebp-4h]

  m_Root = elem;
  if ( elem != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    do
    {
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
      }
      if ( m_Root == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[m_Root];
      if ( *((_WORD *)v5 + 3) != 1 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
      }
      if ( m_Root == 0xFFFF )
        v6 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v6 = (int *)&this->m_Elements.m_pMemory[m_Root];
      v7 = *((_WORD *)v6 + 2);
      parent = v7;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003466C = 0x1FFFF;
      }
      if ( v7 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v7];
      if ( m_Root == *(_WORD *)v8 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
        }
        if ( v7 == 0xFFFF )
          v9 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v9 = (int *)&this->m_Elements.m_pMemory[v7];
        v10 = *((unsigned __int16 *)v9 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v11 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v11 = (int *)&this->m_Elements.m_pMemory[v10];
        if ( *((_WORD *)v11 + 3) == 0 )
        {
          this->m_Elements.m_pMemory[v10].m_Tag = 1;
          this->m_Elements.m_pMemory[v7].m_Tag = 0;
          CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v7);
          v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( m_Root == 0xFFFF )
            v12 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v12 = (int *)&this->m_Elements.m_pMemory[m_Root];
          v7 = *((_WORD *)v12 + 2);
          parent = v7;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( v7 == 0xFFFF )
            v13 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v13 = (int *)&this->m_Elements.m_pMemory[v7];
          LOWORD(v10) = *((_WORD *)v13 + 1);
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v14 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v14 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
        v15 = *(unsigned __int16 *)v14;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v15 == 0xFFFF )
          v16 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v16 = (int *)&this->m_Elements.m_pMemory[v15];
        if ( *((_WORD *)v16 + 3) != 1 )
          goto LABEL_67;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v10 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
        v18 = *((unsigned __int16 *)v17 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v19 = (_WORD)v18 == 0xFFFF
            ? &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[v18];
        if ( *((_WORD *)v19 + 3) != 1 )
        {
LABEL_67:
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v20 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v20 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
          v21 = *((unsigned __int16 *)v20 + 1);
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          }
          if ( (_WORD)v21 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v21];
          if ( *((_WORD *)v22 + 3) == 1 )
          {
            if ( (v4 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
              dword_1003466C = 0x1FFFF;
            }
            if ( (_WORD)v10 == 0xFFFF )
              v23 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
            else
              v23 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v10];
            this->m_Elements.m_pMemory[*(unsigned __int16 *)v23].m_Tag = 1;
            this->m_Elements.m_pMemory[(unsigned __int16)v10].m_Tag = 0;
            CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
              this,
              elem: v10);
            v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                 | 1;
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
              dword_1003466C = 0x1FFFF;
            }
            if ( elem == 0xFFFF )
              v24 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
            else
              v24 = (int *)&this->m_Elements.m_pMemory[elem];
            v7 = *((_WORD *)v24 + 2);
            parent = v7;
            if ( (v4 & 1) == 0 )
            {
              v4 |= 1u;
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
              dword_1003466C = 0x1FFFF;
            }
            if ( v7 == 0xFFFF )
              v25 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
            else
              v25 = (int *)&this->m_Elements.m_pMemory[v7];
            LOWORD(v10) = *((_WORD *)v25 + 1);
          }
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( v7 == 0xFFFF )
            v26 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v26 = (int *)&this->m_Elements.m_pMemory[v7];
          v27 = (unsigned __int16)v10;
          this->m_Elements.m_pMemory[v27].m_Tag = *((_WORD *)v26 + 3);
          this->m_Elements.m_pMemory[v7].m_Tag = 1;
          if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( (_WORD)v10 == 0xFFFF )
            v28 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v28 = (int *)&this->m_Elements.m_pMemory[v27];
          this->m_Elements.m_pMemory[*((unsigned __int16 *)v28 + 1)].m_Tag = 1;
          CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: parent);
          goto LABEL_189;
        }
        if ( (_WORD)v10 != 0xFFFF )
        {
          this->m_Elements.m_pMemory[(unsigned __int16)v10].m_Tag = 0;
          v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
        }
        if ( v7 == 0xFFFF )
          v29 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v29 = (int *)&this->m_Elements.m_pMemory[v7];
        v30 = *(unsigned __int16 *)v29;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v30 == 0xFFFF )
          v31 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v31 = (int *)&this->m_Elements.m_pMemory[v30];
        if ( *((_WORD *)v31 + 3) == 0 )
        {
          this->m_Elements.m_pMemory[v30].m_Tag = 1;
          this->m_Elements.m_pMemory[v7].m_Tag = 0;
          CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v7);
          v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
               | 1;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( m_Root == 0xFFFF )
            v32 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v32 = (int *)&this->m_Elements.m_pMemory[m_Root];
          v7 = *((_WORD *)v32 + 2);
          parent = v7;
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( v7 == 0xFFFF )
            v33 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v33 = (int *)&this->m_Elements.m_pMemory[v7];
          LOWORD(v30) = *(_WORD *)v33;
        }
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v30 == 0xFFFF )
          v34 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v34 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v30];
        v35 = *((unsigned __int16 *)v34 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v35 == 0xFFFF )
          v36 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v36 = (int *)&this->m_Elements.m_pMemory[v35];
        if ( *((_WORD *)v36 + 3) != 1 )
          goto LABEL_151;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v30 == 0xFFFF )
          v37 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v37 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v30];
        v38 = *(unsigned __int16 *)v37;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v39 = (_WORD)v38 == 0xFFFF
            ? &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[v38];
        if ( *((_WORD *)v39 + 3) != 1 )
        {
LABEL_151:
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          }
          if ( (_WORD)v30 == 0xFFFF )
            v40 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v40 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v30];
          v41 = *(unsigned __int16 *)v40;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          }
          if ( (_WORD)v41 == 0xFFFF )
            v42 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v42 = (int *)&this->m_Elements.m_pMemory[v41];
          if ( *((_WORD *)v42 + 3) == 1 )
          {
            if ( (v4 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
              dword_1003466C = 0x1FFFF;
            }
            if ( (_WORD)v30 == 0xFFFF )
              v43 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
            else
              v43 = (int *)&this->m_Elements.m_pMemory[(unsigned __int16)v30];
            this->m_Elements.m_pMemory[*((unsigned __int16 *)v43 + 1)].m_Tag = 1;
            this->m_Elements.m_pMemory[(unsigned __int16)v30].m_Tag = 0;
            CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
              this,
              elem: v30);
            v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                 | 1;
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
              dword_1003466C = 0x1FFFF;
            }
            if ( elem == 0xFFFF )
              v44 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
            else
              v44 = (int *)&this->m_Elements.m_pMemory[elem];
            v7 = *((_WORD *)v44 + 2);
            parent = v7;
            if ( (v4 & 1) == 0 )
            {
              v4 |= 1u;
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
              `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
              dword_1003466C = 0x1FFFF;
            }
            if ( v7 == 0xFFFF )
              v45 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
            else
              v45 = (int *)&this->m_Elements.m_pMemory[v7];
            LOWORD(v30) = *(_WORD *)v45;
          }
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( v7 == 0xFFFF )
            v46 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v46 = (int *)&this->m_Elements.m_pMemory[v7];
          v47 = (unsigned __int16)v30;
          this->m_Elements.m_pMemory[v47].m_Tag = *((_WORD *)v46 + 3);
          this->m_Elements.m_pMemory[v7].m_Tag = 1;
          if ( (`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003466C = 0x1FFFF;
          }
          if ( (_WORD)v30 == 0xFFFF )
            v48 = &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v48 = (int *)&this->m_Elements.m_pMemory[v47];
          this->m_Elements.m_pMemory[*(unsigned __int16 *)v48].m_Tag = 1;
          CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: parent);
LABEL_189:
          m_Root = this->m_Root;
LABEL_190:
          v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          goto LABEL_191;
        }
        if ( (_WORD)v30 != 0xFFFF )
        {
          this->m_Elements.m_pMemory[(unsigned __int16)v30].m_Tag = 0;
          m_Root = v7;
          goto LABEL_190;
        }
      }
      m_Root = v7;
LABEL_191:
      elem = m_Root;
    }
    while ( m_Root != this->m_Root );
  }
  this->m_Elements.m_pMemory[m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100053C0
// Name: protected: void CUtlRBTree<class ConCommandBase __near *,int,bool (*)(class ConCommandBase __near * const __near &,class ConCommandBase __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::InsertRebalance(
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl*)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<ConCommandBase *,int> *v7; // ecx
  UtlRBTreeNode_t<ConCommandBase *,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<ConCommandBase *,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<ConCommandBase *,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v18; // ecx
  UtlRBTreeNode_t<ConCommandBase *,int> *v19; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v20; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<ConCommandBase *,int> *v23; // ecx
  UtlRBTreeNode_t<ConCommandBase *,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10034678 = -1;
        dword_1003467C = -1;
        dword_10034680 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10034678 = -1;
        dword_1003467C = -1;
        dword_10034680 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10034678 = -1;
        dword_1003467C = -1;
        dword_10034680 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10034678 = -1;
        dword_1003467C = -1;
        dword_10034680 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10034678 = -1;
          dword_1003467C = -1;
          dword_10034680 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10034678 = -1;
          dword_1003467C = -1;
          dword_10034680 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10034678 = -1;
            dword_1003467C = -1;
            dword_10034680 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10034678 = -1;
            dword_1003467C = -1;
            dword_10034680 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10034678 = -1;
          dword_1003467C = -1;
          dword_10034680 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10034678 = -1;
          dword_1003467C = -1;
          dword_10034680 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
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
        if ( CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10034678 = -1;
            dword_1003467C = -1;
            dword_10034680 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10034678 = -1;
            dword_1003467C = -1;
            dword_10034680 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<ConCommandBase *,int> *)&`CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<ConCommandBase *,int,bool (__cdecl *)(ConCommandBase * const &,ConCommandBase * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>>::RotateLeft(
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
// Address: 0x10005BD0
// Name: protected: void CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v6; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005C50
// Name: protected: void CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v3; // ax
  int v4; // ecx
  unsigned __int16 m_Left; // di
  int *v6; // eax
  unsigned __int16 v7; // bx
  unsigned __int16 v8; // ax
  int v9; // ebx
  unsigned __int16 v10; // ax
  CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> >::NodeColor_t ycolor; // [esp+8h] [ebp-8h]
  unsigned __int16 x; // [esp+Ch] [ebp-4h]

  if ( elem != 0xFFFF )
  {
    if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: elem) == 0xFFFF
      || CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: elem) == 0xFFFF )
    {
      m_Left = elem;
    }
    else
    {
      v3 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
             this,
             i: elem);
      v4 = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      m_Left = v3;
      while ( 1 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
        }
        v6 = m_Left == 0xFFFF
           ? &`CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
           : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( *(_WORD *)v6 == 0xFFFF )
          break;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003466C = 0x1FFFF;
        }
        if ( m_Left == 0xFFFF )
          m_Left = `CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          m_Left = this->m_Elements.m_pMemory[m_Left].m_Left;
      }
    }
    if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: m_Left) == 0xFFFF )
    {
      x = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
            this,
            i: m_Left);
      v7 = x;
    }
    else
    {
      v7 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this,
             i: m_Left);
      x = v7;
    }
    if ( v7 != 0xFFFF )
      this->m_Elements.m_pMemory[v7].m_Parent = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                  this,
                                                  i: m_Left);
    if ( m_Left == this->m_Root )
    {
      this->m_Root = v7;
    }
    else
    {
      v8 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
             this,
             i: m_Left);
      if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this,
             i: v8) == m_Left )
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                     this,
                                     i: m_Left)].m_Left = v7;
      else
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                     this,
                                     i: m_Left)].m_Right = v7;
    }
    ycolor = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(
               this,
               i: m_Left);
    if ( m_Left != elem )
    {
      v9 = m_Left;
      this->m_Elements.m_pMemory[v9].m_Parent = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                  this,
                                                  i: elem);
      this->m_Elements.m_pMemory[v9].m_Right = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                                 this,
                                                 i: elem);
      this->m_Elements.m_pMemory[v9].m_Left = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                                this,
                                                i: elem);
      if ( elem == this->m_Root )
      {
        this->m_Root = m_Left;
      }
      else
      {
        v10 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                this,
                i: elem);
        if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: v10) == elem )
          this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                       this,
                                       i: elem)].m_Left = m_Left;
        else
          this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                       this,
                                       i: elem)].m_Right = m_Left;
      }
      if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this,
             i: m_Left) != 0xFFFF )
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      if ( CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
             this,
             i: m_Left) != 0xFFFF )
        this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                     this,
                                     i: m_Left)].m_Parent = m_Left;
      this->m_Elements.m_pMemory[v9].m_Tag = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Color(
                                               this,
                                               i: elem);
      v7 = x;
    }
    if ( v7 != 0xFFFF && ycolor == BLACK )
      CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveRebalance(
        this,
        elem: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006130
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // eax
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  unsigned __int16 v10; // bx
  UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  CUtlString *p_elem; // edi

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
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
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
    v10 = v6;
  }
  else
  {
    v10 = this->m_FirstFree;
    this->m_FirstFree = this->m_Elements.m_pMemory[m_FirstFree].m_Right;
  }
  m_pMemory = this->m_Elements.m_pMemory;
  if ( &m_pMemory[v10] != (UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *)-8 )
  {
    p_elem = (CUtlString *)&m_pMemory[v10].m_Data.elem;
    CUtlString::CUtlString(this: p_elem);
    CUtlString::operator=(this: p_elem, src: str);
    p_elem[1].m_Storage.m_Memory.m_pMemory = nullptr;
    CUtlString::operator=(this: p_elem, src: str);
    p_elem[1].m_Storage.m_Memory.m_pMemory = nullptr;
  }
  this->m_pElements = this->m_Elements.m_pMemory;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10006460
// Name: public: void CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // si
  unsigned __int16 v4; // di
  UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  unsigned int v6; // edi
  bool v7; // sf
  int p_elem; // esi
  __int16 v9; // ax
  unsigned __int16 v10; // [esp+4h] [ebp-8h]
  unsigned __int16 it; // [esp+8h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      while ( 1 )
      {
        v4 = v3;
        v10 = v3;
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          m_pMemory = this->m_Elements.m_pMemory;
          v6 = v3;
          v7 = m_pMemory[v6].m_Data.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_nGrowSize < 0;
          p_elem = (int)&m_pMemory[v6].m_Data.elem;
          m_pMemory[v6].m_Data.elem.m_Vars[0].m_VarName.m_Storage.m_nActualLength = 0;
          if ( !v7 )
          {
            if ( *(_DWORD *)p_elem != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)p_elem);
              *(_DWORD *)p_elem = 0;
            }
            *(_DWORD *)(p_elem + 4) = 0;
          }
          this->m_Elements.m_pMemory[v6].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v6].m_Left = it;
          v4 = v10;
          this->m_FirstFree = it;
          v3 = it;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        v9 = v4 + 1;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v9 = -1;
        it = v9;
        if ( v9 == -1 )
          break;
        v3 = v9;
      }
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006570
// Name: public: void CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FreeNode(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FreeNode(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v3; // cx
  UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  unsigned int v5; // edi
  bool v6; // sf
  int p_m_Data; // esi

  v3 = i;
  m_pMemory = this->m_Elements.m_pMemory;
  v5 = i;
  v6 = m_pMemory[v5].m_Data.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_nGrowSize < 0;
  p_m_Data = (int)&m_pMemory[v5].m_Data;
  m_pMemory[v5].m_Data.elem.m_Vars[0].m_VarName.m_Storage.m_nActualLength = 0;
  if ( !v6 )
  {
    if ( m_pMemory[v5].m_Data.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: m_pMemory[v5].m_Data.elem.m_Vars[0].m_VarName.m_Storage.m_Memory.m_pMemory);
      v3 = i;
      *(_DWORD *)(p_m_Data + 4) = 0;
    }
    *(_DWORD *)(p_m_Data + 8) = 0;
  }
  this->m_Elements.m_pMemory[v5].m_Left = v3;
  this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
  this->m_FirstFree = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10006E30
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  CUtlString *p_elem; // ebx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *)-8 )
  {
    p_elem = (CUtlString *)&m_pMemory[v4].m_Data.elem;
    m_pMemory[v4].m_Data.key = insert->key;
    CUtlString::CUtlString(this: p_elem, string: (const CUtlString *)&insert->elem);
    p_elem[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)insert->elem.m_Vars[0].m_pVar;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10006FF0
// Name: public: CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,class CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short,CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x1000BEB0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1003783C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_1003783C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x1000C3A0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1003783C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1000C400
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1003783C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1000C460
// Name: protected: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<int,bool,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<int,bool,unsigned short>::Node_t *insert,
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
      if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003783C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003783C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C550
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *v12; // edx

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
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
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
// Address: 0x1000C650
// Name: protected: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000C740
// Name: protected: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000C830
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<int,bool,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<int,bool,unsigned short>::Node_t *search)
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
      if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003783C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003783C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x1000C930
// Name: public: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x1000C9E0
// Name: protected: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
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
      v4 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003783C = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003783C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003783C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003783C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003783C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1003783C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003783C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003783C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003783C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003783C = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003783C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003783C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003783C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003783C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
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
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003783C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1003783C = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003783C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1003783C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
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
// Address: 0x1000CFD0
// Name: public: void CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>::RemoveAll(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int> > *this)
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
          if ( (`CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10037848 = -1;
            dword_1003784C = -1;
            dword_10037850 = 1;
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
// Address: 0x1000D090
// Name: protected: void CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
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
    CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D3B0
// Name: public: CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
// Address: 0x1000D420
// Name: public: CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>::~CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>::~CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int> > *this)
{
  CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyValuesSystem::MemoryLeakTracker_t,int>,int>>::RemoveAll(this);
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
// Address: 0x1000D480
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,class CUtlMap<int,bool,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<int,bool,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<int,bool,unsigned short>::Node_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1000F4F0
// Name: public: unsigned short CUtlRBTree<struct CVCoverage::Location_t,unsigned short,class CVCoverage::CLocationLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CVCoverage::Location_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    word_1003797E = -1;
    dword_10037980 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1000F550
// Name: public: void CUtlRBTree<struct CVCoverage::Location_t,unsigned short,class CVCoverage::CLocationLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CVCoverage::Location_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short> > *this)
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
          && CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>::LeftChild(
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
// Address: 0x1000F600
// Name: public: CUtlRBTree<struct CVCoverage::Location_t,unsigned short,class CVCoverage::CLocationLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CVCoverage::Location_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CVCoverage::Location_t,unsigned short,class CVCoverage::CLocationLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CVCoverage::Location_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>::~CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CVCoverage::Location_t,unsigned short,CVCoverage::CLocationLess,CUtlMemory<UtlRBTreeNode_t<CVCoverage::Location_t,unsigned short>,unsigned short>>::RemoveAll(this);
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
