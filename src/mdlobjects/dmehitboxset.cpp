// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmehitboxset.cpp
// Functions: 16
// ============================================================

#include "mdlobjects\dmehitboxset.h"

//------------------------------------------------------------------------------
// Address: 0x0049C250
// Name: public: virtual bool CDmeMdlList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMdlList::IsA(CDmeMdlList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049C280
// Name: public: virtual int CDmeMdlList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMdlList::GetInheritanceDepth(CDmeMdlList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049C2C0
// Name: public: virtual bool CDmeHitboxSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitboxSet::IsA(CDmeHitboxSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitboxSet::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049C2F0
// Name: public: virtual int CDmeHitboxSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitboxSet::GetInheritanceDepth(CDmeHitboxSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitboxSet::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049C340
// Name: protected: virtual void CDmeHitboxSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitboxSet::PerformConstruction(CDmeHitboxSet *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_HitboxList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hitboxList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_HitboxList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_HitboxList.m_pAttribute, typeSymbol: CDmeHitbox::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0049CB00
// Name: protected: virtual void CDmeMdlList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMdlList::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00598640
// Name: _dynamic_initializer_for__CDmeHitboxSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitboxSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitboxSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitboxSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00598700
// Name: _dynamic_initializer_for__CDmeMdlList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMdlList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMdlList::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMdlList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059DF20
// Name: _dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitboxSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059DF60
// Name: _dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMdlList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598670
// Name: _dynamic_initializer_for__g_CDmeHitboxSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitboxSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598680
// Name: _dynamic_initializer_for__g_CDmeHitboxSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitboxSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitboxSet_Helper,
           classname: "DmeHitboxSet",
           pFactory: &g_CDmeHitboxSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00598730
// Name: _dynamic_initializer_for__g_CDmeMdlList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMdlList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598740
// Name: _dynamic_initializer_for__g_CDmeMdlList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMdlList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMdlList_Helper,
           classname: "DmeMdlList",
           pFactory: &g_CDmeMdlList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059DF30
// Name: _dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeHitboxSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059DF70
// Name: _dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMdlList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E1A30
// Name: protected: virtual void CDmeMdlList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMdlList::PerformConstruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004E3090
// Name: public: virtual bool CDmeMdlList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMdlList::IsA(CDmeMdlList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E30C0
// Name: public: virtual int CDmeMdlList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMdlList::GetInheritanceDepth(CDmeMdlList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3110
// Name: public: virtual bool CDmeHitboxSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitboxSet::IsA(CDmeHitboxSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitboxSet::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3140
// Name: public: virtual int CDmeHitboxSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitboxSet::GetInheritanceDepth(CDmeHitboxSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitboxSet::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3190
// Name: protected: virtual void CDmeHitboxSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitboxSet::PerformConstruction(CDmeHitboxSet *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_HitboxList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hitboxList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_HitboxList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_HitboxList.m_pAttribute, typeSymbol: CDmeHitbox::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005ED520
// Name: _dynamic_initializer_for__CDmeHitboxSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitboxSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitboxSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitboxSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEA80
// Name: _dynamic_initializer_for__CDmeMdlList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMdlList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMdlList::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMdlList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F32F0
// Name: _dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitboxSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3A10
// Name: _dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMdlList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMdlList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED550
// Name: _dynamic_initializer_for__g_CDmeHitboxSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitboxSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED560
// Name: _dynamic_initializer_for__g_CDmeHitboxSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitboxSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitboxSet_Helper,
           classname: "DmeHitboxSet",
           pFactory: &g_CDmeHitboxSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EEAB0
// Name: _dynamic_initializer_for__g_CDmeMdlList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMdlList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEAC0
// Name: _dynamic_initializer_for__g_CDmeMdlList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMdlList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMdlList_Helper,
           classname: "DmeMdlList",
           pFactory: &g_CDmeMdlList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3300
// Name: _dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeHitboxSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3A20
// Name: _dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMdlList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMdlList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050C0C0
// Name: public: virtual bool CDmeHitboxSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitboxSet::IsA(CDmeHitboxSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitboxSet::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050C0F0
// Name: public: virtual int CDmeHitboxSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitboxSet::GetInheritanceDepth(CDmeHitboxSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitboxSet::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050C150
// Name: protected: virtual void CDmeHitboxSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitboxSet::PerformConstruction(CDmeHitboxSet *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_HitboxList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hitboxList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_HitboxList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_HitboxList.m_pAttribute, typeSymbol: CDmeHitbox::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006ACB00
// Name: _dynamic_initializer_for__CDmeHitboxSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitboxSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitboxSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitboxSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3D30
// Name: _dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitboxSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACB30
// Name: _dynamic_initializer_for__g_CDmeHitboxSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitboxSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACB40
// Name: _dynamic_initializer_for__g_CDmeHitboxSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitboxSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitboxSet_Helper,
           classname: "DmeHitboxSet",
           pFactory: &g_CDmeHitboxSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3D40
// Name: _dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeHitboxSet_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DBB50
// Name: public: virtual bool CDmeHitboxSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitboxSet::IsA(CDmeHitboxSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitboxSet::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DBB80
// Name: public: virtual int CDmeHitboxSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitboxSet::GetInheritanceDepth(CDmeHitboxSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitboxSet::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DBBD0
// Name: protected: virtual void CDmeHitboxSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitboxSet::PerformConstruction(CDmeHitboxSet *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_HitboxList.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "hitboxList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_HitboxList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_HitboxList.m_pAttribute, typeSymbol: CDmeHitbox::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E61D0
// Name: _dynamic_initializer_for__CDmeHitboxSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitboxSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitboxSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitboxSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC0F0
// Name: _dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitboxSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitboxSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6200
// Name: _dynamic_initializer_for__g_CDmeHitboxSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitboxSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6210
// Name: _dynamic_initializer_for__g_CDmeHitboxSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitboxSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitboxSet_Helper,
           classname: "DmeHitboxSet",
           pFactory: &g_CDmeHitboxSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC100
// Name: _dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitboxSet_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeHitboxSet_Factory.m_CallBackList);
}

} // namespace studiomdl
