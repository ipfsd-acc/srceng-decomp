// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmematerialgroup.cpp
// Functions: 9
// ============================================================

#include "mdlobjects\dmematerialgroup.h"

//------------------------------------------------------------------------------
// Address: 0x004A4820
// Name: public: virtual bool CDmeMaterialGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialGroup::IsA(CDmeMaterialGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialGroup::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4850
// Name: public: virtual int CDmeMaterialGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroup::GetInheritanceDepth(CDmeMaterialGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialGroup::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A48A0
// Name: protected: virtual void CDmeMaterialGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialGroup::PerformConstruction(CDmeMaterialGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_MaterialList,
    pOwner: this,
    pAttributeName: "materialList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004A48D0
// Name: public: virtual class CDmAttribute __near * CDmeMaterialGroup::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeMaterialGroup::GetListAttr(CDmeMaterialGroup *this)
{
  return this->m_MaterialList.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00599BA0
// Name: _dynamic_initializer_for__CDmeMaterialGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialGroup::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E640
// Name: _dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599BD0
// Name: _dynamic_initializer_for__g_CDmeMaterialGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599BE0
// Name: _dynamic_initializer_for__g_CDmeMaterialGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialGroup_Helper,
           classname: "DmeMaterialGroup",
           pFactory: &g_CDmeMaterialGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E650
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialGroup_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E6580
// Name: public: virtual bool CDmeMaterialGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialGroup::IsA(CDmeMaterialGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialGroup::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E65B0
// Name: public: virtual int CDmeMaterialGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroup::GetInheritanceDepth(CDmeMaterialGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialGroup::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6600
// Name: protected: virtual void CDmeMaterialGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialGroup::PerformConstruction(CDmeMaterialGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_MaterialList,
    pOwner: this,
    pAttributeName: "materialList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004E6630
// Name: public: virtual class CDmAttribute __near * CDmeMaterialGroup::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroup::GetListAttr(CDmeCombinationOperator *this)
{
  return this->m_InputControls.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005EDB80
// Name: _dynamic_initializer_for__CDmeMaterialGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialGroup::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3510
// Name: _dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDBB0
// Name: _dynamic_initializer_for__g_CDmeMaterialGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDBC0
// Name: _dynamic_initializer_for__g_CDmeMaterialGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialGroup_Helper,
           classname: "DmeMaterialGroup",
           pFactory: &g_CDmeMaterialGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3520
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialGroup_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005143B0
// Name: public: virtual bool CDmeMaterialGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialGroup::IsA(CDmeMaterialGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialGroup::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005143E0
// Name: public: virtual int CDmeMaterialGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroup::GetInheritanceDepth(CDmeMaterialGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialGroup::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514430
// Name: protected: virtual void CDmeMaterialGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialGroup::PerformConstruction(CDmeMaterialGroup *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_MaterialList,
    pOwner: this,
    pAttributeName: "materialList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00525C40
// Name: public: virtual class CDmAttribute __near * CDmeMaterialGroup::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroup::GetListAttr(CDmeCombinationOperator *this)
{
  return this->m_InputControls.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x006ADFA0
// Name: _dynamic_initializer_for__CDmeMaterialGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialGroup::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4410
// Name: _dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ADFD0
// Name: _dynamic_initializer_for__g_CDmeMaterialGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ADFE0
// Name: _dynamic_initializer_for__g_CDmeMaterialGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialGroup_Helper,
           classname: "DmeMaterialGroup",
           pFactory: &g_CDmeMaterialGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4420
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMaterialGroup_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E3E20
// Name: public: virtual bool CDmeMaterialGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialGroup::IsA(CDmeMaterialGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialGroup::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3E50
// Name: public: virtual int CDmeMaterialGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroup::GetInheritanceDepth(CDmeMaterialGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialGroup::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E3EA0
// Name: protected: virtual void CDmeMaterialGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialGroup::PerformConstruction(CDmeMaterialGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_MaterialList,
    pOwner: this,
    pAttributeName: "materialList",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004E3ED0
// Name: public: virtual class CDmAttribute __near * CDmeMaterialGroup::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialGroup::GetListAttr(CDmeCombinationOperator *this)
{
  return this->m_InputControls.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005E7680
// Name: _dynamic_initializer_for__CDmeMaterialGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialGroup::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC7D0
// Name: _dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E76B0
// Name: _dynamic_initializer_for__g_CDmeMaterialGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E76C0
// Name: _dynamic_initializer_for__g_CDmeMaterialGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialGroup_Helper,
           classname: "DmeMaterialGroup",
           pFactory: &g_CDmeMaterialGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC7E0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialGroup_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialGroup_Factory.m_CallBackList);
}

} // namespace studiomdl
