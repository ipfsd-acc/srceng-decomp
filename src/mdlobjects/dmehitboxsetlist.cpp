// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmehitboxsetlist.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmehitboxsetlist.h"

//------------------------------------------------------------------------------
// Address: 0x0049C480
// Name: public: virtual bool CDmeHitboxSetList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitboxSetList::IsA(CDmeHitboxSetList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitboxSetList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049C4B0
// Name: public: virtual int CDmeHitboxSetList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitboxSetList::GetInheritanceDepth(CDmeHitboxSetList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitboxSetList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049C500
// Name: protected: virtual void CDmeHitboxSetList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitboxSetList::PerformConstruction(CDmeHitboxSetList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_HitboxSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "hitboxSetList",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_HitboxSetList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_HitboxSetList.m_pAttribute, typeSymbol: CDmeHitboxSet::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005986A0
// Name: _dynamic_initializer_for__CDmeHitboxSetList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitboxSetList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitboxSetList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitboxSetList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059DF40
// Name: _dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitboxSetList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005986D0
// Name: _dynamic_initializer_for__g_CDmeHitboxSetList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitboxSetList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005986E0
// Name: _dynamic_initializer_for__g_CDmeHitboxSetList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitboxSetList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitboxSetList_Helper,
           classname: "DmeHitboxSetList",
           pFactory: &g_CDmeHitboxSetList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059DF50
// Name: _dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeHitboxSetList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E32D0
// Name: public: virtual bool CDmeHitboxSetList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitboxSetList::IsA(CDmeHitboxSetList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitboxSetList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3300
// Name: public: virtual int CDmeHitboxSetList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitboxSetList::GetInheritanceDepth(CDmeHitboxSetList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitboxSetList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3350
// Name: protected: virtual void CDmeHitboxSetList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitboxSetList::PerformConstruction(CDmeHitboxSetList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_HitboxSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "hitboxSetList",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_HitboxSetList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_HitboxSetList.m_pAttribute, typeSymbol: CDmeHitboxSet::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005ED580
// Name: _dynamic_initializer_for__CDmeHitboxSetList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitboxSetList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitboxSetList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitboxSetList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3310
// Name: _dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitboxSetList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED5B0
// Name: _dynamic_initializer_for__g_CDmeHitboxSetList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitboxSetList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED5C0
// Name: _dynamic_initializer_for__g_CDmeHitboxSetList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitboxSetList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitboxSetList_Helper,
           classname: "DmeHitboxSetList",
           pFactory: &g_CDmeHitboxSetList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3320
// Name: _dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeHitboxSetList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050C290
// Name: public: virtual bool CDmeHitboxSetList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitboxSetList::IsA(CDmeHitboxSetList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitboxSetList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050C2C0
// Name: public: virtual int CDmeHitboxSetList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitboxSetList::GetInheritanceDepth(CDmeHitboxSetList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitboxSetList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050C310
// Name: protected: virtual void CDmeHitboxSetList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitboxSetList::PerformConstruction(CDmeHitboxSetList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_HitboxSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "hitboxSetList",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_HitboxSetList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_HitboxSetList.m_pAttribute, typeSymbol: CDmeHitboxSet::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006ACB60
// Name: _dynamic_initializer_for__CDmeHitboxSetList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitboxSetList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitboxSetList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitboxSetList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3D50
// Name: _dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitboxSetList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACB90
// Name: _dynamic_initializer_for__g_CDmeHitboxSetList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitboxSetList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACBA0
// Name: _dynamic_initializer_for__g_CDmeHitboxSetList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitboxSetList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitboxSetList_Helper,
           classname: "DmeHitboxSetList",
           pFactory: &g_CDmeHitboxSetList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3D60
// Name: _dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeHitboxSetList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DBD10
// Name: public: virtual bool CDmeHitboxSetList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitboxSetList::IsA(CDmeHitboxSetList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitboxSetList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DBD40
// Name: public: virtual int CDmeHitboxSetList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitboxSetList::GetInheritanceDepth(CDmeHitboxSetList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitboxSetList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DBD90
// Name: protected: virtual void CDmeHitboxSetList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitboxSetList::PerformConstruction(CDmeHitboxSetList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_HitboxSetList.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "hitboxSetList",
                                         type: AT_FIRST_ARRAY_TYPE,
                                         pMemory: &this->m_HitboxSetList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_HitboxSetList.m_pAttribute, typeSymbol: CDmeHitboxSet::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E6230
// Name: _dynamic_initializer_for__CDmeHitboxSetList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitboxSetList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitboxSetList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitboxSetList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC110
// Name: _dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitboxSetList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitboxSetList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6260
// Name: _dynamic_initializer_for__g_CDmeHitboxSetList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitboxSetList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6270
// Name: _dynamic_initializer_for__g_CDmeHitboxSetList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitboxSetList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitboxSetList_Helper,
           classname: "DmeHitboxSetList",
           pFactory: &g_CDmeHitboxSetList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC120
// Name: _dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitboxSetList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeHitboxSetList_Factory.m_CallBackList);
}

} // namespace studiomdl
