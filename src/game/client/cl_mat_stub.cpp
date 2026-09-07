// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cl_mat_stub.cpp
// Functions: 3
// ============================================================

#include "game\client\cl_mat_stub.h"

//------------------------------------------------------------------------------
// Address: 0x1009FF90
// Name: public: CMatStubHandler::~CMatStubHandler(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatStubHandler::~CMatStubHandler(CMatStubHandler *this)
{
  IMaterialSystem *m_pOldMaterialSystem; // ecx

  m_pOldMaterialSystem = this->m_pOldMaterialSystem;
  if ( m_pOldMaterialSystem != nullptr )
  {
    materials = m_pOldMaterialSystem;
    m_pOldMaterialSystem->SetInStubMode(this: m_pOldMaterialSystem, a2: false);
    engine->Mat_Stub(this: engine, a2: materials);
    this->m_pOldMaterialSystem = nullptr;
    materials->ClearBuffers(this: materials, a2: true, a3: true, a4: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FFE0
// Name: public: CMatStubHandler::CMatStubHandler(void)
// Source: json
//------------------------------------------------------------------------------
CMatStubHandler *__thiscall CMatStubHandler::CMatStubHandler(CMatStubHandler *this)
{
  if ( mat_stub.m_pParent != nullptr && mat_stub.m_pParent->m_Value.m_nValue != 0 )
  {
    this->m_pOldMaterialSystem = materials;
    materials_stub->SetRealMaterialSystem(this: materials_stub, a2: materials);
    materials->SetInStubMode(this: materials, a2: true);
    materials = materials_stub;
    engine->Mat_Stub(this: engine, a2: materials_stub);
    return this;
  }
  else
  {
    this->m_pOldMaterialSystem = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0080
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<char const __near *,class classentry_t,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class classentry_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}
