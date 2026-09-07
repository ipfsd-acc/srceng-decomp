// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmematerialgrouplist.cpp
// Functions: 9
// ============================================================

#include "mdlobjects\dmematerialgrouplist.h"

//------------------------------------------------------------------------------
// Address: 0x004A2FA0
// Name: protected: virtual int CDmeMaterialGroupList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroupList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x004A49E0
// Name: public: virtual bool CDmeMaterialGroupList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialGroupList::IsA(CDmeMaterialGroupList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialGroupList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4A10
// Name: public: virtual int CDmeMaterialGroupList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroupList::GetInheritanceDepth(CDmeMaterialGroupList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialGroupList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4A70
// Name: protected: virtual void CDmeMaterialGroupList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialGroupList::PerformConstruction(CDmeMaterialGroupList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_MaterialGroups.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "materialGroups",
                                          type: AT_FIRST_ARRAY_TYPE,
                                          pMemory: &this->m_MaterialGroups);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_MaterialGroups.m_pAttribute,
    typeSymbol: CDmeMaterialGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00599C00
// Name: _dynamic_initializer_for__CDmeMaterialGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialGroupList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialGroupList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialGroupList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E660
// Name: _dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialGroupList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599C30
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialGroupList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599C40
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialGroupList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialGroupList_Helper,
           classname: "DmeMaterialGroupList",
           pFactory: &g_CDmeMaterialGroupList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E670
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialGroupList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E6740
// Name: public: virtual bool CDmeMaterialGroupList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialGroupList::IsA(CDmeMaterialGroupList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialGroupList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6770
// Name: public: virtual int CDmeMaterialGroupList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroupList::GetInheritanceDepth(CDmeMaterialGroupList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialGroupList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E67D0
// Name: protected: virtual void CDmeMaterialGroupList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialGroupList::PerformConstruction(CDmeMaterialGroupList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_MaterialGroups.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "materialGroups",
                                          type: AT_FIRST_ARRAY_TYPE,
                                          pMemory: &this->m_MaterialGroups);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_MaterialGroups.m_pAttribute,
    typeSymbol: CDmeMaterialGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E7AE0
// Name: protected: virtual int CDmeMaterialGroupList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroupList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x005EDBE0
// Name: _dynamic_initializer_for__CDmeMaterialGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialGroupList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialGroupList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialGroupList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3530
// Name: _dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialGroupList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC10
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialGroupList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC20
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialGroupList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialGroupList_Helper,
           classname: "DmeMaterialGroupList",
           pFactory: &g_CDmeMaterialGroupList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3540
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialGroupList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050C140
// Name: protected: virtual int CDmeMaterialGroupList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroupList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x00514560
// Name: public: virtual bool CDmeMaterialGroupList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialGroupList::IsA(CDmeMaterialGroupList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialGroupList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514590
// Name: public: virtual int CDmeMaterialGroupList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroupList::GetInheritanceDepth(CDmeMaterialGroupList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialGroupList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005145E0
// Name: protected: virtual void CDmeMaterialGroupList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialGroupList::PerformConstruction(CDmeMaterialGroupList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_MaterialGroups.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "materialGroups",
                                          type: AT_FIRST_ARRAY_TYPE,
                                          pMemory: &this->m_MaterialGroups);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_MaterialGroups.m_pAttribute,
    typeSymbol: CDmeMaterialGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006AE000
// Name: _dynamic_initializer_for__CDmeMaterialGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialGroupList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialGroupList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialGroupList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4430
// Name: _dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialGroupList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE030
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialGroupList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE040
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialGroupList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialGroupList_Helper,
           classname: "DmeMaterialGroupList",
           pFactory: &g_CDmeMaterialGroupList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4440
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMaterialGroupList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E3FE0
// Name: public: virtual bool CDmeMaterialGroupList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialGroupList::IsA(CDmeMaterialGroupList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialGroupList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4010
// Name: public: virtual int CDmeMaterialGroupList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroupList::GetInheritanceDepth(CDmeMaterialGroupList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialGroupList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4070
// Name: protected: virtual void CDmeMaterialGroupList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialGroupList::PerformConstruction(CDmeMaterialGroupList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_MaterialGroups.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "materialGroups",
                                          type: AT_FIRST_ARRAY_TYPE,
                                          pMemory: &this->m_MaterialGroups);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_MaterialGroups.m_pAttribute,
    typeSymbol: CDmeMaterialGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004E5E70
// Name: protected: virtual int CDmeMaterialGroupList::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroupList::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x005E76E0
// Name: _dynamic_initializer_for__CDmeMaterialGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialGroupList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialGroupList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialGroupList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC7F0
// Name: _dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialGroupList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialGroupList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7710
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialGroupList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7720
// Name: _dynamic_initializer_for__g_CDmeMaterialGroupList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialGroupList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialGroupList_Helper,
           classname: "DmeMaterialGroupList",
           pFactory: &g_CDmeMaterialGroupList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC800
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialGroupList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialGroupList_Factory.m_CallBackList);
}

} // namespace studiomdl
