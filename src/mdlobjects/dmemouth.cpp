// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmemouth.cpp
// Functions: 9
// ============================================================

#include "mdlobjects\dmemouth.h"

//------------------------------------------------------------------------------
// Address: 0x004ADFC0
// Name: protected: void CDmeMouth::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouth::OnConstruction(CDmeMouth *this)
{
  this->m_nMouthNumber.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "mouthNumber",
                                        type: AT_INT,
                                        pMemory: &this->m_nMouthNumber);
  this->m_sFlexControllerName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "flexControllerName",
                                               type: AT_STRING,
                                               pMemory: &this->m_sFlexControllerName);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_vForward.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "forward",
                                    type: AT_VECTOR3,
                                    pMemory: &this->m_vForward);
}

//------------------------------------------------------------------------------
// Address: 0x004AE0B0
// Name: public: virtual bool CDmeMouth::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouth::IsA(CDmeMouth *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouth::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE0E0
// Name: public: virtual int CDmeMouth::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouth::GetInheritanceDepth(CDmeMouth *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouth::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE120
// Name: protected: virtual void CDmeMouth::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouth::PerformConstruction(CDmeMouth *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMouth::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059A760
// Name: _dynamic_initializer_for__CDmeMouth::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouth::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouth::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouth pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EA20
// Name: _dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouth::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059A790
// Name: _dynamic_initializer_for__g_CDmeMouth_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouth_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouth_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A7A0
// Name: _dynamic_initializer_for__g_CDmeMouth_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouth_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouth_Helper,
           classname: "DmeMouth",
           pFactory: &g_CDmeMouth_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059EA30
// Name: _dynamic_atexit_destructor_for__g_CDmeMouth_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouth_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMouth_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EB850
// Name: protected: void CDmeMouth::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouth::OnConstruction(CDmeMouth *this)
{
  this->m_nMouthNumber.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "mouthNumber",
                                        type: AT_INT,
                                        pMemory: &this->m_nMouthNumber);
  this->m_sFlexControllerName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "flexControllerName",
                                               type: AT_STRING,
                                               pMemory: &this->m_sFlexControllerName);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_vForward.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "forward",
                                    type: AT_VECTOR3,
                                    pMemory: &this->m_vForward);
}

//------------------------------------------------------------------------------
// Address: 0x004EB940
// Name: public: virtual bool CDmeMouth::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouth::IsA(CDmeMouth *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouth::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB970
// Name: public: virtual int CDmeMouth::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouth::GetInheritanceDepth(CDmeMouth *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouth::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EB9B0
// Name: protected: virtual void CDmeMouth::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouth::PerformConstruction(CDmeMouth *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMouth::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EE9C0
// Name: _dynamic_initializer_for__CDmeMouth::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouth::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouth::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouth pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F39D0
// Name: _dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouth::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EE9F0
// Name: _dynamic_initializer_for__g_CDmeMouth_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouth_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouth_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEA00
// Name: _dynamic_initializer_for__g_CDmeMouth_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouth_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouth_Helper,
           classname: "DmeMouth",
           pFactory: &g_CDmeMouth_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F39E0
// Name: _dynamic_atexit_destructor_for__g_CDmeMouth_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouth_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMouth_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0051DA90
// Name: protected: void CDmeMouth::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouth::OnConstruction(CDmeMouth *this)
{
  this->m_nMouthNumber.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "mouthNumber",
                                        type: AT_INT,
                                        pMemory: &this->m_nMouthNumber);
  this->m_sFlexControllerName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "flexControllerName",
                                               type: AT_STRING,
                                               pMemory: &this->m_sFlexControllerName);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_vForward.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "forward",
                                    type: AT_VECTOR3,
                                    pMemory: &this->m_vForward);
}

//------------------------------------------------------------------------------
// Address: 0x0051DB80
// Name: public: virtual bool CDmeMouth::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouth::IsA(CDmeMouth *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouth::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051DBB0
// Name: public: virtual int CDmeMouth::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouth::GetInheritanceDepth(CDmeMouth *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouth::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051DC00
// Name: protected: virtual void CDmeMouth::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouth::PerformConstruction(CDmeMouth *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeMouth::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AEB60
// Name: _dynamic_initializer_for__CDmeMouth::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouth::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouth::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouth pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B47F0
// Name: _dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouth::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AEB90
// Name: _dynamic_initializer_for__g_CDmeMouth_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouth_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouth_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AEBA0
// Name: _dynamic_initializer_for__g_CDmeMouth_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouth_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouth_Helper,
           classname: "DmeMouth",
           pFactory: &g_CDmeMouth_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4800
// Name: _dynamic_atexit_destructor_for__g_CDmeMouth_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouth_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMouth_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DB090
// Name: protected: void CDmeMouth::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouth::OnConstruction(CDmeMouth *this)
{
  this->m_nMouthNumber.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "mouthNumber",
                                        type: AT_INT,
                                        pMemory: &this->m_nMouthNumber);
  this->m_sFlexControllerName.m_pAttribute = CDmElement::AddExternalAttribute(
                                               this,
                                               pAttributeName: "flexControllerName",
                                               type: AT_STRING,
                                               pMemory: &this->m_sFlexControllerName);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  this->m_vForward.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "forward",
                                    type: AT_VECTOR3,
                                    pMemory: &this->m_vForward);
}

//------------------------------------------------------------------------------
// Address: 0x004DB180
// Name: public: virtual bool CDmeMouth::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouth::IsA(CDmeMouth *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouth::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DB1B0
// Name: public: virtual int CDmeMouth::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouth::GetInheritanceDepth(CDmeMouth *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouth::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DB1F0
// Name: protected: virtual void CDmeMouth::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouth::PerformConstruction(CDmeMouth *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMouth::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E6050
// Name: _dynamic_initializer_for__CDmeMouth::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouth::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouth::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouth pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC070
// Name: _dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouth::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouth::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6080
// Name: _dynamic_initializer_for__g_CDmeMouth_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouth_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouth_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6090
// Name: _dynamic_initializer_for__g_CDmeMouth_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouth_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouth_Helper,
           classname: "DmeMouth",
           pFactory: &g_CDmeMouth_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC080
// Name: _dynamic_atexit_destructor_for__g_CDmeMouth_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouth_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMouth_Factory.m_CallBackList);
}

} // namespace studiomdl
