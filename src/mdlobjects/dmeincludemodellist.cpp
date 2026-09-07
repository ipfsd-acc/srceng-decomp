// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeincludemodellist.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmeincludemodellist.h"

//------------------------------------------------------------------------------
// Address: 0x004A4250
// Name: public: virtual bool CDmeIncludeModelList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIncludeModelList::IsA(CDmeIncludeModelList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIncludeModelList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4280
// Name: public: virtual int CDmeIncludeModelList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIncludeModelList::GetInheritanceDepth(CDmeIncludeModelList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIncludeModelList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A42C0
// Name: protected: virtual void CDmeIncludeModelList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIncludeModelList::PerformConstruction(CDmeIncludeModelList *this)
{
  CDmeFXClip::OnDestruction();
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_IncludeModels,
    pOwner: this,
    pAttributeName: "includeModels",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00599A80
// Name: _dynamic_initializer_for__CDmeIncludeModelList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIncludeModelList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIncludeModelList::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIncludeModelList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E5E0
// Name: _dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIncludeModelList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599AB0
// Name: _dynamic_initializer_for__g_CDmeIncludeModelList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIncludeModelList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599AC0
// Name: _dynamic_initializer_for__g_CDmeIncludeModelList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIncludeModelList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIncludeModelList_Helper,
           classname: "DmeIncludeModelList",
           pFactory: &g_CDmeIncludeModelList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E5F0
// Name: _dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIncludeModelList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E5FB0
// Name: public: virtual bool CDmeIncludeModelList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIncludeModelList::IsA(CDmeIncludeModelList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIncludeModelList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5FE0
// Name: public: virtual int CDmeIncludeModelList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIncludeModelList::GetInheritanceDepth(CDmeIncludeModelList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIncludeModelList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6020
// Name: protected: virtual void CDmeIncludeModelList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIncludeModelList::PerformConstruction(CDmeIncludeModelList *this)
{
  CDmeFXClip::OnDestruction();
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_IncludeModels,
    pOwner: this,
    pAttributeName: "includeModels",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA60
// Name: _dynamic_initializer_for__CDmeIncludeModelList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIncludeModelList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIncludeModelList::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIncludeModelList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F34B0
// Name: _dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIncludeModelList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA90
// Name: _dynamic_initializer_for__g_CDmeIncludeModelList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIncludeModelList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDAA0
// Name: _dynamic_initializer_for__g_CDmeIncludeModelList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIncludeModelList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIncludeModelList_Helper,
           classname: "DmeIncludeModelList",
           pFactory: &g_CDmeIncludeModelList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F34C0
// Name: _dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIncludeModelList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00513DD0
// Name: public: virtual bool CDmeIncludeModelList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIncludeModelList::IsA(CDmeIncludeModelList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIncludeModelList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513E00
// Name: public: virtual int CDmeIncludeModelList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIncludeModelList::GetInheritanceDepth(CDmeIncludeModelList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIncludeModelList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00513E40
// Name: protected: virtual void CDmeIncludeModelList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIncludeModelList::PerformConstruction(CDmeIncludeModelList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_IncludeModels,
    pOwner: this,
    pAttributeName: "includeModels",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x006ADE80
// Name: _dynamic_initializer_for__CDmeIncludeModelList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIncludeModelList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIncludeModelList::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIncludeModelList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B43B0
// Name: _dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIncludeModelList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ADEB0
// Name: _dynamic_initializer_for__g_CDmeIncludeModelList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIncludeModelList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADEC0
// Name: _dynamic_initializer_for__g_CDmeIncludeModelList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIncludeModelList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIncludeModelList_Helper,
           classname: "DmeIncludeModelList",
           pFactory: &g_CDmeIncludeModelList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B43C0
// Name: _dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeIncludeModelList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E3850
// Name: public: virtual bool CDmeIncludeModelList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeIncludeModelList::IsA(CDmeIncludeModelList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeIncludeModelList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3880
// Name: public: virtual int CDmeIncludeModelList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeIncludeModelList::GetInheritanceDepth(CDmeIncludeModelList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeIncludeModelList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E38C0
// Name: protected: virtual void CDmeIncludeModelList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeIncludeModelList::PerformConstruction(CDmeIncludeModelList *this)
{
  CDmeFXClip::OnDestruction();
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_IncludeModels,
    pOwner: this,
    pAttributeName: "includeModels",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005E7560
// Name: _dynamic_initializer_for__CDmeIncludeModelList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeIncludeModelList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeIncludeModelList::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeIncludeModelList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC770
// Name: _dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeIncludeModelList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeIncludeModelList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7590
// Name: _dynamic_initializer_for__g_CDmeIncludeModelList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeIncludeModelList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E75A0
// Name: _dynamic_initializer_for__g_CDmeIncludeModelList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeIncludeModelList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeIncludeModelList_Helper,
           classname: "DmeIncludeModelList",
           pFactory: &g_CDmeIncludeModelList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC780
// Name: _dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeIncludeModelList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeIncludeModelList_Factory.m_CallBackList);
}

} // namespace studiomdl
