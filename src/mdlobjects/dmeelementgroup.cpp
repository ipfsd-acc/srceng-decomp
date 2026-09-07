// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeelementgroup.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmeelementgroup.h"

//------------------------------------------------------------------------------
// Address: 0x004A6630
// Name: public: virtual bool CDmeElementGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeElementGroup::IsA(CDmeElementGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeElementGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6660
// Name: public: virtual int CDmeElementGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeElementGroup::GetInheritanceDepth(CDmeElementGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeElementGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A66A0
// Name: protected: virtual void CDmeElementGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeElementGroup::PerformConstruction(CDmeElementGroup *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "elementList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eElementList.m_pAttribute, typeSymbol: CDmeElementGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0059A020
// Name: _dynamic_initializer_for__CDmeElementGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeElementGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeElementGroup::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeElementGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E7C0
// Name: _dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeElementGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059A050
// Name: _dynamic_initializer_for__g_CDmeElementGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeElementGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A060
// Name: _dynamic_initializer_for__g_CDmeElementGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeElementGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeElementGroup_Helper,
           classname: "DmeElementGroup",
           pFactory: &g_CDmeElementGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E7D0
// Name: _dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeElementGroup_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004ECF00
// Name: public: virtual bool CDmeElementGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeElementGroup::IsA(CDmeElementGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeElementGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ECF30
// Name: public: virtual int CDmeElementGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeElementGroup::GetInheritanceDepth(CDmeElementGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeElementGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ECF70
// Name: protected: virtual void CDmeElementGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeElementGroup::PerformConstruction(CDmeElementGroup *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "elementList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eElementList.m_pAttribute, typeSymbol: CDmeElementGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005EED20
// Name: _dynamic_initializer_for__CDmeElementGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeElementGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeElementGroup::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeElementGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3AF0
// Name: _dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeElementGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EED50
// Name: _dynamic_initializer_for__g_CDmeElementGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeElementGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EED60
// Name: _dynamic_initializer_for__g_CDmeElementGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeElementGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeElementGroup_Helper,
           classname: "DmeElementGroup",
           pFactory: &g_CDmeElementGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3B00
// Name: _dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeElementGroup_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00516170
// Name: public: virtual bool CDmeElementGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeElementGroup::IsA(CDmeElementGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeElementGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005161A0
// Name: public: virtual int CDmeElementGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeElementGroup::GetInheritanceDepth(CDmeElementGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeElementGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005161E0
// Name: protected: virtual void CDmeElementGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeElementGroup::PerformConstruction(CDmeElementGroup *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_eElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "elementList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eElementList.m_pAttribute, typeSymbol: CDmeElementGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006AE420
// Name: _dynamic_initializer_for__CDmeElementGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeElementGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeElementGroup::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeElementGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4590
// Name: _dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeElementGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE450
// Name: _dynamic_initializer_for__g_CDmeElementGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeElementGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE460
// Name: _dynamic_initializer_for__g_CDmeElementGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeElementGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeElementGroup_Helper,
           classname: "DmeElementGroup",
           pFactory: &g_CDmeElementGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B45A0
// Name: _dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeElementGroup_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E57A0
// Name: public: virtual bool CDmeElementGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeElementGroup::IsA(CDmeElementGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeElementGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E57D0
// Name: public: virtual int CDmeElementGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeElementGroup::GetInheritanceDepth(CDmeElementGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeElementGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5810
// Name: protected: virtual void CDmeElementGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeElementGroup::PerformConstruction(CDmeElementGroup *this)
{
  CDmeFXClip::OnDestruction();
  this->m_eElementList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "elementList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_eElementList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eElementList.m_pAttribute, typeSymbol: CDmeElementGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E7AA0
// Name: _dynamic_initializer_for__CDmeElementGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeElementGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeElementGroup::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeElementGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC930
// Name: _dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeElementGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeElementGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7AD0
// Name: _dynamic_initializer_for__g_CDmeElementGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeElementGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7AE0
// Name: _dynamic_initializer_for__g_CDmeElementGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeElementGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeElementGroup_Helper,
           classname: "DmeElementGroup",
           pFactory: &g_CDmeElementGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC940
// Name: _dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeElementGroup_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeElementGroup_Factory.m_CallBackList);
}

} // namespace studiomdl
