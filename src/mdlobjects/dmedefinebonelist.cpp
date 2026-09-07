// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmedefinebonelist.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmedefinebonelist.h"

//------------------------------------------------------------------------------
// Address: 0x004A4660
// Name: public: virtual bool CDmeDefineBoneList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDefineBoneList::IsA(CDmeDefineBoneList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDefineBoneList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4690
// Name: public: virtual int CDmeDefineBoneList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDefineBoneList::GetInheritanceDepth(CDmeDefineBoneList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDefineBoneList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A46E0
// Name: protected: virtual void CDmeDefineBoneList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBoneList::PerformConstruction(CDmeDefineBoneList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_DefineBones.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "defineBones",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_DefineBones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_DefineBones.m_pAttribute, typeSymbol: CDmeDefineBone::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00599B40
// Name: _dynamic_initializer_for__CDmeDefineBoneList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDefineBoneList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDefineBoneList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDefineBoneList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E620
// Name: _dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDefineBoneList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599B70
// Name: _dynamic_initializer_for__g_CDmeDefineBoneList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDefineBoneList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599B80
// Name: _dynamic_initializer_for__g_CDmeDefineBoneList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDefineBoneList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDefineBoneList_Helper,
           classname: "DmeDefineBoneList",
           pFactory: &g_CDmeDefineBoneList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E630
// Name: _dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDefineBoneList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E63C0
// Name: public: virtual bool CDmeDefineBoneList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDefineBoneList::IsA(CDmeDefineBoneList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDefineBoneList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E63F0
// Name: public: virtual int CDmeDefineBoneList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDefineBoneList::GetInheritanceDepth(CDmeDefineBoneList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDefineBoneList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6440
// Name: protected: virtual void CDmeDefineBoneList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBoneList::PerformConstruction(CDmeDefineBoneList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_DefineBones.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "defineBones",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_DefineBones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_DefineBones.m_pAttribute, typeSymbol: CDmeDefineBone::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005EDB20
// Name: _dynamic_initializer_for__CDmeDefineBoneList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDefineBoneList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDefineBoneList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDefineBoneList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F34F0
// Name: _dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDefineBoneList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDB50
// Name: _dynamic_initializer_for__g_CDmeDefineBoneList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDefineBoneList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDB60
// Name: _dynamic_initializer_for__g_CDmeDefineBoneList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDefineBoneList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDefineBoneList_Helper,
           classname: "DmeDefineBoneList",
           pFactory: &g_CDmeDefineBoneList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3500
// Name: _dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDefineBoneList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005141F0
// Name: public: virtual bool CDmeDefineBoneList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDefineBoneList::IsA(CDmeDefineBoneList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDefineBoneList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514220
// Name: public: virtual int CDmeDefineBoneList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDefineBoneList::GetInheritanceDepth(CDmeDefineBoneList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDefineBoneList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514270
// Name: protected: virtual void CDmeDefineBoneList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBoneList::PerformConstruction(CDmeDefineBoneList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_DefineBones.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "defineBones",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_DefineBones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_DefineBones.m_pAttribute, typeSymbol: CDmeDefineBone::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006ADF40
// Name: _dynamic_initializer_for__CDmeDefineBoneList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDefineBoneList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDefineBoneList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDefineBoneList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B43F0
// Name: _dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDefineBoneList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ADF70
// Name: _dynamic_initializer_for__g_CDmeDefineBoneList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDefineBoneList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADF80
// Name: _dynamic_initializer_for__g_CDmeDefineBoneList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDefineBoneList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDefineBoneList_Helper,
           classname: "DmeDefineBoneList",
           pFactory: &g_CDmeDefineBoneList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4400
// Name: _dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeDefineBoneList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E3C60
// Name: public: virtual bool CDmeDefineBoneList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDefineBoneList::IsA(CDmeDefineBoneList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDefineBoneList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3C90
// Name: public: virtual int CDmeDefineBoneList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDefineBoneList::GetInheritanceDepth(CDmeDefineBoneList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDefineBoneList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3CE0
// Name: protected: virtual void CDmeDefineBoneList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDefineBoneList::PerformConstruction(CDmeDefineBoneList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_DefineBones.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "defineBones",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_DefineBones);
  CDmAttribute::SetElementTypeSymbol(this: this->m_DefineBones.m_pAttribute, typeSymbol: CDmeDefineBone::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E7620
// Name: _dynamic_initializer_for__CDmeDefineBoneList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDefineBoneList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDefineBoneList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDefineBoneList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC7B0
// Name: _dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDefineBoneList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDefineBoneList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7650
// Name: _dynamic_initializer_for__g_CDmeDefineBoneList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDefineBoneList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7660
// Name: _dynamic_initializer_for__g_CDmeDefineBoneList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDefineBoneList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDefineBoneList_Helper,
           classname: "DmeDefineBoneList",
           pFactory: &g_CDmeDefineBoneList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC7C0
// Name: _dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDefineBoneList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDefineBoneList_Factory.m_CallBackList);
}

} // namespace studiomdl
