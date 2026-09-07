// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeboneweight.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmeboneweight.h"

//------------------------------------------------------------------------------
// Address: 0x0049E550
// Name: public: virtual bool CDmeBoneWeight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneWeight::IsA(CDmeBoneWeight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneWeight::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E580
// Name: public: virtual int CDmeBoneWeight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneWeight::GetInheritanceDepth(CDmeBoneWeight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneWeight::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E620
// Name: protected: virtual void CDmeBoneWeight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneWeight::PerformConstruction(CDmeBoneWeight *this)
{
  CDmeFXClip::OnDestruction();
  this->m_flWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "weight",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flWeight);
}

//------------------------------------------------------------------------------
// Address: 0x00598BE0
// Name: _dynamic_initializer_for__CDmeBoneWeight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneWeight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneWeight::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneWeight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E100
// Name: _dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneWeight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598C10
// Name: _dynamic_initializer_for__g_CDmeBoneWeight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneWeight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598C20
// Name: _dynamic_initializer_for__g_CDmeBoneWeight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneWeight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneWeight_Helper,
           classname: "DmeBoneWeight",
           pFactory: &g_CDmeBoneWeight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E110
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneWeight_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E7040
// Name: public: virtual bool CDmeBoneWeight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneWeight::IsA(CDmeBoneWeight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneWeight::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7070
// Name: public: virtual int CDmeBoneWeight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneWeight::GetInheritanceDepth(CDmeBoneWeight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneWeight::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7110
// Name: protected: virtual void CDmeBoneWeight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneWeight::PerformConstruction(CDmeBoneWeight *this)
{
  CDmeFXClip::OnDestruction();
  this->m_flWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "weight",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flWeight);
}

//------------------------------------------------------------------------------
// Address: 0x005EDD60
// Name: _dynamic_initializer_for__CDmeBoneWeight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneWeight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneWeight::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneWeight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F35B0
// Name: _dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneWeight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDD90
// Name: _dynamic_initializer_for__g_CDmeBoneWeight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneWeight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDDA0
// Name: _dynamic_initializer_for__g_CDmeBoneWeight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneWeight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneWeight_Helper,
           classname: "DmeBoneWeight",
           pFactory: &g_CDmeBoneWeight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F35C0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneWeight_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050E100
// Name: public: virtual bool CDmeBoneWeight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneWeight::IsA(CDmeBoneWeight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneWeight::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E130
// Name: public: virtual int CDmeBoneWeight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneWeight::GetInheritanceDepth(CDmeBoneWeight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneWeight::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E1D0
// Name: protected: virtual void CDmeBoneWeight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneWeight::PerformConstruction(CDmeBoneWeight *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_flWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "weight",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flWeight);
}

//------------------------------------------------------------------------------
// Address: 0x006ACFE0
// Name: _dynamic_initializer_for__CDmeBoneWeight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneWeight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneWeight::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneWeight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3ED0
// Name: _dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneWeight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AD010
// Name: _dynamic_initializer_for__g_CDmeBoneWeight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneWeight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD020
// Name: _dynamic_initializer_for__g_CDmeBoneWeight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneWeight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneWeight_Helper,
           classname: "DmeBoneWeight",
           pFactory: &g_CDmeBoneWeight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3EE0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBoneWeight_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DDB70
// Name: public: virtual bool CDmeBoneWeight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBoneWeight::IsA(CDmeBoneWeight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBoneWeight::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DDBA0
// Name: public: virtual int CDmeBoneWeight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBoneWeight::GetInheritanceDepth(CDmeBoneWeight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBoneWeight::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DDC40
// Name: protected: virtual void CDmeBoneWeight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBoneWeight::PerformConstruction(CDmeBoneWeight *this)
{
  CDmeFXClip::OnDestruction();
  this->m_flWeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "weight",
                                    type: AT_FLOAT,
                                    pMemory: &this->m_flWeight);
}

//------------------------------------------------------------------------------
// Address: 0x005E66B0
// Name: _dynamic_initializer_for__CDmeBoneWeight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBoneWeight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBoneWeight::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBoneWeight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC290
// Name: _dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBoneWeight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBoneWeight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E66E0
// Name: _dynamic_initializer_for__g_CDmeBoneWeight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBoneWeight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E66F0
// Name: _dynamic_initializer_for__g_CDmeBoneWeight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBoneWeight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBoneWeight_Helper,
           classname: "DmeBoneWeight",
           pFactory: &g_CDmeBoneWeight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC2A0
// Name: _dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBoneWeight_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBoneWeight_Factory.m_CallBackList);
}

} // namespace studiomdl
