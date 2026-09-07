// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmebonemasklist.cpp
// Functions: 9
// ============================================================

#include "mdlobjects\dmebonemasklist.h"

//------------------------------------------------------------------------------
// Address: 0x0049E8F0
// Name: public: virtual bool CDmeBoneMaskList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMaskList::IsA(CDmeBoneMaskList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMaskList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E920
// Name: public: virtual int CDmeBoneMaskList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMaskList::GetInheritanceDepth(CDmeBoneMaskList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMaskList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E970
// Name: public: virtual class CDmAttribute __near * CDmeBoneMaskList::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeBoneMaskList::GetListAttr(CDmeBoneMaskList *this)
{
  return this->m_BoneMaskList.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0049E980
// Name: protected: virtual void CDmeBoneMaskList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMaskList::PerformConstruction(CDmeBoneMaskList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_eDefaultBoneMask.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "defaultBoneMask",
                                            type: AT_FIRST_VALUE_TYPE,
                                            pMemory: &this->m_eDefaultBoneMask);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDefaultBoneMask.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
  this->m_BoneMaskList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "boneMaskList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_BoneMaskList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BoneMaskList.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00598CA0
// Name: _dynamic_initializer_for__CDmeBoneMaskList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMaskList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMaskList::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMaskList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E140
// Name: _dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMaskList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598CD0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMaskList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598CE0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMaskList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMaskList_Helper,
           classname: "DmeBoneMaskList",
           pFactory: &g_CDmeBoneMaskList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E150
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneMaskList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E73E0
// Name: public: virtual bool CDmeBoneMaskList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMaskList::IsA(CDmeBoneMaskList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMaskList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7410
// Name: public: virtual int CDmeBoneMaskList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMaskList::GetInheritanceDepth(CDmeBoneMaskList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMaskList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7460
// Name: public: virtual class CDmAttribute __near * CDmeBoneMaskList::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeBoneMaskList::GetListAttr(CDmeBoneMaskList *this)
{
  return this->m_BoneMaskList.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x004E7470
// Name: protected: virtual void CDmeBoneMaskList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMaskList::PerformConstruction(CDmeBoneMaskList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_eDefaultBoneMask.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "defaultBoneMask",
                                            type: AT_FIRST_VALUE_TYPE,
                                            pMemory: &this->m_eDefaultBoneMask);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDefaultBoneMask.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
  this->m_BoneMaskList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "boneMaskList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_BoneMaskList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BoneMaskList.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005EDE20
// Name: _dynamic_initializer_for__CDmeBoneMaskList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMaskList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMaskList::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMaskList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F35F0
// Name: _dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMaskList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDE50
// Name: _dynamic_initializer_for__g_CDmeBoneMaskList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMaskList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDE60
// Name: _dynamic_initializer_for__g_CDmeBoneMaskList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMaskList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMaskList_Helper,
           classname: "DmeBoneMaskList",
           pFactory: &g_CDmeBoneMaskList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3600
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneMaskList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050E4A0
// Name: public: virtual bool CDmeBoneMaskList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMaskList::IsA(CDmeBoneMaskList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMaskList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E4D0
// Name: public: virtual int CDmeBoneMaskList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMaskList::GetInheritanceDepth(CDmeBoneMaskList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMaskList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E530
// Name: protected: virtual void CDmeBoneMaskList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMaskList::PerformConstruction(CDmeBoneMaskList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_eDefaultBoneMask.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "defaultBoneMask",
                                            type: AT_FIRST_VALUE_TYPE,
                                            pMemory: &this->m_eDefaultBoneMask);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDefaultBoneMask.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
  this->m_BoneMaskList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "boneMaskList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_BoneMaskList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BoneMaskList.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0051C540
// Name: protected: virtual void CDmeBoneMaskList::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMaskList::PerformDestruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x006AD0A0
// Name: _dynamic_initializer_for__CDmeBoneMaskList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMaskList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMaskList::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMaskList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3F10
// Name: _dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMaskList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AD0D0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMaskList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD0E0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMaskList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMaskList_Helper,
           classname: "DmeBoneMaskList",
           pFactory: &g_CDmeBoneMaskList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3F20
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBoneMaskList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DDF10
// Name: public: virtual bool CDmeBoneMaskList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneMaskList::IsA(CDmeBoneMaskList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneMaskList::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DDF40
// Name: public: virtual int CDmeBoneMaskList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneMaskList::GetInheritanceDepth(CDmeBoneMaskList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneMaskList::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMdlList::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DDF90
// Name: public: virtual class CDmAttribute __near * CDmeBoneMaskList::GetListAttr(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeBoneMaskList::GetListAttr(CDmeBoneMaskList *this)
{
  return this->m_BoneMaskList.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x004DDFA0
// Name: protected: virtual void CDmeBoneMaskList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMaskList::PerformConstruction(CDmeBoneMaskList *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  this->m_eDefaultBoneMask.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "defaultBoneMask",
                                            type: AT_FIRST_VALUE_TYPE,
                                            pMemory: &this->m_eDefaultBoneMask);
  CDmAttribute::SetElementTypeSymbol(this: this->m_eDefaultBoneMask.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
  this->m_BoneMaskList.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "boneMaskList",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_BoneMaskList);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BoneMaskList.m_pAttribute, typeSymbol: CDmeBoneMask::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004EB380
// Name: protected: virtual void CDmeBoneMaskList::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneMaskList::PerformDestruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005E6770
// Name: _dynamic_initializer_for__CDmeBoneMaskList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneMaskList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneMaskList::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneMaskList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC2D0
// Name: _dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneMaskList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneMaskList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E67A0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneMaskList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E67B0
// Name: _dynamic_initializer_for__g_CDmeBoneMaskList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneMaskList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneMaskList_Helper,
           classname: "DmeBoneMaskList",
           pFactory: &g_CDmeBoneMaskList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC2E0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneMaskList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneMaskList_Factory.m_CallBackList);
}

} // namespace studiomdl
