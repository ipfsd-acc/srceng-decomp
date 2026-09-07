// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeposeparameter.cpp
// Functions: 9
// ============================================================

#include "mdlobjects\dmeposeparameter.h"

//------------------------------------------------------------------------------
// Address: 0x004A5A40
// Name: protected: void CDmePoseParameter::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameter::OnConstruction(CDmePoseParameter *this)
{
  this->m_flMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "min",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flMin);
  this->m_flMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "max",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flMax);
  this->m_bLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "loop",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bLoop);
  this->m_flLoopRange.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "loopRange",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flLoopRange);
  this->m_bWrap.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "wrap",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bWrap);
}

//------------------------------------------------------------------------------
// Address: 0x004A5B40
// Name: public: virtual bool CDmePoseParameter::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePoseParameter::IsA(CDmePoseParameter *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePoseParameter::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5B70
// Name: public: virtual int CDmePoseParameter::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePoseParameter::GetInheritanceDepth(CDmePoseParameter *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePoseParameter::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A5C30
// Name: protected: virtual void CDmePoseParameter::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameter::PerformConstruction(CDmePoseParameter *this)
{
  CDmeFXClip::OnDestruction();
  CDmePoseParameter::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00599E40
// Name: _dynamic_initializer_for__CDmePoseParameter::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePoseParameter::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePoseParameter::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePoseParameter pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E720
// Name: _dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePoseParameter::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599E70
// Name: _dynamic_initializer_for__g_CDmePoseParameter_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePoseParameter_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599E80
// Name: _dynamic_initializer_for__g_CDmePoseParameter_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePoseParameter_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePoseParameter_Helper,
           classname: "DmePoseParameter",
           pFactory: &g_CDmePoseParameter_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E730
// Name: _dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePoseParameter_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E9E60
// Name: protected: void CDmePoseParameter::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameter::OnConstruction(CDmePoseParameter *this)
{
  this->m_flMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "min",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flMin);
  this->m_flMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "max",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flMax);
  this->m_bLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "loop",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bLoop);
  this->m_flLoopRange.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "loopRange",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flLoopRange);
  this->m_bWrap.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "wrap",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bWrap);
}

//------------------------------------------------------------------------------
// Address: 0x004E9F60
// Name: public: virtual bool CDmePoseParameter::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePoseParameter::IsA(CDmePoseParameter *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePoseParameter::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9F90
// Name: public: virtual int CDmePoseParameter::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePoseParameter::GetInheritanceDepth(CDmePoseParameter *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePoseParameter::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA060
// Name: protected: virtual void CDmePoseParameter::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameter::PerformConstruction(CDmePoseParameter *this)
{
  CDmeFXClip::OnDestruction();
  CDmePoseParameter::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EE720
// Name: _dynamic_initializer_for__CDmePoseParameter::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePoseParameter::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePoseParameter::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePoseParameter pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F38F0
// Name: _dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePoseParameter::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EE750
// Name: _dynamic_initializer_for__g_CDmePoseParameter_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePoseParameter_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EE760
// Name: _dynamic_initializer_for__g_CDmePoseParameter_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePoseParameter_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePoseParameter_Helper,
           classname: "DmePoseParameter",
           pFactory: &g_CDmePoseParameter_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3900
// Name: _dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePoseParameter_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00515590
// Name: protected: void CDmePoseParameter::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameter::OnConstruction(CDmePoseParameter *this)
{
  this->m_flMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "min",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flMin);
  this->m_flMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "max",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flMax);
  this->m_bLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "loop",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bLoop);
  this->m_flLoopRange.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "loopRange",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flLoopRange);
  this->m_bWrap.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "wrap",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bWrap);
}

//------------------------------------------------------------------------------
// Address: 0x00515690
// Name: public: virtual bool CDmePoseParameter::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePoseParameter::IsA(CDmePoseParameter *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePoseParameter::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005156C0
// Name: public: virtual int CDmePoseParameter::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePoseParameter::GetInheritanceDepth(CDmePoseParameter *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePoseParameter::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00515780
// Name: protected: virtual void CDmePoseParameter::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameter::PerformConstruction(CDmePoseParameter *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmePoseParameter::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AE240
// Name: _dynamic_initializer_for__CDmePoseParameter::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePoseParameter::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePoseParameter::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePoseParameter pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B44F0
// Name: _dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePoseParameter::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE270
// Name: _dynamic_initializer_for__g_CDmePoseParameter_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePoseParameter_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE280
// Name: _dynamic_initializer_for__g_CDmePoseParameter_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePoseParameter_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePoseParameter_Helper,
           classname: "DmePoseParameter",
           pFactory: &g_CDmePoseParameter_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4500
// Name: _dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePoseParameter_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E4BB0
// Name: protected: void CDmePoseParameter::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameter::OnConstruction(CDmePoseParameter *this)
{
  this->m_flMin.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "min",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flMin);
  this->m_flMax.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "max",
                                 type: AT_FLOAT,
                                 pMemory: &this->m_flMax);
  this->m_bLoop.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "loop",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bLoop);
  this->m_flLoopRange.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "loopRange",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flLoopRange);
  this->m_bWrap.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "wrap",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bWrap);
}

//------------------------------------------------------------------------------
// Address: 0x004E4CB0
// Name: public: virtual bool CDmePoseParameter::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePoseParameter::IsA(CDmePoseParameter *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePoseParameter::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4CE0
// Name: public: virtual int CDmePoseParameter::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePoseParameter::GetInheritanceDepth(CDmePoseParameter *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePoseParameter::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4DA0
// Name: protected: virtual void CDmePoseParameter::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePoseParameter::PerformConstruction(CDmePoseParameter *this)
{
  CDmeFXClip::OnDestruction();
  CDmePoseParameter::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E78C0
// Name: _dynamic_initializer_for__CDmePoseParameter::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePoseParameter::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePoseParameter::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePoseParameter pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC890
// Name: _dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePoseParameter::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePoseParameter::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E78F0
// Name: _dynamic_initializer_for__g_CDmePoseParameter_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePoseParameter_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7900
// Name: _dynamic_initializer_for__g_CDmePoseParameter_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePoseParameter_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePoseParameter_Helper,
           classname: "DmePoseParameter",
           pFactory: &g_CDmePoseParameter_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC8A0
// Name: _dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePoseParameter_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePoseParameter_Factory.m_CallBackList);
}

} // namespace studiomdl
