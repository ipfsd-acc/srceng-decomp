// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/sharedobject.cpp
// Functions: 4
// ============================================================

#include "gcsdk\sharedobject.h"

//------------------------------------------------------------------------------
// Address: 0x10025980
// Name: public: bool GCSDK::CSharedObject::BIsKeyEqual(class GCSDK::CSharedObject const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GCSDK::CSharedObject::BIsKeyEqual(GCSDK::CSharedObject *this, const GCSDK::CSharedObject *soRHS)
{
  return !this->BIsKeyLess(this, a2: soRHS) && !soRHS->BIsKeyLess(this: soRHS, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10025BE0
// Name: public: static class GCSDK::CSharedObject __near * GCSDK::CSharedObject::Create(int)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CSharedObject *__cdecl GCSDK::CSharedObject::Create(int nTypeID)
{
  unsigned __int16 v1; // ax
  int v2; // edi
  CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::Node_t search; // [esp+8h] [ebp-Ch] BYREF

  search.key = nTypeID;
  v1 = CUtlRBTree<CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &GCSDK::CSharedObject::sm_mapFactories.m_Tree,
         &search);
  v2 = v1;
  if ( v1 >= GCSDK::CSharedObject::sm_mapFactories.m_Tree.m_Elements.m_nAllocationCount
    || v1 > GCSDK::CSharedObject::sm_mapFactories.m_Tree.m_LastAlloc.index
    || CUtlRBTree<CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &GCSDK::CSharedObject::sm_mapFactories.m_Tree,
         i: v1) == v1 )
  {
    return nullptr;
  }
  else
  {
    return GCSDK::CSharedObject::sm_mapFactories.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem.m_pFactoryFunction();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054670
// Name: _dynamic_initializer_for__GCSDK::CSharedObject::sm_mapFactories__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__GCSDK::CSharedObject::sm_mapFactories__()
{
  return atexit(func: dynamic_atexit_destructor_for__GCSDK::CSharedObject::sm_mapFactories__);
}

//------------------------------------------------------------------------------
// Address: 0x10055300
// Name: _dynamic_atexit_destructor_for__GCSDK::CSharedObject::sm_mapFactories__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__GCSDK::CSharedObject::sm_mapFactories__()
{
  CUtlRBTree<CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,GCSDK::CSharedObject::SharedObjectInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &GCSDK::CSharedObject::sm_mapFactories.m_Tree);
}
